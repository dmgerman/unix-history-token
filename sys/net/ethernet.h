begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Fundamental constants relating to ethernet.  *  * $Id$  *  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|ETHER_TYPE_LEN
value|2
end_define

begin_define
define|#
directive|define
name|ETHER_CRC_LENGTH
value|4
end_define

begin_define
define|#
directive|define
name|ETHER_HDR_SIZE
value|(ETHER_ADDR_LEN*2+ETHER_TYPE_LEN)
end_define

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_define
define|#
directive|define
name|ETHER_MAX_LEN
value|1518
end_define

end_unit

