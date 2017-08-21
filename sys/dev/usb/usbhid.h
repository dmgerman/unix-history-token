begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  * Copyright (c) 1998 The NetBSD Foundation, Inc. All rights reserved.  * Copyright (c) 1998 Lennart Augustsson. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB_HID_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB_HID_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USB_GLOBAL_INCLUDE_FILE
end_ifndef

begin_include
include|#
directive|include
file|<dev/usb/usb_endian.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UR_GET_HID_DESCRIPTOR
value|0x06
end_define

begin_define
define|#
directive|define
name|UDESC_HID
value|0x21
end_define

begin_define
define|#
directive|define
name|UDESC_REPORT
value|0x22
end_define

begin_define
define|#
directive|define
name|UDESC_PHYSICAL
value|0x23
end_define

begin_define
define|#
directive|define
name|UR_SET_HID_DESCRIPTOR
value|0x07
end_define

begin_define
define|#
directive|define
name|UR_GET_REPORT
value|0x01
end_define

begin_define
define|#
directive|define
name|UR_SET_REPORT
value|0x09
end_define

begin_define
define|#
directive|define
name|UR_GET_IDLE
value|0x02
end_define

begin_define
define|#
directive|define
name|UR_SET_IDLE
value|0x0a
end_define

begin_define
define|#
directive|define
name|UR_GET_PROTOCOL
value|0x03
end_define

begin_define
define|#
directive|define
name|UR_SET_PROTOCOL
value|0x0b
end_define

