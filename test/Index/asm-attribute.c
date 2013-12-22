begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|int
name|foo
argument_list|(
name|int
name|x
argument_list|)
name|__asm__
argument_list|(
literal|"_foo_"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// RUN: c-index-test -test-load-source all %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: asm-attribute.c:1:5: FunctionDecl=foo:1:5 Extent=[1:1 - 1:32]
end_comment

begin_comment
comment|// CHECK: asm-attribute.c:1:24: asm label=_foo_ Extent=[1:24 - 1:31]
end_comment

end_unit

