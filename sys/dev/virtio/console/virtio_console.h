begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This header is BSD licensed so anyone can use the definitions to implement  * compatible drivers/servers.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of IBM nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL IBM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Copyright (C) Red Hat, Inc., 2009, 2010, 2011  * Copyright (C) Amit Shah<amit.shah@redhat.com>, 2009, 2010, 2011  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_CONSOLE_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_CONSOLE_H
end_define

begin_comment
comment|/* Feature bits */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_F_SIZE
value|0x01
end_define

begin_comment
comment|/* Console size */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_F_MULTIPORT
value|0x02
end_define

begin_comment
comment|/* Multiple ports */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_F_EMERG_WRITE
value|0x04
end_define

begin_comment
comment|/* Emergency write */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_BAD_ID
value|(~(uint32_t)0)
end_define

begin_struct
struct|struct
name|virtio_console_config
block|{
comment|/* colums of the screens */
name|uint16_t
name|cols
decl_stmt|;
comment|/* rows of the screens */
name|uint16_t
name|rows
decl_stmt|;
comment|/* max. number of ports this device can hold */
name|uint32_t
name|max_nr_ports
decl_stmt|;
comment|/* emergency write register */
name|uint32_t
name|emerg_wr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * A message that's passed between the Host and the Guest for a  * particular port.  */
end_comment

begin_struct
struct|struct
name|virtio_console_control
block|{
name|uint32_t
name|id
decl_stmt|;
comment|/* Port number */
name|uint16_t
name|event
decl_stmt|;
comment|/* The kind of control event (see below) */
name|uint16_t
name|value
decl_stmt|;
comment|/* Extra information for the key */
block|}
struct|;
end_struct

begin_comment
comment|/* Some events for control messages */
end_comment

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_DEVICE_READY
value|0
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_PORT_ADD
value|1
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_PORT_REMOVE
value|2
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_PORT_READY
value|3
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_CONSOLE_PORT
value|4
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_RESIZE
value|5
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_PORT_OPEN
value|6
end_define

begin_define
define|#
directive|define
name|VIRTIO_CONSOLE_PORT_NAME
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_CONSOLE_H */
end_comment

end_unit

