begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  *   * (c)Copyright 1992 Hewlett-Packard Co.,  All Rights Reserved.  *   *                          RESTRICTED RIGHTS LEGEND  * Use, duplication, or disclosure by the U.S. Government is subject to  * restrictions as set forth in sub-paragraph (c)(1)(ii) of the Rights in  * Technical Data and Computer Software clause in DFARS 252.227-7013.  *   *                          Hewlett-Packard Company  *                          3000 Hanover Street  *                          Palo Alto, CA 94304 U.S.A.  *   * Rights for non-DOD U.S. Government Departments and Agencies are as set  * forth in FAR 52.227-19(c)(1,2).  *  *************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HPEXT_H
end_ifndef

begin_define
define|#
directive|define
name|HPEXT_H
end_define

begin_comment
comment|/* $Header: /host/kaukau/disk2/X11R5/R5-hp300/mit/server/ddx/hpbsd/input/RCS/hpext.h,v 1.1 1992/09/30 03:14:10 root Exp $ */
end_comment

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_define
define|#
directive|define
name|NEED_REPLIES
end_define

begin_include
include|#
directive|include
file|"Xproto.h"
end_include

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"XHPproto.h"
end_include

begin_comment
comment|/* server version definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XINPUT
end_ifdef

begin_include
include|#
directive|include
file|"XIproto.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XINPUT */
end_comment

begin_comment
comment|/* Definitions for HP extensions used by the server and Xlib */
end_comment

begin_comment
comment|/*********************************************************  *  * number of hp events, errors, and extension name.  *  */
end_comment

begin_define
define|#
directive|define
name|HPEVENTS
value|12
end_define

begin_define
define|#
directive|define
name|HPERRORS
value|3
end_define

begin_define
define|#
directive|define
name|CLIENT_REQ
value|1
end_define

begin_define
define|#
directive|define
name|HPNAME
value|"HPExtension"
end_define

begin_define
define|#
directive|define
name|MIN_EVENT_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|MAX_EVENT_REQUEST
value|11
end_define

begin_comment
comment|/*********************************************************  *  * Protocol request constants  *  */
end_comment

begin_define
define|#
directive|define
name|X_GetHpKeyboardId
value|1
end_define

begin_comment
comment|/* DO NOT CHANGE THIS LINE! */
end_comment

begin_define
define|#
directive|define
name|X_HPListInputDevices
value|2
end_define

begin_define
define|#
directive|define
name|X_HPSetInputDevice
value|3
end_define

begin_define
define|#
directive|define
name|X_HPGetExtEventMask
value|4
end_define

begin_define
define|#
directive|define
name|X_HPGetDeviceFocus
value|5
end_define

begin_define
define|#
directive|define
name|X_HPGetClipList
value|6
end_define

begin_define
define|#
directive|define
name|X_HPGrabDevice
value|7
end_define

begin_define
define|#
directive|define
name|X_HPSetDeviceFocus
value|8
end_define

begin_define
define|#
directive|define
name|X_HPUnGrabDevice
value|9
end_define

begin_define
define|#
directive|define
name|X_HPSelectExtensionEvent
value|10
end_define

begin_define
define|#
directive|define
name|X_HPGetCurrentDeviceMask
value|11
end_define

begin_define
define|#
directive|define
name|X_HPEnableReset
value|12
end_define

begin_define
define|#
directive|define
name|X_HPDisableReset
value|13
end_define

begin_define
define|#
directive|define
name|X_HPGetDeviceMotionEvents
value|14
end_define

begin_define
define|#
directive|define
name|X_HPGrabDeviceButton
value|15
end_define

begin_define
define|#
directive|define
name|X_HPUngrabDeviceButton
value|16
end_define

begin_define
define|#
directive|define
name|X_HPGrabDeviceKey
value|17
end_define

begin_define
define|#
directive|define
name|X_HPUngrabDeviceKey
value|18
end_define

begin_define
define|#
directive|define
name|X_HPDeviceAutoRepeatOn
value|19
end_define

begin_define
define|#
directive|define
name|X_HPDeviceAutoRepeatOff
value|20
end_define

