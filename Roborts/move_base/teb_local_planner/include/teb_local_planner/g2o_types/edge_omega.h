#ifndef EDGE_OMEGA_H
#define EDGE_OMEGA_H

#include <teb_local_planner/g2o_types/vertex_pose.h>
#include <teb_local_planner/g2o_types/vertex_timediff.h>
#include <teb_local_planner/g2o_types/base_teb_edges.h>
#include <teb_local_planner/g2o_types/penalties.h>
#include <teb_local_planner/teb_config.h>


#include <iostream>

namespace teb_local_planner
{

  
/**
 * @class EdgeVelocity
 * @brief Edge defining the cost function for limiting the translational and rotational velocity.
 * 
 * The edge depends on three vertices \f$ \mathbf{s}_i, \mathbf{s}_{ip1}, \Delta T_i \f$ and minimizes: \n
 * \f$ \min \textrm{penaltyInterval}( [v,omega]^T ) \cdot weight \f$. \n
 * \e v is calculated using the difference quotient and the position parts of both poses. \n
 * \e omega is calculated using the difference quotient of both yaw angles followed by a normalization to [-pi, pi]. \n
 * \e weight can be set using setInformation(). \n
 * \e penaltyInterval denotes the penalty function, see penaltyBoundToInterval(). \n
 * The dimension of the error / cost vector is 2: the first component represents the translational velocity and
 * the second one the rotational velocity.
 * @see TebOptimalPlanner::AddEdgesVelocity
 * @remarks Do not forget to call setTebConfig()
 */  
class EdgeOmega : public BaseTebMultiEdge<1, double>
{
public:
  
  /**
   * @brief Construct edge.
   */	      
  EdgeOmega()
  {
    this->resize(3); // Since we derive from a g2o::BaseMultiEdge, set the desired number of vertices
  }
  
  /**
   * @brief Actual cost function
   */  
  void computeError()
  {
    ROS_ASSERT_MSG(cfg_, "You must call setTebConfig on EdgeOmega()");
    const VertexPose* conf1 = static_cast<const VertexPose*>(_vertices[0]);
    const VertexPose* conf2 = static_cast<const VertexPose*>(_vertices[1]);
    const VertexTimeDiff* deltaT = static_cast<const VertexTimeDiff*>(_vertices[2]);
    
    double omega = g2o::normalize_theta(conf2->theta() - conf1->theta()) / deltaT->estimate();
  
    _error[0] = penaltyBoundToEpsilon(omega, cfg_->robot.target_theta, cfg_->optim.penalty_epsilon);

    ROS_ASSERT_MSG(std::isfinite(_error[0]), "EdgeOmega::computeError() _error[0]=%f\n",_error[0]);
  }

#ifdef USE_ANALYTIC_JACOBI
#if 0 //TODO the hardcoded jacobian does not include the changing direction (just the absolute value)
      // Change accordingly...

  /**
   * @brief Jacobi matrix of the cost function specified in computeError().
   */
  void linearizeOplus()
  {
    ROS_ASSERT_MSG(cfg_, "You must call setTebConfig on EdgeVelocity()");
    const VertexPose* conf1 = static_cast<const VertexPose*>(_vertices[0]);
    const VertexPose* conf2 = static_cast<const VertexPose*>(_vertices[1]);
    const VertexTimeDiff* deltaT = static_cast<const VertexTimeDiff*>(_vertices[2]);
    
    Eigen::Vector2d deltaS = conf2->position() - conf1->position();
    double dist = deltaS.norm();
    double aux1 = dist*deltaT->estimate();
    double aux2 = 1/deltaT->estimate();
    
    double vel = dist * aux2;
    double omega = g2o::normalize_theta(conf2->theta() - conf1->theta()) * aux2;
    
    double dev_border_vel = penaltyBoundToIntervalDerivative(vel, -cfg_->robot.max_vel_x_backwards, cfg_->robot.max_vel_x,cfg_->optim.penalty_epsilon);
    double dev_border_omega = penaltyBoundToIntervalDerivative(omega, cfg_->robot.max_vel_theta,cfg_->optim.penalty_epsilon);
    
    _jacobianOplus[0].resize(2,3); // conf1
    _jacobianOplus[1].resize(2,3); // conf2
    _jacobianOplus[2].resize(2,1); // deltaT
    
//  if (aux1==0) aux1=1e-6;
//  if (aux2==0) aux2=1e-6;
    
    if (dev_border_vel!=0)
    {
      double aux3 = dev_border_vel / aux1;
      _jacobianOplus[0](0,0) = -deltaS[0] * aux3; // vel x1
      _jacobianOplus[0](0,1) = -deltaS[1] * aux3; // vel y1	
      _jacobianOplus[1](0,0) = deltaS[0] * aux3; // vel x2
      _jacobianOplus[1](0,1) = deltaS[1] * aux3; // vel y2
      _jacobianOplus[2](0,0) = -vel * aux2 * dev_border_vel; // vel deltaT
    }
    else
    {
      _jacobianOplus[0](0,0) = 0; // vel x1
      _jacobianOplus[0](0,1) = 0; // vel y1	
      _jacobianOplus[1](0,0) = 0; // vel x2
      _jacobianOplus[1](0,1) = 0; // vel y2	
      _jacobianOplus[2](0,0) = 0; // vel deltaT
    }
    
    if (dev_border_omega!=0)
    {
      double aux4 = aux2 * dev_border_omega;
      _jacobianOplus[2](1,0) = -omega * aux4; // omega deltaT
      _jacobianOplus[0](1,2) = -aux4; // omega angle1
      _jacobianOplus[1](1,2) = aux4; // omega angle2
    }
    else
    {
      _jacobianOplus[2](1,0) = 0; // omega deltaT
      _jacobianOplus[0](1,2) = 0; // omega angle1
      _jacobianOplus[1](1,2) = 0; // omega angle2			
    }

    _jacobianOplus[0](1,0) = 0; // omega x1
    _jacobianOplus[0](1,1) = 0; // omega y1
    _jacobianOplus[1](1,0) = 0; // omega x2
    _jacobianOplus[1](1,1) = 0; // omega y2
    _jacobianOplus[0](0,2) = 0; // vel angle1
    _jacobianOplus[1](0,2) = 0; // vel angle2
  }
#endif
#endif
 
  
public:
  
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};