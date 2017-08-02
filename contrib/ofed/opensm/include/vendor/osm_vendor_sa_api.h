begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Specification of the OpenSM SA Client API. This API uses the basic osm  *    vendor API to provide SA Client interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_SA_API_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_SA_API_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
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
comment|/****d* OpenSM Vendor SA Client/osmv_flags_t * NAME *	osmv_flags_t * * DESCRIPTION *	Access layer flags used to direct the operation of various calls. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|osmv_flags_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSM_SA_FLAGS_SYNC
value|0x00000001
end_define

begin_comment
comment|/* * VALUES *	OSM_SA_FLAGS_SYNC *		Indicates that the given operation should be performed synchronously. *		The call will block until it completes.  Callbacks will still be *		invoked. * * SEE ALSO *  osmv_query_sa *****/
end_comment

begin_comment
comment|/****d* OpenSM Vendor SA Client/osmv_query_type_t * NAME *	osmv_query_type_t * * DESCRIPTION *	Abstracted queries supported by the access layer. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osmv_query_type
block|{
name|OSMV_QUERY_USER_DEFINED
block|,
name|OSMV_QUERY_ALL_SVC_RECS
block|,
name|OSMV_QUERY_SVC_REC_BY_NAME
block|,
name|OSMV_QUERY_SVC_REC_BY_ID
block|,
name|OSMV_QUERY_CLASS_PORT_INFO
block|,
name|OSMV_QUERY_NODE_REC_BY_NODE_GUID
block|,
name|OSMV_QUERY_PORT_REC_BY_LID
block|,
name|OSMV_QUERY_PORT_REC_BY_LID_AND_NUM
block|,
name|OSMV_QUERY_VLARB_BY_LID_PORT_BLOCK
block|,
name|OSMV_QUERY_SLVL_BY_LID_AND_PORTS
block|,
name|OSMV_QUERY_PATH_REC_BY_PORT_GUIDS
block|,
name|OSMV_QUERY_PATH_REC_BY_GIDS
block|,
name|OSMV_QUERY_PATH_REC_BY_LIDS
block|,
name|OSMV_QUERY_UD_MULTICAST_SET
block|,
name|OSMV_QUERY_UD_MULTICAST_DELETE
block|,
name|OSMV_QUERY_MULTIPATH_REC
block|,  }
name|osmv_query_type_t
typedef|;
end_typedef

begin_comment
comment|/* * VALUES *	OSMV_QUERY_USER_DEFINED *		Query the SA based on user-defined input.  Queries of this type *		should reference an osmv_user_query_t structure as input to the *		query. * *	OSMV_QUERY_SVC_REC_BY_NAME *		Query for service records based on the service name.  Queries of *		this type should reference an ib_svc_name_t structure as input *		to the query. * *	OSMV_QUERY_SVC_REC_BY_ID *		Query for service records based on the service ID.  Queries of *		this type should reference an ib_net64_t value that indicates *		the ID of the service being requested. * *	OSMV_QUERY_NODE_REC_BY_NODE_GUID *		Query for node information based on the node's GUID.  Queries of *		this type should reference an ib_net64_t value that indicates *		the GUID of the node being requested. * *	OSMV_QUERY_PORT_REC_BY_LID *		Query for port information based on the port's base LID. Queries *		of this type should reference an ib_net16_t value that indicates *		the base LID of the port being requested. * *	OSMV_QUERY_PORT_REC_BY_LID_AND_NUM *		Query for port information based on the port's LID and port num. *		Queries of this type should reference an osmv_user_query_t *		structure as input to the query. The port num and lid should *		be provided by it. * *	OSMV_QUERY_PATH_REC_BY_PORT_GUIDS *		Query for path records between the specified pair of port GUIDs. *		Queries of this type should reference an osmv_guid_pair_t *		structure that indicates the GUIDs of the path being requested. * *	OSMV_QUERY_PATH_REC_BY_GIDS *		Query for path records between the specified pair of port GIDs. *		Queries of this type should reference an osmv_gid_pair_t *		structure that indicates the GIDs of the path being requested. * *	OSMV_QUERY_PATH_REC_BY_LIDS *		Query for path records between the specified pair of port LIDs. *		Queries of this type should reference an osmv_lid_pair_t *		structure that indicates the LIDs of the path being requested. * * NOTES *	This enum is used to define abstracted queries provided by the access *	layer.  Users may issue queries not listed here by sending MADs directly *	to subnet administration or a class manager.  These queries are *	intended to represent those most often used by clients. * * SEE ALSO *	osmv_query, osmv_query_req_t, osmv_user_query_t, osmv_gid_pair_t, *	osmv_lid_pair_t osmv_guid_pair_t *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_user_query_t * NAME *	osmv_user_query_t * * DESCRIPTION *	User-defined query information. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_user_query
block|{
name|uint8_t
name|method
decl_stmt|;
name|ib_net16_t
name|attr_id
decl_stmt|;
name|ib_net16_t
name|attr_offset
decl_stmt|;
name|ib_net32_t
name|attr_mod
decl_stmt|;
name|ib_net64_t
name|comp_mask
decl_stmt|;
name|void
modifier|*
name|p_attr
decl_stmt|;
block|}
name|osmv_user_query_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	method *		Method to be used * *	attr_id *		Attribute identifier of query data. * *	attr_offset *		Size of the query attribute, in 8-byte words.  Users can set *		this value by passing in the sizeof( attribute ) into the *		ib_get_attr_offset() routine. * *	attr_mod *		Attribute modifier for query request. * *	comp_mask *		Indicates the attribute components that are specified for the *		query. * *	p_attr *		References the attribute structure used as input into the query. *		This field is ignored if comp_mask is set to 0. * * NOTES *	This structure is used to describe a user-defined query.  The attribute *	ID, attribute offset, component mask, and attribute structure must match *	those defined by the IBA specification.  Users should refer to chapter *	15 of the IBA specification for additional details. * * SEE ALSO *	osmv_query_type_t, ib_get_attr_offset, ib_get_attr_size, osmv_query_sa *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_gid_pair_t * NAME *	osmv_gid_pair_t * * DESCRIPTION *	Source and destination GIDs. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_gid_pair
block|{
name|ib_gid_t
name|src_gid
decl_stmt|;
name|ib_gid_t
name|dest_gid
decl_stmt|;
block|}
name|osmv_gid_pair_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	src_gid *		Source GID of a path. * *	dest_gid *		Destination GID of a path. * * NOTES *	This structure is used to describe the endpoints of a path. * * SEE ALSO *	ib_gid_t *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_lid_pair_t * NAME *	osmv_lid_pair_t * * DESCRIPTION *	Source and destination LIDs. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_lid_pair
block|{
name|ib_net16_t
name|src_lid
decl_stmt|;
name|ib_net16_t
name|dest_lid
decl_stmt|;
block|}
name|osmv_lid_pair_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	src_lid *		Source LID of a path. * *	dest_lid *		Destination LID of a path. * * NOTES *	This structure is used to describe the endpoints of a path. *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_guid_pair_t * NAME *	osmv_guid_pair_t * * DESCRIPTION *	Source and destination GUIDs.  These may be port or channel adapter *	GUIDs, depending on the context in which this structure is used. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_guid_pair
block|{
name|ib_net64_t
name|src_guid
decl_stmt|;
name|ib_net64_t
name|dest_guid
decl_stmt|;
block|}
name|osmv_guid_pair_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	src_guid *		Source GUID of a path. * *	dest_guid *		Destination GUID of a path. * * NOTES *	This structure is used to describe the endpoints of a path.  The given *	GUID pair may belong to either ports or channel adapters. * * SEE ALSO *	ib_guid_t *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_multipath_req_t * NAME *       osmv_multipath_req_t * * DESCRIPTION *       Fields from which to generate a MultiPathRecord request. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_multipath_req_t
block|{
name|ib_net64_t
name|comp_mask
decl_stmt|;
name|uint16_t
name|pkey
decl_stmt|;
name|boolean_t
name|reversible
decl_stmt|;
name|uint8_t
name|num_path
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|uint8_t
name|independence
decl_stmt|;
name|uint8_t
name|sgid_count
decl_stmt|;
name|uint8_t
name|dgid_count
decl_stmt|;
name|ib_gid_t
name|gids
index|[
name|IB_MULTIPATH_MAX_GIDS
index|]
decl_stmt|;
block|}
name|osmv_multipath_req_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * * NOTES *       This structure is used to describe a multipath request. * * SEE ALSO *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_query_res_t * NAME *	osmv_query_res_t * * DESCRIPTION *	Contains the results of a subnet administration query. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_query_res
block|{
specifier|const
name|void
modifier|*
name|query_context
decl_stmt|;
name|ib_api_status_t
name|status
decl_stmt|;
name|osmv_query_type_t
name|query_type
decl_stmt|;
name|uint32_t
name|result_cnt
decl_stmt|;
name|osm_madw_t
modifier|*
name|p_result_madw
decl_stmt|;
block|}
name|osmv_query_res_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	query_context *		User-defined context information associated with the query *		through the osm_vendor_query_sa call. * *	status *		Indicates the success of the query operation. * *	query_type *		Indicates the type of query for which the results are being *		returned.  This matches the query_type specified through the *               osm_vendor_query_sa call. * *	result_cnt *		The number of result structures that were returned by the query. * *	p_result_madw *		For queries returning IB_SUCCESS or IB_REMOTE_ERROR, this *		references the MAD wrapper returned by subnet administration *		containing the list of results or the returned error code. * * NOTES *	A query result structure is returned to a client through their *	osmv_pfn_query_cb_t routine to notify them of the results of a subnet *	administration query.  If the query was successful or received an error *	from subnet administration, p_result_madw will reference a MAD wrapper *	containing the results.  The MAD referenced by p_result_madw is owned by *	the user and remains available even after their callback returns.  Users *	must call osm_mad_pool_put() to return the MAD wrapper back to the *	mad pool when they are done accessing the results. * *	To retrieve individual result structures from the p_result_madw, users *	may call osmv_get_query_result(). * * SEE ALSO *	osmv_query_sa, osmv_pfn_query_cb_t, ib_api_status_t, *	osmv_query_status_t, osmv_query_type_t, *	osmv_get_query_result *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_result * NAME *	osmv_get_query_result * * DESCRIPTION *	Retrieves a result structure from a MADW returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|osmv_get_query_result
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|ib_get_attr_size
argument_list|(
name|p_sa_mad
operator|->
name|attr_offset
argument_list|)
operator|*
operator|(
name|result_index
operator|+
literal|1
operator|)
operator|+
name|IB_SA_MAD_HDR_SIZE
operator|<=
name|p_result_madw
operator|->
name|mad_size
argument_list|)
expr_stmt|;
return|return
operator|(
name|p_sa_mad
operator|->
name|data
operator|+
operator|(
name|ib_get_attr_size
argument_list|(
name|p_sa_mad
operator|->
name|attr_offset
argument_list|)
operator|*
name|result_index
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a result structure from a *	call to osmv_query_sa().  The type of result structure must be known to *	the user either through the user's context or the query_type returned as *	part of the osmv_query_res_t structure. * * SEE ALSO *	osmv_query_res_t, osm_madw_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_path_rec * NAME *	osmv_get_query_path_rec * * DESCRIPTION *	Retrieves a path record result from a MAD returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_path_rec_t
modifier|*
name|osmv_get_query_path_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_PATH_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_path_rec_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a path record result from *	a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_path_rec_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_portinfo_rec * NAME *	osmv_get_query_portinfo_rec * * DESCRIPTION *	Retrieves a port info record result from a MAD returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_portinfo_record_t
modifier|*
name|osmv_get_query_portinfo_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_PORTINFO_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_portinfo_record_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a port info record result *	from a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_portinfo_record_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_node_rec * NAME *	osmv_get_query_node_rec * * DESCRIPTION *	Retrieves a node record result from a MAD returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_node_record_t
modifier|*
name|osmv_get_query_node_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_NODE_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_node_record_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a node record result from *	a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_node_record_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_svc_rec * NAME *	osmv_get_query_svc_rec * * DESCRIPTION *	Retrieves a service record result from a MAD returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_service_record_t
modifier|*
name|osmv_get_query_svc_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_SERVICE_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_service_record_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a service record result from *	a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_service_record_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_mc_rec * NAME *	osmv_get_query_mc_rec * * DESCRIPTION *	Retrieves a multicast record result from a MAD returned by a call to *	osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_member_rec_t
modifier|*
name|osmv_get_query_mc_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_MCMEMBER_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_member_rec_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a service record result from *	a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_member_rec_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_get_query_inform_info_rec * NAME *	osmv_get_query_inform_info_rec * * DESCRIPTION *	Retrieves an InformInfo record result from a MAD returned by *	a call to osmv_query_sa(). * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_inform_info_record_t
modifier|*
name|osmv_get_query_inform_info_rec
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_result_madw
parameter_list|,
name|IN
name|uint32_t
name|result_index
parameter_list|)
block|{
name|ib_sa_mad_t
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
modifier|*
name|p_sa_mad
decl_stmt|;
name|CL_ASSERT
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|p_sa_mad
operator|=
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|osm_madw_get_mad_ptr
argument_list|(
name|p_result_madw
argument_list|)
expr_stmt|;
name|CL_ASSERT
argument_list|(
name|p_sa_mad
operator|&&
name|p_sa_mad
operator|->
name|attr_id
operator|==
name|IB_MAD_ATTR_INFORM_INFO_RECORD
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|ib_inform_info_record_t
operator|*
operator|)
name|osmv_get_query_result
argument_list|(
name|p_result_madw
argument_list|,
name|result_index
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_result_madw *		[in] This is a reference to the MAD returned as a result of the *		query. * *	result_index *		[in] A zero-based index indicating which result to return. * * NOTES *	This call returns a pointer to the start of a service record result from *	a call to osmv_query_sa(). * * SEE ALSO *	osmv_query_res_t, osm_madw_t, osmv_get_query_result, ib_inform_info_record_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_pfn_query_cb_t * NAME *	osmv_pfn_query_cb_t * * DESCRIPTION *	User-defined callback invoked on completion of subnet administration *	query. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osmv_pfn_query_cb_t
function_decl|)
parameter_list|(
name|IN
name|osmv_query_res_t
modifier|*
name|p_query_res
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *	p_query_res *		[in] This is a reference to a structure containing the result of *		the query. * * NOTES *	This routine is invoked to notify a client of the result of a subnet *	administration query.  The p_query_rec parameter references the result *	of the query and, in the case of a successful query, any information *	returned by subnet administration. * *	In the kernel, this callback is usually invoked using a tasklet, *	dependent on the implementation of the underlying verbs provider driver. * * SEE ALSO *	osmv_query_res_t *****/
end_comment

