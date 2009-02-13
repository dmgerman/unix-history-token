begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2006  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: acache.h,v 1.3.2.4 2006/05/03 00:07:49 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ACACHE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ACACHE_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Acache  *   * The Additional Cache Object  *  *	This module manages internal caching entries that correspond to  *	the additional section data of a DNS DB node (an RRset header, more  *	accurately).  An additional cache entry is expected to be (somehow)  *	attached to a particular RR in a particular DB node, and contains a set  *	of information of an additional data for the DB node.  *  *	An additional cache object is intended to be created as a per-view  *	object, and manages all cache entries within the view.  *  *	The intended usage of the additional caching is to provide a short cut  *	to additional glue RRs of an NS RR.  For each NS RR, it is often  *	necessary to look for glue RRs to make a proper response.  Once the  *	glue RRs are known, the additional caching allows the client to  *	associate the information to the original NS RR so that further  *	expensive lookups can be avoided for the NS RR.  *  *	Each additional cache entry contains information to identify a  *	particular DB node and (optionally) an associated RRset.  The  *	information consists of its zone, database, the version of the  *	database, database node, and RRset.  *  *	A "negative" information can also be cached.  For example, if a glue  *	RR does not exist as an authoritative data in the same zone as that  *	of the NS RR, this fact can be cached by specifying a NULL pointer  *	for the database, version, and node.  (See the description for  *	dns_acache_getentry() below for more details.)  *  *	Since each member stored in an additional cache entry holds a reference  *	to a corresponding object, a stale cache entry may cause unnecessary  *	memory consumption.  For instance, when a zone is reloaded, additional  *	cache entries that have a reference to the zone (and its DB and/or  *	DB nodes) can delay the cleanup of the referred objects.  In order to  *	minimize such a bad effect, this module provides several cleanup  *	mechanisms.  *  *	The first one is a shutdown procedure called when the associated view  *	is shut down.  In this case, dns_acache_shutdown() will be called and  *	all cache entries will be purged.  This mechanism will help the  *	situation when the configuration is reloaded or the main server is  *	stopped.  *  *	Per-DB cleanup mechanism is also provided.  Each additional cache entry  *	is associated with related DB, which is expected to have been  *	registered when the DB was created by dns_acache_setdb().  If a  *	particular DB is going to be destroyed, the primary holder of the DB,  *	a typical example of which is a zone, will call dns_acache_putdb().  *	Then this module will clean-up all cache entries associated with the  *	DB.  This mechanism is effective when a secondary zone DB is going to  *	be stale after a zone transfer.  *  *	Finally, this module supports for periodic clean-up of stale entries.  *	Each cache entry has a timestamp field, which is updated every time  *	the entry is referred.  A periodically invoked cleaner checks the  *	timestamp of each entry, and purge entries that have not been referred  *	for a certain period.  The cleaner interval can be specified by  *	dns_acache_setcleaninginterval().  If the periodic clean-up is not  *	enough, it is also possible to specify the upper limit of entries  *	in terms of the memory consumption.  If the maximum value is  *	specified, the cleaner is invoked when the memory consumption reaches  *	the high watermark inferred from the maximum value.  In this case,  *	the cleaner will use more aggressive algorithm to decide the "victim"  *	entries.  The maximum value can be specified by  *	dns_acache_setcachesize().  *  *	When a cache entry is going to be purged within this module, the  *	callback function specified at the creation time will be called.  *	The callback function is expected to release all internal resources  *	related to the entry, which will typically be specific to DB  *	implementation, and to call dns_acache_detachentry().  The callback  *	mechanism is very important, since the holder of an additional cache  *	entry may not be able to initiate the clean-up of the entry, due to  *	the reference ordering.  For example, as long as an additional cache  *	entry has a reference to a DB object, the DB cannot be freed, in which  *	a DB node may have a reference to the cache entry.  *  *	Credits:  *	The basic idea of this kind of short-cut for frequently used  *	information is similar to the "pre-compiled answer" approach adopted  *	in nsd by NLnet LABS with RIPE NCC.  Our work here is an independent  *	effort, but the success of nsd encouraged us to pursue this path.  *  *	The design and implementation of the periodic memory management and  *	the upper limitation of memory consumption was derived from the cache  *	DB implementation of BIND9.  *  * MP:  *	There are two main locks in this module.  One is for each entry, and  *	the other is for the additional cache object.  *  * Reliability:  *	The callback function for a cache entry is called with holding the  *	entry lock.  Thus, it implicitly assumes the callback function does not  *	call a function that can require the lock.  Typically, the only  *	function that can be called from the callback function safely is  *	dns_acache_detachentry().  The breakage of this implicit assumption  *	may cause a deadlock.  *  * Resources:  *	In a 32-bit architecture (such as i386), the following additional  *	memory is required comparing to the case that disables this module.  *	- 76 bytes for each additional cache entry  *	- if the entry has a DNS name and associated RRset,  *	  * 44 bytes + size of the name (1-255 bytes)  *	  * 52 bytes x number_of_RRs   *	- 28 bytes for each DB related to this module  *  *	Using the additional cache also requires extra memory consumption in  *	the DB implementation.  In the current implementation for rbtdb, we  *	need:  *	- two additional pointers for each DB node (8 bytes for a 32-bit  *	  architecture  *	- for each RR associated to an RR in a DB node, we also need  *	  a pointer and management objects to support the additional cache  *	  function.  These are allocated on-demand.  The total size is  *	  32 bytes for a 32-bit architecture.  *  * Security:  *	Since this module does not handle any low-level data directly,  *	no security issue specific to this module is anticipated.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
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

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|dns_acache_create
parameter_list|(
name|dns_acache_t
modifier|*
modifier|*
name|acachep
parameter_list|,
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new DNS additional cache object.  *  * Requires:  *  *	'mctx' is a valid memory context  *  *	'taskmgr' is a valid task manager  *  *	'timermgr' is a valid timer or NULL.  If NULL, no periodic cleaning of  *	the cache will take place.  *  *	'acachep' is a valid pointer, and *acachep == NULL  *  * Ensures:  *  *	'*acachep' is attached to the newly created cache  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|dns_acache_attach
parameter_list|(
name|dns_acache_t
modifier|*
name|source
parameter_list|,
name|dns_acache_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to cache.  *  * Requires:  *  *	'acache' is a valid additional cache.  *  *	'targetp' points to a NULL dns_acache_t *.  *  * Ensures:  *  *	*targetp is attached to the 'source' additional cache.  */
end_comment

begin_function_decl
name|void
name|dns_acache_detach
parameter_list|(
name|dns_acache_t
modifier|*
modifier|*
name|acachep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *acachep from its cache.  *  * Requires:  *  *	'*acachep' points to a valid additional cache.  *  * Ensures:  *  *	*acachep is NULL.  *  *	If '*acachep' is the last reference to the cache and the additional  *	cache does not have an outstanding task, all resources used by the  *	cache will be freed.  */
end_comment

begin_function_decl
name|void
name|dns_acache_setcleaninginterval
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|unsigned
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the periodic cleaning interval of an additional cache to 'interval'  * seconds.  */
end_comment

begin_function_decl
name|void
name|dns_acache_setcachesize
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|isc_uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the maximum additional cache size.  0 means unlimited.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acache_setdb
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set 'db' in 'acache' when the db can be referred from acache, in order  * to provide a hint for resolving the back reference.  *  * Requires:  *	'acache' is a valid acache pointer.  *	'db' is a valid DNS DB pointer.  *  * Ensures:  *	'acache' will have a reference to 'db'.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_EXISTS	(which means the specified 'db' is already set)  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acache_putdb
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release 'db' from 'acache' if it has been set by dns_acache_setdb().  *  * Requires:  *	'acache' is a valid acache pointer.  *	'db' is a valid DNS DB pointer.  *  * Ensures:  *	'acache' will release the reference to 'db'.  Additionally, the content  *	of each cache entry that is related to the 'db' will be released via  *	the callback function.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND	(which means the specified 'db' is not set in 'acache')  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_acache_shutdown
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shutdown 'acache'.  *  * Requires:  *  * 	'*acache' is a valid additional cache.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acache_createentry
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_db_t
modifier|*
name|origdb
parameter_list|,
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|dns_acacheentry_t
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|,
name|dns_acacheentry_t
modifier|*
modifier|*
name|entryp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an additional cache entry.  A new entry is created and attached to  * the given additional cache object.  A callback function is also associated  * with the created entry, which will be called when the cache entry is purged  * for some reason.  *  * Requires:  *  * 	'acache' is a valid additional cache.  *	'entryp' is a valid pointer, and *entryp == NULL  *	'origdb' is a valid DNS DB pointer.  *	'callback' and 'cbarg' can be NULL.  In this case, however, the entry  *	is meaningless (and will be cleaned-up in the next periodical  *	cleaning).  *  * Ensures:  *	'*entryp' will point to a new additional cache entry.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acache_getentry
parameter_list|(
name|dns_acacheentry_t
modifier|*
name|entry
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get content from a particular additional cache entry.  *  * Requires:  *  * 	'entry' is a valid additional cache entry.  *	'zonep' is a NULL pointer or '*zonep' == NULL (this is the only  *	optional parameter.)  *	'dbp' is a valid pointer, and '*dbp' == NULL  *	'versionp' is a valid pointer, and '*versionp' == NULL  *	'nodep' is a valid pointer, and '*nodep' == NULL  *	'fname' is a valid DNS name.  *	'msg' is a valid DNS message.  *  * Ensures:  *	Several possible cases can happen according to the content.  *	1. For a positive cache entry,  *	'*zonep' will point to the corresponding zone (if zonep is a valid  *	pointer),  *	'*dbp' will point to a DB for the zone,  *	'*versionp' will point to its version, and  *	'*nodep' will point to the corresponding DB node.  *	'fname' will have the DNS name of the DB node and contain a list of  *	rdataset for the node (which can be an empty list).  *  * 	2. For a negative cache entry that means no corresponding zone exists,  *	'*zonep' == NULL (if zonep is a valid pointer)  *	'*dbp', '*versionp', and '*nodep' will be NULL.  *  *	3. For a negative cache entry that means no corresponding DB node  *	exists, '*zonep' will point to the corresponding zone (if zonep is a  *	valid pointer),  *	'*dbp' will point to a corresponding DB for zone,  *	'*versionp' will point to its version.  *	'*nodep' will be kept as NULL.  *	'fname' will not change.  *  *	On failure, no new references will be created.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_acache_setentry
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|,
name|dns_acacheentry_t
modifier|*
name|entry
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set content to a particular additional cache entry.  *  * Requires:  *	'acache' is a valid additional cache.  *	'entry' is a valid additional cache entry.  *	All the others pointers are NULL or a valid pointer of the  *	corresponding type.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|void
name|dns_acache_cancelentry
parameter_list|(
name|dns_acacheentry_t
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancel the use of the cache entry 'entry'.  This function is supposed to  * be called when the node that holds the entry finds the content is not  * correct any more.  This function will try to release as much dependency as  * possible, and will be ready to be cleaned-up.  The registered callback  * function will be canceled and will never called.  *  * Requires:  *	'entry' is a valid additional cache entry.  */
end_comment

begin_function_decl
name|void
name|dns_acache_attachentry
parameter_list|(
name|dns_acacheentry_t
modifier|*
name|source
parameter_list|,
name|dns_acacheentry_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to the cache entry 'source'.  *  * Requires:  *  *	'source' is a valid additional cache entry.  *  *	'targetp' points to a NULL dns_acacheentry_t *.  *  * Ensures:  *  *	*targetp is attached to 'source'.  */
end_comment

begin_function_decl
name|void
name|dns_acache_detachentry
parameter_list|(
name|dns_acacheentry_t
modifier|*
modifier|*
name|entryp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *entryp from its cache.  *  * Requires:  *  *	'*entryp' points to a valid additional cache entry.  *  * Ensures:  *  *	*entryp is NULL.  *  *	If '*entryp' is the last reference to the entry,   *	cache does not have an outstanding task, all resources used by the  *	entry (including the entry object itself) will be freed.  */
end_comment

begin_function_decl
name|void
name|dns_acache_countquerymiss
parameter_list|(
name|dns_acache_t
modifier|*
name|acache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Count up a missed acache query.  XXXMLG need more docs.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ACACHE_H */
end_comment

end_unit

