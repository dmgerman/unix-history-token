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
name|rcsid_apa16_c
init|=
literal|"$Header: apa16.c,v 10.1 86/11/19 10:39:18 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* apa16.c - APA16 controller initialization  *  * 	apa16_init	APA16 initialization routine  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
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
file|"apa16.h"
end_include

begin_comment
comment|/*  * Initialize APA16  */
end_comment

begin_macro
name|apa16_init
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In apa16_init\n"
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
comment|/*          * Initialize (reset) the APA16 screen          */
name|RESET_APA16
argument_list|()
expr_stmt|;
operator|*
operator|(
name|short
operator|*
operator|)
name|MR
operator|=
name|MR_DEFAULT
expr_stmt|;
operator|*
operator|(
name|short
operator|*
operator|)
name|CSR
operator|=
name|WHITE_ON_BLACK
expr_stmt|;
name|ENABLE_VD_OUT
argument_list|()
expr_stmt|;
comment|/*          * Test for the APA16 screen.          */
operator|*
operator|(
name|char
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
name|char
operator|*
operator|)
name|SCREEN_BASE
operator|!=
literal|0x0F
condition|)
block|{
comment|/* 		 * Log error and exit 		 */
name|DeviceError
argument_list|(
literal|"apa16 not found !!"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

