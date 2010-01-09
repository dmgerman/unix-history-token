begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_APBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_APBVAR_H_
end_define

begin_define
define|#
directive|define
name|APB_IRQ_BASE
value|0
end_define

begin_define
define|#
directive|define
name|APB_IRQ_END
value|7
end_define

begin_define
define|#
directive|define
name|APB_NIRQS
value|8
end_define

begin_struct
struct|struct
name|apb_softc
block|{
name|struct
name|rman
name|apb_irq_rman
decl_stmt|;
name|struct
name|rman
name|apb_mem_rman
decl_stmt|;
comment|/* IRQ events structs for child devices */
name|struct
name|intr_event
modifier|*
name|sc_eventstab
index|[
name|APB_NIRQS
index|]
decl_stmt|;
name|mips_intrcnt_t
name|sc_intr_counter
index|[
name|APB_NIRQS
index|]
decl_stmt|;
comment|/* Resources and cookies for MIPS CPU INTs */
name|struct
name|resource
modifier|*
name|sc_misc_irq
decl_stmt|;
name|void
modifier|*
name|sc_misc_ih
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|apb_ivar
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
comment|/* _APBVAR_H_ */
end_comment

end_unit

