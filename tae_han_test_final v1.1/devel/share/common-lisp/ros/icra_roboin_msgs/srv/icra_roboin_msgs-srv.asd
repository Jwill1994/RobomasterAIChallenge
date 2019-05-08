
(cl:in-package :asdf)

(defsystem "icra_roboin_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "BlackboardGeneralInfo" :depends-on ("_package_BlackboardGeneralInfo"))
    (:file "_package_BlackboardGeneralInfo" :depends-on ("_package"))
  ))