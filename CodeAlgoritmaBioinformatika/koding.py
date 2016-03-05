#import fasta import read_fasta

import fasta
import codon



data = fasta.read_fasta('DNA.fasta')
nama    = data[0][0]
sekuens = data[0][1]



#transkripsi
mRNA = sekuens.replace('T','U')
print mRNA



#cari posisi start codon
start = mRNA.find('AUG')
print "Start codon ada di posisi %d" %(start)


#pecahin mRNA per tiga huruf, mulai dari start kodon
prot = ""
while start <= len(mRNA):
        kodon = mRNA[start:start+3]
        print kodon


        if kodon in ['UAA', 'UGA' , 'UAG']:
            break

        start +=3


        prot += codon.codontable[kodon]
print prot
    
