begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sdb.h,v 1.12.12.3 2004/03/08 09:04:39 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_SDB_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_SDB_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Simple database API.  */
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
file|<dns/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*  * A simple database.  This is an opaque type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdb
name|dns_sdb_t
typedef|;
end_typedef

begin_comment
comment|/*  * A simple database lookup in progress.  This is an opaque type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdblookup
name|dns_sdblookup_t
typedef|;
end_typedef

begin_comment
comment|/*  * A simple database traversal in progress.  This is an opaque type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdballnodes
name|dns_sdballnodes_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdblookupfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdblookup_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdbauthorityfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdblookup_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdballnodesfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdballnodes_t
modifier|*
name|allnodes
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdbcreatefunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|void
modifier|*
name|driverdata
parameter_list|,
name|void
modifier|*
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_sdbdestroyfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|driverdata
parameter_list|,
name|void
modifier|*
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dns_sdbmethods
block|{
name|dns_sdblookupfunc_t
name|lookup
decl_stmt|;
name|dns_sdbauthorityfunc_t
name|authority
decl_stmt|;
name|dns_sdballnodesfunc_t
name|allnodes
decl_stmt|;
name|dns_sdbcreatefunc_t
name|create
decl_stmt|;
name|dns_sdbdestroyfunc_t
name|destroy
decl_stmt|;
block|}
name|dns_sdbmethods_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
define|#
directive|define
name|DNS_SDBFLAG_RELATIVEOWNER
value|0x00000001U
define|#
directive|define
name|DNS_SDBFLAG_RELATIVERDATA
value|0x00000002U
define|#
directive|define
name|DNS_SDBFLAG_THREADSAFE
value|0x00000004U
name|isc_result_t
name|dns_sdb_register
parameter_list|(
specifier|const
name|char
modifier|*
name|drivername
parameter_list|,
specifier|const
name|dns_sdbmethods_t
modifier|*
name|methods
parameter_list|,
name|void
modifier|*
name|driverdata
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_sdbimplementation_t
modifier|*
modifier|*
name|sdbimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Register a simple database driver for the database type 'drivername',  * implemented by the functions in '*methods'.  *  * sdbimp must point to a NULL dns_sdbimplementation_t pointer.  That is,  * sdbimp != NULL&& *sdbimp == NULL.  It will be assigned a value that  * will later be used to identify the driver when deregistering it.  *  * The name server will perform lookups in the database by calling the  * function 'lookup', passing it a printable zone name 'zone', a printable  * domain name 'name', and a copy of the argument 'dbdata' that  * was potentially returned by the create function.  The 'dns_sdblookup_t'  * argument to 'lookup' and 'authority' is an opaque pointer to be passed to  * ns_sdb_putrr().  *  * The lookup function returns the lookup results to the name server  * by calling ns_sdb_putrr() once for each record found.  On success,  * the return value of the lookup function should be ISC_R_SUCCESS.  * If the domain name 'name' does not exist, the lookup function should  * ISC_R_NOTFOUND.  Any other return value is treated as an error.  *  * Lookups at the zone apex will cause the server to also call the  * function 'authority' (if non-NULL), which must provide an SOA record  * and NS records for the zone by calling ns_sdb_putrr() once for each of  * these records.  The 'authority' function may be NULL if invoking  * the 'lookup' function on the zone apex will return SOA and NS records.  *  * The allnodes function, if non-NULL, fills in an opaque structure to be  * used by a database iterator.  This allows the zone to be transferred.  * This may use a considerable amount of memory for large zones, and the  * zone transfer may not be fully RFC 1035 compliant if the zone is   * frequently changed.  *  * The create function will be called for each zone configured  * into the name server using this database type.  It can be used  * to create a "database object" containg zone specific data,  * which can make use of the database arguments specified in the  * name server configuration.  *  * The destroy function will be called to free the database object  * when its zone is destroyed.  *  * The create and destroy functions may be NULL.  *  * If flags includes DNS_SDBFLAG_RELATIVEOWNER, the lookup and authority  * functions will be called with relative names rather than absolute names.  * The string "@" represents the zone apex in this case.  *  * If flags includes DNS_SDBFLAG_RELATIVERDATA, the rdata strings may  * include relative names.  Otherwise, all names in the rdata string must  * be absolute.  Be aware that if relative names are allowed, any  * absolute names must contain a trailing dot.  *  * If flags includes DNS_SDBFLAG_THREADSAFE, the driver must be able to  * handle multiple lookups in parallel.  Otherwise, calls into the driver  * are serialized.  */
end_comment

begin_function_decl
name|void
name|dns_sdb_unregister
parameter_list|(
name|dns_sdbimplementation_t
modifier|*
modifier|*
name|sdbimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Removes the simple database driver from the list of registered database  * types.  There must be no active databases of this type when this function  * is called.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdb_putrr
parameter_list|(
name|dns_sdblookup_t
modifier|*
name|lookup
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|dns_ttl_t
name|ttl
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
name|dns_sdb_putrdata
parameter_list|(
name|dns_sdblookup_t
modifier|*
name|lookup
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|rdata
parameter_list|,
name|unsigned
name|int
name|rdlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a single resource record to the lookup structure to be  * returned in the query response.  dns_sdb_putrr() takes the  * resource record in master file text format as a null-terminated  * string, and dns_sdb_putrdata() takes the raw RDATA in  * uncompressed wire format.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdb_putnamedrr
parameter_list|(
name|dns_sdballnodes_t
modifier|*
name|allnodes
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|dns_ttl_t
name|ttl
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
name|dns_sdb_putnamedrdata
parameter_list|(
name|dns_sdballnodes_t
modifier|*
name|allnodes
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_ttl_t
name|ttl
parameter_list|,
specifier|const
name|void
modifier|*
name|rdata
parameter_list|,
name|unsigned
name|int
name|rdlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a single resource record to the allnodes structure to be  * included in a zone transfer response, in text or wire  * format as above.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdb_putsoa
parameter_list|(
name|dns_sdblookup_t
modifier|*
name|lookup
parameter_list|,
specifier|const
name|char
modifier|*
name|mname
parameter_list|,
specifier|const
name|char
modifier|*
name|rname
parameter_list|,
name|isc_uint32_t
name|serial
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function may optionally be called from the 'authority' callback  * to simplify construction of the SOA record for 'zone'.  It will  * provide a SOA listing 'mname' as as the master server and 'rname' as  * the responsible person mailbox.  It is the responsibility of the  * driver to increment the serial number between responses if necessary.  * All other SOA fields will have reasonable default values.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_SDB_H */
end_comment

end_unit

