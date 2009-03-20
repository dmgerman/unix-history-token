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
name|_USB2_LOOKUP_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_LOOKUP_H_
end_define

begin_struct_decl
struct_decl|struct
name|usb2_attach_arg
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The following structure is used when looking up an USB driver for  * an USB device. It is inspired by the Linux structure called  * "usb2_device_id".  */
end_comment

begin_struct
struct|struct
name|usb2_device_id
block|{
comment|/* Hook for driver specific information */
specifier|const
name|void
modifier|*
name|driver_info
decl_stmt|;
comment|/* Used for product specific matches; the BCD range is inclusive */
name|uint16_t
name|idVendor
decl_stmt|;
name|uint16_t
name|idProduct
decl_stmt|;
name|uint16_t
name|bcdDevice_lo
decl_stmt|;
name|uint16_t
name|bcdDevice_hi
decl_stmt|;
comment|/* Used for device class matches */
name|uint8_t
name|bDeviceClass
decl_stmt|;
name|uint8_t
name|bDeviceSubClass
decl_stmt|;
name|uint8_t
name|bDeviceProtocol
decl_stmt|;
comment|/* Used for interface class matches */
name|uint8_t
name|bInterfaceClass
decl_stmt|;
name|uint8_t
name|bInterfaceSubClass
decl_stmt|;
name|uint8_t
name|bInterfaceProtocol
decl_stmt|;
comment|/* Select which fields to match against */
name|uint8_t
name|match_flag_vendor
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_product
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_lo
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_hi
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_class
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_subclass
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_dev_protocol
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_class
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_subclass
range|:
literal|1
decl_stmt|;
name|uint8_t
name|match_flag_int_protocol
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_VENDOR
parameter_list|(
name|vend
parameter_list|)
define|\
value|.match_flag_vendor = 1, .idVendor = (vend)
end_define

begin_define
define|#
directive|define
name|USB_PRODUCT
parameter_list|(
name|prod
parameter_list|)
define|\
value|.match_flag_product = 1, .idProduct = (prod)
end_define

begin_define
define|#
directive|define
name|USB_VP
parameter_list|(
name|vend
parameter_list|,
name|prod
parameter_list|)
define|\
value|USB_VENDOR(vend), USB_PRODUCT(prod)
end_define

begin_define
define|#
directive|define
name|USB_VPI
parameter_list|(
name|vend
parameter_list|,
name|prod
parameter_list|,
name|info
parameter_list|)
define|\
value|USB_VENDOR(vend), USB_PRODUCT(prod), USB_DRIVER_INFO(info)
end_define

begin_define
define|#
directive|define
name|USB_DEV_BCD_GTEQ
parameter_list|(
name|lo
parameter_list|)
comment|/* greater than or equal */
define|\
value|.match_flag_dev_lo = 1, .bcdDevice_lo = (lo)
end_define

begin_define
define|#
directive|define
name|USB_DEV_BCD_LTEQ
parameter_list|(
name|hi
parameter_list|)
comment|/* less than or equal */
define|\
value|.match_flag_dev_hi = 1, .bcdDevice_hi = (hi)
end_define

begin_define
define|#
directive|define
name|USB_DEV_CLASS
parameter_list|(
name|dc
parameter_list|)
define|\
value|.match_flag_dev_class = 1, .bDeviceClass = (dc)
end_define

begin_define
define|#
directive|define
name|USB_DEV_SUBCLASS
parameter_list|(
name|dsc
parameter_list|)
define|\
value|.match_flag_dev_subclass = 1, .bDeviceSubClass = (dsc)
end_define

begin_define
define|#
directive|define
name|USB_DEV_PROTOCOL
parameter_list|(
name|dp
parameter_list|)
define|\
value|.match_flag_dev_protocol = 1, .bDeviceProtocol = (dp)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_CLASS
parameter_list|(
name|ic
parameter_list|)
define|\
value|.match_flag_int_class = 1, .bInterfaceClass = (ic)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_SUBCLASS
parameter_list|(
name|isc
parameter_list|)
define|\
value|.match_flag_int_subclass = 1, .bInterfaceSubClass = (isc)
end_define

begin_define
define|#
directive|define
name|USB_IFACE_PROTOCOL
parameter_list|(
name|ip
parameter_list|)
define|\
value|.match_flag_int_protocol = 1, .bInterfaceProtocol = (ip)
end_define

begin_define
define|#
directive|define
name|USB_IF_CSI
parameter_list|(
name|class
parameter_list|,
name|subclass
parameter_list|,
name|info
parameter_list|)
define|\
value|USB_IFACE_CLASS(class), USB_IFACE_SUBCLASS(subclass), USB_DRIVER_INFO(info)
end_define

begin_define
define|#
directive|define
name|USB_DRIVER_INFO
parameter_list|(
name|ptr
parameter_list|)
define|\
value|.driver_info = ((const void *)(ptr))
end_define

begin_define
define|#
directive|define
name|USB_GET_DRIVER_INFO
parameter_list|(
name|did
parameter_list|)
define|\
value|(((const uint8_t *)((did)->driver_info)) - ((const uint8_t *)0))
end_define

begin_function_decl
specifier|const
name|struct
name|usb2_device_id
modifier|*
name|usb2_lookup_id_by_info
parameter_list|(
specifier|const
name|struct
name|usb2_device_id
modifier|*
name|id
parameter_list|,
name|usb2_size_t
name|sizeof_id
parameter_list|,
specifier|const
name|struct
name|usb2_lookup_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|usb2_lookup_id_by_uaa
parameter_list|(
specifier|const
name|struct
name|usb2_device_id
modifier|*
name|id
parameter_list|,
name|usb2_size_t
name|sizeof_id
parameter_list|,
name|struct
name|usb2_attach_arg
modifier|*
name|uaa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_LOOKUP_H_ */
end_comment

end_unit

