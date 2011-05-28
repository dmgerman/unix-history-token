begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: stats.h,v 1.18.56.2 2009-01-29 23:47:44 tbox Exp $ */
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

begin_comment
comment|/*! \file dns/stats.h */
end_comment

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/*%  * Statistics counters.  Used as isc_statscounter_t values.  */
end_comment

begin_enum
enum|enum
block|{
comment|/*% 	 * Resolver statistics counters. 	 */
name|dns_resstatscounter_queryv4
init|=
literal|0
block|,
name|dns_resstatscounter_queryv6
init|=
literal|1
block|,
name|dns_resstatscounter_responsev4
init|=
literal|2
block|,
name|dns_resstatscounter_responsev6
init|=
literal|3
block|,
name|dns_resstatscounter_nxdomain
init|=
literal|4
block|,
name|dns_resstatscounter_servfail
init|=
literal|5
block|,
name|dns_resstatscounter_formerr
init|=
literal|6
block|,
name|dns_resstatscounter_othererror
init|=
literal|7
block|,
name|dns_resstatscounter_edns0fail
init|=
literal|8
block|,
name|dns_resstatscounter_mismatch
init|=
literal|9
block|,
name|dns_resstatscounter_truncated
init|=
literal|10
block|,
name|dns_resstatscounter_lame
init|=
literal|11
block|,
name|dns_resstatscounter_retry
init|=
literal|12
block|,
name|dns_resstatscounter_gluefetchv4
init|=
literal|13
block|,
name|dns_resstatscounter_gluefetchv6
init|=
literal|14
block|,
name|dns_resstatscounter_gluefetchv4fail
init|=
literal|15
block|,
name|dns_resstatscounter_gluefetchv6fail
init|=
literal|16
block|,
name|dns_resstatscounter_val
init|=
literal|17
block|,
name|dns_resstatscounter_valsuccess
init|=
literal|18
block|,
name|dns_resstatscounter_valnegsuccess
init|=
literal|19
block|,
name|dns_resstatscounter_valfail
init|=
literal|20
block|,
name|dns_resstatscounter_dispabort
init|=
literal|21
block|,
name|dns_resstatscounter_dispsockfail
init|=
literal|22
block|,
name|dns_resstatscounter_querytimeout
init|=
literal|23
block|,
name|dns_resstatscounter_queryrtt0
init|=
literal|24
block|,
name|dns_resstatscounter_queryrtt1
init|=
literal|25
block|,
name|dns_resstatscounter_queryrtt2
init|=
literal|26
block|,
name|dns_resstatscounter_queryrtt3
init|=
literal|27
block|,
name|dns_resstatscounter_queryrtt4
init|=
literal|28
block|,
name|dns_resstatscounter_queryrtt5
init|=
literal|29
block|,
name|dns_resstatscounter_max
init|=
literal|30
block|,
comment|/*% 	 * Zone statistics counters. 	 */
name|dns_zonestatscounter_notifyoutv4
init|=
literal|0
block|,
name|dns_zonestatscounter_notifyoutv6
init|=
literal|1
block|,
name|dns_zonestatscounter_notifyinv4
init|=
literal|2
block|,
name|dns_zonestatscounter_notifyinv6
init|=
literal|3
block|,
name|dns_zonestatscounter_notifyrej
init|=
literal|4
block|,
name|dns_zonestatscounter_soaoutv4
init|=
literal|5
block|,
name|dns_zonestatscounter_soaoutv6
init|=
literal|6
block|,
name|dns_zonestatscounter_axfrreqv4
init|=
literal|7
block|,
name|dns_zonestatscounter_axfrreqv6
init|=
literal|8
block|,
name|dns_zonestatscounter_ixfrreqv4
init|=
literal|9
block|,
name|dns_zonestatscounter_ixfrreqv6
init|=
literal|10
block|,
name|dns_zonestatscounter_xfrsuccess
init|=
literal|11
block|,
name|dns_zonestatscounter_xfrfail
init|=
literal|12
block|,
name|dns_zonestatscounter_max
init|=
literal|13
block|,
comment|/*% 	* Query statistics counters (obsolete). 	*/
name|dns_statscounter_success
init|=
literal|0
block|,
comment|/*%< Successful lookup */
name|dns_statscounter_referral
init|=
literal|1
block|,
comment|/*%< Referral result */
name|dns_statscounter_nxrrset
init|=
literal|2
block|,
comment|/*%< NXRRSET result */
name|dns_statscounter_nxdomain
init|=
literal|3
block|,
comment|/*%< NXDOMAIN result */
name|dns_statscounter_recursion
init|=
literal|4
block|,
comment|/*%< Recursion was used */
name|dns_statscounter_failure
init|=
literal|5
block|,
comment|/*%< Some other failure */
name|dns_statscounter_duplicate
init|=
literal|6
block|,
comment|/*%< Duplicate query */
name|dns_statscounter_dropped
init|=
literal|7
comment|/*%< Duplicate query (dropped) */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DNS_STATS_NCOUNTERS
value|8
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*%<  * Flag(s) for dns_xxxstats_dump().  DNS_STATSDUMP_VERBOSE is obsolete.  * ISC_STATSDUMP_VERBOSE should be used instead.  These two values are  * intentionally defined to be the same value to ensure binary compatibility.  */
end_comment

begin_define
define|#
directive|define
name|DNS_STATSDUMP_VERBOSE
value|0x00000001
end_define

begin_comment
comment|/*%< dump 0-value counters */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%<  * (Obsoleted)  */
end_comment

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

begin_comment
comment|/*%  * Attributes for statistics counters of RRset and Rdatatype types.  *  * _OTHERTYPE  *	The rdata type is not explicitly supported and the corresponding counter  *	is counted for other such types, too.  When this attribute is set,  *	the base type is of no use.  *  * _NXRRSET  * 	RRset type counters only.  Indicates the RRset is non existent.  *  * _NXDOMAIN  *	RRset type counters only.  Indicates a non existent name.  When this  *	attribute is set, the base type is of no use.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_ATTR_OTHERTYPE
value|0x0001
end_define

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_ATTR_NXRRSET
value|0x0002
end_define

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_ATTR_NXDOMAIN
value|0x0004
end_define

begin_comment
comment|/*%<  * Conversion macros among dns_rdatatype_t, attributes and isc_statscounter_t.  */
end_comment

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_BASE
parameter_list|(
name|type
parameter_list|)
value|((dns_rdatatype_t)((type)& 0xFFFF))
end_define

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_ATTR
parameter_list|(
name|type
parameter_list|)
value|((type)>> 16)
end_define

begin_define
define|#
directive|define
name|DNS_RDATASTATSTYPE_VALUE
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|)
value|(((a)<< 16) | (b))
end_define

