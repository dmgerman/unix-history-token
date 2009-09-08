begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  * Copyright (c) 1998 The NetBSD Foundation, Inc. All rights reserved.  * Copyright (c) 1998 Lennart Augustsson. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * This file contains standard definitions for the following USB  * protocol versions:  *  * USB v1.0  * USB v1.1  * USB v2.0  * USB v3.0  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_STANDARD_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_STANDARD_H_
end_define

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
file|"opt_usb.h"
end_include

begin_comment
comment|/* Declare parent SYSCTL USB node. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_usb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBDEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_USBHC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<dev/usb/usb_endian.h>
end_include

begin_include
include|#
directive|include
file|<dev/usb/usb_freebsd.h>
end_include

begin_define
define|#
directive|define
name|USB_STACK_VERSION
value|2000
end_define

begin_comment
comment|/* 2.0 */
end_comment

begin_comment
comment|/* Definition of some hardcoded USB constants. */
end_comment

begin_define
define|#
directive|define
name|USB_MAX_IPACKET
value|8
end_define

begin_comment
comment|/* initial USB packet size */
end_comment

begin_define
define|#
directive|define
name|USB_EP_MAX
value|(2*16)
end_define

begin_comment
comment|/* hardcoded */
end_comment

begin_define
define|#
directive|define
name|USB_ROOT_HUB_ADDR
value|1
end_define

begin_comment
comment|/* index */
end_comment

begin_define
define|#
directive|define
name|USB_MIN_DEVICES
value|2
end_define

begin_comment
comment|/* unused + root HUB */
end_comment

begin_define
define|#
directive|define
name|USB_UNCONFIG_INDEX
value|0xFF
end_define

begin_comment
comment|/* internal use only */
end_comment

begin_define
define|#
directive|define
name|USB_IFACE_INDEX_ANY
value|0xFF
end_define

begin_comment
comment|/* internal use only */
end_comment

begin_define
define|#
directive|define
name|USB_START_ADDR
value|0
end_define

begin_comment
comment|/* default USB device BUS address 					 * after USB bus reset */
end_comment

begin_define
define|#
directive|define
name|USB_CONTROL_ENDPOINT
value|0
end_define

begin_comment
comment|/* default control endpoint */
end_comment

begin_define
define|#
directive|define
name|USB_FRAMES_PER_SECOND_FS
value|1000
end_define

begin_comment
comment|/* full speed */
end_comment

begin_define
define|#
directive|define
name|USB_FRAMES_PER_SECOND_HS
value|8000
end_define

begin_comment
comment|/* high speed */
end_comment

begin_define
define|#
directive|define
name|USB_FS_BYTES_PER_HS_UFRAME
value|188
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|USB_HS_MICRO_FRAMES_MAX
value|8
end_define

begin_comment
comment|/* units */
end_comment

begin_define
define|#
directive|define
name|USB_ISOC_TIME_MAX
value|128
end_define

begin_comment
comment|/* ms */
end_comment

begin_comment
comment|/*  * Minimum time a device needs to be powered down to go through a  * power cycle. These values are not in the USB specification.  */
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

begin_comment
comment|/* Definition of software USB power modes */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_MODE_OFF
value|0
end_define

begin_comment
comment|/* turn off device */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_MODE_ON
value|1
end_define

begin_comment
comment|/* always on */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_MODE_SAVE
value|2
end_define

begin_comment
comment|/* automatic suspend and resume */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_MODE_SUSPEND
value|3
end_define

begin_comment
comment|/* force suspend */
end_comment

begin_define
define|#
directive|define
name|USB_POWER_MODE_RESUME
value|4
end_define

begin_comment
comment|/* force resume */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* These are the values from the USB specification. */
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
name|USB_PORT_RESET_RECOVERY
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
name|USB_PORT_RESUME_DELAY
value|20
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
comment|/* Allow for marginal and non-conforming devices. */
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
value|250
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
name|USB_PORT_RESUME_DELAY
value|(20*2)
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
comment|/* ms */
end_comment

begin_comment
comment|/*  * USB record layout in memory:  *  * - USB config 0  *   - USB interfaces  *     - USB alternative interfaces  *       - USB endpoints  *  * - USB config 1  *   - USB interfaces  *     - USB alternative interfaces  *       - USB endpoints  */
end_comment

begin_comment
comment|/* Declaration of USB records */
end_comment

begin_struct
struct|struct
name|usb_device_request
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_device_request
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
name|USB_LANGUAGE_TABLE
value|0x00
end_define

begin_comment
comment|/* language ID string index */
end_comment

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
name|UDESC_DEBUG
value|0x0A
end_define

begin_define
define|#
directive|define
name|UDESC_IFACE_ASSOC
value|0x0B
end_define

