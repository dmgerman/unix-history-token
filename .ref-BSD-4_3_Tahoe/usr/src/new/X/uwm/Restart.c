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
name|rcsid_Restart_c
init|=
literal|"$Header: Restart.c,v 10.4 86/11/19 16:24:40 jg Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/*  *			COPYRIGHT 1985, 1986  *		   DIGITAL EQUIPMENT CORPORATION  *		       MAYNARD, MASSACHUSETTS  *			ALL RIGHTS RESERVED.  *  * THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND  * SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL EQUIPMENT CORPORATION.  * DIGITAL MAKES NO REPRESENTATIONS ABOUT THE SUITIBILITY OF THIS SOFTWARE FOR  * ANY PURPOSE.  IT IS SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.  *  * IF THE SOFTWARE IS MODIFIED IN A MANNER CREATING DERIVATIVE COPYRIGHT RIGHTS,  * APPROPRIATE LEGENDS MAY BE PLACED ON THE DERIVATIVE WORK IN ADDITION TO THAT  * SET FORTH ABOVE.  *  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting documentation,  * and that the name of Digital Equipment Corporation not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission.  *  */
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)Restart.c	3.8	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uwm.h"
end_include

begin_function
name|Bool
name|Restart
parameter_list|(
name|window
parameter_list|,
name|mask
parameter_list|,
name|button
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
name|Window
name|window
decl_stmt|;
comment|/* Event window. */
name|int
name|mask
decl_stmt|;
comment|/* Button/key mask. */
name|short
name|button
decl_stmt|;
comment|/* Button event detail. */
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Event mouse position. */
block|{
name|XButtonEvent
name|button_event
decl_stmt|;
name|XFeep
argument_list|(
name|Volume
argument_list|)
expr_stmt|;
name|XFeep
argument_list|(
name|Volume
argument_list|)
expr_stmt|;
name|XFlush
argument_list|()
expr_stmt|;
name|execvp
argument_list|(
operator|*
name|Argv
argument_list|,
name|Argv
argument_list|,
name|Environ
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uwm: Restart failed!\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

