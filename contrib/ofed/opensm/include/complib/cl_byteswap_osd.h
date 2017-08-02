begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Provides common macros for dealing with byte swapping issues.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CL_BYTESWAP_OSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_CL_BYTESWAP_OSD_H_
end_define

begin_comment
comment|/*  * This provides defines __LITTLE_ENDIAN, __BIG_ENDIAN and __BYTE_ORDER  */
end_comment

begin_include
include|#
directive|include
file|<infiniband/endian.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/byteswap.h>
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

begin_expr_stmt
name|BEGIN_C_DECLS
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
define|#
directive|define
name|cl_ntoh16
parameter_list|(
name|x
parameter_list|)
value|bswap_16(x)
define|#
directive|define
name|cl_hton16
parameter_list|(
name|x
parameter_list|)
value|bswap_16(x)
define|#
directive|define
name|cl_ntoh32
parameter_list|(
name|x
parameter_list|)
value|bswap_32(x)
define|#
directive|define
name|cl_hton32
parameter_list|(
name|x
parameter_list|)
value|bswap_32(x)
define|#
directive|define
name|cl_ntoh64
parameter_list|(
name|x
parameter_list|)
value|(uint64_t)bswap_64(x)
define|#
directive|define
name|cl_hton64
parameter_list|(
name|x
parameter_list|)
value|(uint64_t)bswap_64(x)
else|#
directive|else
comment|/* Big Endian */
define|#
directive|define
name|cl_ntoh16
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|cl_hton16
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|cl_ntoh32
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|cl_hton32
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|cl_ntoh64
parameter_list|(
name|x
parameter_list|)
value|(x)
define|#
directive|define
name|cl_hton64
parameter_list|(
name|x
parameter_list|)
value|(x)
endif|#
directive|endif
name|END_C_DECLS
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CL_BYTESWAP_OSD_H_ */
end_comment

end_unit

