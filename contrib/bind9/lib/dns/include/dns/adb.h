begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: adb.h,v 1.66.2.5.2.4 2004/03/06 08:13:50 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ADB_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ADB_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS Address Database  *  * This module implements an address database (ADB) for mapping a name  * to an isc_sockaddr_t. It also provides statistical information on  * how good that address might be.  *  * A client will pass in a dns_name_t, and the ADB will walk through  * the rdataset looking up addresses associated with the name.  If it  * is found on the internal lists, a structure is filled in with the  * address information and stats for found addresses.  *  * If the name cannot be found on the internal lists, a new entry will  * be created for a name if all the information needed can be found  * in the zone table or cache.  This new address will then be returned.  *  * If a request must be made to remote servers to satisfy a name lookup,  * this module will start fetches to try to complete these addresses.  When  * at least one more completes, an event is sent to the caller.  If none of  * them resolve before the fetch times out, an event indicating this is  * sent instead.  *  * Records are stored internally until a timer expires. The timer is the  * smaller of the TTL or signature validity period.  *  * Lameness is stored per-zone, and this data hangs off each address field.  * When an address is marked lame for a given zone the address will not  * be returned to a caller.  *  *  * MP:  *  *	The ADB takes care of all necessary locking.  *  *	Only the task which initiated the name lookup can cancel the lookup.  *  *  * Security:  *  *	None, since all data stored is required to be pre-filtered.  *	(Cache needs to be sane, fetches return bounds-checked and sanity-  *       checked data, caller passes a good dns_name_t for the zone, etc)  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

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
file|<isc/mem.h>
end_include

begin_include
include|#
directive|include
file|<isc/sockaddr.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_include
include|#
directive|include
file|<dns/view.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Magic number checks  ***/
end_comment

begin_define
define|#
directive|define
name|DNS_ADBFIND_MAGIC
value|ISC_MAGIC('a','d','b','H')
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_VALID
parameter_list|(
name|x
parameter_list|)
value|ISC_MAGIC_VALID(x, DNS_ADBFIND_MAGIC)
end_define

begin_define
define|#
directive|define
name|DNS_ADBADDRINFO_MAGIC
value|ISC_MAGIC('a','d','A','I')
end_define

begin_define
define|#
directive|define
name|DNS_ADBADDRINFO_VALID
parameter_list|(
name|x
parameter_list|)
value|ISC_MAGIC_VALID(x, DNS_ADBADDRINFO_MAGIC)
end_define

begin_comment
comment|/***  *** TYPES  ***/
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_adbname
name|dns_adbname_t
typedef|;
end_typedef

begin_comment
comment|/* dns_adbfind_t  *  * Represents a lookup for a single name.  *  * On return, the client can safely use "list", and can reorder the list.  * Items may not be _deleted_ from this list, however, or added to it  * other than by using the dns_adb_*() API.  */
end_comment

begin_struct
struct|struct
name|dns_adbfind
block|{
comment|/* Public */
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* RO: magic */
name|dns_adbaddrinfolist_t
name|list
decl_stmt|;
comment|/* RO: list of addrs */
name|unsigned
name|int
name|query_pending
decl_stmt|;
comment|/* RO: partial list */
name|unsigned
name|int
name|partial_result
decl_stmt|;
comment|/* RO: addrs missing */
name|unsigned
name|int
name|options
decl_stmt|;
comment|/* RO: options */
name|isc_result_t
name|result_v4
decl_stmt|;
comment|/* RO: v4 result */
name|isc_result_t
name|result_v6
decl_stmt|;
comment|/* RO: v6 result */
name|ISC_LINK
argument_list|(
argument|dns_adbfind_t
argument_list|)
name|publink
expr_stmt|;
comment|/* RW: client use */
comment|/* Private */
name|isc_mutex_t
name|lock
decl_stmt|;
comment|/* locks all below */
name|in_port_t
name|port
decl_stmt|;
name|int
name|name_bucket
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|dns_adbname_t
modifier|*
name|adbname
decl_stmt|;
name|dns_adb_t
modifier|*
name|adb
decl_stmt|;
name|isc_event_t
name|event
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_adbfind_t
argument_list|)
name|plink
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * _INET:  * _INET6:  *	return addresses of that type.  *  * _EMPTYEVENT:  *	Only schedule an event if no addresses are known.  *	Must set _WANTEVENT for this to be meaningful.  *  * _WANTEVENT:  *	An event is desired.  Check this bit in the returned find to see  *	if one will actually be generated.  *  * _AVOIDFETCHES:  *	If set, fetches will not be generated unless no addresses are  *	available in any of the address families requested.  *  * _STARTATZONE:  *	Fetches will start using the closest zone data or use the root servers.  *	This is useful for reestablishing glue that has expired.  *  * _GLUEOK:  * _HINTOK:  *	Glue or hints are ok.  These are used when matching names already  *	in the adb, and when dns databases are searched.  *  * _RETURNLAME:  *	Return lame servers in a find, so that all addresses are returned.  *  * _LAMEPRUNED:  *	At least one address was omitted from the list because it was lame.  *	This bit will NEVER be set if _RETURNLAME is set in the createfind().  */
end_comment

