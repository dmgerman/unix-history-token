begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -O0 -emit-llvm -S -o - | FileCheck %s
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

begin_comment
comment|// CHECK: call{{.*}}rb_define_global_function
end_comment

begin_comment
comment|// PR10335
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|JSErrorCallback
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|js_GetErrorMessage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|JS_ReportErrorNumber
parameter_list|(
name|JSErrorCallback
name|errorCallback
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|Interpret
parameter_list|()
block|{
name|JS_ReportErrorNumber
argument_list|(
name|js_GetErrorMessage
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call void ({{.*}}, ...)* @JS_ReportErrorNumber({{.*}}@js_GetErrorMessage
block|}
end_function

begin_comment
comment|// PR10337
end_comment

begin_struct
struct|struct
name|sigaction
block|{
name|int
function_decl|(
modifier|*
name|_sa_handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
name|SigHandler
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|sigaction
name|sighandler_cxt
typedef|;
end_typedef

begin_function
name|SigHandler
modifier|*
name|rl_set_sighandler
parameter_list|(
name|ohandler
parameter_list|)
name|sighandler_cxt
modifier|*
name|ohandler
decl_stmt|;
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|rl_set_signals
parameter_list|()
block|{
name|SigHandler
modifier|*
name|oh
decl_stmt|;
name|oh
operator|=
name|rl_set_sighandler
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

