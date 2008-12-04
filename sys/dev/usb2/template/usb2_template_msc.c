begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky<hselasky@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This file contains the USB templates for an USB Mass Storage Device.  */
end_comment

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_standard.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/include/usb2_mfunc.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/core/usb2_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb2/template/usb2_template.h>
end_include

begin_enum
enum|enum
block|{
name|STRING_LANG_INDEX
block|,
name|STRING_MSC_DATA_INDEX
block|,
name|STRING_MSC_CONFIG_INDEX
block|,
name|STRING_MSC_VENDOR_INDEX
block|,
name|STRING_MSC_PRODUCT_INDEX
block|,
name|STRING_MSC_SERIAL_INDEX
block|,
name|STRING_MSC_MAX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|STRING_LANG
define|\
value|0x09, 0x04,
end_define

begin_comment
comment|/* American English */
end_comment

begin_define
define|#
directive|define
name|STRING_MSC_DATA
define|\
value|'U', 0, 'S', 0, 'B', 0, ' ', 0, \   'M', 0, 'a', 0, 's', 0, 's', 0, \   ' ', 0, 'S', 0, 't', 0, 'o', 0, \   'r', 0, 'a', 0, 'g', 0, 'e', 0, \   ' ', 0, 'I', 0, 'n', 0, 't', 0, \   'e', 0, 'r', 0, 'f', 0, 'a', 0, \   'c', 0, 'e', 0,
end_define

begin_define
define|#
directive|define
name|STRING_MSC_CONFIG
define|\
value|'D', 0, 'e', 0, 'f', 0, 'a', 0, \   'u', 0, 'l', 0, 't', 0, ' ', 0, \   'c', 0, 'o', 0, 'n', 0, 'f', 0, \   'i', 0, 'g', 0,
end_define

begin_define
define|#
directive|define
name|STRING_MSC_VENDOR
define|\
value|'F', 0, 'r', 0, 'e', 0, 'e', 0, \   'B', 0, 'S', 0, 'D', 0, ' ', 0, \   'f', 0, 'o', 0, 'u', 0, 'n', 0, \   'd', 0, 'a', 0, 't', 0, 'i', 0, \   'o', 0, 'n', 0,
end_define

begin_define
define|#
directive|define
name|STRING_MSC_PRODUCT
define|\
value|'U', 0, 'S', 0, 'B', 0, ' ', 0, \   'M', 0, 'e', 0, 'm', 0, 'o', 0, \   'r', 0, 'y', 0, ' ', 0, 'S', 0, \   't', 0, 'i', 0, 'c', 0, 'k', 0
end_define

begin_define
define|#
directive|define
name|STRING_MSC_SERIAL
define|\
value|'M', 0, 'a', 0, 'r', 0, 'c', 0, \   'h', 0, ' ', 0, '2', 0, '0', 0, \   '0', 0, '8', 0,
end_define

begin_comment
comment|/* make the real string descriptors */
end_comment

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_LANG
argument_list|,
name|string_lang
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MSC_DATA
argument_list|,
name|string_msc_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MSC_CONFIG
argument_list|,
name|string_msc_config
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MSC_VENDOR
argument_list|,
name|string_msc_vendor
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MSC_PRODUCT
argument_list|,
name|string_msc_product
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MSC_SERIAL
argument_list|,
name|string_msc_serial
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* prototypes */
end_comment

begin_decl_stmt
specifier|static
name|usb2_temp_get_string_desc_t
name|msc_get_string_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_packet_size
name|bulk_mps
init|=
block|{
operator|.
name|mps
index|[
name|USB_SPEED_FULL
index|]
operator|=
literal|64
block|,
operator|.
name|mps
index|[
name|USB_SPEED_HIGH
index|]
operator|=
literal|512
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_endpoint_desc
name|bulk_in_ep
init|=
block|{
operator|.
name|pPacketSize
operator|=
operator|&
name|bulk_mps
block|,
ifdef|#
directive|ifdef
name|USB_HIP_IN_EP_0
operator|.
name|bEndpointAddress
operator|=
name|USB_HIP_IN_EP_0
block|,
else|#
directive|else
operator|.
name|bEndpointAddress
operator|=
name|UE_DIR_IN
block|,
endif|#
directive|endif
operator|.
name|bmAttributes
operator|=
name|UE_BULK
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_endpoint_desc
name|bulk_out_ep
init|=
block|{
operator|.
name|pPacketSize
operator|=
operator|&
name|bulk_mps
block|,
ifdef|#
directive|ifdef
name|USB_HIP_OUT_EP_0
operator|.
name|bEndpointAddress
operator|=
name|USB_HIP_OUT_EP_0
block|,
else|#
directive|else
operator|.
name|bEndpointAddress
operator|=
name|UE_DIR_OUT
block|,
endif|#
directive|endif
operator|.
name|bmAttributes
operator|=
name|UE_BULK
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_endpoint_desc
modifier|*
name|msc_data_endpoints
index|[]
init|=
block|{
operator|&
name|bulk_in_ep
block|,
operator|&
name|bulk_out_ep
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_interface_desc
name|msc_data_interface
init|=
block|{
operator|.
name|ppEndpoints
operator|=
name|msc_data_endpoints
block|,
operator|.
name|bInterfaceClass
operator|=
name|UICLASS_MASS
block|,
operator|.
name|bInterfaceSubClass
operator|=
name|UISUBCLASS_SCSI
block|,
operator|.
name|bInterfaceProtocol
operator|=
name|UIPROTO_MASS_BBB
block|,
operator|.
name|iInterface
operator|=
name|STRING_MSC_DATA_INDEX
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_interface_desc
modifier|*
name|msc_interfaces
index|[]
init|=
block|{
operator|&
name|msc_data_interface
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_config_desc
name|msc_config_desc
init|=
block|{
operator|.
name|ppIfaceDesc
operator|=
name|msc_interfaces
block|,
operator|.
name|bmAttributes
operator|=
name|UC_BUS_POWERED
block|,
operator|.
name|bMaxPower
operator|=
literal|25
block|,
comment|/* 50 mA */
operator|.
name|iConfiguration
operator|=
name|STRING_MSC_CONFIG_INDEX
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb2_temp_config_desc
modifier|*
name|msc_configs
index|[]
init|=
block|{
operator|&
name|msc_config_desc
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|usb2_temp_device_desc
name|usb2_template_msc
init|=
block|{
operator|.
name|getStringDesc
operator|=
operator|&
name|msc_get_string_desc
block|,
operator|.
name|ppConfigDesc
operator|=
name|msc_configs
block|,
operator|.
name|idVendor
operator|=
literal|0x0001
block|,
operator|.
name|idProduct
operator|=
literal|0x0001
block|,
operator|.
name|bcdDevice
operator|=
literal|0x0100
block|,
operator|.
name|bDeviceClass
operator|=
name|UDCLASS_COMM
block|,
operator|.
name|bDeviceSubClass
operator|=
literal|0
block|,
operator|.
name|bDeviceProtocol
operator|=
literal|0
block|,
operator|.
name|iManufacturer
operator|=
name|STRING_MSC_VENDOR_INDEX
block|,
operator|.
name|iProduct
operator|=
name|STRING_MSC_PRODUCT_INDEX
block|,
operator|.
name|iSerialNumber
operator|=
name|STRING_MSC_SERIAL_INDEX
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*------------------------------------------------------------------------*  *	msc_get_string_desc  *  * Return values:  * NULL: Failure. No such string.  * Else: Success. Pointer to string descriptor is returned.  *------------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
specifier|const
name|void
modifier|*
name|msc_get_string_desc
parameter_list|(
name|uint16_t
name|lang_id
parameter_list|,
name|uint8_t
name|string_index
parameter_list|)
block|{
specifier|static
specifier|const
name|void
modifier|*
name|ptr
index|[
name|STRING_MSC_MAX
index|]
init|=
block|{
index|[
name|STRING_LANG_INDEX
index|]
operator|=
operator|&
name|string_lang
block|,
index|[
name|STRING_MSC_DATA_INDEX
index|]
operator|=
operator|&
name|string_msc_data
block|,
index|[
name|STRING_MSC_CONFIG_INDEX
index|]
operator|=
operator|&
name|string_msc_config
block|,
index|[
name|STRING_MSC_VENDOR_INDEX
index|]
operator|=
operator|&
name|string_msc_vendor
block|,
index|[
name|STRING_MSC_PRODUCT_INDEX
index|]
operator|=
operator|&
name|string_msc_product
block|,
index|[
name|STRING_MSC_SERIAL_INDEX
index|]
operator|=
operator|&
name|string_msc_serial
block|, 	}
decl_stmt|;
if|if
condition|(
name|string_index
operator|==
literal|0
condition|)
block|{
return|return
operator|(
operator|&
name|string_lang
operator|)
return|;
block|}
if|if
condition|(
name|lang_id
operator|!=
literal|0x0409
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
if|if
condition|(
name|string_index
operator|<
name|STRING_MSC_MAX
condition|)
block|{
return|return
operator|(
name|ptr
index|[
name|string_index
index|]
operator|)
return|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

