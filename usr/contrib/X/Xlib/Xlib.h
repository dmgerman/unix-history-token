begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: Xlib.h,v 10.14 86/02/01 15:41:59 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  *	Xlib.h - Header definition and support file for the C subroutine  *	interface library (Xlib) to the X Window System Protocol.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<X/X.h>
end_include

begin_define
define|#
directive|define
name|Status
value|int
end_define

begin_define
define|#
directive|define
name|XId
value|long
end_define

begin_define
define|#
directive|define
name|XClearVertexFlag
parameter_list|()
value|(_XlibCurrentDisplay->lastdraw = NULL)
end_define

begin_define
define|#
directive|define
name|XMakePattern
parameter_list|(
name|pattern
parameter_list|,
name|patlen
parameter_list|,
name|patmul
parameter_list|)
define|\
value|((Pattern)(((patmul)<< 20) | (((patlen) - 1)<< 16) | (pattern) ))
end_define

begin_define
define|#
directive|define
name|dpyno
parameter_list|()
value|(_XlibCurrentDisplay->fd)
end_define

begin_define
define|#
directive|define
name|RootWindow
value|(_XlibCurrentDisplay->root)
end_define

begin_define
define|#
directive|define
name|BlackPixmap
value|(_XlibCurrentDisplay->black)
end_define

begin_define
define|#
directive|define
name|WhitePixmap
value|(_XlibCurrentDisplay->white)
end_define

begin_define
define|#
directive|define
name|AllPlanes
value|(~0)
end_define

begin_define
define|#
directive|define
name|QLength
parameter_list|()
value|(_XlibCurrentDisplay->qlen)
end_define

begin_define
define|#
directive|define
name|DisplayType
parameter_list|()
value|(_XlibCurrentDisplay->dtype)
end_define

begin_define
define|#
directive|define
name|DisplayPlanes
parameter_list|()
value|(_XlibCurrentDisplay->dplanes)
end_define

begin_define
define|#
directive|define
name|DisplayCells
parameter_list|()
value|(_XlibCurrentDisplay->dcells)
end_define

begin_define
define|#
directive|define
name|ProtocolVersion
parameter_list|()
value|(_XlibCurrentDisplay->vnumber)
end_define

begin_define
define|#
directive|define
name|DisplayName
parameter_list|()
value|(_XlibCurrentDisplay->displayname)
end_define

begin_comment
comment|/* Bitmask returned by XParseGeometry().  Each bit tells if the corresponding    value (x, y, width, height) was found in the parsed string. */
end_comment

begin_define
define|#
directive|define
name|NoValue
value|0x0000
end_define

begin_define
define|#
directive|define
name|XValue
value|0x0001
end_define

begin_define
define|#
directive|define
name|YValue
value|0x0002
end_define

begin_define
define|#
directive|define
name|WidthValue
value|0x0004
end_define

begin_define
define|#
directive|define
name|HeightValue
value|0x0008
end_define

begin_define
define|#
directive|define
name|AllValues
value|0x000F
end_define

begin_define
define|#
directive|define
name|XNegative
value|0x0010
end_define

begin_define
define|#
directive|define
name|YNegative
value|0x0020
end_define

begin_comment
comment|/* Definition of a generic event.  It must be cast to a specific event  * type before one can read event-specific data */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* of event (KeyPressed, ExposeWindow, etc.) */
name|Window
name|window
decl_stmt|;
comment|/* which selected this event */
name|long
name|pad_l1
decl_stmt|,
name|pad_l2
decl_stmt|;
comment|/* event-specific data */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) event actually happened in */
name|long
name|pad_l4
decl_stmt|;
comment|/* event-specific data */
block|}
name|XEvent
typedef|;
end_typedef

