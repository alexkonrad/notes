(defn make-rat
  "Return rational number from num and denom"
  [n d]
  (list n d))
(def numer first)
(def denom second)
(defn add-rat [x y]
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))
(defn sub-rat [x y]
  (make-rat (- (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))
(defn mul-rat [x y]
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))
(defn div-rat [x y]
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))
(defn equal-rat? [x y]
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))

(defn my-cons [x y]
  (fn [m] (m x y)))
(defn car [z]
  (z (fn [p q] p)))
(defn cdr [z]
  (z (fn [p q] q)))

(def zero (fn [f] (fn [x] x)))
(defn add-1 [n] (fn [f] (fn [x] (f ((n f) x)))))

(defn list-ref [items n]
  (if (= n 0) (first items)
      (list-ref (rest items) (- n 1))))

(defn count-leaves [x]
  (defn null? [x] (not (seq x)))
  (defn pair? [x] (= (count x) 2))
  (cond (null? x) 0
        (not (pair? x)) 1
        :else (+ (count-leaves (first x))
                 (count-leaves (rest x))))) 

