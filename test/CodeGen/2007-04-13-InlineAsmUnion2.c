begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s
end_comment

begin_union
union|union
name|U
block|{
name|int
name|x
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|foo
parameter_list|()
block|{
name|union
name|U
name|bar
decl_stmt|;
comment|// CHECK: call void asm
asm|__asm__
specifier|volatile
asm|("foo %0\n" :: "r"(bar));
block|}
end_function

end_unit

