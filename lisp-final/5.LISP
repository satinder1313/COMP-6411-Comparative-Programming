; question 5

(defun rem-if-dupl(lst)
  (if lst
      (if (member (car lst) (cdr lst))
          (cons (car lst) (rem-if-dupl (vl-remove (car lst) (cdr lst))))
          (rem-if-dupl (vl-remove (car lst) (cdr lst)))
      )
   ) 
)

;(print (rem-if-dupl nil))
(print (rem-if-dupl `(1 1)))
(print (rem-if-dupl `(1 2 2 3 4)))
(print (rem-if-dupl `(1 2 3 4)))
(print (rem-if-dupl `(1 2 3 4 2)))