begin_define
define|#
directive|define
name|X_HPPrompt
value|21
end_define

begin_define
define|#
directive|define
name|X_HPAcknowledge
value|22
end_define

begin_define
define|#
directive|define
name|X_HPRegisterWindow
value|23
end_define

begin_define
define|#
directive|define
name|X_HPUnRegisterWindow
value|24
end_define

begin_define
define|#
directive|define
name|X_HPSynchronizeColorRange
value|25
end_define

begin_define
define|#
directive|define
name|X_HPGetServerMode
value|26
end_define

begin_define
define|#
directive|define
name|X_HPGetDeviceKeyMapping
value|27
end_define

begin_define
define|#
directive|define
name|X_HPChangeDeviceKeyMapping
value|28
end_define

begin_define
define|#
directive|define
name|X_HPGetDeviceModifierMapping
value|29
end_define

begin_define
define|#
directive|define
name|X_HPSetDeviceModifierMapping
value|30
end_define

begin_define
define|#
directive|define
name|X_HPGetDeviceControl
value|31
end_define

begin_define
define|#
directive|define
name|X_HPChangeDeviceControl
value|32
end_define

begin_define
define|#
directive|define
name|X_HPGetWindowCursor
value|33
end_define

begin_define
define|#
directive|define
name|X_HPGrabReset
value|34
end_define

begin_define
define|#
directive|define
name|X_HPSendDdxDriverMsg
value|35
end_define

begin_define
define|#
directive|define
name|X_HPGetClipLists
value|36
end_define

begin_define
define|#
directive|define
name|X_HPSSChange
value|37
end_define

begin_comment
comment|/* Screen saver change */
end_comment

begin_define
define|#
directive|define
name|sz_xHPListInputDevicesReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_xHPListInputDevicesReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPSetInputDeviceReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPSetInputDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetExtEventMaskReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetExtEventMaskReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceFocusReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceFocusReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetClipListReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPGetClipListReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabDeviceReq
value|24
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabDeviceReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPSetDeviceFocusReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xHPUnGrabDeviceReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPSelectExtensionEventReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPGetCurrentDeviceMaskReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPGetCurrentDeviceMaskReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPEnableResetReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_xHPDisableResetReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceMotionEventsReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceMotionEventsReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabDeviceButtonReq
value|24
end_define

begin_define
define|#
directive|define
name|sz_xHPUngrabDeviceButtonReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabDeviceKeyReq
value|20
end_define

begin_define
define|#
directive|define
name|sz_xHPUngrabDeviceKeyReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPDeviceAutoRepeatOnReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPDeviceAutoRepeatOffReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPPromptReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPAcknowledgeReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPRegisterWindowReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPRegisterWindowReply
value|152
end_define

begin_define
define|#
directive|define
name|sz_xHPSynchronizeColorRangeReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPGetServerModeReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetServerModeReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceKeyMappingReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceKeyMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPChangeDeviceKeyMappingReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceModifierMappingReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceModifierMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPSetDeviceModifierMappingReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPSetDeviceModifierMappingReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceControlReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetDeviceControlReply
value|64
end_define

begin_define
define|#
directive|define
name|sz_xHPChangeDeviceControlReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_xHPGetWindowCursorReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_xHPGetWindowCursorReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabResetReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_xHPGrabResetReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPSendDdxDriverMsgReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPSendDdxDriverMsgReply
value|32
end_define

begin_define
define|#
directive|define
name|sz_xHPGetClipListsReq
value|16
end_define

begin_define
define|#
directive|define
name|sz_xHPGetClipListsReply
value|32
end_define

begin_define
define|#
directive|define
name|GET_HPINPUTDEVICE
parameter_list|(
name|pDev
parameter_list|)
define|\
value|((HPInputDevice *) ((pDev)->public.devicePrivate))
end_define

