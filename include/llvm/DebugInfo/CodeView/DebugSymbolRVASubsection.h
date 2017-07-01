begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugSymbolRVASubsection.h -------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSYMBOLRVASUBSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_DEBUGSYMBOLRVASUBSECTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|namespace
name|codeview
block|{
name|class
name|DebugSymbolRVASubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|public
operator|:
name|using
name|ArrayType
operator|=
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
block|;
name|DebugSymbolRVASubsectionRef
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsectionRef *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|CoffSymbolRVA
return|;
block|}
name|ArrayType
operator|::
name|Iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|RVAs
operator|.
name|begin
argument_list|()
return|;
block|}
name|ArrayType
operator|::
name|Iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|RVAs
operator|.
name|end
argument_list|()
return|;
block|}
name|Error
name|initialize
argument_list|(
name|BinaryStreamReader
operator|&
name|Reader
argument_list|)
block|;
name|private
operator|:
name|ArrayType
name|RVAs
block|; }
decl_stmt|;
name|class
name|DebugSymbolRVASubsection
name|final
range|:
name|public
name|DebugSubsection
block|{
name|public
operator|:
name|DebugSymbolRVASubsection
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DebugSubsection *S
argument_list|)
block|{
return|return
name|S
operator|->
name|kind
argument_list|()
operator|==
name|DebugSubsectionKind
operator|::
name|CoffSymbolRVA
return|;
block|}
name|Error
name|commit
argument_list|(
argument|BinaryStreamWriter&Writer
argument_list|)
specifier|const
name|override
block|;
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
name|override
block|;
name|void
name|addRVA
argument_list|(
argument|uint32_t RVA
argument_list|)
block|{
name|RVAs
operator|.
name|push_back
argument_list|(
name|support
operator|::
name|ulittle32_t
argument_list|(
name|RVA
argument_list|)
argument_list|)
block|; }
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|RVAs
block|; }
decl_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_DEBUGSYMBOLRVASUBSECTION_H
end_comment

end_unit

