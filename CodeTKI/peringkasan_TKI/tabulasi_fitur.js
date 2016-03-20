				
function tabulasi_fitur(panjang_array, f1, f2, f3, f4, f5, f6, f7, f7, f8, f9){ 
	var jumlah_skor_f1 = 0; var tabulasi_skor_f1 = new Array(); var max_f1 = 0;
	var jumlah_skor_f2 = 0; var tabulasi_skor_f2 = new Array(); var max_f2 = 0;
	var jumlah_skor_f3 = 0; var tabulasi_skor_f3 = new Array(); var max_f3 = 0;
	var jumlah_skor_f4 = 0; var tabulasi_skor_f4 = new Array(); var max_f4 = 0;
	var jumlah_skor_f5 = 0; var tabulasi_skor_f5 = new Array(); var max_f5 = 0;
	var jumlah_skor_f6 = 0; var tabulasi_skor_f6 = new Array(); var max_f6 = 0;
	var jumlah_skor_f7 = 0; var tabulasi_skor_f7 = new Array(); var max_f7 = 0;
	var jumlah_skor_f8 = 0; var tabulasi_skor_f8 = new Array(); var max_f8 = 0; 
	var jumlah_skor_f9 = 0; var tabulasi_skor_f9 = new Array(); var max_f9 = 0;			

	for(var i=0 ; i<panjang_array ; i++){ 
		if(tabulasi_skor_f1[f1[i]] == undefined) tabulasi_skor_f1[f1[i]] = 0; 
		if(tabulasi_skor_f2[f2[i]] == undefined) tabulasi_skor_f2[f2[i]] = 0; 
		if(tabulasi_skor_f3[f3[i]] == undefined) tabulasi_skor_f3[f3[i]] = 0; 
		if(tabulasi_skor_f4[f4[i]] == undefined) tabulasi_skor_f4[f4[i]] = 0; 
		if(tabulasi_skor_f5[f5[i]] == undefined) tabulasi_skor_f5[f5[i]] = 0; 
		if(tabulasi_skor_f6[f6[i]] == undefined) tabulasi_skor_f6[f6[i]] = 0; 
		if(tabulasi_skor_f7[f7[i]] == undefined) tabulasi_skor_f7[f7[i]] = 0; 
		if(tabulasi_skor_f8[f8[i]] == undefined) tabulasi_skor_f8[f8[i]] = 0; 
		if(tabulasi_skor_f9[f9[i]] == undefined) tabulasi_skor_f9[f9[i]] = 0; 
	}

	for(var i=0 ; i<panjang_array ; i++){
		total_skor[i] = f1[i] + f2[i] + f3[i] + f4[i] + f5[i] + f6[i] + f7[i] + f8[i] + f9[i];
		
		if(f1[i] >= 0){
			jumlah_skor_f1 = jumlah_skor_f1 + f1[i];
			tabulasi_skor_f1[f1[i]]++;
		}
		if(f2[i] >= 0){
			jumlah_skor_f2 = jumlah_skor_f2 + f2[i];
			tabulasi_skor_f2[f2[i]]++;
		}
		if(f3[i] >= 0){
			jumlah_skor_f3 = jumlah_skor_f3 + f3[i];
			tabulasi_skor_f3[f3[i]]++;
		}
		if(f4[i] >= 0){
			jumlah_skor_f4 = jumlah_skor_f4 + f4[i];
			tabulasi_skor_f4[f4[i]]++;
		}
		if(f5[i] >= 0){
			jumlah_skor_f5 = jumlah_skor_f5 + f5[i];
			tabulasi_skor_f5[f5[i]]++;
		}
		if(f6[i] >= 0){
			jumlah_skor_f6 = jumlah_skor_f6 + f6[i];
			tabulasi_skor_f6[f6[i]]++;
		}
		if(f7[i] >= 0){
			jumlah_skor_f7 = jumlah_skor_f7 + f7[i];
			tabulasi_skor_f7[f7[i]]++;
		}
		if(f8[i] >= 0){
			jumlah_skor_f8 = jumlah_skor_f8 + f8[i];
			tabulasi_skor_f8[f8[i]]++;
		}
		if(f9[i] >= 0){
			jumlah_skor_f9 = jumlah_skor_f9 + f9[i];
			tabulasi_skor_f9[f9[i]]++;
		}
	}

	for (var tabulasi in tabulasi_skor_f1)	
		if(tabulasi_skor_f1[f1[tabulasi]] >= max_f1 && (f1[tabulasi] != 0 && f1[tabulasi] != 1) )
			{ max_f1 = tabulasi_skor_f1[f1[tabulasi]]; var maxf1 = f1[tabulasi];}
	for (var tabulasi in tabulasi_skor_f2)	
		if(tabulasi_skor_f2[f2[tabulasi]] >= max_f2 && (f2[tabulasi] != 0 && f2[tabulasi] != 1) )
			{ max_f2 = tabulasi_skor_f2[f2[tabulasi]]; var maxf2 = f2[tabulasi];}
	for (var tabulasi in tabulasi_skor_f3)	
		if(tabulasi_skor_f3[f3[tabulasi]] >= max_f3 && (f3[tabulasi] != 0 && f3[tabulasi] != 1) )
			{ max_f3 = tabulasi_skor_f3[f3[tabulasi]]; var maxf3 = f3[tabulasi];}
	for (var tabulasi in tabulasi_skor_f4)
		if(tabulasi_skor_f4[f4[tabulasi]] >= max_f4 && (f4[tabulasi] != 0 && f4[tabulasi] != 1) )
			{ max_f4 = tabulasi_skor_f4[f4[tabulasi]]; var maxf4 = f4[tabulasi];}
	for (var tabulasi in tabulasi_skor_f5)	
		if(tabulasi_skor_f5[f5[tabulasi]] >= max_f5 && (f5[tabulasi] != 0 && f5[tabulasi] != 1) )
			{ max_f5 = tabulasi_skor_f5[f5[tabulasi]]; var maxf5 = f5[tabulasi];}
	for (var tabulasi in tabulasi_skor_f6)	
		if(tabulasi_skor_f6[f6[tabulasi]] >= max_f6 && (f6[tabulasi] != 0 && f6[tabulasi] != 1) )
			{ max_f6 = tabulasi_skor_f6[f6[tabulasi]]; var maxf6 = f6[tabulasi];}
	for (var tabulasi in tabulasi_skor_f7)	
		if(tabulasi_skor_f7[f7[tabulasi]] >= max_f7 && (f7[tabulasi] != 0 && f7[tabulasi] != 1) )
			{ max_f7 = tabulasi_skor_f7[f7[tabulasi]]; var maxf7 = f7[tabulasi];}
	for (var tabulasi in tabulasi_skor_f8)	
		if(tabulasi_skor_f8[f8[tabulasi]] >= max_f8 && (f8[tabulasi] != 0 && f8[tabulasi] != 1) )
			{ max_f8 = tabulasi_skor_f8[f8[tabulasi]]; var maxf8 = f8[tabulasi];}
	for (var tabulasi in tabulasi_skor_f9)	
		if(tabulasi_skor_f9[f9[tabulasi]] >= max_f9 && (f9[tabulasi] != 0 && f9[tabulasi] != 1) )
			{ max_f9 = tabulasi_skor_f9[f9[tabulasi]]; var maxf9 = f9[tabulasi];}
	
	var hasil = new Array(jumlah_skor_f1, tabulasi_skor_f1, maxf1, jumlah_skor_f2, tabulasi_skor_f2, maxf2, jumlah_skor_f3, tabulasi_skor_f3, maxf3, jumlah_skor_f4, tabulasi_skor_f4, maxf4, jumlah_skor_f5, tabulasi_skor_f5, maxf5, jumlah_skor_f6, tabulasi_skor_f1, maxf6, jumlah_skor_f7, tabulasi_skor_f7, maxf7, jumlah_skor_f8, tabulasi_skor_f8, maxf8, jumlah_skor_f9, tabulasi_skor_f9, maxf9);
	
	return hasil;
}

