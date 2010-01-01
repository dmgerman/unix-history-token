begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// PR2360
end_comment

begin_typedef
typedef|typedef
name|void
name|fn_t
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|fn_t
name|a
decl_stmt|,
name|b
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|b
parameter_list|()
block|{ }
end_function

end_unit

