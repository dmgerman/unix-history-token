begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)tty_subr.c	8.2 (Berkeley) 9/5/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_decl_stmt
name|char
name|cwaiting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cblock
modifier|*
name|cfree
decl_stmt|,
modifier|*
name|cfreelist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cfreecount
decl_stmt|,
name|nclist
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|clist_init
parameter_list|()
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_function

begin_macro
name|getc
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
operator|(
name|char
operator|)
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|q_to_b
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a3
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|ndqb
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|void
name|ndflush
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
name|int
name|a2
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_function

begin_macro
name|putc
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|)
end_macro

begin_decl_stmt
name|char
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a2
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|b_to_q
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a3
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|char
modifier|*
name|nextc
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|)
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
name|char
modifier|*
name|a2
decl_stmt|;
name|int
modifier|*
name|a3
decl_stmt|;
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
operator|(
name|char
operator|*
operator|)
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|unputc
argument_list|(
argument|a1
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|clist
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return
operator|(
operator|(
name|char
operator|)
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|void
name|catq
parameter_list|(
name|a1
parameter_list|,
name|a2
parameter_list|)
name|struct
name|clist
modifier|*
name|a1
decl_stmt|,
decl|*
name|a2
decl_stmt|;
end_function

begin_block
block|{
comment|/* 	 * Body deleted. 	 */
return|return;
block|}
end_block

end_unit

