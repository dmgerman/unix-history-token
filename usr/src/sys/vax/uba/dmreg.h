begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * DM-11 device register definitions.  */
end_comment

begin_struct
struct|struct
name|dmdevice
block|{
name|short
name|dmcsr
decl_stmt|;
comment|/* control status register */
name|short
name|dmlstat
decl_stmt|;
comment|/* line status register */
name|short
name|dmpad1
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits in dm csr */
end_comment

begin_define
define|#
directive|define
name|DM_RF
value|0100000
end_define

begin_comment
comment|/* ring flag */
end_comment

begin_define
define|#
directive|define
name|DM_CF
value|0040000
end_define

begin_comment
comment|/* carrier flag */
end_comment

begin_define
define|#
directive|define
name|DM_CTS
value|0020000
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DM_SRF
value|0010000
end_define

begin_comment
comment|/* secondary receive flag */
end_comment

begin_define
define|#
directive|define
name|DM_CS
value|0004000
end_define

begin_comment
comment|/* clear scan */
end_comment

begin_define
define|#
directive|define
name|DM_CM
value|0002000
end_define

begin_comment
comment|/* clear multiplexor */
end_comment

begin_define
define|#
directive|define
name|DM_MM
value|0001000
end_define

begin_comment
comment|/* maintenance mode */
end_comment

begin_define
define|#
directive|define
name|DM_STP
value|0000400
end_define

begin_comment
comment|/* step */
end_comment

begin_define
define|#
directive|define
name|DM_DONE
value|0000200
end_define

begin_comment
comment|/* scanner is done */
end_comment

begin_define
define|#
directive|define
name|DM_IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DM_SE
value|0000040
end_define

begin_comment
comment|/* scan enable */
end_comment

begin_define
define|#
directive|define
name|DM_BUSY
value|0000020
end_define

begin_comment
comment|/* scan busy */
end_comment

begin_comment
comment|/* bits in dm lsr */
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

begin_define
define|#
directive|define
name|DML_ON
value|(DML_DTR|DML_RTS|DML_LE)
end_define

begin_define
define|#
directive|define
name|DML_OFF
value|(DML_LE)
end_define

end_unit

