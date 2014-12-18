begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_VIEW_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_VIEW_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file dns/view.h  * \brief  * DNS View  *  * A "view" is a DNS namespace, together with an optional resolver and a  * forwarding policy.  A "DNS namespace" is a (possibly empty) set of  * authoritative zones together with an optional cache and optional  * "hints" information.  *  * Views start out "unfrozen".  In this state, core attributes like  * the cache, set of zones, and forwarding policy may be set.  While  * "unfrozen", the caller (e.g. nameserver configuration loading  * code), must ensure exclusive access to the view.  When the view is  * "frozen", the core attributes become immutable, and the view module  * will ensure synchronization.  Freezing allows the view's core attributes  * to be accessed without locking.  *  * MP:  *\li	Before the view is frozen, the caller must ensure synchronization.  *  *\li	After the view is frozen, the module guarantees appropriate  *	synchronization of any data structures it creates and manipulates.  *  * Reliability:  *\li	No anticipated impact.  *  * Resources:  *\li	TBS  *  * Security:  *\li	No anticipated impact.  *  * Standards:  *\li	None.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/mutex.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isc/refcount.h>
end_include

begin_include
include|#
directive|include
file|<isc/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/acl.h>
end_include

begin_include
include|#
directive|include
file|<dns/fixedname.h>
end_include

begin_include
include|#
directive|include
file|<dns/rrl.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdatastruct.h>
end_include

