group_2 = ['laki-laki';'perempuan';'laki-laki';'perempuan';'laki-laki';'perempuan']
training_2 = [155 50;175 63;160 55;177 68;163 52;176 78]
sampel_2 = [175 60;172 58;159 55]
class_2 = knnclassify(sampel_2,training_2,group_2,3)
