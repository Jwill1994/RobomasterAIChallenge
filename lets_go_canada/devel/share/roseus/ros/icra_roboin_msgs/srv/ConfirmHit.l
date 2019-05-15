;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::ConfirmHit)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'ConfirmHit (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::CONFIRMHIT")
  (make-package "ICRA_ROBOIN_MSGS::CONFIRMHIT"))
(unless (find-package "ICRA_ROBOIN_MSGS::CONFIRMHITREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::CONFIRMHITREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::CONFIRMHITRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::CONFIRMHITRESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::ConfirmHitRequest
  :super ros::object
  :slots ())

(defmethod icra_roboin_msgs::ConfirmHitRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass icra_roboin_msgs::ConfirmHitResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::ConfirmHitResponse
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

(defclass icra_roboin_msgs::ConfirmHit
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::ConfirmHit :md5sum-) "358e233cde0c8a8bcfea4ce193f8fc15")
(setf (get icra_roboin_msgs::ConfirmHit :datatype-) "icra_roboin_msgs/ConfirmHit")
(setf (get icra_roboin_msgs::ConfirmHit :request) icra_roboin_msgs::ConfirmHitRequest)
(setf (get icra_roboin_msgs::ConfirmHit :response) icra_roboin_msgs::ConfirmHitResponse)

(defmethod icra_roboin_msgs::ConfirmHitRequest
  (:response () (instance icra_roboin_msgs::ConfirmHitResponse :init)))

(setf (get icra_roboin_msgs::ConfirmHitRequest :md5sum-) "358e233cde0c8a8bcfea4ce193f8fc15")
(setf (get icra_roboin_msgs::ConfirmHitRequest :datatype-) "icra_roboin_msgs/ConfirmHitRequest")
(setf (get icra_roboin_msgs::ConfirmHitRequest :definition-)
      "---
bool success

")

(setf (get icra_roboin_msgs::ConfirmHitResponse :md5sum-) "358e233cde0c8a8bcfea4ce193f8fc15")
(setf (get icra_roboin_msgs::ConfirmHitResponse :datatype-) "icra_roboin_msgs/ConfirmHitResponse")
(setf (get icra_roboin_msgs::ConfirmHitResponse :definition-)
      "---
bool success

")



(provide :icra_roboin_msgs/ConfirmHit "358e233cde0c8a8bcfea4ce193f8fc15")


