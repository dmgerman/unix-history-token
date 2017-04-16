begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CVTypeDumper.h - CodeView type info dumper --------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_CVTYPEDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_CVTYPEDUMPER_H
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
file|"llvm/DebugInfo/CodeView/TypeDatabase.h"
end_include

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

begin_include
include|#
directive|include
file|"llvm/Support/ScopedPrinter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeServerHandler
decl_stmt|;
comment|/// Dumper for CodeView type streams found in COFF object files and PDB files.
name|class
name|CVTypeDumper
block|{
name|public
label|:
name|explicit
name|CVTypeDumper
argument_list|(
name|TypeDatabase
operator|&
name|TypeDB
argument_list|,
name|TypeServerHandler
operator|*
name|Handler
operator|=
name|nullptr
argument_list|)
operator|:
name|TypeDB
argument_list|(
name|TypeDB
argument_list|)
operator|,
name|Handler
argument_list|(
argument|Handler
argument_list|)
block|{}
comment|/// Dumps one type record.  Returns false if there was a type parsing error,
comment|/// and true otherwise.  This should be called in order, since the dumper
comment|/// maintains state about previous records which are necessary for cross
comment|/// type references.
name|Error
name|dump
argument_list|(
specifier|const
name|CVType
operator|&
name|Record
argument_list|,
name|TypeVisitorCallbacks
operator|&
name|Dumper
argument_list|)
expr_stmt|;
comment|/// Dumps the type records in Types. Returns false if there was a type stream
comment|/// parse error, and true otherwise.
name|Error
name|dump
parameter_list|(
specifier|const
name|CVTypeArray
modifier|&
name|Types
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Dumper
parameter_list|)
function_decl|;
comment|/// Dumps the type records in Data. Returns false if there was a type stream
comment|/// parse error, and true otherwise. Use this method instead of the
comment|/// CVTypeArray overload when type records are laid out contiguously in
comment|/// memory.
name|Error
name|dump
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|,
name|TypeVisitorCallbacks
operator|&
name|Dumper
argument_list|)
decl_stmt|;
specifier|static
name|void
name|printTypeIndex
parameter_list|(
name|ScopedPrinter
modifier|&
name|Printer
parameter_list|,
name|StringRef
name|FieldName
parameter_list|,
name|TypeIndex
name|TI
parameter_list|,
name|TypeDatabase
modifier|&
name|DB
parameter_list|)
function_decl|;
name|private
label|:
name|TypeDatabase
modifier|&
name|TypeDB
decl_stmt|;
name|TypeServerHandler
modifier|*
name|Handler
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
comment|// LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPER_H
end_comment

end_unit

