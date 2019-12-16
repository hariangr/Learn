import mysql.connector
import csv
from datetime import datetime

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    port="1201",
    passwd="rootpassword",
    database="bank_sampah15"
)


def addJenisSampah(_id, _nama_sampah, _harga_jual, _harga_beli):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_jenis_sampah (id_jenis_sampah, nama_sampah, harga_jual_perkg, harga_beli_perkg) VALUES ('{_id}', '{_nama_sampah}', '{_harga_jual}', '{_harga_beli}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addNasabah(_id, _nama, _alamat):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_nasabah (id_nasabah, nama_nasabah, alamat_nasabah) VALUES ('{_id}', '{_nama}', '{_alamat}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addPegawai(_id, _nama, _alamat, _level):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_pegawai (id_pegawai, nama_pegawai, alamat_pegawai, level_pegawai) VALUES ('{_id}', '{_nama}', '{_alamat}', '{_level}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addPengepul(_id, _nama, _alamat):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_pengepul (id_pengepul, nama_pengepul, alamat_pengepul) VALUES ('{_id}', '{_nama}', '{_alamat}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addTransaksiPembelian(ID_TRANSAKSI, ID_PEGAWAI, ID_NASABAH, TANGGAL, BERAT_TOTAL, CASH_KELUAR):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_transaksi_pembelian (id_transaksi_pembelian, id_pegawai, id_nasabah , tgl_transaksi, berat_total, cash_keluar) VALUES  ('{ID_TRANSAKSI}', '{ID_PEGAWAI}', '{ID_NASABAH}', '{TANGGAL}', '{BERAT_TOTAL}', '{CASH_KELUAR}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addDetailPembelian(	ID_DETAIL_TRANSAKSI	, ID_TRANSAKSI,	ID_JENIS_SAMPAH,	BERAT):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_detail_transaksi_pembelian ( id_detail_transaksi_pembelian, id_transaksi_pembelian, id_jenis_sampah, berat) VALUES ('{ID_DETAIL_TRANSAKSI}', '{ID_TRANSAKSI}', '{ID_JENIS_SAMPAH}', '{BERAT}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addTransaksiPengepulan(ID_TRANSAKSI, ID_PEGAWAI, ID_PENGEPUL, TANGGAL, BERAT_TOTAL, CASH_MASUK):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_transaksi_pengepulan (id_transaksi_pengepulan, id_pegawai, id_pengepul , tgl_transaksi, berat_total, cash_masuk) VALUES  ('{ID_TRANSAKSI}', '{ID_PEGAWAI}', '{ID_PENGEPUL}', '{TANGGAL}', '{BERAT_TOTAL}', '{CASH_MASUK}')"

    print(sql)
    mycursor.execute(sql)

    mydb.commit()


def addDetailPengepulan(	ID_DETAIL_TRANSAKSI	, ID_TRANSAKSI,	ID_JENIS_SAMPAH,	BERAT):
    mycursor = mydb.cursor()
    sql = f"INSERT INTO tb_detail_transaksi_pengepulan ( id_detail_transaksi_pengepulan, id_transaksi_pengepulan, id_jenis_sampah, berat) VALUES ('{ID_DETAIL_TRANSAKSI}', '{ID_TRANSAKSI}', '{ID_JENIS_SAMPAH}', '{BERAT}')"
    print(sql)
    mycursor.execute(sql)

    mydb.commit()


# def addTransaksiPengepulan(ID_TRANSAKSI, ID_PEGAWAI, ID_NASABAH, ID_PENGEPUL, TANGGAL, JENIS_TRANSAKSI, BERAT_TOTAL, CASH_MASUK, CASH_KELUAR):
#     mycursor = mydb.cursor()
#     sql = f"INSERT INTO TRANSAKSI (ID_TRANSAKSI, ID_PEGAWAI, ID_PENGEPUL , TANGGAL , JENIS_TRANSAKSI, BERAT_TOTAL , CASH_MASUK) VALUES  ('{ID_TRANSAKSI}', '{ID_PEGAWAI}', '{ID_PENGEPUL}', '{TANGGAL}', '{JENIS_TRANSAKSI}', '{BERAT_TOTAL}', '{CASH_MASUK}')"

#     print(sql)
#     mycursor.execute(sql)

#     mydb.commit()


# def addDetailPengepulan(	ID_DETAIL_TRANSAKSI	, ID_TRANSAKSI,	ID_JENIS_SAMPAH,	BERAT):
#     mycursor = mydb.cursor()
#     sql = f"INSERT INTO DETAIL_TRANSAKSI ( ID_DETAIL_TRANSAKSI, ID_TRANSAKSI, ID_JENIS_SAMPAH, BERAT) VALUES ('{ID_DETAIL_TRANSAKSI}', '{ID_TRANSAKSI}', '{ID_JENIS_SAMPAH}', '{BERAT}')"
#     print(sql)
#     mycursor.execute(sql)

#     mydb.commit()


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

