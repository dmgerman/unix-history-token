begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_H_
end_define

begin_define
define|#
directive|define
name|VRING_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_NEXT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_WRITE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VRING_DESC_F_INDIRECT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VRING_AVAIL_F_NO_INTERRUPT
value|1
end_define

begin_struct
struct|struct
name|virtio_desc
block|{
name|uint64_t
name|vd_addr
decl_stmt|;
name|uint32_t
name|vd_len
decl_stmt|;
name|uint16_t
name|vd_flags
decl_stmt|;
name|uint16_t
name|vd_next
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|virtio_used
block|{
name|uint32_t
name|vu_idx
decl_stmt|;
name|uint32_t
name|vu_tlen
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * PFN register shift amount  */
end_comment

begin_define
define|#
directive|define
name|VRING_PFN
value|12
end_define

begin_comment
comment|/*  * Virtio device types  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_TYPE_NET
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_TYPE_BLOCK
value|2
end_define

begin_comment
comment|/*  * PCI vendor/device IDs  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_VENDOR
value|0x1AF4
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_NET
value|0x1000
end_define

begin_define
define|#
directive|define
name|VIRTIO_DEV_BLOCK
value|0x1001
end_define

begin_comment
comment|/*  * PCI config space constants  */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_HOSTCAP
value|0
end_define

begin_define
define|#
directive|define
name|VTCFG_R_GUESTCAP
value|4
end_define

begin_define
define|#
directive|define
name|VTCFG_R_PFN
value|8
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QNUM
value|12
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QSEL
value|14
end_define

begin_define
define|#
directive|define
name|VTCFG_R_QNOTIFY
value|16
end_define

begin_define
define|#
directive|define
name|VTCFG_R_STATUS
value|18
end_define

begin_define
define|#
directive|define
name|VTCFG_R_ISR
value|19
end_define

begin_define
define|#
directive|define
name|VTCFG_R_CFG0
value|20
end_define

begin_comment
comment|/* No MSI-X */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_CFG1
value|24
end_define

begin_comment
comment|/* With MSI-X */
end_comment

begin_define
define|#
directive|define
name|VTCFG_R_MSIX
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_H_ */
end_comment

end_unit

