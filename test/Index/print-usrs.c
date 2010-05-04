begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -print-usr-file %s | FileCheck %s
end_comment

begin_comment
comment|// This isn't really C code; it has a .c extension to get picked up by lit.
end_comment

begin_decl_stmt
name|ObjCClass
name|NSObject
name|ObjCCategory
name|NSObject
name|foo
name|ObjCIvar
name|x
name|c
range|:
name|objc
argument_list|(
argument|cs
argument_list|)
name|NSObject
name|ObjCMethod
name|foo
operator|:
literal|0
name|c
operator|:
name|objc
argument_list|(
argument|cs
argument_list|)
name|NSObject
name|ObjCMethod
name|baz
operator|:
name|with
literal|1
name|c
operator|:
name|objc
argument_list|(
argument|cs
argument_list|)
name|NSObject
name|ObjCProperty
name|gimme
name|c
operator|:
name|objc
argument_list|(
argument|cs
argument_list|)
name|NSObject
name|ObjCProtocol
name|blah
end_decl_stmt

begin_comment
comment|// CHECK: c:objc(cs)NSObject
end_comment

begin_comment
comment|// CHECK: c:objc(cy)NSObject@foo
end_comment

begin_comment
comment|// CHECK: c:objc(cs)NSObject@x
end_comment

begin_comment
comment|// CHECK: c:objc(cs)NSObject(cm)foo:
end_comment

begin_comment
comment|// CHECK: c:objc(cs)NSObject(im)baz:with
end_comment

begin_comment
comment|// CHECK: c:objc(cs)NSObject(py)gimme
end_comment

begin_comment
comment|// CHECK: c:objc(pl)blah
end_comment

end_unit

