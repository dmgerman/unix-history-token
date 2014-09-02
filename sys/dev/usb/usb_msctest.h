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
name|_USB_MSCTEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_MSCTEST_H_
end_define

begin_enum
enum|enum
block|{
name|MSC_EJECT_STOPUNIT
block|,
name|MSC_EJECT_REZERO
block|,
name|MSC_EJECT_ZTESTOR
block|,
name|MSC_EJECT_CMOTECH
block|,
name|MSC_EJECT_HUAWEI
block|,
name|MSC_EJECT_HUAWEI2
block|,
name|MSC_EJECT_TCT
block|, }
enum|;
end_enum

begin_function_decl
name|int
name|usb_iface_is_cdrom
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_msc_eject
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|int
name|method
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_msc_auto_quirk
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_msc_read_10
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint32_t
name|lba
parameter_list|,
name|uint32_t
name|blocks
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_msc_write_10
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint32_t
name|lba
parameter_list|,
name|uint32_t
name|blocks
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usb_msc_read_capacity
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint32_t
modifier|*
name|lba_last
parameter_list|,
name|uint32_t
modifier|*
name|block_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_MSCTEST_H_ */
end_comment

end_unit

