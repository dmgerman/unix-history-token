begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolDumper.h - CodeView symbol info dumper ------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolDumpDelegate.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
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
comment|/// Dumper for CodeView symbol streams found in COFF object files and PDB files.
name|class
name|CVSymbolDumper
block|{
name|public
label|:
name|CVSymbolDumper
argument_list|(
argument|ScopedPrinter&W
argument_list|,
argument|TypeCollection&Types
argument_list|,
argument|CodeViewContainer Container
argument_list|,
argument|std::unique_ptr<SymbolDumpDelegate> ObjDelegate
argument_list|,
argument|bool PrintRecordBytes
argument_list|)
block|:
name|W
argument_list|(
name|W
argument_list|)
operator|,
name|Types
argument_list|(
name|Types
argument_list|)
operator|,
name|Container
argument_list|(
name|Container
argument_list|)
operator|,
name|ObjDelegate
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|ObjDelegate
argument_list|)
argument_list|)
operator|,
name|PrintRecordBytes
argument_list|(
argument|PrintRecordBytes
argument_list|)
block|{}
comment|/// Dumps one type record.  Returns false if there was a type parsing error,
comment|/// and true otherwise.  This should be called in order, since the dumper
comment|/// maintains state about previous records which are necessary for cross
comment|/// type references.
name|Error
name|dump
argument_list|(
name|CVRecord
operator|<
name|SymbolKind
operator|>
operator|&
name|Record
argument_list|)
expr_stmt|;
comment|/// Dumps the type records in Data. Returns false if there was a type stream
comment|/// parse error, and true otherwise.
name|Error
name|dump
parameter_list|(
specifier|const
name|CVSymbolArray
modifier|&
name|Symbols
parameter_list|)
function_decl|;
name|private
label|:
name|ScopedPrinter
modifier|&
name|W
decl_stmt|;
name|TypeCollection
modifier|&
name|Types
decl_stmt|;
name|CodeViewContainer
name|Container
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SymbolDumpDelegate
operator|>
name|ObjDelegate
expr_stmt|;
name|bool
name|PrintRecordBytes
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_SYMBOLDUMPER_H
end_comment

end_unit

