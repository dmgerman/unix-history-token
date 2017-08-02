begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_TEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_TEST_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
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
comment|/* This value must be zero for the TEST transport. */
end_comment

begin_define
define|#
directive|define
name|OSM_BIND_INVALID_HANDLE
value|0
end_define

begin_comment
comment|/*  * Abstract:  * 	Declaration of vendor specific transport interface.  *  This is the "Test" vendor which allows compilation and some  *  testing without a real vendor interface.  *	These objects are part of the OpenSM family of objects.  */
end_comment

begin_comment
comment|/****h* OpenSM/Vendor Test * NAME *	Vendor Test * * DESCRIPTION *	The Vendor Test structure encapsulates an artificial transport layer *	interface for testing. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor Test/osm_vend_wrap_t * NAME *	osm_vend_wrap_t * * DESCRIPTION *	Vendor specific MAD wrapper context. * *	This structure allows direct access to member variables. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vend_wrap
block|{
name|uint32_t
name|dummy
decl_stmt|;
block|}
name|osm_vend_wrap_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor Test/osm_vendor_t * NAME *	osm_vendor_t * * DESCRIPTION *	Vendor specific MAD interface. * *	This interface defines access to the vendor specific MAD *	transport layer. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vendor
block|{
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
block|}
name|osm_vendor_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_bind_handle
block|{
name|osm_vendor_t
modifier|*
name|p_vend
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|uint8_t
name|mad_class
decl_stmt|;
name|uint8_t
name|class_version
decl_stmt|;
name|boolean_t
name|is_responder
decl_stmt|;
name|boolean_t
name|is_trap_processor
decl_stmt|;
name|boolean_t
name|is_report_processor
decl_stmt|;
name|uint32_t
name|send_q_size
decl_stmt|;
name|uint32_t
name|recv_q_size
decl_stmt|;
block|}
typedef|*
name|osm_bind_handle_t
typedef|;
end_typedef

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_VENDOR_TEST_H_ */
end_comment

end_unit

