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
literal|"@(#)DEFNAME.c 1.2 3/7/81"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_expr_stmt
name|DEFNAME
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
specifier|register
expr|struct
name|iorec
operator|*
name|filep
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|maxnamlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|datasize
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|filep
operator|=
name|GETNAME
argument_list|(
name|filep
argument_list|,
name|name
argument_list|,
name|maxnamlen
argument_list|,
name|datasize
argument_list|)
expr_stmt|;
name|filep
operator|->
name|funit
operator||=
name|FDEF
expr_stmt|;
block|}
end_block

end_unit

