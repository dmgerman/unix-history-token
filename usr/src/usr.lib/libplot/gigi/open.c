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
literal|"@(#)open.c	5.1 (Berkeley) 5/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Displays plot files on a gigi "graphics" terminal.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"gigi.h"
end_include

begin_decl_stmt
name|int
name|currentx
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|currenty
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lowx
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|lowy
init|=
literal|0.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|scalex
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|scaley
init|=
literal|1.0
decl_stmt|;
end_decl_stmt

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|int
name|closepl
parameter_list|()
function_decl|;
comment|/* catch interupts */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|closepl
argument_list|)
expr_stmt|;
name|currentx
operator|=
literal|0
expr_stmt|;
name|currenty
operator|=
literal|0
expr_stmt|;
comment|/* enter grapics mode */
name|putchar
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'P'
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'p'
argument_list|)
expr_stmt|;
comment|/* set some parameters */
name|printf
argument_list|(
literal|"S(I0 T0 [0,0])"
argument_list|)
expr_stmt|;
name|space
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|XMAX
argument_list|,
name|YMAX
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