begin_include
include|#
directive|include
file|<dns/rpz.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/zt.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_struct
struct|struct
name|dns_view
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|dns_zt_t
modifier|*
name|zonetable
decl_stmt|;
name|dns_dlzdb_t
modifier|*
name|dlzdatabase
decl_stmt|;
name|dns_resolver_t
modifier|*
name|resolver
decl_stmt|;
name|dns_adb_t
modifier|*
name|adb
decl_stmt|;
name|dns_requestmgr_t
modifier|*
name|requestmgr
decl_stmt|;
name|dns_acache_t
modifier|*
name|acache
decl_stmt|;
name|dns_cache_t
modifier|*
name|cache
decl_stmt|;
name|dns_db_t
modifier|*
name|cachedb
decl_stmt|;
name|dns_db_t
modifier|*
name|hints
decl_stmt|;
comment|/* 	 * security roots. 	 * internal use only; access via * dns_view_getsecroots() 	 */
name|dns_keytable_t
modifier|*
name|secroots_priv
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
name|isc_boolean_t
name|frozen
decl_stmt|;
name|isc_task_t
modifier|*
name|task
decl_stmt|;
name|isc_event_t
name|resevent
decl_stmt|;
name|isc_event_t
name|adbevent
decl_stmt|;
name|isc_event_t
name|reqevent
decl_stmt|;
name|isc_stats_t
modifier|*
name|resstats
decl_stmt|;
name|dns_stats_t
modifier|*
name|resquerystats
decl_stmt|;
name|isc_boolean_t
name|cacheshared
decl_stmt|;
comment|/* Configurable data. */
name|dns_tsig_keyring_t
modifier|*
name|statickeys
decl_stmt|;
name|dns_tsig_keyring_t
modifier|*
name|dynamickeys
decl_stmt|;
name|dns_peerlist_t
modifier|*
name|peers
decl_stmt|;
name|dns_order_t
modifier|*
name|order
decl_stmt|;
name|dns_fwdtable_t
modifier|*
name|fwdtable
decl_stmt|;
name|isc_boolean_t
name|recursion
decl_stmt|;
name|isc_boolean_t
name|auth_nxdomain
decl_stmt|;
name|isc_boolean_t
name|additionalfromcache
decl_stmt|;
name|isc_boolean_t
name|additionalfromauth
decl_stmt|;
name|isc_boolean_t
name|minimalresponses
decl_stmt|;
name|isc_boolean_t
name|enablednssec
decl_stmt|;
name|isc_boolean_t
name|enablevalidation
decl_stmt|;
name|isc_boolean_t
name|acceptexpired
decl_stmt|;
name|dns_transfer_format_t
name|transfer_format
decl_stmt|;
name|dns_acl_t
modifier|*
name|cacheacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|cacheonacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|queryacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|queryonacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|recursionacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|recursiononacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|sortlist
decl_stmt|;
name|dns_acl_t
modifier|*
name|notifyacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|transferacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|updateacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|upfwdacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|denyansweracl
decl_stmt|;
name|dns_acl_t
modifier|*
name|nocasecompress
decl_stmt|;
name|dns_rbt_t
modifier|*
name|answeracl_exclude
decl_stmt|;
name|dns_rbt_t
modifier|*
name|denyanswernames
decl_stmt|;
name|dns_rbt_t
modifier|*
name|answernames_exclude
decl_stmt|;
name|dns_rrl_t
modifier|*
name|rrl
decl_stmt|;
name|isc_boolean_t
name|provideixfr
decl_stmt|;
name|isc_boolean_t
name|requestnsid
decl_stmt|;
name|dns_ttl_t
name|maxcachettl
decl_stmt|;
name|dns_ttl_t
name|maxncachettl
decl_stmt|;
name|in_port_t
name|dstport
decl_stmt|;
name|dns_aclenv_t
name|aclenv
decl_stmt|;
name|dns_rdatatype_t
name|preferred_glue
decl_stmt|;
name|isc_boolean_t
name|flush
decl_stmt|;
name|dns_namelist_t
modifier|*
name|delonly
decl_stmt|;
name|isc_boolean_t
name|rootdelonly
decl_stmt|;
name|dns_namelist_t
modifier|*
name|rootexclude
decl_stmt|;
name|isc_boolean_t
name|checknames
decl_stmt|;
name|dns_name_t
modifier|*
name|dlv
decl_stmt|;
name|dns_fixedname_t
name|dlv_fixed
decl_stmt|;
name|isc_uint16_t
name|maxudp
decl_stmt|;
name|unsigned
name|int
name|maxbits
decl_stmt|;
name|dns_v4_aaaa_t
name|v4_aaaa
decl_stmt|;
name|dns_acl_t
modifier|*
name|v4_aaaa_acl
decl_stmt|;
name|dns_dns64list_t
name|dns64
decl_stmt|;
name|unsigned
name|int
name|dns64cnt
decl_stmt|;
name|ISC_LIST
argument_list|(
argument|dns_rpz_zone_t
argument_list|)
name|rpz_zones
expr_stmt|;
name|isc_boolean_t
name|rpz_recursive_only
decl_stmt|;
name|isc_boolean_t
name|rpz_break_dnssec
decl_stmt|;
name|unsigned
name|int
name|rpz_min_ns_labels
decl_stmt|;
comment|/* 	 * Configurable data for server use only, 	 * locked by server configuration lock. 	 */
name|dns_acl_t
modifier|*
name|matchclients
decl_stmt|;
name|dns_acl_t
modifier|*
name|matchdestinations
decl_stmt|;
name|isc_boolean_t
name|matchrecursiveonly
decl_stmt|;
comment|/* Locked by themselves. */
name|isc_refcount_t
name|references
decl_stmt|;
comment|/* Locked by lock. */
name|unsigned
name|int
name|weakrefs
decl_stmt|;
name|unsigned
name|int
name|attributes
decl_stmt|;
comment|/* Under owner's locking control. */
name|ISC_LINK
argument_list|(
argument|struct dns_view
argument_list|)
name|link
expr_stmt|;
name|dns_viewlist_t
modifier|*
name|viewlist
decl_stmt|;
name|dns_zone_t
modifier|*
name|managed_keys
decl_stmt|;
name|dns_zone_t
modifier|*
name|redirect
decl_stmt|;
ifdef|#
directive|ifdef
name|BIND9
comment|/* File in which to store configuration for newly added zones */
name|char
modifier|*
name|new_zone_file
decl_stmt|;
name|void
modifier|*
name|new_zone_config
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cfg_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_VIEW_MAGIC
value|ISC_MAGIC('V','i','e','w')
end_define

