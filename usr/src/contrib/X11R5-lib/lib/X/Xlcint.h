begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Xlcint.h,v 11.14 92/04/14 15:42:59 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation, NTT Software Corporation,  *                      and Nippon Telegraph and Telephone Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  * Copyright 1991 by the Open Software Foundation  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON, NTT Software, NTT, Open  * Software Foundation and M.I.T. not be used in advertising or   * publicity pertaining to distribution of the software without specific,   * written prior permission. OMRON, NTT Software, NTT, Open Software  * Foundation and M.I.T. make no representations about the suitability of this  * software for any purpose.  It is provided "as is" without express or  * implied warranty.  *  * OMRON, NTT SOFTWARE, NTT, OPEN SOFTWARE FOUNDATION AND M.I.T.   * DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING   * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT   * SHALL OMRON, NTT SOFTWARE, NTT, OPEN SOFTWARE FOUNDATIONN OR M.I.T. BE  * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   *	Authors: Li Yuhong		OMRON Corporation  *		 Tatsuya Kato		NTT Software Corporation  *		 Hiroshi Kuribayashi	OMRON Coproration  *		 Muneiyoshi Suzuki	Nippon Telegraph and Telephone Co.  *   *		 M. Collins		OSF    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XLCINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_XLCINT_H_
end_define

begin_include
include|#
directive|include
file|<X11/Xresource.h>
end_include

begin_comment
comment|/* current Ultrix compiler gets horribly confused */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FUNCPROTO
argument_list|)
operator|&&
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|NeedFunctionPrototypes
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_XIMFilter
block|{
name|struct
name|_XIMFilter
modifier|*
name|next
decl_stmt|;
name|Window
name|window
decl_stmt|;
name|unsigned
name|long
name|event_mask
decl_stmt|;
name|int
name|start_type
decl_stmt|,
name|end_type
decl_stmt|;
name|Bool
function_decl|(
modifier|*
name|filter
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|Window
parameter_list|,
name|XEvent
modifier|*
parameter_list|,
name|XPointer
endif|#
directive|endif
parameter_list|)
function_decl|;
name|XPointer
name|client_data
decl_stmt|;
block|}
name|XFilterEventRec
operator|,
typedef|*
name|XFilterEventList
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|offsetof
end_ifdef

begin_define
define|#
directive|define
name|XOffsetOf
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|offsetof(s_type,field)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XOffsetOf
parameter_list|(
name|s_type
parameter_list|,
name|field
parameter_list|)
value|((unsigned int)&(((s_type*)NULL)->field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XIMNumber
parameter_list|(
name|arr
parameter_list|)
value|((unsigned int) (sizeof(arr) / sizeof(arr[0])))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|XPointer
name|value
decl_stmt|;
block|}
name|XIMArg
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ICInputStyle
value|0
end_define

begin_define
define|#
directive|define
name|ICClientWindow
value|1
end_define

begin_define
define|#
directive|define
name|ICFocusWindow
value|2
end_define

begin_define
define|#
directive|define
name|ICFilterEvents
value|3
end_define

begin_define
define|#
directive|define
name|ICArea
value|4
end_define

begin_define
define|#
directive|define
name|ICAreaNeeded
value|5
end_define

begin_define
define|#
directive|define
name|ICSpotLocation
value|6
end_define

begin_define
define|#
directive|define
name|ICColormap
value|7
end_define

begin_define
define|#
directive|define
name|ICStdColormap
value|8
end_define

begin_define
define|#
directive|define
name|ICForeground
value|9
end_define

begin_define
define|#
directive|define
name|ICBackground
value|10
end_define

begin_define
define|#
directive|define
name|ICBackgroundPixmap
value|11
end_define

begin_define
define|#
directive|define
name|ICFontSet
value|12
end_define

begin_define
define|#
directive|define
name|ICLineSpace
value|13
end_define

begin_define
define|#
directive|define
name|ICCursor
value|14
end_define

begin_define
define|#
directive|define
name|ICResourceClass
value|26
end_define

begin_define
define|#
directive|define
name|ICResourceName
value|27
end_define

begin_define
define|#
directive|define
name|IMQueryInputStyle
value|0
end_define

begin_define
define|#
directive|define
name|IMResourceWrite
value|1
end_define

begin_define
define|#
directive|define
name|IMResourceRead
value|2
end_define

begin_define
define|#
directive|define
name|IMResourceReadWrite
value|3
end_define

begin_comment
comment|/*  * define secondary data structs which are part of Input methods  * and input context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XrmQuark
name|xrm_name
decl_stmt|;
comment|/* Resource name quark */
name|int
name|xrm_size
decl_stmt|;
comment|/* Size in bytes of data */
name|long
name|xrm_offset
decl_stmt|;
comment|/* -offset-1 */
name|unsigned
name|short
name|mode
decl_stmt|;
comment|/* Read Write Permission */
name|int
name|mask
decl_stmt|;
comment|/* ? */
block|}
name|XIMrmResource
operator|,
typedef|*
name|XIMrmResourceList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|resource_name
decl_stmt|;
comment|/* Resource string */
name|int
name|resource_size
decl_stmt|;
comment|/* Size in bytes of data */
name|long
name|resource_offset
decl_stmt|;
comment|/* -offset-1 */
name|unsigned
name|short
name|mode
decl_stmt|;
comment|/* Read Write Permission */
name|int
name|mask
decl_stmt|;
comment|/* ? */
block|}
name|XIMResource
operator|,
typedef|*
name|XIMResourceList
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|XIMCallback
name|start
decl_stmt|;
name|XIMCallback
name|done
decl_stmt|;
name|XIMCallback
name|draw
decl_stmt|;
name|XIMCallback
name|caret
decl_stmt|;
block|}
name|ICCallbacks
typedef|;
end_typedef

