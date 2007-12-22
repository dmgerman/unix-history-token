begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Eduardo E. Horvath  * Copyright (c) 1999 Matthew R. Green  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: psychoreg.h,v 1.8 2001/09/10 16:17:06 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_OFW_NEXUS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_OFW_NEXUS_H_
end_define

begin_comment
comment|/*  * These are the regs used for devices on the nexus. They apply to all of  * Fireplane/Safari, JBus and UPA.  */
end_comment

begin_struct
struct|struct
name|nexus_regs
block|{
name|uint32_t
name|phys_hi
decl_stmt|;
name|uint32_t
name|phys_lo
decl_stmt|;
name|uint32_t
name|size_hi
decl_stmt|;
name|uint32_t
name|size_lo
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NEXUS_REG_PHYS
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->phys_hi<< 32) | (uint64_t)(r)->phys_lo)
end_define

begin_define
define|#
directive|define
name|NEXUS_REG_SIZE
parameter_list|(
name|r
parameter_list|)
define|\
value|(((uint64_t)(r)->size_hi<< 32) | (uint64_t)(r)->size_lo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_OFW_NEXUS_H_ */
end_comment

end_unit