begin_comment
comment|/****s* OpenSM Vendor SA Client/osmv_query_req_t * NAME *	osmv_query_req_t * * DESCRIPTION *	Information used to request an access layer provided query of subnet *	administration. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmv_query_req
block|{
name|osmv_query_type_t
name|query_type
decl_stmt|;
specifier|const
name|void
modifier|*
name|p_query_input
decl_stmt|;
name|ib_net64_t
name|sm_key
decl_stmt|;
name|uint32_t
name|timeout_ms
decl_stmt|;
name|uint32_t
name|retry_cnt
decl_stmt|;
name|osmv_flags_t
name|flags
decl_stmt|;
specifier|const
name|void
modifier|*
name|query_context
decl_stmt|;
name|osmv_pfn_query_cb_t
name|pfn_query_cb
decl_stmt|;
name|int
name|with_grh
decl_stmt|;
name|ib_gid_t
name|gid
decl_stmt|;
block|}
name|osmv_query_req_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	query_type *		Indicates the type of query that the access layer should *		perform. * *	p_query_input *		A pointer to the input for the query.  The data referenced by *		this structure is dependent on the type of query being requested *		and is determined by the specified query_type. * *	sm_key *		The SM_Key to be provided with the SA MAD for authentication. *		Normally 0 is used. * *	timeout_ms *		Specifies the number of milliseconds to wait for a response for *		this query until retrying or timing out the request. * *	retry_cnt *		Specifies the number of times that the query will be retried *		before failing the request. * *	flags *		Used to describe the mode of operation.  Set to IB_FLAGS_SYNC to *		process the called routine synchronously. * *	query_context *		User-defined context information associated with this query. *		The context data is returned to the user as a part of their *		query callback. * *	pfn_query_cb *		A user-defined callback that is invoked upon completion of the *		query. * *	with_grh *		Indicates that SA queries should be sent with GRH. * *	gid *		Used to store the SM/SA GID. * * NOTES *	This structure is used when requesting an osm vendor provided query *	of subnet administration.  Clients specify the type of query through *	the query_type field.  Based on the type of query, the p_query_input *	field is set to reference the appropriate data structure. * *	The information referenced by the p_query_input field is one of the *	following: * *		-- a NULL terminated service name *		-- a service id *		-- a single GUID *		-- a pair of GUIDs specified through an osmv_guid_pair_t structure *		-- a pair of GIDs specified through an osmv_gid_pair_t structure * * SEE ALSO *	osmv_query_type_t, osmv_pfn_query_cb_t, osmv_guid_pair_t, *	osmv_gid_pair_t *****/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_bind_sa * NAME *   osmv_bind_sa * * DESCRIPTION *	Bind to the SA service and return a handle to be used for later *  queries. * * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_bind_handle_t
name|osmv_bind_sa
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|osm_mad_pool_t
modifier|*
specifier|const
name|p_mad_pool
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   p_vend *	[in] an osm_vendor object to work with * *   p_mad_pool *	[in] mad pool to obtain madw from * *   port_guid *	[in] the port guid to attach to. * * RETURN VALUE *	Bind handle to be used for later SA queries or OSM_BIND_INVALID_HANDLE * * NOTES * * SEE ALSO * osmv_query_sa *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor SA Client/osmv_query_sa * NAME *   osmv_query_sa * * DESCRIPTION *   Query the SA given an SA query request (similar to IBAL ib_query). * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmv_query_sa
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
specifier|const
name|osmv_query_req_t
modifier|*
specifier|const
name|p_query_req
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *	[in] bind handle for this port. Should be previously *       obtained by calling osmv_bind_sa * *   p_query_req *	[in] an SA query request structure. * * RETURN VALUE *	IB_SUCCESS if completed successfuly (or in ASYNC mode *	if the request was sent). * * NOTES * * SEE ALSO * osmv_bind_sa *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VENDOR_SA_API_H_ */
end_comment

end_unit

