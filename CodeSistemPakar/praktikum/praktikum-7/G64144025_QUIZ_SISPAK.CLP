(deftemplate ayah-dari (slot ayah) (slot anak))
(deftemplate ibu-dari (slot ibu) (slot anak))
(deftemplate suami-dari (slot suami) (slot istri))
(deftemplate kakek-dari (slot kakek) (slot cucu))
(deftemplate nenek-dari (slot nenek) (slot cucu))
(deftemplate mertua-dari (slot mertua) (slot menantu))
(deftemplate paman-dari (slot paman)(slot keponakan))
(deftemplate sepupu-dari (slot sepupu)(slot anak))
(deftemplate laki (slot orang))
(deftemplate perempuan (slot orang))

(deffacts keluarga
	; ayah umar
	(ayah-dari (ayah "umar")(anak "zulaikha"))
	(ayah-dari (ayah "umar")(anak "aziza"))
	(ayah-dari (ayah "umar")(anak "zaenab"))

	; ayah utsman
	(ayah-dari (ayah "utsman")(anak "abas"))
	(ayah-dari (ayah "utsman")(anak "abdurrahman"))
	(ayah-dari (ayah "utsman")(anak "ali"))

	; ibu Sumayyah
	(ibu-dari (ibu "sumayyah")(anak "zulaikha"))
	(ibu-dari (ibu "sumayyah")(anak "aziza"))
	(ibu-dari (ibu "sumayyah")(anak "zaenab"))

	; ibu Ruqoyyah
	(ibu-dari (ibu "ruqoyyah")(anak "abas"))
	(ibu-dari (ibu "ruqoyyah")(anak "abdurrahman"))
	(ibu-dari (ibu "ruqoyyah")(anak "ali"))

	; ayah abas
	(ayah-dari (ayah "abas")(anak "fatimah"))

	; ayah abdurrahman
	(ayah-dari (ayah "abdurrahman")(anak "aisyah"))

	; ibu zulaikha
	(ibu-dari (ibu "zulaikha")(anak "fatimah"))

	; ayah aziza
	(ibu-dari (ibu "aziza")(anak "aisyah"))

	; suami dari
	(suami-dari (suami "umar")(istri "sumayyah"))
	(suami-dari (suami "utsman")(istri "ruqoyyah"))
	(suami-dari (suami "abas")(istri "zulaikha"))
	(suami-dari (suami "abdurrahman")(istri "aziza"))
	(suami-dari (suami "ali")(istri "zaenab"))

	(laki (orang "umar"))
	(laki (orang "utsman"))
	(laki (orang "abas"))
	(laki (orang "abdurrahman"))
	(laki (orang "ali"))

	(perempuan (orang "zulaikha"))
	(perempuan (orang "aziza"))
	(perempuan (orang "zaenab"))
	(perempuan (orang "ruqoyyah"))
)
(defrule kakeknya
	(and
		(ayah-dari (ayah ?ay)(anak ?an))
		(or
		(ibu-dari (ibu ?an)(anak ?an1))
		(ayah-dari (ayah ?an)(anak ?an1))
		)
	)
	=>
	(assert(kakek-dari (kakek ?ay)(cucu ?an1))))

(defrule neneknya
	(and
		(ibu-dari (ibu ?ay)(anak ?an))
		(or
		(ibu-dari (ibu ?an)(anak ?an1))
		(ayah-dari (ayah ?an)(anak ?an1))
		)
	)
	=>
	(assert(nenek-dari (nenek ?ay)(cucu ?an1))))

(defrule mantunya
	(and
		(or
		(ibu-dari (ibu ?ay)(anak ?an))
		(ayah-dari (ayah ?ay)(anak ?an))
		)
		(or
		(suami-dari (suami ?an)(istri ?man))
		(suami-dari (suami ?man)(istri ?an))
		)
	)
	=>
	(assert(mertua-dari (mertua ?ay)(menantu ?man))))