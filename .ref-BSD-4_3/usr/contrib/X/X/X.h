begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/* $Header: X.h,v 10.10 86/02/01 15:15:16 tony Rel $ */
end_comment

begin_comment
comment|/* Definitions for the X window system likely to be used by applications */
end_comment

begin_define
define|#
directive|define
name|X_PROTOCOL
value|10
end_define

begin_comment
comment|/* current protocol version */
end_comment

begin_comment
comment|/* Resources */
end_comment

begin_typedef
typedef|typedef
name|long
name|Window
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Font
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Bitmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Pixmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Cursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Locator
typedef|;
end_typedef

begin_comment
comment|/* Input Event Codes */
end_comment

begin_define
define|#
directive|define
name|NoEvent
value|0x0000
end_define

begin_define
define|#
directive|define
name|KeyPressed
value|0x0001
end_define

begin_comment
comment|/* keyboard key pressed */
end_comment

begin_define
define|#
directive|define
name|KeyReleased
value|0x0002
end_define

begin_comment
comment|/* keyboard key released */
end_comment

begin_define
define|#
directive|define
name|ButtonPressed
value|0x0004
end_define

begin_comment
comment|/* mouse button pressed */
end_comment

begin_define
define|#
directive|define
name|ButtonReleased
value|0x0008
end_define

begin_comment
comment|/* mouse button released */
end_comment

begin_define
define|#
directive|define
name|EnterWindow
value|0x0010
end_define

begin_comment
comment|/* mouse entering window */
end_comment

begin_define
define|#
directive|define
name|LeaveWindow
value|0x0020
end_define

begin_comment
comment|/* mouse leaving window */
end_comment

begin_define
define|#
directive|define
name|MouseMoved
value|0x0040
end_define

begin_comment
comment|/* mouse moves within window */
end_comment

begin_define
define|#
directive|define
name|ExposeWindow
value|0x0080
end_define

begin_comment
comment|/* full window changed and/or exposed */
end_comment

begin_define
define|#
directive|define
name|ExposeRegion
value|0x0100
end_define

begin_comment
comment|/* region of window exposed */
end_comment

begin_define
define|#
directive|define
name|ExposeCopy
value|0x0200
end_define

begin_comment
comment|/* region exposed by X_CopyArea */
end_comment

begin_define
define|#
directive|define
name|RightDownMotion
value|0x0400
end_define

begin_comment
comment|/* mouse moves with right button down */
end_comment

begin_define
define|#
directive|define
name|MiddleDownMotion
value|0x0800
end_define

begin_comment
comment|/* mouse moves with middle button down */
end_comment

begin_define
define|#
directive|define
name|LeftDownMotion
value|0x1000
end_define

begin_comment
comment|/* mouse moves with left button down */
end_comment

begin_define
define|#
directive|define
name|UnmapWindow
value|0x2000
end_define

begin_comment
comment|/* window is unmapped */
end_comment

begin_define
define|#
directive|define
name|FocusChange
value|0x4000
end_define

begin_comment
comment|/* keyboard focus changed */
end_comment

begin_comment
comment|/* Event detail bits */
end_comment

begin_define
define|#
directive|define
name|ControlMask
value|0x4000
end_define

begin_comment
comment|/* Control key */
end_comment

begin_define
define|#
directive|define
name|MetaMask
value|0x2000
end_define

begin_comment
comment|/* Meta (Symbol) key */
end_comment

begin_define
define|#
directive|define
name|ShiftMask
value|0x1000
end_define

begin_comment
comment|/* Shift key */
end_comment

begin_define
define|#
directive|define
name|ShiftLockMask
value|0x0800
end_define

begin_comment
comment|/* ShiftLock key */
end_comment

begin_define
define|#
directive|define
name|LeftMask
value|0x0400
end_define

begin_comment
comment|/* Left button */
end_comment

begin_define
define|#
directive|define
name|MiddleMask
value|0x0200
end_define

begin_comment
comment|/* Middle button */
end_comment

