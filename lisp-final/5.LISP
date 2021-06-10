; question 5

;helper function to remove all the occurrences 
(defun remove-all-occurrences( lst elt)
  (if (null lst)
  nil
  (if (equal (car lst) elt)
      (remove-all-occurrences (cdr lst) elt)
      (cons (car lst) (remove-all-occurrences (cdr lst) elt))
  ))
)

;test of above function
;(print (remove-all-occurrences `(1 2 3 4 4) 4))


; main function that find duplicates and remove all its occurrences 
(defun rem-if-dupl(arg)
  (cond ((null arg) nil)
        ((member (car arg) (cdr arg))
        (rem-if-dupl (remove-all-occurrences (cdr arg) (car arg))))
        (t (cons (car arg) (rem-if-dupl (cdr arg))))
  )
)

;test of main function
(print (rem-if-dupl nil))
(print (rem-if-dupl `(1 1)))
(print (rem-if-dupl `(1 2 2 3 4)))
(print (rem-if-dupl `(1 2 3 4)))
(print (rem-if-dupl `(1 2 3 4 2)))
