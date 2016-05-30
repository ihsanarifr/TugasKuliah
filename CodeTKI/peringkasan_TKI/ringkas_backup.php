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
			
			var hasil_token = tabulasi_kata(kalimat);
			document.write("<hr><br><b>Tabulasi Kata</b><br>");
			for(var i=0 ; i<hasil_token[0].length ; i++){
				document.write(hasil_token[0][i] + "=>" + hasil_token[1][hasil_token[0][i]] + "<br>");
			}
			var kata_unik = hasil_token[0];
			var positif = hasil_token[2];
			var negatif = hasil_token[3];
			var entiti = new Array('karena', 'artinya', 'sebab', 'sebabnya', 'namun', 'kesimpulan', 'kesimpulanya', 'singkatnya', 'singkat', 'akibat', 'akibatnya', 'sedangkan', 'sehingga', 'menurut', 'kemudian', 'tetapi', 'berdasarkan', 'kalau', 'pasalnya', 'adalah', 'ialah', 'yaitu', 'sebesar', 'seperti', 'hasil', 'hasilnya', 'sementara', 'katanya', 'mengatakan', 'menambahkan', 'ujar', 'ujarnya', 'menegaskan', 'menjelaskan', 'meskipun', 'apabila' );
					
			var hasil_fitur = cari_fitur(isi, judul_baru, kalimat, positif, negatif,  entiti, kata_unik, flag_stopword); 
			var f1 = hasil_fitur[0];
			var f2 = hasil_fitur[1];
			var f3 = hasil_fitur[2];
			var f4 = hasil_fitur[3];
			var f5 = hasil_fitur[4];
			var f6 = hasil_fitur[5];
			var f7 = hasil_fitur[6];
			var f8 = hasil_fitur[7];
			var f9 = hasil_fitur[8];
			
			var panjang_array = hasil_fitur[0].length;
			var total_skor = new Array();
			
			for(var i=0 ; i<panjang_array ; i++){
				total_skor[i] = f1[i] + f2[i] + f3[i] + f4[i] + f5[i] + f6[i] + f7[i] + f8[i] + f9[i];
			}
			
			var banyak_kalimat = kalimat.length;
			var banyak_terambil = 30/100 * banyak_kalimat;
						
		</script>

		<br> <hr> <br>
		<b><center>MATRIKS KOVARIAN</center></b>
		<br>
		<table border=1 align="center">
			<tr> <th width=100 align=center>Kalimat</th><th width=80 align=center>Fitur 1</th><th width=80 align=center>Fitur 2</th><th width=80 align=center>Fitur 3</th><th width=80 align=center>Fitur 4</th><th width=80 align=center>Fitur 5</th><th width=80 align=center>Fitur 6</th><th width=80 align=center>Fitur 7</th><th width=80 align=center>Fitur 8</th><th width=80 align=center>Fitur 9</th><th width=80 align=center>Total Skor</th> </tr>
		<script>
			for(var i=0 ; i<panjang_array ; i++){
					document.write("<tr> <td align=center>" + (i+1) + "</td> <td align=center>" + f1[i].toFixed(2) + "</td> <td align=center>" + f2[i].toFixed(2) + "</td> <td align=center>" + f3[i].toFixed(2) + "</td> <td align=center>" + f4[i].toFixed(2) + "</td> <td align=center>" + f5[i].toFixed(2) + "</td> <td align=center>" + f6[i].toFixed(2) + "</td> <td align=center>" + f7[i].toFixed(2) + "</td> <td align=center>" + f8[i].toFixed(2) + "</td> <td align=center>" + f9[i].toFixed(2) + "</td> <td align=center>" + total_skor[i].toFixed(2) + "</td></tr>");
			}
		</script>
		</table>
		

	</body>
</html>

	</td></tr></table>
</td></tr></table>