begin_struct
struct|struct
name|dev_select_info
block|{
name|Mask
name|mask
decl_stmt|;
name|long
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*********************************************************  *  * Protocol request and reply structures.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPListInputDevices */
name|CARD16
name|length
decl_stmt|;
block|}
name|xHPListInputDevicesReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPListInputDevices  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|ndevices
name|B32
decl_stmt|;
name|CARD32
name|t_axes
name|B32
decl_stmt|;
name|CARD32
name|data02
name|B32
decl_stmt|;
name|CARD32
name|data03
name|B32
decl_stmt|;
name|CARD32
name|data04
name|B32
decl_stmt|;
name|CARD32
name|data05
name|B32
decl_stmt|;
block|}
name|xHPListInputDevicesReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPSetInputDevice */
name|CARD16
name|length
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|mode
decl_stmt|;
block|}
name|xHPSetInputDeviceReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPSetInputDevice  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|status
name|B32
decl_stmt|;
name|CARD32
name|data01
name|B32
decl_stmt|;
name|CARD32
name|data02
name|B32
decl_stmt|;
name|CARD32
name|data03
name|B32
decl_stmt|;
name|CARD32
name|data04
name|B32
decl_stmt|;
name|CARD32
name|data05
name|B32
decl_stmt|;
block|}
name|xHPSetInputDeviceReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetExtEventMask */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|evconst
decl_stmt|;
block|}
name|xHPGetExtEventMaskReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetExtEventMask  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|mask
name|B32
decl_stmt|;
name|CARD32
name|evtype
name|B32
decl_stmt|;
name|CARD32
name|data01
name|B32
decl_stmt|;
name|CARD32
name|data02
name|B32
decl_stmt|;
name|CARD32
name|data03
name|B32
decl_stmt|;
name|CARD32
name|data04
name|B32
decl_stmt|;
block|}
name|xHPGetExtEventMaskReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpeqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetCurrentDeviceMask */
name|CARD16
name|length
decl_stmt|;
name|Window
name|window
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPGetCurrentDeviceMaskReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetCurrentDeviceMask  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|mask
name|B32
decl_stmt|;
name|CARD32
name|data01
name|B32
decl_stmt|;
name|CARD32
name|data02
name|B32
decl_stmt|;
name|CARD32
name|data03
name|B32
decl_stmt|;
name|CARD32
name|data04
name|B32
decl_stmt|;
name|CARD32
name|data05
name|B32
decl_stmt|;
block|}
name|xHPGetCurrentDeviceMaskReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetDeviceFocus */
name|CARD16
name|length
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPGetDeviceFocusReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetDeviceFocus  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|status
name|B32
decl_stmt|;
name|CARD32
name|focus
name|B32
decl_stmt|;
name|Window
name|revertTo
name|B32
decl_stmt|;
name|CARD32
name|data01
name|B32
decl_stmt|;
name|CARD32
name|data02
name|B32
decl_stmt|;
name|CARD32
name|data03
name|B32
decl_stmt|;
block|}
name|xHPGetDeviceFocusReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPSetDeviceFocus */
name|CARD16
name|length
decl_stmt|;
name|Window
name|focus
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|Time
name|time
name|B32
decl_stmt|;
name|CARD8
name|revertTo
decl_stmt|;
name|CARD8
name|pad00
decl_stmt|;
name|CARD16
name|pad01
decl_stmt|;
block|}
name|xHPSetDeviceFocusReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGrabDevice */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|grabWindow
name|B32
decl_stmt|;
name|Time
name|time
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|eventMask
name|B32
decl_stmt|;
name|BOOL
name|ownerEvents
decl_stmt|;
name|CARD8
name|pad00
decl_stmt|;
name|CARD16
name|pad01
name|B16
decl_stmt|;
block|}
name|xHPGrabDeviceReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGrabDevice  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
comment|/* 0 */
name|CARD32
name|status
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
name|CARD32
name|pad6
name|B32
decl_stmt|;
name|CARD32
name|pad7
name|B32
decl_stmt|;
block|}
name|xHPGrabDeviceReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPUnGrabDevice */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Time
name|time
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPUnGrabDeviceReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPSelectExtensionEvent */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|window
name|B32
decl_stmt|;
name|CARD32
name|extensionMask
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPSelectExtensionEventReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPEnableReset          */
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|xHPEnableResetReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPDisableReset          */
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|xHPDisableResetReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetDeviceMotionEvents*/
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|window
name|B32
decl_stmt|;
name|Time
name|start
name|B32
decl_stmt|;
name|Time
name|stop
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPGetDeviceMotionEventsReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetDeviceMotionEvents  */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|nEvents
name|B32
decl_stmt|;
name|INT16
name|axes
name|B16
decl_stmt|;
name|CARD16
name|pad2
name|B16
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
name|CARD32
name|pad6
name|B32
decl_stmt|;
block|}
name|xHPGetDeviceMotionEventsReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGrabDeviceButton */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|grabWindow
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|eventMask
decl_stmt|;
name|CARD16
name|modifiers
name|B16
decl_stmt|;
name|BOOL
name|ownerEvents
decl_stmt|;
name|CARD8
name|button
decl_stmt|;
name|BYTE
name|pointerMode
decl_stmt|,
name|keyboardMode
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|,
name|pad2
decl_stmt|;
block|}
name|xHPGrabDeviceButtonReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPUngrabDeviceButton */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|grabWindow
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD16
name|modifiers
name|B16
decl_stmt|;
name|CARD8
name|button
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|;
block|}
name|xHPUngrabDeviceButtonReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGrabDeviceKey */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|grabWindow
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD16
name|modifiers
name|B16
decl_stmt|;
name|BOOL
name|ownerEvents
decl_stmt|;
name|CARD8
name|key
decl_stmt|;
name|BYTE
name|pointerMode
decl_stmt|,
name|keyboardMode
decl_stmt|;
name|BYTE
name|pad1
decl_stmt|,
name|pad2
decl_stmt|;
block|}
name|xHPGrabDeviceKeyReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPUngrabDeviceKey */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|grabWindow
name|B32
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD16
name|modifiers
name|B16
decl_stmt|;
name|CARD8
name|key
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|;
block|}
name|xHPUngrabDeviceKeyReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPDeviceAutoRepeatOn */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|INT32
name|rate
decl_stmt|;
block|}
name|xHPDeviceAutoRepeatOnReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPDeviceAutoRepeatOff */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPDeviceAutoRepeatOffReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPPrompt */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD8
name|prompt
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|,
name|pad2
decl_stmt|,
name|pad3
decl_stmt|;
block|}
name|xHPPromptReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPAcknowledge */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD8
name|ack
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|,
name|pad2
decl_stmt|,
name|pad3
decl_stmt|;
block|}
name|xHPAcknowledgeReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetServerMode */
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|screen
name|B32
decl_stmt|;
block|}
name|xHPGetServerModeReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetServerMode */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD32
name|mode
name|B32
decl_stmt|;
name|CARD32
name|pad1
name|B32
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
block|}
name|xHPGetServerModeReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetDeviceKeyMapping */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|KeyCode
name|firstKeyCode
decl_stmt|;
name|CARD8
name|count
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
block|}
name|xHPGetDeviceKeyMappingReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetDeviceKeyMapping */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD8
name|keySymsPerKeyCode
decl_stmt|;
name|CARD8
name|pad0
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
name|CARD32
name|pad6
name|B32
decl_stmt|;
block|}
name|xHPGetDeviceKeyMappingReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPChangeDeviceKeyMapping */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD8
name|keyCodes
decl_stmt|;
name|KeyCode
name|firstKeyCode
decl_stmt|;
name|CARD8
name|keySymsPerKeyCode
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|;
block|}
name|xHPChangeDeviceKeyMappingReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetDeviceModifierMapping */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPGetDeviceModifierMappingReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetDeviceModifierMapping */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD8
name|numKeyPerModifier
decl_stmt|;
name|CARD8
name|pad0
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
name|CARD32
name|pad6
name|B32
decl_stmt|;
block|}
name|xHPGetDeviceModifierMappingReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPSetDeviceModifierMapping */
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD8
name|numKeyPerModifier
decl_stmt|;
name|CARD8
name|pad1
decl_stmt|;
name|CARD16
name|pad2
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPSetDeviceModifierMappingReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPSetDeviceModifierMapping */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|CARD8
name|success
decl_stmt|;
name|CARD8
name|pad0
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
name|CARD32
name|pad6
name|B32
decl_stmt|;
block|}
name|xHPSetDeviceModifierMappingReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetDeviceControl */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
block|}
name|xHPGetDeviceControlReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetDeviceControl */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|BOOL
name|globalAutoRepeat
decl_stmt|;
name|CARD8
name|keyClickPercent
decl_stmt|;
name|CARD8
name|bellPercent
decl_stmt|;
name|CARD8
name|pad0
decl_stmt|;
name|CARD32
name|ledMask
name|B32
decl_stmt|;
name|CARD16
name|bellPitch
name|B16
decl_stmt|;
name|CARD16
name|bellDuration
name|B16
decl_stmt|;
name|CARD16
name|accelNumerator
name|B16
decl_stmt|;
name|CARD16
name|accelDenominator
name|B16
decl_stmt|;
name|CARD16
name|threshold
name|B16
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|BYTE
name|map
index|[
literal|32
index|]
decl_stmt|;
comment|/* bit masks start here */
block|}
name|xHPGetDeviceControlReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPChangeDeviceControl */
name|CARD16
name|length
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|mask
name|B32
decl_stmt|;
block|}
name|xHPChangeDeviceControlReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_GetWindowCursor */
name|CARD16
name|length
name|B16
decl_stmt|;
name|Window
name|window
name|B32
decl_stmt|;
block|}
name|xHPGetWindowCursorReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* X_Reply */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* always X_HPGetWindowCursor */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|Cursor
name|cursor
name|B32
decl_stmt|;
name|CARD32
name|pad1
name|B32
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
block|}
name|xHPGetWindowCursorReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetClipList */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|wid
decl_stmt|;
comment|/* window id */
name|CARD32
name|gcid
decl_stmt|;
comment|/* graphics context id */
name|CARD32
name|format
decl_stmt|;
comment|/* clip list format */
block|}
name|xHPGetClipListReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
comment|/* X_Reply */
name|BYTE
name|pad0
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|INT16
name|x
name|B16
decl_stmt|;
comment|/* x origin of window */
name|INT16
name|y
name|B16
decl_stmt|;
comment|/* y origin of window */
name|CARD16
name|width
name|B16
decl_stmt|;
comment|/* width of window */
name|CARD16
name|height
name|B16
decl_stmt|;
comment|/* height of window */
name|CARD32
name|count
name|B32
decl_stmt|;
comment|/* number of clipping rectanges */
name|CARD32
name|data03
name|B32
decl_stmt|;
name|CARD32
name|data04
name|B32
decl_stmt|;
name|CARD32
name|data05
name|B32
decl_stmt|;
block|}
name|xHPGetClipListReply
typedef|;
end_typedef

