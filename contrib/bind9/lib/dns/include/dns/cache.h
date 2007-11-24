begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: cache.h,v 1.17.12.5 2006/03/02 00:37:20 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_CACHE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_CACHE_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * cache  *  * Defines dns_cache_t, the cache object.  *  * Notes:  * 	A cache object contains DNS data of a single class.  *	Multiple classes will be handled by creating multiple  *	views, each with a different class and its own cache.  *  * MP:  *	See notes at the individual functions.  *  * Reliability:  *  * Resources:  *  * Security:  *  * Standards:  */
end_comment

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Functions  ***/
name|isc_result_t
name|dns_cache_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
specifier|const
name|char
modifier|*
name|db_type
parameter_list|,
name|unsigned
name|int
name|db_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|db_argv
parameter_list|,
name|dns_cache_t
modifier|*
modifier|*
name|cachep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new DNS cache.  *  * Requires:  *  *	'mctx' is a valid memory context  *  *	'taskmgr' is a valid task manager and 'timermgr' is a valid timer  * 	manager, or both are NULL.  If NULL, no periodic cleaning of the  * 	cache will take place.  *  *	'cachep' is a valid pointer, and *cachep == NULL  *  * Ensures:  *  *	'*cachep' is attached to the newly created cache  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_cache_attach
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|dns_cache_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to cache.  *  * Requires:  *  *	'cache' is a valid cache.  *  *	'targetp' points to a NULL dns_cache_t *.  *  * Ensures:  *  *	*targetp is attached to cache.  */
end_comment

begin_function_decl
name|void
name|dns_cache_detach
parameter_list|(
name|dns_cache_t
modifier|*
modifier|*
name|cachep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *cachep from its cache.  *  * Requires:  *  *	'cachep' points to a valid cache.  *  * Ensures:  *  *	*cachep is NULL.  *  *	If '*cachep' is the last reference to the cache,  *  *		All resources used by the cache will be freed  */
end_comment

begin_function_decl
name|void
name|dns_cache_attachdb
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *dbp to the cache's database.  *  * Notes:  *  *	This may be used to get a reference to the database for  *	the purpose of cache lookups (XXX currently it is also  * 	the way to add data to the cache, but having a  * 	separate dns_cache_add() interface instead would allow  * 	more control over memory usage).  *	The caller should call dns_db_detach() on the reference  *	when it is no longer needed.  *  * Requires:  *  *	'cache' is a valid cache.  *  *	'dbp' points to a NULL dns_db *.  *  * Ensures:  *  *	*dbp is attached to the database.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_setfilename
parameter_list|(
name|dns_cache_t
modifier|*
name|cahce
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If 'filename' is non-NULL, make the cache persistent.  * The cache's data will be stored in the given file.  * If 'filename' is NULL, make the cache non-persistent.  * Files that are no longer used are not unlinked automatically.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	Various file-related failures  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_load
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the cache has a file name, load the cache contents from the file.  * Previous cache contents are not discarded.  * If no file name has been set, do nothing and return success.  *  * MT:  *	Multiple simultaneous attempts to load or dump the cache  * 	will be serialized with respect to one another, but  *	the cache may be read and updated while the dump is  *	in progress.  Updates performed during loading  *	may or may not be preserved, and reads may return  * 	either the old or the newly loaded data.  *  * Returns:  *  *	ISC_R_SUCCESS  *      Various failures depending on the database implementation type  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_dump
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the cache has a file name, write the cache contents to disk,  * overwriting any preexisting file.  If no file name has been set,  * do nothing and return success.  *  * MT:  *	Multiple simultaneous attempts to load or dump the cache  * 	will be serialized with respect to one another, but  *	the cache may be read and updated while the dump is  *	in progress.  Updates performed during the dump may  * 	or may not be reflected in the dumped file.  *  * Returns:  *  *	ISC_R_SUCCESS  *      Various failures depending on the database implementation type  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_clean
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Force immediate cleaning of the cache, freeing all rdatasets  * whose TTL has expired as of 'now' and that have no pending  * references.  */
end_comment

begin_function_decl
name|void
name|dns_cache_setcleaninginterval
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|unsigned
name|int
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the periodic cache cleaning interval to 'interval' seconds.  */
end_comment

begin_function_decl
name|void
name|dns_cache_setcachesize
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|isc_uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the maximum cache size.  0 means unlimited.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_flush
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flushes all data from the cache.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_cache_flushname
parameter_list|(
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flushes a given name from the cache.  *  * Requires:  *	'cache' to be valid.  *	'name' to be valid.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	other error returns.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_CACHE_H */
end_comment

end_unit

