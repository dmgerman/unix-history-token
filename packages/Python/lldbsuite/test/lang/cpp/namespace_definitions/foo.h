begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- foo.h ---------------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|class
name|ThingInside
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|Foo
block|{
name|class
name|MyClass
block|{
name|ThingInside
modifier|*
name|thing
decl_stmt|;
name|public
label|:
name|MyClass
argument_list|()
block|{ }
block|}
empty_stmt|;
block|}
end_decl_stmt

end_unit

