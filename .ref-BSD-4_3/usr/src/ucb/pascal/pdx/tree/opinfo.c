begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)opinfo.c	5.1 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Operator information structure.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"opinfo.h"
end_include

begin_decl_stmt
name|OPINFO
name|opinfo
index|[]
init|=
block|{
comment|/* O_NOP */
literal|0
block|,
literal|0
block|,
comment|/* O_NAME */
name|LEAF
block|,
literal|0
block|,
comment|/* O_QNAME */
name|LEAF
block|,
literal|"$"
block|,
comment|/* O_LCON */
name|LEAF
block|,
literal|0
block|,
comment|/* O_FCON */
name|LEAF
block|,
literal|0
block|,
comment|/* O_SCON */
name|LEAF
block|,
literal|0
block|,
comment|/* O_INDEX */
name|UNARY
block|,
literal|0
block|,
comment|/* O_INDIR */
name|UNARY
block|,
literal|"^"
block|,
comment|/* O_RVAL */
name|UNARY
block|,
literal|0
block|,
comment|/* O_COMMA */
name|BINARY
block|,
literal|","
block|,
comment|/* O_ITOF */
name|UNARY
operator||
name|INTOP
block|,
literal|0
block|,
comment|/* O_ADD */
name|BINARY
operator||
name|INTOP
block|,
literal|"+"
block|,
comment|/* O_ADDF */
name|BINARY
operator||
name|REALOP
block|,
literal|"+"
block|,
comment|/* O_SUB */
name|BINARY
operator||
name|INTOP
block|,
literal|"-"
block|,
comment|/* O_SUBF */
name|BINARY
operator||
name|REALOP
block|,
literal|"-"
block|,
comment|/* O_NEG */
name|UNARY
operator||
name|INTOP
block|,
literal|"-"
block|,
comment|/* O_NEGF */
name|UNARY
operator||
name|REALOP
block|,
literal|"-"
block|,
comment|/* O_MUL */
name|BINARY
operator||
name|INTOP
block|,
literal|"*"
block|,
comment|/* O_MULF */
name|BINARY
operator||
name|REALOP
block|,
literal|"*"
block|,
comment|/* O_DIVF */
name|BINARY
operator||
name|REALOP
block|,
literal|"/"
block|,
comment|/* O_DIV */
name|BINARY
operator||
name|INTOP
block|,
literal|" div "
block|,
comment|/* O_MOD */
name|BINARY
operator||
name|INTOP
block|,
literal|" mod "
block|,
comment|/* O_AND */
name|BINARY
operator||
name|INTOP
block|,
literal|" and "
block|,
comment|/* O_OR */
name|BINARY
operator||
name|INTOP
block|,
literal|" or "
block|,
comment|/* O_LT */
name|BINARY
operator||
name|INTOP
block|,
literal|"< "
block|,
comment|/* O_LTF */
name|BINARY
operator||
name|REALOP
block|,
literal|"< "
block|,
comment|/* O_LE */
name|BINARY
operator||
name|INTOP
block|,
literal|"<= "
block|,
comment|/* O_LEF */
name|BINARY
operator||
name|REALOP
block|,
literal|"<= "
block|,
comment|/* O_GT */
name|BINARY
operator||
name|INTOP
block|,
literal|"> "
block|,
comment|/* O_GTF */
name|BINARY
operator||
name|REALOP
block|,
literal|"> "
block|,
comment|/* O_GE */
name|BINARY
operator||
name|INTOP
block|,
literal|">= "
block|,
comment|/* O_GEF */
name|BINARY
operator||
name|REALOP
block|,
literal|">= "
block|,
comment|/* O_EQ */
name|BINARY
operator||
name|INTOP
block|,
literal|" = "
block|,
comment|/* O_EQF */
name|BINARY
operator||
name|REALOP
block|,
literal|" = "
block|,
comment|/* O_NE */
name|BINARY
operator||
name|INTOP
block|,
literal|"<> "
block|,
comment|/* O_NEF */
name|BINARY
operator||
name|REALOP
block|,
literal|"<> "
block|,
comment|/* O_ASSIGN */
name|BINARY
block|,
literal|" := "
block|,
comment|/* O_CHFILE */
literal|0
block|,
name|NIL
block|,
comment|/* O_CONT */
literal|0
block|,
name|NIL
block|,
comment|/* O_LIST */
literal|0
block|,
name|NIL
block|,
comment|/* O_NEXT */
literal|0
block|,
name|NIL
block|,
comment|/* O_PRINT */
literal|0
block|,
name|NIL
block|,
comment|/* O_STEP */
literal|0
block|,
name|NIL
block|,
comment|/* O_WHATIS */
literal|0
block|,
name|NIL
block|,
comment|/* O_WHERE */
literal|0
block|,
name|NIL
block|,
comment|/* O_XI */
literal|0
block|,
name|NIL
block|,
comment|/* O_XD */
literal|0
block|,
name|NIL
block|,
comment|/* O_CALL */
literal|0
block|,
name|NIL
block|,
comment|/* O_EDIT */
literal|0
block|,
name|NIL
block|,
comment|/* O_DUMP */
literal|0
block|,
name|NIL
block|,
comment|/* O_HELP */
literal|0
block|,
name|NIL
block|,
comment|/* O_REMAKE */
literal|0
block|,
name|NIL
block|,
comment|/* O_RUN */
literal|0
block|,
name|NIL
block|,
comment|/* O_SOURCE */
literal|0
block|,
name|NIL
block|,
comment|/* O_STATUS */
literal|0
block|,
name|NIL
block|,
comment|/* O_TRACE */
literal|0
block|,
name|NIL
block|,
comment|/* O_TRACEI */
literal|0
block|,
name|NIL
block|,
comment|/* O_STOP */
literal|0
block|,
name|NIL
block|,
comment|/* O_STOPI */
literal|0
block|,
name|NIL
block|,
comment|/* O_DELETE */
literal|0
block|,
name|NIL
block|,
comment|/* O_WHICH */
literal|0
block|,
name|NIL
block|,
comment|/* O_QLINE */
name|LEAF
block|,
name|NIL
block|,
comment|/* O_ALIAS */
name|LEAF
block|,
name|NIL
block|,
comment|/* O_GRIPE */
literal|0
block|,
name|NIL
block|, }
decl_stmt|;
end_decl_stmt

end_unit