begin_define
define|#
directive|define
name|RightMask
value|0x0100
end_define

begin_comment
comment|/* Right button */
end_comment

begin_define
define|#
directive|define
name|ValueMask
value|0x00ff
end_define

begin_comment
comment|/* Key/button code */
end_comment

begin_define
define|#
directive|define
name|KeyState
parameter_list|(
name|x
parameter_list|)
value|(((x)& (ControlMask|MetaMask|ShiftMask))>> 12)
end_define

begin_define
define|#
directive|define
name|FullKeyState
parameter_list|(
name|x
parameter_list|)
value|(((x)& (ControlMask|MetaMask|ShiftMask|ShiftLockMask))>> 11)
end_define

begin_define
define|#
directive|define
name|ButtonState
parameter_list|(
name|x
parameter_list|)
value|(((x)& (LeftMask|MiddleMask|RightMask))>> 8)
end_define

begin_comment
comment|/* Button event detail codes */
end_comment

begin_define
define|#
directive|define
name|RightButton
value|0
end_define

begin_define
define|#
directive|define
name|MiddleButton
value|1
end_define

begin_define
define|#
directive|define
name|LeftButton
value|2
end_define

begin_comment
comment|/* Enter/Leave event detail codes */
end_comment

begin_define
define|#
directive|define
name|IntoOrFromSubwindow
value|1
end_define

begin_define
define|#
directive|define
name|VirtualCrossing
value|2
end_define

begin_comment
comment|/* These are the error codes */
end_comment

begin_define
define|#
directive|define
name|BadRequest
value|1
end_define

begin_comment
comment|/* bad request code */
end_comment

begin_define
define|#
directive|define
name|BadValue
value|2
end_define

begin_comment
comment|/* int parameter out of range */
end_comment

begin_define
define|#
directive|define
name|BadWindow
value|3
end_define

begin_comment
comment|/* parameter not a Window */
end_comment

begin_define
define|#
directive|define
name|BadPixmap
value|4
end_define

begin_comment
comment|/* parameter not a Pixmap */
end_comment

begin_define
define|#
directive|define
name|BadBitmap
value|5
end_define

begin_comment
comment|/* parameter not a Bitmap */
end_comment

begin_define
define|#
directive|define
name|BadCursor
value|6
end_define

begin_comment
comment|/* parameter not a Cursor */
end_comment

begin_define
define|#
directive|define
name|BadFont
value|7
end_define

begin_comment
comment|/* parameter not a Font */
end_comment

begin_define
define|#
directive|define
name|BadMatch
value|8
end_define

begin_comment
comment|/* parameter mismatch */
end_comment

begin_define
define|#
directive|define
name|BadTile
value|9
end_define

begin_comment
comment|/* Pixmap shape invalid for tiling */
end_comment

begin_define
define|#
directive|define
name|BadGrab
value|10
end_define

begin_comment
comment|/* mouse/button already grabbed */
end_comment

begin_define
define|#
directive|define
name|BadAccess
value|11
end_define

begin_comment
comment|/* access control violation */
end_comment

begin_define
define|#
directive|define
name|BadAlloc
value|12
end_define

begin_comment
comment|/* insufficient resources */
end_comment

begin_define
define|#
directive|define
name|BadColor
value|13
end_define

begin_comment
comment|/* no such color */
end_comment

begin_comment
comment|/* for monochrome applications */
end_comment

begin_define
define|#
directive|define
name|BlackPixel
value|0
end_define

begin_comment
comment|/* may not actually be black */
end_comment

begin_define
define|#
directive|define
name|WhitePixel
value|1
end_define

begin_comment
comment|/* may not actually be white */
end_comment

begin_comment
comment|/* graphics functions */
end_comment

begin_define
define|#
directive|define
name|GXclear
value|0x0
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|GXand
value|0x1
end_define

begin_comment
comment|/* src AND dst */
end_comment

begin_define
define|#
directive|define
name|GXandReverse
value|0x2
end_define

