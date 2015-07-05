begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-pc-linux -emit-llvm %s -o - | FileCheck %s
end_comment

begin_decl_stmt
specifier|extern
name|void
name|foo_alias
argument_list|(
name|void
argument_list|)
asm|__asm ("foo");
specifier|inline
namespace|void
name|foo
namespace|(
name|void
decl_stmt|)
block|{
return|return
name|foo_alias
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|abs_alias
argument_list|(
name|int
argument_list|)
asm|__asm ("abs");
specifier|inline
namespace|__attribute__ ((
name|__always_inline__
decl_stmt|)
end_decl_stmt

begin_function
unit|)
name|int
name|abs
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|abs_alias
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strrchr_foo
argument_list|(
specifier|const
name|char
operator|*
name|__s
argument_list|,
name|int
name|__c
argument_list|)
asm|__asm ("strrchr");
decl|extern
specifier|inline
namespace|__attribute__ ((
name|__always_inline__
decl_stmt|)
end_decl_stmt

begin_macro
unit|)
name|__attribute__
argument_list|(
argument|(__gnu_inline__)
argument_list|)
end_macro

begin_function
name|char
modifier|*
name|strrchr_foo
parameter_list|(
specifier|const
name|char
modifier|*
name|__s
parameter_list|,
name|int
name|__c
parameter_list|)
block|{
return|return
name|__builtin_strrchr
argument_list|(
name|__s
argument_list|,
name|__c
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|extern
specifier|inline
name|void
name|__attribute__
argument_list|(
operator|(
name|always_inline
operator|,
name|__gnu_inline__
operator|)
argument_list|)
name|prefetch
argument_list|(
name|void
argument_list|)
block|{
name|__builtin_prefetch
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_extern
extern|extern
specifier|inline
namespace|__attribute__((
name|__always_inline__
operator|,
name|__gnu_inline__
end_extern

begin_function
unit|))
name|void
modifier|*
name|memchr
parameter_list|(
name|void
modifier|*
name|__s
parameter_list|,
name|int
name|__c
parameter_list|,
name|__SIZE_TYPE__
name|__n
parameter_list|)
block|{
return|return
name|__builtin_memchr
argument_list|(
name|__s
argument_list|,
name|__c
argument_list|,
name|__n
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|foo
argument_list|()
expr_stmt|;
name|abs
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|strrchr_foo
argument_list|(
literal|""
argument_list|,
literal|'.'
argument_list|)
expr_stmt|;
name|prefetch
argument_list|()
expr_stmt|;
name|memchr
argument_list|(
literal|""
argument_list|,
literal|'.'
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @f()
end_comment

begin_comment
comment|// CHECK: call void @foo()
end_comment

begin_comment
comment|// CHECK: call i32 @abs(i32 0)
end_comment

begin_comment
comment|// CHECK: call i8* @strrchr(
end_comment

begin_comment
comment|// CHECK: call void @llvm.prefetch(
end_comment

begin_comment
comment|// CHECK: call i8* @memchr(
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// CHECK: declare void @foo()
end_comment

begin_comment
comment|// CHECK: declare i32 @abs(i32
end_comment

begin_comment
comment|// CHECK: declare i8* @strrchr(i8*, i32)
end_comment

begin_comment
comment|// CHECK: declare i8* @memchr(
end_comment

begin_comment
comment|// CHECK: declare void @llvm.prefetch(
end_comment

end_unit

