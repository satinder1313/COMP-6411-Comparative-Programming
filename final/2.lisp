(defun fn2 (obj)
	(typecase obj
        (cons #'append)
        (number #'+))
)

(defun combine2 (&rest args)
	(apply (fn2 (car args)) args)
)