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
name|void
name|bar_alias
argument_list|(
name|void
argument_list|)
asm|__asm ("bar");
specifier|inline
namespace|__attribute__ ((
name|__always_inline__
decl_stmt|)
end_decl_stmt

begin_function
unit|)
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|bar_alias
argument_list|()
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
name|bar
argument_list|()
expr_stmt|;
name|strrchr_foo
argument_list|(
literal|""
argument_list|,
literal|'.'
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
comment|// CHECK-NEXT: call void @bar()
end_comment

begin_comment
comment|// CHECK-NEXT: call i8* @strrchr(
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK: declare void @foo()
end_comment

begin_comment
comment|// CHECK: declare void @bar()
end_comment

begin_comment
comment|// CHECK: declare i8* @strrchr(i8*, i32)
end_comment

end_unit

