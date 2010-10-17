begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|char
name|x_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|x_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|x_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|x_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|x_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|x_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|x_char_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|s_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|short
name|s_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|s_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|s_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|float
name|s_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|double
name|s_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|s_char_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|g_char
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|g_short
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g_int
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|g_long
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|g_float
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|g_double
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|g_char_p
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|x_char
operator|=
name|s_char
expr_stmt|;
name|g_char
operator|=
name|x_char
expr_stmt|;
name|x_short
operator|=
name|s_short
expr_stmt|;
name|g_short
operator|=
name|x_short
expr_stmt|;
name|x_int
operator|=
name|s_int
expr_stmt|;
name|g_int
operator|=
name|x_int
expr_stmt|;
name|x_long
operator|=
name|s_long
expr_stmt|;
name|g_long
operator|=
name|x_long
expr_stmt|;
name|x_float
operator|=
name|s_float
expr_stmt|;
name|g_float
operator|=
name|x_float
expr_stmt|;
name|x_double
operator|=
name|s_double
expr_stmt|;
name|g_double
operator|=
name|x_double
expr_stmt|;
name|x_char_p
operator|=
name|s_char_p
expr_stmt|;
name|g_char_p
operator|=
name|x_char_p
expr_stmt|;
block|}
end_function

end_unit

