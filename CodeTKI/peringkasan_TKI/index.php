<?php
	$file = fopen('config.txt' , 'r');
	$i = 0;
	while(!feof($file) && $i<3)  
	{  
		$config[$i] = fgetss($file);
		//echo $config[$i];
		$i++;
	}
?>

<html>
	<head>
		<script type="text/javascript" src="jquery-1.4.js"></script>
		<script type="text/javascript">
			$(document).ready(function(){

				$("#tabel2").show("fast"); 
				$("#tabel1").hide("fast"); 
				
				
				$(".btn1").click(function(){
					$("#tabel1").toggle("fast");
					document.form.jenis_input.value = 1;
					$("#tabel2").hide("fast"); 
					$("#tabel1").show("fast"); 
					
				});

				$(".btn2").click(function(){
					$("#tabel2").toggle("fast");
					document.form.jenis_input.value = 2;
					$("#tabel1").hide("fast"); 
					$("#tabel2").show("fast"); 
				});
			});
		</script>		
	</head>

	<body style="background-image:url(dd1.jpg); background-repeat : repeat; backround : transparant;">
			<table border="0" width="900" align="center">
			<tr><td>
				<br><br><br>
				<div align="center">
					<div>
						<img src="ringkas3.png" width="400" />
					</div>
					<br>

					<form id="form" method="post" name="form" action="ringkas.php" enctype="multipart/form-data" onSubmit="">
					
					<table border="5" width="710" cellspacing="10" align="center">
					<tr align="center">
						<td>
						<div style="font-family: Lucida Sans Typewriter;"  class="btn1"> <b>Input Teks</b> </div>
							<table id="tabel1" width="700" border="0" cellspacing="2" >
								<tr align="center">
									<td width="100">Judul Dokumen</td>
									<td width="25"> <b>:</b> </td>
									<td width="300"> <input type="text" style="padding: 5px; color: cyan; background:black; width: 500px" name="judul" id="judul" /> </td>
								</tr>
								<tr align="center">
									<td width="100">Isi Dokumen</td>
									<td width="25"> <b>:</b> </td>
									<td width="300"> <textarea style="padding: 5px; color: cyan; background:black; width: 500px" name="isi" id="isi" cols="58" rows="12" /></textarea> </td>
								</tr>	
							</table>
						</td>
					</tr>
					<tr align="center">
						<td>
						<div style="font-family: Lucida Sans Typewriter;" class="btn2"> <b>Input File</b> </div>
							<table id="tabel2" width="700" border="0" cellspacing="8" >
								<tr align="center">
									<td width="100"> Input Dokumen</td>
									<td width="25"> <b>:</b> </td>
									<td width="500"> <input type="file" style="padding: 5px; color: cyan; background:black; width: 500px;" name="dokumen" id="dokumen" /></textarea> </td>
								</tr>
							</table>				
						</td>
					</tr>
					</table>

						<input type="hidden" name="jenis_input" value="2"/>
						<input type="hidden" name="nama_folder_rule" value="<?php echo $config[1]?>"/>
						<input type="hidden" name="flag_stopword" value="<?php echo $config[2]?>"/>
						<br>
						<input type="submit" value="Proses" style="height: 35px; width: 120px" />

					</form>
					<br>
				</div>
								
			</td></tr>
		</table>
		


	</body>
</html>
