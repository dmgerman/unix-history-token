begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb.h,v 1.63 2002/02/25 00:46:37 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$    */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dev/usb/usb_port.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|USB_STACK_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|USB_MAX_DEVICES
value|128
end_define

begin_define
define|#
directive|define
name|USB_START_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|USB_CONTROL_ENDPOINT
value|0
end_define

begin_define
define|#
directive|define
name|USB_MAX_ENDPOINTS
value|16
end_define

begin_define
define|#
directive|define
name|USB_FRAMES_PER_SECOND
value|1000
end_define

begin_comment
comment|/*  * The USB records contain some unaligned little-endian word  * components.  The U[SG]ETW macros take care of both the alignment  * and endian problem and should always be used to access non-byte  * values.  */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|uByte
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|uWord
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|uDWord
index|[
literal|4
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USETW2
parameter_list|(
name|w
parameter_list|,
name|h
parameter_list|,
name|l
parameter_list|)
value|((w)[0] = (u_int8_t)(l), (w)[1] = (u_int8_t)(h))
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|UGETW
parameter_list|(
name|w
parameter_list|)
value|((w)[0] | ((w)[1]<< 8))
end_define

begin_define
define|#
directive|define
name|USETW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|((w)[0] = (u_int8_t)(v), (w)[1] = (u_int8_t)((v)>> 8))
end_define

begin_define
define|#
directive|define
name|UGETDW
parameter_list|(
name|w
parameter_list|)
value|((w)[0] | ((w)[1]<< 8) | ((w)[2]<< 16) | ((w)[3]<< 24))
end_define

begin_define
define|#
directive|define
name|USETDW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|((w)[0] = (u_int8_t)(v), \ 		     (w)[1] = (u_int8_t)((v)>> 8), \ 		     (w)[2] = (u_int8_t)((v)>> 16), \ 		     (w)[3] = (u_int8_t)((v)>> 24))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*   * On little-endian machines that can handle unanliged accesses  * (e.g. i386) these macros can be replaced by the following.  */
end_comment

begin_define
define|#
directive|define
name|UGETW
parameter_list|(
name|w
parameter_list|)
value|(*(u_int16_t *)(w))
end_define

begin_define
define|#
directive|define
name|USETW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|(*(u_int16_t *)(w) = (v))
end_define

begin_define
define|#
directive|define
name|UGETDW
parameter_list|(
name|w
parameter_list|)
value|(*(u_int32_t *)(w))
end_define

begin_define
define|#
directive|define
name|USETDW
parameter_list|(
name|w
parameter_list|,
name|v
parameter_list|)
value|(*(u_int32_t *)(w) = (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UPACKED
value|__attribute__((__packed__))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bmRequestType
decl_stmt|;
name|uByte
name|bRequest
decl_stmt|;
name|uWord
name|wValue
decl_stmt|;
name|uWord
name|wIndex
decl_stmt|;
name|uWord
name|wLength
decl_stmt|;
block|}
name|UPACKED
name|usb_device_request_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|UT_WRITE
value|0x00
end_define

begin_define
define|#
directive|define
name|UT_READ
value|0x80
end_define

begin_define
define|#
directive|define
name|UT_STANDARD
value|0x00
end_define

begin_define
define|#
directive|define
name|UT_CLASS
value|0x20
end_define

begin_define
define|#
directive|define
name|UT_VENDOR
value|0x40
end_define

begin_define
define|#
directive|define
name|UT_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|UT_INTERFACE
value|0x01
end_define

begin_define
define|#
directive|define
name|UT_ENDPOINT
value|0x02
end_define

begin_define
define|#
directive|define
name|UT_OTHER
value|0x03
end_define

begin_define
define|#
directive|define
name|UT_READ_DEVICE
value|(UT_READ  | UT_STANDARD | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_READ_INTERFACE
value|(UT_READ  | UT_STANDARD | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_READ_ENDPOINT
value|(UT_READ  | UT_STANDARD | UT_ENDPOINT)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_DEVICE
value|(UT_WRITE | UT_STANDARD | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_INTERFACE
value|(UT_WRITE | UT_STANDARD | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_ENDPOINT
value|(UT_WRITE | UT_STANDARD | UT_ENDPOINT)
end_define

begin_define
define|#
directive|define
name|UT_READ_CLASS_DEVICE
value|(UT_READ  | UT_CLASS | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_READ_CLASS_INTERFACE
value|(UT_READ  | UT_CLASS | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_READ_CLASS_OTHER
value|(UT_READ  | UT_CLASS | UT_OTHER)
end_define

begin_define
define|#
directive|define
name|UT_READ_CLASS_ENDPOINT
value|(UT_READ  | UT_CLASS | UT_ENDPOINT)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_CLASS_DEVICE
value|(UT_WRITE | UT_CLASS | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_CLASS_INTERFACE
value|(UT_WRITE | UT_CLASS | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_CLASS_OTHER
value|(UT_WRITE | UT_CLASS | UT_OTHER)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_CLASS_ENDPOINT
value|(UT_WRITE | UT_CLASS | UT_ENDPOINT)
end_define

begin_define
define|#
directive|define
name|UT_READ_VENDOR_DEVICE
value|(UT_READ  | UT_VENDOR | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_READ_VENDOR_INTERFACE
value|(UT_READ  | UT_VENDOR | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_READ_VENDOR_OTHER
value|(UT_READ  | UT_VENDOR | UT_OTHER)
end_define

begin_define
define|#
directive|define
name|UT_READ_VENDOR_ENDPOINT
value|(UT_READ  | UT_VENDOR | UT_ENDPOINT)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_VENDOR_DEVICE
value|(UT_WRITE | UT_VENDOR | UT_DEVICE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_VENDOR_INTERFACE
value|(UT_WRITE | UT_VENDOR | UT_INTERFACE)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_VENDOR_OTHER
value|(UT_WRITE | UT_VENDOR | UT_OTHER)
end_define

begin_define
define|#
directive|define
name|UT_WRITE_VENDOR_ENDPOINT
value|(UT_WRITE | UT_VENDOR | UT_ENDPOINT)
end_define

begin_comment
comment|/* Requests */
end_comment

begin_define
define|#
directive|define
name|UR_GET_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|UR_CLEAR_FEATURE
value|0x01
end_define

begin_define
define|#
directive|define
name|UR_SET_FEATURE
value|0x03
end_define

begin_define
define|#
directive|define
name|UR_SET_ADDRESS
value|0x05
end_define

begin_define
define|#
directive|define
name|UR_GET_DESCRIPTOR
value|0x06
end_define

begin_define
define|#
directive|define
name|UDESC_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|UDESC_CONFIG
value|0x02
end_define

begin_define
define|#
directive|define
name|UDESC_STRING
value|0x03
end_define

begin_define
define|#
directive|define
name|UDESC_INTERFACE
value|0x04
end_define

begin_define
define|#
directive|define
name|UDESC_ENDPOINT
value|0x05
end_define

begin_define
define|#
directive|define
name|UDESC_DEVICE_QUALIFIER
value|0x06
end_define

begin_define
define|#
directive|define
name|UDESC_OTHER_SPEED_CONFIGURATION
value|0x07
end_define

begin_define
define|#
directive|define
name|UDESC_INTERFACE_POWER
value|0x08
end_define

begin_define
define|#
directive|define
name|UDESC_OTG
value|0x09
end_define

begin_define
define|#
directive|define
name|UDESC_CS_DEVICE
value|0x21
end_define

begin_comment
comment|/* class specific */
end_comment

begin_define
define|#
directive|define
name|UDESC_CS_CONFIG
value|0x22
end_define

begin_define
define|#
directive|define
name|UDESC_CS_STRING
value|0x23
end_define

begin_define
define|#
directive|define
name|UDESC_CS_INTERFACE
value|0x24
end_define

begin_define
define|#
directive|define
name|UDESC_CS_ENDPOINT
value|0x25
end_define

begin_define
define|#
directive|define
name|UDESC_HUB
value|0x29
end_define

begin_define
define|#
directive|define
name|UR_SET_DESCRIPTOR
value|0x07
end_define

begin_define
define|#
directive|define
name|UR_GET_CONFIG
value|0x08
end_define

begin_define
define|#
directive|define
name|UR_SET_CONFIG
value|0x09
end_define

begin_define
define|#
directive|define
name|UR_GET_INTERFACE
value|0x0a
end_define

begin_define
define|#
directive|define
name|UR_SET_INTERFACE
value|0x0b
end_define

begin_define
define|#
directive|define
name|UR_SYNCH_FRAME
value|0x0c
end_define

begin_comment
comment|/* Feature numbers */
end_comment

begin_define
define|#
directive|define
name|UF_ENDPOINT_HALT
value|0
end_define

begin_define
define|#
directive|define
name|UF_DEVICE_REMOTE_WAKEUP
value|1
end_define

begin_define
define|#
directive|define
name|UF_TEST_MODE
value|2
end_define

begin_define
define|#
directive|define
name|USB_MAX_IPACKET
value|8
end_define

begin_comment
comment|/* maximum size of the initial packet */
end_comment

begin_define
define|#
directive|define
name|USB_2_MAX_CTRL_PACKET
value|64
end_define

begin_define
define|#
directive|define
name|USB_2_MAX_BULK_PACKET
value|512
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDescriptorSubtype
decl_stmt|;
block|}
name|UPACKED
name|usb_descriptor_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|bcdUSB
decl_stmt|;
define|#
directive|define
name|UD_USB_2_0
value|0x0200
define|#
directive|define
name|UD_IS_USB2
parameter_list|(
name|d
parameter_list|)
value|(UGETW((d)->bcdUSB)>= UD_USB_2_0)
name|uByte
name|bDeviceClass
decl_stmt|;
name|uByte
name|bDeviceSubClass
decl_stmt|;
name|uByte
name|bDeviceProtocol
decl_stmt|;
name|uByte
name|bMaxPacketSize
decl_stmt|;
comment|/* The fields below are not part of the initial descriptor. */
name|uWord
name|idVendor
decl_stmt|;
name|uWord
name|idProduct
decl_stmt|;
name|uWord
name|bcdDevice
decl_stmt|;
name|uByte
name|iManufacturer
decl_stmt|;
name|uByte
name|iProduct
decl_stmt|;
name|uByte
name|iSerialNumber
decl_stmt|;
name|uByte
name|bNumConfigurations
decl_stmt|;
block|}
name|UPACKED
name|usb_device_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_DEVICE_DESCRIPTOR_SIZE
value|18
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|wTotalLength
decl_stmt|;
name|uByte
name|bNumInterface
decl_stmt|;
name|uByte
name|bConfigurationValue
decl_stmt|;
name|uByte
name|iConfiguration
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
define|#
directive|define
name|UC_BUS_POWERED
value|0x80
define|#
directive|define
name|UC_SELF_POWERED
value|0x40
define|#
directive|define
name|UC_REMOTE_WAKEUP
value|0x20
name|uByte
name|bMaxPower
decl_stmt|;
comment|/* max current in 2 mA units */
define|#
directive|define
name|UC_POWER_FACTOR
value|2
block|}
name|UPACKED
name|usb_config_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_CONFIG_DESCRIPTOR_SIZE
value|9
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bInterfaceNumber
decl_stmt|;
name|uByte
name|bAlternateSetting
decl_stmt|;
name|uByte
name|bNumEndpoints
decl_stmt|;
name|uByte
name|bInterfaceClass
decl_stmt|;
name|uByte
name|bInterfaceSubClass
decl_stmt|;
name|uByte
name|bInterfaceProtocol
decl_stmt|;
name|uByte
name|iInterface
decl_stmt|;
block|}
name|UPACKED
name|usb_interface_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_INTERFACE_DESCRIPTOR_SIZE
value|9
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bEndpointAddress
decl_stmt|;
define|#
directive|define
name|UE_GET_DIR
parameter_list|(
name|a
parameter_list|)
value|((a)& 0x80)
define|#
directive|define
name|UE_SET_DIR
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|((a) | (((d)&1)<< 7))
define|#
directive|define
name|UE_DIR_IN
value|0x80
define|#
directive|define
name|UE_DIR_OUT
value|0x00
define|#
directive|define
name|UE_ADDR
value|0x0f
define|#
directive|define
name|UE_GET_ADDR
parameter_list|(
name|a
parameter_list|)
value|((a)& UE_ADDR)
name|uByte
name|bmAttributes
decl_stmt|;
define|#
directive|define
name|UE_XFERTYPE
value|0x03
define|#
directive|define
name|UE_CONTROL
value|0x00
define|#
directive|define
name|UE_ISOCHRONOUS
value|0x01
define|#
directive|define
name|UE_BULK
value|0x02
define|#
directive|define
name|UE_INTERRUPT
value|0x03
define|#
directive|define
name|UE_GET_XFERTYPE
parameter_list|(
name|a
parameter_list|)
value|((a)& UE_XFERTYPE)
define|#
directive|define
name|UE_ISO_TYPE
value|0x0c
define|#
directive|define
name|UE_ISO_ASYNC
value|0x04
define|#
directive|define
name|UE_ISO_ADAPT
value|0x08
define|#
directive|define
name|UE_ISO_SYNC
value|0x0c
define|#
directive|define
name|UE_GET_ISO_TYPE
parameter_list|(
name|a
parameter_list|)
value|((a)& UE_ISO_TYPE)
name|uWord
name|wMaxPacketSize
decl_stmt|;
name|uByte
name|bInterval
decl_stmt|;
block|}
name|UPACKED
name|usb_endpoint_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_ENDPOINT_DESCRIPTOR_SIZE
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|bString
index|[
literal|127
index|]
decl_stmt|;
block|}
name|UPACKED
name|usb_string_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_MAX_STRING_LEN
value|128
end_define

begin_define
define|#
directive|define
name|USB_LANGUAGE_TABLE
value|0
end_define

begin_comment
comment|/* # of the string language id table */
end_comment

begin_comment
comment|/* Hub specific request */
end_comment

begin_define
define|#
directive|define
name|UR_GET_BUS_STATE
value|0x02
end_define

begin_define
define|#
directive|define
name|UR_CLEAR_TT_BUFFER
value|0x08
end_define

begin_define
define|#
directive|define
name|UR_RESET_TT
value|0x09
end_define

begin_define
define|#
directive|define
name|UR_GET_TT_STATE
value|0x0a
end_define

begin_define
define|#
directive|define
name|UR_STOP_TT
value|0x0b
end_define

begin_comment
comment|/* Hub features */
end_comment

begin_define
define|#
directive|define
name|UHF_C_HUB_LOCAL_POWER
value|0
end_define

begin_define
define|#
directive|define
name|UHF_C_HUB_OVER_CURRENT
value|1
end_define

begin_define
define|#
directive|define
name|UHF_PORT_CONNECTION
value|0
end_define

begin_define
define|#
directive|define
name|UHF_PORT_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|UHF_PORT_SUSPEND
value|2
end_define

begin_define
define|#
directive|define
name|UHF_PORT_OVER_CURRENT
value|3
end_define

begin_define
define|#
directive|define
name|UHF_PORT_RESET
value|4
end_define

begin_define
define|#
directive|define
name|UHF_PORT_POWER
value|8
end_define

begin_define
define|#
directive|define
name|UHF_PORT_LOW_SPEED
value|9
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_CONNECTION
value|16
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_ENABLE
value|17
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_SUSPEND
value|18
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_OVER_CURRENT
value|19
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_RESET
value|20
end_define

begin_define
define|#
directive|define
name|UHF_PORT_TEST
value|21
end_define

begin_define
define|#
directive|define
name|UHF_PORT_INDICATOR
value|22
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bDescLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bNbrPorts
decl_stmt|;
name|uWord
name|wHubCharacteristics
decl_stmt|;
define|#
directive|define
name|UHD_PWR
value|0x0003
define|#
directive|define
name|UHD_PWR_GANGED
value|0x0000
define|#
directive|define
name|UHD_PWR_INDIVIDUAL
value|0x0001
define|#
directive|define
name|UHD_PWR_NO_SWITCH
value|0x0002
define|#
directive|define
name|UHD_COMPOUND
value|0x0004
define|#
directive|define
name|UHD_OC
value|0x0018
define|#
directive|define
name|UHD_OC_GLOBAL
value|0x0000
define|#
directive|define
name|UHD_OC_INDIVIDUAL
value|0x0008
define|#
directive|define
name|UHD_OC_NONE
value|0x0010
define|#
directive|define
name|UHD_TT_THINK
value|0x0060
define|#
directive|define
name|UHD_TT_THINK_8
value|0x0000
define|#
directive|define
name|UHD_TT_THINK_16
value|0x0020
define|#
directive|define
name|UHD_TT_THINK_24
value|0x0040
define|#
directive|define
name|UHD_TT_THINK_32
value|0x0060
define|#
directive|define
name|UHD_PORT_IND
value|0x0080
name|uByte
name|bPwrOn2PwrGood
decl_stmt|;
comment|/* delay in 2 ms units */
define|#
directive|define
name|UHD_PWRON_FACTOR
value|2
name|uByte
name|bHubContrCurrent
decl_stmt|;
name|uByte
name|DeviceRemovable
index|[
literal|32
index|]
decl_stmt|;
comment|/* max 255 ports */
define|#
directive|define
name|UHD_NOT_REMOV
parameter_list|(
name|desc
parameter_list|,
name|i
parameter_list|)
define|\
value|(((desc)->DeviceRemovable[(i)/8]>> ((i) % 8))& 1)
comment|/* deprecated */
name|uByte
name|PortPowerCtrlMask
index|[
literal|1
index|]
decl_stmt|;
block|}
name|UPACKED
name|usb_hub_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_HUB_DESCRIPTOR_SIZE
value|9
end_define

begin_comment
comment|/* includes deprecated PortPowerCtrlMask */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|bcdUSB
decl_stmt|;
name|uByte
name|bDeviceClass
decl_stmt|;
name|uByte
name|bDeviceSubClass
decl_stmt|;
name|uByte
name|bDeviceProtocol
decl_stmt|;
name|uByte
name|bMaxPacketSize0
decl_stmt|;
name|uByte
name|bNumConfigurations
decl_stmt|;
name|uByte
name|bReserved
decl_stmt|;
block|}
name|UPACKED
name|usb_device_qualifier_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_DEVICE_QUALIFIER_SIZE
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
define|#
directive|define
name|UOTG_SRP
value|0x01
define|#
directive|define
name|UOTG_HNP
value|0x02
block|}
name|UPACKED
name|usb_otg_descriptor_t
typedef|;
end_typedef

begin_comment
comment|/* OTG feature selectors */
end_comment

begin_define
define|#
directive|define
name|UOTG_B_HNP_ENABLE
value|3
end_define

begin_define
define|#
directive|define
name|UOTG_A_HNP_SUPPORT
value|4
end_define

begin_define
define|#
directive|define
name|UOTG_A_ALT_HNP_SUPPORT
value|5
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|uWord
name|wStatus
decl_stmt|;
comment|/* Device status flags */
define|#
directive|define
name|UDS_SELF_POWERED
value|0x0001
define|#
directive|define
name|UDS_REMOTE_WAKEUP
value|0x0002
comment|/* Endpoint status flags */
define|#
directive|define
name|UES_HALT
value|0x0001
block|}
name|UPACKED
name|usb_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uWord
name|wHubStatus
decl_stmt|;
define|#
directive|define
name|UHS_LOCAL_POWER
value|0x0001
define|#
directive|define
name|UHS_OVER_CURRENT
value|0x0002
name|uWord
name|wHubChange
decl_stmt|;
block|}
name|UPACKED
name|usb_hub_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uWord
name|wPortStatus
decl_stmt|;
define|#
directive|define
name|UPS_CURRENT_CONNECT_STATUS
value|0x0001
define|#
directive|define
name|UPS_PORT_ENABLED
value|0x0002
define|#
directive|define
name|UPS_SUSPEND
value|0x0004
define|#
directive|define
name|UPS_OVERCURRENT_INDICATOR
value|0x0008
define|#
directive|define
name|UPS_RESET
value|0x0010
define|#
directive|define
name|UPS_PORT_POWER
value|0x0100
define|#
directive|define
name|UPS_LOW_SPEED
value|0x0200
define|#
directive|define
name|UPS_HIGH_SPEED
value|0x0400
define|#
directive|define
name|UPS_PORT_TEST
value|0x0800
define|#
directive|define
name|UPS_PORT_INDICATOR
value|0x1000
name|uWord
name|wPortChange
decl_stmt|;
define|#
directive|define
name|UPS_C_CONNECT_STATUS
value|0x0001
define|#
directive|define
name|UPS_C_PORT_ENABLED
value|0x0002
define|#
directive|define
name|UPS_C_SUSPEND
value|0x0004
define|#
directive|define
name|UPS_C_OVERCURRENT_INDICATOR
value|0x0008
define|#
directive|define
name|UPS_C_PORT_RESET
value|0x0010
block|}
name|UPACKED
name|usb_port_status_t
typedef|;
end_typedef

begin_comment
comment|/* Device class codes */
end_comment

begin_define
define|#
directive|define
name|UDCLASS_AUDIO
value|0x00
end_define

begin_define
define|#
directive|define
name|UDCLASS_COMM
value|0x02
end_define

begin_define
define|#
directive|define
name|UDCLASS_HID
value|0x00
end_define

begin_define
define|#
directive|define
name|UDCLASS_HUB
value|0x09
end_define

begin_define
define|#
directive|define
name|UDSUBCLASS_HUB
value|0
end_define

begin_define
define|#
directive|define
name|UDPROTO_FSHUB
value|0
end_define

begin_define
define|#
directive|define
name|UDPROTO_HSHUBSTT
value|1
end_define

begin_define
define|#
directive|define
name|UDPROTO_HSHUBMTT
value|2
end_define

begin_define
define|#
directive|define
name|UDCLASS_MASS
value|0x00
end_define

begin_comment
comment|/* Interface class codes */
end_comment

begin_define
define|#
directive|define
name|UICLASS_UNSPEC
value|0x00
end_define

begin_define
define|#
directive|define
name|UICLASS_AUDIO
value|0x01
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_AUDIOCONTROL
value|1
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_AUDIOSTREAM
value|2
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_MIDISTREAM
value|3
end_define

begin_define
define|#
directive|define
name|UICLASS_CDC
value|0x02
end_define

begin_comment
comment|/* communication */
end_comment

begin_define
define|#
directive|define
name|UISUBCLASS_DIRECT_LINE_CONTROL_MODEL
value|1
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_ABSTRACT_CONTROL_MODEL
value|2
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_TELEPHONE_CONTROL_MODEL
value|3
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_MULTICHANNEL_CONTROL_MODEL
value|4
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_CAPI_CONTROLMODEL
value|5
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_ETHERNET_NETWORKING_CONTROL_MODEL
value|6
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_ATM_NETWORKING_CONTROL_MODEL
value|7
end_define

begin_define
define|#
directive|define
name|UIPROTO_CDC_AT
value|1
end_define

begin_define
define|#
directive|define
name|UICLASS_HID
value|0x03
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_BOOT
value|1
end_define

begin_define
define|#
directive|define
name|UIPROTO_BOOT_KEYBOARD
value|1
end_define

begin_define
define|#
directive|define
name|UICLASS_PHYSICAL
value|0x05
end_define

begin_define
define|#
directive|define
name|UICLASS_PRINTER
value|0x07
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_PRINTER
value|1
end_define

begin_define
define|#
directive|define
name|UIPROTO_PRINTER_UNI
value|1
end_define

begin_define
define|#
directive|define
name|UIPROTO_PRINTER_BI
value|2
end_define

begin_define
define|#
directive|define
name|UIPROTO_PRINTER_1284
value|3
end_define

begin_define
define|#
directive|define
name|UICLASS_MASS
value|0x08
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_RBC
value|1
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_SFF8020I
value|2
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_QIC157
value|3
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_UFI
value|4
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_SFF8070I
value|5
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_SCSI
value|6
end_define

begin_define
define|#
directive|define
name|UIPROTO_MASS_CBI_I
value|0
end_define

begin_define
define|#
directive|define
name|UIPROTO_MASS_CBI
value|1
end_define

begin_define
define|#
directive|define
name|UIPROTO_MASS_BBB_OLD
value|2
end_define

begin_comment
comment|/* Not in the spec anymore */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_MASS_BBB
value|80
end_define

begin_comment
comment|/* 'P' for the Iomega Zip drive */
end_comment

begin_define
define|#
directive|define
name|UICLASS_HUB
value|0x09
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_HUB
value|0
end_define

begin_define
define|#
directive|define
name|UIPROTO_FSHUB
value|0
end_define

begin_define
define|#
directive|define
name|UIPROTO_HSHUBSTT
value|0
end_define

begin_comment
comment|/* Yes, same as previous */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_HSHUBMTT
value|1
end_define

begin_define
define|#
directive|define
name|UICLASS_CDC_DATA
value|0x0a
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_DATA
value|0
end_define

begin_define
define|#
directive|define
name|UIPROTO_DATA_ISDNBRI
value|0x30
end_define

begin_comment
comment|/* Physical iface */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_HDLC
value|0x31
end_define

begin_comment
comment|/* HDLC */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_TRANSPARENT
value|0x32
end_define

begin_comment
comment|/* Transparent */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_Q921M
value|0x50
end_define

begin_comment
comment|/* Management for Q921 */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_Q921
value|0x51
end_define

begin_comment
comment|/* Data for Q921 */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_Q921TM
value|0x52
end_define

begin_comment
comment|/* TEI multiplexer for Q921 */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_V42BIS
value|0x90
end_define

begin_comment
comment|/* Data compression */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_Q931
value|0x91
end_define

begin_comment
comment|/* Euro-ISDN */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_V120
value|0x92
end_define

begin_comment
comment|/* V.24 rate adaption */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_CAPI
value|0x93
end_define

begin_comment
comment|/* CAPI 2.0 commands */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_HOST_BASED
value|0xfd
end_define

begin_comment
comment|/* Host based driver */
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_PUF
value|0xfe
end_define

begin_comment
comment|/* see Prot. Unit Func. Desc.*/
end_comment

begin_define
define|#
directive|define
name|UIPROTO_DATA_VENDOR
value|0xff
end_define

begin_comment
comment|/* Vendor specific */
end_comment

begin_define
define|#
directive|define
name|UICLASS_FIRM_UPD
value|0x0c
end_define

begin_define
define|#
directive|define
name|UICLASS_APPL_SPEC
value|0xfe
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_FIRMWARE_DOWNLOAD
value|1
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_IRDA
value|2
end_define

begin_define
define|#
directive|define
name|UIPROTO_IRDA
value|0
end_define

begin_define
define|#
directive|define
name|UICLASS_VENDOR
value|0xff
end_define

begin_define
define|#
directive|define
name|USB_HUB_MAX_DEPTH
value|5
end_define

begin_comment
comment|/*   * Minimum time a device needs to be powered down to go through   * a power cycle.  XXX Are these time in the spec?  */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_DOWN_TIME
value|200
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_POWER_DOWN_TIME
value|100
end_define

begin_comment
comment|/* ms */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These are the values from the spec. */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_RESET_DELAY
value|10
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_ROOT_RESET_DELAY
value|50
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_RESET_SETTLE
value|10
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_POWERUP_DELAY
value|100
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_SET_ADDRESS_SETTLE
value|2
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_DELAY
value|(20*5)
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_WAIT
value|10
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_RECOVERY
value|10
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_EXTRA_POWER_UP_TIME
value|0
end_define

begin_comment
comment|/* ms */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Allow for marginal (i.e. non-conforming) devices. */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_RESET_DELAY
value|50
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_ROOT_RESET_DELAY
value|250
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_RESET_RECOVERY
value|50
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_PORT_POWERUP_DELAY
value|300
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_SET_ADDRESS_SETTLE
value|10
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_DELAY
value|(50*5)
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_WAIT
value|50
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_RESUME_RECOVERY
value|50
end_define

begin_comment
comment|/* ms */
end_comment

begin_define
define|#
directive|define
name|USB_EXTRA_POWER_UP_TIME
value|20
end_define

begin_comment
comment|/* ms */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USB_MIN_POWER
value|100
end_define

begin_comment
comment|/* mA */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_POWER
value|500
end_define

begin_comment
comment|/* mA */
end_comment

begin_define
define|#
directive|define
name|USB_BUS_RESET_DELAY
value|100
end_define

begin_comment
comment|/* ms XXX?*/
end_comment

begin_define
define|#
directive|define
name|USB_UNCONFIG_NO
value|0
end_define

begin_define
define|#
directive|define
name|USB_UNCONFIG_INDEX
value|(-1)
end_define

begin_comment
comment|/*** ioctl() related stuff ***/
end_comment

begin_struct
struct|struct
name|usb_ctl_request
block|{
name|int
name|ucr_addr
decl_stmt|;
name|usb_device_request_t
name|ucr_request
decl_stmt|;
name|void
modifier|*
name|ucr_data
decl_stmt|;
name|int
name|ucr_flags
decl_stmt|;
define|#
directive|define
name|USBD_SHORT_XFER_OK
value|0x04
comment|/* allow short reads */
name|int
name|ucr_actlen
decl_stmt|;
comment|/* actual length transferred */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_alt_interface
block|{
name|int
name|uai_config_index
decl_stmt|;
name|int
name|uai_interface_index
decl_stmt|;
name|int
name|uai_alt_no
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_CURRENT_CONFIG_INDEX
value|(-1)
end_define

begin_define
define|#
directive|define
name|USB_CURRENT_ALT_INDEX
value|(-1)
end_define

begin_struct
struct|struct
name|usb_config_desc
block|{
name|int
name|ucd_config_index
decl_stmt|;
name|usb_config_descriptor_t
name|ucd_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_interface_desc
block|{
name|int
name|uid_config_index
decl_stmt|;
name|int
name|uid_interface_index
decl_stmt|;
name|int
name|uid_alt_index
decl_stmt|;
name|usb_interface_descriptor_t
name|uid_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_endpoint_desc
block|{
name|int
name|ued_config_index
decl_stmt|;
name|int
name|ued_interface_index
decl_stmt|;
name|int
name|ued_alt_index
decl_stmt|;
name|int
name|ued_endpoint_index
decl_stmt|;
name|usb_endpoint_descriptor_t
name|ued_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_full_desc
block|{
name|int
name|ufd_config_index
decl_stmt|;
name|u_int
name|ufd_size
decl_stmt|;
name|u_char
modifier|*
name|ufd_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_string_desc
block|{
name|int
name|usd_string_index
decl_stmt|;
name|int
name|usd_language_id
decl_stmt|;
name|usb_string_descriptor_t
name|usd_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_ctl_report_desc
block|{
name|int
name|ucrd_size
decl_stmt|;
name|u_char
name|ucrd_data
index|[
literal|1024
index|]
decl_stmt|;
comment|/* filled data size will vary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|cookie
decl_stmt|;
block|}
name|usb_event_cookie_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_MAX_DEVNAMES
value|4
end_define

begin_define
define|#
directive|define
name|USB_MAX_DEVNAMELEN
value|16
end_define

begin_struct
struct|struct
name|usb_device_info
block|{
name|u_int8_t
name|udi_bus
decl_stmt|;
name|u_int8_t
name|udi_addr
decl_stmt|;
comment|/* device address */
name|usb_event_cookie_t
name|udi_cookie
decl_stmt|;
name|char
name|udi_product
index|[
name|USB_MAX_STRING_LEN
index|]
decl_stmt|;
name|char
name|udi_vendor
index|[
name|USB_MAX_STRING_LEN
index|]
decl_stmt|;
name|char
name|udi_release
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|udi_productNo
decl_stmt|;
name|u_int16_t
name|udi_vendorNo
decl_stmt|;
name|u_int16_t
name|udi_releaseNo
decl_stmt|;
name|u_int8_t
name|udi_class
decl_stmt|;
name|u_int8_t
name|udi_subclass
decl_stmt|;
name|u_int8_t
name|udi_protocol
decl_stmt|;
name|u_int8_t
name|udi_config
decl_stmt|;
name|u_int8_t
name|udi_speed
decl_stmt|;
define|#
directive|define
name|USB_SPEED_LOW
value|1
define|#
directive|define
name|USB_SPEED_FULL
value|2
define|#
directive|define
name|USB_SPEED_HIGH
value|3
name|int
name|udi_power
decl_stmt|;
comment|/* power consumption in mA, 0 if selfpowered */
name|int
name|udi_nports
decl_stmt|;
name|char
name|udi_devnames
index|[
name|USB_MAX_DEVNAMES
index|]
index|[
name|USB_MAX_DEVNAMELEN
index|]
decl_stmt|;
name|u_int8_t
name|udi_ports
index|[
literal|16
index|]
decl_stmt|;
comment|/* hub only: addresses of devices on ports */
define|#
directive|define
name|USB_PORT_ENABLED
value|0xff
define|#
directive|define
name|USB_PORT_SUSPENDED
value|0xfe
define|#
directive|define
name|USB_PORT_POWERED
value|0xfd
define|#
directive|define
name|USB_PORT_DISABLED
value|0xfc
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_ctl_report
block|{
name|int
name|ucr_report
decl_stmt|;
name|u_char
name|ucr_data
index|[
literal|1024
index|]
decl_stmt|;
comment|/* filled data size will vary */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|usb_device_stats
block|{
name|u_long
name|uds_requests
index|[
literal|4
index|]
decl_stmt|;
comment|/* indexed by transfer type UE_* */
block|}
struct|;
end_struct

begin_comment
comment|/* Events that can be read from /dev/usb */
end_comment

begin_struct
struct|struct
name|usb_event
block|{
name|int
name|ue_type
decl_stmt|;
define|#
directive|define
name|USB_EVENT_CTRLR_ATTACH
value|1
define|#
directive|define
name|USB_EVENT_CTRLR_DETACH
value|2
define|#
directive|define
name|USB_EVENT_DEVICE_ATTACH
value|3
define|#
directive|define
name|USB_EVENT_DEVICE_DETACH
value|4
define|#
directive|define
name|USB_EVENT_DRIVER_ATTACH
value|5
define|#
directive|define
name|USB_EVENT_DRIVER_DETACH
value|6
define|#
directive|define
name|USB_EVENT_IS_ATTACH
parameter_list|(
name|n
parameter_list|)
value|((n) == USB_EVENT_CTRLR_ATTACH || (n) == USB_EVENT_DEVICE_ATTACH || (n) == USB_EVENT_DRIVER_ATTACH)
define|#
directive|define
name|USB_EVENT_IS_DETACH
parameter_list|(
name|n
parameter_list|)
value|((n) == USB_EVENT_CTRLR_DETACH || (n) == USB_EVENT_DEVICE_DETACH || (n) == USB_EVENT_DRIVER_DETACH)
name|struct
name|timespec
name|ue_time
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|int
name|ue_bus
decl_stmt|;
block|}
name|ue_ctrlr
struct|;
name|struct
name|usb_device_info
name|ue_device
decl_stmt|;
struct|struct
block|{
name|usb_event_cookie_t
name|ue_cookie
decl_stmt|;
name|char
name|ue_devname
index|[
literal|16
index|]
decl_stmt|;
block|}
name|ue_driver
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* USB controller */
end_comment

begin_define
define|#
directive|define
name|USB_REQUEST
value|_IOWR('U', 1, struct usb_ctl_request)
end_define

begin_define
define|#
directive|define
name|USB_SETDEBUG
value|_IOW ('U', 2, int)
end_define

begin_define
define|#
directive|define
name|USB_DISCOVER
value|_IO  ('U', 3)
end_define

begin_define
define|#
directive|define
name|USB_DEVICEINFO
value|_IOWR('U', 4, struct usb_device_info)
end_define

begin_define
define|#
directive|define
name|USB_DEVICESTATS
value|_IOR ('U', 5, struct usb_device_stats)
end_define

begin_comment
comment|/* Generic HID device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_REPORT_DESC
value|_IOR ('U', 21, struct usb_ctl_report_desc)
end_define

begin_define
define|#
directive|define
name|USB_SET_IMMED
value|_IOW ('U', 22, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_REPORT
value|_IOWR('U', 23, struct usb_ctl_report)
end_define

begin_define
define|#
directive|define
name|USB_SET_REPORT
value|_IOW ('U', 24, struct usb_ctl_report)
end_define

begin_define
define|#
directive|define
name|USB_GET_REPORT_ID
value|_IOR ('U', 25, int)
end_define

begin_comment
comment|/* Generic USB device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_CONFIG
value|_IOR ('U', 100, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_CONFIG
value|_IOW ('U', 101, int)
end_define

begin_define
define|#
directive|define
name|USB_GET_ALTINTERFACE
value|_IOWR('U', 102, struct usb_alt_interface)
end_define

begin_define
define|#
directive|define
name|USB_SET_ALTINTERFACE
value|_IOWR('U', 103, struct usb_alt_interface)
end_define

begin_define
define|#
directive|define
name|USB_GET_NO_ALT
value|_IOWR('U', 104, struct usb_alt_interface)
end_define

begin_define
define|#
directive|define
name|USB_GET_DEVICE_DESC
value|_IOR ('U', 105, usb_device_descriptor_t)
end_define

begin_define
define|#
directive|define
name|USB_GET_CONFIG_DESC
value|_IOWR('U', 106, struct usb_config_desc)
end_define

begin_define
define|#
directive|define
name|USB_GET_INTERFACE_DESC
value|_IOWR('U', 107, struct usb_interface_desc)
end_define

begin_define
define|#
directive|define
name|USB_GET_ENDPOINT_DESC
value|_IOWR('U', 108, struct usb_endpoint_desc)
end_define

begin_define
define|#
directive|define
name|USB_GET_FULL_DESC
value|_IOWR('U', 109, struct usb_full_desc)
end_define

begin_define
define|#
directive|define
name|USB_GET_STRING_DESC
value|_IOWR('U', 110, struct usb_string_desc)
end_define

begin_define
define|#
directive|define
name|USB_DO_REQUEST
value|_IOWR('U', 111, struct usb_ctl_request)
end_define

begin_define
define|#
directive|define
name|USB_GET_DEVICEINFO
value|_IOR ('U', 112, struct usb_device_info)
end_define

begin_define
define|#
directive|define
name|USB_SET_SHORT_XFER
value|_IOW ('U', 113, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_TIMEOUT
value|_IOW ('U', 114, int)
end_define

begin_comment
comment|/* Modem device */
end_comment

begin_define
define|#
directive|define
name|USB_GET_CM_OVER_DATA
value|_IOR ('U', 130, int)
end_define

begin_define
define|#
directive|define
name|USB_SET_CM_OVER_DATA
value|_IOW ('U', 131, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_H_ */
end_comment

end_unit

