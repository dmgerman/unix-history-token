begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: XIMproto.h,v 1.4 91/06/05 08:24:13 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON and MIT not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission.  OMRON and MIT make no representations  * about the suitability of this software for any purpose.  It is provided  * "as is" without express or implied warranty.  *  * OMRON AND MIT DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL OMRON OR MIT BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.   *  *	Author:	Seiji Kuwari	OMRON Corporation  *				kuwa@omron.co.jp  *				kuwa%omron.co.jp@uunet.uu.net  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XIMPROTO_H
end_ifndef

begin_define
define|#
directive|define
name|XIMPROTO_H
end_define

begin_include
include|#
directive|include
file|<X11/Xmd.h>
end_include

begin_comment
comment|/*  * Define constants for the sizes of the network packets.  The sz_ prefix is  * used instead of something more descriptive so that the symbols are no more  * than 32 characters in length (which causes problems for some compilers).  */
end_comment

begin_define
define|#
directive|define
name|XIM_MAJOR_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|XIM_MINOR_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|sz_ximRequestHeader
value|4
end_define

begin_define
define|#
directive|define
name|sz_ximNormalReply
value|4
end_define

begin_define
define|#
directive|define
name|sz_ximConnClient
value|4
end_define

begin_define
define|#
directive|define
name|sz_ximGetIMReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximGetIMReply
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximCreateICReq
value|4
end_define

begin_define
define|#
directive|define
name|sz_ximCreateICReply
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximChangeICReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximChangeICReply
value|sz_ximNormalReply
end_define

begin_define
define|#
directive|define
name|sz_ximGetICReq
value|12
end_define

begin_define
define|#
directive|define
name|sz_ximGetICReply
value|sz_ximNormalReply
end_define

begin_define
define|#
directive|define
name|sz_ximICValuesReq
value|28
end_define

begin_define
define|#
directive|define
name|sz_ximICAttributesReq
value|48
end_define

begin_define
define|#
directive|define
name|sz_ximDestroyICReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximICFocusReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximResetICReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximEventReq
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximEventReply
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximReturnReply
value|8
end_define

begin_comment
comment|/* For Callback */
end_comment

begin_define
define|#
directive|define
name|sz_ximPreDrawReply
value|16
end_define

begin_define
define|#
directive|define
name|sz_ximPreCaretReply
value|8
end_define

begin_define
define|#
directive|define
name|sz_ximStatusDrawReply
value|12
end_define

begin_define
define|#
directive|define
name|Window
value|CARD32
end_define

begin_define
define|#
directive|define
name|Atom
value|CARD32
end_define

begin_define
define|#
directive|define
name|Colormap
value|CARD32
end_define

begin_define
define|#
directive|define
name|Pixmap
value|CARD32
end_define

