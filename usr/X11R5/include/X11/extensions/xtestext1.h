begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * xtestext1.h  *  * X11 Input Synthesis Extension include file  */
end_comment

begin_comment
comment|/*  Copyright 1986, 1987, 1988 by Hewlett-Packard Corporation Copyright 1986, 1987, 1988 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  Hewlett-Packard and M.I.T. make no representations about the  suitability of this software for any purpose.  It is provided  "as is" without express or implied warranty.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/*  * the typedefs for CARD8, CARD16, and CARD32 are defined in Xmd.h  */
end_comment

begin_comment
comment|/*  * used in the XTestPressButton and XTestPressKey functions  */
end_comment

begin_define
define|#
directive|define
name|XTestPRESS
value|1<< 0
end_define

begin_define
define|#
directive|define
name|XTestRELEASE
value|1<< 1
end_define

begin_define
define|#
directive|define
name|XTestSTROKE
value|1<< 2
end_define

begin_comment
comment|/*  * When doing a key or button stroke, the number of milliseconds  * to delay between the press and the release of a key or button  * in the XTestPressButton and XTestPressKey functions.  */
end_comment

begin_define
define|#
directive|define
name|XTestSTROKE_DELAY_TIME
value|10
end_define

begin_comment
comment|/*  * used in the XTestGetInput function  */
end_comment

begin_define
define|#
directive|define
name|XTestEXCLUSIVE
value|1<< 0
end_define

begin_define
define|#
directive|define
name|XTestPACKED_ACTIONS
value|1<< 1
end_define

begin_define
define|#
directive|define
name|XTestPACKED_MOTION
value|1<< 2
end_define

begin_comment
comment|/*  * used in the XTestFakeInput function  */
end_comment

begin_define
define|#
directive|define
name|XTestFAKE_ACK_NOT_NEEDED
value|0
end_define

begin_define
define|#
directive|define
name|XTestFAKE_ACK_REQUEST
value|1
end_define

begin_comment
comment|/*  * used in the XTest extension initialization routine  */
end_comment

begin_define
define|#
directive|define
name|XTestEXTENSION_NAME
value|"XTestExtension1"
end_define

begin_define
define|#
directive|define
name|XTestEVENT_COUNT
value|2
end_define

begin_comment
comment|/*  * XTest request type values   *  * used in the XTest extension protocol requests  */
end_comment

begin_define
define|#
directive|define
name|X_TestFakeInput
value|1
end_define

begin_define
define|#
directive|define
name|X_TestGetInput
value|2
end_define

begin_define
define|#
directive|define
name|X_TestStopInput
value|3
end_define

begin_define
define|#
directive|define
name|X_TestReset
value|4
end_define

begin_define
define|#
directive|define
name|X_TestQueryInputSize
value|5
end_define

begin_comment
comment|/*  * This defines the maximum size of a list of input actions  * to be sent to the server.  It should always be a multiple of  * 4 so that the entire xTestFakeInputReq structure size is a  * multiple of 4.  */
end_comment

begin_define
define|#
directive|define
name|XTestMAX_ACTION_LIST_SIZE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always XTestReqCode             */
name|CARD8
name|XTestReqType
decl_stmt|;
comment|/* always X_TestFakeInput           */
name|CARD16
name|length
name|B16
decl_stmt|;
comment|/* 2 + XTestMAX_ACTION_LIST_SIZE/4 */
name|CARD32
name|ack
name|B32
decl_stmt|;
name|CARD8
name|action_list
index|[
name|XTestMAX_ACTION_LIST_SIZE
index|]
decl_stmt|;
block|}
name|xTestFakeInputReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xTestFakeInputReq
value|(XTestMAX_ACTION_LIST_SIZE + 8)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always XTestReqCode  */
name|CARD8
name|XTestReqType
decl_stmt|;
comment|/* always X_TestGetInput */
name|CARD16
name|length
name|B16
decl_stmt|;
comment|/* 2                    */
name|CARD32
name|mode
name|B32
decl_stmt|;
block|}
name|xTestGetInputReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xTestGetInputReq
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always XTestReqCode   */
name|CARD8
name|XTestReqType
decl_stmt|;
comment|/* always X_TestStopInput */
name|CARD16
name|length
name|B32
decl_stmt|;
comment|/* 1                     */
block|}
name|xTestStopInputReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xTestStopInputReq
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always XTestReqCode */
name|CARD8
name|XTestReqType
decl_stmt|;
comment|/* always X_TestReset   */
name|CARD16
name|length
name|B16
decl_stmt|;
comment|/* 1                   */
block|}
name|xTestResetReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xTestResetReq
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|reqType
decl_stmt|;
comment|/* always XTestReqCode        */
name|CARD8
name|XTestReqType
decl_stmt|;
comment|/* always X_TestQueryInputSize */
name|CARD16
name|length
name|B16
decl_stmt|;
comment|/* 1                          */
block|}
name|xTestQueryInputSizeReq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sz_xTestQueryInputSizeReq
value|4
end_define