begin_comment
comment|/*  * _QEvent datatype for use in input queueing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qevent
block|{
name|struct
name|_qevent
modifier|*
name|next
decl_stmt|;
name|XEvent
name|event
decl_stmt|;
block|}
name|_QEvent
typedef|;
end_typedef

begin_comment
comment|/*  * Display datatype maintaining display specific data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_display
block|{
name|int
name|fd
decl_stmt|;
comment|/* Network socket. */
name|Window
name|root
decl_stmt|;
comment|/* Root window id. */
name|int
name|vnumber
decl_stmt|;
comment|/* X protocol version number. */
name|int
name|dtype
decl_stmt|;
comment|/* X server display device type. */
name|int
name|dplanes
decl_stmt|;
comment|/* Number of display bit planes. */
name|int
name|dcells
decl_stmt|;
comment|/* Number of display color map cells. */
name|_QEvent
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
comment|/* Input event queue. */
name|int
name|qlen
decl_stmt|;
comment|/* Length of input event queue */
name|int
name|request
decl_stmt|;
comment|/* Id of last request. */
name|char
modifier|*
name|lastdraw
decl_stmt|;
comment|/* Last draw request. */
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Output buffer starting address. */
name|char
modifier|*
name|bufptr
decl_stmt|;
comment|/* Output buffer index pointer. */
name|char
modifier|*
name|bufmax
decl_stmt|;
comment|/* Output buffer maximum+1 address. */
name|int
name|squish
decl_stmt|;
comment|/* Squish MouseMoved events? */
name|Pixmap
name|black
decl_stmt|,
name|white
decl_stmt|;
comment|/* Constant tile pixmaps */
name|char
modifier|*
name|displayname
decl_stmt|;
comment|/* "host:display" string used on this connect*/
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width and height of display */
block|}
name|Display
typedef|;
end_typedef

begin_comment
comment|/*  * XAssoc - Associations used in the XAssocTable data structure.  The   * associations are used as circular queue entries in the association table  * which is contains an array of circular queues (buckets).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_x_assoc
block|{
name|struct
name|_x_assoc
modifier|*
name|next
decl_stmt|;
comment|/* Next object in this bucket. */
name|struct
name|_x_assoc
modifier|*
name|prev
decl_stmt|;
comment|/* Previous obejct in this bucket. */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display which ownes the id. */
name|XId
name|x_id
decl_stmt|;
comment|/* X Window System id. */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Pointer to untyped memory. */
block|}
name|XAssoc
typedef|;
end_typedef

begin_comment
comment|/*   * XAssocTable - X Window System id to data structure pointer association  * table. An XAssocTable consists of a pointer to an array of XAssoc's  * (table) which are circular queue (bucket) headers and an integer (size)  * representing the number of circular queues (buckets) in the array.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_x_assoc_table
block|{
name|struct
name|_x_assoc
argument_list|(
operator|*
name|table
argument_list|)
decl|[]
decl_stmt|;
comment|/* Array of association queues. */
name|int
name|size
decl_stmt|;
comment|/* Table size. */
block|}
name|XAssocTable
typedef|;
end_typedef

begin_comment
comment|/*   * Data returned by XQueryWindow.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_WindowInfo
block|{
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* Width and height. */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* X and y coordinates. */
name|short
name|bdrwidth
decl_stmt|;
comment|/* Border width. */
name|short
name|mapped
decl_stmt|;
comment|/* IsUnmapped, IsMapped or IsInvisible.*/
name|short
name|type
decl_stmt|;
comment|/* IsTransparent, IsOpaque or IsIcon. */
name|Window
name|assoc_wind
decl_stmt|;
comment|/* Associated icon or opaque Window. */
block|}
name|WindowInfo
typedef|;
end_typedef