begin_define
define|#
directive|define
name|DNS_VIEW_VALID
parameter_list|(
name|view
parameter_list|)
value|ISC_MAGIC_VALID(view, DNS_VIEW_MAGIC)
end_define

begin_define
define|#
directive|define
name|DNS_VIEWATTR_RESSHUTDOWN
value|0x01
end_define

begin_define
define|#
directive|define
name|DNS_VIEWATTR_ADBSHUTDOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|DNS_VIEWATTR_REQSHUTDOWN
value|0x04
end_define

begin_function_decl
name|isc_result_t
name|dns_view_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|dns_view_t
modifier|*
modifier|*
name|viewp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a view.  *  * Notes:  *  *\li	The newly created view has no cache, no resolver, and an empty  *	zone table.  The view is not frozen.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'rdclass' is a valid class.  *  *\li	'name' is a valid C string.  *  *\li	viewp != NULL&& *viewp == NULL  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *  *\li	Other errors are possible.  */
end_comment

begin_function_decl
name|void
name|dns_view_attach
parameter_list|(
name|dns_view_t
modifier|*
name|source
parameter_list|,
name|dns_view_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach '*targetp' to 'source'.  *  * Requires:  *  *\li	'source' is a valid, frozen view.  *  *\li	'targetp' points to a NULL dns_view_t *.  *  * Ensures:  *  *\li	*targetp is attached to source.  *  *\li	While *targetp is attached, the view will not shut down.  */
end_comment

begin_function_decl
name|void
name|dns_view_detach
parameter_list|(
name|dns_view_t
modifier|*
modifier|*
name|viewp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach '*viewp' from its view.  *  * Requires:  *  *\li	'viewp' points to a valid dns_view_t *  *  * Ensures:  *  *\li	*viewp is NULL.  */
end_comment

begin_function_decl
name|void
name|dns_view_flushanddetach
parameter_list|(
name|dns_view_t
modifier|*
modifier|*
name|viewp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach '*viewp' from its view.  If this was the last reference  * uncommitted changed in zones will be flushed to disk.  *  * Requires:  *  *\li	'viewp' points to a valid dns_view_t *  *  * Ensures:  *  *\li	*viewp is NULL.  */
end_comment

begin_function_decl
name|void
name|dns_view_weakattach
parameter_list|(
name|dns_view_t
modifier|*
name|source
parameter_list|,
name|dns_view_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Weakly attach '*targetp' to 'source'.  *  * Requires:  *  *\li	'source' is a valid, frozen view.  *  *\li	'targetp' points to a NULL dns_view_t *.  *  * Ensures:  *  *\li	*targetp is attached to source.  *  * \li	While *targetp is attached, the view will not be freed.  */
end_comment

begin_function_decl
name|void
name|dns_view_weakdetach
parameter_list|(
name|dns_view_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach '*viewp' from its view.  *  * Requires:  *  *\li	'viewp' points to a valid dns_view_t *.  *  * Ensures:  *  *\li	*viewp is NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_createresolver
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|unsigned
name|int
name|ntasks
parameter_list|,
name|unsigned
name|int
name|ndisp
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_dispatchmgr_t
modifier|*
name|dispatchmgr
parameter_list|,
name|dns_dispatch_t
modifier|*
name|dispatchv4
parameter_list|,
name|dns_dispatch_t
modifier|*
name|dispatchv6
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a resolver and address database for the view.  *  * Requires:  *  *\li	'view' is a valid, unfrozen view.  *  *\li	'view' does not have a resolver already.  *  *\li	The requirements of dns_resolver_create() apply to 'taskmgr',  *	'ntasks', 'socketmgr', 'timermgr', 'options', 'dispatchv4', and  *	'dispatchv6'.  *  * Returns:  *  *\li   	#ISC_R_SUCCESS  *  *\li	Any error that dns_resolver_create() can return.  */
end_comment

begin_function_decl
name|void
name|dns_view_setcache
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_cache_t
modifier|*
name|cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_view_setcache2
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_cache_t
modifier|*
name|cache
parameter_list|,
name|isc_boolean_t
name|shared
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the view's cache database.  If 'shared' is true, this means the cache  * is created by another view and is shared with that view.  dns_view_setcache()  * is a backward compatible version equivalent to setcache2(..., ISC_FALSE).  *  * Requires:  *  *\li	'view' is a valid, unfrozen view.  *  *\li	'cache' is a valid cache.  *  * Ensures:  *  * \li    	The cache of 'view' is 'cached.  *  *\li	If this is not the first call to dns_view_setcache() for this  *	view, then previously set cache is detached.  */
end_comment

begin_function_decl
name|void
name|dns_view_sethints
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_db_t
modifier|*
name|hints
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the view's hints database.  *  * Requires:  *  *\li	'view' is a valid, unfrozen view, whose hints database has not been  *	set.  *  *\li	'hints' is a valid zone database.  *  * Ensures:  *  * \li    	The hints database of 'view' is 'hints'.  */
end_comment

begin_function_decl
name|void
name|dns_view_setkeyring
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_view_setdynamickeyring
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
name|ring
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the view's static TSIG keys  *  * Requires:  *  *   \li   'view' is a valid, unfrozen view, whose static TSIG keyring has not  *	been set.  *  *\li      'ring' is a valid TSIG keyring  *  * Ensures:  *  *\li      The static TSIG keyring of 'view' is 'ring'.  */
end_comment

begin_function_decl
name|void
name|dns_view_getdynamickeyring
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_tsig_keyring_t
modifier|*
modifier|*
name|ringp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the views dynamic keys.  *  *   \li  'view' is a valid, unfrozen view.  *   \li  'ringp' != NULL&& ringp == NULL.  */
end_comment

begin_function_decl
name|void
name|dns_view_setdstport
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|in_port_t
name|dstport
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the view's destination port.  This is the port to  * which outgoing queries are sent.  The default is 53,  * the standard DNS port.  *  * Requires:  *  *\li      'view' is a valid view.  *  *\li      'dstport' is a valid TCP/UDP port number.  *  * Ensures:  *\li	External name servers will be assumed to be listening  *	on 'dstport'.  For servers whose address has already  *	obtained obtained at the time of the call, the view may  *	continue to use the previously set port until the address  *	times out from the view's address database.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_addzone
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add zone 'zone' to 'view'.  *  * Requires:  *  *\li	'view' is a valid, unfrozen view.  *  *\li	'zone' is a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_view_freeze
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Freeze view.  No changes can be made to view configuration while frozen.  *  * Requires:  *  *\li	'view' is a valid, unfrozen view.  *  * Ensures:  *  *\li	'view' is frozen.  */
end_comment

begin_function_decl
name|void
name|dns_view_thaw
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Thaw view.  This allows zones to be added or removed at runtime.  This is  * NOT thread-safe; the caller MUST have run isc_task_exclusive() prior to  * thawing the view.  *  * Requires:  *  *\li	'view' is a valid, frozen view.  *  * Ensures:  *  *\li	'view' is no longer frozen.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_find
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_boolean_t
name|use_hints
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_view_find2
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_boolean_t
name|use_hints
parameter_list|,
name|isc_boolean_t
name|use_static_stub
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find an rdataset whose owner name is 'name', and whose type is  * 'type'.  * In general, this function first searches view's zone and cache DBs for the  * best match data against 'name'.  If nothing found there, and if 'use_hints'  * is ISC_TRUE, the view's hint DB (if configured) is searched.  * If the view is configured with a static-stub zone which gives the longest  * match for 'name' among the zones, however, the cache DB is not consulted  * unless 'use_static_stub' is ISC_FALSE (see below about this argument).  *  * dns_view_find() is a backward compatible version equivalent to  * dns_view_find2() with use_static_stub argument being ISC_FALSE.  *  * Notes:  *  *\li	See the description of dns_db_find() for information about 'options'.  *	If the caller sets #DNS_DBFIND_GLUEOK, it must ensure that 'name'  *	and 'type' are appropriate for glue retrieval.  *  *\li	If 'now' is zero, then the current time will be used.  *  *\li	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  If the answer is found in the hints  *	database, the result code will be DNS_R_HINT.  If the name is found  *	in the hints database but not the type, the result code will be  *	#DNS_R_HINTNXRRSET.  *  *\li	If 'use_static_stub' is ISC_FALSE and the longest match zone for 'name'  *	is a static-stub zone, it's ignored and the cache and/or hints will be  *	searched.  In the majority of the cases this argument should be  *	ISC_FALSE.  The only known usage of this argument being ISC_TRUE is  *	if this search is for a "bailiwick" glue A or AAAA RRset that may  *	best match a static-stub zone.  Consider the following example:  *	this view is configured with a static-stub zone "example.com",  *	and an attempt of recursive resolution needs to send a query for the  *	zone.  In this case it's quite likely that the resolver is trying to  *	find A/AAAA RRs for the apex name "example.com".  And, to honor the  *	static-stub configuration it needs to return the glue RRs in the  *	static-stub zone even if that exact RRs coming from the authoritative  *	zone has been cached.  *	In other general cases, the requested data is better to be  *	authoritative, either locally configured or retrieved from an external  *	server, and the data in the static-stub zone should better be ignored.  *  *\li	'foundname' must meet the requirements of dns_db_find().  *  *\li	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  * Requires:  *  *\li	'view' is a valid, frozen view.  *  *\li	'name' is valid name.  *  *\li	'type' is a valid dns_rdatatype_t, and is not a meta query type  *	except dns_rdatatype_any.  *  *\li	dbp == NULL || *dbp == NULL  *  *\li	nodep == NULL || *nodep == NULL.  If nodep != NULL, dbp != NULL.  *  *\li	'foundname' is a valid name with a dedicated buffer or NULL.  *  *\li	'rdataset' is a valid, disassociated rdataset.  *  *\li	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Ensures:  *  *\li	In successful cases, 'rdataset', and possibly 'sigrdataset', are  *	bound to the found data.  *  *\li	If dbp != NULL, it points to the database containing the data.  *  *\li	If nodep != NULL, it points to the database node containing the data.  *  *\li	If foundname != NULL, it contains the full name of the found data.  *  * Returns:  *  *\li	Any result that dns_db_find() can return, with the exception of  *	#DNS_R_DELEGATION.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_simplefind
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_boolean_t
name|use_hints
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find an rdataset whose owner name is 'name', and whose type is  * 'type'.  *  * Notes:  *  *\li	This routine is appropriate for simple, exact-match queries of the  *	view.  'name' must be a canonical name; there is no DNAME or CNAME  *	processing.  *  *\li	See the description of dns_db_find() for information about 'options'.  *	If the caller sets DNS_DBFIND_GLUEOK, it must ensure that 'name'  *	and 'type' are appropriate for glue retrieval.  *  *\li	If 'now' is zero, then the current time will be used.  *  *\li	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  If the answer is found in the hints  *	database, the result code will be DNS_R_HINT.  If the name is found  *	in the hints database but not the type, the result code will be  *	DNS_R_HINTNXRRSET.  *  *\li	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  * Requires:  *  *\li	'view' is a valid, frozen view.  *  *\li	'name' is valid name.  *  *\li	'type' is a valid dns_rdatatype_t, and is not a meta query type  *	(e.g. dns_rdatatype_any), or dns_rdatatype_rrsig.  *  *\li	'rdataset' is a valid, disassociated rdataset.  *  *\li	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Ensures:  *  *\li	In successful cases, 'rdataset', and possibly 'sigrdataset', are  *	bound to the found data.  *  * Returns:  *  *\li	#ISC_R_SUCCESS			Success; result is desired type.  *\li	DNS_R_GLUE			Success; result is glue.  *\li	DNS_R_HINT			Success; result is a hint.  *\li	DNS_R_NCACHENXDOMAIN		Success; result is a ncache entry.  *\li	DNS_R_NCACHENXRRSET		Success; result is a ncache entry.  *\li	DNS_R_NXDOMAIN			The name does not exist.  *\li	DNS_R_NXRRSET			The rrset does not exist.  *\li	#ISC_R_NOTFOUND			No matching data found,  *					or an error occurred.  */
end_comment

begin_comment
comment|/*% See dns_view_findzonecut2() */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_findzonecut
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_boolean_t
name|use_hints
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_view_findzonecut2
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|fname
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_boolean_t
name|use_hints
parameter_list|,
name|isc_boolean_t
name|use_cache
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the best known zonecut containing 'name'.  *  * This uses local authority, cache, and optionally hints data.  * No external queries are performed.  *  * Notes:  *  *\li	If 'now' is zero, then the current time will be used.  *  *\li	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  *  *\li	If 'use_cache' is ISC_TRUE, and the view has a cache, then it will be  *	searched.  *  *\li	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  *\li	If the DNS_DBFIND_NOEXACT option is set, then the zonecut returned  *	(if any) will be the deepest known ancestor of 'name'.  *  * Requires:  *  *\li	'view' is a valid, frozen view.  *  *\li	'name' is valid name.  *  *\li	'rdataset' is a valid, disassociated rdataset.  *  *\li	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Returns:  *  *\li	#ISC_R_SUCCESS				Success.  *  *\li	Many other results are possible.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_viewlist_find
parameter_list|(
name|dns_viewlist_t
modifier|*
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_view_t
modifier|*
modifier|*
name|viewp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search for a view with name 'name' and class 'rdclass' in 'list'.  * If found, '*viewp' is (strongly) attached to it.  *  * Requires:  *  *\li	'viewp' points to a NULL dns_view_t *.  *  * Returns:  *  *\li	#ISC_R_SUCCESS		A matching view was found.  *\li	#ISC_R_NOTFOUND		No matching view was found.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_viewlist_findzone
parameter_list|(
name|dns_viewlist_t
modifier|*
name|list
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|allclasses
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search zone with 'name' in view with 'rdclass' in viewlist 'list'  * If found, zone is returned in *zonep. If allclasses is set rdclass is ignored  *  * Returns:  *\li	#ISC_R_SUCCESS          A matching zone was found.  *\li	#ISC_R_NOTFOUND         No matching zone was found.  *\li	#ISC_R_MULTIPLE         Multiple zones with the same name were found.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_findzone
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Search for the zone 'name' in the zone table of 'view'.  * If found, 'zonep' is (strongly) attached to it.  There  * are no partial matches.  *  * Requires:  *  *\li	'zonep' points to a NULL dns_zone_t *.  *  * Returns:  *\li	#ISC_R_SUCCESS		A matching zone was found.  *\li	#ISC_R_NOTFOUND		No matching zone was found.  *\li	others			An error occurred.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_load
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_view_loadnew
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|stop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_view_asyncload
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_zt_allloaded_t
name|callback
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Load zones attached to this view.  dns_view_load() loads  * all zones whose master file has changed since the last  * load; dns_view_loadnew() loads only zones that have never  * been loaded.  *  * dns_view_asyncload() loads zones asynchronously.  When all zones  * in the view have finished loading, 'callback' is called with argument  * 'arg' to inform the caller.  *  * If 'stop' is ISC_TRUE, stop on the first error and return it.  * If 'stop' is ISC_FALSE (or we are loading asynchronously), ignore errors.  *  * Requires:  *  *\li	'view' is valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_gettsig
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|keyname
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the TSIG key configured in 'view' with name 'keyname',  * if any.  *  * Requires:  *\li	keyp points to a NULL dns_tsigkey_t *.  *  * Returns:  *\li	#ISC_R_SUCCESS	A key was found and '*keyp' now points to it.  *\li	#ISC_R_NOTFOUND	No key was found.  *\li	others		An error occurred.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_getpeertsig
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_netaddr_t
modifier|*
name|peeraddr
parameter_list|,
name|dns_tsigkey_t
modifier|*
modifier|*
name|keyp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the TSIG key configured in 'view' for the server whose  * address is 'peeraddr', if any.  *  * Requires:  *	keyp points to a NULL dns_tsigkey_t *.  *  * Returns:  *\li	#ISC_R_SUCCESS	A key was found and '*keyp' now points to it.  *\li	#ISC_R_NOTFOUND	No key was found.  *\li	others		An error occurred.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_checksig
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_buffer_t
modifier|*
name|source
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Verifies the signature of a message.  *  * Requires:  *  *\li	'view' is a valid view.  *\li	'source' is a valid buffer containing the message  *\li	'msg' is a valid message  *  * Returns:  *\li	see dns_tsig_verify()  */
end_comment

begin_function_decl
name|void
name|dns_view_dialup
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Perform dialup-time maintenance on the zones of 'view'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_dumpdbtostream
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Dump the current state of the view 'view' to the stream 'fp'  * for purposes of analysis or debugging.  *  * Currently the dumped state includes the view's cache; in the future  * it may also include other state such as the address database.  * It will not not include authoritative data since it is voluminous and  * easily obtainable by other means.  *  * Requires:  *  *\li	'view' is valid.  *  *\li	'fp' refers to a file open for writing.  *  * Returns:  * \li	ISC_R_SUCCESS	The cache was successfully dumped.  * \li	others		An error occurred (see dns_master_dump)  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_flushcache
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_view_flushcache2
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|fixuponly
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Flush the view's cache (and ADB).  If 'fixuponly' is true, it only updates  * the internal reference to the cache DB with omitting actual flush operation.  * 'fixuponly' is intended to be used for a view that shares a cache with  * a different view.  dns_view_flushcache() is a backward compatible version  * that always sets fixuponly to false.  *  * Requires:  * 	'view' is valid.  *  * 	No other tasks are executing.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_flushnode
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Flush the given name from the view's cache (and optionally ADB/badcache).  *  * If 'tree' is true, flush 'name' and all names below it  * from the cache, but do not flush ADB.  *  * If 'tree' is false, flush 'name' frmo both the cache and ADB,  * but do not touch any other nodes.  *  * Requires:  *\li	'view' is valid.  *\li	'name' is valid.  *  * Returns:  *\li	#ISC_R_SUCCESS  *	other returns are failures.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_flushname
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Flush the given name from the view's cache, ADB and badcache.  * Equivalent to dns_view_flushnode(view, name, ISC_FALSE).  *  *  * Requires:  *\li	'view' is valid.  *\li	'name' is valid.  *  * Returns:  *\li	#ISC_R_SUCCESS  *	other returns are failures.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_adddelegationonly
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add the given name to the delegation only table.  *  * Requires:  *\li	'view' is valid.  *\li	'name' is valid.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_excludedelegationonly
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Add the given name to be excluded from the root-delegation-only.  *  *  * Requires:  *\li	'view' is valid.  *\li	'name' is valid.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_view_isdelegationonly
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check if 'name' is in the delegation only table or if  * rootdelonly is set that name is not being excluded.  *  * Requires:  *\li	'view' is valid.  *\li	'name' is valid.  *  * Returns:  *\li	#ISC_TRUE if the name is the table.  *\li	#ISC_FALSE otherwise.  */
end_comment

begin_function_decl
name|void
name|dns_view_setrootdelonly
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the root delegation only flag.  *  * Requires:  *\li	'view' is valid.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_view_getrootdelonly
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the root delegation only flag.  *  * Requires:  *\li	'view' is valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_freezezones
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|freeze
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Freeze/thaw updates to master zones.  *  * Requires:  * \li	'view' is valid.  */
end_comment

begin_function_decl
name|void
name|dns_view_setresstats
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set a general resolver statistics counter set 'stats' for 'view'.  *  * Requires:  * \li	'view' is valid and is not frozen.  *  *\li	stats is a valid statistics supporting resolver statistics counters  *	(see dns/stats.h).  */
end_comment

begin_function_decl
name|void
name|dns_view_getresstats
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the general statistics counter set for 'view'.  If a statistics set is  * set '*statsp' will be attached to the set; otherwise, '*statsp' will be  * untouched.  *  * Requires:  * \li	'view' is valid and is not frozen.  *  *\li	'statsp' != NULL&& '*statsp' != NULL  */
end_comment

begin_function_decl
name|void
name|dns_view_setresquerystats
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set a statistics counter set of rdata type, 'stats', for 'view'.  Once the  * statistic set is installed, view's resolver will count outgoing queries  * per rdata type.  *  * Requires:  * \li	'view' is valid and is not frozen.  *  *\li	stats is a valid statistics created by dns_rdatatypestats_create().  */
end_comment

begin_function_decl
name|void
name|dns_view_getresquerystats
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_stats_t
modifier|*
modifier|*
name|statsp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the rdatatype statistics counter set for 'view'.  If a statistics set is  * set '*statsp' will be attached to the set; otherwise, '*statsp' will be  * untouched.  *  * Requires:  * \li	'view' is valid and is not frozen.  *  *\li	'statsp' != NULL&& '*statsp' != NULL  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_view_iscacheshared
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check if the view shares the cache created by another view.  *  * Requires:  * \li	'view' is valid.  *  * Returns:  *\li	#ISC_TRUE if the cache is shared.  *\li	#ISC_FALSE otherwise.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_initsecroots
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initialize security roots for the view.  (Note that secroots is  * NULL until this function is called, so any function using  * secroots must check its validity first.  One way to do this is  * use dns_view_getsecroots() and check its return value.)  *  * Requires:  * \li	'view' is valid.  * \li	'view->secroots' is NULL.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	Any other result indicates failure  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_getsecroots
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_keytable_t
modifier|*
modifier|*
name|ktp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the security roots for this view.  Returns ISC_R_NOTFOUND if  * the security roots keytable has not been initialized for the view.  *  * '*ktp' is attached on success; the caller is responsible for  * detaching it with dns_keytable_detach().  *  * Requires:  * \li	'view' is valid.  * \li	'ktp' is not NULL and '*ktp' is NULL.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_NOTFOUND  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_view_issecuredomain
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
modifier|*
name|secure_domain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Is 'name' at or beneath a trusted key?  Put answer in  * '*secure_domain'.  *  * Requires:  * \li	'view' is valid.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	Any other value indicates failure  */
end_comment

begin_function_decl
name|void
name|dns_view_untrust
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|keyname
parameter_list|,
name|dns_rdata_dnskey_t
modifier|*
name|dnskey
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove keys that match 'keyname' and 'dnskey' from the views trust  * anchors.  *  * Requires:  * \li	'view' is valid.  * \li	'keyname' is valid.  * \li	'mctx' is valid.  * \li	'dnskey' is valid.  */
end_comment

begin_function_decl
name|void
name|dns_view_setnewzones
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_boolean_t
name|allow
parameter_list|,
name|void
modifier|*
name|cfgctx
parameter_list|,
name|void
function_decl|(
modifier|*
name|cfg_destroy
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set whether or not to allow zones to be created or deleted at runtime.  *  * If 'allow' is ISC_TRUE, determines the filename into which new zone  * configuration will be written.  Preserves the configuration context  * (a pointer to which is passed in 'cfgctx') for use when parsing new  * zone configuration.  'cfg_destroy' points to a callback routine to  * destroy the configuration context when the view is destroyed.  (This  * roundabout method is used in order to avoid libdns having a dependency  * on libisccfg and libbind9.)  *  * If 'allow' is ISC_FALSE, removes any existing references to  * configuration context and frees any memory.  *  * Requires:  * \li 'view' is valid.  */
end_comment

begin_function_decl
name|void
name|dns_view_restorekeyring
parameter_list|(
name|dns_view_t
modifier|*
name|view
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
comment|/* DNS_VIEW_H */
end_comment

end_unit

