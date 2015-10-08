(deftemplate variabel
	(slot number))
(deftemplate jumlah
	(slot total))
(deffacts nilai
	(variabel (number 4))
	(variabel (number 6)))
(defrule addup
	(variabel (number ?x))
	(variabel (number ?y))
	=>
	(bind ?total (+ ?x ?y))
	(printout t ?x " + "?y" = "?total crlf)
	(assert (jumlah (total ?total))))
