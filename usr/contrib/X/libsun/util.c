begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_util_c
init|=
literal|"$Header: util.c,v 10.2 86/02/01 16:21:36 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_comment
comment|/*  * The Sun X drivers are a product of Sun Microsystems, Inc. and are provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify these drivers without charge, but are not authorized  * to license or distribute them to anyone else except as part of a product or  * program developed by the user.  *   * THE SUN X DRIVERS ARE PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND  * INCLUDING THE WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A  * PARTICULAR PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE  * PRACTICE.  *  * The Sun X Drivers are provided with no support and without any obligation  * on the part of Sun Microsystems, Inc. to assist in their use, correction,  * modification or enhancement.  *   * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THE SUN X  * DRIVERS OR ANY PART THEREOF.  *   * In no event will Sun Microsystems, Inc. be liable for any lost revenue  * or profits or other special, indirect and consequential damages, even if  * Sun has been advised of the possibility of such damages.  *   * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California  94043  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)util.c 2.1 86/01/28 Copyright 1986 Sun Micro"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * Copyright (c) 1986 by Sun Microsystems,  Inc.  */
end_comment

begin_comment
comment|/* util.c		Various utilities  *  *	SoundBell	Generate audible bell  *	SetKeyClick	Control key click  *	SetAutoRepeat	Control auto repeat  *	SetLockLED	Control Lock LED  *	SetVideo	Disable/enable video  *	QueryShape	Determine shapes  *	ResolveColors	does nothing  *	StoreColors	does nothing  */
end_comment

begin_comment
comment|/*  *	ToDo:  *		Implement SetVideo  *		Implement SoundBell(!)  */
end_comment

begin_include
include|#
directive|include
file|"Xsun.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|vsdev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sound bell, volume between 0 (quiet) and 7 (loud) */
end_comment

begin_macro
name|SoundBell
argument_list|(
argument|volume
argument_list|)
end_macro

begin_decl_stmt
name|int
name|volume
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Set key click, volume between -1 (default), 0 (off) and 8 (loud) */
end_comment

begin_macro
name|SetKeyClick
argument_list|(
argument|volume
argument_list|)
end_macro

begin_decl_stmt
name|int
name|volume
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Set autorepeat */
end_comment

begin_macro
name|SetAutoRepeat
argument_list|(
argument|onoff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|onoff
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|int
name|SetVideo
parameter_list|(
name|onoff
parameter_list|)
name|int
name|onoff
decl_stmt|;
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|QueryShape
argument_list|(
argument|shape
argument_list|,
argument|width
argument_list|,
argument|height
argument_list|)
end_macro

begin_decl_stmt
name|int
name|shape
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
modifier|*
name|width
decl_stmt|,
modifier|*
name|height
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* Cursors& tiles unrestricted */
block|}
end_block

begin_macro
name|SetLockLED
argument_list|(
argument|onoff
argument_list|)
end_macro

begin_decl_stmt
name|int
name|onoff
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|ResolveColor
argument_list|(
argument|red
argument_list|,
argument|green
argument_list|,
argument|blue
argument_list|)
end_macro

begin_decl_stmt
name|unsigned
name|short
modifier|*
name|red
decl_stmt|,
modifier|*
name|green
decl_stmt|,
modifier|*
name|blue
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|*
name|red
operator|&=
operator|~
literal|0377
expr_stmt|;
operator|*
name|green
operator|&=
operator|~
literal|0377
expr_stmt|;
operator|*
name|blue
operator|&=
operator|~
literal|0377
expr_stmt|;
block|}
end_block

begin_macro
name|StoreColors
argument_list|(
argument|count
argument_list|,
argument|entries
argument_list|)
end_macro

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ColorDef
modifier|*
name|entries
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* XXX - should keep interal shadow of color map and rewrite whole */
specifier|extern
name|struct
name|pixrect
modifier|*
name|PixRect
decl_stmt|;
while|while
condition|(
name|count
operator|--
condition|)
block|{
name|u_char
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
name|r
operator|=
call|(
name|u_char
call|)
argument_list|(
name|entries
operator|->
name|red
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|g
operator|=
call|(
name|u_char
call|)
argument_list|(
name|entries
operator|->
name|green
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|b
operator|=
call|(
name|u_char
call|)
argument_list|(
name|entries
operator|->
name|blue
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|pr_putcolormap
argument_list|(
name|PixRect
argument_list|,
name|entries
operator|->
name|pixel
argument_list|,
literal|1
argument_list|,
operator|&
name|r
argument_list|,
operator|&
name|g
argument_list|,
operator|&
name|b
argument_list|)
expr_stmt|;
name|entries
operator|++
expr_stmt|;
block|}
block|}
end_block

begin_decl_stmt
specifier|extern
name|u_char
name|InvPix
index|[]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|InvertPixelOrder
argument_list|(
name|p
argument_list|,
name|n
argument_list|)
specifier|register
name|unsigned
name|short
operator|*
name|p
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
for|for
control|(
init|;
name|n
operator|--
condition|;
name|p
operator|++
control|)
block|{
specifier|register
name|unsigned
name|short
name|l
init|=
operator|(
operator|*
name|p
operator|&
literal|0xff
operator|)
decl_stmt|,
name|h
init|=
operator|(
operator|*
name|p
operator|>>
literal|8
operator|)
operator|&
literal|0xff
decl_stmt|;
name|unsigned
name|short
name|old
init|=
operator|*
name|p
decl_stmt|;
operator|*
name|p
operator|=
call|(
name|unsigned
name|short
call|)
argument_list|(
operator|(
name|InvPix
index|[
name|l
index|]
operator|<<
literal|8
operator|)
operator||
name|InvPix
index|[
name|h
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
endif|sun
end_endif

end_unit

