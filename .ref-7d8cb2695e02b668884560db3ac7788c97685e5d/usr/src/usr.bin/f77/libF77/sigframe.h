begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  *  *	@(#)sigframe.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definition of signal handler frame.  */
end_comment

begin_struct
struct|struct
name|sigframe
block|{
name|int
name|sf_signum
decl_stmt|;
name|int
name|sf_code
decl_stmt|;
name|struct
name|sigcontext
modifier|*
name|sf_scp
decl_stmt|;
name|int
function_decl|(
modifier|*
name|sf_handler
function_decl|)
parameter_list|()
function_decl|;
name|int
name|r1
decl_stmt|;
name|int
name|r0
decl_stmt|;
name|struct
name|sigcontext
modifier|*
name|sf_scpcopy
decl_stmt|;
block|}
struct|;
end_struct

end_unit

