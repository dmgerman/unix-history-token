begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)libI66.c	5.1	6/7/85  */
end_comment

begin_comment
comment|/*  * set flag to initialize fortran-66 mods  *  * usage: f77 ... -lI66 ...  */
end_comment

begin_include
include|#
directive|include
file|"fiodefs.h"
end_include

begin_decl_stmt
name|struct
name|ioiflg
name|ioiflg_
init|=
block|{
literal|0
block|,
comment|/* open files at beginning */
literal|1
block|,
comment|/* carriage control on all units */
literal|1
block|,
comment|/* blanks are zero on input; 0 => 0.0 on output */
block|}
decl_stmt|;
end_decl_stmt

end_unit