begin_comment
comment|/* src AND NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXcopy
value|0x3
end_define

begin_comment
comment|/* src */
end_comment

begin_define
define|#
directive|define
name|GXandInverted
value|0x4
end_define

begin_comment
comment|/* NOT src AND dst */
end_comment

begin_define
define|#
directive|define
name|GXnoop
value|0x5
end_define

begin_comment
comment|/* dst */
end_comment

begin_define
define|#
directive|define
name|GXxor
value|0x6
end_define

begin_comment
comment|/* src XOR dst */
end_comment

begin_define
define|#
directive|define
name|GXor
value|0x7
end_define

begin_comment
comment|/* src OR dst */
end_comment

begin_define
define|#
directive|define
name|GXnor
value|0x8
end_define

begin_comment
comment|/* NOT src AND NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXequiv
value|0x9
end_define

begin_comment
comment|/* NOT src XOR dst */
end_comment

begin_define
define|#
directive|define
name|GXinvert
value|0xa
end_define

begin_comment
comment|/* NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXorReverse
value|0xb
end_define

begin_comment
comment|/* src OR NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXcopyInverted
value|0xc
end_define

begin_comment
comment|/* NOT src */
end_comment

begin_define
define|#
directive|define
name|GXorInverted
value|0xd
end_define

begin_comment
comment|/* NOT src OR dst */
end_comment

begin_define
define|#
directive|define
name|GXnand
value|0xe
end_define

begin_comment
comment|/* NOT src OR NOT dst */
end_comment

begin_define
define|#
directive|define
name|GXset
value|0xf
end_define

begin_comment
comment|/* 1 */
end_comment

begin_comment
comment|/* Used in X_TileMode */
end_comment

begin_define
define|#
directive|define
name|TileModeAbsolute
value|0
end_define

begin_define
define|#
directive|define
name|TileModeRelative
value|1
end_define

begin_comment
comment|/* Used in X_ClipMode */
end_comment

begin_define
define|#
directive|define
name|ClipModeClipped
value|0
end_define

begin_define
define|#
directive|define
name|ClipModeDrawThru
value|1
end_define

begin_comment
comment|/* Used in X_QueryWindow reply */
end_comment

begin_define
define|#
directive|define
name|IsUnmapped
value|0
end_define

begin_define
define|#
directive|define
name|IsMapped
value|1
end_define

begin_define
define|#
directive|define
name|IsInvisible
value|2
end_define

begin_define
define|#
directive|define
name|IsTransparent
value|0
end_define

begin_define
define|#
directive|define
name|IsOpaque
value|1
end_define

begin_define
define|#
directive|define
name|IsIcon
value|2
end_define

begin_comment
comment|/* Used in X_Draw */
end_comment

begin_define
define|#
directive|define
name|DrawSolidLine
value|0
end_define

begin_define
define|#
directive|define
name|DrawDashedLine
value|1
end_define

begin_define
define|#
directive|define
name|DrawPatternedLine
value|2
end_define

begin_comment
comment|/* Used in X_Draw and X_DrawFilled */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_Vertex
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|short
name|flags
decl_stmt|;
block|}
name|Vertex
typedef|;
end_typedef

begin_comment
comment|/* The meanings of the flag bits.  If the bit is 1 the predicate is true */
end_comment

begin_define
define|#
directive|define
name|VertexRelative
value|0x0001
end_define

begin_comment
comment|/* else absolute */
end_comment

begin_define
define|#
directive|define
name|VertexDontDraw
value|0x0002
end_define

begin_comment
comment|/* else draw */
end_comment

begin_define
define|#
directive|define
name|VertexCurved
value|0x0004
end_define

begin_comment
comment|/* else straight */
end_comment

begin_define
define|#
directive|define
name|VertexStartClosed
value|0x0008
end_define

begin_comment
comment|/* else not */
end_comment

begin_define
define|#
directive|define
name|VertexEndClosed
value|0x0010
end_define

begin_comment
comment|/* else not */
end_comment

