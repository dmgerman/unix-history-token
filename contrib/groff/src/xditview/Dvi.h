begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Dvi.h,v 1.4 89/07/21 14:22:06 jim Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtDvi_h
end_ifndef

begin_define
define|#
directive|define
name|_XtDvi_h
end_define

begin_comment
comment|/***********************************************************************  *  * Dvi Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		pixel		White  foreground	     Foreground		Pixel		Black  fontMap	     FontMap		char *		...  pageNumber	     PageNumber		int		1 */
end_comment

begin_define
define|#
directive|define
name|XtNfontMap
value|"fontMap"
end_define

begin_define
define|#
directive|define
name|XtNpageNumber
value|"pageNumber"
end_define

begin_define
define|#
directive|define
name|XtNlastPageNumber
value|"lastPageNumber"
end_define

begin_define
define|#
directive|define
name|XtNnoPolyText
value|"noPolyText"
end_define

begin_define
define|#
directive|define
name|XtNseek
value|"seek"
end_define

begin_define
define|#
directive|define
name|XtNresolution
value|"resolution"
end_define

begin_define
define|#
directive|define
name|XtCFontMap
value|"FontMap"
end_define

begin_define
define|#
directive|define
name|XtCPageNumber
value|"PageNumber"
end_define

begin_define
define|#
directive|define
name|XtCLastPageNumber
value|"LastPageNumber"
end_define

begin_define
define|#
directive|define
name|XtCNoPolyText
value|"NoPolyText"
end_define

begin_define
define|#
directive|define
name|XtCSeek
value|"Seek"
end_define

begin_define
define|#
directive|define
name|XtCResolution
value|"Resolution"
end_define

begin_typedef
typedef|typedef
name|struct
name|_DviRec
modifier|*
name|DviWidget
typedef|;
end_typedef

begin_comment
comment|/* completely defined in DviPrivate.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_DviClassRec
modifier|*
name|DviWidgetClass
typedef|;
end_typedef

begin_comment
comment|/* completely defined in DviPrivate.h */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|dviWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|DviSaveToFile
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtDvi_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

