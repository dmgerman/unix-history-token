begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *    Declaration of osmtest_t.  * This object represents the OSMTest Test object.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMTEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMTEST_H_
end_define

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_sa_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_helper.h>
end_include

begin_include
include|#
directive|include
file|"osmtest_base.h"
end_include

begin_include
include|#
directive|include
file|"osmtest_subnet.h"
end_include

begin_enum
enum|enum
name|OSMT_FLOWS
block|{
name|OSMT_FLOW_ALL
init|=
literal|0
block|,
name|OSMT_FLOW_CREATE_INVENTORY
block|,
name|OSMT_FLOW_VALIDATE_INVENTORY
block|,
name|OSMT_FLOW_SERVICE_REGISTRATION
block|,
name|OSMT_FLOW_EVENT_FORWARDING
block|,
name|OSMT_FLOW_STRESS_SA
block|,
name|OSMT_FLOW_MULTICAST
block|,
name|OSMT_FLOW_QOS
block|,
name|OSMT_FLOW_TRAP
block|, }
enum|;
end_enum

begin_comment
comment|/****s* OpenSM: Subnet/osmtest_opt_t  * NAME  * osmtest_opt_t  *  * DESCRIPTION  * Subnet options structure.  This structure contains the various  * site specific configuration parameters for osmtest.  *  * SYNOPSIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmtest_opt
block|{
name|uint32_t
name|transaction_timeout
decl_stmt|;
name|boolean_t
name|force_log_flush
decl_stmt|;
name|boolean_t
name|create
decl_stmt|;
name|uint32_t
name|retry_count
decl_stmt|;
name|uint32_t
name|stress
decl_stmt|;
name|uint32_t
name|mmode
decl_stmt|;
name|char
name|file_name
index|[
name|OSMTEST_FILE_PATH_MAX
index|]
decl_stmt|;
name|uint8_t
name|flow
decl_stmt|;
name|uint8_t
name|wait_time
decl_stmt|;
name|char
modifier|*
name|log_file
decl_stmt|;
name|boolean_t
name|ignore_path_records
decl_stmt|;
block|}
name|osmtest_opt_t
typedef|;
end_typedef

begin_comment
comment|/*  * FIELDS  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****h* OSMTest/OSMTest  * NAME  * OSMTest  *  * DESCRIPTION  * The OSMTest object tests an SM/SA for conformance to a known  * set of data about an Infiniband subnet.  *  * AUTHOR  * Steve King, Intel  *  *********/
end_comment

