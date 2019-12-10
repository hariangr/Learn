import csv
import random as ran

ratioBeliJual = 0.9


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

    def __str__(self):
        return f'id\tid_nasabah\tid_pegawai\tid_pengepul\ttanggal\tjenis_transaksi\tberat_total\tcash_masuk\tcash_keluar\n' + f'{self.id}\t{self.id_nasabah}\t{self.id_pegawai}\t{self.id_pengepul}\t{self.tanggal}\t{self.jenis_transaksi}\t{self.berat_total}\t{self.cash_masuk}\t{self.cash_keluar}'


class GeneratedTableDetail:
    def __init__(self, _id, _id_transaksi, _id_jenis_sampah, _berat):
        self.id = _id
        self.id_transaksi = _id_transaksi
        self.id_jenis_sampah = _id_jenis_sampah
        self.berat = _berat

    def __str__(self):
        return f'id\t\tid_transaksi\tid_jenis_sampah\t\tberat\n' + f'{self.id}\t\t{self.id_transaksi}\t\t{self.id_jenis_sampah}\t\t\t{self.berat}'


pool_jenis_sampah = []
pool_nasabah = []
pool_pegawai = []
pool_pengepul = []


def loadPools():
    # Load pool jenis sampah
    with open('pool_jenis_sampah.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
        for row in spamreader:
            pool_jenis_sampah.append(JenisSampah(row[0], row[1], row[2]))

    # Load pool id nasabah
    with open('pool_nasabah.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in spamreader:
            pool_nasabah.append(row)

    # Load pool id pegawai
    with open('pool_pegawai.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in spamreader:
            pool_pegawai.append(row)

    # Load pool id nasabah
    with open('pool_pengepul.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in spamreader:
            pool_pengepul.append(row)


def generateTransaksiId(i):
    return 'TR' + str(i).zfill(3)


def generateDetailId(i):
    return 'DT' + str(i).zfill(3)


def generateOneRandomDetail(_idOffset, _idTransaksi):
    _randomJenisSampah = ran.randrange(0, len(pool_jenis_sampah))
    _randomJenisSampahId = pool_jenis_sampah[_randomJenisSampah].id

    _randomBerat = ran.randrange(1, 10) / 2

    _detail = GeneratedTableDetail(
        _id, _idTransaksi, _randomJenisSampahId, _randomBerat)

    return _detail


def _generateOneRandomTransaksiBeli(_idOffset, numDetail, _idPegawai):
    ranNasabah = ran.randrange(0, len(pool_nasabah))
    ranIdNasabah = pool_nasabah[ranNasabah]

    _transaksi = GeneratedTableTransaksi(generateTransaksiId(
        _idOffset), ranIdNasabah, _idPegawai, '', '00-00-0000', 'BELI', 3, 3, '')

    return _transaksi


def _generateOneRandomTransaksiJual(_idOffset, numDetail, _idPegawai):
    ranPengepul = ran.randrange(0, len(pool_pengepul))
    ranIdPengepul = pool_pengepul[ranPengepul]

    _transaksi = GeneratedTableTransaksi(generateTransaksiId(
        _idOffset), '', _idPegawai, ranIdPengepul, '00-00-0000', 'JUAL', 3, 3, '')

    return _transaksi


def generateOneRandomTransaksi(_idOffset, numDetail=1):
    isBeli = None

    _ranJualvBeli = ran.randrange(0, 100) / 100
    if (_ranJualvBeli <= ratioBeliJual):
        isBeli = 1
    else:
        isBeli = 0

    ranPegawai = ran.randrange(0, len(pool_pegawai))
    ranIdPegawai = pool_pegawai[ranPegawai]

    _traksaksi = None
    if (isBeli == 1):
        _transaksi = _generateOneRandomTransaksiBeli(
            _idOffset, numDetail, ranIdPegawai)
    elif(isBeli == 0):
        _transaksi = _generateOneRandomTransaksiJual(
            _idOffset, numDetail, ranIdPegawai)

    return _transaksi


# for _p in pool_jenis_sampah:
#     print(_p.id, _p.hargaJual, _p.hargaBeli)


# with open('generated.csv', 'w', newline='') as csvfile:
#     wr = csv.writer(csvfile, delimiter='\t',
#                     quotechar='|', quoting=csv.QUOTE_MINIMAL)

#     for i in range(20):
#         wr.writerow([i] + ['Spam'] * 8 + [''] + ['s'] * 4)
loadPools()

id_detail_offset = 1
for id_transaksi_offset in range(1, 50):
    pass

# print(generateOneRandomDetail("DT001", "TR001"))
# print(generateOneRandomDetail("DT002", "TR002"))
# generateOneRandomDetail("DT001", "TR001")

print(generateOneRandomTransaksi(1))
