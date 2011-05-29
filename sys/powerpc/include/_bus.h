begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POWERPC_INCLUDE__BUS_H
end_ifndef

begin_define
define|#
directive|define
name|POWERPC_INCLUDE__BUS_H
end_define

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_comment
comment|/*  * Bus address and size types  */
end_comment

begin_typedef
typedef|typedef
name|vm_paddr_t
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vm_size_t
name|bus_size_t
typedef|;
end_typedef

begin_comment
comment|/*  * Access methods for bus resources and address space.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_space
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|vm_offset_t
name|bus_space_handle_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POWERPC_INCLUDE__BUS_H */
end_comment

end_unit

