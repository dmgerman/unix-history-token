begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1986 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)Aprober.c	7.1 (Berkeley) 12/6/90  */
end_comment

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_define
define|#
directive|define
name|PSL_USER
value|PSL_CURMOD
end_define

begin_macro
name|prober
argument_list|(
argument|infop
argument_list|)
end_macro

begin_decl_stmt
name|process_info
modifier|*
name|infop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /*	Probe read accessability. /* /*************************************/
end_comment

begin_block
block|{
specifier|register
name|long
name|Register_12
decl_stmt|;
comment|/* Has to be first reg ! */
specifier|register
name|long
name|Register_11
decl_stmt|;
specifier|register
name|long
name|Register_10
decl_stmt|;
specifier|register
name|long
name|Register_9
decl_stmt|;
name|Register_9
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|0
argument_list|)
operator|->
name|data
operator|&
literal|1
expr_stmt|;
comment|/* Required mode */
if|if
condition|(
name|psl
operator|&
name|PSL_USER
condition|)
name|Register_9
operator|=
literal|1
expr_stmt|;
comment|/* user can't probe as 							 *  kernel ! */
name|Register_10
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|1
argument_list|)
operator|->
name|address
expr_stmt|;
comment|/* Base address */
name|Register_11
operator|=
name|operand
argument_list|(
name|infop
argument_list|,
literal|2
argument_list|)
operator|->
name|data
expr_stmt|;
comment|/* Length */
name|Register_12
operator|=
name|psl
expr_stmt|;
name|Set_psl
argument_list|(
name|r12
argument_list|)
expr_stmt|;
comment|/* restore the user psl */
asm|asm ("	prober	r9,(r10),r11");
asm|asm ("	movpsl	r12");
name|New_cc
argument_list|(
name|Register_12
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

