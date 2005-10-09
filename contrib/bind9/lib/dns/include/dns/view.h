begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: view.h,v 1.73.2.4.2.12 2004/03/10 02:55:58 marka Exp $ */
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
comment|/*  * DNS View  *  * A "view" is a DNS namespace, together with an optional resolver and a  * forwarding policy.  A "DNS namespace" is a (possibly empty) set of  * authoritative zones together with an optional cache and optional  * "hints" information.  *  * Views start out "unfrozen".  In this state, core attributes like  * the cache, set of zones, and forwarding policy may be set.  While  * "unfrozen", the caller (e.g. nameserver configuration loading  * code), must ensure exclusive access to the view.  When the view is  * "frozen", the core attributes become immutable, and the view module  * will ensure synchronization.  Freezing allows the view's core attributes  * to be accessed without locking.  *  * MP:  *	Before the view is frozen, the caller must ensure synchronization.  *  *	After the view is frozen, the module guarantees appropriate  *	synchronization of any data structures it creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
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
file|<dns/types.h>
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
name|dns_keytable_t
modifier|*
name|secroots
decl_stmt|;
name|dns_keytable_t
modifier|*
name|trustedkeys
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
name|dns_transfer_format_t
name|transfer_format
decl_stmt|;
name|dns_acl_t
modifier|*
name|queryacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|recursionacl
decl_stmt|;
name|dns_acl_t
modifier|*
name|sortlist
decl_stmt|;
name|isc_boolean_t
name|requestixfr
decl_stmt|;
name|isc_boolean_t
name|provideixfr
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
comment|/*  * Create a view.  *  * Notes:  *  *	The newly created view has no cache, no resolver, and an empty  *	zone table.  The view is not frozen.  *  * Requires:  *  *	'mctx' is a valid memory context.  *  *	'rdclass' is a valid class.  *  *	'name' is a valid C string.  *  *	viewp != NULL&& *viewp == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other errors are possible.  */
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
comment|/*  * Attach '*targetp' to 'source'.  *  * Requires:  *  *	'source' is a valid, frozen view.  *  *	'targetp' points to a NULL dns_view_t *.  *  * Ensures:  *  *	*targetp is attached to source.  *  *	While *targetp is attached, the view will not shut down.  */
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
comment|/*  * Detach '*viewp' from its view.  *  * Requires:  *  *	'viewp' points to a valid dns_view_t *  *  * Ensures:  *  *	*viewp is NULL.  */
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
comment|/*  * Detach '*viewp' from its view.  If this was the last reference  * uncommited changed in zones will be flushed to disk.  *  * Requires:  *  *	'viewp' points to a valid dns_view_t *  *  * Ensures:  *  *	*viewp is NULL.  */
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
comment|/*  * Weakly attach '*targetp' to 'source'.  *  * Requires:  *  *	'source' is a valid, frozen view.  *  *	'targetp' points to a NULL dns_view_t *.  *  * Ensures:  *  *	*targetp is attached to source.  *  * 	While *targetp is attached, the view will not be freed.  */
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
comment|/*  * Detach '*viewp' from its view.  *  * Requires:  *  *	'viewp' points to a valid dns_view_t *.  *  * Ensures:  *  *	*viewp is NULL.  */
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
comment|/*  * Create a resolver and address database for the view.  *  * Requires:  *  *	'view' is a valid, unfrozen view.  *  *	'view' does not have a resolver already.  *  *	The requirements of dns_resolver_create() apply to 'taskmgr',  *	'ntasks', 'socketmgr', 'timermgr', 'options', 'dispatchv4', and  *	'dispatchv6'.  *  * Returns:  *  *     	ISC_R_SUCCESS  *  *	Any error that dns_resolver_create() can return.  */
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

begin_comment
comment|/*  * Set the view's cache database.  *  * Requires:  *  *	'view' is a valid, unfrozen view.  *  *	'cache' is a valid cache.  *  * Ensures:  *  *     	The cache of 'view' is 'cached.  *  *	If this is not the first call to dns_view_setcache() for this  *	view, then previously set cache is detached.  */
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
comment|/*  * Set the view's hints database.  *  * Requires:  *  *	'view' is a valid, unfrozen view, whose hints database has not been  *	set.  *  *	'hints' is a valid zone database.  *  * Ensures:  *  *     	The hints database of 'view' is 'hints'.  */
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

