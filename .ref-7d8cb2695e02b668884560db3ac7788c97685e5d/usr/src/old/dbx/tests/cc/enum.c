begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
enum|enum
block|{
name|RED
block|,
name|GREEN
block|,
name|BLUE
block|}
name|Color
typedef|;
end_typedef

begin_function
name|main
parameter_list|()
block|{
name|Color
name|c
decl_stmt|;
name|c
operator|=
name|BLUE
expr_stmt|;
name|f
argument_list|(
name|RED
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|f
argument_list|(
argument|c
argument_list|)
end_macro

begin_decl_stmt
name|Color
name|c
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"c = %d\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

