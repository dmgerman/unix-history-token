begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<i386/linux/linux.h>
end_include

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
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_decl_stmt
specifier|static
name|caddr_t
name|ua_ptr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|caddr_t
name|ua_alloc_init
parameter_list|(
name|int
name|len
parameter_list|)
block|{
name|caddr_t
name|ptr
decl_stmt|;
name|ptr
operator|=
operator|(
name|caddr_t
operator|)
name|ALIGN
argument_list|(
operator|(
name|PS_STRINGS
operator|)
argument_list|)
expr_stmt|;
name|ptr
operator|-=
name|SPARE_USRSPACE
expr_stmt|;
name|ua_ptr
operator|=
call|(
name|caddr_t
call|)
argument_list|(
name|ptr
operator|+
name|ALIGN
argument_list|(
name|len
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

begin_function
name|caddr_t
name|ua_alloc
parameter_list|(
name|int
name|len
parameter_list|)
block|{
name|caddr_t
name|ptr
decl_stmt|;
name|ptr
operator|=
name|ua_ptr
expr_stmt|;
name|ua_ptr
operator|+=
name|ALIGN
argument_list|(
name|len
argument_list|)
expr_stmt|;
return|return
name|ptr
return|;
block|}
end_function

end_unit

