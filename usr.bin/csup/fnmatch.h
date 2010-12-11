begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  *	@(#)fnmatch.h	8.1 (Berkeley) 6/2/93  *  * From FreeBSD fnmatch.h 1.7  * $Id: fnmatch.h,v 1.4 2001/10/04 02:46:21 jdp Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FNMATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_FNMATCH_H_
end_define

begin_define
define|#
directive|define
name|FNM_NOMATCH
value|1
end_define

begin_comment
comment|/* Match failed. */
end_comment

begin_define
define|#
directive|define
name|FNM_NOESCAPE
value|0x01
end_define

begin_comment
comment|/* Disable backslash escaping. */
end_comment

begin_define
define|#
directive|define
name|FNM_PATHNAME
value|0x02
end_define

begin_comment
comment|/* Slash must be matched by slash. */
end_comment

begin_define
define|#
directive|define
name|FNM_PERIOD
value|0x04
end_define

begin_comment
comment|/* Period must be matched by period. */
end_comment

begin_define
define|#
directive|define
name|FNM_LEADING_DIR
value|0x08
end_define

begin_comment
comment|/* Ignore /<tail> after Imatch. */
end_comment

begin_define
define|#
directive|define
name|FNM_CASEFOLD
value|0x10
end_define

begin_comment
comment|/* Case insensitive search. */
end_comment

begin_define
define|#
directive|define
name|FNM_PREFIX_DIRS
value|0x20
end_define

begin_comment
comment|/* Directory prefixes of pattern match too. */
end_comment

begin_comment
comment|/* Make this compile successfully with "gcc -traditional" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|fnmatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FNMATCH_H_ */
end_comment

end_unit

