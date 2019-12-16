/*==============================================================*/
/* DBMS name:      SAP SQL Anywhere 17                          */
/* Created on:     12/16/2019 8:06:11 PM                        */
/*==============================================================*/



/*==============================================================*/
/* Table: DETAIL_TRANSAKSI_PEMBELIAN                            */
/*==============================================================*/
create or replace table DETAIL_TRANSAKSI_PEMBELIAN 
(
   ID_DETAIL_PEMBELIAN  varchar(5)                        not null,
   KAT_ID_KATEGORI_SAMPAH char(5)                        null,
   ID_KATEGORI_SAMPAH   char(5)                        not null,
   TOTAL_PEMBELIAN      integer                        not null,
   constraint PK_DETAIL_TRANSAKSI_PEMBELIAN primary key clustered (ID_DETAIL_PEMBELIAN)
);

/*==============================================================*/
/* Index: DETAIL_TRANSAKSI_PEMBELIAN_PK                         */
/*==============================================================*/
create unique clustered index DETAIL_TRANSAKSI_PEMBELIAN_PK on DETAIL_TRANSAKSI_PEMBELIAN (
ID_DETAIL_PEMBELIAN ASC
);

/*==============================================================*/
/* Index: RELATIONSHIP_7_FK                                     */
/*==============================================================*/
create index RELATIONSHIP_7_FK on DETAIL_TRANSAKSI_PEMBELIAN (
KAT_ID_KATEGORI_SAMPAH ASC
);

/*==============================================================*/
/* Table: DETAIL_TRANSAKSI_PENGEPUL                             */
/*==============================================================*/
create or replace table DETAIL_TRANSAKSI_PENGEPUL 
(
   ID_DETAIL_PENGEPULAN char(5)                        not null,
   KAT_ID_KATEGORI_SAMPAH char(5)                        null,
   ID_KATEGORI_SAMPAH   char(5)                        not null,
   TOTAL_PENGEPULAN     integer                        not null,
   constraint PK_DETAIL_TRANSAKSI_PENGEPUL primary key clustered (ID_DETAIL_PENGEPULAN)
);

/*==============================================================*/
/* Index: DETAIL_TRANSAKSI_PENGEPUL_PK                          */
/*==============================================================*/
create unique clustered index DETAIL_TRANSAKSI_PENGEPUL_PK on DETAIL_TRANSAKSI_PENGEPUL (
ID_DETAIL_PENGEPULAN ASC
);

/*==============================================================*/
/* Index: RELATIONSHIP_8_FK                                     */
/*==============================================================*/
create index RELATIONSHIP_8_FK on DETAIL_TRANSAKSI_PENGEPUL (
KAT_ID_KATEGORI_SAMPAH ASC
);

/*==============================================================*/
/* Table: KATEGORI_SAMPAH                                       */
/*==============================================================*/
create or replace table KATEGORI_SAMPAH 
(
   ID_KATEGORI_SAMPAH   char(5)                        not null,
   NAMA_SAMPAH          varchar(20)                    not null,
   HARGA_JUAL_PERKG     integer                        not null,
   HARGA_BELI_PERKG     integer                        not null,
   constraint PK_KATEGORI_SAMPAH primary key clustered (ID_KATEGORI_SAMPAH)
);

/*==============================================================*/
/* Index: JENIS_SAM_AH_PK                                       */
/*==============================================================*/
create unique clustered index JENIS_SAM_AH_PK on KATEGORI_SAMPAH (
ID_KATEGORI_SAMPAH ASC
);

/*==============================================================*/
/* Table: NASABAH                                               */
/*==============================================================*/
create or replace table NASABAH 
(
   ID_NASABAH           char(5)                        not null,
   NAMA_NASABAH         varchar(30)                    not null,
   ALAMAT_NASABAH       varchar(100)                   not null,
   constraint PK_NASABAH primary key clustered (ID_NASABAH)
);

/*==============================================================*/
/* Index: NASABAH_PK                                            */
/*==============================================================*/
create unique clustered index NASABAH_PK on NASABAH (
ID_NASABAH ASC
);

/*==============================================================*/
/* Table: PEGAWAI                                               */
/*==============================================================*/
create or replace table PEGAWAI 
(
   ID_PEGAWAI           char(5)                        not null,
   NAMA_PEGAWAI         varchar(30)                    not null,
   ALAMAT_PEGAWAI       varchar(100)                   not null,
   LEVEL_PEGAWAI        numeric                        not null,
   constraint PK_PEGAWAI primary key clustered (ID_PEGAWAI)
);

/*==============================================================*/
/* Index: PEGAWAI_PK                                            */
/*==============================================================*/
create unique clustered index PEGAWAI_PK on PEGAWAI (
ID_PEGAWAI ASC
);

/*==============================================================*/
/* Table: PENGEPUL                                              */
/*==============================================================*/
create or replace table PENGEPUL 
(
   ID_PENGEPUL          char(5)                        not null,
   NAMA_PENGEPUL        varchar(30)                    not null,
   ALAMAT_PENGEPUL      varchar(100)                   not null,
   constraint PK_PENGEPUL primary key clustered (ID_PENGEPUL)
);

/*==============================================================*/
/* Index: PENGEPUL_PK                                           */
/*==============================================================*/
create unique clustered index PENGEPUL_PK on PENGEPUL (
ID_PENGEPUL ASC
);