begin_comment
comment|/*  * Set the view's static TSIG keys  *  * Requires:  *  *      'view' is a valid, unfrozen view, whose static TSIG keyring has not  *	been set.  *  *      'ring' is a valid TSIG keyring  *  * Ensures:  *  *      The static TSIG keyring of 'view' is 'ring'.  */
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
comment|/*  * Set the view's destination port.  This is the port to  * which outgoing queries are sent.  The default is 53,  * the standard DNS port.  *  * Requires:  *  *      'view' is a valid view.  *  *      'dstport' is a valid TCP/UDP port number.  *  * Ensures:  *	External name servers will be assumed to be listning  *	on 'dstport'.  For servers whose address has already  *	obtained obtained at the time of the call, the view may  *	continue to use the previously set port until the address  *	times out from the view's address database.  */
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
comment|/*  * Add zone 'zone' to 'view'.  *  * Requires:  *  *	'view' is a valid, unfrozen view.  *  *	'zone' is a valid zone.  */
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
comment|/*  * Freeze view.  *  * Requires:  *  *	'view' is a valid, unfrozen view.  *  * Ensures:  *  *	'view' is frozen.  */
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

begin_comment
comment|/*  * Find an rdataset whose owner name is 'name', and whose type is  * 'type'.  *  * Notes:  *  *	See the description of dns_db_find() for information about 'options'.  *	If the caller sets DNS_DBFIND_GLUEOK, it must ensure that 'name'  *	and 'type' are appropriate for glue retrieval.  *  *	If 'now' is zero, then the current time will be used.  *  *	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  If the answer is found in the hints  *	database, the result code will be DNS_R_HINT.  If the name is found  *	in the hints database but not the type, the result code will be  *	DNS_R_HINTNXRRSET.  *  *	'foundname' must meet the requirements of dns_db_find().  *  *	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  * Requires:  *  *	'view' is a valid, frozen view.  *  *	'name' is valid name.  *  *	'type' is a valid dns_rdatatype_t, and is not a meta query type  *	except dns_rdatatype_any.  *  *	dbp == NULL || *dbp == NULL  *  *	nodep == NULL || *nodep == NULL.  If nodep != NULL, dbp != NULL.  *  *	'foundname' is a valid name with a dedicated buffer or NULL.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Ensures:  *  *	In successful cases, 'rdataset', and possibly 'sigrdataset', are  *	bound to the found data.  *  *	If dbp != NULL, it points to the database containing the data.  *  *	If nodep != NULL, it points to the database node containing the data.  *  *	If foundname != NULL, it contains the full name of the found data.  *  * Returns:  *  *	Any result that dns_db_find() can return, with the exception of  *	DNS_R_DELEGATION.  */
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
comment|/*  * Find an rdataset whose owner name is 'name', and whose type is  * 'type'.  *  * Notes:  *  *	This routine is appropriate for simple, exact-match queries of the  *	view.  'name' must be a canonical name; there is no DNAME or CNAME  *	processing.  *  *	See the description of dns_db_find() for information about 'options'.  *	If the caller sets DNS_DBFIND_GLUEOK, it must ensure that 'name'  *	and 'type' are appropriate for glue retrieval.  *  *	If 'now' is zero, then the current time will be used.  *  *	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  If the answer is found in the hints  *	database, the result code will be DNS_R_HINT.  If the name is found  *	in the hints database but not the type, the result code will be  *	DNS_R_HINTNXRRSET.  *  *	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  * Requires:  *  *	'view' is a valid, frozen view.  *  *	'name' is valid name.  *  *	'type' is a valid dns_rdatatype_t, and is not a meta query type  *	(e.g. dns_rdatatype_any), or dns_rdatatype_rrsig.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Ensures:  *  *	In successful cases, 'rdataset', and possibly 'sigrdataset', are  *	bound to the found data.  *  * Returns:  *  *	ISC_R_SUCCESS			Success; result is desired type.  *	DNS_R_GLUE			Success; result is glue.  *	DNS_R_HINT			Success; result is a hint.  *	DNS_R_NCACHENXDOMAIN		Success; result is a ncache entry.  *	DNS_R_NCACHENXRRSET		Success; result is a ncache entry.  *	DNS_R_NXDOMAIN			The name does not exist.  *	DNS_R_NXRRSET			The rrset does not exist.  *	ISC_R_NOTFOUND			No matching data found,  *					or an error occurred.  */
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
comment|/*  * Find the best known zonecut containing 'name'.  *  * This uses local authority, cache, and optionally hints data.  * No external queries are performed.  *  * Notes:  *  *	If 'now' is zero, then the current time will be used.  *  *	If 'use_hints' is ISC_TRUE, and the view has a hints database, then  *	it will be searched last.  *  *	If 'use_cache' is ISC_TRUE, and the view has a cache, then it will be  *	searched.  *  *	If 'sigrdataset' is not NULL, and there is a SIG rdataset which  *	covers 'type', then 'sigrdataset' will be bound to it.  *  *	If the DNS_DBFIND_NOEXACT option is set, then the zonecut returned  *	(if any) will be the deepest known ancestor of 'name'.  *  * Requires:  *  *	'view' is a valid, frozen view.  *  *	'name' is valid name.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	'sigrdataset' is NULL, or is a valid, disassociated rdataset.  *  * Returns:  *  *	ISC_R_SUCCESS				Success.  *  *	Many other results are possible.  */
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
comment|/*  * Search for a view with name 'name' and class 'rdclass' in 'list'.  * If found, '*viewp' is (strongly) attached to it.  *  * Requires:  *  *	'viewp' points to a NULL dns_view_t *.  *  * Returns:  *  *	ISC_R_SUCCESS		A matching view was found.  *	ISC_R_NOTFOUND		No matching view was found.  */
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
comment|/*  * Search for the zone 'name' in the zone table of 'view'.  * If found, 'zonep' is (strongly) attached to it.  There  * are no partial matches.  *  * Requires:  *  *	'zonep' points to a NULL dns_zone_t *.  *  * Returns:  *	ISC_R_SUCCESS		A matching zone was found.  *	ISC_R_NOTFOUND		No matching zone was found.  *	others			An error occurred.  */
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

