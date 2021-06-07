; question 5

(defun rem-if-dupl(lst)
  (cond ((> (length lst) 0)
        (delete-duplicates lst))
  )
)

;(print (rem-if-dupl nil))
(print (rem-if-dupl `(1 1)))
(print (rem-if-dupl `(1 2 2 3 4)))
(print (rem-if-dupl `(1 2 3 4)))
(print (rem-if-dupl `(1 2 3 4 2)))
