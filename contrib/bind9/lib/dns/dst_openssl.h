begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2005, 2007, 2008, 2011  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dst_openssl.h,v 1.7.120.2 2011-03-12 04:57:26 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DST_OPENSSL_H
end_ifndef

begin_define
define|#
directive|define
name|DST_OPENSSL_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<openssl/err.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rand.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/conf.h>
end_include

begin_include
include|#
directive|include
file|<openssl/crypto.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_ENGINE
argument_list|)
operator|&&
name|defined
argument_list|(
name|CRYPTO_LOCK_ENGINE
argument_list|)
operator|&&
expr|\
operator|(
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x0090707f
operator|)
end_if

begin_define
define|#
directive|define
name|USE_ENGINE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dst__openssl_toresult
parameter_list|(
name|isc_result_t
name|fallback
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ENGINE
end_ifdef

begin_function_decl
name|ENGINE
modifier|*
name|dst__openssl_getengine
parameter_list|(
specifier|const
name|char
modifier|*
name|engine
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dst__openssl_getengine
parameter_list|(
name|x
parameter_list|)
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|isc_result_t
name|dst__openssl_setdefault
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DST_OPENSSL_H */
end_comment

begin_comment
comment|/*! \file */
end_comment

end_unit

