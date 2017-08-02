begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSMV_INOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSMV_INOUT_H_
end_define

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

begin_expr_stmt
name|BEGIN_C_DECLS
ifdef|#
directive|ifdef
name|IN
undef|#
directive|undef
name|IN
endif|#
directive|endif
ifdef|#
directive|ifdef
name|OUT
undef|#
directive|undef
name|OUT
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_ANAFA
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_TS_NO_VAPI
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_SIM
include|#
directive|include
file|<mtl_common.h>
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|IN
define|#
directive|define
name|IN
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OUT
define|#
directive|define
name|OUT
endif|#
directive|endif
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_TS_NO_VAPI
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_ANAFA
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_SIM
include|#
directive|include
file|<vapi_types.h>
include|#
directive|include
file|<evapi.h>
endif|#
directive|endif
endif|#
directive|endif
endif|#
directive|endif
name|END_C_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSMV_INOUT_H_ */
end_comment

end_unit

