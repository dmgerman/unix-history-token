begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFINIBAND_MARSHALL_H
end_ifndef

begin_define
define|#
directive|define
name|INFINIBAND_MARSHALL_H
end_define

begin_include
include|#
directive|include
file|<infiniband/verbs.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/sa.h>
end_include

begin_include
include|#
directive|include
file|<infiniband/kern-abi.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_user_sa.h>
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

begin_function_decl
name|BEGIN_C_DECLS
name|void
name|ibv_copy_qp_attr_from_kern
parameter_list|(
name|struct
name|ibv_qp_attr
modifier|*
name|dst
parameter_list|,
name|struct
name|ibv_kern_qp_attr
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibv_copy_ah_attr_from_kern
parameter_list|(
name|struct
name|ibv_ah_attr
modifier|*
name|dst
parameter_list|,
name|struct
name|ibv_kern_ah_attr
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibv_copy_path_rec_from_kern
parameter_list|(
name|struct
name|ibv_sa_path_rec
modifier|*
name|dst
parameter_list|,
name|struct
name|ib_user_path_rec
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ibv_copy_path_rec_to_kern
parameter_list|(
name|struct
name|ib_user_path_rec
modifier|*
name|dst
parameter_list|,
name|struct
name|ibv_sa_path_rec
modifier|*
name|src
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
comment|/* INFINIBAND_MARSHALL_H */
end_comment

end_unit

