begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: XI.h,v 1.13 91/07/24 15:32:36 rws Exp $ */
end_comment

begin_comment
comment|/************************************************************ Copyright (c) 1989 by Hewlett-Packard Company, Palo Alto, California, and the  Massachusetts Institute of Technology, Cambridge, Massachusetts.  			All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the names of Hewlett-Packard or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL HEWLETT-PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ********************************************************/
end_comment

begin_comment
comment|/* Definitions used by the server, library and client */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XI_H_
end_ifndef

begin_define
define|#
directive|define
name|_XI_H_
end_define

begin_define
define|#
directive|define
name|sz_xGetExtensionVersionReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetExtensionVersionReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xListInputDevicesReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_xListInputDevicesReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xOpenDeviceReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xOpenDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xCloseDeviceReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceModeReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceModeReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xSelectExtensionEventReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xGetSelectedExtensionEventsReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetSelectedExtensionEventsReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangeDeviceDontPropagateListReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceDontPropagateListReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceDontPropagateListReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceMotionEventsReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceMotionEventsReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangeKeyboardDeviceReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xChangeKeyboardDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangePointerDeviceReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xChangePointerDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xUngrabDeviceReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceKeyReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceKeyReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xUngrabDeviceKeyReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceButtonReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xGrabDeviceButtonReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xUngrabDeviceButtonReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xAllowDeviceEventsReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceFocusReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceFocusReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceFocusReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xGetFeedbackControlReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetFeedbackControlReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangeFeedbackControlReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceKeyMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceKeyMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangeDeviceKeyMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceModifierMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceModifierMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceModifierMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceButtonMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceButtonMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceButtonMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceButtonMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xQueryDeviceStateReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xQueryDeviceStateReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xSendExtensionEventReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xDeviceBellReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceValuatorsReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xSetDeviceValuatorsReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceControlReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xGetDeviceControlReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xChangeDeviceControlReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xChangeDeviceControlReply
value|32
end_define

begin_define
define|#
directive|define
name|INAME
value|"XInputExtension"
end_define

begin_define
define|#
directive|define
name|XI_KEYBOARD
value|"KEYBOARD"
end_define

begin_define
define|#
directive|define
name|XI_MOUSE
value|"MOUSE"
end_define

begin_define
define|#
directive|define
name|XI_TABLET
value|"TABLET"
end_define

begin_define
define|#
directive|define
name|XI_TOUCHSCREEN
value|"TOUCHSCREEN"
end_define

begin_define
define|#
directive|define
name|XI_TOUCHPAD
value|"TOUCHPAD"
end_define

begin_define
define|#
directive|define
name|XI_BARCODE
value|"BARCODE"
end_define

begin_define
define|#
directive|define
name|XI_BUTTONBOX
value|"BUTTONBOX"
end_define

begin_define
define|#
directive|define
name|XI_KNOB_BOX
value|"KNOB_BOX"
end_define

begin_define
define|#
directive|define
name|XI_ONE_KNOB
value|"ONE_KNOB"
end_define

begin_define
define|#
directive|define
name|XI_NINE_KNOB
value|"NINE_KNOB"
end_define

begin_define
define|#
directive|define
name|XI_TRACKBALL
value|"TRACKBALL"
end_define

begin_define
define|#
directive|define
name|XI_QUADRATURE
value|"QUADRATURE"
end_define

begin_define
define|#
directive|define
name|XI_ID_MODULE
value|"ID_MODULE"
end_define

begin_define
define|#
directive|define
name|XI_SPACEBALL
value|"SPACEBALL"
end_define

begin_define
define|#
directive|define
name|XI_DATAGLOVE
value|"DATAGLOVE"
end_define

begin_define
define|#
directive|define
name|XI_EYETRACKER
value|"EYETRACKER"
end_define

begin_define
define|#
directive|define
name|XI_CURSORKEYS
value|"CURSORKEYS"
end_define

begin_define
define|#
directive|define
name|XI_FOOTMOUSE
value|"FOOTMOUSE"
end_define

begin_define
define|#
directive|define
name|Dont_Check
value|0
end_define

begin_define
define|#
directive|define
name|XInput_Initial_Release
value|1
end_define

begin_define
define|#
directive|define
name|XInput_Add_XDeviceBell
value|2
end_define

begin_define
define|#
directive|define
name|XInput_Add_XSetDeviceValuators
value|3
end_define

begin_define
define|#
directive|define
name|XInput_Add_XChangeDeviceControl
value|4
end_define

begin_define
define|#
directive|define
name|XI_Absent
value|0
end_define

begin_define
define|#
directive|define
name|XI_Present
value|1
end_define

begin_define
define|#
directive|define
name|XI_Initial_Release_Major
value|1
end_define

begin_define
define|#
directive|define
name|XI_Initial_Release_Minor
value|0
end_define

begin_define
define|#
directive|define
name|XI_Add_XDeviceBell_Major
value|1
end_define

begin_define
define|#
directive|define
name|XI_Add_XDeviceBell_Minor
value|1
end_define

begin_define
define|#
directive|define
name|XI_Add_XSetDeviceValuators_Major
value|1
end_define

begin_define
define|#
directive|define
name|XI_Add_XSetDeviceValuators_Minor
value|2
end_define

