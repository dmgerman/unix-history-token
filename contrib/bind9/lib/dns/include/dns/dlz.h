begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2005  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Copyright (C) 2002 Stichting NLnet, Netherlands, stichting@nlnet.nl.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the  * above copyright notice and this permission notice appear in all  * copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND STICHTING NLNET  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * STICHTING NLNET BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS  * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE  * USE OR PERFORMANCE OF THIS SOFTWARE.  *  * The development of Dynamically Loadable Zones (DLZ) for Bind 9 was  * conceived and contributed by Rob Butler.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the  * above copyright notice and this permission notice appear in all  * copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ROB BUTLER  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * ROB BUTLER BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS  * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE  * USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: dlz.h,v 1.2.2.2 2005/09/06 03:47:18 marka Exp $ */
end_comment

begin_comment
comment|/*! \file */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DLZ_H
end_ifndef

begin_define
define|#
directive|define
name|DLZ_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DLZ Interface  *  * The DLZ interface allows zones to be looked up using a driver instead of  * Bind's default in memory zone table.  *  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
end_comment

begin_include
include|#
directive|include
file|<dns/name.h>
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

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_define
define|#
directive|define
name|DNS_DLZ_MAGIC
value|ISC_MAGIC('D','L','Z','D')
end_define

begin_define
define|#
directive|define
name|DNS_DLZ_VALID
parameter_list|(
name|dlz
parameter_list|)
value|ISC_MAGIC_VALID(dlz, DNS_DLZ_MAGIC)
end_define

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_dlzallowzonexfr_t
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
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|clientaddr
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<  * Method prototype.  Drivers implementing the DLZ interface MUST  * supply an allow zone transfer method.  This method is called when  * the DNS server is performing a zone transfer query.  The driver's  * method should return ISC_R_SUCCESS and a database pointer to the  * name server if the zone is supported by the database, and zone  * transfer is allowed.  Otherwise it will return ISC_R_NOTFOUND if  * the zone is not supported by the database, or ISC_R_NOPERM if zone  * transfers are not allowed.  If an error occurs it should return a  * result code indicating the type of error.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_dlzcreate_t
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
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
comment|/*%<  * Method prototype.  Drivers implementing the DLZ interface MUST  * supply a create method.  This method is called when the DNS server  * is starting up and creating drivers for use later.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|dns_dlzdestroy_t
function_decl|)
parameter_list|(
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
comment|/*%<  * Method prototype.  Drivers implementing the DLZ interface MUST  * supply a destroy method.  This method is called when the DNS server  * is shuting down and no longer needs the driver.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_dlzfindzone_t
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
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*%<   * Method prototype.  Drivers implementing the DLZ interface MUST  * supply a find zone method.  This method is called when the DNS  * server is performing a query.  The find zone method will be called  * with the longest possible name first, and continue to be called  * with successively shorter domain names, until any of the following  * occur:  *  * \li	1) a match is found, and the function returns (ISC_R_SUCCESS)  *  * \li	2) a problem occurs, and the functions returns anything other  *	   than (ISC_R_NOTFOUND)  * \li	3) we run out of domain name labels. I.E. we have tried the  *	   shortest domain name  * \li	4) the number of labels in the domain name is less than  *	   min_lables for dns_dlzfindzone  *  * The driver's find zone method should return ISC_R_SUCCESS and a  * database pointer to the name server if the zone is supported by the  * database.  Otherwise it will return ISC_R_NOTFOUND, and a null  * pointer if the zone is not supported.  If an error occurs it should  * return a result code indicating the type of error.  */
end_comment

begin_comment
comment|/*% the methods supplied by a DLZ driver */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_dlzmethods
block|{
name|dns_dlzcreate_t
name|create
decl_stmt|;
name|dns_dlzdestroy_t
name|destroy
decl_stmt|;
name|dns_dlzfindzone_t
name|findzone
decl_stmt|;
name|dns_dlzallowzonexfr_t
name|allowzonexfr
decl_stmt|;
block|}
name|dns_dlzmethods_t
typedef|;
end_typedef

begin_comment
comment|/*% information about a DLZ driver */
end_comment

begin_struct
struct|struct
name|dns_dlzimplementation
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|dns_dlzmethods_t
modifier|*
name|methods
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|void
modifier|*
name|driverarg
decl_stmt|;
name|ISC_LINK
argument_list|(
argument|dns_dlzimplementation_t
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*% an instance of a DLZ driver */
end_comment

begin_struct
struct|struct
name|dns_dlzdb
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
name|dns_dlzimplementation_t
modifier|*
name|implementation
decl_stmt|;
name|void
modifier|*
name|dbdata
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Method declarations  ***/
end_comment

begin_function_decl
name|isc_result_t
name|dns_dlzallowzonexfr
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_sockaddr_t
modifier|*
name|clientaddr
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This method is called when the DNS server is performing a zone  * transfer query.  It will call the DLZ driver's allow zone tranfer  * method.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dlzcreate
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|dlzname
parameter_list|,
specifier|const
name|char
modifier|*
name|drivername
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
name|dns_dlzdb_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This method is called when the DNS server is starting up and  * creating drivers for use later.  It will search the DLZ driver list  * for 'drivername' and return a DLZ driver via dbp if a match is  * found.  If the DLZ driver supplies a create method, this function  * will call it.  */
end_comment

begin_function_decl
name|void
name|dns_dlzdestroy
parameter_list|(
name|dns_dlzdb_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This method is called when the DNS server is shuting down and no  * longer needs the driver.  If the DLZ driver supplies a destroy  * methods, this function will call it.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dlzfindzone
parameter_list|(
name|dns_view_t
modifier|*
name|view
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|minlabels
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This method is called when the DNS server is performing a query.  * It will call the DLZ driver's find zone method.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dlzregister
parameter_list|(
specifier|const
name|char
modifier|*
name|drivername
parameter_list|,
specifier|const
name|dns_dlzmethods_t
modifier|*
name|methods
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_dlzimplementation_t
modifier|*
modifier|*
name|dlzimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a dynamically loadable zones (DLZ) driver for the database  * type 'drivername', implemented by the functions in '*methods'.  *  * dlzimp must point to a NULL dlz_implementation_t pointer.  That is,  * dlzimp != NULL&& *dlzimp == NULL.  It will be assigned a value that  * will later be used to identify the driver when deregistering it.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_dlzstrtoargv
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|int
modifier|*
name|argcp
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argvp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * This method is called when the name server is starting up to parse  * the DLZ driver command line from named.conf.  Basically it splits  * up a string into and argc / argv.  The primary difference of this  * method is items between braces { } are considered only 1 word.  for  * example the command line "this is { one grouped phrase } and this  * isn't" would be parsed into:  *  * \li	argv[0]: "this"  * \li	argv[1]: "is"  * \li	argv{2]: " one grouped phrase "  * \li	argv[3]: "and"  * \li	argv[4]: "this"  * \li	argv{5}: "isn't"  *  * braces should NOT be nested, more than one grouping in the command  * line is allowed.  Notice, argv[2] has an extra space at the  * beginning and end.  Extra spaces are not stripped between a  * grouping.  You can do so in your driver if needed, or be sure not  * to put extra spaces before / after the braces.  */
end_comment

begin_function_decl
name|void
name|dns_dlzunregister
parameter_list|(
name|dns_dlzimplementation_t
modifier|*
modifier|*
name|dlzimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Removes the dlz driver from the list of registered dlz drivers.  * There must be no active dlz drivers of this type when this function  * is called.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DLZ_H */
end_comment

end_unit

