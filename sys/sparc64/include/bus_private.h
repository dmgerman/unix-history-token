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

begin_struct
struct|struct
name|bus_dmamap
block|{
name|bus_dma_tag_t
name|dmat
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
comment|/* unmapped buffer pointer */
name|bus_size_t
name|buflen
decl_stmt|;
comment|/* unmapped buffer length */
name|bus_addr_t
name|start
decl_stmt|;
comment|/* start of mapped region */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
comment|/* associated resource */
name|bus_size_t
name|dvmaresv
decl_stmt|;
comment|/* reseved DVMA memory */
name|STAILQ_ENTRY
argument_list|(
argument|bus_dmamap
argument_list|)
name|maplruq
expr_stmt|;
name|int
name|onq
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BUS_PRIVATE_H_ */
end_comment

end_unit

