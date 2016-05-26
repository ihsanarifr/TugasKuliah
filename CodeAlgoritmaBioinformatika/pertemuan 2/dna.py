# from fasta import read_fasta

import fasta
import codon

#sekuens = fasta.read_fasta('flu_A.fasta')

#print(sekuens)

data = fasta.read_fasta('flu_A.fasta')

nama = data[0][0]
sekuens = data[0][1]

#Menghitung persentasi A, T, G, C

sum_basa_adenin = sekuens.count("A")
sum_basa_timin = sekuens.count("T")
sum_basa_guanin = sekuens.count("G")
sum_basa_citocin = sekuens.count("C")

total_basa = sum_basa_adenin + sum_basa_timin + sum_basa_guanin + sum_basa_citocin

print ("\n================Persentase A, T, G, C===============")
print ("Persentase A = %.2f%%" %((sum_basa_adenin / total_basa) * 100))
print ("Persentase T = %.2f%%" %((sum_basa_timin / total_basa) * 100))
print ("Persentase G = %.2f%%" %((sum_basa_guanin / total_basa) * 100))
print ("Persentase C = %.2f%%" %((sum_basa_citocin / total_basa) * 100))

#transkripsi

mRNA = sekuens.replace('T','U')
print ("\n===============Hasil Transkripsi==================")
print(mRNA)

#Translasi
#cari posisi start kodon

start = mRNA.find('AUG')
print ("\n=================Posisi Start Kodon=================")
print ("start codon ada diposisi %d" %(start))

protein =""
panjang_asam_amino = 0;
print ("\n=================Hasil Translasi=========================")
while start <= len(mRNA):
    
    kodon = mRNA[start:start+3]
    
    if kodon in ('UAA', 'UGA', 'UAG'):
        break
    start += 3
    
    protein = codon.codontable[kodon]
    panjang_asam_amino += 1
    print("{}:{}".format(kodon, protein), end=" ")
#Panjang Asam Amino
print ("\n\n=================Panjang Rangkaian Asam Amino==============")
print ("Panjang Asam Amino = %d" %panjang_asam_amino)
