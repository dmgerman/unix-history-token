begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 SRI International  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBNETBSD_SYS_CDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBNETBSD_SYS_CDEFS_H_
end_define

begin_empty
empty|#include_next<sys/cdefs.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__dead2
end_ifdef

begin_define
define|#
directive|define
name|__dead
value|__dead2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__dead
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Return the number of elements in a statically-allocated array,  * __x.  */
end_comment

begin_define
define|#
directive|define
name|__arraycount
parameter_list|(
name|__x
parameter_list|)
value|(sizeof(__x) / sizeof(__x[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBNETBSD_SYS_CDEFS_H_ */
end_comment

end_unit