begin_comment
comment|/*  * Load zones attached to this view.  dns_view_load() loads  * all zones whose master file has changed since the last  * load; dns_view_loadnew() loads only zones that have never   * been loaded.  *  * If 'stop' is ISC_TRUE, stop on the first error and return it.  * If 'stop' is ISC_FALSE, ignore errors.  *  * Requires:  *  *	'view' is valid.  */
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
comment|/*  * Find the TSIG key configured in 'view' with name 'keyname',  * if any.  *  * Reqires:  *	keyp points to a NULL dns_tsigkey_t *.  *  * Returns:  *	ISC_R_SUCCESS	A key was found and '*keyp' now points to it.  *	ISC_R_NOTFOUND	No key was found.  *	others		An error occurred.  */
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
comment|/*  * Find the TSIG key configured in 'view' for the server whose  * address is 'peeraddr', if any.  *  * Reqires:  *	keyp points to a NULL dns_tsigkey_t *.  *  * Returns:  *	ISC_R_SUCCESS	A key was found and '*keyp' now points to it.  *	ISC_R_NOTFOUND	No key was found.  *	others		An error occurred.  */
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
comment|/*  * Verifies the signature of a message.  *  * Requires:  *  *	'view' is a valid view.  *	'source' is a valid buffer containing the message  *	'msg' is a valid message  *  * Returns:  *	see dns_tsig_verify()  */
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
comment|/*  * Perform dialup-time maintenance on the zones of 'view'.  */
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
comment|/*  * Dump the current state of the view 'view' to the stream 'fp'  * for purposes of analysis or debugging.  *  * Currently the dumped state includes the view's cache; in the future  * it may also include other state such as the address database.  * It will not not include authoritative data since it is voluminous and  * easily obtainable by other means.  *  * Requires:  * 	  *	'view' is valid.  *  *	'fp' refers to a file open for writing.  *  * Returns:  * 	ISC_R_SUCCESS	The cache was successfully dumped.  * 	others		An error occurred (see dns_master_dump)  */
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

begin_comment
comment|/*  * Flush the view's cache (and ADB).  *  * Requires:  * 	'view' is valid.  *  * 	No other tasks are executing.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flush the given name from the view's cache (and ADB).  *  * Requires:  *	'view' is valid.  *	'name' is valid.  *  * Returns:  *	ISC_R_SUCCESS  *	other returns are failures.  */
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
comment|/*  * Add the given name to the delegation only table.  *   *  * Requires:  *	'view' is valid.  *	'name' is valid.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
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
comment|/*  * Add the given name to be excluded from the root-delegation-only.  *   *  * Requires:  *	'view' is valid.  *	'name' is valid.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
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
comment|/*  * Check if 'name' is in the delegation only table or if  * rootdelonly is set that name is not being excluded.  *  * Requires:  *	'view' is valid.  *	'name' is valid.  *  * Returns:  *	ISC_TRUE if the name is is the table.  *	ISC_FALSE othewise.  */
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
comment|/*  * Set the root delegation only flag.  *  * Requires:  *	'view' is valid.  */
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
comment|/*  * Get the root delegation only flag.  *  * Requires:  *	'view' is valid.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_VIEW_H */
end_comment

end_unit