begin_comment
comment|/*%<  * Types of dump callbacks.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_generalstats_dumper_t
function_decl|)
parameter_list|(
name|isc_statscounter_t
parameter_list|,
name|isc_uint64_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_rdatatypestats_dumper_t
function_decl|)
parameter_list|(
name|dns_rdatastatstype_t
parameter_list|,
name|isc_uint64_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_opcodestats_dumper_t
function_decl|)
parameter_list|(
name|dns_opcode_t
parameter_list|,
name|isc_uint64_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|dns_generalstats_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|,
name|int
name|ncounters
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a statistics counter structure of general type.  It counts a general  * set of counters indexed by an ID between 0 and ncounters -1.  * This function is obsolete.  A more general function, isc_stats_create(),  * should be used.  *  * Requires:  *\li	'mctx' must be a valid memory context.  *  *\li	'statsp' != NULL&& '*statsp' == NULL.  *  * Returns:  *\li	ISC_R_SUCCESS	-- all ok  *  *\li	anything else	-- failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatatypestats_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a statistics counter structure per rdatatype.  *  * Requires:  *\li	'mctx' must be a valid memory context.  *  *\li	'statsp' != NULL&& '*statsp' == NULL.  *  * Returns:  *\li	ISC_R_SUCCESS	-- all ok  *  *\li	anything else	-- failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_rdatasetstats_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a statistics counter structure per RRset.  *  * Requires:  *\li	'mctx' must be a valid memory context.  *  *\li	'statsp' != NULL&& '*statsp' == NULL.  *  * Returns:  *\li	ISC_R_SUCCESS	-- all ok  *  *\li	anything else	-- failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_opcodestats_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a statistics counter structure per opcode.  *  * Requires:  *\li	'mctx' must be a valid memory context.  *  *\li	'statsp' != NULL&& '*statsp' == NULL.  *  * Returns:  *\li	ISC_R_SUCCESS	-- all ok  *  *\li	anything else	-- failure  */
end_comment