begin_comment
comment|/*  * This is the definition of the reply for the xTestQueryInputSize  * request.  It should remain the same minimum size as other replies  * (32 bytes).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|type
decl_stmt|;
comment|/* always X_Reply  */
name|CARD8
name|pad1
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD32
name|length
name|B32
decl_stmt|;
comment|/* always 0 */
name|CARD32
name|size_return
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
name|CARD32
name|pad6
name|B32
decl_stmt|;
block|}
name|xTestQueryInputSizeReply
typedef|;
end_typedef

begin_comment
comment|/*  * This is the definition for the input action wire event structure.  * This event is sent to the client when the server has one or  * more user input actions to report to the client.  It must  * remain the same size as all other wire events (32 bytes).  */
end_comment

begin_define
define|#
directive|define
name|XTestACTIONS_SIZE
value|28
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|type
decl_stmt|;
comment|/* always XTestInputActionType */
name|CARD8
name|pad00
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
decl_stmt|;
name|CARD8
name|actions
index|[
name|XTestACTIONS_SIZE
index|]
decl_stmt|;
block|}
name|xTestInputActionEvent
typedef|;
end_typedef

begin_comment
comment|/*  * This is the definition for the xTestFakeAck wire event structure.  * This event is sent to the client when the server has completely  * processed its input action buffer, and is ready for more.  * It must remain the same size as all other wire events (32 bytes).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|type
decl_stmt|;
comment|/* always XTestFakeAckType */
name|CARD8
name|pad00
decl_stmt|;
name|CARD16
name|sequenceNumber
name|B16
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
name|CARD32
name|pad06
name|B32
decl_stmt|;
name|CARD32
name|pad07
name|B32
decl_stmt|;
name|CARD32
name|pad08
name|B32
decl_stmt|;
block|}
name|xTestFakeAckEvent
typedef|;
end_typedef

begin_comment
comment|/*  * The server side of this extension does not (and should not) have  * definitions for Display and Window.  The ifndef allows the server  * side of the extension to ignore the following typedefs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XTestSERVER_SIDE
end_ifndef

begin_comment
comment|/*  * This is the definition for the input action host format event structure.  * This is the form that a client using this extension will see when  * it receives an input action event.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* always XTestInputActionType */
name|Display
modifier|*
name|display
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|CARD8
name|actions
index|[
name|XTestACTIONS_SIZE
index|]
decl_stmt|;
block|}
name|XTestInputActionEvent
typedef|;
end_typedef

begin_comment
comment|/*  * This is the definition for the xTestFakeAck host format event structure.  * This is the form that a client using this extension will see when  * it receives an XTestFakeAck event.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* always XTestFakeAckType */
name|Display
modifier|*
name|display
decl_stmt|;
name|Window
name|window
decl_stmt|;
block|}
name|XTestFakeAckEvent
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This is the definition for the format of the header byte  * in the input action structures.  */
end_comment

begin_define
define|#
directive|define
name|XTestACTION_TYPE_MASK
value|0x03
end_define

begin_comment
comment|/* bits 0 and 1          */
end_comment

begin_define
define|#
directive|define
name|XTestKEY_STATE_MASK
value|0x04
end_define

begin_comment
comment|/* bit 2 (key action)    */
end_comment

begin_define
define|#
directive|define
name|XTestX_SIGN_BIT_MASK
value|0x04
end_define

begin_comment
comment|/* bit 2 (motion action) */
end_comment

begin_define
define|#
directive|define
name|XTestY_SIGN_BIT_MASK
value|0x08
end_define

begin_comment
comment|/* bit 3 (motion action) */
end_comment

begin_define
define|#
directive|define
name|XTestDEVICE_ID_MASK
value|0xf0
end_define

begin_comment
comment|/* bits 4 through 7      */
end_comment

begin_define
define|#
directive|define
name|XTestMAX_DEVICE_ID
value|0x0f
end_define

begin_define
define|#
directive|define
name|XTestPackDeviceID
parameter_list|(
name|x
parameter_list|)
value|(((x)& XTestMAX_DEVICE_ID)<< 4)
end_define

begin_define
define|#
directive|define
name|XTestUnpackDeviceID
parameter_list|(
name|x
parameter_list|)
value|(((x)& XTestDEVICE_ID_MASK)>> 4)
end_define

