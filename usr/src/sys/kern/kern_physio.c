begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)kern_physio.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_macro
name|physio
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|,
argument|a5
argument_list|,
argument|a6
argument_list|)
end_macro

begin_function_decl
name|int
function_decl|(
modifier|*
name|a1
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|buf
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|dev_t
name|a3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a4
decl_stmt|;
end_decl_stmt

begin_function_decl
name|u_int
function_decl|(
modifier|*
name|a5
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|uio
modifier|*
name|a6
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
name|EIO
operator|)
return|;
block|}
end_block

begin_function
name|u_int
name|minphys
parameter_list|(
name|a1
parameter_list|)
name|struct
name|buf
modifier|*
name|a1
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Do a read on a device for a user process.  */
end_comment

begin_macro
name|rawread
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|physio
argument_list|(
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|.
name|d_strategy
argument_list|,
operator|(
expr|struct
name|buf
operator|*
operator|)
name|NULL
argument_list|,
name|dev
argument_list|,
name|B_READ
argument_list|,
name|minphys
argument_list|,
name|uio
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Do a write on a device for a user process.  */
end_comment

begin_macro
name|rawwrite
argument_list|(
argument|dev
argument_list|,
argument|uio
argument_list|)
end_macro

begin_decl_stmt
name|dev_t
name|dev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uio
modifier|*
name|uio
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|physio
argument_list|(
name|cdevsw
index|[
name|major
argument_list|(
name|dev
argument_list|)
index|]
operator|.
name|d_strategy
argument_list|,
operator|(
expr|struct
name|buf
operator|*
operator|)
name|NULL
argument_list|,
name|dev
argument_list|,
name|B_WRITE
argument_list|,
name|minphys
argument_list|,
name|uio
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

