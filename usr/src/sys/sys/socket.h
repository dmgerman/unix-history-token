begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	socket.h	4.4	81/11/08	*/
end_comment

begin_comment
comment|/*  * Externally visible attributes of sockets:  * types and options.  */
end_comment

begin_define
define|#
directive|define
name|SOCK_STREAM
value|0
end_define

begin_comment
comment|/* stream socket */
end_comment

begin_define
define|#
directive|define
name|SOCK_DGRAM
value|1
end_define

begin_comment
comment|/* datagram socket */
end_comment

begin_define
define|#
directive|define
name|SOCK_RAW
value|2
end_define

begin_comment
comment|/* raw-protocol interface */
end_comment

begin_define
define|#
directive|define
name|SOCK_RDM
value|3
end_define

begin_comment
comment|/* reliably-delivered message */
end_comment

begin_comment
comment|/* ... */
end_comment

begin_comment
comment|/*  * Option flags per-socket.  */
end_comment

begin_define
define|#
directive|define
name|SO_DEBUG
value|0x01
end_define

begin_comment
comment|/* turn on debugging info recording */
end_comment

begin_define
define|#
directive|define
name|SO_ACCEPT
value|0x02
end_define

begin_comment
comment|/* willing to accept connection */
end_comment

begin_define
define|#
directive|define
name|SO_NBIO
value|0x04
end_define

begin_comment
comment|/* don't block on this socket */
end_comment

begin_define
define|#
directive|define
name|SO_INTR
value|0x08
end_define

begin_comment
comment|/* interrupt when data available */
end_comment

begin_define
define|#
directive|define
name|SO_NEWFD
value|0x10
end_define

begin_comment
comment|/* give new fd's for each connect */
end_comment

end_unit

