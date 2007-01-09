begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994 Henry Spencer.  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)utils.h	8.3 (Berkeley) 3/20/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* utility definitions */
end_comment

begin_define
define|#
directive|define
name|DUPMAX
value|_POSIX2_RE_DUP_MAX
end_define

begin_comment
comment|/* xxx is this right? */
end_comment

begin_define
define|#
directive|define
name|INFINITY
value|(DUPMAX + 1)
end_define

begin_define
define|#
directive|define
name|NC
value|(CHAR_MAX - CHAR_MIN + 1)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uch
typedef|;
end_typedef

begin_comment
comment|/* switch off assertions (if not already off) if no REDEBUG */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REDEBUG
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NDEBUG
end_ifndef

begin_define
define|#
directive|define
name|NDEBUG
end_define

begin_comment
comment|/* no assertions please */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|/* for old systems with bcopy() but no memmove() */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USEBCOPY
end_ifdef

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|bcopy(s, d, c)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

