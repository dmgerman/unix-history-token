begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: ctl.h 1.4 83/03/28 20:46:27 moore Exp $ */
end_comment

begin_comment
comment|/* ctl.h describes the structure that talk and talkd pass back    and forth  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_define
define|#
directive|define
name|NAME_SIZE
value|9
end_define

begin_define
define|#
directive|define
name|TTY_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|HOST_NAME_LENGTH
value|256
end_define

begin_define
define|#
directive|define
name|MAX_LIFE
value|60
end_define

begin_comment
comment|/* maximum time an invitation is saved by the 			 talk daemons */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT
value|30
end_define

begin_comment
comment|/* time to wait before refreshing invitation  			 should be 10's of seconds less than MAX_LIFE */
end_comment

begin_comment
comment|/* the values for type */
end_comment

begin_define
define|#
directive|define
name|LEAVE_INVITE
value|0
end_define

begin_define
define|#
directive|define
name|LOOK_UP
value|1
end_define

begin_define
define|#
directive|define
name|DELETE
value|2
end_define

begin_define
define|#
directive|define
name|ANNOUNCE
value|3
end_define

begin_comment
comment|/* the values for answer */
end_comment

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|NOT_HERE
value|1
end_define

begin_define
define|#
directive|define
name|FAILED
value|2
end_define

begin_define
define|#
directive|define
name|MACHINE_UNKNOWN
value|3
end_define

begin_define
define|#
directive|define
name|PERMISSION_DENIED
value|4
end_define

begin_define
define|#
directive|define
name|UNKNOWN_REQUEST
value|5
end_define

begin_typedef
typedef|typedef
name|struct
name|ctl_response
name|CTL_RESPONSE
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_response
block|{
name|char
name|type
decl_stmt|;
name|char
name|answer
decl_stmt|;
name|int
name|id_num
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ctl_msg
name|CTL_MSG
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_msg
block|{
name|char
name|type
decl_stmt|;
name|char
name|l_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|char
name|r_name
index|[
name|NAME_SIZE
index|]
decl_stmt|;
name|int
name|id_num
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|char
name|r_tty
index|[
name|TTY_SIZE
index|]
decl_stmt|;
name|struct
name|sockaddr_in
name|addr
decl_stmt|;
name|struct
name|sockaddr_in
name|ctl_addr
decl_stmt|;
block|}
struct|;
end_struct

end_unit

