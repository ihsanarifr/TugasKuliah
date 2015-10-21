(defrule start
	(declare (salience 10000))
(initial-fact)
=>
(set-fact-duplication TRUE))
(defrule both-positif
	?fact1 <- (pasien ?sakit ?tifus ?c1&:(>= ?c1 0))
	?fact2 <- (pasien ?sakit ?tifus ?c2&:(>= ?c2 0))
(test (neq ?fact1 ?fact2))
=>
(retract ?fact1 ?fact2)
	(bind ?c3 (- (+ ?c1 ?c2)(* ?c1 ?c2)))
	(assert (pasien ?sakit ?tifus ?c3)))

(defrule both-negatif
	?fact1 <- (pasien ?sakit ?tifus ?c1&:(< ?c1 0))
	?fact2 <- (pasien ?sakit ?tifus ?c2&:(< ?c2 0))
(test (neq ?fact1 ?fact2))
=>
(retract ?fact1 ?fact2)
	(bind ?c3 (+ (+ ?c1 ?c2)(* ?c1 ?c2)))
	(assert (pasien ?sakit ?tifus ?c3)))

(defrule opposite-sign
	?fact1 <- (pasien ?sakit ?tifus ?c1)
	?fact2 <- (pasien ?sakit ?tifus ?c2)
(test (< (* ?c1 ?c2) 0))
(test (neq ?fact1 ?fact2))
=>
(retract ?fact1 ?fact2)
	(bind ?c3 (/ (+ ?c1 ?c2)(- 1 (min (abs ?c1)(abs ?c2)))))
	(assert (pasien ?sakit ?tifus ?c3)))

(deffacts rumahsakit
	(pasien sakit tifus -0.39)
	(pasien sakit tifus -0.51)
	(pasien sakit tifus 0.87)
	(pasien sakit tifus 0.63)
)
