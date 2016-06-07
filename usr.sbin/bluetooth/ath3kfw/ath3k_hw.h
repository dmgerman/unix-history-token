begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Adrian Chadd<adrian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH3K_HW_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH3K_HW_H__
end_define

begin_define
define|#
directive|define
name|ATH3K_DNLOAD
value|0x01
end_define

begin_define
define|#
directive|define
name|ATH3K_GETSTATE
value|0x05
end_define

begin_define
define|#
directive|define
name|ATH3K_SET_NORMAL_MODE
value|0x07
end_define

begin_define
define|#
directive|define
name|ATH3K_GETVERSION
value|0x09
end_define

begin_define
define|#
directive|define
name|USB_REG_SWITCH_VID_PID
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATH3K_MODE_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|ATH3K_NORMAL_MODE
value|0x0E
end_define

begin_define
define|#
directive|define
name|ATH3K_PATCH_UPDATE
value|0x80
end_define

begin_define
define|#
directive|define
name|ATH3K_SYSCFG_UPDATE
value|0x40
end_define

begin_define
define|#
directive|define
name|ATH3K_XTAL_FREQ_26M
value|0x00
end_define

begin_define
define|#
directive|define
name|ATH3K_XTAL_FREQ_40M
value|0x01
end_define

begin_define
define|#
directive|define
name|ATH3K_XTAL_FREQ_19P2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATH3K_NAME_LEN
value|0xFF
end_define

begin_define
define|#
directive|define
name|USB_REQ_DFU_DNLOAD
value|1
end_define

begin_define
define|#
directive|define
name|BULK_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|FW_HDR_SIZE
value|20
end_define

begin_function_decl
specifier|extern
name|int
name|ath3k_load_fwfile
parameter_list|(
name|struct
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|,
specifier|const
name|struct
name|ath3k_firmware
modifier|*
name|fw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_get_state
parameter_list|(
name|struct
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|,
name|unsigned
name|char
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_get_version
parameter_list|(
name|struct
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|,
name|struct
name|ath3k_version
modifier|*
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_load_patch
parameter_list|(
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|,
specifier|const
name|char
modifier|*
name|fw_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_load_syscfg
parameter_list|(
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|,
specifier|const
name|char
modifier|*
name|fw_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_set_normal_mode
parameter_list|(
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath3k_switch_pid
parameter_list|(
name|libusb_device_handle
modifier|*
name|hdl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

