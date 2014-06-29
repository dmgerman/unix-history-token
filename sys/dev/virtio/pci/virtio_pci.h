begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright IBM Corp. 2007  *  * Authors:  *  Anthony Liguori<aliguori@us.ibm.com>  *  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of IBM nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_PCI_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_PCI_H
end_define

begin_comment
comment|/* VirtIO PCI vendor/device ID. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_VENDORID
value|0x1AF4
end_define

begin_define
define|#
directive|define
name|VIRTIO_PCI_DEVICEID_MIN
value|0x1000
end_define

begin_define
define|#
directive|define
name|VIRTIO_PCI_DEVICEID_MAX
value|0x103F
end_define

begin_comment
comment|/* VirtIO ABI version, this must match exactly. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_ABI_VERSION
value|0
end_define

begin_comment
comment|/*  * VirtIO Header, located in BAR 0.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_HOST_FEATURES
value|0
end_define

begin_comment
comment|/* host's supported features (32bit, RO)*/
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_GUEST_FEATURES
value|4
end_define

begin_comment
comment|/* guest's supported features (32, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_QUEUE_PFN
value|8
end_define

begin_comment
comment|/* physical address of VQ (32, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_QUEUE_NUM
value|12
end_define

begin_comment
comment|/* number of ring entries (16, RO) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_QUEUE_SEL
value|14
end_define

begin_comment
comment|/* current VQ selection (16, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_QUEUE_NOTIFY
value|16
end_define

begin_comment
comment|/* notify host regarding VQ (16, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_STATUS
value|18
end_define

begin_comment
comment|/* device status register (8, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_ISR
value|19
end_define

begin_comment
comment|/* interrupt status register, reading 				      * also clears the register (8, RO) */
end_comment

begin_comment
comment|/* Only if MSIX is enabled: */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MSI_CONFIG_VECTOR
value|20
end_define

begin_comment
comment|/* configuration change vector (16, RW) */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MSI_QUEUE_VECTOR
value|22
end_define

begin_comment
comment|/* vector for selected VQ notifications 					(16, RW) */
end_comment

begin_comment
comment|/* The bit of the ISR which indicates a device has an interrupt. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_ISR_INTR
value|0x1
end_define

begin_comment
comment|/* The bit of the ISR which indicates a device configuration change. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_ISR_CONFIG
value|0x2
end_define

begin_comment
comment|/* Vector value used to disable MSI for queue. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_MSI_NO_VECTOR
value|0xFFFF
end_define

begin_comment
comment|/*  * The remaining space is defined by each driver as the per-driver  * configuration space.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_CONFIG_OFF
parameter_list|(
name|msix_enabled
parameter_list|)
value|((msix_enabled) ? 24 : 20)
end_define

begin_comment
comment|/*  * How many bits to shift physical queue address written to QUEUE_PFN.  * 12 is historical, and due to x86 page size.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_QUEUE_ADDR_SHIFT
value|12
end_define

begin_comment
comment|/* The alignment to use between consumer and producer parts of vring. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_PCI_VRING_ALIGN
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_PCI_H */
end_comment

end_unit

