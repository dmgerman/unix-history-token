begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ast-print | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|void
name|func_typedef
parameter_list|()
function_decl|;
end_typedef

begin_decl_stmt
name|func_typedef
name|xxx
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|func_t
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|func_t
name|a
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|blah
block|{
struct|struct
block|{
struct|struct
block|{
name|int
name|b
decl_stmt|;
block|}
struct|;
block|}
struct|;
block|}
struct|;
end_struct

begin_function
name|int
name|foo
parameter_list|(
specifier|const
name|struct
name|blah
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK: return b->b;
return|return
name|b
operator|->
name|b
return|;
block|}
end_function

end_unit

