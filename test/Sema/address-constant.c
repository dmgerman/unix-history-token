begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|a
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|s
struct|;
end_struct

begin_decl_stmt
name|int
modifier|*
name|array
index|[]
init|=
block|{
operator|&
name|i
block|,
name|a
block|,
operator|&
name|s
operator|.
name|i
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
function_decl|(
modifier|*
name|f_addr
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|&
name|f
function_decl|;
end_function_decl

end_unit

