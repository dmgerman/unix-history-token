begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 2001 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IICONF_H
end_ifndef

begin_define
define|#
directive|define
name|__IICONF_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<dev/iicbus/iic.h>
end_include

begin_define
define|#
directive|define
name|IICPRI
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

begin_define
define|#
directive|define
name|LSB
value|0x1
end_define

begin_comment
comment|/*  * How tsleep() is called in iic_request_bus().  */
end_comment

begin_define
define|#
directive|define
name|IIC_DONTWAIT
value|0
end_define

begin_define
define|#
directive|define
name|IIC_NOINTR
value|0
end_define

begin_define
define|#
directive|define
name|IIC_WAIT
value|0x1
end_define

begin_define
define|#
directive|define
name|IIC_INTR
value|0x2
end_define

begin_comment
comment|/*  * i2c modes  */
end_comment

begin_define
define|#
directive|define
name|IIC_MASTER
value|0x1
end_define

begin_define
define|#
directive|define
name|IIC_SLAVE
value|0x2
end_define

begin_define
define|#
directive|define
name|IIC_POLLED
value|0x4
end_define

begin_comment
comment|/*  * i2c speed  */
end_comment

begin_define
define|#
directive|define
name|IIC_UNKNOWN
value|0x0
end_define

begin_define
define|#
directive|define
name|IIC_SLOW
value|0x1
end_define

begin_define
define|#
directive|define
name|IIC_FAST
value|0x2
end_define

begin_define
define|#
directive|define
name|IIC_FASTEST
value|0x3
end_define

begin_define
define|#
directive|define
name|IIC_LAST_READ
value|0x1
end_define

begin_comment
comment|/*  * callback index  */
end_comment

begin_define
define|#
directive|define
name|IIC_REQUEST_BUS
value|0x1
end_define

begin_define
define|#
directive|define
name|IIC_RELEASE_BUS
value|0x2
end_define

begin_comment
comment|/*  * interrupt events  */
end_comment

begin_define
define|#
directive|define
name|INTR_GENERAL
value|0x1
end_define

begin_comment
comment|/* general call received */
end_comment

begin_define
define|#
directive|define
name|INTR_START
value|0x2
end_define

begin_comment
comment|/* the I2C interface is addressed */
end_comment

begin_define
define|#
directive|define
name|INTR_STOP
value|0x3
end_define

begin_comment
comment|/* stop condition received */
end_comment

begin_define
define|#
directive|define
name|INTR_RECEIVE
value|0x4
end_define

begin_comment
comment|/* character received */
end_comment

begin_define
define|#
directive|define
name|INTR_TRANSMIT
value|0x5
end_define

begin_comment
comment|/* character to transmit */
end_comment

begin_define
define|#
directive|define
name|INTR_ERROR
value|0x6
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|INTR_NOACK
value|0x7
end_define

begin_comment
comment|/* no ack from master receiver */
end_comment

begin_comment
comment|/*  * adapter layer errors  */
end_comment

begin_define
define|#
directive|define
name|IIC_NOERR
value|0x0
end_define

begin_comment
comment|/* no error occured */
end_comment

begin_define
define|#
directive|define
name|IIC_EBUSERR
value|0x1
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|IIC_ENOACK
value|0x2
end_define

begin_comment
comment|/* ack not received until timeout */
end_comment

begin_define
define|#
directive|define
name|IIC_ETIMEOUT
value|0x3
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|IIC_EBUSBSY
value|0x4
end_define

begin_comment
comment|/* bus busy */
end_comment

begin_define
define|#
directive|define
name|IIC_ESTATUS
value|0x5
end_define

begin_comment
comment|/* status error */
end_comment

begin_define
define|#
directive|define
name|IIC_EUNDERFLOW
value|0x6
end_define

begin_comment
comment|/* slave ready for more data */
end_comment

begin_define
define|#
directive|define
name|IIC_EOVERFLOW
value|0x7
end_define

begin_comment
comment|/* too much data */
end_comment

begin_define
define|#
directive|define
name|IIC_ENOTSUPP
value|0x8
end_define

begin_comment
comment|/* request not supported */
end_comment

begin_define
define|#
directive|define
name|IIC_ENOADDR
value|0x9
end_define

begin_comment
comment|/* no address assigned to the interface */
end_comment

begin_comment
comment|/*  * ivars codes  */
end_comment

begin_define
define|#
directive|define
name|IICBUS_IVAR_ADDR
value|0x1
end_define

begin_comment
comment|/* I2C address of the device */
end_comment

begin_function_decl
specifier|extern
name|int
name|iicbus_request_bus
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
name|iicbus_release_bus
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
name|iicbus_alloc_bus
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iicbus_intr
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_null_repeated_start
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_null_callback
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|iicbus_reset
parameter_list|(
name|bus
parameter_list|,
name|speed
parameter_list|,
name|addr
parameter_list|,
name|oldaddr
parameter_list|)
define|\
value|(IICBUS_RESET(device_get_parent(bus), speed, addr, oldaddr))
end_define

begin_comment
comment|/* basic I2C operations */
end_comment

begin_function_decl
specifier|extern
name|int
name|iicbus_started
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_start
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_stop
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_repeated_start
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_write
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_read
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* single byte read/write functions, start/stop not managed */
end_comment

begin_function_decl
specifier|extern
name|int
name|iicbus_write_byte
parameter_list|(
name|device_t
parameter_list|,
name|char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_read_byte
parameter_list|(
name|device_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read/write operations with start/stop conditions managed */
end_comment

begin_function_decl
specifier|extern
name|int
name|iicbus_block_write
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|iicbus_block_read
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_char
name|iicbus_get_addr
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vectors of iic operations to pass to bridge */
end_comment

begin_function_decl
name|int
name|iicbus_transfer
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|struct
name|iic_msg
modifier|*
name|msgs
parameter_list|,
name|uint32_t
name|nmsgs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iicbus_transfer_gen
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|struct
name|iic_msg
modifier|*
name|msgs
parameter_list|,
name|uint32_t
name|nmsgs
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IICBUS_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBUS_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBUS_MAXVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBUS_PREFVER
value|IICBUS_MODVER
end_define

begin_decl_stmt
specifier|extern
name|driver_t
name|iicbb_driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|iicbb_devclass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IICBB_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBB_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBB_MAXVER
value|1
end_define

begin_define
define|#
directive|define
name|IICBB_PREFVER
value|IICBB_MODVER
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

