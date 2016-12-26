begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- InfoStreamBuilder.h - PDB Info Stream Creation -----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBINFOSTREAMBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBINFOSTREAMBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/PDBTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/NameMapBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/PDBFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/RawConstants.h"
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
name|InfoStreamBuilder
block|{
name|public
label|:
name|InfoStreamBuilder
argument_list|()
expr_stmt|;
name|InfoStreamBuilder
argument_list|(
specifier|const
name|InfoStreamBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|InfoStreamBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|InfoStreamBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
name|setVersion
parameter_list|(
name|PdbRaw_ImplVer
name|V
parameter_list|)
function_decl|;
name|void
name|setSignature
parameter_list|(
name|uint32_t
name|S
parameter_list|)
function_decl|;
name|void
name|setAge
parameter_list|(
name|uint32_t
name|A
parameter_list|)
function_decl|;
name|void
name|setGuid
parameter_list|(
name|PDB_UniqueId
name|G
parameter_list|)
function_decl|;
name|NameMapBuilder
modifier|&
name|getNamedStreamsBuilder
parameter_list|()
function_decl|;
name|uint32_t
name|calculateSerializedLength
argument_list|()
specifier|const
expr_stmt|;
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InfoStream
operator|>>
name|build
argument_list|(
name|PDBFile
operator|&
name|File
argument_list|)
expr_stmt|;
name|private
label|:
name|Optional
operator|<
name|PdbRaw_ImplVer
operator|>
name|Ver
expr_stmt|;
name|Optional
operator|<
name|uint32_t
operator|>
name|Sig
expr_stmt|;
name|Optional
operator|<
name|uint32_t
operator|>
name|Age
expr_stmt|;
name|Optional
operator|<
name|PDB_UniqueId
operator|>
name|Guid
expr_stmt|;
name|NameMapBuilder
name|NamedStreams
decl_stmt|;
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

