begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ucomvar.h,v 1.9 2001/01/23 21:56:17 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2002, Shunsuke Akiyama<akiyama@jp.FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Module interface related macros */
end_comment

begin_define
define|#
directive|define
name|UCOM_MODVER
value|1
end_define

begin_define
define|#
directive|define
name|UCOM_MINVER
value|1
end_define

begin_define
define|#
directive|define
name|UCOM_PREFVER
value|UCOM_MODVER
end_define

begin_define
define|#
directive|define
name|UCOM_MAXVER
value|1
end_define

begin_comment
comment|/* Macros to clear/set/test flags. */
end_comment

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|(t) |= (f)
end_define

begin_define
define|#
directive|define
name|CLR
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|(t)&= ~((unsigned)(f))
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|((t)& (f))
end_define

begin_define
define|#
directive|define
name|UCOM_CALLOUT_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|UCOMUNIT_MASK
value|0x3ff7f
end_define

begin_define
define|#
directive|define
name|UCOMDIALOUT_MASK
value|0x80000
end_define

begin_define
define|#
directive|define
name|UCOMCALLUNIT_MASK
value|0x40000
end_define

begin_define
define|#
directive|define
name|UCOMUNIT
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& UCOMUNIT_MASK)
end_define

begin_define
define|#
directive|define
name|UCOMDIALOUT
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& UCOMDIALOUT_MASK)
end_define

begin_define
define|#
directive|define
name|UCOMCALLUNIT
parameter_list|(
name|x
parameter_list|)
value|(minor(x)& UCOMCALLUNIT_MASK)
end_define

begin_define
define|#
directive|define
name|UCOM_UNK_PORTNO
value|-1
end_define

begin_comment
comment|/* XXX */
end_comment

