;question-8

(defun validity (switch)
     (if (> switch 0)
              (print "This is not a valid")
              (print "This is valid")
             )
    )

(setq switch '())


(defun isValid (tree)
    (let ((root (car tree)))
    (let ((leftChildNode (car (car (cdr tree)))))
    (let ((rightChildNode (car (car (cdr (cdr tree))))))
    (let ((leftChild (car (cdr tree))))
    (let ((rightChild (car (cdr (cdr tree)))))
         
         ; Case 1: 1 left & 1 right child 
         (if (and (not (eq leftChild () )) (not (eq rightChild () )))
             (if (and (or (> root leftChildNode) (= root leftChildNode)) (< root rightChildNode))
                 (progn
                     (isValid leftChild)
                     (isValid rightChild)
                  )
             (setq switch (append switch '(F)))
              
             )        
        )
         
         ; Case 2: 1 left, 0 right (and (not (= leftChild () )) (= rightChild () ) ) 
        
         (if  (and (not (eq leftChild () ))  (eq rightChild () ))
          (if (or (> root leftChildNode) (= root leftChildNode)) 
             (isValid leftChild)
             (setq switch (append switch '(F)))
          )         
         )
         
         ; Case 3: 0 left, 1 right (and (= leftChild () )) (not (= rightChild () ) ))
         (if (and (eq leftChild () ) (not (eq rightChild () )))
          (if (< root rightChildNode)         
             (isValid rightChild)
             (setq switch (append switch '(F)))
                     
          )
         )
    
         ;Case 4: 0 left, 0 right 
         (if (and (eq leftChild () ) (eq rightChild () ))
             (return-from isValid)
         )
         
         
         )
        )
       )
      )
     )
    (print switch)
    )