"Exercise 1.1. Below is a sequence of expressions. What 
is the result printed by the interpreter in response to
each expression? Assume that the sequence is to be evaluated
in the order in which it is presented."
10
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))
(def 3)
(def b (+ a 1))
(+ a b (* a b))
(= a b)
(if (and (> b a) (< b (* a b)))
  b
  a)
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      :else 25)
(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)
     ((< a b) b)
     :else -1)
   (+ a 1))

"Exercise 1.2. Translate the following expression
into prefix form"
(/ 
  (+ 5 4 
    (- 2 
      (- 3 
        (+ 6 
          (float (/ 4 5)))))) 
  (* 3 
    (- 6 2) 
    (- 2 7)))

"Exercise 1.3. Define a procedure that takes three numbers
as arguments and returns the sum of the squares of the
two larger numbers."
(defn sum-of-squares [a b]
  (+ (* a a) (* b b)))

(defn fib [n]
  (cond (= n 0) 0
        (= n 1) 1
        :else (+ (fib (- n 1))
                 (fib (- n 2)))))

(defn iter-fib [n]
  (defn fib-iter [a b count]
    (if (= count 0)
      b
      (fib-iter (+ a b) a (- count 1))))
  (fib-iter 1 0 n))

(defn count-change [amount]
  (def first-denomination { 1 1
                            2 5
                            3 10
                            4 25
                            5 50 })
  (defn cc [amount kinds-of-coins]
    (cond (= amount 0) 1
          (or (< amount 0) (= kinds-of-coins 0)) 0
          :else (+ (cc amount
                       (- kinds-of-coins 1))
                   (cc (- amount
                         (first-denomination kinds-of-coins))
                       kinds-of-coins)))) 
  (cc amount 5))
                           
(defn pascals-triangle [num-levels]
  (defn make-row [m]))

(defn cube [x] (* x x x))
(defn p [x] (- (* 3 x) (* 4 (cube x))))
(defn sine [angle]
  (if (not (> (Math/abs angle) 0.1))
    angle
    (p (sine (/ angle 3.0))))) 

(defn expt [b n]
  (defn expt-iter [b counter product]
    (if (= counter 0)
      product
      (expt-iter b
                 (- counter 1)
                 (* b product))))
  (expt-iter b n 1))

(defn square [n] (* n n))
(defn fast-expt [b n]
  (cond (= n 0) 1
        (even? n) (square (fast-expt b (/ n 2)))
        :else (* b (fast-expt b (- n 1)))))

(defn gcd [a b]
  (if (= b 0)
    a
    (gcd b (rem a b))))

(defn smallest-divisor [n]
  (defn divides? [a b] (= (rem b a) 0))
  (defn find-divisor [n test-divisor]
    (cond (> (square test-divisor) n) n
          (divides? test-divisor n) test-divisor
          :else (find-divisor n (+ test-divisor 1))))
  (find-divisor n 2))

(defn prime? [n]
  (= n (smallest-divisor n)))

(defn expmod [base exp m]
  (cond (= exp 0) 1
        (even? exp) (rem (square (expmod base (/ exp 2) m)) m)
        :else (rem (* base (expmod base (- exp 1) m)) m)))

(defn fermat-test [n]
  (defn try-it [a]
    (= (expmod a n n) a))
  (try-it (+ 1 (rand (- n 1)))))

(defn fast-prime? [n times]
  (cond (= times 0) true
        (fermat-test n) (fast-prime? n (- times 1))
        :else false))

(defn timed-prime-test [n]
  (defn start-prime-test [n]
    (if (prime? n)
      (println n)))
  (time (start-prime-test n)))

(defn sum [term a next b]
  (if (> a b)
    0
    (+ (term a)
       (sum term (next a) next b))))
(defn sum-cubes [a b]
  (sum cube a inc b))
(defn sum-integers [a b]
  (sum identity a inc b))
(defn pi-sum [a b]
  (defn pi-term [x]
    (/ 1.0 (* x (+ x 2))))
  (defn pi-next [x]
    (+ x 4))
  (sum pi-term a pi-next b))

(defn integral [f a b dx]
  (defn add-dx [x] (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))

(defn simpsons-integral [f a b n]
  (def h (/ (- b a) n))
  (atom counter 0)
  (defn next-h [x] (+ x h))
  (defn cycle-coefficients [m]
    (set! counter (+ counter 1))
    (println counter)
    (cond (or (= counter 0) (= counter n)) 1
          (odd? counter) 4
          :else 2))
  (println h)
  (* (/ h 3) (sum cycle-coefficients a next-h b)))