begin_comment
comment|/*  *  X_HPRegisterWindow request/reply structures...  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* X_HPRegisterWindow or X_HPUnReg... */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|wid
decl_stmt|;
comment|/* window id */
name|CARD32
name|accelid
decl_stmt|;
comment|/* accelerated id */
name|CARD32
name|flags
decl_stmt|;
comment|/* flags */
block|}
name|xHPRegisterWindowReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
comment|/* X_Reply */
name|BYTE
name|pad0
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|INT32
name|error
name|B32
decl_stmt|;
comment|/* error status */
name|CARD32
name|flags
name|B32
decl_stmt|;
comment|/* flags */
name|BYTE
name|path
index|[
literal|80
index|]
decl_stmt|;
comment|/* length must>= cfbPrivScreen->path */
name|CARD32
name|depth
name|B32
decl_stmt|;
comment|/* depth of window */
name|INT32
name|w_class
name|B32
decl_stmt|;
comment|/* window GRM_ID class */
name|INT32
name|w_screen
name|B32
decl_stmt|;
comment|/* window GRM_ID screen */
name|INT32
name|w_window
name|B32
decl_stmt|;
comment|/* window GRM_ID window */
name|BYTE
name|w_name
index|[
literal|40
index|]
decl_stmt|;
comment|/* window GRM_ID name */
block|}
name|xHPRegisterWindowReply
typedef|;
end_typedef