begin_comment
comment|/*   * Data returned by XQueryFont.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_FontInfo
block|{
name|Font
name|id
decl_stmt|;
name|short
name|height
decl_stmt|,
name|width
decl_stmt|,
name|baseline
decl_stmt|,
name|fixedwidth
decl_stmt|;
name|unsigned
name|char
name|firstchar
decl_stmt|,
name|lastchar
decl_stmt|;
name|short
modifier|*
name|widths
decl_stmt|;
comment|/* pointer to width array in OpenFont */
block|}
name|FontInfo
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure used by color operations; ints rather than shorts  * to keep 16 bit protocol limitation out of the library.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_Color
block|{
name|int
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
name|Color
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure use by XCreateTiles.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TileFrame
block|{
name|int
name|pixel
decl_stmt|;
comment|/* Pixel color for constructing the tile. */
name|Pixmap
name|pixmap
decl_stmt|;
comment|/* Pixmap id of the pixmap, filled in later. */
block|}
name|TileFrame
typedef|;
end_typedef

begin_comment
comment|/*  * Data structures used by XCreateWindows XCreateTransparencies and  * XCreateWindowBatch.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_OpaqueFrame
block|{
name|Window
name|self
decl_stmt|;
comment|/* window id of the window, filled in later */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* where to create the window */
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width and height */
name|short
name|bdrwidth
decl_stmt|;
comment|/* border width */
name|Pixmap
name|border
decl_stmt|;
comment|/* border pixmap */
name|Pixmap
name|background
decl_stmt|;
comment|/* background */
block|}
name|OpaqueFrame
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TransparentFrame
block|{
name|Window
name|self
decl_stmt|;
comment|/* window id of the window, filled in later */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* where to create the window */
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width and height */
block|}
name|TransparentFrame
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_BatchFrame
block|{
name|short
name|type
decl_stmt|;
comment|/* One of (IsOpaque, IsTransparent). */
name|Window
name|parent
decl_stmt|;
comment|/* Window if of the window's parent. */
name|Window
name|self
decl_stmt|;
comment|/* Window id of the window, filled in later. */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Where to create the window. */
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* Window width and height. */
name|short
name|bdrwidth
decl_stmt|;
comment|/* Window border width. */
name|Pixmap
name|border
decl_stmt|;
comment|/* Window border pixmap */
name|Pixmap
name|background
decl_stmt|;
comment|/* Window background pixmap. */
block|}
name|BatchFrame
typedef|;
end_typedef

begin_comment
comment|/*  * Definitions of specific events  * In all of the following, fields whose names begin with "pad" contain  * no meaningful value.  */
end_comment

begin_struct
struct|struct
name|_XKeyOrButtonEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* of event (KeyPressed, ButtonReleased, etc.) */
name|Window
name|window
decl_stmt|;
comment|/* which selected this event */
name|unsigned
name|short
name|time
decl_stmt|;
comment|/* in 10 millisecond ticks */
name|short
name|detail
decl_stmt|;
comment|/* event-dependent data (key state, etc.) */
name|short
name|x
decl_stmt|;
comment|/* mouse x coordinate within event window */
name|short
name|y
decl_stmt|;
comment|/* mouse y coordinate within event window */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) mouse was in */
name|Locator
name|location
decl_stmt|;
comment|/* absolute coordinates of mouse */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XKeyOrButtonEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XKeyEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XKeyPressedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XKeyReleasedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XButtonEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XButtonPressedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XKeyOrButtonEvent
name|XButtonReleasedEvent
typedef|;
end_typedef

begin_struct
struct|struct
name|_XMouseOrCrossingEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* EnterWindow, LeaveWindow, or MouseMoved */
name|Window
name|window
decl_stmt|;
comment|/* which selected this event */
name|short
name|pad_s2
decl_stmt|;
name|short
name|detail
decl_stmt|;
comment|/* event-dependent data (key state, etc. ) */
name|short
name|x
decl_stmt|;
comment|/* mouse x coordinate within event window */
name|short
name|y
decl_stmt|;
comment|/* mouse y coordinate within event window */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) mouse was in */
name|Locator
name|location
decl_stmt|;
comment|/* absolute coordinates of mouse */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XMouseOrCrossingEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XMouseEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XMouseMovedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XCrossingEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XEnterWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XMouseOrCrossingEvent
name|XLeaveWindowEvent
typedef|;
end_typedef

