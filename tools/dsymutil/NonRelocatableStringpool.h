begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NonRelocatableStringpool.h - A simple stringpool  -----------------===//
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
name|LLVM_TOOLS_DSYMUTIL_NONRELOCATABLESTRINGPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_DSYMUTIL_NONRELOCATABLESTRINGPOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dsymutil
block|{
comment|/// \brief A string table that doesn't need relocations.
comment|///
comment|/// We are doing a final link, no need for a string table that
comment|/// has relocation entries for every reference to it. This class
comment|/// provides this ablitity by just associating offsets with
comment|/// strings.
name|class
name|NonRelocatableStringpool
block|{
name|public
label|:
comment|/// \brief Entries are stored into the StringMap and simply linked
comment|/// together through the second element of this pair in order to
comment|/// keep track of insertion order.
typedef|typedef
name|StringMap
operator|<
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|StringMapEntryBase
operator|*
operator|>
operator|,
name|BumpPtrAllocator
operator|>
name|MapTy
expr_stmt|;
name|NonRelocatableStringpool
argument_list|()
operator|:
name|CurrentEndOffset
argument_list|(
literal|0
argument_list|)
operator|,
name|Sentinel
argument_list|(
literal|0
argument_list|)
operator|,
name|Last
argument_list|(
argument|&Sentinel
argument_list|)
block|{
comment|// Legacy dsymutil puts an empty string at the start of the line
comment|// table.
name|getStringOffset
argument_list|(
literal|""
argument_list|)
block|;   }
comment|/// \brief Get the offset of string \p S in the string table. This
comment|/// can insert a new element or return the offset of a preexisitng
comment|/// one.
name|uint32_t
name|getStringOffset
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
comment|/// \brief Get permanent storage for \p S (but do not necessarily
comment|/// emit \p S in the output section).
comment|/// \returns The StringRef that points to permanent storage to use
comment|/// in place of \p S.
name|StringRef
name|internString
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|// \brief Return the first entry of the string table.
specifier|const
name|MapTy
operator|::
name|MapEntryTy
operator|*
name|getFirstEntry
argument_list|()
specifier|const
block|{
return|return
name|getNextEntry
argument_list|(
operator|&
name|Sentinel
argument_list|)
return|;
block|}
comment|// \brief Get the entry following \p E in the string table or null
comment|// if \p E was the last entry.
specifier|const
name|MapTy
operator|::
name|MapEntryTy
operator|*
name|getNextEntry
argument_list|(
argument|const MapTy::MapEntryTy *E
argument_list|)
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|MapTy
operator|::
name|MapEntryTy
operator|*
operator|>
operator|(
name|E
operator|->
name|getValue
argument_list|()
operator|.
name|second
operator|)
return|;
block|}
name|uint64_t
name|getSize
parameter_list|()
block|{
return|return
name|CurrentEndOffset
return|;
block|}
name|private
label|:
name|MapTy
name|Strings
decl_stmt|;
name|uint32_t
name|CurrentEndOffset
decl_stmt|;
name|MapTy
operator|::
name|MapEntryTy
name|Sentinel
operator|,
operator|*
name|Last
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

