begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: AsciiTextP.h,v 1.15 89/07/17 18:09:37 kit Exp $   */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/***********************************************************************  *  * AsciiText Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/*  * AsciiText.c - Private header file for AsciiText Widget.  *  * This Widget is intended to be used as a simple front end to the   * text widget with an ascii source and ascii sink attached to it.  *  * Date:    June 29, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AsciiTextP_h
end_ifndef

begin_define
define|#
directive|define
name|_AsciiTextP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/TextP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSrc.h>
end_include

begin_comment
comment|/* no need to get private header. */
end_comment

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiText.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|AsciiClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiTextClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|TextClassPart
name|text_class
decl_stmt|;
name|AsciiClassPart
name|ascii_class
decl_stmt|;
block|}
name|AsciiTextClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AsciiTextClassRec
name|asciiTextClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|foo
decl_stmt|;
comment|/* keep compiler happy. */
block|}
name|AsciiPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|TextPart
name|text
decl_stmt|;
name|AsciiPart
name|ascii
decl_stmt|;
block|}
name|AsciiRec
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Ascii String Emulation widget.  *  ************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII_STRING
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|AsciiStringClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiStringClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|TextClassPart
name|text_class
decl_stmt|;
name|AsciiClassPart
name|ascii_class
decl_stmt|;
name|AsciiStringClassPart
name|string_class
decl_stmt|;
block|}
name|AsciiStringClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AsciiStringClassRec
name|asciiStringClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|foo
decl_stmt|;
comment|/* keep compiler happy. */
block|}
name|AsciiStringPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiStringRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|TextPart
name|text
decl_stmt|;
name|AsciiPart
name|ascii
decl_stmt|;
name|AsciiStringPart
name|ascii_str
decl_stmt|;
block|}
name|AsciiStringRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASCII_STRING */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASCII_DISK
end_ifdef

begin_comment
comment|/************************************************************  *  * Ascii Disk Emulation widget.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|empty
decl_stmt|;
block|}
name|AsciiDiskClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiDiskClassRec
block|{
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|TextClassPart
name|text_class
decl_stmt|;
name|AsciiClassPart
name|ascii_class
decl_stmt|;
name|AsciiDiskClassPart
name|disk_class
decl_stmt|;
block|}
name|AsciiDiskClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AsciiDiskClassRec
name|asciiDiskClassRec
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|foo
decl_stmt|;
comment|/* keep compiler happy. */
block|}
name|AsciiDiskPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_AsciiDiskRec
block|{
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|TextPart
name|text
decl_stmt|;
name|AsciiPart
name|ascii
decl_stmt|;
name|AsciiDiskPart
name|ascii_disk
decl_stmt|;
block|}
name|AsciiDiskRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASCII_DISK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AsciiTextP_h */
end_comment

end_unit

