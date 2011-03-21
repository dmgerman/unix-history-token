begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004, 2005 Topspin Communications.  All rights reserved.  * Copyright (c) 2005 Mellanox Technologies. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MTHCA_PROFILE_H
end_ifndef

begin_define
define|#
directive|define
name|MTHCA_PROFILE_H
end_define

begin_include
include|#
directive|include
file|"mthca_dev.h"
end_include

begin_include
include|#
directive|include
file|"mthca_cmd.h"
end_include

begin_struct
struct|struct
name|mthca_profile
block|{
name|int
name|num_qp
decl_stmt|;
name|int
name|rdb_per_qp
decl_stmt|;
name|int
name|num_srq
decl_stmt|;
name|int
name|num_cq
decl_stmt|;
name|int
name|num_mcg
decl_stmt|;
name|int
name|num_mpt
decl_stmt|;
name|int
name|num_mtt
decl_stmt|;
name|int
name|num_udav
decl_stmt|;
name|int
name|num_uar
decl_stmt|;
name|int
name|uarc_size
decl_stmt|;
name|int
name|fmr_reserved_mtts
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|s64
name|mthca_make_profile
parameter_list|(
name|struct
name|mthca_dev
modifier|*
name|mdev
parameter_list|,
name|struct
name|mthca_profile
modifier|*
name|request
parameter_list|,
name|struct
name|mthca_dev_lim
modifier|*
name|dev_lim
parameter_list|,
name|struct
name|mthca_init_hca_param
modifier|*
name|init_hca
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MTHCA_PROFILE_H */
end_comment

end_unit

