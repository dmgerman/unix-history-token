begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: ClockP.h,v 1.21 90/10/22 14:43:22 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawClockP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawClockP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xos.h>
end_include

begin_comment
comment|/* Needed for struct tm. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/Clock.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_define
define|#
directive|define
name|SEG_BUFF_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|ASCII_TIME_BUFLEN
value|32
end_define

begin_comment
comment|/* big enough for 26 plus slop */
end_comment

begin_comment
comment|/* New fields for the clock widget instance record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pixel
name|fgpixel
decl_stmt|;
comment|/* color index for text */
name|Pixel
name|Hipixel
decl_stmt|;
comment|/* color index for Highlighting */
name|Pixel
name|Hdpixel
decl_stmt|;
comment|/* color index for hands */
name|XFontStruct
modifier|*
name|font
decl_stmt|;
comment|/* font for text */
name|GC
name|myGC
decl_stmt|;
comment|/* pointer to GraphicsContext */
name|GC
name|EraseGC
decl_stmt|;
comment|/* eraser GC */
name|GC
name|HandGC
decl_stmt|;
comment|/* Hand GC */
name|GC
name|HighGC
decl_stmt|;
comment|/* Highlighting GC */
comment|/* start of graph stuff */
name|int
name|update
decl_stmt|;
comment|/* update frequence */
name|Dimension
name|radius
decl_stmt|;
comment|/* radius factor */
name|int
name|backing_store
decl_stmt|;
comment|/* backing store type */
name|Boolean
name|chime
decl_stmt|;
name|Boolean
name|beeped
decl_stmt|;
name|Boolean
name|analog
decl_stmt|;
name|Boolean
name|show_second_hand
decl_stmt|;
name|Dimension
name|second_hand_length
decl_stmt|;
name|Dimension
name|minute_hand_length
decl_stmt|;
name|Dimension
name|hour_hand_length
decl_stmt|;
name|Dimension
name|hand_width
decl_stmt|;
name|Dimension
name|second_hand_width
decl_stmt|;
name|Position
name|centerX
decl_stmt|;
name|Position
name|centerY
decl_stmt|;
name|int
name|numseg
decl_stmt|;
name|int
name|padding
decl_stmt|;
name|XPoint
name|segbuff
index|[
name|SEG_BUFF_SIZE
index|]
decl_stmt|;
name|XPoint
modifier|*
name|segbuffptr
decl_stmt|;
name|XPoint
modifier|*
name|hour
decl_stmt|,
modifier|*
name|sec
decl_stmt|;
name|struct
name|tm
name|otm
decl_stmt|;
name|XtIntervalId
name|interval_id
decl_stmt|;
name|char
name|prev_time_string
index|[
name|ASCII_TIME_BUFLEN
index|]
decl_stmt|;
block|}
name|ClockPart
typedef|;
end_typedef

begin_comment
comment|/* Full instance record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ClockRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|ClockPart
name|clock
decl_stmt|;
block|}
name|ClockRec
typedef|;
end_typedef

begin_comment
comment|/* New fields for the Clock widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dummy
decl_stmt|;
block|}
name|ClockClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ClockClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|ClockClassPart
name|clock_class
decl_stmt|;
block|}
name|ClockClassRec
typedef|;
end_typedef

begin_comment
comment|/* Class pointer. */
end_comment

begin_decl_stmt
specifier|extern
name|ClockClassRec
name|clockClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawClockP_h */
end_comment

end_unit

