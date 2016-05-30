# import the necessary packages
from pyimagesearch.shapedetector import ShapeDetector
from pyimagesearch.colorlabeler import ColorLabeler
import argparse
import imutils
import cv2

# argumen untuk mengambil data dari file
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required=True,
	help="lokasi gambar pada folde yang akan dimasukkan")
args = vars(ap.parse_args())

# mengambil gambar dan mengubah ukuran menjadi kecil
# usahakan bentuknya itu sudah satu warna sehingga bisa lebih baik untuk diambil
image = cv2.imread(args["image"])
resized = imutils.resize(image, width=300)
ratio = image.shape[0] / float(resized.shape[0])

# lalu emage tersebut diubah menjadi grayscale, blur dan menggunakan treshold
# Lihat pada saat melakukan blur disini menggunakan gaussianBlur dengan matrix 5,5
# tambahan menggunakan colorlab
# tambahan hasil gray di threshold
blurred = cv2.GaussianBlur(resized, (5, 5), 0)
gray = cv2.cvtColor(blurred, cv2.COLOR_BGR2GRAY)
lab = cv2.cvtColor(blurred, cv2.COLOR_BGR2LAB)
thresh = cv2.threshold(gray, 60, 255, cv2.THRESH_BINARY)[1]

# cv2.imshow("Blur", cv2.GaussianBlur(resized,(5,5),0))
# cv2.imshow("Gray", cv2.cvtColor(resized,cv2.COLOR_BGR2GRAY))
# cv2.imshow("lab", cv2.cvtColor(resized,cv2.COLOR_BGR2LAB))
# cv2.imshow("threshold",cv2.threshold(resized,60,255,cv2.THRESH_BINARY)[1])

# menemukan kontur dalam gambar yang sudah di treshold
cnts = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL,
	cv2.CHAIN_APPROX_SIMPLE)
cnts = cnts[0] if imutils.is_cv2() else cnts[1]

# inisialisasi ambil fungsi pada library shape detector dan color labeler
sd = ShapeDetector()
cl = ColorLabeler()

red = 0
green = 0
blue = 0
lingkaran = 0
segitiga = 0
persegi = 0
persegi_panjang = 0
pentagon = 0
nama = ""
# loop over the contours
for c in cnts:
	# compute the center of the contour
	M = cv2.moments(c)
	cX = int((M["m10"] / M["m00"]) * ratio)
	cY = int((M["m01"] / M["m00"]) * ratio)

	# mendeteksi bentuk dan warna dalam gambar menggunakan fungsi library
	shape = sd.detect(c)
	color = cl.label(lab, c)
	
	# Menghitung jumlah dari tiap warna yang muncul
	if color == 'red':
		red += 1
	elif color == 'blue':
		blue += 1
	elif color == 'green':
		green += 1
	# Menghitung jumlah dari tiap bentuk yang muncul
	if shape == 'circle':
		lingkaran += 1
		nama = 'lingkaran'
	elif shape == 'triangle':
		segitiga += 1
		nama = 'segitiga'
	elif shape == 'square':
		persegi += 1
		nama = 'persegi'
	elif shape == 'rectangle':
		persegi_panjang += 1
		nama = 'persegi panjang'
	elif shape == 'pentagon':
		pentagon += 1
		nama = 'segilima'
		
	# mengkalikan kontul koordinat (x, y)-coordinates dari ukuran ratio
	# menuliskan nama warna dan bentuk ke dekat bentuk yang terdeteksi
	c = c.astype("float")
	c *= ratio
	c = c.astype("int")
	text = "{} {}".format(color, nama)
	cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
	cv2.putText(image, text, (cX, cY),
		cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

	# menampilkan gambar ke layar
	cv2.imshow("Image", image)
	cv2.waitKey(0)

print "======================================="
print " Deteksi Bentuk dan Warna "
print " Beta Version "
print "======================================="
print "Jumlah Bentuk berwarna Merah : ",red
print "Jumlah Bentuk berwarna Hijau : ",green
print "Jumlah Bentuk berwarna Biru  : ",blue
print "---------------------------------------"
print "Jumlah Bentuk lingkaran       : ",lingkaran
print "Jumlah Bentuk Segitiga        : ",segitiga
print "Jumlah Bentuk Persegi         : ",persegi
print "Jumlah Bentuk Persegi Panjang : ",persegi_panjang
print "Jumlah Bentuk Segilima        : ",pentagon
print "======================================="
