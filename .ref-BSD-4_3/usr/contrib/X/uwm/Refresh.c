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
name|rcsid_Refresh_c
init|=
literal|"$Header: Refresh.c,v 10.3 86/02/01 16:23:41 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1986 by				*  *		Digital Equipment Corporation, Maynard, MA		*  *		         All Rights Reserved.				*  *									*  *	Permission to use, copy, modify, and distribute this software	*  *	and its documentation is hereby granted only to licensees of 	*  *	The Regents of the University of California pursuant to their	*  *	license agreement for the Berkeley Software Distribution 	*  *	provided that the following appears on all copies.		*  *									*  *            "LICENSED FROM DIGITAL EQUIPMENT CORPORATION		*  *                      COPYRIGHT (C) 1986				*	  *                 DIGITAL EQUIPMENT CORPORATION			*  *                         MAYNARD, MA					*  *                     ALL RIGHTS RESERVED.				*  *									*  *      THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT	*   *	NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL	*  *	EQUIPMENT CORPORATION.  DIGITAL MAKES NO REPRESENTATIONS	*  *	ABOUT SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE. IT IS	*  *	SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.		*  *									*	  * 	IF THE UNIVERSITY OF CALIFORNIA OR ITS LICENSEES MODIFY 	*	  *	THE SOFTWARE IN A MANNER CREATING DERIVATIVE COPYRIGHT 		*	  *	RIGHTS APPROPRIATE COPYRIGHT LEGENDS MAY BE PLACED ON THE	*  *	DERIVATIVE WORK IN ADDITION TO THAT SET FORTH ABOVE."		*	  *									*  ************************************************************************/
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
literal|"@(#)Refresh.c	3.8	1/24/86"
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
name|Refresh
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
name|WindowInfo
name|winfo
decl_stmt|;
comment|/* Root window info. */
name|Window
name|w
decl_stmt|;
comment|/* Refresh window. */
comment|/*      * Get info on the root window.      */
name|status
operator|=
name|XQueryWindow
argument_list|(
name|RootWindow
argument_list|,
operator|&
name|winfo
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|FAILURE
condition|)
name|Error
argument_list|(
literal|"Refresh -> Can't query root window."
argument_list|)
expr_stmt|;
comment|/*      * Create and map a window which covers the root window, then destroy it.      */
if|if
condition|(
operator|(
name|w
operator|=
name|XCreateWindow
argument_list|(
name|RootWindow
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|winfo
operator|.
name|width
argument_list|,
name|winfo
operator|.
name|height
argument_list|,
literal|0
argument_list|,
operator|(
name|Pixmap
operator|)
literal|0
argument_list|,
operator|(
name|Pixmap
operator|)
literal|0
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|Error
argument_list|(
literal|"Refresh -> Can't create refresh window."
argument_list|)
expr_stmt|;
name|XMapWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|XDestroyWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|XFlush
argument_list|()
expr_stmt|;
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_function

end_unit

