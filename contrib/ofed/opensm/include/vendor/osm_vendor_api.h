begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *  Specification of the OpenSM transport API. This API is OpenSM's view  *  of the Infiniband transport.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_API_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_API_H_
end_define

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor.h>
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
comment|/****s* OpenSM Vendor API/osm_vend_mad_recv_callback_t * NAME *  osm_vend_mad_recv_callback_t * * DESCRIPTION *  Function prototype for the vendor MAD receive callback. *  The vendor layer calls this function for MAD receives. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osm_vend_mad_recv_callback_t
function_decl|)
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|,
name|IN
name|void
modifier|*
name|bind_context
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_req_madw
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *  p_madw *     [in] The received MAD wrapper. * *  bind_context *     [in] User context supplied during the bind call. * *  p_req_madw *     [in] Pointer to the request mad wrapper that generated this response. *     If the inbound MAD is not a response, this field is NULL. * * RETURN VALUES *  None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM Vendor API/osm_vend_mad_send_err_callback_t * NAME *  osm_vend_mad_send_err_callback_t * * DESCRIPTION *  Function prototype for the vendor send failure callback. *  The vendor layer calls this function when MADs expecting *  a response are completed in error, most likely due to a *  timeout. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|osm_vend_mad_send_err_callback_t
function_decl|)
parameter_list|(
name|IN
name|void
modifier|*
name|bind_context
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* * PARAMETERS *  bind_context *     [in] User context supplied during the bind call. * *  p_madw *     [in] Pointer to the request mad that failed. * * RETURN VALUES *  None. * * NOTES *  The vendor layer does not call this function (or any other) *  for MADs that were not expecting a response. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_new * NAME *  osm_vendor_new * * DESCRIPTION *  Allocates and initializes a new osm_vendor_t object. *  OpenSM calls this function before any other in the vendor API. *  This object is passed as a parameter to all other vendor functions. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_vendor_t
modifier|*
name|osm_vendor_new
parameter_list|(
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_log *     [in] Pointer to the log object to use. * *  timeout *     [in] transaction timeout * * RETURN VALUES *  Returns a pointer to the vendor object. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM Vendor API/osm_vendor_delete * NAME *  osm_vendor_delete * * DESCRIPTION *  Dealocate the vendor object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vendor_delete
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
modifier|*
specifier|const
name|pp_vend
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  pp_vend *     [in/out] pointer to pointer to vendor objcet to be deleted * * RETURN VALUES *  None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_get_all_port_attr * NAME *  osm_vendor_get_all_port_attr * * DESCRIPTION *  Returns an array of available port attribute structures. * * SYNOPSIS */
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
comment|/* * PARAMETERS *  p_vend *     [in] Pointer to the vendor object to initialize. * *  p_attr_array *     [in/out] Pointer to pre-allocated array of port attributes. *     If it is NULL - then the command only updates the p_num_ports, *     and return IB_INSUFFICIENT_MEMORY. * *  p_num_ports *     [in/out] Pointer to a variable to hold the total number of ports *     available on the local machine. * * RETURN VALUES *  IB_SUCCESS on success. *  IB_INSUFFICIENT_MEMORY if the attribute array was not large enough. *  The number of attributes needed is returned in num_guids. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_init * NAME *  osm_vendor_init * * DESCRIPTION *  The osm_vendor_init function initializes the vendor transport layer. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vendor_init
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|osm_log_t
modifier|*
specifier|const
name|p_log
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_vend *     [in] Pointer to the vendor object to initialize. * *  p_log *     [in] Pointer to OpenSM's log object.  Vendor code may *     use the log object to send messages to OpenSM's log. * *  timeout *     [in] Transaction timeout value in milliseconds. *     A value of 0 disables timeouts. * * RETURN VALUE * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_bind * NAME *   osm_vendor_bind * * DESCRIPTION *   The osm_vendor_bind function registers with the vendor transport layer *   per Mad Class per PortGuid for mad transport capability. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_bind_handle_t
name|osm_vendor_bind
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|osm_bind_info_t
modifier|*
specifier|const
name|p_bind_info
parameter_list|,
name|IN
name|osm_mad_pool_t
modifier|*
specifier|const
name|p_mad_pool
parameter_list|,
name|IN
name|osm_vend_mad_recv_callback_t
name|mad_recv_callback
parameter_list|,
name|IN
name|osm_vend_mad_send_err_callback_t
name|send_err_callback
parameter_list|,
name|IN
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  p_vend *    [in] pointer to the vendor object * *  p_osm_bind_info *    [in] pointer to a struct defining the type of bind to perform. * *  p_mad_pool *    [in] pointer to a mad wrappers pool to be used for allocating *    mad wrappers on send and receive. * *  mad_recv_callback *    [in] the callback function to be invoked on mad receive. * *  send_err_callback *    [in] the callback function to be invoked on mad transaction errors. * *  context *    [in] the context to be provided to the callbacks as bind_ctx. * * RETURN VALUE *  On success, a valid bind handle. *  OSM_BIND_INVALID_HANDLE otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_unbind * NAME *   osm_vendor_unbind * * DESCRIPTION *   Unbind the given bind handle (obtained by osm_vendor_bind). * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vendor_unbind
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *  h_bind *    [in] the bind handle to release. * * RETURN VALUE *    NONE. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_get * NAME *   osm_vendor_get * * DESCRIPTION *   Obtain a mad wrapper holding actual mad buffer to be sent via *   the transport. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_mad_t
modifier|*
name|osm_vendor_get
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|mad_size
parameter_list|,
name|IN
name|osm_vend_wrap_t
modifier|*
specifier|const
name|p_vend_wrap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *      [in] the bind handle obtained by calling osm_vendor_bind * *   mad_size *      [in] the actual mad size required * *   p_vend_wrap *      [out] the returned mad vendor wrapper * * RETURN VALUE *   IB_SUCCESS on succesful completion. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_send * NAME *   osm_vendor_send * * DESCRIPTION * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vendor_send
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
specifier|const
name|p_madw
parameter_list|,
name|IN
name|boolean_t
specifier|const
name|resp_expected
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *      [in] the bind handle obtained by calling osm_vendor_bind * *   p_madw *      [in] pointer to the Mad Wrapper structure for the MAD to be sent. * *   resp_expected *      [in] boolean value declaring the mad as a request (expecting a response). * * RETURN VALUE *   IB_SUCCESS on succesful completion. * * NOTES *   1. Only mads that expect a response are tracked for transaction competion. *   2. A mad that does not expect a response is being put back immediately *      after being sent. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_put * NAME *   osm_vendor_put * * DESCRIPTION *   Return a mad vendor wrapper to the mad pool. It also means that the *   mad buffer is returned to the transport. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vendor_put
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|osm_vend_wrap_t
modifier|*
specifier|const
name|p_vend_wrap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *      [in] the bind handle obtained by calling osm_vendor_bind * *   p_vend_wrap *      [in] pointer to the mad vendor wrapper to put back into the pool. * * RETURN VALUE *   None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****i* OpenSM Vendor API/osm_vendor_local_lid_change * NAME *   osm_vendor_local_lid_change * * DESCRIPTION *  Notifies the vendor transport layer that the local address *  has changed.  This allows the vendor layer to perform housekeeping *  functions such as address vector updates. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_vendor_local_lid_change
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *      [in] the bind handle obtained by calling osm_vendor_bind * * RETURN VALUE * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_set_sm * NAME *   osm_vendor_set_sm * * DESCRIPTION *  Modifies the port info for the bound port to set the "IS_SM" bit *  according to the value given (TRUE or FALSE). * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vendor_set_sm
parameter_list|(
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|boolean_t
name|is_sm_val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   h_bind *     [in] bind handle for this port. * *   is_sm_val *     [in] If TRUE - will set the is_sm to TRUE, if FALSE - will set the *          the is_sm to FALSE. * * RETURN VALUE *  None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM Vendor API/osm_vendor_set_debug * NAME *   osm_vendor_set_debug * * DESCRIPTION *  Modifies the vendor specific debug level. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_vendor_set_debug
parameter_list|(
name|IN
name|osm_vendor_t
modifier|*
specifier|const
name|p_vend
parameter_list|,
name|IN
name|int32_t
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *   p_vend *     [in] vendor handle. * *   level *     [in] vendor specific debug level. * * RETURN VALUE *  None. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VENDOR_API_H_ */
end_comment

end_unit

