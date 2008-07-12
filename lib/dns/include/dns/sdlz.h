begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2002 Stichting NLnet, Netherlands, stichting@nlnet.nl.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the  * above copyright notice and this permission notice appear in all  * copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND STICHTING NLNET  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * STICHTING NLNET BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS  * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE  * USE OR PERFORMANCE OF THIS SOFTWARE.  *  * The development of Dynamically Loadable Zones (DLZ) for Bind 9 was  * conceived and contributed by Rob Butler.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the  * above copyright notice and this permission notice appear in all  * copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ROB BUTLER  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * ROB BUTLER BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS  * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE  * USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sdlz.h,v 1.2.2.2 2005/09/06 03:47:19 marka Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDLZ_H
end_ifndef

begin_define
define|#
directive|define
name|SDLZ_H
value|1
end_define

begin_include
include|#
directive|include
file|<dns/dlz.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_define
define|#
directive|define
name|DNS_SDLZFLAG_THREADSAFE
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|DNS_SDLZFLAG_RELATIVEOWNER
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|DNS_SDLZFLAG_RELATIVERDATA
value|0x00000004U
end_define

begin_comment
comment|/* A simple DLZ database. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdlz_db
name|dns_sdlz_db_t
typedef|;
end_typedef

begin_comment
comment|/* A simple DLZ database lookup in progress. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdlzlookup
name|dns_sdlzlookup_t
typedef|;
end_typedef

begin_comment
comment|/* A simple DLZ database traversal in progress. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_sdlzallnodes
name|dns_sdlzallnodes_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzallnodesfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzallnodes_t
modifier|*
name|allnodes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface may  * supply an all nodes method.  This method is called when the DNS  * server is performing a zone transfer query, after the allow zone  * transfer method has been called.  This method is only called if the  * allow zone transfer method returned ISC_R_SUCCESS.  This method and  * the allow zone transfer method are both required for zone transfers  * to be supported.  If the driver generates data dynamically (instead  * of searching in a database for it) it should not implement this  * function as a zone transfer would be meaningless.  A SDLZ driver  * does not have to implement an all nodes method.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzallowzonexfr_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|client
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface may  * supply an allow zone transfer method.  This method is called when  * the DNS server is performing a zone transfer query, before the all  * nodes method can be called.  This method and the all node method  * are both required for zone transfers to be supported.  If the  * driver generates data dynamically (instead of searching in a  * database for it) it should not implement this function as a zone  * transfer would be meaningless.  A SDLZ driver does not have to  * implement an allow zone transfer method.  *  * This method should return ISC_R_SUCCESS if the zone is supported by  * the database and a zone transfer is allowed for the specified  * client.  If the zone is supported by the database, but zone  * transfers are not allowed for the specified client this method  * should return ISC_R_NOPERM..  Lastly the method should return  * ISC_R_NOTFOUND if the zone is not supported by the database.  If an  * error occurs it should return a result code indicating the type of  * error.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzauthorityfunc_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|zone
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzlookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface may  * supply an authority method.  This method is called when the DNS  * server is performing a query, after both the find zone and lookup  * methods have been called.  This method is required if the lookup  * function does not supply authority information for the dns  * record. A SDLZ driver does not have to implement an authority  * method.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzcreate_t
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|dlzname
parameter_list|,
name|unsigned
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface may  * supply a create method.  This method is called when the DNS server  * is starting up and creating drivers for use later. A SDLZ driver  * does not have to implement a create method.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_sdlzdestroy_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface may  * supply a destroy method.  This method is called when the DNS server  * is shuting down and no longer needs the driver.  A SDLZ driver does  * not have to implement a destroy method.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzfindzone_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface MUST  * supply a find zone method.  This method is called when the DNS  * server is performing a query to to determine if 'name' is a  * supported dns zone.  The find zone method will be called with the  * longest possible name first, and continue to be called with  * successively shorter domain names, until any of the following  * occur:  *  * \li	1) the function returns (ISC_R_SUCCESS) indicating a zone name  *	   match.  *  * \li	2) a problem occurs, and the functions returns anything other than  *	   (ISC_R_NOTFOUND)  *  * \li	3) we run out of domain name labels. I.E. we have tried the  *	   shortest domain name  *  * \li	4) the number of labels in the domain name is less than min_lables  *	   for dns_dlzfindzone  *  * The driver's find zone method should return ISC_R_SUCCESS if the  * zone is supported by the database.  Otherwise it should return  * ISC_R_NOTFOUND, if the zone is not supported.  If an error occurs  * it should return a result code indicating the type of error.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_sdlzlookupfunc_t
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
name|driverarg
parameter_list|,
name|void
modifier|*
name|dbdata
parameter_list|,
name|dns_sdlzlookup_t
modifier|*
name|lookup
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the SDLZ interface MUST  * supply a lookup method.  This method is called when the DNS server  * is performing a query, after the find zone and before any other  * methods have been called.  This function returns record DNS record  * information using the dns_sdlz_putrr and dns_sdlz_putsoa functions.  * If this function supplies authority information for the DNS record  * the authority method is not required.  If it does not, the  * authority function is required.  A SDLZ driver must implement a  * lookup method.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_sdlzmethods
block|{
name|dns_sdlzcreate_t
name|create
decl_stmt|;
name|dns_sdlzdestroy_t
name|destroy
decl_stmt|;
name|dns_sdlzfindzone_t
name|findzone
decl_stmt|;
name|dns_sdlzlookupfunc_t
name|lookup
decl_stmt|;
name|dns_sdlzauthorityfunc_t
name|authority
decl_stmt|;
name|dns_sdlzallnodesfunc_t
name|allnodes
decl_stmt|;
name|dns_sdlzallowzonexfr_t
name|allowzonexfr
decl_stmt|;
block|}
name|dns_sdlzmethods_t
typedef|;
end_typedef

begin_function_decl
name|isc_result_t
name|dns_sdlzregister
parameter_list|(
specifier|const
name|char
modifier|*
name|drivername
parameter_list|,
specifier|const
name|dns_sdlzmethods_t
modifier|*
name|methods
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_sdlzimplementation_t
modifier|*
modifier|*
name|sdlzimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a dynamically loadable zones (dlz) driver for the database  * type 'drivername', implemented by the functions in '*methods'.  *  * sdlzimp must point to a NULL dns_sdlzimplementation_t pointer.  * That is, sdlzimp != NULL&& *sdlzimp == NULL.  It will be assigned  * a value that will later be used to identify the driver when  * deregistering it.  */
end_comment

begin_function_decl
name|void
name|dns_sdlzunregister
parameter_list|(
name|dns_sdlzimplementation_t
modifier|*
modifier|*
name|sdlzimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Removes the sdlz driver from the list of registered sdlz drivers.  * There must be no active sdlz drivers of this type when this  * function is called.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdlz_putnamedrr
parameter_list|(
name|dns_sdlzallnodes_t
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

begin_comment
comment|/*%<  * Add a single resource record to the allnodes structure to be later  * parsed into a zone transfer response.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdlz_putrr
parameter_list|(
name|dns_sdlzlookup_t
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

begin_comment
comment|/*%<  * Add a single resource record to the lookup structure to be later  * parsed into a query response.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_sdlz_putsoa
parameter_list|(
name|dns_sdlzlookup_t
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
comment|/*%<  * This function may optionally be called from the 'authority'  * callback to simplify construction of the SOA record for 'zone'.  It  * will provide a SOA listing 'mname' as as the master server and  * 'rname' as the responsible person mailbox.  It is the  * responsibility of the driver to increment the serial number between  * responses if necessary.  All other SOA fields will have reasonable  * default values.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SDLZ_H */
end_comment

end_unit

