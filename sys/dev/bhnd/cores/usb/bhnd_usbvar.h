begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, Aleksandr Rybalko<ray@ddteam.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_USBVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_USBVAR_H_
end_define

begin_struct
struct|struct
name|bhnd_usb_softc
block|{
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
name|bus_addr_t
name|sc_maddr
decl_stmt|;
name|bus_size_t
name|sc_msize
decl_stmt|;
name|bus_addr_t
name|sc_irqn
decl_stmt|;
name|struct
name|intr_event
modifier|*
name|sc_events
decl_stmt|;
comment|/* IRQ events structs */
name|struct
name|resource
modifier|*
name|sc_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|struct
name|rman
name|mem_rman
decl_stmt|;
name|struct
name|rman
name|irq_rman
decl_stmt|;
name|int
name|devid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bhnd_usb_devinfo
block|{
name|struct
name|resource_list
name|sdi_rl
decl_stmt|;
name|uint8_t
name|sdi_unit
decl_stmt|;
comment|/* core index on bus */
name|rman_res_t
name|sdi_irq
decl_stmt|;
comment|/**< child IRQ, if mapped */
name|bool
name|sdi_irq_mapped
decl_stmt|;
comment|/**< true if IRQ mapped, false otherwise */
name|char
name|sdi_name
index|[
literal|8
index|]
decl_stmt|;
name|rman_res_t
name|sdi_maddr
decl_stmt|;
name|rman_res_t
name|sdi_msize
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_USBVAR_H_ */
end_comment

end_unit

