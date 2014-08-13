begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Hans Petter Selasky<hselasky@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* USB templates are used to build up real USB descriptors */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_TEMPLATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_TEMPLATE_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USB_TEMPLATE_VENDOR
end_ifndef

begin_define
define|#
directive|define
name|USB_TEMPLATE_VENDOR
value|0x0001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
function_decl|(
name|usb_temp_get_string_desc_t
function_decl|)
parameter_list|(
name|uint16_t
name|lang_id
parameter_list|,
name|uint8_t
name|string_index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
function_decl|(
name|usb_temp_get_vendor_desc_t
function_decl|)
parameter_list|(
specifier|const
name|struct
name|usb_device_request
modifier|*
name|req
parameter_list|,
name|uint16_t
modifier|*
name|plen
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|usb_temp_packet_size
block|{
name|uint16_t
name|mps
index|[
name|USB_SPEED_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_interval
block|{
name|uint8_t
name|bInterval
index|[
name|USB_SPEED_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_endpoint_desc
block|{
specifier|const
name|void
modifier|*
modifier|*
name|ppRawDesc
decl_stmt|;
specifier|const
name|struct
name|usb_temp_packet_size
modifier|*
name|pPacketSize
decl_stmt|;
specifier|const
name|struct
name|usb_temp_interval
modifier|*
name|pIntervals
decl_stmt|;
comment|/* 	 * If (bEndpointAddress& UE_ADDR) is non-zero the endpoint number 	 * is pre-selected for this endpoint descriptor. Else an endpoint 	 * number is automatically chosen. 	 */
name|uint8_t
name|bEndpointAddress
decl_stmt|;
comment|/* UE_DIR_IN or UE_DIR_OUT */
name|uint8_t
name|bmAttributes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_interface_desc
block|{
specifier|const
name|void
modifier|*
modifier|*
name|ppRawDesc
decl_stmt|;
specifier|const
name|struct
name|usb_temp_endpoint_desc
modifier|*
modifier|*
name|ppEndpoints
decl_stmt|;
name|uint8_t
name|bInterfaceClass
decl_stmt|;
name|uint8_t
name|bInterfaceSubClass
decl_stmt|;
name|uint8_t
name|bInterfaceProtocol
decl_stmt|;
name|uint8_t
name|iInterface
decl_stmt|;
name|uint8_t
name|isAltInterface
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_config_desc
block|{
specifier|const
name|struct
name|usb_temp_interface_desc
modifier|*
modifier|*
name|ppIfaceDesc
decl_stmt|;
name|uint8_t
name|bmAttributes
decl_stmt|;
name|uint8_t
name|bMaxPower
decl_stmt|;
name|uint8_t
name|iConfiguration
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_device_desc
block|{
name|usb_temp_get_string_desc_t
modifier|*
name|getStringDesc
decl_stmt|;
name|usb_temp_get_vendor_desc_t
modifier|*
name|getVendorDesc
decl_stmt|;
specifier|const
name|struct
name|usb_temp_config_desc
modifier|*
modifier|*
name|ppConfigDesc
decl_stmt|;
name|uint16_t
name|idVendor
decl_stmt|;
name|uint16_t
name|idProduct
decl_stmt|;
name|uint16_t
name|bcdDevice
decl_stmt|;
name|uint8_t
name|bDeviceClass
decl_stmt|;
name|uint8_t
name|bDeviceSubClass
decl_stmt|;
name|uint8_t
name|bDeviceProtocol
decl_stmt|;
name|uint8_t
name|iManufacturer
decl_stmt|;
name|uint8_t
name|iProduct
decl_stmt|;
name|uint8_t
name|iSerialNumber
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_temp_data
block|{
specifier|const
name|struct
name|usb_temp_device_desc
modifier|*
name|tdd
decl_stmt|;
name|struct
name|usb_device_descriptor
name|udd
decl_stmt|;
comment|/* device descriptor */
name|struct
name|usb_device_qualifier
name|udq
decl_stmt|;
comment|/* device qualifier */
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_audio
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_cdce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_kbd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_modem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_mouse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_msc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_mtp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_phone
decl_stmt|;
end_decl_stmt

begin_function_decl
name|usb_error_t
name|usb_temp_setup
parameter_list|(
name|struct
name|usb_device
modifier|*
parameter_list|,
specifier|const
name|struct
name|usb_temp_device_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_temp_unsetup
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
comment|/* _USB_TEMPLATE_H_ */
end_comment

end_unit

