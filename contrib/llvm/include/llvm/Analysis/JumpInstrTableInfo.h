begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JumpInstrTableInfo.h: Info for Jump-Instruction Tables --*- C++ -*-===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Information about jump-instruction tables that have been created by
end_comment

begin_comment
comment|/// JumpInstrTables pass.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_JUMPINSTRTABLEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_JUMPINSTRTABLEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
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
name|class
name|Function
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
comment|/// This class stores information about jump-instruction tables created by the
comment|/// JumpInstrTables pass (in lib/CodeGen/JumpInstrTables.cpp). Each table is a
comment|/// map from a function type to a vector of pairs. The first element of each
comment|/// pair is the function that has the jumptable annotation. The second element
comment|/// is a function that was declared by JumpInstrTables and used to replace all
comment|/// address-taking sites for the original function.
comment|///
comment|/// The information in this pass is used in AsmPrinter
comment|/// (lib/CodeGen/AsmPrinter/AsmPrinter.cpp) to generate the required assembly
comment|/// for the jump-instruction tables.
name|class
name|JumpInstrTableInfo
range|:
name|public
name|ImmutablePass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|/// The default byte alignment for jump tables is 16, which is large but
comment|/// usually safe.
name|JumpInstrTableInfo
argument_list|(
argument|uint64_t ByteAlign =
literal|16
argument_list|)
block|;
name|virtual
operator|~
name|JumpInstrTableInfo
argument_list|()
block|;
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"Jump-Instruction Table Info"
return|;
block|}
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Function
operator|*
operator|,
name|Function
operator|*
operator|>
name|JumpPair
expr_stmt|;
typedef|typedef
name|DenseMap
operator|<
name|FunctionType
operator|*
operator|,
name|std
operator|::
name|vector
operator|<
name|JumpPair
operator|>
expr|>
name|JumpTables
expr_stmt|;
comment|/// Inserts an entry in a table, adding the table if it doesn't exist.
name|void
name|insertEntry
parameter_list|(
name|FunctionType
modifier|*
name|TableFunTy
parameter_list|,
name|Function
modifier|*
name|Target
parameter_list|,
name|Function
modifier|*
name|Jump
parameter_list|)
function_decl|;
comment|/// Gets the tables.
specifier|const
name|JumpTables
operator|&
name|getTables
argument_list|()
specifier|const
block|{
return|return
name|Tables
return|;
block|}
comment|/// Gets the alignment in bytes of a jumptable entry.
name|uint64_t
name|entryByteAlignment
argument_list|()
specifier|const
block|{
return|return
name|ByteAlignment
return|;
block|}
name|private
label|:
name|JumpTables
name|Tables
decl_stmt|;
comment|/// A power-of-two alignment of a jumptable entry.
name|uint64_t
name|ByteAlignment
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Creates a JumpInstrTableInfo pass with the given bound on entry size. This
end_comment

begin_comment
comment|/// bound specifies the maximum number of bytes needed to represent an
end_comment

begin_comment
comment|/// unconditional jump or a trap instruction in the back end currently in use.
end_comment

begin_function_decl
name|ModulePass
modifier|*
name|createJumpInstrTableInfoPass
parameter_list|(
name|unsigned
name|Bound
parameter_list|)
function_decl|;
end_function_decl

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* LLVM_ANALYSIS_JUMPINSTRTABLEINFO_H */
end_comment

end_unit

