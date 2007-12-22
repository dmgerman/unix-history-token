begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Nicolas Souchu, Marc Bouget  * Copyright (c) 2004 Joerg Wunsch  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|IO_PCFSIZE
value|2
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|9999
end_define

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/* Status bits of S1 register (read only) */
end_comment

begin_define
define|#
directive|define
name|nBB
value|0x01
end_define

begin_comment
comment|/* busy when low set/reset by STOP/START*/
end_comment

begin_define
define|#
directive|define
name|LAB
value|0x02
end_define

begin_comment
comment|/* lost arbitration bit in multi-master mode */
end_comment

begin_define
define|#
directive|define
name|AAS
value|0x04
end_define

begin_comment
comment|/* addressed as slave */
end_comment

begin_define
define|#
directive|define
name|LRB
value|0x08
end_define

begin_comment
comment|/* last received byte when not AAS */
end_comment

begin_define
define|#
directive|define
name|AD0
value|0x08
end_define

begin_comment
comment|/* general call received when AAS */
end_comment

begin_define
define|#
directive|define
name|BER
value|0x10
end_define

begin_comment
comment|/* bus error, misplaced START or STOP */
end_comment

begin_define
define|#
directive|define
name|STS
value|0x20
end_define

begin_comment
comment|/* STOP detected in slave receiver mode */
end_comment

begin_define
define|#
directive|define
name|PIN
value|0x80
end_define

begin_comment
comment|/* pending interrupt not (r/w) */
end_comment

begin_comment
comment|/* Control bits of S1 register (write only) */
end_comment

begin_define
define|#
directive|define
name|ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|STO
value|0x02
end_define

begin_define
define|#
directive|define
name|STA
value|0x04
end_define

begin_define
define|#
directive|define
name|ENI
value|0x08
end_define

begin_define
define|#
directive|define
name|ES2
value|0x10
end_define

begin_define
define|#
directive|define
name|ES1
value|0x20
end_define

begin_define
define|#
directive|define
name|ESO
value|0x40
end_define

begin_define
define|#
directive|define
name|BUFSIZE
value|2048
end_define

begin_define
define|#
directive|define
name|SLAVE_TRANSMITTER
value|0x1
end_define

begin_define
define|#
directive|define
name|SLAVE_RECEIVER
value|0x2
end_define

begin_define
define|#
directive|define
name|PCF_DEFAULT_ADDR
value|0xaa
end_define

begin_struct
struct|struct
name|pcf_softc
block|{
name|u_char
name|pcf_addr
decl_stmt|;
comment|/* interface I2C address */
name|int
name|pcf_flags
decl_stmt|;
comment|/* IIC_POLLED? */
name|int
name|pcf_slave_mode
decl_stmt|;
comment|/* receiver or transmitter */
name|int
name|pcf_started
decl_stmt|;
comment|/* 1 if start condition sent */
name|device_t
name|iicbus
decl_stmt|;
comment|/* the corresponding iicbus */
comment|/* Resource handling stuff. */
name|struct
name|resource
modifier|*
name|res_ioport
decl_stmt|;
name|int
name|rid_ioport
decl_stmt|;
name|bus_space_tag_t
name|bt_ioport
decl_stmt|;
name|bus_space_handle_t
name|bh_ioport
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_irq
decl_stmt|;
name|int
name|rid_irq
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVTOSOFTC
parameter_list|(
name|dev
parameter_list|)
value|((struct pcf_softc *)device_get_softc(dev))
end_define

begin_comment
comment|/*  * PCF8584 datasheet : when operate at 8 MHz or more, a minimun time of  * 6 clocks cycles must be left between two consecutives access  */
end_comment

begin_define
define|#
directive|define
name|pcf_nops
parameter_list|()
value|DELAY(10)
end_define

begin_define
define|#
directive|define
name|dummy_read
parameter_list|(
name|sc
parameter_list|)
value|pcf_get_S0(sc)
end_define

begin_define
define|#
directive|define
name|dummy_write
parameter_list|(
name|sc
parameter_list|)
value|pcf_set_S0(sc, 0)
end_define

begin_comment
comment|/*  * Specific register access to PCF8584  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|pcf_set_S0
parameter_list|(
name|struct
name|pcf_softc
modifier|*
name|sc
parameter_list|,
name|int
name|data
parameter_list|)
block|{
name|bus_space_write_1
argument_list|(
name|sc
operator|->
name|bt_ioport
argument_list|,
name|sc
operator|->
name|bh_ioport
argument_list|,
literal|0
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|pcf_nops
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|pcf_set_S1
parameter_list|(
name|struct
name|pcf_softc
modifier|*
name|sc
parameter_list|,
name|int
name|data
parameter_list|)
block|{
name|bus_space_write_1
argument_list|(
name|sc
operator|->
name|bt_ioport
argument_list|,
name|sc
operator|->
name|bh_ioport
argument_list|,
literal|1
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|pcf_nops
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|char
name|pcf_get_S0
parameter_list|(
name|struct
name|pcf_softc
modifier|*
name|sc
parameter_list|)
block|{
name|char
name|data
decl_stmt|;
name|data
operator|=
name|bus_space_read_1
argument_list|(
name|sc
operator|->
name|bt_ioport
argument_list|,
name|sc
operator|->
name|bh_ioport
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pcf_nops
argument_list|()
expr_stmt|;
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|char
name|pcf_get_S1
parameter_list|(
name|struct
name|pcf_softc
modifier|*
name|sc
parameter_list|)
block|{
name|char
name|data
decl_stmt|;
name|data
operator|=
name|bus_space_read_1
argument_list|(
name|sc
operator|->
name|bt_ioport
argument_list|,
name|sc
operator|->
name|bh_ioport
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|pcf_nops
argument_list|()
expr_stmt|;
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|pcf_repeated_start
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
name|pcf_start
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
name|pcf_stop
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcf_write
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
name|pcf_read
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

begin_function_decl
specifier|extern
name|int
name|pcf_rst_card
parameter_list|(
name|device_t
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|driver_intr_t
name|pcf_intr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PCF_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|PCF_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|PCF_MAXVER
value|1
end_define

begin_define
define|#
directive|define
name|PCF_PREFVER
value|PCF_MODVER
end_define

end_unit

