begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tsreg.h	7.2 (Berkeley) 11/3/87  */
end_comment

begin_comment
comment|/*  * TS11 controller registers  */
end_comment

begin_struct
struct|struct
name|tsdevice
block|{
name|u_short
name|tsdb
decl_stmt|;
comment|/* data buffer */
name|u_short
name|tssr
decl_stmt|;
comment|/* status register */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits in (unibus) status register */
end_comment

begin_define
define|#
directive|define
name|TS_SC
value|0100000
end_define

begin_comment
comment|/* special condition (error) */
end_comment

begin_define
define|#
directive|define
name|TS_UPE
value|0040000
end_define

begin_comment
comment|/* Unibus parity error */
end_comment

begin_define
define|#
directive|define
name|TS_SPE
value|0020000
end_define

begin_comment
comment|/* serial bus parity error */
end_comment

begin_define
define|#
directive|define
name|TS_RMR
value|0010000
end_define

begin_comment
comment|/* register modification refused */
end_comment

begin_define
define|#
directive|define
name|TS_NXM
value|0004000
end_define

begin_comment
comment|/* nonexistant memory */
end_comment

begin_define
define|#
directive|define
name|TS_NBA
value|0002000
end_define

begin_comment
comment|/* need buffer address */
end_comment

begin_define
define|#
directive|define
name|TS_XMEM
value|0001400
end_define

begin_comment
comment|/* Unibus xmem bits */
end_comment

begin_define
define|#
directive|define
name|TS_SSR
value|0000200
end_define

begin_comment
comment|/* subsytem ready */
end_comment

begin_define
define|#
directive|define
name|TS_OFL
value|0000100
end_define

begin_comment
comment|/* off-line */
end_comment

begin_define
define|#
directive|define
name|TS_FTC
value|0000060
end_define

begin_comment
comment|/* fatal termination class */
end_comment

begin_define
define|#
directive|define
name|TS_TC
value|0000016
end_define

begin_comment
comment|/* termination class */
end_comment

begin_define
define|#
directive|define
name|TS_SUCC
value|000
end_define

begin_comment
comment|/* successful termination */
end_comment

begin_define
define|#
directive|define
name|TS_ATTN
value|002
end_define

begin_comment
comment|/* attention */
end_comment

begin_define
define|#
directive|define
name|TS_ALERT
value|004
end_define

begin_comment
comment|/* tape status alert */
end_comment

begin_define
define|#
directive|define
name|TS_REJECT
value|06
end_define

begin_comment
comment|/* function reject */
end_comment

begin_define
define|#
directive|define
name|TS_RECOV
value|010
end_define

begin_comment
comment|/* recoverable error */
end_comment

begin_define
define|#
directive|define
name|TS_RECNM
value|012
end_define

begin_comment
comment|/* recoverable error, no tape motion */
end_comment

begin_define
define|#
directive|define
name|TS_UNREC
value|014
end_define

begin_comment
comment|/* unrecoverable error */
end_comment

begin_define
define|#
directive|define
name|TS_FATAL
value|016
end_define

begin_comment
comment|/* fatal error */
end_comment

begin_define
define|#
directive|define
name|TSSR_BITS
define|\
value|"\10\20SC\17UPE\16SPE\15RMR\14NXM\13NBA\12A17\11A16\10SSR\ \7OFL\6FC1\5FC0\4TC2\3TC1\2TC0\1-"
end_define

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

begin_comment
comment|/* status message */
end_comment

begin_struct
struct|struct
name|ts_sts
block|{
name|u_short
name|s_sts
decl_stmt|;
comment|/* packet header */
name|u_short
name|s_len
decl_stmt|;
comment|/* packet length */
name|u_short
name|s_rbpcr
decl_stmt|;
comment|/* residual frame count */
name|u_short
name|s_xs0
decl_stmt|;
comment|/* extended status 0 - 3 */
name|u_short
name|s_xs1
decl_stmt|;
name|u_short
name|s_xs2
decl_stmt|;
name|u_short
name|s_xs3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Error codes in xstat 0 */
end_comment

begin_define
define|#
directive|define
name|TS_TMK
value|0100000
end_define

begin_comment
comment|/* tape mark detected */
end_comment

begin_define
define|#
directive|define
name|TS_RLS
value|0040000
end_define

begin_comment
comment|/* record length short */
end_comment

begin_define
define|#
directive|define
name|TS_LET
value|0020000
end_define

begin_comment
comment|/* logical end of tape */
end_comment

begin_define
define|#
directive|define
name|TS_RLL
value|0010000
end_define

begin_comment
comment|/* record length long */
end_comment

begin_define
define|#
directive|define
name|TS_WLE
value|0004000
end_define

begin_comment
comment|/* write lock error */
end_comment

begin_define
define|#
directive|define
name|TS_NEF
value|0002000
end_define

begin_comment
comment|/* non-executable function */
end_comment

begin_define
define|#
directive|define
name|TS_ILC
value|0001000
end_define

begin_comment
comment|/* illegal command */
end_comment

begin_define
define|#
directive|define
name|TS_ILA
value|0000400
end_define

begin_comment
comment|/* illegal address */
end_comment

begin_define
define|#
directive|define
name|TS_MOT
value|0000200
end_define

begin_comment
comment|/* capstan is moving */
end_comment

begin_define
define|#
directive|define
name|TS_ONL
value|0000100
end_define

begin_comment
comment|/* on-line */
end_comment

begin_define
define|#
directive|define
name|TS_IES
value|0000040
end_define

begin_comment
comment|/* interrupt enable status */
end_comment

begin_define
define|#
directive|define
name|TS_VCK
value|0000020
end_define

begin_comment
comment|/* volume check */
end_comment

begin_define
define|#
directive|define
name|TS_PED
value|0000010
end_define

begin_comment
comment|/* phase-encoded drive */
end_comment

begin_define
define|#
directive|define
name|TS_WLK
value|0000004
end_define

begin_comment
comment|/* write locked */
end_comment

begin_define
define|#
directive|define
name|TS_BOT
value|0000002
end_define

begin_comment
comment|/* beginning of tape */
end_comment

begin_define
define|#
directive|define
name|TS_EOT
value|0000001
end_define

begin_comment
comment|/* end of tape */
end_comment

begin_define
define|#
directive|define
name|TSXS0_BITS
define|\
value|"\10\20TMK\17RLS\16LET\15RLL\14WLE\13NEF\12ILC\11ILA\10MOT\ \7ONL\6IES\5VCK\4PED\3WLK\2BOT\1EOT"
end_define

begin_comment
comment|/* Error codes in xstat 1 */
end_comment

begin_define
define|#
directive|define
name|TS_DLT
value|0100000
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|TS_COR
value|0020000
end_define

begin_comment
comment|/* correctable data */
end_comment

begin_define
define|#
directive|define
name|TS_CRS
value|0010000
end_define

begin_comment
comment|/* crease detected */
end_comment

begin_define
define|#
directive|define
name|TS_TIG
value|0004000
end_define

begin_comment
comment|/* trash in the gap */
end_comment

begin_define
define|#
directive|define
name|TS_DBF
value|0002000
end_define

begin_comment
comment|/* deskew buffer full */
end_comment

begin_define
define|#
directive|define
name|TS_SCK
value|0001000
end_define

begin_comment
comment|/* speed check */
end_comment

begin_define
define|#
directive|define
name|TS_IPR
value|0000200
end_define

begin_comment
comment|/* invalid preamble */
end_comment

begin_define
define|#
directive|define
name|TS_SYN
value|0000100
end_define

begin_comment
comment|/* synchronization failure */
end_comment

begin_define
define|#
directive|define
name|TS_IPO
value|0000040
end_define

begin_comment
comment|/* invalid postamble */
end_comment

begin_define
define|#
directive|define
name|TS_IED
value|0000020
end_define

begin_comment
comment|/* invalid end of data */
end_comment

begin_define
define|#
directive|define
name|TS_POS
value|0000010
end_define

begin_comment
comment|/* postamble short */
end_comment

begin_define
define|#
directive|define
name|TS_POL
value|0000004
end_define

begin_comment
comment|/* postamble long */
end_comment

begin_define
define|#
directive|define
name|TS_UNC
value|0000002
end_define

begin_comment
comment|/* uncorrectable data */
end_comment

begin_define
define|#
directive|define
name|TS_MTE
value|0000001
end_define

begin_comment
comment|/* multitrack error */
end_comment

begin_define
define|#
directive|define
name|TSXS1_BITS
define|\
value|"\10\20DLT\17-\16COR\15CRS\14TIG\13DBF\12SCK\11-\10IPR\ \7SYN\6IPO\5IED\4POS\3POL\2UNC\1MTE"
end_define

begin_comment
comment|/* Error codes in xstat 2 */
end_comment

begin_define
define|#
directive|define
name|TS_OPM
value|0100000
end_define

begin_comment
comment|/* operation in progress */
end_comment

begin_define
define|#
directive|define
name|TS_SIP
value|0040000
end_define

begin_comment
comment|/* silo parity error */
end_comment

begin_define
define|#
directive|define
name|TS_BPE
value|0020000
end_define

begin_comment
comment|/* serial bus parity error */
end_comment

begin_define
define|#
directive|define
name|TS_CAF
value|0010000
end_define

begin_comment
comment|/* capstan acceleration failure */
end_comment

begin_define
define|#
directive|define
name|TS_WCF
value|0002000
end_define

begin_comment
comment|/* write card fail */
end_comment

begin_define
define|#
directive|define
name|TS_DTP
value|0000400
end_define

begin_comment
comment|/* dead track parity */
end_comment

begin_define
define|#
directive|define
name|TS_DT
value|0000377
end_define

begin_comment
comment|/* dead tracks */
end_comment

begin_define
define|#
directive|define
name|TSXS2_BITS
define|\
value|"\10\20OPM\17SIP\16BPE\15CAF\14-\13WCF\12-\11DTP"
end_define

begin_comment
comment|/* Error codes in xstat 3 */
end_comment

begin_define
define|#
directive|define
name|TS_MEC
value|0177400
end_define

begin_comment
comment|/* microdiagnostic error code */
end_comment

begin_define
define|#
directive|define
name|TS_LMX
value|0000200
end_define

begin_comment
comment|/* limit exceeded */
end_comment

begin_define
define|#
directive|define
name|TS_OPI
value|0000100
end_define

begin_comment
comment|/* operation incomplete */
end_comment

begin_define
define|#
directive|define
name|TS_REV
value|0000040
end_define

begin_comment
comment|/* reverse */
end_comment

begin_define
define|#
directive|define
name|TS_CRF
value|0000020
end_define

begin_comment
comment|/* capstan response fail */
end_comment

begin_define
define|#
directive|define
name|TS_DCK
value|0000010
end_define

begin_comment
comment|/* density check */
end_comment

begin_define
define|#
directive|define
name|TS_NOI
value|0000004
end_define

begin_comment
comment|/* noise record */
end_comment

begin_define
define|#
directive|define
name|TS_LXS
value|0000002
end_define

begin_comment
comment|/* limit exceeded statically */
end_comment

begin_define
define|#
directive|define
name|TS_RIB
value|0000001
end_define

begin_comment
comment|/* reverse into BOT */
end_comment

begin_define
define|#
directive|define
name|TSXS3_BITS
define|\
value|"\10\10LMX\7OPI\6REV\5CRF\4DCK\3NOI\2LXS\1RIB"
end_define

begin_comment
comment|/* command message */
end_comment

begin_struct
struct|struct
name|ts_cmd
block|{
name|u_short
name|c_cmd
decl_stmt|;
comment|/* command */
name|u_short
name|c_loba
decl_stmt|;
comment|/* low order buffer address */
name|u_short
name|c_hiba
decl_stmt|;
comment|/* high order buffer address */
define|#
directive|define
name|c_repcnt
value|c_loba
name|u_short
name|c_size
decl_stmt|;
comment|/* byte count */
block|}
struct|;
end_struct

begin_comment
comment|/* commands and command bits */
end_comment

begin_define
define|#
directive|define
name|TS_ACK
value|0100000
end_define

begin_comment
comment|/* ack - release command packet */
end_comment

begin_define
define|#
directive|define
name|TS_CVC
value|0040000
end_define

begin_comment
comment|/* clear volume check */
end_comment

begin_define
define|#
directive|define
name|TS_IE
value|0000200
end_define

begin_define
define|#
directive|define
name|TS_RCOM
value|0000001
end_define

begin_define
define|#
directive|define
name|TS_REREAD
value|0001001
end_define

begin_comment
comment|/* read data retry */
end_comment

begin_define
define|#
directive|define
name|TS_SETCHR
value|0000004
end_define

begin_comment
comment|/* set characteristics */
end_comment

begin_define
define|#
directive|define
name|TS_WCOM
value|0000005
end_define

begin_define
define|#
directive|define
name|TS_REWRITE
value|0001005
end_define

begin_comment
comment|/* write data retry */
end_comment

begin_define
define|#
directive|define
name|TS_RETRY
value|0001000
end_define

begin_comment
comment|/* retry bit for read and write */
end_comment

begin_define
define|#
directive|define
name|TS_SFORW
value|0000010
end_define

begin_comment
comment|/* forward space record */
end_comment

begin_define
define|#
directive|define
name|TS_SREV
value|0000410
end_define

begin_comment
comment|/* reverse space record */
end_comment

begin_define
define|#
directive|define
name|TS_SFORWF
value|0001010
end_define

begin_comment
comment|/* forward space file */
end_comment

begin_define
define|#
directive|define
name|TS_SREVF
value|0001410
end_define

begin_comment
comment|/* reverse space file */
end_comment

begin_define
define|#
directive|define
name|TS_REW
value|0002010
end_define

begin_comment
comment|/* rewind */
end_comment

begin_define
define|#
directive|define
name|TS_OFFL
value|0000412
end_define

begin_comment
comment|/* unload */
end_comment

begin_define
define|#
directive|define
name|TS_WEOF
value|0000011
end_define

begin_comment
comment|/* write tape mark */
end_comment

begin_define
define|#
directive|define
name|TS_SENSE
value|0000017
end_define

begin_comment
comment|/* get status */
end_comment

begin_comment
comment|/* characteristics data */
end_comment

begin_struct
struct|struct
name|ts_char
block|{
name|long
name|char_addr
decl_stmt|;
comment|/* address of status packet */
name|u_short
name|char_size
decl_stmt|;
comment|/* its size */
name|u_short
name|char_mode
decl_stmt|;
comment|/* characteristics */
block|}
struct|;
end_struct

begin_comment
comment|/* characteristics */
end_comment

begin_define
define|#
directive|define
name|TS_ESS
value|0200
end_define

begin_comment
comment|/* enable skip tape marks stop */
end_comment

begin_define
define|#
directive|define
name|TS_ENB
value|0100
end_define

begin_comment
comment|/* enable skip stop BOT */
end_comment

begin_define
define|#
directive|define
name|TS_EAI
value|0040
end_define

begin_comment
comment|/* enable attention interrupts */
end_comment

begin_define
define|#
directive|define
name|TS_ERI
value|0020
end_define

begin_comment
comment|/* enable message buffer release interrupts */
end_comment

begin_comment
comment|/* Emulex TC13 only */
end_comment

begin_define
define|#
directive|define
name|TS_NRZI
value|0001
end_define

begin_comment
comment|/* select NRZI (800bpi) rather than PE */
end_comment

end_unit

