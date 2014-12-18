begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2010, 2014  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dns64.h,v 1.3 2010/12/08 23:51:56 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DNS64_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DNS64_H
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
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*  * dns_dns64_create() flags.  */
define|#
directive|define
name|DNS_DNS64_RECURSIVE_ONLY
value|0x01
comment|/* If set then this record 						 * only applies to recursive 						 * queries. 						 */
define|#
directive|define
name|DNS_DNS64_BREAK_DNSSEC
value|0x02
comment|/* If set then still perform 						 * DNSSEC synthesis even 						 * though the result would 						 * fail validation. 						 */
comment|/*  * dns_dns64_aaaaok() and dns_dns64_aaaafroma() flags.  */
define|#
directive|define
name|DNS_DNS64_RECURSIVE
value|0x01
comment|/* Recursive query. */
define|#
directive|define
name|DNS_DNS64_DNSSEC
value|0x02
comment|/* DNSSEC sensitive query. */
name|isc_result_t
name|dns_dns64_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_netaddr_t
modifier|*
name|prefix
parameter_list|,
name|unsigned
name|int
name|prefixlen
parameter_list|,
name|isc_netaddr_t
modifier|*
name|suffix
parameter_list|,
name|dns_acl_t
modifier|*
name|client
parameter_list|,
name|dns_acl_t
modifier|*
name|mapped
parameter_list|,
name|dns_acl_t
modifier|*
name|excluded
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|dns_dns64_t
modifier|*
modifier|*
name|dns64
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a dns64 record which is used to identify the set of clients  * it applies to and how to perform the DNS64 synthesis.  *  * 'prefix' and 'prefixlen' defined the leading bits of the AAAA records  * to be synthesised.  'suffix' defines the bits after the A records bits.  * If suffix is NULL zeros will be used for these bits.  'client' defines  * for which clients this record applies.  If 'client' is NULL then all  * clients apply.  'mapped' defines which A records are candidated for  * mapping.  If 'mapped' is NULL then all A records will be mapped.  * 'excluded' defines which AAAA are to be treated as non-existent for the  * purposed of determining whether to perform syntesis.  If 'excluded' is  * NULL then no AAAA records prevent synthesis.  *  * If DNS_DNS64_RECURSIVE_ONLY is set then the record will only match if  * DNS_DNS64_RECURSIVE is set when calling  dns_dns64_aaaaok() and  * dns_dns64_aaaafroma().  *  * If DNS_DNS64_BREAK_DNSSEC is set then the record will still apply if  * DNS_DNS64_DNSSEC is set when calling  dns_dns64_aaaaok() and  * dns_dns64_aaaafroma() otherwise the record will be ignored.  *  * Requires:  *      'mctx'          to be valid.  *      'prefix'        to be valid and the address family to AF_INET6.  *      'prefixlen'     to be one of 32, 40, 48, 56, 72 and 96.  *                      the bits not covered by prefixlen in prefix to  *                      be zero.  *      'suffix'        to be NULL or the address family be set to AF_INET6  *                      and the leading 'prefixlen' + 32 bits of the 'suffix'  *                      to be zero.  If 'prefixlen' is 40, 48 or 56 then the  *                      the leading 'prefixlen' + 40 bits of 'suffix' must be  *                      zero.  *	'client'	to be NULL or a valid acl.  *	'mapped'	to be NULL or a valid acl.  *	'excluded'	to be NULL or a valid acl.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_dns64_destroy
parameter_list|(
name|dns_dns64_t
modifier|*
modifier|*
name|dns64p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroys a dns64 record.  *  * Requires the record to not be linked.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dns64_aaaafroma
parameter_list|(
specifier|const
name|dns_dns64_t
modifier|*
name|dns64
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|reqaddr
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|reqsigner
parameter_list|,
specifier|const
name|dns_aclenv_t
modifier|*
name|env
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|unsigned
name|char
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
name|aaaa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dns_dns64_aaaafroma() determines whether to perform a DNS64 address  * synthesis from 'a' based on 'dns64', 'reqaddr', 'reqsigner', 'env',  * 'flags' and 'aaaa'.  If synthesis is performed then the result is  * written to '*aaaa'.  *  * The synthesised address will be of the form:  *  *<prefix bits><a bits><suffix bits>  *  * If<a bits> straddle bits 64-71 of the AAAA record, then 8 zero bits will  * be inserted at bits 64-71.  *  * Requires:  *	'dns64'		to be valid.  *	'reqaddr'	to be valid.  *	'reqsigner'	to be NULL or valid.  *	'env'		to be valid.  *	'a'		to point to a IPv4 address in network order.  *	'aaaa'		to point to a IPv6 address buffer in network order.  *  * Returns:  *	ISC_R_SUCCESS		if synthesis was performed.  *	DNS_R_DISALLOWED	if there is no match.  */
end_comment

begin_function_decl
name|dns_dns64_t
modifier|*
name|dns_dns64_next
parameter_list|(
name|dns_dns64_t
modifier|*
name|dns64
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the next dns64 record in the list.  */
end_comment

begin_function_decl
name|void
name|dns_dns64_append
parameter_list|(
name|dns_dns64list_t
modifier|*
name|list
parameter_list|,
name|dns_dns64_t
modifier|*
name|dns64
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Append the dns64 record to the list.  */
end_comment

begin_function_decl
name|void
name|dns_dns64_unlink
parameter_list|(
name|dns_dns64list_t
modifier|*
name|list
parameter_list|,
name|dns_dns64_t
modifier|*
name|dns64
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Unlink the dns64 record from the list.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_dns64_aaaaok
parameter_list|(
specifier|const
name|dns_dns64_t
modifier|*
name|dns64
parameter_list|,
specifier|const
name|isc_netaddr_t
modifier|*
name|reqaddr
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|reqsigner
parameter_list|,
specifier|const
name|dns_aclenv_t
modifier|*
name|env
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|isc_boolean_t
modifier|*
name|aaaaok
parameter_list|,
name|size_t
name|aaaaoklen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Determine if there are any non-excluded AAAA records in from the  * matching dns64 records in the list starting at 'dns64'.  If there  * is a non-exluded address return ISC_TRUE.  If all addresses are  * excluded in the matched records return ISC_FALSE.   If no records  * match then return ISC_TRUE.  *  * If aaaaok is defined then dns_dns64_aaaaok() return a array of which  * addresses in 'rdataset' were deemed to not be exclude by any matching  * record.  If there are no matching records then all entries are set  * to ISC_TRUE.  *  * Requires  * 	'rdataset'	to be valid and to be for type AAAA and class IN.  *	'aaaaoklen'	must match the number of records in 'rdataset'  *			if 'aaaaok' in non NULL.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DNS64_H */
end_comment

end_unit

