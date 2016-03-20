def read_fasta(infile):
    seqs = []
    f = open(infile, 'r')
    try:
        name = ''
        seq = ''
        is_first_seq = True        
        for line in f:
            line = line.rstrip()
            if len(line) > 0:
                if line[0] == '>':
                    if not is_first_seq:
                        seqs.append([new, seq])
                        seq = ''
                    name = line[1:]
                    new = name
                    is_first_seq = False
                else:
                    seq += line
        seqs.append([new, seq])
    finally:
        f.close()
        return seqs

