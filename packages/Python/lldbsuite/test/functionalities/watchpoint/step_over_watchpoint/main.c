begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
name|g_watch_me_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|g_watch_me_write
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|g_temp
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|watch_read
parameter_list|()
block|{
name|g_temp
operator|=
name|g_watch_me_read
expr_stmt|;
block|}
end_function

begin_function
name|void
name|watch_write
parameter_list|()
block|{
name|g_watch_me_write
operator|=
name|g_temp
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|watch_read
argument_list|()
expr_stmt|;
name|g_temp
operator|=
name|g_watch_me_read
expr_stmt|;
name|watch_write
argument_list|()
expr_stmt|;
name|g_watch_me_write
operator|=
name|g_temp
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