begin_comment
comment|/* interface association */
end_comment

begin_define
define|#
directive|define
name|UDESC_BOS
value|0x0F
end_define

begin_comment
comment|/* binary object store */
end_comment

begin_define
define|#
directive|define
name|UDESC_DEVICE_CAPABILITY
value|0x10
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
name|UDESC_ENDPOINT_SS_COMP
value|0x30
end_define

begin_comment
comment|/* super speed */
end_comment

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

begin_define
define|#
directive|define
name|UR_SET_SEL
value|0x30
end_define

begin_define
define|#
directive|define
name|UR_ISOCH_DELAY
value|0x31
end_define

begin_comment
comment|/* HUB specific request */
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

begin_define
define|#
directive|define
name|UR_SET_HUB_DEPTH
value|0x0c
end_define

begin_define
define|#
directive|define
name|UR_GET_PORT_ERR_COUNT
value|0x0d
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
name|UF_U1_ENABLE
value|0x30
end_define

begin_define
define|#
directive|define
name|UF_U2_ENABLE
value|0x31
end_define

begin_define
define|#
directive|define
name|UF_LTM_ENABLE
value|0x32
end_define

begin_comment
comment|/* HUB specific features */
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
name|UHF_PORT_LINK_STATE
value|5
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

begin_comment
comment|/* SuperSpeed HUB specific features */
end_comment

begin_define
define|#
directive|define
name|UHF_PORT_U1_TIMEOUT
value|23
end_define

begin_define
define|#
directive|define
name|UHF_PORT_U2_TIMEOUT
value|24
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_LINK_STATE
value|25
end_define

begin_define
define|#
directive|define
name|UHF_C_PORT_CONFIG_ERROR
value|26
end_define

begin_define
define|#
directive|define
name|UHF_PORT_REMOTE_WAKE_MASK
value|27
end_define

begin_define
define|#
directive|define
name|UHF_BH_PORT_RESET
value|28
end_define

begin_define
define|#
directive|define
name|UHF_C_BH_PORT_RESET
value|29
end_define

begin_define
define|#
directive|define
name|UHF_FORCE_LINKPM_ACCEPT
value|30
end_define

begin_struct
struct|struct
name|usb_descriptor
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_descriptor
name|usb_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_device_descriptor
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
name|UD_USB_3_0
value|0x0300
define|#
directive|define
name|UD_IS_USB2
parameter_list|(
name|d
parameter_list|)
value|((d)->bcdUSB[1] == 0x02)
define|#
directive|define
name|UD_IS_USB3
parameter_list|(
name|d
parameter_list|)
value|((d)->bcdUSB[1] == 0x03)
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_device_descriptor
name|usb_device_descriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Binary Device Object Store (BOS) */
end_comment

begin_struct
struct|struct
name|usb_bos_descriptor
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
name|bNumDeviceCaps
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_bos_descriptor
name|usb_bos_descriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Binary Device Object Store Capability */
end_comment

begin_struct
struct|struct
name|usb_bos_cap_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDevCapabilityType
decl_stmt|;
define|#
directive|define
name|USB_DEVCAP_RESERVED
value|0x00
define|#
directive|define
name|USB_DEVCAP_WUSB
value|0x01
define|#
directive|define
name|USB_DEVCAP_USB2EXT
value|0x02
define|#
directive|define
name|USB_DEVCAP_SUPER_SPEED
value|0x03
define|#
directive|define
name|USB_DEVCAP_CONTAINER_ID
value|0x04
comment|/* data ... */
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_bos_cap_descriptor
name|usb_bos_cap_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_devcap_usb2ext_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDevCapabilityType
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
define|#
directive|define
name|USB_V2EXT_LPM
value|0x02
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_devcap_usb2ext_descriptor
name|usb_devcap_usb2ext_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_devcap_ss_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDevCapabilityType
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
name|uWord
name|wSpeedsSupported
decl_stmt|;
name|uByte
name|bFunctionaltySupport
decl_stmt|;
name|uByte
name|bU1DevExitLat
decl_stmt|;
name|uByte
name|bU2DevExitLat
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_devcap_ss_descriptor
name|usb_devcap_ss_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_devcap_container_id_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bDevCapabilityType
decl_stmt|;
name|uByte
name|bReserved
decl_stmt|;
name|uByte
name|ContainerID
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_devcap_container_id_descriptor
name|usb_devcap_container_id_descriptor_t
typedef|;
end_typedef

begin_comment
comment|/* Device class codes */
end_comment

begin_define
define|#
directive|define
name|UDCLASS_IN_INTERFACE
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
name|UDCLASS_HUB
value|0x09
end_define

begin_define
define|#
directive|define
name|UDSUBCLASS_HUB
value|0x00
end_define

