begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  * Written by: Navdeep Parhar<np@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_IOCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_IOCTL_H__
end_define

begin_comment
comment|/*  * Ioctl commands specific to this driver.  */
end_comment

begin_enum
enum|enum
block|{
name|T4_GET32
init|=
literal|0x40
block|,
comment|/* read 32 bit register */
name|T4_SET32
block|,
comment|/* write 32 bit register */
name|T4_REGDUMP
block|,
comment|/* dump of all registers */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t4_reg32
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T4_REGDUMP_SIZE
value|(160 * 1024)
end_define

begin_struct
struct|struct
name|t4_regdump
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
comment|/* bytes */
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHELSIO_T4_GETREG32
value|_IOWR('f', T4_GET32, struct t4_reg32)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SETREG32
value|_IOW('f', T4_SET32, struct t4_reg32)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_REGDUMP
value|_IOWR('f', T4_REGDUMP, struct t4_regdump)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

