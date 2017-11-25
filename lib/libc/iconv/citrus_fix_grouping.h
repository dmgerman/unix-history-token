begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: citrus_fix_grouping.h,v 1.2 2009/01/11 02:46:24 christos Exp $ */
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause  *  * Copyright (c)2008 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CITRUS_FIX_GROUPING_H_
end_ifndef

begin_define
define|#
directive|define
name|_CITRUS_FIX_GROUPING_H_
end_define

begin_define
define|#
directive|define
name|_CITRUS_LC_GROUPING_VALUE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|_CITRUS_LC_GROUPING_VALUE_MAX
value|126
end_define

begin_define
define|#
directive|define
name|_CITRUS_LC_GROUPING_VALUE_NO_FUTHER
value|127
end_define

begin_if
if|#
directive|if
name|CHAR_MAX
operator|!=
name|_CITRUS_LC_GROUPING_VALUE_NO_FUTHER
end_if

begin_function
specifier|static
name|__inline
name|void
name|_citrus_fixup_char_max_md
parameter_list|(
name|char
modifier|*
name|grouping
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|grouping
init|;
operator|*
name|p
operator|!=
literal|'\0'
condition|;
operator|++
name|p
control|)
if|if
condition|(
operator|*
name|p
operator|==
name|_CITRUS_LC_GROUPING_VALUE_NO_FUTHER
condition|)
operator|*
name|p
operator|=
operator|(
name|char
operator|)
name|CHAR_MAX
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|_CITRUS_FIXUP_CHAR_MAX_MD
parameter_list|(
name|grouping
parameter_list|)
define|\
value|_citrus_fixup_char_max_md(__DECONST(void *, grouping))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_CITRUS_FIXUP_CHAR_MAX_MD
parameter_list|(
name|grouping
parameter_list|)
end_define

begin_comment
comment|/* nothing to do */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_CITRUS_FIX_GROUPING_H_*/
end_comment

end_unit

