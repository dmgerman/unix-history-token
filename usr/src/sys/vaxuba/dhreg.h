begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dhreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*   * DH-11 device register definitions.  */
end_comment

begin_struct
struct|struct
name|dhdevice
block|{
union|union
block|{
name|short
name|dhcsr
decl_stmt|;
comment|/* control-status register */
name|char
name|dhcsrl
decl_stmt|;
comment|/* low byte for line select */
block|}
name|un
union|;
name|short
name|dhrcr
decl_stmt|;
comment|/* receive character register */
name|short
name|dhlpr
decl_stmt|;
comment|/* line parameter register */
name|u_short
name|dhcar
decl_stmt|;
comment|/* current address register */
name|short
name|dhbcr
decl_stmt|;
comment|/* byte count register */
name|u_short
name|dhbar
decl_stmt|;
comment|/* buffer active register */
name|short
name|dhbreak
decl_stmt|;
comment|/* break control register */
name|short
name|dhsilo
decl_stmt|;
comment|/* silo status register */
block|}
struct|;
end_struct

begin_comment
comment|/* Bits in dhcsr */
end_comment

begin_define
define|#
directive|define
name|DH_TI
value|0100000
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|DH_SI
value|0040000
end_define

begin_comment
comment|/* storage interrupt */
end_comment

begin_define
define|#
directive|define
name|DH_TIE
value|0020000
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DH_SIE
value|0010000
end_define

begin_comment
comment|/* storage interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DH_MC
value|0004000
end_define

begin_comment
comment|/* master clear */
end_comment

begin_define
define|#
directive|define
name|DH_NXM
value|0002000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|DH_MM
value|0001000
end_define

begin_comment
comment|/* maintenance mode */
end_comment

begin_define
define|#
directive|define
name|DH_CNI
value|0000400
end_define

begin_comment
comment|/* clear non-existant memory interrupt */
end_comment

begin_define
define|#
directive|define
name|DH_RI
value|0000200
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|DH_RIE
value|0000100
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_comment
comment|/* Bits in dhlpr */
end_comment

begin_define
define|#
directive|define
name|BITS6
value|01
end_define

begin_define
define|#
directive|define
name|BITS7
value|02
end_define

begin_define
define|#
directive|define
name|BITS8
value|03
end_define

begin_define
define|#
directive|define
name|TWOSB
value|04
end_define

begin_define
define|#
directive|define
name|PENABLE
value|020
end_define

begin_comment
comment|/* DEC manuals incorrectly say this bit causes generation of even parity. */
end_comment

begin_define
define|#
directive|define
name|OPAR
value|040
end_define

begin_define
define|#
directive|define
name|HDUPLX
value|040000
end_define

begin_define
define|#
directive|define
name|DH_IE
value|(DH_TIE|DH_SIE|DH_RIE)
end_define

begin_comment
comment|/* Bits in dhrcr */
end_comment

begin_define
define|#
directive|define
name|DH_PE
value|0010000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DH_FE
value|0020000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|DH_DO
value|0040000
end_define

begin_comment
comment|/* data overrun */
end_comment

end_unit

