begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo0", {{.*}} [[READNONE:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo1", {{.*}} [[READNONE]]
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo2", {{.*}} [[NOATTRS:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: call i32 asm sideeffect "foo3", {{.*}} [[NOATTRS]]
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo4", {{.*}} [[READONLY:#[0-9]+]]
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo5", {{.*}} [[READONLY]]
end_comment

begin_comment
comment|// CHECK: call i32 asm "foo6", {{.*}} [[NOATTRS]]
end_comment

begin_comment
comment|// CHECK: call void asm sideeffect "foo7", {{.*}} [[NOATTRS]]
end_comment

begin_comment
comment|// CHECK: call void asm "foo8", {{.*}} [[NOATTRS]]
end_comment

begin_comment
comment|// CHECK: attributes [[READNONE]] = { nounwind readnone }
end_comment

begin_comment
comment|// CHECK: attributes [[NOATTRS]] = { nounwind }
end_comment

begin_comment
comment|// CHECK: attributes [[READONLY]] = { nounwind readonly }
end_comment

begin_decl_stmt
name|int
name|g0
decl_stmt|,
name|g1
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|S
block|{
name|int
name|i
decl_stmt|;
block|}
name|g2
struct|;
end_struct

begin_function
name|void
name|test_attrs
parameter_list|(
name|int
name|a
parameter_list|)
block|{
asm|__asm__ ("foo0" : "=r"(g1) : "r"(a));
asm|__asm__ ("foo1" : "=r"(g1) : "r"(a) : "cc");
asm|__asm__ ("foo2" : "=r"(g1) : "r"(a) : "memory");
asm|__asm__
specifier|volatile
asm|("foo3" : "=r"(g1) : "r"(a));
asm|__asm__ ("foo4" : "=r"(g1) : "r"(a), "m"(g0));
asm|__asm__ ("foo5" : "=r"(g1) : "r"(a), "Q"(g0));
asm|__asm__ ("foo6" : "=r"(g1), "=m"(g0) : "r"(a));
asm|__asm__ ("foo7" : : "r"(a));
asm|__asm__ ("foo8" : "=r"(g2) : "r"(a));
block|}
end_function

end_unit

