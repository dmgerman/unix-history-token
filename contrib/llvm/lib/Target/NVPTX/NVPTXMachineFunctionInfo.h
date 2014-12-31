begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXMachineFunctionInfo.h - NVPTX-specific Function Info  --------===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This class is attached to a MachineFunction instance and tracks target-
end_comment

begin_comment
comment|// dependent information
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NVPTXMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|private
operator|:
comment|/// Stores a mapping from index to symbol name for removing image handles
comment|/// on Fermi.
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|8
operator|>
name|ImageHandleList
block|;
name|public
operator|:
name|NVPTXMachineFunctionInfo
argument_list|(
argument|MachineFunction&MF
argument_list|)
block|{}
comment|/// Returns the index for the symbol \p Symbol. If the symbol was previously,
comment|/// added, the same index is returned. Otherwise, the symbol is added and the
comment|/// new index is returned.
name|unsigned
name|getImageHandleSymbolIndex
argument_list|(
argument|const char *Symbol
argument_list|)
block|{
comment|// Is the symbol already present?
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|ImageHandleList
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|ImageHandleList
index|[
name|i
index|]
operator|==
name|std
operator|::
name|string
argument_list|(
name|Symbol
argument_list|)
condition|)
return|return
name|i
return|;
comment|// Nope, insert it
name|ImageHandleList
operator|.
name|push_back
argument_list|(
name|Symbol
argument_list|)
block|;
return|return
name|ImageHandleList
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
comment|/// Returns the symbol name at the given index.
specifier|const
name|char
modifier|*
name|getImageHandleSymbol
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|ImageHandleList
operator|.
name|size
argument_list|()
operator|>
name|Idx
operator|&&
literal|"Bad index"
argument_list|)
expr_stmt|;
return|return
name|ImageHandleList
index|[
name|Idx
index|]
operator|.
name|c_str
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

unit|}
end_unit

