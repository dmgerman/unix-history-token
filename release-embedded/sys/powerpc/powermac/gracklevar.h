begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_POWERMAC_GRACKLEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_POWERMAC_GRACKLEVAR_H_
end_define

begin_struct
struct|struct
name|grackle_softc
block|{
name|struct
name|ofw_pci_softc
name|pci_sc
decl_stmt|;
name|vm_offset_t
name|sc_addr
decl_stmt|;
name|vm_offset_t
name|sc_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Apple uses address map B for the MPC106  */
end_comment

begin_define
define|#
directive|define
name|GRACKLE_ADDR
value|0xFEC00000
end_define

begin_define
define|#
directive|define
name|GRACKLE_DATA
value|0xFEE00000
end_define

begin_comment
comment|/*  * The high bit of the config word is 'Enable'. This should always be  * set.  */
end_comment

begin_define
define|#
directive|define
name|GRACKLE_CFG_ENABLE
value|0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_POWERMAC_GRACKLEVAR_H_ */
end_comment

end_unit

