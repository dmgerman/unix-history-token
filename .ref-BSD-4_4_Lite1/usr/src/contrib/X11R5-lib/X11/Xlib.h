begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xlib.h,v 11.215 91/07/22 15:42:38 rws Exp $ */
end_comment

begin_comment
comment|/*   * Copyright 1985, 1986, 1987, 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * X Window System is a Trademark of MIT.  *  */
end_comment

begin_comment
comment|/*  *	Xlib.h - Header definition and support file for the C subroutine  *	interface library (Xlib) to the X Window System Protocol (V11).  *	Structures and symbols starting with "_" are private to the library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_XLIB_H_
end_define

begin_define
define|#
directive|define
name|XlibSpecificationRelease
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPES__
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* forgot to protect it... */
end_comment

begin_define
define|#
directive|define
name|__TYPES__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPES__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
name|defined
argument_list|(
name|MOTOROLA
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|_POSIX_SOURCE
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USG */
end_comment

begin_include
include|#
directive|include
file|<X11/X.h>
end_include

begin_comment
comment|/* applications should not depend on these two headers being included! */
end_comment

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xosdefs.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|X_WCHAR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|X_NOT_STDC_ENV
end_ifdef

begin_define
define|#
directive|define
name|X_WCHAR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|X_WCHAR
end_ifndef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* replace this with #include or typedef appropriate for your system */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|wchar_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
modifier|*
name|XPointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Bool
value|int
end_define

begin_define
define|#
directive|define
name|Status
value|int
end_define

begin_define
define|#
directive|define
name|True
value|1
end_define

begin_define
define|#
directive|define
name|False
value|0
end_define

begin_define
define|#
directive|define
name|QueuedAlready
value|0
end_define

begin_define
define|#
directive|define
name|QueuedAfterReading
value|1
end_define

begin_define
define|#
directive|define
name|QueuedAfterFlush
value|2
end_define

begin_define
define|#
directive|define
name|ConnectionNumber
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->fd)
end_define

begin_define
define|#
directive|define
name|RootWindow
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).root)
end_define

begin_define
define|#
directive|define
name|DefaultScreen
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->default_screen)
end_define

begin_define
define|#
directive|define
name|DefaultRootWindow
parameter_list|(
name|dpy
parameter_list|)
value|(((dpy)->screens[(dpy)->default_screen]).root)
end_define

begin_define
define|#
directive|define
name|DefaultVisual
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).root_visual)
end_define

begin_define
define|#
directive|define
name|DefaultGC
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).default_gc)
end_define

begin_define
define|#
directive|define
name|BlackPixel
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).black_pixel)
end_define

begin_define
define|#
directive|define
name|WhitePixel
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).white_pixel)
end_define

begin_define
define|#
directive|define
name|AllPlanes
value|((unsigned long)~0L)
end_define

begin_define
define|#
directive|define
name|QLength
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->qlen)
end_define

begin_define
define|#
directive|define
name|DisplayWidth
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).width)
end_define

begin_define
define|#
directive|define
name|DisplayHeight
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).height)
end_define

begin_define
define|#
directive|define
name|DisplayWidthMM
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).mwidth)
end_define

begin_define
define|#
directive|define
name|DisplayHeightMM
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).mheight)
end_define

begin_define
define|#
directive|define
name|DisplayPlanes
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).root_depth)
end_define

begin_define
define|#
directive|define
name|DisplayCells
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(DefaultVisual((dpy), (scr))->map_entries)
end_define

begin_define
define|#
directive|define
name|ScreenCount
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->nscreens)
end_define

begin_define
define|#
directive|define
name|ServerVendor
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->vendor)
end_define

begin_define
define|#
directive|define
name|ProtocolVersion
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->proto_major_version)
end_define

begin_define
define|#
directive|define
name|ProtocolRevision
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->proto_minor_version)
end_define

begin_define
define|#
directive|define
name|VendorRelease
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->release)
end_define

begin_define
define|#
directive|define
name|DisplayString
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->display_name)
end_define

begin_define
define|#
directive|define
name|DefaultDepth
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).root_depth)
end_define

begin_define
define|#
directive|define
name|DefaultColormap
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(((dpy)->screens[(scr)]).cmap)
end_define

begin_define
define|#
directive|define
name|BitmapUnit
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->bitmap_unit)
end_define

begin_define
define|#
directive|define
name|BitmapBitOrder
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->bitmap_bit_order)
end_define

begin_define
define|#
directive|define
name|BitmapPad
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->bitmap_pad)
end_define

begin_define
define|#
directive|define
name|ImageByteOrder
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->byte_order)
end_define

begin_define
define|#
directive|define
name|NextRequest
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->request + 1)
end_define

begin_define
define|#
directive|define
name|LastKnownRequestProcessed
parameter_list|(
name|dpy
parameter_list|)
value|((dpy)->last_request_read)
end_define

begin_comment
comment|/* macros for screen oriented applications (toolkit) */
end_comment

begin_define
define|#
directive|define
name|ScreenOfDisplay
parameter_list|(
name|dpy
parameter_list|,
name|scr
parameter_list|)
value|(&((dpy)->screens[(scr)]))
end_define

begin_define
define|#
directive|define
name|DefaultScreenOfDisplay
parameter_list|(
name|dpy
parameter_list|)
value|(&((dpy)->screens[(dpy)->default_screen]))
end_define

begin_define
define|#
directive|define
name|DisplayOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->display)
end_define

begin_define
define|#
directive|define
name|RootWindowOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->root)
end_define

begin_define
define|#
directive|define
name|BlackPixelOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->black_pixel)
end_define

begin_define
define|#
directive|define
name|WhitePixelOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->white_pixel)
end_define

begin_define
define|#
directive|define
name|DefaultColormapOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->cmap)
end_define

begin_define
define|#
directive|define
name|DefaultDepthOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->root_depth)
end_define

begin_define
define|#
directive|define
name|DefaultGCOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->default_gc)
end_define

begin_define
define|#
directive|define
name|DefaultVisualOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->root_visual)
end_define

begin_define
define|#
directive|define
name|WidthOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->width)
end_define

begin_define
define|#
directive|define
name|HeightOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->height)
end_define

begin_define
define|#
directive|define
name|WidthMMOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->mwidth)
end_define

begin_define
define|#
directive|define
name|HeightMMOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->mheight)
end_define

begin_define
define|#
directive|define
name|PlanesOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->root_depth)
end_define

begin_define
define|#
directive|define
name|CellsOfScreen
parameter_list|(
name|s
parameter_list|)
value|(DefaultVisualOfScreen((s))->map_entries)
end_define

begin_define
define|#
directive|define
name|MinCmapsOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->min_maps)
end_define

begin_define
define|#
directive|define
name|MaxCmapsOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->max_maps)
end_define

begin_define
define|#
directive|define
name|DoesSaveUnders
parameter_list|(
name|s
parameter_list|)
value|((s)->save_unders)
end_define

begin_define
define|#
directive|define
name|DoesBackingStore
parameter_list|(
name|s
parameter_list|)
value|((s)->backing_store)
end_define

begin_define
define|#
directive|define
name|EventMaskOfScreen
parameter_list|(
name|s
parameter_list|)
value|((s)->root_input_mask)
end_define

begin_comment
comment|/*  * Extensions need a way to hang private data on some structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XExtData
block|{
name|int
name|number
decl_stmt|;
comment|/* number returned by XRegisterExtension */
name|struct
name|_XExtData
modifier|*
name|next
decl_stmt|;
comment|/* next item on list of data for structure */
name|int
function_decl|(
modifier|*
name|free_private
function_decl|)
parameter_list|()
function_decl|;
comment|/* called to free private storage */
name|XPointer
name|private_data
decl_stmt|;
comment|/* data private to this extension. */
block|}
name|XExtData
typedef|;
end_typedef

begin_comment
comment|/*  * This file contains structures used by the extension mechanism.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* public to extension, cannot be changed */
name|int
name|extension
decl_stmt|;
comment|/* extension number */
name|int
name|major_opcode
decl_stmt|;
comment|/* major op-code assigned by server */
name|int
name|first_event
decl_stmt|;
comment|/* first event number for the extension */
name|int
name|first_error
decl_stmt|;
comment|/* first error number for the extension */
block|}
name|XExtCodes
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure for retrieving info about pixmap formats.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|depth
decl_stmt|;
name|int
name|bits_per_pixel
decl_stmt|;
name|int
name|scanline_pad
decl_stmt|;
block|}
name|XPixmapFormatValues
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure for setting graphics context.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|function
decl_stmt|;
comment|/* logical operation */
name|unsigned
name|long
name|plane_mask
decl_stmt|;
comment|/* plane mask */
name|unsigned
name|long
name|foreground
decl_stmt|;
comment|/* foreground pixel */
name|unsigned
name|long
name|background
decl_stmt|;
comment|/* background pixel */
name|int
name|line_width
decl_stmt|;
comment|/* line width */
name|int
name|line_style
decl_stmt|;
comment|/* LineSolid, LineOnOffDash, LineDoubleDash */
name|int
name|cap_style
decl_stmt|;
comment|/* CapNotLast, CapButt,  				   CapRound, CapProjecting */
name|int
name|join_style
decl_stmt|;
comment|/* JoinMiter, JoinRound, JoinBevel */
name|int
name|fill_style
decl_stmt|;
comment|/* FillSolid, FillTiled,  				   FillStippled, FillOpaeueStippled */
name|int
name|fill_rule
decl_stmt|;
comment|/* EvenOddRule, WindingRule */
name|int
name|arc_mode
decl_stmt|;
comment|/* ArcChord, ArcPieSlice */
name|Pixmap
name|tile
decl_stmt|;
comment|/* tile pixmap for tiling operations */
name|Pixmap
name|stipple
decl_stmt|;
comment|/* stipple 1 plane pixmap for stipping */
name|int
name|ts_x_origin
decl_stmt|;
comment|/* offset for tile or stipple operations */
name|int
name|ts_y_origin
decl_stmt|;
name|Font
name|font
decl_stmt|;
comment|/* default text font for text operations */
name|int
name|subwindow_mode
decl_stmt|;
comment|/* ClipByChildren, IncludeInferiors */
name|Bool
name|graphics_exposures
decl_stmt|;
comment|/* boolean, should exposures be generated */
name|int
name|clip_x_origin
decl_stmt|;
comment|/* origin for clipping */
name|int
name|clip_y_origin
decl_stmt|;
name|Pixmap
name|clip_mask
decl_stmt|;
comment|/* bitmap clipping; other calls for rects */
name|int
name|dash_offset
decl_stmt|;
comment|/* patterned/dashed line information */
name|char
name|dashes
decl_stmt|;
block|}
name|XGCValues
typedef|;
end_typedef

begin_comment
comment|/*  * Graphics context.  The contents of this structure are implementation  * dependent.  A GC should be treated as opaque by application code.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XGC
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|GContext
name|gid
decl_stmt|;
comment|/* protocol ID for graphics context */
name|Bool
name|rects
decl_stmt|;
comment|/* boolean: TRUE if clipmask is list of rectangles */
name|Bool
name|dashes
decl_stmt|;
comment|/* boolean: TRUE if dash-list is really a list */
name|unsigned
name|long
name|dirty
decl_stmt|;
comment|/* cache dirty bits */
name|XGCValues
name|values
decl_stmt|;
comment|/* shadow structure of values */
block|}
typedef|*
name|GC
typedef|;
end_typedef

begin_comment
comment|/*  * Visual structure; contains information about colormapping possible.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|VisualID
name|visualid
decl_stmt|;
comment|/* visual id of this visual */
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
comment|/* C++ class of screen (monochrome, etc.) */
else|#
directive|else
name|int
name|class
decl_stmt|;
comment|/* class of screen (monochrome, etc.) */
endif|#
directive|endif
name|unsigned
name|long
name|red_mask
decl_stmt|,
name|green_mask
decl_stmt|,
name|blue_mask
decl_stmt|;
comment|/* mask values */
name|int
name|bits_per_rgb
decl_stmt|;
comment|/* log base 2 of distinct color values */
name|int
name|map_entries
decl_stmt|;
comment|/* color map entries */
block|}
name|Visual
typedef|;
end_typedef

begin_comment
comment|/*  * Depth structure; contains information for each possible depth.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|depth
decl_stmt|;
comment|/* this depth (Z) of the depth */
name|int
name|nvisuals
decl_stmt|;
comment|/* number of Visual types at this depth */
name|Visual
modifier|*
name|visuals
decl_stmt|;
comment|/* list of visuals possible at this depth */
block|}
name|Depth
typedef|;
end_typedef

