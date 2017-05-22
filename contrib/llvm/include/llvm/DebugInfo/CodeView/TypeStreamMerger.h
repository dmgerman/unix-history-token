begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeStreamMerger.h ---------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|TypeIndex
decl_stmt|;
name|class
name|TypeServerHandler
decl_stmt|;
name|class
name|TypeTableBuilder
decl_stmt|;
comment|/// Merges one type stream into another. Returns true on success.
name|Error
name|mergeTypeStreams
argument_list|(
name|TypeTableBuilder
operator|&
name|DestIdStream
argument_list|,
name|TypeTableBuilder
operator|&
name|DestTypeStream
argument_list|,
name|SmallVectorImpl
operator|<
name|TypeIndex
operator|>
operator|&
name|SourceToDest
argument_list|,
name|TypeServerHandler
operator|*
name|Handler
argument_list|,
specifier|const
name|CVTypeArray
operator|&
name|Types
argument_list|)
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
comment|// LLVM_DEBUGINFO_CODEVIEW_TYPESTREAMMERGER_H
end_comment

end_unit

