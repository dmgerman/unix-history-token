begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HV_KBD_H
end_ifndef

begin_define
define|#
directive|define
name|_HV_KBD_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<dev/kbd/kbdreg.h>
end_include

begin_define
define|#
directive|define
name|HVKBD_DRIVER_NAME
value|"hvkbd"
end_define

begin_define
define|#
directive|define
name|IS_UNICODE
value|(1)
end_define

begin_define
define|#
directive|define
name|IS_BREAK
value|(2)
end_define

begin_define
define|#
directive|define
name|IS_E0
value|(4)
end_define

begin_define
define|#
directive|define
name|IS_E1
value|(8)
end_define

begin_define
define|#
directive|define
name|XTKBD_EMUL0
value|(0xe0)
end_define

begin_define
define|#
directive|define
name|XTKBD_EMUL1
value|(0xe1)
end_define

begin_define
define|#
directive|define
name|XTKBD_RELEASE
value|(0x80)
end_define

begin_define
define|#
directive|define
name|DEBUG_HVSC
parameter_list|(
name|sc
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	if (sc->debug> 0) {				\ 		device_printf(sc->dev, __VA_ARGS__);	\ 	}						\ } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUG_HVKBD
parameter_list|(
name|kbd
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	hv_kbd_sc *sc = (kbd)->kb_data;			\ 	DEBUG_HVSC(sc, __VA_ARGS__);				\ } while (0)
end_define

begin_struct_decl
struct_decl|struct
name|vmbus_channel
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_xact_ctx
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|keystroke_t
block|{
name|uint16_t
name|makecode
decl_stmt|;
name|uint32_t
name|info
decl_stmt|;
block|}
name|keystroke
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|keystroke_info
block|{
name|LIST_ENTRY
argument_list|(
argument|keystroke_info
argument_list|)
name|link
expr_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|keystroke_info
argument_list|)
name|slink
expr_stmt|;
name|keystroke
name|ks
decl_stmt|;
block|}
name|keystroke_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|hv_kbd_sc_t
block|{
name|struct
name|vmbus_channel
modifier|*
name|hs_chan
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|vmbus_xact_ctx
modifier|*
name|hs_xact_ctx
decl_stmt|;
name|int32_t
name|buflen
decl_stmt|;
name|uint8_t
modifier|*
name|buf
decl_stmt|;
name|struct
name|mtx
name|ks_mtx
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument_list|,
argument|keystroke_info
argument_list|)
name|ks_free_list
expr_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|keystroke_info
argument_list|)
name|ks_queue
expr_stmt|;
comment|/* keystroke info queue */
name|keyboard_t
name|sc_kbd
decl_stmt|;
name|int
name|sc_mode
decl_stmt|;
name|int
name|sc_state
decl_stmt|;
name|int
name|sc_polling
decl_stmt|;
comment|/* polling recursion count */
name|uint32_t
name|sc_flags
decl_stmt|;
name|int
name|debug
decl_stmt|;
block|}
name|hv_kbd_sc
typedef|;
end_typedef

begin_function_decl
name|int
name|hv_kbd_produce_ks
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|,
specifier|const
name|keystroke
modifier|*
name|ks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_fetch_top
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|,
name|keystroke
modifier|*
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_modify_top
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|,
name|keystroke
modifier|*
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_remove_top
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_prod_is_ready
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_kbd_read_channel
parameter_list|(
name|struct
name|vmbus_channel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_drv_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_kbd_drv_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hvkbd_driver_load
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_kbd_intr
parameter_list|(
name|hv_kbd_sc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