begin_function_decl
name|void
name|dns_stats_attach
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach to a statistics set.  *  * Requires:  *\li	'stats' is a valid dns_stats_t.  *  *\li	'statsp' != NULL&& '*statsp' == NULL  */
end_comment

begin_function_decl
name|void
name|dns_stats_detach
parameter_list|(
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detaches from the statistics set.  *  * Requires:  *\li	'statsp' != NULL and '*statsp' is a valid dns_stats_t.  */
end_comment

begin_function_decl
name|void
name|dns_generalstats_increment
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|isc_statscounter_t
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the counter-th counter of stats.  This function is obsolete.  * A more general function, isc_stats_increment(), should be used.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_generalstats_create().  *  *\li	counter is less than the maximum available ID for the stats specified  *	on creation.  */
end_comment

begin_function_decl
name|void
name|dns_rdatatypestats_increment
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the statistics counter for 'type'.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_rdatatypestats_create().  */
end_comment

begin_function_decl
name|void
name|dns_rdatasetstats_increment
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_rdatastatstype_t
name|rrsettype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the statistics counter for 'rrsettype'.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_rdatasetstats_create().  */
end_comment

begin_function_decl
name|void
name|dns_rdatasetstats_decrement
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_rdatastatstype_t
name|rrsettype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Decrement the statistics counter for 'rrsettype'.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_rdatasetstats_create().  */
end_comment

begin_function_decl
name|void
name|dns_opcodestats_increment
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_opcode_t
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the statistics counter for 'code'.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_opcodestats_create().  */
end_comment

begin_function_decl
name|void
name|dns_generalstats_dump
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_generalstats_dumper_t
name|dump_fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the current statistics counters in a specified way.  For each counter  * in stats, dump_fn is called with its current value and the given argument  * arg.  By default counters that have a value of 0 is skipped; if options has  * the ISC_STATSDUMP_VERBOSE flag, even such counters are dumped.  *  * This function is obsolete.  A more general function, isc_stats_dump(),  * should be used.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_generalstats_create().  */
end_comment

begin_function_decl
name|void
name|dns_rdatatypestats_dump
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_rdatatypestats_dumper_t
name|dump_fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the current statistics counters in a specified way.  For each counter  * in stats, dump_fn is called with the corresponding type in the form of  * dns_rdatastatstype_t, the current counter value and the given argument  * arg.  By default counters that have a value of 0 is skipped; if options has  * the ISC_STATSDUMP_VERBOSE flag, even such counters are dumped.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_generalstats_create().  */
end_comment

begin_function_decl
name|void
name|dns_rdatasetstats_dump
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_rdatatypestats_dumper_t
name|dump_fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the current statistics counters in a specified way.  For each counter  * in stats, dump_fn is called with the corresponding type in the form of  * dns_rdatastatstype_t, the current counter value and the given argument  * arg.  By default counters that have a value of 0 is skipped; if options has  * the ISC_STATSDUMP_VERBOSE flag, even such counters are dumped.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_generalstats_create().  */
end_comment

begin_function_decl
name|void
name|dns_opcodestats_dump
parameter_list|(
name|dns_stats_t
modifier|*
name|stats
parameter_list|,
name|dns_opcodestats_dumper_t
name|dump_fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the current statistics counters in a specified way.  For each counter  * in stats, dump_fn is called with the corresponding opcode, the current  * counter value and the given argument arg.  By default counters that have a  * value of 0 is skipped; if options has the ISC_STATSDUMP_VERBOSE flag, even  * such counters are dumped.  *  * Requires:  *\li	'stats' is a valid dns_stats_t created by dns_generalstats_create().  */
end_comment

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
comment|/*%<  * Allocate an array of query statistics counters from the memory  * context 'mctx'.  *  * This function is obsoleted.  Use dns_xxxstats_create() instead.  */
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
comment|/*%<  * Free an array of query statistics counters allocated from the memory  * context 'mctx'.  *  * This function is obsoleted.  Use dns_stats_destroy() instead.  */
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

