begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: scsireg.h,v 4.300 91/06/09 06:38:12 root Rel41 $ SONY  *  *	@(#)scsireg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	scsireg.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCSIREG__
end_ifndef

begin_define
define|#
directive|define
name|__SCSIREG__
value|1
end_define

begin_comment
comment|/*  *	initiator status byte bit image  */
end_comment

begin_define
define|#
directive|define
name|INST_EP
value|0x80
end_define

begin_comment
comment|/* End of Process */
end_comment

begin_define
define|#
directive|define
name|INST_WR
value|0x40
end_define

begin_comment
comment|/* Waiting Reselection */
end_comment

begin_define
define|#
directive|define
name|INST_IP
value|0x20
end_define

begin_comment
comment|/* In Process */
end_comment

begin_define
define|#
directive|define
name|INST_WAIT
value|0x10
end_define

begin_comment
comment|/* Waiting Bus free */
end_comment

begin_define
define|#
directive|define
name|INST_LB
value|0x8
end_define

begin_comment
comment|/* Loss of BUSY */
end_comment

begin_define
define|#
directive|define
name|INST_TO
value|0x4
end_define

begin_comment
comment|/* Time Out */
end_comment

begin_define
define|#
directive|define
name|INST_PRE
value|0x2
end_define

begin_comment
comment|/* PaRameter Error */
end_comment

begin_define
define|#
directive|define
name|INST_HE
value|0x1
end_define

begin_comment
comment|/* Hard Error */
end_comment

begin_define
define|#
directive|define
name|INSTERMASK
value|0x7
end_define

begin_comment
comment|/*  *	target status byte bit image  */
end_comment

begin_define
define|#
directive|define
name|VENDOR
value|0x61
end_define

begin_define
define|#
directive|define
name|TGSTMASK
value|0x1e
end_define

begin_define
define|#
directive|define
name|TGST_RSVCFLCT
value|0x18
end_define

begin_define
define|#
directive|define
name|TGST_INTERMED
value|0x10
end_define

begin_define
define|#
directive|define
name|TGST_BUSY
value|0x8
end_define

begin_define
define|#
directive|define
name|TGST_CC
value|0x2
end_define

begin_define
define|#
directive|define
name|TGST_GOOD
value|0x0
end_define

begin_define
define|#
directive|define
name|TS_MAPPED_PIO
value|0x01
end_define

begin_comment
comment|/* program I/O with map */
end_comment

begin_define
define|#
directive|define
name|TS_CONTR_ON
value|0x02
end_define

begin_comment
comment|/* contiguous transfer on */
end_comment

begin_define
define|#
directive|define
name|TS_CONTR_OFF
value|0x04
end_define

begin_comment
comment|/* contiguous transfer off */
end_comment

begin_define
define|#
directive|define
name|TS_BYTE_DMA
value|0x08
end_define

begin_comment
comment|/* DMA transfer(byte access) */
end_comment

begin_define
define|#
directive|define
name|TS_LONG_DMA
value|0x10
end_define

begin_comment
comment|/* DMA transfer(long access) */
end_comment

begin_comment
comment|/*  *	message byte  */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENT
value|0x80
end_define

begin_define
define|#
directive|define
name|MSG_RESELEN
value|0x40
end_define

begin_define
define|#
directive|define
name|MSG_CCOMP
value|0
end_define

begin_define
define|#
directive|define
name|MSG_EXTND
value|1
end_define

begin_define
define|#
directive|define
name|MSG_SDP
value|2
end_define

begin_define
define|#
directive|define
name|MSG_RDP
value|3
end_define

begin_define
define|#
directive|define
name|MSG_DCNT
value|4
end_define

begin_define
define|#
directive|define
name|MSG_IDE
value|5
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|6
end_define

begin_define
define|#
directive|define
name|MSG_MREJ
value|7
end_define

begin_define
define|#
directive|define
name|MSG_NOP
value|8
end_define

begin_define
define|#
directive|define
name|MSG_PERROR
value|9
end_define

begin_comment
comment|/*  *	message identify byte bit image  */
end_comment

begin_define
define|#
directive|define
name|IDT_DISCON
value|0x40
end_define

begin_define
define|#
directive|define
name|IDT_DRMASK
value|0x7
end_define

begin_comment
comment|/*  *	scsi command opcodes  */
end_comment

begin_define
define|#
directive|define
name|SCOP_TST
value|0x00
end_define

begin_define
define|#
directive|define
name|SCOP_REZERO
value|0x01
end_define

begin_define
define|#
directive|define
name|SCOP_REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|SCOP_RSENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCOP_FMT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCOP_RBLIM
value|0x05
end_define

begin_define
define|#
directive|define
name|SCOP_SPARAM
value|0x06
end_define

begin_define
define|#
directive|define
name|SCOP_RASBLK
value|0x07
end_define

begin_define
define|#
directive|define
name|SCOP_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|SCOP_MOERASE
value|0x09
end_define

begin_define
define|#
directive|define
name|SCOP_WRITE
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCOP_SEEK
value|0x0b
end_define

begin_define
define|#
directive|define
name|SCOP_MERASE
value|0x0e
end_define

begin_define
define|#
directive|define
name|SCOP_WFMARK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCOP_SPACE
value|0x11
end_define

begin_define
define|#
directive|define
name|SCOP_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|SCOP_SVERIFY
value|0x13
end_define

begin_define
define|#
directive|define
name|SCOP_RBDATA
value|0x14
end_define

begin_define
define|#
directive|define
name|SCOP_MSELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|SCOP_ERASE
value|0x19
end_define

begin_define
define|#
directive|define
name|SCOP_MSENSE
value|0x1a
end_define

begin_define
define|#
directive|define
name|SCOP_STST
value|0x1b
end_define

begin_define
define|#
directive|define
name|SCOP_LOAD
value|0x1b
end_define

begin_define
define|#
directive|define
name|SCOP_RECDIAG
value|0x1c
end_define

begin_define
define|#
directive|define
name|SCOP_SNDDIAG
value|0x1d
end_define

begin_define
define|#
directive|define
name|SCOP_MEDRMV
value|0x1e
end_define

begin_define
define|#
directive|define
name|SCOP_RCAP
value|0x25
end_define

begin_define
define|#
directive|define
name|SCOP_EREAD
value|0x28
end_define

begin_define
define|#
directive|define
name|SCOP_EWRITE
value|0x2a
end_define

begin_define
define|#
directive|define
name|SCOP_BSSRCH
value|0x2c
end_define

begin_define
define|#
directive|define
name|SCOP_WSSRCH
value|0x2d
end_define

begin_define
define|#
directive|define
name|SCOP_WRTVRFY
value|0x2e
end_define

begin_define
define|#
directive|define
name|SCOP_VERIFY
value|0x2f
end_define

begin_define
define|#
directive|define
name|SCOP_RDL
value|0x37
end_define

begin_define
define|#
directive|define
name|SCOP_WBUF
value|0x3b
end_define

begin_define
define|#
directive|define
name|SCOP_RBUF
value|0x3c
end_define

begin_define
define|#
directive|define
name|SCOP_EJECT
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCOP_EESENSE
value|0xc1
end_define

begin_define
define|#
directive|define
name|SCOP_READTOC
value|0xc1
end_define

begin_define
define|#
directive|define
name|SCOP_READID
value|0xc2
end_define

begin_define
define|#
directive|define
name|SCOP_ADP
value|0xc2
end_define

begin_define
define|#
directive|define
name|SCOP_READQ
value|0xc2
end_define

begin_define
define|#
directive|define
name|SCOP_BLANKS
value|0xc3
end_define

begin_define
define|#
directive|define
name|SCOP_READHEAD
value|0xc3
end_define

begin_define
define|#
directive|define
name|SCOP_PBSTS
value|0xc4
end_define

begin_define
define|#
directive|define
name|SCOP_RCVDISK
value|0xc4
end_define

begin_define
define|#
directive|define
name|SCOP_PAUSE
value|0xc5
end_define

begin_define
define|#
directive|define
name|SCOP_PLAYTRACK
value|0xc6
end_define

begin_define
define|#
directive|define
name|SCOP_PLAYMSF
value|0xc7
end_define

begin_define
define|#
directive|define
name|SCOP_PLAYAUDIO
value|0xc8
end_define

begin_define
define|#
directive|define
name|SCOP_ERASED
value|0xe7
end_define

begin_define
define|#
directive|define
name|SCOP_RESET
value|0xff
end_define

begin_comment
comment|/*  *	other definition  */
end_comment

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_comment
comment|/*  *	scsi internal parameter block  */
end_comment

begin_struct
struct|struct
name|scsi
block|{
comment|/*00*/
name|u_char
name|sc_istatus
decl_stmt|;
comment|/*01*/
name|u_char
name|sc_tstatus
decl_stmt|;
comment|/*02*/
name|u_char
name|sc_identify
decl_stmt|;
comment|/*03*/
name|u_char
name|sc_message
decl_stmt|;
comment|/*04*/
name|u_int
name|sc_mpages
decl_stmt|;
comment|/*08*/
name|u_int
name|sc_bytesec
decl_stmt|;
comment|/*0c*/
name|u_char
modifier|*
name|sc_cpoint
decl_stmt|;
comment|/*10*/
name|u_int
name|sc_ctrnscnt
decl_stmt|;
comment|/*14*/
name|struct
name|sc_map
modifier|*
name|sc_map
decl_stmt|;
union|union
block|{
struct|struct
name|un_type0
block|{
comment|/*18*/
name|u_int
name|t0_opcode
range|:
literal|8
decl_stmt|;
comment|/*19*/
name|u_int
name|t0_lun
range|:
literal|3
decl_stmt|;
comment|/*19*/
name|u_int
name|t0_lad
range|:
literal|21
decl_stmt|;
comment|/*1c*/
name|u_char
name|t0_count
decl_stmt|;
comment|/*1d*/
name|u_char
name|t0_ctrl
decl_stmt|;
comment|/*1e*/
block|}
name|un_type0
struct|;
struct|struct
name|un_tuio
block|{
comment|/*18*/
name|u_char
name|tu_opcode
decl_stmt|;
comment|/*19*/
name|u_char
name|tu_lun
range|:
literal|3
decl_stmt|;
comment|/*19*/
name|u_char
name|tu_resved
range|:
literal|3
decl_stmt|;
comment|/*19*/
name|u_char
name|tu_code
range|:
literal|2
decl_stmt|;
comment|/*1a*/
name|u_char
name|tu_count1
decl_stmt|;
comment|/*1b*/
name|u_char
name|tu_count2
decl_stmt|;
comment|/*1c*/
name|u_char
name|tu_count3
decl_stmt|;
comment|/*1d*/
name|u_char
name|tu_ctrl
decl_stmt|;
comment|/*1e*/
block|}
name|un_tuio
struct|;
struct|struct
name|un_mtio
block|{
comment|/*18*/
name|u_char
name|mt_opcode
decl_stmt|;
comment|/*19*/
name|u_char
name|mt_lun
range|:
literal|3
decl_stmt|;
comment|/*19*/
name|u_char
name|mt_resvd
range|:
literal|2
decl_stmt|;
comment|/*19*/
name|u_char
name|mt_st
range|:
literal|1
decl_stmt|;
comment|/*19*/
name|u_char
name|mt_code
range|:
literal|2
decl_stmt|;
comment|/*1a*/
name|u_char
name|mt_len1
decl_stmt|;
comment|/*1b*/
name|u_char
name|mt_len2
decl_stmt|;
comment|/*1c*/
name|u_char
name|mt_len3
decl_stmt|;
comment|/*1d*/
name|u_char
name|mt_ctrl
decl_stmt|;
comment|/*1e*/
block|}
name|un_mtio
struct|;
struct|struct
name|un_type1
block|{
comment|/*18*/
name|u_char
name|t1_opcode
decl_stmt|;
comment|/*19*/
name|u_char
name|t1_lun
range|:
literal|3
decl_stmt|;
comment|/*19*/
name|u_char
name|t1_rsvd
range|:
literal|4
decl_stmt|;
comment|/*19*/
name|u_char
name|t1_relat
range|:
literal|1
decl_stmt|;
comment|/*1a*/
name|u_short
name|t1_ladhi
decl_stmt|;
comment|/*1c*/
name|u_short
name|t1_ladlo
decl_stmt|;
comment|/*1e*/
name|u_char
name|t1_p1
decl_stmt|;
comment|/*1f*/
name|u_char
name|t1_p2
decl_stmt|;
comment|/*20*/
name|u_char
name|t1_p3
decl_stmt|;
comment|/*21*/
name|u_char
name|t1_ctrl
decl_stmt|;
comment|/*22*/
block|}
name|un_type1
struct|;
comment|/*18*/
name|u_char
name|un_reserved
index|[
literal|12
index|]
decl_stmt|;
comment|/*24*/
block|}
name|sc_cdb
union|;
comment|/*24*/
name|u_char
name|sc_param
index|[
literal|20
index|]
decl_stmt|;
comment|/*38*/
name|int
name|sc_hbinfo
decl_stmt|;
comment|/* Copy of the hb_ctlr->hm_hbinfo */
comment|/*3c*/
name|u_int
name|sc_ctag
decl_stmt|;
comment|/*40*/
name|u_int
name|sc_coffset
decl_stmt|;
comment|/*44*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_opcode
value|sc_cdb.un_type0.t0_opcode
end_define

begin_define
define|#
directive|define
name|sc_lun
value|sc_cdb.un_type0.t0_lun
end_define

begin_define
define|#
directive|define
name|sc_lad
value|sc_cdb.un_type0.t0_lad
end_define

begin_define
define|#
directive|define
name|sc_count
value|sc_cdb.un_type0.t0_count
end_define

begin_define
define|#
directive|define
name|sc_nsect
value|sc_cdb.un_type0.t0_count
end_define

begin_define
define|#
directive|define
name|sc_switch
value|sc_cdb.un_type0.t0_count
end_define

begin_define
define|#
directive|define
name|sc_ctrl
value|sc_cdb.un_type0.t0_ctrl
end_define

begin_define
define|#
directive|define
name|sc_tucode
value|sc_cdb.un_tuio.tu_code
end_define

begin_define
define|#
directive|define
name|sc_tucount1
value|sc_cdb.un_tuio.tu_count1
end_define

begin_define
define|#
directive|define
name|sc_tucount2
value|sc_cdb.un_tuio.tu_count2
end_define

begin_define
define|#
directive|define
name|sc_tucount3
value|sc_cdb.un_tuio.tu_count3
end_define

begin_define
define|#
directive|define
name|sc_tunsect1
value|sc_cdb.un_tuio.tu_count1
end_define

begin_define
define|#
directive|define
name|sc_tunsect2
value|sc_cdb.un_tuio.tu_count2
end_define

begin_define
define|#
directive|define
name|sc_tunsect3
value|sc_cdb.un_tuio.tu_count3
end_define

begin_define
define|#
directive|define
name|sc_mtst
value|sc_cdb.un_mtio.mt_st
end_define

begin_define
define|#
directive|define
name|sc_mtcode
value|sc_cdb.un_mtio.mt_code
end_define

begin_define
define|#
directive|define
name|sc_mtlen1
value|sc_cdb.un_mtio.mt_len1
end_define

begin_define
define|#
directive|define
name|sc_mtlen2
value|sc_cdb.un_mtio.mt_len2
end_define

begin_define
define|#
directive|define
name|sc_mtlen3
value|sc_cdb.un_mtio.mt_len3
end_define

begin_define
define|#
directive|define
name|sc_mtcount1
value|sc_cdb.un_mtio.mt_len1
end_define

begin_define
define|#
directive|define
name|sc_mtcount2
value|sc_cdb.un_mtio.mt_len2
end_define

begin_define
define|#
directive|define
name|sc_mtcount3
value|sc_cdb.un_mtio.mt_len3
end_define

begin_define
define|#
directive|define
name|sc_mtnsect1
value|sc_cdb.un_mtio.mt_len1
end_define

begin_define
define|#
directive|define
name|sc_mtnsect2
value|sc_cdb.un_mtio.mt_len2
end_define

begin_define
define|#
directive|define
name|sc_mtnsect3
value|sc_cdb.un_mtio.mt_len3
end_define

begin_define
define|#
directive|define
name|sc_mtctrl
value|sc_cdb.un_mtio.mt_ctrl
end_define

begin_define
define|#
directive|define
name|sc_mtfxd
value|sc_mtcode
end_define

begin_define
define|#
directive|define
name|sc_mtimm
value|sc_mtcode
end_define

begin_define
define|#
directive|define
name|sc_mtlng
value|sc_mtcode
end_define

begin_define
define|#
directive|define
name|sc_ladhi
value|sc_cdb.un_type1.t1_ladhi
end_define

begin_define
define|#
directive|define
name|sc_ladlo
value|sc_cdb.un_type1.t1_ladlo
end_define

begin_define
define|#
directive|define
name|sc_pmi
value|sc_cdb.un_type1.t1_p3
end_define

begin_define
define|#
directive|define
name|scop_load
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|scop_stst(a,b,c,d,e)
end_define

begin_comment
comment|/*  *	tape unit space operation code definitions  */
end_comment

begin_define
define|#
directive|define
name|SCSC_DATA
value|0
end_define

begin_define
define|#
directive|define
name|SCSC_FM
value|1
end_define

begin_define
define|#
directive|define
name|SCSC_SQFM
value|2
end_define

begin_define
define|#
directive|define
name|SCSC_EOD
value|3
end_define

begin_comment
comment|/*  *	scsi map table format  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|news3400
end_ifdef

begin_define
define|#
directive|define
name|NSCMAP
value|120
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|news3800
end_ifdef

begin_define
define|#
directive|define
name|NSCMAP
value|129
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sc_map
block|{
comment|/*000*/
name|unsigned
name|mp_offset
decl_stmt|;
comment|/*004*/
name|unsigned
name|mp_pages
decl_stmt|;
comment|/*008*/
name|unsigned
name|mp_addr
index|[
name|NSCMAP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	scsi nonextended sense data  */
end_comment

begin_struct
struct|struct
name|sc_nextnd
block|{
comment|/*00*/
name|u_int
name|scn_advalid
range|:
literal|1
decl_stmt|;
comment|/*00*/
name|u_int
name|scn_ecode
range|:
literal|7
decl_stmt|;
comment|/*01*/
name|u_int
name|scn_resvd
range|:
literal|3
decl_stmt|;
comment|/*01*/
name|u_int
name|scn_secno
range|:
literal|21
decl_stmt|;
comment|/*04*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	scsi extended sense data  */
end_comment

begin_struct
struct|struct
name|sc_extnd
block|{
comment|/*00*/
name|u_char
name|sce_advalid
range|:
literal|1
decl_stmt|;
comment|/*00*/
name|u_char
name|sce_extend
range|:
literal|7
decl_stmt|;
comment|/*01*/
name|u_char
name|sce_segno
decl_stmt|;
comment|/*02*/
name|u_char
name|sce_fm
range|:
literal|1
decl_stmt|;
comment|/*02*/
name|u_char
name|sce_eom
range|:
literal|1
decl_stmt|;
comment|/*02*/
name|u_char
name|sce_ili
range|:
literal|1
decl_stmt|;
comment|/*02*/
name|u_char
name|sce_resvd
range|:
literal|1
decl_stmt|;
comment|/*02*/
name|u_char
name|sce_skey
range|:
literal|4
decl_stmt|;
comment|/*03*/
name|u_char
name|sce_infob1
decl_stmt|;
comment|/*04*/
name|u_char
name|sce_infob2
decl_stmt|;
comment|/*05*/
name|u_char
name|sce_infob3
decl_stmt|;
comment|/*06*/
name|u_char
name|sce_infob4
decl_stmt|;
comment|/*07*/
name|u_char
name|sce_addlen
decl_stmt|;
union|union
block|{
struct|struct
name|un_ehd
block|{
comment|/*08*/
name|u_short
name|ehd_resvd1
decl_stmt|;
comment|/*0a*/
name|u_short
name|ehd_resvd2
decl_stmt|;
comment|/*0c*/
name|u_char
name|ehd_ecode
decl_stmt|;
comment|/*0d*/
name|u_char
name|ehd_resvd3
decl_stmt|;
comment|/*0e*/
name|u_char
name|ehd_fru
decl_stmt|;
comment|/*0f*/
name|u_char
name|ehd_fpv
range|:
literal|1
decl_stmt|;
comment|/*0f*/
name|u_char
name|ehd_cd
range|:
literal|1
decl_stmt|;
comment|/*0f*/
name|u_char
name|ehd_resvd4
range|:
literal|2
decl_stmt|;
comment|/*0f*/
name|u_char
name|ehd_bpv
range|:
literal|1
decl_stmt|;
comment|/*0f*/
name|u_char
name|ehd_bitpnt
range|:
literal|3
decl_stmt|;
comment|/*10*/
name|u_short
name|ehd_fldpnt
decl_stmt|;
comment|/*12*/
block|}
name|un_ehd
struct|;
struct|struct
name|un_etu
block|{
comment|/*08*/
name|u_char
name|etu_ecode
decl_stmt|;
comment|/*09*/
name|u_char
name|etu_nerrhi
decl_stmt|;
comment|/*0a*/
name|u_char
name|etu_nerrlo
decl_stmt|;
comment|/*0b*/
block|}
name|un_etu
struct|;
struct|struct
name|un_emt
block|{
comment|/*08*/
name|u_short
name|emt_estat
decl_stmt|;
comment|/*0a*/
name|u_char
name|emt_resvd1
decl_stmt|;
comment|/*0b*/
name|u_char
name|emt_totlrtry
decl_stmt|;
comment|/*0c*/
name|u_short
name|emt_resvd2
decl_stmt|;
comment|/*0e*/
name|u_short
name|emt_resvd3
decl_stmt|;
comment|/*10*/
name|u_char
name|emt_resvd4
decl_stmt|;
comment|/*11*/
name|u_char
name|emt_ecode
decl_stmt|;
comment|/*12*/
block|}
name|un_emt
struct|;
struct|struct
name|un_ewo
block|{
comment|/*08*/
name|u_char
name|ewo_resvd1
decl_stmt|;
comment|/*09*/
name|u_char
name|ewo_resvd2
decl_stmt|;
comment|/*0a*/
name|u_char
name|ewo_resvd3
decl_stmt|;
comment|/*0b*/
name|u_char
name|ewo_sadvalid
range|:
literal|1
decl_stmt|;
comment|/*0b*/
name|u_char
name|ewo_secode
range|:
literal|7
decl_stmt|;
comment|/*0c*/
name|u_char
name|ewo_saddr1
decl_stmt|;
comment|/*0d*/
name|u_char
name|ewo_saddr2
decl_stmt|;
comment|/*0e*/
name|u_char
name|ewo_saddr3
decl_stmt|;
comment|/*0f*/
name|u_char
name|ewo_saddr4
decl_stmt|;
comment|/*10*/
name|u_char
name|ewo_resvd4
decl_stmt|;
comment|/*11*/
name|u_char
name|ewo_dadvalid
range|:
literal|1
decl_stmt|;
comment|/*11*/
name|u_char
name|ewo_decode
range|:
literal|7
decl_stmt|;
comment|/*12*/
name|u_char
name|ewo_daddr1
decl_stmt|;
comment|/*13*/
name|u_char
name|ewo_daddr2
decl_stmt|;
comment|/*14*/
name|u_char
name|ewo_daddr3
decl_stmt|;
comment|/*15*/
name|u_char
name|ewo_daddr4
decl_stmt|;
comment|/*16*/
block|}
name|un_ewo
struct|;
struct|struct
name|un_eod
block|{
comment|/*08*/
name|u_char
name|eod_resvd1
decl_stmt|;
comment|/*09*/
name|u_char
name|eod_resvd2
decl_stmt|;
comment|/*0a*/
name|u_char
name|eod_resvd3
decl_stmt|;
comment|/*0b*/
name|u_char
name|eod_resvd4
decl_stmt|;
comment|/*0c*/
name|u_char
name|eod_ecode
decl_stmt|;
comment|/*0d*/
name|u_char
name|eod_resvd5
decl_stmt|;
comment|/*0e*/
name|u_char
name|eod_resvd6
decl_stmt|;
comment|/*0f*/
name|u_char
name|eod_resvd7
decl_stmt|;
comment|/*10*/
name|u_char
name|eod_resvd8
decl_stmt|;
comment|/*11*/
name|u_char
name|eod_resvd9
decl_stmt|;
comment|/*12*/
block|}
name|un_eod
struct|;
comment|/*08*/
name|u_char
name|un_data
index|[
literal|24
index|]
decl_stmt|;
comment|/*20*/
block|}
name|sce_add
union|;
comment|/*20*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sce_hdecode
value|sce_add.un_ehd.ehd_ecode
end_define

begin_define
define|#
directive|define
name|sce_tuecode
value|sce_add.un_etu.etu_ecode
end_define

begin_define
define|#
directive|define
name|sce_tunerrhi
value|sce_add.un_etu.etu_nerrhi
end_define

begin_define
define|#
directive|define
name|sce_tunerrlo
value|sce_add.un_etu.etu_nerrlo
end_define

begin_define
define|#
directive|define
name|sce_mtestat
value|sce_add.un_emt.emt_estat
end_define

begin_define
define|#
directive|define
name|sce_mtecode
value|sce_add.un_emt.emt_ecode
end_define

begin_define
define|#
directive|define
name|sce_odecode
value|sce_add.un_eod.eod_ecode
end_define

begin_define
define|#
directive|define
name|sce_ascq
value|sce_add.un_ehd.ehd_resvd3
end_define

begin_define
define|#
directive|define
name|sce_sksv
value|sce_add.un_ehd.ehd_fpv
end_define

begin_define
define|#
directive|define
name|sce_actretry
value|sce_add.un_ehd.ehd_fldpnt
end_define

begin_comment
comment|/*  *	scsi inquiry response data  */
end_comment

begin_struct
struct|struct
name|sc_inq
block|{
comment|/*00*/
name|u_char
name|sci_devtype
decl_stmt|;
comment|/*01*/
name|u_char
name|sci_qual
decl_stmt|;
comment|/*02*/
name|u_char
name|sci_version
decl_stmt|;
comment|/*03*/
name|u_char
name|sci_resvd1
decl_stmt|;
comment|/*04*/
name|u_char
name|sci_ninfo
decl_stmt|;
comment|/*05*/
name|u_char
name|sci_drinfo
decl_stmt|;
comment|/*06*/
name|u_char
name|sci_firmrev
decl_stmt|;
comment|/*07*/
name|u_char
name|sci_ready
decl_stmt|;
comment|/*08*/
name|u_char
name|sci_vendid
index|[
literal|8
index|]
decl_stmt|;
comment|/*10*/
name|u_char
name|sci_prodid
index|[
literal|16
index|]
decl_stmt|;
comment|/*20*/
name|u_char
name|sci_revision
index|[
literal|4
index|]
decl_stmt|;
comment|/*24*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	scsi read capacity data  */
end_comment

begin_struct
struct|struct
name|sc_rcap
block|{
comment|/*00*/
name|u_int
name|scr_nblock
decl_stmt|;
comment|/*04*/
name|u_int
name|scr_blocklen
decl_stmt|;
comment|/*08*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	scsi mode sense/select data  */
end_comment

begin_struct
struct|struct
name|sc_mdata
block|{
comment|/*00*/
name|u_char
name|scm_len
decl_stmt|;
comment|/*01*/
name|u_char
name|scm_type
decl_stmt|;
comment|/*02*/
name|u_char
name|scm_flags1
decl_stmt|;
comment|/*03*/
name|u_char
name|scm_dlen
decl_stmt|;
comment|/*04*/
name|u_int
name|scm_dens
range|:
literal|8
decl_stmt|;
comment|/*05*/
name|u_int
name|scm_nblock
range|:
literal|24
decl_stmt|;
comment|/*08*/
name|u_int
name|scm_resvd1
range|:
literal|8
decl_stmt|;
comment|/*09*/
name|u_int
name|scm_bsize
range|:
literal|24
decl_stmt|;
comment|/*0c*/
name|u_char
name|scm_flags2
decl_stmt|;
comment|/*0d*/
name|u_char
name|scm_resvd2
decl_stmt|;
comment|/*0e*/
name|u_char
name|scm_resvd3
decl_stmt|;
comment|/*0f*/
name|u_char
name|scm_maxrtry
decl_stmt|;
comment|/*10*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|scm_tdens
value|scm_flags2
end_define

begin_comment
comment|/*  *	bits of scm_flags1  */
end_comment

begin_define
define|#
directive|define
name|SCM1_WRP
value|0x80
end_define

begin_define
define|#
directive|define
name|SCM1_BUFM
value|0x10
end_define

begin_define
define|#
directive|define
name|SCM1_SPD90
value|0x02
end_define

begin_comment
comment|/*  *	scm_type  */
end_comment

begin_define
define|#
directive|define
name|SCMT_DEFAULT
value|0x0
end_define

begin_define
define|#
directive|define
name|SCMT_150_600
value|0x80
end_define

begin_define
define|#
directive|define
name|SCMT_300_450
value|0x81
end_define

begin_comment
comment|/*  *	scm_dens  */
end_comment

begin_define
define|#
directive|define
name|SCMD_QIC_24_9
value|0x0
end_define

begin_comment
comment|/* This may be 0x5 */
end_comment

begin_define
define|#
directive|define
name|SCMD_QIC_11_4
value|0x4
end_define

begin_define
define|#
directive|define
name|SCMD_QIC_11_9
value|0x84
end_define

begin_define
define|#
directive|define
name|SCMD_QIC_120_15
value|0xf
end_define

begin_define
define|#
directive|define
name|SCMD_QIC_150_18
value|0x10
end_define

begin_define
define|#
directive|define
name|SCMD_DEFAULT
value|0x00
end_define

begin_define
define|#
directive|define
name|SCMD_800_BPI
value|0x01
end_define

begin_define
define|#
directive|define
name|SCMD_1600_BPI
value|0x02
end_define

begin_define
define|#
directive|define
name|SCMD_6250_BPI
value|0x03
end_define

begin_define
define|#
directive|define
name|SCMD_3200_BPI
value|0x06
end_define

begin_define
define|#
directive|define
name|SCMD_NEWTAPE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCMD_NOTAPE
value|0xff
end_define

begin_comment
comment|/*  *	bits of scm_flags2  */
end_comment

begin_define
define|#
directive|define
name|SCM2_DEA
value|0x04
end_define

begin_define
define|#
directive|define
name|SCM2_AUI
value|0x02
end_define

begin_define
define|#
directive|define
name|SCM2_SEC
value|0x01
end_define

begin_comment
comment|/*  *	scsi reassign block perameter list  */
end_comment

begin_struct
struct|struct
name|sc_rab
block|{
comment|/*00*/
name|u_short
name|sca_resved
decl_stmt|;
comment|/*02*/
name|u_short
name|sca_dllen
decl_stmt|;
comment|/*04*/
name|u_int
name|sca_dlad
index|[
literal|4
index|]
decl_stmt|;
comment|/*14*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_DOUBLE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|ipc_phys
parameter_list|(
name|x
parameter_list|)
value|(caddr_t)K0_TT0(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ipc_phys
parameter_list|(
name|x
parameter_list|)
value|(caddr_t)((int)(x)& ~0x80000000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|news3800
end_ifdef

begin_define
define|#
directive|define
name|splsc
value|spl4
end_define

begin_define
define|#
directive|define
name|splscon
value|spl3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_DOUBLE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_define
define|#
directive|define
name|ipc_phys
parameter_list|(
name|x
parameter_list|)
value|(caddr_t)(x)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|news3400
end_ifdef

begin_define
define|#
directive|define
name|splsc
value|spl3
end_define

begin_define
define|#
directive|define
name|splscon
value|spl2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|splsc
value|spl4
end_define

begin_define
define|#
directive|define
name|splscon
value|spl3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_define
define|#
directive|define
name|SCSI_INTEN
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_INTDIS
value|0
end_define

begin_struct
struct|struct
name|scintsw
block|{
comment|/*00*/
name|int
function_decl|(
modifier|*
name|sci_inthandler
function_decl|)
parameter_list|()
function_decl|;
comment|/* pointer to interrupt handler */
comment|/*04*/
name|int
name|sci_ctlr
decl_stmt|;
comment|/* controller number */
comment|/*08*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sc_data
block|{
comment|/*00*/
name|caddr_t
name|scd_scaddr
decl_stmt|;
comment|/* pointer to struct scsi */
comment|/*04*/
name|caddr_t
name|scd_vaddr
decl_stmt|;
comment|/* pointer to buffer address */
comment|/*08*/
name|int
name|scd_count
decl_stmt|;
comment|/* buffer size */
comment|/*0c*/
name|int
name|scd_rw
decl_stmt|;
comment|/* R/W flag see buf.h */
comment|/*10*/
name|struct
name|proc
modifier|*
name|scd_procp
decl_stmt|;
comment|/* user prrocess */
comment|/*14*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__SCSIREG__ */
end_comment

end_unit

