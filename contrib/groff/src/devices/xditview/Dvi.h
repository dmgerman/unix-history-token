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
value|(String)"fontMap"
end_define

begin_define
define|#
directive|define
name|XtNpageNumber
value|(String)"pageNumber"
end_define

begin_define
define|#
directive|define
name|XtNlastPageNumber
value|(String)"lastPageNumber"
end_define

begin_define
define|#
directive|define
name|XtNnoPolyText
value|(String)"noPolyText"
end_define

begin_define
define|#
directive|define
name|XtNseek
value|(String)"seek"
end_define

begin_define
define|#
directive|define
name|XtNresolution
value|(String)"resolution"
end_define

begin_define
define|#
directive|define
name|XtCFontMap
value|(String)"FontMap"
end_define

begin_define
define|#
directive|define
name|XtCPageNumber
value|(String)"PageNumber"
end_define

begin_define
define|#
directive|define
name|XtCLastPageNumber
value|(String)"LastPageNumber"
end_define

begin_define
define|#
directive|define
name|XtCNoPolyText
value|(String)"NoPolyText"
end_define

begin_define
define|#
directive|define
name|XtCSeek
value|(String)"Seek"
end_define

begin_define
define|#
directive|define
name|XtCResolution
value|(String)"Resolution"
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
comment|/* completely defined in DviP.h */
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
comment|/* completely defined in DviP.h */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|dviWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|DviSaveToFile
parameter_list|(
name|Widget
parameter_list|,
name|FILE
modifier|*
parameter_list|)
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

