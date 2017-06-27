begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFDebugAranges.h --------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARFDEBUGARANGES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARFDEBUGARANGES_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataExtractor.h"
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
name|class
name|DWARFContext
decl_stmt|;
name|class
name|DWARFDebugAranges
block|{
name|public
label|:
name|void
name|generate
parameter_list|(
name|DWARFContext
modifier|*
name|CTX
parameter_list|)
function_decl|;
name|uint32_t
name|findAddress
argument_list|(
name|uint64_t
name|Address
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|extract
parameter_list|(
name|DataExtractor
name|DebugArangesData
parameter_list|)
function_decl|;
comment|/// Call appendRange multiple times and then call construct.
name|void
name|appendRange
parameter_list|(
name|uint32_t
name|CUOffset
parameter_list|,
name|uint64_t
name|LowPC
parameter_list|,
name|uint64_t
name|HighPC
parameter_list|)
function_decl|;
name|void
name|construct
parameter_list|()
function_decl|;
struct|struct
name|Range
block|{
name|explicit
name|Range
argument_list|(
argument|uint64_t LowPC = -
literal|1ULL
argument_list|,
argument|uint64_t HighPC = -
literal|1ULL
argument_list|,
argument|uint32_t CUOffset = -
literal|1U
argument_list|)
block|:
name|LowPC
argument_list|(
name|LowPC
argument_list|)
operator|,
name|Length
argument_list|(
name|HighPC
operator|-
name|LowPC
argument_list|)
operator|,
name|CUOffset
argument_list|(
argument|CUOffset
argument_list|)
block|{}
name|void
name|setHighPC
argument_list|(
argument|uint64_t HighPC
argument_list|)
block|{
if|if
condition|(
name|HighPC
operator|==
operator|-
literal|1ULL
operator|||
name|HighPC
operator|<=
name|LowPC
condition|)
name|Length
operator|=
literal|0
expr_stmt|;
else|else
name|Length
operator|=
name|HighPC
operator|-
name|LowPC
expr_stmt|;
block|}
name|uint64_t
name|HighPC
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Length
condition|)
return|return
name|LowPC
operator|+
name|Length
return|;
return|return
operator|-
literal|1ULL
return|;
block|}
name|bool
name|containsAddress
argument_list|(
name|uint64_t
name|Address
argument_list|)
decl|const
block|{
return|return
name|LowPC
operator|<=
name|Address
operator|&&
name|Address
operator|<
name|HighPC
argument_list|()
return|;
block|}
name|bool
name|operator
decl|<
argument_list|(
specifier|const
name|Range
operator|&
name|other
argument_list|)
decl|const
block|{
return|return
name|LowPC
operator|<
name|other
operator|.
name|LowPC
return|;
block|}
name|uint64_t
name|LowPC
struct|;
comment|/// Start of address range.
name|uint32_t
name|Length
decl_stmt|;
comment|/// End of address range (not including this address).
name|uint32_t
name|CUOffset
decl_stmt|;
comment|/// Offset of the compile unit or die.
block|}
empty_stmt|;
struct|struct
name|RangeEndpoint
block|{
name|uint64_t
name|Address
decl_stmt|;
name|uint32_t
name|CUOffset
decl_stmt|;
name|bool
name|IsRangeStart
decl_stmt|;
name|RangeEndpoint
argument_list|(
argument|uint64_t Address
argument_list|,
argument|uint32_t CUOffset
argument_list|,
argument|bool IsRangeStart
argument_list|)
block|:
name|Address
argument_list|(
name|Address
argument_list|)
operator|,
name|CUOffset
argument_list|(
name|CUOffset
argument_list|)
operator|,
name|IsRangeStart
argument_list|(
argument|IsRangeStart
argument_list|)
block|{}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|RangeEndpoint
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Address
operator|<
name|Other
operator|.
name|Address
return|;
block|}
block|}
struct|;
name|using
name|RangeColl
init|=
name|std
operator|::
name|vector
operator|<
name|Range
operator|>
decl_stmt|;
name|using
name|RangeCollIterator
init|=
name|RangeColl
operator|::
name|const_iterator
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|RangeEndpoint
operator|>
name|Endpoints
expr_stmt|;
name|RangeColl
name|Aranges
decl_stmt|;
name|DenseSet
operator|<
name|uint32_t
operator|>
name|ParsedCUOffsets
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_DWARFDEBUGARANGES_H
end_comment

end_unit

