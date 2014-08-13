begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of IBM nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_CONFIG_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_CONFIG_H_
end_define

begin_comment
comment|/* Status byte for guest to report progress. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_DRIVER
value|0x03
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_DRIVER_OK
value|0x04
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONFIG_STATUS_FAILED
value|0x80
end_define

begin_comment
comment|/*  * Generate interrupt when the virtqueue ring is  * completely used, even if we've suppressed them.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_F_NOTIFY_ON_EMPTY
value|(1<< 24)
end_define

begin_comment
comment|/* Support for indirect buffer descriptors. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_RING_F_INDIRECT_DESC
value|(1<< 28)
end_define

begin_comment
comment|/* Support to suppress interrupt until specific index is reached. */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_RING_F_EVENT_IDX
value|(1<< 29)
end_define

begin_comment
comment|/*  * The guest should never negotiate this feature; it  * is used to detect faulty drivers.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_F_BAD_FEATURE
value|(1<< 30)
end_define

begin_comment
comment|/*  * Some VirtIO feature bits (currently bits 28 through 31) are  * reserved for the transport being used (eg. virtio_ring), the  * rest are per-device feature bits.  */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_TRANSPORT_F_START
value|28
end_define

begin_define
define|#
directive|define
name|VIRTIO_TRANSPORT_F_END
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_CONFIG_H_ */
end_comment

end_unit

