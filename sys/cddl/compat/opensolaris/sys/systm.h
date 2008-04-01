begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSOLARIS_SYS_SYSTM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OPENSOLARIS_SYS_SYSTM_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_empty
empty|#include_next<sys/systm.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/string.h>
end_include

begin_define
define|#
directive|define
name|PAGESIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|PAGEOFFSET
value|(PAGESIZE - 1)
end_define

begin_define
define|#
directive|define
name|PAGEMASK
value|(~PAGEOFFSET)
end_define

begin_define
define|#
directive|define
name|delay
parameter_list|(
name|x
parameter_list|)
value|pause("soldelay", (x))
end_define

begin_define
define|#
directive|define
name|xcopyin
parameter_list|(
name|u
parameter_list|,
name|k
parameter_list|,
name|s
parameter_list|)
value|copyin(u, k, s)
end_define

begin_define
define|#
directive|define
name|xcopyout
parameter_list|(
name|k
parameter_list|,
name|u
parameter_list|,
name|s
parameter_list|)
value|copyout(k, u, s)
end_define

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
comment|/* _OPENSOLARIS_SYS_SYSTM_H_ */
end_comment

end_unit

