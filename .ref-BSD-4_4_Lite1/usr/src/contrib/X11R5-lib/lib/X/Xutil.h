begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xutil.h,v 11.73 91/07/30 16:21:37 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XUTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_XUTIL_H_
end_define

begin_comment
comment|/* You must include<X11/Xlib.h> before including this file */
end_comment

begin_comment
comment|/*   * Bitmask returned by XParseGeometry().  Each bit tells if the corresponding  * value (x, y, width, height) was found in the parsed string.  */
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
comment|/*  * new version containing base_width, base_height, and win_gravity fields;  * used with WM_NORMAL_HINTS.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|flags
decl_stmt|;
comment|/* marks which fields in this structure are defined */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* obsolete for new window mgrs, but clients */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* should set so old wm's don't mess up */
name|int
name|min_width
decl_stmt|,
name|min_height
decl_stmt|;
name|int
name|max_width
decl_stmt|,
name|max_height
decl_stmt|;
name|int
name|width_inc
decl_stmt|,
name|height_inc
decl_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
comment|/* numerator */
name|int
name|y
decl_stmt|;
comment|/* denominator */
block|}
name|min_aspect
struct|,
name|max_aspect
struct|;
name|int
name|base_width
decl_stmt|,
name|base_height
decl_stmt|;
comment|/* added by ICCCM version 1 */
name|int
name|win_gravity
decl_stmt|;
comment|/* added by ICCCM version 1 */
block|}
name|XSizeHints
typedef|;
end_typedef

begin_comment
comment|/*  * The next block of definitions are for window manager properties that  * clients and applications use for communication.  */
end_comment

begin_comment
comment|/* flags argument in size hints */
end_comment

begin_define
define|#
directive|define
name|USPosition
value|(1L<< 0)
end_define

begin_comment
comment|/* user specified x, y */
end_comment

begin_define
define|#
directive|define
name|USSize
value|(1L<< 1)
end_define

begin_comment
comment|/* user specified width, height */
end_comment

begin_define
define|#
directive|define
name|PPosition
value|(1L<< 2)
end_define

begin_comment
comment|/* program specified position */
end_comment

begin_define
define|#
directive|define
name|PSize
value|(1L<< 3)
end_define

begin_comment
comment|/* program specified size */
end_comment

begin_define
define|#
directive|define
name|PMinSize
value|(1L<< 4)
end_define

begin_comment
comment|/* program specified minimum size */
end_comment

begin_define
define|#
directive|define
name|PMaxSize
value|(1L<< 5)
end_define

begin_comment
comment|/* program specified maximum size */
end_comment

begin_define
define|#
directive|define
name|PResizeInc
value|(1L<< 6)
end_define

begin_comment
comment|/* program specified resize increments */
end_comment

begin_define
define|#
directive|define
name|PAspect
value|(1L<< 7)
end_define

begin_comment
comment|/* program specified min and max aspect ratios */
end_comment

begin_define
define|#
directive|define
name|PBaseSize
value|(1L<< 8)
end_define

begin_comment
comment|/* program specified base for incrementing */
end_comment

begin_define
define|#
directive|define
name|PWinGravity
value|(1L<< 9)
end_define

begin_comment
comment|/* program specified window gravity */
end_comment

begin_comment
comment|/* obsolete */
end_comment

begin_define
define|#
directive|define
name|PAllHints
value|(PPosition|PSize|PMinSize|PMaxSize|PResizeInc|PAspect)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|flags
decl_stmt|;
comment|/* marks which fields in this structure are defined */
name|Bool
name|input
decl_stmt|;
comment|/* does this application rely on the window manager to 			get keyboard input? */
name|int
name|initial_state
decl_stmt|;
comment|/* see below */
name|Pixmap
name|icon_pixmap
decl_stmt|;
comment|/* pixmap to be used as icon */
name|Window
name|icon_window
decl_stmt|;
comment|/* window to be used as icon */
name|int
name|icon_x
decl_stmt|,
name|icon_y
decl_stmt|;
comment|/* initial position of icon */
name|Pixmap
name|icon_mask
decl_stmt|;
comment|/* icon mask bitmap */
name|XID
name|window_group
decl_stmt|;
comment|/* id of related window group */
comment|/* this structure may be extended in the future */
block|}
name|XWMHints
typedef|;
end_typedef

begin_comment
comment|/* definition for flags of XWMHints */
end_comment

begin_define
define|#
directive|define
name|InputHint
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|StateHint
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|IconPixmapHint
value|(1L<< 2)
end_define

begin_define
define|#
directive|define
name|IconWindowHint
value|(1L<< 3)
end_define

