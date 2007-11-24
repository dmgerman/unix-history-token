begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: ns_smf_globals.h,v 1.2.4.4 2005/05/13 01:22:33 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NS_SMF_GLOBALS_H
end_ifndef

begin_define
define|#
directive|define
name|NS_SMF_GLOBALS_H
value|1
end_define

begin_include
include|#
directive|include
file|<libscf.h>
end_include

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NS_MAIN
end_ifdef

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|v
parameter_list|)
value|= (v)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|v
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|ns_smf_got_instance
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|ns_smf_chroot
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|unsigned
name|int
name|ns_smf_want_disable
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|isc_result_t
name|ns_smf_add_message
parameter_list|(
name|isc_buffer_t
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|ns_smf_get_instance
parameter_list|(
name|char
modifier|*
modifier|*
name|name
parameter_list|,
name|int
name|debug
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NS_SMF_GLOBALS_H */
end_comment

end_unit

