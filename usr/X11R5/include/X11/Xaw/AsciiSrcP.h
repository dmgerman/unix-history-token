begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: AsciiSrcP.h,v 1.8 91/02/20 17:58:15 converse Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * AsciiSrcP.h - Private Header for Ascii Text Source.  *  * This is the private header file for the Ascii Text Source.  * It is intended to be used with the Text widget, the simplest way to use  * this text source is to use the AsciiText Object.  *  * Date:    June 29, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_comment
comment|/*   * TextSrcP.h - Private definitions for AsciiSrc object  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawAsciiSrcP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawAsciiSrcP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/TextSrcP.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiSrc.h>
end_include

begin_comment
comment|/************************************************************  *  * Private declarations.  *  ************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_tmpnam
end_ifdef

begin_define
define|#
directive|define
name|TMPSIZ
value|L_tmpnam
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TMPSIZ
value|32
end_define

begin_comment
comment|/* bytes to allocate for tmpnam */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAGIC_VALUE
value|((XawTextPosition) -1)
end_define

begin_comment
comment|/* Magic value. */
end_comment

begin_define
define|#
directive|define
name|streq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( strcmp((a), (b)) == 0 )
end_define

begin_typedef
typedef|typedef
struct|struct
name|_Piece
block|{
comment|/* Piece of the text file of BUFSIZ allocated  				   characters. */
name|char
modifier|*
name|text
decl_stmt|;
comment|/* The text in this buffer. */
name|XawTextPosition
name|used
decl_stmt|;
comment|/* The number of characters of this buffer  				   that have been used. */
name|struct
name|_Piece
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
comment|/* linked list pointers. */
block|}
name|Piece
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * New fields for the AsciiSrc object class record.  *  ************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSrcClassPart
block|{
name|char
name|foo
decl_stmt|;
block|}
name|AsciiSrcClassPart
typedef|;
end_typedef

begin_comment
comment|/* Full class record declaration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSrcClassRec
block|{
name|ObjectClassPart
name|object_class
decl_stmt|;
name|TextSrcClassPart
name|text_src_class
decl_stmt|;
name|AsciiSrcClassPart
name|ascii_src_class
decl_stmt|;
block|}
name|AsciiSrcClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|AsciiSrcClassRec
name|asciiSrcClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* New fields for the AsciiSrc object record */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSrcPart
block|{
comment|/* Resources. */
name|char
modifier|*
name|string
decl_stmt|;
comment|/* either the string, or the 				   file name, depending upon the type. */
name|XawAsciiType
name|type
decl_stmt|;
comment|/* either string or disk. */
name|XawTextPosition
name|piece_size
decl_stmt|;
comment|/* Size of text buffer for each piece. */
name|Boolean
name|data_compression
decl_stmt|;
comment|/* compress to minimum memory automatically 				   on save? */
name|XtCallbackList
name|callback
decl_stmt|;
comment|/* A callback list to call when the source is 				   changed. */
name|Boolean
name|use_string_in_place
decl_stmt|;
comment|/* Use the string passed in place. */
name|int
name|ascii_length
decl_stmt|;
comment|/* length field for ascii string emulation. */
ifdef|#
directive|ifdef
name|ASCII_DISK
name|String
name|filename
decl_stmt|;
comment|/* name of file for Compatability. */
endif|#
directive|endif
comment|/* ASCII_DISK */
comment|/* Private data. */
name|Boolean
name|is_tempfile
decl_stmt|;
comment|/* Is this a temporary file? */
name|Boolean
name|changes
decl_stmt|;
comment|/* Has this file been edited? */
name|Boolean
name|allocated_string
decl_stmt|;
comment|/* Have I allocated the 				     string in ascii_src->string? */
name|XawTextPosition
name|length
decl_stmt|;
comment|/* length of file */
name|Piece
modifier|*
name|first_piece
decl_stmt|;
comment|/* first piece of the text. */
block|}
name|AsciiSrcPart
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *  * Full instance record declaration  *  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_AsciiSrcRec
block|{
name|ObjectPart
name|object
decl_stmt|;
name|TextSrcPart
name|text_src
decl_stmt|;
name|AsciiSrcPart
name|ascii_src
decl_stmt|;
block|}
name|AsciiSrcRec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawAsciiSrcP_h  --- Don't add anything after this line. */
end_comment

end_unit

