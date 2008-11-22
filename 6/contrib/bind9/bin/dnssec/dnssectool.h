begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dnssectool.h,v 1.15.12.3 2004/03/08 04:04:18 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNSSECTOOL_H
end_ifndef

begin_define
define|#
directive|define
name|DNSSECTOOL_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/log.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatastruct.h>
end_include

begin_include
include|#
directive|include
file|<dst/dst.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
name|fatalcallback_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|setfatalcallback
parameter_list|(
name|fatalcallback_t
modifier|*
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_result
parameter_list|(
name|isc_result_t
name|result
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vbprintf
parameter_list|(
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|type_format
parameter_list|(
specifier|const
name|dns_rdatatype_t
name|type
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TYPE_FORMATSIZE
value|10
end_define

begin_function_decl
name|void
name|alg_format
parameter_list|(
specifier|const
name|dns_secalg_t
name|alg
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ALG_FORMATSIZE
value|10
end_define

begin_function_decl
name|void
name|sig_format
parameter_list|(
name|dns_rdata_rrsig_t
modifier|*
name|sig
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SIG_FORMATSIZE
value|(DNS_NAME_FORMATSIZE + ALG_FORMATSIZE + sizeof("65535"))
end_define

begin_function_decl
name|void
name|key_format
parameter_list|(
specifier|const
name|dst_key_t
modifier|*
name|key
parameter_list|,
name|char
modifier|*
name|cp
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KEY_FORMATSIZE
value|(DNS_NAME_FORMATSIZE + ALG_FORMATSIZE + sizeof("65535"))
end_define

begin_function_decl
name|void
name|setup_logging
parameter_list|(
name|int
name|verbose
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_log_t
modifier|*
modifier|*
name|logp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup_logging
parameter_list|(
name|isc_log_t
modifier|*
modifier|*
name|logp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setup_entropy
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|randomfile
parameter_list|,
name|isc_entropy_t
modifier|*
modifier|*
name|ectx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup_entropy
parameter_list|(
name|isc_entropy_t
modifier|*
modifier|*
name|ectx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_stdtime_t
name|strtotime
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|isc_int64_t
name|now
parameter_list|,
name|isc_int64_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rdataclass_t
name|strtoclass
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNSSEC_DNSSECTOOL_H */
end_comment

end_unit

