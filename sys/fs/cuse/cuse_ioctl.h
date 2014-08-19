begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2014 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CUSE_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CUSE_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|CUSE_BUFFER_MAX
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|CUSE_DEVICES_MAX
value|64
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|CUSE_BUF_MIN_PTR
value|0x10000UL
end_define

begin_define
define|#
directive|define
name|CUSE_BUF_MAX_PTR
value|0x20000UL
end_define

begin_define
define|#
directive|define
name|CUSE_ALLOC_UNIT_MAX
value|128
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|CUSE_ALLOC_PAGES_MAX
value|(((16UL * 1024UL * 1024UL) + PAGE_SIZE - 1) / PAGE_SIZE)
end_define

begin_struct_decl
struct_decl|struct
name|cuse_dev
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|cuse_data_chunk
block|{
name|unsigned
name|long
name|local_ptr
decl_stmt|;
name|unsigned
name|long
name|peer_ptr
decl_stmt|;
name|unsigned
name|long
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cuse_alloc_info
block|{
name|unsigned
name|long
name|page_count
decl_stmt|;
name|unsigned
name|long
name|alloc_nr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cuse_command
block|{
name|struct
name|cuse_dev
modifier|*
name|dev
decl_stmt|;
name|unsigned
name|long
name|fflags
decl_stmt|;
name|unsigned
name|long
name|per_file_handle
decl_stmt|;
name|unsigned
name|long
name|data_pointer
decl_stmt|;
name|unsigned
name|long
name|argument
decl_stmt|;
name|unsigned
name|long
name|command
decl_stmt|;
comment|/* see CUSE_CMD_XXX */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cuse_create_dev
block|{
name|struct
name|cuse_dev
modifier|*
name|dev
decl_stmt|;
name|uid_t
name|user_id
decl_stmt|;
name|gid_t
name|group_id
decl_stmt|;
name|int
name|permissions
decl_stmt|;
name|char
name|devname
index|[
literal|80
index|]
decl_stmt|;
comment|/* /dev/xxxxx */
block|}
struct|;
end_struct

begin_comment
comment|/* Definition of internal IOCTLs for /dev/cuse */
end_comment

begin_define
define|#
directive|define
name|CUSE_IOCTL_GET_COMMAND
value|_IOR('C', 0, struct cuse_command)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_WRITE_DATA
value|_IOW('C', 1, struct cuse_data_chunk)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_READ_DATA
value|_IOW('C', 2, struct cuse_data_chunk)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_SYNC_COMMAND
value|_IOW('C', 3, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_GET_SIG
value|_IOR('C', 4, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_ALLOC_MEMORY
value|_IOW('C', 5, struct cuse_alloc_info)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_FREE_MEMORY
value|_IOW('C', 6, struct cuse_alloc_info)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_SET_PFH
value|_IOW('C', 7, unsigned long)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_CREATE_DEV
value|_IOW('C', 8, struct cuse_create_dev)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_DESTROY_DEV
value|_IOW('C', 9, struct cuse_dev *)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_ALLOC_UNIT
value|_IOR('C',10, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_FREE_UNIT
value|_IOW('C',11, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_SELWAKEUP
value|_IOW('C',12, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_ALLOC_UNIT_BY_ID
value|_IOWR('C',13, int)
end_define

begin_define
define|#
directive|define
name|CUSE_IOCTL_FREE_UNIT_BY_ID
value|_IOWR('C',14, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CUSE_IOCTL_H_ */
end_comment

end_unit

