begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2008 Yahoo!, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * LSI MPT-Fusion Host Adapter FreeBSD userland interface  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPT_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MPT_IOCTL_H_
end_define

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_type.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi.h>
end_include

begin_include
include|#
directive|include
file|<dev/mpt/mpilib/mpi_cnfg.h>
end_include

begin_comment
comment|/*  * For the read header requests, the header should include the page  * type or extended page type, page number, and page version.  The  * buffer and length are unused.  The completed header is returned in  * the 'header' member.  *  * For the read page and write page requests, 'buf' should point to a  * buffer of 'len' bytes which holds the entire page (including the  * header).  *  * All requests specify the page address in 'page_address'.  */
end_comment

begin_struct
struct|struct
name|mpt_cfg_page_req
block|{
name|CONFIG_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_ext_cfg_page_req
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_raid_action
block|{
name|uint8_t
name|action
decl_stmt|;
name|uint8_t
name|volume_bus
decl_stmt|;
name|uint8_t
name|volume_id
decl_stmt|;
name|uint8_t
name|phys_disk_num
decl_stmt|;
name|uint32_t
name|action_data_word
decl_stmt|;
name|void
modifier|*
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint32_t
name|volume_status
decl_stmt|;
name|uint32_t
name|action_data
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|action_status
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
name|uint8_t
name|write
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MPTIO_READ_CFG_HEADER
value|_IOWR('M', 100, struct mpt_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_CFG_PAGE
value|_IOWR('M', 101, struct mpt_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_EXT_CFG_HEADER
value|_IOWR('M', 102, struct mpt_ext_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_EXT_CFG_PAGE
value|_IOWR('M', 103, struct mpt_ext_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPTIO_WRITE_CFG_PAGE
value|_IOWR('M', 104, struct mpt_cfg_page_req)
end_define

begin_define
define|#
directive|define
name|MPTIO_RAID_ACTION
value|_IOWR('M', 105, struct mpt_raid_action)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_struct
struct|struct
name|mpt_cfg_page_req32
block|{
name|CONFIG_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|uint32_t
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_ext_cfg_page_req32
block|{
name|CONFIG_EXTENDED_PAGE_HEADER
name|header
decl_stmt|;
name|uint32_t
name|page_address
decl_stmt|;
name|uint32_t
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mpt_raid_action32
block|{
name|uint8_t
name|action
decl_stmt|;
name|uint8_t
name|volume_bus
decl_stmt|;
name|uint8_t
name|volume_id
decl_stmt|;
name|uint8_t
name|phys_disk_num
decl_stmt|;
name|uint32_t
name|action_data_word
decl_stmt|;
name|uint32_t
name|buf
decl_stmt|;
name|int
name|len
decl_stmt|;
name|uint32_t
name|volume_status
decl_stmt|;
name|uint32_t
name|action_data
index|[
literal|4
index|]
decl_stmt|;
name|uint16_t
name|action_status
decl_stmt|;
name|uint16_t
name|ioc_status
decl_stmt|;
name|uint8_t
name|write
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MPTIO_READ_CFG_HEADER32
value|_IOWR('M', 100, struct mpt_cfg_page_req32)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_CFG_PAGE32
value|_IOWR('M', 101, struct mpt_cfg_page_req32)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_EXT_CFG_HEADER32
value|_IOWR('M', 102, struct mpt_ext_cfg_page_req32)
end_define

begin_define
define|#
directive|define
name|MPTIO_READ_EXT_CFG_PAGE32
value|_IOWR('M', 103, struct mpt_ext_cfg_page_req32)
end_define

begin_define
define|#
directive|define
name|MPTIO_WRITE_CFG_PAGE32
value|_IOWR('M', 104, struct mpt_cfg_page_req32)
end_define

begin_define
define|#
directive|define
name|MPTIO_RAID_ACTION32
value|_IOWR('M', 105, struct mpt_raid_action32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MPT_IOCTL_H_ */
end_comment

end_unit

