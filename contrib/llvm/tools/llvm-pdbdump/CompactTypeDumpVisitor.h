begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CompactTypeDumpVisitor.h - CodeView type info dumper ----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_COMPACTTYPEDUMPVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_COMPACTTYPEDUMPVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeVisitorCallbacks.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ScopedPrinter
decl_stmt|;
name|namespace
name|codeview
block|{
name|class
name|TypeCollection
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
comment|/// Dumper for CodeView type streams found in COFF object files and PDB files.
comment|/// Dumps records on a single line, and ignores member records.
name|class
name|CompactTypeDumpVisitor
range|:
name|public
name|codeview
operator|::
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|CompactTypeDumpVisitor
argument_list|(
name|codeview
operator|::
name|TypeCollection
operator|&
name|Types
argument_list|,
name|ScopedPrinter
operator|*
name|W
argument_list|)
block|;
name|CompactTypeDumpVisitor
argument_list|(
argument|codeview::TypeCollection&Types
argument_list|,
argument|codeview::TypeIndex FirstTI
argument_list|,
argument|ScopedPrinter *W
argument_list|)
block|;
comment|/// Paired begin/end actions for all types. Receives all record data,
comment|/// including the fixed-length record prefix.
name|Error
name|visitTypeBegin
argument_list|(
argument|codeview::CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitTypeEnd
argument_list|(
argument|codeview::CVType&Record
argument_list|)
name|override
block|;
name|private
operator|:
name|ScopedPrinter
operator|*
name|W
block|;
name|codeview
operator|::
name|TypeIndex
name|TI
block|;
name|uint32_t
name|Offset
block|;
name|codeview
operator|::
name|TypeCollection
operator|&
name|Types
block|; }
decl_stmt|;
block|}
comment|// end namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

