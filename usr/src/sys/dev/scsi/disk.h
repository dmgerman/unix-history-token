begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)disk.h	5.4 (Berkeley) %G%  *  * from: $Header: disk.h,v 1.4 93/04/30 00:04:10 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI definitions for Direct Access Devices (disks).  * This includes WORMs and CD-ROMs (although a few commands, such as  * format or write, are nonsensical on some).  *  * Commands defined in common headers (scsi.h or disktape.h) appear here  * as comments.  */
end_comment

begin_comment
comment|/* group 0 */
end_comment

begin_comment
comment|/*	CMD_TEST_UNIT_READY	0x00	   test unit ready */
end_comment

begin_define
define|#
directive|define
name|CMD_REZERO
value|0x01
end_define

begin_comment
comment|/* rezero unit */
end_comment

begin_comment
comment|/*	CMD_REQUEST_SENSE	0x03	   request sense */
end_comment

begin_define
define|#
directive|define
name|CMD_FORMAT_UNIT
value|0x04
end_define

begin_comment
comment|/* format unit (disk) */
end_comment

begin_define
define|#
directive|define
name|CMD_REASSIGN_BLOCKS
value|0x07
end_define

begin_comment
comment|/* reassign blocks (disk, WORM) */
end_comment

begin_define
define|#
directive|define
name|CMD_READ6
value|0x08
end_define

begin_comment
comment|/* read (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE6
value|0x0a
end_define

begin_comment
comment|/* write (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_SEEK6
value|0x0b
end_define

begin_comment
comment|/* seek (6 byte cdb) */
end_comment

begin_comment
comment|/*	CMD_INQUIRY		0x12	   inquiry */
end_comment

begin_comment
comment|/*	CMD_MODE_SELECT		0x15	   mode select */
end_comment

begin_define
define|#
directive|define
name|CMD_RESERVE
value|0x16
end_define

begin_comment
comment|/* reserve */
end_comment

begin_define
define|#
directive|define
name|CMD_RELEASE
value|0x17
end_define

begin_comment
comment|/* release */
end_comment

begin_comment
comment|/*	CMD_COPY		0x18	   copy */
end_comment

begin_comment
comment|/*	CMD_MODE_SENSE		0x1a	   mode sense */
end_comment

begin_define
define|#
directive|define
name|CMD_SSU
value|0x1b
end_define

begin_comment
comment|/* start/stop unit */
end_comment

begin_comment
comment|/*	CMD_RECEIVE_DIAG	0x1c	   receive diagnostic results */
end_comment

begin_comment
comment|/*	CMD_SEND_DIAG		0x1d	   send diagnostic */
end_comment

begin_define
define|#
directive|define
name|CMD_PAMR
value|0x1e
end_define

begin_comment
comment|/* prevent/allow medium removal */
end_comment

begin_comment
comment|/* group 1 */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_CAPACITY
value|0x25
end_define

begin_comment
comment|/* read capacity */
end_comment

begin_define
define|#
directive|define
name|CMD_READ10
value|0x28
end_define

begin_comment
comment|/* read (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE10
value|0x2a
end_define

begin_comment
comment|/* write (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_SEEK10
value|0x2b
end_define

begin_comment
comment|/* write (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_WRITE_VERIFY
value|0x2e
end_define

begin_comment
comment|/* write and verify */
end_comment

begin_define
define|#
directive|define
name|CMD_VERIFY
value|0x2f
end_define

begin_comment
comment|/* verify */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_H
value|0x30
end_define

begin_comment
comment|/* search data high */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_E
value|0x31
end_define

begin_comment
comment|/* search data equal */
end_comment

begin_define
define|#
directive|define
name|CMD_SEARCH_L
value|0x32
end_define

begin_comment
comment|/* search data low */
end_comment

begin_define
define|#
directive|define
name|CMD_SET_LIMITS
value|0x33
end_define

begin_comment
comment|/* set limits */
end_comment

begin_comment
comment|/*	CMD_COMPARE		0x39	   compare */
end_comment

begin_define
define|#
directive|define
name|CMD_COPY_VERIFY
value|0x3a
end_define

begin_comment
comment|/* copy and verify */
end_comment