begin_define
define|#
directive|define
name|IconPositionHint
value|(1L<< 4)
end_define

begin_define
define|#
directive|define
name|IconMaskHint
value|(1L<< 5)
end_define

begin_define
define|#
directive|define
name|WindowGroupHint
value|(1L<< 6)
end_define

begin_define
define|#
directive|define
name|AllHints
value|(InputHint|StateHint|IconPixmapHint|IconWindowHint| \ IconPositionHint|IconMaskHint|WindowGroupHint)
end_define

begin_comment
comment|/* definitions for initial window state */
end_comment

begin_define
define|#
directive|define
name|WithdrawnState
value|0
end_define

begin_comment
comment|/* for windows that are not mapped */
end_comment

begin_define
define|#
directive|define
name|NormalState
value|1
end_define

begin_comment
comment|/* most applications want to start this way */
end_comment

begin_define
define|#
directive|define
name|IconicState
value|3
end_define

begin_comment
comment|/* application wants to start as an icon */
end_comment

begin_comment
comment|/*  * Obsolete states no longer defined by ICCCM  */
end_comment

begin_define
define|#
directive|define
name|DontCareState
value|0
end_define

begin_comment
comment|/* don't know or care */
end_comment

begin_define
define|#
directive|define
name|ZoomState
value|2
end_define

begin_comment
comment|/* application wants to start zoomed */
end_comment

begin_define
define|#
directive|define
name|InactiveState
value|4
end_define

begin_comment
comment|/* application believes it is seldom used; */
end_comment

begin_comment
comment|/* some wm's may put it on inactive menu */
end_comment

begin_comment
comment|/*  * new structure for manipulating TEXT properties; used with WM_NAME,   * WM_ICON_NAME, WM_CLIENT_MACHINE, and WM_COMMAND.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
modifier|*
name|value
decl_stmt|;
comment|/* same as Property routines */
name|Atom
name|encoding
decl_stmt|;
comment|/* prop type */
name|int
name|format
decl_stmt|;
comment|/* prop data format: 8, 16, or 32 */
name|unsigned
name|long
name|nitems
decl_stmt|;
comment|/* number of data items in value */
block|}
name|XTextProperty
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XNoMemory
value|-1
end_define

begin_define
define|#
directive|define
name|XLocaleNotSupported
value|-2
end_define

begin_define
define|#
directive|define
name|XConverterNotFound
value|-3
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XStringStyle
block|,
comment|/* STRING */
name|XCompoundTextStyle
block|,
comment|/* COMPOUND_TEXT */
name|XTextStyle
block|,
comment|/* text in owner's encoding (current locale)*/
name|XStdICCTextStyle
comment|/* STRING, else COMPOUND_TEXT */
block|}
name|XICCEncodingStyle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|min_width
decl_stmt|,
name|min_height
decl_stmt|;
name|int
name|max_width
decl_stmt|,
name|max_height
decl_stmt|;
name|int
name|width_inc
decl_stmt|,
name|height_inc
decl_stmt|;
block|}
name|XIconSize
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|res_name
decl_stmt|;
name|char
modifier|*
name|res_class
decl_stmt|;
block|}
name|XClassHint
typedef|;
end_typedef

begin_comment
comment|/*  * These macros are used to give some sugar to the image routines so that  * naive people are more comfortable with them.  */
end_comment

begin_define
define|#
directive|define
name|XDestroyImage
parameter_list|(
name|ximage
parameter_list|)
define|\
value|((*((ximage)->f.destroy_image))((ximage)))
end_define

begin_define
define|#
directive|define
name|XGetPixel
parameter_list|(
name|ximage
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((*((ximage)->f.get_pixel))((ximage), (x), (y)))
end_define

begin_define
define|#
directive|define
name|XPutPixel
parameter_list|(
name|ximage
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|pixel
parameter_list|)
define|\
value|((*((ximage)->f.put_pixel))((ximage), (x), (y), (pixel)))
end_define

begin_define
define|#
directive|define
name|XSubImage
parameter_list|(
name|ximage
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|width
parameter_list|,
name|height
parameter_list|)
define|\
value|((*((ximage)->f.sub_image))((ximage), (x), (y), (width), (height)))
end_define

begin_define
define|#
directive|define
name|XAddPixel
parameter_list|(
name|ximage
parameter_list|,
name|value
parameter_list|)
define|\
value|((*((ximage)->f.add_pixel))((ximage), (value)))
end_define

begin_comment
comment|/*  * Compose sequence status structure, used in calling XLookupString.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XComposeStatus
block|{
name|XPointer
name|compose_ptr
decl_stmt|;
comment|/* state table pointer */
name|int
name|chars_matched
decl_stmt|;
comment|/* match state */
block|}
name|XComposeStatus
typedef|;
end_typedef

