begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IIC_H
end_ifndef

begin_define
define|#
directive|define
name|__IIC_H
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/* Designed to be compatible with linux's struct i2c_msg */
end_comment

begin_struct
struct|struct
name|iic_msg
block|{
name|uint16_t
name|slave
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|IIC_M_WR
value|0
comment|/* Fake flag for write */
define|#
directive|define
name|IIC_M_RD
value|0x0001
comment|/* read vs write */
name|uint16_t
name|len
decl_stmt|;
comment|/* msg legnth */
name|uint8_t
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iiccmd
block|{
name|u_char
name|slave
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|last
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iic_rdwr_data
block|{
name|struct
name|iic_msg
modifier|*
name|msgs
decl_stmt|;
name|uint32_t
name|nmsgs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|I2CSTART
value|_IOW('i', 1, struct iiccmd)
end_define

begin_comment
comment|/* start condition */
end_comment

begin_define
define|#
directive|define
name|I2CSTOP
value|_IO('i', 2)
end_define

begin_comment
comment|/* stop condition */
end_comment

begin_define
define|#
directive|define
name|I2CRSTCARD
value|_IOW('i', 3, struct iiccmd)
end_define

begin_comment
comment|/* reset the card */
end_comment

begin_define
define|#
directive|define
name|I2CWRITE
value|_IOW('i', 4, struct iiccmd)
end_define

begin_comment
comment|/* send data */
end_comment

begin_define
define|#
directive|define
name|I2CREAD
value|_IOW('i', 5, struct iiccmd)
end_define

begin_comment
comment|/* receive data */
end_comment

begin_define
define|#
directive|define
name|I2CRDWR
value|_IOW('i', 6, struct iic_rdwr_data)
end_define

begin_comment
comment|/* General read/write interface */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

