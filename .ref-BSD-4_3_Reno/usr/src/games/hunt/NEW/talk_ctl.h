begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)talk_ctl.h	5.2 (Berkeley) 3/13/86  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TALK_43
end_ifdef

begin_include
include|#
directive|include
file|<protocols/talkd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/socket.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAXHOSTNAMELEN
end_ifndef

begin_define
define|#
directive|define
name|MAXHOSTNAMELEN
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_LIFE
value|60
end_define

begin_comment
comment|/* max time daemon saves invitations */
end_comment

begin_comment
comment|/* RING_WAIT should be 10's of seconds less than MAX_LIFE */
end_comment

begin_define
define|#
directive|define
name|RING_WAIT
value|30
end_define

begin_comment
comment|/* time to wait before refreshing invitation */
end_comment

begin_comment
comment|/* type values */
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
comment|/* answer values */
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
name|CTL_RESPONSE
typedef|;
end_typedef

begin_typedef
typedef|typedef
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
name|CTL_MSG
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|daemon_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|ctl_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
name|my_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|my_machine_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|in_addr
name|his_machine_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|daemon_port
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ctl_sockt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CTL_MSG
name|msg
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOG
end_ifdef

begin_define
define|#
directive|define
name|p_error
parameter_list|(
name|str
parameter_list|)
value|syslog(LOG_WARNING, "faketalk %s: %m", str)
end_define

begin_else
else|#
directive|else
else|LOG
end_else

begin_define
define|#
directive|define
name|p_error
parameter_list|(
name|str
parameter_list|)
value|perror(str)
end_define

begin_endif
endif|#
directive|endif
endif|LOG
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htons
end_ifndef

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|htons
argument_list|()
decl_stmt|,
name|ntohs
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|htonl
end_ifndef

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|htonl
argument_list|()
decl_stmt|,
name|ntohl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

