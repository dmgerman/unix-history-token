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
file|"../ascii/ascebc.h"
end_include

begin_include
include|#
directive|include
file|"../ctlr/dctype.h"
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

begin_include
include|#
directive|include
file|"../keyboard/state.h"
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

end_unit

