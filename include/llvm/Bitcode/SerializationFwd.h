begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SerializationFwd.h - Forward references for Serialization ---*- C++ -*-=//
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
comment|// This file provides forward references for bitcode object serialization.
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
name|LLVM_BITCODE_SERIALIZE_FWD
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_SERIALIZE_FWD
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Serializer
decl_stmt|;
name|class
name|Deserializer
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SerializeTrait
expr_stmt|;
typedef|typedef
name|unsigned
name|SerializedPtrID
typedef|;
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