begin_comment
comment|/*  *  X_HPSynchronizeColorRange Request structure (no reply)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* X_HPRegisterWindow or X_HPUnReg... */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|cmap
decl_stmt|;
comment|/* Colormap ID of interest */
name|CARD32
name|start
decl_stmt|;
comment|/* Starting pixel if changes to cmap */
name|CARD32
name|ncolors
decl_stmt|;
comment|/* number of pixels changed */
block|}
name|xHPSynchronizeColorRangeReq
typedef|;
end_typedef

begin_comment
comment|/*  *  X_HPSendDdxDriverMsg Request structure (possible reply)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* X_HPRegisterWindow or X_HPUnReg... */
name|CARD16
name|length
decl_stmt|;
name|Window
name|window
decl_stmt|;
comment|/* window of interest */
name|INT32
name|nMsgBytes
decl_stmt|;
comment|/* Number of bytes in message */
name|INT32
name|needReply
decl_stmt|;
comment|/* whether or not a reply is forthcoming */
block|}
name|xHPSendDdxDriverMsgReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|type
decl_stmt|;
name|CARD8
name|pad0
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|INT32
name|nRepBytes
decl_stmt|;
name|CARD32
name|pad1
name|B32
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
block|}
name|xHPSendDdxDriverMsgReply
typedef|;
end_typedef

