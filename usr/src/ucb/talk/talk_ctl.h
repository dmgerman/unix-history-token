begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)talk_ctl.h	5.4 (Berkeley) 6/29/88  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<protocols/talkd.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
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

