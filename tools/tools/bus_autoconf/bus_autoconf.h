begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BUS_AUTOCONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_BUS_AUTOCONF_H_
end_define

begin_comment
comment|/* Make sure we get the have compat linux definition. */
end_comment

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_struct
struct|struct
name|usb_device_id
block|{
comment|/* Hook for driver specific information */
name|unsigned
name|long
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
if|#
directive|if
name|USB_HAVE_COMPAT_LINUX
comment|/* which fields to match against */
name|uint16_t
name|match_flags
decl_stmt|;
define|#
directive|define
name|USB_DEVICE_ID_MATCH_VENDOR
value|0x0001
define|#
directive|define
name|USB_DEVICE_ID_MATCH_PRODUCT
value|0x0002
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_LO
value|0x0004
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_HI
value|0x0008
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_CLASS
value|0x0010
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_SUBCLASS
value|0x0020
define|#
directive|define
name|USB_DEVICE_ID_MATCH_DEV_PROTOCOL
value|0x0040
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_CLASS
value|0x0080
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_SUBCLASS
value|0x0100
define|#
directive|define
name|USB_DEVICE_ID_MATCH_INT_PROTOCOL
value|0x0200
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BUS_AUTOCONF_H_ */
end_comment

end_unit

