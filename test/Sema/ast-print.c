begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ast-print
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

end_unit