begin_comment
comment|/*  * Information about the screen.  The contents of this structure are  * implementation dependent.  A Screen should be treated as opaque  * by application code.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|struct
name|_XDisplay
modifier|*
name|display
decl_stmt|;
comment|/* back pointer to display structure */
name|Window
name|root
decl_stmt|;
comment|/* Root window id. */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width and height of screen */
name|int
name|mwidth
decl_stmt|,
name|mheight
decl_stmt|;
comment|/* width and height of  in millimeters */
name|int
name|ndepths
decl_stmt|;
comment|/* number of depths possible */
name|Depth
modifier|*
name|depths
decl_stmt|;
comment|/* list of allowable depths on the screen */
name|int
name|root_depth
decl_stmt|;
comment|/* bits per pixel */
name|Visual
modifier|*
name|root_visual
decl_stmt|;
comment|/* root visual */
name|GC
name|default_gc
decl_stmt|;
comment|/* GC for the root root visual */
name|Colormap
name|cmap
decl_stmt|;
comment|/* default color map */
name|unsigned
name|long
name|white_pixel
decl_stmt|;
name|unsigned
name|long
name|black_pixel
decl_stmt|;
comment|/* White and Black pixel values */
name|int
name|max_maps
decl_stmt|,
name|min_maps
decl_stmt|;
comment|/* max and min color maps */
name|int
name|backing_store
decl_stmt|;
comment|/* Never, WhenMapped, Always */
name|Bool
name|save_unders
decl_stmt|;
name|long
name|root_input_mask
decl_stmt|;
comment|/* initial root input mask */
block|}
name|Screen
typedef|;
end_typedef

begin_comment
comment|/*  * Format structure; describes ZFormat data the screen will understand.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|int
name|depth
decl_stmt|;
comment|/* depth of this image format */
name|int
name|bits_per_pixel
decl_stmt|;
comment|/* bits/pixel at this depth */
name|int
name|scanline_pad
decl_stmt|;
comment|/* scanline must padded to this multiple */
block|}
name|ScreenFormat
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure for setting window attributes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pixmap
name|background_pixmap
decl_stmt|;
comment|/* background or None or ParentRelative */
name|unsigned
name|long
name|background_pixel
decl_stmt|;
comment|/* background pixel */
name|Pixmap
name|border_pixmap
decl_stmt|;
comment|/* border of the window */
name|unsigned
name|long
name|border_pixel
decl_stmt|;
comment|/* border pixel value */
name|int
name|bit_gravity
decl_stmt|;
comment|/* one of bit gravity values */
name|int
name|win_gravity
decl_stmt|;
comment|/* one of the window gravity values */
name|int
name|backing_store
decl_stmt|;
comment|/* NotUseful, WhenMapped, Always */
name|unsigned
name|long
name|backing_planes
decl_stmt|;
comment|/* planes to be preseved if possible */
name|unsigned
name|long
name|backing_pixel
decl_stmt|;
comment|/* value to use in restoring planes */
name|Bool
name|save_under
decl_stmt|;
comment|/* should bits under be saved? (popups) */
name|long
name|event_mask
decl_stmt|;
comment|/* set of events that should be saved */
name|long
name|do_not_propagate_mask
decl_stmt|;
comment|/* set of events that should not propagate */
name|Bool
name|override_redirect
decl_stmt|;
comment|/* boolean value for override-redirect */
name|Colormap
name|colormap
decl_stmt|;
comment|/* color map to be associated with window */
name|Cursor
name|cursor
decl_stmt|;
comment|/* cursor to be displayed (or None) */
block|}
name|XSetWindowAttributes
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* location of window */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width and height of window */
name|int
name|border_width
decl_stmt|;
comment|/* border width of window */
name|int
name|depth
decl_stmt|;
comment|/* depth of window */
name|Visual
modifier|*
name|visual
decl_stmt|;
comment|/* the associated visual structure */
name|Window
name|root
decl_stmt|;
comment|/* root of screen containing window */
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
comment|/* C++ InputOutput, InputOnly*/
else|#
directive|else
name|int
name|class
decl_stmt|;
comment|/* InputOutput, InputOnly*/
endif|#
directive|endif
name|int
name|bit_gravity
decl_stmt|;
comment|/* one of bit gravity values */
name|int
name|win_gravity
decl_stmt|;
comment|/* one of the window gravity values */
name|int
name|backing_store
decl_stmt|;
comment|/* NotUseful, WhenMapped, Always */
name|unsigned
name|long
name|backing_planes
decl_stmt|;
comment|/* planes to be preserved if possible */
name|unsigned
name|long
name|backing_pixel
decl_stmt|;
comment|/* value to be used when restoring planes */
name|Bool
name|save_under
decl_stmt|;
comment|/* boolean, should bits under be saved? */
name|Colormap
name|colormap
decl_stmt|;
comment|/* color map to be associated with window */
name|Bool
name|map_installed
decl_stmt|;
comment|/* boolean, is color map currently installed*/
name|int
name|map_state
decl_stmt|;
comment|/* IsUnmapped, IsUnviewable, IsViewable */
name|long
name|all_event_masks
decl_stmt|;
comment|/* set of events all people have interest in*/
name|long
name|your_event_mask
decl_stmt|;
comment|/* my event mask */
name|long
name|do_not_propagate_mask
decl_stmt|;
comment|/* set of events that should not propagate */
name|Bool
name|override_redirect
decl_stmt|;
comment|/* boolean value for override-redirect */
name|Screen
modifier|*
name|screen
decl_stmt|;
comment|/* back pointer to correct screen */
block|}
name|XWindowAttributes
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure for host setting; getting routines.  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|family
decl_stmt|;
comment|/* for example FamilyInternet */
name|int
name|length
decl_stmt|;
comment|/* length of address, in bytes */
name|char
modifier|*
name|address
decl_stmt|;
comment|/* pointer to where to find the bytes */
block|}
name|XHostAddress
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure for "image" data, used by image manipulation routines.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XImage
block|{
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* size of image */
name|int
name|xoffset
decl_stmt|;
comment|/* number of pixels offset in X direction */
name|int
name|format
decl_stmt|;
comment|/* XYBitmap, XYPixmap, ZPixmap */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* pointer to image data */
name|int
name|byte_order
decl_stmt|;
comment|/* data byte order, LSBFirst, MSBFirst */
name|int
name|bitmap_unit
decl_stmt|;
comment|/* quant. of scanline 8, 16, 32 */
name|int
name|bitmap_bit_order
decl_stmt|;
comment|/* LSBFirst, MSBFirst */
name|int
name|bitmap_pad
decl_stmt|;
comment|/* 8, 16, 32 either XY or ZPixmap */
name|int
name|depth
decl_stmt|;
comment|/* depth of image */
name|int
name|bytes_per_line
decl_stmt|;
comment|/* accelarator to next line */
name|int
name|bits_per_pixel
decl_stmt|;
comment|/* bits per pixel (ZPixmap) */
name|unsigned
name|long
name|red_mask
decl_stmt|;
comment|/* bits in z arrangment */
name|unsigned
name|long
name|green_mask
decl_stmt|;
name|unsigned
name|long
name|blue_mask
decl_stmt|;
name|XPointer
name|obdata
decl_stmt|;
comment|/* hook for the object routines to hang on */
struct|struct
name|funcs
block|{
comment|/* image manipulation routines */
name|struct
name|_XImage
modifier|*
function_decl|(
modifier|*
name|create_image
function_decl|)
parameter_list|()
function_decl|;
if|#
directive|if
name|NeedFunctionPrototypes
name|int
function_decl|(
modifier|*
name|destroy_image
function_decl|)
parameter_list|(
name|struct
name|_XImage
modifier|*
parameter_list|)
function_decl|;
name|unsigned
name|long
function_decl|(
modifier|*
name|get_pixel
function_decl|)
parameter_list|(
name|struct
name|_XImage
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|put_pixel
function_decl|)
parameter_list|(
name|struct
name|_XImage
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
name|struct
name|_XImage
modifier|*
function_decl|(
modifier|*
name|sub_image
function_decl|)
parameter_list|(
name|struct
name|_XImage
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|add_pixel
function_decl|)
parameter_list|(
name|struct
name|_XImage
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
else|#
directive|else
name|int
function_decl|(
modifier|*
name|destroy_image
function_decl|)
parameter_list|()
function_decl|;
name|unsigned
name|long
function_decl|(
modifier|*
name|get_pixel
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|put_pixel
function_decl|)
parameter_list|()
function_decl|;
name|struct
name|_XImage
modifier|*
function_decl|(
modifier|*
name|sub_image
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|add_pixel
function_decl|)
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
name|f
struct|;
block|}
name|XImage
typedef|;
end_typedef

begin_comment
comment|/*   * Data structure for XReconfigureWindow  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|border_width
decl_stmt|;
name|Window
name|sibling
decl_stmt|;
name|int
name|stack_mode
decl_stmt|;
block|}
name|XWindowChanges
typedef|;
end_typedef

begin_comment
comment|/*  * Data structure used by color operations  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
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
name|char
name|flags
decl_stmt|;
comment|/* do_red, do_green, do_blue */
name|char
name|pad
decl_stmt|;
block|}
name|XColor
typedef|;
end_typedef

begin_comment
comment|/*   * Data structures for graphics operations.  On most machines, these are  * congruent with the wire protocol structures, so reformatting the data  * can be avoided on these architectures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x1
decl_stmt|,
name|y1
decl_stmt|,
name|x2
decl_stmt|,
name|y2
decl_stmt|;
block|}
name|XSegment
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|XPoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
block|}
name|XRectangle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
name|short
name|angle1
decl_stmt|,
name|angle2
decl_stmt|;
block|}
name|XArc
typedef|;
end_typedef

begin_comment
comment|/* Data structure for XChangeKeyboardControl */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|key_click_percent
decl_stmt|;
name|int
name|bell_percent
decl_stmt|;
name|int
name|bell_pitch
decl_stmt|;
name|int
name|bell_duration
decl_stmt|;
name|int
name|led
decl_stmt|;
name|int
name|led_mode
decl_stmt|;
name|int
name|key
decl_stmt|;
name|int
name|auto_repeat_mode
decl_stmt|;
comment|/* On, Off, Default */
block|}
name|XKeyboardControl
typedef|;
end_typedef

begin_comment
comment|/* Data structure for XGetKeyboardControl */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|key_click_percent
decl_stmt|;
name|int
name|bell_percent
decl_stmt|;
name|unsigned
name|int
name|bell_pitch
decl_stmt|,
name|bell_duration
decl_stmt|;
name|unsigned
name|long
name|led_mask
decl_stmt|;
name|int
name|global_auto_repeat
decl_stmt|;
name|char
name|auto_repeats
index|[
literal|32
index|]
decl_stmt|;
block|}
name|XKeyboardState
typedef|;
end_typedef

begin_comment
comment|/* Data structure for XGetMotionEvents.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Time
name|time
decl_stmt|;
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|XTimeCoord
typedef|;
end_typedef

begin_comment
comment|/* Data structure for X{Set,Get}ModifierMapping */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|max_keypermod
decl_stmt|;
comment|/* The server's max # of keys per modifier */
name|KeyCode
modifier|*
name|modifiermap
decl_stmt|;
comment|/* An 8 by max_keypermod array of modifiers */
block|}
name|XModifierKeymap
typedef|;
end_typedef

