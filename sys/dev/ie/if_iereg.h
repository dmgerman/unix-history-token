begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * definitions for AT&T StarLAN 10 etc...  */
end_comment

begin_define
define|#
directive|define
name|IEATT_RESET
value|0
end_define

begin_comment
comment|/* any write here resets the 586 */
end_comment

begin_define
define|#
directive|define
name|IEATT_ATTN
value|1
end_define

begin_comment
comment|/* any write here sends a Chan attn */
end_comment

begin_define
define|#
directive|define
name|IEATT_REVISION
value|6
end_define

begin_comment
comment|/* read here to figure out this board */
end_comment

begin_define
define|#
directive|define
name|IEATT_ATTRIB
value|7
end_define

begin_comment
comment|/* more information about this board */
end_comment

begin_define
define|#
directive|define
name|SL_BOARD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_define
define|#
directive|define
name|SL_REV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 4)
end_define

begin_define
define|#
directive|define
name|SL1_BOARD
value|0
end_define

begin_define
define|#
directive|define
name|SL10_BOARD
value|1
end_define

begin_define
define|#
directive|define
name|EN100_BOARD
value|2
end_define

begin_define
define|#
directive|define
name|SLFIBER_BOARD
value|3
end_define

begin_define
define|#
directive|define
name|SL_ATTR_WIDTH
value|0x04
end_define

begin_comment
comment|/* bus width: clear -> 8-bit */
end_comment

begin_define
define|#
directive|define
name|SL_ATTR_SPEED
value|0x08
end_define

begin_comment
comment|/* medium speed: clear -> 10 Mbps */
end_comment

begin_define
define|#
directive|define
name|SL_ATTR_CODING
value|0x10
end_define

begin_comment
comment|/* encoding: clear -> Manchester */
end_comment

begin_define
define|#
directive|define
name|SL_ATTR_HBW
value|0x20
end_define

begin_comment
comment|/* host bus width: clear -> 16-bit */
end_comment

begin_define
define|#
directive|define
name|SL_ATTR_TYPE
value|0x40
end_define

begin_comment
comment|/* medium type: clear -> Ethernet */
end_comment

begin_define
define|#
directive|define
name|SL_ATTR_BOOTROM
value|0x80
end_define

begin_comment
comment|/* set -> boot ROM present */
end_comment

end_unit

