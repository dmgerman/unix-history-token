begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Reports.h,v 1.3 90/02/28 18:46:46 jim Exp $  *  * Copyright 1990 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * M.I.T. DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL M.I.T.  * BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN   * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_Xaw_Reports_h
end_ifndef

begin_define
define|#
directive|define
name|_Xaw_Reports_h
end_define

begin_comment
comment|/*  * XawPannerReport - this structure is used by the reportCallback of the  * Panner, Porthole, Viewport, and Scrollbar widgets to report its position.  * All fields must be filled in, although the changed field may be used as  * a hint as to which fields have been altered since the last report.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|changed
decl_stmt|;
comment|/* mask, see below */
name|Position
name|slider_x
decl_stmt|,
name|slider_y
decl_stmt|;
comment|/* location of slider within outer */
name|Dimension
name|slider_width
decl_stmt|,
name|slider_height
decl_stmt|;
comment|/* size of slider */
name|Dimension
name|canvas_width
decl_stmt|,
name|canvas_height
decl_stmt|;
comment|/* size of canvas */
block|}
name|XawPannerReport
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XawPRSliderX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|XawPRSliderY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|XawPRSliderWidth
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|XawPRSliderHeight
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|XawPRCanvasWidth
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|XawPRCanvasHeight
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|XawPRAll
value|(63)
end_define

begin_comment
comment|/* union of above */
end_comment

begin_define
define|#
directive|define
name|XtNreportCallback
value|"reportCallback"
end_define

begin_define
define|#
directive|define
name|XtCReportCallback
value|"reportCallback"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _Xaw_Reports_h */
end_comment

end_unit

