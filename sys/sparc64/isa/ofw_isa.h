begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, 2000 Matthew R. Green  * Copyright (c) 2001 Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: ebus.c,v 1.26 2001/09/10 16:27:53 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPARC64_ISA_OFW_ISA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SPARC64_ISA_OFW_ISA_H_
end_define

begin_comment
comment|/*  * ISA PROM structures  */
end_comment

begin_struct
struct|struct
name|isa_regs
block|{
name|u_int32_t
name|phys_hi
decl_stmt|;
comment|/* high bits of physaddr */
name|u_int32_t
name|phys_lo
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISA_REG_PHYS
parameter_list|(
name|r
parameter_list|)
define|\
value|((((u_int64_t)((r)->phys_hi))<< 32) | ((u_int64_t)(r)->phys_lo))
end_define

begin_comment
comment|/* XXX: this is a guess. Verify... */
end_comment

begin_struct
struct|struct
name|isa_ranges
block|{
name|u_int32_t
name|child_hi
decl_stmt|;
name|u_int32_t
name|child_lo
decl_stmt|;
name|u_int32_t
name|phys_hi
decl_stmt|;
name|u_int32_t
name|phys_mid
decl_stmt|;
name|u_int32_t
name|phys_lo
decl_stmt|;
name|u_int32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISA_RANGE_CHILD
parameter_list|(
name|r
parameter_list|)
define|\
value|((((u_int64_t)((r)->child_hi))<< 32) | ((u_int64_t)(r)->child_lo))
end_define

begin_define
define|#
directive|define
name|ISA_RANGE_PS
parameter_list|(
name|r
parameter_list|)
value|(((r)->phys_hi>> 24)& 0x03)
end_define

begin_struct
struct|struct
name|isa_imap
block|{
name|u_int32_t
name|phys_hi
decl_stmt|;
comment|/* high phys addr mask */
name|u_int32_t
name|phys_lo
decl_stmt|;
comment|/* low phys addr mask */
name|u_int32_t
name|intr
decl_stmt|;
comment|/* interrupt mask */
name|int32_t
name|cnode
decl_stmt|;
comment|/* child node */
name|u_int32_t
name|cintr
decl_stmt|;
comment|/* child interrupt */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|isa_imap_msk
block|{
name|u_int32_t
name|phys_hi
decl_stmt|;
comment|/* high phys addr */
name|u_int32_t
name|phys_lo
decl_stmt|;
comment|/* low phys addr */
name|u_int32_t
name|intr
decl_stmt|;
comment|/* interrupt */
block|}
struct|;
end_struct

begin_comment
comment|/* Map an interrupt property to an INO */
end_comment

begin_function_decl
name|int
name|ofw_isa_map_intr
parameter_list|(
name|struct
name|isa_imap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|isa_imap_msk
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|isa_regs
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map an IO range. Returns the resource type of the range. */
end_comment

begin_function_decl
name|int
name|ofw_isa_map_iorange
parameter_list|(
name|struct
name|isa_ranges
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SPARC64_ISA_OFW_ISA_H_ */
end_comment

end_unit

