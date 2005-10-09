begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: random.h,v 1.11.206.1 2004/03/06 08:14:46 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RANDOM_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RANDOM_H
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
file|<isc/types.h>
end_include

begin_comment
comment|/*  * Implements a random state pool which will let the caller return a  * series of possibly non-reproducable random values.  Note that the  * strength of these numbers is not all that high, and should not be  * used in cryptography functions.  It is useful for jittering values  * a bit here and there, such as timeouts, etc.  */
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|void
name|isc_random_seed
parameter_list|(
name|isc_uint32_t
name|seed
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the initial seed of the random state.  */
end_comment

begin_function_decl
name|void
name|isc_random_get
parameter_list|(
name|isc_uint32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get a random value.  *  * Requires:  *	val != NULL.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|isc_random_jitter
parameter_list|(
name|isc_uint32_t
name|max
parameter_list|,
name|isc_uint32_t
name|jitter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get a random value between (max - jitter) and (max).  * This is useful for jittering timer values.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RANDOM_H */
end_comment

end_unit

