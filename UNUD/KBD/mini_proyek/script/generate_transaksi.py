import csv
import random as ran
import importer as haIm
import datetime as datetime

idDtOffsetPembelian = 1
idDtOffsetPengepulan = 1
dateTrOffset = datetime.date(2018, 8, 13)


class JenisSampah:
    def __init__(self, _id, _hargaJual, _hargaBeli):
        self.id = _id
        self.hargaJual = int(_hargaJual)
        self.hargaBeli = int(_hargaBeli)


class GeneratedTableTransaksi:
    def __init__(self, _id, _id_nasabah, _id_pegawai, _id_pengepul, _tanggal, _jenis_transaksi, _berat_total, _cash_masuk, _cash_keluar):
        self.id = _id
        self.id_nasabah = _id_nasabah
        self.id_pegawai = _id_pegawai
        self.id_pengepul = _id_pengepul
        self.tanggal = _tanggal
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


def generateAdvancingDate():
    

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
            pool_nasabah.append(row[0])

    # Load pool id pegawai
    with open('pool_pegawai.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in spamreader:
            pool_pegawai.append(row[0])

    # Load pool id nasabah
    with open('pool_pengepul.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in spamreader:
            pool_pengepul.append(row[0])


def generateTransaksiId(i):
    return 'TR' + str(i).zfill(3)


def generateDetailId(i):
    return 'DT' + str(i).zfill(3)


def generateOneRandomDetail(_idOffset, _idTransaksi):
    _randomJenisSampah = ran.randrange(0, len(pool_jenis_sampah))
    _randomJenisSampahId = pool_jenis_sampah[_randomJenisSampah].id

    _randomBerat = ran.randrange(1, 10) / 2

    _detail = GeneratedTableDetail(
        generateDetailId(_idOffset), _idTransaksi, _randomJenisSampahId, _randomBerat)

    return _detail


def getJenisSampahById(_id):
    for it in pool_jenis_sampah:
        if(it.id == _id):
            return it
    return None


def _generateOneRandomTransaksiBeli(_idOffset, numDetail, _idPegawai):
    global idDtOffsetPembelian

    _trId = generateTransaksiId(_idOffset)
    ranNasabah = ran.randrange(0, len(pool_nasabah))
    ranIdNasabah = pool_nasabah[ranNasabah]

    arrDetail = []

    _beratTotal = 0
    _cashOut = 0

    for _ in range(numDetail):
        print("Detail no:", idDtOffsetPembelian)
        _detail = generateOneRandomDetail(idDtOffsetPembelian, _trId)
        arrDetail.append(_detail)
        _beratTotal += _detail.berat
        _cashOut = _cashOut + \
            getJenisSampahById(_detail.id_jenis_sampah).hargaBeli
        idDtOffsetPembelian += 1

    print(_cashOut)

    _transaksi = GeneratedTableTransaksi(generateTransaksiId(
        _idOffset), ranIdNasabah, _idPegawai, '', datetime.datetime(2019, 11, 12), 'BELI', _beratTotal, '', _cashOut)

    # Tulis yg pertama semua
    csvWriteLn(_transaksi, arrDetail[0])
    haIm.addTransaksiPembelian(_transaksi.id, _transaksi.id_pegawai, _transaksi.id_nasabah,
                               _transaksi.tanggal, _transaksi.berat_total, _transaksi.cash_keluar)
    haIm.addDetailPembelian(arrDetail[0].id, arrDetail[0].id_transaksi,
                            arrDetail[0].id_jenis_sampah, arrDetail[0].berat)

    if(numDetail > 1):
        for i in range(1, len(arrDetail)):
            csvWriteLn(GeneratedTableTransaksi(
                '', '', '', '', '', '', '', '', ''), arrDetail[i])
            haIm.addDetailPembelian(arrDetail[i].id, arrDetail[i].id_transaksi,
                                    arrDetail[i].id_jenis_sampah, arrDetail[i].berat)

    return _transaksi


def _generateOneRandomTransaksiJual(_idOffset, numDetail, _idPegawai):
    global idDtOffsetPengepulan

    _trId = generateTransaksiId(_idOffset)

    ranPengepul = ran.randrange(0, len(pool_pengepul))
    ranIdPengepul = pool_pengepul[ranPengepul]

    arrDetail = []

    _beratTotal = 0
    _cashIn = 0

    for _ in range(numDetail):
        print("xxx__")
        _detail = generateOneRandomDetail(idDtOffsetPengepulan, _trId)
        arrDetail.append(_detail)
        _beratTotal += _detail.berat
        _cashIn = _cashIn + \
            getJenisSampahById(_detail.id_jenis_sampah).hargaJual
        idDtOffsetPengepulan += 1

    _transaksi = GeneratedTableTransaksi(generateTransaksiId(
        _idOffset), '', _idPegawai, ranIdPengepul, datetime.datetime(2019, 11, 12), 'JUAL', _beratTotal, _cashIn, '')

    haIm.addTransaksiPengepulan(_transaksi.id, _transaksi.id_pegawai, _transaksi.id_pengepul, _transaksi.tanggal,
                                _transaksi.berat_total, _transaksi.cash_masuk)
    haIm.addDetailPengepulan(arrDetail[0].id, arrDetail[0].id_transaksi,
                             arrDetail[0].id_jenis_sampah, arrDetail[0].berat)

    # Tulis yg pertama semua
    csvWriteLn(_transaksi, arrDetail[0])

    if(numDetail > 1):
        for i in range(1, len(arrDetail)):
            csvWriteLn(GeneratedTableTransaksi(
                '', '', '', '', '', '', '', '', ''), arrDetail[i])
            haIm.addDetailPengepulan(arrDetail[i].id, arrDetail[i].id_transaksi,
                                     arrDetail[i].id_jenis_sampah, arrDetail[i].berat)

    return _transaksi


def csvWriteLn(tr, dt):
    with open('result.csv', 'a', newline='\n') as csvfile:
        wr = csv.writer(csvfile, delimiter='\t',
                        quotechar='|', quoting=csv.QUOTE_MINIMAL)
        wr.writerow([tr.id] + [tr.id_nasabah]+[tr.id_pegawai]+[tr.id_pengepul]+[tr.tanggal]+[tr.jenis_transaksi] +
                    [tr.berat_total]+[tr.cash_masuk]+[tr.cash_keluar]+[''] + [dt.id]+[dt.id_transaksi]+[dt.id_jenis_sampah]+[dt.berat])


loadPools()

haIm.insertJenisSampah()
haIm.insertNasabah()
haIm.insertPegawai()
haIm.insertPengepul()

for i in range(1, 101):
    ranPegawai = ran.randrange(0, len(pool_pegawai))
    ranIdPegawai = pool_pegawai[ranPegawai]

    # Transaksi Beli
    ranNumDetail = ran.randrange(1, 5)
    _generateOneRandomTransaksiBeli(
        i, ranNumDetail, ranIdPegawai,)

    # Transaksi Jual
    _generateOneRandomTransaksiJual(
        i, 1, ranIdPegawai)
