begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- YamlSerializationContext.h ----------------------------- *- C++ --*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLSERIALIZATIONCONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLSERIALIZATIONCONTEXT_H
end_define

begin_include
include|#
directive|include
file|"PdbYaml.h"
end_include

begin_include
include|#
directive|include
file|"YamlTypeDumper.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeSerializer
decl_stmt|;
block|}
name|namespace
name|yaml
block|{
name|class
name|IO
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|namespace
name|yaml
block|{
struct|struct
name|SerializationContext
block|{
name|explicit
name|SerializationContext
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|IO
operator|&
name|IO
argument_list|,
name|BumpPtrAllocator
operator|&
name|Allocator
argument_list|)
range|:
name|Dumper
argument_list|(
name|IO
argument_list|,
operator|*
name|this
argument_list|)
decl_stmt|,
name|Allocator
argument_list|(
name|Allocator
argument_list|)
block|{}
name|codeview
operator|::
name|yaml
operator|::
name|YamlTypeDumperCallbacks
name|Dumper
expr_stmt|;
name|BumpPtrAllocator
modifier|&
name|Allocator
decl_stmt|;
name|codeview
operator|::
name|TypeSerializer
operator|*
name|ActiveSerializer
operator|=
name|nullptr
expr_stmt|;
block|}
struct|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

