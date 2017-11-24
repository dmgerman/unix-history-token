begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_DB_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_DB_H_
end_define

begin_comment
comment|/*  * Abstract:  * Declaration of the DB interface.  */
end_comment

begin_include
include|#
directive|include
file|<complib/cl_list.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_spinlock.h>
end_include

begin_struct_decl
struct_decl|struct
name|osm_log
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* OpenSM/Database * NAME *	Database * * DESCRIPTION *	The OpenSM database interface provide the means to restore persistent *  data, query, modify, delete and eventually commit it back to the *  persistent media. * *  The interface is defined such that it can is not "data dependent": *  All keys and data items are texts. * *	The DB implementation should be thread safe, thus callers do not need to *  provide serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Eitan Zahavi, Mellanox Technologies LTD * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Database/osm_db_domain_t * NAME *	osm_db_domain_t * * DESCRIPTION *	A domain of the database. Can be viewed as a database table. * *	The osm_db_domain_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_db_domain
block|{
name|struct
name|osm_db
modifier|*
name|p_db
decl_stmt|;
name|void
modifier|*
name|p_domain_imp
decl_stmt|;
block|}
name|osm_db_domain_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_db *		Pointer to the parent database object. * *	p_domain_imp *		Pointer to the db implementation object * * SEE ALSO * osm_db_t *********/
end_comment

begin_comment
comment|/****s* OpenSM: Database/osm_db_t * NAME *	osm_db_t * * DESCRIPTION *	The main database object. * *	The osm_db_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_db
block|{
name|void
modifier|*
name|p_db_imp
decl_stmt|;
name|struct
name|osm_log
modifier|*
name|p_log
decl_stmt|;
name|cl_list_t
name|domains
decl_stmt|;
block|}
name|osm_db_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_db_imp *		Pointer to the database implementation object * *	p_log *		Pointer to the OSM logging facility * *  domains *     List of initialize domains * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_construct * NAME *	osm_db_construct * * DESCRIPTION *	Construct a database. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_db_construct
parameter_list|(
name|IN
name|osm_db_t
modifier|*
name|p_db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_db *		[in] Pointer to the database object to construct * * RETURN VALUES *	NONE * * SEE ALSO *	Database, osm_db_init, osm_db_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_destroy * NAME *	osm_db_destroy * * DESCRIPTION *	Destroys the osm_db_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_db_destroy
parameter_list|(
name|IN
name|osm_db_t
modifier|*
name|p_db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_db *		[in] Pointer to osm_db_t structure to destroy * * SEE ALSO *	Database, osm_db_construct, osm_db_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_init * NAME *	osm_db_init * * DESCRIPTION *	Initializes the osm_db_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_init
parameter_list|(
name|IN
name|osm_db_t
modifier|*
name|p_db
parameter_list|,
name|IN
name|struct
name|osm_log
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_db *		[in] Pointer to the database object to initialize * *	p_log *		[in] Pointer to the OSM logging facility * * RETURN VALUES *	0 on success 1 otherwise * * SEE ALSO *	Database, osm_db_construct, osm_db_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_domain_init * NAME *	osm_db_domain_init * * DESCRIPTION *	Initializes the osm_db_domain_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_db_domain_t
modifier|*
name|osm_db_domain_init
parameter_list|(
name|IN
name|osm_db_t
modifier|*
name|p_db
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
name|domain_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_db *		[in] Pointer to the database object to initialize * *	domain_name *		[in] a char array with the domain name. * * RETURN VALUES *	pointer to the new domain object or NULL if failed. * * SEE ALSO *	Database, osm_db_construct, osm_db_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_restore * NAME *	osm_db_restore * * DESCRIPTION *	Reads the entire domain from persistent storage - overrides all *  existing cached data (if any). * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_restore
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_domain *		[in] Pointer to the database domain object to restore *		     from persistent db * * RETURN VALUES *	0 if successful 1 otherwize * * SEE ALSO *	Database, osm_db_domain_init, osm_db_clear, osm_db_store, *  osm_db_keys, osm_db_lookup, osm_db_update, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_clear * NAME *	osm_db_clear * * DESCRIPTION *	Clears the entire domain values from/in the cache * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_clear
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_domain *		[in] Pointer to the database domain object to clear * * RETURN VALUES *	0 if successful 1 otherwize * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_store, *  osm_db_keys, osm_db_lookup, osm_db_update, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_store * NAME *	osm_db_store * * DESCRIPTION *	Store the domain cache back to the database (commit) * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_store
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|,
name|IN
name|boolean_t
name|fsync_high_avail_files
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_domain *		[in] Pointer to the database domain object to restore from *		     persistent db * *	fsync_high_avail_files *		[in] Boolean that indicates whether or not to synchronize *		     in-memory high availability files with storage * * RETURN VALUES *	0 if successful 1 otherwize * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_clear, *  osm_db_keys, osm_db_lookup, osm_db_update, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_keys * NAME *	osm_db_keys * * DESCRIPTION *	Retrive all keys of the domain * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_keys
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|,
name|OUT
name|cl_list_t
modifier|*
name|p_key_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * * p_domain *    [in] Pointer to the database domain object * * p_key_list *    [out] List of key values. It should be PRE constructed and initialized. * * RETURN VALUES *	0 if successful 1 otherwize * * NOTE: the caller needs to free and destruct the list, *       the keys returned are intrnal to the hash and should NOT be free'ed * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_clear, osm_db_store, *  osm_db_lookup, osm_db_update, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_lookup * NAME *	osm_db_lookup * * DESCRIPTION *	Lookup an entry in the domain by the given key * * SYNOPSIS */
end_comment

begin_comment
comment|/* lookup value by key */
end_comment

begin_function_decl
name|char
modifier|*
name|osm_db_lookup
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|,
name|IN
name|char
modifier|*
name|p_key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *  p_domain *    [in] Pointer to the database domain object * *	key *		[in] The key to look for * * RETURN VALUES *  the value as char * or NULL if not found * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_clear, osm_db_store, *  osm_db_keys, osm_db_update, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_update * NAME *	osm_db_update * * DESCRIPTION *	Set the value of the given key * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_update
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|,
name|IN
name|char
modifier|*
name|p_key
parameter_list|,
name|IN
name|char
modifier|*
name|p_val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *  p_domain *    [in] Pointer to the database domain object * *	p_key *		[in] The key to update * *	p_val *		[in] The value to update * * RETURN VALUES *  0 on success * * NOTE: the value will be duplicated so can be free'ed * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_clear, osm_db_store, *  osm_db_keys, osm_db_lookup, osm_db_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Database/osm_db_delete * NAME *	osm_db_delete * * DESCRIPTION *	Delete an entry by the given key * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_delete
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
name|p_domain
parameter_list|,
name|IN
name|char
modifier|*
name|p_key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *  p_domain *    [in] Pointer to the database domain object * *	p_key *		[in] The key to look for * * RETURN VALUES *  0 on success * * SEE ALSO *	Database, osm_db_domain_init, osm_db_restore, osm_db_clear, osm_db_store, *  osm_db_keys, osm_db_lookup, osm_db_update *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_DB_H_ */
end_comment

end_unit

