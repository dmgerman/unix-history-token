begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/****h* OpenSM/DB-Pack * NAME *	Database Types * * DESCRIPTION *	This module provides packing and unpacking of the database *  storage into specific types. * *  The following domains/conversions are supported: *  guid2lid - key is a guid and data is a lid. * * AUTHOR *	Eitan Zahavi, Mellanox Technologies LTD * *********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_DB_PACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_DB_PACK_H_
end_define

begin_include
include|#
directive|include
file|<opensm/osm_db.h>
end_include

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

begin_function
name|BEGIN_C_DECLS
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_init * NAME *	osm_db_guid2lid_init * * DESCRIPTION *	Initialize a domain for the guid2lid table * * SYNOPSIS */
specifier|static
specifier|inline
name|osm_db_domain_t
modifier|*
name|osm_db_guid2lid_init
parameter_list|(
name|IN
name|osm_db_t
modifier|*
specifier|const
name|p_db
parameter_list|)
block|{
return|return
operator|(
name|osm_db_domain_init
argument_list|(
name|p_db
argument_list|,
literal|"guid2lid"
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_db *		[in] Pointer to the database object to construct * * RETURN VALUES *	The pointer to the new allocated domain object or NULL. * * NOTE: DB domains are destroyed by the osm_db_destroy * * SEE ALSO *	Database, osm_db_init, osm_db_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_init * NAME *	osm_db_guid2lid_init * * DESCRIPTION *	Initialize a domain for the guid2lid table * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_db_guid_elem
block|{
name|cl_list_item_t
name|item
decl_stmt|;
name|uint64_t
name|guid
decl_stmt|;
block|}
name|osm_db_guid_elem_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	item *		required for list manipulations * *  guid * ************/
end_comment

begin_comment
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_guids * NAME *	osm_db_guid2lid_guids * * DESCRIPTION *	Provides back a list of guid elements. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_guid2lid_guids
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
specifier|const
name|p_g2l
parameter_list|,
name|OUT
name|cl_qlist_t
modifier|*
name|p_guid_list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_g2l *		[in] Pointer to the guid2lid domain * *  p_guid_list *     [out] A quick list of guid elements of type osm_db_guid_elem_t * * RETURN VALUES *	0 if successful * * NOTE: the output qlist should be initialized and each item freed *       by the caller, then destroyed. * * SEE ALSO * osm_db_guid2lid_init, osm_db_guid2lid_guids, osm_db_guid2lid_get * osm_db_guid2lid_set, osm_db_guid2lid_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_get * NAME *	osm_db_guid2lid_get * * DESCRIPTION *	Get a lid range by given guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_guid2lid_get
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
specifier|const
name|p_g2l
parameter_list|,
name|IN
name|uint64_t
name|guid
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|p_min_lid
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|p_max_lid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_g2l *		[in] Pointer to the guid2lid domain * *  guid *     [in] The guid to look for * *  p_min_lid *     [out] Pointer to the resulting min lid in host order. * *  p_max_lid *     [out] Pointer to the resulting max lid in host order. * * RETURN VALUES *	0 if successful. The lid will be set to 0 if not found. * * SEE ALSO * osm_db_guid2lid_init, osm_db_guid2lid_guids * osm_db_guid2lid_set, osm_db_guid2lid_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_set * NAME *	osm_db_guid2lid_set * * DESCRIPTION *	Set a lid range for the given guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_guid2lid_set
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
specifier|const
name|p_g2l
parameter_list|,
name|IN
name|uint64_t
name|guid
parameter_list|,
name|IN
name|uint16_t
name|min_lid
parameter_list|,
name|IN
name|uint16_t
name|max_lid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_g2l *		[in] Pointer to the guid2lid domain * *  guid *     [in] The guid to look for * *  min_lid *     [in] The min lid value to set * *  max_lid *     [in] The max lid value to set * * RETURN VALUES *	0 if successful * * SEE ALSO * osm_db_guid2lid_init, osm_db_guid2lid_guids * osm_db_guid2lid_get, osm_db_guid2lid_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: DB-Pack/osm_db_guid2lid_delete * NAME *	osm_db_guid2lid_delete * * DESCRIPTION *	Delete the entry by the given guid * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_db_guid2lid_delete
parameter_list|(
name|IN
name|osm_db_domain_t
modifier|*
specifier|const
name|p_g2l
parameter_list|,
name|IN
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_g2l *		[in] Pointer to the guid2lid domain * *  guid *     [in] The guid to look for * * RETURN VALUES *	0 if successful otherwise 1 * * SEE ALSO * osm_db_guid2lid_init, osm_db_guid2lid_guids * osm_db_guid2lid_get, osm_db_guid2lid_set *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_DB_PACK_H_ */
end_comment

end_unit

