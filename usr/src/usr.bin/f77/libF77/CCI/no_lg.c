begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Computer Consoles Inc.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)no_lg.c	5.2 (Berkeley) %G%"
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
comment|/*  *	@(#)no_lg.c	1.2  *  *	ld -lg ...  * then /usr/lib/libg.a is loaded and defines _dbsubc as non-zero.  * Otherwise, this is loaded defining it as zero.  * in main.c, f77_abort() uses this to decide whether or not to call  * abort to terminate.  */
end_comment

begin_decl_stmt
name|char
name|id_no_lg
index|[]
init|=
literal|"@(#)no_lg.c	5.2"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_dbsubc
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

