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
literal|"@(#)FSAV.c 1.4 11/12/82"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_decl_stmt
name|struct
name|formalrtn
modifier|*
name|FSAV
argument_list|(
name|entryaddr
argument_list|,
name|cbn
argument_list|,
name|frtn
argument_list|)
name|long
argument_list|(
operator|*
name|entryaddr
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|cbn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|formalrtn
modifier|*
name|frtn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|frtn
operator|->
name|fentryaddr
operator|=
name|entryaddr
expr_stmt|;
name|frtn
operator|->
name|fbn
operator|=
name|cbn
expr_stmt|;
name|blkcpy
argument_list|(
operator|&
name|_disply
index|[
literal|1
index|]
argument_list|,
operator|&
name|frtn
operator|->
name|fdisp
index|[
literal|0
index|]
argument_list|,
name|frtn
operator|->
name|fbn
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|display
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|frtn
return|;
block|}
end_block

end_unit

