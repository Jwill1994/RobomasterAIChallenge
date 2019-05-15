;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeShoot)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeShoot (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREESHOOT")
  (make-package "ICRA_ROBOIN_MSGS::REFEREESHOOT"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREESHOOTREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREESHOOTREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREESHOOTRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREESHOOTRESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::RefereeShootRequest
  :super ros::object
  :slots (_x _y ))

(defmethod icra_roboin_msgs::RefereeShootRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; float64 _x
    8
    ;; float64 _y
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeShootResponse
  :super ros::object
  :slots (_judgement _success ))

(defmethod icra_roboin_msgs::RefereeShootResponse
  (:init
   (&key
    ((:judgement __judgement) 0)
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _judgement (round __judgement))
   (setq _success __success)
   self)
  (:judgement
   (&optional __judgement)
   (if __judgement (setq _judgement __judgement)) _judgement)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; int16 _judgement
    2
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _judgement
       (write-word _judgement s)
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _judgement
     (setq _judgement (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeShoot
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeShoot :md5sum-) "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(setf (get icra_roboin_msgs::RefereeShoot :datatype-) "icra_roboin_msgs/RefereeShoot")
(setf (get icra_roboin_msgs::RefereeShoot :request) icra_roboin_msgs::RefereeShootRequest)
(setf (get icra_roboin_msgs::RefereeShoot :response) icra_roboin_msgs::RefereeShootResponse)

(defmethod icra_roboin_msgs::RefereeShootRequest
  (:response () (instance icra_roboin_msgs::RefereeShootResponse :init)))

(setf (get icra_roboin_msgs::RefereeShootRequest :md5sum-) "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(setf (get icra_roboin_msgs::RefereeShootRequest :datatype-) "icra_roboin_msgs/RefereeShootRequest")
(setf (get icra_roboin_msgs::RefereeShootRequest :definition-)
      "float64 x
float64 y
---

int16 judgement
bool success

")

(setf (get icra_roboin_msgs::RefereeShootResponse :md5sum-) "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(setf (get icra_roboin_msgs::RefereeShootResponse :datatype-) "icra_roboin_msgs/RefereeShootResponse")
(setf (get icra_roboin_msgs::RefereeShootResponse :definition-)
      "float64 x
float64 y
---

int16 judgement
bool success

")



(provide :icra_roboin_msgs/RefereeShoot "e5d6900e0dd94f9bda0c89e5f1af2cd8")