begin_struct
struct|struct
name|_XExposeEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* ExposeWindow or ExposeRegion */
name|Window
name|window
decl_stmt|;
comment|/* that selected this event */
name|short
name|pad_s2
decl_stmt|;
name|short
name|detail
decl_stmt|;
comment|/* 0 or ExposeCopy */
name|short
name|width
decl_stmt|;
comment|/* width of exposed area */
name|short
name|height
decl_stmt|;
comment|/* height of exposed area */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) actually exposed */
name|short
name|y
decl_stmt|;
comment|/* top of exposed area (0 for ExposeWindow) */
name|short
name|x
decl_stmt|;
comment|/* left edge of exposed area (0 for ExposeWindow) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|_XExposeEvent
name|XExposeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XExposeEvent
name|XExposeWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XExposeEvent
name|XExposeRegionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XExposeCopyEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* ExposeCopy */
name|Window
name|window
decl_stmt|;
comment|/* that selected this event */
name|long
name|pad_l1
decl_stmt|;
name|long
name|pad_l2
decl_stmt|;
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) actually exposed */
name|long
name|pad_l4
decl_stmt|;
block|}
name|XExposeCopyEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XUnmapEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* UnmapWindow */
name|Window
name|window
decl_stmt|;
comment|/* that selected this event */
name|long
name|pad_l1
decl_stmt|;
name|long
name|pad_l2
decl_stmt|;
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) actually unmapped */
name|long
name|pad_l4
decl_stmt|;
block|}
name|XUnmapEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XFocusChangeEvent
block|{
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* FocusChange */
name|Window
name|window
decl_stmt|;
comment|/* that selected this event */
name|short
name|pad_s2
decl_stmt|;
name|short
name|detail
decl_stmt|;
comment|/* EnterWindow or LeaveWindow */
name|long
name|pad_l2
decl_stmt|;
name|Window
name|subwindow
decl_stmt|;
comment|/* child window (if any) of actual focus change*/
name|long
name|pad_l4
decl_stmt|;
block|}
name|XFocusChangeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XErrorEvent
block|{
name|long
name|pad
decl_stmt|;
name|long
name|serial
decl_stmt|;
comment|/* serial number of failed request */
name|char
name|error_code
decl_stmt|;
comment|/* error code of failed request */
name|char
name|request_code
decl_stmt|;
comment|/* request code of failed request */
name|char
name|func
decl_stmt|;
comment|/* function field of failed request */
name|char
name|pad_b7
decl_stmt|;
name|Window
name|window
decl_stmt|;
comment|/* Window of failed request */
name|long
name|pad_l3
decl_stmt|;
name|long
name|pad_l4
decl_stmt|;
block|}
name|XErrorEvent
typedef|;
end_typedef

begin_comment
comment|/*  * Line pattern related definitions for the library.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|Pattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DashedLine
value|XMakePattern(0xf0f0, 16, 1)
end_define

begin_define
define|#
directive|define
name|DottedLine
value|XMakePattern(0xaaaa, 16, 1)
end_define

begin_define
define|#
directive|define
name|DotDashLine
value|XMakePattern(0xf4f4, 16, 1)
end_define

begin_define
define|#
directive|define
name|SolidLine
value|XMakePattern(1,1,1)
end_define

begin_typedef
typedef|typedef
name|short
name|KeyMapEntry
index|[
literal|8
index|]
typedef|;
end_typedef

begin_comment
comment|/* define values for keyboard map table */
end_comment

begin_comment
comment|/* these values will vanish in the next version; DO NOT USE THEM! */
end_comment

begin_define
define|#
directive|define
name|SHFT
value|(short) -2
end_define

begin_define
define|#
directive|define
name|CNTL
value|(short) -3
end_define

begin_define
define|#
directive|define
name|LOCK
value|(short) -4
end_define

begin_define
define|#
directive|define
name|SYMBOL
value|(short) -5
end_define

begin_define
define|#
directive|define
name|KEYPAD
value|(short) -6
end_define

begin_define
define|#
directive|define
name|CURSOR
value|(short) -7
end_define

begin_define
define|#
directive|define
name|PFX
value|(short) -8
end_define

begin_define
define|#
directive|define
name|FUNC1
value|(short) -9
end_define

begin_define
define|#
directive|define
name|FUNC2
value|(short) -10
end_define

begin_define
define|#
directive|define
name|FUNC3
value|(short) -11
end_define

begin_define
define|#
directive|define
name|FUNC4
value|(short) -12
end_define

