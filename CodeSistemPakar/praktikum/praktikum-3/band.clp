(deftemplate member_bands
(multislot member-of))
(deffacts nama_band
(member_bands (member-of beatles john_lennon paul_mccartney george_harrison ringo_starr))
(member_bands (member-of smash roger_daltrey pete_townsend keith_moon))
(member_bands (member-of kangen_band tracey_thorn ben_watt)))
(defrule bands
(member_bands (member-of ?band $?))
=>
(printout t "there is a band called " ?band crlf))