begin_define
define|#
directive|define
name|VertexDrawLastPoint
value|0x0020
end_define

begin_comment
comment|/* else don't */
end_comment

begin_comment
comment|/* Device identifiers returned by X_SetUp */
end_comment

begin_define
define|#
directive|define
name|XDEV_XNEST
value|0
end_define

begin_comment
comment|/* X in an X window */
end_comment

begin_comment
comment|/* DEC address space 1-99 */
end_comment

begin_define
define|#
directive|define
name|XDEV_VS100
value|1
end_define

begin_comment
comment|/* DEC VS100			*/
end_comment

begin_define
define|#
directive|define
name|XDEV_QVSS
value|2
end_define

begin_comment
comment|/* DEC QVSS (VS1 and VS2)	*/
end_comment

begin_define
define|#
directive|define
name|XDEV_QDSS
value|3
end_define

begin_comment
comment|/* DEC QDSS display		*/
end_comment

begin_define
define|#
directive|define
name|XDEV_DECXXX
value|4
end_define

begin_comment
comment|/* reserved for future use	*/
end_comment

begin_define
define|#
directive|define
name|XDEV_DECYYY
value|5
end_define

begin_comment
comment|/* reserved for future use	*/
end_comment

begin_define
define|#
directive|define
name|XDEV_DECZZZ
value|6
end_define

begin_comment
comment|/* reserved for future use	*/
end_comment

begin_comment
comment|/* Cognition address space 100-199 */
end_comment

begin_define
define|#
directive|define
name|XDEV_LEX90
value|100
end_define

begin_comment
comment|/* Lexidata 90, Cognition       */
end_comment

begin_comment
comment|/* IBM address space 200-299 */
end_comment

begin_define
define|#
directive|define
name|XDEV_IBMACIS
value|200
end_define

begin_comment
comment|/* IBM ACIS  display, wuf, RT/PC*/
end_comment

begin_define
define|#
directive|define
name|XDEV_IBMAPA8
value|201
end_define

begin_comment
comment|/* IBM APA8  display, RT/PC     */
end_comment

begin_define
define|#
directive|define
name|XDEV_IBMAPA16
value|202
end_define

begin_comment
comment|/* IBM APA16 display, RT/PC	*/
end_comment

begin_comment
comment|/* SMI address space 300-399 */
end_comment

begin_define
define|#
directive|define
name|SUN_BASE
value|300
end_define

begin_comment
comment|/* base of SMI displays		*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FBTYPE_SUN1BW
end_ifndef

begin_comment
comment|/* from /usr/include/sun/fbio.h */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN1BW
value|0
end_define

begin_define
define|#
directive|define
name|FBTYPE_SUN1COLOR
value|1
end_define

begin_define
define|#
directive|define
name|FBTYPE_SUN2BW
value|2
end_define

begin_define
define|#
directive|define
name|FBTYPE_SUN2COLOR
value|3
end_define

begin_define
define|#
directive|define
name|FBTYPE_SUN2GP
value|4
end_define

begin_comment
comment|/* reserved for future Sun use	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN3BW
value|5
end_define

begin_comment
comment|/* reserved for future Sun use	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN3COLOR
value|6
end_define

begin_comment
comment|/* reserved for future Sun use	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN4BW
value|7
end_define

begin_comment
comment|/* reserved for future Sun use	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN4COLOR
value|8
end_define

begin_comment
comment|/* reserved for future Sun use	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN1
value|9
end_define

begin_comment
comment|/* reserved for Sun customer	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN2
value|10
end_define

begin_comment
comment|/* reserved for Sun customer	*/
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN3
value|11
end_define

