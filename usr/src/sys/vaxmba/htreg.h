begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)htreg.h	7.2 (Berkeley) 5/12/87  */
end_comment

begin_struct
struct|struct
name|htdevice
block|{
name|int
name|htcs1
decl_stmt|;
comment|/* control status register */
name|int
name|htds
decl_stmt|;
comment|/* drive status register */
name|int
name|hter
decl_stmt|;
comment|/* error register */
name|int
name|htmr
decl_stmt|;
comment|/* maintenance register */
name|int
name|htas
decl_stmt|;
comment|/* attention status register */
name|int
name|htfc
decl_stmt|;
comment|/* frame counter */
name|int
name|htdt
decl_stmt|;
comment|/* drive type register */
name|int
name|htck
decl_stmt|;
comment|/* nrzi check (crc) error character */
name|int
name|htsn
decl_stmt|;
comment|/* serial number register */
name|int
name|httc
decl_stmt|;
comment|/* tape controll register */
block|}
struct|;
end_struct

begin_comment
comment|/* htcs1 */
end_comment

begin_define
define|#
directive|define
name|HT_GO
value|000001
end_define

begin_comment
comment|/* go bit */
end_comment

begin_define
define|#
directive|define
name|HT_SENSE
value|000000
end_define

begin_comment
comment|/* no operations (sense) */
end_comment

begin_define
define|#
directive|define
name|HT_REWOFFL
value|000002
end_define

begin_comment
comment|/* rewind offline */
end_comment

begin_define
define|#
directive|define
name|HT_REW
value|000006
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|HT_DCLR
value|000010
end_define

begin_comment
comment|/* drive clear */
end_comment

begin_define
define|#
directive|define
name|HT_RIP
value|000020
end_define

begin_comment
comment|/* read in preset */
end_comment

begin_define
define|#
directive|define
name|HT_ERASE
value|000024
end_define

begin_comment
comment|/* erase */
end_comment

begin_define
define|#
directive|define
name|HT_WEOF
value|000026
end_define

begin_comment
comment|/* write tape mark */
end_comment

begin_define
define|#
directive|define
name|HT_SFORW
value|000030
end_define

begin_comment
comment|/* space forward */
end_comment

begin_define
define|#
directive|define
name|HT_SREV
value|000032
end_define

begin_comment
comment|/* space reverse */
end_comment

begin_define
define|#
directive|define
name|HT_WCHFWD
value|000050
end_define

begin_comment
comment|/* write check forward */
end_comment

begin_define
define|#
directive|define
name|HT_WCHREV
value|000056
end_define

begin_comment
comment|/* write check reverse */
end_comment

begin_define
define|#
directive|define
name|HT_WCOM
value|000060
end_define

begin_comment
comment|/* write forward */
end_comment

begin_define
define|#
directive|define
name|HT_RCOM
value|000070
end_define

begin_comment
comment|/* read forward */
end_comment

begin_define
define|#
directive|define
name|HT_RREV
value|000076
end_define

begin_comment
comment|/* read reverse */
end_comment

begin_comment
comment|/* htds */
end_comment

begin_define
define|#
directive|define
name|HTDS_ATA
value|0100000
end_define

begin_comment
comment|/* attention active */
end_comment

begin_define
define|#
directive|define
name|HTDS_ERR
value|0040000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|HTDS_PIP
value|0020000
end_define

begin_comment
comment|/* positioning in progress */
end_comment

begin_define
define|#
directive|define
name|HTDS_MOL
value|0010000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|HTDS_WRL
value|0004000
end_define

begin_comment
comment|/* write lock */
end_comment

begin_define
define|#
directive|define
name|HTDS_EOT
value|0002000
end_define

begin_comment
comment|/* end of tape */
end_comment

begin_comment
comment|/* bit 9 is unused */
end_comment

begin_define
define|#
directive|define
name|HTDS_DPR
value|0000400
end_define

begin_comment
comment|/* drive present (always 1) */
end_comment

begin_define
define|#
directive|define
name|HTDS_DRY
value|0000200
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|HTDS_SSC
value|0000100
end_define

begin_comment
comment|/* slave status change */
end_comment

begin_define
define|#
directive|define
name|HTDS_PES
value|0000040
end_define

begin_comment
comment|/* phase-encoded status */
end_comment

begin_define
define|#
directive|define
name|HTDS_SDWN
value|0000020
end_define

begin_comment
comment|/* settle down */
end_comment

begin_define
define|#
directive|define
name|HTDS_IDB
value|0000010
end_define

begin_comment
comment|/* identification burst */
end_comment

begin_define
define|#
directive|define
name|HTDS_TM
value|0000004
end_define

begin_comment
comment|/* tape mark */
end_comment

begin_define
define|#
directive|define
name|HTDS_BOT
value|0000002
end_define

begin_comment
comment|/* beginning of tape */
end_comment

begin_define
define|#
directive|define
name|HTDS_SLA
value|0000001
end_define

begin_comment
comment|/* slave attention */
end_comment

begin_define
define|#
directive|define
name|HTDS_BITS
define|\
value|"\10\20ATA\17ERR\16PIP\15MOL\14WRL\13EOT\11DPR\10DRY\ \7SSC\6PES\5SDWN\4IDB\3TM\2BOT\1SLA"
end_define

begin_comment
comment|/* hter */
end_comment

begin_define
define|#
directive|define
name|HTER_CORCRC
value|0100000
end_define

begin_comment
comment|/* correctible data or ecc */
end_comment

