begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)optab.c	5.1 (Berkeley) 4/4/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"optab.h"
end_include

begin_decl_stmt
name|struct
name|optab
name|optab
index|[]
init|=
block|{
define|#
directive|define
name|OP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|,
name|g
parameter_list|,
name|h
parameter_list|,
name|i
parameter_list|)
value|{a,b,c,d,e,f,g,h,i}
include|#
directive|include
file|"instrs.adb"
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|regname
index|[]
init|=
block|{
literal|"r0"
block|,
literal|"r1"
block|,
literal|"r2"
block|,
literal|"r3"
block|,
literal|"r4"
block|,
literal|"r5"
block|,
literal|"r6"
block|,
literal|"r7"
block|,
literal|"r8"
block|,
literal|"r9"
block|,
literal|"r10"
block|,
literal|"r11"
block|,
literal|"r12"
block|,
literal|"fp"
block|,
literal|"sp"
block|,
literal|"pc"
block|}
decl_stmt|;
end_decl_stmt

end_unit

