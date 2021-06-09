(defun append2 (lst1 lst2)
(if (null lst1)
lst2
(cons (car lst1) (append2 (cdr lst1) lst2))))