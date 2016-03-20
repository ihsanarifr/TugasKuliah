(deftemplate suhu
	(slot kondisi))
(deftemplate respon
	(slot lajureaksi))
;make rule
(defrule tinggi-suhu
	(suhu (kondisi tinggi))
		=>
	(assert (respon 
			(lajureaksi naik))))
(defrule rendah-suhu
	(suhu (kondisi rendah))
		=>
	(assert (respon
			(lajureaksi turun))))
