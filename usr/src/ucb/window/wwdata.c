begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)wwdata.c	3.14 4/24/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_decl_stmt
name|int
name|wwbaudmap
index|[]
init|=
block|{
literal|0
block|,
literal|50
block|,
literal|75
block|,
literal|110
block|,
literal|134
block|,
literal|150
block|,
literal|200
block|,
literal|300
block|,
literal|600
block|,
literal|1200
block|,
literal|1800
block|,
literal|2400
block|,
literal|4800
block|,
literal|9600
block|,
literal|19200
block|,
literal|38400
block|}
decl_stmt|;
end_decl_stmt

end_unit

