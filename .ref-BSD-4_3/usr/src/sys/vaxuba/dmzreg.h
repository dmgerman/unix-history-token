begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmzreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * HISTORY  * 23-Apr-85  Joe Camaratta (jcc) at Siemens RTL  *	Header file for DEC's DMZ32  */
end_comment

begin_struct
struct|struct
name|dmzdevice
block|{
name|short
name|dmz_config
decl_stmt|;
comment|/* configuration cntl and status register */
name|short
name|dmz_diag
decl_stmt|;
comment|/* diagnostic control and status register */
struct|struct
block|{
name|short
name|octet_csr
decl_stmt|;
comment|/* octet control and status */
name|short
name|octet_lprm
decl_stmt|;
comment|/* line parameter */
union|union
block|{
name|short
name|octet_rb
decl_stmt|;
comment|/* receiver buffer */
name|short
name|octet_rsp
decl_stmt|;
comment|/* receive silo parameter */
block|}
name|octet_receive
union|;
union|union
block|{
name|u_short
name|word
decl_stmt|;
comment|/* word */
name|u_char
name|bytes
index|[
literal|2
index|]
decl_stmt|;
comment|/* bytes */
block|}
name|octet_ir
union|;
comment|/* indirect registers */
block|}
name|octet
index|[
literal|3
index|]
struct|;
name|short
name|dmz_unused
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|octet_sato
value|octet_rsp
end_define

begin_comment
comment|/* aliases for asynchronous indirect control registers */
end_comment

begin_define
define|#
directive|define
name|IR_TBUF
value|000
end_define

begin_comment
comment|/* transmit character */
end_comment

begin_define
define|#
directive|define
name|IR_RMSTSC
value|000
end_define

begin_comment
comment|/* receive modem status, transmit silo count */
end_comment

begin_define
define|#
directive|define
name|IR_LCTMR
value|010
end_define

begin_comment
comment|/* line control and transmit modem */
end_comment

begin_define
define|#
directive|define
name|IR_TBA
value|020
end_define

begin_comment
comment|/* transmit buffer address register */
end_comment

begin_define
define|#
directive|define
name|IR_TCC
value|030
end_define

begin_comment
comment|/* transmit character count (DMA) */
end_comment

begin_define
define|#
directive|define
name|octet_tbf
value|octet_ir.bytes[0]
end_define

begin_comment
comment|/* transmit buffer */
end_comment

begin_define
define|#
directive|define
name|octet_tbf2
value|octet_ir.word
end_define

begin_comment
comment|/* transmit buffer, 2 chars */
end_comment

begin_define
define|#
directive|define
name|octet_rmstsc
value|octet_ir.word
end_define

begin_comment
comment|/* rcv modem status, xmit silo count */
end_comment

begin_define
define|#
directive|define
name|octet_lctmr
value|octet_ir.word
end_define

begin_comment
comment|/* line control, xmit modem */
end_comment

begin_define
define|#
directive|define
name|octet_tba
value|octet_ir.word
end_define

begin_comment
comment|/* transmit buffer address */
end_comment

begin_define
define|#
directive|define
name|octet_tcc
value|octet_ir.word
end_define

begin_comment
comment|/* transmit character count */
end_comment

begin_comment
comment|/* bits in octet_csr */
end_comment

begin_define
define|#
directive|define
name|DMZ_TRDY
value|0100000
end_define

begin_comment
comment|/* transmit ready */
end_comment

begin_define
define|#
directive|define
name|DMZ_TIE
value|0040000
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_NXM
value|0030000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|DMZ_LIN
value|0003400
end_define

begin_comment
comment|/* transmit line number */
end_comment

begin_define
define|#
directive|define
name|DMZ_RRDY
value|0000200
end_define

begin_comment
comment|/* receiver data available */
end_comment

begin_define
define|#
directive|define
name|DMZ_RIE
value|0000100
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_RESET
value|0000040
end_define

begin_comment
comment|/* master reset */
end_comment

begin_define
define|#
directive|define
name|DMZ_IAD
value|0000037
end_define

begin_comment
comment|/* indirect address register */
end_comment

begin_define
define|#
directive|define
name|DMZ_IE
value|(DMZ_TIE | DMZ_RIE)
end_define

begin_comment
comment|/* enable transmit and receive */
end_comment

begin_comment
comment|/* bits in octet_lprm (taken from dmfreg.h) */
end_comment

begin_define
define|#
directive|define
name|DMZ_6BT
value|0010
end_define

begin_comment
comment|/* 6 bits per character */
end_comment

begin_define
define|#
directive|define
name|DMZ_7BT
value|0020
end_define

begin_comment
comment|/* 7 bits per character */
end_comment

begin_define
define|#
directive|define
name|DMZ_8BT
value|0030
end_define

begin_comment
comment|/* 8 bits per character */
end_comment

begin_define
define|#
directive|define
name|DMZ_PEN
value|0040
end_define

begin_comment
comment|/* parity enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_EPR
value|0100
end_define

begin_comment
comment|/* even parity */
end_comment

begin_define
define|#
directive|define
name|DMZ_SCD
value|0200
end_define

begin_comment
comment|/* stop code */
end_comment

begin_define
define|#
directive|define
name|DMZ_XTE
value|0170000
end_define

begin_comment
comment|/* transmit rate */
end_comment

begin_define
define|#
directive|define
name|DMZ_RRT
value|0007400
end_define

begin_comment
comment|/* receive rate */
end_comment

begin_define
define|#
directive|define
name|DMZ_LSL
value|0000007
end_define

begin_comment
comment|/* line select */
end_comment

begin_comment
comment|/* baud rates */
end_comment

begin_define
define|#
directive|define
name|BR_50
value|000
end_define

begin_define
define|#
directive|define
name|BR_75
value|001
end_define

begin_define
define|#
directive|define
name|BR_110
value|002
end_define

begin_define
define|#
directive|define
name|BR_134_5
value|003
end_define

begin_define
define|#
directive|define
name|BR_150
value|004
end_define

begin_define
define|#
directive|define
name|BR_300
value|005
end_define

begin_define
define|#
directive|define
name|BR_600
value|006
end_define

begin_define
define|#
directive|define
name|BR_1200
value|007
end_define

begin_define
define|#
directive|define
name|BR_1800
value|010
end_define

begin_define
define|#
directive|define
name|BR_2000
value|011
end_define

begin_define
define|#
directive|define
name|BR_2400
value|012
end_define

begin_define
define|#
directive|define
name|BR_3600
value|013
end_define

begin_define
define|#
directive|define
name|BR_4800
value|014
end_define

begin_define
define|#
directive|define
name|BR_7200
value|015
end_define

begin_define
define|#
directive|define
name|BR_9600
value|016
end_define

begin_define
define|#
directive|define
name|BR_19200
value|017
end_define

begin_comment
comment|/* bits in octet_rb (taken from dmfreg.h) */
end_comment

begin_define
define|#
directive|define
name|DMZ_DSC
value|0004000
end_define

begin_comment
comment|/* data set change */
end_comment

begin_define
define|#
directive|define
name|DMZ_PE
value|0010000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DMZ_FE
value|0020000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|DMZ_DO
value|0040000
end_define

begin_comment
comment|/* data overrun */
end_comment

begin_define
define|#
directive|define
name|DMZ_DV
value|0100000
end_define

begin_comment
comment|/* data valid */
end_comment

begin_define
define|#
directive|define
name|DMZ_RL
value|0003400
end_define

begin_comment
comment|/* line */
end_comment

begin_define
define|#
directive|define
name|DMZ_RD
value|0000377
end_define

begin_comment
comment|/* data */
end_comment

begin_define
define|#
directive|define
name|DMZ_AT
value|0000377
end_define

begin_comment
comment|/* alarm timeout */
end_comment

begin_comment
comment|/* bits in dmz_rmstsc */
end_comment

begin_define
define|#
directive|define
name|DMZ_TSC
value|0x00ff
end_define

begin_comment
comment|/* transmit silo count */
end_comment

begin_define
define|#
directive|define
name|DMZ_USRR
value|0x0400
end_define

begin_comment
comment|/* user modem signal (pin 25) */
end_comment

begin_define
define|#
directive|define
name|DMF_SR
value|0x0800
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DMZ_CTS
value|0x1000
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DMZ_CAR
value|0x2000
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DMZ_RNG
value|0x4000
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DMZ_DSR
value|0x8000
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_comment
comment|/* bits in dmz_lctmr (tms half) */
end_comment

begin_define
define|#
directive|define
name|DMZ_USRW
value|0x0100
end_define

begin_comment
comment|/* user modem signal (pin 18) */
end_comment

begin_define
define|#
directive|define
name|DMZ_DTR
value|0x0200
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DMZ_RATE
value|0x0400
end_define

begin_comment
comment|/* data signal rate select */
end_comment

begin_define
define|#
directive|define
name|DMF_ST
value|0x0800
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DMZ_RTS
value|0x1000
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DMZ_PREEMPT
value|0x8000
end_define

begin_comment
comment|/* preempt output */
end_comment

begin_comment
comment|/* bits in octet_lctmr (lc half) */
end_comment

begin_define
define|#
directive|define
name|DMZ_MIE
value|0040
end_define

begin_comment
comment|/* modem interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_FLS
value|0020
end_define

begin_comment
comment|/* flush transmit silo */
end_comment

begin_define
define|#
directive|define
name|DMZ_BRK
value|0010
end_define

begin_comment
comment|/* send break bit */
end_comment

begin_define
define|#
directive|define
name|DMZ_RE
value|0004
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_AUT
value|0002
end_define

begin_comment
comment|/* auto XON/XOFF */
end_comment

begin_define
define|#
directive|define
name|DMZ_TE
value|0001
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|DMZ_CF
value|0300
end_define

begin_comment
comment|/* control function */
end_comment

begin_define
define|#
directive|define
name|DMZ_LCE
value|(DMZ_MIE|DMZ_RE|DMZ_TE)
end_define

begin_define
define|#
directive|define
name|DMZ_ON
value|(DMZ_DTR|DMZ_RTS|DMZ_LCE)
end_define

begin_define
define|#
directive|define
name|DMZ_OFF
value|DMZ_LCE
end_define

begin_comment
comment|/* bits in octet_tcc */
end_comment

begin_define
define|#
directive|define
name|DMZ_HA
value|0140000
end_define

begin_comment
comment|/* high address bits */
end_comment

begin_comment
comment|/* bits added to dm lsr for DMGET/DMSET */
end_comment

begin_define
define|#
directive|define
name|DML_USR
value|0001000
end_define

begin_comment
comment|/* usr modem sig, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DMZ_SIZ
value|32
end_define

begin_comment
comment|/* size of DMZ output silo (per line) */
end_comment

begin_define
define|#
directive|define
name|DMZ
parameter_list|(
name|a
parameter_list|)
value|(a/24)
end_define

begin_define
define|#
directive|define
name|OCTET
parameter_list|(
name|a
parameter_list|)
value|((a%24)/8)
end_define

begin_define
define|#
directive|define
name|LINE
parameter_list|(
name|a
parameter_list|)
value|((a%24)%8)
end_define

begin_define
define|#
directive|define
name|DMZ_NOC_MASK
value|03
end_define

begin_define
define|#
directive|define
name|DMZ_INTERFACE
value|000
end_define

end_unit

