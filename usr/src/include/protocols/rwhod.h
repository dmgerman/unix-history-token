begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)rwhod.h	5.4 (Berkeley) %G%  */
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

begin_define
define|#
directive|define
name|_PATH_RWHODIR
value|"/var/rwho"
end_define

end_unit

