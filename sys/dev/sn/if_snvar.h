begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 M. Warner Losh<imp@village.org>   * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_SNVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_SNVAR_H
end_define

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_comment
comment|/*  * Ethernet software status per interface.  The first element MUST  * be the arpcom struct since the address of the arpcom struct is  * used as a backdoor to obtain the address of this whole structure  * in many cases.  */
end_comment

begin_struct
struct|struct
name|sn_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common part */
name|short
name|sn_io_addr
decl_stmt|;
comment|/* i/o bus address (BASE) */
name|int
name|pages_wanted
decl_stmt|;
comment|/* Size of outstanding MMU ALLOC */
name|int
name|intr_mask
decl_stmt|;
comment|/* Most recently set interrupt mask */
name|device_t
name|dev
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
name|int
name|port_rid
decl_stmt|;
name|int
name|pccard_enaddr
decl_stmt|;
comment|/* MAC address in pccard CIS tupple */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sn_probe
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sn_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sn_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sn_activate
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sn_deactivate
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_SNVAR_H */
end_comment

end_unit

