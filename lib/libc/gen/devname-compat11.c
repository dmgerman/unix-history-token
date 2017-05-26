begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Gleb Kurtsou<gleb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"gen-compat.h"
end_include

begin_function
name|char
modifier|*
name|freebsd11_devname
parameter_list|(
name|uint32_t
name|dev
parameter_list|,
name|mode_t
name|type
parameter_list|)
block|{
return|return
operator|(
name|devname
argument_list|(
name|dev
argument_list|,
name|type
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|freebsd11_devname_r
parameter_list|(
name|uint32_t
name|dev
parameter_list|,
name|mode_t
name|type
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
block|{
return|return
operator|(
name|devname_r
argument_list|(
name|dev
argument_list|,
name|type
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|__sym_compat
argument_list|(
name|devname
argument_list|,
name|freebsd11_devname
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__sym_compat
argument_list|(
name|devname_r
argument_list|,
name|freebsd11_devname_r
argument_list|,
name|FBSD_1
literal|.0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

