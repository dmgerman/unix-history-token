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
name|rcsid_apa8c_c
init|=
literal|"$Header: apa8c.c,v 10.1 86/11/19 10:39:58 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* apa8c.c - APA8C controller initialization  *  * 	apa8c_init		APA8C initialization routine  *	apa8c_set_colors	set defualt colors  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
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

begin_include
include|#
directive|include
file|"apa8c.h"
end_include

begin_comment
comment|/*  * Initialize APA8C  */
end_comment

begin_macro
name|apa8c_init
argument_list|()
end_macro

begin_block
block|{
name|u_short
name|tmp
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In apa8c_init\n"
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
comment|/*          * Initialize (reset) the APA8C screen          */
comment|/* 	 * Set up the write and data mask. 	 */
name|SET_APA8C_WRITEMASK
argument_list|(
name|NOMASK
argument_list|)
expr_stmt|;
name|SET_APA8C_DATAMASK
argument_list|(
name|HIDDEN_DM
argument_list|)
expr_stmt|;
comment|/* 	 * Set up the APA8C control register to use its system read/write 	 * calls in the X direction. 	 */
name|SET_APA8C_FC
argument_list|(
name|DCR_VEN
operator||
name|DCR_SEN
operator||
name|DCR_SWR
operator||
name|DCR_X
operator||
name|HIDDEN_FUNC
argument_list|)
expr_stmt|;
comment|/* 	 * Set up the color plane select register and foreground/background 	 * registers. 	 */
operator|*
operator|(
name|u_short
operator|*
operator|)
name|CPS_REG
operator|=
name|DEFAULT_CPS
expr_stmt|;
operator|*
operator|(
name|u_short
operator|*
operator|)
name|FGBG_REG
operator|=
name|DEFAULT_FGBG
expr_stmt|;
comment|/* 	 * Set default colors in Video Look-up Table. 	 */
name|apa8c_set_colors
argument_list|()
expr_stmt|;
comment|/* 	 * Test for the APA8C screen. 	 */
name|tmp
operator|=
operator|*
operator|(
name|u_short
operator|*
operator|)
name|SCREEN_BASE
expr_stmt|;
operator|*
operator|(
name|u_short
operator|*
operator|)
name|SCREEN_BASE
operator|=
literal|0x0F0F
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|u_short
operator|*
operator|)
name|SCREEN_BASE
operator|!=
literal|0x0F0F
condition|)
block|{
comment|/* 		 * Log error and exit 		 */
name|DeviceError
argument_list|(
literal|"apa8 color not found !!"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
operator|*
operator|(
name|u_short
operator|*
operator|)
name|SCREEN_BASE
operator|=
name|tmp
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Sets default foreground and background colors in   * video look-up table. FG_COLOR and BG_COLOR are default   * colors. They are defined in apa8c.h  */
end_comment

begin_expr_stmt
specifier|static
name|apa8c_set_colors
argument_list|()
block|{
specifier|register
name|i
block|;
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In apa8c_set_colors\n"
argument_list|)
block|;
name|fflush
argument_list|(
name|stderr
argument_list|)
block|;
endif|#
directive|endif
endif|TRACE_X
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|VLT_SIZE
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|i
operator|==
literal|15
condition|)
operator|*
operator|(
name|u_short
operator|*
operator|)
name|VLT_REG
operator|=
call|(
name|u_short
call|)
argument_list|(
name|i
operator||
name|FG_COLOR
argument_list|)
expr_stmt|;
else|else
operator|*
operator|(
name|u_short
operator|*
operator|)
name|VLT_REG
operator|=
call|(
name|u_short
call|)
argument_list|(
name|i
operator||
name|BG_COLOR
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

unit|}
end_unit

