begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/KnownBits.h - Stores known zeros/ones -------*- C++ -*-===//
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
comment|// This file contains a class for representing known zeros and ones used by
end_comment

begin_comment
comment|// computeKnownBits.
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
name|LLVM_SUPPORT_KNOWNBITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_KNOWNBITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// For now this is a simple wrapper around two APInts.
struct|struct
name|KnownBits
block|{
name|APInt
name|Zero
decl_stmt|;
name|APInt
name|One
decl_stmt|;
comment|// Default construct Zero and One.
name|KnownBits
argument_list|()
block|{}
comment|/// Create a known bits object of BitWidth bits initialized to unknown.
name|KnownBits
argument_list|(
argument|unsigned BitWidth
argument_list|)
block|:
name|Zero
argument_list|(
name|BitWidth
argument_list|,
literal|0
argument_list|)
operator|,
name|One
argument_list|(
argument|BitWidth
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// Get the bit width of this value.
name|unsigned
name|getBitWidth
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Zero
operator|.
name|getBitWidth
argument_list|()
operator|==
name|One
operator|.
name|getBitWidth
argument_list|()
operator|&&
literal|"Zero and One should have the same width!"
argument_list|)
block|;
return|return
name|Zero
operator|.
name|getBitWidth
argument_list|()
return|;
block|}
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

