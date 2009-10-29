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
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_SERIAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_SERIAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<sys/serial.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

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

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ucom_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device_request
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * NOTE: There is no guarantee that "ucom_cfg_close()" will  * be called after "ucom_cfg_open()" if the device is detached  * while it is open!  */
end_comment

begin_struct
struct|struct
name|ucom_callback
block|{
name|void
function_decl|(
modifier|*
name|ucom_cfg_get_status
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
name|plsr
parameter_list|,
name|uint8_t
modifier|*
name|pmsr
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_set_dtr
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_set_rts
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_set_break
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_set_ring
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_param
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_open
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_cfg_close
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ucom_pre_open
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ucom_pre_param
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
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
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_start_read
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_stop_read
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_start_write
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_stop_write
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_tty_name
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|char
modifier|*
name|pbuf
parameter_list|,
name|uint16_t
name|buflen
parameter_list|,
name|uint16_t
name|local_subunit
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucom_poll
function_decl|)
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Line status register */
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

begin_struct
struct|struct
name|ucom_cfg_task
block|{
name|struct
name|usb_proc_msg
name|hdr
decl_stmt|;
name|struct
name|ucom_softc
modifier|*
name|sc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ucom_param_task
block|{
name|struct
name|usb_proc_msg
name|hdr
decl_stmt|;
name|struct
name|ucom_softc
modifier|*
name|sc
decl_stmt|;
name|struct
name|termios
name|termios_copy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ucom_super_softc
block|{
name|struct
name|usb_process
name|sc_tq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ucom_softc
block|{
comment|/* 	 * NOTE: To avoid loosing level change information we use two 	 * tasks instead of one for all commands. 	 * 	 * Level changes are transitions like: 	 * 	 * ON->OFF 	 * OFF->ON 	 * OPEN->CLOSE 	 * CLOSE->OPEN 	 */
name|struct
name|ucom_cfg_task
name|sc_start_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ucom_cfg_task
name|sc_open_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ucom_cfg_task
name|sc_close_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ucom_cfg_task
name|sc_line_state_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ucom_cfg_task
name|sc_status_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|ucom_param_task
name|sc_param_task
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|cv
name|sc_cv
decl_stmt|;
comment|/* Used to set "UCOM_FLAG_GP_DATA" flag: */
name|struct
name|usb_proc_msg
modifier|*
name|sc_last_start_xfer
decl_stmt|;
specifier|const
name|struct
name|ucom_callback
modifier|*
name|sc_callback
decl_stmt|;
name|struct
name|ucom_super_softc
modifier|*
name|sc_super
decl_stmt|;
name|struct
name|tty
modifier|*
name|sc_tty
decl_stmt|;
name|struct
name|mtx
modifier|*
name|sc_mtx
decl_stmt|;
name|void
modifier|*
name|sc_parent
decl_stmt|;
name|uint32_t
name|sc_unit
decl_stmt|;
name|uint32_t
name|sc_local_unit
decl_stmt|;
name|uint16_t
name|sc_portno
decl_stmt|;
name|uint16_t
name|sc_flag
decl_stmt|;
define|#
directive|define
name|UCOM_FLAG_RTS_IFLOW
value|0x01
comment|/* use RTS input flow control */
define|#
directive|define
name|UCOM_FLAG_GONE
value|0x02
comment|/* the device is gone */
define|#
directive|define
name|UCOM_FLAG_ATTACHED
value|0x04
comment|/* set if attached */
define|#
directive|define
name|UCOM_FLAG_GP_DATA
value|0x08
comment|/* set if get and put data is possible */
define|#
directive|define
name|UCOM_FLAG_LL_READY
value|0x20
comment|/* set if low layer is ready */
define|#
directive|define
name|UCOM_FLAG_HL_READY
value|0x40
comment|/* set if high layer is ready */
define|#
directive|define
name|UCOM_FLAG_CONSOLE
value|0x80
comment|/* set if device is a console */
name|uint8_t
name|sc_lsr
decl_stmt|;
name|uint8_t
name|sc_msr
decl_stmt|;
name|uint8_t
name|sc_mcr
decl_stmt|;
name|uint8_t
name|sc_ttyfreed
decl_stmt|;
comment|/* set when TTY has been freed */
comment|/* programmed line state bits */
name|uint8_t
name|sc_pls_set
decl_stmt|;
comment|/* set bits */
name|uint8_t
name|sc_pls_clr
decl_stmt|;
comment|/* cleared bits */
name|uint8_t
name|sc_pls_curr
decl_stmt|;
comment|/* last state */
define|#
directive|define
name|UCOM_LS_DTR
value|0x01
define|#
directive|define
name|UCOM_LS_RTS
value|0x02
define|#
directive|define
name|UCOM_LS_BREAK
value|0x04
define|#
directive|define
name|UCOM_LS_RING
value|0x08
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ucom_cfg_do_request
parameter_list|(
name|udev
parameter_list|,
name|com
parameter_list|,
name|req
parameter_list|,
name|ptr
parameter_list|,
name|flags
parameter_list|,
name|timo
parameter_list|)
define|\
value|usbd_do_request_proc(udev,&(com)->sc_super->sc_tq,req,ptr,flags,NULL,timo)
end_define

begin_function_decl
name|int
name|ucom_attach
parameter_list|(
name|struct
name|ucom_super_softc
modifier|*
parameter_list|,
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|ucom_callback
modifier|*
name|callback
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ucom_detach
parameter_list|(
name|struct
name|ucom_super_softc
modifier|*
parameter_list|,
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|uint32_t
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

begin_function_decl
name|uint8_t
name|ucom_get_data
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|struct
name|usb_page_cache
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ucom_put_data
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|,
name|struct
name|usb_page_cache
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|ucom_cfg_is_gone
parameter_list|(
name|struct
name|ucom_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_SERIAL_H_ */
end_comment

end_unit

