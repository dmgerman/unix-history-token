begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009, 2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_STATS_H
value|1
end_define

begin_comment
comment|/*! \file isc/stats.h */
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*%<  * Flag(s) for isc_stats_dump().  */
end_comment

begin_define
define|#
directive|define
name|ISC_STATSDUMP_VERBOSE
value|0x00000001
end_define

begin_comment
comment|/*%< dump 0-value counters */
end_comment

begin_comment
comment|/*%<  * Dump callback type.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_stats_dumper_t
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

begin_function_decl
name|isc_result_t
name|isc_stats_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_stats_t
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
comment|/*%<  * Create a statistics counter structure of general type.  It counts a general  * set of counters indexed by an ID between 0 and ncounters -1.  *  * Requires:  *\li	'mctx' must be a valid memory context.  *  *\li	'statsp' != NULL&& '*statsp' == NULL.  *  * Returns:  *\li	ISC_R_SUCCESS	-- all ok  *  *\li	anything else	-- failure  */
end_comment

begin_function_decl
name|void
name|isc_stats_attach
parameter_list|(
name|isc_stats_t
modifier|*
name|stats
parameter_list|,
name|isc_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach to a statistics set.  *  * Requires:  *\li	'stats' is a valid isc_stats_t.  *  *\li	'statsp' != NULL&& '*statsp' == NULL  */
end_comment

begin_function_decl
name|void
name|isc_stats_detach
parameter_list|(
name|isc_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detaches from the statistics set.  *  * Requires:  *\li	'statsp' != NULL and '*statsp' is a valid isc_stats_t.  */
end_comment

begin_function_decl
name|int
name|isc_stats_ncounters
parameter_list|(
name|isc_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the number of counters contained in stats.  *  * Requires:  *\li	'stats' is a valid isc_stats_t.  *  */
end_comment

begin_function_decl
name|void
name|isc_stats_increment
parameter_list|(
name|isc_stats_t
modifier|*
name|stats
parameter_list|,
name|isc_statscounter_t
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Increment the counter-th counter of stats.  *  * Requires:  *\li	'stats' is a valid isc_stats_t.  *  *\li	counter is less than the maximum available ID for the stats specified  *	on creation.  */
end_comment

begin_function_decl
name|void
name|isc_stats_decrement
parameter_list|(
name|isc_stats_t
modifier|*
name|stats
parameter_list|,
name|isc_statscounter_t
name|counter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Decrement the counter-th counter of stats.  *  * Requires:  *\li	'stats' is a valid isc_stats_t.  */
end_comment

begin_function_decl
name|void
name|isc_stats_dump
parameter_list|(
name|isc_stats_t
modifier|*
name|stats
parameter_list|,
name|isc_stats_dumper_t
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
comment|/*%<  * Dump the current statistics counters in a specified way.  For each counter  * in stats, dump_fn is called with its current value and the given argument  * arg.  By default counters that have a value of 0 is skipped; if options has  * the ISC_STATSDUMP_VERBOSE flag, even such counters are dumped.  *  * Requires:  *\li	'stats' is a valid isc_stats_t.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_STATS_H */
end_comment

end_unit

