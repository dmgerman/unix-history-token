begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dzreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * DZ-11/DZ-32 Registers and bits.  */
end_comment

begin_struct
struct|struct
name|dzdevice
block|{
name|short
name|dzcsr
decl_stmt|;
name|short
name|dzrbuf
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|char
name|dztcr0
decl_stmt|;
name|char
name|dzdtr0
decl_stmt|;
name|char
name|dztbuf0
decl_stmt|;
name|char
name|dzbrk0
decl_stmt|;
block|}
name|dz11
struct|;
struct|struct
block|{
name|short
name|dzlcs0
decl_stmt|;
name|char
name|dztbuf0
decl_stmt|;
name|char
name|dzlnen0
decl_stmt|;
block|}
name|dz32
struct|;
block|}
name|dzun
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dzlpr
value|dzrbuf
end_define

begin_define
define|#
directive|define
name|dzmsr
value|dzun.dz11.dzbrk0
end_define

begin_define
define|#
directive|define
name|dztcr
value|dzun.dz11.dztcr0
end_define

begin_define
define|#
directive|define
name|dzdtr
value|dzun.dz11.dzdtr0
end_define

begin_define
define|#
directive|define
name|dztbuf
value|dzun.dz11.dztbuf0
end_define

begin_define
define|#
directive|define
name|dzlcs
value|dzun.dz32.dzlcs0
end_define

begin_define
define|#
directive|define
name|dzbrk
value|dzmsr
end_define

begin_define
define|#
directive|define
name|dzlnen
value|dzun.dz32.dzlnen0
end_define

begin_define
define|#
directive|define
name|dzmtsr
value|dzun.dz32.dztbuf0
end_define

begin_comment
comment|/* bits in dzlpr */
end_comment

begin_define
define|#
directive|define
name|BITS7
value|0020
end_define

begin_define
define|#
directive|define
name|BITS8
value|0030
end_define

begin_define
define|#
directive|define
name|TWOSB
value|0040
end_define

begin_define
define|#
directive|define
name|PENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|OPAR
value|0200
end_define

begin_comment
comment|/* bits in dzrbuf */
end_comment

begin_define
define|#
directive|define
name|DZ_PE
value|010000
end_define

begin_define
define|#
directive|define
name|DZ_FE
value|020000
end_define

begin_define
define|#
directive|define
name|DZ_DO
value|040000
end_define

begin_comment
comment|/* bits in dzcsr */
end_comment

begin_define
define|#
directive|define
name|DZ_32
value|000001
end_define

begin_comment
comment|/* DZ32 mode */
end_comment

begin_define
define|#
directive|define
name|DZ_MIE
value|000002
end_define

begin_comment
comment|/* Modem Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_CLR
value|000020
end_define

begin_comment
comment|/* Reset dz */
end_comment

begin_define
define|#
directive|define
name|DZ_MSE
value|000040
end_define

begin_comment
comment|/* Master Scan Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_RIE
value|000100
end_define

begin_comment
comment|/* Receiver Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_MSC
value|004000
end_define

begin_comment
comment|/* Modem Status Change */
end_comment

begin_define
define|#
directive|define
name|DZ_SAE
value|010000
end_define

begin_comment
comment|/* Silo Alarm Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_TIE
value|040000
end_define

begin_comment
comment|/* Transmit Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_IEN
value|(DZ_32|DZ_MIE|DZ_MSE|DZ_RIE|DZ_TIE)
end_define

begin_comment
comment|/* flags for modem-control */
end_comment

begin_define
define|#
directive|define
name|DZ_ON
value|DZ_DTR
end_define

begin_define
define|#
directive|define
name|DZ_OFF
value|0
end_define

begin_comment
comment|/* bits in dzlcs */
end_comment

begin_define
define|#
directive|define
name|DZ_ACK
value|0100000
end_define

begin_comment
comment|/* ACK bit in dzlcs */
end_comment

begin_define
define|#
directive|define
name|DZ_RTS
value|0010000
end_define

begin_comment
comment|/* Request To Send */
end_comment

begin_define
define|#
directive|define
name|DZ_ST
value|0004000
end_define

begin_comment
comment|/* Secondary Transmit */
end_comment

begin_define
define|#
directive|define
name|DZ_BRK
value|0002000
end_define

begin_comment
comment|/* Break */
end_comment

begin_define
define|#
directive|define
name|DZ_DTR
value|0001000
end_define

begin_comment
comment|/* Data Terminal Ready */
end_comment

begin_define
define|#
directive|define
name|DZ_LE
value|0000400
end_define

begin_comment
comment|/* Line Enable */
end_comment

begin_define
define|#
directive|define
name|DZ_DSR
value|0000200
end_define

begin_comment
comment|/* Data Set Ready */
end_comment

begin_define
define|#
directive|define
name|DZ_RI
value|0000100
end_define

begin_comment
comment|/* Ring Indicate */
end_comment

begin_define
define|#
directive|define
name|DZ_CD
value|0000040
end_define

begin_comment
comment|/* Carrier Detect */
end_comment

begin_define
define|#
directive|define
name|DZ_CTS
value|0000020
end_define

begin_comment
comment|/* Clear To Send */
end_comment

begin_define
define|#
directive|define
name|DZ_SR
value|0000010
end_define

begin_comment
comment|/* Secondary Receive */
end_comment

begin_comment
comment|/* bits in dm lsr, copied from dmreg.h */
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
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

end_unit

