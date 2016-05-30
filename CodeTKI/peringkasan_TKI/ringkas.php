<table border='7' width='900' align='center' cellspacing='15'><tr><td>
	<table border='0' width='850' align='center' cellspacing='15'><tr><td>
		<?php 
			$nama_folder_rule = $_POST['nama_folder_rule'];
			$flag_stopword = $_POST['flag_stopword'];
			$flag_stopword = str_replace("\r\n", "", $flag_stopword);		
		?>

<html>
	<head>
		<title> Peringkasan Dokumen </title>
	</head>
	
	<body style="background-image:url(dd1.jpg); background-repeat : repeat; backround : transparant;">
		<script>
			var rule = new Array();
		</script>

		<?php
			
			$jenis = $_POST['jenis_input'];
			
			if($_FILES['dokumen']['size'] > 0 && $_FILES['dokumen']['error'] == 0){
				$file = fopen($_FILES['dokumen']['tmp_name'], 'r');
				
				$i = 0;
				while(!feof($file))  
				{  
					$line[$i] = fgetss($file);
					$line[$i] = trim(str_replace(array("\r", "\n"), '', $line[$i]));
					$line[$i] = str_replace(array("'", "\'"), '', $line[$i]);
					for($x=0 ; $x<strlen($line[$i]) ; $x++){
						if($x < (strlen($line[$i])-1)){
							if( $line[$i][$x]=="." && preg_match("/[0-9]|[a-z]|[A-Z]/", $line[$i][$x-1]) && preg_match("/[0-9]|[a-z]|[A-Z]/", $line[$i][$x+1])){
								$line[$i][$x] = ",";
							}
						}
					}
					
					for($x=0 ; $x<strlen($line[$i]) ; $x++){
						if($line[$i][$x]=="\""){
							for($y=$x+1 ; $y<strlen($line[$i])-1 ; $y++){
								if($line[$i][$y]=="."){
									$line[$i][$y]=",";
								}
								if($line[$i][$y]=="\""){
									$x = $y+1;
									$y = strlen($line[$i]);
								}
							}
						}
					}
					$i++;
				} 
					
				fclose($file);
				
				//$fileData = fread($tmpFile, filesize($_FILES['dokumen']['tmp_name']));
				//$fileData = addslashes($fileData);
			}
			
			$judul='';
			$isi='';
			$isi_jadi='';
			
			if($jenis == 1){
				$judul = $_POST['judul'];
				$isi = $_POST['isi'];
				$isi_jadi = explode("\n", $isi);
				$isi_jadi = str_replace(array("\r", "\n"), '', $isi_jadi);
			}
			else if($jenis == 2){
				$isi_jadi = $line;
				$isi_jadi = str_replace(array("\r", "\n"), '', $isi_jadi);
			}		
		?>

		<script>
			var jenis = '<?php echo $jenis?>';
			var judul = '';
			var isi = new Array();
			var rule_f1 = new Array();
			var rule_f2 = new Array();
			var rule_f3 = new Array();
			var rule_f4 = new Array();
			var rule_f5 = new Array();
			var rule_f6 = new Array();
			var rule_f7 = new Array();
			var rule_f8 = new Array();
			var rule_f9 = new Array();
		</script>

		<?php
			for($i=0 ; $i<count($isi_jadi) ; $i++){
				echo "
					<script>				
							isi['$i'] = '$isi_jadi[$i]';
							var flag_stopword = $flag_stopword;
					</script>
				";
			}			
		?>

		<script type="text/javascript" src="ringkasan_fix.js"></script>
		<script>
			if(jenis == 2){
				judul = isi[0];
				isi.shift(); 
			}
			else if(jenis == 1){
				judul = '<?phpecho $judul?>';
			}
			
			//alert(judul);
			//alert(isi);
			var praproses = pra_proses(judul, isi);
			var kalimat = praproses[0];
			var judul_baru = praproses[1];	

			document.write("<hr><br><b><center> Kalimat Dalam Dokumen </center></b><br>");
			for(var i=0 ; i<kalimat.length ; i++){
				document.write("<b>"+ (i+1) + ". " + kalimat[i] + "</b><br><br>");
			}
			
// Tabulasi Kata
			var hasil_token = tabulasi_kata(kalimat);
