begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Sun Microsystems, Inc. All rights reserved.  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PKEY_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PKEY_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_map.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_msgdef.h>
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
comment|/*    Forward references. */
end_comment

begin_struct_decl
struct_decl|struct
name|osm_physp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_subn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_physp
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Abstract:  * 	Declaration of pkey manipulation functions.  */
end_comment

begin_comment
comment|/****s* OpenSM: osm_pkey_tbl_t * NAME *	osm_pkey_tbl_t * * DESCRIPTION *	This object represents a pkey table. The need for a special object *  is required to optimize search performance of a PKey in the IB standard *  non sorted table. * *	The osm_pkey_tbl_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_pkeybl
block|{
name|cl_map_t
name|accum_pkeys
decl_stmt|;
name|cl_ptr_vector_t
name|blocks
decl_stmt|;
name|cl_ptr_vector_t
name|new_blocks
decl_stmt|;
name|cl_map_t
name|keys
decl_stmt|;
name|cl_qlist_t
name|pending
decl_stmt|;
name|uint16_t
name|last_pkey_idx
decl_stmt|;
name|uint16_t
name|used_blocks
decl_stmt|;
name|uint16_t
name|max_blocks
decl_stmt|;
name|uint16_t
name|rcv_blocks_cnt
decl_stmt|;
name|uint16_t
name|indx0_pkey
decl_stmt|;
block|}
name|osm_pkey_tbl_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	accum_pkeys *		Accumulated pkeys with pkey index. Used to *		preserve pkey index. * *	blocks *		The IBA defined blocks of pkey values, updated from the subnet * *	new_blocks *		The blocks of pkey values, will be used for updates by SM * *	keys *		A set holding all keys * *	pending *		A list of osm_pending_pkey structs that is temporarily set by *		the pkey mgr and used during pkey mgr algorithm only * *	used_blocks *		Tracks the number of blocks having non-zero pkeys * *	max_blocks *		The maximal number of blocks this partition table might hold *		this value is based on node_info (for port 0 or CA) or *		switch_info updated on receiving the node_info or switch_info *		GetResp * *	rcv_blocks_cnt *		Counter for the received GetPKeyTable mads. *		For every GetPKeyTable mad we send, increase the counter, *		and for every GetRespPKeyTable we decrease the counter. * *	indx0_pkey *		stores the pkey to be inserted at block 0 index 0. *		if this field is 0, the default pkey will be inserted. * * NOTES * 'blocks' vector should be used to store pkey values obtained from * the port and SM pkey manager should not change it directly, for this * purpose 'new_blocks' should be used. * * The only pkey values stored in 'blocks' vector will be mapped with * 'keys' map * *********/
end_comment

