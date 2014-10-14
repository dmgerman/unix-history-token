begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 M. Warner Losh  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright 1992 by the University of Guelph  *  * Permission to use, copy and modify this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting  * documentation.  * University of Guelph makes no representations about the suitability of  * this software for any purpose.  It is provided "as is"  * without express or implied warranty.  */
end_comment

begin_comment
comment|/* driver configuration flags (config) */
end_comment

begin_define
define|#
directive|define
name|MSE_CONFIG_ACCEL
value|0x00f0
end_define

begin_comment
comment|/* acceleration factor */
end_comment

begin_define
define|#
directive|define
name|MSE_CONFIG_FLAGS
value|(MSE_CONFIG_ACCEL)
end_define

begin_comment
comment|/*  * Software control structure for mouse. The sc_enablemouse(),  * sc_disablemouse() and sc_getmouse() routines must be called locked.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mse_softc
block|{
name|int
name|sc_flags
decl_stmt|;
name|int
name|sc_mousetype
decl_stmt|;
name|struct
name|selinfo
name|sc_selp
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_port
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_intr
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sc_enablemouse
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_disablemouse
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_getmouse
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
function_decl|;
name|int
name|sc_deltax
decl_stmt|;
name|int
name|sc_deltay
decl_stmt|;
name|int
name|sc_obuttons
decl_stmt|;
name|int
name|sc_buttons
decl_stmt|;
name|int
name|sc_bytesread
decl_stmt|;
name|u_char
name|sc_bytes
index|[
name|MOUSE_SYS_PACKETSIZE
index|]
decl_stmt|;
name|struct
name|callout
name|sc_callout
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
name|int
name|sc_watchdog
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|sc_ndev
decl_stmt|;
name|mousehw_t
name|hw
decl_stmt|;
name|mousemode_t
name|mode
decl_stmt|;
name|mousestatus_t
name|status
decl_stmt|;
block|}
name|mse_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MSE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|MSE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|MSE_ASSERT_LOCKED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_lock, MA_OWNED)
end_define

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|MSESC_OPEN
value|0x1
end_define

begin_define
define|#
directive|define
name|MSESC_WANT
value|0x2
end_define

begin_define
define|#
directive|define
name|MSESC_READING
value|0x4
end_define

begin_comment
comment|/* and Mouse Types */
end_comment

begin_define
define|#
directive|define
name|MSE_NONE
value|0
end_define

begin_comment
comment|/* don't move this! */
end_comment

begin_comment
comment|/* pc98 bus mouse types */
end_comment

begin_define
define|#
directive|define
name|MSE_98BUSMOUSE
value|0x1
end_define

begin_comment
comment|/* isa bus mouse types */
end_comment

begin_define
define|#
directive|define
name|MSE_LOGITECH
value|0x1
end_define

begin_define
define|#
directive|define
name|MSE_ATIINPORT
value|0x2
end_define

begin_define
define|#
directive|define
name|MSE_LOGI_SIG
value|0xA5
end_define

begin_comment
comment|/* XXX msereg.h? */
end_comment

begin_define
define|#
directive|define
name|MSE_PORTA
value|0
end_define

begin_define
define|#
directive|define
name|MSE_PORTB
value|1
end_define

begin_define
define|#
directive|define
name|MSE_PORTC
value|2
end_define

begin_define
define|#
directive|define
name|MSE_PORTD
value|3
end_define

begin_define
define|#
directive|define
name|MSE_IOSIZE
value|4
end_define

begin_comment
comment|/*  * Table of mouse types.  * Keep the Logitech last, since I haven't figured out how to probe it  * properly yet. (Someday I'll have the documentation.)  */
end_comment

begin_struct
struct|struct
name|mse_types
block|{
name|int
name|m_type
decl_stmt|;
comment|/* Type of bus mouse */
name|int
function_decl|(
modifier|*
name|m_probe
function_decl|)
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mse_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
comment|/* Probe routine to test for it */
name|void
function_decl|(
modifier|*
name|m_enable
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
comment|/* Start routine */
name|void
function_decl|(
modifier|*
name|m_disable
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|)
function_decl|;
comment|/* Disable interrupts routine */
name|void
function_decl|(
modifier|*
name|m_get
function_decl|)
parameter_list|(
name|struct
name|resource
modifier|*
name|port
parameter_list|,
name|int
modifier|*
name|dx
parameter_list|,
name|int
modifier|*
name|dy
parameter_list|,
name|int
modifier|*
name|but
parameter_list|)
function_decl|;
comment|/* and get mouse status */
name|mousehw_t
name|m_hw
decl_stmt|;
comment|/* buttons iftype type model hwid */
name|mousemode_t
name|m_mode
decl_stmt|;
comment|/* proto rate res accel level size mask */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|mse_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|mse_common_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mse_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

