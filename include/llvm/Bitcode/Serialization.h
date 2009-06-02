begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- Serialization.h - Generic Object Serialization to Bitcode ---*- C++ -*-=//
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
comment|// This file defines traits for primitive types used for both object
end_comment

begin_comment
comment|// serialization and deserialization.
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
name|LLVM_BITCODE_SERIALIZE
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_SERIALIZE
end_define

begin_include
include|#
directive|include
file|"llvm/Bitcode/SerializationFwd.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// SerializeTrait - SerializeTrait bridges between the Serializer/Deserializer
comment|///  and the functions that serialize objects of specific types.  The default
comment|///  behavior is to call static methods of the class for the object being
comment|///  serialized, but this behavior can be changed by specializing this
comment|///  template.  Classes only need to implement the methods corresponding
comment|///  to the serialization scheme they want to support.  For example, "Read"
comment|///  and "ReadVal" correspond to different deserialization schemes which make
comment|///  sense for different types; a class need only implement one of them.
comment|///  Serialization and deserialization of pointers are specially handled
comment|///  by the Serializer and Deserializer using the EmitOwnedPtr, etc. methods.
comment|///  To serialize the actual object referred to by a pointer, the class
comment|///  of the object either must implement the methods called by the default
comment|///  behavior of SerializeTrait, or specialize SerializeTrait.  This latter
comment|///  is useful when one cannot add methods to an existing class (for example).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SerializeTrait
block|{
specifier|static
specifier|inline
name|void
name|Emit
argument_list|(
argument|Serializer& S
argument_list|,
argument|const T& X
argument_list|)
block|{
name|X
operator|.
name|Emit
argument_list|(
name|S
argument_list|)
block|; }
specifier|static
specifier|inline
name|void
name|Read
argument_list|(
argument|Deserializer& D
argument_list|,
argument|T& X
argument_list|)
block|{
name|X
operator|.
name|Read
argument_list|(
name|D
argument_list|)
block|; }
specifier|static
specifier|inline
name|T
operator|*
name|Create
argument_list|(
argument|Deserializer& D
argument_list|)
block|{
return|return
name|T
operator|::
name|Create
argument_list|(
name|D
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|Arg1
operator|>
specifier|static
specifier|inline
name|T
operator|*
name|Create
argument_list|(
argument|Deserializer& D
argument_list|,
argument|Arg1& arg1
argument_list|)
block|{
return|return
name|T
operator|::
name|Create
argument_list|(
name|D
argument_list|,
name|arg1
argument_list|)
return|;
block|}
expr|}
block|;
define|#
directive|define
name|SERIALIZE_INT_TRAIT
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|template<> struct SerializeTrait<TYPE> {\   static void Emit(Serializer& S, TYPE X);\   static void Read(Deserializer& S, TYPE& X); };
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|bool
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|unsigned char
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|unsigned short
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|unsigned int
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|unsigned long
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|signed char
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|signed short
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|signed int
argument_list|)
name|SERIALIZE_INT_TRAIT
argument_list|(
argument|signed long
argument_list|)
undef|#
directive|undef
name|SERIALIZE_INT_TRAIT
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

