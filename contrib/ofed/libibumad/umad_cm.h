begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Intel Corporation.  All rights reserved.  * Copyright (c) 2014 Mellanox Technologies LTD. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UMAD_CM_H
end_ifndef

begin_define
define|#
directive|define
name|_UMAD_CM_H
end_define

begin_include
include|#
directive|include
file|<infiniband/umad_types.h>
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

begin_decl_stmt
name|BEGIN_C_DECLS
comment|/* Communication management attributes */
name|enum
type|{
name|UMAD_CM_ATTR_REQ
init|=
literal|0x0010
decl_stmt|,
name|UMAD_CM_ATTR_MRA
init|=
literal|0x0011
decl_stmt|,
name|UMAD_CM_ATTR_REJ
init|=
literal|0x0012
decl_stmt|,
name|UMAD_CM_ATTR_REP
init|=
literal|0x0013
decl_stmt|,
name|UMAD_CM_ATTR_RTU
init|=
literal|0x0014
decl_stmt|,
name|UMAD_CM_ATTR_DREQ
init|=
literal|0x0015
decl_stmt|,
name|UMAD_CM_ATTR_DREP
init|=
literal|0x0016
decl_stmt|,
name|UMAD_CM_ATTR_SIDR_REQ
init|=
literal|0x0017
decl_stmt|,
name|UMAD_CM_ATTR_SIDR_REP
init|=
literal|0x0018
decl_stmt|,
name|UMAD_CM_ATTR_LAP
init|=
literal|0x0019
decl_stmt|,
name|UMAD_CM_ATTR_APR
init|=
literal|0x001A
decl_stmt|,
name|UMAD_CM_ATTR_SAP
init|=
literal|0x001B
decl_stmt|,
name|UMAD_CM_ATTR_SPR
init|=
literal|0x001C
decl_stmt|,
end_decl_stmt

begin_macro
unit|};
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UMAD_CM_H */
end_comment

end_unit