begin_comment
comment|/* reserved for Sun customer	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XDEV_SUN1BW
value|FBTYPE_SUN1BW+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN1COLOR
value|FBTYPE_SUN1COLOR+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN2BW
value|FBTYPE_SUN2BW+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN2COLOR
value|FBTYPE_SUN2COLOR+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN2GP
value|FBTYPE_SUN2GP+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN3BW
value|FBTYPE_SUN3BW+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN3COLOR
value|FBTYPE_SUN3COLOR+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN4BW
value|FBTYPE_SUN4BW+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_SUN4COLOR
value|FBTYPE_SUN4COLOR+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_NOTSUN1
value|FBTYPE_NOTSUN1+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_NOTSUN2
value|FBTYPE_NOTSUN2+SUN_BASE
end_define

begin_define
define|#
directive|define
name|XDEV_NOTSUN3
value|FBTYPE_NOTSUN3+SUN_BASE
end_define

begin_comment
comment|/* MASSCOMP address space 400-499 */
end_comment

begin_define
define|#
directive|define
name|XDEV_MC1
value|401
end_define

begin_comment
comment|/* Masscomp, in progress	*/
end_comment

begin_define
define|#
directive|define
name|XDEV_MC2
value|402
end_define

begin_comment
comment|/* Masscomp, (not implemented)  */
end_comment

begin_define
define|#
directive|define
name|XDEV_MC3
value|403
end_define

begin_comment
comment|/* Masscomp, (not implemented)  */
end_comment

begin_comment
comment|/* Jupiter Systems address space 500-599 */
end_comment

begin_define
define|#
directive|define
name|XDEV_PGP20
value|501
end_define

begin_comment
comment|/* 24 bit deep frame buffer	*/
end_comment

begin_comment
comment|/* Used in X_StoreColors */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ColorDef
block|{
name|unsigned
name|short
name|pixel
decl_stmt|;
name|unsigned
name|short
name|red
decl_stmt|,
name|green
decl_stmt|,
name|blue
decl_stmt|;
block|}
name|ColorDef
typedef|;
end_typedef

begin_comment
comment|/* Used in X_PixmapBitsPut and X_StorePixmap */
end_comment

begin_define
define|#
directive|define
name|XYFormat
value|0
end_define

begin_define
define|#
directive|define
name|ZFormat
value|1
end_define

begin_comment
comment|/* size in bytes of a bitmap */
end_comment

begin_define
define|#
directive|define
name|BitmapSize
parameter_list|(
name|width
parameter_list|,
name|height
parameter_list|)
value|(((((width) + 15)>> 3)&~ 1) * (height))
end_define

begin_comment
comment|/* size in bytes of a pixmap in XYFormat */
end_comment

begin_define
define|#
directive|define
name|XYPixmapSize
parameter_list|(
name|width
parameter_list|,
name|height
parameter_list|,
name|planes
parameter_list|)
value|(BitmapSize(width, height) * (planes))
end_define

begin_comment
comment|/* size in bytes of a pizmap in ZFormat for 9 to 16 bit planes */
end_comment

begin_define
define|#
directive|define
name|WZPixmapSize
parameter_list|(
name|width
parameter_list|,
name|height
parameter_list|)
value|(((width) * (height))<< 1)
end_define

begin_comment
comment|/* size in bytes of a pixmap in ZFormat for 2 to 8 bit planes */
end_comment

begin_define
define|#
directive|define
name|BZPixmapSize
parameter_list|(
name|width
parameter_list|,
name|height
parameter_list|)
value|((width) * (height))
end_define

begin_comment
comment|/* Used in X_QueryShape */
end_comment

begin_define
define|#
directive|define
name|CursorShape
value|0
end_define

begin_define
define|#
directive|define
name|TileShape
value|1
end_define

begin_define
define|#
directive|define
name|BrushShape
value|2
end_define

begin_comment
comment|/* Used in X_ShiftLock */
end_comment

begin_define
define|#
directive|define
name|LockUpDownMode
value|0
end_define

begin_define
define|#
directive|define
name|LockToggleMode
value|1
end_define

begin_comment
comment|/* Used in X_AddHost, X_RemoveHost, and X_GetHosts */
end_comment

begin_define
define|#
directive|define
name|XAF_INET
value|2
end_define

begin_define
define|#
directive|define
name|XAF_DECnet
value|12
end_define

end_unit

