begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cons.h	4.2	%G%	*/
end_comment

begin_comment
comment|/*  * VAX console interface registers  */
end_comment

begin_define
define|#
directive|define
name|RXCS_IE
value|0x40
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RXCS_DONE
value|0x80
end_define

begin_comment
comment|/* receiver done */
end_comment

begin_define
define|#
directive|define
name|RXDB_DATA
value|0xff
end_define

begin_comment
comment|/* received character */
end_comment

begin_define
define|#
directive|define
name|RXDB_ID
value|0xf00
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
value|0x40
end_define

begin_comment
comment|/* transmitter interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TXCS_RDY
value|0x80
end_define

begin_comment
comment|/* transmitter ready for next char */
end_comment

begin_define
define|#
directive|define
name|TXDB_DATA
value|0xff
end_define

begin_comment
comment|/* transmitter byte */
end_comment

begin_define
define|#
directive|define
name|TXDB_ID
value|0xf00
end_define

begin_comment
comment|/* channel id */
end_comment

begin_define
define|#
directive|define
name|TXDB_WSI
value|0xf02
end_define

begin_comment
comment|/* set warm start inhibit */
end_comment

begin_define
define|#
directive|define
name|TXDB_CWSI
value|0xf03
end_define

begin_comment
comment|/* clear warm start inhibit */
end_comment

begin_define
define|#
directive|define
name|TXDB_BOOT
value|0xf04
end_define

begin_comment
comment|/* enable boot */
end_comment

end_unit

