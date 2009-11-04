begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -x c-header -o %t.pch %s&&
end_comment

begin_comment
comment|// RUN: echo> %t.empty.c&&
end_comment

begin_comment
comment|// RUN: clang -include %t -x c %t.empty.c -emit-llvm -S -o -
end_comment

begin_comment
comment|// PR 4489: Crash with PCH
end_comment

begin_comment
comment|// PR 4492: Crash with PCH (round two)
end_comment

begin_comment
comment|// PR 4509: Crash with PCH (round three)
end_comment

begin_typedef
typedef|typedef
name|struct
name|_IO_FILE
name|FILE
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|fprintf
parameter_list|(
name|struct
name|_IO_FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|x
parameter_list|(
name|void
parameter_list|)
block|{
switch|switch
condition|(
literal|1
condition|)
block|{
case|case
literal|2
case|:
empty_stmt|;
name|int
name|y
init|=
literal|0
decl_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|y
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|char
name|z
decl_stmt|;
name|fprintf
argument_list|(
literal|0
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|y0
block|{
name|int
name|i
decl_stmt|;
block|}
name|y0
index|[
literal|1
index|]
init|=
block|{}
struct|;
end_struct

begin_function
name|void
name|x0
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|char
name|z0
decl_stmt|;
name|fprintf
argument_list|(
literal|0
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|x1
parameter_list|(
name|void
parameter_list|)
block|{
name|fprintf
argument_list|(
literal|0
argument_list|,
literal|"asdf"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|y1
parameter_list|(
name|void
parameter_list|)
block|{
specifier|extern
name|char
name|e
decl_stmt|;
name|fprintf
argument_list|(
literal|0
argument_list|,
literal|"asdf"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

