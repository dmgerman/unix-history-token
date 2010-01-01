begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -O0 -emit-llvm -S -o - | grep 'call.*rb_define_global_function'
end_comment

begin_comment
comment|// This should call rb_define_global_function, not rb_f_chop.
end_comment

begin_function_decl
name|void
name|rb_define_global_function
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|()
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|rb_f_chop
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|Init_String
parameter_list|()
block|{
name|rb_define_global_function
argument_list|(
literal|"chop"
argument_list|,
name|rb_f_chop
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|rb_f_chop
parameter_list|()
block|{ }
end_function

end_unit

