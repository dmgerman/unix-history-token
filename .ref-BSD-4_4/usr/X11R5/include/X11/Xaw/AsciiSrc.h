begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: AsciiSrc.h,v 1.13 91/07/22 19:02:47 converse Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  */
end_comment

begin_comment
comment|/*  * AsciiSrc.h - Public Header file for Ascii Text Source.  *  * This is the public header file for the Ascii Text Source.  * It is intended to be used with the Text widget, the simplest way to use  * this text source is to use the AsciiText Object.  *  * Date:    June 29, 1989  *  * By:      Chris D. Peterson  *          MIT X Consortium   *          kit@expo.lcs.mit.edu  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawAsciiSrc_h
end_ifndef

begin_define
define|#
directive|define
name|_XawAsciiSrc_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/TextSrc.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xfuncproto.h>
end_include

begin_comment
comment|/* Resources:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  callback	     Callback		Callback	(none)  dataCompression     DataCompression	Boolean		True  length		     Length		int		(internal)  pieceSize	     PieceSize		int		BUFSIZ  string		     String		String		NULL  type		     Type		XawAsciiType	XawAsciiString  useStringInPlace    UseStringInPlace	Boolean		False  */
end_comment

begin_comment
comment|/* Class record constants */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|asciiSrcObjectClass
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|_AsciiSrcClassRec
modifier|*
name|AsciiSrcObjectClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_AsciiSrcRec
modifier|*
name|AsciiSrcObject
typedef|;
end_typedef

begin_comment
comment|/*  * Just to make people's lives a bit easier.  */
end_comment

begin_define
define|#
directive|define
name|AsciiSourceObjectClass
value|AsciiSrcObjectClass
end_define

begin_define
define|#
directive|define
name|AsciiSourceObject
value|AsciiSrcObject
end_define

begin_comment
comment|/*  * Resource Definitions.  */
end_comment

begin_define
define|#
directive|define
name|XtCDataCompression
value|"DataCompression"
end_define

begin_define
define|#
directive|define
name|XtCPieceSize
value|"PieceSize"
end_define

begin_define
define|#
directive|define
name|XtCType
value|"Type"
end_define

begin_define
define|#
directive|define
name|XtCUseStringInPlace
value|"UseStringInPlace"
end_define

begin_define
define|#
directive|define
name|XtNdataCompression
value|"dataCompression"
end_define

begin_define
define|#
directive|define
name|XtNpieceSize
value|"pieceSize"
end_define

begin_define
define|#
directive|define
name|XtNtype
value|"type"
end_define

begin_define
define|#
directive|define
name|XtNuseStringInPlace
value|"useStringInPlace"
end_define

begin_define
define|#
directive|define
name|XtRAsciiType
value|"AsciiType"
end_define

begin_define
define|#
directive|define
name|XtEstring
value|"string"
end_define

begin_define
define|#
directive|define
name|XtEfile
value|"file"
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|XawAsciiFile
block|,
name|XawAsciiString
block|}
name|XawAsciiType
typedef|;
end_typedef

begin_comment
comment|/************************************************************  *  * Public routines   *  ************************************************************/
end_comment

begin_function_decl
name|_XFUNCPROTOBEGIN
comment|/*	Function Name: XawAsciiSourceFreeString  *	Description: Frees the string returned by a get values call  *                   on the string when the source is of type string.  *	Arguments: w - the AsciiSrc object.  *	Returns: none.  */
specifier|extern
name|void
name|XawAsciiSourceFreeString
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawAsciiSave  *	Description: Saves all the pieces into a file or string as required.  *	Arguments: w - the asciiSrc Object.  *	Returns: TRUE if the save was successful.  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XawAsciiSave
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*	Function Name: XawAsciiSaveAsFile  *	Description: Save the current buffer as a file.  *	Arguments: w - the asciiSrc object.  *                 name - name of the file to save this file into.  *	Returns: True if the save was successful.  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XawAsciiSaveAsFile
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
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

begin_comment
comment|/*	Function Name: XawAsciiSourceChanged  *	Description: Returns true if the source has changed since last saved.  *	Arguments: w - the asciiSource object.  *	Returns: a Boolean (see description).  */
end_comment

begin_function_decl
specifier|extern
name|Boolean
name|XawAsciiSourceChanged
parameter_list|(
if|#
directive|if
name|NeedFunctionPrototypes
name|Widget
comment|/* w */
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
comment|/* _XawAsciiSrc_h  - Don't add anything after this line. */
end_comment

end_unit

