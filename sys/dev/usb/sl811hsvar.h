begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*      $FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Tetsuya Isaki.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by the NetBSD  *      Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * ScanLogic SL811HS/T USB Host Controller  */
end_comment

begin_define
define|#
directive|define
name|MS_TO_TICKS
parameter_list|(
name|ms
parameter_list|)
value|((ms) * hz / 1000)
end_define

begin_define
define|#
directive|define
name|delay_ms
parameter_list|(
name|X
parameter_list|)
define|\
value|pause("slhci", MS_TO_TICKS(X))
end_define

begin_define
define|#
directive|define
name|SL11_PID_OUT
value|(0x1)
end_define

begin_define
define|#
directive|define
name|SL11_PID_IN
value|(0x9)
end_define

begin_define
define|#
directive|define
name|SL11_PID_SOF
value|(0x5)
end_define

begin_define
define|#
directive|define
name|SL11_PID_SETUP
value|(0xd)
end_define

begin_struct
struct|struct
name|slhci_xfer
block|{
name|usbd_xfer_handle
name|sx_xfer
decl_stmt|;
name|usb_callout_t
name|sx_callout_t
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|slhci_softc
block|{
name|struct
name|usbd_bus
name|sc_bus
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_space_handle_t
name|sc_ioh
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|void
modifier|*
name|ih
decl_stmt|;
name|struct
name|resource
modifier|*
name|io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
endif|#
directive|endif
name|void
function_decl|(
modifier|*
name|sc_enable_power
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
name|sc_enable_intr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|sc_arg
decl_stmt|;
name|int
name|sc_powerstat
decl_stmt|;
define|#
directive|define
name|POWER_ON
value|(1)
define|#
directive|define
name|POWER_OFF
value|(0)
define|#
directive|define
name|INTR_ON
value|(1)
define|#
directive|define
name|INTR_OFF
value|(0)
name|struct
name|device
modifier|*
name|sc_parent
decl_stmt|;
comment|/* parent device */
name|int
name|sc_sltype
decl_stmt|;
comment|/* revision */
define|#
directive|define
name|SLTYPE_SL11H
value|(0x00)
define|#
directive|define
name|SLTYPE_SL811HS
value|(0x01)
define|#
directive|define
name|SLTYPE_SL811HS_R12
value|SLTYPE_SL811HS
define|#
directive|define
name|SLTYPE_SL811HS_R14
value|(0x02)
name|u_int8_t
name|sc_addr
decl_stmt|;
comment|/* device address of root hub */
name|u_int8_t
name|sc_conf
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|usbd_xfer
argument_list|)
name|sc_free_xfers
expr_stmt|;
comment|/* Information for the root hub interrupt pipe */
name|int
name|sc_interval
decl_stmt|;
name|usbd_xfer_handle
name|sc_intr_xfer
decl_stmt|;
name|usb_callout_t
name|sc_poll_handle
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|SLF_RESET
value|(0x01)
define|#
directive|define
name|SLF_INSERT
value|(0x02)
define|#
directive|define
name|SLF_ATTACHED
value|(0x04)
comment|/* Root HUB specific members */
name|int
name|sc_fullspeed
decl_stmt|;
name|int
name|sc_connect
decl_stmt|;
comment|/* XXX */
name|int
name|sc_change
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|sl811hs_find
parameter_list|(
name|struct
name|slhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|slhci_attach
parameter_list|(
name|struct
name|slhci_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|slhci_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

