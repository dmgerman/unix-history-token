begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)disktape.h	5.4 (Berkeley) %G%  *  * from: $Header: disktape.h,v 1.4 93/04/30 00:02:16 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Commands common to disk and tape devices, but not other SCSI devices.  */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SELECT6
value|0x15
end_define

begin_comment
comment|/* mode select (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SENSE6
value|0x1a
end_define

begin_comment
comment|/* mode sense (6 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SELECT10
value|0x55
end_define

begin_comment
comment|/* mode select (10 byte cdb) */
end_comment

begin_define
define|#
directive|define
name|CMD_MODE_SENSE10
value|0x5a
end_define

begin_comment
comment|/* mode sense (10 byte cdb) */
end_comment

begin_comment
comment|/*  * Structure of MODE SELECT commands (i.e., the cdb; 6& 10 byte flavors).  * The only difference is that the 10-byte version can give more parameter  * bytes.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_modeselect6
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x15 */
name|cdb_lun_flags
decl_stmt|,
comment|/* LUN + flags */
name|cdb_xxx
index|[
literal|2
index|]
decl_stmt|,
comment|/* reserved */
name|cdb_len
decl_stmt|,
comment|/* parameter list length */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_cdb_modeselect10
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x55 */
name|cdb_lun_flags
decl_stmt|,
comment|/* LUN + flags */
name|cdb_xxx
index|[
literal|5
index|]
decl_stmt|,
comment|/* reserved */
name|cdb_lenh
decl_stmt|,
comment|/* parameter list length (MSB) */
name|cdb_lenl
decl_stmt|,
comment|/* parameter list length (LSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/* flags in SCSI_MODESELECT commands */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SCSI1_DATA
value|0x00
end_define

begin_comment
comment|/* SCSI-1 data format */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SCSI2_DATA
value|0x10
end_define

begin_comment
comment|/* SCSI-2 data format */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_DONTSAVE
value|0x00
end_define

begin_comment
comment|/* don't save pages */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSEL_SAVEPAGES
value|0x01
end_define

begin_comment
comment|/* save mode pages */
end_comment

begin_comment
comment|/*  * Structure of MODE SENSE command (i.e., the cdb; 6& 10 byte flavors).  * Again, the 10-byte version merely allows more parameter bytes.  * Note that these lengths include the MODE SENSE headers, while those  * for individual mode pages do not.  (Consistency?  What's that?)  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_modesense6
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x1a */
name|cdb_lun_flags
decl_stmt|,
comment|/* logical unit number + flags */
name|cdb_pcc
decl_stmt|,
comment|/* page control& code */
name|cdb_xxx
decl_stmt|,
comment|/* reserved */
name|cdb_len
decl_stmt|,
comment|/* allocation length */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_cdb_modesense10
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x5a */
name|cdb_lun_flags
decl_stmt|,
comment|/* logical unit number + flags */
name|cdb_pcc
decl_stmt|,
comment|/* page control& code */
name|cdb_xxx
index|[
literal|4
index|]
decl_stmt|,
comment|/* reserved */
name|cdb_lenh
decl_stmt|,
comment|/* allocation length (MSB) */
name|cdb_lenl
decl_stmt|,
comment|/* allocation length (MSB) */
name|cdb_ctrl
decl_stmt|;
comment|/* control byte */
block|}
struct|;
end_struct

begin_comment
comment|/* flags in SCSI_MODESENSE commands */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSENSE_DBD
value|0x08
end_define

begin_comment
comment|/* device returns db descriptors */
end_comment

begin_comment
comment|/* page controls */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSENSE_PCTL_CUR
value|0x00
end_define

begin_comment
comment|/* return current parameters */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSENSE_PCTL_VAR
value|0x40
end_define

begin_comment
comment|/* return variable parameters */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSENSE_PCTL_DFLT
value|0x80
end_define

begin_comment
comment|/* return default parameters */
end_comment

begin_define
define|#
directive|define
name|SCSI_MSENSE_PCTL_SAVED
value|0xc0
end_define

begin_comment
comment|/* return saved parameters */
end_comment

begin_comment
comment|/*  * Both MODE_SENSE and MODE_SELECT use a Mode Parameter Header,  * followed by an array of Block Descriptors, followed by an array  * of Pages.  We define structures for the Block Descriptor and Page  * header first, then the two (6 and 10 byte) Mode Parameter headers  * (not including the Block Descriptor(s) and any mode pages themselves).  */
end_comment

