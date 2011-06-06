begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2007 John Birrell<jb@freebsd.org>  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_OPENSOLARIS_SYS_STAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_OPENSOLARIS_SYS_STAT_H_
end_define

begin_empty
empty|#include_next<sys/stat.h>
end_empty

begin_define
define|#
directive|define
name|stat64
value|stat
end_define

begin_define
define|#
directive|define
name|MAXOFFSET_T
value|OFF_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_function
specifier|static
name|__inline
name|int
name|fstat64
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|ret
operator|=
name|fstat
argument_list|(
name|fd
argument_list|,
name|sb
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|S_ISCHR
argument_list|(
name|sb
operator|->
name|st_mode
argument_list|)
condition|)
operator|(
name|void
operator|)
name|ioctl
argument_list|(
name|fd
argument_list|,
name|DIOCGMEDIASIZE
argument_list|,
operator|&
name|sb
operator|->
name|st_size
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_OPENSOLARIS_SYS_STAT_H_ */
end_comment

end_unit