begin_define
define|#
directive|define
name|FUNC5
value|(short) -13
end_define

begin_define
define|#
directive|define
name|FUNC6
value|(short) -14
end_define

begin_define
define|#
directive|define
name|FUNC7
value|(short) -15
end_define

begin_define
define|#
directive|define
name|FUNC8
value|(short) -16
end_define

begin_define
define|#
directive|define
name|FUNC9
value|(short) -17
end_define

begin_define
define|#
directive|define
name|FUNC10
value|(short) -18
end_define

begin_define
define|#
directive|define
name|FUNC11
value|(short) -19
end_define

begin_define
define|#
directive|define
name|FUNC12
value|(short) -20
end_define

begin_define
define|#
directive|define
name|FUNC13
value|(short) -21
end_define

begin_define
define|#
directive|define
name|FUNC14
value|(short) -22
end_define

begin_define
define|#
directive|define
name|FUNC15
value|(short) -23
end_define

begin_define
define|#
directive|define
name|FUNC16
value|(short) -24
end_define

begin_define
define|#
directive|define
name|FUNC17
value|(short) -25
end_define

begin_define
define|#
directive|define
name|FUNC18
value|(short) -26
end_define

begin_define
define|#
directive|define
name|FUNC19
value|(short) -27
end_define

begin_define
define|#
directive|define
name|FUNC20
value|(short) -28
end_define

begin_define
define|#
directive|define
name|E1
value|(short) -29
end_define

begin_define
define|#
directive|define
name|E2
value|(short) -30
end_define

begin_define
define|#
directive|define
name|E3
value|(short) -31
end_define

begin_define
define|#
directive|define
name|E4
value|(short) -32
end_define

begin_define
define|#
directive|define
name|E5
value|(short) -33
end_define

begin_define
define|#
directive|define
name|E6
value|(short) -34
end_define

begin_comment
comment|/*   * X function declarations.  */
end_comment

begin_function_decl
name|Display
modifier|*
name|XOpenDisplay
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XFetchBytes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XFetchBuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XErrDescrip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XLookupMapping
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|short
modifier|*
name|XFontWidths
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|FontInfo
modifier|*
name|XOpenFont
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|Display
modifier|*
name|_XlibCurrentDisplay
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|XGetDefault
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|Bitmap
name|XCharBitmap
argument_list|()
decl_stmt|,
name|XStoreBitmap
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Pixmap
name|XMakePixmap
argument_list|()
decl_stmt|,
name|XMakeTile
argument_list|()
decl_stmt|,
name|XStorePixmapXY
argument_list|()
decl_stmt|,
name|XStorePixmapZ
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Pixmap
name|XPixmapSave
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|Cursor
name|XCreateCursor
argument_list|()
decl_stmt|,
name|XStoreCursor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Window
name|XCreate
argument_list|()
decl_stmt|,
name|XCreateTerm
argument_list|()
decl_stmt|,
name|XCreateTransparency
argument_list|()
decl_stmt|,
name|XCreateWindow
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Window
name|XGetIconWindow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Font
name|XGetFont
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|Status
name|XFetchName
argument_list|()
decl_stmt|,
name|XGetColorCells
argument_list|()
decl_stmt|,
name|XGetColor
argument_list|()
decl_stmt|,
name|XGetHardwareColor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Status
name|XGetResizeHint
argument_list|()
decl_stmt|,
name|XGrabButton
argument_list|()
decl_stmt|,
name|XGrabMouse
argument_list|()
decl_stmt|,
name|XInterpretLocator
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Status
name|XParseColor
argument_list|()
decl_stmt|,
name|XPixmapGetXY
argument_list|()
decl_stmt|,
name|XPismapGetZ
argument_list|()
decl_stmt|,
name|XQueryMouseButtons
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Status
name|XQueryFont
argument_list|()
decl_stmt|,
name|XQueryMouse
argument_list|()
decl_stmt|,
name|XQueryTree
argument_list|()
decl_stmt|,
name|XQueryWindow
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Status
name|XReadBitmapFile
argument_list|()
decl_stmt|,
name|XUpdateMouse
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

