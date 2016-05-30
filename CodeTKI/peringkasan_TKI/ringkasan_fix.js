	var kalimat = new Array();	
	
	var stopword = new Array('ada' , 'adalah' , 'adanya' , 'adapun' , 'aduh' , 'agar' , 'ah' , 'akan' , 'aku' , 'alih-alih' , 'anda' , 'andai' , 'antar' , 'antara' , 'apa' , 'apakah' , 'apalagi' , 'asalkan' , 'atas' , 'atau' , 'ataupun' , 'bagai' , 'bagaikan' , 'bagaimana' , 'bagaimanakah' , 'bagaimanapun' , 'bagi' , 'bahkan' , 'bahwa' , 'balik' , 'banyak' , 'barangkali' , 'bawah' , 'beberapa' , 'begini' , 'begitu' , 'belakang' , 'belum' , 'berapa' , 'berbagai' , 'bersama' , 'beserta' , 'betapa' , 'biar' , 'biasanya ' , 'bila' , 'bilamana' , 'buat' , 'bukan' , 'dalam' , 'dan' , 'dapat' , 'dari' , 'daripada' , 'dekat' , 'demi' , 'demikian' , 'dengan' , 'depan' , 'di' , 'dia' , 'dikatakan' , 'dilakukan' , 'dkk' , 'dll' , 'dsb' , 'engkau' , 'hal' , 'hampir' , 'hanya' , 'harus' , 'hingga' , 'ia' , 'ialah' , 'ini' , 'itu' , 'iya' , 'jadi' , 'jangan' , 'jarang' , 'jauh' , 'jika' , 'jikalau' , 'juga' , 'jumlah' , 'justru' , 'kadang' , 'kadang-kadang' , 'kalau' , 'kalian' , 'kami' , 'kamu' , 'karena' , 'kata' , 'katanya' , 'kau' , 'ke' , 'kebanyakan' , 'kecuali' , 'kemanakah' , 'kemudian' , 'kenapa' , 'kenapakah' , 'kepada' , 'ketika' , 'ketimbang' , 'kini' , 'kita' , 'lagi' , 'lain' , 'lain-lain' , 'lainnya' , 'lalu' , 'lebih' , 'lepas' , 'lewat' , 'maka' , 'makin' , 'manakala' , 'masih' , 'masing-masing' , 'masing-masingnya' , 'maupun' , 'melainkan' , 'melakukan' , 'melalui' , 'memang' , 'mengatakan' , 'mengenai' , 'menjadi' , 'menjelang' , 'menuju' , 'menunjukkan' , 'menurut' , 'mereka' , 'merupakan' , 'meski' , 'meskipun' , 'misalnya' , 'mungkin' , 'namun' , 'nanti' , 'nyaris' , 'oleh' , 'pada' , 'padahal' , 'para' , 'pasti' , 'pelbagai' , 'per ' , 'peri' , 'perihal' , 'pinggir' , 'pula' , 'pun' , 'saat' , 'saja' , 'sambil' , 'sampai' , 'samping' , 'sang' , 'sangat' , 'sangatlah' , 'saya' , 'seakan' , 'seakan-akan' , 'seantero' , 'sebab' , 'sebabnya' , 'sebagai' , 'sebagaimana' , 'sebagainya' , 'sebelum' , 'sebelumnya' , 'sebuah' , 'secara' , 'sedang' , 'sedangkan' , 'sedikit' , 'segera' , 'sehabis' , 'sehingga' , 'sehubungan' , 'sejak' , 'sejumlah' , 'sekarang' , 'sekeliling' , 'seketika' , 'sekitar' , 'sekonyong-konyong' , 'selagi' , 'selain' , 'selalu' , 'selama' , 'selanjutnya' , 'selesai' , 'seluruh' , 'seluruhnya' , 'semakin' , 'semenjak' , 'sementara' , 'semua' , 'semuanya' , 'seorang' , 'sepanjang' , 'seperti' , 'sepertinya' , 'seputar' , 'seraya' , 'sering' , 'seringkali' , 'serta' , 'sesuai' , 'sesuatu' , 'sesudah' , 'sesudahnya' , 'sesungguhnya' , 'setelah' , 'seterusnya' , 'setiap' , 'seusai' , 'sewaktu' , 'si' , 'siapa' , 'siapakah' , 'siapapun' , 'suatu' , 'sudah' , 'supaya' , 'tak' , 'tanpa' , 'tapi' , 'tatkala' , 'telah' , 'tengah' , 'tentang' , 'tentu' , 'tentunya' , 'tergolong' , 'terhadap' , 'terjadi' , 'terkadang' , 'terlalu' , 'terlebih' , 'termasuk' , 'ternyata' , 'tersebut' , 'tertentu' , 'tetap' , 'tetapi' , 'tiap' , 'tiba-tiba' , 'tidak' , 'ujar' , 'ujarnya' , 'umumnya' , 'untuk' , 'walau' , 'walaupun' , 'ya' , 'yaitu |yakni' , 'yang' , 'mau');

	var entiti = [];
    var angka = /[0-9]+/
    var karakter_buang = /(,|-|\(|\)|"|:)/g;
	
	var total_kata_dokumen = 0;
    var kata_dlm_kalimat = new Array();
    var entiti_cocok = new Array();
    var angka_cocok = new Array();
    var positif_keyword_cocok = new Array();
    var negatif_keyword_cocok = new Array();
    var bantuan_cari_kata_unik = new Array();
    var gabungan_judul_kalimat = new Array();
	var gabungan_judul_kalimat_unik = new Array();
    var gabungan_judul_unik = new Array();             
    var kata_sama_judul = new Array();
    var semua_kata = new Array();
    var semua_kata_tanpa_stopword = new Array();
    var banyak_kata_mirip = new Array();
	var banyak_koneksi_kalimat = new Array();
	var banyak_entiti = entiti.length;
                    
	var f1 = new Array();
    var f2 = new Array();
    var f3 = new Array();
    var f4 = new Array();
    var f5 = new Array();
    var f6 = new Array();
    var f7 = new Array();
    var f8 = new Array();
    var f9 = new Array();
    var paragraf = new Array();
	var kalimat_bantu = new Array();		
	
	function unique(arrayName){
		var newArray = new Array();
		label:for(var i=0 ; i<arrayName.length ; i++ ){  
			for(var j=0 ; j<newArray.length ; j++ ){
				if(newArray[j] == arrayName[i]) 
					continue label;
			}
			newArray[newArray.length] = arrayName[i];
		}
		return newArray;
	}
	
	function pra_proses(title, isi){                            
		var judul = title;
		judul = judul.replace(karakter_buang, "");
		
		var inc = 0;
			
		document.write("<br><center><b>Judul Dokumen : </b></center>");
		document.write("<center>" +judul + "</center><br><br>");
//		document.write("<b>Isi Dokumen : </b><br>");
					
		judul = judul.toLowerCase();
		judul = judul.split(" ");
			
		//alert(judul);

		for(var ulang=0 ; ulang<isi.length ; ulang++){
			if(isi[ulang] != ""){
				paragraf[inc] = isi[ulang].toLowerCase();
				inc++;
			}
		}

//		document.write("<br><br><hr />");

		for(var ulang=0 ; ulang<paragraf.length ; ulang++){
			if(ulang == 0){
				kalimat = paragraf[ulang].split(".");
			}
			else{
				kalimat = kalimat.concat(paragraf[ulang].split("."));			
			}
		}

		inc = 0;
		for(var ulang=0 ; ulang<kalimat.length ; ulang++){
			if(kalimat[ulang].length > 10){
				kalimat_bantu[inc] = kalimat[ulang];
				inc++;
			}
		}
		
		for(var i=0 ; i<kalimat_bantu.length ; i++){
			kalimat_bantu[i] = kalimat_bantu[i].replace(/^\s+|\s+$/g, "");
//			kalimat_bantu[i] = kalimat_bantu[i].replace(/[\^]/g, "");
		}

		kalimat = kalimat_bantu;

		var hasil_praproses = new Array(kalimat, judul);
		return hasil_praproses;
	}		
	
	function tabulasi_kata(kalimat, flag_stopword){
            for(var i=0 ; i<kalimat.length ; i++){
                if(kalimat[i].length > 10){
                    var kata = kalimat[i].split(" ");
					var kata1 = kalimat[i].split(" ");
					for(var j=0 ; j<kata.length ; j++){
						kata[j] = kata[j].replace(karakter_buang, "");
						for(var k=0 ; k<stopword.length ; k++){
							if(kata[j] == stopword[k]){
								kata[j] = "";
							} 
						}
                    }    
					kata = unique(kata).sort();
					kata.shift();
					
					// OFF Stopword
						if(flag_stopword == 0)
							kata = kata1;

					for(var j=0 ; j<kata.length ; j++){
                        kata[j] = kata[j].replace(karakter_buang, "");
                        if(kata[j].length > 2){
                            total_kata_dokumen++;
                                                                                                                                                
							if(bantuan_cari_kata_unik[kata[j]]>=1){
                                bantuan_cari_kata_unik[kata[j]]++;
                            }
                            else{
                                bantuan_cari_kata_unik[kata[j]]=1;
                            }
						}
                    }
                }
            }

			var jumlah_kata = bantuan_cari_kata_unik; 
			var kata_unik = new Array();
			var inc = 0;
			var max = 0;
			var min = 10000000000;
			for (var word in jumlah_kata){
                kata_unik[inc] = word;
				inc++;
				if(jumlah_kata[word] > max)  { max = jumlah_kata[word]; }
				if(jumlah_kata[word] < min)  { min = jumlah_kata[word]; }
            }
			
			var positif_key = new Array();					
			var negatif_key = new Array();
			for (var word in jumlah_kata){
				if(jumlah_kata[word] == max)  { positif_key.push(word); }
				if(jumlah_kata[word] == min)  { negatif_key.push(word); }
			}
			//document.write(positif_key +  " => " + max +" <br> " + negatif_key);
			
			var hasil_tabulasi = new Array(kata_unik, jumlah_kata, positif_key, negatif_key, max);
			
			return hasil_tabulasi;    
		}
				
    function cari_fitur(isi, judul, kalimat, positif_keyword, negatif_keyword, entiti, kata_unik, flag_stopword){
			var temp_kata_unik = new Array();
			var total = 0;
			var semua_kata_unik = new Array();
			var kata_unik_dlm_kalimat = new Array();
			var panjang_kalimat = new Array();
			var posisi_kalimat = new Array();
			var max_koneksi = 0;
			var max_mirip = 0;
			var max_panjang = 0;
			var max_angka = 0;
			var max_entiti = 0;
			var max_positif = 0;
			var max_negatif = 0;
			var max_judul = 0;
			var banyak_kalimat = new Array();
			var total = 0;
			var total_kata_dlm_dok = kata_unik.length;
			
			//fitur 1
			for(var ulang=0 ; ulang<paragraf.length ; ulang++){
				banyak_kalimat[ulang]=0;
				for (var i=0 ; i<paragraf[ulang].length ; i++){
					if(paragraf[ulang].charAt(i) == "."){
						banyak_kalimat[ulang]++;
					}
				}
				total=total+banyak_kalimat[ulang];
			}
			
			var inc = 0;
			for(var i=0 ; i<paragraf.length ; i++){
				for(var j=banyak_kalimat[i] ; j>0 ; j--){					
					posisi_kalimat[inc] = j/banyak_kalimat[i];
					inc++;
				}
			}
			//selesai fitur 1			
			
			for(i=0 ; i<kalimat.length ; i++){
                if(kalimat[i].length > 10){
                    kata_dlm_kalimat[i] = 0;
                    entiti_cocok[i] = 0;
                    angka_cocok[i] = 0;
                    positif_keyword_cocok[i] = 0;
                    negatif_keyword_cocok[i] = 0;
                    gabungan_judul_unik[i] = 0;
                    kata_sama_judul[i] = 0;
																
					var kata = kalimat[i].split(" ").sort();
					var kata1 = kalimat[i].split(" ").sort();
                    semua_kata[i] = kata;
                    semua_kata_tanpa_stopword[i] = kata1;
                    
					for(j=0 ; j<semua_kata[i].length ; j++){
						semua_kata[i][j] = semua_kata[i][j].replace(karakter_buang, "");
						semua_kata_tanpa_stopword[i][j] = semua_kata_tanpa_stopword[i][j].replace(karakter_buang, "");
						for(var k=0 ; k<stopword.length ; k++){
							if(semua_kata[i][j] == stopword[k]){
								semua_kata_tanpa_stopword[i][j] = "";
							} 
						}
					}
				
					kata_unik_dlm_kalimat[i] = unique(semua_kata[i].sort());

					// fitur 6
					for(j=0 ; j<kata_unik_dlm_kalimat[i].length ; j++){
                        kata_unik_dlm_kalimat[i][j] = kata_unik_dlm_kalimat[i][j].replace(karakter_buang, "");
						if(kata_unik_dlm_kalimat[i].length > 2){
                            //document.write("* "+kata_unik_dlm_kalimat[i][j]+"<br>");
                                        							
                            for(var k=0 ; k<entiti.length ; k++){    
                                if(kata_unik_dlm_kalimat[i][j] == entiti[k]){
									entiti_cocok[i]++;
                                }
						    }
						}
					}
					//

					
		// Panel Stopword			
					// OFF Stopword
					if(flag_stopword == 0)
						semua_kata_tanpa_stopword[i] = kata_unik_dlm_kalimat[i];
					
					// ON Stopword
					if(flag_stopword == 1){
						semua_kata_tanpa_stopword[i] = unique(semua_kata_tanpa_stopword[i]).sort();
						semua_kata_tanpa_stopword[i].shift();
					}
		// end panel
					 
					 
					//document.write(semua_kata[i].sort() + "<br>");
					//document.write(semua_kata_tanpa_stopword[i] + "<br>");
					
					panjang_kalimat[i] = semua_kata_tanpa_stopword[i].length / total_kata_dlm_dok;
					//document.write("+_+ "+ panjang_kalimat[i] +"<br>");						

					gabungan_judul_kalimat[i] = kata.concat(judul).sort();
					gabungan_judul_kalimat_unik[i] = unique(gabungan_judul_kalimat[i].sort());
					//document.write("*_* "+ gabungan_judul_kalimat_unik[i] +"<br>");						
							
					for(j=0 ; j<semua_kata_tanpa_stopword[i].length ; j++){
    					if(kata_unik_dlm_kalimat[i].length > 2){
                            //document.write("* "+semua_kata_tanpa_stopword[i][j]+"<br>");
                                        							
                            for(var k=0 ; k<entiti.length ; k++){    
                                if(semua_kata_tanpa_stopword[i][j] == entiti[k]){
									entiti_cocok[i]++;
                                }
						    }
                                    
                            for(var k=0 ; k<judul.length ; k++){    
                                 if(semua_kata_tanpa_stopword[i][j] == judul[k]){
                                    kata_sama_judul[i]++;
								}
                            }
                                         
                            if(angka.test(semua_kata_tanpa_stopword[i][j]) == true){ angka_cocok[i]++ }
                                         
                            for(var k=0 ; k<positif_keyword.length ; k++){    
								if(semua_kata_tanpa_stopword[i][j] == positif_keyword[k]){
									positif_keyword_cocok[i]++;
								}
                            }
							
                            for(var k=0 ; k<negatif_keyword.length ; k++){    
								if(semua_kata_tanpa_stopword[i][j] == negatif_keyword[k]){
									negatif_keyword_cocok[i]++;
								}
							}
						}
					}
					//positif_keyword_cocok[i] = positif_keyword_cocok[i]/panjang_kalimat[i];
					//entiti_cocok[i] = entiti_cocok[i]/panjang_kalimat[i]; 
					//kata_sama_judul[i] = kata_sama_judul[i] / panjang_kalimat[i];
				}
				
				var kata_gabungan_untuk_kemiripan = new Array();
				var gabungan_untuk_koneksi_kalimat = new Array();
                                                            		
				kata_gabungan_untuk_kemiripan = new Array();
				gabungan_untuk_koneksi_kalimat = new Array();
				for(j=0 ; j<kalimat.length ; j++){
                    if(j != i){
                        kata_gabungan_untuk_kemiripan = kata_gabungan_untuk_kemiripan.concat(semua_kata[j]).sort();       
                    }
                    if(j == i-1 || j==i+1){
                        gabungan_untuk_koneksi_kalimat = gabungan_untuk_koneksi_kalimat.concat(semua_kata[j]).sort();       
                    }    
                }
							
				gabungan_untuk_koneksi_kalimat = unique(gabungan_untuk_koneksi_kalimat);
				kata_gabungan_untuk_kemiripan = unique(kata_gabungan_untuk_kemiripan);
			
				//document.write("*_*" + unique(gabungan_untuk_koneksi_kalimat) + "<br />");
                //document.write("% " + unique(kata_gabungan_untuk_kemiripan) + "<br />");
			
                banyak_kata_mirip[i] = 0;
                banyak_koneksi_kalimat[i] = 0;
                for(j=0 ; j<semua_kata_tanpa_stopword.length ; j++){
					for(k=0 ; k<kata_gabungan_untuk_kemiripan.length ; k++){
                        //document.write("* " + kata_unik_dlm_kalimat[i][j] + " == " + kata_gabungan_untuk_kemiripan[k] + "<br />");
						if(semua_kata_tanpa_stopword[i][j] == kata_gabungan_untuk_kemiripan[k]){
							banyak_kata_mirip[i]++;
						}  
					}
					for(k=0 ; k<gabungan_untuk_koneksi_kalimat.length ; k++){
                        if(semua_kata_tanpa_stopword[i][j] == gabungan_untuk_koneksi_kalimat[k]){
							banyak_koneksi_kalimat[i]++;
                        }  
                    }
                }
				
				banyak_koneksi_kalimat[i] = banyak_koneksi_kalimat[i]/panjang_kalimat[i];
				banyak_kata_mirip[i] = banyak_kata_mirip[i]/panjang_kalimat[i];							
				
				if(positif_keyword_cocok[i] > max_positif)		{ max_positif = positif_keyword_cocok[i]; }
				if(negatif_keyword_cocok[i] > max_negatif)		{ max_negatif = negatif_keyword_cocok[i]; }
				if(banyak_kata_mirip[i] > max_mirip)			{ max_mirip = banyak_kata_mirip[i]; }
				if(kata_sama_judul[i] > max_judul)				{ max_judul = kata_sama_judul[i]; }
				if(entiti_cocok[i] > max_entiti)				{ max_entiti = entiti_cocok[i]; }
				if(angka_cocok[i] > max_angka)					{ max_angka = angka_cocok[i]; }
				if(panjang_kalimat[i] > max_panjang)			{ max_panjang = panjang_kalimat[i]; }
				if(banyak_koneksi_kalimat[i] > max_koneksi)		{ max_koneksi = banyak_koneksi_kalimat[i]; }
					
				//document.write("% " + banyak_kata_mirip[i] + " , " + banyak_koneksi_kalimat[i] + " , " + max + "<br />");				
			}				
			
			for(i=0 ; i<kalimat.length ; i++){
				if(max_positif > 0) 	{ positif_keyword_cocok[i] 	= positif_keyword_cocok[i] / max_positif; 	}
				if(max_negatif > 0) 	{ negatif_keyword_cocok[i] 	= negatif_keyword_cocok[i] / max_negatif; 	}
				if(max_mirip > 0) 		{ banyak_kata_mirip[i] 		= banyak_kata_mirip[i] / max_mirip; 		}
				if(judul.length > 0) 	{ kata_sama_judul[i] 		= kata_sama_judul[i] / max_judul; 			}
				if(max_entiti > 0) 		{ entiti_cocok[i] 			= entiti_cocok[i] / max_entiti; 			}
				if(max_angka > 0) 		{ angka_cocok[i] 			= angka_cocok[i] / max_angka; 				}
				if(max_panjang > 0) 	{ panjang_kalimat[i] 		= panjang_kalimat[i] / max_panjang; 	    }
				if(max_koneksi > 0) 	{ banyak_koneksi_kalimat[i] = banyak_koneksi_kalimat[i] / max_koneksi; 	}
			}

			var hasil_cari_fitur = new Array(posisi_kalimat, positif_keyword_cocok, negatif_keyword_cocok, banyak_kata_mirip, kata_sama_judul, entiti_cocok, angka_cocok, panjang_kalimat, banyak_koneksi_kalimat);
			
			return hasil_cari_fitur; 
	}		
		
	function fuzzifikasi(VL, L, M, H, VH, value){
		var result = 0;
		var result_fix = -1;
		var level;
		
		if(value <= VL[2] && value >= VL[0]){
			if(value < VL[1] && value > VL[0]){
				result = (value-VL[0]) / (VL[1]-VL[0]);
			}
			else if(value == VL[1]){
				result = 1;
			}
			else if(value == VL[0] || value == VL[2]){
				result = 0;
			}
			else{
				result = (VL[2]-value) / (VL[2]-VL[1]);
			}
			if(result_fix <= result){
				result_fix = result;
				level = "very_low";
			}
		}
		
		if(value <= L[2] && value >= L[0]){
			if(value < L[1] && value > L[0]){
				result = (value-L[0]) / (L[1]-L[0]);
			}
			else if(value == L[1]){
				result = 1;
			}
			else if(value == L[0] || value == L[2]){
				result = 0;
			}
			else{
				result = (L[2]-value) / (L[2]-L[1]);
			}
			if(result_fix < result){
				result_fix = result;
				level = "low";
			}
		}

		if(value <= M[2] && value >= M[0]){
			if(value < M[1] && value > M[0]){
				result = (value-M[0]) / (M[1]-M[0]);
			}
			else if(value == M[1]){
				result = 1;
			}
			else if(value == M[0] || value == M[2]){
				result = 0;
			}
			else{
				result = (M[2]-value) / (M[2]-M[1]);
			}
			if(result_fix < result){
				result_fix = result;
				level = "medium";
			}
		}
		
		if(value <= H[2] && value >= H[0]){
			if(value < H[1] && value > H[0]){
				result = (value-H[0]) / (H[1]-H[0]);
			}
			else if(value == H[1]){
				result = 1;
			}
			else if(value == H[0] || value == H[2]){
				result = 0;
			}
			else{
				result = (H[2]-value) / (H[2]-H[1]);
			}
			if(result_fix < result){
				result_fix = result;
				level = "high";
			}
		}
		
		if(value <= VH[2] && value >= VH[0]){
			if(value < VH[1] && value > VH[0]){
				result = (value-VH[0]) / (VH[1]-VH[0]);
			}
			else if(value == VH[1]){
				result = 1;
			}
			else if(value == VH[0] || value == VH[2]){
				result = 0;
			}
			else{
				result = (VH[2]-value) / (VH[2]-VH[1]);
			}
			if(result_fix < result){
				result_fix = result;
				level = "very_high";
			}
		}

		var hasil = new Array(result_fix, level);
		return hasil;
	}
	
	function defuzzifikasi(hasil_fuzzifikasi){
		var linguistik = hasil_fuzzifikasi[0];
		var level = hasil_fuzzifikasi[1];
		var result = 0 ;
		
		if(level == 'very_low'){
			result = 1 * linguistik;
		}
		else if(level == 'low'){
			result = 2.5 * linguistik;
		}
		else if(level == 'medium'){
			result = 5 * linguistik;
		}
		else if(level == 'high'){
			result = 7.5 * linguistik;
		}
		else if(level == 'very_high'){
			result = 10 * linguistik;
		}
		else{
			result = linguistik;
		}
		
		return result;
	}