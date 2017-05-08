begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DbiModuleDescriptor.h - PDB module information -----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_DBIMODULEDESCRIPTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_DBIMODULEDESCRIPTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Native/RawTypes.h"
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
name|namespace
name|pdb
block|{
name|class
name|DbiModuleDescriptor
block|{
name|friend
name|class
name|DbiStreamBuilder
decl_stmt|;
name|public
label|:
name|DbiModuleDescriptor
argument_list|()
expr_stmt|;
name|DbiModuleDescriptor
argument_list|(
specifier|const
name|DbiModuleDescriptor
operator|&
name|Info
argument_list|)
expr_stmt|;
operator|~
name|DbiModuleDescriptor
argument_list|()
expr_stmt|;
specifier|static
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|,
name|DbiModuleDescriptor
modifier|&
name|Info
parameter_list|)
function_decl|;
name|bool
name|hasECInfo
argument_list|()
specifier|const
expr_stmt|;
name|uint16_t
name|getTypeServerIndex
argument_list|()
specifier|const
expr_stmt|;
name|uint16_t
name|getModuleStreamIndex
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getSymbolDebugInfoByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getC11LineInfoByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getC13LineInfoByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getNumberOfFiles
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getSourceFileNameIndex
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getPdbFilePathNameIndex
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getModuleName
argument_list|()
specifier|const
expr_stmt|;
name|StringRef
name|getObjFileName
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|getRecordLength
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|StringRef
name|ModuleName
decl_stmt|;
name|StringRef
name|ObjFileName
decl_stmt|;
specifier|const
name|ModuleInfoHeader
modifier|*
name|Layout
init|=
name|nullptr
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace pdb
name|template
operator|<
operator|>
expr|struct
name|VarStreamArrayExtractor
operator|<
name|pdb
operator|::
name|DbiModuleDescriptor
operator|>
block|{
typedef|typedef
name|void
name|ContextType
typedef|;
specifier|static
name|Error
name|extract
argument_list|(
argument|BinaryStreamRef Stream
argument_list|,
argument|uint32_t&Length
argument_list|,
argument|pdb::DbiModuleDescriptor&Info
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|pdb
operator|::
name|DbiModuleDescriptor
operator|::
name|initialize
argument_list|(
name|Stream
argument_list|,
name|Info
argument_list|)
condition|)
return|return
name|EC
return|;
name|Length
operator|=
name|Info
operator|.
name|getRecordLength
argument_list|()
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_PDB_RAW_DBIMODULEDESCRIPTOR_H
end_comment

end_unit