begin_define
define|#
directive|define
name|Cursor
value|CARD32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 4 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|ximRequestHeader
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 4 */
name|CARD16
name|state
name|B16
decl_stmt|;
name|CARD16
name|detail
name|B16
decl_stmt|;
block|}
name|ximNormalReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 4 */
name|CARD8
name|byteOrder
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|ximConnClient
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|mask
name|B32
decl_stmt|;
block|}
name|ximGetIMReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD16
name|state
name|B16
decl_stmt|;
name|INT16
name|num_styles
name|B16
decl_stmt|;
name|INT16
name|nbytes
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
block|}
name|ximGetIMReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 4 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
block|}
name|ximCreateICReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD16
name|state
name|B16
decl_stmt|;
name|CARD16
name|detail
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximCreateICReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximChangeICReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ximNormalReply
name|ximChangeICReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 12 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
name|CARD32
name|mask
name|B32
decl_stmt|;
block|}
name|ximGetICReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ximNormalReply
name|ximGetICReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 28 */
name|CARD32
name|mask
name|B32
decl_stmt|;
name|INT32
name|input_style
name|B32
decl_stmt|;
name|Window
name|c_window
name|B32
decl_stmt|;
name|Window
name|focus_window
name|B32
decl_stmt|;
name|CARD32
name|filter_events
name|B32
decl_stmt|;
name|INT32
name|max_keycode
name|B32
decl_stmt|;
name|INT16
name|nbytes
name|B16
decl_stmt|;
name|INT16
name|nbytes2
name|B16
decl_stmt|;
block|}
name|ximICValuesReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 48 */
name|INT16
name|area_x
name|B16
decl_stmt|,
name|area_y
name|B16
decl_stmt|;
name|CARD16
name|area_width
name|B16
decl_stmt|,
name|area_height
name|B16
decl_stmt|;
name|CARD16
name|areaneeded_width
name|B16
decl_stmt|,
name|areaneeded_height
name|B16
decl_stmt|;
name|INT16
name|spot_x
name|B16
decl_stmt|,
name|spot_y
name|B16
decl_stmt|;
name|Colormap
name|colormap
name|B32
decl_stmt|;
name|Atom
name|std_colormap
name|B32
decl_stmt|;
name|CARD32
name|foreground
name|B32
decl_stmt|,
name|background
name|B32
decl_stmt|;
name|Pixmap
name|pixmap
name|B32
decl_stmt|;
name|INT16
name|line_space
name|B16
decl_stmt|;
name|CARD16
name|pad1
name|B16
decl_stmt|;
name|Cursor
name|cursor
name|B32
decl_stmt|;
name|CARD16
name|nfonts
name|B16
decl_stmt|;
name|INT16
name|nbytes
name|B16
decl_stmt|;
block|}
name|ximICAttributesReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximDestroyICReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximICFocusReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximResetICReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD8
name|reqType
decl_stmt|;
name|BYTE
name|pad
decl_stmt|;
name|CARD16
name|length
name|B16
decl_stmt|;
name|CARD32
name|xic
name|B32
decl_stmt|;
block|}
name|ximEventReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD16
name|state
name|B16
decl_stmt|;
name|CARD16
name|detail
name|B16
decl_stmt|;
name|INT16
name|number
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
block|}
name|ximEventReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|CARD16
name|type
name|B16
decl_stmt|;
name|INT16
name|length
name|B16
decl_stmt|;
name|KeySym
name|keysym
name|B32
decl_stmt|;
block|}
name|ximReturnReply
typedef|;
end_typedef

begin_comment
comment|/* For Callback */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 16 */
name|INT16
name|caret
name|B16
decl_stmt|;
name|INT16
name|chg_first
name|B16
decl_stmt|;
name|INT16
name|chg_length
name|B16
decl_stmt|;
name|INT16
name|encoding_is_wchar
name|B16
decl_stmt|;
name|INT16
name|length
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
name|INT32
name|feedback
name|B32
decl_stmt|;
block|}
name|ximPreDrawReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 8 */
name|INT16
name|position
name|B16
decl_stmt|;
name|CARD16
name|direction
name|B16
decl_stmt|;
name|CARD16
name|style
name|B16
decl_stmt|;
name|CARD16
name|pad
name|B16
decl_stmt|;
block|}
name|ximPreCaretReply
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 12 */
name|CARD16
name|type
name|B16
decl_stmt|;
name|INT16
name|encoding_is_wchar
name|B16
decl_stmt|;
name|INT16
name|length
name|B16
decl_stmt|;
name|INT16
name|feedback
name|B16
decl_stmt|;
name|Pixmap
name|bitmap
name|B32
decl_stmt|;
block|}
name|ximStatusDrawReply
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XIM_GetIM
value|1
end_define

begin_define
define|#
directive|define
name|XIM_CreateIC
value|2
end_define

begin_define
define|#
directive|define
name|XIM_ChangeIC
value|3
end_define

begin_define
define|#
directive|define
name|XIM_GetIC
value|4
end_define

