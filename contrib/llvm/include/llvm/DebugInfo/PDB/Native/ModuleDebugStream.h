begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleDebugStream.h - PDB Module Info Stream Access ----------------===//
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
name|LLVM_DEBUGINFO_PDB_RAW_MODULEDEBUGSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_MODULEDEBUGSTREAM_H
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
file|"llvm/DebugInfo/CodeView/DebugChecksumsSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsectionRecord.h"
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
name|DbiModuleDescriptor
decl_stmt|;
name|class
name|ModuleDebugStreamRef
block|{
typedef|typedef
name|codeview
operator|::
name|DebugSubsectionArray
operator|::
name|Iterator
name|DebugSubsectionIterator
expr_stmt|;
name|public
label|:
name|ModuleDebugStreamRef
argument_list|(
specifier|const
name|DbiModuleDescriptor
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
name|ModuleDebugStreamRef
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
name|llvm
operator|::
name|iterator_range
operator|<
name|DebugSubsectionIterator
operator|>
name|subsections
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasDebugSubsections
argument_list|()
specifier|const
expr_stmt|;
name|Error
name|commit
parameter_list|()
function_decl|;
name|Expected
operator|<
name|codeview
operator|::
name|DebugChecksumsSubsectionRef
operator|>
name|findChecksumsSubsection
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
specifier|const
name|DbiModuleDescriptor
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
name|C11LinesSubstream
decl_stmt|;
name|BinaryStreamRef
name|C13LinesSubstream
decl_stmt|;
name|BinaryStreamRef
name|GlobalRefsSubstream
decl_stmt|;
name|codeview
operator|::
name|DebugSubsectionArray
name|Subsections
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

