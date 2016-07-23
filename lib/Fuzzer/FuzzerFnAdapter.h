begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerAdapter.h - Arbitrary function Fuzzer adapter -------*- C++ -*===//
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
comment|// W A R N I N G :  E X P E R I M E N T A L.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines an adapter to fuzz functions with (almost) arbitrary signatures.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_FUZZER_ADAPTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_ADAPTER_H
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
comment|/// Unpacks bytes from \p Data according to \p F argument types
comment|/// and calls the function.
comment|/// Use to automatically adapt LLVMFuzzerTestOneInput interface to
comment|/// a specific function.
comment|/// Supported argument types: primitive types, std::vector<uint8_t>.
name|template
operator|<
name|typename
name|Fn
operator|>
name|bool
name|Adapt
argument_list|(
argument|Fn F
argument_list|,
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|)
expr_stmt|;
comment|// The implementation performs several steps:
comment|// - function argument types are obtained (Args...)
comment|// - data is unpacked into std::tuple<Args...> one by one
comment|// - function is called with std::tuple<Args...> containing arguments.
name|namespace
name|impl
block|{
comment|// Single argument unpacking.
name|template
operator|<
name|typename
name|T
operator|>
name|size_t
name|UnpackPrimitive
argument_list|(
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|T *Value
argument_list|)
block|{
if|if
condition|(
name|Size
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
condition|)
return|return
name|Size
return|;
operator|*
name|Value
operator|=
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|Data
operator|)
expr_stmt|;
return|return
name|Size
operator|-
sizeof|sizeof
argument_list|(
name|T
argument_list|)
return|;
block|}
comment|/// Unpacks into a given Value and returns the Size - num_consumed_bytes.
comment|/// Return value equal to Size signals inability to unpack the data (typically
comment|/// because there are not enough bytes).
name|template
operator|<
name|typename
name|T
operator|>
name|size_t
name|UnpackSingle
argument_list|(
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|T *Value
argument_list|)
expr_stmt|;
define|#
directive|define
name|UNPACK_SINGLE_PRIMITIVE
parameter_list|(
name|Type
parameter_list|)
define|\
value|template<>                                                                  \   size_t UnpackSingle<Type>(const uint8_t *Data, size_t Size, Type *Value) {   \     return UnpackPrimitive(Data, Size, Value);                                 \   }
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|char
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|signed char
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|unsigned char
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|short int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|unsigned short int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|unsigned int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|long int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|unsigned long int
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|bool
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|wchar_t
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|float
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|double
argument_list|)
name|UNPACK_SINGLE_PRIMITIVE
argument_list|(
argument|long double
argument_list|)
undef|#
directive|undef
name|UNPACK_SINGLE_PRIMITIVE
name|template
operator|<
operator|>
name|size_t
name|UnpackSingle
operator|<
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>>
operator|(
specifier|const
name|uint8_t
operator|*
name|Data
operator|,
name|size_t
name|Size
operator|,
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
operator|*
name|Value
operator|)
block|{
if|if
condition|(
name|Size
operator|<
literal|1
condition|)
return|return
name|Size
return|;
name|size_t
name|Len
operator|=
name|std
operator|::
name|min
argument_list|(
name|static_cast
operator|<
name|size_t
operator|>
operator|(
operator|*
name|Data
operator|)
argument_list|,
name|Size
operator|-
literal|1
argument_list|)
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint8_t
operator|>
name|V
argument_list|(
name|Data
operator|+
literal|1
argument_list|,
name|Data
operator|+
literal|1
operator|+
name|Len
argument_list|)
expr_stmt|;
name|Value
operator|->
name|swap
argument_list|(
name|V
argument_list|)
expr_stmt|;
return|return
name|Size
operator|-
name|Len
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|size_t
name|UnpackSingle
operator|<
name|std
operator|::
name|string
operator|>
operator|(
specifier|const
name|uint8_t
operator|*
name|Data
operator|,
name|size_t
name|Size
operator|,
name|std
operator|::
name|string
operator|*
name|Value
operator|)
block|{
if|if
condition|(
name|Size
operator|<
literal|1
condition|)
return|return
name|Size
return|;
name|size_t
name|Len
operator|=
name|std
operator|::
name|min
argument_list|(
name|static_cast
operator|<
name|size_t
operator|>
operator|(
operator|*
name|Data
operator|)
argument_list|,
name|Size
operator|-
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|S
argument_list|(
name|Data
operator|+
literal|1
argument_list|,
name|Data
operator|+
literal|1
operator|+
name|Len
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Value
operator|->
name|swap
argument_list|(
name|S
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Size
operator|-
name|Len
operator|-
literal|1
return|;
end_return

begin_comment
unit|}
comment|// Unpacking into arbitrary tuple.
end_comment

begin_comment
comment|// Recursion guard.
end_comment

begin_expr_stmt
unit|template
operator|<
name|int
name|N
operator|,
name|typename
name|TupleT
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|N
operator|==
name|std
operator|::
name|tuple_size
operator|<
name|TupleT
operator|>
operator|::
name|value
operator|,
name|bool
operator|>
operator|::
name|type
name|UnpackImpl
argument_list|(
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|TupleT *Tuple
argument_list|)
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|// Unpack tuple elements starting from Nth.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
name|N
operator|,
name|typename
name|TupleT
operator|>
name|typename
name|std
operator|::
name|enable_if
operator|<
name|N
operator|<
name|std
operator|::
name|tuple_size
operator|<
name|TupleT
operator|>
operator|::
name|value
operator|,
name|bool
operator|>
operator|::
name|type
name|UnpackImpl
argument_list|(
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|TupleT *Tuple
argument_list|)
block|{
name|size_t
name|NewSize
operator|=
name|UnpackSingle
argument_list|(
name|Data
argument_list|,
name|Size
argument_list|,
operator|&
name|std
operator|::
name|get
operator|<
name|N
operator|>
operator|(
operator|*
name|Tuple
operator|)
argument_list|)
block|;
if|if
condition|(
name|NewSize
operator|==
name|Size
condition|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|UnpackImpl
operator|<
name|N
operator|+
literal|1
operator|,
name|TupleT
operator|>
operator|(
name|Data
operator|+
operator|(
name|Size
operator|-
name|NewSize
operator|)
operator|,
name|NewSize
operator|,
name|Tuple
operator|)
return|;
end_return

begin_comment
unit|}
comment|// Unpacks into arbitrary tuple and returns true if successful.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|bool
name|Unpack
argument_list|(
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|,
argument|std::tuple<Args...> *Tuple
argument_list|)
block|{
return|return
name|UnpackImpl
operator|<
literal|0
operator|,
name|std
operator|::
name|tuple
operator|<
name|Args
operator|...
operator|>>
operator|(
name|Data
operator|,
name|Size
operator|,
name|Tuple
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Helper integer sequence templates.
end_comment

begin_expr_stmt
name|template
operator|<
name|int
operator|...
operator|>
expr|struct
name|Seq
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|N
operator|,
name|int
operator|...
name|S
operator|>
expr|struct
name|GenSeq
operator|:
name|GenSeq
operator|<
name|N
operator|-
literal|1
operator|,
name|N
operator|-
literal|1
operator|,
name|S
operator|...
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// GenSeq<N>::type is Seq<0, 1, ..., N-1>
end_comment

begin_expr_stmt
name|template
operator|<
name|int
operator|...
name|S
operator|>
expr|struct
name|GenSeq
operator|<
literal|0
operator|,
name|S
operator|...
operator|>
block|{
typedef|typedef
name|Seq
operator|<
name|S
operator|...
operator|>
name|type
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Function signature introspection.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|FnTraits
block|{}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|ReturnType
operator|,
name|typename
operator|...
name|Args
operator|>
expr|struct
name|FnTraits
operator|<
name|ReturnType
argument_list|(
operator|*
argument_list|)
argument_list|(
name|Args
operator|...
argument_list|)
operator|>
block|{   enum
block|{
name|Arity
operator|=
expr|sizeof
operator|...
operator|(
name|Args
operator|)
block|}
block|;
typedef|typedef
name|std
operator|::
name|tuple
operator|<
name|Args
operator|...
operator|>
name|ArgsTupleT
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Calling a function with arguments in a tuple.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Fn
operator|,
name|int
operator|...
name|S
operator|>
name|void
name|ApplyImpl
argument_list|(
argument|Fn F
argument_list|,
argument|const typename FnTraits<Fn>::ArgsTupleT&Params
argument_list|,
argument|Seq<S...>
argument_list|)
block|{
name|F
argument_list|(
name|std
operator|::
name|get
operator|<
name|S
operator|>
operator|(
name|Params
operator|)
operator|...
argument_list|)
block|; }
name|template
operator|<
name|typename
name|Fn
operator|>
name|void
name|Apply
argument_list|(
argument|Fn F
argument_list|,
argument|const typename FnTraits<Fn>::ArgsTupleT&Params
argument_list|)
block|{
comment|// S is Seq<0, ..., Arity-1>
name|auto
name|S
operator|=
name|typename
name|GenSeq
operator|<
name|FnTraits
operator|<
name|Fn
operator|>
operator|::
name|Arity
operator|>
operator|::
name|type
argument_list|()
block|;
name|ApplyImpl
argument_list|(
name|F
argument_list|,
name|Params
argument_list|,
name|S
argument_list|)
block|; }
comment|// Unpacking data into arguments tuple of correct type and calling the function.
name|template
operator|<
name|typename
name|Fn
operator|>
name|bool
name|UnpackAndApply
argument_list|(
argument|Fn F
argument_list|,
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|)
block|{
name|typename
name|FnTraits
operator|<
name|Fn
operator|>
operator|::
name|ArgsTupleT
name|Tuple
block|;
if|if
condition|(
operator|!
name|Unpack
argument_list|(
name|Data
argument_list|,
name|Size
argument_list|,
operator|&
name|Tuple
argument_list|)
condition|)
return|return
name|false
return|;
name|Apply
argument_list|(
name|F
argument_list|,
name|Tuple
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}  }
comment|// namespace impl
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Fn
operator|>
name|bool
name|Adapt
argument_list|(
argument|Fn F
argument_list|,
argument|const uint8_t *Data
argument_list|,
argument|size_t Size
argument_list|)
block|{
return|return
name|impl
operator|::
name|UnpackAndApply
argument_list|(
name|F
argument_list|,
name|Data
argument_list|,
name|Size
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

