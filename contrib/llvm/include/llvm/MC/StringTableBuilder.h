begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StringTableBuilder.h - String table building utility ------*- C++ -*-=//
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
name|LLVM_MC_STRINGTABLEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_STRINGTABLEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// \brief Utility for building string tables with deduplicated suffixes.
name|class
name|StringTableBuilder
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|ELF
block|,
name|WinCOFF
block|,
name|MachO
block|,
name|RAW
block|}
enum|;
name|private
label|:
name|SmallString
operator|<
literal|256
operator|>
name|StringTable
expr_stmt|;
name|DenseMap
operator|<
name|StringRef
operator|,
name|size_t
operator|>
name|StringIndexMap
expr_stmt|;
name|size_t
name|Size
init|=
literal|0
decl_stmt|;
name|Kind
name|K
decl_stmt|;
name|public
label|:
name|StringTableBuilder
argument_list|(
argument|Kind K
argument_list|)
empty_stmt|;
comment|/// \brief Add a string to the builder. Returns the position of S in the
comment|/// table. The position will be changed if finalize is used.
comment|/// Can only be used before the table is finalized.
name|size_t
name|add
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|/// \brief Analyze the strings and build the final table. No more strings can
comment|/// be added after this point.
name|void
name|finalize
parameter_list|()
function_decl|;
comment|/// \brief Retrieve the string table data. Can only be used after the table
comment|/// is finalized.
name|StringRef
name|data
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isFinalized
argument_list|()
argument_list|)
block|;
return|return
name|StringTable
return|;
block|}
comment|/// \brief Get the offest of a string in the string table. Can only be used
comment|/// after the table is finalized.
name|size_t
name|getOffset
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|DenseMap
operator|<
name|StringRef
operator|,
name|size_t
operator|>
operator|&
name|getMap
argument_list|()
specifier|const
block|{
return|return
name|StringIndexMap
return|;
block|}
name|size_t
name|getSize
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
name|void
name|clear
parameter_list|()
function_decl|;
name|private
label|:
name|bool
name|isFinalized
argument_list|()
specifier|const
block|{
return|return
operator|!
name|StringTable
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