begin_comment
comment|/*  * data block describing the visual attributes associated with  * an input context  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XRectangle
name|area
decl_stmt|;
name|XRectangle
name|area_needed
decl_stmt|;
name|XPoint
name|spot_location
decl_stmt|;
name|Colormap
name|colormap
decl_stmt|;
name|Atom
name|std_colormap
decl_stmt|;
name|unsigned
name|long
name|foreground
decl_stmt|;
name|unsigned
name|long
name|background
decl_stmt|;
name|Pixmap
name|background_pixmap
decl_stmt|;
name|XFontSet
name|fontset
decl_stmt|;
name|int
name|line_space
decl_stmt|;
name|Cursor
name|cursor
decl_stmt|;
name|ICCallbacks
name|callbacks
decl_stmt|;
block|}
name|ICAttributes
operator|,
typedef|*
name|ICAttributesPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_XLCd
modifier|*
name|XLCd
typedef|;
end_typedef

begin_comment
comment|/* need forward reference */
end_comment

begin_comment
comment|/*  * define an LC, it's methods, and data.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
function_decl|(
modifier|*
name|map_modifiers
function_decl|)
parameter_list|(
comment|/* called by XSetModifiers */
if|#
directive|if
name|NeedFunctionPrototypes
name|XLCd
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|XFontSet
function_decl|(
modifier|*
name|create_fontset
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XLCd
parameter_list|,
name|Display
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|,
name|int
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|XIM
function_decl|(
modifier|*
name|open_im
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XLCd
parameter_list|,
name|Display
modifier|*
parameter_list|,
name|XrmDatabase
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
block|}
name|XLCdMethodsRec
operator|,
typedef|*
name|XLCdMethods
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name of this LC */
name|char
modifier|*
name|modifiers
decl_stmt|;
comment|/* modifiers of locale */
block|}
name|XLCdCoreRec
operator|,
typedef|*
name|XLCdCore
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XLCd
block|{
name|XLCdMethods
name|methods
decl_stmt|;
comment|/* methods of this LC */
name|XLCdCoreRec
name|core
decl_stmt|;
comment|/* data of this LC */
block|}
name|XLCdRec
typedef|;
end_typedef

begin_comment
comment|/*  * X Font Sets are an instantiable object, so we define it, the   * object itself, a method list and data  */
end_comment