begin_comment
comment|/*  * Display datatype maintaining display specific data.  * The contents of this structure are implementation dependent.  * A Display should be treated as opaque by application code.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XDisplay
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|struct
name|_XFreeFuncs
modifier|*
name|free_funcs
decl_stmt|;
comment|/* internal free functions */
name|int
name|fd
decl_stmt|;
comment|/* Network socket. */
name|int
name|lock
decl_stmt|;
comment|/* is someone in critical section? */
name|int
name|proto_major_version
decl_stmt|;
comment|/* maj. version of server's X protocol */
name|int
name|proto_minor_version
decl_stmt|;
comment|/* minor version of servers X protocol */
name|char
modifier|*
name|vendor
decl_stmt|;
comment|/* vendor of the server hardware */
name|XID
name|resource_base
decl_stmt|;
comment|/* resource ID base */
name|XID
name|resource_mask
decl_stmt|;
comment|/* resource ID mask bits */
name|XID
name|resource_id
decl_stmt|;
comment|/* allocator current ID */
name|int
name|resource_shift
decl_stmt|;
comment|/* allocator shift to correct bits */
name|XID
function_decl|(
modifier|*
name|resource_alloc
function_decl|)
parameter_list|()
function_decl|;
comment|/* allocator function */
name|int
name|byte_order
decl_stmt|;
comment|/* screen byte order, LSBFirst, MSBFirst */
name|int
name|bitmap_unit
decl_stmt|;
comment|/* padding and data requirements */
name|int
name|bitmap_pad
decl_stmt|;
comment|/* padding requirements on bitmaps */
name|int
name|bitmap_bit_order
decl_stmt|;
comment|/* LeastSignificant or MostSignificant */
name|int
name|nformats
decl_stmt|;
comment|/* number of pixmap formats in list */
name|ScreenFormat
modifier|*
name|pixmap_format
decl_stmt|;
comment|/* pixmap format list */
name|int
name|vnumber
decl_stmt|;
comment|/* Xlib's X protocol version number. */
name|int
name|release
decl_stmt|;
comment|/* release of the server */
name|struct
name|_XSQEvent
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
name|unsigned
name|long
name|last_request_read
decl_stmt|;
comment|/* seq number of last event read */
name|unsigned
name|long
name|request
decl_stmt|;
comment|/* sequence number of last request. */
name|char
modifier|*
name|last_req
decl_stmt|;
comment|/* beginning of last request, or dummy */
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
name|unsigned
name|max_request_size
decl_stmt|;
comment|/* maximum number 32 bit words in request*/
name|struct
name|_XrmHashBucketRec
modifier|*
name|db
decl_stmt|;
name|int
function_decl|(
modifier|*
name|synchandler
function_decl|)
parameter_list|()
function_decl|;
comment|/* Synchronization handler */
name|char
modifier|*
name|display_name
decl_stmt|;
comment|/* "host:display" string used on this connect*/
name|int
name|default_screen
decl_stmt|;
comment|/* default screen for operations */
name|int
name|nscreens
decl_stmt|;
comment|/* number of screens on this server*/
name|Screen
modifier|*
name|screens
decl_stmt|;
comment|/* pointer to list of screens */
name|unsigned
name|long
name|motion_buffer
decl_stmt|;
comment|/* size of motion buffer */
name|Window
name|current
decl_stmt|;
comment|/* for use internally for Keymap notify */
name|int
name|min_keycode
decl_stmt|;
comment|/* minimum defined keycode */
name|int
name|max_keycode
decl_stmt|;
comment|/* maximum defined keycode */
name|KeySym
modifier|*
name|keysyms
decl_stmt|;
comment|/* This server's keysyms */
name|XModifierKeymap
modifier|*
name|modifiermap
decl_stmt|;
comment|/* This server's modifier keymap */
name|int
name|keysyms_per_keycode
decl_stmt|;
comment|/* number of rows */
name|char
modifier|*
name|xdefaults
decl_stmt|;
comment|/* contents of defaults from server */
name|char
modifier|*
name|scratch_buffer
decl_stmt|;
comment|/* place to hang scratch buffer */
name|unsigned
name|long
name|scratch_length
decl_stmt|;
comment|/* length of scratch buffer */
name|int
name|ext_number
decl_stmt|;
comment|/* extension number on this display */
name|struct
name|_XExten
modifier|*
name|ext_procs
decl_stmt|;
comment|/* extensions initialized on this display */
comment|/* 	 * the following can be fixed size, as the protocol defines how 	 * much address space is available.  	 * While this could be done using the extension vector, there 	 * may be MANY events processed, so a search through the extension 	 * list to find the right procedure for each event might be 	 * expensive if many extensions are being used. 	 */
name|Bool
function_decl|(
modifier|*
name|event_vec
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* vector for wire to event */
name|Status
function_decl|(
modifier|*
name|wire_vec
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* vector for event to wire */
name|KeySym
name|lock_meaning
decl_stmt|;
comment|/* for XLookupString */
name|struct
name|_XKeytrans
modifier|*
name|key_bindings
decl_stmt|;
comment|/* for XLookupString */
name|Font
name|cursor_font
decl_stmt|;
comment|/* for XCreateFontCursor */
name|struct
name|_XDisplayAtoms
modifier|*
name|atoms
decl_stmt|;
comment|/* for XInternAtom */
struct|struct
block|{
comment|/* for XReconfigureWMWindow */
name|long
name|sequence_number
decl_stmt|;
name|int
function_decl|(
modifier|*
name|old_handler
function_decl|)
parameter_list|()
function_decl|;
name|Bool
name|succeeded
decl_stmt|;
block|}
name|reconfigure_wm_window
struct|;
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* internal connection flags */
name|unsigned
name|int
name|mode_switch
decl_stmt|;
comment|/* keyboard group modifiers */
name|struct
name|_XContextDB
modifier|*
name|context_db
decl_stmt|;
comment|/* context database */
name|Bool
function_decl|(
modifier|*
modifier|*
name|error_vec
function_decl|)
parameter_list|()
function_decl|;
comment|/* vector for wire to error */
comment|/* 	 * Xcms information 	 */
struct|struct
block|{
name|XPointer
name|defaultCCCs
decl_stmt|;
comment|/* pointer to an array of default XcmsCCC */
name|XPointer
name|clientCmaps
decl_stmt|;
comment|/* pointer to linked list of XcmsCmapRec */
name|XPointer
name|perVisualIntensityMaps
decl_stmt|;
comment|/* linked list of XcmsIntensityMap */
block|}
name|cms
struct|;
name|int
name|conn_checker
decl_stmt|;
comment|/* ugly thing used by _XEventsQueued */
name|struct
name|_XIMFilter
modifier|*
name|im_filters
decl_stmt|;
block|}
name|Display
typedef|;
end_typedef

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_comment
comment|/* prototypes require event type definitions */
end_comment

begin_undef
undef|#
directive|undef
name|_XEVENT_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_XEVENT_
end_ifndef

begin_comment
comment|/*  * Definitions of specific events.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* "event" window it is reported relative to */
name|Window
name|root
decl_stmt|;
comment|/* root window that the event occured on */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window */
name|Time
name|time
decl_stmt|;
comment|/* milliseconds */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* pointer x, y coordinates in event window */
name|int
name|x_root
decl_stmt|,
name|y_root
decl_stmt|;
comment|/* coordinates relative to root */
name|unsigned
name|int
name|state
decl_stmt|;
comment|/* key or button mask */
name|unsigned
name|int
name|keycode
decl_stmt|;
comment|/* detail */
name|Bool
name|same_screen
decl_stmt|;
comment|/* same screen flag */
block|}
name|XKeyEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XKeyEvent
name|XKeyPressedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XKeyEvent
name|XKeyReleasedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* "event" window it is reported relative to */
name|Window
name|root
decl_stmt|;
comment|/* root window that the event occured on */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window */
name|Time
name|time
decl_stmt|;
comment|/* milliseconds */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* pointer x, y coordinates in event window */
name|int
name|x_root
decl_stmt|,
name|y_root
decl_stmt|;
comment|/* coordinates relative to root */
name|unsigned
name|int
name|state
decl_stmt|;
comment|/* key or button mask */
name|unsigned
name|int
name|button
decl_stmt|;
comment|/* detail */
name|Bool
name|same_screen
decl_stmt|;
comment|/* same screen flag */
block|}
name|XButtonEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XButtonEvent
name|XButtonPressedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XButtonEvent
name|XButtonReleasedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* "event" window reported relative to */
name|Window
name|root
decl_stmt|;
comment|/* root window that the event occured on */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window */
name|Time
name|time
decl_stmt|;
comment|/* milliseconds */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* pointer x, y coordinates in event window */
name|int
name|x_root
decl_stmt|,
name|y_root
decl_stmt|;
comment|/* coordinates relative to root */
name|unsigned
name|int
name|state
decl_stmt|;
comment|/* key or button mask */
name|char
name|is_hint
decl_stmt|;
comment|/* detail */
name|Bool
name|same_screen
decl_stmt|;
comment|/* same screen flag */
block|}
name|XMotionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XMotionEvent
name|XPointerMovedEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* of event */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* "event" window reported relative to */
name|Window
name|root
decl_stmt|;
comment|/* root window that the event occured on */
name|Window
name|subwindow
decl_stmt|;
comment|/* child window */
name|Time
name|time
decl_stmt|;
comment|/* milliseconds */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* pointer x, y coordinates in event window */
name|int
name|x_root
decl_stmt|,
name|y_root
decl_stmt|;
comment|/* coordinates relative to root */
name|int
name|mode
decl_stmt|;
comment|/* NotifyNormal, NotifyGrab, NotifyUngrab */
name|int
name|detail
decl_stmt|;
comment|/* 	 * NotifyAncestor, NotifyVirtual, NotifyInferior,  	 * NotifyNonlinear,NotifyNonlinearVirtual 	 */
name|Bool
name|same_screen
decl_stmt|;
comment|/* same screen flag */
name|Bool
name|focus
decl_stmt|;
comment|/* boolean focus */
name|unsigned
name|int
name|state
decl_stmt|;
comment|/* key or button mask */
block|}
name|XCrossingEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XCrossingEvent
name|XEnterWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XCrossingEvent
name|XLeaveWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* FocusIn or FocusOut */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* window of event */
name|int
name|mode
decl_stmt|;
comment|/* NotifyNormal, NotifyGrab, NotifyUngrab */
name|int
name|detail
decl_stmt|;
comment|/* 	 * NotifyAncestor, NotifyVirtual, NotifyInferior,  	 * NotifyNonlinear,NotifyNonlinearVirtual, NotifyPointer, 	 * NotifyPointerRoot, NotifyDetailNone  	 */
block|}
name|XFocusChangeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XFocusChangeEvent
name|XFocusInEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|XFocusChangeEvent
name|XFocusOutEvent
typedef|;
end_typedef

begin_comment
comment|/* generated on EnterWindow and FocusIn  when KeyMapState selected */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|char
name|key_vector
index|[
literal|32
index|]
decl_stmt|;
block|}
name|XKeymapEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|count
decl_stmt|;
comment|/* if non-zero, at least this many more */
block|}
name|XExposeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Drawable
name|drawable
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|count
decl_stmt|;
comment|/* if non-zero, at least this many more */
name|int
name|major_code
decl_stmt|;
comment|/* core is CopyArea or CopyPlane */
name|int
name|minor_code
decl_stmt|;
comment|/* not defined in the core */
block|}
name|XGraphicsExposeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Drawable
name|drawable
decl_stmt|;
name|int
name|major_code
decl_stmt|;
comment|/* core is CopyArea or CopyPlane */
name|int
name|minor_code
decl_stmt|;
comment|/* not defined in the core */
block|}
name|XNoExposeEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|int
name|state
decl_stmt|;
comment|/* Visibility state */
block|}
name|XVisibilityEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|parent
decl_stmt|;
comment|/* parent of the window */
name|Window
name|window
decl_stmt|;
comment|/* window id of window created */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* window location */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* size of window */
name|int
name|border_width
decl_stmt|;
comment|/* border width */
name|Bool
name|override_redirect
decl_stmt|;
comment|/* creation should be overridden */
block|}
name|XCreateWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
block|}
name|XDestroyWindowEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|Bool
name|from_configure
decl_stmt|;
block|}
name|XUnmapEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|Bool
name|override_redirect
decl_stmt|;
comment|/* boolean, is override set... */
block|}
name|XMapEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|parent
decl_stmt|;
name|Window
name|window
decl_stmt|;
block|}
name|XMapRequestEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|Window
name|parent
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|Bool
name|override_redirect
decl_stmt|;
block|}
name|XReparentEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|border_width
decl_stmt|;
name|Window
name|above
decl_stmt|;
name|Bool
name|override_redirect
decl_stmt|;
block|}
name|XConfigureEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|XGravityEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
block|}
name|XResizeRequestEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|parent
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
name|int
name|border_width
decl_stmt|;
name|Window
name|above
decl_stmt|;
name|int
name|detail
decl_stmt|;
comment|/* Above, Below, TopIf, BottomIf, Opposite */
name|unsigned
name|long
name|value_mask
decl_stmt|;
block|}
name|XConfigureRequestEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|event
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|place
decl_stmt|;
comment|/* PlaceOnTop, PlaceOnBottom */
block|}
name|XCirculateEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|parent
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|int
name|place
decl_stmt|;
comment|/* PlaceOnTop, PlaceOnBottom */
block|}
name|XCirculateRequestEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|Atom
name|atom
decl_stmt|;
name|Time
name|time
decl_stmt|;
name|int
name|state
decl_stmt|;
comment|/* NewValue, Deleted */
block|}
name|XPropertyEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|Atom
name|selection
decl_stmt|;
name|Time
name|time
decl_stmt|;
block|}
name|XSelectionClearEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|owner
decl_stmt|;
name|Window
name|requestor
decl_stmt|;
name|Atom
name|selection
decl_stmt|;
name|Atom
name|target
decl_stmt|;
name|Atom
name|property
decl_stmt|;
name|Time
name|time
decl_stmt|;
block|}
name|XSelectionRequestEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|requestor
decl_stmt|;
name|Atom
name|selection
decl_stmt|;
name|Atom
name|target
decl_stmt|;
name|Atom
name|property
decl_stmt|;
comment|/* ATOM or None */
name|Time
name|time
decl_stmt|;
block|}
name|XSelectionEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|Colormap
name|colormap
decl_stmt|;
comment|/* COLORMAP or None */
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
name|Bool
name|c_new
decl_stmt|;
comment|/* C++ */
else|#
directive|else
name|Bool
name|new
decl_stmt|;
endif|#
directive|endif
name|int
name|state
decl_stmt|;
comment|/* ColormapInstalled, ColormapUninstalled */
block|}
name|XColormapEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
name|Atom
name|message_type
decl_stmt|;
name|int
name|format
decl_stmt|;
union|union
block|{
name|char
name|b
index|[
literal|20
index|]
decl_stmt|;
name|short
name|s
index|[
literal|10
index|]
decl_stmt|;
name|long
name|l
index|[
literal|5
index|]
decl_stmt|;
block|}
name|data
union|;
block|}
name|XClientMessageEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* unused */
name|int
name|request
decl_stmt|;
comment|/* one of MappingModifier, MappingKeyboard, 				   MappingPointer */
name|int
name|first_keycode
decl_stmt|;
comment|/* first keycode */
name|int
name|count
decl_stmt|;
comment|/* defines range of change w. first_keycode*/
block|}
name|XMappingEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|XID
name|resourceid
decl_stmt|;
comment|/* resource id */
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* serial number of failed request */
name|unsigned
name|char
name|error_code
decl_stmt|;
comment|/* error code of failed request */
name|unsigned
name|char
name|request_code
decl_stmt|;
comment|/* Major op-code of failed request */
name|unsigned
name|char
name|minor_code
decl_stmt|;
comment|/* Minor op-code of failed request */
block|}
name|XErrorEvent
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
name|unsigned
name|long
name|serial
decl_stmt|;
comment|/* # of last request processed by server */
name|Bool
name|send_event
decl_stmt|;
comment|/* true if this came from a SendEvent request */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display the event was read from */
name|Window
name|window
decl_stmt|;
comment|/* window on which event was requested in event mask */
block|}
name|XAnyEvent
typedef|;
end_typedef

