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
name|rcsid_Bindings_c
init|=
literal|"$Header: Bindings.c,v 10.3 86/02/01 16:22:39 tony Rel $"
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
literal|"@(#)Bindings.c	3.8	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bindings.c 	Default bindings for the X window manager 'uwm'  *  * Note: Any changes to this file should also be added to the file  * /usr/new/lib/X/uwm/default.uwmrc to keep users informed as to the bindings  * contained herein.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|DefaultBindings
index|[]
init|=
block|{
literal|"autoselect;delta=25;freeze;grid;hiconpad=5;hmenupad=6;iconfont=oldengssx"
block|,
literal|"menufont=timrom12b;resizefont=9x15;viconpad=5;vmenupad=3;volume=7"
block|,
literal|"f.menu=m::l d:\"WINDOW OPS\""
block|,
literal|"f.menu=m::m d:\"EXTENDED WINDOW OPS\""
block|,
literal|"f.move=m:w|i:r d"
block|,
literal|"f.circleup=m:r:r d"
block|,
literal|"menu=\"WINDOW OPS\" {"
block|,
literal|"\"(De)Iconify\":f.iconify"
block|,
literal|"Move:f.move"
block|,
literal|"Resize:f.resize"
block|,
literal|"Lower:f.lower"
block|,
literal|"Raise:f.raise"
block|,
literal|"}"
block|,
literal|"menu=\"EXTENDED WINDOW OPS\"{"
block|,
literal|"Create Window:!\"xterm&\""
block|,
literal|"Iconify at New Position:f.newiconify"
block|,
literal|"Focus Keyboard on Window:f.focus"
block|,
literal|"Freeze All Windows:f.pause"
block|,
literal|"Unfreeze All Windows:f.continue"
block|,
literal|"Circulate Windows Up:f.circleup"
block|,
literal|"Circulate Windows Down:f.circledown"
block|,
literal|"}"
block|,
literal|0
comment|/* Must NOT be removed. */
block|}
decl_stmt|;
end_decl_stmt

end_unit

