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
name|_USB_PROCESS_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_PROCESS_H_
end_define

begin_include
include|#
directive|include
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/priority.h>
end_include

begin_include
include|#
directive|include
file|<sys/runq.h>
end_include

begin_comment
comment|/* defines */
end_comment

begin_define
define|#
directive|define
name|USB_PRI_HIGH
value|PI_SWI(SWI_NET)
end_define

begin_define
define|#
directive|define
name|USB_PRI_MED
value|PI_SWI(SWI_CAMBIO)
end_define

begin_define
define|#
directive|define
name|USB_PROC_WAIT_TIMEOUT
value|2
end_define

begin_define
define|#
directive|define
name|USB_PROC_WAIT_DRAIN
value|1
end_define

begin_define
define|#
directive|define
name|USB_PROC_WAIT_NORMAL
value|0
end_define

begin_comment
comment|/* structure prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|usb_proc_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_device
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The following structure defines the USB process.  */
end_comment

begin_struct
struct|struct
name|usb_process
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|usb_proc_msg
argument_list|)
name|up_qhead
expr_stmt|;
name|struct
name|cv
name|up_cv
decl_stmt|;
name|struct
name|cv
name|up_drain
decl_stmt|;
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|800000
operator|)
name|struct
name|thread
modifier|*
name|up_ptr
decl_stmt|;
else|#
directive|else
name|struct
name|proc
modifier|*
name|up_ptr
decl_stmt|;
endif|#
directive|endif
name|struct
name|thread
modifier|*
name|up_curtd
decl_stmt|;
name|struct
name|mtx
modifier|*
name|up_mtx
decl_stmt|;
name|usb_size_t
name|up_msg_num
decl_stmt|;
name|uint8_t
name|up_prio
decl_stmt|;
name|uint8_t
name|up_gone
decl_stmt|;
name|uint8_t
name|up_msleep
decl_stmt|;
name|uint8_t
name|up_csleep
decl_stmt|;
name|uint8_t
name|up_dsleep
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|uint8_t
name|usb_proc_is_gone
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_proc_create
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|,
name|struct
name|mtx
modifier|*
name|p_mtx
parameter_list|,
specifier|const
name|char
modifier|*
name|pmesg
parameter_list|,
name|uint8_t
name|prio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_drain
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_mwait
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|,
name|void
modifier|*
name|pm0
parameter_list|,
name|void
modifier|*
name|pm1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_free
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usb_proc_msignal
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|,
name|void
modifier|*
name|pm0
parameter_list|,
name|void
modifier|*
name|pm1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_rewakeup
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb_proc_is_called_from
parameter_list|(
name|struct
name|usb_process
modifier|*
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_explore_mwait
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|usb_proc_explore_msignal
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_explore_lock
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_proc_explore_unlock
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_PROCESS_H_ */
end_comment

end_unit

