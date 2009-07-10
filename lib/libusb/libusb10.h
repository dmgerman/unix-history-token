begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2009 Sylvestre Gallon. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBUSB10_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIBUSB10_H__
end_define

begin_comment
comment|/*  * The two following macros were taken from the original LibUSB v1.0  * for sake of compatibility:  */
end_comment

begin_function_decl
specifier|static
name|int
name|get_next_timeout
parameter_list|(
name|libusb_context
modifier|*
name|ctx
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|struct
name|timeval
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|handle_timeouts
parameter_list|(
name|struct
name|libusb_context
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|handle_events
parameter_list|(
name|struct
name|libusb_context
modifier|*
name|ctx
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|libusb_context
modifier|*
name|usbi_default_context
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pthread_mutex_t
name|libusb20_lock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if ctx is NULL use default context*/
end_comment

begin_define
define|#
directive|define
name|GET_CONTEXT
parameter_list|(
name|ctx
parameter_list|)
define|\
value|if (ctx == NULL) ctx = usbi_default_context;
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)>(b))?(a):(b))
end_define

begin_define
define|#
directive|define
name|USB_TIMED_OUT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|UNEXPORTED
value|__attribute__((__visibility__("hidden")))
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|ctx
parameter_list|,
name|dbg
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (ctx->debug == dbg) {			\ 	printf("LIBUSB_%s : ", (ctx->debug == LIBUSB_DEBUG_FUNCTION) ? "FUNCTION" : "TRANSFER");	\ 	switch(ctx->debug) {			\ 		case LIBUSB_DEBUG_FUNCTION:	\ 			printf(format, ## args);\ 			break ;			\ 		case LIBUSB_DEBUG_TRANSFER:	\ 			printf(format, ## args);\ 			break ;			\ 	}					\ 	printf("\n");				\ }
end_define

begin_function_decl
name|UNEXPORTED
name|int
name|usb_add_pollfd
parameter_list|(
name|libusb_context
modifier|*
name|ctx
parameter_list|,
name|int
name|fd
parameter_list|,
name|short
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UNEXPORTED
name|void
name|usb_remove_pollfd
parameter_list|(
name|libusb_context
modifier|*
name|ctx
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UNEXPORTED
name|void
name|usb_handle_transfer_completion
parameter_list|(
name|struct
name|usb_transfer
modifier|*
name|uxfer
parameter_list|,
name|enum
name|libusb_transfer_status
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UNEXPORTED
name|void
name|usb_handle_disconnect
parameter_list|(
name|struct
name|libusb_device_handle
modifier|*
name|devh
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__LIBUSB10_H__*/
end_comment

end_unit

