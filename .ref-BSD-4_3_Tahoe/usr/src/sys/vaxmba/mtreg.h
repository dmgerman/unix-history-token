begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mtreg.h	7.2 (Berkeley) 5/6/88  */
end_comment

begin_comment
comment|/*  * TU78 registers.  */
end_comment

begin_struct
struct|struct
name|mtdevice
block|{
name|int
name|mtcs
decl_stmt|;
comment|/* control status register */
name|int
name|mter
decl_stmt|;
comment|/* error register */
name|int
name|mtca
decl_stmt|;
comment|/* command address, rec cnt, skp cnt reg */
name|int
name|mtmr1
decl_stmt|;
comment|/* maintenance register */
name|int
name|mtas
decl_stmt|;
comment|/* attention summary register */
name|int
name|mtbc
decl_stmt|;
comment|/* byte count register */
name|int
name|mtdt
decl_stmt|;
comment|/* drive type register */
name|int
name|mtds
decl_stmt|;
comment|/* drive status register */
name|int
name|mtsn
decl_stmt|;
comment|/* serial number register */
name|int
name|mtmr2
decl_stmt|;
comment|/* maintenance register */
name|int
name|mtmr3
decl_stmt|;
comment|/* maintenance register */
name|int
name|mtner
decl_stmt|;
comment|/* non-data transfer error register */
name|int
name|mtncs
index|[
literal|4
index|]
decl_stmt|;
comment|/* non-data transfer command registers */
name|int
name|mtia
decl_stmt|;
comment|/* internal address */
name|int
name|mtid
decl_stmt|;
comment|/* internal data */
block|}
struct|;
end_struct

begin_comment
comment|/* mtcs */
end_comment

begin_define
define|#
directive|define
name|MT_GO
value|000001
end_define

begin_comment
comment|/* go bit */
end_comment

begin_define
define|#
directive|define
name|MT_NOOP
value|000002
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|MT_UNLOAD
value|000004
end_define

begin_comment
comment|/* unload tape */
end_comment

begin_define
define|#
directive|define
name|MT_REW
value|000006
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|MT_SENSE
value|000010
end_define

begin_comment
comment|/* sense */
end_comment

begin_define
define|#
directive|define
name|MT_DSE
value|000012
end_define

begin_comment
comment|/* data security erase */
end_comment

begin_define
define|#
directive|define
name|MT_WTMPE
value|000014
end_define

begin_comment
comment|/* write phase encoded tape mark */
end_comment

begin_define
define|#
directive|define
name|MT_WTM
value|MT_WTMPE
end_define

begin_comment
comment|/* generic write tape mark */
end_comment

begin_define
define|#
directive|define
name|MT_WTMGCR
value|000016
end_define

begin_comment
comment|/* write GCR tape mark */
end_comment

begin_define
define|#
directive|define
name|MT_SFORW
value|000020
end_define

begin_comment
comment|/* space forward record */
end_comment

begin_define
define|#
directive|define
name|MT_SREV
value|000022
end_define

begin_comment
comment|/* space reverse record */
end_comment

begin_define
define|#
directive|define
name|MT_SFORWF
value|000024
end_define

begin_comment
comment|/* space forward file */
end_comment

begin_define
define|#
directive|define
name|MT_SREVF
value|000026
end_define

begin_comment
comment|/* space reverse file */
end_comment

begin_define
define|#
directive|define
name|MT_SFORWE
value|000030
end_define

begin_comment
comment|/* space forward either */
end_comment

begin_define
define|#
directive|define
name|MT_SREVE
value|000032
end_define

begin_comment
comment|/* space reverse either */
end_comment

begin_define
define|#
directive|define
name|MT_ERGPE
value|000034
end_define

begin_comment
comment|/* erase tape, set PE */
end_comment

begin_define
define|#
directive|define
name|MT_ERASE
value|MT_ERGPE
end_define

begin_comment
comment|/* generic erase tape */
end_comment

begin_define
define|#
directive|define
name|MT_ERGGCR
value|000036
end_define

begin_comment
comment|/* erase tape, set GCR */
end_comment

begin_define
define|#
directive|define
name|MT_CLSPE
value|000040
end_define

begin_comment
comment|/* close file PE */
end_comment

begin_define
define|#
directive|define
name|MT_CLS
value|MT_CLSPE
end_define

begin_comment
comment|/* generic close file */
end_comment

begin_define
define|#
directive|define
name|MT_CLSGCR
value|000042
end_define

begin_comment
comment|/* close file GCR */
end_comment

begin_define
define|#
directive|define
name|MT_SLEOT
value|000044
end_define

begin_comment
comment|/* space to logical EOT */
end_comment