/*==============================================================*/
/* Table: TRANSAKSI_PEMBELIAN                                   */
/*==============================================================*/
create or replace table TRANSAKSI_PEMBELIAN 
(
   ID_TRANSAKSI_PEMBELIAN char(5)                        not null,
   ID_DETAIL_PEMBELIAN  char(5)                        null,
   ID_NASABAH           char(5)                        null,
   ID_PEGAWAI           char(5)                        null,
   TGL_TRANSAKSI_PEMBELIAN char(10)                       null,
   CASH_KELUAR          integer                        not null,
   constraint PK_TRANSAKSI_PEMBELIAN primary key clustered (ID_TRANSAKSI_PEMBELIAN)
);

/*==============================================================*/
/* Index: TRANSAKSI_PEMBELIAN_PK                                */
/*==============================================================*/
create unique clustered index TRANSAKSI_PEMBELIAN_PK on TRANSAKSI_PEMBELIAN (
ID_TRANSAKSI_PEMBELIAN ASC
);

/*==============================================================*/
/* Index: MELAKUKAN_1_FK                                        */
/*==============================================================*/
create index MELAKUKAN_1_FK on TRANSAKSI_PEMBELIAN (
ID_PEGAWAI ASC
);

/*==============================================================*/
/* Index: MEJUAL_FK                                             */
/*==============================================================*/
create index MEJUAL_FK on TRANSAKSI_PEMBELIAN (
ID_NASABAH ASC
);

/*==============================================================*/
/* Index: MENDETAILKAN_1_FK                                     */
/*==============================================================*/
create index MENDETAILKAN_1_FK on TRANSAKSI_PEMBELIAN (
ID_DETAIL_PEMBELIAN ASC
);

/*==============================================================*/
/* Table: TRANSAKSI_PENGEPULAN                                  */
/*==============================================================*/
create or replace table TRANSAKSI_PENGEPULAN 
(
   ID_TRANSAKSI_PENGEPULAN char(5)                        not null,
   ID_PEGAWAI           char(5)                        null,
   ID_PENGEPUL          char(5)                        null,
   ID_DETAIL_PENGEPULAN char(5)                        null,
   TGL_TRANSAKSI_PENGEPULAN timestamp                      not null,
   CASH_MASUK           integer                        not null,
   constraint PK_TRANSAKSI_PENGEPULAN primary key clustered (ID_TRANSAKSI_PENGEPULAN)
);

/*==============================================================*/
/* Index: TRANSAKSI_PENGEPULAN_PK                               */
/*==============================================================*/
create unique clustered index TRANSAKSI_PENGEPULAN_PK on TRANSAKSI_PENGEPULAN (
ID_TRANSAKSI_PENGEPULAN ASC
);

/*==============================================================*/
/* Index: MELAKUKAN_2_FK                                        */
/*==============================================================*/
create index MELAKUKAN_2_FK on TRANSAKSI_PENGEPULAN (
ID_PEGAWAI ASC
);

/*==============================================================*/
/* Index: MENGEPUL_FK                                           */
/*==============================================================*/
create index MENGEPUL_FK on TRANSAKSI_PENGEPULAN (
ID_PENGEPUL ASC
);

/*==============================================================*/
/* Index: MENDETAILKAN_2_FK                                     */
/*==============================================================*/
create index MENDETAILKAN_2_FK on TRANSAKSI_PENGEPULAN (
ID_DETAIL_PENGEPULAN ASC
);

alter table DETAIL_TRANSAKSI_PEMBELIAN
   add constraint FK_DETAIL_T_RELATIONS_KATEGORI foreign key (KAT_ID_KATEGORI_SAMPAH)
      references KATEGORI_SAMPAH (ID_KATEGORI_SAMPAH)
      on update restrict
      on delete restrict;

alter table DETAIL_TRANSAKSI_PENGEPUL
   add constraint FK_DETAIL_T_RELATIONS_KATEGORI foreign key (KAT_ID_KATEGORI_SAMPAH)
      references KATEGORI_SAMPAH (ID_KATEGORI_SAMPAH)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PEMBELIAN
   add constraint FK_TRANSAKS_MEJUAL_NASABAH foreign key (ID_NASABAH)
      references NASABAH (ID_NASABAH)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PEMBELIAN
   add constraint FK_TRANSAKS_MELAKUKAN_PEGAWAI foreign key (ID_PEGAWAI)
      references PEGAWAI (ID_PEGAWAI)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PEMBELIAN
   add constraint FK_TRANSAKS_MENDETAIL_DETAIL_T foreign key (ID_DETAIL_PEMBELIAN)
      references DETAIL_TRANSAKSI_PEMBELIAN (ID_DETAIL_PEMBELIAN)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PENGEPULAN
   add constraint FK_TRANSAKS_MELAKUKAN_PEGAWAI foreign key (ID_PEGAWAI)
      references PEGAWAI (ID_PEGAWAI)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PENGEPULAN
   add constraint FK_TRANSAKS_MENDETAIL_DETAIL_T foreign key (ID_DETAIL_PENGEPULAN)
      references DETAIL_TRANSAKSI_PENGEPUL (ID_DETAIL_PENGEPULAN)
      on update restrict
      on delete restrict;

alter table TRANSAKSI_PENGEPULAN
   add constraint FK_TRANSAKS_MENGEPUL_PENGEPUL foreign key (ID_PENGEPUL)
      references PENGEPUL (ID_PENGEPUL)
      on update restrict
      on delete restrict;

