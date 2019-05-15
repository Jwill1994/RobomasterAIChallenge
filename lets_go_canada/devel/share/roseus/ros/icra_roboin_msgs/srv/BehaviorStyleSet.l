;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::BehaviorStyleSet)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'BehaviorStyleSet (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESET")
  (make-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESET"))
(unless (find-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESETREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESETREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESETRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::BEHAVIORSTYLESETRESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::BehaviorStyleSetRequest
  :super ros::object
  :slots (_behavior ))

(defmethod icra_roboin_msgs::BehaviorStyleSetRequest
  (:init
   (&key
    ((:behavior __behavior) 0)
    )
   (send-super :init)
   (setq _behavior (round __behavior))
   self)
  (:behavior
   (&optional __behavior)
   (if __behavior (setq _behavior __behavior)) _behavior)
  (:serialization-length
   ()
   (+
    ;; uint8 _behavior
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _behavior
       (write-byte _behavior s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _behavior
     (setq _behavior (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::BehaviorStyleSetResponse
  :super ros::object
  :slots (_success _info ))

(defmethod icra_roboin_msgs::BehaviorStyleSetResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:info __info) 0)
    )
   (send-super :init)
   (setq _success __success)
   (setq _info (round __info))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:info
   (&optional __info)
   (if __info (setq _info __info)) _info)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; int16 _info
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; int16 _info
       (write-word _info s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int16 _info
     (setq _info (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass icra_roboin_msgs::BehaviorStyleSet
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::BehaviorStyleSet :md5sum-) "55497cc3dd55c5632392e3da32c9b591")
(setf (get icra_roboin_msgs::BehaviorStyleSet :datatype-) "icra_roboin_msgs/BehaviorStyleSet")
(setf (get icra_roboin_msgs::BehaviorStyleSet :request) icra_roboin_msgs::BehaviorStyleSetRequest)
(setf (get icra_roboin_msgs::BehaviorStyleSet :response) icra_roboin_msgs::BehaviorStyleSetResponse)

(defmethod icra_roboin_msgs::BehaviorStyleSetRequest
  (:response () (instance icra_roboin_msgs::BehaviorStyleSetResponse :init)))

(setf (get icra_roboin_msgs::BehaviorStyleSetRequest :md5sum-) "55497cc3dd55c5632392e3da32c9b591")
(setf (get icra_roboin_msgs::BehaviorStyleSetRequest :datatype-) "icra_roboin_msgs/BehaviorStyleSetRequest")
(setf (get icra_roboin_msgs::BehaviorStyleSetRequest :definition-)
      "uint8 behavior
---
bool success
int16 info

")

(setf (get icra_roboin_msgs::BehaviorStyleSetResponse :md5sum-) "55497cc3dd55c5632392e3da32c9b591")
(setf (get icra_roboin_msgs::BehaviorStyleSetResponse :datatype-) "icra_roboin_msgs/BehaviorStyleSetResponse")
(setf (get icra_roboin_msgs::BehaviorStyleSetResponse :definition-)
      "uint8 behavior
---
bool success
int16 info

")



(provide :icra_roboin_msgs/BehaviorStyleSet "55497cc3dd55c5632392e3da32c9b591")


