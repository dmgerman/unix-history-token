begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010-2011 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qla_ioctl.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLA_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLA_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|qla_reg_val
block|{
name|uint16_t
name|rd
decl_stmt|;
name|uint16_t
name|direct
decl_stmt|;
name|uint32_t
name|reg
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_reg_val
name|qla_reg_val_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_rd_flash
block|{
name|uint32_t
name|off
decl_stmt|;
name|uint32_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rd_flash
name|qla_rd_flash_t
typedef|;
end_typedef

begin_comment
comment|/*  * Read/Write Register  */
end_comment

begin_define
define|#
directive|define
name|QLA_RDWR_REG
value|_IOWR('q', 1, qla_reg_val_t)
end_define

begin_comment
comment|/*  * Read Flash  */
end_comment

begin_define
define|#
directive|define
name|QLA_RD_FLASH
value|_IOWR('q', 2, qla_rd_flash_t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLA_IOCTL_H_ */
end_comment

end_unit