begin_comment
comment|/*  * this union is defined so Xlib can always use the same sized  * event structure internally, to avoid memory fragmentation.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|_XEvent
block|{
name|int
name|type
decl_stmt|;
comment|/* must not be changed; first element */
name|XAnyEvent
name|xany
decl_stmt|;
name|XKeyEvent
name|xkey
decl_stmt|;
name|XButtonEvent
name|xbutton
decl_stmt|;
name|XMotionEvent
name|xmotion
decl_stmt|;
name|XCrossingEvent
name|xcrossing
decl_stmt|;
name|XFocusChangeEvent
name|xfocus
decl_stmt|;
name|XExposeEvent
name|xexpose
decl_stmt|;
name|XGraphicsExposeEvent
name|xgraphicsexpose
decl_stmt|;
name|XNoExposeEvent
name|xnoexpose
decl_stmt|;
name|XVisibilityEvent
name|xvisibility
decl_stmt|;
name|XCreateWindowEvent
name|xcreatewindow
decl_stmt|;
name|XDestroyWindowEvent
name|xdestroywindow
decl_stmt|;
name|XUnmapEvent
name|xunmap
decl_stmt|;
name|XMapEvent
name|xmap
decl_stmt|;
name|XMapRequestEvent
name|xmaprequest
decl_stmt|;
name|XReparentEvent
name|xreparent
decl_stmt|;
name|XConfigureEvent
name|xconfigure
decl_stmt|;
name|XGravityEvent
name|xgravity
decl_stmt|;
name|XResizeRequestEvent
name|xresizerequest
decl_stmt|;
name|XConfigureRequestEvent
name|xconfigurerequest
decl_stmt|;
name|XCirculateEvent
name|xcirculate
decl_stmt|;
name|XCirculateRequestEvent
name|xcirculaterequest
decl_stmt|;
name|XPropertyEvent
name|xproperty
decl_stmt|;
name|XSelectionClearEvent
name|xselectionclear
decl_stmt|;
name|XSelectionRequestEvent
name|xselectionrequest
decl_stmt|;
name|XSelectionEvent
name|xselection
decl_stmt|;
name|XColormapEvent
name|xcolormap
decl_stmt|;
name|XClientMessageEvent
name|xclient
decl_stmt|;
name|XMappingEvent
name|xmapping
decl_stmt|;
name|XErrorEvent
name|xerror
decl_stmt|;
name|XKeymapEvent
name|xkeymap
decl_stmt|;
name|long
name|pad
index|[
literal|24
index|]
decl_stmt|;
block|}
name|XEvent
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XAllocID
parameter_list|(
name|dpy
parameter_list|)
value|((*(dpy)->resource_alloc)((dpy)))
end_define

begin_comment
comment|/*  * per character font metric information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|lbearing
decl_stmt|;
comment|/* origin to left edge of raster */
name|short
name|rbearing
decl_stmt|;
comment|/* origin to right edge of raster */
name|short
name|width
decl_stmt|;
comment|/* advance to next char's origin */
name|short
name|ascent
decl_stmt|;
comment|/* baseline to top edge of raster */
name|short
name|descent
decl_stmt|;
comment|/* baseline to bottom edge of raster */
name|unsigned
name|short
name|attributes
decl_stmt|;
comment|/* per char flags (not predefined) */
block|}
name|XCharStruct
typedef|;
end_typedef

begin_comment
comment|/*  * To allow arbitrary information with fonts, there are additional properties  * returned.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Atom
name|name
decl_stmt|;
name|unsigned
name|long
name|card32
decl_stmt|;
block|}
name|XFontProp
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XExtData
modifier|*
name|ext_data
decl_stmt|;
comment|/* hook for extension to hang data */
name|Font
name|fid
decl_stmt|;
comment|/* Font id for this font */
name|unsigned
name|direction
decl_stmt|;
comment|/* hint about direction the font is painted */
name|unsigned
name|min_char_or_byte2
decl_stmt|;
comment|/* first character */
name|unsigned
name|max_char_or_byte2
decl_stmt|;
comment|/* last character */
name|unsigned
name|min_byte1
decl_stmt|;
comment|/* first row that exists */
name|unsigned
name|max_byte1
decl_stmt|;
comment|/* last row that exists */
name|Bool
name|all_chars_exist
decl_stmt|;
comment|/* flag if all characters have non-zero size*/
name|unsigned
name|default_char
decl_stmt|;
comment|/* char to print for undefined character */
name|int
name|n_properties
decl_stmt|;
comment|/* how many properties there are */
name|XFontProp
modifier|*
name|properties
decl_stmt|;
comment|/* pointer to array of additional properties*/
name|XCharStruct
name|min_bounds
decl_stmt|;
comment|/* minimum bounds over all existing char*/
name|XCharStruct
name|max_bounds
decl_stmt|;
comment|/* maximum bounds over all existing char*/
name|XCharStruct
modifier|*
name|per_char
decl_stmt|;
comment|/* first_char to last_char information */
name|int
name|ascent
decl_stmt|;
comment|/* log. extent above baseline for spacing */
name|int
name|descent
decl_stmt|;
comment|/* log. descent below baseline for spacing */
block|}
name|XFontStruct
typedef|;
end_typedef

begin_comment
comment|/*  * PolyText routines take these as arguments.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|chars
decl_stmt|;
comment|/* pointer to string */
name|int
name|nchars
decl_stmt|;
comment|/* number of characters */
name|int
name|delta
decl_stmt|;
comment|/* delta between strings */
name|Font
name|font
decl_stmt|;
comment|/* font to print it in, None don't change */
block|}
name|XTextItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* normal 16 bit characters are two bytes */
name|unsigned
name|char
name|byte1
decl_stmt|;
name|unsigned
name|char
name|byte2
decl_stmt|;
block|}
name|XChar2b
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XChar2b
modifier|*
name|chars
decl_stmt|;
comment|/* two byte characters */
name|int
name|nchars
decl_stmt|;
comment|/* number of characters */
name|int
name|delta
decl_stmt|;
comment|/* delta between strings */
name|Font
name|font
decl_stmt|;
comment|/* font to print it in, None don't change */
block|}
name|XTextItem16
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Display
modifier|*
name|display
decl_stmt|;
name|GC
name|gc
decl_stmt|;
name|Visual
modifier|*
name|visual
decl_stmt|;
name|Screen
modifier|*
name|screen
decl_stmt|;
name|ScreenFormat
modifier|*
name|pixmap_format
decl_stmt|;
name|XFontStruct
modifier|*
name|font
decl_stmt|;
block|}
name|XEDataObject
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XRectangle
name|max_ink_extent
decl_stmt|;
name|XRectangle
name|max_logical_extent
decl_stmt|;
block|}
name|XFontSetExtents
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XFontSet
modifier|*
name|XFontSet
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|chars
decl_stmt|;
name|int
name|nchars
decl_stmt|;
name|int
name|delta
decl_stmt|;
name|XFontSet
name|font_set
decl_stmt|;
block|}
name|XmbTextItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|wchar_t
modifier|*
name|chars
decl_stmt|;
name|int
name|nchars
decl_stmt|;
name|int
name|delta
decl_stmt|;
name|XFontSet
name|font_set
decl_stmt|;
block|}
name|XwcTextItem
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|XIMProc
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XIM
modifier|*
name|XIM
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XIC
modifier|*
name|XIC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XIMStyle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|count_styles
decl_stmt|;
name|XIMStyle
modifier|*
name|supported_styles
decl_stmt|;
block|}
name|XIMStyles
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XIMPreeditArea
value|0x0001L
end_define

begin_define
define|#
directive|define
name|XIMPreeditCallbacks
value|0x0002L
end_define

begin_define
define|#
directive|define
name|XIMPreeditPosition
value|0x0004L
end_define

begin_define
define|#
directive|define
name|XIMPreeditNothing
value|0x0008L
end_define

begin_define
define|#
directive|define
name|XIMPreeditNone
value|0x0010L
end_define

begin_define
define|#
directive|define
name|XIMStatusArea
value|0x0100L
end_define

begin_define
define|#
directive|define
name|XIMStatusCallbacks
value|0x0200L
end_define

begin_define
define|#
directive|define
name|XIMStatusNothing
value|0x0400L
end_define

begin_define
define|#
directive|define
name|XIMStatusNone
value|0x0800L
end_define

begin_define
define|#
directive|define
name|XNVaNestedList
value|"XNVaNestedList"
end_define

begin_define
define|#
directive|define
name|XNQueryInputStyle
value|"queryInputStyle"
end_define

begin_define
define|#
directive|define
name|XNClientWindow
value|"clientWindow"
end_define

begin_define
define|#
directive|define
name|XNInputStyle
value|"inputStyle"
end_define

begin_define
define|#
directive|define
name|XNFocusWindow
value|"focusWindow"
end_define

begin_define
define|#
directive|define
name|XNResourceName
value|"resourceName"
end_define

begin_define
define|#
directive|define
name|XNResourceClass
value|"resourceClass"
end_define

begin_define
define|#
directive|define
name|XNGeometryCallback
value|"geometryCallback"
end_define

begin_define
define|#
directive|define
name|XNFilterEvents
value|"filterEvents"
end_define

begin_define
define|#
directive|define
name|XNPreeditStartCallback
value|"preeditStartCallback"
end_define

begin_define
define|#
directive|define
name|XNPreeditDoneCallback
value|"preeditDoneCallback"
end_define

begin_define
define|#
directive|define
name|XNPreeditDrawCallback
value|"preeditDrawCallback"
end_define

begin_define
define|#
directive|define
name|XNPreeditCaretCallback
value|"preeditCaretCallback"
end_define

begin_define
define|#
directive|define
name|XNPreeditAttributes
value|"preeditAttributes"
end_define

begin_define
define|#
directive|define
name|XNStatusStartCallback
value|"statusStartCallback"
end_define

begin_define
define|#
directive|define
name|XNStatusDoneCallback
value|"statusDoneCallback"
end_define

begin_define
define|#
directive|define
name|XNStatusDrawCallback
value|"statusDrawCallback"
end_define

begin_define
define|#
directive|define
name|XNStatusAttributes
value|"statusAttributes"
end_define

begin_define
define|#
directive|define
name|XNArea
value|"area"
end_define

begin_define
define|#
directive|define
name|XNAreaNeeded
value|"areaNeeded"
end_define

begin_define
define|#
directive|define
name|XNSpotLocation
value|"spotLocation"
end_define

begin_define
define|#
directive|define
name|XNColormap
value|"colorMap"
end_define

begin_define
define|#
directive|define
name|XNStdColormap
value|"stdColorMap"
end_define

begin_define
define|#
directive|define
name|XNForeground
value|"foreground"
end_define

begin_define
define|#
directive|define
name|XNBackground
value|"background"
end_define