begin_define
define|#
directive|define
name|DNS_ADBFIND_INET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_INET6
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_ADDRESSMASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_EMPTYEVENT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_WANTEVENT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_AVOIDFETCHES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_STARTATZONE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_GLUEOK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_HINTOK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_RETURNLAME
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DNS_ADBFIND_LAMEPRUNED
value|0x00000200
end_define

begin_comment
comment|/* dns_adbaddrinfo_t  *  * The answers to queries come back as a list of these.  */
end_comment

begin_struct
struct|struct
name|dns_adbaddrinfo
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
comment|/* private */
name|isc_sockaddr_t
name|sockaddr
decl_stmt|;
comment|/* [rw] */
name|unsigned
name|int
name|srtt
decl_stmt|;
comment|/* [rw] microseconds */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* [rw] */
name|dns_adbentry_t
modifier|*
name|entry
decl_stmt|;
comment|/* private */
name|ISC_LINK
argument_list|(
argument|dns_adbaddrinfo_t
argument_list|)
name|publink
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The event sent to the caller task is just a plain old isc_event_t.  It  * contains no data other than a simple status, passed in the "type" field  * to indicate that another address resolved, or all partially resolved  * addresses have failed to resolve.  *  * "sender" is the dns_adbfind_t used to issue this query.  *  * This is simply a standard event, with the "type" set to:  *  *	DNS_EVENT_ADBMOREADDRESSES   -- another address resolved.  *	DNS_EVENT_ADBNOMOREADDRESSES -- all pending addresses failed,  *					were canceled, or otherwise will  *					not be usable.  *	DNS_EVENT_ADBCANCELED	     -- The request was canceled by a  *					3rd party.  *	DNS_EVENT_ADBNAMEDELETED     -- The name was deleted, so this request  *					was canceled.  *  * In each of these cases, the addresses returned by the initial call  * to dns_adb_createfind() can still be used until they are no longer needed.  */
end_comment

begin_comment
comment|/****  **** FUNCTIONS  ****/
end_comment

begin_function_decl
name|isc_result_t
name|dns_adb_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mem
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|isc_timermgr_t
modifier|*
name|tmgr
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|,
name|dns_adb_t
modifier|*
modifier|*
name|newadb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new ADB.  *  * Notes:  *  *	Generally, applications should not create an ADB directly, but  *	should instead call dns_view_createresolver().  *  * Requires:  *  *	'mem' must be a valid memory context.  *  *	'view' be a pointer to a valid view.  *  *	'tmgr' be a pointer to a valid timer manager.  *  *	'taskmgr' be a pointer to a valid task manager.  *  *	'newadb' != NULL&& '*newadb' == NULL.  *  * Returns:  *  *	ISC_R_SUCCESS	after happiness.  *	ISC_R_NOMEMORY	after resource allocation failure.  */
end_comment

begin_function_decl
name|void
name|dns_adb_attach
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_adb_t
modifier|*
modifier|*
name|adbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach to an 'adb' to 'adbp'.  *  * Requires:  *	'adb' to be a valid dns_adb_t, created via dns_adb_create().  *	'adbp' to be a valid pointer to a *dns_adb_t which is initialized  *	to NULL.  */
end_comment