begin_define
define|#
directive|define
name|UDPROTO_FSHUB
value|0x00
end_define

begin_define
define|#
directive|define
name|UDPROTO_HSHUBSTT
value|0x01
end_define

begin_define
define|#
directive|define
name|UDPROTO_HSHUBMTT
value|0x02
end_define

begin_define
define|#
directive|define
name|UDCLASS_DIAGNOSTIC
value|0xdc
end_define

begin_define
define|#
directive|define
name|UDCLASS_WIRELESS
value|0xe0
end_define

begin_define
define|#
directive|define
name|UDSUBCLASS_RF
value|0x01
end_define

begin_define
define|#
directive|define
name|UDPROTO_BLUETOOTH
value|0x01
end_define

begin_define
define|#
directive|define
name|UDCLASS_VENDOR
value|0xff
end_define

begin_struct
struct|struct
name|usb_config_descriptor
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
define|#
directive|define
name|USB_UNCONFIG_NO
value|0
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_config_descriptor
name|usb_config_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_interface_descriptor
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_interface_descriptor
name|usb_interface_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_interface_assoc_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uByte
name|bFirstInterface
decl_stmt|;
name|uByte
name|bInterfaceCount
decl_stmt|;
name|uByte
name|bFunctionClass
decl_stmt|;
name|uByte
name|bFunctionSubClass
decl_stmt|;
name|uByte
name|bFunctionProtocol
decl_stmt|;
name|uByte
name|iFunction
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_interface_assoc_descriptor
name|usb_interface_assoc_descriptor_t
typedef|;
end_typedef

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

begin_comment
comment|/* audio */
end_comment

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
name|UISUBCLASS_WIRELESS_HANDSET_CM
value|8
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_DEVICE_MGMT
value|9
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_MOBILE_DIRECT_LINE_MODEL
value|10
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_OBEX
value|11
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_ETHERNET_EMULATION_MODEL
value|12
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
name|UIPROTO_CDC_ETH_512X4
value|0x76
end_define

begin_comment
comment|/* FreeBSD specific */
end_comment

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
name|UIPROTO_MOUSE
value|2
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
name|UICLASS_IMAGE
value|0x06
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_SIC
value|1
end_define

begin_comment
comment|/* still image class */
end_comment

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
comment|/* see Prot. Unit Func. Desc. */
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
name|UICLASS_SMARTCARD
value|0x0b
end_define

begin_define
define|#
directive|define
name|UICLASS_FIRM_UPD
value|0x0c
end_define

begin_define
define|#
directive|define
name|UICLASS_SECURITY
value|0x0d
end_define

begin_define
define|#
directive|define
name|UICLASS_DIAGNOSTIC
value|0xdc
end_define

begin_define
define|#
directive|define
name|UICLASS_WIRELESS
value|0xe0
end_define

begin_define
define|#
directive|define
name|UISUBCLASS_RF
value|0x01
end_define

begin_define
define|#
directive|define
name|UIPROTO_BLUETOOTH
value|0x01
end_define

begin_define
define|#
directive|define
name|UICLASS_IAD
value|0xEF
end_define

begin_comment
comment|/* Interface Association Descriptor */
end_comment

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
name|UISUBCLASS_XBOX360_CONTROLLER
value|0x5d
end_define

begin_define
define|#
directive|define
name|UIPROTO_XBOX360_GAMEPAD
value|0x01
end_define

begin_struct
struct|struct
name|usb_endpoint_descriptor
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
comment|/* IN-token endpoint, fixed */
define|#
directive|define
name|UE_DIR_OUT
value|0x00
comment|/* OUT-token endpoint, fixed */
define|#
directive|define
name|UE_DIR_RX
value|0xfd
comment|/* for internal use only! */
define|#
directive|define
name|UE_DIR_TX
value|0xfe
comment|/* for internal use only! */
define|#
directive|define
name|UE_DIR_ANY
value|0xff
comment|/* for internal use only! */
define|#
directive|define
name|UE_ADDR
value|0x0f
define|#
directive|define
name|UE_ADDR_ANY
value|0xff
comment|/* for internal use only! */
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
name|UE_BULK_INTR
value|0xfe
comment|/* for internal use only! */
define|#
directive|define
name|UE_TYPE_ANY
value|0xff
comment|/* for internal use only! */
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
define|#
directive|define
name|UE_ZERO_MPS
value|0xFFFF
comment|/* for internal use only */
name|uByte
name|bInterval
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_endpoint_descriptor
name|usb_endpoint_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_endpoint_ss_comp_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|bMaxBurst
decl_stmt|;
name|uByte
name|bmAttributes
decl_stmt|;
name|uWord
name|wBytesPerInterval
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_endpoint_ss_comp_descriptor
name|usb_endpoint_ss_comp_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_string_descriptor
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
literal|126
index|]
decl_stmt|;
name|uByte
name|bUnused
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_string_descriptor
name|usb_string_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_MAKE_STRING_DESC
parameter_list|(
name|m
parameter_list|,
name|name
parameter_list|)
define|\
value|struct name {				\   uByte bLength;			\   uByte bDescriptorType;		\   uByte bData[sizeof((uint8_t []){m})];	\ } __packed;				\ static const struct name name = {	\   .bLength = sizeof(struct name),	\   .bDescriptorType = UDESC_STRING,	\   .bData = { m },			\ }
end_define

