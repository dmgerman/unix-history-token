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
name|rcsid_apa8_c
init|=
literal|"$Header: apa8.c,v 10.1 86/11/19 10:39:37 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  * apa8.c		device initialization  *  * 	apa8_init	apa8 initialization routine  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
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
file|"apa8.h"
end_include

begin_macro
name|apa8_init
argument_list|()
end_macro

begin_block
block|{
name|u_char
name|tmp
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In apa8_init\n"
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
comment|/*          * Initialize (reset) the APA-8 screen          */
comment|/* 	 * Set up the write and data mask. 	 */
name|SET_WRITEMASK
argument_list|(
name|NOMASK
argument_list|)
expr_stmt|;
name|SET_DATAMASK
argument_list|(
name|HIDDEN_DM
argument_list|)
expr_stmt|;
comment|/* 	 * Set up the APA8 control register to use its system read/write 	 * calls in the X direction. 	 */
name|SET_FC
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
comment|/*          * Test for the APA8 screen.          */
name|tmp
operator|=
operator|*
operator|(
name|u_char
operator|*
operator|)
name|SCREEN_BASE
expr_stmt|;
operator|*
operator|(
name|u_char
operator|*
operator|)
name|SCREEN_BASE
operator|=
literal|0x0F
expr_stmt|;
if|if
condition|(
operator|*
operator|(
name|u_char
operator|*
operator|)
name|SCREEN_BASE
operator|!=
literal|0x0F
condition|)
block|{
name|DeviceError
argument_list|(
literal|"apa8 not found !!"
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
name|u_char
operator|*
operator|)
name|SCREEN_BASE
operator|=
name|tmp
expr_stmt|;
block|}
end_block

end_unit

