begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_backend_block.h#1 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer driver backend interface for block devices.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_BACKEND_BLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_BACKEND_BLOCK_H_
end_define

begin_struct
struct|struct
name|ctl_block_disk
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* interface version */
name|uint32_t
name|disknum
decl_stmt|;
comment|/* returned device number */
name|STAILQ_ENTRY
argument_list|(
argument|ctl_block_disk
argument_list|)
name|links
expr_stmt|;
comment|/* linked list pointer */
name|char
name|disk_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* name of this device */
name|int
name|allocated
decl_stmt|;
comment|/* disk is allocated to a LUN */
name|uint64_t
name|size_blocks
decl_stmt|;
comment|/* disk size in blocks */
name|uint64_t
name|size_bytes
decl_stmt|;
comment|/* disk size in bytes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_BLOCK_DEVLIST_MORE
block|,
name|CTL_BLOCK_DEVLIST_DONE
block|}
name|ctl_block_devlist_status
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_block_devlist
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* interface version */
name|uint32_t
name|buf_len
decl_stmt|;
comment|/* passed in, buffer length */
name|uint32_t
name|ctl_disk_size
decl_stmt|;
comment|/* size of adddev, passed in */
name|struct
name|ctl_block_disk
modifier|*
name|devbuf
decl_stmt|;
comment|/* buffer passed in/filled out*/
name|uint32_t
name|num_bufs
decl_stmt|;
comment|/* number passed out */
name|uint32_t
name|buf_used
decl_stmt|;
comment|/* bytes passed out */
name|uint32_t
name|total_disks
decl_stmt|;
comment|/* number of disks in system */
name|ctl_block_devlist_status
name|status
decl_stmt|;
comment|/* did we get the whole list? */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CTL_BLOCK_ADDDEV
value|_IOWR(COPAN_ARRAY_BE_BLOCK, 0x00, struct ctl_block_disk)
end_define

begin_define
define|#
directive|define
name|CTL_BLOCK_DEVLIST
value|_IOWR(COPAN_ARRAY_BE_BLOCK, 0x01, struct ctl_block_devlist)
end_define

begin_define
define|#
directive|define
name|CTL_BLOCK_RMDEV
value|_IOW(COPAN_ARRAY_BE_BLOCK, 0x02, struct ctl_block_disk)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_BACKEND_BLOCK_H_ */
end_comment

end_unit

