begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: sdreg.h,v 4.300 91/06/09 06:38:28 root Rel41 $ SONY  *  *	@(#)sdreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989- by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	sdreg.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SDREG__
end_ifndef

begin_define
define|#
directive|define
name|__SDREG__
value|1
end_define

begin_define
define|#
directive|define
name|MAXSLAVE
value|8
end_define

begin_define
define|#
directive|define
name|PNUM
value|8
end_define

begin_define
define|#
directive|define
name|RSEN_CNT
value|32
end_define

begin_comment
comment|/******************************************************/
end_comment

begin_comment
comment|/*  *	software control structure / controller  */
end_comment

begin_struct
struct|struct
name|sdc_softc
block|{
comment|/*00*/
name|int
name|sdc_wticks
decl_stmt|;
comment|/*04*/
name|int
name|sdc_state
decl_stmt|;
define|#
directive|define
name|SDCS_NORMAL
value|0x0
define|#
directive|define
name|SDCS_RSENSE
value|0x1
define|#
directive|define
name|SDCS_ECC
value|0x2
define|#
directive|define
name|SDCS_RASREAD
value|0x4
define|#
directive|define
name|SDCS_RASBLK
value|0x8
define|#
directive|define
name|SDCS_RASWRITE
value|0x10
define|#
directive|define
name|SDCS_RETRY
value|0x20
define|#
directive|define
name|SDCS_PREVRMB
value|0x40
define|#
directive|define
name|SDCS_LOSTDATA
value|0x1000
define|#
directive|define
name|SDCS_ECC_HOLD
value|0x100000
define|#
directive|define
name|SDCS_ECCOFF
value|0x200000
define|#
directive|define
name|SDCS_REZERO
value|0x400000
define|#
directive|define
name|SDCS_OPEN_WAIT
value|0x20000000
define|#
directive|define
name|SDCS_SCUNLOCK
value|0x40000000
define|#
directive|define
name|SDCS_IOCTL
value|0x80000000
comment|/*08*/
name|int
name|sdc_nhrderr
decl_stmt|;
comment|/*0c*/
name|int
name|sdc_retrycnt
decl_stmt|;
comment|/*10*/
name|int
name|sdc_softas
decl_stmt|;
comment|/*14*/
name|int
name|sdc_timeo
decl_stmt|;
comment|/*18*/
name|int
name|sdc_countcc
decl_stmt|;
comment|/*1c*/
name|int
name|sdc_firmware
decl_stmt|;
define|#
directive|define
name|SDCFW_DEFMODE
value|0x1
define|#
directive|define
name|SDCFW_CACHE
value|0x2
define|#
directive|define
name|SDCFW_AWRE
value|0x4
define|#
directive|define
name|SDCFW_ARRE
value|0x8
define|#
directive|define
name|SDCFW_OLDWREN3
value|0x10
define|#
directive|define
name|SDCFW_WANTED
value|0x20
define|#
directive|define
name|SDCFW_BUSY
value|0x40
define|#
directive|define
name|SDCFW_RMB
value|0x80
define|#
directive|define
name|SDCFW_CDBUGS
value|0x100
define|#
directive|define
name|SDCFW_CONTR
value|0x200
define|#
directive|define
name|SDCFW_DEVMASK
value|0xf0000000
define|#
directive|define
name|SDCFW_HD
value|0x10000000
define|#
directive|define
name|SDCFW_MO
value|0x20000000
define|#
directive|define
name|SDCFW_CD
value|0x40000000
comment|/*20*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *	software control structure / drive  */
end_comment

begin_struct
struct|struct
name|sdd_softc
block|{
comment|/*00*/
name|int
name|sdd_sectsize
decl_stmt|;
comment|/*04*/
name|int
name|sdd_nsect
decl_stmt|;
comment|/*08*/
name|int
name|sdd_badsect
decl_stmt|;
comment|/*0c*/
name|int
name|sdd_flags
decl_stmt|;
define|#
directive|define
name|SDDF_DSKCHGD
value|0x0
define|#
directive|define
name|SDDF_SAMEDSK
value|0x1
define|#
directive|define
name|SDDF_WPROTECT
value|0x2
define|#
directive|define
name|SDDF_XUSE
value|0x4
define|#
directive|define
name|SDDF_NONFMT
value|0x8
define|#
directive|define
name|SDDF_FMTDONE
value|0x10
define|#
directive|define
name|SDDF_REQ_EJECT
value|0x20
define|#
directive|define
name|SDDF_ERASEOFF
value|0x40
define|#
directive|define
name|SDDF_VBADSECT
value|0x80
define|#
directive|define
name|SDDF_SKIPCHECK
value|0x100
define|#
directive|define
name|SDDF_SYNCTR
value|0x200
define|#
directive|define
name|SDDF_INHRMV
value|0x400
define|#
directive|define
name|SDDF_GETTMP
value|0x800
define|#
directive|define
name|SDDF_AUDIO_START
value|0x80000000
comment|/*10*/
name|int
name|sdd_start
decl_stmt|;
comment|/* for removable disk */
comment|/*14*/
name|int
name|sdd_stoptime
decl_stmt|;
comment|/* for removable disk */
name|daddr_t
name|sdd_lastblk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sdst
block|{
comment|/*00*/
name|short
name|nsect
decl_stmt|;
comment|/* # sectors / track */
comment|/*02*/
name|short
name|ntrak
decl_stmt|;
comment|/* # tracks / cylinder */
comment|/*04*/
name|short
name|nspc
decl_stmt|;
comment|/* # sectors / cylinder */
comment|/*06*/
name|short
name|ncyl
decl_stmt|;
comment|/* # cylinders */
comment|/*08*/
name|short
name|rps
decl_stmt|;
comment|/* # revolutions / second */
comment|/*0a*/
name|short
name|xxxx
decl_stmt|;
comment|/* reserved */
comment|/*0c*/
name|struct
name|size
modifier|*
name|sizes
decl_stmt|;
comment|/* partition table */
comment|/*10*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|size
block|{
comment|/*00*/
name|daddr_t
name|sd_nblocks
decl_stmt|;
comment|/*04*/
name|daddr_t
name|sd_blkoff
decl_stmt|;
comment|/*08*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Device configuration table.  */
end_comment

begin_struct
struct|struct
name|sddevinfo
block|{
comment|/*00*/
name|int
name|id_len
decl_stmt|;
comment|/* identify length */
comment|/*04*/
name|char
modifier|*
name|id_name
decl_stmt|;
comment|/* vendor& product ID */
comment|/*08*/
name|char
modifier|*
name|revs
decl_stmt|;
comment|/* revision */
comment|/*0c*/
name|int
name|capacity
decl_stmt|;
comment|/* drive capacity */
comment|/*10*/
name|char
modifier|*
name|call_name
decl_stmt|;
comment|/* device nickname */
comment|/*14*/
name|int
name|type
decl_stmt|;
comment|/* device type code */
define|#
directive|define
name|UNKNOWN_DISK
value|0
comment|/**/
define|#
directive|define
name|WREN3_101
value|110
define|#
directive|define
name|WREN3_182
value|111
define|#
directive|define
name|WREN3_101_HH
value|112
define|#
directive|define
name|WREN4_286
value|120
define|#
directive|define
name|WREN5_170_HH
value|130
define|#
directive|define
name|WREN6_415_HH
value|141
define|#
directive|define
name|ST1480N
value|171
comment|/**/
define|#
directive|define
name|DK515C_78
value|210
define|#
directive|define
name|DK516C_16
value|211
define|#
directive|define
name|DK312C_25
value|220
define|#
directive|define
name|DK312C_20
value|221
comment|/**/
define|#
directive|define
name|SRD_2040Z
value|310
define|#
directive|define
name|SMO_S501
value|330
comment|/* format mode 2 */
define|#
directive|define
name|SMO_S501_ISO
value|331
comment|/* format mode 3 (spare band 1024) */
define|#
directive|define
name|SMO_S501_ISO2
value|332
comment|/* format mode 3 (spare band 2048) */
comment|/**/
define|#
directive|define
name|XT_8760S
value|810
comment|/**/
comment|/*18*/
name|int
name|firm_flags
decl_stmt|;
comment|/* firmware spec */
define|#
directive|define
name|FIRM_CACHE_ON
value|0x01
define|#
directive|define
name|FIRM_CACHE_OFF
value|0x02
define|#
directive|define
name|FIRM_SYNCTR
value|0x04
define|#
directive|define
name|FIRM_AWRE
value|0x08
define|#
directive|define
name|FIRM_ARRE
value|0x10
comment|/*1c*/
name|int
name|tr_period
decl_stmt|;
comment|/* synchronous transfer period */
comment|/*20*/
name|int
name|tr_offset
decl_stmt|;
comment|/* synchronous transfer offset */
comment|/*24*/
name|struct
name|sc_ureq
modifier|*
modifier|*
name|setup_cmds
decl_stmt|;
comment|/* device setup commands */
comment|/*28*/
name|struct
name|sdst
modifier|*
name|sdstp
decl_stmt|;
comment|/* device specifications */
define|#
directive|define
name|calc_disk_sizes
value|NULL
comment|/*2c*/
name|char
modifier|*
name|ERP_page
decl_stmt|;
comment|/* normal Error Recovery Parameters */
comment|/*30*/
name|char
modifier|*
name|max_ERP_page
decl_stmt|;
comment|/* max Error Recovery Parameters */
comment|/*34*/
name|char
modifier|*
modifier|*
name|other_pages
decl_stmt|;
comment|/* Other Parameters */
comment|/*38*/
name|int
name|fmt_opts
decl_stmt|;
comment|/* Format options */
define|#
directive|define
name|FMT_DLFMT
value|0x07
comment|/* Defect list format */
define|#
directive|define
name|FMT_DLF_BLK
value|0x00
comment|/* block format */
define|#
directive|define
name|FMT_DLF_IDX
value|0x04
comment|/* bytes from index format */
define|#
directive|define
name|FMT_DLF_PHYS
value|0x05
comment|/* physical sector format */
define|#
directive|define
name|FMT_DCRT
value|0x20
comment|/* Disable Certification */
comment|/*3c*/
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|news1800
end_ifdef

begin_define
define|#
directive|define
name|SYNC_TR_OFS
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SYNC_TR_OFS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*********************************************************/
end_comment

begin_comment
comment|/*  *	MODE SELECT/SENSE bit assign  */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_NULL
value|0x00
end_define

begin_comment
comment|/* product unique not used */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_ERR
value|0x01
end_define

begin_comment
comment|/* error recovery parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_CNCT
value|0x02
end_define

begin_comment
comment|/* disconnect/reconnect control parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_FMT1
value|0x03
end_define

begin_comment
comment|/* direct access device format parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_GEOM
value|0x04
end_define

begin_comment
comment|/* rigid disk drive geometry parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_CACHE1
value|0x08
end_define

begin_comment
comment|/* cache control parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_CACHE2
value|0x38
end_define

begin_comment
comment|/* cache control parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_FMT2
value|0x20
end_define

begin_comment
comment|/* format parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PG_MODIFY
value|0x20
end_define

begin_comment
comment|/* modification parameters */
end_comment

begin_define
define|#
directive|define
name|SDM_PAGE
value|0x00
end_define

begin_comment
comment|/* page cache mode */
end_comment

begin_define
define|#
directive|define
name|SDM_RING
value|0x10
end_define

begin_comment
comment|/* ring cache mode */
end_comment

begin_define
define|#
directive|define
name|SDM_RCD
value|0x01
end_define

begin_comment
comment|/* Read Cache Disable */
end_comment

begin_define
define|#
directive|define
name|SDM_STOD
value|0x08
end_define

begin_comment
comment|/* SCSI Time Out Delay*/
end_comment

begin_define
define|#
directive|define
name|SDM_ESDT
value|0x04
end_define

begin_comment
comment|/* enable SCSI data timeout */
end_comment

begin_define
define|#
directive|define
name|SDM_PF
value|0x10
end_define

begin_comment
comment|/* page format */
end_comment

begin_define
define|#
directive|define
name|SDM_PC_CUR
value|0x00
end_define

begin_comment
comment|/* page control field (current value) */
end_comment

begin_define
define|#
directive|define
name|SDM_PC_CHG
value|0x40
end_define

begin_comment
comment|/* page control field (changeable value) */
end_comment

begin_define
define|#
directive|define
name|SDM_PC_DEF
value|0x80
end_define

begin_comment
comment|/* page control field (default value) */
end_comment

begin_define
define|#
directive|define
name|SDM_PC_SAVE
value|0xc0
end_define

begin_comment
comment|/* page control field (saved value) */
end_comment

begin_define
define|#
directive|define
name|SDM_PCODE_ER
value|SDM_PG_ERR
end_define

begin_define
define|#
directive|define
name|SDM_PCODE_CON
value|SDM_PG_CNCT
end_define

begin_define
define|#
directive|define
name|SDM_PCODE_FMT
value|SDM_PG_FMT2
end_define

begin_define
define|#
directive|define
name|SDM_PCODE_ALL
value|0x3f
end_define

begin_define
define|#
directive|define
name|SDM_DCR
value|0x01
end_define

begin_comment
comment|/* Disable Correction */
end_comment

begin_define
define|#
directive|define
name|SDM_DTE
value|0x02
end_define

begin_comment
comment|/* Disable Transfer on Error */
end_comment

begin_define
define|#
directive|define
name|SDM_PER
value|0x04
end_define

begin_comment
comment|/* Post Error */
end_comment

begin_define
define|#
directive|define
name|SDM_EEC
value|0x08
end_define

begin_comment
comment|/* Enable Early Correction */
end_comment

begin_define
define|#
directive|define
name|SDM_RC
value|0x10
end_define

begin_comment
comment|/* Read Continuous */
end_comment

begin_define
define|#
directive|define
name|SDM_TB
value|0x20
end_define

begin_comment
comment|/* Transfer Block */
end_comment

begin_define
define|#
directive|define
name|SDM_ARRE
value|0x40
end_define

begin_comment
comment|/* automatic read reallocate enable */
end_comment

begin_define
define|#
directive|define
name|SDM_AWRE
value|0x80
end_define

begin_comment
comment|/* automatic write reallocate enable */
end_comment

begin_comment
comment|/*  *	READ DEFECT LIST bit assign  */
end_comment

begin_define
define|#
directive|define
name|SDDL_PLIST
value|0x10
end_define

begin_comment
comment|/* primary defect list */
end_comment

begin_define
define|#
directive|define
name|SDDL_GLIST
value|0x08
end_define

begin_comment
comment|/* grown defect list  */
end_comment

begin_define
define|#
directive|define
name|SDDL_PHYSFMT
value|0x05
end_define

begin_comment
comment|/* physical sector format */
end_comment

begin_comment
comment|/*  *	FORMAT UNIT bit assign  */
end_comment

begin_define
define|#
directive|define
name|SDF_FMTDAT
value|0x10
end_define

begin_comment
comment|/* format data */
end_comment

begin_define
define|#
directive|define
name|SDF_CMPLST
value|0x08
end_define

begin_comment
comment|/* complete list */
end_comment

begin_define
define|#
directive|define
name|SDF_BLKFMT
value|0x10
end_define

begin_comment
comment|/* block format */
end_comment

begin_define
define|#
directive|define
name|SDF_PHYSFMT
value|0x15
end_define

begin_comment
comment|/* physical sector format */
end_comment

begin_define
define|#
directive|define
name|SDF_MKCDA
value|0x02
end_define

begin_comment
comment|/* make controll data area */
end_comment

begin_define
define|#
directive|define
name|SDF_MKPLST
value|0x01
end_define

begin_comment
comment|/* make P list */
end_comment

begin_comment
comment|/*  *	PREVENT/ALLOW MEDIUM REMOVAL bit assign  */
end_comment

begin_define
define|#
directive|define
name|SDRMV_PREV
value|0x01
end_define

begin_comment
comment|/* prevent medium removal */
end_comment

begin_define
define|#
directive|define
name|SDRMV_ALLOW
value|0x00
end_define

begin_comment
comment|/* allow medium removal */
end_comment

begin_comment
comment|/*  *	START/STOP UNIT bit assign  */
end_comment

begin_define
define|#
directive|define
name|SDSS_STOP
value|0x00
end_define

begin_comment
comment|/* stop unit */
end_comment

begin_define
define|#
directive|define
name|SDSS_START
value|0x01
end_define

begin_comment
comment|/* start unit */
end_comment

begin_define
define|#
directive|define
name|SDSS_EJECT
value|0x02
end_define

begin_comment
comment|/* eject */
end_comment

begin_comment
comment|/*********************************************************/
end_comment

begin_comment
comment|/*  *	IOCTL DEFINES  */
end_comment

begin_define
define|#
directive|define
name|SDIOC_PRVRMV
value|_IO('D', 0)
end_define

begin_comment
comment|/* prevent medium removal */
end_comment

begin_define
define|#
directive|define
name|SDIOC_ALWRMV
value|_IO('D', 1)
end_define

begin_comment
comment|/* allow medium removal */
end_comment

begin_define
define|#
directive|define
name|SDIOC_FORMAT
value|_IOWR('D', 2, struct fmt_data)
end_define

begin_comment
comment|/* format unit */
end_comment

begin_struct
struct|struct
name|fmt_data
block|{
comment|/*00*/
name|int
name|noglist
decl_stmt|;
comment|/* ignore G-list flag */
comment|/*04*/
name|u_char
modifier|*
name|dlh
decl_stmt|;
comment|/* defect list header */
comment|/*08*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDIOC_GSTOPT
value|_IOR('D', 3, int)
end_define

begin_comment
comment|/* get stop time */
end_comment

begin_define
define|#
directive|define
name|SDIOC_SSTOPT
value|_IOW('D', 4, int)
end_define

begin_comment
comment|/* set stop time */
end_comment

begin_define
define|#
directive|define
name|SDIOC_SEJECT
value|_IO('D', 5)
end_define

begin_comment
comment|/* set medium eject request */
end_comment

begin_define
define|#
directive|define
name|SDIOC_SXUSE
value|_IO('D', 6)
end_define

begin_comment
comment|/* set exclusive use */
end_comment

begin_define
define|#
directive|define
name|SDIOC_RXUSE
value|_IO('D', 7)
end_define

begin_comment
comment|/* reset exclusive use */
end_comment

begin_define
define|#
directive|define
name|SDIOC_ERSOFF
value|_IO('D', 8)
end_define

begin_comment
comment|/* no erase before write */
end_comment

begin_define
define|#
directive|define
name|SDIOC_ERSON
value|_IO('D', 9)
end_define

begin_comment
comment|/* erase before write */
end_comment

begin_define
define|#
directive|define
name|SDIOC_INQUIRY
value|_IOR('D', 10, struct sc_inq)
end_define

begin_define
define|#
directive|define
name|SDIOC_RCAP
value|_IOR('D', 11, int)
end_define

begin_define
define|#
directive|define
name|SDIOC_ECODE
value|_IOW('D', 14, int)
end_define

begin_comment
comment|/* extend ecode on/off */
end_comment

begin_define
define|#
directive|define
name|SDIOC_GFLAGS
value|_IOR('D', 15, int)
end_define

begin_comment
comment|/* get ii->ii_flags */
end_comment

begin_define
define|#
directive|define
name|SDIOC_SFLAGS
value|_IOW('D', 16, int)
end_define

begin_comment
comment|/* set ii->ii_flags */
end_comment

begin_comment
comment|/*  * ii->ii_flags bits assign  */
end_comment

begin_define
define|#
directive|define
name|SD_F_ENW
value|0x01
end_define

begin_comment
comment|/* enable write open */
end_comment

begin_define
define|#
directive|define
name|SD_F_ECODE
value|0x02
end_define

begin_comment
comment|/* enable extend code */
end_comment

begin_define
define|#
directive|define
name|SD_F_WRTVRFY
value|0x04
end_define

begin_comment
comment|/* execute write& verify */
end_comment

begin_define
define|#
directive|define
name|SD_F_IGNLABEL
value|0x08
end_define

begin_comment
comment|/* ignore disklabel/diskinfo */
end_comment

begin_define
define|#
directive|define
name|SD_F_EOLBA
value|0x10
end_define

begin_comment
comment|/* error if outside LBA */
end_comment

begin_define
define|#
directive|define
name|SDIOC_RASBLK
value|_IOW('D', 17, int)
end_define

begin_comment
comment|/* reassign block */
end_comment

begin_define
define|#
directive|define
name|SDIOC_GNICKNAME
value|_IOW('D', 18, char *)
end_define

begin_comment
comment|/* get device nickname */
end_comment

begin_define
define|#
directive|define
name|SDIOC_GTYPINDEX
value|_IOR('D', 19, int)
end_define

begin_comment
comment|/* get ii->ii_type */
end_comment

begin_define
define|#
directive|define
name|SDIOC_SSYNCPARAM
value|_IOW('D', 20, struct sync_param)
end_define

begin_comment
comment|/* set sync tr param */
end_comment

begin_define
define|#
directive|define
name|SDIOC_GSYNCPARAM
value|_IOR('D', 21, struct sync_param)
end_define

begin_comment
comment|/* get sync tr param */
end_comment

begin_struct
struct|struct
name|sync_param
block|{
name|int
name|tr_period
decl_stmt|;
name|int
name|tr_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDIOC_FORMAT2
value|_IOWR('D', 22, struct sc_ureq)
end_define

begin_comment
comment|/* format unit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__SDREG__ */
end_comment

end_unit

