;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::AmmoConsume)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'AmmoConsume (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::AMMOCONSUME")
  (make-package "ICRA_ROBOIN_MSGS::AMMOCONSUME"))
(unless (find-package "ICRA_ROBOIN_MSGS::AMMOCONSUMEREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::AMMOCONSUMEREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::AMMOCONSUMERESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::AMMOCONSUMERESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::AmmoConsumeRequest
  :super ros::object
  :slots (_shots ))

(defmethod icra_roboin_msgs::AmmoConsumeRequest
  (:init
   (&key
    ((:shots __shots) 0)
    )
   (send-super :init)
   (setq _shots (round __shots))
   self)
  (:shots
   (&optional __shots)
   (if __shots (setq _shots __shots)) _shots)
  (:serialization-length
   ()
   (+
    ;; int16 _shots
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _shots
       (write-word _shots s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _shots
     (setq _shots (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass icra_roboin_msgs::AmmoConsumeResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::AmmoConsumeResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::AmmoConsume
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::AmmoConsume :md5sum-) "5a21dae1d703fd52723eaf9cba0ba9be")
(setf (get icra_roboin_msgs::AmmoConsume :datatype-) "icra_roboin_msgs/AmmoConsume")
(setf (get icra_roboin_msgs::AmmoConsume :request) icra_roboin_msgs::AmmoConsumeRequest)
(setf (get icra_roboin_msgs::AmmoConsume :response) icra_roboin_msgs::AmmoConsumeResponse)

(defmethod icra_roboin_msgs::AmmoConsumeRequest
  (:response () (instance icra_roboin_msgs::AmmoConsumeResponse :init)))

(setf (get icra_roboin_msgs::AmmoConsumeRequest :md5sum-) "5a21dae1d703fd52723eaf9cba0ba9be")
(setf (get icra_roboin_msgs::AmmoConsumeRequest :datatype-) "icra_roboin_msgs/AmmoConsumeRequest")
(setf (get icra_roboin_msgs::AmmoConsumeRequest :definition-)
      "int16 shots
---
bool success

")

(setf (get icra_roboin_msgs::AmmoConsumeResponse :md5sum-) "5a21dae1d703fd52723eaf9cba0ba9be")
(setf (get icra_roboin_msgs::AmmoConsumeResponse :datatype-) "icra_roboin_msgs/AmmoConsumeResponse")
(setf (get icra_roboin_msgs::AmmoConsumeResponse :definition-)
      "int16 shots
---
bool success

")



(provide :icra_roboin_msgs/AmmoConsume "5a21dae1d703fd52723eaf9cba0ba9be")


