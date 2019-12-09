import csv


class JenisSampah:
    def __init__(self, _id, _hargaJual, _hargaBeli):
        self.id = _id
        self.hargaJual = _hargaJual
        self.hargaBeli = _hargaBeli


class GeneratedTableTransaksi:
    def __init__(self, _id, _id_nasabah, _id_pegawai, _id_pengepul, _tanggal, _jenis_transaksi, _berat_total, _cash_masuk, _cash_keluar):
        self.id = _id
        self.id_nasabah = _id_nasabah
        self.id_pegawai = _id_pegawai
        self.id_pengepul = _id_pengepul
        self. tanggal = _tanggal
        self.jenis_transaksi = _jenis_transaksi
        self.berat_total = _berat_total
        self.cash_masuk = _cash_masuk
        self.cash_keluar = _cash_keluar


class GeneratedTableDetail:
    def __init__(self, _id, _id_transaksi, _id_jenis_sampah, _berat):
        self.id = _id
        self.id_transaksi = _id_transaksi
        self.id_jenis_sampah = _id_jenis_sampah
        self.berat = _berat


# Load pool jenis sampah
pool_jenis_sampah = []
with open('pool_jenis_sampah.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
    for row in spamreader:
        pool_jenis_sampah.append(JenisSampah(row[0], row[1], row[2]))

# Load pool id nasabah
pool_nasabah = []
with open('pool_nasabah.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        pool_nasabah.append(row)

# Load pool id pegawai
pool_pegawai = []
with open('pool_pegawai.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        pool_pegawai.append(row)

# Load pool id nasabah
pool_pengepul = []
with open('pool_pengepul.csv', newline='') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in spamreader:
        pool_pengepul.append(row)

for _p in pool_jenis_sampah:
    print(_p.id, _p.hargaJual, _p.hargaBeli)


with open('generated.csv', 'w', newline='') as csvfile:
    wr = csv.writer(csvfile, delimiter='\t',
                    quotechar='|', quoting=csv.QUOTE_MINIMAL)

    for i in range(20):
        wr.writerow([i] + ['Spam'] * 8 + [''] + ['s'] * 4)
