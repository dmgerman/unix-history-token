begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_accreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * ACC LH/DH-11 interface  */
end_comment

begin_struct
struct|struct
name|accdma
block|{
name|short
name|csr
decl_stmt|;
comment|/* control and status */
name|short
name|db
decl_stmt|;
comment|/* data buffer */
name|u_short
name|ba
decl_stmt|;
comment|/* buss address */
name|short
name|wc
decl_stmt|;
comment|/* word count */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|accdevice
block|{
name|struct
name|accdma
name|input
decl_stmt|;
name|struct
name|accdma
name|output
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|icsr
value|input.csr
end_define

begin_define
define|#
directive|define
name|iba
value|input.ba
end_define

begin_define
define|#
directive|define
name|iwc
value|input.wc
end_define

begin_define
define|#
directive|define
name|ocsr
value|output.csr
end_define

begin_define
define|#
directive|define
name|oba
value|output.ba
end_define

begin_define
define|#
directive|define
name|owc
value|output.wc
end_define

begin_comment
comment|/*  * Bits Common to both input and out CSR's  */
end_comment

begin_define
define|#
directive|define
name|ACC_ERR
value|0x8000
end_define

begin_comment
comment|/* error present */
end_comment

begin_define
define|#
directive|define
name|ACC_NXM
value|0x4000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|ACC_RDY
value|0x0080
end_define

begin_comment
comment|/* ready */
end_comment

begin_define
define|#
directive|define
name|ACC_IE
value|0x0040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|ACC_RESET
value|0x0002
end_define

begin_comment
comment|/* reset interface */
end_comment

begin_define
define|#
directive|define
name|ACC_GO
value|0x0001
end_define

begin_comment
comment|/* start operation */
end_comment

begin_comment
comment|/*  * Input Control Status Register  */
end_comment

begin_define
define|#
directive|define
name|IN_EOM
value|0x2000
end_define

begin_comment
comment|/* end-of-message recieved */
end_comment

begin_define
define|#
directive|define
name|IN_HRDY
value|0x0800
end_define

begin_comment
comment|/* host ready */
end_comment

begin_define
define|#
directive|define
name|IN_IMPBSY
value|0x0400
end_define

begin_comment
comment|/* IMP not ready */
end_comment

begin_define
define|#
directive|define
name|IN_RMR
value|0x0200
end_define

begin_comment
comment|/* receive master ready error */
end_comment

begin_define
define|#
directive|define
name|IN_IBF
value|0x0100
end_define

begin_comment
comment|/* input data buffer full */
end_comment

begin_define
define|#
directive|define
name|IN_WEN
value|0x0008
end_define

begin_comment
comment|/* write enable */
end_comment

begin_define
define|#
directive|define
name|IN_MRDY
value|0x0004
end_define

begin_comment
comment|/* master ready */
end_comment

begin_define
define|#
directive|define
name|ACC_INBITS
define|\
value|"\20\20ERR\17NXM\16EOM\14HRDY\13IMPBSY\12RMR\11IBF\10RDY\7IE\ \4WEN\3MRDY\2RESET\1GO"
end_define

begin_comment
comment|/*  * Output Control Status Register  */
end_comment

begin_define
define|#
directive|define
name|OUT_TMR
value|0x0200
end_define

begin_comment
comment|/* transmit master ready error */
end_comment

begin_define
define|#
directive|define
name|OUT_BBACK
value|0x0008
end_define

begin_comment
comment|/* bus back */
end_comment

begin_define
define|#
directive|define
name|OUT_ENLB
value|0x0004
end_define

begin_comment
comment|/* enable last bit */
end_comment

begin_define
define|#
directive|define
name|ACC_OUTBITS
define|\
value|"\20\20ERR\17NXM\12TMR\10RDY\7IE\4BBACK\3ENLB\2RESET\1GO"
end_define

end_unit

