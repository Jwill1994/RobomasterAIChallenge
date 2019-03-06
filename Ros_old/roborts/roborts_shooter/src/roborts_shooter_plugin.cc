#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>

#include <gazebo/physics/physics.hh>
#include <gazebo_plugins/gazebo_ros_utils.h>

#include <gazebo/physics/World.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/physics/physics.hh>

#include <unistd.h>

#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include <thread>


#include "roborts_msgs/ShootState.h"
#include "roborts_msgs/ShootInfo.h"
#include "roborts_msgs/ShootCmd.h"
#include "roborts_msgs/FricWhl.h"
#include "gazebo_msgs/GetLinkState.h"
#include "geometry_msgs/Pose.h"


#include <ignition/math/Pose3.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Quaternion.hh>

namespace gazebo
{
    class RobortsShooterPlugin : public ModelPlugin
    {
    
        public: RobortsShooterPlugin() : ModelPlugin()
        {
        }

        public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
        {
            this->model_ = _parent;
            this->gimbal_link = _sdf->Get<std::string>("gimbal_link");
            this->reference_frame_ = _sdf->Get<std::string>("reference_frame");
            
            // Initialize ros, if it has not already bee initialized.
            if (!ros::isInitialized())
            {
                int argc = 0;
                char **argv = NULL;
                ros::init(argc, argv, "roborts_shooter_node",
                    ros::init_options::NoSigintHandler);
            }

            // Create our ROS node. This acts in a similar manner to
            // the Gazebo node
            // this->ros_nh_.reset(new ros::NodeHandle("roborts_shooter_node"));

            //ros service
            this->gazebo_ros_link_state = this->ros_nh_.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
            
            srv.request.link_name = this->gimbal_link;
            srv.request.reference_frame = this->reference_frame_;

            

            // ros::SubscribeOptions so =
            //     ros::SubscribeOptions::create<std_msgs::Float32>(
            //         earthquake_freq_topicName,
            //         1,
            //         boost::bind(&RobortsShooterPlugin::OnRosMsg, this, _1),
            //         ros::VoidPtr(), &this->rosQueue);
            // this->rosSub = this->rosNode->subscribe(so);
            
            // // Spin up the queue helper thread.
            // this->rosQueueThread =
            //     std::thread(std::bind(&RobortsShooterPlugin::QueueThread, this));

            // ros::Publisher pub = ros_nh_.advertise<geometry_msgs::Pose>("gimbal_pose", 1);
            // pub.publish(this->gimbal_pose);
            

            // this->ros_ctrl_fric_wheel_srv_ = ros_nh_.advertiseService("cmd_fric_wheel", &RobortsShooterPlugin::CtrlFricWheelService, this);
            // this->ros_ctrl_shoot_srv_ = ros_nh_.advertiseService("cmd_shoot", &RobortsShooterPlugin::CtrlShootService, this);

            // this->ros_shoot_state_pub_ = ros_nh_.advertise<roborts_msgs::ShootState>("shoot_state",1);
            // this->ros_shoot_info_pub_ = ros_nh_.advertise<roborts_msgs::ShootInfo>("shoot_info",1);

            // Listen to the update event. This event is broadcast every
            // simulation iteration.
            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&RobortsShooterPlugin::OnUpdate, this));

            this->old_secs =ros::Time::now().toSec();

            GetBulletList();
            OutputBulletList();

