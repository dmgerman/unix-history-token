begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1984-1987 by the Regents of the  *	University of California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
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
literal|"@(#)oia.c	3.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Routines to maintain the Operator Information Area.  */
end_comment

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_include
include|#
directive|include
file|"oia.h"
end_include

begin_include
include|#
directive|include
file|"../general/globals.h"
end_include

begin_macro
name|init_oia
argument_list|()
end_macro

begin_block
block|{
name|ClearElement
argument_list|(
name|OperatorInformationArea
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

