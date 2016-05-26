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
# Lihat pada
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
# loop over the contours
for c in cnts:
	# compute the center of the contour
	M = cv2.moments(c)
	cX = int((M["m10"] / M["m00"]) * ratio)
	cY = int((M["m01"] / M["m00"]) * ratio)

	# detect the shape of the contour and label the color
	shape = sd.detect(c)
	color = cl.label(lab, c)

	if color == 'red':
		red += 1
	elif color == 'blue':
		blue += 1
	elif color == 'green':
		green += 1

	# multiply the contour (x, y)-coordinates by the resize ratio,
	# then draw the contours and the name of the shape and labeled
	# color on the image
	c = c.astype("float")
	c *= ratio
	c = c.astype("int")
	text = "{} {}".format(color, shape)
	cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
	cv2.putText(image, text, (cX, cY),
		cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)

	# show the output image
	cv2.imshow("Image", image)
	cv2.waitKey(0)
print red
print green
print blue