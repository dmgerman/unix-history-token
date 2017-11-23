begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2006 Michael Lorenz  * Copyright (c) 2008 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_CUDAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_CUDAVAR_H_
end_define

begin_define
define|#
directive|define
name|CUDA_DEVSTR
value|"Apple CUDA I/O Controller"
end_define

begin_define
define|#
directive|define
name|CUDA_MAXPACKETS
value|10
end_define

begin_comment
comment|/* Cuda addresses */
end_comment

begin_define
define|#
directive|define
name|CUDA_ADB
value|0
end_define

begin_define
define|#
directive|define
name|CUDA_PSEUDO
value|1
end_define

begin_define
define|#
directive|define
name|CUDA_ERROR
value|2
end_define

begin_comment
comment|/* error codes? */
end_comment

begin_define
define|#
directive|define
name|CUDA_TIMER
value|3
end_define

begin_define
define|#
directive|define
name|CUDA_POWER
value|4
end_define

begin_define
define|#
directive|define
name|CUDA_IIC
value|5
end_define

begin_comment
comment|/* XXX ??? */
end_comment

begin_define
define|#
directive|define
name|CUDA_PMU
value|6
end_define

begin_define
define|#
directive|define
name|CUDA_ADB_QUERY
value|7
end_define

begin_comment
comment|/* Cuda commands */
end_comment

begin_define
define|#
directive|define
name|CMD_AUTOPOLL
value|1
end_define

begin_define
define|#
directive|define
name|CMD_READ_RTC
value|3
end_define

begin_define
define|#
directive|define
name|CMD_WRITE_RTC
value|9
end_define

begin_define
define|#
directive|define
name|CMD_POWEROFF
value|10
end_define

begin_define
define|#
directive|define
name|CMD_RESET
value|17
end_define

begin_define
define|#
directive|define
name|CMD_IIC
value|34
end_define

begin_comment
comment|/* Cuda state codes */
end_comment

begin_define
define|#
directive|define
name|CUDA_NOTREADY
value|0x1
end_define

begin_comment
comment|/* has not been initialized yet */
end_comment

begin_define
define|#
directive|define
name|CUDA_IDLE
value|0x2
end_define

begin_comment
comment|/* the bus is currently idle */
end_comment

begin_define
define|#
directive|define
name|CUDA_OUT
value|0x3
end_define

begin_comment
comment|/* sending out a command */
end_comment

begin_define
define|#
directive|define
name|CUDA_IN
value|0x4
end_define

begin_comment
comment|/* receiving data */
end_comment

begin_define
define|#
directive|define
name|CUDA_POLLING
value|0x5
end_define

begin_comment
comment|/* polling - II only */
end_comment

begin_struct
struct|struct
name|cuda_packet
block|{
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|data
index|[
literal|253
index|]
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|cuda_packet
argument_list|)
name|pkt_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cuda_pktq
argument_list|,
name|cuda_packet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|cuda_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|sc_memrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_memr
decl_stmt|;
name|int
name|sc_irqrid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|struct
name|mtx
name|sc_mutex
decl_stmt|;
name|device_t
name|adb_bus
decl_stmt|;
name|int
name|sc_node
decl_stmt|;
specifier|volatile
name|int
name|sc_state
decl_stmt|;
name|int
name|sc_waiting
decl_stmt|;
name|int
name|sc_polling
decl_stmt|;
name|int
name|sc_iic_done
decl_stmt|;
specifier|volatile
name|int
name|sc_autopoll
decl_stmt|;
name|uint32_t
name|sc_rtc
decl_stmt|;
name|int
name|sc_i2c_read_len
decl_stmt|;
comment|/* internal buffers */
name|uint8_t
name|sc_in
index|[
literal|256
index|]
decl_stmt|;
name|uint8_t
name|sc_out
index|[
literal|256
index|]
decl_stmt|;
name|int
name|sc_sent
decl_stmt|;
name|int
name|sc_out_length
decl_stmt|;
name|int
name|sc_received
decl_stmt|;
name|struct
name|cuda_packet
name|sc_pkts
index|[
name|CUDA_MAXPACKETS
index|]
decl_stmt|;
name|struct
name|cuda_pktq
name|sc_inq
decl_stmt|;
name|struct
name|cuda_pktq
name|sc_outq
decl_stmt|;
name|struct
name|cuda_pktq
name|sc_freeq
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_CUDAVAR_H_ */
end_comment

end_unit

