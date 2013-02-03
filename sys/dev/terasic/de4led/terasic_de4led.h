begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_TERASIC_DE4LED_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_TERASIC_DE4LED_H_
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_NUMLEDS
value|8
end_define

begin_struct
struct|struct
name|terasic_de4led_softc
block|{
name|device_t
name|tdl_dev
decl_stmt|;
name|int
name|tdl_unit
decl_stmt|;
name|struct
name|resource
modifier|*
name|tdl_res
decl_stmt|;
name|int
name|tdl_rid
decl_stmt|;
name|struct
name|mtx
name|tdl_lock
decl_stmt|;
name|uint8_t
name|tdl_bits
decl_stmt|;
name|struct
name|cdev
modifier|*
name|tdl_leds
index|[
name|TERASIC_DE4LED_NUMLEDS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TERASIC_DE4LED_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->tdl_lock)
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->tdl_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->tdl_lock)
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|mtx_init(&(sc)->tdl_lock,	\ 					    "terasic_de4led", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->tdl_lock)
end_define

begin_comment
comment|/*  * Setting and clearing LEDs.  tdl_bits is in the bit order preferred for I/O.  * The LED elements are labelled 1..8 on the DE-4, so bit 0 is LED 1, and so  * on.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_DE4LED_CLEARBAR
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	(sc)->tdl_bits = 0;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|TERASIC_DE4LED_SETLED
parameter_list|(
name|sc
parameter_list|,
name|led
parameter_list|,
name|onoff
parameter_list|)
value|do {			\ 	(sc)->tdl_bits&= ~(1<< (led));				\ 	(sc)->tdl_bits |= ((onoff != 0) ? 1 : 0)<< (led);		\ } while (0)
end_define

begin_comment
comment|/*  * Only one offset matters for this device -- 0.  */
end_comment

begin_define
define|#
directive|define
name|TERASIC_DE4LED_OFF_LED
value|0
end_define

begin_function_decl
name|void
name|terasic_de4led_attach
parameter_list|(
name|struct
name|terasic_de4led_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|terasic_de4led_detach
parameter_list|(
name|struct
name|terasic_de4led_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|terasic_de4led_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_TERASIC_DE4LED_H_ */
end_comment

end_unit