begin_define
define|#
directive|define
name|XNBackgroundPixmap
value|"backgroundPixmap"
end_define

begin_define
define|#
directive|define
name|XNFontSet
value|"fontSet"
end_define

begin_define
define|#
directive|define
name|XNLineSpace
value|"lineSpace"
end_define

begin_define
define|#
directive|define
name|XNCursor
value|"cursor"
end_define

begin_define
define|#
directive|define
name|XBufferOverflow
value|-1
end_define

begin_define
define|#
directive|define
name|XLookupNone
value|1
end_define

begin_define
define|#
directive|define
name|XLookupChars
value|2
end_define

begin_define
define|#
directive|define
name|XLookupKeySym
value|3
end_define

begin_define
define|#
directive|define
name|XLookupBoth
value|4
end_define

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|XVaNestedList
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|XPointer
name|XVaNestedList
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|XPointer
name|client_data
decl_stmt|;
name|XIMProc
name|callback
decl_stmt|;
block|}
name|XIMCallback
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|XIMFeedback
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XIMReverse
value|1
end_define

begin_define
define|#
directive|define
name|XIMUnderline
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|XIMHighlight
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|XIMPrimary
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|XIMSecondary
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|XIMTertiary
value|(1<<7)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_XIMText
block|{
name|unsigned
name|short
name|length
decl_stmt|;
name|XIMFeedback
modifier|*
name|feedback
decl_stmt|;
name|Bool
name|encoding_is_wchar
decl_stmt|;
union|union
block|{
name|char
modifier|*
name|multi_byte
decl_stmt|;
name|wchar_t
modifier|*
name|wide_char
decl_stmt|;
block|}
name|string
union|;
block|}
name|XIMText
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XIMPreeditDrawCallbackStruct
block|{
name|int
name|caret
decl_stmt|;
comment|/* Cursor offset within pre-edit string */
name|int
name|chg_first
decl_stmt|;
comment|/* Starting change position */
name|int
name|chg_length
decl_stmt|;
comment|/* Length of the change in character count */
name|XIMText
modifier|*
name|text
decl_stmt|;
block|}
name|XIMPreeditDrawCallbackStruct
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XIMForwardChar
block|,
name|XIMBackwardChar
block|,
name|XIMForwardWord
block|,
name|XIMBackwardWord
block|,
name|XIMCaretUp
block|,
name|XIMCaretDown
block|,
name|XIMNextLine
block|,
name|XIMPreviousLine
block|,
name|XIMLineStart
block|,
name|XIMLineEnd
block|,
name|XIMAbsolutePosition
block|,
name|XIMDontChange
block|}
name|XIMCaretDirection
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XIMIsInvisible
block|,
comment|/* Disable caret feedback */
name|XIMIsPrimary
block|,
comment|/* UI defined caret feedback */
name|XIMIsSecondary
comment|/* UI defined caret feedback */
block|}
name|XIMCaretStyle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XIMPreeditCaretCallbackStruct
block|{
name|int
name|position
decl_stmt|;
comment|/* Caret offset within pre-edit string */
name|XIMCaretDirection
name|direction
decl_stmt|;
comment|/* Caret moves direction */
name|XIMCaretStyle
name|style
decl_stmt|;
comment|/* Feedback of the caret */
block|}
name|XIMPreeditCaretCallbackStruct
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XIMTextType
block|,
name|XIMBitmapType
block|}
name|XIMStatusDataType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XIMStatusDrawCallbackStruct
block|{
name|XIMStatusDataType
name|type
decl_stmt|;
union|union
block|{
name|XIMText
modifier|*
name|text
decl_stmt|;
name|Pixmap
name|bitmap
decl_stmt|;
block|}
name|data
union|;
block|}
name|XIMStatusDrawCallbackStruct
typedef|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|XFontStruct
modifier|*
name|XLoadQueryFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XFontStruct
modifier|*
name|XQueryFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XID
comment|/* font_ID */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XTimeCoord
modifier|*
name|XGetMotionEvents
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
name|Time
comment|/* start */
parameter_list|,
name|Time
comment|/* stop */
parameter_list|,
name|int
modifier|*
comment|/* nevents_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XModifierKeymap
modifier|*
name|XDeleteModifiermapEntry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XModifierKeymap
modifier|*
comment|/* modmap */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* keycode_entry */
parameter_list|,
else|#
directive|else
name|KeyCode
comment|/* keycode_entry */
parameter_list|,
endif|#
directive|endif
name|int
comment|/* modifier */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XModifierKeymap
modifier|*
name|XGetModifierMapping
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XModifierKeymap
modifier|*
name|XInsertModifiermapEntry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XModifierKeymap
modifier|*
comment|/* modmap */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* keycode_entry */
parameter_list|,
else|#
directive|else
name|KeyCode
comment|/* keycode_entry */
parameter_list|,
endif|#
directive|endif
name|int
comment|/* modifier */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XModifierKeymap
modifier|*
name|XNewModifiermap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|int
comment|/* max_keys_per_mod */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XImage
modifier|*
name|XCreateImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
parameter_list|,
name|int
comment|/* format */
parameter_list|,
name|int
comment|/* offset */
parameter_list|,
name|char
modifier|*
comment|/* data */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|int
comment|/* bitmap_pad */
parameter_list|,
name|int
comment|/* bytes_per_line */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XImage
modifier|*
name|XGetImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
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
parameter_list|,
name|unsigned
name|long
comment|/* plane_mask */
parameter_list|,
name|int
comment|/* format */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XImage
modifier|*
name|XGetSubImage
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
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
parameter_list|,
name|unsigned
name|long
comment|/* plane_mask */
parameter_list|,
name|int
comment|/* format */
parameter_list|,
name|XImage
modifier|*
comment|/* dest_image */
parameter_list|,
name|int
comment|/* dest_x */
parameter_list|,
name|int
comment|/* dest_y */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * X function declarations.  */
end_comment

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XOpenDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* display_name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XrmInitialize
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
name|XFetchBytes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* nbytes_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XFetchBuffer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* nbytes_return */
parameter_list|,
name|int
comment|/* buffer */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XGetAtomName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Atom
comment|/* atom */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XGetDefault
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* program */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* option */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XDisplayName
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XKeysymToString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|KeySym
comment|/* keysym */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern int (*XSynchronize(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Bool
end_extern

begin_comment
comment|/* onoff */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern int (*XSetAfterFunction(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
endif|#
directive|endif
operator|)
end_expr_stmt

begin_comment
comment|/* procedure */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|))
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|Atom
name|XInternAtom
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* atom_name */
parameter_list|,
name|Bool
comment|/* only_if_exists */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Colormap
name|XCopyColormapAndFree
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Colormap
name|XCreateColormap
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
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|int
comment|/* alloc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|XCreatePixmapCursor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Pixmap
comment|/* source */
parameter_list|,
name|Pixmap
comment|/* mask */
parameter_list|,
name|XColor
modifier|*
comment|/* foreground_color */
parameter_list|,
name|XColor
modifier|*
comment|/* background_color */
parameter_list|,
name|unsigned
name|int
comment|/* x */
parameter_list|,
name|unsigned
name|int
comment|/* y */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|XCreateGlyphCursor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Font
comment|/* source_font */
parameter_list|,
name|Font
comment|/* mask_font */
parameter_list|,
name|unsigned
name|int
comment|/* source_char */
parameter_list|,
name|unsigned
name|int
comment|/* mask_char */
parameter_list|,
name|XColor
modifier|*
comment|/* foreground_color */
parameter_list|,
name|XColor
modifier|*
comment|/* background_color */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Cursor
name|XCreateFontCursor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|int
comment|/* shape */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Font
name|XLoadFont
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GC
name|XCreateGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XGCValues
modifier|*
comment|/* values */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GContext
name|XGContextFromGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|GC
comment|/* gc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XFlushGC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|GC
comment|/* gc */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XCreatePixmap
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Pixmap
name|XCreateBitmapFromData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* data */
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
name|Pixmap
name|XCreatePixmapFromBitmapData
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|char
modifier|*
comment|/* data */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|long
comment|/* fg */
parameter_list|,
name|unsigned
name|long
comment|/* bg */
parameter_list|,
name|unsigned
name|int
comment|/* depth */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XCreateSimpleWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* parent */
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
parameter_list|,
name|unsigned
name|int
comment|/* border_width */
parameter_list|,
name|unsigned
name|long
comment|/* border */
parameter_list|,
name|unsigned
name|long
comment|/* background */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XGetSelectionOwner
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Atom
comment|/* selection */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XCreateWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* parent */
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
parameter_list|,
name|unsigned
name|int
comment|/* border_width */
parameter_list|,
name|int
comment|/* depth */
parameter_list|,
name|unsigned
name|int
comment|/* class */
parameter_list|,
name|Visual
modifier|*
comment|/* visual */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XSetWindowAttributes
modifier|*
comment|/* attributes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Colormap
modifier|*
name|XListInstalledColormaps
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
name|int
modifier|*
comment|/* num_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|XListFonts
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* pattern */
parameter_list|,
name|int
comment|/* maxnames */
parameter_list|,
name|int
modifier|*
comment|/* actual_count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|XListFontsWithInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* pattern */
parameter_list|,
name|int
comment|/* maxnames */
parameter_list|,
name|int
modifier|*
comment|/* count_return */
parameter_list|,
name|XFontStruct
modifier|*
modifier|*
comment|/* info_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|XGetFontPath
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* npaths_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|XListExtensions
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* nextensions_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Atom
modifier|*
name|XListProperties
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
name|int
modifier|*
comment|/* num_prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XHostAddress
modifier|*
name|XListHosts
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
modifier|*
comment|/* nhosts_return */
parameter_list|,
name|Bool
modifier|*
comment|/* state_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
name|XKeycodeToKeysym
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* keycode */
parameter_list|,
else|#
directive|else
name|KeyCode
comment|/* keycode */
parameter_list|,
endif|#
directive|endif
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
name|XLookupKeysym
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XKeyEvent
modifier|*
comment|/* key_event */
parameter_list|,
name|int
comment|/* index */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
modifier|*
name|XGetKeyboardMapping
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
name|unsigned
name|int
comment|/* first_keycode */
parameter_list|,
else|#
directive|else
name|KeyCode
comment|/* first_keycode */
parameter_list|,
endif|#
directive|endif
name|int
comment|/* keycode_count */
parameter_list|,
name|int
modifier|*
comment|/* keysyms_per_keycode_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|KeySym
name|XStringToKeysym
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|XMaxRequestSize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XResourceManagerString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XScreenResourceString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XDisplayMotionBufferSize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|VisualID
name|XVisualIDFromVisual
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Visual
modifier|*
comment|/* visual */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* routines for dealing with extensions */
end_comment

begin_function_decl
specifier|extern
name|XExtCodes
modifier|*
name|XInitExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XExtCodes
modifier|*
name|XAddExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XExtData
modifier|*
name|XFindOnExtensionList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XExtData
modifier|*
modifier|*
comment|/* structure */
parameter_list|,
name|int
comment|/* number */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XExtData
modifier|*
modifier|*
name|XEHeadOfExtensionList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XEDataObject
comment|/* object */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* these are routines for which there are also macros */
end_comment

begin_function_decl
specifier|extern
name|Window
name|XRootWindow
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XDefaultRootWindow
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Window
name|XRootWindowOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Visual
modifier|*
name|XDefaultVisual
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Visual
modifier|*
name|XDefaultVisualOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GC
name|XDefaultGC
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|GC
name|XDefaultGCOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XBlackPixel
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XWhitePixel
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XAllPlanes
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
name|unsigned
name|long
name|XBlackPixelOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XWhitePixelOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XNextRequest
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|XLastKnownRequestProcessed
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XServerVendor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XDisplayString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Colormap
name|XDefaultColormap
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Colormap
name|XDefaultColormapOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XDisplayOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Screen
modifier|*
name|XScreenOfDisplay
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Screen
modifier|*
name|XDefaultScreenOfDisplay
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|XEventMaskOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XScreenNumberOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|XErrorHandler
function_decl|)
parameter_list|(
comment|/* WARNING, this type not in Xlib spec */
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XErrorEvent
modifier|*
comment|/* error_event */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|XErrorHandler
name|XSetErrorHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|XIOErrorHandler
function_decl|)
parameter_list|(
comment|/* WARNING, this type not in Xlib spec */
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|XIOErrorHandler
name|XSetIOErrorHandler
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIOErrorHandler
comment|/* handler */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XPixmapFormatValues
modifier|*
name|XListPixmapFormats
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
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
modifier|*
name|XListDepths
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
name|int
modifier|*
comment|/* count_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ICCCM routines for things that don't require special include files; */
end_comment

begin_comment
comment|/* other declarations are given in Xutil.h                             */
end_comment

begin_function_decl
specifier|extern
name|Status
name|XReconfigureWMWindow
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
name|int
comment|/* screen_number */
parameter_list|,
name|unsigned
name|int
comment|/* mask */
parameter_list|,
name|XWindowChanges
modifier|*
comment|/* changes */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMProtocols
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
name|Atom
modifier|*
modifier|*
comment|/* protocols_return */
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
name|XSetWMProtocols
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
name|Atom
modifier|*
comment|/* protocols */
parameter_list|,
name|int
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XIconifyWindow
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
name|int
comment|/* screen_number */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XWithdrawWindow
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
name|int
comment|/* screen_number */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetCommand
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
name|char
modifier|*
modifier|*
modifier|*
comment|/* argv_return */
parameter_list|,
name|int
modifier|*
comment|/* argc_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWMColormapWindows
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
name|Window
modifier|*
modifier|*
comment|/* windows_return */
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
name|XSetWMColormapWindows
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
name|Window
modifier|*
comment|/* colormap_windows */
parameter_list|,
name|int
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XFreeStringList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
modifier|*
comment|/* list */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetTransientForHint(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Window
end_extern

begin_comment
comment|/* prop_window */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* The following are given in alphabetical order */
end_comment

begin_extern
extern|extern XActivateScreenSaver(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XAddHost(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XHostAddress*
end_extern

begin_comment
comment|/* host */
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
extern|extern XAddHosts(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XHostAddress*
comment|/* hosts */
operator|,
extern|int
end_extern

begin_comment
comment|/* num_hosts */
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
extern|extern XAddToExtensionList(
if|#
directive|if
name|NeedFunctionPrototypes
extern|struct _XExtData**
comment|/* structure */
operator|,
extern|XExtData*
end_extern

begin_comment
comment|/* ext_data */
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
extern|extern XAddToSaveSet(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
name|XAllocColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|XColor
modifier|*
comment|/* screen_in_out */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XAllocColorCells
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|Bool
comment|/* contig */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* plane_masks_return */
parameter_list|,
name|unsigned
name|int
comment|/* nplanes */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* pixels_return */
parameter_list|,
name|unsigned
name|int
comment|/* npixels */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XAllocColorPlanes
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|Bool
comment|/* contig */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* pixels_return */
parameter_list|,
name|int
comment|/* ncolors */
parameter_list|,
name|int
comment|/* nreds */
parameter_list|,
name|int
comment|/* ngreens */
parameter_list|,
name|int
comment|/* nblues */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* rmask_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* gmask_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* bmask_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XAllocNamedColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* color_name */
parameter_list|,
name|XColor
modifier|*
comment|/* screen_def_return */
parameter_list|,
name|XColor
modifier|*
comment|/* exact_def_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XAllowEvents(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* event_mode */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XAutoRepeatOff(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XAutoRepeatOn(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XBell(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
end_extern

begin_comment
comment|/* percent */
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
name|XBitmapBitOrder
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XBitmapPad
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XBitmapUnit
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XCellsOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XChangeActivePointerGrab(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|unsigned int
comment|/* event_mask */
operator|,
extern|Cursor
comment|/* cursor */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XChangeGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned long
comment|/* valuemask */
operator|,
extern|XGCValues*
end_extern

begin_comment
comment|/* values */
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
extern|extern XChangeKeyboardControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|unsigned long
comment|/* value_mask */
operator|,
extern|XKeyboardControl*
end_extern

begin_comment
comment|/* values */
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
extern|extern XChangeKeyboardMapping(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* first_keycode */
operator|,
extern|int
comment|/* keysyms_per_keycode */
operator|,
extern|KeySym*
comment|/* keysyms */
operator|,
extern|int
end_extern

begin_comment
comment|/* num_codes */
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
extern|extern XChangePointerControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Bool
comment|/* do_accel */
operator|,
extern|Bool
comment|/* do_threshold */
operator|,
extern|int
comment|/* accel_numerator */
operator|,
extern|int
comment|/* accel_denominator */
operator|,
extern|int
end_extern

begin_comment
comment|/* threshold */
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
extern|extern XChangeProperty(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Atom
comment|/* property */
operator|,
extern|Atom
comment|/* type */
operator|,
extern|int
comment|/* format */
operator|,
extern|int
comment|/* mode */
operator|,
extern|_Xconst unsigned char*
comment|/* data */
operator|,
extern|int
end_extern

begin_comment
comment|/* nelements */
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
extern|extern XChangeSaveSet(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|int
end_extern

begin_comment
comment|/* change_mode */
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
extern|extern XChangeWindowAttributes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned long
comment|/* valuemask */
operator|,
extern|XSetWindowAttributes*
end_extern

begin_comment
comment|/* attributes */
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
name|XCheckIfEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
parameter_list|,
name|Bool
function_decl|(
modifier|*
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|XPointer
comment|/* arg */
endif|#
directive|endif
parameter_list|)
comment|/* predicate */
parameter_list|,
name|XPointer
comment|/* arg */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XCheckMaskEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|long
comment|/* event_mask */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XCheckTypedEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* event_type */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XCheckTypedWindowEvent
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
name|int
comment|/* event_type */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XCheckWindowEvent
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
name|long
comment|/* event_mask */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XCirculateSubwindows(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|int
end_extern

begin_comment
comment|/* direction */
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
extern|extern XCirculateSubwindowsDown(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XCirculateSubwindowsUp(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XClearArea(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
comment|/* height */
operator|,
extern|Bool
end_extern

begin_comment
comment|/* exposures */
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
extern|extern XClearWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XCloseDisplay(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XConfigureWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned int
comment|/* value_mask */
operator|,
extern|XWindowChanges*
end_extern

begin_comment
comment|/* values */
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
name|XConnectionNumber
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XConvertSelection(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Atom
comment|/* selection */
operator|,
extern|Atom
comment|/* target */
operator|,
extern|Atom
comment|/* property */
operator|,
extern|Window
comment|/* requestor */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XCopyArea(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* src */
operator|,
extern|Drawable
comment|/* dest */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* src_x */
operator|,
extern|int
comment|/* src_y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
comment|/* height */
operator|,
extern|int
comment|/* dest_x */
operator|,
extern|int
end_extern

begin_comment
comment|/* dest_y */
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
extern|extern XCopyGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* src */
operator|,
extern|unsigned long
comment|/* valuemask */
operator|,
extern|GC
end_extern

begin_comment
comment|/* dest */
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
extern|extern XCopyPlane(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* src */
operator|,
extern|Drawable
comment|/* dest */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* src_x */
operator|,
extern|int
comment|/* src_y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
comment|/* height */
operator|,
extern|int
comment|/* dest_x */
operator|,
extern|int
comment|/* dest_y */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* plane */
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
name|XDefaultDepth
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDefaultDepthOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDefaultScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XDefineCursor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Cursor
end_extern

begin_comment
comment|/* cursor */
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
extern|extern XDeleteProperty(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
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
extern|extern XDestroyWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XDestroySubwindows(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
name|XDoesBackingStore
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XDoesSaveUnders
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XDisableAccessControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
name|XDisplayCells
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDisplayHeight
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDisplayHeightMM
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XDisplayKeycodes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int*
comment|/* min_keycodes_return */
operator|,
extern|int*
end_extern

begin_comment
comment|/* max_keycodes_return */
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
name|XDisplayPlanes
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDisplayWidth
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XDisplayWidthMM
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XDrawArc(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
comment|/* height */
operator|,
extern|int
comment|/* angle1 */
operator|,
extern|int
end_extern

begin_comment
comment|/* angle2 */
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
extern|extern XDrawArcs(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XArc*
comment|/* arcs */
operator|,
extern|int
end_extern

begin_comment
comment|/* narcs */
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
extern|extern XDrawImageString(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|_Xconst char*
comment|/* string */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
extern|extern XDrawImageString16(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|_Xconst XChar2b*
comment|/* string */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
extern|extern XDrawLine(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x1 */
operator|,
extern|int
comment|/* x2 */
operator|,
extern|int
comment|/* y1 */
operator|,
extern|int
end_extern

begin_comment
comment|/* y2 */
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
extern|extern XDrawLines(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XPoint*
comment|/* points */
operator|,
extern|int
comment|/* npoints */
operator|,
extern|int
end_extern

begin_comment
comment|/* mode */
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
extern|extern XDrawPoint(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
end_extern

begin_comment
comment|/* y */
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
extern|extern XDrawPoints(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XPoint*
comment|/* points */
operator|,
extern|int
comment|/* npoints */
operator|,
extern|int
end_extern

begin_comment
comment|/* mode */
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
extern|extern XDrawRectangle(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* height */
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
extern|extern XDrawRectangles(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XRectangle*
comment|/* rectangles */
operator|,
extern|int
end_extern

begin_comment
comment|/* nrectangles */
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
extern|extern XDrawSegments(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XSegment*
comment|/* segments */
operator|,
extern|int
end_extern

begin_comment
comment|/* nsegments */
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
extern|extern XDrawString(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|_Xconst char*
comment|/* string */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
extern|extern XDrawString16(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|_Xconst XChar2b*
comment|/* string */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
extern|extern XDrawText(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|XTextItem*
comment|/* items */
operator|,
extern|int
end_extern

begin_comment
comment|/* nitems */
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
extern|extern XDrawText16(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|XTextItem16*
comment|/* items */
operator|,
extern|int
end_extern

begin_comment
comment|/* nitems */
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
extern|extern XEnableAccessControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
name|XEventsQueued
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* mode */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XFetchName
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
name|char
modifier|*
modifier|*
comment|/* window_name_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XFillArc(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
comment|/* height */
operator|,
extern|int
comment|/* angle1 */
operator|,
extern|int
end_extern

begin_comment
comment|/* angle2 */
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
extern|extern XFillArcs(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XArc*
comment|/* arcs */
operator|,
extern|int
end_extern

begin_comment
comment|/* narcs */
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
extern|extern XFillPolygon(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XPoint*
comment|/* points */
operator|,
extern|int
comment|/* npoints */
operator|,
extern|int
comment|/* shape */
operator|,
extern|int
end_extern

begin_comment
comment|/* mode */
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
extern|extern XFillRectangle(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* height */
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
extern|extern XFillRectangles(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XRectangle*
comment|/* rectangles */
operator|,
extern|int
end_extern

begin_comment
comment|/* nrectangles */
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
extern|extern XFlush(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XForceScreenSaver(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
end_extern

begin_comment
comment|/* mode */
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
extern|extern XFree(
if|#
directive|if
name|NeedFunctionPrototypes
extern|void*
end_extern

begin_comment
comment|/* data */
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
extern|extern XFreeColormap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
end_extern

begin_comment
comment|/* colormap */
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
extern|extern XFreeColors(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|unsigned long*
comment|/* pixels */
operator|,
extern|int
comment|/* npixels */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* planes */
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
extern|extern XFreeCursor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Cursor
end_extern

begin_comment
comment|/* cursor */
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
extern|extern XFreeExtensionList(
if|#
directive|if
name|NeedFunctionPrototypes
extern|char**
end_extern

begin_comment
comment|/* list */
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
extern|extern XFreeFont(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XFontStruct*
end_extern

begin_comment
comment|/* font_struct */
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
extern|extern XFreeFontInfo(
if|#
directive|if
name|NeedFunctionPrototypes
extern|char**
comment|/* names */
operator|,
extern|XFontStruct*
comment|/* free_info */
operator|,
extern|int
end_extern

begin_comment
comment|/* actual_count */
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
extern|extern XFreeFontNames(
if|#
directive|if
name|NeedFunctionPrototypes
extern|char**
end_extern

begin_comment
comment|/* list */
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
extern|extern XFreeFontPath(
if|#
directive|if
name|NeedFunctionPrototypes
extern|char**
end_extern

begin_comment
comment|/* list */
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
extern|extern XFreeGC(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
end_extern

begin_comment
comment|/* gc */
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
extern|extern XFreeModifiermap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XModifierKeymap*
end_extern

begin_comment
comment|/* modmap */
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
extern|extern XFreePixmap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* pixmap */
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
name|XGeometry
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
name|_Xconst
name|char
modifier|*
comment|/* position */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* default_position */
parameter_list|,
name|unsigned
name|int
comment|/* bwidth */
parameter_list|,
name|unsigned
name|int
comment|/* fwidth */
parameter_list|,
name|unsigned
name|int
comment|/* fheight */
parameter_list|,
name|int
comment|/* xadder */
parameter_list|,
name|int
comment|/* yadder */
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
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XGetErrorDatabaseText(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|_Xconst char*
comment|/* name */
operator|,
extern|_Xconst char*
comment|/* message */
operator|,
extern|_Xconst char*
comment|/* default_string */
operator|,
extern|char*
comment|/* buffer_return */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
extern|extern XGetErrorText(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* code */
operator|,
extern|char*
comment|/* buffer_return */
operator|,
extern|int
end_extern

begin_comment
comment|/* length */
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
name|XGetFontProperty
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontStruct
modifier|*
comment|/* font_struct */
parameter_list|,
name|Atom
comment|/* atom */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* value_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetGCValues
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|unsigned
name|long
comment|/* valuemask */
parameter_list|,
name|XGCValues
modifier|*
comment|/* values_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetGeometry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|Window
modifier|*
comment|/* root_return */
parameter_list|,
name|int
modifier|*
comment|/* x_return */
parameter_list|,
name|int
modifier|*
comment|/* y_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* border_width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* depth_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetIconName
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
name|char
modifier|*
modifier|*
comment|/* icon_name_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XGetInputFocus(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window*
comment|/* focus_return */
operator|,
extern|int*
end_extern

begin_comment
comment|/* revert_to_return */
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
extern|extern XGetKeyboardControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XKeyboardState*
end_extern

begin_comment
comment|/* values_return */
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
extern|extern XGetPointerControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int*
comment|/* accel_numerator_return */
operator|,
extern|int*
comment|/* accel_denominator_return */
operator|,
extern|int*
end_extern

begin_comment
comment|/* threshold_return */
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
name|XGetPointerMapping
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|unsigned
name|char
modifier|*
comment|/* map_return */
parameter_list|,
name|int
comment|/* nmap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XGetScreenSaver(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int*
comment|/* timeout_return */
operator|,
extern|int*
comment|/* interval_return */
operator|,
extern|int*
comment|/* prefer_blanking_return */
operator|,
extern|int*
end_extern

begin_comment
comment|/* allow_exposures_return */
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
name|XGetTransientForHint
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
name|Window
modifier|*
comment|/* prop_window_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XGetWindowProperty
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
name|Atom
comment|/* property */
parameter_list|,
name|long
comment|/* long_offset */
parameter_list|,
name|long
comment|/* long_length */
parameter_list|,
name|Bool
comment|/* delete */
parameter_list|,
name|Atom
comment|/* req_type */
parameter_list|,
name|Atom
modifier|*
comment|/* actual_type_return */
parameter_list|,
name|int
modifier|*
comment|/* actual_format_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* nitems_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* bytes_after_return */
parameter_list|,
name|unsigned
name|char
modifier|*
modifier|*
comment|/* prop_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XGetWindowAttributes
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
name|XWindowAttributes
modifier|*
comment|/* window_attributes_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XGrabButton(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|unsigned int
comment|/* button */
operator|,
extern|unsigned int
comment|/* modifiers */
operator|,
extern|Window
comment|/* grab_window */
operator|,
extern|Bool
comment|/* owner_events */
operator|,
extern|unsigned int
comment|/* event_mask */
operator|,
extern|int
comment|/* pointer_mode */
operator|,
extern|int
comment|/* keyboard_mode */
operator|,
extern|Window
comment|/* confine_to */
operator|,
extern|Cursor
end_extern

begin_comment
comment|/* cursor */
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
extern|extern XGrabKey(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* keycode */
operator|,
extern|unsigned int
comment|/* modifiers */
operator|,
extern|Window
comment|/* grab_window */
operator|,
extern|Bool
comment|/* owner_events */
operator|,
extern|int
comment|/* pointer_mode */
operator|,
extern|int
end_extern

begin_comment
comment|/* keyboard_mode */
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
name|XGrabKeyboard
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* grab_window */
parameter_list|,
name|Bool
comment|/* owner_events */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XGrabPointer
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* grab_window */
parameter_list|,
name|Bool
comment|/* owner_events */
parameter_list|,
name|unsigned
name|int
comment|/* event_mask */
parameter_list|,
name|int
comment|/* pointer_mode */
parameter_list|,
name|int
comment|/* keyboard_mode */
parameter_list|,
name|Window
comment|/* confine_to */
parameter_list|,
name|Cursor
comment|/* cursor */
parameter_list|,
name|Time
comment|/* time */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XGrabServer(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
name|XHeightMMOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XHeightOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XIfEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XEvent*
comment|/* event_return */
operator|,
extern|Bool (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XEvent
operator|*
comment|/* event */
operator|,
name|XPointer
comment|/* arg */
endif|#
directive|endif
operator|)
comment|/* predicate */
operator|,
name|XPointer
end_expr_stmt

begin_comment
comment|/* arg */
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
name|XImageByteOrder
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XInstallColormap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
end_extern

begin_comment
comment|/* colormap */
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
name|KeyCode
name|XKeysymToKeycode
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|KeySym
comment|/* keysym */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XKillClient(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XID
end_extern

begin_comment
comment|/* resource */
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
name|unsigned
name|long
name|XLastKnownRequestProcessed
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XLookupColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* color_name */
parameter_list|,
name|XColor
modifier|*
comment|/* exact_def_return */
parameter_list|,
name|XColor
modifier|*
comment|/* screen_def_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XLowerWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XMapRaised(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XMapSubwindows(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XMapWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XMaskEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|long
comment|/* event_mask */
operator|,
extern|XEvent*
end_extern

begin_comment
comment|/* event_return */
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
name|XMaxCmapsOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XMinCmapsOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XMoveResizeWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
comment|/* y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* height */
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
extern|extern XMoveWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
end_extern

begin_comment
comment|/* y */
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
extern|extern XNextEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XEvent*
end_extern

begin_comment
comment|/* event_return */
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
extern|extern XNoOp(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
name|XParseColor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Colormap
comment|/* colormap */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* spec */
parameter_list|,
name|XColor
modifier|*
comment|/* exact_def_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XParseGeometry
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* parsestring */
parameter_list|,
name|int
modifier|*
comment|/* x_return */
parameter_list|,
name|int
modifier|*
comment|/* y_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XPeekEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XEvent*
end_extern

begin_comment
comment|/* event_return */
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
extern|extern XPeekIfEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XEvent*
comment|/* event_return */
operator|,
extern|Bool (*
end_extern

begin_expr_stmt
unit|)
operator|(
if|#
directive|if
name|NeedNestedPrototypes
name|Display
operator|*
comment|/* display */
operator|,
name|XEvent
operator|*
comment|/* event */
operator|,
name|XPointer
comment|/* arg */
endif|#
directive|endif
operator|)
comment|/* predicate */
operator|,
name|XPointer
end_expr_stmt

begin_comment
comment|/* arg */
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
name|XPending
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XPlanesOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XProtocolRevision
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XProtocolVersion
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XPutBackEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XEvent*
end_extern

begin_comment
comment|/* event */
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
extern|extern XPutImage(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Drawable
comment|/* d */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|XImage*
comment|/* image */
operator|,
extern|int
comment|/* src_x */
operator|,
extern|int
comment|/* src_y */
operator|,
extern|int
comment|/* dest_x */
operator|,
extern|int
comment|/* dest_y */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* height */
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
name|XQLength
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XQueryBestCursor
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XQueryBestSize
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|int
comment|/* class */
parameter_list|,
name|Drawable
comment|/* which_screen */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XQueryBestStipple
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* which_screen */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XQueryBestTile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* which_screen */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XQueryColor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|XColor*
end_extern

begin_comment
comment|/* def_in_out */
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
extern|extern XQueryColors(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|XColor*
comment|/* defs_in_out */
operator|,
extern|int
end_extern

begin_comment
comment|/* ncolors */
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
name|XQueryExtension
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* name */
parameter_list|,
name|int
modifier|*
comment|/* major_opcode_return */
parameter_list|,
name|int
modifier|*
comment|/* first_event_return */
parameter_list|,
name|int
modifier|*
comment|/* first_error_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XQueryKeymap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|char [32]
end_extern

begin_comment
comment|/* keys_return */
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
name|XQueryPointer
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
name|Window
modifier|*
comment|/* root_return */
parameter_list|,
name|Window
modifier|*
comment|/* child_return */
parameter_list|,
name|int
modifier|*
comment|/* root_x_return */
parameter_list|,
name|int
modifier|*
comment|/* root_y_return */
parameter_list|,
name|int
modifier|*
comment|/* win_x_return */
parameter_list|,
name|int
modifier|*
comment|/* win_y_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* mask_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XQueryTextExtents(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XID
comment|/* font_ID */
operator|,
extern|_Xconst char*
comment|/* string */
operator|,
extern|int
comment|/* nchars */
operator|,
extern|int*
comment|/* direction_return */
operator|,
extern|int*
comment|/* font_ascent_return */
operator|,
extern|int*
comment|/* font_descent_return */
operator|,
extern|XCharStruct*
end_extern

begin_comment
comment|/* overall_return */
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
extern|extern XQueryTextExtents16(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XID
comment|/* font_ID */
operator|,
extern|_Xconst XChar2b*
comment|/* string */
operator|,
extern|int
comment|/* nchars */
operator|,
extern|int*
comment|/* direction_return */
operator|,
extern|int*
comment|/* font_ascent_return */
operator|,
extern|int*
comment|/* font_descent_return */
operator|,
extern|XCharStruct*
end_extern

begin_comment
comment|/* overall_return */
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
name|XQueryTree
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
name|Window
modifier|*
comment|/* root_return */
parameter_list|,
name|Window
modifier|*
comment|/* parent_return */
parameter_list|,
name|Window
modifier|*
modifier|*
comment|/* children_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* nchildren_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XRaiseWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
name|XReadBitmapFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* filename */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* width_return */
parameter_list|,
name|unsigned
name|int
modifier|*
comment|/* height_return */
parameter_list|,
name|Pixmap
modifier|*
comment|/* bitmap_return */
parameter_list|,
name|int
modifier|*
comment|/* x_hot_return */
parameter_list|,
name|int
modifier|*
comment|/* y_hot_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XRebindKeysym(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|KeySym
comment|/* keysym */
operator|,
extern|KeySym*
comment|/* list */
operator|,
extern|int
comment|/* mod_count */
operator|,
extern|_Xconst unsigned char*
comment|/* string */
operator|,
extern|int
end_extern

begin_comment
comment|/* bytes_string */
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
extern|extern XRecolorCursor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Cursor
comment|/* cursor */
operator|,
extern|XColor*
comment|/* foreground_color */
operator|,
extern|XColor*
end_extern

begin_comment
comment|/* background_color */
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
extern|extern XRefreshKeyboardMapping(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XMappingEvent*
end_extern

begin_comment
comment|/* event_map */
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
extern|extern XRemoveFromSaveSet(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XRemoveHost(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XHostAddress*
end_extern

begin_comment
comment|/* host */
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
extern|extern XRemoveHosts(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|XHostAddress*
comment|/* hosts */
operator|,
extern|int
end_extern

begin_comment
comment|/* num_hosts */
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
extern|extern XReparentWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Window
comment|/* parent */
operator|,
extern|int
comment|/* x */
operator|,
extern|int
end_extern

begin_comment
comment|/* y */
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
extern|extern XResetScreenSaver(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XResizeWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned int
comment|/* width */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* height */
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
extern|extern XRestackWindows(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window*
comment|/* windows */
operator|,
extern|int
end_extern

begin_comment
comment|/* nwindows */
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
extern|extern XRotateBuffers(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
end_extern

begin_comment
comment|/* rotate */
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
extern|extern XRotateWindowProperties(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Atom*
comment|/* properties */
operator|,
extern|int
comment|/* num_prop */
operator|,
extern|int
end_extern

begin_comment
comment|/* npositions */
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
name|XScreenCount
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSelectInput(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|long
end_extern

begin_comment
comment|/* event_mask */
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
name|XSendEvent
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
name|Bool
comment|/* propagate */
parameter_list|,
name|long
comment|/* event_mask */
parameter_list|,
name|XEvent
modifier|*
comment|/* event_send */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetAccessControl(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
end_extern

begin_comment
comment|/* mode */
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
extern|extern XSetArcMode(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
end_extern

begin_comment
comment|/* arc_mode */
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
extern|extern XSetBackground(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* background */
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
extern|extern XSetClipMask(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* pixmap */
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
extern|extern XSetClipOrigin(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* clip_x_origin */
operator|,
extern|int
end_extern

begin_comment
comment|/* clip_y_origin */
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
extern|extern XSetClipRectangles(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* clip_x_origin */
operator|,
extern|int
comment|/* clip_y_origin */
operator|,
extern|XRectangle*
comment|/* rectangles */
operator|,
extern|int
comment|/* n */
operator|,
extern|int
end_extern

begin_comment
comment|/* ordering */
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
extern|extern XSetCloseDownMode(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
end_extern

begin_comment
comment|/* close_mode */
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
extern|extern XSetCommand(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|char**
comment|/* argv */
operator|,
extern|int
end_extern

begin_comment
comment|/* argc */
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
extern|extern XSetDashes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* dash_offset */
operator|,
extern|_Xconst char*
comment|/* dash_list */
operator|,
extern|int
end_extern

begin_comment
comment|/* n */
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
extern|extern XSetFillRule(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
end_extern

begin_comment
comment|/* fill_rule */
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
extern|extern XSetFillStyle(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
end_extern

begin_comment
comment|/* fill_style */
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
extern|extern XSetFont(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Font
end_extern

begin_comment
comment|/* font */
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
extern|extern XSetFontPath(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|char**
comment|/* directories */
operator|,
extern|int
end_extern

begin_comment
comment|/* ndirs */
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
extern|extern XSetForeground(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* foreground */
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
extern|extern XSetFunction(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
end_extern

begin_comment
comment|/* function */
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
extern|extern XSetGraphicsExposures(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Bool
end_extern

begin_comment
comment|/* graphics_exposures */
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
extern|extern XSetIconName(
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
end_extern

begin_comment
comment|/* icon_name */
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
extern|extern XSetInputFocus(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* focus */
operator|,
extern|int
comment|/* revert_to */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XSetLineAttributes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned int
comment|/* line_width */
operator|,
extern|int
comment|/* line_style */
operator|,
extern|int
comment|/* cap_style */
operator|,
extern|int
end_extern

begin_comment
comment|/* join_style */
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
name|XSetModifierMapping
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XModifierKeymap
modifier|*
comment|/* modmap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetPlaneMask(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* plane_mask */
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
name|XSetPointerMapping
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|unsigned
name|char
modifier|*
comment|/* map */
parameter_list|,
name|int
comment|/* nmap */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XSetScreenSaver(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* timeout */
operator|,
extern|int
comment|/* interval */
operator|,
extern|int
comment|/* prefer_blanking */
operator|,
extern|int
end_extern

begin_comment
comment|/* allow_exposures */
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
extern|extern XSetSelectionOwner(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Atom
comment|/* selection */
operator|,
extern|Window
comment|/* owner */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XSetState(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|unsigned long
comment|/* foreground */
operator|,
extern|unsigned long
comment|/* background */
operator|,
extern|int
comment|/* function */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* plane_mask */
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
extern|extern XSetStipple(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* stipple */
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
extern|extern XSetSubwindowMode(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
end_extern

begin_comment
comment|/* subwindow_mode */
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
extern|extern XSetTSOrigin(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|int
comment|/* ts_x_origin */
operator|,
extern|int
end_extern

begin_comment
comment|/* ts_y_origin */
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
extern|extern XSetTile(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|GC
comment|/* gc */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* tile */
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
extern|extern XSetWindowBackground(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* background_pixel */
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
extern|extern XSetWindowBackgroundPixmap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* background_pixmap */
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
extern|extern XSetWindowBorder(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned long
end_extern

begin_comment
comment|/* border_pixel */
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
extern|extern XSetWindowBorderPixmap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Pixmap
end_extern

begin_comment
comment|/* border_pixmap */
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
extern|extern XSetWindowBorderWidth(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|unsigned int
end_extern

begin_comment
comment|/* width */
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
extern|extern XSetWindowColormap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|Colormap
end_extern

begin_comment
comment|/* colormap */
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
extern|extern XStoreBuffer(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|_Xconst char*
comment|/* bytes */
operator|,
extern|int
comment|/* nbytes */
operator|,
extern|int
end_extern

begin_comment
comment|/* buffer */
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
extern|extern XStoreBytes(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|_Xconst char*
comment|/* bytes */
operator|,
extern|int
end_extern

begin_comment
comment|/* nbytes */
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
extern|extern XStoreColor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|XColor*
end_extern

begin_comment
comment|/* color */
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
extern|extern XStoreColors(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|XColor*
comment|/* color */
operator|,
extern|int
end_extern

begin_comment
comment|/* ncolors */
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
extern|extern XStoreName(
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
end_extern

begin_comment
comment|/* window_name */
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
extern|extern XStoreNamedColor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
comment|/* colormap */
operator|,
extern|_Xconst char*
comment|/* color */
operator|,
extern|unsigned long
comment|/* pixel */
operator|,
extern|int
end_extern

begin_comment
comment|/* flags */
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
extern|extern XSync(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Bool
end_extern

begin_comment
comment|/* discard */
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
extern|extern XTextExtents(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XFontStruct*
comment|/* font_struct */
operator|,
extern|_Xconst char*
comment|/* string */
operator|,
extern|int
comment|/* nchars */
operator|,
extern|int*
comment|/* direction_return */
operator|,
extern|int*
comment|/* font_ascent_return */
operator|,
extern|int*
comment|/* font_descent_return */
operator|,
extern|XCharStruct*
end_extern

begin_comment
comment|/* overall_return */
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
extern|extern XTextExtents16(
if|#
directive|if
name|NeedFunctionPrototypes
extern|XFontStruct*
comment|/* font_struct */
operator|,
extern|_Xconst XChar2b*
comment|/* string */
operator|,
extern|int
comment|/* nchars */
operator|,
extern|int*
comment|/* direction_return */
operator|,
extern|int*
comment|/* font_ascent_return */
operator|,
extern|int*
comment|/* font_descent_return */
operator|,
extern|XCharStruct*
end_extern

begin_comment
comment|/* overall_return */
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
name|XTextWidth
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontStruct
modifier|*
comment|/* font_struct */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* string */
parameter_list|,
name|int
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XTextWidth16
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontStruct
modifier|*
comment|/* font_struct */
parameter_list|,
name|_Xconst
name|XChar2b
modifier|*
comment|/* string */
parameter_list|,
name|int
comment|/* count */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XTranslateCoordinates
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Window
comment|/* src_w */
parameter_list|,
name|Window
comment|/* dest_w */
parameter_list|,
name|int
comment|/* src_x */
parameter_list|,
name|int
comment|/* src_y */
parameter_list|,
name|int
modifier|*
comment|/* dest_x_return */
parameter_list|,
name|int
modifier|*
comment|/* dest_y_return */
parameter_list|,
name|Window
modifier|*
comment|/* child_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XUndefineCursor(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XUngrabButton(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|unsigned int
comment|/* button */
operator|,
extern|unsigned int
comment|/* modifiers */
operator|,
extern|Window
end_extern

begin_comment
comment|/* grab_window */
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
extern|extern XUngrabKey(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|int
comment|/* keycode */
operator|,
extern|unsigned int
comment|/* modifiers */
operator|,
extern|Window
end_extern

begin_comment
comment|/* grab_window */
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
extern|extern XUngrabKeyboard(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XUngrabPointer(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Time
end_extern

begin_comment
comment|/* time */
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
extern|extern XUngrabServer(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
end_extern

begin_comment
comment|/* display */
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
extern|extern XUninstallColormap(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Colormap
end_extern

begin_comment
comment|/* colormap */
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
extern|extern XUnloadFont(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Font
end_extern

begin_comment
comment|/* font */
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
extern|extern XUnmapSubwindows(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
extern|extern XUnmapWindow(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
end_extern

begin_comment
comment|/* w */
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
name|XVendorRelease
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XWarpPointer(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* src_w */
operator|,
extern|Window
comment|/* dest_w */
operator|,
extern|int
comment|/* src_x */
operator|,
extern|int
comment|/* src_y */
operator|,
extern|unsigned int
comment|/* src_width */
operator|,
extern|unsigned int
comment|/* src_height */
operator|,
extern|int
comment|/* dest_x */
operator|,
extern|int
end_extern

begin_comment
comment|/* dest_y */
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
name|XWidthMMOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XWidthOfScreen
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Screen
modifier|*
comment|/* screen */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_extern
extern|extern XWindowEvent(
if|#
directive|if
name|NeedFunctionPrototypes
extern|Display*
comment|/* display */
operator|,
extern|Window
comment|/* w */
operator|,
extern|long
comment|/* event_mask */
operator|,
extern|XEvent*
end_extern

begin_comment
comment|/* event_return */
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
name|XWriteBitmapFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* filename */
parameter_list|,
name|Pixmap
comment|/* bitmap */
parameter_list|,
name|unsigned
name|int
comment|/* width */
parameter_list|,
name|unsigned
name|int
comment|/* height */
parameter_list|,
name|int
comment|/* x_hot */
parameter_list|,
name|int
comment|/* y_hot */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XSupportsLocale
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
name|XSetLocaleModifiers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|_Xconst
name|char
modifier|*
comment|/* modifier_list */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XFontSet
name|XCreateFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* base_font_name_list */
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
comment|/* missing_charset_list */
parameter_list|,
name|int
modifier|*
comment|/* missing_charset_count */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* def_string */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XFreeFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|XFontSet
comment|/* font_set */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XFontsOfFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|XFontStruct
modifier|*
modifier|*
modifier|*
comment|/* font_struct_list */
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
comment|/* font_name_list */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XBaseFontNameListOfFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XLocaleOfFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XContextDependentDrawing
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XFontSetExtents
modifier|*
name|XExtentsOfFontSet
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmbTextEscapement
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* bytes_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XwcTextEscapement
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|wchar_t
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* num_wchars */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmbTextExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* bytes_text */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_ink_return */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_logical_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XwcTextExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|wchar_t
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* num_wchars */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_ink_return */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_logical_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XmbTextPerCharExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* bytes_text */
parameter_list|,
name|XRectangle
modifier|*
comment|/* ink_extents_buffer */
parameter_list|,
name|XRectangle
modifier|*
comment|/* logical_extents_buffer */
parameter_list|,
name|int
comment|/* buffer_size */
parameter_list|,
name|int
modifier|*
comment|/* num_chars */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_ink_return */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_logical_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XwcTextPerCharExtents
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
comment|/* font_set */
parameter_list|,
name|wchar_t
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* num_wchars */
parameter_list|,
name|XRectangle
modifier|*
comment|/* ink_extents_buffer */
parameter_list|,
name|XRectangle
modifier|*
comment|/* logical_extents_buffer */
parameter_list|,
name|int
comment|/* buffer_size */
parameter_list|,
name|int
modifier|*
comment|/* num_chars */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_ink_return */
parameter_list|,
name|XRectangle
modifier|*
comment|/* overall_logical_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbDrawText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|XmbTextItem
modifier|*
comment|/* text_items */
parameter_list|,
name|int
comment|/* nitems */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XwcDrawText
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|XwcTextItem
modifier|*
comment|/* text_items */
parameter_list|,
name|int
comment|/* nitems */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbDrawString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|XFontSet
comment|/* font_set */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* bytes_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XwcDrawString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|XFontSet
comment|/* font_set */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|wchar_t
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* num_wchars */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XmbDrawImageString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|XFontSet
comment|/* font_set */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|_Xconst
name|char
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* bytes_text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XwcDrawImageString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* display */
parameter_list|,
name|Drawable
comment|/* d */
parameter_list|,
name|XFontSet
comment|/* font_set */
parameter_list|,
name|GC
comment|/* gc */
parameter_list|,
name|int
comment|/* x */
parameter_list|,
name|int
comment|/* y */
parameter_list|,
name|wchar_t
modifier|*
comment|/* text */
parameter_list|,
name|int
comment|/* num_wchars */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XIM
name|XOpenIM
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|struct
name|_XrmHashBucketRec
modifier|*
comment|/* rdb */
parameter_list|,
name|char
modifier|*
comment|/* res_name */
parameter_list|,
name|char
modifier|*
comment|/* res_class */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Status
name|XCloseIM
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
comment|/* im */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XGetIMValues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XIM
comment|/* im */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Display
modifier|*
name|XDisplayOfIM
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
comment|/* im */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XLocaleOfIM
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
comment|/* im*/
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XIC
name|XCreateIC
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XIM
comment|/* im */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XDestroyIC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XSetICFocus
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XUnsetICFocus
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|wchar_t
modifier|*
name|XwcResetIC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XmbResetIC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XSetICValues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XIC
comment|/* ic */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|XGetICValues
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|XIC
comment|/* ic */
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XIM
name|XIMOfIC
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|XFilterEvent
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|Window
comment|/* window */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XmbLookupString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
parameter_list|,
name|XKeyPressedEvent
modifier|*
comment|/* event */
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
name|Status
modifier|*
comment|/* status_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XwcLookupString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
comment|/* ic */
parameter_list|,
name|XKeyPressedEvent
modifier|*
comment|/* event */
parameter_list|,
name|wchar_t
modifier|*
comment|/* buffer_return */
parameter_list|,
name|int
comment|/* wchars_buffer */
parameter_list|,
name|KeySym
modifier|*
comment|/* keysym_return */
parameter_list|,
name|Status
modifier|*
comment|/* status_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XVaNestedList
name|XVaCreateNestedList
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|int
comment|/*unused*/
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|_XFUNCPROTOEND
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XLIB_H_ */
end_comment

end_unit

