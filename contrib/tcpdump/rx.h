begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Rx protocol format  *  * $Id: rx.h,v 1.1 1999/11/17 05:45:58 assar Exp $  */
end_comment

begin_define
define|#
directive|define
name|FS_RX_PORT
value|7000
end_define

begin_define
define|#
directive|define
name|CB_RX_PORT
value|7001
end_define

begin_define
define|#
directive|define
name|PROT_RX_PORT
value|7002
end_define

begin_define
define|#
directive|define
name|VLDB_RX_PORT
value|7003
end_define

begin_define
define|#
directive|define
name|KAUTH_RX_PORT
value|7004
end_define

begin_define
define|#
directive|define
name|VOL_RX_PORT
value|7005
end_define

begin_define
define|#
directive|define
name|ERROR_RX_PORT
value|7006
end_define

begin_comment
comment|/* Doesn't seem to be used */
end_comment

begin_define
define|#
directive|define
name|BOS_RX_PORT
value|7007
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|AFSNAMEMAX
end_ifndef

begin_define
define|#
directive|define
name|AFSNAMEMAX
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AFSOPAQUEMAX
end_ifndef

begin_define
define|#
directive|define
name|AFSOPAQUEMAX
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PRNAMEMAX
value|64
end_define

begin_define
define|#
directive|define
name|VLNAMEMAX
value|65
end_define

begin_define
define|#
directive|define
name|KANAMEMAX
value|64
end_define

begin_define
define|#
directive|define
name|BOSNAMEMAX
value|256
end_define

begin_define
define|#
directive|define
name|PRSFS_READ
value|1
end_define

begin_comment
comment|/* Read files */
end_comment

begin_define
define|#
directive|define
name|PRSFS_WRITE
value|2
end_define

begin_comment
comment|/* Write files */
end_comment

begin_define
define|#
directive|define
name|PRSFS_INSERT
value|4
end_define

begin_comment
comment|/* Insert files into a directory */
end_comment

begin_define
define|#
directive|define
name|PRSFS_LOOKUP
value|8
end_define

begin_comment
comment|/* Lookup files into a directory */
end_comment

begin_define
define|#
directive|define
name|PRSFS_DELETE
value|16
end_define

begin_comment
comment|/* Delete files */
end_comment

begin_define
define|#
directive|define
name|PRSFS_LOCK
value|32
end_define

begin_comment
comment|/* Lock files */
end_comment

begin_define
define|#
directive|define
name|PRSFS_ADMINISTER
value|64
end_define

begin_comment
comment|/* Change ACL's */
end_comment

begin_struct
struct|struct
name|rx_header
block|{
name|u_int32_t
name|epoch
decl_stmt|;
name|u_int32_t
name|cid
decl_stmt|;
name|u_int32_t
name|callNumber
decl_stmt|;
name|u_int32_t
name|seq
decl_stmt|;
name|u_int32_t
name|serial
decl_stmt|;
name|u_char
name|type
decl_stmt|;
define|#
directive|define
name|RX_PACKET_TYPE_DATA
value|1
define|#
directive|define
name|RX_PACKET_TYPE_ACK
value|2
define|#
directive|define
name|RX_PACKET_TYPE_BUSY
value|3
define|#
directive|define
name|RX_PACKET_TYPE_ABORT
value|4
define|#
directive|define
name|RX_PACKET_TYPE_ACKALL
value|5
define|#
directive|define
name|RX_PACKET_TYPE_CHALLENGE
value|6
define|#
directive|define
name|RX_PACKET_TYPE_RESPONSE
value|7
define|#
directive|define
name|RX_PACKET_TYPE_DEBUG
value|8
define|#
directive|define
name|RX_PACKET_TYPE_PARAMS
value|9
define|#
directive|define
name|RX_PACKET_TYPE_VERSION
value|13
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|RX_CLIENT_INITIATED
value|1
define|#
directive|define
name|RX_REQUEST_ACK
value|2
define|#
directive|define
name|RX_LAST_PACKET
value|4
define|#
directive|define
name|RX_MORE_PACKETS
value|8
define|#
directive|define
name|RX_FREE_PACKET
value|16
name|u_char
name|userStatus
decl_stmt|;
name|u_char
name|securityIndex
decl_stmt|;
name|u_short
name|spare
decl_stmt|;
comment|/* How clever: even though the AFS */
name|u_short
name|serviceId
decl_stmt|;
comment|/* header files indicate that the */
block|}
struct|;
end_struct

begin_comment
comment|/* serviceId is first, it's really */
end_comment

begin_comment
comment|/* encoded _after_ the spare field */
end_comment

begin_comment
comment|/* I wasted a day figuring that out! */
end_comment

begin_define
define|#
directive|define
name|NUM_RX_FLAGS
value|5
end_define

end_unit