            ROS_INFO("Roborts Shooter Ready....");

        }

        // // need to be fixed!
        // bool RobortsShooterPlugin::CtrlFricWheelService(roborts_msgs::FricWhl::Request &req,
        //                                 roborts_msgs::FricWhl::Response &res){
        //     roborts_sdk::cmd_fric_wheel_speed fric_speed;
        //     if(req.open){
        //         fric_speed.left = 1200;
        //         fric_speed.right = 1200;
        //     } else{
        //         fric_speed.left = 1000;
        //         fric_speed.right = 1000;
        //     }
        //     fric_wheel_pub_->Publish(fric_speed);
        //     res.received = true;
        //     return true;
        // }

        // // need to be fixed!
        // bool RobortsShooterPlugin::CtrlShootService(roborts_msgs::ShootCmd::Request &req,
        //                             roborts_msgs::ShootCmd::Response &res){
        //     roborts_sdk::cmd_shoot_info gimbal_shoot;
        //     uint16_t default_freq = 1500;
        //     switch(static_cast<roborts_sdk::shoot_cmd_e>(req.mode)){
        //         case roborts_sdk::SHOOT_STOP:
        //         gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_STOP;
        //         gimbal_shoot.shoot_add_num = 0;
        //         gimbal_shoot.shoot_freq = 0;
        //         break;
        //         case roborts_sdk::SHOOT_ONCE:
        //         if(req.number!=0){
        //             gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_ONCE;
        //             gimbal_shoot.shoot_add_num = req.number;
        //             gimbal_shoot.shoot_freq = default_freq;
        //         }
        //         else{
        //             gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_ONCE;
        //             gimbal_shoot.shoot_add_num = 1;
        //             gimbal_shoot.shoot_freq = default_freq;
        //         }
        //         break;
        //         case roborts_sdk::SHOOT_CONTINUOUS:
        //         gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_CONTINUOUS;
        //         gimbal_shoot.shoot_add_num = req.number;
        //         gimbal_shoot.shoot_freq = default_freq;
        //         break;
        //         default:
        //         return  false;
        //     }
        //     gimbal_shoot_pub_->Publish(gimbal_shoot);

        //     res.received = true;
        //     return true;
        // }

        // Called by the world update start event
        public: void OnUpdate()
        {


            if(gazebo_ros_link_state.call(srv) && srv.response.success){
                this->gimbal_pose.position.x = srv.response.link_state.pose.position.x;
                this->gimbal_pose.position.y = srv.response.link_state.pose.position.y;
                this->gimbal_pose.position.z = srv.response.link_state.pose.position.z;

                this->gimbal_pose.orientation.x = srv.response.link_state.pose.orientation.x;
                this->gimbal_pose.orientation.y = srv.response.link_state.pose.orientation.y;
                this->gimbal_pose.orientation.z = srv.response.link_state.pose.orientation.z;
                this->gimbal_pose.orientation.w = srv.response.link_state.pose.orientation.w;

                // ROS_INFO("%f", this->gimbal_pose.position.x);
                // ROS_INFO("%f", this->gimbal_pose.position.y);
                // ROS_INFO("%f", this->gimbal_pose.position.z);
            }

        //     if (this->reseting_plugin)
        //     {
        //         ROS_ERROR("Reseting in Process, please wait...");
        //     } else
        //     {
        //         // TODO: Check what is necessary now here
        //         double new_secs =this->world->GetSimTime().Float();
        //         double delta = new_secs - this->old_secs;

        //         double max_delta = 0.0;

        //         if (this->reset_frequency != 0.0)
        //         {
        //         max_delta = 1.0 / this->reset_frequency;
        //         }

        //         if (delta > max_delta && delta != 0.0)
        //         {
        //             // We update the Old Time variable.
        //             this->old_secs = new_secs;
                    
                    
        //             if (this->model_to_update_index_now >= this->modelIDToName_size)
        //             {
        //                 this->model_to_update_index_now = 0;
        //             }
                
        //             // Update the Particles
        //             UpdateParticles(this->model_to_update_index_now);
        //             this->model_to_update_index_now ++;
        //         }
        //     }
        }

        void WaitForseconds(float seconds_to_wait)
        {
            unsigned int microseconds;
            microseconds = seconds_to_wait * 1e6;
            ROS_WARN("Waiting for %f seconds",seconds_to_wait);
            usleep(microseconds);
            ROS_WARN("Done waiting...");

        }

        // void UpdateParticles(int model_to_update_index)
        // {
        //     for (auto model : this->world->GetModels())
        //     {
        //         std::string model_name = model->GetName();
        //         if (this->modelIDToName[model_to_update_index] == model_name)
        //         {
        //             this->MoveParticle(model);
        //             this->SetForceParticle(model);
        //         }
                
        //     }
        // }
        
        
        
        void GetBulletList()
        {
            this->linkIDToName.clear();
            // Initialize color map.
            this->linkIDToName_size = 0;
            
            int i = 0;
            for (auto link : this->model_->GetLinks())
            {
                std::string link_name = link->GetName();
                ROS_WARN("%s", link_name.c_str());
                if (link_name.find("pitch_Link") != std::string::npos)
                {
                    ROS_WARN("hh");
                    for(auto child_link : link->GetChildJointsLinks()) {
                        std::string child_link_name = child_link->GetName();
                        ROS_WARN("%s", child_link_name.c_str());
                        if (child_link_name.find(this->bullet_link_name) != std::string::npos) {
                            
                            this->linkIDToName[i] = child_link->GetName();
                            i ++;
                        }
                        
                    }
                    
                }
            
            }
            ROS_WARN("%s", this->model_->GetLink("bullet_0")->GetName().c_str());
            
            this->linkIDToName_size = linkIDToName.size();
            ROS_WARN("linkIDToName Size : %d", this->linkIDToName_size);
        }
        
        void OutputBulletList()
        {
            ROS_WARN("Start OutputBulleteList...");

            for (auto const& x : this->linkIDToName)
            {
                ROS_WARN("LinkID=%i, Name=%s", x.first, x.second.c_str());
            }

            ROS_WARN("END OutputBulletList...");

        }
        
        
        // void MoveParticle(boost::shared_ptr<gazebo::physics::Model> model)
        // {

        //     std::string model_name = model->GetName();

        //     float x_pos_rand = 0.0;
        //     float y_pos_rand = 0.0;
        //     float z_pos_rand = 0.0;
        //     float roll_rand = 0.0;
        //     float pitch_rand = 0.0;
        //     float yaw_rand = 0.0;

        //     // If the model name contains the substring particle, we consider it a particle
        //     if (model_name.find(this->particle_base_name) != std::string::npos)
        //     {
        //         ROS_WARN("Moving model=%s",model_name.c_str());

        //         float x_pos_rand = RandomFloat(this->x_origin - this->random_range, this->x_origin + this->random_range);
        //         float y_pos_rand = RandomFloat(this->y_origin - this->random_range, this->y_origin + this->random_range);
        //         float z_pos_rand = RandomFloat(this->z_origin - this->random_range, this->z_origin + this->random_range);
                
        //         ROS_DEBUG("POSE-RANDOM[X,Y,Z,Roll,Pitch,Yaw=[%f,%f,%f,%f,%f,%f], model=%s", x_pos_rand,y_pos_rand,z_pos_rand,roll_rand,pitch_rand,yaw_rand,model_name.c_str());
        //         //ignition::math::Pose3 initPose(ignition::math::Vector3<float>(x_pos_rand, y_pos_rand, z_pos_rand), ignition::math::Quaternion<float>(roll_rand, pitch_rand, yaw_rand));
                
        //         model->SetWorldPose(
        //                             ignition::math::Pose3d(
        //                                 ignition::math::Vector3d(x_pos_rand, y_pos_rand, z_pos_rand),
        //                                 ignition::math::Quaterniond(roll_rand, pitch_rand, yaw_rand)
        //                                                 )
        //                             );
                
        //         ROS_DEBUG("Moving model=%s....END",model_name.c_str());

        //     }

            

        // }
        
        
        void SetForceBullet(boost::shared_ptr<gazebo::physics::Link> link)
        {
            
            std::string link_name = link->GetName();

            // If the model name contains the substring particle, we consider it a particle
            if (link_name.find(this->bullet_link_name) != std::string::npos)
            {
                ROS_WARN("FORCE APPLIED[X,Y,Z]=[%f,%f,%f]", this->x_axis_force, this->y_axis_force, this->z_axis_force);
                link->SetForce(ignition::math::Vector3d(this->x_axis_force, this->y_axis_force, this->z_axis_force));
            }
        }


        // public: void SetFrequency(const double &_freq)
        // {
        // this->x_axis_freq = _freq;
        // ROS_WARN("x_axis_freq >> %f", this->x_axis_freq);
        // }
        
        // public: void SetMagnitude(const double &_magn)
        // {
        // this->x_axis_magn = _magn;
        // ROS_WARN("x_axis_magn >> %f", this->x_axis_magn);
        // }
        
        
        // public: void OnRosMsg(const std_msgs::Float32ConstPtr &_msg)
        // {
        // this->SetFrequency(_msg->data);
        // }
        
        // /// \brief ROS helper function that processes messages
        // private: void QueueThread()
        // {
        // static const double timeout = 0.01;
        // while (this->rosNode->ok())
        // {
        //     this->rosQueue.callAvailable(ros::WallDuration(timeout));
        // }
        // }
        
        
        // Pointer to the update event connection
        private: event::ConnectionPtr updateConnection;
        

        /// \brief A node use for ROS transport
        // private: std::unique_ptr<ros::NodeHandle> rosNode;
        
        // /// \brief A ROS subscriber
        // private: ros::Subscriber rosSub;
        // /// \brief A ROS callbackqueue that helps process messages
        // private: ros::CallbackQueue rosQueue;
        // /// \brief A thread the keeps running the rosQueue
        // private: std::thread rosQueueThread;
        
        
        // /// \brief A ROS subscriber
        // private: ros::Subscriber rosSub2;
        // /// \brief A ROS callbackqueue that helps process messages
        // private: ros::CallbackQueue rosQueue2;
        // /// \brief A thread the keeps running the rosQueue
        // private: std::thread rosQueueThread2;

        private:
            gazebo::physics::ModelPtr model_;

            ros::NodeHandle ros_nh_;

            // ros::Publisher ros_shoot_info_pub_;
            // ros::Publisher ros_shoot_state_pub_;

            ros::ServiceServer ros_ctrl_fric_wheel_srv_;
            ros::ServiceServer ros_ctrl_shoot_srv_;

            ros::ServiceClient gazebo_ros_link_state;
            geometry_msgs::Pose gimbal_pose;
            gazebo_msgs::GetLinkState srv;

            std::string gimbal_link;
            std::string reference_frame_;

        /// \brief Maps model IDs to ModelNames
        private: std::map<int, std::string> linkIDToName;
        
        
        // Update Loop frequency, rate at which we restart the positions and apply force to particles
        double reset_frequency = 2.0;
        // Time Memory
        double old_secs;
        // Force Direction
        double x_axis_force = 0.0;
        double y_axis_force = 0.0;
        double z_axis_force = 0.0;

        // Reseting Flag
        bool reseting_plugin = false;
        
        int linkIDToName_size = 0;
        int link_to_update_index_now = 0;
        
        std::string bullet_link_name = "bullet";
    };
    GZ_REGISTER_MODEL_PLUGIN(RobortsShooterPlugin)
}