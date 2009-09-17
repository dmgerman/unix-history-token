begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_UTIL_H_
end_define

begin_function_decl
name|int
name|device_delete_all_children
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|usb2_get_devid
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_make_str_desc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uint16_t
name|max_len
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_usb2_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_pause_mtx
parameter_list|(
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|_ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_printBCD
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|uint16_t
name|p_len
parameter_list|,
name|uint16_t
name|bcd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_trim_spaces
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|USB_USE_CONDVAR
operator|==
literal|0
operator|)
end_if

begin_function_decl
name|void
name|usb2_cv_init
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_cv_destroy
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_cv_wait
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_cv_wait_sig
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_cv_timedwait
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|int
name|timo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_cv_signal
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_cv_broadcast
parameter_list|(
name|struct
name|cv
modifier|*
name|cv
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|usb2_cv_init
value|cv_init
end_define

begin_define
define|#
directive|define
name|usb2_cv_destroy
value|cv_destroy
end_define

begin_define
define|#
directive|define
name|usb2_cv_wait
value|cv_wait
end_define

begin_define
define|#
directive|define
name|usb2_cv_wait_sig
value|cv_wait_sig
end_define

begin_define
define|#
directive|define
name|usb2_cv_timedwait
value|cv_timedwait
end_define

begin_define
define|#
directive|define
name|usb2_cv_signal
value|cv_signal
end_define

begin_define
define|#
directive|define
name|usb2_cv_broadcast
value|cv_broadcast
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_UTIL_H_ */
end_comment

end_unit

