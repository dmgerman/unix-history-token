begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-2-Clause-FreeBSD  *  * Copyright (c) 2011, 2012 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by David Chisnall under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLOCALE_LOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_XLOCALE_LOCALE_H
end_define

begin_comment
comment|/* Bit shifting order of LC_*_MASK should match XLC_* and LC_* order. */
end_comment

begin_define
define|#
directive|define
name|LC_COLLATE_MASK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|LC_CTYPE_MASK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|LC_MONETARY_MASK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|LC_NUMERIC_MASK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|LC_TIME_MASK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|LC_MESSAGES_MASK
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|LC_ALL_MASK
value|(LC_COLLATE_MASK | LC_CTYPE_MASK | LC_MESSAGES_MASK | \ 			  LC_MONETARY_MASK | LC_NUMERIC_MASK | LC_TIME_MASK)
end_define

begin_define
define|#
directive|define
name|LC_GLOBAL_LOCALE
value|((locale_t)-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCALE_T_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_LOCALE_T_DEFINED
end_define

begin_typedef
typedef|typedef
name|struct
name|_xlocale
modifier|*
name|locale_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|locale_t
name|duplocale
parameter_list|(
name|locale_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|freelocale
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|locale_t
name|newlocale
parameter_list|(
name|int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|locale
parameter_list|,
name|locale_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|querylocale
parameter_list|(
name|int
name|mask
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|locale_t
name|uselocale
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XLOCALE_LOCALE_H */
end_comment

end_unit

