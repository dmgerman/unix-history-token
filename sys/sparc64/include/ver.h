begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_VER_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_VER_H_
end_define

begin_define
define|#
directive|define
name|VER_MANUF_SHIFT
value|(48)
end_define

begin_define
define|#
directive|define
name|VER_IMPL_SHIFT
value|(32)
end_define

begin_define
define|#
directive|define
name|VER_MASK_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|VER_MAXTL_SHIFT
value|(8)
end_define

begin_define
define|#
directive|define
name|VER_MAXWIN_SHIFT
value|(0)
end_define

begin_define
define|#
directive|define
name|VER_MANUF_SIZE
value|(16)
end_define

begin_define
define|#
directive|define
name|VER_IMPL_SIZE
value|(16)
end_define

begin_define
define|#
directive|define
name|VER_MASK_SIZE
value|(8)
end_define

begin_define
define|#
directive|define
name|VER_MAXTL_SIZE
value|(8)
end_define

begin_define
define|#
directive|define
name|VER_MAXWIN_SIZE
value|(5)
end_define

begin_define
define|#
directive|define
name|VER_MANUF_MASK
value|(((1L<<VER_MANUF_SIZE)-1)<<VER_MANUF_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_IMPL_MASK
value|(((1L<<VER_IMPL_SIZE)-1)<<VER_IMPL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MASK_MASK
value|(((1L<<VER_MASK_SIZE)-1)<<VER_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MAXTL_MASK
value|(((1L<<VER_MAXTL_SIZE)-1)<<VER_MAXTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MAXWIN_MASK
value|(((1L<<VER_MAXWIN_SIZE)-1)<<VER_MAXWIN_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MANUF
parameter_list|(
name|ver
parameter_list|)
define|\
value|(((ver)& VER_MANUF_MASK)>> VER_MANUF_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_IMPL
parameter_list|(
name|ver
parameter_list|)
define|\
value|(((ver)& VER_IMPL_MASK)>> VER_IMPL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MASK
parameter_list|(
name|ver
parameter_list|)
define|\
value|(((ver)& VER_MASK_MASK)>> VER_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MAXTL
parameter_list|(
name|ver
parameter_list|)
define|\
value|(((ver)& VER_MAXTL_MASK)>> VER_MAXTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|VER_MAXWIN
parameter_list|(
name|ver
parameter_list|)
define|\
value|(((ver)& VER_MAXWIN_MASK)>> VER_MAXWIN_SHIFT)
end_define

begin_decl_stmt
specifier|extern
name|int
name|cpu_impl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Known implementations. */
end_comment

begin_define
define|#
directive|define
name|CPU_IMPL_SPARC64
value|0x01
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_ULTRASPARCI
value|0x10
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_ULTRASPARCII
value|0x11
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_ULTRASPARCIIi
value|0x12
end_define

begin_define
define|#
directive|define
name|CPU_IMPL_ULTRASPARCIIe
value|0x13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_VER_H_ */
end_comment

end_unit

