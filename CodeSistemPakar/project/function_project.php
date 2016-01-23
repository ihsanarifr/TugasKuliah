// tingkat nafsu makan berdasarkan bobot
public function nafsumakan_bobot($bobot,$feeding_rate){
	/*
	1 Rendah
	2 Normal
	*/
	if($bobot > 12.18 AND $bobot <= 32.28){
		if($feeding_rate == 0.968){
			$nafsumakan = 1;
		}else if($feeding_rate == 1.292)
			$nafsumakan = 2;
		}
	}else if($bobot > 32.28 AND $bobot <= 55.96)
		if($feeding_rate == 1.677){
			$nafsumakan = 1;
		}else if($feeding_rate == 2.239){
			$nafsumakan = 2;
		}
	}
	return $nafsumakan;
}

// tingkat kepadatan
public fungtion kepadatan($padat){
	/*
	1 Sangat Jarang sekali
	2 Sangat jarang
	3 Jarang
	4 Normal
	5 Padat
	6 Sangat padat
	*/
	if($padat <= 60){
		$kepadatan = 1;
	}elseif($padat <= 80){
		$kepadatan = 2;
	}elseif($padat <= 99){
		$kepadatan = 3;
	}elseif($padat <=140){
		$kepadatan = 4;
	}elseif($padat <=160){
		$kepadatan = 5;
	}else{
		$kepadatan = 6;
	}
	return $kepadatan;
}

// tingkat kematian
public function kematian($mati){
	/*
	1 sangat bagus
	2 normal
	3 cukup tinggi
	4 tinggi
	5 sangat tinggi
	6 massal
	*/
	if($mati <= 10){
		return 1;
	}elseif($mati <= 20){
		return 2;
	}elseif($mati <= 25){
		return 3;
	}elseif($mati <= 40){
		return 4;
	}elseif($mati <=50){
		return 5;
	}else{
		return 6;
	}
}

// tingkat kelayakan suhu air
public function suhu_air($suhu){
	/*
	1 rendah
	2 normal
	3 tinggi
	*/
	if($suhu < 25){
		return 1;
	}else if($suhu <= 29){
		return 2;
	}else{
		return 3;
	}
}

// tingkat kelayakan pH air
public function ph_air($ph){
	/*
	1 Rendah / asam
	2 Normal
	3 Tinggi / basa
	*/
	if($ph<7){
		return 1;
	}else if($ph <=7.5){
		return 2;
	}else{
		return 3;
	}
}

// tingkat kelayakan Oksigen
public function oksigen_air($oksigen){
	/*
	1 Rendah
	2 Normal
	*/
	if($oksigen < 3){
		return 1;
	}else{
		return 2;
	}
}

// tingkat kelayakan Kecerahan Air
public function kecerahan_air($cerah){
	/*
	1 Rendah
	2 Normal
	*/
	if($cerah < 65){
		return 1;
	}else{
		return 2;
	}
}

// tingkat kelayakan NH3 Air (amoniak)
public function amoniak_air($amoniak){
	/*
	1 Rendah
	2 Normal
	3 Tinggi	
	*/
	if($amoniak < 0.02){
		return 2;
	}else{
		return 3;
	}
}

// Rule Base Kualitas Air
public function role_base_fuzzy_kualitas_air($suhu,$ph,$oksigen,$cerah,$amoniak){
	/*
	1 Kurang bagus
	2 Bagus
	
	rule :
	1 	1 1 1 1 2		1
	2	1 2 1 1 2		1
	3	1 2 2 1 2		1
	4	1 2 2 2 2		1
	5	1 2 2 2 3		1
	6	1 3 1 1 2 		1
	7	1 3 2 1 2 		1
	8	1 3 2 2 2		1
	9 	1 3 2 2 3 		1
	10	2 1 1 1 2 		1 
	11	2 1 2 1 2 		1 
	12  2 1 2 2 2		1
	13  2 1 2 2 3 		1 
	14  2 1 1 1 3		1
	15	2 3 2 1 2		1 
	16  2 3 2 2 3 		1
	17  2 3 1 1 2 		1 
	18 	3 1 1 1 2 		1
	19  3 2 1 1 2 		1 
	20 	3 2 2 2 3		1
	21  3 3 1 1 2 		1
	22	3 3 2 2 3 		1
	23 	2 2 2 2 2		2
	24  2 2 2 1 2 		2
	25  1 1 2 2 2		2
	*/
	// 1
	if($suhu == 1 && $ph==1 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 2
	}else if($suhu == 1 && $ph==2 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 3
	}else if($suhu == 1 && $ph==2 && $oksigen==2 && $cerah==1 && $amoniak==2){
		return 1;
	// 4
	}else if($suhu == 1 && $ph==2 && $oksigen==2 && $cerah==2 && $amoniak==2){
		return 1;
	// 5
	}else if($suhu == 1 && $ph==2 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 6
	}else if($suhu == 1 && $ph==3 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 7
	}else if($suhu == 1 && $ph==3 && $oksigen==2 && $cerah==1 && $amoniak==2){
		return 1;
	// 8
	}else if($suhu == 1 && $ph==3 && $oksigen==2 && $cerah==2 && $amoniak==2){
		return 1;
	// 9
	}else if($suhu == 1 && $ph==3 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 10
	}else if($suhu == 2 && $ph==1 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 11
	}else if($suhu == 2 && $ph==1 && $oksigen==2 && $cerah==1 && $amoniak==2){
		return 1;
	// 12
	}else if($suhu == 2 && $ph==1 && $oksigen==2 && $cerah==2 && $amoniak==2){
		return 1;
	// 13
	}else if($suhu == 2 && $ph==3 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 14
	}else if($suhu == 2 && $ph==1 && $oksigen==1 && $cerah==1 && $amoniak==3){
		return 1;
	// 15
	}else if($suhu == 2 && $ph==3 && $oksigen==2 && $cerah==1 && $amoniak==2){
		return 1;
	// 16
	}else if($suhu == 2 && $ph==3 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 17
	}else if($suhu == 2 && $ph==3 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 18
	}else if($suhu == 3 && $ph==1 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 19
	}else if($suhu == 3 && $ph==2 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 20
	}else if($suhu == 3 && $ph==2 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 21
	}else if($suhu == 3 && $ph==3 && $oksigen==1 && $cerah==1 && $amoniak==2){
		return 1;
	// 22
	}else if($suhu == 3 && $ph==3 && $oksigen==2 && $cerah==2 && $amoniak==3){
		return 1;
	// 23
	}else if($suhu == 2 && $ph==2 && $oksigen==2 && $cerah==2 && $amoniak==2){
		return 2;
	// 24
	}else if($suhu == 2 && $ph==2 && $oksigen==2 && $cerah==1 && $amoniak==2){
		return 2;
	// 25
	}else if($suhu == 1 && $ph==1 && $oksigen==2 && $cerah==2 && $amoniak==2){
		return 2
	}
}