begin_function_decl
name|void
name|dns_adb_detach
parameter_list|(
name|dns_adb_t
modifier|*
modifier|*
name|adb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Delete the ADB. Sets *ADB to NULL. Cancels any outstanding requests.  *  * Requires:  *  *	'adb' be non-NULL and '*adb' be a valid dns_adb_t, created via  *	dns_adb_create().  */
end_comment

begin_function_decl
name|void
name|dns_adb_whenshutdown
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Send '*eventp' to 'task' when 'adb' has shutdown.  *  * Requires:  *  *	'*adb' is a valid dns_adb_t.  *  *	eventp != NULL&& *eventp is a valid event.  *  * Ensures:  *  *	*eventp == NULL  *  *	The event's sender field is set to the value of adb when the event  *	is sent.  */
end_comment

begin_function_decl
name|void
name|dns_adb_shutdown
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shutdown 'adb'.  *  * Requires:  *  * 	'*adb' is a valid dns_adb_t.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_adb_createfind
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_name_t
modifier|*
name|zone
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_name_t
modifier|*
name|target
parameter_list|,
name|in_port_t
name|port
parameter_list|,
name|dns_adbfind_t
modifier|*
modifier|*
name|find
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Main interface for clients. The adb will look up the name given in  * "name" and will build up a list of found addresses, and perhaps start  * internal fetches to resolve names that are unknown currently.  *  * If other addresses resolve after this call completes, an event will  * be sent to the<task, taskaction, arg> with the sender of that event  * set to a pointer to the dns_adbfind_t returned by this function.  *  * If no events will be generated, the *find->result_v4 and/or result_v6  * members may be examined for address lookup status.  The usual ISC_R_SUCCESS,  * ISC_R_FAILURE, and DNS_R_NX{DOMAIN,RRSET} are returned, along with  * ISC_R_NOTFOUND meaning the ADB has not _yet_ found the values.  In this  * latter case, retrying may produce more addresses.  *  * If events will be returned, the result_v[46] members are only valid  * when that event is actually returned.  *  * The list of addresses returned is unordered.  The caller must impose  * any ordering required.  The list will not contain "known bad" addresses,  * however.  For instance, it will not return hosts that are known to be  * lame for the zone in question.  *  * The caller cannot (directly) modify the contents of the address list's  * fields other than the "link" field.  All values can be read at any  * time, however.  *  * The "now" parameter is used only for determining which entries that  * have a specific time to live or expire time should be removed from  * the running database.  If specified as zero, the current time will  * be retrieved and used.  *  * If 'target' is not NULL and 'name' is an alias (i.e. the name is  * CNAME'd or DNAME'd to another name), then 'target' will be updated with  * the domain name that 'name' is aliased to.  *  * All addresses returned will have the sockaddr's port set to 'port.'  * The caller may change them directly in the dns_adbaddrinfo_t since  * they are copies of the internal address only.  *  * XXXMLG  Document options, especially the flags which control how  *         events are sent.  *  * Requires:  *  *	*adb be a valid isc_adb_t object.  *  *	If events are to be sent, *task be a valid task,  *	and isc_taskaction_t != NULL.  *  *	*name is a valid dns_name_t.  *  *	zone != NULL and *zone be a valid dns_name_t.  *  *	target == NULL or target is a valid name with a buffer.  *  *	find != NULL&& *find == NULL.  *  * Returns:  *  *	ISC_R_SUCCESS	Addresses might have been returned, and events will be  *			delivered for unresolved addresses.  *	ISC_R_NOMORE	Addresses might have been returned, but no events  *			will ever be posted for this context.  This is only  *			returned if task != NULL.  *	ISC_R_NOMEMORY	insufficient resources  *	DNS_R_ALIAS	'name' is an alias for another name.  *  * Calls, and returns error codes from:  *  *	isc_stdtime_get()  *  * Notes:  *  *	No internal reference to "name" exists after this function  *	returns.  */
end_comment

begin_function_decl
name|void
name|dns_adb_cancelfind
parameter_list|(
name|dns_adbfind_t
modifier|*
name|find
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cancels the find, and sends the event off to the caller.  *  * It is an error to call dns_adb_cancelfind() on a find where  * no event is wanted, or will ever be sent.  *  * Note:  *  *	It is possible that the real completion event was posted just  *	before the dns_adb_cancelfind() call was made.  In this case,  *	dns_adb_cancelfind() will do nothing.  The event callback needs  *	to be prepared to find this situation (i.e. result is valid but  *	the caller expects it to be canceled).  *  * Requires:  *  *	'find' be a valid dns_adbfind_t pointer.  *  *	events would have been posted to the task.  This can be checked  *	with (find->options& DNS_ADBFIND_WANTEVENT).  *  * Ensures:  *  *	The event was posted to the task.  */
end_comment

begin_function_decl
name|void
name|dns_adb_destroyfind
parameter_list|(
name|dns_adbfind_t
modifier|*
modifier|*
name|find
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroys the find reference.  *  * Note:  *  *	This can only be called after the event was delivered for a  *	find.  Additionally, the event MUST have been freed via  *	isc_event_free() BEFORE this function is called.  *  * Requires:  *  *	'find' != NULL and *find be valid dns_adbfind_t pointer.  *  * Ensures:  *  *	No "address found" events will be posted to the originating task  *	after this function returns.  */
end_comment

begin_function_decl
name|void
name|dns_adb_dump
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function is only used for debugging.  It will dump as much of the  * state of the running system as possible.  *  * Requires:  *  *	adb be valid.  *  *	f != NULL, and is a file open for writing.  */
end_comment

begin_function_decl
name|void
name|dns_adb_dumpfind
parameter_list|(
name|dns_adbfind_t
modifier|*
name|find
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function is only used for debugging.  Dump the data associated  * with a find.  *  * Requires:  *  *	find is valid.  *  * 	f != NULL, and is a file open for writing.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_adb_marklame
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_adbaddrinfo_t
modifier|*
name|addr
parameter_list|,
name|dns_name_t
modifier|*
name|zone
parameter_list|,
name|isc_stdtime_t
name|expire_time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Mark the given address as lame for the zone "zone".  expire_time should  * be set to the time when the entry should expire.  That is, if it is to  * expire 10 minutes in the future, it should set it to (now + 10 * 60).  *  * Requires:  *  *	adb be valid.  *  *	addr be valid.  *  *	zone be the zone used in the dns_adb_createfind() call.  *  * Returns:  *  *	ISC_R_SUCCESS		-- all is well.  *	ISC_R_NOMEMORY		-- could not mark address as lame.  */
end_comment

begin_comment
comment|/*  * A reasonable default for RTT adjustments  */
end_comment

begin_define
define|#
directive|define
name|DNS_ADB_RTTADJDEFAULT
value|7
end_define

begin_comment
comment|/* default scale */
end_comment

begin_define
define|#
directive|define
name|DNS_ADB_RTTADJREPLACE
value|0
end_define

begin_comment
comment|/* replace with our rtt */
end_comment

begin_define
define|#
directive|define
name|DNS_ADB_RTTADJAGE
value|10
end_define

begin_comment
comment|/* age this rtt */
end_comment

begin_function_decl
name|void
name|dns_adb_adjustsrtt
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_adbaddrinfo_t
modifier|*
name|addr
parameter_list|,
name|unsigned
name|int
name|rtt
parameter_list|,
name|unsigned
name|int
name|factor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Mix the round trip time into the existing smoothed rtt.  The formula used  * (where srtt is the existing rtt value, and rtt and factor are arguments to  * this function):  *  *	new_srtt = (old_srtt / 10 * factor) + (rtt / 10 * (10 - factor));  *  * XXXRTH  Do we want to publish the formula?  What if we want to change how  *         this works later on?  Recommend/require that the units are  *	   microseconds?  *  * Requires:  *  *	adb be valid.  *  *	addr be valid.  *  *	0<= factor<= 10  *  * Note:  *  *	The srtt in addr will be updated to reflect the new global  *	srtt value.  This may include changes made by others.  */
end_comment

begin_function_decl
name|void
name|dns_adb_changeflags
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_adbaddrinfo_t
modifier|*
name|addr
parameter_list|,
name|unsigned
name|int
name|bits
parameter_list|,
name|unsigned
name|int
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set the flags as given by:  *  *	newflags = (oldflags& ~mask) | (bits& mask);  *  * Requires:  *  *	adb be valid.  *  *	addr be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_adb_findaddrinfo
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|sa
parameter_list|,
name|dns_adbaddrinfo_t
modifier|*
modifier|*
name|addrp
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a dns_adbaddrinfo_t that is associated with address 'sa'.  *  * Requires:  *  *	adb is valid.  *  *	sa is valid.  *  *	addrp != NULL&& *addrp == NULL  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_SHUTTINGDOWN  */
end_comment

begin_function_decl
name|void
name|dns_adb_freeaddrinfo
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_adbaddrinfo_t
modifier|*
modifier|*
name|addrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a dns_adbaddrinfo_t allocated by dns_adb_findaddrinfo().  *  * Requires:  *  *	adb is valid.  *  *	*addrp is a valid dns_adbaddrinfo_t *.  */
end_comment

begin_function_decl
name|void
name|dns_adb_flush
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flushes all cached data from the adb.  *  * Requires:  * 	adb is valid.  */
end_comment

begin_function_decl
name|void
name|dns_adb_setadbsize
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|isc_uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set a target memory size.  If memory usage exceeds the target  * size entries will be removed before they would have expired on  * a random basis.  *  * If 'size' is 0 then memory usage is unlimited.  *  * Requires:  *	'adb' is valid.  */
end_comment

begin_function_decl
name|void
name|dns_adb_flushname
parameter_list|(
name|dns_adb_t
modifier|*
name|adb
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Flush 'name' from the adb cache.  *   * Requires:  *	'adb' is valid.  *	'name' is valid.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ADB_H */
end_comment

end_unit