begin_struct
struct|struct
name|usb_hid_descriptor
block|{
name|uByte
name|bLength
decl_stmt|;
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|bcdHID
decl_stmt|;
name|uByte
name|bCountryCode
decl_stmt|;
name|uByte
name|bNumDescriptors
decl_stmt|;
struct|struct
block|{
name|uByte
name|bDescriptorType
decl_stmt|;
name|uWord
name|wDescriptorLength
decl_stmt|;
block|}
name|descrs
index|[
literal|1
index|]
struct|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_HID_DESCRIPTOR_SIZE
parameter_list|(
name|n
parameter_list|)
value|(9+((n)*3))
end_define

begin_comment
comment|/* Usage pages */
end_comment

begin_define
define|#
directive|define
name|HUP_UNDEFINED
value|0x0000
end_define

begin_define
define|#
directive|define
name|HUP_GENERIC_DESKTOP
value|0x0001
end_define

begin_define
define|#
directive|define
name|HUP_SIMULATION
value|0x0002
end_define

begin_define
define|#
directive|define
name|HUP_VR_CONTROLS
value|0x0003
end_define

begin_define
define|#
directive|define
name|HUP_SPORTS_CONTROLS
value|0x0004
end_define

begin_define
define|#
directive|define
name|HUP_GAMING_CONTROLS
value|0x0005
end_define

begin_define
define|#
directive|define
name|HUP_KEYBOARD
value|0x0007
end_define

begin_define
define|#
directive|define
name|HUP_LEDS
value|0x0008
end_define

begin_define
define|#
directive|define
name|HUP_BUTTON
value|0x0009
end_define

begin_define
define|#
directive|define
name|HUP_ORDINALS
value|0x000a
end_define

begin_define
define|#
directive|define
name|HUP_TELEPHONY
value|0x000b
end_define

begin_define
define|#
directive|define
name|HUP_CONSUMER
value|0x000c
end_define

begin_define
define|#
directive|define
name|HUP_DIGITIZERS
value|0x000d
end_define

begin_define
define|#
directive|define
name|HUP_PHYSICAL_IFACE
value|0x000e
end_define

begin_define
define|#
directive|define
name|HUP_UNICODE
value|0x0010
end_define

begin_define
define|#
directive|define
name|HUP_ALPHANUM_DISPLAY
value|0x0014
end_define

begin_define
define|#
directive|define
name|HUP_MONITOR
value|0x0080
end_define

begin_define
define|#
directive|define
name|HUP_MONITOR_ENUM_VAL
value|0x0081
end_define

begin_define
define|#
directive|define
name|HUP_VESA_VC
value|0x0082
end_define

begin_define
define|#
directive|define
name|HUP_VESA_CMD
value|0x0083
end_define

begin_define
define|#
directive|define
name|HUP_POWER
value|0x0084
end_define

begin_define
define|#
directive|define
name|HUP_BATTERY_SYSTEM
value|0x0085
end_define

begin_define
define|#
directive|define
name|HUP_BARCODE_SCANNER
value|0x008b
end_define

begin_define
define|#
directive|define
name|HUP_SCALE
value|0x008c
end_define

begin_define
define|#
directive|define
name|HUP_CAMERA_CONTROL
value|0x0090
end_define

begin_define
define|#
directive|define
name|HUP_ARCADE
value|0x0091
end_define

begin_define
define|#
directive|define
name|HUP_MICROSOFT
value|0xff00
end_define

begin_comment
comment|/* Usages, generic desktop */
end_comment

begin_define
define|#
directive|define
name|HUG_POINTER
value|0x0001
end_define

begin_define
define|#
directive|define
name|HUG_MOUSE
value|0x0002
end_define

begin_define
define|#
directive|define
name|HUG_JOYSTICK
value|0x0004
end_define

begin_define
define|#
directive|define
name|HUG_GAME_PAD
value|0x0005
end_define

begin_define
define|#
directive|define
name|HUG_KEYBOARD
value|0x0006
end_define

begin_define
define|#
directive|define
name|HUG_KEYPAD
value|0x0007
end_define

begin_define
define|#
directive|define
name|HUG_X
value|0x0030
end_define

begin_define
define|#
directive|define
name|HUG_Y
value|0x0031
end_define

begin_define
define|#
directive|define
name|HUG_Z
value|0x0032
end_define

begin_define
define|#
directive|define
name|HUG_RX
value|0x0033
end_define

begin_define
define|#
directive|define
name|HUG_RY
value|0x0034
end_define

begin_define
define|#
directive|define
name|HUG_RZ
value|0x0035
end_define

begin_define
define|#
directive|define
name|HUG_SLIDER
value|0x0036
end_define

begin_define
define|#
directive|define
name|HUG_DIAL
value|0x0037
end_define

begin_define
define|#
directive|define
name|HUG_WHEEL
value|0x0038
end_define

begin_define
define|#
directive|define
name|HUG_HAT_SWITCH
value|0x0039
end_define

begin_define
define|#
directive|define
name|HUG_COUNTED_BUFFER
value|0x003a
end_define

begin_define
define|#
directive|define
name|HUG_BYTE_COUNT
value|0x003b
end_define

begin_define
define|#
directive|define
name|HUG_MOTION_WAKEUP
value|0x003c
end_define

begin_define
define|#
directive|define
name|HUG_VX
value|0x0040
end_define

begin_define
define|#
directive|define
name|HUG_VY
value|0x0041
end_define

begin_define
define|#
directive|define
name|HUG_VZ
value|0x0042
end_define

begin_define
define|#
directive|define
name|HUG_VBRX
value|0x0043
end_define

begin_define
define|#
directive|define
name|HUG_VBRY
value|0x0044
end_define

begin_define
define|#
directive|define
name|HUG_VBRZ
value|0x0045
end_define

begin_define
define|#
directive|define
name|HUG_VNO
value|0x0046
end_define

begin_define
define|#
directive|define
name|HUG_TWHEEL
value|0x0048
end_define

begin_comment
comment|/* M$ Wireless Intellimouse Wheel */
end_comment

begin_define
define|#
directive|define
name|HUG_SYSTEM_CONTROL
value|0x0080
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_POWER_DOWN
value|0x0081
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_SLEEP
value|0x0082
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_WAKEUP
value|0x0083
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_CONTEXT_MENU
value|0x0084
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MAIN_MENU
value|0x0085
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_APP_MENU
value|0x0086
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_HELP
value|0x0087
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_EXIT
value|0x0088
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_SELECT
value|0x0089
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_RIGHT
value|0x008a
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_LEFT
value|0x008b
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_UP
value|0x008c
end_define

begin_define
define|#
directive|define
name|HUG_SYSTEM_MENU_DOWN
value|0x008d
end_define

begin_define
define|#
directive|define
name|HUG_APPLE_EJECT
value|0x00b8
end_define

begin_comment
comment|/* Usages Digitizers */
end_comment

begin_define
define|#
directive|define
name|HUD_UNDEFINED
value|0x0000
end_define

begin_define
define|#
directive|define
name|HUD_DIGITIZER
value|0x0001
end_define

begin_define
define|#
directive|define
name|HUD_PEN
value|0x0002
end_define

begin_define
define|#
directive|define
name|HUD_TOUCHSCREEN
value|0x0004
end_define

begin_define
define|#
directive|define
name|HUD_TOUCHPAD
value|0x0005
end_define

begin_define
define|#
directive|define
name|HUD_CONFIG
value|0x000e
end_define

begin_define
define|#
directive|define
name|HUD_FINGER
value|0x0022
end_define

begin_define
define|#
directive|define
name|HUD_TIP_PRESSURE
value|0x0030
end_define

begin_define
define|#
directive|define
name|HUD_BARREL_PRESSURE
value|0x0031
end_define

begin_define
define|#
directive|define
name|HUD_IN_RANGE
value|0x0032
end_define

begin_define
define|#
directive|define
name|HUD_TOUCH
value|0x0033
end_define

begin_define
define|#
directive|define
name|HUD_UNTOUCH
value|0x0034
end_define

begin_define
define|#
directive|define
name|HUD_TAP
value|0x0035
end_define

begin_define
define|#
directive|define
name|HUD_QUALITY
value|0x0036
end_define

begin_define
define|#
directive|define
name|HUD_DATA_VALID
value|0x0037
end_define

begin_define
define|#
directive|define
name|HUD_TRANSDUCER_INDEX
value|0x0038
end_define

begin_define
define|#
directive|define
name|HUD_TABLET_FKEYS
value|0x0039
end_define

begin_define
define|#
directive|define
name|HUD_PROGRAM_CHANGE_KEYS
value|0x003a
end_define

begin_define
define|#
directive|define
name|HUD_BATTERY_STRENGTH
value|0x003b
end_define

begin_define
define|#
directive|define
name|HUD_INVERT
value|0x003c
end_define

begin_define
define|#
directive|define
name|HUD_X_TILT
value|0x003d
end_define

begin_define
define|#
directive|define
name|HUD_Y_TILT
value|0x003e
end_define

begin_define
define|#
directive|define
name|HUD_AZIMUTH
value|0x003f
end_define

begin_define
define|#
directive|define
name|HUD_ALTITUDE
value|0x0040
end_define

begin_define
define|#
directive|define
name|HUD_TWIST
value|0x0041
end_define

begin_define
define|#
directive|define
name|HUD_TIP_SWITCH
value|0x0042
end_define

begin_define
define|#
directive|define
name|HUD_SEC_TIP_SWITCH
value|0x0043
end_define

begin_define
define|#
directive|define
name|HUD_BARREL_SWITCH
value|0x0044
end_define

begin_define
define|#
directive|define
name|HUD_ERASER
value|0x0045
end_define

begin_define
define|#
directive|define
name|HUD_TABLET_PICK
value|0x0046
end_define

begin_define
define|#
directive|define
name|HUD_CONFIDENCE
value|0x0047
end_define

begin_define
define|#
directive|define
name|HUD_WIDTH
value|0x0048
end_define

begin_define
define|#
directive|define
name|HUD_HEIGHT
value|0x0049
end_define

begin_define
define|#
directive|define
name|HUD_CONTACTID
value|0x0051
end_define

begin_define
define|#
directive|define
name|HUD_INPUT_MODE
value|0x0052
end_define

begin_define
define|#
directive|define
name|HUD_DEVICE_INDEX
value|0x0053
end_define

begin_define
define|#
directive|define
name|HUD_CONTACTCOUNT
value|0x0054
end_define

begin_define
define|#
directive|define
name|HUD_CONTACT_MAX
value|0x0055
end_define

begin_define
define|#
directive|define
name|HUD_SCAN_TIME
value|0x0056
end_define

begin_define
define|#
directive|define
name|HUD_BUTTON_TYPE
value|0x0059
end_define

begin_comment
comment|/* Usages, Consumer */
end_comment

begin_define
define|#
directive|define
name|HUC_AC_PAN
value|0x0238
end_define

begin_define
define|#
directive|define
name|HID_USAGE2
parameter_list|(
name|p
parameter_list|,
name|u
parameter_list|)
value|(((p)<< 16) | (u))
end_define

begin_define
define|#
directive|define
name|UHID_INPUT_REPORT
value|0x01
end_define

begin_define
define|#
directive|define
name|UHID_OUTPUT_REPORT
value|0x02
end_define

begin_define
define|#
directive|define
name|UHID_FEATURE_REPORT
value|0x03
end_define

begin_comment
comment|/* Bits in the input/output/feature items */
end_comment

begin_define
define|#
directive|define
name|HIO_CONST
value|0x001
end_define

begin_define
define|#
directive|define
name|HIO_VARIABLE
value|0x002
end_define

begin_define
define|#
directive|define
name|HIO_RELATIVE
value|0x004
end_define

begin_define
define|#
directive|define
name|HIO_WRAP
value|0x008
end_define

begin_define
define|#
directive|define
name|HIO_NONLINEAR
value|0x010
end_define

begin_define
define|#
directive|define
name|HIO_NOPREF
value|0x020
end_define

begin_define
define|#
directive|define
name|HIO_NULLSTATE
value|0x040
end_define

begin_define
define|#
directive|define
name|HIO_VOLATILE
value|0x080
end_define

begin_define
define|#
directive|define
name|HIO_BUFBYTES
value|0x100
end_define

begin_comment
comment|/* Units of Measure */
end_comment

begin_define
define|#
directive|define
name|HUM_CENTIMETER
value|0x11
end_define

begin_define
define|#
directive|define
name|HUM_RADIAN
value|0x12
end_define

begin_define
define|#
directive|define
name|HUM_INCH
value|0x13
end_define

begin_define
define|#
directive|define
name|HUM_DEGREE
value|0x14
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|usb_config_descriptor
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|hid_kind
block|{
name|hid_input
block|,
name|hid_output
block|,
name|hid_feature
block|,
name|hid_collection
block|,
name|hid_endcollection
block|}
enum|;
end_enum

begin_struct
struct|struct
name|hid_location
block|{
name|uint32_t
name|size
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
name|uint32_t
name|pos
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hid_item
block|{
comment|/* Global */
name|int32_t
name|_usage_page
decl_stmt|;
name|int32_t
name|logical_minimum
decl_stmt|;
name|int32_t
name|logical_maximum
decl_stmt|;
name|int32_t
name|physical_minimum
decl_stmt|;
name|int32_t
name|physical_maximum
decl_stmt|;
name|int32_t
name|unit_exponent
decl_stmt|;
name|int32_t
name|unit
decl_stmt|;
name|int32_t
name|report_ID
decl_stmt|;
comment|/* Local */
name|int32_t
name|usage
decl_stmt|;
name|int32_t
name|usage_minimum
decl_stmt|;
name|int32_t
name|usage_maximum
decl_stmt|;
name|int32_t
name|designator_index
decl_stmt|;
name|int32_t
name|designator_minimum
decl_stmt|;
name|int32_t
name|designator_maximum
decl_stmt|;
name|int32_t
name|string_index
decl_stmt|;
name|int32_t
name|string_minimum
decl_stmt|;
name|int32_t
name|string_maximum
decl_stmt|;
name|int32_t
name|set_delimiter
decl_stmt|;
comment|/* Misc */
name|int32_t
name|collection
decl_stmt|;
name|int
name|collevel
decl_stmt|;
name|enum
name|hid_kind
name|kind
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* Location */
name|struct
name|hid_location
name|loc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes from "usb_hid.c" */
end_comment

begin_function_decl
name|struct
name|hid_data
modifier|*
name|hid_start_parse
parameter_list|(
specifier|const
name|void
modifier|*
name|d
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|int
name|kindset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_end_parse
parameter_list|(
name|struct
name|hid_data
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_get_item
parameter_list|(
name|struct
name|hid_data
modifier|*
name|s
parameter_list|,
name|struct
name|hid_item
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_report_size
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|enum
name|hid_kind
name|k
parameter_list|,
name|uint8_t
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_locate
parameter_list|(
specifier|const
name|void
modifier|*
name|desc
parameter_list|,
name|usb_size_t
name|size
parameter_list|,
name|int32_t
name|usage
parameter_list|,
name|enum
name|hid_kind
name|kind
parameter_list|,
name|uint8_t
name|index
parameter_list|,
name|struct
name|hid_location
modifier|*
name|loc
parameter_list|,
name|uint32_t
modifier|*
name|flags
parameter_list|,
name|uint8_t
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|hid_get_data
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|struct
name|hid_location
modifier|*
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hid_get_data_unsigned
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|struct
name|hid_location
modifier|*
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hid_put_data_unsigned
parameter_list|(
name|uint8_t
modifier|*
name|buf
parameter_list|,
name|usb_size_t
name|len
parameter_list|,
name|struct
name|hid_location
modifier|*
name|loc
parameter_list|,
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_is_collection
parameter_list|(
specifier|const
name|void
modifier|*
name|desc
parameter_list|,
name|usb_size_t
name|size
parameter_list|,
name|int32_t
name|usage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|usb_hid_descriptor
modifier|*
name|hid_get_descriptor_from_usb
parameter_list|(
name|struct
name|usb_config_descriptor
modifier|*
name|cd
parameter_list|,
name|struct
name|usb_interface_descriptor
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|usb_error_t
name|usbd_req_get_hid_desc
parameter_list|(
name|struct
name|usb_device
modifier|*
name|udev
parameter_list|,
name|struct
name|mtx
modifier|*
name|mtx
parameter_list|,
name|void
modifier|*
modifier|*
name|descp
parameter_list|,
name|uint16_t
modifier|*
name|sizep
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|mem
parameter_list|,
name|uint8_t
name|iface_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|hid_item_resolution
parameter_list|(
name|struct
name|hid_item
modifier|*
name|hi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_is_mouse
parameter_list|(
specifier|const
name|void
modifier|*
name|d_ptr
parameter_list|,
name|uint16_t
name|d_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_is_keyboard
parameter_list|(
specifier|const
name|void
modifier|*
name|d_ptr
parameter_list|,
name|uint16_t
name|d_len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB_HID_H_ */
end_comment

end_unit