function cetak_tab_fitur(hasil_tab_fitur, jum_kalimat){ 				
	var jumlah_skor_f1 = hasil_tab_fitur[0]; var tabulasi_skor_f1 = hasil_tab_fitur[1]; var maxf1 = hasil_tab_fitur[2];
	var jumlah_skor_f2 = hasil_tab_fitur[3]; var tabulasi_skor_f2 = hasil_tab_fitur[4]; var maxf2 = hasil_tab_fitur[5];
	var jumlah_skor_f3 = hasil_tab_fitur[6]; var tabulasi_skor_f3 = hasil_tab_fitur[7]; var maxf3 = hasil_tab_fitur[8];
	var jumlah_skor_f4 = hasil_tab_fitur[9]; var tabulasi_skor_f4 = hasil_tab_fitur[10]; var maxf4 = hasil_tab_fitur[11];
	var jumlah_skor_f5 = hasil_tab_fitur[12]; var tabulasi_skor_f5 = hasil_tab_fitur[13]; var maxf5 = hasil_tab_fitur[14];
	var jumlah_skor_f6 = hasil_tab_fitur[15]; var tabulasi_skor_f6 = hasil_tab_fitur[16]; var maxf6 = hasil_tab_fitur[17];
	var jumlah_skor_f7 = hasil_tab_fitur[18]; var tabulasi_skor_f7 = hasil_tab_fitur[19]; var maxf7 = hasil_tab_fitur[20];
	var jumlah_skor_f8 = hasil_tab_fitur[21]; var tabulasi_skor_f8 = hasil_tab_fitur[22]; var maxf8 = hasil_tab_fitur[23];
	var jumlah_skor_f9 = hasil_tab_fitur[24]; var tabulasi_skor_f9 = hasil_tab_fitur[25]; var maxf9 = hasil_tab_fitur[26];
	
	document.write("Tabulasi F1 : " + jumlah_skor_f1 + " " + jum_kalimat);
	document.write("<br>" + maxf1.toFixed(2) + "=>" + tabulasi_skor_f1[maxf1]);
	// for (var tabulasi in tabulasi_skor_f1){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f1[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F1 => " + (jumlah_skor_f1/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F2 : ");
	document.write("<br>" + maxf2.toFixed(2) + "=>" + tabulasi_skor_f2[maxf2]);
	// for (var tabulasi in tabulasi_skor_f2){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f2[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F2 => " + (jumlah_skor_f2/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F3 : ");
	document.write("<br>" + maxf3.toFixed(2) + "=>" + tabulasi_skor_f3[maxf3]);
	// for (var tabulasi in tabulasi_skor_f3){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f3[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F3 => " + (jumlah_skor_f3/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F4 : ");
	document.write("<br>" + maxf4.toFixed(2) + "=>" + tabulasi_skor_f4[maxf4]);
	// for (var tabulasi in tabulasi_skor_f4){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f4[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F4 => " + (jumlah_skor_f4/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F5 : ");
	document.write("<br>" + maxf5.toFixed(2) + "=>" + tabulasi_skor_f5[maxf5]);
	// for (var tabulasi in tabulasi_skor_f5){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f5[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F5 => " + (jumlah_skor_f5/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F6 : ");
	document.write("<br>" + maxf6.toFixed(2) + "=>" + tabulasi_skor_f6[maxf6]);
	// for (var tabulasi in tabulasi_skor_f6){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f6[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F6 => " + (jumlah_skor_f6/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F7 : ");
	document.write("<br>" + maxf7.toFixed(2) + "=>" + tabulasi_skor_f7[maxf7]);
	// for (var tabulasi in tabulasi_skor_f7){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f7[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F7 => " + (jumlah_skor_f7/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F8 : ");
	document.write("<br>" + maxf8.toFixed(2) + "=>" + tabulasi_skor_f8[maxf8]);
	// for (var tabulasi in tabulasi_skor_f8){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f8[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F8 => " + (jumlah_skor_f8/jum_kalimat).toFixed(2) + "<br><br>");

	document.write("Tabulasi F9 : ");
	document.write("<br>" + maxf9.toFixed(2) + "=>" + tabulasi_skor_f9[maxf9]);
	// for (var tabulasi in tabulasi_skor_f9){
		// document.write("<br>" + tabulasi + "=>" + tabulasi_skor_f9[tabulasi]);
	// }
	document.write("<br><br> Rata-rata Skor F9 => " + (jumlah_skor_f9/jum_kalimat).toFixed(2) + "<br><br>");
}