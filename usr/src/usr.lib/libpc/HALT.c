begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)HALT.c 1.3 6/10/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|HALT
argument_list|()
end_macro

begin_block
block|{
name|PFLUSH
argument_list|()
expr_stmt|;
name|fputs
argument_list|(
literal|"Call to procedure halt\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|PCEXIT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