begin_define
define|#
directive|define
name|XIM_DestroyIC
value|5
end_define

begin_define
define|#
directive|define
name|XIM_SetICFocus
value|6
end_define

begin_define
define|#
directive|define
name|XIM_UnsetICFocus
value|7
end_define

begin_define
define|#
directive|define
name|XIM_ResetIC
value|8
end_define

begin_define
define|#
directive|define
name|XIM_Event
value|9
end_define

begin_define
define|#
directive|define
name|XIM_NOTHING
value|1
end_define

begin_define
define|#
directive|define
name|XIM_NOFILTER
value|2
end_define

begin_define
define|#
directive|define
name|XIM_RETURN
value|3
end_define

begin_define
define|#
directive|define
name|XIM_CALLBACK
value|4
end_define

begin_define
define|#
directive|define
name|XIM_IC
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XML
end_ifdef

begin_define
define|#
directive|define
name|XIM_CH_LOCALE
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XML */
end_comment

begin_define
define|#
directive|define
name|XIM_STRING
value|(short)1
end_define

begin_define
define|#
directive|define
name|XIM_KEYSYM
value|(short)2
end_define

begin_comment
comment|/* For Callback */
end_comment

begin_define
define|#
directive|define
name|XIM_CB_PRE_START
value|1
end_define

begin_define
define|#
directive|define
name|XIM_CB_PRE_DONE
value|2
end_define

begin_define
define|#
directive|define
name|XIM_CB_PRE_DRAW
value|3
end_define

begin_define
define|#
directive|define
name|XIM_CB_PRE_CARET
value|4
end_define

begin_define
define|#
directive|define
name|XIM_CB_ST_START
value|5
end_define

begin_define
define|#
directive|define
name|XIM_CB_ST_DONE
value|6
end_define

begin_define
define|#
directive|define
name|XIM_CB_ST_DRAW
value|7
end_define

begin_define
define|#
directive|define
name|XIM_CB_FW_CHAR
value|1
end_define

begin_define
define|#
directive|define
name|XIM_CB_BW_CHAR
value|2
end_define

begin_define
define|#
directive|define
name|XIM_CB_FW_WORD
value|3
end_define

begin_define
define|#
directive|define
name|XIM_CB_BW_WORD
value|4
end_define

begin_define
define|#
directive|define
name|XIM_CB_CARET_UP
value|5
end_define

begin_define
define|#
directive|define
name|XIM_CB_CARET_DOWN
value|6
end_define

begin_define
define|#
directive|define
name|XIM_CB_NEXT_LINE
value|7
end_define

begin_define
define|#
directive|define
name|XIM_CB_PREV_LINE
value|8
end_define

begin_define
define|#
directive|define
name|XIM_CB_LINE_START
value|9
end_define

begin_define
define|#
directive|define
name|XIM_CB_LINE_END
value|10
end_define

begin_define
define|#
directive|define
name|XIM_CB_ABS_POS
value|11
end_define

begin_define
define|#
directive|define
name|XIM_CB_DONT_CHANGE
value|12
end_define

begin_define
define|#
directive|define
name|XIM_ST_TEXT
value|1
end_define

begin_define
define|#
directive|define
name|XIM_ST_BITMAP
value|2
end_define

begin_undef
undef|#
directive|undef
name|Window
end_undef

begin_undef
undef|#
directive|undef
name|Atom
end_undef

begin_undef
undef|#
directive|undef
name|Colormap
end_undef

begin_undef
undef|#
directive|undef
name|Pixmap
end_undef

begin_undef
undef|#
directive|undef
name|Cursor
end_undef

begin_define
define|#
directive|define
name|_Read
parameter_list|(
name|fd
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
value|read((fd), (data), (size))
end_define

begin_define
define|#
directive|define
name|_Write
parameter_list|(
name|fd
parameter_list|,
name|data
parameter_list|,
name|size
parameter_list|)
value|write((fd), (data), (size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XIMPROTO_H */
end_comment

end_unit

