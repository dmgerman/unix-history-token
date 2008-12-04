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
name|_USB2_MSCTEST_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_MSCTEST_H_
end_define

begin_function_decl
name|usb2_error_t
name|usb2_test_autoinstall
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|,
name|uint8_t
name|do_eject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb2_error_t
name|usb2_test_huawei
parameter_list|(
name|struct
name|usb2_device
modifier|*
name|udev
parameter_list|,
name|struct
name|usb2_attach_arg
modifier|*
name|uaa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_lookup_huawei
parameter_list|(
name|struct
name|usb2_attach_arg
modifier|*
name|uaa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Huawei specific defines */
end_comment

begin_define
define|#
directive|define
name|U3GINFO
parameter_list|(
name|flag
parameter_list|,
name|speed
parameter_list|)
value|((flag)|((speed) * 256))
end_define

begin_define
define|#
directive|define
name|U3G_GET_SPEED
parameter_list|(
name|uaa
parameter_list|)
value|(USB_GET_DRIVER_INFO(uaa) / 256)
end_define

begin_define
define|#
directive|define
name|U3GFL_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|U3GFL_HUAWEI_INIT
value|0x01
end_define

begin_comment
comment|/* Requires init command (Huawei 					 * cards) */
end_comment

begin_define
define|#
directive|define
name|U3GFL_SCSI_EJECT
value|0x02
end_define

begin_comment
comment|/* Requires SCSI eject command 					 * (Novatel) */
end_comment

begin_define
define|#
directive|define
name|U3GFL_SIERRA_INIT
value|0x04
end_define

begin_comment
comment|/* Requires init command (Sierra 					 * cards) */
end_comment

begin_define
define|#
directive|define
name|U3GSP_GPRS
value|0
end_define

begin_define
define|#
directive|define
name|U3GSP_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|U3GSP_CDMA
value|2
end_define

begin_define
define|#
directive|define
name|U3GSP_UMTS
value|3
end_define

begin_define
define|#
directive|define
name|U3GSP_HSDPA
value|4
end_define

begin_define
define|#
directive|define
name|U3GSP_HSUPA
value|5
end_define

begin_define
define|#
directive|define
name|U3GSP_HSPA
value|6
end_define

begin_define
define|#
directive|define
name|U3GSP_MAX
value|7
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_MSCTEST_H_ */
end_comment

end_unit

