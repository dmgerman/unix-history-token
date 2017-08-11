begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MMC_MMC_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MMC_MMC_IOCTL_H_
end_define

begin_struct
struct|struct
name|mmc_ioc_cmd
block|{
name|int
name|write_flag
decl_stmt|;
comment|/* 0: RD, 1: WR, (1<< 31): reliable WR */
name|int
name|is_acmd
decl_stmt|;
comment|/* 0: normal, 1: use CMD55 */
name|uint32_t
name|opcode
decl_stmt|;
name|uint32_t
name|arg
decl_stmt|;
name|uint32_t
name|response
index|[
literal|4
index|]
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|u_int
name|blksz
decl_stmt|;
name|u_int
name|blocks
decl_stmt|;
name|u_int
name|__spare
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|__pad
decl_stmt|;
name|uint64_t
name|data_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mmc_ioc_cmd_set_data
parameter_list|(
name|mic
parameter_list|,
name|ptr
parameter_list|)
define|\
value|(mic).data_ptr = (uint64_t)(uintptr_t)(ptr)
end_define

begin_struct
struct|struct
name|mmc_ioc_multi_cmd
block|{
name|uint64_t
name|num_of_cmds
decl_stmt|;
name|struct
name|mmc_ioc_cmd
name|cmds
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MMC_IOC_BASE
value|'M'
end_define

begin_define
define|#
directive|define
name|MMC_IOC_CMD
value|_IOWR(MMC_IOC_BASE, 0, struct mmc_ioc_cmd)
end_define

begin_define
define|#
directive|define
name|MMC_IOC_MULTI_CMD
value|_IOWR(MMC_IOC_BASE, 1, struct mmc_ioc_multi_cmd)
end_define

begin_comment
comment|/* Maximum accepted data transfer size */
end_comment

begin_define
define|#
directive|define
name|MMC_IOC_MAX_BYTES
value|(512  * 256)
end_define

begin_comment
comment|/* Maximum accepted number of commands */
end_comment

begin_define
define|#
directive|define
name|MMC_IOC_MAX_CMDS
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MMC_MMC_IOCTL_H_ */
end_comment

end_unit

