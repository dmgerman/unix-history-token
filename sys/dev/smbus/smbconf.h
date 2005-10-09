begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SMBONF_H
end_ifndef

begin_define
define|#
directive|define
name|__SMBONF_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_define
define|#
directive|define
name|SMBPRI
value|(PZERO+8)
end_define

begin_comment
comment|/* XXX sleep/wakeup queue priority */
end_comment

begin_define
define|#
directive|define
name|n
parameter_list|(
name|flags
parameter_list|)
value|(~(flags)& (flags))
end_define

begin_comment
comment|/*  * How tsleep() is called in smb_request_bus().  */
end_comment

begin_define
define|#
directive|define
name|SMB_DONTWAIT
value|0
end_define

begin_define
define|#
directive|define
name|SMB_NOINTR
value|0
end_define

begin_define
define|#
directive|define
name|SMB_WAIT
value|0x1
end_define

begin_define
define|#
directive|define
name|SMB_INTR
value|0x2
end_define

begin_comment
comment|/*  * callback index  */
end_comment

begin_define
define|#
directive|define
name|SMB_REQUEST_BUS
value|0x1
end_define

begin_define
define|#
directive|define
name|SMB_RELEASE_BUS
value|0x2
end_define

begin_comment
comment|/*  * SMB bus errors  */
end_comment

begin_define
define|#
directive|define
name|SMB_ENOERR
value|0x0
end_define

begin_define
define|#
directive|define
name|SMB_EBUSERR
value|0x1
end_define

begin_define
define|#
directive|define
name|SMB_ENOTSUPP
value|0x2
end_define

begin_define
define|#
directive|define
name|SMB_ENOACK
value|0x4
end_define

begin_define
define|#
directive|define
name|SMB_ECOLLI
value|0x8
end_define

begin_define
define|#
directive|define
name|SMB_EABORT
value|0x10
end_define

begin_define
define|#
directive|define
name|SMB_ETIMEOUT
value|0x20
end_define

begin_define
define|#
directive|define
name|SMB_EBUSY
value|0x40
end_define

begin_comment
comment|/*  * How Quick command is executed  */
end_comment

begin_define
define|#
directive|define
name|SMB_QWRITE
value|0x0
end_define

begin_define
define|#
directive|define
name|SMB_QREAD
value|0x1
end_define

begin_comment
comment|/*  * ivars codes  */
end_comment

begin_define
define|#
directive|define
name|SMBUS_IVAR_ADDR
value|0x1
end_define

begin_comment
comment|/* I2C address of the device */
end_comment

begin_function_decl
specifier|extern
name|int
name|smbus_request_bus
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smbus_release_bus
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|device_t
name|smbus_alloc_bus
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smbus_error
parameter_list|(
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|smbus_intr
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|char
name|low
parameter_list|,
name|char
name|high
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_char
name|smbus_get_addr
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|smbus_quick
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|how
parameter_list|)
define|\
value|(SMBUS_QUICK(device_get_parent(bus), slave, how))
end_define

begin_define
define|#
directive|define
name|smbus_sendb
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|byte
parameter_list|)
define|\
value|(SMBUS_SENDB(device_get_parent(bus), slave, byte))
end_define

begin_define
define|#
directive|define
name|smbus_recvb
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|byte
parameter_list|)
define|\
value|(SMBUS_RECVB(device_get_parent(bus), slave, byte))
end_define

begin_define
define|#
directive|define
name|smbus_writeb
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|byte
parameter_list|)
define|\
value|(SMBUS_WRITEB(device_get_parent(bus), slave, cmd, byte))
end_define

begin_define
define|#
directive|define
name|smbus_writew
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|word
parameter_list|)
define|\
value|(SMBUS_WRITEW(device_get_parent(bus), slave, cmd, word))
end_define

begin_define
define|#
directive|define
name|smbus_readb
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|byte
parameter_list|)
define|\
value|(SMBUS_READB(device_get_parent(bus), slave, cmd, byte))
end_define

begin_define
define|#
directive|define
name|smbus_readw
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|word
parameter_list|)
define|\
value|(SMBUS_READW(device_get_parent(bus), slave, cmd, word))
end_define

begin_define
define|#
directive|define
name|smbus_pcall
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|sdata
parameter_list|,
name|rdata
parameter_list|)
define|\
value|(SMBUS_PCALL(device_get_parent(bus), slave, cmd, sdata, rdata))
end_define

begin_define
define|#
directive|define
name|smbus_bwrite
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|count
parameter_list|,
name|buf
parameter_list|)
define|\
value|(SMBUS_BWRITE(device_get_parent(bus), slave, cmd, count, buf))
end_define

begin_define
define|#
directive|define
name|smbus_bread
parameter_list|(
name|bus
parameter_list|,
name|slave
parameter_list|,
name|cmd
parameter_list|,
name|count
parameter_list|,
name|buf
parameter_list|)
define|\
value|(SMBUS_BREAD(device_get_parent(bus), slave, cmd, count, buf))
end_define

begin_define
define|#
directive|define
name|SMBUS_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|SMBUS_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|SMBUS_MAXVER
value|1
end_define

begin_define
define|#
directive|define
name|SMBUS_PREFVER
value|SMBUS_MODVER
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

