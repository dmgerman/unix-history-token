begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Menu.h,v 1.2 89/07/21 14:22:10 jim Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtMenu_h
end_ifndef

begin_define
define|#
directive|define
name|_XtMenu_h
end_define

begin_comment
comment|/***********************************************************************  *  * Menu Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		pixel		White  border		     BorderColor	pixel		Black  borderWidth	     BorderWidth	int		1  height		     Height		int		120  mappedWhenManaged   MappedWhenManaged	Boolean		True  reverseVideo	     ReverseVideo	Boolean		False  width		     Width		int		120  x		     Position		int		0  y		     Position		int		0  */
end_comment

begin_define
define|#
directive|define
name|XtNmenuEntries
value|"menuEntries"
end_define

begin_define
define|#
directive|define
name|XtNhorizontalPadding
value|"horizontalPadding"
end_define

begin_define
define|#
directive|define
name|XtNverticalPadding
value|"verticalPadding"
end_define

begin_define
define|#
directive|define
name|XtNselection
value|"Selection"
end_define

begin_define
define|#
directive|define
name|XtCMenuEntries
value|"MenuEntries"
end_define

begin_define
define|#
directive|define
name|XtCPadding
value|"Padding"
end_define

begin_define
define|#
directive|define
name|XtCSelection
value|"Selection"
end_define

begin_typedef
typedef|typedef
name|struct
name|_MenuRec
modifier|*
name|MenuWidget
typedef|;
end_typedef

begin_comment
comment|/* completely defined in MenuPrivate.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_MenuClassRec
modifier|*
name|MenuWidgetClass
typedef|;
end_typedef

begin_comment
comment|/* completely defined in MenuPrivate.h */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|menuWidgetClass
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|Widget
name|XawMenuCreate
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtMenu_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

