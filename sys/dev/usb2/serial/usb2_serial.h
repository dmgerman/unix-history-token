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
name|_USB2_SERIAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_SERIAL_H_
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
name|usb2_com_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_comment
comment|/* NOTE: Only callbacks with "_cfg_" in its name are called  * from a config thread, and are allowed to sleep! The other  * callbacks are _not_ allowed to sleep!  *  * NOTE: There is no guarantee that "usb2_com_cfg_close()" will  * be called after "usb2_com_cfg_open()" if the device is detached  * while it is open!  */
end_comment

begin_struct
struct|struct
name|usb2_com_callback
block|{
name|void
function_decl|(
modifier|*
name|usb2_com_cfg_get_status
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
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
name|usb2_com_cfg_set_dtr
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_cfg_set_rts
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_cfg_set_break
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_cfg_param
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
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
name|usb2_com_cfg_open
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_cfg_close
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|usb2_com_pre_open
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|usb2_com_pre_param
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
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
name|usb2_com_ioctl
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
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
name|usb2_com_start_read
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_stop_read
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_start_write
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_stop_write
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|usb2_com_tty_name
function_decl|)
parameter_list|(
name|struct
name|usb2_com_softc
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

begin_comment
comment|/*  * List of serial adapter commands or deferred function calls:  */
end_comment

begin_enum
enum|enum
block|{
name|USB_COM_CFG_START_TRANSFERS
block|,
name|USB_COM_CFG_OPEN
block|,
name|USB_COM_CFG_CLOSE
block|,
name|USB_COM_CFG_BREAK_ON
block|,
name|USB_COM_CFG_BREAK_OFF
block|,
name|USB_COM_CFG_DTR_ON
block|,
name|USB_COM_CFG_DTR_OFF
block|,
name|USB_COM_CFG_RTS_ON
block|,
name|USB_COM_CFG_RTS_OFF
block|,
name|USB_COM_CFG_STATUS_CHANGE
block|,
name|USB_COM_CFG_PARAM
block|,
name|USB_COM_CFG_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|usb2_com_command_msg
block|{
name|struct
name|usb2_proc_msg
name|hdr
decl_stmt|;
comment|/* must be first */
name|struct
name|usb2_com_softc
modifier|*
name|cc_softc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb2_com_super_softc
block|{
name|struct
name|usb2_process
name|sc_config_td
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb2_com_softc
block|{
name|struct
name|usb2_com_command_msg
name|sc_cmds
index|[
literal|2
operator|*
name|USB_COM_CFG_MAX
index|]
decl_stmt|;
name|struct
name|termios
name|sc_termios_copy
decl_stmt|;
name|struct
name|cv
name|sc_cv
decl_stmt|;
specifier|const
name|struct
name|usb2_com_callback
modifier|*
name|sc_callback
decl_stmt|;
name|struct
name|usb2_com_super_softc
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
name|sc_parent_mtx
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
name|uint8_t
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
name|UCOM_FLAG_WR_START
value|0x10
comment|/* set if write start was issued */
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
name|uint8_t
name|sc_last_cmd_flag
index|[
name|USB_COM_CFG_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|usb2_com_attach
parameter_list|(
name|struct
name|usb2_com_super_softc
modifier|*
name|ssc
parameter_list|,
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|sub_units
parameter_list|,
name|void
modifier|*
name|parent
parameter_list|,
specifier|const
name|struct
name|usb2_com_callback
modifier|*
name|callback
parameter_list|,
name|struct
name|mtx
modifier|*
name|p_mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_com_detach
parameter_list|(
name|struct
name|usb2_com_super_softc
modifier|*
name|ssc
parameter_list|,
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|sub_units
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_com_status_change
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_com_get_data
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|len
parameter_list|,
name|uint32_t
modifier|*
name|actlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_com_put_data
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|usb2_page_cache
modifier|*
name|pc
parameter_list|,
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_com_cfg_sleep
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_com_cfg_is_gone
parameter_list|(
name|struct
name|usb2_com_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_SERIAL_H_ */
end_comment

end_unit

