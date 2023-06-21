;; Auto-generated. Do not edit!


(when (boundp 'first_package::nums)
  (if (not (find-package "FIRST_PACKAGE"))
    (make-package "FIRST_PACKAGE"))
  (shadow 'nums (find-package "FIRST_PACKAGE")))
(unless (find-package "FIRST_PACKAGE::NUMS")
  (make-package "FIRST_PACKAGE::NUMS"))
(unless (find-package "FIRST_PACKAGE::NUMSREQUEST")
  (make-package "FIRST_PACKAGE::NUMSREQUEST"))
(unless (find-package "FIRST_PACKAGE::NUMSRESPONSE")
  (make-package "FIRST_PACKAGE::NUMSRESPONSE"))

(in-package "ROS")





(defclass first_package::numsRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod first_package::numsRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass first_package::numsResponse
  :super ros::object
  :slots (_sum ))

(defmethod first_package::numsResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass first_package::nums
  :super ros::object
  :slots ())

(setf (get first_package::nums :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get first_package::nums :datatype-) "first_package/nums")
(setf (get first_package::nums :request) first_package::numsRequest)
(setf (get first_package::nums :response) first_package::numsResponse)

(defmethod first_package::numsRequest
  (:response () (instance first_package::numsResponse :init)))

(setf (get first_package::numsRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get first_package::numsRequest :datatype-) "first_package/numsRequest")
(setf (get first_package::numsRequest :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")

(setf (get first_package::numsResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get first_package::numsResponse :datatype-) "first_package/numsResponse")
(setf (get first_package::numsResponse :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")



(provide :first_package/nums "4781436a0c2affec8025955a6041e481")


