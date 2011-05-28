begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2007  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: iptable.h,v 1.4 2007-09-14 01:46:05 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_IPTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_IPTABLE_H
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
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/radix.h>
end_include

begin_struct
struct|struct
name|dns_iptable
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|isc_refcount_t
name|refcount
decl_stmt|;
name|isc_radix_tree_t
modifier|*
name|radix
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_iptable_t
argument_list|)
name|nextincache
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_IPTABLE_MAGIC
value|ISC_MAGIC('T','a','b','l')
end_define

begin_define
define|#
directive|define
name|DNS_IPTABLE_VALID
parameter_list|(
name|a
parameter_list|)
value|ISC_MAGIC_VALID(a, DNS_IPTABLE_MAGIC)
end_define

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_iptable_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_iptable_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new IP table and the underlying radix structure  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_iptable_addprefix
parameter_list|(
name|dns_iptable_t
modifier|*
name|tab
parameter_list|,
name|isc_netaddr_t
modifier|*
name|addr
parameter_list|,
name|isc_uint16_t
name|bitlen
parameter_list|,
name|isc_boolean_t
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add an IP prefix to an existing IP table  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_iptable_merge
parameter_list|(
name|dns_iptable_t
modifier|*
name|tab
parameter_list|,
name|dns_iptable_t
modifier|*
name|source
parameter_list|,
name|isc_boolean_t
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Merge one IP table into another one.  */
end_comment

begin_function_decl
name|void
name|dns_iptable_attach
parameter_list|(
name|dns_iptable_t
modifier|*
name|source
parameter_list|,
name|dns_iptable_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_iptable_detach
parameter_list|(
name|dns_iptable_t
modifier|*
modifier|*
name|tabp
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
comment|/* DNS_IPTABLE_H */
end_comment

end_unit