begin_struct
struct|struct
name|usb_hub_descriptor
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
name|uByte
name|PortPowerCtrlMask
index|[
literal|1
index|]
decl_stmt|;
comment|/* deprecated */
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_hub_descriptor
name|usb_hub_descriptor_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_hub_ss_descriptor
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
comment|/* max 15 */
name|uWord
name|wHubCharacteristics
decl_stmt|;
name|uByte
name|bPwrOn2PwrGood
decl_stmt|;
comment|/* delay in 2 ms units */
name|uByte
name|bHubContrCurrent
decl_stmt|;
name|uByte
name|bHubHdrDecLat
decl_stmt|;
name|uWord
name|wHubDelay
decl_stmt|;
name|uByte
name|DeviceRemovable
index|[
literal|2
index|]
decl_stmt|;
comment|/* max 15 ports */
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_hub_ss_descriptor
name|usb_hub_ss_descriptor_t
typedef|;
end_typedef

begin_comment
comment|/* minimum HUB descriptor (8-ports maximum) */
end_comment

begin_struct
struct|struct
name|usb_hub_descriptor_min
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
name|uByte
name|bPwrOn2PwrGood
decl_stmt|;
name|uByte
name|bHubContrCurrent
decl_stmt|;
name|uByte
name|DeviceRemovable
index|[
literal|1
index|]
decl_stmt|;
name|uByte
name|PortPowerCtrlMask
index|[
literal|1
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_hub_descriptor_min
name|usb_hub_descriptor_min_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_device_qualifier
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_device_qualifier
name|usb_device_qualifier_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_otg_descriptor
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_otg_descriptor
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

begin_struct
struct|struct
name|usb_status
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_status
name|usb_status_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_hub_status
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_hub_status
name|usb_hub_status_t
typedef|;
end_typedef

begin_struct
struct|struct
name|usb_port_status
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
define|#
directive|define
name|UPS_PORT_MODE_DEVICE
value|0x8000
comment|/* currently FreeBSD specific */
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
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|usb_port_status
name|usb_port_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * The "USB_SPEED" macros defines all the supported USB speeds.  */
end_comment

begin_enum
enum|enum
name|usb_dev_speed
block|{
name|USB_SPEED_VARIABLE
block|,
name|USB_SPEED_LOW
block|,
name|USB_SPEED_FULL
block|,
name|USB_SPEED_HIGH
block|,
name|USB_SPEED_SUPER
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|USB_SPEED_MAX
value|(USB_SPEED_SUPER+1)
end_define

begin_comment
comment|/*  * The "USB_REV" macros defines all the supported USB revisions.  */
end_comment

begin_enum
enum|enum
name|usb_revision
block|{
name|USB_REV_UNKNOWN
block|,
name|USB_REV_PRE_1_0
block|,
name|USB_REV_1_0
block|,
name|USB_REV_1_1
block|,
name|USB_REV_2_0
block|,
name|USB_REV_2_5
block|,
name|USB_REV_3_0
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|USB_REV_MAX
value|(USB_REV_3_0+1)
end_define

begin_comment
comment|/*  * Supported host contoller modes.  */
end_comment

begin_enum
enum|enum
name|usb_hc_mode
block|{
name|USB_MODE_HOST
block|,
comment|/* initiates transfers */
name|USB_MODE_DEVICE
block|,
comment|/* bus transfer target */
name|USB_MODE_DUAL
comment|/* can be host or device */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|USB_MODE_MAX
value|(USB_MODE_DUAL+1)
end_define

begin_comment
comment|/*  * The "USB_MODE" macros defines all the supported device states.  */
end_comment

begin_enum
enum|enum
name|usb_dev_state
block|{
name|USB_STATE_DETACHED
block|,
name|USB_STATE_ATTACHED
block|,
name|USB_STATE_POWERED
block|,
name|USB_STATE_ADDRESSED
block|,
name|USB_STATE_CONFIGURED
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|USB_STATE_MAX
value|(USB_STATE_CONFIGURED+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_STANDARD_H_ */
end_comment

end_unit

