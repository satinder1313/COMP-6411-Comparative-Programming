

(defun LTree (X)
    (if (endp X)
        '()
        (car (cdr X))
    )
)


(defun RTree (X)
    (if (endp X)
        '()
        (car (cdr (cdr X)))
    )
)

(defun greater1 (element X)
    (if (endp X)
        t
        (and (> (car X) element)
             (greater1 element (LTree X))
             (greater1 element (RTree X))
        )
    )
)


(defun smaller1 (element X)
    (if (endp X)
        t
        (and (<= (car X) element)
             (smaller1 element (LTree X))
             (smaller1 element (RTree X))
        )
    )
)

(defun isBinarySearchTree (X)
    (if (endp X)
        t
        (and (smaller1 (car X) (LTree X))
             (greater1 (car X) (RTree X))
             (isBinarySearchTree (LTree X))
             (isBinarySearchTree (RTree X))
        )
    )
)


(defun is-bst (X)
    (if (isBinarySearchTree X)
        'YES
        'NO
    )
)