begin_define
define|#
directive|define
name|HTER_UNS
value|0040000
end_define

begin_comment
comment|/* unsafe */
end_comment

begin_define
define|#
directive|define
name|HTER_OPI
value|0020000
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|HTER_DTE
value|0010000
end_define

begin_comment
comment|/* drive timing error */
end_comment

begin_define
define|#
directive|define
name|HTER_NEF
value|0004000
end_define

begin_comment
comment|/* non-executable function */
end_comment

begin_define
define|#
directive|define
name|HTER_CSITM
value|0002000
end_define

begin_comment
comment|/* correctable skew/illegal tape mark */
end_comment

begin_define
define|#
directive|define
name|HTER_FCE
value|0001000
end_define

begin_comment
comment|/* frame count error */
end_comment

begin_define
define|#
directive|define
name|HTER_NSG
value|0000400
end_define

begin_comment
comment|/* non-standard gap */
end_comment

begin_define
define|#
directive|define
name|HTER_PEFLRC
value|0000200
end_define

begin_comment
comment|/* format error or lrc error */
end_comment

begin_define
define|#
directive|define
name|HTER_INCVPE
value|0000100
end_define

begin_comment
comment|/* incorrectable data error or vertical 					   parity error */
end_comment

begin_define
define|#
directive|define
name|HTER_DPAR
value|0000040
end_define

begin_comment
comment|/* data parity error */
end_comment

begin_define
define|#
directive|define
name|HTER_FMT
value|0000020
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|HTER_CPAR
value|0000010
end_define

begin_comment
comment|/* control bus parity error */
end_comment

begin_define
define|#
directive|define
name|HTER_RMR
value|0000004
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|HTER_ILR
value|0000002
end_define

begin_comment
comment|/* illegal register */
end_comment

begin_define
define|#
directive|define
name|HTER_ILF
value|0000001
end_define

begin_comment
comment|/* illegal function */
end_comment

begin_define
define|#
directive|define
name|HTER_BITS
define|\
value|"\10\20CORCRC\17UNS\16OPI\15DTE\14NEF\13CSITM\12FCE\11NSG\10PEFLRC\ \7INCVPE\6DPAR\5FMT\4CPAR\3RMR\2ILR\1ILF"
end_define

begin_define
define|#
directive|define
name|HTER_HARD
define|\
value|(HTER_UNS|HTER_OPI|HTER_NEF|HTER_DPAR|HTER_FMT|HTER_CPAR| \ 	HTER_RMR|HTER_ILR|HTER_ILF)
end_define

begin_comment
comment|/* htdt */
end_comment

begin_define
define|#
directive|define
name|HTDT_NSA
value|0100000
end_define

begin_comment
comment|/* not sector addressed; always 1 */
end_comment

begin_define
define|#
directive|define
name|HTDT_TAP
value|0040000
end_define

begin_comment
comment|/* tape; always 1 */
end_comment

begin_define
define|#
directive|define
name|HTDT_MOH
value|0020000
end_define

begin_comment
comment|/* moving head; always 0 */
end_comment

begin_define
define|#
directive|define
name|HTDT_7CH
value|0010000
end_define

begin_comment
comment|/* 7 channel; always 0 */
end_comment

begin_define
define|#
directive|define
name|HTDT_DRQ
value|0004000
end_define

begin_comment
comment|/* drive requested; always 0 */
end_comment

begin_define
define|#
directive|define
name|HTDT_SPR
value|0002000
end_define

begin_comment
comment|/* slave present */
end_comment

begin_comment
comment|/* bit 9 is spare */
end_comment

begin_comment
comment|/* bits 8-0 are formatter/transport type */
end_comment

begin_comment
comment|/* httc */
end_comment

begin_define
define|#
directive|define
name|HTTC_ACCL
value|0100000
end_define

begin_comment
comment|/* transport is not reading/writing */
end_comment

begin_define
define|#
directive|define
name|HTTC_FCS
value|0040000
end_define

begin_comment
comment|/* frame count status */
end_comment

begin_define
define|#
directive|define
name|HTTC_SAC
value|0020000
end_define

begin_comment
comment|/* slave address change */
end_comment

begin_define
define|#
directive|define
name|HTTC_EAODTE
value|0010000
end_define

begin_comment
comment|/* enable abort on data xfer errors */
end_comment

begin_comment
comment|/* bits 8-10 are density select */
end_comment

begin_define
define|#
directive|define
name|HTTC_800BPI
value|0001400
end_define

begin_comment
comment|/* in bits 8-10, dens=1600 */
end_comment

begin_define
define|#
directive|define
name|HTTC_1600BPI
value|0002000
end_define

begin_comment
comment|/* in bits 8-10, dens=800 */
end_comment

begin_define
define|#
directive|define
name|HTTC_6250BPI
value|0003400
end_define

begin_comment
comment|/* in bits 8-10, dens=6250 */
end_comment

begin_comment
comment|/* bits 4-7 are format select */
end_comment

begin_define
define|#
directive|define
name|HTTC_PDP11
value|0000300
end_define

begin_comment
comment|/* in bits 4-7, pdp11 normal format */
end_comment

begin_define
define|#
directive|define
name|HTTC_EVEN
value|0000010
end_define

begin_comment
comment|/* select even parity */
end_comment

begin_comment
comment|/* bits 0 - 2 are slave select */
end_comment

begin_define
define|#
directive|define
name|b_repcnt
value|b_bcount
end_define

begin_define
define|#
directive|define
name|b_command
value|b_resid
end_define

end_unit

