begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DWARFRelocMap.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_DWARF_DWARFRELOCMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_DWARF_DWARFRELOCMAP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct|struct
name|RelocAddrEntry
block|{
name|uint8_t
name|Width
decl_stmt|;
name|int64_t
name|Value
decl_stmt|;
block|}
struct|;
comment|// In place of applying the relocations to the data we've read from disk we use
comment|// a separate mapping table to the side and checking that at locations in the
comment|// dwarf where we expect relocated values. This adds a bit of complexity to the
comment|// dwarf parsing/extraction at the benefit of not allocating memory for the
comment|// entire size of the debug info sections.
typedef|typedef
name|DenseMap
operator|<
name|uint64_t
operator|,
name|RelocAddrEntry
operator|>
name|RelocAddrMap
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_DWARF_DWARFRELOCMAP_H
end_comment

end_unit

