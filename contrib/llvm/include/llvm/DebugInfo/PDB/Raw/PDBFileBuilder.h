begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PDBFileBuilder.h - PDB File Creation ---------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_PDBFILEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_PDBFILEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/MsfBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/PDB/Raw/PDBFile.h"
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|codeview
block|{
name|class
name|StreamInterface
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|DbiStreamBuilder
decl_stmt|;
name|class
name|InfoStreamBuilder
decl_stmt|;
name|class
name|PDBFile
decl_stmt|;
name|class
name|PDBFileBuilder
block|{
name|public
label|:
name|explicit
name|PDBFileBuilder
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|codeview
operator|::
name|StreamInterface
operator|>
name|FileBuffer
argument_list|)
decl_stmt|;
name|PDBFileBuilder
argument_list|(
specifier|const
name|PDBFileBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|PDBFileBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PDBFileBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|Error
name|initialize
argument_list|(
specifier|const
name|msf
operator|::
name|SuperBlock
operator|&
name|Super
argument_list|)
decl_stmt|;
name|MsfBuilder
modifier|&
name|getMsfBuilder
parameter_list|()
function_decl|;
name|InfoStreamBuilder
modifier|&
name|getInfoBuilder
parameter_list|()
function_decl|;
name|DbiStreamBuilder
modifier|&
name|getDbiBuilder
parameter_list|()
function_decl|;
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|PDBFile
operator|>>
name|build
argument_list|()
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|InfoStreamBuilder
operator|>
name|Info
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DbiStreamBuilder
operator|>
name|Dbi
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|PDBFile
operator|>
name|File
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MsfBuilder
operator|>
name|Msf
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

