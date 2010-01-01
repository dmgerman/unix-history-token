begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o %t
end_comment

begin_function_decl
specifier|static
name|int
name|staticfun
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|*
name|staticuse1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|staticfun
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|staticfun
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function_decl
name|int
function_decl|(
modifier|*
name|staticuse2
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|staticfun
function_decl|;
end_function_decl

end_unit

