begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- raw_sha1_ostream.h - raw_ostream that compute SHA1        --*- C++ -*-==//
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
comment|//  This file defines the raw_sha1_ostream class.
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
name|LLVM_SUPPORT_RAW_SHA1_OSTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_RAW_SHA1_OSTREAM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SHA1.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A raw_ostream that hash the content using the sha1 algorithm.
name|class
name|raw_sha1_ostream
range|:
name|public
name|raw_ostream
block|{
name|SHA1
name|State
block|;
comment|/// See raw_ostream::write_impl.
name|void
name|write_impl
argument_list|(
argument|const char *Ptr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{
name|State
operator|.
name|update
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
operator|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
name|Ptr
expr|,
name|Size
operator|)
argument_list|)
block|;   }
name|public
operator|:
comment|/// Return the current SHA1 hash for the content of the stream
name|StringRef
name|sha1
argument_list|()
block|{
name|flush
argument_list|()
block|;
return|return
name|State
operator|.
name|result
argument_list|()
return|;
block|}
comment|/// Reset the internal state to start over from scratch.
name|void
name|resetHash
argument_list|()
block|{
name|State
operator|.
name|init
argument_list|()
block|; }
name|uint64_t
name|current_pos
argument_list|()
specifier|const
name|override
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

