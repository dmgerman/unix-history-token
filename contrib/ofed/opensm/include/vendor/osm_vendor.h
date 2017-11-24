begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Include file used by OpenSM to pull in the correct vendor file.  */
end_comment

begin_comment
comment|/*   this is the generic include file which includes   the proper vendor specific file */
end_comment

begin_include
include|#
directive|include
file|<opensm/osm_config.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OSM_VENDOR_INTF_TEST
argument_list|)
end_if

begin_include
include|#
directive|include
file|<vendor/osm_vendor_test.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_UMADT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<vendor/osm_vendor_umadt.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_MTL
argument_list|)
end_elif

begin_comment
comment|/* HACK - I do not know how to prevent complib from loading kernel H files */
end_comment

begin_undef
undef|#
directive|undef
name|__init
end_undef

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_TS
argument_list|)
end_elif

begin_undef
undef|#
directive|undef
name|__init
end_undef

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_ANAFA
argument_list|)
end_elif

begin_undef
undef|#
directive|undef
name|__init
end_undef

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_SIM
argument_list|)
end_elif

begin_undef
undef|#
directive|undef
name|__init
end_undef

begin_include
include|#
directive|include
file|<vendor/osm_vendor_mlx.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_OPENIB
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<vendor/osm_vendor_ibumad.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OSM_VENDOR_INTF_AL
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<vendor/osm_vendor_al.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|No MAD Interface selected!
end_error

begin_error
error|#
directive|error
error|Choose an interface in osm_config.h
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