begin_comment
comment|/*  * Keysym macros, used on Keysyms to test for classes of symbols  */
end_comment

begin_define
define|#
directive|define
name|IsKeypadKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|(((unsigned)(keysym)>= XK_KP_Space)&& ((unsigned)(keysym)<= XK_KP_Equal))
end_define

begin_define
define|#
directive|define
name|IsCursorKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|(((unsigned)(keysym)>= XK_Home)&& ((unsigned)(keysym)<  XK_Select))
end_define

begin_define
define|#
directive|define
name|IsPFKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|(((unsigned)(keysym)>= XK_KP_F1)&& ((unsigned)(keysym)<= XK_KP_F4))
end_define

begin_define
define|#
directive|define
name|IsFunctionKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|(((unsigned)(keysym)>= XK_F1)&& ((unsigned)(keysym)<= XK_F35))
end_define

begin_define
define|#
directive|define
name|IsMiscFunctionKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|(((unsigned)(keysym)>= XK_Select)&& ((unsigned)(keysym)<= XK_Break))
end_define

begin_define
define|#
directive|define
name|IsModifierKey
parameter_list|(
name|keysym
parameter_list|)
define|\
value|((((unsigned)(keysym)>= XK_Shift_L)&& ((unsigned)(keysym)<= XK_Hyper_R)) \    || ((unsigned)(keysym) == XK_Mode_switch) \    || ((unsigned)(keysym) == XK_Num_Lock))
end_define

begin_comment
comment|/*  * opaque reference to Region data type   */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_XRegion
modifier|*
name|Region
typedef|;
end_typedef

begin_comment
comment|/* Return values from XRectInRegion() */
end_comment

begin_define
define|#
directive|define
name|RectangleOut
value|0
end_define

begin_define
define|#
directive|define
name|RectangleIn
value|1
end_define

begin_define
define|#
directive|define
name|RectanglePart
value|2
end_define

begin_comment
comment|/*  * Information used by the visual utility routines to find desired visual  * type from the many visuals a display may support.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Visual
modifier|*
name|visual
decl_stmt|;
name|VisualID
name|visualid
decl_stmt|;
name|int
name|screen
decl_stmt|;
name|int
name|depth
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|c_plusplus
argument_list|)
name|int
name|c_class
decl_stmt|;
comment|/* C++ */
else|#
directive|else
name|int
name|class
decl_stmt|;
endif|#
directive|endif
name|unsigned
name|long
name|red_mask
decl_stmt|;
name|unsigned
name|long
name|green_mask
decl_stmt|;
name|unsigned
name|long
name|blue_mask
decl_stmt|;
name|int
name|colormap_size
decl_stmt|;
name|int
name|bits_per_rgb
decl_stmt|;
block|}
name|XVisualInfo
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VisualNoMask
value|0x0
end_define

begin_define
define|#
directive|define
name|VisualIDMask
value|0x1
end_define

begin_define
define|#
directive|define
name|VisualScreenMask
value|0x2
end_define

begin_define
define|#
directive|define
name|VisualDepthMask
value|0x4
end_define

begin_define
define|#
directive|define
name|VisualClassMask
value|0x8
end_define

begin_define
define|#
directive|define
name|VisualRedMaskMask
value|0x10
end_define

begin_define
define|#
directive|define
name|VisualGreenMaskMask
value|0x20
end_define

begin_define
define|#
directive|define
name|VisualBlueMaskMask
value|0x40
end_define

begin_define
define|#
directive|define
name|VisualColormapSizeMask
value|0x80
end_define

begin_define
define|#
directive|define
name|VisualBitsPerRGBMask
value|0x100
end_define

begin_define
define|#
directive|define
name|VisualAllMask
value|0x1FF
end_define

begin_comment
comment|/*  * This defines a window manager property that clients may use to  * share standard color maps of type RGB_COLOR_MAP:  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Colormap
name|colormap
decl_stmt|;
name|unsigned
name|long
name|red_max
decl_stmt|;
name|unsigned
name|long
name|red_mult
decl_stmt|;
name|unsigned
name|long
name|green_max
decl_stmt|;
name|unsigned
name|long
name|green_mult
decl_stmt|;
name|unsigned
name|long
name|blue_max
decl_stmt|;
name|unsigned
name|long
name|blue_mult
decl_stmt|;
name|unsigned
name|long
name|base_pixel
decl_stmt|;
name|VisualID
name|visualid
decl_stmt|;
comment|/* added by ICCCM version 1 */
name|XID
name|killid
decl_stmt|;
comment|/* added by ICCCM version 1 */
block|}
name|XStandardColormap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ReleaseByFreeingColormap
value|((XID) 1L)
end_define

