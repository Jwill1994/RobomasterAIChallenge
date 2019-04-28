/*
 * twirling_cost_function.cpp
 *
 *  Created on: Apr 20, 2016
 *      Author: Morgan Quigley
 */

#include <base_local_planner/twirling_cost_function.h>

#include <math.h>

namespace base_local_planner {

double TwirlingCostFunction::scoreTrajectory(Trajectory &traj) {
  ROS_ERROR("TwirlingCostFunction::scoreTrajectory ThetaV : %f, Target Omega : %f", traj.thetav_, traj.target_omega);
  return fabs(traj.thetav_ - traj.target_omega); // add cost for making the robot spin
}

} /* namespace base_local_planner */
