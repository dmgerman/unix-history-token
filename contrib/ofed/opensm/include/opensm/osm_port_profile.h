begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005,2008 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2008 Xsigo Systems Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of Switch/osm_port_profile_t.  *	This object represents a port profile for an IBA switch.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_PORT_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_PORT_PROFILE_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

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
file|<opensm/osm_madw.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_node.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mcast_tbl.h>
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
comment|/****h* OpenSM/Port Profile * NAME *	Port Profile * * DESCRIPTION *	The Port Profile object contains profiling information for *	each Physical Port on a switch.  The profile information *	may be used to optimize path selection. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Switch/osm_port_profile_t * NAME *	osm_port_profile_t * * DESCRIPTION *	The Port Profile object contains profiling information for *	each Physical Port on the switch.  The profile information *	may be used to optimize path selection. * *	This object should be treated as opaque and should be *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_port_profile
block|{
name|uint32_t
name|num_paths
decl_stmt|;
block|}
name|osm_port_profile_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	num_paths *		The number of paths using this port. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: Switch/osm_port_mask_t * NAME *	osm_port_mask_t * * DESCRIPTION *       The Port Mask object contains a port numbered bit mask *	for whether the port should be ignored by the link load *	equalization algorithm. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|long
name|osm_port_mask_t
index|[
literal|32
operator|/
sizeof|sizeof
argument_list|(
name|long
argument_list|)
index|]
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	osm_port_mask_t *		Bit mask by port number * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port Profile/osm_port_prof_construct * NAME *	osm_port_prof_construct * * DESCRIPTION * * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_port_prof_construct
parameter_list|(
name|IN
name|osm_port_profile_t
modifier|*
name|p_prof
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_prof
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|p_prof
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_prof
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_prof *		[in] Pointer to the Port Profile object to construct. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port Profile/osm_port_prof_path_count_inc * NAME *	osm_port_prof_path_count_inc * * DESCRIPTION *	Increments the count of the number of paths going through this port. * * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_port_prof_path_count_inc
parameter_list|(
name|IN
name|osm_port_profile_t
modifier|*
name|p_prof
parameter_list|)
block|{
name|CL_ASSERT
argument_list|(
name|p_prof
argument_list|)
expr_stmt|;
name|p_prof
operator|->
name|num_paths
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_prof *		[in] Pointer to the Port Profile object. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port Profile/osm_port_prof_path_count_get * NAME *	osm_port_prof_path_count_get * * DESCRIPTION *	Returns the count of the number of paths going through this port. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osm_port_prof_path_count_get
parameter_list|(
name|IN
specifier|const
name|osm_port_profile_t
modifier|*
name|p_prof
parameter_list|)
block|{
return|return
name|p_prof
operator|->
name|num_paths
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_prof *		[in] Pointer to the Port Profile object. * * RETURN VALUE *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_PORT_PROFILE_H_ */
end_comment

end_unit

