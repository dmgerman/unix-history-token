begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2011, 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by David Chisnall under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Extended locale versions of the locale-aware functions from inttypes.h.  * Include<inttypes.h> before<xlocale.h> to expose these.  */
end_comment

begin_function_decl
name|intmax_t
name|strtoimax_l
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|strtoumax_l
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|intmax_t
name|wcstoimax_l
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintmax_t
name|wcstoumax_l
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

