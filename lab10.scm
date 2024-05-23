// Q1

(define (greetings name age) (display (string-append "Hello " name ", you are " age " years old." )) )
(greetings "world" "4.6 billion")

// alternative solution
(define (greetings name age) (string-append "Hello " name ", you are " age " years old." )) 
(display (greetings "world" "4.6 billion"))


(display "\n\n")


// Q2

(define (list-square ls)
  (if (null? ls)
      '()
      (cons (* (car ls) (car ls))
	    (list-square (cdr ls)) )))

(display (list-square '(1 2 3 4 5 6 7 8 9 10)))


(display "\n\n")

// Q3

(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

(display (factorial 6))