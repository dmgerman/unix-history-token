begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	$Id: script.h,v 10.3 2012/04/21 23:51:46 zy Exp $  */
end_comment

begin_struct
struct|struct
name|_script
block|{
name|pid_t
name|sh_pid
decl_stmt|;
comment|/* Shell pid. */
name|int
name|sh_master
decl_stmt|;
comment|/* Master pty fd. */
name|int
name|sh_slave
decl_stmt|;
comment|/* Slave pty fd. */
name|char
modifier|*
name|sh_prompt
decl_stmt|;
comment|/* Prompt. */
name|size_t
name|sh_prompt_len
decl_stmt|;
comment|/* Prompt length. */
name|char
name|sh_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* Pty name */
name|struct
name|winsize
name|sh_win
decl_stmt|;
comment|/* Window size. */
name|struct
name|termios
name|sh_term
decl_stmt|;
comment|/* Terminal information. */
block|}
struct|;
end_struct

end_unit

