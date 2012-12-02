begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2009-2012 Semihalf  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_NAND_CDEV_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_NAND_CDEV_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_struct
struct|struct
name|nand_raw_rw
block|{
name|off_t
name|off
decl_stmt|;
name|off_t
name|len
decl_stmt|;
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|nand_oob_rw
block|{
name|uint32_t
name|page
decl_stmt|;
name|off_t
name|len
decl_stmt|;
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
name|NAND_IOCTL_GROUP
value|'N'
end_define

begin_define
define|#
directive|define
name|NAND_IO_ERASE
value|_IOWR(NAND_IOCTL_GROUP, 0x0, off_t[2])
end_define

begin_define
define|#
directive|define
name|NAND_IO_OOB_READ
value|_IOWR(NAND_IOCTL_GROUP, 0x1, struct nand_oob_rw)
end_define

begin_define
define|#
directive|define
name|NAND_IO_OOB_PROG
value|_IOWR(NAND_IOCTL_GROUP, 0x2, struct nand_oob_rw)
end_define

begin_define
define|#
directive|define
name|NAND_IO_RAW_READ
value|_IOWR(NAND_IOCTL_GROUP, 0x3, struct nand_raw_rw)
end_define

begin_define
define|#
directive|define
name|NAND_IO_RAW_PROG
value|_IOWR(NAND_IOCTL_GROUP, 0x4, struct nand_raw_rw)
end_define

begin_define
define|#
directive|define
name|NAND_IO_GET_STATUS
value|_IOWR(NAND_IOCTL_GROUP, 0x5, uint8_t)
end_define

begin_struct
struct|struct
name|page_stat_io
block|{
name|uint32_t
name|page_num
decl_stmt|;
name|uint32_t
name|page_read
decl_stmt|;
name|uint32_t
name|page_written
decl_stmt|;
name|uint32_t
name|page_raw_read
decl_stmt|;
name|uint32_t
name|page_raw_written
decl_stmt|;
name|uint32_t
name|ecc_succeded
decl_stmt|;
name|uint32_t
name|ecc_corrected
decl_stmt|;
name|uint32_t
name|ecc_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAND_IO_PAGE_STAT
value|_IOWR(NAND_IOCTL_GROUP, 0x6, \     struct page_stat_io)
end_define

begin_struct
struct|struct
name|block_stat_io
block|{
name|uint32_t
name|block_num
decl_stmt|;
name|uint32_t
name|block_erased
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAND_IO_BLOCK_STAT
value|_IOWR(NAND_IOCTL_GROUP, 0x7, \     struct block_stat_io)
end_define

begin_struct
struct|struct
name|chip_param_io
block|{
name|uint32_t
name|page_size
decl_stmt|;
name|uint32_t
name|oob_size
decl_stmt|;
name|uint32_t
name|blocks
decl_stmt|;
name|uint32_t
name|pages_per_block
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NAND_IO_GET_CHIP_PARAM
value|_IOWR(NAND_IOCTL_GROUP, 0x8, \     struct chip_param_io)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_NAND_CDEV_H_ */
end_comment

end_unit