begin_comment
comment|/*  * These are the possible action types.  */
end_comment

begin_define
define|#
directive|define
name|XTestDELAY_ACTION
value|0
end_define

begin_define
define|#
directive|define
name|XTestKEY_ACTION
value|1
end_define

begin_define
define|#
directive|define
name|XTestMOTION_ACTION
value|2
end_define

begin_define
define|#
directive|define
name|XTestJUMP_ACTION
value|3
end_define

begin_comment
comment|/*  * These are the definitions for key/button motion input actions.  */
end_comment

begin_define
define|#
directive|define
name|XTestKEY_UP
value|0x04
end_define

begin_define
define|#
directive|define
name|XTestKEY_DOWN
value|0x00
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|header
decl_stmt|;
comment|/* which device, key up/down */
name|CARD8
name|keycode
decl_stmt|;
comment|/* which key/button to move  */
name|CARD16
name|delay_time
name|B16
decl_stmt|;
comment|/* how long to delay (in ms) */
block|}
name|XTestKeyInfo
typedef|;
end_typedef

begin_comment
comment|/*  * This is the definition for pointer jump input actions.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|header
decl_stmt|;
comment|/* which pointer             */
name|CARD8
name|pad1
decl_stmt|;
comment|/* unused padding byte       */
name|CARD16
name|jumpx
name|B16
decl_stmt|;
comment|/* x coord to jump to        */
name|CARD16
name|jumpy
name|B16
decl_stmt|;
comment|/* y coord to jump to        */
name|CARD16
name|delay_time
name|B16
decl_stmt|;
comment|/* how long to delay (in ms) */
block|}
name|XTestJumpInfo
typedef|;
end_typedef

begin_comment
comment|/*  * These are the definitions for pointer relative motion input  * actions.  *  * The sign bits for the x and y relative motions are contained  * in the header byte.  The x and y relative motions are packed  * into one byte to make things fit in 32 bits.  If the relative  * motion range is larger than +/-15, use the pointer jump action.  */
end_comment

begin_define
define|#
directive|define
name|XTestMOTION_MAX
value|15
end_define

begin_define
define|#
directive|define
name|XTestMOTION_MIN
value|-15
end_define

begin_define
define|#
directive|define
name|XTestX_NEGATIVE
value|0x04
end_define

begin_define
define|#
directive|define
name|XTestY_NEGATIVE
value|0x08
end_define

begin_define
define|#
directive|define
name|XTestX_MOTION_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|XTestY_MOTION_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|XTestPackXMotionValue
parameter_list|(
name|x
parameter_list|)
value|((x)& XTestX_MOTION_MASK)
end_define

begin_define
define|#
directive|define
name|XTestPackYMotionValue
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 4)& XTestY_MOTION_MASK)
end_define

begin_define
define|#
directive|define
name|XTestUnpackXMotionValue
parameter_list|(
name|x
parameter_list|)
value|((x)& XTestX_MOTION_MASK)
end_define

begin_define
define|#
directive|define
name|XTestUnpackYMotionValue
parameter_list|(
name|x
parameter_list|)
value|(((x)& XTestY_MOTION_MASK)>> 4)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|header
decl_stmt|;
comment|/* which pointer             */
name|CARD8
name|motion_data
decl_stmt|;
comment|/* x,y relative motion       */
name|CARD16
name|delay_time
name|B16
decl_stmt|;
comment|/* how long to delay (in ms) */
block|}
name|XTestMotionInfo
typedef|;
end_typedef

begin_comment
comment|/*  * These are the definitions for a long delay input action.  It is   * used when more than XTestSHORT_DELAY_TIME milliseconds of delay  * (approximately one minute) is needed.  *  * The device ID for a delay is always set to XTestDELAY_DEVICE_ID.  * This guarantees that a header byte with a value of 0 is not  * a valid header, so it can be used as a flag to indicate that  * there are no more input actions in an XTestInputAction event.  */
end_comment

begin_define
define|#
directive|define
name|XTestSHORT_DELAY_TIME
value|0xffff
end_define

begin_define
define|#
directive|define
name|XTestDELAY_DEVICE_ID
value|0x0f
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CARD8
name|header
decl_stmt|;
comment|/* always XTestDELAY_DEVICE_ID */
name|CARD8
name|pad1
decl_stmt|;
comment|/* unused padding byte         */
name|CARD16
name|pad2
name|B16
decl_stmt|;
comment|/* unused padding word         */
name|CARD32
name|delay_time
name|B32
decl_stmt|;
comment|/* how long to delay (in ms)   */
block|}
name|XTestDelayInfo
typedef|;
end_typedef

end_unit

