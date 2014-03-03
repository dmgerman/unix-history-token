begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2013  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_H
value|1
end_define

begin_comment
comment|/*! \file dns/zone.h */
end_comment

begin_comment
comment|/***  ***	Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<dns/master.h>
end_include

begin_include
include|#
directive|include
file|<dns/masterdump.h>
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_zone_none
block|,
name|dns_zone_master
block|,
name|dns_zone_slave
block|,
name|dns_zone_stub
block|,
name|dns_zone_staticstub
block|,
name|dns_zone_key
block|,
name|dns_zone_dlz
block|,
name|dns_zone_redirect
block|}
name|dns_zonetype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|dns_zonestat_none
init|=
literal|0
block|,
name|dns_zonestat_terse
block|,
name|dns_zonestat_full
block|}
name|dns_zonestat_level_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DNS_ZONEOPT_SERVERS
value|0x00000001U
end_define

begin_comment
comment|/*%< perform server checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_PARENTS
value|0x00000002U
end_define

begin_comment
comment|/*%< perform parent checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHILDREN
value|0x00000004U
end_define

begin_comment
comment|/*%< perform child checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NOTIFY
value|0x00000008U
end_define

begin_comment
comment|/*%< perform NOTIFY */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_MANYERRORS
value|0x00000010U
end_define

begin_comment
comment|/*%< return many errors on load */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_IXFRFROMDIFFS
value|0x00000020U
end_define

begin_comment
comment|/*%< calculate differences */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NOMERGE
value|0x00000040U
end_define

begin_comment
comment|/*%< don't merge journal */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKNS
value|0x00000080U
end_define

begin_comment
comment|/*%< check if NS's are addresses */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_FATALNS
value|0x00000100U
end_define

begin_comment
comment|/*%< DNS_ZONEOPT_CHECKNS is fatal */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_MULTIMASTER
value|0x00000200U
end_define

begin_comment
comment|/*%< this zone has multiple masters */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_USEALTXFRSRC
value|0x00000400U
end_define

begin_comment
comment|/*%< use alternate transfer sources */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKNAMES
value|0x00000800U
end_define

begin_comment
comment|/*%< check-names */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKNAMESFAIL
value|0x00001000U
end_define

begin_comment
comment|/*%< fatal check-name failures */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKWILDCARD
value|0x00002000U
end_define

begin_comment
comment|/*%< check for internal wildcards */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKMX
value|0x00004000U
end_define

begin_comment
comment|/*%< check-mx */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKMXFAIL
value|0x00008000U
end_define

begin_comment
comment|/*%< fatal check-mx failures */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKINTEGRITY
value|0x00010000U
end_define

begin_comment
comment|/*%< perform integrity checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKSIBLING
value|0x00020000U
end_define

begin_comment
comment|/*%< perform sibling glue checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NOCHECKNS
value|0x00040000U
end_define

begin_comment
comment|/*%< disable IN NS address checks */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_WARNMXCNAME
value|0x00080000U
end_define

begin_comment
comment|/*%< warn on MX CNAME check */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_IGNOREMXCNAME
value|0x00100000U
end_define

begin_comment
comment|/*%< ignore MX CNAME check */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_WARNSRVCNAME
value|0x00200000U
end_define

begin_comment
comment|/*%< warn on SRV CNAME check */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_IGNORESRVCNAME
value|0x00400000U
end_define

begin_comment
comment|/*%< ignore SRV CNAME check */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_UPDATECHECKKSK
value|0x00800000U
end_define

begin_comment
comment|/*%< check dnskey KSK flag */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_TRYTCPREFRESH
value|0x01000000U
end_define

begin_comment
comment|/*%< try tcp refresh on udp failure */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NOTIFYTOSOA
value|0x02000000U
end_define

begin_comment
comment|/*%< Notify the SOA MNAME */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NSEC3TESTZONE
value|0x04000000U
end_define

begin_comment
comment|/*%< nsec3-test-zone */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_SECURETOINSECURE
value|0x08000000U
end_define

begin_comment
comment|/*%< dnssec-secure-to-insecure */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_DNSKEYKSKONLY
value|0x10000000U
end_define

begin_comment
comment|/*%< dnssec-dnskey-kskonly */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKDUPRR
value|0x20000000U
end_define

begin_comment
comment|/*%< check-dup-records */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKDUPRRFAIL
value|0x40000000U
end_define

begin_comment
comment|/*%< fatal check-dup-records failures */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_CHECKSPF
value|0x80000000U
end_define

begin_comment
comment|/*%< check SPF records */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOMINUM_PUBLIC
end_ifndef

begin_comment
comment|/*  * Nominum specific options build down.  */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEOPT_NOTIFYFORWARD
value|0x80000000U
end_define

begin_comment
comment|/* forward notify to master */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOMINUM_PUBLIC */
end_comment

begin_comment
comment|/*  * Zone key maintenance options  */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEKEY_ALLOW
value|0x00000001U
end_define

begin_comment
comment|/*%< fetch keys on command */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEKEY_MAINTAIN
value|0x00000002U
end_define

begin_comment
comment|/*%< publish/sign on schedule */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEKEY_CREATE
value|0x00000004U
end_define

begin_comment
comment|/*%< make keys when needed */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEKEY_FULLSIGN
value|0x00000008U
end_define

