begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rwhod.h	5.1 (Berkeley) 5/28/85  */
end_comment

begin_comment
comment|/*  * rwho protocol packet format.  */
end_comment

begin_struct
struct|struct
name|outmp
block|{
name|char
name|out_line
index|[
literal|8
index|]
decl_stmt|;
comment|/* tty name */
name|char
name|out_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* user id */
name|long
name|out_time
decl_stmt|;
comment|/* time on */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|whod
block|{
name|char
name|wd_vers
decl_stmt|;
comment|/* protocol version # */
name|char
name|wd_type
decl_stmt|;
comment|/* packet type, see below */
name|char
name|wd_pad
index|[
literal|2
index|]
decl_stmt|;
name|int
name|wd_sendtime
decl_stmt|;
comment|/* time stamp by sender */
name|int
name|wd_recvtime
decl_stmt|;
comment|/* time stamp applied by receiver */
name|char
name|wd_hostname
index|[
literal|32
index|]
decl_stmt|;
comment|/* hosts's name */
name|int
name|wd_loadav
index|[
literal|3
index|]
decl_stmt|;
comment|/* load average as in uptime */
name|int
name|wd_boottime
decl_stmt|;
comment|/* time system booted */
struct|struct
name|whoent
block|{
name|struct
name|outmp
name|we_utmp
decl_stmt|;
comment|/* active tty info */
name|int
name|we_idle
decl_stmt|;
comment|/* tty idle time */
block|}
name|wd_we
index|[
literal|1024
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|whoent
argument_list|)
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WHODVERSION
value|1
end_define

begin_define
define|#
directive|define
name|WHODTYPE_STATUS
value|1
end_define

begin_comment
comment|/* host status */
end_comment

end_unit

