begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Cisco Systems.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IB_UMEM_H
end_ifndef

begin_define
define|#
directive|define
name|IB_UMEM_H
end_define

begin_struct_decl
struct_decl|struct
name|ib_ucontext
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ib_umem_chunk
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ib_umem_chunk
argument_list|)
name|entry
expr_stmt|;
name|int
name|nents
decl_stmt|;
name|int
name|nmap
decl_stmt|;
name|struct
name|rdma_scatterlist
name|page_list
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ib_umem
block|{
name|struct
name|ib_ucontext
modifier|*
name|context
decl_stmt|;
name|size_t
name|length
decl_stmt|;
name|int
name|offset
decl_stmt|;
name|int
name|page_size
decl_stmt|;
name|int
name|writable
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ib_umem_chunk
argument_list|)
name|chunk_list
expr_stmt|;
ifdef|#
directive|ifdef
name|notyet
name|struct
name|work_struct
name|work
decl_stmt|;
name|struct
name|mm_struct
modifier|*
name|mm
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|long
name|diff
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_INFINIBAND_USER_MEM
end_ifdef

begin_function_decl
name|struct
name|ib_umem
modifier|*
name|ib_umem_get
parameter_list|(
name|struct
name|ib_ucontext
modifier|*
name|context
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|access
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ib_umem_release
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ib_umem_page_count
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_INFINIBAND_USER_MEM */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|ib_umem
modifier|*
name|ib_umem_get
parameter_list|(
name|struct
name|ib_ucontext
modifier|*
name|context
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|access
parameter_list|)
block|{
return|return
name|ERR_PTR
argument_list|(
name|EINVAL
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ib_umem_release
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
specifier|inline
name|int
name|ib_umem_page_count
parameter_list|(
name|struct
name|ib_umem
modifier|*
name|umem
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_INFINIBAND_USER_MEM */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IB_UMEM_H */
end_comment

end_unit

