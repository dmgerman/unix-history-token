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
name|rcsid_Error_c
init|=
literal|"$Header: Error.c,v 10.3 86/02/01 16:22:48 tony Rel $"
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
literal|"@(#)Error.c	3.8	1/24/86"
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

begin_comment
comment|/*  * Default error reporting routine.  Called when a random uwm error  * is encountered.  */
end_comment

begin_macro
name|Error
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error description string */
end_comment

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"uwm: %s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

