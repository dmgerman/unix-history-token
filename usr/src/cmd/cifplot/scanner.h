begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|CharNo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in_buf[CharNo] is the current char being read */
end_comment

begin_decl_stmt
name|int
name|LineNo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current line number */
end_comment

begin_decl_stmt
name|int
name|in_buf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current allocation for in_buf */
end_comment

begin_decl_stmt
name|char
modifier|*
name|in_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer holding current input line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|in_store
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Buffer to store previous line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|CurrentFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of current input file */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|maxlines
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OldLength
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of previous line of input */
end_comment

begin_decl_stmt
name|int
name|FStackPtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|FileName
index|[
name|FStackSize
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|in_file
index|[
name|FStackSize
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|argb
decl_stmt|,
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

end_unit