begin_comment
comment|/* this one is in van's but not in my 17B documents */
end_comment

begin_define
define|#
directive|define
name|CMD_READ_DEFECT_DATA
value|0x37
end_define

begin_comment
comment|/* read defect data */
end_comment

begin_comment
comment|/* ??? */
end_comment

begin_comment
comment|/*  * Structure of a FORMAT UNIT command (i.e., the cdb):  *	byte 0: opcode<8>  *	byte 1: lun<3> format_data<1> complete_list<1> defect_list_format<3>  *	byte 2: vendor unique  *	byte 3: interleave (MSB)  *	byte 4: interleave (LSB)  *	byte 5: control  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_fu
block|{
name|u_char
name|cdb_cmd
decl_stmt|;
comment|/* SCSI_CMD_FU */
name|u_char
name|cdb_lun_etc
decl_stmt|;
comment|/* lun+FD+CL+DLF */
name|u_char
name|cdb_vu
decl_stmt|;
comment|/* vendor unique */
name|u_char
name|cdb_ilvh
decl_stmt|;
comment|/* interleave (MSB) */
name|u_char
name|cdb_ilvl
decl_stmt|;
comment|/* interleave (LSB) */
name|u_char
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/*  * If format data are supplied, they give either additional (cl=0) or  * new (cl=1) defect list in one of the following formats.  * Formats 1, 2, and 3 are the same as 0; formats 6 and 7 are  * vendor unique and reserved, respectively.  (The `backwards'  * in `backwards compatible'...)  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_BLOCK
value|0
end_define

begin_comment
comment|/* dlf = blocks */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_BFI
value|4
end_define

begin_comment
comment|/* dlf = bytes from index */
end_comment

begin_define
define|#
directive|define
name|SCSI_DLF_PS
value|5
end_define

begin_comment
comment|/* dlf = physical sectors */
end_comment

begin_comment
comment|/*  * Defect list header, block format (`defect block address').  *  * N.B.: this structure is also used for the Reassign Blocks command;  * there the `defect block address' becomes a `defect logical block address'.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_dba
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_dba_desc
block|{
name|u_char
name|dbah
decl_stmt|,
comment|/* defect block address (MSB) */
name|dbahm
decl_stmt|,
comment|/* defect block address */
name|dbalm
decl_stmt|,
comment|/* defect block address */
name|dbal
decl_stmt|;
comment|/* defect block address (LSB) */
block|}
name|dlf_dba
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defect list header, Bytes From Index format.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_bfi
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_bfi_desc
block|{
name|u_char
name|cylh
decl_stmt|,
comment|/* cylinder number of defect (MSB) */
name|cylm
decl_stmt|,
comment|/* cylinder number of defect */
name|cyll
decl_stmt|,
comment|/* cylinder number of defect (LSB) */
name|head
decl_stmt|,
comment|/* head number of defect */
name|bfih
decl_stmt|,
comment|/* defect bytes from index (MSB) */
name|bfihm
decl_stmt|,
comment|/* defect bytes from index */
name|bfilm
decl_stmt|,
comment|/* defect bytes from index */
name|bfil
decl_stmt|;
comment|/* defect bytes from index (LSB) */
block|}
name|dlf_bfi
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Defect list header, Physical Sector format.  */
end_comment

