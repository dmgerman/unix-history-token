begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_XATOMTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_XATOMTYPE_H_
end_define

begin_comment
comment|/* $XConsortium: Xatomtype.h,v 11.14 89/04/19 15:09:29 jim Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * This files defines crock C structures for calling XGetWindowProperty and  * XChangeProperty.  All fields must be longs as the semantics of property  * routines will handle conversion to and from actual 32 bit objects.  If your  * compiler doesn't treat&structoflongs the same as&arrayoflongs[0], you  * will have some work to do.  */
end_comment

begin_define
define|#
directive|define
name|BOOL
value|long
end_define

begin_define
define|#
directive|define
name|SIGNEDINT
value|long
end_define

begin_define
define|#
directive|define
name|UNSIGNEDINT
value|unsigned long
end_define

begin_define
define|#
directive|define
name|RESOURCEID
value|unsigned long
end_define

begin_comment
comment|/* this structure may be extended, but do not change the order */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UNSIGNEDINT
name|flags
decl_stmt|;
name|SIGNEDINT
name|x
decl_stmt|,
name|y
decl_stmt|,
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* need to cvt; only for pre-ICCCM */
name|SIGNEDINT
name|minWidth
decl_stmt|,
name|minHeight
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|maxWidth
decl_stmt|,
name|maxHeight
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|widthInc
decl_stmt|,
name|heightInc
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|minAspectX
decl_stmt|,
name|minAspectY
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|maxAspectX
decl_stmt|,
name|maxAspectY
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|baseWidth
decl_stmt|,
name|baseHeight
decl_stmt|;
comment|/* need to cvt; ICCCM version 1 */
name|SIGNEDINT
name|winGravity
decl_stmt|;
comment|/* need to cvt; ICCCM version 1 */
block|}
name|xPropSizeHints
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OldNumPropSizeElements
value|15
end_define

begin_comment
comment|/* pre-ICCCM */
end_comment

begin_define
define|#
directive|define
name|NumPropSizeElements
value|18
end_define

begin_comment
comment|/* ICCCM version 1 */
end_comment

begin_comment
comment|/* this structure may be extended, but do not change the order */
end_comment

begin_comment
comment|/* RGB properties */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|RESOURCEID
name|colormap
decl_stmt|;
name|UNSIGNEDINT
name|red_max
decl_stmt|;
name|UNSIGNEDINT
name|red_mult
decl_stmt|;
name|UNSIGNEDINT
name|green_max
decl_stmt|;
name|UNSIGNEDINT
name|green_mult
decl_stmt|;
name|UNSIGNEDINT
name|blue_max
decl_stmt|;
name|UNSIGNEDINT
name|blue_mult
decl_stmt|;
name|UNSIGNEDINT
name|base_pixel
decl_stmt|;
name|RESOURCEID
name|visualid
decl_stmt|;
comment|/* ICCCM version 1 */
name|RESOURCEID
name|killid
decl_stmt|;
comment|/* ICCCM version 1 */
block|}
name|xPropStandardColormap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OldNumPropStandardColormapElements
value|8
end_define

begin_comment
comment|/* pre-ICCCM */
end_comment

begin_define
define|#
directive|define
name|NumPropStandardColormapElements
value|10
end_define

begin_comment
comment|/* ICCCM version 1 */
end_comment

begin_comment
comment|/* this structure may be extended, but do not change the order */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UNSIGNEDINT
name|flags
decl_stmt|;
name|BOOL
name|input
decl_stmt|;
comment|/* need to convert */
name|SIGNEDINT
name|initialState
decl_stmt|;
comment|/* need to cvt */
name|RESOURCEID
name|iconPixmap
decl_stmt|;
name|RESOURCEID
name|iconWindow
decl_stmt|;
name|SIGNEDINT
name|iconX
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|iconY
decl_stmt|;
comment|/* need to cvt */
name|RESOURCEID
name|iconMask
decl_stmt|;
name|UNSIGNEDINT
name|windowGroup
decl_stmt|;
block|}
name|xPropWMHints
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NumPropWMHintsElements
value|9
end_define

begin_comment
comment|/* number of elements in this structure */
end_comment

begin_comment
comment|/* this structure defines the icon size hints information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SIGNEDINT
name|minWidth
decl_stmt|,
name|minHeight
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|maxWidth
decl_stmt|,
name|maxHeight
decl_stmt|;
comment|/* need to cvt */
name|SIGNEDINT
name|widthInc
decl_stmt|,
name|heightInc
decl_stmt|;
comment|/* need to cvt */
block|}
name|xPropIconSize
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NumPropIconSizeElements
value|6
end_define

begin_comment
comment|/* number of elements in this structure */
end_comment

begin_comment
comment|/* this structure defines the window manager state information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|SIGNEDINT
name|state
decl_stmt|;
comment|/* need to cvt */
name|RESOURCEID
name|iconWindow
decl_stmt|;
block|}
name|xPropWMState
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NumPropWMStateElements
value|2
end_define

begin_comment
comment|/* number of elements in struct */
end_comment

begin_undef
undef|#
directive|undef
name|BOOL
end_undef

begin_undef
undef|#
directive|undef
name|SIGNEDINT
end_undef

begin_undef
undef|#
directive|undef
name|UNSIGNEDINT
end_undef

begin_undef
undef|#
directive|undef
name|RESOURCEID
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XATOMTYPE_H_ */
end_comment

end_unit

