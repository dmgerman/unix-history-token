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
name|rcsid_aed_c
init|=
literal|"$Header: aed.c,v 10.1 86/11/19 10:38:53 jg Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/* aed.c - AED display initialization routine  *  *	aed_init	Display initialization routine  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software   * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_comment
comment|/*  * Initialize AED  */
end_comment

begin_macro
name|aed_init
argument_list|()
end_macro

begin_block
block|{
name|int
modifier|*
name|color
init|=
operator|(
name|int
operator|*
operator|)
name|AED_COLOR
decl_stmt|;
ifdef|#
directive|ifdef
name|TRACE_X
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"In aed_init\n"
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
comment|/* 	 * Set forground/background colors to match X 	 */
operator|*
name|color
operator|=
name|WHITE_ON_BLACK
expr_stmt|;
comment|/* 	 * Clear off-screen bitmap 	 */
name|bzero
argument_list|(
operator|(
name|caddr_t
operator|)
name|SCREEN_BASE
argument_list|,
name|SCREEN_BM_SIZE
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

