begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: StripCharP.h,v 1.4 90/10/22 14:38:15 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawStripChartP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawStripChartP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/StripChart.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_define
define|#
directive|define
name|NO_GCS
value|0
end_define

begin_define
define|#
directive|define
name|FOREGROUND
value|1<< 0
end_define

begin_define
define|#
directive|define
name|HIGHLIGHT
value|1<< 1
end_define

begin_define
define|#
directive|define
name|ALL_GCS
value|(FOREGROUND | HIGHLIGHT)
end_define

begin_comment
comment|/* New fields for the stripChart widget instance record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pixel
name|fgpixel
decl_stmt|;
comment|/* color index for graph */
name|Pixel
name|hipixel
decl_stmt|;
comment|/* color index for lines */
name|GC
name|fgGC
decl_stmt|;
comment|/* graphics context for fgpixel */
name|GC
name|hiGC
decl_stmt|;
comment|/* graphics context for hipixel */
comment|/* start of graph stuff */
name|int
name|update
decl_stmt|;
comment|/* update frequence */
name|int
name|scale
decl_stmt|;
comment|/* scale factor */
name|int
name|min_scale
decl_stmt|;
comment|/* smallest scale factor */
name|int
name|interval
decl_stmt|;
comment|/* data point interval */
name|XPoint
modifier|*
name|points
decl_stmt|;
comment|/* Poly point for repairing graph lines. */
name|double
name|max_value
decl_stmt|;
comment|/* Max Value in window */
name|double
name|valuedata
index|[
literal|2048
index|]
decl_stmt|;
comment|/* record of data points */
name|XtIntervalId
name|interval_id
decl_stmt|;
name|XtCallbackList
name|get_value
decl_stmt|;
comment|/* proc to call to fetch load pt */
name|int
name|jump_val
decl_stmt|;
comment|/* Amount to jump on each scroll. */
block|}
name|StripChartPart
typedef|;
end_typedef

begin_comment
comment|/* Full instance record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_StripChartRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|StripChartPart
name|strip_chart
decl_stmt|;
block|}
name|StripChartRec
typedef|;
end_typedef

begin_comment
comment|/* New fields for the StripChart widget class record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dummy
decl_stmt|;
block|}
name|StripChartClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_StripChartClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|StripChartClassPart
name|strip_chart_class
decl_stmt|;
block|}
name|StripChartClassRec
typedef|;
end_typedef

begin_comment
comment|/* Class pointer. */
end_comment

begin_decl_stmt
specifier|extern
name|StripChartClassRec
name|stripChartClassRec
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawStripChartP_h */
end_comment

end_unit