//			document.write("<hr><br><b>Tabulasi Kata</b><br>");
//			for(var i=0 ; i<hasil_token[0].length ; i++){
//				document.write(hasil_token[0][i] + "=>" + hasil_token[1][hasil_token[0][i]] + "<br>");
//			}
			var kata_unik = hasil_token[0];
			var positif = hasil_token[2];
			var negatif = hasil_token[3];
			var entiti = new Array('karena', 'artinya', 'sebab', 'sebabnya', 'namun', 'kesimpulan', 'kesimpulanya', 'singkatnya', 'singkat', 'akibat', 'akibatnya', 'sedangkan', 'sehingga', 'menurut', 'kemudian', 'tetapi', 'berdasarkan', 'kalau', 'pasalnya', 'adalah', 'ialah', 'yaitu', 'sebesar', 'seperti', 'hasil', 'hasilnya', 'sementara', 'katanya', 'mengatakan', 'menambahkan', 'ujar', 'ujarnya', 'menegaskan', 'menjelaskan', 'meskipun', 'apabila' );
					
			var hasil_fitur = cari_fitur(isi, judul_baru, kalimat, positif, negatif,  entiti, kata_unik, flag_stopword); 
			var f_posisi = hasil_fitur[0];
			var f_judul = hasil_fitur[5];
			var f_kata_khusus = hasil_fitur[6];
			var f_numerik = hasil_fitur[7];
			var f_panjang_kalimat = hasil_fitur[8];
			
			var panjang_array = hasil_fitur[0].length;
			var total_skor = new Array();
			
			var sort_skor = new Array();			
			for(var i=0 ; i<panjang_array ; i++){
				total_skor[i] = f_posisi[i] + f_judul[i] + f_kata_khusus[i] + f_numerik[i] + f_panjang_kalimat[i];
				sort_skor[i] = [i, total_skor[i]];				
			}
			
			// Sorting Total Skor
			sort_skor = sort_skor.sort(function(a,b) {
				return a[1] - b[1];
			});						
			sort_skor = sort_skor.reverse();
			
			// Persentase ringkasan
			var banyak_kalimat = kalimat.length;
			var banyak_terambil = Math.round( 30/100 * banyak_kalimat );
									
		</script>

		<br> <hr> <br>
		<b><center>MATRIKS KOVARIAN</center></b>
		<br>
		<table border=1 align="center">
			<tr> <th width=100 align=center>Kalimat</th><th width=80 align=center>Fitur Posisi Kalimat</th><th width=100 align=center>Fitur Judul</th><th width=100 align=center>Fitur Kata Khusus</th><th width=100 align=center>Fitur Numerik</th><th width=100 align=center>Fitur Panjang Kalimat</th><th width=80 align=center>Total Skor</th> </tr>
		<script>
			for(var i=0 ; i<panjang_array ; i++){
					document.write("<tr> <td align=center>" + (i+1) + "</td> <td align=center>" + f_posisi[i].toFixed(2) + "</td> <td align=center>" + f_judul[i].toFixed(2) + "</td> <td align=center>" + f_kata_khusus[i].toFixed(2) + "</td> <td align=center>" + f_numerik[i].toFixed(2) + "</td> <td align=center>" + f_panjang_kalimat[i].toFixed(2) + "</td> <td align=center>" + total_skor[i].toFixed(2) + "</td></tr>");
			}
		</script>
		</table>

		<br> <hr> <br>
		<b><center>MATRIKS KOVARIAN (Sorting)</center></b>
		<br>
		<table border=1 align="center">
			<tr> <th width=100 align=center>Kalimat</th><th width=80 align=center>Fitur Posisi Kalimat</th><th width=100 align=center>Fitur Judul</th><th width=100 align=center>Fitur Kata Khusus</th><th width=100 align=center>Fitur Numerik</th><th width=100 align=center>Fitur Panjang Kalimat</th><th width=80 align=center>Total Skor</th> </tr>
			<script>
				for(var i=0 ; i<panjang_array ; i++){
						document.write("<tr> <td align=center>" + (sort_skor[i][0]+1) + "</td> <td align=center>" + f_posisi[sort_skor[i][0]].toFixed(2) + "</td> <td align=center>" + f_judul[sort_skor[i][0]].toFixed(2) + "</td> <td align=center>" + f_kata_khusus[sort_skor[i][0]].toFixed(2) + "</td> <td align=center>" + f_numerik[sort_skor[i][0]].toFixed(2) + "</td> <td align=center>" + f_panjang_kalimat[sort_skor[i][0]].toFixed(2) + "</td> <td align=center>" + total_skor[sort_skor[i][0]].toFixed(2) + "</td></tr>");
				}
			</script>
		</table>
		
		<script>
			
			var index_kalimat_terambil = new Array();
			for(var i=0 ; i<banyak_terambil ; i++){
				index_kalimat_terambil[i] = sort_skor[i][0];
			}
			
			index_kalimat_terambil = index_kalimat_terambil.sort();
			
			document.write("<br><h3>Hasil Ringkasan<br> </h3>");

			document.write("<br><b>Hasil peringkasan sebanyak : " + Math.round(banyak_terambil) + " kalimat </b><br><br>");			
									
			for(var i=0 ; i<banyak_terambil ; i++){
					document.write("<b>" + (i+1) + "</b>. " + kalimat[index_kalimat_terambil[i] + 1] + " <b>(Kalimat ke-" + (index_kalimat_terambil[i] + 1) + ")</b><br><br>" );
			}			
			
		</script>

	</body>
</html>

	</td></tr></table>
</td></tr></table>