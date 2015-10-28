begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<x86/bus.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_comment
comment|/*  * Implementation of bus_space_map(), which effectively is a thin  * wrapper around pmap_mapdev() for memory mapped I/O space. It's  * implemented here and not in<x86/bus.h> to avoid pollution.  */
end_comment

begin_function
name|int
name|bus_space_map
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_addr_t
name|addr
parameter_list|,
name|bus_size_t
name|size
parameter_list|,
name|int
name|flags
name|__unused
parameter_list|,
name|bus_space_handle_t
modifier|*
name|bshp
parameter_list|)
block|{
operator|*
name|bshp
operator|=
operator|(
name|tag
operator|==
name|X86_BUS_SPACE_MEM
operator|)
condition|?
operator|(
name|uintptr_t
operator|)
name|pmap_mapdev
argument_list|(
name|addr
argument_list|,
name|size
argument_list|)
else|:
name|addr
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|bus_space_unmap
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
block|{
if|if
condition|(
name|tag
operator|==
name|X86_BUS_SPACE_MEM
condition|)
name|pmap_unmapdev
argument_list|(
name|bsh
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

