begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/**                   Copyright 1991 by Andreas Stolcke                     **/
end_comment

begin_comment
comment|/**               Copyright 1990 by Solbourne Computer Inc.                 **/
end_comment

begin_comment
comment|/**                          Longmont, Colorado                             **/
end_comment

begin_comment
comment|/**                                                                         **/
end_comment

begin_comment
comment|/**                           All Rights Reserved                           **/
end_comment

begin_comment
comment|/**                                                                         **/
end_comment

begin_comment
comment|/**    Permission to use, copy, modify, and distribute this software and    **/
end_comment

begin_comment
comment|/**    its documentation  for  any  purpose  and  without  fee is hereby    **/
end_comment

begin_comment
comment|/**    granted, provided that the above copyright notice appear  in  all    **/
end_comment

begin_comment
comment|/**    copies and that both  that  copyright  notice  and  this  permis-    **/
end_comment

begin_comment
comment|/**    sion  notice appear in supporting  documentation,  and  that  the    **/
end_comment

begin_comment
comment|/**    name of Solbourne not be used in advertising                         **/
end_comment

begin_comment
comment|/**    in publicity pertaining to distribution of the  software  without    **/
end_comment

begin_comment
comment|/**    specific, written prior permission.                                  **/
end_comment

begin_comment
comment|/**                                                                         **/
end_comment

begin_comment
comment|/**    ANDREAS STOLCKE AND SOLBOURNE COMPUTER INC. DISCLAIMS ALL WARRANTIES **/
end_comment

begin_comment
comment|/**    WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF    **/
end_comment

begin_comment
comment|/**    MERCHANTABILITY  AND  FITNESS,  IN  NO  EVENT SHALL ANDREAS STOLCKE  **/
end_comment

begin_comment
comment|/**    OR SOLBOURNE BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL    **/
end_comment

begin_comment
comment|/**    DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA   **/
end_comment

begin_comment
comment|/**    OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER    **/
end_comment

begin_comment
comment|/**    TORTIOUS ACTION, ARISING OUT OF OR IN  CONNECTION  WITH  THE  USE    **/
end_comment

begin_comment
comment|/**    OR PERFORMANCE OF THIS SOFTWARE.                                     **/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  * vroot.h -- Virtual Root Window handling header file  *  * This header file redefines the X11 macros RootWindow and DefaultRootWindow,  * making them look for a virtual root window as provided by certain `virtual'  * window managers like swm and tvtwm. If none is found, the ordinary root  * window is returned, thus retaining backward compatibility with standard  * window managers.  * The function implementing the virtual root lookup remembers the result of  * its last invocation to avoid overhead in the case of repeated calls  * on the same display and screen arguments.   * The lookup code itself is taken from Tom LaStrange's ssetroot program.  *  * Most simple root window changing X programs can be converted to using  * virtual roots by just including  *  * #include<X11/vroot.h>  *  * after all the X11 header files.  It has been tested on such popular  * X clients as xphoon, xfroot, xloadimage, and xaqua.  * It also works with the core clients xprop, xwininfo, xwd, and editres  * (and is necessary to get those clients working under tvtwm).  * It does NOT work with xsetroot; get the xsetroot replacement included in  * the tvtwm distribution instead.  *  * Andreas Stolcke<stolcke@ICSI.Berkeley.EDU>, 9/7/90  * - replaced all NULL's with properly cast 0's, 5/6/91  * - free children list (suggested by Mark Martin<mmm@cetia.fr>), 5/16/91  * - include X11/Xlib.h and support RootWindowOfScreen, too 9/17/91  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VROOT_H_
end_ifndef

begin_define
define|#
directive|define
name|_VROOT_H_
end_define

begin_include
include|#
directive|include
file|<X11/X.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_function
specifier|static
name|Window
name|VirtualRootWindowOfScreen
parameter_list|(
name|screen
parameter_list|)
name|Screen
modifier|*
name|screen
decl_stmt|;
block|{
specifier|static
name|Screen
modifier|*
name|save_screen
init|=
operator|(
name|Screen
operator|*
operator|)
literal|0
decl_stmt|;
specifier|static
name|Window
name|root
init|=
operator|(
name|Window
operator|)
literal|0
decl_stmt|;
if|if
condition|(
name|screen
operator|!=
name|save_screen
condition|)
block|{
name|Display
modifier|*
name|dpy
init|=
name|DisplayOfScreen
argument_list|(
name|screen
argument_list|)
decl_stmt|;
name|Atom
name|__SWM_VROOT
init|=
name|None
decl_stmt|;
name|int
name|i
decl_stmt|;
name|Window
name|rootReturn
decl_stmt|,
name|parentReturn
decl_stmt|,
modifier|*
name|children
decl_stmt|;
name|unsigned
name|int
name|numChildren
decl_stmt|;
name|root
operator|=
name|RootWindowOfScreen
argument_list|(
name|screen
argument_list|)
expr_stmt|;
comment|/* go look for a virtual root */
name|__SWM_VROOT
operator|=
name|XInternAtom
argument_list|(
name|dpy
argument_list|,
literal|"__SWM_VROOT"
argument_list|,
name|False
argument_list|)
expr_stmt|;
if|if
condition|(
name|XQueryTree
argument_list|(
name|dpy
argument_list|,
name|root
argument_list|,
operator|&
name|rootReturn
argument_list|,
operator|&
name|parentReturn
argument_list|,
operator|&
name|children
argument_list|,
operator|&
name|numChildren
argument_list|)
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|numChildren
condition|;
name|i
operator|++
control|)
block|{
name|Atom
name|actual_type
decl_stmt|;
name|int
name|actual_format
decl_stmt|;
name|unsigned
name|long
name|nitems
decl_stmt|,
name|bytesafter
decl_stmt|;
name|Window
modifier|*
name|newRoot
init|=
operator|(
name|Window
operator|*
operator|)
literal|0
decl_stmt|;
if|if
condition|(
name|XGetWindowProperty
argument_list|(
name|dpy
argument_list|,
name|children
index|[
name|i
index|]
argument_list|,
name|__SWM_VROOT
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
name|False
argument_list|,
name|XA_WINDOW
argument_list|,
operator|&
name|actual_type
argument_list|,
operator|&
name|actual_format
argument_list|,
operator|&
name|nitems
argument_list|,
operator|&
name|bytesafter
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|)
operator|&
name|newRoot
argument_list|)
operator|==
name|Success
operator|&&
name|newRoot
condition|)
block|{
name|root
operator|=
operator|*
name|newRoot
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|children
condition|)
name|XFree
argument_list|(
operator|(
name|char
operator|*
operator|)
name|children
argument_list|)
expr_stmt|;
block|}
name|save_screen
operator|=
name|screen
expr_stmt|;
block|}
return|return
name|root
return|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|RootWindowOfScreen
end_undef

begin_define
define|#
directive|define
name|RootWindowOfScreen
parameter_list|(
name|s
parameter_list|)
value|VirtualRootWindowOfScreen(s)
end_define

begin_undef
undef|#
directive|undef
name|RootWindow
end_undef

begin_define
define|#
directive|define
name|RootWindow
parameter_list|(
name|dpy
parameter_list|,
name|screen
parameter_list|)
value|VirtualRootWindowOfScreen(ScreenOfDisplay(dpy,screen))
end_define

begin_undef
undef|#
directive|undef
name|DefaultRootWindow
end_undef

begin_define
define|#
directive|define
name|DefaultRootWindow
parameter_list|(
name|dpy
parameter_list|)
value|VirtualRootWindowOfScreen(DefaultScreenOfDisplay(dpy))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VROOT_H_ */
end_comment

end_unit

