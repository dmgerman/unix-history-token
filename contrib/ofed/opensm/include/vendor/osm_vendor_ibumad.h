begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_VENDOR_UMAD_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_VENDOR_UMAD_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
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
file|<infiniband/umad.h>
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
comment|/****h* OpenSM/Vendor Access Layer (UMAD) * NAME *	Vendor UMAD * * DESCRIPTION *	This file is the vendor specific file for the UMAD Infiniband API. * * AUTHOR * * *********/
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_RETRY_COUNT
value|3
end_define

begin_define
define|#
directive|define
name|OSM_UMAD_MAX_CAS
value|UMAD_MAX_DEVICES
end_define

begin_define
define|#
directive|define
name|OSM_UMAD_MAX_PORTS_PER_CA
value|2
end_define

begin_define
define|#
directive|define
name|OSM_UMAD_MAX_AGENTS
value|32
end_define

begin_comment
comment|/****s* OpenSM: Vendor UMAD/osm_ca_info_t * NAME *   osm_ca_info_t * * DESCRIPTION * 	Structure containing information about local Channel Adapters. * * SYNOPSIS */
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

begin_comment
comment|/****f* OpenSM: CA Info/osm_ca_info_get_num_ports * NAME *	osm_ca_info_get_num_ports * * DESCRIPTION *	Returns the number of ports owned by this CA. * * SYNOPSIS */
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
comment|/* * PARAMETERS *	p_ca_info *		[in] Pointer to a CA Info object. * * RETURN VUMADUE *	Returns the number of ports owned by this CA. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: Vendor UMAD/osm_bind_handle_t * NAME *   osm_bind_handle_t * * DESCRIPTION * 	handle returned by the vendor transport bind call. * * SYNOPSIS */
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

begin_typedef
typedef|typedef
struct|struct
name|_umad_match
block|{
name|ib_net64_t
name|tid
decl_stmt|;
name|void
modifier|*
name|v
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
name|uint8_t
name|mgmt_class
decl_stmt|;
block|}
name|umad_match_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEFAULT_OSM_UMAD_MAX_PENDING
value|1000
end_define

begin_typedef
typedef|typedef
struct|struct
name|vendor_match_tbl
block|{
name|uint32_t
name|last_version
decl_stmt|;
name|int
name|max
decl_stmt|;
name|umad_match_t
modifier|*
name|tbl
decl_stmt|;
block|}
name|vendor_match_tbl_t
typedef|;
end_typedef

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
name|ca_count
decl_stmt|;
name|osm_ca_info_t
modifier|*
name|p_ca_info
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
name|int
name|max_retries
decl_stmt|;
name|osm_bind_handle_t
name|agents
index|[
name|OSM_UMAD_MAX_AGENTS
index|]
decl_stmt|;
name|char
name|ca_names
index|[
name|OSM_UMAD_MAX_CAS
index|]
index|[
name|UMAD_CA_NAME_LEN
index|]
decl_stmt|;
name|vendor_match_tbl_t
name|mtbl
decl_stmt|;
name|umad_port_t
name|umad_port
decl_stmt|;
name|pthread_mutex_t
name|cb_mutex
decl_stmt|;
name|pthread_mutex_t
name|match_tbl_mutex
decl_stmt|;
name|int
name|umad_port_id
decl_stmt|;
name|void
modifier|*
name|receiver
decl_stmt|;
name|int
name|issmfd
decl_stmt|;
name|char
name|issm_path
index|[
literal|256
index|]
decl_stmt|;
block|}
name|osm_vendor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OSM_BIND_INVALID_HANDLE
value|0
end_define

begin_typedef
typedef|typedef
struct|struct
name|_osm_vend_wrap
block|{
name|int
name|agent
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|retries
decl_stmt|;
name|void
modifier|*
name|umad
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
block|}
name|osm_vend_wrap_t
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
comment|/* _OSM_VENDOR_UMAD_H_ */
end_comment

end_unit