begin_struct
struct|struct
name|scsi_dlf_ps
block|{
name|u_short
name|dlf_xxx
decl_stmt|;
comment|/* reserved */
name|u_char
name|dlf_lenh
decl_stmt|,
comment|/* defect list length (MSB) */
name|dlf_lenl
decl_stmt|;
comment|/* defect list length (LSB) */
struct|struct
name|scsi_dlf_ps_desc
block|{
name|u_char
name|cylh
decl_stmt|,
comment|/* cylinder number of defect (MSB) */
name|cylm
decl_stmt|,
comment|/* cylinder number of defect */
name|cyll
decl_stmt|,
comment|/* cylinder number of defect (LSB) */
name|head
decl_stmt|,
comment|/* head number of defect */
name|dsnh
decl_stmt|,
comment|/* defect sector number (MSB) */
name|dsnhm
decl_stmt|,
comment|/* defect sector number */
name|dsnlm
decl_stmt|,
comment|/* defect sector number */
name|dsnl
decl_stmt|;
comment|/* defect sector number (LSB) */
block|}
name|dlf_ps
index|[
literal|1
index|]
struct|;
comment|/* actually longer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * For MODE SENSE and MODE SELECT: Mode page codes for disks.  */
end_comment

begin_comment
comment|/*				0x00	   vendor specific */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_RWERRREC
value|0x01
end_define

begin_comment
comment|/* r/w error recovery parameters */
end_comment

begin_comment
comment|/*	SCSI_MS_PC_DR		0x02	   disconnect/reconnect control */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_FMT
value|0x03
end_define

begin_comment
comment|/* format parameters */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_RDGEOM
value|0x04
end_define

begin_comment
comment|/* Rigid Disk geometry */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_FD
value|0x05
end_define

begin_comment
comment|/* flexible disk page */
end_comment

begin_comment
comment|/*				0x06	   reserved */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_VERRREC
value|0x07
end_define

begin_comment
comment|/* verify error recovery page */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_CACHE
value|0x08
end_define

begin_comment
comment|/* cache page */
end_comment

begin_comment
comment|/*	SCSI_MS_PC_PDEV		0x09	   peripheral device page */
end_comment

begin_comment
comment|/*	SCSI_MS_PC_CTLMODE	0x0a	   control mode page */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_MTSUPP
value|0x0b
end_define

begin_comment
comment|/* medium types supported */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_NOTCH
value|0x0c
end_define

begin_comment
comment|/* notch page */
end_comment

begin_comment
comment|/*				0x0d..0x1f reserved */
end_comment

begin_comment
comment|/*				0x20..0x3e vendor specific */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_CDCCACHECTL
value|0x38
end_define

begin_comment
comment|/* CDC (Wren) cache control page */
end_comment

begin_comment
comment|/*  * Structure of a Read/Write Error Recovery mode page.  * N.B.: CDC Wren V, at least, does not include write retry& time limit.  */
end_comment

begin_struct
struct|struct
name|scsi_page_rwerrrec
block|{
name|u_char
name|rw_flags
decl_stmt|,
comment|/* flags, see below */
name|rw_read_retry
decl_stmt|,
comment|/* read retry count */
name|rw_corr_span
decl_stmt|,
comment|/* correction span */
name|rw_hd_off
decl_stmt|,
comment|/* head offset count */
name|rw_ds_off
decl_stmt|,
comment|/* data strobe offset count */
name|rw_xxx0
decl_stmt|,
comment|/* reserved */
name|rw_write_retry
decl_stmt|,
comment|/* write retry count */
name|rw_xxx1
decl_stmt|,
comment|/* reserved */
name|rw_rtlh
decl_stmt|,
comment|/* recovery time limit (MSB) */
name|rw_rtll
decl_stmt|;
comment|/* recovery time limit (LSB) */
block|}
struct|;
end_struct

begin_comment
comment|/* rw_flags */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_AWRE
value|0x80
end_define

begin_comment
comment|/* reallocate defective blocks on write */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_ARRE
value|0x40
end_define

begin_comment
comment|/* reallocate defective blocks on read */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_TB
value|0x20
end_define

begin_comment
comment|/* transfer unrecoverable block */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_RC
value|0x10
end_define

begin_comment
comment|/* recovery may not cause delay: may lie */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_EER
value|0x08
end_define

begin_comment
comment|/* use most expedient recovery, not best */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_PER
value|0x04
end_define

begin_comment
comment|/* report recovered errors */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_DTE
value|0x02
end_define

begin_comment
comment|/* stop after recovered error */
end_comment

begin_define
define|#
directive|define
name|SCSI_RWE_DCR
value|0x01
end_define

begin_comment
comment|/* use ECC for detection only */
end_comment

begin_comment
comment|/*  * Structure of a Format Device mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_fmt
block|{
name|u_char
name|fmt_tpzh
decl_stmt|,
comment|/* tracks per zone (MSB) */
name|fmt_tpzl
decl_stmt|,
comment|/* tracks per zone (LSB) */
name|fmt_aspzh
decl_stmt|,
comment|/* alternate sectors per zone (MSB) */
name|fmt_aspzl
decl_stmt|,
comment|/* alternate sectors per zone (LSB) */
name|fmt_atpzh
decl_stmt|,
comment|/* alternate tracks per zone (MSB) */
name|fmt_atpzl
decl_stmt|,
comment|/* alternate tracks per zone (LSB) */
name|fmt_atpvh
decl_stmt|,
comment|/* alternate tracks per volume (MSB) */
name|fmt_atpvl
decl_stmt|,
comment|/* alternate tracks per volume (LSB) */
name|fmt_spth
decl_stmt|,
comment|/* sectors per track (MSB) */
name|fmt_sptl
decl_stmt|,
comment|/* sectors per track (LSB) */
name|fmt_dbppsh
decl_stmt|,
comment|/* data bytes per physical sector (MSB) */
name|fmt_dbppsl
decl_stmt|,
comment|/* data bytes per physical sector (LSB) */
name|fmt_ilh
decl_stmt|,
comment|/* interleave (MSB) */
name|fmt_ill
decl_stmt|,
comment|/* interleave (LSB) */
name|fmt_tsfh
decl_stmt|,
comment|/* track skew factor (MSB) */
name|fmt_tsfl
decl_stmt|,
comment|/* track skew factor (LSB) */
name|fmt_csfh
decl_stmt|,
comment|/* cylinder skew factor (MSB) */
name|fmt_csfl
decl_stmt|,
comment|/* cylinder skew factor (LSB) */
name|fmt_flags
decl_stmt|,
comment|/* flags, see below */
name|fmt_xxx
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_comment
comment|/* fmt_flags. Note, HSEC|SSEC meaning varies all over the map! */
end_comment

begin_define
define|#
directive|define
name|SCSI_FMT_HSEC
value|0x80
end_define

begin_comment
comment|/* hard sector */
end_comment

begin_define
define|#
directive|define
name|SCSI_FMT_SSEC
value|0x40
end_define

begin_comment
comment|/* soft sector */
end_comment

begin_define
define|#
directive|define
name|SCSI_FMT_RMB
value|0x20
end_define

begin_comment
comment|/* removable media */
end_comment

begin_define
define|#
directive|define
name|SCSI_FMT_SURF
value|0x10
end_define

begin_comment
comment|/* format by surface (vs. by cylinder) */
end_comment

begin_comment
comment|/*			0x0f	   reserved */
end_comment

begin_comment
comment|/*  * Structure of a Rigid Disk Geometry mode page.  * N.B.: CDC Wren V, at least, does not include rpm.  */
end_comment

begin_struct
struct|struct
name|scsi_page_rdgeom
block|{
name|u_char
name|rd_ncylh
decl_stmt|,
comment|/* number of cylinders (MSB) */
name|rd_ncylm
decl_stmt|,
comment|/* number of cylinders */
name|rd_ncyll
decl_stmt|,
comment|/* number of cylinders (LSB) */
name|rd_nheads
decl_stmt|,
comment|/* number of heads */
name|rd_wpcylh
decl_stmt|,
comment|/* start cyl for write precomp. (MSB) */
name|rd_wpcylm
decl_stmt|,
comment|/* start cyl for write precomp. */
name|rd_wpcyll
decl_stmt|,
comment|/* start cyl for write precomp. (LSB) */
name|rd_rwcylh
decl_stmt|,
comment|/* start cyl for reduced write current (MSB) */
name|rd_rwcylm
decl_stmt|,
comment|/* start cyl for reduced write current */
name|rd_rwcyll
decl_stmt|,
comment|/* start cyl for reduced write current (LSB) */
name|rd_steph
decl_stmt|,
comment|/* drive step rate (.1 us units) (MSB) */
name|rd_stepl
decl_stmt|,
comment|/* drive step rate (LSB) */
name|rd_lcylh
decl_stmt|,
comment|/* landing zone cylinder (MSB) */
name|rd_lcylm
decl_stmt|,
comment|/* landing zone cylinder */
name|rd_lcyll
decl_stmt|,
comment|/* landing zone cylinder (LSB) */
name|rd_rpl
decl_stmt|,
comment|/* spindle synch control, see below */
name|rd_roff
decl_stmt|,
comment|/* rotational offset (for rpl) */
name|rd_xxx1
decl_stmt|,
comment|/* reserved */
name|rd_rpmh
decl_stmt|,
comment|/* medium rotation rate (rpm) (MSB) */
name|rd_rpml
decl_stmt|,
comment|/* medium rotation rate (rpm) (LSB) */
name|rd_xxx2
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_comment
comment|/* values for rd_rpl. */
end_comment

begin_define
define|#
directive|define
name|SCSI_RD_RPL_MASK
value|0x03
end_define

begin_comment
comment|/* mask for RPL field */
end_comment

begin_define
define|#
directive|define
name|SCSI_RD_RPL_NONE
value|0x00
end_define

begin_comment
comment|/* sync disabled or not supported */
end_comment

begin_define
define|#
directive|define
name|SCSI_RD_RPL_SLAVE
value|0x01
end_define

begin_comment
comment|/* disk is a Slave */
end_comment

begin_define
define|#
directive|define
name|SCSI_RD_RPL_MASTER
value|0x02
end_define

begin_comment
comment|/* disk is a Master */
end_comment

begin_define
define|#
directive|define
name|SCSI_RD_RPL_MCONTROL
value|0x03
end_define

begin_comment
comment|/* disk is a Master Control */
end_comment

begin_comment
comment|/*  * Structure of a Verify Error Recovery mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_verrrec
block|{
name|u_char
name|v_flags
decl_stmt|,
comment|/* flags, see below */
name|v_verify_retry
decl_stmt|,
comment|/* verify retry count */
name|v_corr_span
decl_stmt|,
comment|/* verify correction span */
name|v_xxx
index|[
literal|5
index|]
decl_stmt|,
comment|/* reserved */
name|v_rtlh
decl_stmt|,
comment|/* verify recovery time limit (MSB) */
name|v_rtll
decl_stmt|;
comment|/* verify recovery time limit (LSB) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_V_EER
value|0x08
end_define

begin_comment
comment|/* use most expedient recovery, not best */
end_comment

begin_define
define|#
directive|define
name|SCSI_V_PER
value|0x04
end_define

begin_comment
comment|/* report recovered errors */
end_comment

begin_define
define|#
directive|define
name|SCSI_V_DTE
value|0x02
end_define

begin_comment
comment|/* stop after recovered error */
end_comment

begin_define
define|#
directive|define
name|SCSI_V_DCR
value|0x01
end_define

begin_comment
comment|/* use ECC for detection only */
end_comment

begin_comment
comment|/*  * Structure of a Caching mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_cache
block|{
name|u_char
name|cache_flags
decl_stmt|,
comment|/* flags, see below */
name|cache_reten
decl_stmt|,
comment|/* cache retention priorities (rd + wr) */
name|cache_dptlh
decl_stmt|,
comment|/* disable prefetch transfer length (MSB) */
name|cache_dptll
decl_stmt|,
comment|/* disable prefetch transfer length (LSB) */
name|cache_minpfh
decl_stmt|,
comment|/* minimum prefetch (MSB) */
name|cache_minpfl
decl_stmt|,
comment|/* minimum prefetch (LSB) */
name|cache_maxpfh
decl_stmt|,
comment|/* maximum prefetch (MSB) */
name|cache_maxpfl
decl_stmt|,
comment|/* maximum prefetch (LSB) */
name|cache_mpch
decl_stmt|,
comment|/* maximum prefetch ceiling (MSB) */
name|cache_mpcl
decl_stmt|;
comment|/* maximum prefetch ceiling (LSB) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_CACHE_WCE
value|0x04
end_define

begin_comment
comment|/* write cache enable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CACHE_MF
value|0x02
end_define

begin_comment
comment|/* if set, prefetch depends on xfer length */
end_comment

begin_define
define|#
directive|define
name|SCSI_CACHE_RCD
value|0x01
end_define

begin_comment
comment|/* read cache disable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CACHE_RDPOLICY
parameter_list|(
name|x
parameter_list|)
value|((x)>> 4)
end_define

begin_define
define|#
directive|define
name|SCSI_CACHE_WRPOLICY
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_define
define|#
directive|define
name|SCSI_CACHE_DEFAULT
value|0
end_define

begin_comment
comment|/* use target default */
end_comment

begin_define
define|#
directive|define
name|SCSI_CACHE_KEEPPF
value|1
end_define

begin_comment
comment|/* keep prefetch data over cmd data */
end_comment

begin_define
define|#
directive|define
name|SCSI_CACHE_KEEPCMD
value|15
end_define

begin_comment
comment|/* keep cmd data over prefetch data */
end_comment

begin_comment
comment|/*  * Structure of a Control Mode mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_ctlmode
block|{
name|u_char
name|cm_rlec
decl_stmt|,
comment|/* report log-activity exception condition */
name|cm_qctl
decl_stmt|,
comment|/* queue control (below) */
name|cm_ecaaen
decl_stmt|,
comment|/* ECA and AEN flags (below) */
name|cm_xxx
decl_stmt|,
comment|/* reserved */
name|cm_aenholdh
decl_stmt|,
comment|/* AEN holdoff period (ms) (MSB) */
name|cm_aenholdl
decl_stmt|;
comment|/* AEN holdoff period (ms) (LSB) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_CM_RLEC
value|0x01
end_define

begin_comment
comment|/* RLEC flag occupies only low bit */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_QMOD
parameter_list|(
name|x
parameter_list|)
value|((x)>> 4)
end_define

begin_comment
comment|/* queue algorithm modifier */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_QERR
value|0x02
end_define

begin_comment
comment|/* abort cmd queue after error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_DQUE
value|0x01
end_define

begin_comment
comment|/* disable tagged queueing */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_ECA
value|0x80
end_define

begin_comment
comment|/* enable Extended Contingent Alliance */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_RAENP
value|0x04
end_define

begin_comment
comment|/* target may do Async Err Notif after init */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_UAAENP
value|0x02
end_define

begin_comment
comment|/* target may do AEN for Unit Attention */
end_comment

begin_define
define|#
directive|define
name|SCSI_CM_EAENP
value|0x01
end_define

begin_comment
comment|/* target may do AEN for deferred errors */
end_comment

begin_comment
comment|/*  * Structure of a CDC-specific Cache Control mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_CDCcachectlmode
block|{
name|u_char
name|ccm_flags
decl_stmt|,
comment|/* flags (below) */
name|ccm_pfthresh
decl_stmt|,
comment|/* prefetch threshold */
name|ccm_maxthresh
decl_stmt|,
comment|/* maximum threshold (?) */
name|ccm_maxpfmult
decl_stmt|,
comment|/* maximum prefetch multiplier */
name|ccm_minthresh
decl_stmt|,
comment|/* minimum thresold (?) */
name|ccm_minpfmult
decl_stmt|,
comment|/* minimum prefetch multiplier */
name|ccm_xxx
index|[
literal|8
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_CDC_CCM_WIE
value|0x40
end_define

begin_comment
comment|/* write index enable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CDC_CCM_CE
value|0x10
end_define

begin_comment
comment|/* cache enable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CDC_CCM_TBLSZ
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_comment
comment|/* table size */
end_comment

begin_comment
comment|/*  * Bits in cdb_lenl for a READ CAPACITY command,  * and structure returned as data.  *  * If PMI is off, the lba in the cdb must be 0.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_RC_PMI
value|0x01
end_define

begin_comment
comment|/* Partial Medium Indicator */
end_comment

begin_struct
struct|struct
name|scsi_rc
block|{
name|u_char
name|rc_lbah
decl_stmt|;
comment|/* logical block address (MSB) */
name|u_char
name|rc_lbahm
decl_stmt|;
comment|/* logical block address */
name|u_char
name|rc_lbalm
decl_stmt|;
comment|/* logical block address */
name|u_char
name|rc_lbal
decl_stmt|;
comment|/* logical block address (LSB) */
name|u_char
name|rc_blh
decl_stmt|;
comment|/* block length (MSB) */
name|u_char
name|rc_blhm
decl_stmt|;
comment|/* block length */
name|u_char
name|rc_bllm
decl_stmt|;
comment|/* block length */
name|u_char
name|rc_bll
decl_stmt|;
comment|/* block length (LSB) */
block|}
struct|;
end_struct

end_unit

