group_3 = {'tidak';'tidak';'kebakaran';'kebakaran';'tidak';'kebakaran';'kebakaran';'kebakaran';'tidak'}

training_3 = [24 38 27 100;
    30 35 29 104;
    52 30 21 88;
    53 30 24 101;
    23 40 25 120;
    64 32 25 84;
    67 28 22 90;
    69 24 23 103;
    29 32 25 192]

sampel_3 = [25 30 20 95]

class_3 = knnclassify(sampel_3,training_3,group_3,3)