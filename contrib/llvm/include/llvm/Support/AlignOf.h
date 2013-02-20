begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AlignOf.h - Portable calculation of type alignment -----*- C++ -*-===//
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
comment|// This file defines the AlignOf function that computes alignments for
end_comment

begin_comment
comment|// arbitrary types.
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
name|LLVM_SUPPORT_ALIGNOF_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ALIGNOF_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|AlignmentCalcImpl
block|{
name|char
name|x
block|;
name|T
name|t
block|;
name|private
operator|:
name|AlignmentCalcImpl
argument_list|()
block|{}
comment|// Never instantiate.
block|}
expr_stmt|;
comment|/// AlignOf - A templated class that contains an enum value representing
comment|///  the alignment of the template argument.  For example,
comment|///  AlignOf<int>::Alignment represents the alignment of type "int".  The
comment|///  alignment calculated is the minimum alignment, and not necessarily
comment|///  the "desired" alignment returned by GCC's __alignof__ (for example).  Note
comment|///  that because the alignment is an enum value, it can be used as a
comment|///  compile-time constant (e.g., for template instantiation).
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|AlignOf
block|{   enum
block|{
name|Alignment
operator|=
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
sizeof|sizeof
argument_list|(
name|AlignmentCalcImpl
operator|<
name|T
operator|>
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|)
block|}
block|;    enum
block|{
name|Alignment_GreaterEqual_2Bytes
operator|=
name|Alignment
operator|>=
literal|2
operator|?
literal|1
operator|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_GreaterEqual_4Bytes
operator|=
name|Alignment
operator|>=
literal|4
condition|?
literal|1
else|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_GreaterEqual_8Bytes
operator|=
name|Alignment
operator|>=
literal|8
condition|?
literal|1
else|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_GreaterEqual_16Bytes
operator|=
name|Alignment
operator|>=
literal|16
condition|?
literal|1
else|:
literal|0
block|}
block|;    enum
block|{
name|Alignment_LessEqual_2Bytes
operator|=
name|Alignment
operator|<=
literal|2
condition|?
literal|1
else|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_LessEqual_4Bytes
operator|=
name|Alignment
operator|<=
literal|4
condition|?
literal|1
else|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_LessEqual_8Bytes
operator|=
name|Alignment
operator|<=
literal|8
condition|?
literal|1
else|:
literal|0
block|}
block|;   enum
block|{
name|Alignment_LessEqual_16Bytes
operator|=
name|Alignment
operator|<=
literal|16
condition|?
literal|1
else|:
literal|0
block|}
block|;  }
expr_stmt|;
comment|/// alignOf - A templated function that returns the minimum alignment of
comment|///  of a type.  This provides no extra functionality beyond the AlignOf
comment|///  class besides some cosmetic cleanliness.  Example usage:
comment|///  alignOf<int>() returns the alignment of an int.
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|unsigned
name|alignOf
argument_list|()
block|{
return|return
name|AlignOf
operator|<
name|T
operator|>
operator|::
name|Alignment
return|;
block|}
comment|/// \brief Helper for building an aligned character array type.
comment|///
comment|/// This template is used to explicitly build up a collection of aligned
comment|/// character types. We have to build these up using a macro and explicit
comment|/// specialization to cope with old versions of MSVC and GCC where only an
comment|/// integer literal can be used to specify an alignment constraint. Once built
comment|/// up here, we can then begin to indirect between these using normal C++
comment|/// template parameters.
name|template
operator|<
name|size_t
name|Alignment
operator|>
expr|struct
name|AlignedCharArrayImpl
expr_stmt|;
comment|// MSVC requires special handling here.
ifndef|#
directive|ifndef
name|_MSC_VER
if|#
directive|if
name|__has_feature
argument_list|(
name|cxx_alignas
argument_list|)
define|#
directive|define
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
parameter_list|(
name|x
parameter_list|)
define|\
value|template<> struct AlignedCharArrayImpl<x> { \     char alignas(x) aligned; \   }
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__IBM_ATTRIBUTES
argument_list|)
define|#
directive|define
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
parameter_list|(
name|x
parameter_list|)
define|\
value|template<> struct AlignedCharArrayImpl<x> { \     char aligned __attribute__((aligned(x))); \   }
else|#
directive|else
error|#
directive|error
error|No supported align as directive.
endif|#
directive|endif
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|64
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|128
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|512
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|1024
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|2048
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|4096
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|8192
argument_list|)
expr_stmt|;
undef|#
directive|undef
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
else|#
directive|else
comment|// _MSC_VER
comment|// We provide special variations of this template for the most common
comment|// alignments because __declspec(align(...)) doesn't actually work when it is
comment|// a member of a by-value function argument in MSVC, even if the alignment
comment|// request is something reasonably like 8-byte or 16-byte.
name|template
operator|<
operator|>
expr|struct
name|AlignedCharArrayImpl
operator|<
literal|1
operator|>
block|{
name|char
name|aligned
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|AlignedCharArrayImpl
operator|<
literal|2
operator|>
block|{
name|short
name|aligned
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|AlignedCharArrayImpl
operator|<
literal|4
operator|>
block|{
name|int
name|aligned
block|; }
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|AlignedCharArrayImpl
operator|<
literal|8
operator|>
block|{
name|double
name|aligned
block|; }
expr_stmt|;
define|#
directive|define
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
parameter_list|(
name|x
parameter_list|)
define|\
value|template<> struct AlignedCharArrayImpl<x> { \     __declspec(align(x)) char aligned; \   }
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|32
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|64
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|128
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|512
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|1024
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|2048
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|4096
argument_list|)
expr_stmt|;
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|8192
argument_list|)
expr_stmt|;
comment|// Any larger and MSVC complains.
undef|#
directive|undef
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
endif|#
directive|endif
comment|// _MSC_VER
comment|/// \brief This union template exposes a suitably aligned and sized character
comment|/// array member which can hold elements of any of up to four types.
comment|///
comment|/// These types may be arrays, structs, or any other types. The goal is to
comment|/// produce a union type containing a character array which, when used, forms
comment|/// storage suitable to placement new any of these types over. Support for more
comment|/// than four types can be added at the cost of more boiler plate.
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|=
name|char
operator|,
name|typename
name|T3
operator|=
name|char
operator|,
name|typename
name|T4
operator|=
name|char
operator|>
expr|union
name|AlignedCharArrayUnion
block|{
name|private
operator|:
name|class
name|AlignerImpl
block|{
name|T1
name|t1
block|;
name|T2
name|t2
block|;
name|T3
name|t3
block|;
name|T4
name|t4
block|;
name|AlignerImpl
argument_list|()
block|;
comment|// Never defined or instantiated.
block|}
block|;
expr|union
name|SizerImpl
block|{
name|char
name|arr1
index|[
sizeof|sizeof
argument_list|(
name|T1
argument_list|)
index|]
block|,
name|arr2
index|[
sizeof|sizeof
argument_list|(
name|T2
argument_list|)
index|]
block|,
name|arr3
index|[
sizeof|sizeof
argument_list|(
name|T3
argument_list|)
index|]
block|,
name|arr4
index|[
sizeof|sizeof
argument_list|(
name|T4
argument_list|)
index|]
block|;   }
block|;
name|public
operator|:
comment|/// \brief The character array buffer for use by clients.
comment|///
comment|/// No other member of this union should be referenced. The exist purely to
comment|/// constrain the layout of this character array.
name|char
name|buffer
index|[
sizeof|sizeof
argument_list|(
name|SizerImpl
argument_list|)
index|]
block|;
name|private
operator|:
comment|// Tests seem to indicate that both Clang and GCC will properly register the
comment|// alignment of a struct containing an aligned member, and this alignment
comment|// should carry over to the character array in the union.
name|llvm
operator|::
name|AlignedCharArrayImpl
operator|<
name|AlignOf
operator|<
name|AlignerImpl
operator|>
operator|::
name|Alignment
operator|>
name|nonce_member
block|; }
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

end_unit

