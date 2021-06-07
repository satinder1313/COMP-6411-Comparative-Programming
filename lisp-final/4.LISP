;question number 4

(defun dist(n lst)
  (cond ((and (atom n) (> (length lst) 0))
      (format t "~% n is an atom and a list ") (cons (cons n (car lst)) (dist n (cdr lst))))
      (t (format t "~% no case is true" n))
  )      
)

(write(dist 40 '(a b c)))