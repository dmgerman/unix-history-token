begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mcast_tbl_t.  *	This object represents a multicast forwarding table.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MCAST_TBL_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MCAST_TBL_H_
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
file|<opensm/osm_base.h>
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
comment|/****s* OpenSM: Forwarding Table/osm_mcast_tbl_t * NAME *	osm_mcast_tbl_t * * DESCRIPTION *	Multicast Forwarding Table structure. * *	Callers may directly access this object. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mcast_fwdbl
block|{
name|uint8_t
name|num_ports
decl_stmt|;
name|uint8_t
name|max_position
decl_stmt|;
name|uint16_t
name|max_block
decl_stmt|;
name|int16_t
name|max_block_in_use
decl_stmt|;
name|uint16_t
name|num_entries
decl_stmt|;
name|uint16_t
name|max_mlid_ho
decl_stmt|;
name|uint16_t
name|mft_depth
decl_stmt|;
name|uint16_t
argument_list|(
operator|*
name|p_mask_tbl
argument_list|)
index|[]
index|[
name|IB_MCAST_POSITION_MAX
operator|+
literal|1
index|]
expr_stmt|;
block|}
name|osm_mcast_tbl_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	num_ports *		The number of ports in the port mask.  This value *		is the same as the number of ports on the switch * *	max_position *		Maximum bit mask position for this table.  This value *		is computed from the number of ports on the switch. * *	max_block *		Maximum block number supported in the table.  This value *		is approximately the number of MLID entries divided by the *		number of MLIDs per block * *	num_entries *		Number of entries in the table (aka number of MLIDs supported). * *	max_mlid_ho *		Maximum MLID (host order) for the currently allocated multicast *		port mask table. * *	mft_depth *		Number of MLIDs in the currently allocated multicast port mask *		table. * *	p_mask_tbl *		Pointer to a two dimensional array of port_masks for this switch. *		The first dimension is MLID offset, second dimension is mask position. *		This pointer is null for switches that do not support multicast. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_init * NAME *	osm_mcast_tbl_init * * DESCRIPTION *	This function initializes a Multicast Forwarding Table object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcast_tbl_init
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|uint8_t
name|num_ports
parameter_list|,
name|IN
name|uint16_t
name|capacity
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	num_ports *		[in] Number of ports in the switch owning this table. * *	capacity *		[in] The number of MLID entries (starting at 0xC000) supported *		by this switch. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_delete * NAME *	osm_mcast_tbl_delete * * DESCRIPTION *	This destroys and deallocates a Multicast Forwarding Table object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcast_tbl_delete
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
modifier|*
name|pp_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	pp_tbl *		[in] Pointer a Pointer to the Multicast Forwarding Table object. * * RETURN VALUE *	On success, returns a pointer to a new Multicast Forwarding Table object *	of the specified size. *	NULL otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_realloc * NAME *	osm_mcast_tbl_realloc * * DESCRIPTION *	This function reallocates the multicast port mask table if necessary. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_mcast_tbl_realloc
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|unsigned
name|mlid_offset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	mlid_offset *		[in] Offset of MLID being accessed. * * RETURN VALUE *	Returns 0 on success and non-zero value otherwise. * * NOTES * * SEE ALSO */
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_destroy * NAME *	osm_mcast_tbl_destroy * * DESCRIPTION *	This destroys and deallocates a Multicast Forwarding Table object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcast_tbl_destroy
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * * RETURN VALUE *    None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_set * NAME *	osm_mcast_tbl_set * * DESCRIPTION *	Adds the port to the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcast_tbl_set
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	mlid_ho *		[in] MLID value (host order) for which to set the route. * *	port_num *		[in] Port to add to the multicast group. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_clear_mlid * NAME *	osm_mcast_tbl_clear_mlid * * DESCRIPTION *	Removes all multicast paths for the specified MLID. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mcast_tbl_clear_mlid
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	mlid_ho *		[in] MLID value (host order) for which to clear. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_is_port * NAME *	osm_mcast_tbl_is_port * * DESCRIPTION *	Returns TRUE if the port is in the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_mcast_tbl_is_port
parameter_list|(
name|IN
specifier|const
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	mlid_ho *		[in] MLID value (host order). * *	port_num *		[in] Port number on the switch * * RETURN VALUE *	Returns the port that routes the specified LID. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_is_any_port * NAME *	osm_mcast_tbl_is_any_port * * DESCRIPTION *	Returns TRUE if any port is in the multicast group. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_mcast_tbl_is_any_port
parameter_list|(
name|IN
specifier|const
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|uint16_t
name|mlid_ho
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	mlid_ho *		[in] MLID value (host order). * * RETURN VALUE *	Returns TRUE if any port is in the multicast group. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_set_block * NAME *	osm_mcast_tbl_set_block * * DESCRIPTION *	Copies the specified block into the Multicast Forwarding Table. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_mcast_tbl_set_block
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
modifier|*
name|p_block
parameter_list|,
name|IN
name|int16_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|position
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to the Multicast Forwarding Table object. * *	p_block *		[in] Pointer to the Forwarding Table block. * *	block_num *		[in] Block number of this block. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_get_tbl_block * NAME *	osm_mcast_get_tbl_block * * DESCRIPTION *	Retrieve a multicast forwarding table block. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_mcast_tbl_get_block
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|int16_t
name|block_num
parameter_list|,
name|IN
name|uint8_t
name|position
parameter_list|,
name|OUT
name|ib_net16_t
modifier|*
name|p_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to an osm_mcast_tbl_t object. * *	p_block *		[in] Pointer to the Forwarding Table block. * *	block_num *		[in] Block number of this block. * *	p_block *		[out] Pointer to the 32 entry array to store the *		forwarding table clock specified by block_id. * * RETURN VALUES *	Returns true if there are more blocks necessary to *	configure all the MLIDs reachable from this switch. *	FALSE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_get_max_block * NAME *	osm_mcast_tbl_get_max_block * * DESCRIPTION *	Returns the maximum block ID in this table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|osm_mcast_tbl_get_max_block
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|)
block|{
return|return
name|p_tbl
operator|->
name|max_block
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to an osm_mcast_tbl_t object. * * RETURN VALUES *	Returns the maximum block ID in this table. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_get_max_block_in_use * NAME *	osm_mcast_tbl_get_max_block_in_use * * DESCRIPTION *	Returns the maximum block ID in use in this table. *	A value of -1 indicates no blocks are in use. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|int16_t
name|osm_mcast_tbl_get_max_block_in_use
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|)
block|{
return|return
operator|(
name|p_tbl
operator|->
name|max_block_in_use
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to an osm_mcast_tbl_t object. * * RETURN VALUES *	Returns the maximum block ID in use in this table. *	A value of -1 indicates no blocks are in use. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Forwarding Table/osm_mcast_tbl_get_max_position * NAME *	osm_mcast_tbl_get_max_position * * DESCRIPTION *	Returns the maximum position in this table. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_mcast_tbl_get_max_position
parameter_list|(
name|IN
name|osm_mcast_tbl_t
modifier|*
name|p_tbl
parameter_list|)
block|{
return|return
operator|(
name|p_tbl
operator|->
name|max_position
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_tbl *		[in] Pointer to an osm_mcast_tbl_t object. * * RETURN VALUES *	Returns the maximum position in this table. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MCAST_TBL_H_ */
end_comment

end_unit