begin_define
define|#
directive|define
name|MT_SFLEOT
value|000046
end_define

begin_comment
comment|/* space forward file, stop on LEOT */
end_comment

begin_define
define|#
directive|define
name|MT_WCHFWD
value|000050
end_define

begin_comment
comment|/* write check forward */
end_comment

begin_define
define|#
directive|define
name|MT_WCHREV
value|000056
end_define

begin_comment
comment|/* write check reverse */
end_comment

begin_define
define|#
directive|define
name|MT_WRITEPE
value|000060
end_define

begin_comment
comment|/* write phase encoded */
end_comment

begin_define
define|#
directive|define
name|MT_WRITE
value|MT_WRITEPE
end_define

begin_comment
comment|/* generic write */
end_comment

begin_define
define|#
directive|define
name|MT_WRITEGCR
value|000062
end_define

begin_comment
comment|/* write group coded */
end_comment

begin_define
define|#
directive|define
name|MT_READ
value|000070
end_define

begin_comment
comment|/* read forward */
end_comment

begin_define
define|#
directive|define
name|MT_EXSNS
value|000072
end_define

begin_comment
comment|/* read extended sense error log */
end_comment

begin_define
define|#
directive|define
name|MT_READREV
value|000076
end_define

begin_comment
comment|/* read reverse */
end_comment

begin_define
define|#
directive|define
name|MT_GCR
value|000002
end_define

begin_comment
comment|/* make generic ops GCR ops */
end_comment

begin_comment
comment|/* mtds */
end_comment

begin_define
define|#
directive|define
name|MTDS_RDY
value|0100000
end_define

begin_comment
comment|/* tape ready */
end_comment

begin_define
define|#
directive|define
name|MTDS_PRES
value|0040000
end_define

begin_comment
comment|/* tape unit has power */
end_comment

begin_define
define|#
directive|define
name|MTDS_ONL
value|0020000
end_define

begin_comment
comment|/* online */
end_comment

begin_define
define|#
directive|define
name|MTDS_REW
value|0010000
end_define

begin_comment
comment|/* tape rewinding */
end_comment

begin_define
define|#
directive|define
name|MTDS_PE
value|0004000
end_define

begin_comment
comment|/* tape set for phase encoded */
end_comment

begin_define
define|#
directive|define
name|MTDS_BOT
value|0002000
end_define

begin_comment
comment|/* tape at BOT */
end_comment

begin_define
define|#
directive|define
name|MTDS_EOT
value|0001000
end_define

begin_comment
comment|/* tape at EOT */
end_comment

begin_define
define|#
directive|define
name|MTDS_FPT
value|0000400
end_define

begin_comment
comment|/* write protected */
end_comment

begin_define
define|#
directive|define
name|MTDS_AVAIL
value|0000200
end_define

begin_comment
comment|/* unit available */
end_comment

begin_define
define|#
directive|define
name|MTDS_SHR
value|0000100
end_define

begin_comment
comment|/* unit is shared */
end_comment

begin_define
define|#
directive|define
name|MTDS_MAINT
value|0000040
end_define

begin_comment
comment|/* maintenance mode */
end_comment

begin_define
define|#
directive|define
name|MTDS_DSE
value|0000020
end_define

begin_comment
comment|/* DSE in progress */
end_comment

begin_define
define|#
directive|define
name|MTDS_BITS
define|\
value|"\10\20RDY\17PRES\16ONL\15REW\14PE\13BOT\12EOT\11FPT\10AVAIL\ \7SHR\6MAINT\5DSE"
end_define

begin_comment
comment|/* mter */
end_comment

begin_define
define|#
directive|define
name|MTER_INTCODE
value|0377
end_define

begin_comment
comment|/* mask for interrupt code */
end_comment

begin_define
define|#
directive|define
name|MTER_FAILCODE
value|0176000
end_define

begin_comment
comment|/* failure code */
end_comment

begin_define
define|#
directive|define
name|MTER_FSHIFT
value|10
end_define

begin_comment
comment|/* shift to make units */
end_comment

begin_comment
comment|/* interrupt codes */
end_comment

begin_define
define|#
directive|define
name|MTER_DONE
value|001
end_define

begin_comment
comment|/* operation complete */
end_comment

begin_define
define|#
directive|define
name|MTER_TM
value|002
end_define

begin_comment
comment|/* unexpected tape mark */
end_comment

begin_define
define|#
directive|define
name|MTER_BOT
value|003
end_define

begin_comment
comment|/* unexpected BOT detected */
end_comment

begin_define
define|#
directive|define
name|MTER_EOT
value|004
end_define

begin_comment
comment|/* tape positioned beyond EOT */
end_comment