begin_comment
comment|/*%< roll to new keys immediately */
end_comment

begin_define
define|#
directive|define
name|DNS_ZONEKEY_NORESIGN
value|0x00000010U
end_define

begin_comment
comment|/*%< no automatic resigning */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_MINREFRESH
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_MINREFRESH
value|300
end_define

begin_comment
comment|/*%< 5 minutes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_MAXREFRESH
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_MAXREFRESH
value|2419200
end_define

begin_comment
comment|/*%< 4 weeks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_DEFAULTREFRESH
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_DEFAULTREFRESH
value|3600
end_define

begin_comment
comment|/*%< 1 hour */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_MINRETRY
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_MINRETRY
value|300
end_define

begin_comment
comment|/*%< 5 minutes */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_MAXRETRY
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_MAXRETRY
value|1209600
end_define

begin_comment
comment|/*%< 2 weeks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_ZONE_DEFAULTRETRY
end_ifndef

begin_define
define|#
directive|define
name|DNS_ZONE_DEFAULTRETRY
value|60
end_define

begin_comment
comment|/*%< 1 minute, subject to 						   exponential backoff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DNS_ZONESTATE_XFERRUNNING
value|1
end_define

begin_define
define|#
directive|define
name|DNS_ZONESTATE_XFERDEFERRED
value|2
end_define

begin_define
define|#
directive|define
name|DNS_ZONESTATE_SOAQUERY
value|3
end_define

begin_define
define|#
directive|define
name|DNS_ZONESTATE_ANY
value|4
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  ***	Functions  ***/
name|isc_result_t
name|dns_zone_create
parameter_list|(
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Creates a new empty zone and attach '*zonep' to it.  *  * Requires:  *\li	'zonep' to point to a NULL pointer.  *\li	'mctx' to be a valid memory context.  *  * Ensures:  *\li	'*zonep' refers to a valid zone.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|dns_zone_setclass
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the class of a zone.  This operation can only be performed  *	once on a zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	dns_zone_setclass() not to have been called since the zone was  *	created.  *\li	'rdclass' != dns_rdataclass_none.  */
end_comment

begin_function_decl
name|dns_rdataclass_t
name|dns_zone_getclass
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the current zone class.  *  * Requires:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_getserial2
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
modifier|*
name|serialp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_zone_getserial
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the current serial number of the zone.  On success, the SOA  *	serial of the zone will be copied into '*serialp'.  *	dns_zone_getserial() cannot catch failure cases and is deprecated by  *	dns_zone_getserial2().  *  * Requires:  *\li	'zone' to be a valid zone.  *\li	'serialp' to be non NULL  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#DNS_R_NOTLOADED	zone DB is not loaded  */
end_comment

begin_function_decl
name|void
name|dns_zone_settype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zonetype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the zone type. This operation can only be performed once on  *	a zone.  *  * Requires:  *\li	'zone' to be a valid zone.  *\li	dns_zone_settype() not to have been called since the zone was  *	created.  *\li	'type' != dns_zone_none  */
end_comment

begin_function_decl
name|void
name|dns_zone_setview
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_view_t
modifier|*
name|view
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Associate the zone with a view.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|dns_view_t
modifier|*
name|dns_zone_getview
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the zone's associated view.  *  * Requires:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setorigin
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|dns_name_t
modifier|*
name|origin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the zones origin to 'origin'.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'origin' to be non NULL.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li 	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|dns_name_t
modifier|*
name|dns_zone_getorigin
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the value of the origin.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setfile
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setfile2
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *    Sets the name of the master file in the format of 'format' from which  *    the zone loads its database to 'file'.  *  *    For zones that have no associated master file, 'file' will be NULL.  *  *	For zones with persistent databases, the file name  *	setting is ignored.  *  *    dns_zone_setfile() is a backward-compatible form of  *    dns_zone_setfile2(), which always specifies the  *    dns_masterformat_text (RFC1035) format.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_zone_getfile
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Gets the name of the zone's master file, if any.  *  * Requires:  *\li	'zone' to be valid initialised zone.  *  * Returns:  *\li	Pointer to null-terminated file name, or NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_load
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_loadnew
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_loadandthaw
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Cause the database to be loaded from its backing store.  *	Confirm that the minimum requirements for the zone type are  *	met, otherwise DNS_R_BADZONE is returned.  *  *	dns_zone_loadnew() only loads zones that are not yet loaded.  *	dns_zone_load() also loads zones that are already loaded and  *	and whose master file has changed since the last load.  *	dns_zone_loadandthaw() is similar to dns_zone_load() but will  *	also re-enable DNS UPDATEs when the load completes.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	#ISC_R_UNEXPECTED  *\li	#ISC_R_SUCCESS  *\li	DNS_R_CONTINUE	  Incremental load has been queued.  *\li	DNS_R_UPTODATE	  The zone has already been loaded based on  *			  file system timestamps.  *\li	DNS_R_BADZONE  *\li	Any result value from dns_db_load().  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_asyncload
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zt_zoneloaded_t
name|done
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Cause the database to be loaded from its backing store asynchronously.  * Other zone maintenance functions are suspended until this is complete.  * When finished, 'done' is called to inform the caller, with 'arg' as  * its first argument and 'zone' as its second.  (Normally, 'arg' is  * expected to point to the zone table but is left undefined for testing  * purposes.)  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns__zone_loadpending
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Indicates whether the zone is waiting to be loaded asynchronously.  * (Not currently intended for use outside of this module and associated  * tests.)  */
end_comment

begin_function_decl
name|void
name|dns_zone_attach
parameter_list|(
name|dns_zone_t
modifier|*
name|source
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Attach '*target' to 'source' incrementing its external  * 	reference count.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'target' to be non NULL and '*target' to be NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zone_detach
parameter_list|(
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Detach from a zone decrementing its external reference count.  *	If this was the last external reference to the zone it will be  * 	shut down and eventually freed.  *  * Require:  *\li	'zonep' to point to a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_iattach
parameter_list|(
name|dns_zone_t
modifier|*
name|source
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Attach '*target' to 'source' incrementing its internal  * 	reference count.  This is intended for use by operations  * 	such as zone transfers that need to prevent the zone  * 	object from being freed but not from shutting down.  *  * Require:  *\li	The caller is running in the context of the zone's task.  *\li	'zone' to be a valid zone.  *\li	'target' to be non NULL and '*target' to be NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zone_idetach
parameter_list|(
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Detach from a zone decrementing its internal reference count.  *	If there are no more internal or external references to the  * 	zone, it will be freed.  *  * Require:  *\li	The caller is running in the context of the zone's task.  *\li	'zonep' to point to a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setflag
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|isc_boolean_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets ('value' == 'ISC_TRUE') / clears ('value' == 'IS_FALSE')  *	zone flags.  Valid flag bits are DNS_ZONE_F_*.  *  * Requires  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_getdb
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Attach '*dbp' to the database to if it exists otherwise  *	return DNS_R_NOTLOADED.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'dbp' to be != NULL&& '*dbp' == NULL.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	DNS_R_NOTLOADED  */
end_comment

begin_function_decl
name|void
name|dns_zone_setdb
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the zone database to 'db'.  *  *	This function is expected to be used to configure a zone with a  *	database which is not loaded from a file or zone transfer.  *	It can be used for a general purpose zone, but right now its use  *	is limited to static-stub zones to avoid possible undiscovered  *	problems in the general cases.  *  * Require:  *\li	'zone' to be a valid zone of static-stub.  *\li	zone doesn't have a database.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setdbtype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|unsigned
name|int
name|dbargc
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|dbargv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the database type to dbargv[0] and database arguments  *	to subsequent dbargv elements.  *	'db_type' is not checked to see if it is a valid database type.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'database' to be non NULL.  *\li	'dbargc' to be>= 1  *\li	'dbargv' to point to dbargc NULL-terminated strings  *  * Returns:  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_getdbtype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the current dbtype.  isc_mem_free() should be used  * 	to free 'argv' after use.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'argv' to be non NULL and *argv to be NULL.  *\li	'mctx' to be valid.  *  * Returns:  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|void
name|dns_zone_markdirty
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Mark a zone as 'dirty'.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_expire
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Mark the zone as expired.  If the zone requires dumping cause it to  *	be initiated.  Set the refresh and retry intervals to there default  *	values and unload the zone.  *  * Require  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_refresh
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Initiate zone up to date checks.  The zone must already be being  *	managed.  *  * Require  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_flush
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Write the zone to database if there are uncommitted changes.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_dump
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Write the zone to database.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_dumptostream
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_dumptostream2
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|FILE
modifier|*
name|fd
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_dumptostream3
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|FILE
modifier|*
name|fd
parameter_list|,
name|dns_masterformat_t
name|format
parameter_list|,
specifier|const
name|dns_master_style_t
modifier|*
name|style
parameter_list|,
specifier|const
name|isc_uint32_t
name|rawversion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *    Write the zone to stream 'fd' in the specified 'format'.  *    If the 'format' is dns_masterformat_text (RFC1035), 'style' also  *    specifies the file style (e.g.,&dns_master_style_default).  *  *    dns_zone_dumptostream() is a backward-compatible form of  *    dns_zone_dumptostream2(), which always uses the dns_masterformat_text  *    format and the dns_master_style_default style.  *  *    dns_zone_dumptostream2() is a backward-compatible form of  *    dns_zone_dumptostream3(), which always uses the current  *    default raw file format version.  *  *    Note that dns_zone_dumptostream3() is the most flexible form.  It  *    can also provide the functionality of dns_zone_fulldumptostream().  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'fd' to be a stream open for writing.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_fulldumptostream
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|FILE
modifier|*
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	The same as dns_zone_dumptostream, but dumps the zone with  *	different dump settings (dns_master_style_full).  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'fd' to be a stream open for writing.  */
end_comment

begin_function_decl
name|void
name|dns_zone_maintenance
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Perform regular maintenance on the zone.  This is called as a  *	result of a zone being managed.  *  * Require  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setmasters
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|masters
parameter_list|,
name|isc_uint32_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setmasterswithkeys
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|masters
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|keynames
parameter_list|,
name|isc_uint32_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the list of master servers for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'masters' array of isc_sockaddr_t with port set or NULL.  *\li	'count' the number of masters.  *\li      'keynames' array of dns_name_t's for tsig keys or NULL.  *  *  \li    dns_zone_setmasters() is just a wrapper to setmasterswithkeys(),  *      passing NULL in the keynames field.  *  * \li	If 'masters' is NULL then 'count' must be zero.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li      Any result dns_name_dup() can return, if keynames!=NULL  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setalsonotify
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|notify
parameter_list|,
name|isc_uint32_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setalsonotifywithkeys
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|notify
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|keynames
parameter_list|,
name|isc_uint32_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the list of additional servers to be notified when  *	a zone changes.	 To clear the list use 'count = 0'.  *  *	dns_zone_alsonotifywithkeys() allows each notify address to  *	be associated with a TSIG key.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'notify' to be non-NULL if count != 0.  *\li	'count' to be the number of notifiees.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|dns_zone_unload
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	detach the database from the zone structure.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setoption
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|unsigned
name|int
name|option
parameter_list|,
name|isc_boolean_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set given options on ('value' == ISC_TRUE) or off ('value' ==  *	#ISC_FALSE).  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_zone_getoptions
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the current zone options.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setkeyopt
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|unsigned
name|int
name|option
parameter_list|,
name|isc_boolean_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set key options on ('value' == ISC_TRUE) or off ('value' ==  *	#ISC_FALSE).  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_zone_getkeyopts
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the current zone key options.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setminrefreshtime
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the minimum refresh time.  *  * Requires:  *\li	'zone' is valid.  *\li	val> 0.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setmaxrefreshtime
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the maximum refresh time.  *  * Requires:  *\li	'zone' is valid.  *\li	val> 0.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setminretrytime
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the minimum retry time.  *  * Requires:  *\li	'zone' is valid.  *\li	val> 0.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setmaxretrytime
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the maximum retry time.  *  * Requires:  *\li	'zone' is valid.  *	val> 0.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setxfrsource4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|xfrsource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setaltxfrsource4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|xfrsource
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Set the source address to be used in IPv4 zone transfers.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'xfrsource' to contain the address.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getxfrsource4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getaltxfrsource4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the source address set by a previous dns_zone_setxfrsource4  *	call, or the default of inaddr_any, port 0.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setxfrsource6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|xfrsource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setaltxfrsource6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|xfrsource
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Set the source address to be used in IPv6 zone transfers.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'xfrsource' to contain the address.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getxfrsource6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getaltxfrsource6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the source address set by a previous dns_zone_setxfrsource6  *	call, or the default of in6addr_any, port 0.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setnotifysrc4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|notifysrc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Set the source address to be used with IPv4 NOTIFY messages.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'notifysrc' to contain the address.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getnotifysrc4
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the source address set by a previous dns_zone_setnotifysrc4  *	call, or the default of inaddr_any, port 0.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setnotifysrc6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|isc_sockaddr_t
modifier|*
name|notifysrc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Set the source address to be used with IPv6 NOTIFY messages.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'notifysrc' to contain the address.  *  * Returns:  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
name|isc_sockaddr_t
modifier|*
name|dns_zone_getnotifysrc6
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the source address set by a previous dns_zone_setnotifysrc6  *	call, or the default of in6addr_any, port 0.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setnotifyacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the notify acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be a valid acl.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setqueryacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the query acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be a valid acl.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setqueryonacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the query-on acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be a valid acl.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setupdateacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the update acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be valid acl.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setforwardacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the forward unsigned updates acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be valid acl.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setxfracl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acl_t
modifier|*
name|acl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the transfer acl list for the zone.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'acl' to be valid acl.  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getnotifyacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current notify acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getqueryacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current query acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getqueryonacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current query-on acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getupdateacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current update acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getforwardacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current forward unsigned updates acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|dns_acl_t
modifier|*
name|dns_zone_getxfracl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Returns the current transfer acl or NULL.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	acl a pointer to the acl.  *\li	NULL  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearupdateacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current update acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearforwardacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current forward unsigned updates acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearnotifyacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current notify acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearqueryacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current query acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearqueryonacl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current query-on acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_clearxfracl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Clear the current transfer acl.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_getupdatedisabled
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return update disabled.  * Transient unless called when running in isc_task_exclusive() mode.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setupdatedisabled
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set update disabled.  * Should only be called only when running in isc_task_exclusive() mode.  * Failure to do so may result in updates being committed after the  * call has been made.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_getzeronosoattl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return zero-no-soa-ttl status.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setzeronosoattl
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set zero-no-soa-ttl status.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setchecknames
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_severity_t
name|severity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Set the severity of name checking when loading a zone.  *  * Require:  * \li     'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|dns_severity_t
name|dns_zone_getchecknames
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return the current severity of name checking.  *  * Require:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setjournalsize
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_int32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the journal size for the zone.  *  * Requires:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_int32_t
name|dns_zone_getjournalsize
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return the journal size as set with a previous call to  *	dns_zone_setjournalsize().  *  * Requires:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_notifyreceive
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|from
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Tell the zone that it has received a NOTIFY message from another  *	server.  This may cause some zone maintenance activity to occur.  *  * Requires:  *\li	'zone' to be a valid zone.  *\li	'*from' to contain the address of the server from which 'msg'  *		was received.  *\li	'msg' a message with opcode NOTIFY and qr clear.  *  * Returns:  *\li	DNS_R_REFUSED  *\li	DNS_R_NOTIMP  *\li	DNS_R_FORMERR  *\li	DNS_R_SUCCESS  */
end_comment

begin_function_decl
name|void
name|dns_zone_setmaxxfrin
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|maxxfrin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the maximum time (in seconds) that a zone transfer in (AXFR/IXFR)  * of this zone will use before being aborted.  *  * Requires:  * \li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getmaxxfrin
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the maximum transfer time for this zone.  This will be  * either the value set by the last call to dns_zone_setmaxxfrin() or  * the default value of 1 hour.  *  * Requires:  *\li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setmaxxfrout
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|maxxfrout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the maximum time (in seconds) that a zone transfer out (AXFR/IXFR)  * of this zone will use before being aborted.  *  * Requires:  * \li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getmaxxfrout
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the maximum transfer time for this zone.  This will be  * either the value set by the last call to dns_zone_setmaxxfrout() or  * the default value of 1 hour.  *  * Requires:  *\li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setjournal
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|journal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets the filename used for journaling updates / IXFR transfers.  * The default journal name is set by dns_zone_setfile() to be  * "file.jnl".  If 'journal' is NULL, the zone will have no  * journal name.  *  * Requires:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|char
modifier|*
name|dns_zone_getjournal
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the journal name associated with this zone.  * If no journal has been set this will be NULL.  *  * Requires:  *\li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|dns_zonetype_t
name|dns_zone_gettype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the type of the zone (master/slave/etc.)  *  * Requires:  *\li	'zone' to be valid initialised zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_settask
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Give a zone a task to work with.  Any current task will be detached.  *  * Requires:  *\li	'zone' to be valid.  *\li	'task' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_zone_gettask
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach '*target' to the zone's task.  *  * Requires:  *\li	'zone' to be valid initialised zone.  *\li	'zone' to have a task.  *\li	'target' to be != NULL&& '*target' == NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zone_notify
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Generate notify events for this zone.  *  * Requires:  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_replacedb
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_boolean_t
name|dump
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Replace the database of "zone" with a new database "db".  *  * If "dump" is ISC_TRUE, then the new zone contents are dumped  * into to the zone's master file for persistence.  When replacing  * a zone database by one just loaded from a master file, set  * "dump" to ISC_FALSE to avoid a redundant redump of the data just  * loaded.  Otherwise, it should be set to ISC_TRUE.  *  * If the "diff-on-reload" option is enabled in the configuration file,  * the differences between the old and the new database are added to the  * journal file, and the master file dump is postponed.  *  * Requires:  * \li	'zone' to be a valid zone.  *  * Returns:  * \li	DNS_R_SUCCESS  * \li	DNS_R_BADZONE	zone failed basic consistency checks:  *			* a single SOA must exist  *			* some NS records must exist.  *	Others  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getidlein
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Requires:  * \li	'zone' to be a valid zone.  *  * Returns:  * \li	number of seconds of idle time before we abort the transfer in.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setidlein
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|idlein
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * \li	Set the idle timeout for transfer the.  * \li	Zero set the default value, 1 hour.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getidleout
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *  * Requires:  * \li	'zone' to be a valid zone.  *  * Returns:  * \li	number of seconds of idle time before we abort a transfer out.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setidleout
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|idleout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * \li	Set the idle timeout for transfers out.  * \li	Zero set the default value, 1 hour.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_getssutable
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_ssutable_t
modifier|*
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the simple-secure-update policy table.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setssutable
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_ssutable_t
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set / clear the simple-secure-update policy table.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_mem_t
modifier|*
name|dns_zone_getmctx
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the memory context of a zone.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|dns_zonemgr_t
modifier|*
name|dns_zone_getmgr
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	If 'zone' is managed return the zone manager otherwise NULL.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setsigvalidityinterval
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the zone's RRSIG validity interval.  This is the length of time  * for which DNSSEC signatures created as a result of dynamic updates  * to secure zones will remain valid, in seconds.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getsigvalidityinterval
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the zone's RRSIG validity interval.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setsigresigninginterval
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the zone's RRSIG re-signing interval.  A dynamic zone's RRSIG's  * will be re-signed 'interval' amount of time before they expire.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getsigresigninginterval
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the zone's RRSIG re-signing interval.  *  * Requires:  * \li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setnotifytype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_notifytype_t
name|notifytype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets zone notify method to "notifytype"  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_forwardupdate
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_message_t
modifier|*
name|msg
parameter_list|,
name|dns_updatecallback_t
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Forward 'msg' to each master in turn until we get an answer or we  * have exhausted the list of masters. 'callback' will be called with  * ISC_R_SUCCESS if we get an answer and the returned message will be  * passed as 'answer_message', otherwise a non ISC_R_SUCCESS result code  * will be passed and answer_message will be NULL.  The callback function  * is responsible for destroying 'answer_message'.  *		(callback)(callback_arg, result, answer_message);  *  * Require:  *\li	'zone' to be valid  *\li	'msg' to be valid.  *\li	'callback' to be non NULL.  * Returns:  *\li	#ISC_R_SUCCESS if the message has been forwarded,  *\li	#ISC_R_NOMEMORY  *\li	Others  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_next
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the next zone in the list of managed zones.  *  * Requires:  *\li	'zone' to be valid  *\li	The zone manager for the indicated zone MUST be locked  *	by the caller.  This is not checked.  *\li	'next' be non-NULL, and '*next' be NULL.  *  * Ensures:  *\li	'next' points to a valid zone (result ISC_R_SUCCESS) or to NULL  *	(result ISC_R_NOMORE).  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_first
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find the first zone in the list of managed zones.  *  * Requires:  *\li	'zonemgr' to be valid  *\li	The zone manager for the indicated zone MUST be locked  *	by the caller.  This is not checked.  *\li	'first' be non-NULL, and '*first' be NULL  *  * Ensures:  *\li	'first' points to a valid zone (result ISC_R_SUCCESS) or to NULL  *	(result ISC_R_NOMORE).  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setkeydirectory
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|directory
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Sets the name of the directory where private keys used for  *	online signing of dynamic zones are found.  *  * Require:  *\li	'zone' to be a valid zone.  *  * Returns:  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_SUCCESS  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|dns_zone_getkeydirectory
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * 	Gets the name of the directory where private keys used for  *	online signing of dynamic zones are found.  *  * Requires:  *\li	'zone' to be valid initialised zone.  *  * Returns:  *	Pointer to null-terminated file name, or NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zonemgr_create
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
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|,
name|dns_zonemgr_t
modifier|*
modifier|*
name|zmgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a zone manager.  Note: the zone manager will not be able to  * manage any zones until dns_zonemgr_setsize() has been run.  *  * Requires:  *\li	'mctx' to be a valid memory context.  *\li	'taskmgr' to be a valid task manager.  *\li	'timermgr' to be a valid timer manager.  *\li	'zmgrp'	to point to a NULL pointer.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zonemgr_setsize
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|int
name|num_zones
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the size of the zone manager task pool.  This must be run  *	before zmgr can be used for managing zones.  Currently, it can only  *	be run once; the task pool cannot be resized.  *  * Requires:  *\li	zmgr is a valid zone manager.  *\li	zmgr->zonetasks has been initialized.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zonemgr_createzone
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|zonep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Allocate a new zone using a memory context from the  *	zone manager's memory context pool.  *  * Require:  *\li	'zmgr' to be a valid zone manager.  *\li	'zonep' != NULL and '*zonep' == NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zonemgr_managezone
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Bring the zone under control of a zone manager.  *  * Require:  *\li	'zmgr' to be a valid zone manager.  *\li	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zonemgr_forcemaint
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Force zone maintenance of all zones managed by 'zmgr' at its  * earliest convenience.  */
end_comment

begin_function_decl
name|void
name|dns__zonemgr_run
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Event handler to call dns_zonemgr_forcemaint(); used to start  * zone operations from a unit test.  Not intended for use outside  * libdns or related tests.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_resumexfrs
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attempt to start any stalled zone transfers.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_shutdown
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Shut down the zone manager.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_attach
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|source
parameter_list|,
name|dns_zonemgr_t
modifier|*
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Attach '*target' to 'source' incrementing its external  * 	reference count.  *  * Require:  *\li	'zone' to be a valid zone.  *\li	'target' to be non NULL and '*target' to be NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_detach
parameter_list|(
name|dns_zonemgr_t
modifier|*
modifier|*
name|zmgrp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	 Detach from a zone manager.  *  * Requires:  *\li	'*zmgrp' is a valid, non-NULL zone manager pointer.  *  * Ensures:  *\li	'*zmgrp' is NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_releasezone
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Release 'zone' from the managed by 'zmgr'.  'zmgr' is implicitly  *	detached from 'zone'.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'zone' to be a valid zone.  *\li	'zmgr' == 'zone->zmgr'  *  * Ensures:  *\li	'zone->zmgr' == NULL;  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_settransfersin
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the maximum number of simultaneous transfers in allowed by  *	the zone manager.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zonemgr_getttransfersin
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return the maximum number of simultaneous transfers in allowed.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_settransfersperns
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the number of zone transfers allowed per nameserver.  *  * Requires:  *\li	'zmgr' to be a valid zone manager  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zonemgr_getttransfersperns
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return the number of transfers allowed per nameserver.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_setiolimit
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_uint32_t
name|iolimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the number of simultaneous file descriptors available for  *	reading and writing masterfiles.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'iolimit' to be positive.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zonemgr_getiolimit
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Get the number of simultaneous file descriptors available for  *	reading and writing masterfiles.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_setserialqueryrate
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the number of SOA queries sent per second.  *  * Requires:  *\li	'zmgr' to be a valid zone manager  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_zonemgr_getserialqueryrate
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Return the number of SOA queries sent per second.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_zonemgr_getcount
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns the number of zones in the specified state.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'state' to be a valid DNS_ZONESTATE_ constant.  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_unreachableadd
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|remote
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|local
parameter_list|,
name|isc_time_t
modifier|*
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Add the pair of addresses to the unreachable cache.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'remote' to be a valid sockaddr.  *\li	'local' to be a valid sockaddr.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zonemgr_unreachable
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|remote
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|local
parameter_list|,
name|isc_time_t
modifier|*
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Returns ISC_TRUE if the given local/remote address pair  *	is found in the zone maanger's unreachable cache.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'remote' to be a valid sockaddr.  *\li	'local' to be a valid sockaddr.  *\li	'now' != NULL  */
end_comment

begin_function_decl
name|void
name|dns_zonemgr_unreachabledel
parameter_list|(
name|dns_zonemgr_t
modifier|*
name|zmgr
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|remote
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Remove the pair of addresses from the unreachable cache.  *  * Requires:  *\li	'zmgr' to be a valid zone manager.  *\li	'remote' to be a valid sockaddr.  *\li	'local' to be a valid sockaddr.  */
end_comment

begin_function_decl
name|void
name|dns_zone_forcereload
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *      Force a reload of specified zone.  *  * Requires:  *\li      'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_isforced
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *      Check if the zone is waiting a forced reload.  *  * Requires:  * \li     'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setstatistics
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This function is obsoleted by dns_zone_setrequeststats().  */
end_comment

begin_function_decl
name|isc_uint64_t
modifier|*
name|dns_zone_getstatscounters
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This function is obsoleted by dns_zone_getrequeststats().  */
end_comment

begin_function_decl
name|void
name|dns_zone_setstats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set a general zone-maintenance statistics set 'stats' for 'zone'.  This  * function is expected to be called only on zone creation (when necessary).  * Once installed, it cannot be removed or replaced.  Also, there is no  * interface to get the installed stats from the zone; the caller must keep the  * stats to reference (e.g. dump) it later.  *  * Requires:  * \li	'zone' to be a valid zone and does not have a statistics set already  *	installed.  *  *\li	stats is a valid statistics supporting zone statistics counters  *	(see dns/stats.h).  */
end_comment

begin_function_decl
name|void
name|dns_zone_setrequeststats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_zone_setrcvquerystats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set additional statistics sets to zone.  These are attached to the zone  * but are not counted in the zone module; only the caller updates the  * counters.  *  * Requires:  * \li	'zone' to be a valid zone.  *  *\li	stats is a valid statistics.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSTATS
end_ifdef

begin_function_decl
name|void
name|dns_zone_setrcvquerystats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_stats_t
modifier|*
name|stats
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|isc_stats_t
modifier|*
name|dns_zone_getrequeststats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|NEWSTATS
end_ifdef

begin_function_decl
name|dns_stats_t
modifier|*
name|dns_zone_getrcvquerystats
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%<  * Get the additional statistics for zone, if one is installed.  *  * Requires:  * \li	'zone' to be a valid zone.  *  * Returns:  * \li	when available, a pointer to the statistics set installed in zone;  *	otherwise NULL.  */
end_comment

begin_function_decl
name|void
name|dns_zone_dialup
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Perform dialup-time maintenance on 'zone'.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setdialup
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_dialuptype_t
name|dialup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the dialup type of 'zone' to 'dialup'.  *  * Requires:  * \li	'zone' to be valid initialised zone.  *\li	'dialup' to be a valid dialup type.  */
end_comment

begin_function_decl
name|void
name|dns_zone_log
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%<  * Log the message 'msg...' at 'level', including text that identifies  * the message as applying to 'zone'.  */
end_comment

begin_function_decl
name|void
name|dns_zone_logc
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%<  * Log the message 'msg...' at 'level', including text that identifies  * the message as applying to 'zone'.  */
end_comment

begin_function_decl
name|void
name|dns_zone_name
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the name of the zone with class and view.  *  * Requires:  *\li	'zone' to be valid.  *\li	'buf' to be non NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_checknames
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_rdata_t
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Check if this record meets the check-names policy.  *  * Requires:  *	'zone' to be valid.  *	'name' to be valid.  *	'rdata' to be valid.  *  * Returns:  *	DNS_R_SUCCESS		passed checks.  *	DNS_R_BADOWNERNAME	failed ownername checks.  *	DNS_R_BADNAME		failed rdata checks.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setacache
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_acache_t
modifier|*
name|acache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Associate the zone with an additional cache.  *  * Require:  *	'zone' to be a valid zone.  *	'acache' to be a non NULL pointer.  *  * Ensures:  *	'zone' will have a reference to 'acache'  */
end_comment

begin_function_decl
name|void
name|dns_zone_setcheckmx
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_checkmxfunc_t
name|checkmx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the post load integrity callback function 'checkmx'.  *	'checkmx' will be called if the MX TARGET is not within the zone.  *  * Require:  *	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setchecksrv
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_checkmxfunc_t
name|checksrv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the post load integrity callback function 'checksrv'.  *	'checksrv' will be called if the SRV TARGET is not within the zone.  *  * Require:  *	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setcheckns
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_checknsfunc_t
name|checkns
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  *	Set the post load integrity callback function 'checkns'.  *	'checkns' will be called if the NS TARGET is not within the zone.  *  * Require:  *	'zone' to be a valid zone.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setnotifydelay
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the minimum delay between sets of notify messages.  *  * Requires:  *	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_zone_getnotifydelay
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the minimum delay between sets of notify messages.  *  * Requires:  *	'zone' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setisself
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_isselffunc_t
name|isself
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the isself callback function and argument.  *  * isc_boolean_t  * isself(dns_view_t *myview, dns_tsigkey_t *mykey, isc_netaddr_t *srcaddr,  *	  isc_netaddr_t *destaddr, dns_rdataclass_t rdclass, void *arg);  *  * 'isself' returns ISC_TRUE if a non-recursive query from 'srcaddr' to  * 'destaddr' with optional key 'mykey' for class 'rdclass' would be  * delivered to 'myview'.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setnodes
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|nodes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the number of nodes that will be checked per quantum.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setsignatures
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|signatures
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the number of signatures that will be generated per quantum.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_signwithkey
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_secalg_t
name|algorithm
parameter_list|,
name|isc_uint16_t
name|keyid
parameter_list|,
name|isc_boolean_t
name|deleteit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initiate/resume signing of the entire zone with the zone DNSKEY(s)  * that match the given algorithm and keyid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_addnsec3chain
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_rdata_nsec3param_t
modifier|*
name|nsec3param
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Incrementally add a NSEC3 chain that corresponds to 'nsec3param'.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setprivatetype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_rdatatype_t
name|dns_zone_getprivatetype
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get/Set the private record type.  It is expected that these interfaces  * will not be permanent.  */
end_comment

begin_function_decl
name|void
name|dns_zone_rekey
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|fullsign
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Update the zone's DNSKEY set from the key repository.  *  * If 'fullsign' is true, trigger an immediate full signing of  * the zone with the new key.  Otherwise, if there are no keys or  * if the new keys are for algorithms that have already signed the  * zone, then the zone can be re-signed incrementally.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_nscheck
parameter_list|(
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
name|unsigned
name|int
modifier|*
name|errors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Check if the name servers for the zone are sane (have address, don't  * refer to CNAMEs/DNAMEs.  The number of constiancy errors detected in  * returned in '*errors'  *  * Requires:  * \li	'zone' to be valid.  * \li	'db' to be valid.  * \li	'version' to be valid or NULL.  * \li	'errors' to be non NULL.  *  * Returns:  * 	ISC_R_SUCCESS if there were no errors examining the zone contents.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setadded
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|added
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Sets the value of zone->added, which should be ISC_TRUE for  * zones that were originally added by "rndc addzone".  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_getadded
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Returns ISC_TRUE if the zone was originally added at runtime  * using "rndc addzone".  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_dlzpostload
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Load the origin names for a writeable DLZ database.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_isdynamic
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|ignore_freeze
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Return true iff the zone is "dynamic", in the sense that the zone's  * master file (if any) is written by the server, rather than being  * updated manually and read by the server.  *  * This is true for slave zones, stub zones, key zones, and zones that  * allow dynamic updates either by having an update policy ("ssutable")  * or an "allow-update" ACL with a value other than exactly "{ none; }".  *  * If 'ignore_freeze' is true, then the zone which has had updates disabled  * will still report itself to be dynamic.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_setrefreshkeyinterval
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint32_t
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Sets the frequency, in minutes, with which the key repository will be  * checked to see if the keys for this zone have been updated.  Any value  * higher than 1440 minutes (24 hours) will be silently reduced.  A  * value of zero will return an out-of-range error.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_getrequestixfr
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Returns the true/false value of the request-ixfr option in the zone.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setrequestixfr
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_boolean_t
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Sets the request-ixfr option for the zone. Either true or false. The  * default value is determined by the setting of this option in the view.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setserialupdatemethod
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_updatemethod_t
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Sets the update method to use when incrementing the zone serial number  * due to a DDNS update.  Valid options are dns_updatemethod_increment  * and dns_updatemethod_unixtime.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|dns_updatemethod_t
name|dns_zone_getserialupdatemethod
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Returns the update method to be used when incrementing the zone serial  * number due to a DDNS update.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_link
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zone_t
modifier|*
name|raw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_zone_getraw
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zone_t
modifier|*
modifier|*
name|raw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_keydone
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_zone_setnsec3param
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|isc_uint8_t
name|hash
parameter_list|,
name|isc_uint8_t
name|flags
parameter_list|,
name|isc_uint16_t
name|iter
parameter_list|,
name|isc_uint8_t
name|saltlen
parameter_list|,
name|unsigned
name|char
modifier|*
name|salt
parameter_list|,
name|isc_boolean_t
name|replace
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Set the NSEC3 parameters for the zone.  *  * If 'replace' is ISC_TRUE, then the existing NSEC3 chain, if any, will  * be replaced with the new one.  If 'hash' is zero, then the replacement  * chain will be NSEC rather than NSEC3.  *  * Requires:  * \li	'zone' to be valid.  */
end_comment

begin_function_decl
name|void
name|dns_zone_setrawdata
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_masterrawheader_t
modifier|*
name|header
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Set the data to be included in the header when the zone is dumped in  * binary format.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_synckeyzone
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Force the managed key zone to synchronize, and start the key  * maintenance timer.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_rpz_enable
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Set the response policy associated with a zone.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_zone_rpz_enable_db
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * If a zone is a response policy zone, mark its new database.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_zone_get_rpz
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns_zone_setstatlevel
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|,
name|dns_zonestat_level_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|dns_zonestat_level_t
name|dns_zone_getstatlevel
parameter_list|(
name|dns_zone_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%  * Set and get the statistics reporting level for the zone;  * full, terse, or none.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_ZONE_H */
end_comment

end_unit