begin_comment
comment|/****s* OSMTest/osmtest_t  * NAME  * osmtest_t  *  * DESCRIPTION  * OSMTest structure.  *  * This object should be treated as opaque and should  * be manipulated only through the provided functions.  *  * SYNOPSIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmtest
block|{
name|osm_log_t
name|log
decl_stmt|;
name|struct
name|_osm_vendor
modifier|*
name|p_vendor
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
name|osm_mad_pool_t
name|mad_pool
decl_stmt|;
name|osmtest_opt_t
name|opt
decl_stmt|;
name|ib_port_attr_t
name|local_port
decl_stmt|;
name|subnet_t
name|exp_subn
decl_stmt|;
name|cl_qpool_t
name|node_pool
decl_stmt|;
name|cl_qpool_t
name|port_pool
decl_stmt|;
name|cl_qpool_t
name|link_pool
decl_stmt|;
name|uint16_t
name|max_lid
decl_stmt|;
block|}
name|osmtest_t
typedef|;
end_typedef

begin_comment
comment|/*  * FIELDS  * log  *    Log facility used by all OSMTest components.  *  * p_vendor  *    Pointer to the vendor transport layer.  *  *  h_bind  *     The bind handle obtained by osm_vendor_sa_api/osmv_bind_sa  *  *  mad_pool  *     The mad pool provided for teh vendor layer to allocate mad wrappers in  *  * opt  *    osmtest options structure  *  * local_port  *    Port attributes for the port over which osmtest is running.  *  * exp_subn  *    Subnet object representing the expected subnet  *  * node_pool  *    Pool of objects for use in populating the subnet databases.  *  * port_pool  *    Pool of objects for use in populating the subnet databases.  *  * link_pool  *    Pool of objects for use in populating the subnet databases.  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osmtest_req_context_t  * NAME  * osmtest_req_context_t  *  * DESCRIPTION  * Query context for ib_query callback function.  *  * SYNOPSIS  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osmtest_req_context
block|{
name|osmtest_t
modifier|*
name|p_osmt
decl_stmt|;
name|osmv_query_res_t
name|result
decl_stmt|;
block|}
name|osmtest_req_context_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osmtest_mgrp_t
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_member_rec_t
name|mcmember_rec
decl_stmt|;
block|}
name|osmtest_mgrp_t
typedef|;
end_typedef

begin_comment
comment|/*  * FIELDS  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_construct  * NAME  * osmtest_construct  *  * DESCRIPTION  * This function constructs an OSMTest object.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osmtest_construct
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_osmt  *    [in] Pointer to a OSMTest object to construct.  *  * RETURN VALUE  * This function does not return a value.  *  * NOTES  * Allows calling osmtest_init, osmtest_destroy.  *  * Calling osmtest_construct is a prerequisite to calling any other  * method except osmtest_init.  *  * SEE ALSO  * SM object, osmtest_init, osmtest_destroy  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_destroy  * NAME  * osmtest_destroy  *  * DESCRIPTION  * The osmtest_destroy function destroys an osmtest object, releasing  * all resources.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osmtest_destroy
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_osmt  *    [in] Pointer to a OSMTest object to destroy.  *  * RETURN VALUE  * This function does not return a value.  *  * NOTES  * Performs any necessary cleanup of the specified OSMTest object.  * Further operations should not be attempted on the destroyed object.  * This function should only be called after a call to osmtest_construct or  * osmtest_init.  *  * SEE ALSO  * SM object, osmtest_construct, osmtest_init  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_init  * NAME  * osmtest_init  *  * DESCRIPTION  * The osmtest_init function initializes a OSMTest object for use.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmtest_init
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|,
name|IN
specifier|const
name|osmtest_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|,
name|IN
specifier|const
name|osm_log_level_t
name|log_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_osmt  *    [in] Pointer to an osmtest_t object to initialize.  *  * p_opt  *    [in] Pointer to the options structure.  *  * log_flags  *    [in] Log level flags to set.  *  * RETURN VALUES  * IB_SUCCESS if the OSMTest object was initialized successfully.  *  * NOTES  * Allows calling other OSMTest methods.  *  * SEE ALSO  * SM object, osmtest_construct, osmtest_destroy  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_run  * NAME  * osmtest_run  *  * DESCRIPTION  * Runs the osmtest suite.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmtest_run
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_osmt  *    [in] Pointer to an osmtest_t object.  *  * guid  *    [in] Port GUID over which to run the test suite.  *  * RETURN VALUES  * IB_SUCCESS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_bind  * NAME  * osmtest_bind  *  * DESCRIPTION  * Binds osmtest to a local port.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmtest_bind
parameter_list|(
name|IN
name|osmtest_t
modifier|*
name|p_osmt
parameter_list|,
name|IN
name|uint16_t
name|max_lid
parameter_list|,
name|IN
name|ib_net64_t
name|guid
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_osmt  *    [in] Pointer to an osmtest_t object.  *  *  max_lid  *     [in] The maximal lid to query about (if RMPP is not supported)  *  * guid  *    [in] Port GUID over which to run the test suite.  *    If zero, the bind function will display a menu of local  *    port guids and wait for user input.  *  * RETURN VALUES  * IB_SUCCESS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmtest_query_res_cb  * NAME  * osmtest_query_res_cb  *  * DESCRIPTION  * A Callback for the query to invoke on completion  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|void
name|osmtest_query_res_cb
parameter_list|(
name|IN
name|osmv_query_res_t
modifier|*
name|p_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_rec  *    [in] Pointer to an ib_query_rec_t object used for the query.  *  * RETURN VALUES  * NONE  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/ib_get_mad_status_str  * NAME  * ib_get_mad_status_str  *  * DESCRIPTION  * return the string representing the given  mad status  *  * SYNOPSIS  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|ib_get_mad_status_str
parameter_list|(
name|IN
specifier|const
name|ib_mad_t
modifier|*
specifier|const
name|p_mad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  * p_mad  *    [in] Pointer to the mad payload  *  * RETURN VALUES  * NONE  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmt_run_service_records_flow  * NAME  * osmt_run_service_records_flow  *  * DESCRIPTION  * Run the service record testing flow.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmt_run_service_records_flow
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *  p_osmt  *    [in] Pointer to the osmtest obj  *  * RETURN VALUES  * IB_SUCCESS if PASS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_function_decl
name|ib_api_status_t
name|osmt_run_inform_info_flow
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OSMTest/osmt_run_slvl_and_vlarb_records_flow  * NAME  * osmt_run_slvl_and_vlarb_records_flow  *  * DESCRIPTION  * Run the sl2vl and vlarb tables testing flow.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmt_run_slvl_and_vlarb_records_flow
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *  p_osmt  *    [in] Pointer to the osmtest obj  *  * RETURN VALUES  * IB_SUCCESS if PASS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmt_run_mcast_flow  * NAME  * osmt_run_mcast_flow  *  * DESCRIPTION  * Run the multicast test flow  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmt_run_mcast_flow
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *  p_osmt  *    [in] Pointer to the osmtest obj  *  * RETURN VALUES  * IB_SUCCESS if PASS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_comment
comment|/****f* OSMTest/osmt_run_trap64_65_flow  * NAME  * osmt_run_trap64_65_flow  *  * DESCRIPTION  * Run the trap 64/65 test flow. This test is ran with  * an outside tool.  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osmt_run_trap64_65_flow
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * PARAMETERS  *  p_osmt  *    [in] Pointer to the osmtest obj  *  * RETURN VALUES  * IB_SUCCESS if PASS  *  * NOTES  *  * SEE ALSO  *********/
end_comment

begin_function_decl
name|ib_api_status_t
name|osmtest_get_all_recs
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|,
name|IN
name|ib_net16_t
specifier|const
name|attr_id
parameter_list|,
name|IN
name|size_t
specifier|const
name|attr_size
parameter_list|,
name|IN
name|OUT
name|osmtest_req_context_t
modifier|*
specifier|const
name|p_context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_api_status_t
name|osmtest_get_local_port_lmc
parameter_list|(
name|IN
name|osmtest_t
modifier|*
specifier|const
name|p_osmt
parameter_list|,
name|IN
name|ib_net16_t
name|lid
parameter_list|,
name|OUT
name|uint8_t
modifier|*
specifier|const
name|p_lmc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A few auxiliary macros for logging  */
end_comment

begin_define
define|#
directive|define
name|EXPECTING_ERRORS_START
value|"[[ ===== Expecting Errors - START ===== "
end_define

begin_define
define|#
directive|define
name|EXPECTING_ERRORS_END
value|"   ===== Expecting Errors  -  END ===== ]]"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMTEST_H_ */
end_comment

end_unit

