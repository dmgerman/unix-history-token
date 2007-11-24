begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 by Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_OFW_PCI_SUBR_H
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_OFW_PCI_SUBR_H
end_define

begin_struct
struct|struct
name|ofw_pcib_gen_softc
block|{
comment|/* 	 * This is here so that we can use pci bridge methods, too - the 	 * generic routines only need the dev, secbus and subbus members 	 * filled. 	 */
name|struct
name|pcib_softc
name|ops_pcib_sc
decl_stmt|;
name|phandle_t
name|ops_node
decl_stmt|;
name|struct
name|ofw_bus_iinfo
name|ops_iinfo
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ofw_pcib_gen_setup
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|pcib_route_interrupt_t
name|ofw_pcib_gen_route_interrupt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_bus_get_node_t
name|ofw_pcib_gen_get_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ofw_pci_adjust_busrange_t
name|ofw_pcib_gen_adjust_busrange
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_PCI_OFW_PCI_SUBR_H */
end_comment

end_unit

