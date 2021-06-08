;question-9

(defun getMax (x y)
    (COND
        ((NOT (NUMBERP x)) y)
        ((NOT (NUMBERP y)) x)
        ((>= x y) x)
        (y)
    )
)

(defun absValue (value)
    (COND
    ((NOT (NUMBERP value)) value)
    ((< value 0) (- 0 value))
    (value)
    )
)

(defun height (tree)
    (COND
        ((NULL tree) 0)
        ((OR (EQUAL -1 (height (CADR tree))) (EQUAL -1 (height (CADDR tree)))) -1)
        ((> (absValue (- (height (CADR tree)) (height (CADDR tree)))) 1) -1)
        ((+ 1 (getMax (height (CADR tree)) (height (CADDR tree)))))
    )
)