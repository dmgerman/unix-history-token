begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- C13DebugFragmentVisitor.h - Visitor for CodeView Info ----*- C++ -*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_C13DEBUGFRAGMENTVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_C13DEBUGFRAGMENTVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugChecksumsSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsectionVisitor.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
name|namespace
name|pdb
block|{
name|class
name|PDBFile
decl_stmt|;
name|class
name|C13DebugFragmentVisitor
range|:
name|public
name|codeview
operator|::
name|DebugSubsectionVisitor
block|{
name|public
operator|:
name|C13DebugFragmentVisitor
argument_list|(
name|PDBFile
operator|&
name|F
argument_list|)
block|;
operator|~
name|C13DebugFragmentVisitor
argument_list|()
block|;
name|Error
name|visitUnknown
argument_list|(
argument|codeview::DebugUnknownSubsectionRef&Fragment
argument_list|)
name|final
block|;
name|Error
name|visitFileChecksums
argument_list|(
argument|codeview::DebugChecksumsSubsectionRef&Checksums
argument_list|)
name|final
block|;
name|Error
name|visitLines
argument_list|(
argument|codeview::DebugLinesSubsectionRef&Lines
argument_list|)
name|final
block|;
name|Error
name|visitInlineeLines
argument_list|(
argument|codeview::DebugInlineeLinesSubsectionRef&Lines
argument_list|)
name|final
block|;
name|Error
name|finished
argument_list|()
name|final
block|;
name|protected
operator|:
name|virtual
name|Error
name|handleFileChecksums
argument_list|()
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|handleLines
argument_list|()
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|handleInlineeLines
argument_list|()
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|Expected
operator|<
name|StringRef
operator|>
name|getNameFromStringTable
argument_list|(
argument|uint32_t Offset
argument_list|)
block|;
name|Expected
operator|<
name|StringRef
operator|>
name|getNameFromChecksumsBuffer
argument_list|(
argument|uint32_t Offset
argument_list|)
block|;
name|Optional
operator|<
name|codeview
operator|::
name|DebugChecksumsSubsectionRef
operator|>
name|Checksums
block|;
name|std
operator|::
name|vector
operator|<
name|codeview
operator|::
name|DebugInlineeLinesSubsectionRef
operator|>
name|InlineeLines
block|;
name|std
operator|::
name|vector
operator|<
name|codeview
operator|::
name|DebugLinesSubsectionRef
operator|>
name|Lines
block|;
name|PDBFile
operator|&
name|F
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

