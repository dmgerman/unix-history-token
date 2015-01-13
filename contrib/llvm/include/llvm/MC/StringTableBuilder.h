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
name|LLVM_MC_STRINGTABLE_BUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_STRINGTABLE_BUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
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
name|SmallString
operator|<
literal|256
operator|>
name|StringTable
expr_stmt|;
name|StringMap
operator|<
name|size_t
operator|>
name|StringIndexMap
expr_stmt|;
name|public
label|:
comment|/// \brief Add a string to the builder. Returns a StringRef to the internal
comment|/// copy of s. Can only be used before the table is finalized.
name|StringRef
name|add
parameter_list|(
name|StringRef
name|s
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isFinalized
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|StringIndexMap
operator|.
name|GetOrCreateValue
argument_list|(
name|s
argument_list|,
literal|0
argument_list|)
operator|.
name|getKey
argument_list|()
return|;
block|}
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
parameter_list|()
block|{
name|assert
argument_list|(
name|isFinalized
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|StringTable
return|;
block|}
comment|/// \brief Get the offest of a string in the string table. Can only be used
comment|/// after the table is finalized.
name|size_t
name|getOffset
parameter_list|(
name|StringRef
name|s
parameter_list|)
block|{
name|assert
argument_list|(
name|isFinalized
argument_list|()
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|StringIndexMap
operator|.
name|count
argument_list|(
name|s
argument_list|)
operator|&&
literal|"String is not in table!"
argument_list|)
expr_stmt|;
return|return
name|StringIndexMap
index|[
name|s
index|]
return|;
block|}
name|private
label|:
name|bool
name|isFinalized
parameter_list|()
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