begin_comment
comment|/****s* OpenSM: osm_pending_pkey_t * NAME *	osm_pending_pkey_t * * DESCRIPTION *	This objects stores temporary information on pkeys, their target block, *  and index during the pkey manager operation * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_pending_pkey
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|uint16_t
name|pkey
decl_stmt|;
name|uint16_t
name|block
decl_stmt|;
name|uint8_t
name|index
decl_stmt|;
name|boolean_t
name|is_new
decl_stmt|;
block|}
name|osm_pending_pkey_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	pkey *		The actual P_Key * *	block *		The block index based on the previous table extracted from the *		device * *	index *		The index of the pkey within the block * *	is_new *		TRUE for new P_Keys such that the block and index are invalid *		in that case * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_construct * NAME *  osm_pkey_tbl_construct * * DESCRIPTION *  Constructs the PKey table object * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_pkey_tbl_construct
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_init * NAME *  osm_pkey_tbl_init * * DESCRIPTION *  Inits the PKey table object * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_pkey_tbl_init
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_destroy * NAME *  osm_pkey_tbl_destroy * * DESCRIPTION *  Destroys the PKey table object * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_pkey_tbl_destroy
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_get_num_blocks * NAME *  osm_pkey_tbl_get_num_blocks * * DESCRIPTION *  Obtain the number of blocks in IB PKey table * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint16_t
name|osm_pkey_tbl_get_num_blocks
parameter_list|(
name|IN
specifier|const
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint16_t
call|)
argument_list|(
name|cl_ptr_vector_get_size
argument_list|(
operator|&
name|p_pkey_tbl
operator|->
name|blocks
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * * RETURN VALUES *  The IB pkey table of that pkey table element * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_block_get * NAME *  osm_pkey_tbl_block_get * * DESCRIPTION *  Obtain the pointer to the IB PKey table block stored in the object * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_pkey_table_t
modifier|*
name|osm_pkey_tbl_block_get
parameter_list|(
specifier|const
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|uint16_t
name|block
parameter_list|)
block|{
return|return
operator|(
operator|(
name|block
operator|<
name|cl_ptr_vector_get_size
argument_list|(
operator|&
name|p_pkey_tbl
operator|->
name|blocks
argument_list|)
operator|)
condition|?
operator|(
name|ib_pkey_table_t
operator|*
operator|)
name|cl_ptr_vector_get
argument_list|(
operator|&
name|p_pkey_tbl
operator|->
name|blocks
argument_list|,
name|block
argument_list|)
else|:
name|NULL
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * *  block *     [in] The block number to get * * RETURN VALUES *  The IB pkey table of that pkey table element * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_new_block_get * NAME *  osm_pkey_tbl_new_block_get * * DESCRIPTION *  The same as above but for new block * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_pkey_table_t
modifier|*
name|osm_pkey_tbl_new_block_get
parameter_list|(
specifier|const
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|uint16_t
name|block
parameter_list|)
block|{
return|return
operator|(
operator|(
name|block
operator|<
name|cl_ptr_vector_get_size
argument_list|(
operator|&
name|p_pkey_tbl
operator|->
name|new_blocks
argument_list|)
operator|)
condition|?
operator|(
name|ib_pkey_table_t
operator|*
operator|)
name|cl_ptr_vector_get
argument_list|(
operator|&
name|p_pkey_tbl
operator|->
name|new_blocks
argument_list|,
name|block
argument_list|)
else|:
name|NULL
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/****f* OpenSM: osm_pkey_find_last_accum_pkey_index  * NAME  *   osm_pkey_find_last_accum_pkey_index  *  * DESCRIPTION  *   Finds the next last accumulated pkey  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osm_pkey_find_last_accum_pkey_index
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_set_accum_pkeys * NAME *  osm_pkey_tbl_set_accum_pkeys * * DESCRIPTION *   Stores the given pkey and pkey index in the "accum_pkeys" array * * SYNOPSIS */
end_comment

begin_function_decl
name|cl_status_t
name|osm_pkey_tbl_set_accum_pkeys
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|IN
name|uint16_t
name|pkey
parameter_list|,
name|IN
name|uint16_t
name|pkey_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * p_pkey_tbl *   [in] Pointer to the PKey table * * pkey *   [in] PKey to store * * pkey_idx *   [in] The overall index * * RETURN VALUES *   CL_SUCCESS if OK *   CL_INSUFFICIENT_MEMORY if failed * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_set_new_entry * NAME *  osm_pkey_tbl_set_new_entry * * DESCRIPTION *   Stores the given pkey in the "new" blocks array and update *   the "map" to show that on the "old" blocks * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_pkey_tbl_set_new_entry
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|IN
name|uint16_t
name|block_idx
parameter_list|,
name|IN
name|uint8_t
name|pkey_idx
parameter_list|,
name|IN
name|uint16_t
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * p_pkey_tbl *   [in] Pointer to the PKey table * * block_idx *   [in] The block index to use * * pkey_idx *   [in] The index within the block * * pkey *   [in] PKey to store * * RETURN VALUES *   IB_SUCCESS if OK *   IB_ERROR if failed * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_find_next_free_entry * NAME *  osm_pkey_find_next_free_entry * * DESCRIPTION *  Find the next free entry in the PKey table starting at the given *  index and block number. The user should increment pkey_idx before *  next call *  Inspect the "new" blocks array for empty space. * * SYNOPSIS */
end_comment