begin_define
define|#
directive|define
name|MTER_LEOT
value|005
end_define

begin_comment
comment|/* unexpected LEOT detected */
end_comment

begin_define
define|#
directive|define
name|MTER_NOOP
value|006
end_define

begin_comment
comment|/* no-op completed */
end_comment

begin_define
define|#
directive|define
name|MTER_RWDING
value|007
end_define

begin_comment
comment|/* rewinding */
end_comment

begin_define
define|#
directive|define
name|MTER_FPT
value|010
end_define

begin_comment
comment|/* write protect error */
end_comment

begin_define
define|#
directive|define
name|MTER_NOTRDY
value|011
end_define

begin_comment
comment|/* not ready */
end_comment

begin_define
define|#
directive|define
name|MTER_NOTAVL
value|012
end_define

begin_comment
comment|/* not available */
end_comment

begin_define
define|#
directive|define
name|MTER_OFFLINE
value|013
end_define

begin_comment
comment|/* offline */
end_comment

begin_define
define|#
directive|define
name|MTER_NONEX
value|014
end_define

begin_comment
comment|/* unit does not exist */
end_comment

begin_define
define|#
directive|define
name|MTER_NOTCAP
value|015
end_define

begin_comment
comment|/* not capable */
end_comment

begin_define
define|#
directive|define
name|MTER_ONLINE
value|017
end_define

begin_comment
comment|/* tape came online */
end_comment

begin_define
define|#
directive|define
name|MTER_LONGREC
value|020
end_define

begin_comment
comment|/* long tape record */
end_comment

begin_define
define|#
directive|define
name|MTER_SHRTREC
value|021
end_define

begin_comment
comment|/* short tape record */
end_comment

begin_define
define|#
directive|define
name|MTER_RETRY
value|022
end_define

begin_comment
comment|/* retry */
end_comment

begin_define
define|#
directive|define
name|MTER_RDOPP
value|023
end_define

begin_comment
comment|/* read opposite */
end_comment

begin_define
define|#
directive|define
name|MTER_UNREAD
value|024
end_define

begin_comment
comment|/* unreadable */
end_comment

begin_define
define|#
directive|define
name|MTER_ERROR
value|025
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|MTER_EOTERR
value|026
end_define

begin_comment
comment|/* EOT error */
end_comment

begin_define
define|#
directive|define
name|MTER_BADTAPE
value|027
end_define

begin_comment
comment|/* tape position lost */
end_comment

begin_define
define|#
directive|define
name|MTER_TMFLTA
value|030
end_define

begin_comment
comment|/* TM fault A */
end_comment

begin_define
define|#
directive|define
name|MTER_TUFLTA
value|031
end_define

begin_comment
comment|/* TU fault A */
end_comment

begin_define
define|#
directive|define
name|MTER_TMFLTB
value|032
end_define

begin_comment
comment|/* TM fault B */
end_comment

begin_define
define|#
directive|define
name|MTER_MBFLT
value|034
end_define

begin_comment
comment|/* Massbus fault */
end_comment

begin_define
define|#
directive|define
name|MTER_KEYFAIL
value|077
end_define

begin_comment
comment|/* keypad entry error */
end_comment

begin_comment
comment|/* mtdt */
end_comment

begin_define
define|#
directive|define
name|MTDT_NSA
value|0100000
end_define

begin_comment
comment|/* not sector addressed; always 1 */
end_comment

begin_define
define|#
directive|define
name|MTDT_TAP
value|0040000
end_define

begin_comment
comment|/* tape; always 1 */
end_comment

begin_define
define|#
directive|define
name|MTDT_MOH
value|0020000
end_define

begin_comment
comment|/* moving head; always 0 */
end_comment

begin_define
define|#
directive|define
name|MTDT_7CH
value|0010000
end_define

begin_comment
comment|/* 7 channel; always 0 */
end_comment

begin_define
define|#
directive|define
name|MTDT_DRQ
value|0004000
end_define

begin_comment
comment|/* drive request required */
end_comment

begin_define
define|#
directive|define
name|MTDT_SPR
value|0002000
end_define

begin_comment
comment|/* slave present; always 1 ??? */
end_comment

begin_comment
comment|/* bit 9 is spare */
end_comment

begin_comment
comment|/* bits 8-0 are formatter/transport type */
end_comment

begin_comment
comment|/* mtid */
end_comment

begin_define
define|#
directive|define
name|MTID_RDY
value|0100000
end_define

begin_comment
comment|/* controller ready */
end_comment

begin_define
define|#
directive|define
name|MTID_CLR
value|0040000
end_define

begin_comment
comment|/* controller clear */
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

