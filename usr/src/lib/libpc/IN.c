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
literal|"@(#)IN.c 1.1 10/29/80"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_macro
name|IN
argument_list|(
argument|element
argument_list|,
argument|lower
argument_list|,
argument|upper
argument_list|,
argument|setptr
argument_list|)
end_macro

begin_decl_stmt
name|int
name|element
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* element to check */
end_comment

begin_decl_stmt
name|int
name|lower
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lowest element of set */
end_comment

begin_decl_stmt
name|int
name|upper
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* upper - lower of set */
end_comment

begin_decl_stmt
name|char
name|setptr
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to set */
end_comment

begin_block
block|{
name|int
name|indx
decl_stmt|;
if|if
condition|(
operator|(
name|indx
operator|=
name|element
operator|-
name|lower
operator|)
operator|<
literal|0
operator|||
name|indx
operator|>
name|upper
condition|)
return|return
name|FALSE
return|;
if|if
condition|(
name|setptr
index|[
name|indx
operator|/
name|BITSPERBYTE
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|indx
operator|%
name|BITSPERBYTE
operator|)
operator|)
condition|)
return|return
name|TRUE
return|;
return|return
name|FALSE
return|;
block|}
end_block

end_unit

