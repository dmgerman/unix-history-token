begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: obiovar.h,v 1.4 2003/06/16 17:40:53 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OCTEON_OBIOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_OCTEON_OBIOVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_struct
struct|struct
name|obio_softc
block|{
name|bus_space_tag_t
name|oba_st
decl_stmt|;
comment|/* bus space tag */
name|bus_addr_t
name|oba_addr
decl_stmt|;
comment|/* address of device */
name|bus_size_t
name|oba_size
decl_stmt|;
comment|/* size of device */
name|int
name|oba_width
decl_stmt|;
comment|/* bus width */
name|int
name|oba_irq
decl_stmt|;
comment|/* XINT interrupt bit # */
name|struct
name|rman
name|oba_rman
decl_stmt|;
name|struct
name|rman
name|oba_irq_rman
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|obio_bs_tag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OCTEON_OBIOVAR_H_ */
end_comment

end_unit

