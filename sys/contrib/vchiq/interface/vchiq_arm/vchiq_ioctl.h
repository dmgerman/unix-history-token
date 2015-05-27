begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHIQ_IOCTLS_H
end_ifndef

begin_define
define|#
directive|define
name|VCHIQ_IOCTLS_H
end_define

begin_include
include|#
directive|include
file|"vchiq_if.h"
end_include

begin_define
define|#
directive|define
name|VCHIQ_IOC_MAGIC
value|0xc4
end_define

begin_define
define|#
directive|define
name|VCHIQ_INVALID_HANDLE
value|(~0)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|VCHIQ_SERVICE_PARAMS_T
name|params
decl_stmt|;
name|int
name|is_open
decl_stmt|;
name|int
name|is_vchi
decl_stmt|;
name|unsigned
name|int
name|handle
decl_stmt|;
comment|/* OUT */
block|}
name|VCHIQ_CREATE_SERVICE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
specifier|const
name|VCHIQ_ELEMENT_T
modifier|*
name|elements
decl_stmt|;
block|}
name|VCHIQ_QUEUE_MESSAGE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
name|void
modifier|*
name|userdata
decl_stmt|;
name|VCHIQ_BULK_MODE_T
name|mode
decl_stmt|;
block|}
name|VCHIQ_QUEUE_BULK_TRANSFER_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|VCHIQ_REASON_T
name|reason
decl_stmt|;
name|VCHIQ_HEADER_T
modifier|*
name|header
decl_stmt|;
name|void
modifier|*
name|service_userdata
decl_stmt|;
name|void
modifier|*
name|bulk_userdata
decl_stmt|;
block|}
name|VCHIQ_COMPLETION_DATA_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|VCHIQ_COMPLETION_DATA_T
modifier|*
name|buf
decl_stmt|;
name|unsigned
name|int
name|msgbufsize
decl_stmt|;
name|unsigned
name|int
name|msgbufcount
decl_stmt|;
comment|/* IN/OUT */
name|void
modifier|*
modifier|*
name|msgbufs
decl_stmt|;
block|}
name|VCHIQ_AWAIT_COMPLETION_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
name|int
name|blocking
decl_stmt|;
name|unsigned
name|int
name|bufsize
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
block|}
name|VCHIQ_DEQUEUE_MESSAGE_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|config_size
decl_stmt|;
name|VCHIQ_CONFIG_T
modifier|*
name|pconfig
decl_stmt|;
block|}
name|VCHIQ_GET_CONFIG_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
name|VCHIQ_SERVICE_OPTION_T
name|option
decl_stmt|;
name|int
name|value
decl_stmt|;
block|}
name|VCHIQ_SET_SERVICE_OPTION_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|virt_addr
decl_stmt|;
name|size_t
name|num_bytes
decl_stmt|;
block|}
name|VCHIQ_DUMP_MEM_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VCHIQ_IOC_CONNECT
value|_IO(VCHIQ_IOC_MAGIC,   0)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_SHUTDOWN
value|_IO(VCHIQ_IOC_MAGIC,   1)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_CREATE_SERVICE
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 2, VCHIQ_CREATE_SERVICE_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_REMOVE_SERVICE
value|_IO(VCHIQ_IOC_MAGIC,   3)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_QUEUE_MESSAGE
define|\
value|_IOW(VCHIQ_IOC_MAGIC,  4, VCHIQ_QUEUE_MESSAGE_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_QUEUE_BULK_TRANSMIT
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 5, VCHIQ_QUEUE_BULK_TRANSFER_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_QUEUE_BULK_RECEIVE
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 6, VCHIQ_QUEUE_BULK_TRANSFER_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_AWAIT_COMPLETION
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 7, VCHIQ_AWAIT_COMPLETION_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_DEQUEUE_MESSAGE
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 8, VCHIQ_DEQUEUE_MESSAGE_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_GET_CLIENT_ID
value|_IO(VCHIQ_IOC_MAGIC,   9)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_GET_CONFIG
define|\
value|_IOWR(VCHIQ_IOC_MAGIC, 10, VCHIQ_GET_CONFIG_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_CLOSE_SERVICE
value|_IO(VCHIQ_IOC_MAGIC,   11)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_USE_SERVICE
value|_IO(VCHIQ_IOC_MAGIC,   12)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_RELEASE_SERVICE
value|_IO(VCHIQ_IOC_MAGIC,   13)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_SET_SERVICE_OPTION
define|\
value|_IOW(VCHIQ_IOC_MAGIC,  14, VCHIQ_SET_SERVICE_OPTION_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_DUMP_PHYS_MEM
define|\
value|_IOW(VCHIQ_IOC_MAGIC,  15, VCHIQ_DUMP_MEM_T)
end_define

begin_define
define|#
directive|define
name|VCHIQ_IOC_MAX
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

