begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usbhid.h,v 1.9 2000/09/03 19:09:14 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USBHID_H_
end_ifndef

begin_define
define|#
directive|define
name|_USBHID_H_
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UPACKED
value|__attribute__ ((packed))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
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
name|UPACKED
name|usb_hid_descriptor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USB_HID_DESCRIPTOR_SIZE
parameter_list|(
name|n
parameter_list|)
value|(9+(n)*3)
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
name|HID_USAGE2
parameter_list|(
name|p
parameter_list|,
name|u
parameter_list|)
value|(((p)<< 16) | u)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USBHID_H_ */
end_comment

end_unit

