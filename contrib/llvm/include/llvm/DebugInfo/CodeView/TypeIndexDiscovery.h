begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeIndexDiscovery.h -------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEINDEXDISCOVERY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEINDEXDISCOVERY_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
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
name|enum
name|class
name|TiRefKind
block|{
name|TypeRef
operator|,
name|IndexRef
block|}
empty_stmt|;
struct|struct
name|TiReference
block|{
name|TiRefKind
name|Kind
decl_stmt|;
name|uint32_t
name|Offset
decl_stmt|;
name|uint32_t
name|Count
decl_stmt|;
block|}
struct|;
name|void
name|discoverTypeIndices
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|RecordData
argument_list|,
name|SmallVectorImpl
operator|<
name|TiReference
operator|>
operator|&
name|Refs
argument_list|)
decl_stmt|;
name|void
name|discoverTypeIndices
argument_list|(
specifier|const
name|CVType
operator|&
name|Type
argument_list|,
name|SmallVectorImpl
operator|<
name|TiReference
operator|>
operator|&
name|Refs
argument_list|)
decl_stmt|;
comment|/// Discover type indices in symbol records. Returns false if this is an unknown
comment|/// record.
name|bool
name|discoverTypeIndices
argument_list|(
specifier|const
name|CVSymbol
operator|&
name|Symbol
argument_list|,
name|SmallVectorImpl
operator|<
name|TiReference
operator|>
operator|&
name|Refs
argument_list|)
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

