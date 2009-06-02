begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/HashExtras.h - Useful functions for STL hash ---*- C++ -*-===//
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
comment|// This file contains some templates that are useful if you are working with the
end_comment

begin_comment
comment|// STL Hashed containers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// No library is required when using these functions.
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
name|LLVM_ADT_HASHEXTRAS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_HASHEXTRAS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Cannot specialize hash template from outside of the std namespace.
end_comment

begin_decl_stmt
name|namespace
name|HASH_NAMESPACE
block|{
comment|// Provide a hash function for arbitrary pointers...
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|hash
operator|<
name|T
operator|*
operator|>
block|{
specifier|inline
name|size_t
name|operator
argument_list|()
operator|(
specifier|const
name|T
operator|*
name|Val
operator|)
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|size_t
operator|>
operator|(
name|Val
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|std
operator|::
name|string
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|std
operator|::
name|string
specifier|const
operator|&
name|str
operator|)
specifier|const
block|{
return|return
name|hash
operator|<
name|char
specifier|const
operator|*
operator|>
operator|(
operator|)
operator|(
name|str
operator|.
name|c_str
argument_list|()
operator|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace std
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

