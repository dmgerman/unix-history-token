begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XStNColor.c,v 11.22 91/07/22 22:35:01 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_include
include|#
directive|include
file|"Xcmsint.h"
end_include

begin_function_decl
specifier|extern
name|void
name|_XcmsRGB_to_XColor
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_macro
name|XStoreNamedColor
argument_list|(
argument|register Display *dpy
argument_list|,
argument|Colormap cmap
argument_list|,
argument|_Xconst char *name
argument_list|,
comment|/* STRING8 */
argument|unsigned long pixel
argument_list|,
comment|/* CARD32 */
argument|int flags
argument_list|)
end_macro

begin_comment
comment|/* DoRed, DoGreen, DoBlue */
end_comment

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|XStoreNamedColor
argument_list|(
name|dpy
argument_list|,
name|cmap
argument_list|,
name|name
argument_list|,
name|pixel
argument_list|,
name|flags
argument_list|)
specifier|register
name|Display
operator|*
name|dpy
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Colormap
name|cmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* STRING8 */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|pixel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CARD32 */
end_comment

begin_decl_stmt
name|int
name|flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DoRed, DoGreen, DoBlue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|unsigned
name|int
name|nbytes
decl_stmt|;
specifier|register
name|xStoreNamedColorReq
modifier|*
name|req
decl_stmt|;
name|XcmsCCC
name|ccc
decl_stmt|;
name|XcmsColor
name|cmsColor_exact
decl_stmt|;
name|XColor
name|scr_def
decl_stmt|;
comment|/*      * Let's Attempt to use TekCMS approach to Parse Color      */
if|if
condition|(
operator|(
name|ccc
operator|=
name|XcmsCCCOfColormap
argument_list|(
name|dpy
argument_list|,
name|cmap
argument_list|)
operator|)
operator|!=
operator|(
name|XcmsCCC
operator|)
name|NULL
condition|)
block|{
if|if
condition|(
name|_XcmsResolveColorString
argument_list|(
name|ccc
argument_list|,
operator|&
name|name
argument_list|,
operator|&
name|cmsColor_exact
argument_list|,
name|XcmsRGBFormat
argument_list|)
operator|!=
name|XcmsFailure
condition|)
block|{
name|_XcmsRGB_to_XColor
argument_list|(
operator|&
name|cmsColor_exact
argument_list|,
operator|&
name|scr_def
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|scr_def
operator|.
name|pixel
operator|=
name|pixel
expr_stmt|;
name|scr_def
operator|.
name|flags
operator|=
name|flags
expr_stmt|;
name|XStoreColor
argument_list|(
name|dpy
argument_list|,
name|cmap
argument_list|,
operator|&
name|scr_def
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Otherwise we failed; or name was changed with yet another 	 * name.  Thus pass name to the X Server. 	 */
block|}
comment|/*      * The TekCMS and i18n methods failed, so lets pass it to the server      * for parsing.      */
name|LockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|GetReq
argument_list|(
name|StoreNamedColor
argument_list|,
name|req
argument_list|)
expr_stmt|;
name|req
operator|->
name|cmap
operator|=
name|cmap
expr_stmt|;
name|req
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
name|req
operator|->
name|pixel
operator|=
name|pixel
expr_stmt|;
name|req
operator|->
name|nbytes
operator|=
name|nbytes
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|req
operator|->
name|length
operator|+=
operator|(
name|nbytes
operator|+
literal|3
operator|)
operator|>>
literal|2
expr_stmt|;
comment|/* round up to multiple of 4 */
name|Data
argument_list|(
name|dpy
argument_list|,
name|name
argument_list|,
operator|(
name|long
operator|)
name|nbytes
argument_list|)
expr_stmt|;
name|UnlockDisplay
argument_list|(
name|dpy
argument_list|)
expr_stmt|;
name|SyncHandle
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

