begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_decl_stmt
name|int
name|A
index|[
literal|10
index|]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|5
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x
index|[]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|x
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|x
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|bar
parameter_list|()
block|{
name|x
index|[
literal|0
index|]
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|y
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|g
init|=
name|y
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|latin_ptr2len
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|mb_ptr2len
function_decl|)
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
init|=
name|latin_ptr2len
function_decl|;
end_function_decl

begin_decl_stmt
name|char
name|string
index|[
literal|8
index|]
init|=
literal|"string"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// extend init
end_comment

begin_decl_stmt
name|char
name|string2
index|[
literal|4
index|]
init|=
literal|"string"
decl_stmt|;
end_decl_stmt

begin_comment
comment|// truncate init
end_comment

begin_function
name|char
modifier|*
name|test
parameter_list|(
name|int
name|c
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|10
index|]
decl_stmt|;
specifier|static
name|char
modifier|*
name|bufptr
init|=
name|buf
decl_stmt|;
return|return
name|c
condition|?
name|buf
else|:
name|bufptr
return|;
block|}
end_function

begin_decl_stmt
name|_Bool
name|booltest
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|booltest2
parameter_list|()
block|{
specifier|static
name|_Bool
name|booltest3
init|=
literal|4
decl_stmt|;
block|}
end_function

begin_comment
comment|// Scalars in braces.
end_comment

begin_decl_stmt
specifier|static
name|int
name|a
init|=
block|{
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// References to enums.
end_comment

begin_enum
enum|enum
block|{
name|EnumA
block|,
name|EnumB
block|}
enum|;
end_enum

begin_decl_stmt
name|int
name|c
index|[]
init|=
block|{
name|EnumA
block|,
name|EnumB
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Binary operators
end_comment

begin_decl_stmt
name|int
name|d
index|[]
init|=
block|{
name|EnumA
operator||
name|EnumB
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// PR1968
end_comment

begin_decl_stmt
specifier|static
name|int
name|array
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|array
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

end_unit