begin_comment
comment|/*   * XFontSet object method list  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* pure font methods */
name|void
function_decl|(
modifier|*
name|free
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|XFontSet
endif|#
directive|endif
parameter_list|)
function_decl|;
comment|/* multi-byte text drawing methods */
name|int
function_decl|(
modifier|*
name|mb_escapement
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mb_extents
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|Status
function_decl|(
modifier|*
name|mb_extents_per_char
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mb_draw_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|Drawable
parameter_list|,
name|XFontSet
parameter_list|,
name|GC
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mb_draw_image_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|Drawable
parameter_list|,
name|XFontSet
parameter_list|,
name|GC
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
comment|/* wide character text drawing methods */
name|int
function_decl|(
modifier|*
name|wc_escapement
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wc_extents
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|Status
function_decl|(
modifier|*
name|wc_extents_per_char
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XFontSet
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|XRectangle
modifier|*
parameter_list|,
name|XRectangle
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wc_draw_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|Drawable
parameter_list|,
name|XFontSet
parameter_list|,
name|GC
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|wc_draw_image_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
parameter_list|,
name|Drawable
parameter_list|,
name|XFontSet
parameter_list|,
name|GC
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
endif|#
directive|endif
parameter_list|)
function_decl|;
block|}
name|XFontSetMethodsRec
operator|,
typedef|*
name|XFontSetMethods
typedef|;
end_typedef

begin_comment
comment|/*  * XFontSet LC independent data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XLCd
name|lcd
decl_stmt|;
comment|/* LC of this font set */
name|char
modifier|*
name|base_name_list
decl_stmt|;
comment|/* base font name list */
name|int
name|num_of_fonts
decl_stmt|;
comment|/* number of fonts */
name|char
modifier|*
modifier|*
name|font_name_list
decl_stmt|;
comment|/* font names list */
name|XFontStruct
modifier|*
modifier|*
name|font_struct_list
decl_stmt|;
comment|/* font struct list */
name|XFontSetExtents
name|font_set_extents
decl_stmt|;
comment|/* font set extents */
name|char
modifier|*
name|default_string
decl_stmt|;
comment|/* default string */
name|Bool
name|context_dependent
decl_stmt|;
comment|/* context-dependent drawing */
block|}
name|XFontSetCoreRec
operator|,
typedef|*
name|XFontSetCore
typedef|;
end_typedef

begin_comment
comment|/*  * An XFontSet.  Implementations may need to extend this data structure to  * accomodate additional data, state information etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XFontSet
block|{
name|XFontSetMethods
name|methods
decl_stmt|;
comment|/* methods of this font set */
name|XFontSetCoreRec
name|core
decl_stmt|;
comment|/* data of this font set */
block|}
name|XFontSetRec
typedef|;
end_typedef

begin_comment
comment|/*  * X Input Managers are an instantiable object, so we define it, the   * object itself, a method list and data.  */
end_comment

begin_comment
comment|/*  * an Input Manager object method list  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Status
function_decl|(
modifier|*
name|close
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|get_values
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
parameter_list|,
name|XIMArg
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|XIC
function_decl|(
modifier|*
name|create_ic
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIM
parameter_list|,
name|XIMArg
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
block|}
name|XIMMethodsRec
operator|,
typedef|*
name|XIMMethods
typedef|;
end_typedef

begin_comment
comment|/*  * Input Manager LC independent data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XLCd
name|lcd
decl_stmt|;
comment|/* LC of this input method */
name|XIC
name|ic_chain
decl_stmt|;
comment|/* list of ICs for this IM */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* display */
name|XrmDatabase
name|rdb
decl_stmt|;
name|char
modifier|*
name|res_name
decl_stmt|;
name|char
modifier|*
name|res_class
decl_stmt|;
name|XIMrmResourceList
name|ic_resources
decl_stmt|;
comment|/* compiled IC resource list */
name|unsigned
name|int
name|ic_num_resources
decl_stmt|;
name|XIMrmResourceList
name|ic_attr_resources
decl_stmt|;
comment|/* compiled IC visual res */
name|unsigned
name|int
name|ic_num_attr_resources
decl_stmt|;
block|}
name|XIMCoreRec
operator|,
typedef|*
name|XIMCore
typedef|;
end_typedef

begin_comment
comment|/*  * An X Input Manager (IM).  Implementations may need to extend this data   * structure to accomodate additional data, state information etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XIM
block|{
name|XIMMethods
name|methods
decl_stmt|;
comment|/* method list of this IM */
name|XIMCoreRec
name|core
decl_stmt|;
comment|/* data of this IM */
block|}
name|XIMRec
typedef|;
end_typedef

begin_comment
comment|/*  * X Input Contexts (IC) are an instantiable object, so we define it, the   * object itself, a method list and data for this object  */
end_comment

