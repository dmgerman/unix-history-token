begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998 Justin T. Gibbs.  * Copyright (c) 2002 by Thomas Moestl<tmm@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	from: FreeBSD: src/sys/i386/i386/busdma_machdep.c,v 1.25 2002/01/05  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUS_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUS_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * This is more or less arbitrary, except for the stack space consumed by  * the segments array. Choose more than ((BUS_SPACE_MAXSIZE / PAGE_SIZE) + 1),  * since in practice we could be map pages more than once.  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMAMAP_NSEGS
value|64
end_define

begin_struct
struct|struct
name|bus_dmamap_res
block|{
name|struct
name|resource
modifier|*
name|dr_res
decl_stmt|;
name|bus_size_t
name|dr_used
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|bus_dmamap_res
argument_list|)
name|dr_link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bus_dmamap
block|{
name|TAILQ_ENTRY
argument_list|(
argument|bus_dmamap
argument_list|)
name|dm_maplruq
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|bus_dmamap_res
argument_list|)
name|dm_reslist
expr_stmt|;
name|int
name|dm_onq
decl_stmt|;
name|int
name|dm_loaded
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|void
name|sparc64_dmamap_init
parameter_list|(
name|struct
name|bus_dmamap
modifier|*
name|m
parameter_list|)
block|{
name|SLIST_INIT
argument_list|(
operator|&
name|m
operator|->
name|dm_reslist
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BUS_PRIVATE_H_ */
end_comment

end_unit

