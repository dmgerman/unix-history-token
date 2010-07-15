begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|one
decl_stmt|;
name|int
name|two
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|S
specifier|const
name|foo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|S
name|tmp
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|priv_sock_init
parameter_list|()
block|{
name|tmp
operator|=
operator|(
expr|struct
name|S
operator|)
name|foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

