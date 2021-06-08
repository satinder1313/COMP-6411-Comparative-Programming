;question-6

(defun oseq(n)
  (let ((i 0) (lst '()))
    (loop 
     (when (> i n ) lst  (return))
     (print lst) (append lst (list i))
     (incf i)
    )
  )
)


;test
(print (oseq 5))