begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1984, 1985, 1986 by the Regents of the  *	University of California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
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
literal|"@(#)globals.c	3.1  10/29/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef lint */
end_comment

begin_comment
comment|/*  *	Do the defining instances for the globals of tn3270.  */
end_comment

begin_include
include|#
directive|include
file|"../ctlr/hostctlr.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/oia.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/options.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/screen.h"
end_include

begin_define
define|#
directive|define
name|DEFINING_INSTANCES
end_define

begin_include
include|#
directive|include
file|"globals.h"
end_include

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_comment
comment|/*  * init_system()  *  * Initialize the global values in case of a restart.  */
end_comment

begin_function
name|void
name|init_system
parameter_list|()
block|{
name|OptHome
operator|=
name|OptLeftMargin
operator|=
name|OptAPLmode
operator|=
name|OptNullProcessing
operator|=
literal|0
expr_stmt|;
name|OptZonesMode
operator|=
name|OptEnterNL
operator|=
name|OptColFieldTab
operator|=
name|OptPacing
operator|=
literal|0
expr_stmt|;
name|OptAlphaInNumeric
operator|=
name|OptHome
operator|=
name|OptLeftMargin
operator|=
name|OptWordWrap
operator|=
literal|0
expr_stmt|;
name|ClearArray
argument_list|(
name|Host
argument_list|)
expr_stmt|;
name|CursorAddress
operator|=
name|BufferAddress
operator|=
literal|0
expr_stmt|;
name|Lowest
operator|=
name|Highest
operator|=
literal|0
expr_stmt|;
name|UnLocked
operator|=
name|AidByte
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

