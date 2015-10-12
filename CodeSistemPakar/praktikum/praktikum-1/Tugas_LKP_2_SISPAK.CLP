(deftemplate person
	(slot nama)
	(slot nrp)
	(slot nilai))

(deftemplate mutu
	(slot nilai-mutu))

(deffacts mahasiswa
	(person (nama "ihsan")
		(nrp "G64144025")
		(nilai 7))
	(person (nama "arif")
		(nrp "G64144026")
		(nilai 6))
	(person (nama "rahman")
		(nrp "G64144075")
		(nilai 5))
	(person (nama "agung")
		(nrp "G64144035")
		(nilai 4))
	(person (nama "aang")
		(nrp "G64144063")
		(nilai 3))
)

(defrule A10
	(person (nilai 10))
	=>
	(assert (mutu (nilai-mutu A))))
(defrule A9
	(person (nilai 9))
	=>
	(assert (mutu (nilai-mutu A))))
(defrule A8
	(person (nilai 8))
	=>
	(assert (mutu (nilai-mutu B))))
(defrule A7
	(person (nilai 7))
	=>
	(assert (mutu (nilai-mutu B))))
(defrule A6
	(person (nilai 6))
	=>
	(assert (mutu (nilai-mutu C))))
(defrule A5
	(person (nilai 5))
	=>
	(assert (mutu (nilai-mutu C))))
