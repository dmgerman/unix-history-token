begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Logo.h,v 1.11 90/10/22 14:45:11 converse Exp $ */
end_comment

begin_comment
comment|/* Copyright 1988 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission. M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawLogo_h
end_ifndef

begin_define
define|#
directive|define
name|_XawLogo_h
end_define

begin_comment
comment|/* Parameters:   Name		     Class		RepType		Default Value  ----		     -----		-------		-------------  background	     Background		Pixel		XtDefaultBackground  border		     BorderColor	Pixel		XtDefaultForeground  borderWidth	     BorderWidth	Dimension	1  destroyCallback     Callback		Pointer		NULL  foreground	     Foreground		Pixel		XtDefaultForeground  height		     Height		Dimension	100  mappedWhenManaged   MappedWhenManaged	Boolean		True  shapeWindow	     ShapeWindow	Boolean		False  width		     Width		Dimension	100  x		     Position		Position	0  y		     Position		Position	0  */
end_comment

begin_define
define|#
directive|define
name|XtNshapeWindow
value|"shapeWindow"
end_define

begin_define
define|#
directive|define
name|XtCShapeWindow
value|"ShapeWindow"
end_define

begin_typedef
typedef|typedef
name|struct
name|_LogoRec
modifier|*
name|LogoWidget
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_LogoClassRec
modifier|*
name|LogoWidgetClass
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|WidgetClass
name|logoWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawLogo_h */
end_comment

end_unit

