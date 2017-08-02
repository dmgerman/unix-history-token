begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2008 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_prtn_t.  *	This object represents an IBA Partition.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PARTITION_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PARTITION_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_map.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_multicast.h>
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

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* OpenSM/Partition * NAME *	Partition * * DESCRIPTION *	The Partition object encapsulates the information needed by the *	OpenSM to manage Partitions.  The OpenSM allocates one Partition *	object per Partition in the IBA subnet. * *	The Partition is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Partition/osm_prtn_t * NAME *	osm_prtn_t * * DESCRIPTION *	Partition structure. * *	The osm_prtn_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_prtn
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_net16_t
name|pkey
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|cl_map_t
name|full_guid_tbl
decl_stmt|;
name|cl_map_t
name|part_guid_tbl
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|osm_mgrp_t
modifier|*
modifier|*
name|mgrps
decl_stmt|;
name|int
name|nmgrps
decl_stmt|;
block|}
name|osm_prtn_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	pkey *		The IBA defined P_KEY of this Partition. * *	sl *		The Service Level (SL) associated with this Partiton. * *	full_guid_tbl *		Container of pointers to all Port objects in the Partition *		with full membership, indexed by port GUID. * *	part_guid_tbl *		Container of pointers to all Port objects in the Partition *		with limited membership, indexed by port GUID. * *	name *		Name of the Partition as specified in partition *		configuration. * *	mgrps *		List of well known Multicast Groups *		that were created for this partition (when configured). *		This includes the IPoIB broadcast group. * *	nmgrps *		Number of known Multicast Groups. * * SEE ALSO *	Partition *********/
end_comment

begin_comment
comment|/****f* OpenSM: Partition/osm_prtn_delete * NAME *	osm_prtn_delete * * DESCRIPTION *	This function destroys and deallocates a Partition object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_prtn_delete
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|OUT
name|osm_prtn_t
modifier|*
modifier|*
name|pp_prtn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	pp_prtn *		[in][out] Pointer to a pointer to a Partition object to *		delete. On return, this pointer is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified Partition object. * * SEE ALSO *	Partition, osm_prtn_new *********/
end_comment

begin_comment
comment|/****f* OpenSM: Partition/osm_prtn_new * NAME *	osm_prtn_new * * DESCRIPTION *	This function allocates and initializes a Partition object. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_prtn_t
modifier|*
name|osm_prtn_new
parameter_list|(
name|IN
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|IN
name|uint16_t
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	name *		[in] Partition name string * *	pkey *		[in] Partition P_Key value * * RETURN VALUE *	Pointer to the initialize Partition object. * * NOTES *	Allows calling other partition methods. * * SEE ALSO *	Partition *********/
end_comment

begin_comment
comment|/****f* OpenSM: Partition/osm_prtn_is_guid * NAME *	osm_prtn_is_guid * * DESCRIPTION *	Indicates if a port is a member of the partition. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_prtn_is_guid
parameter_list|(
name|IN
specifier|const
name|osm_prtn_t
modifier|*
name|p_prtn
parameter_list|,
name|IN
name|ib_net64_t
name|guid
parameter_list|)
block|{
return|return
operator|(
name|cl_map_get
argument_list|(
operator|&
name|p_prtn
operator|->
name|full_guid_tbl
argument_list|,
name|guid
argument_list|)
operator|!=
name|NULL
operator|)
operator|||
operator|(
name|cl_map_get
argument_list|(
operator|&
name|p_prtn
operator|->
name|part_guid_tbl
argument_list|,
name|guid
argument_list|)
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_prtn *		[in] Pointer to an osm_prtn_t object. * *	guid *		[in] Port GUID. * * RETURN VALUES *	TRUE if the specified port GUID is a member of the partition, *	FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Partition/osm_prtn_make_partitions * NAME *	osm_prtn_make_partitions * * DESCRIPTION * 	Makes all partitions in subnet. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_prtn_make_partitions
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to subnet object. * * RETURN VALUES *	IB_SUCCESS value on success. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Partition/osm_prtn_find_by_name * NAME *	osm_prtn_find_by_name * * DESCRIPTION * 	Fides partition by name. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_prtn_t
modifier|*
name|osm_prtn_find_by_name
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to a subnet object. * *	name *		[in] Required partition name. * * RETURN VALUES *	Pointer to the partition object on success. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PARTITION_H_ */
end_comment

end_unit