begin_struct_decl
struct_decl|struct
name|ucom_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ucom_callback
block|{
name|void
function_decl|(
modifier|*
name|ucom_get_status
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_set
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
define|#
directive|define
name|UCOM_SET_DTR
value|1
define|#
directive|define
name|UCOM_SET_RTS
value|2
define|#
directive|define
name|UCOM_SET_BREAK
value|3
name|int
function_decl|(
modifier|*
name|ucom_param
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ucom_ioctl
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|usb_proc_ptr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ucom_open
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_close
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_read
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_write
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* modem control register */
end_comment

begin_define
define|#
directive|define
name|UMCR_RTS
value|0x02
end_define

begin_comment
comment|/* Request To Send */
end_comment

begin_define
define|#
directive|define
name|UMCR_DTR
value|0x01
end_define

begin_comment
comment|/* Data Terminal Ready */
end_comment

begin_comment
comment|/* line status register */
end_comment

begin_define
define|#
directive|define
name|ULSR_RCV_FIFO
value|0x80
end_define

begin_define
define|#
directive|define
name|ULSR_TSRE
value|0x40
end_define

begin_comment
comment|/* Transmitter empty: byte sent */
end_comment

begin_define
define|#
directive|define
name|ULSR_TXRDY
value|0x20
end_define

begin_comment
comment|/* Transmitter buffer empty */
end_comment

begin_define
define|#
directive|define
name|ULSR_BI
value|0x10
end_define

begin_comment
comment|/* Break detected */
end_comment

begin_define
define|#
directive|define
name|ULSR_FE
value|0x08
end_define

begin_comment
comment|/* Framing error: bad stop bit */
end_comment

begin_define
define|#
directive|define
name|ULSR_PE
value|0x04
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|ULSR_OE
value|0x02
end_define

begin_comment
comment|/* Overrun, lost incoming byte */
end_comment

begin_define
define|#
directive|define
name|ULSR_RXRDY
value|0x01
end_define

begin_comment
comment|/* Byte ready in Receive Buffer */
end_comment

begin_define
define|#
directive|define
name|ULSR_RCV_MASK
value|0x1f
end_define

begin_comment
comment|/* Mask for incoming data or error */
end_comment

begin_comment
comment|/* modem status register */
end_comment

begin_comment
comment|/* All deltas are from the last read of the MSR. */
end_comment

begin_define
define|#
directive|define
name|UMSR_DCD
value|0x80
end_define

begin_comment
comment|/* Current Data Carrier Detect */
end_comment

begin_define
define|#
directive|define
name|UMSR_RI
value|0x40
end_define

begin_comment
comment|/* Current Ring Indicator */
end_comment

begin_define
define|#
directive|define
name|UMSR_DSR
value|0x20
end_define

begin_comment
comment|/* Current Data Set Ready */
end_comment

begin_define
define|#
directive|define
name|UMSR_CTS
value|0x10
end_define

begin_comment
comment|/* Current Clear to Send */
end_comment

begin_define
define|#
directive|define
name|UMSR_DDCD
value|0x08
end_define

begin_comment
comment|/* DCD has changed state */
end_comment

begin_define
define|#
directive|define
name|UMSR_TERI
value|0x04
end_define

begin_comment
comment|/* RI has toggled low to high */
end_comment

begin_define
define|#
directive|define
name|UMSR_DDSR
value|0x02
end_define

begin_comment
comment|/* DSR has changed state */
end_comment

begin_define
define|#
directive|define
name|UMSR_DCTS
value|0x01
end_define

begin_comment
comment|/* CTS has changed state */
end_comment

begin_comment
comment|/* ucom state declarations */
end_comment

begin_define
define|#
directive|define
name|UCS_RXSTOP
value|0x0001
end_define

begin_comment
comment|/* Rx stopped */
end_comment

begin_define
define|#
directive|define
name|UCS_RTS_IFLOW
value|0x0008
end_define

begin_comment
comment|/* use RTS input flow control */
end_comment

begin_struct
struct|struct
name|ucom_softc
block|{
name|USBBASEDEVICE
name|sc_dev
decl_stmt|;
comment|/* base device */
name|usbd_device_handle
name|sc_udev
decl_stmt|;
comment|/* USB device */
name|usbd_interface_handle
name|sc_iface
decl_stmt|;
comment|/* data interface */
name|int
name|sc_bulkin_no
decl_stmt|;
comment|/* bulk in endpoint address */
name|usbd_pipe_handle
name|sc_bulkin_pipe
decl_stmt|;
comment|/* bulk in pipe */
name|usbd_xfer_handle
name|sc_ixfer
decl_stmt|;
comment|/* read request */
name|u_char
modifier|*
name|sc_ibuf
decl_stmt|;
comment|/* read buffer */
name|u_int
name|sc_ibufsize
decl_stmt|;
comment|/* read buffer size */
name|u_int
name|sc_ibufsizepad
decl_stmt|;
comment|/* read buffer size padded */
name|int
name|sc_bulkout_no
decl_stmt|;
comment|/* bulk out endpoint address */
name|usbd_pipe_handle
name|sc_bulkout_pipe
decl_stmt|;
comment|/* bulk out pipe */
name|usbd_xfer_handle
name|sc_oxfer
decl_stmt|;
comment|/* write request */
name|u_char
modifier|*
name|sc_obuf
decl_stmt|;
comment|/* write buffer */
name|u_int
name|sc_obufsize
decl_stmt|;
comment|/* write buffer size */
name|u_int
name|sc_opkthdrlen
decl_stmt|;
comment|/* header length of 						   output packet */
name|struct
name|ucom_callback
modifier|*
name|sc_callback
decl_stmt|;
name|void
modifier|*
name|sc_parent
decl_stmt|;
name|int
name|sc_portno
decl_stmt|;
name|struct
name|tty
modifier|*
name|sc_tty
decl_stmt|;
comment|/* our tty */
name|int
name|sc_state
decl_stmt|;
name|int
name|sc_poll
decl_stmt|;
name|u_char
name|hotchar
decl_stmt|;
name|u_char
name|sc_lsr
decl_stmt|;
name|u_char
name|sc_msr
decl_stmt|;
name|u_char
name|sc_mcr
decl_stmt|;
name|u_char
name|sc_opening
decl_stmt|;
comment|/* lock during open */
name|int
name|sc_refcnt
decl_stmt|;
name|u_char
name|sc_dying
decl_stmt|;
comment|/* disconnecting */
name|dev_t
name|dev
decl_stmt|;
comment|/* special device node */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|ucom_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ucom_attach
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ucom_detach
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ucom_status_change
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|UCOM_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UPLCOM_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|UVSCOM_DEBUG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

