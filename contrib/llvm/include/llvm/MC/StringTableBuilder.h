begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- StringTableBuilder.h - String table building utility -----*- C++ -*-===//
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
file|"llvm/ADT/CachedHashString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
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
name|DenseMap
operator|<
name|CachedHashStringRef
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
name|unsigned
name|Alignment
decl_stmt|;
name|bool
name|Finalized
init|=
name|false
decl_stmt|;
name|void
name|finalizeStringTable
parameter_list|(
name|bool
name|Optimize
parameter_list|)
function_decl|;
name|void
name|initSize
parameter_list|()
function_decl|;
name|public
label|:
name|StringTableBuilder
argument_list|(
argument|Kind K
argument_list|,
argument|unsigned Alignment =
literal|1
argument_list|)
empty_stmt|;
operator|~
name|StringTableBuilder
argument_list|()
expr_stmt|;
comment|/// \brief Add a string to the builder. Returns the position of S in the
comment|/// table. The position will be changed if finalize is used.
comment|/// Can only be used before the table is finalized.
name|size_t
name|add
parameter_list|(
name|CachedHashStringRef
name|S
parameter_list|)
function_decl|;
name|size_t
name|add
parameter_list|(
name|StringRef
name|S
parameter_list|)
block|{
return|return
name|add
argument_list|(
name|CachedHashStringRef
argument_list|(
name|S
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Analyze the strings and build the final table. No more strings can
comment|/// be added after this point.
name|void
name|finalize
parameter_list|()
function_decl|;
comment|/// Finalize the string table without reording it. In this mode, offsets
comment|/// returned by add will still be valid.
name|void
name|finalizeInOrder
parameter_list|()
function_decl|;
comment|/// \brief Get the offest of a string in the string table. Can only be used
comment|/// after the table is finalized.
name|size_t
name|getOffset
argument_list|(
name|CachedHashStringRef
name|S
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|getOffset
argument_list|(
name|StringRef
name|S
argument_list|)
decl|const
block|{
return|return
name|getOffset
argument_list|(
name|CachedHashStringRef
argument_list|(
name|S
argument_list|)
argument_list|)
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
name|void
name|write
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
name|void
name|write
argument_list|(
name|uint8_t
operator|*
name|Buf
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|bool
name|isFinalized
argument_list|()
specifier|const
block|{
return|return
name|Finalized
return|;
block|}
block|}
empty_stmt|;
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
comment|// LLVM_MC_STRINGTABLEBUILDER_H
end_comment

end_unit

