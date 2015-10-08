;Implementasi pada CLIPS
; if the ball color is red THEN I like the ball
(deftemplate bola
	(slot warna))
(deftemplate keputusan
	(slot kesukaan))
;membuat aturan
(defrule like
	(bola (warna merah))
	=>
	(assert (keputusan (kesukaan like))))
(defrule do-not-like
	(bola (warna putih))
	=>
	(assert (keputusan (kesukaan not))))
