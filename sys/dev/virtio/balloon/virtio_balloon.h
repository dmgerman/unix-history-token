begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of IBM nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_BALLOON_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_BALLOON_H
end_define

begin_comment
comment|/* Feature bits. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_F_MUST_TELL_HOST
value|0x1
end_define

begin_comment
comment|/* Tell before reclaiming pages */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_F_STATS_VQ
value|0x2
end_define

begin_comment
comment|/* Memory stats virtqueue */
end_comment

begin_comment
comment|/* Size of a PFN in the balloon interface. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_PFN_SHIFT
value|12
end_define

begin_struct
struct|struct
name|virtio_balloon_config
block|{
comment|/* Number of pages host wants Guest to give up. */
name|uint32_t
name|num_pages
decl_stmt|;
comment|/* Number of pages we've actually got in balloon. */
name|uint32_t
name|actual
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_SWAP_IN
value|0
end_define

begin_comment
comment|/* Amount of memory swapped in */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_SWAP_OUT
value|1
end_define

begin_comment
comment|/* Amount of memory swapped out */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MAJFLT
value|2
end_define

begin_comment
comment|/* Number of major faults */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MINFLT
value|3
end_define

begin_comment
comment|/* Number of minor faults */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MEMFREE
value|4
end_define

begin_comment
comment|/* Total amount of free memory */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_MEMTOT
value|5
end_define

begin_comment
comment|/* Total amount of memory */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BALLOON_S_NR
value|6
end_define

begin_struct
struct|struct
name|virtio_balloon_stat
block|{
name|uint16_t
name|tag
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_BALLOON_H */
end_comment

end_unit