begin_comment
comment|/*  * XHPGetClipLists request (not to be confused with XHPGetClipList.  * This extension gets multiple clip lists)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* always X_HPGetClipLists */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|wid
decl_stmt|;
comment|/* window id */
name|CARD32
name|gcid
decl_stmt|;
comment|/* graphics context id */
name|CARD32
name|nClipLists
decl_stmt|;
comment|/* number of clip lists requested */
comment|/* To be followed by 'nClipLists' CARD32 format longwords: */
block|}
name|xHPGetClipListsReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
comment|/* X_Reply */
name|BYTE
name|pad0
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|INT16
name|x
name|B16
decl_stmt|;
comment|/* x origin of window */
name|INT16
name|y
name|B16
decl_stmt|;
comment|/* y origin of window */
name|CARD16
name|width
name|B16
decl_stmt|;
comment|/* width of window */
name|CARD16
name|height
name|B16
decl_stmt|;
comment|/* height of window */
name|CARD32
name|count
name|B32
decl_stmt|;
comment|/* number of clip lists */
name|CARD32
name|pad1
name|B32
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
comment|/* To be followed by 'count' xHPGetClipListsReplyData structures: */
block|}
name|xHPGetClipListsReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD16
name|count
name|B16
decl_stmt|;
comment|/* number of clip boxes */
name|CARD16
name|size
name|B16
decl_stmt|;
comment|/* size of each clip box in bytes */
comment|/* To be followed by 'count * size' bytes: */
block|}
name|xHPGetClipListsReplyData
typedef|;
end_typedef

begin_comment
comment|/*  X_HPGrabReset Request structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* X_HPGrabReset */
name|CARD16
name|length
decl_stmt|;
block|}
name|xHPGrabResetReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* X_HPGrabReset */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|Atom
name|evtype
name|B32
decl_stmt|;
comment|/* event type to expect */
name|CARD32
name|pad1
name|B32
decl_stmt|;
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
block|}
name|xHPGrabResetReply
typedef|;
end_typedef

