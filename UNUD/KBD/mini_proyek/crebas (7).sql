/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     12/16/2019 8:49:53 PM                        */
/*==============================================================*/


/*==============================================================*/
/* Table: DETAIL_TRANSAKSI_PEMBELIAN                            */
/*==============================================================*/
create table DETAIL_TRANSAKSI_PEMBELIAN
(
   ID_DETAIL_PEMBELIAN  char(5) not null  comment '',
   ID_KATEGORI_SAMPAH   char(5)  comment '',
   ID_SAMPAH_BELI       char(5) not null  comment '',
   TOTAL_PEMBELIAN      int not null  comment '',
   primary key (ID_DETAIL_PEMBELIAN)
);

/*==============================================================*/
/* Table: DETAIL_TRANSAKSI_PENGEPUL                             */
/*==============================================================*/
create table DETAIL_TRANSAKSI_PENGEPUL
(
   ID_DETAIL_PENGEPULAN char(5) not null  comment '',
   ID_KATEGORI_SAMPAH   char(5)  comment '',
   ID_SAMPAH_PENGEPULAN char(5) not null  comment '',
   TOTAL_PENGEPULAN     int not null  comment '',
   primary key (ID_DETAIL_PENGEPULAN)
);

/*==============================================================*/
/* Table: KATEGORI_SAMPAH                                       */
/*==============================================================*/
create table KATEGORI_SAMPAH
(
   ID_KATEGORI_SAMPAH   char(5) not null  comment '',
   NAMA_SAMPAH          varchar(20) not null  comment '',
   HARGA_JUAL_PERKG     int not null  comment '',
   HARGA_BELI_PERKG     int not null  comment '',
   primary key (ID_KATEGORI_SAMPAH)
);

/*==============================================================*/
/* Table: NASABAH                                               */
/*==============================================================*/
create table NASABAH
(
   ID_NASABAH           char(5) not null  comment '',
   NAMA_NASABAH         varchar(30) not null  comment '',
   ALAMAT_NASABAH       varchar(100) not null  comment '',
   primary key (ID_NASABAH)
);

/*==============================================================*/
/* Table: PEGAWAI                                               */
/*==============================================================*/
create table PEGAWAI
(
   ID_PEGAWAI           char(5) not null  comment '',
   NAMA_PEGAWAI         varchar(30) not null  comment '',
   ALAMAT_PEGAWAI       varchar(100) not null  comment '',
   LEVEL_PEGAWAI        numeric(8,0) not null  comment '',
   primary key (ID_PEGAWAI)
);

/*==============================================================*/
/* Table: PENGEPUL                                              */
/*==============================================================*/
create table PENGEPUL
(
   ID_PENGEPUL          char(5) not null  comment '',
   NAMA_PENGEPUL        varchar(30) not null  comment '',
   ALAMAT_PENGEPUL      varchar(100) not null  comment '',
   primary key (ID_PENGEPUL)
);

/*==============================================================*/
/* Table: TRANSAKSI_PEMBELIAN                                   */
/*==============================================================*/
create table TRANSAKSI_PEMBELIAN
(
   ID_TRANSAKSI_PEMBELIAN char(5) not null  comment '',
   ID_DETAIL_PEMBELIAN  char(5)  comment '',
   ID_NASABAH           char(5)  comment '',
   ID_PEGAWAI           char(5)  comment '',
   TGL_TRANSAKSI_PEMBELIAN date  comment '',
   CASH_KELUAR          int not null  comment '',
   primary key (ID_TRANSAKSI_PEMBELIAN)
);

/*==============================================================*/
/* Table: TRANSAKSI_PENGEPULAN                                  */
/*==============================================================*/
create table TRANSAKSI_PENGEPULAN
(
   ID_TRANSAKSI_PENGEPULAN char(5) not null  comment '',
   ID_PEGAWAI           char(5)  comment '',
   ID_PENGEPUL          char(5)  comment '',
   ID_DETAIL_PENGEPULAN char(5)  comment '',
   TGL_TRANSAKSI_PENGEPULAN datetime not null  comment '',
   CASH_MASUK           int not null  comment '',
   primary key (ID_TRANSAKSI_PENGEPULAN)
);

alter table DETAIL_TRANSAKSI_PEMBELIAN add constraint FK_DETAIL_T_MENDETAIL_KATEGORI_BELI foreign key (ID_KATEGORI_SAMPAH)
      references KATEGORI_SAMPAH (ID_KATEGORI_SAMPAH) on delete restrict on update restrict;

alter table DETAIL_TRANSAKSI_PENGEPUL add constraint FK_DETAIL_T_MENDETAIL_KATEGORI_PENGEPUL foreign key (ID_KATEGORI_SAMPAH)
      references KATEGORI_SAMPAH (ID_KATEGORI_SAMPAH) on delete restrict on update restrict;

alter table TRANSAKSI_PEMBELIAN add constraint FK_TRANSAKS_MEJUAL_NASABAH foreign key (ID_NASABAH)
      references NASABAH (ID_NASABAH) on delete restrict on update restrict;

alter table TRANSAKSI_PEMBELIAN add constraint FK_TRANSAKS_MELAKUKAN_PEGAWAI_BELI foreign key (ID_PEGAWAI)
      references PEGAWAI (ID_PEGAWAI) on delete restrict on update restrict;

alter table TRANSAKSI_PEMBELIAN add constraint FK_TRANSAKS_MENDETAIL_DETAIL_T_BELI foreign key (ID_DETAIL_PEMBELIAN)
      references DETAIL_TRANSAKSI_PEMBELIAN (ID_DETAIL_PEMBELIAN) on delete restrict on update restrict;

alter table TRANSAKSI_PENGEPULAN add constraint FK_TRANSAKS_MELAKUKAN_PEGAWAI_PENGEPULAN foreign key (ID_PEGAWAI)
      references PEGAWAI (ID_PEGAWAI) on delete restrict on update restrict;

alter table TRANSAKSI_PENGEPULAN add constraint FK_TRANSAKS_MENDETAIL_DETAIL_T_PENGEPULAN foreign key (ID_DETAIL_PENGEPULAN)
      references DETAIL_TRANSAKSI_PENGEPUL (ID_DETAIL_PENGEPULAN) on delete restrict on update restrict;

alter table TRANSAKSI_PENGEPULAN add constraint FK_TRANSAKS_MENGEPUL_PENGEPUL foreign key (ID_PENGEPUL)
      references PENGEPUL (ID_PENGEPUL) on delete restrict on update restrict;

