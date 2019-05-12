;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::YoloDetectionGoal)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'YoloDetectionGoal (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::YOLODETECTIONGOAL")
  (make-package "ICRA_ROBOIN_MSGS::YOLODETECTIONGOAL"))

(in-package "ROS")
;;//! \htmlinclude YoloDetectionGoal.msg.html


(defclass icra_roboin_msgs::YoloDetectionGoal
  :super ros::object
  :slots (_command ))

(defmethod icra_roboin_msgs::YoloDetectionGoal
  (:init
   (&key
    ((:command __command) 0)
    )
   (send-super :init)
   (setq _command (round __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; uint8 _command
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _command
       (write-byte _command s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _command
     (setq _command (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get icra_roboin_msgs::YoloDetectionGoal :md5sum-) "36e1d21d1340e2a5e93f075b6457cbdf")
(setf (get icra_roboin_msgs::YoloDetectionGoal :datatype-) "icra_roboin_msgs/YoloDetectionGoal")
(setf (get icra_roboin_msgs::YoloDetectionGoal :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#Send a flag to server to control the thread start, pause, restart and stop
#command == 1 start
#command == 2 pause
#command == 3 stop
uint8 command

")



(provide :icra_roboin_msgs/YoloDetectionGoal "36e1d21d1340e2a5e93f075b6457cbdf")

