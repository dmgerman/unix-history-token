begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mad_wrapper_t.  *	This object represents the context wrapper for OpenSM MAD processing.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_UMADT_h_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_UMADT_h_
end_define

begin_include
include|#
directive|include
file|"iba/ib_types.h"
end_include

begin_include
include|#
directive|include
file|"complib/cl_qlist.h"
end_include

begin_include
include|#
directive|include
file|"complib/cl_thread.h"
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<vendor/umadt.h>
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
comment|/****h* OpenSM/ Vendor Umadt * NAME *	MAD Wrapper * * DESCRIPTION * * * AUTHOR *	Ranjit Pandit, Intel * *********/
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|osm_vendor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSM_BIND_INVALID_HANDLE
value|0
end_define

begin_comment
comment|/****s* OpenSM: Vendor Umadt /osm_bind_handle_t * NAME *   osm_bind_handle_t * * DESCRIPTION * 	handle returned by the vendor transport bind call. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|osm_bind_handle_t
typedef|;
end_typedef

begin_comment
comment|/****s* OpenSM: Vendor Umadt /mad_direction_t * NAME *	mad_direction_t * * DESCRIPTION *	Tags for mad wrapper to indicate the direction of mads. *	Umadt vendor transport layer uses this tag to call the appropriate * 	Umadt APIs. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_mad_direction_t
block|{
name|SEND
init|=
literal|0
block|,
name|RECEIVE
block|, }
name|mad_direction_t
typedef|;
end_typedef

begin_comment
comment|/****s* OpenSM/ osm_vend_wrap_t * NAME *   Umadt Vendor MAD Wrapper * * DESCRIPTION *	Umadt specific MAD wrapper. Umadt transport layer sets this for *	housekeeping. * * SYNOPSIS *********/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vend_wrap_t
block|{
name|MadtStruct
modifier|*
name|p_madt_struct
decl_stmt|;
name|mad_direction_t
name|direction
decl_stmt|;
comment|// send or receive
name|uint32_t
name|size
decl_stmt|;
block|}
name|osm_vend_wrap_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_madt_struct *		Umadt mad structure to identify a mad. * *	direction *		Used to identify a mad with it's direction. * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VENDOR_UMADT_h_ */
end_comment

end_unit