begin_define
define|#
directive|define
name|XI_Add_XChangeDeviceControl_Major
value|1
end_define

begin_define
define|#
directive|define
name|XI_Add_XChangeDeviceControl_Minor
value|3
end_define

begin_define
define|#
directive|define
name|DEVICE_RESOLUTION
value|1
end_define

begin_define
define|#
directive|define
name|NoSuchExtension
value|1
end_define

begin_define
define|#
directive|define
name|COUNT
value|0
end_define

begin_define
define|#
directive|define
name|CREATE
value|1
end_define

begin_define
define|#
directive|define
name|NewPointer
value|0
end_define

begin_define
define|#
directive|define
name|NewKeyboard
value|1
end_define

begin_define
define|#
directive|define
name|XPOINTER
value|0
end_define

begin_define
define|#
directive|define
name|XKEYBOARD
value|1
end_define

begin_define
define|#
directive|define
name|UseXKeyboard
value|0xFF
end_define

begin_define
define|#
directive|define
name|IsXPointer
value|0
end_define

begin_define
define|#
directive|define
name|IsXKeyboard
value|1
end_define

begin_define
define|#
directive|define
name|IsXExtensionDevice
value|2
end_define

begin_define
define|#
directive|define
name|AsyncThisDevice
value|0
end_define

begin_define
define|#
directive|define
name|SyncThisDevice
value|1
end_define

begin_define
define|#
directive|define
name|ReplayThisDevice
value|2
end_define

begin_define
define|#
directive|define
name|AsyncOtherDevices
value|3
end_define

begin_define
define|#
directive|define
name|AsyncAll
value|4
end_define

begin_define
define|#
directive|define
name|SyncAll
value|5
end_define

begin_define
define|#
directive|define
name|FollowKeyboard
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RevertToFollowKeyboard
end_ifndef

begin_define
define|#
directive|define
name|RevertToFollowKeyboard
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DvAccelNum
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|DvAccelDenom
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|DvThreshold
value|(1L<< 2)
end_define

begin_define
define|#
directive|define
name|DvKeyClickPercent
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|DvPercent
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|DvPitch
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|DvDuration
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|DvLed
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|DvLedMode
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|DvKey
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|DvAutoRepeatMode
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|DvString
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|DvInteger
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|DeviceMode
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|Relative
value|0
end_define

begin_define
define|#
directive|define
name|Absolute
value|1
end_define

begin_define
define|#
directive|define
name|ProximityState
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|InProximity
value|(0L<< 1)
end_define

begin_define
define|#
directive|define
name|OutOfProximity
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|AddToList
value|0
end_define

begin_define
define|#
directive|define
name|DeleteFromList
value|1
end_define

begin_define
define|#
directive|define
name|KeyClass
value|0
end_define

begin_define
define|#
directive|define
name|ButtonClass
value|1
end_define

begin_define
define|#
directive|define
name|ValuatorClass
value|2
end_define

begin_define
define|#
directive|define
name|FeedbackClass
value|3
end_define

begin_define
define|#
directive|define
name|ProximityClass
value|4
end_define

begin_define
define|#
directive|define
name|FocusClass
value|5
end_define

begin_define
define|#
directive|define
name|OtherClass
value|6
end_define

begin_define
define|#
directive|define
name|KbdFeedbackClass
value|0
end_define

begin_define
define|#
directive|define
name|PtrFeedbackClass
value|1
end_define

begin_define
define|#
directive|define
name|StringFeedbackClass
value|2
end_define

begin_define
define|#
directive|define
name|IntegerFeedbackClass
value|3
end_define

begin_define
define|#
directive|define
name|LedFeedbackClass
value|4
end_define

begin_define
define|#
directive|define
name|BellFeedbackClass
value|5
end_define

begin_define
define|#
directive|define
name|_devicePointerMotionHint
value|0
end_define

begin_define
define|#
directive|define
name|_deviceButton1Motion
value|1
end_define

begin_define
define|#
directive|define
name|_deviceButton2Motion
value|2
end_define

begin_define
define|#
directive|define
name|_deviceButton3Motion
value|3
end_define

begin_define
define|#
directive|define
name|_deviceButton4Motion
value|4
end_define

begin_define
define|#
directive|define
name|_deviceButton5Motion
value|5
end_define

begin_define
define|#
directive|define
name|_deviceButtonMotion
value|6
end_define

begin_define
define|#
directive|define
name|_deviceButtonGrab
value|7
end_define

begin_define
define|#
directive|define
name|_deviceOwnerGrabButton
value|8
end_define

begin_define
define|#
directive|define
name|_noExtensionEvent
value|9
end_define

begin_define
define|#
directive|define
name|XI_BadDevice
value|0
end_define

begin_define
define|#
directive|define
name|XI_BadEvent
value|1
end_define

begin_define
define|#
directive|define
name|XI_BadMode
value|2
end_define

begin_define
define|#
directive|define
name|XI_DeviceBusy
value|3
end_define

begin_define
define|#
directive|define
name|XI_BadClass
value|4
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XEventClass
typedef|;
end_typedef

begin_comment
comment|/*******************************************************************  *  * Extension version structure.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|present
decl_stmt|;
name|short
name|major_version
decl_stmt|;
name|short
name|minor_version
decl_stmt|;
block|}
name|XExtensionVersion
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XI_H_ */
end_comment

end_unit

