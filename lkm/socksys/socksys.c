begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
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

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_function_decl
name|int
name|sockopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sockclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sockioctl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|cdevsw
name|dev_socksys
init|=
block|{
operator|(
name|d_open_t
operator|*
operator|)
name|sockopen
block|,
operator|(
name|d_close_t
operator|*
operator|)
name|sockclose
block|,
operator|(
name|d_rdwr_t
operator|*
operator|)
name|enodev
block|,
operator|(
name|d_rdwr_t
operator|*
operator|)
name|enodev
block|,
operator|(
name|d_ioctl_t
operator|*
operator|)
name|sockioctl
block|,
operator|(
name|d_stop_t
operator|*
operator|)
name|enodev
block|,
operator|(
name|d_reset_t
operator|*
operator|)
name|nullop
block|,
name|NULL
block|,
operator|(
name|d_select_t
operator|*
operator|)
name|seltrue
block|,
operator|(
name|d_mmap_t
operator|*
operator|)
name|enodev
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|MOD_DEV
argument_list|(
literal|"socksys_mod"
argument_list|,
argument|LM_DT_CHAR
argument_list|,
argument|-
literal|1
argument_list|,
argument|(void *)&dev_socksys
argument_list|)
end_macro

begin_macro
name|socksys_load
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
name|uprintf
argument_list|(
literal|"socksys driver installed\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|socksys_unload
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|)
end_macro

begin_block
block|{
name|uprintf
argument_list|(
literal|"socksys driver removed\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_macro
name|socksys_init
argument_list|(
argument|struct lkm_table *lkmtp
argument_list|,
argument|int cmd
argument_list|,
argument|int ver
argument_list|)
end_macro

begin_block
block|{
name|DISPATCH
argument_list|(
name|lkmtp
argument_list|,
name|cmd
argument_list|,
name|ver
argument_list|,
name|socksys_load
argument_list|,
name|socksys_unload
argument_list|,
name|nosys
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