begin_comment
comment|/* for killid field above */
end_comment

begin_comment
comment|/*  * return codes for XReadBitmapFile and XWriteBitmapFile  */
end_comment

begin_define
define|#
directive|define
name|BitmapSuccess
value|0
end_define

begin_define
define|#
directive|define
name|BitmapOpenFailed
value|1
end_define

begin_define
define|#
directive|define
name|BitmapFileInvalid
value|2
end_define

begin_define
define|#
directive|define
name|BitmapNoMemory
value|3
end_define

begin_comment
comment|/****************************************************************  *  * Context Management  *  ****************************************************************/
end_comment

begin_comment
comment|/* Associative lookup table return codes */
end_comment

begin_define
define|#
directive|define
name|XCSUCCESS
value|0
end_define

begin_comment
comment|/* No error. */
end_comment

begin_define
define|#
directive|define
name|XCNOMEM
value|1
end_define

begin_comment
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|XCNOENT
value|2
end_define

begin_comment
comment|/* No entry in table */
end_comment

begin_typedef
typedef|typedef
name|int
name|XContext
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XUniqueContext
parameter_list|()
value|((XContext) XrmUniqueQuark())
end_define

begin_define
define|#
directive|define
name|XStringToContext
parameter_list|(
name|string
parameter_list|)
value|((XContext) XrmStringToQuark(string))
end_define

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/* The following declarations are alphabetized. */
specifier|extern
name|XClassHint
modifier|*
name|XAllocClassHint
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XIconSize
modifier|*
name|XAllocIconSize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XSizeHints
modifier|*
name|XAllocSizeHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XStandardColormap
modifier|*
name|XAllocStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XWMHints
modifier|*
name|XAllocWMHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XClipBox(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* r */
operator|,
extern|XRectangle*
end_extern

begin_comment
comment|/* rect_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|Region
name|XCreateRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XDefaultString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|void
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDeleteContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* rid */
parameter_list|,
name|XContext
comment|/* context */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XDestroyRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
end_extern

begin_comment
comment|/* r */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XEmptyRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
end_extern

begin_comment
comment|/* r */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XEqualRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* r1 */
operator|,
extern|Region
end_extern

begin_comment
comment|/* r2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|XFindContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* rid */
parameter_list|,
name|XContext
comment|/* context */
parameter_list|,
name|XPointer
modifier|*
comment|/* data_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetClassHint
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XClassHint
modifier|*
comment|/* class_hints_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetIconSizes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XIconSize
modifier|*
modifier|*
comment|/* size_list_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetNormalHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetRGBColormaps
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XStandardColormap
modifier|*
modifier|*
comment|/* stdcmap_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetSizeHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints_return */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XStandardColormap
modifier|*
comment|/* colormap_return */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetTextProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XVisualInfo
modifier|*
name|XGetVisualInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|long
comment|/* vinfo_mask */
parameter_list|,
name|XVisualInfo
modifier|*
comment|/* vinfo_template */
parameter_list|,
name|int
modifier|*
comment|/* nitems_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMClientMachine
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XWMHints
modifier|*
name|XGetWMHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMIconName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMNormalHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints_return */
parameter_list|,
name|long
modifier|*
comment|/* supplied_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMSizeHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints_return */
parameter_list|,
name|long
modifier|*
comment|/* supplied_return */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetZoomHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* zhints_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XIntersectRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* sra */
operator|,
extern|Region
comment|/* srb */
operator|,
extern|Region
end_extern

begin_comment
comment|/* dr_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|XLookupString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XKeyEvent
modifier|*
comment|/* event_struct */
parameter_list|,
name|char
modifier|*
comment|/* buffer_return */
parameter_list|,
name|int
comment|/* bytes_buffer */
parameter_list|,
name|KeySym
modifier|*
comment|/* keysym_return */
parameter_list|,
name|XComposeStatus
modifier|*
comment|/* status_in_out */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XMatchVisualInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* screen */
parameter_list|,
name|int
comment|/* depth */
parameter_list|,
name|int
comment|/* class */
parameter_list|,
name|XVisualInfo
modifier|*
comment|/* vinfo_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XOffsetRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* r */
operator|,
extern|int
comment|/* dx */
operator|,
extern|int
end_extern

begin_comment
comment|/* dy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|Bool
name|XPointInRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Region
comment|/* r */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Region
name|XPolygonRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPoint
modifier|*
comment|/* points */
parameter_list|,
name|int
comment|/* n */
parameter_list|,
name|int
comment|/* fill_rule */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XRectInRegion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Region
comment|/* r */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XSaveContext
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* rid */
parameter_list|,
name|XContext
comment|/* context */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetClassHint(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XClassHint*
end_extern

begin_comment
comment|/* class_hints */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XSetIconSizes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XIconSize*
comment|/* size_list */
operator|,
extern|int
end_extern

begin_comment
comment|/* count */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XSetNormalHints(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XSizeHints*
end_extern

begin_comment
comment|/* hints */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|XSetRGBColormaps
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XStandardColormap
modifier|*
comment|/* stdcmaps */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetSizeHints(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XSizeHints*
comment|/* hints */
operator|,
extern|Atom
end_extern

begin_comment
comment|/* property */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XSetStandardProperties(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|_Xconst char*
comment|/* window_name */
operator|,
extern|_Xconst char*
comment|/* icon_name */
operator|,
extern|Pixmap
comment|/* icon_pixmap */
operator|,
extern|char**
comment|/* argv */
operator|,
extern|int
comment|/* argc */
operator|,
extern|XSizeHints*
end_extern

begin_comment
comment|/* hints */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|XSetTextProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetWMClientMachine
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetWMHints(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XWMHints*
end_extern

begin_comment
comment|/* wm_hints */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|XSetWMIconName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetWMName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetWMNormalHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetWMProperties
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* window_name */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* icon_name */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv */
parameter_list|,
name|int
comment|/* argc */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* normal_hints */
parameter_list|,
name|XWMHints
modifier|*
comment|/* wm_hints */
parameter_list|,
name|XClassHint
modifier|*
comment|/* class_hints */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbSetWMProperties
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* window_name */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* icon_name */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* argv */
parameter_list|,
name|int
comment|/* argc */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* normal_hints */
parameter_list|,
name|XWMHints
modifier|*
comment|/* wm_hints */
parameter_list|,
name|XClassHint
modifier|*
comment|/* class_hints */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetWMSizeHints
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Region
end_extern

begin_comment
comment|/* r */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|XSetStandardColormap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* w */
parameter_list|,
name|XStandardColormap
modifier|*
comment|/* colormap */
parameter_list|,
name|Atom
comment|/* property */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetZoomHints(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|XSizeHints*
end_extern

begin_comment
comment|/* zhints */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XShrinkRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* r */
operator|,
extern|int
comment|/* dx */
operator|,
extern|int
end_extern

begin_comment
comment|/* dy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|Status
name|XStringListToTextProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
modifier|*
comment|/* list */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSubtractRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* sra */
operator|,
extern|Region
comment|/* srb */
operator|,
extern|Region
end_extern

begin_comment
comment|/* dr_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|XmbTextListToTextProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* list */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|XICCEncodingStyle
comment|/* style */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XwcTextListToTextProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|wchar_t
modifier|*
modifier|*
comment|/* list */
parameter_list|,
name|int
comment|/* count */
parameter_list|,
name|XICCEncodingStyle
comment|/* style */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XwcFreeStringList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|wchar_t
modifier|*
modifier|*
comment|/* list */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XTextPropertyToStringList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XTextProperty
modifier|*
comment|/* text_prop */
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
comment|/* list_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmbTextPropertyToTextList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
comment|/* list_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XwcTextPropertyToTextList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XTextProperty
modifier|*
comment|/* text_prop */
parameter_list|,
name|wchar_t
modifier|*
modifier|*
modifier|*
comment|/* list_return */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XUnionRectWithRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XRectangle*
comment|/* rectangle */
operator|,
extern|Region
comment|/* src_region */
operator|,
extern|Region
end_extern

begin_comment
comment|/* dest_region_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern XUnionRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* sra */
operator|,
extern|Region
comment|/* srb */
operator|,
extern|Region
end_extern

begin_comment
comment|/* dr_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|XWMGeometry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* screen_number */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* user_geometry */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* default_geometry */
parameter_list|,
name|unsigned
name|int
comment|/* border_width */
parameter_list|,
name|XSizeHints
modifier|*
comment|/* hints */
parameter_list|,
name|int
modifier|*
comment|/* x_return */
parameter_list|,
name|int
modifier|*
comment|/* y_return */
parameter_list|,
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|int
modifier|*
comment|/* height_return */
parameter_list|,
name|int
modifier|*
comment|/* gravity_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XXorRegion(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Region
comment|/* sra */
operator|,
extern|Region
comment|/* srb */
operator|,
extern|Region
end_extern

begin_comment
comment|/* dr_return */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XUTIL_H_ */
end_comment

end_unit

