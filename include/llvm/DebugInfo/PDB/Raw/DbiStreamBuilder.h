begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DbiStreamBuilder.h - PDB Dbi Stream Creation -------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBDBISTREAMBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBDBISTREAMBUILDER_H
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
name|DbiStream
decl_stmt|;
name|class
name|PDBFile
decl_stmt|;
name|class
name|DbiStreamBuilder
block|{
name|public
label|:
name|DbiStreamBuilder
argument_list|()
expr_stmt|;
name|DbiStreamBuilder
argument_list|(
specifier|const
name|DbiStreamBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|DbiStreamBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DbiStreamBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|void
name|setVersionHeader
parameter_list|(
name|PdbRaw_DbiVer
name|V
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
name|setBuildNumber
parameter_list|(
name|uint16_t
name|B
parameter_list|)
function_decl|;
name|void
name|setPdbDllVersion
parameter_list|(
name|uint16_t
name|V
parameter_list|)
function_decl|;
name|void
name|setPdbDllRbld
parameter_list|(
name|uint16_t
name|R
parameter_list|)
function_decl|;
name|void
name|setFlags
parameter_list|(
name|uint16_t
name|F
parameter_list|)
function_decl|;
name|void
name|setMachineType
parameter_list|(
name|PDB_Machine
name|M
parameter_list|)
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
name|DbiStream
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
name|PdbRaw_DbiVer
operator|>
name|VerHeader
expr_stmt|;
name|uint32_t
name|Age
decl_stmt|;
name|uint16_t
name|BuildNumber
decl_stmt|;
name|uint16_t
name|PdbDllVersion
decl_stmt|;
name|uint16_t
name|PdbDllRbld
decl_stmt|;
name|uint16_t
name|Flags
decl_stmt|;
name|PDB_Machine
name|MachineType
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

