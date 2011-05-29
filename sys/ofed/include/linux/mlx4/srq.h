begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Cisco Systems, Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *	- Redistributions of source code must retain the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer.  *  *	- Redistributions in binary form must reproduce the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer in the documentation and/or other materials  *	  provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MLX4_SRQ_H
end_ifndef

begin_define
define|#
directive|define
name|MLX4_SRQ_H
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/mlx4/device.h>
end_include

begin_struct
struct|struct
name|mlx4_wqe_srq_next_seg
block|{
name|u16
name|reserved1
decl_stmt|;
name|__be16
name|next_wqe_index
decl_stmt|;
name|u32
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|mlx4_srq_invalidate
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|struct
name|mlx4_srq
modifier|*
name|srq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mlx4_srq_remove
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|struct
name|mlx4_srq
modifier|*
name|srq
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|struct
name|mlx4_srq
modifier|*
name|__mlx4_srq_lookup
parameter_list|(
name|struct
name|mlx4_dev
modifier|*
name|dev
parameter_list|,
name|u32
name|srqn
parameter_list|)
block|{
return|return
name|radix_tree_lookup
argument_list|(
operator|&
name|dev
operator|->
name|srq_table_tree
argument_list|,
name|srqn
operator|&
operator|(
name|dev
operator|->
name|caps
operator|.
name|num_srqs
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MLX4_SRQ_H */
end_comment

end_unit