begin_function_decl
name|boolean_t
name|osm_pkey_find_next_free_entry
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|p_block_idx
parameter_list|,
name|OUT
name|uint8_t
modifier|*
name|p_pkey_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * p_pkey_tbl *   [in] Pointer to the PKey table * * p_block_idx *   [out] The block index to use * * p_pkey_idx *   [out] The index within the block to use * * RETURN VALUES *   TRUE if found *   FALSE if did not find * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_init_new_blocks * NAME *  osm_pkey_tbl_init_new_blocks * * DESCRIPTION *  Initializes new_blocks vector content (allocate and clear) * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_pkey_tbl_init_new_blocks
parameter_list|(
specifier|const
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_get_block_and_idx * NAME *  osm_pkey_tbl_get_block_and_idx * * DESCRIPTION *  Set the block index and pkey index the given *  pkey is found in. Return IB_NOT_FOUND if could *  not find it, IB_SUCCESS if OK * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_pkey_tbl_get_block_and_idx
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|IN
name|uint16_t
modifier|*
name|p_pkey
parameter_list|,
name|OUT
name|uint16_t
modifier|*
name|block_idx
parameter_list|,
name|OUT
name|uint8_t
modifier|*
name|pkey_index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object. * *  p_pkey *     [in] Pointer to the P_Key entry searched * *  p_block_idx *     [out] Pointer to the block index to be updated * *  p_pkey_idx *     [out] Pointer to the pkey index (in the block) to be updated * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_set * NAME *  osm_pkey_tbl_set * * DESCRIPTION *  Set the PKey table block provided in the PKey object. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_pkey_tbl_set
parameter_list|(
name|IN
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|,
name|IN
name|uint16_t
name|block
parameter_list|,
name|IN
name|ib_pkey_table_t
modifier|*
name|p_tbl
parameter_list|,
name|IN
name|boolean_t
name|allow_both_pkeys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* *  p_pkey_tbl *     [in] Pointer to osm_pkey_tbl_t object * *  block *     [in] The block number to set * *  p_tbl *     [in] The IB PKey block to copy to the object * *  allow_both_pkeys *     [in] Whether both full and limited membership on same partition *          are allowed * * RETURN VALUES *  IB_SUCCESS or IB_ERROR * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_physp_share_this_pkey * NAME *  osm_physp_share_this_pkey * * DESCRIPTION *  Checks if the given physical ports share the specified pkey. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|boolean_t
name|osm_physp_share_this_pkey
argument_list|(
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp1
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp2
argument_list|,
name|IN
name|ib_net16_t
name|pkey
argument_list|,
name|IN
name|boolean_t
name|allow_both_pkeys
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS * *  p_physp1 *     [in] Pointer to an osm_physp_t object. * *  p_physp2 *     [in] Pointer to an osm_physp_t object. * *  pkey *     [in] value of P_Key to check. * *  allow_both_pkeys *     [in] whether both pkeys allowed policy is being used. * * RETURN VALUES *  Returns TRUE if the two ports are matching. *  FALSE otherwise. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_physp_find_common_pkey * NAME *  osm_physp_find_common_pkey * * DESCRIPTION *  Returns first matching P_Key values for specified physical ports. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|ib_net16_t
name|osm_physp_find_common_pkey
argument_list|(
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp1
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp2
argument_list|,
name|IN
name|boolean_t
name|allow_both_pkeys
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS * *  p_physp1 *     [in] Pointer to an osm_physp_t object. * *  p_physp2 *     [in] Pointer to an osm_physp_t object. * *  allow_both_pkeys *     [in] Whether both full and limited membership on same partition *          are allowed * * RETURN VALUES *  Returns value of first shared P_Key or INVALID P_Key (0x0) if not *  found. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_physp_share_pkey * NAME *  osm_physp_share_pkey * * DESCRIPTION *  Checks if the given physical ports share a pkey. *  The meaning P_Key matching: *  10.9.3 : *   In the following, let M_P_Key(Message P_Key) be the P_Key in the incoming *   packet and E_P_Key(Endnode P_Key) be the P_Key it is being compared against *   in the packet's destination endnode. * *    If: *    * neither M_P_Key nor E_P_Key are the invalid P_Key *    * and the low-order 15 bits of the M_P_Key match the low order 15 *      bits of the E_P_Key *    * and the high order bit(membership type) of both the M_P_Key and *      E_P_Key are not both 0 (i.e., both are not Limited members of *      the partition) * *    then the P_Keys are said to match. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|boolean_t
name|osm_physp_share_pkey
argument_list|(
name|IN
name|osm_log_t
operator|*
name|p_log
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp_1
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp_2
argument_list|,
name|IN
name|boolean_t
name|allow_both_pkeys
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *  p_log *     [in] Pointer to a log object. * *  p_physp_1 *     [in] Pointer to an osm_physp_t object. * *  p_physp_2 *     [in] Pointer to an osm_physp_t object. * *  allow_both_pkeys *     [in] Whether both full and limited membership on same partition *          are allowed * * RETURN VALUES *  Returns TRUE if the 2 physical ports are matching. *  FALSE otherwise. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_port_share_pkey * NAME *  osm_port_share_pkey * * DESCRIPTION *  Checks if the given ports (on their default physical port) share a pkey. *  The meaning P_Key matching: *  10.9.3 : *   In the following, let M_P_Key(Message P_Key) be the P_Key in the incoming *   packet and E_P_Key(Endnode P_Key) be the P_Key it is being compared against *   in the packet's destination endnode. * *    If: *    * neither M_P_Key nor E_P_Key are the invalid P_Key *    * and the low-order 15 bits of the M_P_Key match the low order 15 *      bits of the E_P_Key *    * and the high order bit(membership type) of both the M_P_Key and *      E_P_Key are not both 0 (i.e., both are not Limited members of *      the partition) * *    then the P_Keys are said to match. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|boolean_t
name|osm_port_share_pkey
argument_list|(
name|IN
name|osm_log_t
operator|*
name|p_log
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_port
operator|*
name|p_port_1
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_port
operator|*
name|p_port_2
argument_list|,
name|IN
name|boolean_t
name|allow_both_pkeys
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *  p_log *     [in] Pointer to a log object. * *  p_port_1 *     [in] Pointer to an osm_port_t object. * *  p_port_2 *     [in] Pointer to an osm_port_t object. * * RETURN VALUES *  Returns TRUE if the 2 ports are matching. *  FALSE otherwise. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_physp_has_pkey * NAME *  osm_physp_has_pkey * * DESCRIPTION *	Given a physp and a pkey, check if pkey exists in physp pkey table * * SYNOPSIS */
end_comment

begin_decl_stmt
name|boolean_t
name|osm_physp_has_pkey
argument_list|(
name|IN
name|osm_log_t
operator|*
name|p_log
argument_list|,
name|IN
name|ib_net16_t
name|pkey
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_physp
operator|*
name|p_physp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *  p_log *     [in] Pointer to a log object. * *  pkey *     [in] pkey number to look for. * *  p_physp *     [in] Pointer to osm_physp_t object. * * RETURN VALUES *  Returns TRUE if the p_physp has the pkey given. False otherwise. * * NOTES * *********/
end_comment

begin_comment
comment|/****f* OpenSM: osm_pkey_tbl_set_indx0_pkey * NAME *  osm_pkey_tbl_set_indx0_pkey * * DESCRIPTION *  Sets given pkey at index0 in given pkey_tbl. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_pkey_tbl_set_indx0_pkey
parameter_list|(
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|ib_net16_t
name|pkey
parameter_list|,
name|IN
name|boolean_t
name|full
parameter_list|,
name|OUT
name|osm_pkey_tbl_t
modifier|*
name|p_pkey_tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_log *     [in] Pointer to a log object. * *  pkey *     [in] P_Key. * *  full *     [in] Indication if this is a full/limited membership pkey. * *  p_pkey_tbl *     [out] Pointer to osm_pkey_tbl_t object in which to set indx0 pkey. * * RETURN VALUES *  None * * NOTES * *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PKEY_H_ */
end_comment

end_unit

