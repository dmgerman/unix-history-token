begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Matthew R. Green  * Copyright (c) 2001, 2003 by Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychoreg.h,v 1.8 2001/09/10 16:17:06 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_PCI_OFW_PCI_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_PCI_OFW_PCI_H_
end_define

begin_include
include|#
directive|include
file|<machine/ofw_bus.h>
end_include

begin_typedef
typedef|typedef
name|u_int32_t
name|ofw_pci_intr_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"ofw_pci_if.h"
end_include

begin_comment
comment|/* PCI range child spaces. XXX: are these MI? */
end_comment

begin_define
define|#
directive|define
name|PCI_CS_CONFIG
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_CS_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|PCI_CS_MEM32
value|0x02
end_define

begin_define
define|#
directive|define
name|PCI_CS_MEM64
value|0x03
end_define

begin_function_decl
name|u_int8_t
name|ofw_pci_alloc_busno
parameter_list|(
name|phandle_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _SPARC64_PCI_OFW_PCI_H_ */
end_comment

end_unit

