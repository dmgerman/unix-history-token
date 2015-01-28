begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  * Copyright (c) 2007-2008 Daniel Drake.  All rights reserved.  * Copyright (c) 2001 Johannes Erdfelt.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * NOTE: This file contains the definition of some standard USB  * structures. All structures which name ends by *DECODED use host byte  * order.  */
end_comment

begin_comment
comment|/*  * NOTE: This file uses a lot of macros. If you want to see what the  * macros become when they are expanded then run the following  * commands from your shell:  *  * cpp libusb20_desc.h> temp.h  * indent temp.h  * less temp.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUSB20_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBUSB20_DESC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
literal|0
block|};
comment|/* style */
endif|#
directive|endif
comment|/* basic macros */
define|#
directive|define
name|LIBUSB20__NOT
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
define|#
directive|define
name|LIBUSB20_NOT
parameter_list|(
name|arg
parameter_list|)
value|LIBUSB20__NOT(LIBUSB20_YES arg(() LIBUSB20_NO))
define|#
directive|define
name|LIBUSB20_YES
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
define|#
directive|define
name|LIBUSB20_NO
parameter_list|(
modifier|...
parameter_list|)
define|#
directive|define
name|LIBUSB20_END
parameter_list|(
modifier|...
parameter_list|)
value|__VA_ARGS__
define|#
directive|define
name|LIBUSB20_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
define|#
directive|define
name|LIBUSB20_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
define|#
directive|define
name|LIBUSB20_ADD_BYTES
parameter_list|(
name|ptr
parameter_list|,
name|off
parameter_list|)
define|\
value|((void *)(((const uint8_t *)(ptr)) + (off) - ((const uint8_t *)0)))
comment|/* basic message elements */
enum|enum
block|{
name|LIBUSB20_ME_INT8
block|,
name|LIBUSB20_ME_INT16
block|,
name|LIBUSB20_ME_INT32
block|,
name|LIBUSB20_ME_INT64
block|,
name|LIBUSB20_ME_STRUCT
block|,
name|LIBUSB20_ME_MAX
block|,
comment|/* used to indicate end */
block|}
enum|;
comment|/* basic message element modifiers */
enum|enum
block|{
name|LIBUSB20_ME_IS_UNSIGNED
init|=
literal|0x00
block|,
name|LIBUSB20_ME_IS_SIGNED
init|=
literal|0x80
block|,
name|LIBUSB20_ME_MASK
init|=
literal|0x7F
block|, }
enum|;
enum|enum
block|{
name|LIBUSB20_ME_IS_RAW
block|,
comment|/* structure excludes length field 					 * (hardcoded value) */
name|LIBUSB20_ME_IS_ENCODED
block|,
comment|/* structure includes length field */
name|LIBUSB20_ME_IS_EMPTY
block|,
comment|/* no structure */
name|LIBUSB20_ME_IS_DECODED
block|,
comment|/* structure is recursive */
block|}
enum|;
comment|/* basic helper structures and macros */
define|#
directive|define
name|LIBUSB20_ME_STRUCT_ALIGN
value|sizeof(void *)
struct|struct
name|libusb20_me_struct
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* data pointer */
name|uint16_t
name|len
decl_stmt|;
comment|/* defaults to zero */
name|uint16_t
name|type
decl_stmt|;
comment|/* defaults to LIBUSB20_ME_IS_EMPTY */
block|}
name|__aligned
argument_list|(
name|LIBUSB20_ME_STRUCT_ALIGN
argument_list|)
struct|;
struct|struct
name|libusb20_me_format
block|{
specifier|const
name|uint8_t
modifier|*
name|format
decl_stmt|;
comment|/* always set */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* optionally set */
specifier|const
name|char
modifier|*
name|fields
decl_stmt|;
comment|/* optionally set */
block|}
struct|;
define|#
directive|define
name|LIBUSB20_ME_STRUCT
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|ismeta ( LIBUSB20_ME_STRUCT, 1, 0, )			\   LIBUSB20_NOT(ismeta) ( struct libusb20_me_struct field; )
define|#
directive|define
name|LIBUSB20_ME_STRUCT_ARRAY
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|ismeta ( LIBUSB20_ME_STRUCT , (arg)& 0xFF,		\ 	   ((arg) / 0x100)& 0xFF, )			\   LIBUSB20_NOT(ismeta) ( struct libusb20_me_struct field [arg]; )
define|#
directive|define
name|LIBUSB20_ME_INTEGER
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|ismeta
parameter_list|,
name|un
parameter_list|,
name|u
parameter_list|,
name|bits
parameter_list|,
name|a
parameter_list|,
name|size
parameter_list|)
define|\
value|ismeta ( LIBUSB20_ME_INT##bits |					\ 	   LIBUSB20_ME_IS_##un##SIGNED ,				\ 	   (size)& 0xFF, ((size) / 0x100)& 0xFF, )		\   LIBUSB20_NOT(ismeta) ( u##int##bits##_t				\ 		    __aligned((bits) / 8) field a; )
define|#
directive|define
name|LIBUSB20_ME_UINT8_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 8, , 1)
define|#
directive|define
name|LIBUSB20_ME_UINT8_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 8, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_SINT8_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 8, , 1)
define|#
directive|define
name|LIBUSB20_ME_SINT8_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 8, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_UINT16_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 16, , 1)
define|#
directive|define
name|LIBUSB20_ME_UINT16_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 16, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_SINT16_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 16, , 1)
define|#
directive|define
name|LIBUSB20_ME_SINT16_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 16, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_UINT32_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 32, , 1)
define|#
directive|define
name|LIBUSB20_ME_UINT32_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 32, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_SINT32_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 32, , 1)
define|#
directive|define
name|LIBUSB20_ME_SINT32_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 32, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_UINT64_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 64, , 1)
define|#
directive|define
name|LIBUSB20_ME_UINT64_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta, UN, u, 64, [arg], arg)
define|#
directive|define
name|LIBUSB20_ME_SINT64_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 64, , 1)
define|#
directive|define
name|LIBUSB20_ME_SINT64_ARRAY_T
parameter_list|(
name|n
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|,
name|ismeta
parameter_list|)
define|\
value|LIBUSB20_ME_INTEGER(n, field, ismeta,,, 64, [arg], arg)
define|#
directive|define
name|LIBUSB20_MAKE_DECODED_FIELD
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|)
define|\
value|LIBUSB20_ME_##type (n, field, arg, LIBUSB20_NO)
define|#
directive|define
name|LIBUSB20_MAKE_STRUCT
parameter_list|(
name|name
parameter_list|)
define|\
value|extern const struct libusb20_me_format			\ 	 name##_FORMAT[1];				\   struct name##_DECODED {				\     const struct libusb20_me_format *name##_FORMAT;	\     name (LIBUSB20_MAKE_DECODED_FIELD,)			\   }
define|#
directive|define
name|LIBUSB20_MAKE_STRUCT_FORMAT
parameter_list|(
name|name
parameter_list|)
define|\
value|const struct libusb20_me_format			\     name##_FORMAT[1] = {{			\       .format = LIBUSB20_MAKE_FORMAT(name),	\       .desc = #name,				\       .fields = NULL,				\   }}
define|#
directive|define
name|LIBUSB20_MAKE_FORMAT_SUB
parameter_list|(
name|n
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|,
name|arg
parameter_list|)
define|\
value|LIBUSB20_ME_##type (n, field, arg, LIBUSB20_YES)
define|#
directive|define
name|LIBUSB20_MAKE_FORMAT
parameter_list|(
name|what
parameter_list|)
value|(const uint8_t []) \   { what (LIBUSB20_MAKE_FORMAT_SUB, ) LIBUSB20_ME_MAX, 0, 0 }
define|#
directive|define
name|LIBUSB20_INIT
parameter_list|(
name|what
parameter_list|,
name|ptr
parameter_list|)
value|do {		\     memset(ptr, 0, sizeof(*(ptr)));		\     (ptr)->what##_FORMAT = what##_FORMAT;	\ } while (0)
define|#
directive|define
name|LIBUSB20_DEVICE_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T, bLength, ) \   m(n, UINT8_T, bDescriptorType, ) \   m(n, UINT16_T, bcdUSB, ) \   m(n, UINT8_T, bDeviceClass, ) \   m(n, UINT8_T, bDeviceSubClass, ) \   m(n, UINT8_T, bDeviceProtocol, ) \   m(n, UINT8_T, bMaxPacketSize0, ) \   m(n, UINT16_T, idVendor, ) \   m(n, UINT16_T, idProduct, ) \   m(n, UINT16_T, bcdDevice, ) \   m(n, UINT8_T, iManufacturer, ) \   m(n, UINT8_T, iProduct, ) \   m(n, UINT8_T, iSerialNumber, ) \   m(n, UINT8_T, bNumConfigurations, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_DEVICE_DESC);
define|#
directive|define
name|LIBUSB20_ENDPOINT_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT8_T,  bEndpointAddress, ) \   m(n, UINT8_T,  bmAttributes, ) \   m(n, UINT16_T, wMaxPacketSize, ) \   m(n, UINT8_T,  bInterval, ) \   m(n, UINT8_T,  bRefresh, ) \   m(n, UINT8_T,  bSynchAddress, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_ENDPOINT_DESC);
define|#
directive|define
name|LIBUSB20_INTERFACE_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT8_T,  bInterfaceNumber, ) \   m(n, UINT8_T,  bAlternateSetting, ) \   m(n, UINT8_T,  bNumEndpoints, ) \   m(n, UINT8_T,  bInterfaceClass, ) \   m(n, UINT8_T,  bInterfaceSubClass, ) \   m(n, UINT8_T,  bInterfaceProtocol, ) \   m(n, UINT8_T,  iInterface, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_INTERFACE_DESC);
define|#
directive|define
name|LIBUSB20_CONFIG_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT16_T, wTotalLength, ) \   m(n, UINT8_T,  bNumInterfaces, ) \   m(n, UINT8_T,  bConfigurationValue, ) \   m(n, UINT8_T,  iConfiguration, ) \   m(n, UINT8_T,  bmAttributes, ) \   m(n, UINT8_T,  bMaxPower, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_CONFIG_DESC);
define|#
directive|define
name|LIBUSB20_CONTROL_SETUP
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bmRequestType, ) \   m(n, UINT8_T,  bRequest, ) \   m(n, UINT16_T, wValue, ) \   m(n, UINT16_T, wIndex, ) \   m(n, UINT16_T, wLength, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_CONTROL_SETUP);
define|#
directive|define
name|LIBUSB20_SS_ENDPT_COMP_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT8_T,  bMaxBurst, ) \   m(n, UINT8_T,  bmAttributes, ) \   m(n, UINT16_T, wBytesPerInterval, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_SS_ENDPT_COMP_DESC);
define|#
directive|define
name|LIBUSB20_USB_20_DEVCAP_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT8_T,  bDevCapabilityType, ) \   m(n, UINT32_T, bmAttributes, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_USB_20_DEVCAP_DESC);
define|#
directive|define
name|LIBUSB20_SS_USB_DEVCAP_DESC
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT8_T,  bDevCapabilityType, ) \   m(n, UINT8_T,  bmAttributes, ) \   m(n, UINT16_T, wSpeedSupported, ) \   m(n, UINT8_T,  bFunctionalitySupport, ) \   m(n, UINT8_T,  bU1DevExitLat, ) \   m(n, UINT16_T, wU2DevExitLat, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_SS_USB_DEVCAP_DESC);
define|#
directive|define
name|LIBUSB20_BOS_DESCRIPTOR
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
define|\
value|m(n, UINT8_T,  bLength, ) \   m(n, UINT8_T,  bDescriptorType, ) \   m(n, UINT16_T, wTotalLength, ) \   m(n, UINT8_T,  bNumDeviceCapabilities, ) \  LIBUSB20_MAKE_STRUCT(LIBUSB20_BOS_DESCRIPTOR);
comment|/* standard USB stuff */
comment|/** \ingroup desc  * Device and/or Interface Class codes */
enum|enum
name|libusb20_class_code
block|{
comment|/** In the context of a \ref LIBUSB20_DEVICE_DESC "device 	 * descriptor", this bDeviceClass value indicates that each 	 * interface specifies its own class information and all 	 * interfaces operate independently. 	 */
name|LIBUSB20_CLASS_PER_INTERFACE
init|=
literal|0
block|,
comment|/** Audio class */
name|LIBUSB20_CLASS_AUDIO
init|=
literal|1
block|,
comment|/** Communications class */
name|LIBUSB20_CLASS_COMM
init|=
literal|2
block|,
comment|/** Human Interface Device class */
name|LIBUSB20_CLASS_HID
init|=
literal|3
block|,
comment|/** Printer dclass */
name|LIBUSB20_CLASS_PRINTER
init|=
literal|7
block|,
comment|/** Picture transfer protocol class */
name|LIBUSB20_CLASS_PTP
init|=
literal|6
block|,
comment|/** Mass storage class */
name|LIBUSB20_CLASS_MASS_STORAGE
init|=
literal|8
block|,
comment|/** Hub class */
name|LIBUSB20_CLASS_HUB
init|=
literal|9
block|,
comment|/** Data class */
name|LIBUSB20_CLASS_DATA
init|=
literal|10
block|,
comment|/** Class is vendor-specific */
name|LIBUSB20_CLASS_VENDOR_SPEC
init|=
literal|0xff
block|, }
enum|;
comment|/** \ingroup desc  * Descriptor types as defined by the USB specification. */
enum|enum
name|libusb20_descriptor_type
block|{
comment|/** Device descriptor. See LIBUSB20_DEVICE_DESC. */
name|LIBUSB20_DT_DEVICE
init|=
literal|0x01
block|,
comment|/** Configuration descriptor. See LIBUSB20_CONFIG_DESC. */
name|LIBUSB20_DT_CONFIG
init|=
literal|0x02
block|,
comment|/** String descriptor */
name|LIBUSB20_DT_STRING
init|=
literal|0x03
block|,
comment|/** Interface descriptor. See LIBUSB20_INTERFACE_DESC. */
name|LIBUSB20_DT_INTERFACE
init|=
literal|0x04
block|,
comment|/** Endpoint descriptor. See LIBUSB20_ENDPOINT_DESC. */
name|LIBUSB20_DT_ENDPOINT
init|=
literal|0x05
block|,
comment|/** HID descriptor */
name|LIBUSB20_DT_HID
init|=
literal|0x21
block|,
comment|/** HID report descriptor */
name|LIBUSB20_DT_REPORT
init|=
literal|0x22
block|,
comment|/** Physical descriptor */
name|LIBUSB20_DT_PHYSICAL
init|=
literal|0x23
block|,
comment|/** Hub descriptor */
name|LIBUSB20_DT_HUB
init|=
literal|0x29
block|,
comment|/** Binary Object Store, BOS */
name|LIBUSB20_DT_BOS
init|=
literal|0x0f
block|,
comment|/** Device Capability */
name|LIBUSB20_DT_DEVICE_CAPABILITY
init|=
literal|0x10
block|,
comment|/** SuperSpeed endpoint companion */
name|LIBUSB20_DT_SS_ENDPOINT_COMPANION
init|=
literal|0x30
block|, }
enum|;
comment|/** \ingroup desc  * Device capability types as defined by the USB specification. */
enum|enum
name|libusb20_device_capability_type
block|{
name|LIBUSB20_WIRELESS_USB_DEVICE_CAPABILITY
init|=
literal|0x1
block|,
name|LIBUSB20_USB_2_0_EXTENSION_DEVICE_CAPABILITY
init|=
literal|0x2
block|,
name|LIBUSB20_SS_USB_DEVICE_CAPABILITY
init|=
literal|0x3
block|,
name|LIBUSB20_CONTAINER_ID_DEVICE_CAPABILITY
init|=
literal|0x4
block|, }
enum|;
comment|/* Descriptor sizes per descriptor type */
define|#
directive|define
name|LIBUSB20_DT_DEVICE_SIZE
value|18
define|#
directive|define
name|LIBUSB20_DT_CONFIG_SIZE
value|9
define|#
directive|define
name|LIBUSB20_DT_INTERFACE_SIZE
value|9
define|#
directive|define
name|LIBUSB20_DT_ENDPOINT_SIZE
value|7
define|#
directive|define
name|LIBUSB20_DT_ENDPOINT_AUDIO_SIZE
value|9
comment|/* Audio extension */
define|#
directive|define
name|LIBUSB20_DT_HUB_NONVAR_SIZE
value|7
define|#
directive|define
name|LIBUSB20_DT_SS_ENDPOINT_COMPANION_SIZE
value|6
define|#
directive|define
name|LIBUSB20_DT_BOS_SIZE
value|5
define|#
directive|define
name|LIBUSB20_USB_2_0_EXTENSION_DEVICE_CAPABILITY_SIZE
value|7
define|#
directive|define
name|LIBUSB20_SS_USB_DEVICE_CAPABILITY_SIZE
value|10
define|#
directive|define
name|LIBUSB20_ENDPOINT_ADDRESS_MASK
value|0x0f
comment|/* in bEndpointAddress */
define|#
directive|define
name|LIBUSB20_ENDPOINT_DIR_MASK
value|0x80
comment|/** \ingroup desc  * Endpoint direction. Values for bit 7 of the  * \ref LIBUSB20_ENDPOINT_DESC::bEndpointAddress "endpoint address" scheme.  */
enum|enum
name|libusb20_endpoint_direction
block|{
comment|/** In: device-to-host */
name|LIBUSB20_ENDPOINT_IN
init|=
literal|0x80
block|,
comment|/** Out: host-to-device */
name|LIBUSB20_ENDPOINT_OUT
init|=
literal|0x00
block|, }
enum|;
define|#
directive|define
name|LIBUSB20_TRANSFER_TYPE_MASK
value|0x03
comment|/* in bmAttributes */
comment|/** \ingroup desc  * Endpoint transfer type. Values for bits 0:1 of the  * \ref LIBUSB20_ENDPOINT_DESC::bmAttributes "endpoint attributes" field.  */
enum|enum
name|libusb20_transfer_type
block|{
comment|/** Control endpoint */
name|LIBUSB20_TRANSFER_TYPE_CONTROL
init|=
literal|0
block|,
comment|/** Isochronous endpoint */
name|LIBUSB20_TRANSFER_TYPE_ISOCHRONOUS
init|=
literal|1
block|,
comment|/** Bulk endpoint */
name|LIBUSB20_TRANSFER_TYPE_BULK
init|=
literal|2
block|,
comment|/** Interrupt endpoint */
name|LIBUSB20_TRANSFER_TYPE_INTERRUPT
init|=
literal|3
block|, }
enum|;
comment|/** \ingroup misc  * Standard requests, as defined in table 9-3 of the USB2 specifications */
enum|enum
name|libusb20_standard_request
block|{
comment|/** Request status of the specific recipient */
name|LIBUSB20_REQUEST_GET_STATUS
init|=
literal|0x00
block|,
comment|/** Clear or disable a specific feature */
name|LIBUSB20_REQUEST_CLEAR_FEATURE
init|=
literal|0x01
block|,
comment|/* 0x02 is reserved */
comment|/** Set or enable a specific feature */
name|LIBUSB20_REQUEST_SET_FEATURE
init|=
literal|0x03
block|,
comment|/* 0x04 is reserved */
comment|/** Set device address for all future accesses */
name|LIBUSB20_REQUEST_SET_ADDRESS
init|=
literal|0x05
block|,
comment|/** Get the specified descriptor */
name|LIBUSB20_REQUEST_GET_DESCRIPTOR
init|=
literal|0x06
block|,
comment|/** Used to update existing descriptors or add new descriptors */
name|LIBUSB20_REQUEST_SET_DESCRIPTOR
init|=
literal|0x07
block|,
comment|/** Get the current device configuration value */
name|LIBUSB20_REQUEST_GET_CONFIGURATION
init|=
literal|0x08
block|,
comment|/** Set device configuration */
name|LIBUSB20_REQUEST_SET_CONFIGURATION
init|=
literal|0x09
block|,
comment|/** Return the selected alternate setting for the specified 	 * interface */
name|LIBUSB20_REQUEST_GET_INTERFACE
init|=
literal|0x0A
block|,
comment|/** Select an alternate interface for the specified interface */
name|LIBUSB20_REQUEST_SET_INTERFACE
init|=
literal|0x0B
block|,
comment|/** Set then report an endpoint's synchronization frame */
name|LIBUSB20_REQUEST_SYNCH_FRAME
init|=
literal|0x0C
block|,
comment|/** Set U1 and U2 system exit latency */
name|LIBUSB20_REQUEST_SET_SEL
init|=
literal|0x30
block|,
comment|/** Set isochronous delay */
name|LIBUSB20_REQUEST_SET_ISOCH_DELAY
init|=
literal|0x31
block|, }
enum|;
comment|/** \ingroup misc  * Request type bits of the  * \ref libusb20_control_setup::bmRequestType "bmRequestType" field in  * control transfers. */
enum|enum
name|libusb20_request_type
block|{
comment|/** Standard */
name|LIBUSB20_REQUEST_TYPE_STANDARD
init|=
operator|(
literal|0x00
operator|<<
literal|5
operator|)
block|,
comment|/** Class */
name|LIBUSB20_REQUEST_TYPE_CLASS
init|=
operator|(
literal|0x01
operator|<<
literal|5
operator|)
block|,
comment|/** Vendor */
name|LIBUSB20_REQUEST_TYPE_VENDOR
init|=
operator|(
literal|0x02
operator|<<
literal|5
operator|)
block|,
comment|/** Reserved */
name|LIBUSB20_REQUEST_TYPE_RESERVED
init|=
operator|(
literal|0x03
operator|<<
literal|5
operator|)
block|, }
enum|;
comment|/** \ingroup misc  * Recipient bits of the  * \ref libusb20_control_setup::bmRequestType "bmRequestType" field in  * control transfers. Values 4 through 31 are reserved. */
enum|enum
name|libusb20_request_recipient
block|{
comment|/** Device */
name|LIBUSB20_RECIPIENT_DEVICE
init|=
literal|0x00
block|,
comment|/** Interface */
name|LIBUSB20_RECIPIENT_INTERFACE
init|=
literal|0x01
block|,
comment|/** Endpoint */
name|LIBUSB20_RECIPIENT_ENDPOINT
init|=
literal|0x02
block|,
comment|/** Other */
name|LIBUSB20_RECIPIENT_OTHER
init|=
literal|0x03
block|, }
enum|;
define|#
directive|define
name|LIBUSB20_ISO_SYNC_TYPE_MASK
value|0x0C
comment|/** \ingroup desc  * Synchronization type for isochronous endpoints. Values for bits 2:3  * of the \ref LIBUSB20_ENDPOINT_DESC::bmAttributes "bmAttributes"  * field in LIBUSB20_ENDPOINT_DESC.  */
enum|enum
name|libusb20_iso_sync_type
block|{
comment|/** No synchronization */
name|LIBUSB20_ISO_SYNC_TYPE_NONE
init|=
literal|0
block|,
comment|/** Asynchronous */
name|LIBUSB20_ISO_SYNC_TYPE_ASYNC
init|=
literal|1
block|,
comment|/** Adaptive */
name|LIBUSB20_ISO_SYNC_TYPE_ADAPTIVE
init|=
literal|2
block|,
comment|/** Synchronous */
name|LIBUSB20_ISO_SYNC_TYPE_SYNC
init|=
literal|3
block|, }
enum|;
define|#
directive|define
name|LIBUSB20_ISO_USAGE_TYPE_MASK
value|0x30
comment|/** \ingroup desc  * Usage type for isochronous endpoints. Values for bits 4:5 of the  * \ref LIBUSB20_ENDPOINT_DESC::bmAttributes "bmAttributes" field in  * LIBUSB20_ENDPOINT_DESC.  */
enum|enum
name|libusb20_iso_usage_type
block|{
comment|/** Data endpoint */
name|LIBUSB20_ISO_USAGE_TYPE_DATA
init|=
literal|0
block|,
comment|/** Feedback endpoint */
name|LIBUSB20_ISO_USAGE_TYPE_FEEDBACK
init|=
literal|1
block|,
comment|/** Implicit feedback Data endpoint */
name|LIBUSB20_ISO_USAGE_TYPE_IMPLICIT
init|=
literal|2
block|, }
enum|;
struct|struct
name|libusb20_endpoint
block|{
name|struct
name|LIBUSB20_ENDPOINT_DESC_DECODED
name|desc
decl_stmt|;
name|struct
name|libusb20_me_struct
name|extra
decl_stmt|;
block|}
name|__aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
struct|;
struct|struct
name|libusb20_interface
block|{
name|struct
name|LIBUSB20_INTERFACE_DESC_DECODED
name|desc
decl_stmt|;
name|struct
name|libusb20_me_struct
name|extra
decl_stmt|;
name|struct
name|libusb20_interface
modifier|*
name|altsetting
decl_stmt|;
name|struct
name|libusb20_endpoint
modifier|*
name|endpoints
decl_stmt|;
name|uint8_t
name|num_altsetting
decl_stmt|;
name|uint8_t
name|num_endpoints
decl_stmt|;
block|}
name|__aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
struct|;
struct|struct
name|libusb20_config
block|{
name|struct
name|LIBUSB20_CONFIG_DESC_DECODED
name|desc
decl_stmt|;
name|struct
name|libusb20_me_struct
name|extra
decl_stmt|;
name|struct
name|libusb20_interface
modifier|*
name|interface
decl_stmt|;
name|uint8_t
name|num_interface
decl_stmt|;
block|}
name|__aligned
argument_list|(
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
struct|;
name|uint8_t
name|libusb20_me_get_1
parameter_list|(
specifier|const
name|struct
name|libusb20_me_struct
modifier|*
name|ie
parameter_list|,
name|uint16_t
name|offset
parameter_list|)
function_decl|;
name|uint16_t
name|libusb20_me_get_2
parameter_list|(
specifier|const
name|struct
name|libusb20_me_struct
modifier|*
name|ie
parameter_list|,
name|uint16_t
name|offset
parameter_list|)
function_decl|;
name|uint16_t
name|libusb20_me_encode
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|uint16_t
name|len
parameter_list|,
specifier|const
name|void
modifier|*
name|pd
parameter_list|)
function_decl|;
name|uint16_t
name|libusb20_me_decode
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|,
name|uint16_t
name|len
parameter_list|,
name|void
modifier|*
name|pd
parameter_list|)
function_decl|;
specifier|const
name|uint8_t
modifier|*
name|libusb20_desc_foreach
parameter_list|(
specifier|const
name|struct
name|libusb20_me_struct
modifier|*
name|pdesc
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|psubdesc
parameter_list|)
function_decl|;
name|struct
name|libusb20_config
modifier|*
name|libusb20_parse_config_desc
parameter_list|(
specifier|const
name|void
modifier|*
name|config_desc
parameter_list|)
function_decl|;
if|#
directive|if
literal|0
block|{
comment|/* style */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LIBUSB20_DESC_H_ */
end_comment

end_unit

