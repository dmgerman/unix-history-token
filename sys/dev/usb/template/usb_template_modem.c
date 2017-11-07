begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This file contains the USB template for an USB Modem Device.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USB_GLOBAL_INCLUDE_FILE
end_ifdef

begin_include
include|#
directive|include
include|USB_GLOBAL_INCLUDE_FILE
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/condvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usbdi.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_core.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_cdc.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/template/usb_template.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USB_GLOBAL_INCLUDE_FILE */
end_comment

begin_enum
enum|enum
block|{
name|INDEX_LANG
block|,
name|INDEX_MODEM
block|,
name|INDEX_PRODUCT
block|,
name|INDEX_MAX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|STRING_PRODUCT
define|\
value|"M\0o\0d\0e\0m\0 \0T\0e\0s\0t\0 \0D\0e\0v\0i\0c\0e"
end_define

begin_define
define|#
directive|define
name|STRING_MODEM
define|\
value|"M\0o\0d\0e\0m\0 \0i\0n\0t\0e\0r\0f\0a\0c\0e"
end_define

begin_comment
comment|/* make the real string descriptors */
end_comment

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_MODEM
argument_list|,
name|string_modem
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|USB_MAKE_STRING_DESC
argument_list|(
name|STRING_PRODUCT
argument_list|,
name|string_product
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MODEM_IFACE_0
value|0
end_define

begin_define
define|#
directive|define
name|MODEM_IFACE_1
value|1
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_packet_size
name|modem_bulk_mps
init|=
block|{
operator|.
name|mps
index|[
name|USB_SPEED_LOW
index|]
operator|=
literal|8
block|,
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
name|usb_temp_packet_size
name|modem_intr_mps
init|=
block|{
operator|.
name|mps
index|[
name|USB_SPEED_LOW
index|]
operator|=
literal|8
block|,
operator|.
name|mps
index|[
name|USB_SPEED_FULL
index|]
operator|=
literal|8
block|,
operator|.
name|mps
index|[
name|USB_SPEED_HIGH
index|]
operator|=
literal|8
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_interval
name|modem_intr_interval
init|=
block|{
operator|.
name|bInterval
index|[
name|USB_SPEED_LOW
index|]
operator|=
literal|8
block|,
comment|/* 8ms */
operator|.
name|bInterval
index|[
name|USB_SPEED_FULL
index|]
operator|=
literal|8
block|,
comment|/* 8ms */
operator|.
name|bInterval
index|[
name|USB_SPEED_HIGH
index|]
operator|=
literal|7
block|,
comment|/* 8ms */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_endpoint_desc
name|modem_ep_0
init|=
block|{
operator|.
name|pPacketSize
operator|=
operator|&
name|modem_intr_mps
block|,
operator|.
name|pIntervals
operator|=
operator|&
name|modem_intr_interval
block|,
operator|.
name|bEndpointAddress
operator|=
name|UE_DIR_IN
block|,
operator|.
name|bmAttributes
operator|=
name|UE_INTERRUPT
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_endpoint_desc
name|modem_ep_1
init|=
block|{
operator|.
name|pPacketSize
operator|=
operator|&
name|modem_bulk_mps
block|,
operator|.
name|bEndpointAddress
operator|=
name|UE_DIR_OUT
block|,
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
name|usb_temp_endpoint_desc
name|modem_ep_2
init|=
block|{
operator|.
name|pPacketSize
operator|=
operator|&
name|modem_bulk_mps
block|,
operator|.
name|bEndpointAddress
operator|=
name|UE_DIR_IN
block|,
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
name|usb_temp_endpoint_desc
modifier|*
name|modem_iface_0_ep
index|[]
init|=
block|{
operator|&
name|modem_ep_0
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_endpoint_desc
modifier|*
name|modem_iface_1_ep
index|[]
init|=
block|{
operator|&
name|modem_ep_1
block|,
operator|&
name|modem_ep_2
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|modem_raw_desc_0
index|[]
init|=
block|{
literal|0x05
block|,
literal|0x24
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x01
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|modem_raw_desc_1
index|[]
init|=
block|{
literal|0x05
block|,
literal|0x24
block|,
literal|0x06
block|,
name|MODEM_IFACE_0
block|,
name|MODEM_IFACE_1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|modem_raw_desc_2
index|[]
init|=
block|{
literal|0x05
block|,
literal|0x24
block|,
literal|0x01
block|,
literal|0x03
block|,
name|MODEM_IFACE_1
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|modem_raw_desc_3
index|[]
init|=
block|{
literal|0x04
block|,
literal|0x24
block|,
literal|0x02
block|,
literal|0x07
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|void
modifier|*
name|modem_iface_0_desc
index|[]
init|=
block|{
operator|&
name|modem_raw_desc_0
block|,
operator|&
name|modem_raw_desc_1
block|,
operator|&
name|modem_raw_desc_2
block|,
operator|&
name|modem_raw_desc_3
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_interface_desc
name|modem_iface_0
init|=
block|{
operator|.
name|ppRawDesc
operator|=
name|modem_iface_0_desc
block|,
operator|.
name|ppEndpoints
operator|=
name|modem_iface_0_ep
block|,
operator|.
name|bInterfaceClass
operator|=
name|UICLASS_CDC
block|,
operator|.
name|bInterfaceSubClass
operator|=
name|UISUBCLASS_ABSTRACT_CONTROL_MODEL
block|,
operator|.
name|bInterfaceProtocol
operator|=
name|UIPROTO_CDC_AT
block|,
operator|.
name|iInterface
operator|=
name|INDEX_MODEM
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_interface_desc
name|modem_iface_1
init|=
block|{
operator|.
name|ppEndpoints
operator|=
name|modem_iface_1_ep
block|,
operator|.
name|bInterfaceClass
operator|=
name|UICLASS_CDC_DATA
block|,
operator|.
name|bInterfaceSubClass
operator|=
name|UISUBCLASS_DATA
block|,
operator|.
name|bInterfaceProtocol
operator|=
name|UIPROTO_CDC_NONE
block|,
operator|.
name|iInterface
operator|=
name|INDEX_MODEM
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_interface_desc
modifier|*
name|modem_interfaces
index|[]
init|=
block|{
operator|&
name|modem_iface_0
block|,
operator|&
name|modem_iface_1
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_config_desc
name|modem_config_desc
init|=
block|{
operator|.
name|ppIfaceDesc
operator|=
name|modem_interfaces
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
name|INDEX_PRODUCT
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|usb_temp_config_desc
modifier|*
name|modem_configs
index|[]
init|=
block|{
operator|&
name|modem_config_desc
block|,
name|NULL
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_temp_get_string_desc_t
name|modem_get_string_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|usb_temp_get_vendor_desc_t
name|modem_get_vendor_desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|struct
name|usb_temp_device_desc
name|usb_template_modem
init|=
block|{
operator|.
name|getStringDesc
operator|=
operator|&
name|modem_get_string_desc
block|,
operator|.
name|getVendorDesc
operator|=
operator|&
name|modem_get_vendor_desc
block|,
operator|.
name|ppConfigDesc
operator|=
name|modem_configs
block|,
operator|.
name|idVendor
operator|=
name|USB_TEMPLATE_VENDOR
block|,
operator|.
name|idProduct
operator|=
literal|0x000E
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
literal|0
block|,
operator|.
name|iProduct
operator|=
name|INDEX_PRODUCT
block|,
operator|.
name|iSerialNumber
operator|=
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*------------------------------------------------------------------------*  *      modem_get_vendor_desc  *  * Return values:  * NULL: Failure. No such vendor descriptor.  * Else: Success. Pointer to vendor descriptor is returned.  *------------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
specifier|const
name|void
modifier|*
name|modem_get_vendor_desc
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
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/*------------------------------------------------------------------------*  *	modem_get_string_desc  *  * Return values:  * NULL: Failure. No such string.  * Else: Success. Pointer to string descriptor is returned.  *------------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
specifier|const
name|void
modifier|*
name|modem_get_string_desc
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
name|INDEX_MAX
index|]
init|=
block|{
index|[
name|INDEX_LANG
index|]
operator|=
operator|&
name|usb_string_lang_en
block|,
index|[
name|INDEX_MODEM
index|]
operator|=
operator|&
name|string_modem
block|,
index|[
name|INDEX_PRODUCT
index|]
operator|=
operator|&
name|string_product
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
name|usb_string_lang_en
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
name|INDEX_MAX
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

