begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -fvisibility default -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g_com = common global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_def = global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_ext = external global i32' %t
end_comment

begin_comment
comment|// RUN: grep '@g_deferred = internal global' %t
end_comment

begin_comment
comment|// RUN: grep 'declare void @f_ext()' %t
end_comment

begin_comment
comment|// RUN: grep 'define internal void @f_deferred()' %t
end_comment

begin_comment
comment|// RUN: grep 'define i32 @f_def()' %t
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -fvisibility protected -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g_com = common protected global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_def = protected global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_ext = external global i32' %t
end_comment

begin_comment
comment|// RUN: grep '@g_deferred = internal global' %t
end_comment

begin_comment
comment|// RUN: grep 'declare void @f_ext()' %t
end_comment

begin_comment
comment|// RUN: grep 'define internal void @f_deferred()' %t
end_comment

begin_comment
comment|// RUN: grep 'define protected i32 @f_def()' %t
end_comment

begin_comment
comment|// RUN: clang-cc -triple i386-unknown-unknown -fvisibility hidden -emit-llvm -o %t %s
end_comment

begin_comment
comment|// RUN: grep '@g_com = common hidden global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_def = hidden global i32 0' %t
end_comment

begin_comment
comment|// RUN: grep '@g_ext = external global i32' %t
end_comment

begin_comment
comment|// RUN: grep '@g_deferred = internal global' %t
end_comment

begin_comment
comment|// RUN: grep 'declare void @f_ext()' %t
end_comment

begin_comment
comment|// RUN: grep 'define internal void @f_deferred()' %t
end_comment

begin_comment
comment|// RUN: grep 'define hidden i32 @f_def()' %t
end_comment

begin_decl_stmt
name|int
name|g_com
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|g_def
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_ext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|g_deferred
index|[]
init|=
literal|"hello"
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|f_ext
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|f_deferred
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|int
name|f_def
parameter_list|(
name|void
parameter_list|)
block|{
name|f_ext
argument_list|()
expr_stmt|;
name|f_deferred
argument_list|()
expr_stmt|;
return|return
name|g_com
operator|+
name|g_def
operator|+
name|g_ext
operator|+
name|g_deferred
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

