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
literal|"@(#)SUBSCZ.c 1.4 11/12/82"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ESUBSC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ESUBSC is defined in SUBSCZ.c */
end_comment

begin_function
name|long
name|SUBSCZ
parameter_list|(
name|value
parameter_list|,
name|upper
parameter_list|)
name|long
name|value
decl_stmt|;
name|unsigned
name|long
name|upper
decl_stmt|;
block|{
if|if
condition|(
name|value
operator|>
name|upper
condition|)
block|{
name|ERROR
argument_list|(
name|ESUBSC
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return;
block|}
return|return
name|value
return|;
block|}
end_function

end_unit

