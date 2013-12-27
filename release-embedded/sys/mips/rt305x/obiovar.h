begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: obiovar.h,v 1.4 2003/06/16 17:40:53 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002, 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RT305X_OBIOVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_RT305X_OBIOVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_comment
comment|/* Number of IRQs */
end_comment

begin_define
define|#
directive|define
name|NIRQS
value|32
end_define

begin_struct
struct|struct
name|obio_softc
block|{
name|struct
name|rman
name|oba_mem_rman
decl_stmt|;
name|struct
name|rman
name|oba_irq_rman
decl_stmt|;
name|struct
name|rman
name|oba_gpio_rman
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|sc_eventstab
index|[
name|NIRQS
index|]
decl_stmt|;
comment|/* IRQ events structs */
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
comment|/* IRQ resource */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt cookie */
name|struct
name|resource
modifier|*
name|sc_fast_irq
decl_stmt|;
comment|/* IRQ resource */
name|void
modifier|*
name|sc_fast_ih
decl_stmt|;
comment|/* interrupt cookie */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|obio_ivar
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RT305X_OBIOVAR_H_ */
end_comment

end_unit

