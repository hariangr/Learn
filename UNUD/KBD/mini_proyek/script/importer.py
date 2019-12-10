import mysql.connector
import csv
from datetime import datetime

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    port="3306",
    passwd="KiterchINIuMiNGerLAyFuLtRO",
    database="new5_bank_sampah"
)


def addJenisSampah(_id, _nama_sampah, _harga_jual, _harga_beli):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO JENIS_SAMPAH (ID_JENIS_SAMPAH, NAMA_SAMPAH, HARGA_JUAL_PERKG, HARGA_BELI_PERKG) VALUES ('{_id}', '{_nama_sampah}', '{_harga_jual}', '{_harga_beli}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addNasabah(_id, _nama, _alamat):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO NASABAH (ID_NASABAH, NAMA_NASABAH, ALAMAT_NASABAH) VALUES ('{_id}', '{_nama}', '{_alamat}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addPegawai(_id, _nama, _alamat, _level):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO PEGAWAI (ID_PEGAWAI, NAMA_PEGAWAI, ALAMAT_PEGAWAI, LEVEL_PEGAWAI) VALUES ('{_id}', '{_nama}', '{_alamat}', '{_level}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addPengepul(_id, _nama, _alamat):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO PENGEPUL (ID_PENGEPUL, NAMA_PENGEPUL, ALAMAT_PENGEPUL) VALUES ('{_id}', '{_nama}', '{_alamat}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addTransaksi(ID_TRANSAKSI, ID_PEGAWAI, ID_NASABAH, ID_PENGEPUL, TANGGAL, JENIS_TRANSAKSI, BERAT_TOTAL, CASH_MASUK, CASH_KELUAR):
    # CASH_MASUK =  int(_CASH_MASUK)
    # CASH_KELUAR = int(_CASH_KELUAR)

    mycursor = mydb.cursor()
    sql = None
    if(JENIS_TRANSAKSI == "BELI"):
        sql = f"INSERT INTO TRANSAKSI (ID_TRANSAKSI, ID_PEGAWAI, ID_NASABAH , TANGGAL , JENIS_TRANSAKSI, BERAT_TOTAL, CASH_KELUAR) VALUES  ('{ID_TRANSAKSI}', '{ID_PEGAWAI}', '{ID_NASABAH}', '{TANGGAL}', '{JENIS_TRANSAKSI}', '{BERAT_TOTAL}', '{CASH_KELUAR}')"
    else:
        sql = f"INSERT INTO TRANSAKSI (ID_TRANSAKSI, ID_PEGAWAI, ID_PENGEPUL , TANGGAL , JENIS_TRANSAKSI, BERAT_TOTAL , CASH_MASUK) VALUES  ('{ID_TRANSAKSI}', '{ID_PEGAWAI}', '{ID_PENGEPUL}', '{TANGGAL}', '{JENIS_TRANSAKSI}', '{BERAT_TOTAL}', '{CASH_MASUK}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addDetail(	ID_DETAIL_TRANSAKSI	, ID_TRANSAKSI,	ID_JENIS_SAMPAH,	BERAT):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO DETAIL_TRANSAKSI ( ID_DETAIL_TRANSAKSI, ID_TRANSAKSI, ID_JENIS_SAMPAH, BERAT) VALUES ('{ID_DETAIL_TRANSAKSI}', '{ID_TRANSAKSI}', '{ID_JENIS_SAMPAH}', '{BERAT}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def sanitize(s):
    pass


def insertJenisSampah():
    # Load pool jenis sampah
    with open('jenis_sampah.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')
        for row in spamreader:
            # pool_jenis_sampah.append(JenisSampah(row[0], row[1], row[2]))
            # print(row[0], row[1], row[2], row[3])
            addJenisSampah(row[0], row[1], row[2], row[3])


def insertNasabah():
    # Load pool jenis sampah
    with open('nasabah.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')
        for row in spamreader:
            addNasabah(row[0], row[1], row[2])


def insertPegawai():
    # Load pool jenis sampah
    with open('pegawai.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')
        for row in spamreader:
            addPegawai(row[0], row[1], row[2], row[3])


def insertPengepul():
    # Load pool jenis sampah
    with open('pengepul.csv', newline='') as csvfile:
        spamreader = csv.reader(csvfile, delimiter=';', quotechar='|')
        for row in spamreader:
            addPengepul(row[0], row[1], row[2])


insertJenisSampah()
insertNasabah()
insertPegawai()
insertPengepul()

# addTransaksi("TR001", "PG002", "NB036", None,
#              "19-19-2000", "BELI", 3.0, None, 3000)
