begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SlotMapping.h - Slot number mapping for unnamed values --*- C++ -*-===//
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
comment|// This file contains the declaration of the SlotMapping struct.
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
name|LLVM_ASMPARSER_SLOTMAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ASMPARSER_SLOTMAPPING_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/TrackingMDRef.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
name|GlobalValue
decl_stmt|;
comment|/// This struct contains the mapping from the slot numbers to unnamed metadata
comment|/// nodes and global values.
struct|struct
name|SlotMapping
block|{
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|*
operator|>
name|GlobalValues
expr_stmt|;
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|TrackingMDNodeRef
operator|>
name|MetadataNodes
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

