begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: stats.h,v 1.4.206.1 2004/03/06 08:14:00 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_STATS_H
value|1
end_define

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/*  * Query statistics counter types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_statscounter_success
init|=
literal|0
block|,
comment|/* Successful lookup */
name|dns_statscounter_referral
init|=
literal|1
block|,
comment|/* Referral result */
name|dns_statscounter_nxrrset
init|=
literal|2
block|,
comment|/* NXRRSET result */
name|dns_statscounter_nxdomain
init|=
literal|3
block|,
comment|/* NXDOMAIN result */
name|dns_statscounter_recursion
init|=
literal|4
block|,
comment|/* Recursion was used */
name|dns_statscounter_failure
init|=
literal|5
comment|/* Some other failure */
block|}
name|dns_statscounter_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_STATS_NCOUNTERS
value|6
end_define

begin_decl_stmt
name|LIBDNS_EXTERNAL_DATA
specifier|extern
specifier|const
name|char
modifier|*
name|dns_statscounter_names
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|isc_result_t
name|dns_stats_alloccounters
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_uint64_t
modifier|*
modifier|*
name|ctrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate an array of query statistics counters from the memory  * context 'mctx'.  */
end_comment

begin_function_decl
name|void
name|dns_stats_freecounters
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_uint64_t
modifier|*
modifier|*
name|ctrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free an array of query statistics counters allocated from the memory  * context 'mctx'.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_STATS_H */
end_comment

end_unit