begin_comment
comment|/*  * Input Context method list  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_focus
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|unset_focus
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|set_values
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
parameter_list|,
name|XIMArg
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|get_values
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
parameter_list|,
name|XIMArg
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|mb_reset
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
endif|#
directive|endif
parameter_list|)
function_decl|;
name|wchar_t
modifier|*
function_decl|(
modifier|*
name|wc_reset
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mb_lookup_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
parameter_list|,
name|XKeyEvent
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|KeySym
modifier|*
parameter_list|,
name|Status
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wc_lookup_string
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIC
parameter_list|,
name|XKeyEvent
modifier|*
parameter_list|,
name|wchar_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|KeySym
modifier|*
parameter_list|,
name|Status
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
block|}
name|XICMethodsRec
operator|,
typedef|*
name|XICMethods
typedef|;
end_typedef

begin_comment
comment|/*  * Input Context LC independent data  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XIM
name|im
decl_stmt|;
comment|/* XIM this IC belongs too */
name|XIC
name|next
decl_stmt|;
comment|/* linked list of ICs for IM */
name|Window
name|client_window
decl_stmt|;
comment|/* window IM can use for */
comment|/* display or subwindows */
name|XIMStyle
name|input_style
decl_stmt|;
comment|/* IM's input style */
name|Window
name|focus_window
decl_stmt|;
comment|/* where key events go */
name|XrmDatabase
name|res_database
decl_stmt|;
comment|/* where IM gets resources */
name|char
modifier|*
name|string_database
decl_stmt|;
comment|/* string for IM's resources */
name|XIMCallback
name|geometry_callback
decl_stmt|;
comment|/* client callback */
name|int
name|preedit_state
decl_stmt|;
comment|/*  */
name|unsigned
name|long
name|filter_events
decl_stmt|;
comment|/* event mask from IM */
name|ICAttributes
name|preedit_attr
decl_stmt|;
comment|/* visuals of preedit area */
name|ICAttributes
name|status_attr
decl_stmt|;
comment|/* visuals of status area */
block|}
name|XICCoreRec
operator|,
typedef|*
name|XICCore
typedef|;
end_typedef

begin_comment
comment|/*  * an Input Context.  Implementations may need to extend this data   * structure to accomodate additional data, state information etc.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XIC
block|{
name|XICMethods
name|methods
decl_stmt|;
comment|/* method list of this IC */
name|XICCoreRec
name|core
decl_stmt|;
comment|/* data of this IC */
block|}
name|XICRec
typedef|;
end_typedef

begin_comment
comment|/*  * Methods for Xrm parsing  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|mbinit
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* state */
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
function_decl|(
modifier|*
name|mbchar
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* state */
parameter_list|,
name|char
modifier|*
comment|/* str */
parameter_list|,
name|int
modifier|*
comment|/* lenp */
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mbfinish
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* state */
endif|#
directive|endif
parameter_list|)
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|lcname
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* state */
endif|#
directive|endif
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* state */
endif|#
directive|endif
parameter_list|)
function_decl|;
block|}
name|XrmMethodsRec
operator|,
typedef|*
name|XrmMethods
typedef|;
end_typedef

begin_comment
comment|/* current Ultrix compiler gets horribly confused */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NeedFunctionPrototypes
argument_list|)
operator|&&
name|defined
argument_list|(
name|FUNCPROTO
argument_list|)
end_if

begin_define
define|#
directive|define
name|NeedFunctionPrototypes
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|XLCd
function_decl|(
modifier|*
name|XLCdLoadProc
function_decl|)
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
endif|#
directive|endif
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|_XFUNCPROTOBEGIN
specifier|extern
name|XLCd
name|_XlcCurrentLC
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
name|Bool
name|_XlcValidModSyntax
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* mods */
parameter_list|,
name|char
modifier|*
modifier|*
comment|/* valid */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|_XlcDefaultMapModifiers
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XLCd
comment|/* lcd */
parameter_list|,
name|char
modifier|*
comment|/* user_mods */
parameter_list|,
name|char
modifier|*
comment|/* prog_mods */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XIMCompileResourceList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XIMResourceList
comment|/* res */
parameter_list|,
name|unsigned
name|int
comment|/* num_res */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XCopyToArg
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
comment|/* src */
parameter_list|,
name|XPointer
modifier|*
comment|/* dst */
parameter_list|,
name|unsigned
name|int
comment|/* size */
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
name|_XParseBaseFontNameList
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|char
modifier|*
comment|/* str */
parameter_list|,
name|int
modifier|*
comment|/* num */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|XrmMethods
name|_XrmInitParseInfo
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|XPointer
modifier|*
comment|/* statep */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XRegisterFilterByMask
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|unsigned
name|long
comment|/* event_mask */
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
name|Window
comment|/* window */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
comment|/* filter */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XRegisterFilterByType
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
parameter_list|,
name|int
comment|/* start_type */
parameter_list|,
name|int
comment|/* end_type */
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
name|Window
comment|/* window */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
comment|/* filter */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_XUnregisterFilter
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Display
modifier|*
comment|/* dpy */
parameter_list|,
name|Window
comment|/* window */
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
name|Window
comment|/* window */
parameter_list|,
name|XEvent
modifier|*
comment|/* event */
parameter_list|,
name|XPointer
comment|/* client_data */
endif|#
directive|endif
parameter_list|)
comment|/* filter */
parameter_list|,
name|XPointer
comment|/* client_data */
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
comment|/* _XLCINT_H_ */
end_comment

end_unit

