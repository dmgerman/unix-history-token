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
literal|"$Header: util.c,v 10.1 86/11/19 10:44:43 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* Copyright 1985 Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* util.c - Various utilities  *  *      SoundBell       Generate audible bell  *      SetKeyClick     Control key click  *      SetAutoRepeat   Control auto repeat  *      SetLockLED      Control Lock LED  *      SetVideo        Disable/enable video  *      QueryShape      Determine shapes  *      ResolveColors   Does nothing  *      StoreColors     Does nothing  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_include
include|#
directive|include
file|"bitblt.h"
end_include

begin_comment
comment|/*  * Sound bell, volume between 0 (quiet) and 7 (loud)  */
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In SoundBell\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
if|if
condition|(
name|volume
operator|>
literal|0
condition|)
name|ioctl
argument_list|(
name|xdev
argument_list|,
name|QIOCBELL
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|volume
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Set key click, volume between -1 (default), 0 (off) and 8 (loud)  */
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In SetKeyClick\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
name|ioctl
argument_list|(
name|xdev
argument_list|,
name|QIOCCLICK
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|volume
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Set autorepeat on or off  */
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In SetAutoRepeat\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
name|ioctl
argument_list|(
name|xdev
argument_list|,
name|QIOCAUTOREP
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|onoff
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Enable/disable video  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|SetVideo
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In SetVideo\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Determine shapes of cursor and tile  */
end_comment

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
specifier|register
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In QueryShape\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
switch|switch
condition|(
name|shape
condition|)
block|{
case|case
name|CursorShape
case|:
if|if
condition|(
operator|*
name|width
operator|>
name|CURSOR_WIDTH
condition|)
operator|*
name|width
operator|=
name|CURSOR_WIDTH
expr_stmt|;
if|if
condition|(
operator|*
name|height
operator|>
name|CURSOR_HEIGHT
condition|)
operator|*
name|height
operator|=
name|CURSOR_HEIGHT
expr_stmt|;
break|break;
case|case
name|TileShape
case|:
operator|*
name|width
operator|=
operator|*
name|height
operator|=
name|TILE_SIZE
expr_stmt|;
break|break;
block|}
block|}
end_block

begin_comment
comment|/*  * Turn caps lock on or off  */
end_comment

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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In SetLockLED\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
name|ioctl
argument_list|(
name|xdev
argument_list|,
operator|(
name|onoff
operator|)
condition|?
name|QIOCSETCAPSL
else|:
name|QIOCCLRCAPSL
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

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
name|u_short
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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In ResolveColor\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

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
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In StoreColors\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|TRACE_X
block|}
end_block

end_unit

