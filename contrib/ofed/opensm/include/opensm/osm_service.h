begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SVCR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SVCR_H_
end_define

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_service_rec_t.  *	This object represents an IBA Service Record.  *	This object is part of the OpenSM family of objects.  */
end_comment

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
file|<complib/cl_spinlock.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
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
comment|/****h* OpenSM/Service Record * NAME *	Service Record * * DESCRIPTION *	The service record encapsulates the information needed by the *	SA to manage service registrations. * *	The service records is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Anil S Keshavamurthy, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Service Record/osm_svcr_t * NAME *	osm_svcr_t * * DESCRIPTION *	Service Record structure. * *	The osm_svcr_t object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_svcr
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|ib_service_record_t
name|service_record
decl_stmt|;
name|uint32_t
name|modified_time
decl_stmt|;
name|uint32_t
name|lease_period
decl_stmt|;
block|}
name|osm_svcr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Map Item for qmap linkage.  Must be first element!! * *	svc_rec *		IB Service record structure * *	modified_time *		Last modified time of this record in milliseconds * *	lease_period *		Remaining lease period for this record * * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Service Record/osm_svcr_new * NAME *	osm_svcr_new * * DESCRIPTION *	Allocates and initializes a Service Record for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_svcr_t
modifier|*
name|osm_svcr_new
parameter_list|(
name|IN
specifier|const
name|ib_service_record_t
modifier|*
name|p_svc_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_svc_rec *		[in] Pointer to IB Service Record * * RETURN VALUES *	pointer to osm_svcr_t structure. * * NOTES *	Allows calling other service record methods. * * SEE ALSO *	Service Record, osm_svcr_delete *********/
end_comment

begin_comment
comment|/****f* OpenSM: Service Record/osm_svcr_init * NAME *	osm_svcr_init * * DESCRIPTION *	Initializes the osm_svcr_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_svcr_init
parameter_list|(
name|IN
name|osm_svcr_t
modifier|*
name|p_svcr
parameter_list|,
name|IN
specifier|const
name|ib_service_record_t
modifier|*
name|p_svc_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_svc_rec *		[in] Pointer to osm_svcr_t structure *	p_svc_rec *		[in] Pointer to the ib_service_record_t * * SEE ALSO *	Service Record *********/
end_comment

begin_comment
comment|/****f* OpenSM: Service Record/osm_svcr_delete * NAME *	osm_svcr_delete * * DESCRIPTION *	Deallocates the osm_svcr_t structure. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_svcr_delete
parameter_list|(
name|IN
name|osm_svcr_t
modifier|*
name|p_svcr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_svc_rec *		[in] Pointer to osm_svcr_t structure * * SEE ALSO *	Service Record, osm_svcr_new *********/
end_comment

begin_function_decl
name|osm_svcr_t
modifier|*
name|osm_svcr_get_by_rid
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|ib_service_record_t
modifier|*
name|p_svc_rec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_svcr_insert_to_db
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_svcr_t
modifier|*
name|p_svcr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_svcr_remove_from_db
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_svcr_t
modifier|*
name|p_svcr
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_SVCR_H_ */
end_comment

end_unit

