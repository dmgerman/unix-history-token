begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: talk_ctl.h 1.1 83/03/26 14:36:39 moore Exp $ */
end_comment

begin_include
include|#
directive|include
file|"ctl.h"
end_include

begin_include
include|#
directive|include
file|"talk.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

end_unit

