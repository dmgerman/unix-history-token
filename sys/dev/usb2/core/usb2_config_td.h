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
name|_USB2_CONFIG_TD_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_CONFIG_TD_H_
end_define

begin_struct_decl
struct_decl|struct
name|usb2_config_td_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb2_config_td_cc
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|USB2_CONFIG_TD_SYNC
value|0xFFFF
end_define

begin_comment
comment|/* magic value */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb2_config_td_command_t
function_decl|)
parameter_list|(
name|struct
name|usb2_config_td_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|usb2_config_td_cc
modifier|*
name|cc
parameter_list|,
name|uint16_t
name|reference
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|usb2_config_td_end_of_commands_t
function_decl|)
parameter_list|(
name|struct
name|usb2_config_td_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * The following structure defines a command that should be executed  * using the USB config thread system.  */
end_comment

begin_struct
struct|struct
name|usb2_config_td_item
block|{
name|struct
name|usb2_proc_msg
name|hdr
decl_stmt|;
name|struct
name|usb2_config_td
modifier|*
name|p_ctd
decl_stmt|;
name|usb2_config_td_command_t
modifier|*
name|command_func
decl_stmt|;
name|uint16_t
name|command_ref
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|USB_HOST_ALIGN
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines an USB config thread.  */
end_comment

begin_struct
struct|struct
name|usb2_config_td
block|{
name|struct
name|usb2_process
name|usb2_proc
decl_stmt|;
name|struct
name|usb2_config_td_softc
modifier|*
name|p_softc
decl_stmt|;
name|usb2_config_td_end_of_commands_t
modifier|*
name|p_end_of_commands
decl_stmt|;
name|void
modifier|*
name|p_msgs
decl_stmt|;
name|uint16_t
name|msg_size
decl_stmt|;
name|uint16_t
name|msg_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|uint8_t
name|usb2_config_td_setup
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|,
name|void
modifier|*
name|priv_sc
parameter_list|,
name|struct
name|mtx
modifier|*
name|priv_mtx
parameter_list|,
name|usb2_config_td_end_of_commands_t
modifier|*
name|p_func_eoc
parameter_list|,
name|uint16_t
name|item_size
parameter_list|,
name|uint16_t
name|item_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_config_td_drain
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_config_td_unsetup
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb2_config_td_queue_command
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|,
name|usb2_config_td_command_t
modifier|*
name|pre_func
parameter_list|,
name|usb2_config_td_command_t
modifier|*
name|post_func
parameter_list|,
name|uint16_t
name|command_sync
parameter_list|,
name|uint16_t
name|command_ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_config_td_is_gone
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_config_td_sleep
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|,
name|uint32_t
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|usb2_config_td_sync
parameter_list|(
name|struct
name|usb2_config_td
modifier|*
name|ctd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_CONFIG_TD_H_ */
end_comment

end_unit

