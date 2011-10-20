begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// END.
end_comment

begin_empty
empty|# 1 "t.c"
end_empty

begin_empty
empty|# 1 "<built-in>"
end_empty

begin_empty
empty|# 1 "<command-line>"
end_empty

begin_empty
empty|# 1 "t.c"
end_empty

begin_decl_stmt
name|int
name|__attribute
argument_list|(
operator|(
name|annotate
argument_list|(
literal|"foo"
argument_list|)
operator|)
argument_list|)
name|foo
argument_list|(
name|void
argument_list|)
block|{
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: private unnamed_addr constant [4 x i8] c"t.c\00"
end_comment

begin_comment
comment|// CHECK: @llvm.global.annotations = {{.*}}, i32 1 }
end_comment

end_unit

