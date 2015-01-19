begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_MMIO_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_MMIO_H
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_MAGIC_VALUE
value|0x000
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_VERSION
value|0x004
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_DEVICE_ID
value|0x008
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_MAGIC_VALUE
value|0x000
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_VERSION
value|0x004
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_DEVICE_ID
value|0x008
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_VENDOR_ID
value|0x00c
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_HOST_FEATURES
value|0x010
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_HOST_FEATURES_SEL
value|0x014
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_GUEST_FEATURES
value|0x020
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_GUEST_FEATURES_SEL
value|0x024
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_GUEST_PAGE_SIZE
value|0x028
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_SEL
value|0x030
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_NUM_MAX
value|0x034
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_NUM
value|0x038
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_ALIGN
value|0x03c
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_PFN
value|0x040
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_QUEUE_NOTIFY
value|0x050
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_INTERRUPT_STATUS
value|0x060
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_INTERRUPT_ACK
value|0x064
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_STATUS
value|0x070
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_CONFIG
value|0x100
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_INT_VRING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_INT_CONFIG
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VIRTIO_MMIO_VRING_ALIGN
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_MMIO_H */
end_comment

end_unit

