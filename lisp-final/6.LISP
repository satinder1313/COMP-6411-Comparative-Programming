;question-6

(defun oseq(n)
  (cond ((= n 1) nil)
    (t (loop for i from 1 to n
      when (/= (mod i 2) 0) collect i))))       

;test
(print (oseq 5))
(print (oseq 0))