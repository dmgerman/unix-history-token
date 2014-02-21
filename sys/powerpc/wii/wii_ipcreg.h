begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Margarida Gouveia  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_WII_WII_IPCREG_H
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_WII_WII_IPCREG_H
end_define

begin_define
define|#
directive|define
name|WIIIPC_REG_ADDR
value|0x0d000000
end_define

begin_define
define|#
directive|define
name|WIIIPC_REG_LEN
value|0x40
end_define

begin_define
define|#
directive|define
name|WIIIPC_IOH_ADDR
value|0x133e0000
end_define

begin_define
define|#
directive|define
name|WIIIPC_IOH_LEN
value|0xc20000
end_define

begin_define
define|#
directive|define
name|WIIIPC_TXBUF
value|0x00
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR
value|0x04
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_TXSTART
value|0x01
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_TBEI
value|0x02
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_RBFI
value|0x04
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_RXREADY
value|0x08
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_RBFIMASK
value|0x10
end_define

begin_define
define|#
directive|define
name|WIIIPC_CSR_TBEIMASK
value|0x20
end_define

begin_define
define|#
directive|define
name|WIIIPC_RXBUF
value|0x08
end_define

begin_define
define|#
directive|define
name|WIIIPC_ISR
value|0x30
end_define

begin_define
define|#
directive|define
name|WIIIPC_ISR_MAGIC
value|0x40000000
end_define

begin_enum
enum|enum
name|wiiipc_cmd
block|{
name|WIIIPC_CMD_OPEN
init|=
literal|1
block|,
name|WIIIPC_CMD_CLOSE
init|=
literal|2
block|,
name|WIIIPC_CMD_READ
init|=
literal|3
block|,
name|WIIIPC_CMD_WRITE
init|=
literal|4
block|,
name|WIIIPC_CMD_SEEK
init|=
literal|5
block|,
name|WIIIPC_CMD_IOCTL
init|=
literal|6
block|,
name|WIIIPC_CMD_IOCTLV
init|=
literal|7
block|,
name|WIIIPC_CMD_ASYNCRESP
init|=
literal|8
block|}
enum|;
end_enum

begin_struct
struct|struct
name|wiiipc_ipc_msg
block|{
name|uint32_t
name|ipc_cmd
decl_stmt|;
name|int32_t
name|ipc_result
decl_stmt|;
name|int32_t
name|ipc_fd
decl_stmt|;
comment|/* WIIIPC_CMD_ASYNCRESP - the original cmd */
union|union
block|{
struct|struct
block|{
name|intptr_t
name|pathname
decl_stmt|;
name|uint32_t
name|mode
decl_stmt|;
block|}
name|_ipc_open
struct|;
struct|struct
block|{
name|intptr_t
name|data
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
block|}
name|_ipc_read
struct|,
name|_ipc_write
struct|;
struct|struct
block|{
name|int32_t
name|offset
decl_stmt|;
name|int32_t
name|whence
decl_stmt|;
block|}
name|_ipc_seek
struct|;
struct|struct
block|{
name|uint32_t
name|request
decl_stmt|;
name|intptr_t
name|ibuf
decl_stmt|;
name|uint32_t
name|ilen
decl_stmt|;
name|intptr_t
name|obuf
decl_stmt|;
name|uint32_t
name|olen
decl_stmt|;
block|}
name|_ipc_ioctl
struct|;
struct|struct
block|{
name|uint32_t
name|request
decl_stmt|;
name|uint32_t
name|argin
decl_stmt|;
name|uint32_t
name|argout
decl_stmt|;
name|intptr_t
name|iovec
decl_stmt|;
block|}
name|_ipc_ioctlv
struct|;
name|uint32_t
name|_ipc_argv
index|[
literal|5
index|]
decl_stmt|;
block|}
name|args
union|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|wiiipc_ipc_msg
argument_list|)
operator|==
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ipc_open
value|args._ipc_open
end_define

begin_define
define|#
directive|define
name|ipc_read
value|args._ipc_read
end_define

begin_define
define|#
directive|define
name|ipc_write
value|args._ipc_write
end_define

begin_define
define|#
directive|define
name|ipc_ioctl
value|args._ipc_ioctl
end_define

begin_define
define|#
directive|define
name|ipc_ioctlv
value|args._ipc_ioctlv
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_WII_WII_IPCREG_H */
end_comment

end_unit

