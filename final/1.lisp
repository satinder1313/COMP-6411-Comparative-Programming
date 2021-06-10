;Defining function mathematically
;Base Case:
; f(nil lst1) = lst2
;Recursive Case:
; f(n) = (cons (car lst1) (append2 (cdr lst1) lst2))

(defun consr(lst1 elt)
  (if(null lst1)
    (cons elt '())
    (cons (car lst1) (consr (cdr lst1) elt))
   )
)