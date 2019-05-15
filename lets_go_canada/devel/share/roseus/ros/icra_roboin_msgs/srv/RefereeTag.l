;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeTag)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeTag (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREETAG")
  (make-package "ICRA_ROBOIN_MSGS::REFEREETAG"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREETAGREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREETAGREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREETAGRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREETAGRESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::RefereeTagRequest
  :super ros::object
  :slots ())

(defmethod icra_roboin_msgs::RefereeTagRequest
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

(defclass icra_roboin_msgs::RefereeTagResponse
  :super ros::object
  :slots (_info _success ))

(defmethod icra_roboin_msgs::RefereeTagResponse
  (:init
   (&key
    ((:info __info) 0)
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _info (round __info))
   (setq _success __success)
   self)
  (:info
   (&optional __info)
   (if __info (setq _info __info)) _info)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; int16 _info
    2
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _info
       (write-word _info s)
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _info
     (setq _info (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeTag
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeTag :md5sum-) "e156420e06769c10db65b694db7ee8bc")
(setf (get icra_roboin_msgs::RefereeTag :datatype-) "icra_roboin_msgs/RefereeTag")
(setf (get icra_roboin_msgs::RefereeTag :request) icra_roboin_msgs::RefereeTagRequest)
(setf (get icra_roboin_msgs::RefereeTag :response) icra_roboin_msgs::RefereeTagResponse)

(defmethod icra_roboin_msgs::RefereeTagRequest
  (:response () (instance icra_roboin_msgs::RefereeTagResponse :init)))

(setf (get icra_roboin_msgs::RefereeTagRequest :md5sum-) "e156420e06769c10db65b694db7ee8bc")
(setf (get icra_roboin_msgs::RefereeTagRequest :datatype-) "icra_roboin_msgs/RefereeTagRequest")
(setf (get icra_roboin_msgs::RefereeTagRequest :definition-)
      "---

int16 info
bool success


")

(setf (get icra_roboin_msgs::RefereeTagResponse :md5sum-) "e156420e06769c10db65b694db7ee8bc")
(setf (get icra_roboin_msgs::RefereeTagResponse :datatype-) "icra_roboin_msgs/RefereeTagResponse")
(setf (get icra_roboin_msgs::RefereeTagResponse :definition-)
      "---

int16 info
bool success


")



(provide :icra_roboin_msgs/RefereeTag "e156420e06769c10db65b694db7ee8bc")


