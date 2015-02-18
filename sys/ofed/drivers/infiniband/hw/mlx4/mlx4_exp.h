begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006, 2007 Cisco Systems.  All rights reserved.  * Copyright (c) 2007, 2008 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX4_EXP_H
end_ifndef

begin_define
define|#
directive|define
name|MLX4_EXP_H
end_define

begin_include
include|#
directive|include
file|<rdma/ib_verbs_exp.h>
end_include

begin_include
include|#
directive|include
file|"mlx4_ib.h"
end_include

begin_function_decl
name|struct
name|ib_qp
modifier|*
name|mlx4_ib_exp_create_qp
parameter_list|(
name|struct
name|ib_pd
modifier|*
name|pd
parameter_list|,
name|struct
name|ib_exp_qp_init_attr
modifier|*
name|init_attr
parameter_list|,
name|struct
name|ib_udata
modifier|*
name|udata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mlx4_ib_exp_query_device
parameter_list|(
name|struct
name|ib_device
modifier|*
name|ibdev
parameter_list|,
name|struct
name|ib_exp_device_attr
modifier|*
name|props
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX4_EXP_H */
end_comment

end_unit

