begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mad_pool_t.  *	This object represents a pool of management datagram (MAD) objects.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MAD_POOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MAD_POOL_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_atomic.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_madw.h>
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
comment|/****h* OpenSM/MAD Pool * NAME *	MAD Pool * * DESCRIPTION *	The MAD Pool encapsulates the information needed by the *	OpenSM to manage a pool of MAD objects.  The OpenSM allocates *	one MAD Pool per IBA subnet. * *	The MAD Pool is thread safe. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Pool/osm_mad_pool_t * NAME *	osm_mad_pool_t * * DESCRIPTION *	MAD Pool structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mad_pool
block|{
name|atomic32_t
name|mads_out
decl_stmt|;
block|}
name|osm_mad_pool_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	mads_out *		Running total of the number of MADs outstanding. * * SEE ALSO *	MAD Pool *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_construct * NAME *	osm_mad_pool_construct * * DESCRIPTION *	This function constructs a MAD Pool. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mad_pool_construct
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a MAD Pool to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_mad_pool_init, osm_mad_pool_destroy * *	Calling osm_mad_pool_construct is a prerequisite to calling any other *	method except osm_mad_pool_init. * * SEE ALSO *	MAD Pool, osm_mad_pool_init, osm_mad_pool_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_destroy * NAME *	osm_mad_pool_destroy * * DESCRIPTION *	The osm_mad_pool_destroy function destroys a node, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mad_pool_destroy
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to a MAD Pool to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified MAD Pool. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_mad_pool_construct or *	osm_mad_pool_init. * * SEE ALSO *	MAD Pool, osm_mad_pool_construct, osm_mad_pool_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_init * NAME *	osm_mad_pool_init * * DESCRIPTION *	The osm_mad_pool_init function initializes a MAD Pool for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_mad_pool_init
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object to initialize. * * RETURN VALUES *	CL_SUCCESS if the MAD Pool was initialized successfully. * * NOTES *	Allows calling other MAD Pool methods. * * SEE ALSO *	MAD Pool, osm_mad_pool_construct, osm_mad_pool_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_get * NAME *	osm_mad_pool_get * * DESCRIPTION *	Gets a MAD wrapper and wire MAD from the pool. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_madw_t
modifier|*
name|osm_mad_pool_get
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|,
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint32_t
name|total_size
parameter_list|,
name|IN
specifier|const
name|osm_mad_addr_t
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object. * *	h_bind *		[in] Handle returned from osm_vendor_bind() call to the *		port over which this mad will be sent. * *	total_size *		[in] Total size, including MAD header of the requested MAD. * *	p_mad_addr *		[in] Pointer to the MAD address structure.  This parameter *		may be NULL for directed route MADs. * * RETURN VALUES *	Returns a pointer to a MAD wrapper containing the MAD. *	A return value of NULL means no MADs are available. * * NOTES *	The MAD must eventually be returned to the pool with a call to *	osm_mad_pool_put. * *	The osm_mad_pool_construct or osm_mad_pool_init must be called before *	using this function. * * SEE ALSO *	MAD Pool, osm_mad_pool_put *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_put * NAME *	osm_mad_pool_put * * DESCRIPTION *	Returns a MAD to the pool. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_mad_pool_put
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object. * *	p_madw *		[in] Pointer to a MAD Wrapper for a MAD that was previously *		retrieved from the pool. * * RETURN VALUES *	This function does not return a value. * * NOTES *	The osm_mad_pool_construct or osm_mad_pool_init must be called before *	using this function. * * SEE ALSO *	MAD Pool, osm_mad_pool_get *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_get_wrapper * NAME *	osm_mad_pool_get_wrapper * * DESCRIPTION *	Gets a only MAD wrapper from the pool (no wire MAD). * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_madw_t
modifier|*
name|osm_mad_pool_get_wrapper
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|,
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint32_t
name|total_size
parameter_list|,
name|IN
specifier|const
name|ib_mad_t
modifier|*
name|p_mad
parameter_list|,
name|IN
specifier|const
name|osm_mad_addr_t
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object. * *	h_bind *		[in] Handle returned from osm_vendor_bind() call to the *		port for which this mad wrapper will be used. * *	total_size *		[in] Total size, including MAD header of the MAD that will *		be attached to this wrapper. * *	p_mad *		[in] Pointer to the MAD to attach to this wrapper. * *	p_mad_addr *		[in] Pointer to the MAD address structure.  This parameter *		may be NULL for directed route MADs. * * RETURN VALUES *	Returns a pointer to a MAD wrapper. *	A return value of NULL means no MAD wrappers are available. * * NOTES *	The MAD must eventually be returned to the pool with a call to *	osm_mad_pool_put. * *	The osm_mad_pool_construct or osm_mad_pool_init must be called before *	using this function. * * SEE ALSO *	MAD Pool, osm_mad_pool_put *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_get_wrapper_raw * NAME *	osm_mad_pool_get_wrapper_raw * * DESCRIPTION *	Gets a only an uninitialized MAD wrapper from the pool (no wire MAD). * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_madw_t
modifier|*
name|osm_mad_pool_get_wrapper_raw
parameter_list|(
name|IN
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object. * * RETURN VALUES *	Returns a pointer to a MAD wrapper. *	A return value of NULL means no MAD wrappers are available. * * NOTES *	The MAD must eventually be returned to the pool with a call to *	osm_mad_pool_put. * *	The osm_mad_pool_construct or osm_mad_pool_init must be called before *	using this function. * * SEE ALSO *	MAD Pool, osm_mad_pool_put *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Pool/osm_mad_pool_get_outstanding * NAME *	osm_mad_pool_get_count * * DESCRIPTION *	Returns the running count of MADs currently outstanding from the pool. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osm_mad_pool_get_outstanding
parameter_list|(
name|IN
specifier|const
name|osm_mad_pool_t
modifier|*
name|p_pool
parameter_list|)
block|{
return|return
name|p_pool
operator|->
name|mads_out
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_pool *		[in] Pointer to an osm_mad_pool_t object. * * RETURN VALUES *	Returns the running count of MADs currently outstanding from the pool. * * NOTES *	The osm_mad_pool_construct or osm_mad_pool_init must be called before *	using this function. * * SEE ALSO *	MAD Pool, osm_mad_pool_get *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MAD_POOL_H_ */
end_comment

end_unit

