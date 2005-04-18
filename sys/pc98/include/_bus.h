begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC98_INCLUDE__BUS_H
end_ifndef

begin_define
define|#
directive|define
name|PC98_INCLUDE__BUS_H
end_define

begin_comment
comment|/*  * Bus address and size types  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|bus_size_t
typedef|;
end_typedef

begin_comment
comment|/*  * Access methods for bus resources and address space.  */
end_comment

begin_struct
struct|struct
name|bus_space_tag
block|{
define|#
directive|define
name|BUS_SPACE_IO
value|0
define|#
directive|define
name|BUS_SPACE_MEM
value|1
name|u_int
name|bs_tag
decl_stmt|;
comment|/* bus space flags */
name|struct
name|bus_space_access_methods
name|bs_da
decl_stmt|;
comment|/* direct access */
name|struct
name|bus_space_access_methods
name|bs_ra
decl_stmt|;
comment|/* relocate access */
if|#
directive|if
literal|0
block|struct bus_space_access_methods bs_ida;
comment|/* indexed direct access */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bus_space_tag
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

begin_comment
comment|/*  * bus space handle  */
end_comment

begin_struct
struct|struct
name|bus_space_handle
block|{
name|bus_addr_t
name|bsh_base
decl_stmt|;
name|size_t
name|bsh_sz
decl_stmt|;
name|bus_addr_t
name|bsh_iat
index|[
name|BUS_SPACE_IAT_MAXSIZE
index|]
decl_stmt|;
name|size_t
name|bsh_maxiatsz
decl_stmt|;
name|size_t
name|bsh_iatsz
decl_stmt|;
name|struct
name|resource
modifier|*
modifier|*
name|bsh_res
decl_stmt|;
name|size_t
name|bsh_ressz
decl_stmt|;
name|struct
name|bus_space_access_methods
name|bsh_bam
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bus_space_handle
modifier|*
name|bus_space_handle_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC98_INCLUDE__BUS_H */
end_comment

end_unit

