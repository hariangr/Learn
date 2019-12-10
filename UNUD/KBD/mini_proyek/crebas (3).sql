/*==============================================================*/
/* DBMS name:      MySQL 5.0                                    */
/* Created on:     12/10/2019 2:59:20 PM                        */
/*==============================================================*/


/*==============================================================*/
/* Table: DETAIL_TRANSAKSI                                      */
/*==============================================================*/
create table DETAIL_TRANSAKSI
(
   ID_DETAIL_TRANSAKSI  char(5) not null  comment '',
   ID_TRANSAKSI         char(5)  comment '',
   ID_JENIS_SAMPAH      char(5)  comment '',
   BERAT                numeric(8,0)  comment '',
   primary key (ID_DETAIL_TRANSAKSI)
);

/*==============================================================*/
/* Table: JENIS_SAMPAH                                          */
/*==============================================================*/
create table JENIS_SAMPAH
(
   ID_JENIS_SAMPAH      char(5) not null  comment '',
   NAMA_SAMPAH          varchar(30)  comment '',
   HARGA_JUAL_PERKG     int  comment '',
   HARGA_BELI_PERKG     int  comment '',
   primary key (ID_JENIS_SAMPAH)
);

/*==============================================================*/
/* Table: NASABAH                                               */
/*==============================================================*/
create table NASABAH
(
   ID_NASABAH           char(5) not null  comment '',
   NAMA_NASABAH         varchar(30)  comment '',
   ALAMAT_NASABAH       varchar(100)  comment '',
   primary key (ID_NASABAH)
);

/*==============================================================*/
/* Table: PEGAWAI                                               */
/*==============================================================*/
create table PEGAWAI
(
   ID_PEGAWAI           char(5) not null  comment '',
   NAMA_PEGAWAI         varchar(100)  comment '',
   ALAMAT_PEGAWAI       varchar(100)  comment '',
   LEVEL_PEGAWAI        numeric(8,0)  comment '',
   primary key (ID_PEGAWAI)
);

/*==============================================================*/
/* Table: PENGEPUL                                              */
/*==============================================================*/
create table PENGEPUL
(
   ID_PENGEPUL          char(5) not null  comment '',
   NAMA_PENGEPUL        varchar(30)  comment '',
   ALAMAT_PENGEPUL      varchar(100)  comment '',
   primary key (ID_PENGEPUL)
);

/*==============================================================*/
/* Table: TRANSAKSI                                             */
/*==============================================================*/
create table TRANSAKSI
(
   ID_TRANSAKSI         char(5) not null  comment '',
   ID_PEGAWAI           char(5)  comment '',
   ID_NASABAH           char(5)  comment '',
   ID_PENGEPUL          char(5)  comment '',
   TANGGAL              datetime  comment '',
   JENIS_TRANSAKSI      varchar(10)  comment '',
   BERAT_TOTAL          decimal  comment '',
   CASH_MASUK           int  comment '',
   CASH_KELUAR          int  comment '',
   primary key (ID_TRANSAKSI)
);

alter table DETAIL_TRANSAKSI add constraint FK_DETAIL_T_MENDETAIL_JENIS_SA foreign key (ID_JENIS_SAMPAH)
      references JENIS_SAMPAH (ID_JENIS_SAMPAH) on delete restrict on update restrict;

alter table DETAIL_TRANSAKSI add constraint FK_DETAIL_T_MENJABARK_TRANSAKS foreign key (ID_TRANSAKSI)
      references TRANSAKSI (ID_TRANSAKSI) on delete restrict on update restrict;

alter table TRANSAKSI add constraint FK_TRANSAKS_MELAKUKAN_PEGAWAI foreign key (ID_PEGAWAI)
      references PEGAWAI (ID_PEGAWAI) on delete restrict on update restrict;

alter table TRANSAKSI add constraint FK_TRANSAKS_MENGEPUL_PENGEPUL foreign key (ID_PENGEPUL)
      references PENGEPUL (ID_PENGEPUL) on delete restrict on update restrict;

alter table TRANSAKSI add constraint FK_TRANSAKS_MENJUAL_NASABAH foreign key (ID_NASABAH)
      references NASABAH (ID_NASABAH) on delete restrict on update restrict;

