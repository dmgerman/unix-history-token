begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)cons.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * VAX console interface registers  */
end_comment

begin_define
define|#
directive|define
name|RXCS_IE
value|0x00000040
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RXCS_DONE
value|0x00000080
end_define

begin_comment
comment|/* receiver done */
end_comment

begin_define
define|#
directive|define
name|RXDB_DATA
value|0x000000ff
end_define

begin_comment
comment|/* received character */
end_comment

begin_define
define|#
directive|define
name|RXDB_ID
value|0x00000f00
end_define

begin_comment
comment|/* channel id */
end_comment

begin_define
define|#
directive|define
name|RXDB_ERR
value|0x80000000
end_define

begin_comment
comment|/* receiver error */
end_comment

begin_define
define|#
directive|define
name|TXCS_IE
value|0x00000040
end_define

begin_comment
comment|/* transmitter interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TXCS_RDY
value|0x00000080
end_define

begin_comment
comment|/* transmitter ready for next char */
end_comment

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_define
define|#
directive|define
name|TXCS_ID
value|0x00000300
end_define

begin_comment
comment|/* interrupt ID field */
end_comment

begin_define
define|#
directive|define
name|TXCS_WMASK
value|0x00008000
end_define

begin_comment
comment|/* enable mask write */
end_comment

begin_define
define|#
directive|define
name|TXCS_TXMASK
value|0x00ff0000
end_define

begin_comment
comment|/* transmit enable channel mask: */
end_comment

begin_define
define|#
directive|define
name|TXCS_CTERM
value|0x00010000
end_define

begin_comment
comment|/*	console terminal */
end_comment

begin_define
define|#
directive|define
name|TXCS_RTERM
value|0x00020000
end_define

begin_comment
comment|/*	remote diagnostic port */
end_comment

begin_define
define|#
directive|define
name|TXCS_EMM
value|0x00040000
end_define

begin_comment
comment|/*	Environmental Monitor Module */
end_comment

begin_define
define|#
directive|define
name|TXCS_LCONS
value|0x00080000
end_define

begin_comment
comment|/*	Logical console */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TXDB_DATA
value|0x000000ff
end_define

begin_comment
comment|/* transmitter byte */
end_comment

begin_define
define|#
directive|define
name|TXDB_ID
value|0x00000f00
end_define

begin_comment
comment|/* channel id- not on 8600 */
end_comment

begin_define
define|#
directive|define
name|TXDB_CONS
value|0x00000f00
end_define

begin_comment
comment|/* channel id for console subsystem */
end_comment

begin_define
define|#
directive|define
name|TXDB_DONE
value|0x01
end_define

begin_comment
comment|/* software done */
end_comment

begin_define
define|#
directive|define
name|TXDB_BOOT
value|0x02
end_define

begin_comment
comment|/* reboot */
end_comment

begin_define
define|#
directive|define
name|TXDB_CWSI
value|0x03
end_define

begin_comment
comment|/* clear warm start inhibit */
end_comment

begin_define
define|#
directive|define
name|TXDB_CCSI
value|0x04
end_define

begin_comment
comment|/* clear cold-start inhibit */
end_comment

end_unit

