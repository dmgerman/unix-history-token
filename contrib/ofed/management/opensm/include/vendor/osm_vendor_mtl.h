begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Definition of interface for the MTL Vendor  *	   This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_MTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_MTL_H_
end_define

begin_undef
undef|#
directive|undef
name|IN
end_undef

begin_undef
undef|#
directive|undef
name|OUT
end_undef

begin_include
include|#
directive|include
file|<vapi_types.h>
end_include

begin_include
include|#
directive|include
file|<evapi.h>
end_include

begin_include
include|#
directive|include
file|<ib_mgt.h>
end_include

begin_define
define|#
directive|define
name|IN
end_define

begin_define
define|#
directive|define
name|OUT
end_define

begin_include
include|#
directive|include
file|"iba/ib_types.h"
end_include

begin_include
include|#
directive|include
file|"iba/ib_al.h"
end_include

begin_include
include|#
directive|include
file|<complib/cl_thread.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_types_osd.h>
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
comment|/****h* OpenSM/Vendor MTL * NAME *	Vendor MTL * * DESCRIPTION * *	The Vendor MTL object is thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * * AUTHOR * * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor MTL/osm_ca_info_t * NAME *   osm_ca_info_t * * DESCRIPTION * 	Structure containing information about local Channle Adapters. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_ca_info
block|{
name|ib_net64_t
name|guid
decl_stmt|;
name|size_t
name|attr_size
decl_stmt|;
name|ib_ca_attr_t
modifier|*
name|p_attr
decl_stmt|;
block|}
name|osm_ca_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	guid *		Node GUID of the local CA. * *	attr_size *		Size of the CA attributes for this CA. * *	p_attr *		Pointer to dynamicly allocated CA Attribute structure. * * SEE ALSO *********/
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_RETRY_COUNT
value|3
end_define

begin_comment
comment|/***** OpenSM: Vendor MTL/osm_vendor_t * NAME *  osm_vendor_t * * DESCRIPTION * 	The structure defining a vendor * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vendor
block|{
name|ib_al_handle_t
name|h_al
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|uint32_t
name|ca_count
decl_stmt|;
name|osm_ca_info_t
modifier|*
name|p_ca_info
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
name|struct
name|osm_transaction_mgr_t
modifier|*
name|p_transaction_mgr
decl_stmt|;
block|}
name|osm_vendor_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	h_al *		Handle returned by MTL open call (ib_open_al). * *	p_log *		Pointer to the log object. * *	ca_count *		Number of CA's in the array pointed to by p_ca_info. * *	p_ca_info *		Pointer to dynamically allocated array of CA info objects. * *	timeout *		Transaction timeout time in milliseconds. * *  p_transaction_mgr *     Pointer to Transaction Manager. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Vendor MTL/CA Info/osm_ca_info_get_port_guid * NAME *	osm_ca_info_get_port_guid * * DESCRIPTION *	Returns the port GUID of the specified port owned by this CA. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_net64_t
name|osm_ca_info_get_port_guid
parameter_list|(
name|IN
specifier|const
name|osm_ca_info_t
modifier|*
specifier|const
name|p_ca_info
parameter_list|,
name|IN
specifier|const
name|uint8_t
name|index
parameter_list|)
block|{
return|return
operator|(
name|p_ca_info
operator|->
name|p_attr
operator|->
name|p_port_attr
index|[
name|index
index|]
operator|.
name|port_guid
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ca_info *		[in] Pointer to a CA Info object. * *	index *		[in] Port "index" for which to retrieve the port GUID. *		The index is the offset into the ca's internal array *		of port attributes. * * RETURN VALUE *	Returns the port GUID of the specified port owned by this CA. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Vendor MTL/CA Info/osm_ca_info_get_num_ports * NAME *	osm_ca_info_get_num_ports * * DESCRIPTION *	Returns the number of ports of the given ca_info * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|osm_ca_info_get_num_ports
parameter_list|(
name|IN
specifier|const
name|osm_ca_info_t
modifier|*
specifier|const
name|p_ca_info
parameter_list|)
block|{
return|return
operator|(
name|p_ca_info
operator|->
name|p_attr
operator|->
name|num_ports
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_ca_info *		[in] Pointer to a CA Info object. * * RETURN VALUE *	Returns the number of CA ports * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM Vendor/osm_vendor_get_guid_ca_and_port  * NAME  *	osm_vendor_get_guid_ca_and_port  *  * DESCRIPTION  * Given the vendor obj and a guid  * return the ca id and port number that have that guid  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vendor_get_guid_ca_and_port
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|ib_net64_t
specifier|const
name|guid
parameter_list|,
name|OUT
name|VAPI_hca_hndl_t
modifier|*
name|p_hca_hndl
parameter_list|,
name|OUT
name|VAPI_hca_id_t
modifier|*
name|p_hca_id
parameter_list|,
name|OUT
name|uint32_t
modifier|*
name|p_port_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to an osm_vendor_t object. * *	guid *		[in] The guid to search for. * *	p_hca_id *		[out] The HCA Id (VAPI_hca_id_t *) that the port is found on. * *	p_port_num *		[out] Pointer to a port number arg to be filled with the port number with the given guid. * * RETURN VALUES *	IB_SUCCESS on SUCCESS *  IB_INVALID_GUID if the guid is notfound on any Local HCA Port * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Vendor MTL/osm_vendor_get_all_port_attr  * NAME  *	osm_vendor_get_all_port_attr  *  * DESCRIPTION  * Fill in the array of port_attr with all available ports on ALL the  * avilable CAs on this machine.  * ALSO -  * UPDATE THE VENDOR OBJECT LIST OF CA_INFO STRUCTS  *  * SYNOPSIS  */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vendor_get_all_port_attr
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|ib_port_attr_t
modifier|*
specifier|const
name|p_attr_array
parameter_list|,
name|IN
name|uint32_t
modifier|*
specifier|const
name|p_num_ports
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_vend *		[in] Pointer to an osm_vendor_t object. * *	p_attr_array *		[out] Pre-allocated array of port attributes to be filled in * *	p_num_ports *		[out] The size of the given array. Filled in by the actual numberof ports found. * * RETURN VALUES *	IB_SUCCESS if OK *  IB_INSUFFICIENT_MEMORY if not enough place for all ports was provided. * * NOTES * * SEE ALSO *********/
end_comment

begin_define
define|#
directive|define
name|OSM_BIND_INVALID_HANDLE
value|0
end_define

begin_comment
comment|/****s* OpenSM: Vendor MTL/osm_bind_handle_t * NAME *   osm_bind_handle_t * * DESCRIPTION * 	handle returned by the vendor transport bind call. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|osm_bind_handle_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor MTL/osm_vend_wrap_t * NAME *   MTL Vendor MAD Wrapper * * DESCRIPTION *	MTL specific MAD wrapper. MTL transport layer uses this for *	housekeeping. * * SYNOPSIS *********/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vend_wrap_t
block|{
name|uint32_t
name|size
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
comment|// ib_av_handle_t         h_av;
name|ib_mad_t
modifier|*
name|mad_buf_p
decl_stmt|;
name|void
modifier|*
name|p_resp_madw
decl_stmt|;
block|}
name|osm_vend_wrap_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	size *		Size of the allocated MAD * *	h_bind *		Bind handle used on this transaction * *	h_av *		Address vector handle used for this transaction. * *	p_resp_madw *		Pointer to the mad wrapper structure used to hold the pending *		reponse to the mad, if any.  If a response is expected, the *		wrapper for the reponse is allocated during the send call. * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VENDOR_MTL_H_ */
end_comment

end_unit