begin_struct
struct|struct
name|scsi_ms_bd
block|{
comment|/* mode sense/select block descriptor */
name|u_char
name|bd_dc
decl_stmt|,
comment|/* density code (tapes only) */
name|bd_nbh
decl_stmt|,
comment|/* number of blocks (MSB) */
name|bd_nbm
decl_stmt|,
comment|/* number of blocks */
name|bd_nbl
decl_stmt|,
comment|/* number of blocks (LSB) */
name|bd_xxx
decl_stmt|,
comment|/* reserved */
name|bd_blh
decl_stmt|,
comment|/* block length (MSB) */
name|bd_blm
decl_stmt|,
comment|/* block length */
name|bd_bll
decl_stmt|;
comment|/* block length (LSB) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_ms_page_hdr
block|{
comment|/* mode sense/select page header */
name|u_char
name|mp_psc
decl_stmt|,
comment|/* saveable flag + code */
name|mp_len
decl_stmt|;
comment|/* parameter length (excludes this header) */
comment|/* followed by parameters */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSI_MS_MP_SAVEABLE
value|0x80
end_define

begin_comment
comment|/* page can be saved */
end_comment

begin_comment
comment|/*				0x40	   reserved */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_MASK
value|0x3f
end_define

begin_comment
comment|/* page code mask */
end_comment

begin_comment
comment|/*  * Structure of returned mode sense6 / mode select6 (hence "ms6") data.  */
end_comment

begin_struct
struct|struct
name|scsi_ms6
block|{
name|u_char
name|ms_len
decl_stmt|,
comment|/* total sense data length */
name|ms_mt
decl_stmt|,
comment|/* medium type (disks only?) */
name|ms_dsp
decl_stmt|,
comment|/* device specific parameter */
name|ms_bdl
decl_stmt|;
comment|/* block descriptor length (bytes) */
comment|/* followed by block descriptors, if any */
comment|/* followed by pages, if any */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Same, but for ms10.  */
end_comment

begin_struct
struct|struct
name|scsi_ms10
block|{
name|u_char
name|ms_lenh
decl_stmt|,
comment|/* total sense length (MSB) */
name|ms_lenl
decl_stmt|,
comment|/* total sense length (LSB) */
name|ms_mt
decl_stmt|,
comment|/* medium type (disks only?) */
name|ms_dsp
decl_stmt|,
comment|/* device specific parameter */
name|ms_xxx
index|[
literal|2
index|]
decl_stmt|,
comment|/* reserved */
name|ms_bdlh
decl_stmt|,
comment|/* block descriptor length (bytes) (MSB) */
name|ms_bdll
decl_stmt|;
comment|/* block descriptor length (bytes) (LSB) */
comment|/* followed by block descriptors, if any */
comment|/* followed by pages, if any */
block|}
struct|;
end_struct

begin_comment
comment|/* values for the Medium Type field - disks */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_DEFAULT
value|0x00
end_define

begin_comment
comment|/* whatever is current */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_SS
value|0x01
end_define

begin_comment
comment|/* single sided, unspecified medium */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_DS
value|0x02
end_define

begin_comment
comment|/* double sided, unspecified medium */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_8SSSD
value|0x05
end_define

begin_comment
comment|/* 8" floppy, SSSD (X3.73-1980) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_8DSSD
value|0x06
end_define

begin_comment
comment|/* 8" floppy, DSSD (X3B8-140) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_8SSDD
value|0x09
end_define

begin_comment
comment|/* 8" floppy, SSDD (X3B8/78-139) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_8DSDD
value|0x0a
end_define

begin_comment
comment|/* 8" floppy, DSDD (X3.121-1984) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_5SSSD
value|0x0d
end_define

begin_comment
comment|/* 5.25" floppy, SSSD (X3.82-1980) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_5DSDD
value|0x12
end_define

begin_comment
comment|/* 5.25" floppy, DSDD (X3.125-1984) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_5DSDD96
value|0x16
end_define

begin_comment
comment|/* 5.25", DSDD, 96tpi (X3.126-198X) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_5DSQD
value|0x1a
end_define

begin_comment
comment|/* 5.25", DSQD, 96tpi (DIS 8630) */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_3DS
value|0x1e
end_define

begin_comment
comment|/* 3.5", double sided (X3.137-198X) */
end_comment

begin_comment
comment|/* values for the Medium Type field - tapes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_QIC_12T
value|0x40
end_define

begin_comment
comment|/* 0.25", 12 tracks */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_MT_QIC_24T
value|0x44
end_define

begin_comment
comment|/* 0.25", 24 tracks */
end_comment

begin_comment
comment|/* values for the Device Specific Parameter field */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_WP
value|0x80
end_define

begin_comment
comment|/* write protect (both disk& tape) */
end_comment

begin_comment
comment|/* if disk */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_DPO_FUA
value|0x10
end_define

begin_comment
comment|/* cache flags DPO, FUA supported */
end_comment

begin_comment
comment|/* if tape */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_UNBUFFERED
value|0x00
end_define

begin_comment
comment|/* unbuffered writes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_BUFFERED
value|0x10
end_define

begin_comment
comment|/* buffered writes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_BUF2
value|0x20
end_define

begin_comment
comment|/* buffered, for shared tapes */
end_comment

begin_comment
comment|/*				0x30..0x70 reserved */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_SPEED_DFLT
value|0x00
end_define

begin_comment
comment|/* use device default speed */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DSP_SPEED_MASK
value|0x0f
end_define

begin_comment
comment|/* mask for non-default speeds */
end_comment

begin_comment
comment|/* values for the Density Code field - tapes */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_DEFAULT
value|0
end_define

begin_comment
comment|/* use device default density */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_9T_800BPI
value|1
end_define

begin_comment
comment|/* 9 track, 800 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_9T_1600BPI
value|2
end_define

begin_comment
comment|/* 9 track, 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_9T_6250BPI
value|3
end_define

begin_comment
comment|/* 9 track, 6250 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_QIC_XX1
value|4
end_define

begin_comment
comment|/* QIC-11? 4 or 9 track, 8000 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_QIC_XX2
value|5
end_define

begin_comment
comment|/* QIC-11? 4 or 9 track, 8000 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_9T_3200BPI
value|6
end_define

begin_comment
comment|/* 9 track, 3200 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_QIC_XX3
value|7
end_define

begin_comment
comment|/* QIC, 4 track, 6400 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_CS_XX4
value|8
end_define

begin_comment
comment|/* cassette 4 track, 8000 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_HIC_XX5
value|9
end_define

begin_comment
comment|/* half inch cartridge, 18 track */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_HIC_XX6
value|10
end_define

begin_comment
comment|/* HIC, 22 track, 6667 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_QIC_XX7
value|11
end_define

begin_comment
comment|/* QIC, 4 track, 1600 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_HIC_XX8
value|12
end_define

begin_comment
comment|/* HIC, 24 track, 12690 bpi */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_DC_HIC_XX9
value|13
end_define

begin_comment
comment|/* HIC, 24 track, 25380 bpi */
end_comment

begin_comment
comment|/*  * Common page codes.  */
end_comment

begin_comment
comment|/*				0x01	   device specific */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_DR
value|0x02
end_define

begin_comment
comment|/* disconnect/reconnect control */
end_comment

begin_comment
comment|/*				0x03..0x08 device specific */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_PDEV
value|0x09
end_define

begin_comment
comment|/* peripheral device page */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_CTLMODE
value|0x0a
end_define

begin_comment
comment|/* control mode page */
end_comment

begin_comment
comment|/*				0x0b..0x1f device specific */
end_comment

begin_comment
comment|/*				0x20..0x3e vendor specific */
end_comment

begin_define
define|#
directive|define
name|SCSI_MS_PC_ALL
value|0x3f
end_define

begin_comment
comment|/* all pages */
end_comment

begin_comment
comment|/*  * Structure of a Disconnect/Reconnect Control mode page.  */
end_comment

begin_struct
struct|struct
name|scsi_page_dr
block|{
name|u_char
name|dr_full
decl_stmt|,
comment|/* buffer full ratio */
name|dr_empty
decl_stmt|,
comment|/* buffer empty ratio */
name|dr_inacth
decl_stmt|,
comment|/* bus inactivity timeout (MSB) */
name|dr_inactl
decl_stmt|,
comment|/* bus inactivity timeout (LSB) */
name|dr_disconh
decl_stmt|,
comment|/* disconnect time limit (MSB) */
name|dr_disconl
decl_stmt|,
comment|/* disconnect time limit (LSB) */
name|dr_conh
decl_stmt|,
comment|/* connect time limit (MSB) */
name|dr_conl
decl_stmt|,
comment|/* connect time limit (LSB) */
name|dr_bursth
decl_stmt|,
comment|/* maximum burst size (MSB) */
name|dr_burstl
decl_stmt|,
comment|/* maximum burst size (LSB) */
name|dr_dtdc
decl_stmt|,
comment|/* Data Transfer Disconnect Control (below) */
name|dr_xxx
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_comment
comment|/* Data Transfer Disconnect Control */
end_comment

begin_define
define|#
directive|define
name|SCSI_DR_DTDC_MASK
value|0x03
end_define

begin_comment
comment|/* mask for valid bits */
end_comment

begin_define
define|#
directive|define
name|SCSI_DR_DTDC_NONE
value|0x00
end_define

begin_comment
comment|/* no control */
end_comment

begin_define
define|#
directive|define
name|SCSI_DR_DTDC_NOTDATA
value|0x01
end_define

begin_comment
comment|/* never during data transfer */
end_comment

begin_define
define|#
directive|define
name|SCSI_DR_DTDC_RSVD
value|0x02
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SCSI_DR_DTDC_NOTD2
value|0x03
end_define

begin_comment
comment|/* never during/after data transfer */
end_comment

begin_comment
comment|/*  * Structure of a PREVENT/ALLOW MEDIUM REMOVAL command.  */
end_comment

begin_struct
struct|struct
name|scsi_cdb_pamr
block|{
name|u_char
name|cdb_cmd
decl_stmt|,
comment|/* 0x1e */
name|cdb_lun_xxx
decl_stmt|,
comment|/* logical unit number + reserved */
name|cdb_xxx1
decl_stmt|,
comment|/* reserved */
name|cdb_xxx2
decl_stmt|,
comment|/* reserved */
name|cdb_prevent
decl_stmt|,
comment|/* 1=prevent, 0=allow */
name|cdb_ctrl
decl_stmt|;
block|}
struct|;
end_struct

end_unit

