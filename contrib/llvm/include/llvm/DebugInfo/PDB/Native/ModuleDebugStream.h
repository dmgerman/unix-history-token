begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleDebugStream.h - PDB Module Info Stream Access ------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_NATIVE_MODULEDEBUGSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_NATIVE_MODULEDEBUGSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
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
file|"llvm/Support/BinaryStreamRef.h"
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
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|class
name|DbiModuleDescriptor
decl_stmt|;
name|class
name|ModuleDebugStreamRef
block|{
name|using
name|DebugSubsectionIterator
init|=
name|codeview
operator|::
name|DebugSubsectionArray
operator|::
name|Iterator
decl_stmt|;
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
name|ModuleDebugStreamRef
argument_list|(
name|ModuleDebugStreamRef
operator|&&
name|Other
argument_list|)
operator|=
expr|default
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
specifier|const
name|codeview
operator|::
name|CVSymbolArray
operator|&
name|getSymbolArray
argument_list|()
specifier|const
block|{
return|return
name|SymbolArray
return|;
block|}
name|BinarySubstreamRef
name|getSymbolsSubstream
argument_list|()
specifier|const
expr_stmt|;
name|BinarySubstreamRef
name|getC11LinesSubstream
argument_list|()
specifier|const
expr_stmt|;
name|BinarySubstreamRef
name|getC13LinesSubstream
argument_list|()
specifier|const
expr_stmt|;
name|BinarySubstreamRef
name|getGlobalRefsSubstream
argument_list|()
specifier|const
expr_stmt|;
name|ModuleDebugStreamRef
modifier|&
name|operator
init|=
operator|(
name|ModuleDebugStreamRef
operator|&&
name|Other
operator|)
operator|=
expr|default
decl_stmt|;
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
name|shared_ptr
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
name|SymbolArray
expr_stmt|;
name|BinarySubstreamRef
name|SymbolsSubstream
decl_stmt|;
name|BinarySubstreamRef
name|C11LinesSubstream
decl_stmt|;
name|BinarySubstreamRef
name|C13LinesSubstream
decl_stmt|;
name|BinarySubstreamRef
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

begin_comment
comment|// LLVM_DEBUGINFO_PDB_NATIVE_MODULEDEBUGSTREAM_H
end_comment

end_unit