begin_comment
comment|/*  X_HPSSChange Request structures  *  Notes:  *    The sz_x numbers are sizeof(struct) padded to the to 4 bytes.  This to  *    make the X packets work correctly.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpReqType
decl_stmt|;
comment|/* X_HPSSChange */
name|CARD16
name|length
decl_stmt|;
name|CARD32
name|flags
decl_stmt|;
comment|/* stuff */
name|CARD32
name|wid
decl_stmt|;
comment|/* just in case */
block|}
name|xHPSSChangeReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xHPSSChangeReq
value|12
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|repType
decl_stmt|;
comment|/* always HpReqCode */
name|CARD8
name|hpRepType
decl_stmt|;
comment|/* X_HPSSChange */
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
name|Atom
name|evtype
name|B32
decl_stmt|;
comment|/* event type to expect */
name|CARD32
name|flags
name|B32
decl_stmt|;
comment|/*  */
name|CARD32
name|pad2
name|B32
decl_stmt|;
name|CARD32
name|pad3
name|B32
decl_stmt|;
name|CARD32
name|pad4
name|B32
decl_stmt|;
name|CARD32
name|pad5
name|B32
decl_stmt|;
block|}
name|xHPSSChangeReply
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xHPSSChangeReply
value|32
end_define

begin_comment
comment|/**********************************************************  *  * extension events.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|INT16
name|ax_num
decl_stmt|;
name|INT16
name|ax_val
decl_stmt|;
block|}
name|XHPaxis_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
name|BYTE
name|count
decl_stmt|;
name|CARD16
name|sequencenumber
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|pad00
name|B32
decl_stmt|;
name|CARD32
name|pad01
name|B32
decl_stmt|;
name|CARD32
name|pad02
name|B32
decl_stmt|;
name|CARD32
name|pad03
name|B32
decl_stmt|;
name|CARD32
name|pad04
name|B32
decl_stmt|;
name|CARD32
name|pad05
name|B32
decl_stmt|;
block|}
name|xAnyExtensionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
name|BYTE
name|ext_type
decl_stmt|;
name|CARD16
name|sequencenumber
name|B16
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|INT16
name|axes_count
name|B16
decl_stmt|;
name|CARD16
name|pad00
name|B16
decl_stmt|;
name|XHPaxis_data
name|data
index|[
literal|4
index|]
decl_stmt|;
name|CARD32
name|pad01
name|B32
decl_stmt|;
block|}
name|xHPExtensionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|xEvent
name|b
decl_stmt|;
name|xAnyExtensionEvent
name|x
decl_stmt|;
block|}
name|xAnyEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|xEvent
name|b
decl_stmt|;
ifdef|#
directive|ifdef
name|XINPUT
name|deviceValuator
name|x
decl_stmt|;
else|#
directive|else
name|xHPExtensionEvent
name|x
decl_stmt|;
endif|#
directive|endif
comment|/* XINPUT */
block|}
name|xHPEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
name|BYTE
name|pad00
decl_stmt|;
name|CARD16
name|sequencenumber
name|B16
decl_stmt|;
name|INT16
name|detail
name|B16
decl_stmt|;
name|BYTE
name|mode
decl_stmt|;
comment|/* really XMode */
name|BYTE
name|pad1
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|Window
name|window
name|B32
decl_stmt|;
name|CARD32
name|pad01
name|B32
decl_stmt|;
name|CARD32
name|pad02
name|B32
decl_stmt|;
name|CARD32
name|pad03
name|B32
decl_stmt|;
name|CARD32
name|pad04
name|B32
decl_stmt|;
block|}
name|xHPdevicefocus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
name|BYTE
name|pad00
decl_stmt|;
name|CARD16
name|sequencenumber
name|B16
decl_stmt|;
name|CARD8
name|request
decl_stmt|;
name|KeyCode
name|firstKeyCode
decl_stmt|;
name|CARD8
name|count
decl_stmt|;
name|BYTE
name|pad1
decl_stmt|;
name|XID
name|deviceid
decl_stmt|;
name|CARD32
name|pad01
name|B32
decl_stmt|;
name|CARD32
name|pad02
name|B32
decl_stmt|;
name|CARD32
name|pad03
name|B32
decl_stmt|;
name|CARD32
name|pad04
name|B32
decl_stmt|;
name|CARD32
name|pad05
name|B32
decl_stmt|;
block|}
name|xHPDeviceMappingEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|BYTE
name|type
decl_stmt|;
name|BYTE
name|deviceid
decl_stmt|;
name|BYTE
name|map
index|[
literal|30
index|]
decl_stmt|;
block|}
name|xHPDeviceKeymapEvent
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

