begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id: ibcs2.c,v 1.7.2.1 1997/05/01 06:09:38 jkh Exp $  */
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
file|<sys/sysproto.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/lkm.h>
end_include

begin_expr_stmt
name|MOD_MISC
argument_list|(
name|ibcs2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|ibcs2_load
parameter_list|(
name|struct
name|lkm_table
modifier|*
name|lkmtp
parameter_list|,
name|int
name|cmd
parameter_list|)
block|{
comment|/* uprintf("ibcs2 emulator installed\n"); XXX - shut up, you! */
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ibcs2_unload
parameter_list|(
name|struct
name|lkm_table
modifier|*
name|lkmtp
parameter_list|,
name|int
name|cmd
parameter_list|)
block|{
name|uprintf
argument_list|(
literal|"ibcs2 emulator removed\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|ibcs2_mod
parameter_list|(
name|struct
name|lkm_table
modifier|*
name|lkmtp
parameter_list|,
name|int
name|cmd
parameter_list|,
name|int
name|ver
parameter_list|)
block|{
name|MOD_DISPATCH
argument_list|(
name|ibcs2
argument_list|,
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|ibcs2_load
argument_list|,
name|ibcs2_unload
argument_list|,
name|lkm_nullcmd
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

