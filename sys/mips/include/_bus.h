begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: src/sys/i386/include/_bus.h,v 1.1 2005/04/18 21:45:33 imp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_INCLUDE__BUS_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_INCLUDE__BUS_H
end_define

begin_comment
comment|/*  * Bus address and size types  */
end_comment

begin_include
include|#
directive|include
file|"opt_cputype.h"
end_include

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|TARGET_OCTEON
argument_list|)
operator|||
name|defined
argument_list|(
name|ISA_MIPS32
argument_list|)
operator|)
end_if

begin_typedef
typedef|typedef
name|uintptr_t
name|bus_addr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint64_t
name|bus_addr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uintptr_t
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
name|bus_addr_t
name|bus_space_handle_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_INCLUDE__BUS_H */
end_comment

end_unit

