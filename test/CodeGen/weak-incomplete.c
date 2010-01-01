begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm< %s | grep 'extern_weak' | count 1
end_comment

begin_struct_decl
struct_decl|struct
name|S
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|weak
operator|)
argument_list|)
name|foo1
argument_list|(
expr|struct
name|S
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|*
name|foo2
function_decl|)
parameter_list|(
name|struct
name|S
parameter_list|)
init|=
name|foo1
function_decl|;
end_function_decl

end_unit

