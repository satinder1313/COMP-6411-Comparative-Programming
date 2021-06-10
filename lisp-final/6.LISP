;question-6     


(defun oseqa(num)
  (let ((lst (list (cond ((= num 1) 0)
                         ((= (rem num 2) 1)(- num 2))
                         (t (- num 1))
              ))))
              (print num)
              (print lst)
              (loop 
                   (when (= (car lst) 0)(return nil))
                   (when (= (car lst) 1)(return lst))
                   (setq num (- (car lst) 2))
                   (setq lst (cons num lst))
)))



(defun oseql(num)
    (format t  " ~% start: " num)
    (let ((lst (list (cond ((= num 1) 0)
                           ((= (rem num 2) 1)(- num 2))
                           (t (- num 1))
                ))))
                (print num)
                (print lst)
                                
                (setq num (- (car lst) 2))
                ;(setq lst (cons num lst))
                (print num)
                (print lst)

                (if (> (car lst) 1)    
                     (oseq num)
                     nil
                     ;(cons (oseq num) (car lst))                     
                     ;(cons val lst)  
                    
                )
                (setq lst (cons num lst))
                
    )
)    

(defun oseq(num)
   (if (> num 1)
       (if (= (rem num 2) 1)
           (cons (oseq (- num 2)) (- num 2))
           (cons (oseq (- num 1)) (- num 1))
       )
       nil)
)

;test
(print (oseq 1))
(print (oseq 2))
(print (oseq 10))
(print (oseq 11))