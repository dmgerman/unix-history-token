begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModStream.h - PDB Module Info Stream Access ------------------------===//
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
name|LLVM_DEBUGINFO_PDB_RAW_MODSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_MODSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CVRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/ModuleSubstream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/MSF/MappedBlockStream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
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
name|pdb
block|{
name|class
name|PDBFile
decl_stmt|;
name|class
name|ModInfo
decl_stmt|;
name|class
name|ModStream
block|{
name|public
label|:
name|ModStream
argument_list|(
specifier|const
name|ModInfo
operator|&
name|Module
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|msf
operator|::
name|MappedBlockStream
operator|>
name|Stream
argument_list|)
expr_stmt|;
operator|~
name|ModStream
argument_list|()
expr_stmt|;
name|Error
name|reload
parameter_list|()
function_decl|;
name|uint32_t
name|signature
argument_list|()
specifier|const
block|{
return|return
name|Signature
return|;
block|}
name|iterator_range
operator|<
name|codeview
operator|::
name|CVSymbolArray
operator|::
name|Iterator
operator|>
name|symbols
argument_list|(
argument|bool *HadError
argument_list|)
specifier|const
expr_stmt|;
name|iterator_range
operator|<
name|codeview
operator|::
name|ModuleSubstreamArray
operator|::
name|Iterator
operator|>
name|lines
argument_list|(
argument|bool *HadError
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|hasLineInfo
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|commit
parameter_list|()
function_decl|;
name|private
label|:
specifier|const
name|ModInfo
modifier|&
name|Mod
decl_stmt|;
name|uint32_t
name|Signature
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|msf
operator|::
name|MappedBlockStream
operator|>
name|Stream
expr_stmt|;
name|codeview
operator|::
name|CVSymbolArray
name|SymbolsSubstream
expr_stmt|;
name|BinaryStreamRef
name|LinesSubstream
decl_stmt|;
name|BinaryStreamRef
name|C13LinesSubstream
decl_stmt|;
name|BinaryStreamRef
name|GlobalRefsSubstream
decl_stmt|;
name|codeview
operator|::
name|ModuleSubstreamArray
name|LineInfo
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

