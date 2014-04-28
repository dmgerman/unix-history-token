begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_FILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_FILE_H_
end_define

begin_empty
empty|#include_next<sys/file.h>
end_empty

begin_define
define|#
directive|define
name|FKIOCTL
value|0x80000000
end_define

begin_comment
comment|/* ioctl addresses are from kernel */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|file
name|file_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/capsicum.h>
end_include

begin_function
specifier|static
name|__inline
name|file_t
modifier|*
name|getf
parameter_list|(
name|int
name|fd
parameter_list|,
name|cap_rights_t
modifier|*
name|rightsp
parameter_list|)
block|{
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
if|if
condition|(
name|fget
argument_list|(
name|curthread
argument_list|,
name|fd
argument_list|,
name|rightsp
argument_list|,
operator|&
name|fp
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|fp
operator|)
return|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|releasef
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|struct
name|file
modifier|*
name|fp
decl_stmt|;
comment|/* No CAP_ rights required, as we're only releasing. */
if|if
condition|(
name|fget
argument_list|(
name|curthread
argument_list|,
name|fd
argument_list|,
name|NULL
argument_list|,
operator|&
name|fp
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fdrop
argument_list|(
name|fp
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
name|fdrop
argument_list|(
name|fp
argument_list|,
name|curthread
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_OPENSOLARIS_SYS_FILE_H_ */
end_comment

end_unit

