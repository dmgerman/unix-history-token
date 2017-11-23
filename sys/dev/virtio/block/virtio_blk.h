begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of IBM nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  *  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_BLK_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_BLK_H
end_define

begin_comment
comment|/* Feature bits */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_BARRIER
value|0x0001
end_define

begin_comment
comment|/* Does host support barriers? */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_SIZE_MAX
value|0x0002
end_define

begin_comment
comment|/* Indicates maximum segment size */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_SEG_MAX
value|0x0004
end_define

begin_comment
comment|/* Indicates maximum # of segments */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_GEOMETRY
value|0x0010
end_define

begin_comment
comment|/* Legacy geometry available  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_RO
value|0x0020
end_define

begin_comment
comment|/* Disk is read-only */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_BLK_SIZE
value|0x0040
end_define

begin_comment
comment|/* Block size of disk is available*/
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_SCSI
value|0x0080
end_define

begin_comment
comment|/* Supports scsi command passthru */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_WCE
value|0x0200
end_define

begin_comment
comment|/* Writeback mode enabled after reset */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_TOPOLOGY
value|0x0400
end_define

begin_comment
comment|/* Topology information is available */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_F_CONFIG_WCE
value|0x0800
end_define

begin_comment
comment|/* Writeback mode available in config */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_ID_BYTES
value|20
end_define

begin_comment
comment|/* ID string length */
end_comment

begin_struct
struct|struct
name|virtio_blk_config
block|{
comment|/* The capacity (in 512-byte sectors). */
name|uint64_t
name|capacity
decl_stmt|;
comment|/* The maximum segment size (if VIRTIO_BLK_F_SIZE_MAX) */
name|uint32_t
name|size_max
decl_stmt|;
comment|/* The maximum number of segments (if VIRTIO_BLK_F_SEG_MAX) */
name|uint32_t
name|seg_max
decl_stmt|;
comment|/* Geometry of the device (if VIRTIO_BLK_F_GEOMETRY) */
struct|struct
name|virtio_blk_geometry
block|{
name|uint16_t
name|cylinders
decl_stmt|;
name|uint8_t
name|heads
decl_stmt|;
name|uint8_t
name|sectors
decl_stmt|;
block|}
name|geometry
struct|;
comment|/* Block size of device (if VIRTIO_BLK_F_BLK_SIZE) */
name|uint32_t
name|blk_size
decl_stmt|;
comment|/* Topology of the device (if VIRTIO_BLK_F_TOPOLOGY) */
struct|struct
name|virtio_blk_topology
block|{
name|uint8_t
name|physical_block_exp
decl_stmt|;
name|uint8_t
name|alignment_offset
decl_stmt|;
name|uint16_t
name|min_io_size
decl_stmt|;
name|uint32_t
name|opt_io_size
decl_stmt|;
block|}
name|topology
struct|;
comment|/* Writeback mode (if VIRTIO_BLK_F_CONFIG_WCE) */
name|uint8_t
name|writeback
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Command types  *  * Usage is a bit tricky as some bits are used as flags and some are not.  *  * Rules:  *   VIRTIO_BLK_T_OUT may be combined with VIRTIO_BLK_T_SCSI_CMD or  *   VIRTIO_BLK_T_BARRIER.  VIRTIO_BLK_T_FLUSH is a command of its own  *   and may not be combined with any of the other flags.  */
end_comment

begin_comment
comment|/* These two define direction. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_IN
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_OUT
value|1
end_define

begin_comment
comment|/* This bit says it's a scsi command, not an actual read or write. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_SCSI_CMD
value|2
end_define

begin_comment
comment|/* Cache flush command */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_FLUSH
value|4
end_define

begin_comment
comment|/* Get device ID command */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_GET_ID
value|8
end_define

begin_comment
comment|/* Barrier before this op. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_T_BARRIER
value|0x80000000
end_define

begin_comment
comment|/* ID string length */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_ID_BYTES
value|20
end_define

begin_comment
comment|/* This is the first element of the read scatter-gather list. */
end_comment

begin_struct
struct|struct
name|virtio_blk_outhdr
block|{
comment|/* VIRTIO_BLK_T* */
name|uint32_t
name|type
decl_stmt|;
comment|/* io priority. */
name|uint32_t
name|ioprio
decl_stmt|;
comment|/* Sector (ie. 512 byte offset) */
name|uint64_t
name|sector
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|virtio_scsi_inhdr
block|{
name|uint32_t
name|errors
decl_stmt|;
name|uint32_t
name|data_len
decl_stmt|;
name|uint32_t
name|sense_len
decl_stmt|;
name|uint32_t
name|residual
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* And this is the final byte of the write scatter-gather list. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_BLK_S_OK
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_BLK_S_IOERR
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_BLK_S_UNSUPP
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_BLK_H */
end_comment

end_unit

