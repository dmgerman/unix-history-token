begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: TextSrc.h,v 1.9 91/02/17 13:12:26 rws Exp $  */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawTextSrc_h
end_ifndef

begin_define
define|#
directive|define
name|_XawTextSrc_h
end_define

begin_comment
comment|/***********************************************************************  *  * TextSrc Object  *  ***********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<X11/Object.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  editType	     EditType		XawTextEditType	XawtextRead  */
end_comment

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|textSrcObjectClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_TextSrcClassRec
modifier|*
name|TextSrcObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TextSrcRec
modifier|*
name|TextSrcObject
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawstPositions
block|,
name|XawstWhiteSpace
block|,
name|XawstEOL
block|,
name|XawstParagraph
block|,
name|XawstAll
block|}
name|XawTextScanType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Normal
block|,
name|Selected
block|}
name|highlightType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawsmTextSelect
block|,
name|XawsmTextExtend
block|}
name|XawTextSelectionMode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawactionStart
block|,
name|XawactionAdjust
block|,
name|XawactionEnd
block|}
name|XawTextSelectionAction
typedef|;
end_typedef

begin_comment
comment|/*  * Error Conditions:  */
end_comment

begin_define
define|#
directive|define
name|XawTextReadError
value|-1
end_define

begin_define
define|#
directive|define
name|XawTextScanError
value|-1
end_define

begin_comment
comment|/************************************************************  *  * Public Functions.  *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawTextSourceRead  *	Description: This function reads the source.  *	Arguments: w - the TextSrc Object.  *                 pos - position of the text to retreive.  * RETURNED        text - text block that will contain returned text.  *                 length - maximum number of characters to read.  *	Returns: The number of characters read into the buffer.  */
specifier|extern
name|XawTextPosition
name|XawTextSourceRead
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* pos */
parameter_list|,
name|XawTextBlock
modifier|*
comment|/* text_return */
parameter_list|,
name|int
comment|/* length */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSourceReplace.  *	Description: Replaces a block of text with new text.  *	Arguments: src - the Text Source Object.  *                 startPos, endPos - ends of text that will be removed.  *                 text - new text to be inserted into buffer at startPos.  *	Returns: XawEditError or XawEditDone.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|XawTextSourceReplace
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* start */
parameter_list|,
name|XawTextPosition
comment|/* end */
parameter_list|,
name|XawTextBlock
modifier|*
comment|/* text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSourceScan  *	Description: Scans the text source for the number and type  *                   of item specified.  *	Arguments: w - the TextSrc Object.  *                 position - the position to start scanning.  *                 type - type of thing to scan for.  *                 dir - direction to scan.  *                 count - which occurance if this thing to search for.  *                 include - whether or not to include the character found in  *                           the position that is returned.   *	Returns: The position of the text.  *  */
end_comment

begin_function_decl
specifier|extern
name|XawTextPosition
name|XawTextSourceScan
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* position */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* XawTextScanType */
name|int
comment|/* type */
parameter_list|,
comment|/* XawTextScanDirection */
name|int
comment|/* dir */
parameter_list|,
else|#
directive|else
name|XawTextScanType
comment|/* type */
parameter_list|,
name|XawTextScanDirection
comment|/* dir */
parameter_list|,
endif|#
directive|endif
name|int
comment|/* count */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* Boolean */
name|int
comment|/* include */
else|#
directive|else
name|Boolean
comment|/* include */
endif|#
directive|endif
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSourceSearch  *	Description: Searchs the text source for the text block passed  *	Arguments: w - the TextSource Object.  *                 position - the position to start scanning.  *                 dir - direction to scan.  *                 text - the text block to search for.  *	Returns: The position of the text we are searching for or  *               XawTextSearchError.  */
end_comment

begin_function_decl
specifier|extern
name|XawTextPosition
name|XawTextSourceSearch
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* position */
parameter_list|,
if|#
directive|if
name|NeedWidePrototypes
comment|/* XawTextScanDirection */
name|int
comment|/* dir */
parameter_list|,
else|#
directive|else
name|XawTextScanDirection
comment|/* dir */
parameter_list|,
endif|#
directive|endif
name|XawTextBlock
modifier|*
comment|/* text */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSourceConvertSelection  *	Description: Dummy selection converter.  *	Arguments: w - the TextSrc object.  *                 selection - the current selection atom.  *                 target    - the current target atom.  *                 type      - the type to conver the selection to.  * RETURNED        value, length - the return value that has been converted.  * RETURNED        format    - the format of the returned value.  *	Returns: TRUE if the selection has been converted.  *  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XawTextSourceConvertSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|Atom
modifier|*
comment|/* selection */
parameter_list|,
name|Atom
modifier|*
comment|/* target */
parameter_list|,
name|Atom
modifier|*
comment|/* type */
parameter_list|,
name|XtPointer
modifier|*
comment|/* value_return */
parameter_list|,
name|unsigned
name|long
modifier|*
comment|/* length_return */
parameter_list|,
name|int
modifier|*
comment|/* format_return */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawTextSourceSetSelection  *	Description: allows special setting of the selection.  *	Arguments: w - the TextSrc object.  *                 left, right - bounds of the selection.  *                 selection - the selection atom.  *	Returns: none  */
end_comment

begin_function_decl
specifier|extern
name|void
name|XawTextSourceSetSelection
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
parameter_list|,
name|XawTextPosition
comment|/* start */
parameter_list|,
name|XawTextPosition
comment|/* end */
parameter_list|,
name|Atom
comment|/* selection */
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
comment|/* _XawTextSrc_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

