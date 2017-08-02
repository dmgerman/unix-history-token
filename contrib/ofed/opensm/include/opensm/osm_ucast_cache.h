begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2008 Mellanox Technologies LTD. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Header file that describes Unicast Cache functions.  *  * Environment:  * 	Linux User Mode  *  * $Revision: 1.4 $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_UCAST_CACHE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_UCAST_CACHE_H_
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
file|<opensm/osm_switch.h>
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

begin_struct_decl
struct_decl|struct
name|osm_ucast_mgr
struct_decl|;
end_struct_decl

begin_comment
comment|/****h* OpenSM/Unicast Manager/Unicast Cache * NAME *	Unicast Cache * * DESCRIPTION *	The Unicast Cache object encapsulates the information *	needed to cache and write unicast routing of the subnet. * *	The Unicast Cache object is NOT thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Yevgeny Kliteynik, Mellanox * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Cache/osm_ucast_cache_invalidate * NAME *	osm_ucast_cache_invalidate * * DESCRIPTION *	The osm_ucast_cache_invalidate function purges the *	unicast cache and marks the cache as invalid. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_cache_invalidate
parameter_list|(
name|struct
name|osm_ucast_mgr
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the ucast mgr object. * * RETURN VALUE *	This function does not return any value. * * NOTES * * SEE ALSO *	Unicast Manager object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Cache/osm_ucast_cache_check_new_link * NAME *	osm_ucast_cache_check_new_link * * DESCRIPTION *	The osm_ucast_cache_check_new_link checks whether *	the newly discovered link still allows us to use *	cached unicast routing. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_cache_check_new_link
parameter_list|(
name|struct
name|osm_ucast_mgr
modifier|*
name|p_mgr
parameter_list|,
name|osm_node_t
modifier|*
name|p_node_1
parameter_list|,
name|uint8_t
name|port_num_1
parameter_list|,
name|osm_node_t
modifier|*
name|p_node_2
parameter_list|,
name|uint8_t
name|port_num_2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the unicast manager object. * *	physp1 *		[in] Pointer to the first physical port of the link. * *	physp2 *		[in] Pointer to the second physical port of the link. * * RETURN VALUE *	This function does not return any value. * * NOTES *	The function checks whether the link was previously *	cached/dropped or is this a completely new link. *	If it decides that the new link makes cached routing *	invalid, the cache is purged and marked as invalid. * * SEE ALSO *	Unicast Cache object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Cache/osm_ucast_cache_add_link * NAME *	osm_ucast_cache_add_link * * DESCRIPTION *	The osm_ucast_cache_add_link adds link to the cache. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_cache_add_link
parameter_list|(
name|struct
name|osm_ucast_mgr
modifier|*
name|p_mgr
parameter_list|,
name|osm_physp_t
modifier|*
name|physp1
parameter_list|,
name|osm_physp_t
modifier|*
name|physp2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the unicast manager object. * *	physp1 *		[in] Pointer to the first physical port of the link. * *	physp2 *		[in] Pointer to the second physical port of the link. * * RETURN VALUE *	This function does not return any value. * * NOTES *	Since the cache operates with ports and not links, *	the function adds two port entries (both sides of the *	link) to the cache. *	If it decides that the dropped link makes cached routing *	invalid, the cache is purged and marked as invalid. * * SEE ALSO *	Unicast Manager object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Cache/osm_ucast_cache_add_node * NAME *	osm_ucast_cache_add_node * * DESCRIPTION *	The osm_ucast_cache_add_node adds node and all *	its links to the cache. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_ucast_cache_add_node
parameter_list|(
name|struct
name|osm_ucast_mgr
modifier|*
name|p_mgr
parameter_list|,
name|osm_node_t
modifier|*
name|p_node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the unicast manager object. * *	p_node *		[in] Pointer to the node object that should be cached. * * RETURN VALUE *	This function does not return any value. * * NOTES *	If the function decides that the dropped node makes cached *	routing invalid, the cache is purged and marked as invalid. * * SEE ALSO *	Unicast Manager object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Unicast Cache/osm_ucast_cache_process * NAME *	osm_ucast_cache_process * * DESCRIPTION *	The osm_ucast_cache_process function writes the *	cached unicast routing on the subnet switches. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_ucast_cache_process
parameter_list|(
name|struct
name|osm_ucast_mgr
modifier|*
name|p_mgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_mgr *		[in] Pointer to the unicast manager object. * * RETURN VALUE *	This function returns zero on sucess and non-zero *	value otherwise. * * NOTES *	Iterates through all the subnet switches and writes *	the LFTs that were calculated during the last routing *       engine execution to the switches. * * SEE ALSO *	Unicast Manager object *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_UCAST_CACHE_H_ */
end_comment

end_unit

