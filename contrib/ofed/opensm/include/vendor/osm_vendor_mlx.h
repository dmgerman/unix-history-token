begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2007,2009 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
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
comment|/*   Forward reference */
end_comment

begin_struct_decl
struct_decl|struct
name|_osm_pkt_randomizer
struct_decl|;
end_struct_decl

begin_comment
comment|/* The structure behind the OSM Vendor handle */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_osm_vendor
block|{
comment|/* for holding common transport info - useful at ibmgt transport */
name|void
modifier|*
name|p_transport_info
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
comment|/* Uniform timeout for every ACK/single MAD */
name|uint32_t
name|resp_timeout
decl_stmt|;
comment|/* Uniform timeout for every rmpp transaction */
name|uint32_t
name|ttime_timeout
decl_stmt|;
comment|/* All the bind handles associated with the vendor */
name|cl_qlist_t
name|bind_handles
decl_stmt|;
comment|/* run randomizer flag */
name|boolean_t
name|run_randomizer
decl_stmt|;
comment|/* Packet Randomizer object */
name|struct
name|_osm_pkt_randomizer
modifier|*
name|p_pkt_randomizer
decl_stmt|;
block|}
name|osm_vendor_t
typedef|;
end_typedef

begin_comment
comment|/* Repeating the definitions in osm_vendor_api.h */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|osm_bind_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_osm_vend_wrap
block|{
name|ib_mad_t
modifier|*
name|p_mad
decl_stmt|;
block|}
name|osm_vend_wrap_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_BIND_INVALID_HANDLE
end_ifndef

begin_define
define|#
directive|define
name|OSM_BIND_INVALID_HANDLE
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The maximum number of retransmissions of the same MAD */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_RETRY_COUNT
value|3
end_define

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

