;question number 4

(defun dist(n lst)
  (cond ((and (atom n) (> (length lst) 0))
      (cons (cons n (car lst)) (dist n (cdr lst))))
      (t (format t "~% output: " n))
  )      
)

(write(dist 40 '(a b c)))