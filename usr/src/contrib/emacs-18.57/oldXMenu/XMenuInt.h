begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: XMenuInt.h,v 1.1 87/08/04 10:29:03 toddb Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  *	XMenuInternal.h - Internal menu system include file for the  *			MIT Project Athena XMenu X window system  *			menu package.  *			  *	Author:		Tony Della Fera, DEC  *			October, 1985  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XMenuInternal_h_
end_ifndef

begin_define
define|#
directive|define
name|_XMenuInternal_h_
end_define

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/X10.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"XMenu.h"
end_include

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<= (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)>= (y) ? (x) : (y))
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|a
parameter_list|)
value|((a)< 0 ? -(a) : (a))
end_define

begin_define
define|#
directive|define
name|_X_FAILURE
value|-1
end_define

begin_define
define|#
directive|define
name|_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|_FAILURE
value|-1
end_define

begin_comment
comment|/*  * XMenu internal event handler variable.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|_XMEventHandler
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|Pixel
end_ifndef

begin_define
define|#
directive|define
name|Pixel
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Internal routine declarations.  */
end_comment

begin_function_decl
name|int
name|_XMWinQueInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|_XMWinQueAddPane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_XMWinQueAddSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_XMWinQueFlush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|XMPane
modifier|*
name|_XMGetPanePtr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|XMSelect
modifier|*
name|_XMGetSelectionPtr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_XMRecomputeGlobals
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|_XMRecomputePane
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_XMRecomputeSelection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_XMTransToOrigin
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|_XMRefreshPane
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|_XMRefreshSelections
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_function_decl
name|int
name|_XMHighlightSelection
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* No value actually returned. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't add stuff after this #endif */
end_comment

end_unit

