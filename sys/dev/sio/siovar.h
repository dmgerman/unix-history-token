begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SET_FLAG
parameter_list|(
name|dev
parameter_list|,
name|bit
parameter_list|)
value|device_set_flags(dev, device_get_flags(dev) | (bit))
end_define

begin_define
define|#
directive|define
name|CLR_FLAG
parameter_list|(
name|dev
parameter_list|,
name|bit
parameter_list|)
value|device_set_flags(dev, device_get_flags(dev)& ~(bit))
end_define

begin_define
define|#
directive|define
name|CE_NTYPES
value|3
end_define

begin_comment
comment|/* types.  XXX - should be elsewhere */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|Port_t
typedef|;
end_typedef

begin_comment
comment|/* hardware port */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|bool_t
typedef|;
end_typedef

begin_comment
comment|/* boolean */
end_comment

begin_comment
comment|/* queue of linear buffers */
end_comment

begin_struct
struct|struct
name|lbq
block|{
name|u_char
modifier|*
name|l_head
decl_stmt|;
comment|/* next char to process */
name|u_char
modifier|*
name|l_tail
decl_stmt|;
comment|/* one past the last char to process */
name|struct
name|lbq
modifier|*
name|l_next
decl_stmt|;
comment|/* next in queue */
name|bool_t
name|l_queued
decl_stmt|;
comment|/* nonzero if queued */
block|}
struct|;
end_struct

begin_comment
comment|/* com device structure */
end_comment

begin_struct
struct|struct
name|com_s
block|{
name|u_int
name|flags
decl_stmt|;
comment|/* Copy isa device flags */
name|u_char
name|state
decl_stmt|;
comment|/* miscellaneous flag bits */
name|bool_t
name|active_out
decl_stmt|;
comment|/* nonzero if the callout device is open */
name|u_char
name|cfcr_image
decl_stmt|;
comment|/* copy of value written to CFCR */
ifdef|#
directive|ifdef
name|COM_ESP
name|bool_t
name|esp
decl_stmt|;
comment|/* is this unit a hayes esp board? */
endif|#
directive|endif
name|u_char
name|extra_state
decl_stmt|;
comment|/* more flag bits, separate for order trick */
name|u_char
name|fifo_image
decl_stmt|;
comment|/* copy of value written to FIFO */
name|bool_t
name|hasfifo
decl_stmt|;
comment|/* nonzero for 16550 UARTs */
name|bool_t
name|st16650a
decl_stmt|;
comment|/* Is a Startech 16650A or RTS/CTS compat */
name|bool_t
name|loses_outints
decl_stmt|;
comment|/* nonzero if device loses output interrupts */
name|u_char
name|mcr_image
decl_stmt|;
comment|/* copy of value written to MCR */
ifdef|#
directive|ifdef
name|COM_MULTIPORT
name|bool_t
name|multiport
decl_stmt|;
comment|/* is this unit part of a multiport device? */
endif|#
directive|endif
comment|/* COM_MULTIPORT */
name|bool_t
name|no_irq
decl_stmt|;
comment|/* nonzero if irq is not attached */
name|bool_t
name|gone
decl_stmt|;
comment|/* hardware disappeared */
name|bool_t
name|poll
decl_stmt|;
comment|/* nonzero if polling is required */
name|bool_t
name|poll_output
decl_stmt|;
comment|/* nonzero if polling for output is required */
name|int
name|unit
decl_stmt|;
comment|/* unit	number */
name|int
name|dtr_wait
decl_stmt|;
comment|/* time to hold DTR down on close (* 1/hz) */
name|u_int
name|tx_fifo_size
decl_stmt|;
name|u_int
name|wopeners
decl_stmt|;
comment|/* # processes waiting for DCD in open() */
comment|/* 	 * The high level of the driver never reads status registers directly 	 * because there would be too many side effects to handle conveniently. 	 * Instead, it reads copies of the registers stored here by the 	 * interrupt handler. 	 */
name|u_char
name|last_modem_status
decl_stmt|;
comment|/* last MSR read by intr handler */
name|u_char
name|prev_modem_status
decl_stmt|;
comment|/* last MSR handled by high level */
name|u_char
name|hotchar
decl_stmt|;
comment|/* ldisc-specific char to be handled ASAP */
name|u_char
modifier|*
name|ibuf
decl_stmt|;
comment|/* start of input buffer */
name|u_char
modifier|*
name|ibufend
decl_stmt|;
comment|/* end of input buffer */
name|u_char
modifier|*
name|ibufold
decl_stmt|;
comment|/* old input buffer, to be freed */
name|u_char
modifier|*
name|ihighwater
decl_stmt|;
comment|/* threshold in input buffer */
name|u_char
modifier|*
name|iptr
decl_stmt|;
comment|/* next free spot in input buffer */
name|int
name|ibufsize
decl_stmt|;
comment|/* size of ibuf (not include error bytes) */
name|int
name|ierroff
decl_stmt|;
comment|/* offset of error bytes in ibuf */
name|struct
name|lbq
name|obufq
decl_stmt|;
comment|/* head of queue of output buffers */
name|struct
name|lbq
name|obufs
index|[
literal|2
index|]
decl_stmt|;
comment|/* output buffers */
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|Port_t
name|data_port
decl_stmt|;
comment|/* i/o ports */
ifdef|#
directive|ifdef
name|COM_ESP
name|Port_t
name|esp_port
decl_stmt|;
endif|#
directive|endif
name|Port_t
name|int_id_port
decl_stmt|;
name|Port_t
name|modem_ctl_port
decl_stmt|;
name|Port_t
name|line_status_port
decl_stmt|;
name|Port_t
name|modem_status_port
decl_stmt|;
name|Port_t
name|intr_ctl_port
decl_stmt|;
comment|/* Ports of IIR register */
name|struct
name|tty
modifier|*
name|tp
decl_stmt|;
comment|/* cross reference */
comment|/* Initial state. */
name|struct
name|termios
name|it_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|it_out
decl_stmt|;
comment|/* Lock state. */
name|struct
name|termios
name|lt_in
decl_stmt|;
comment|/* should be in struct tty */
name|struct
name|termios
name|lt_out
decl_stmt|;
name|bool_t
name|do_timestamp
decl_stmt|;
name|bool_t
name|do_dcd_timestamp
decl_stmt|;
name|struct
name|timeval
name|timestamp
decl_stmt|;
name|struct
name|timeval
name|dcd_timestamp
decl_stmt|;
name|struct
name|pps_state
name|pps
decl_stmt|;
name|u_long
name|bytes_in
decl_stmt|;
comment|/* statistics */
name|u_long
name|bytes_out
decl_stmt|;
name|u_int
name|delta_error_counts
index|[
name|CE_NTYPES
index|]
decl_stmt|;
name|u_long
name|error_counts
index|[
name|CE_NTYPES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|irqres
decl_stmt|;
name|struct
name|resource
modifier|*
name|ioportres
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
name|dev_t
name|devs
index|[
literal|6
index|]
decl_stmt|;
comment|/* 	 * Data area for output buffers.  Someday we should build the output 	 * buffer queue without copying data. 	 */
name|u_char
name|obuf1
index|[
literal|256
index|]
decl_stmt|;
name|u_char
name|obuf2
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|sioattach
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|,
name|int
name|xrid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|siodetach
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sioprobe
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|,
name|int
name|xrid
operator|,
name|int
name|noprobe
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|sio_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sio_driver_name
index|[]
decl_stmt|;
end_decl_stmt

end_unit

