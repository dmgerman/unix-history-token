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
comment|// This file defines the AlignedCharArray and AlignedCharArrayUnion classes.
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
comment|/// \struct AlignedCharArray
comment|/// \brief Helper for building an aligned character array type.
comment|///
comment|/// This template is used to explicitly build up a collection of aligned
comment|/// character array types. We have to build these up using a macro and explicit
comment|/// specialization to cope with MSVC (at least till 2015) where only an
comment|/// integer literal can be used to specify an alignment constraint. Once built
comment|/// up here, we can then begin to indirect between these using normal C++
comment|/// template parameters.
comment|// MSVC requires special handling here.
ifndef|#
directive|ifndef
name|_MSC_VER
name|template
operator|<
name|std
operator|::
name|size_t
name|Alignment
operator|,
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
block|{
name|LLVM_ALIGNAS
argument_list|(
argument|Alignment
argument_list|)
name|char
name|buffer
index|[
name|Size
index|]
block|; }
expr_stmt|;
else|#
directive|else
comment|// _MSC_VER
comment|/// \brief Create a type with an aligned char buffer.
name|template
operator|<
name|std
operator|::
name|size_t
name|Alignment
operator|,
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
expr_stmt|;
comment|// We provide special variations of this template for the most common
comment|// alignments because __declspec(align(...)) doesn't actually work when it is
comment|// a member of a by-value function argument in MSVC, even if the alignment
comment|// request is something reasonably like 8-byte or 16-byte. Note that we can't
comment|// even include the declspec with the union that forces the alignment because
comment|// MSVC warns on the existence of the declspec despite the union member forcing
comment|// proper alignment.
name|template
operator|<
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
operator|<
literal|1
operator|,
name|Size
operator|>
block|{
expr|union
block|{
name|char
name|aligned
block|;
name|char
name|buffer
index|[
name|Size
index|]
block|;   }
block|; }
expr_stmt|;
name|template
operator|<
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
operator|<
literal|2
operator|,
name|Size
operator|>
block|{
expr|union
block|{
name|short
name|aligned
block|;
name|char
name|buffer
index|[
name|Size
index|]
block|;   }
block|; }
expr_stmt|;
name|template
operator|<
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
operator|<
literal|4
operator|,
name|Size
operator|>
block|{
expr|union
block|{
name|int
name|aligned
block|;
name|char
name|buffer
index|[
name|Size
index|]
block|;   }
block|; }
expr_stmt|;
name|template
operator|<
name|std
operator|::
name|size_t
name|Size
operator|>
expr|struct
name|AlignedCharArray
operator|<
literal|8
operator|,
name|Size
operator|>
block|{
expr|union
block|{
name|double
name|aligned
block|;
name|char
name|buffer
index|[
name|Size
index|]
block|;   }
block|; }
expr_stmt|;
comment|// The rest of these are provided with a __declspec(align(...)) and we simply
comment|// can't pass them by-value as function arguments on MSVC.
define|#
directive|define
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
parameter_list|(
name|x
parameter_list|)
define|\
value|template<std::size_t Size> \   struct AlignedCharArray<x, Size> { \     __declspec(align(x)) char buffer[Size]; \   };
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|16
argument_list|)
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|32
argument_list|)
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|64
argument_list|)
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
argument_list|(
literal|128
argument_list|)
undef|#
directive|undef
name|LLVM_ALIGNEDCHARARRAY_TEMPLATE_ALIGNMENT
endif|#
directive|endif
comment|// _MSC_VER
name|namespace
name|detail
block|{
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
operator|,
name|typename
name|T5
operator|=
name|char
operator|,
name|typename
name|T6
operator|=
name|char
operator|,
name|typename
name|T7
operator|=
name|char
operator|,
name|typename
name|T8
operator|=
name|char
operator|,
name|typename
name|T9
operator|=
name|char
operator|,
name|typename
name|T10
operator|=
name|char
operator|>
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
name|T5
name|t5
block|;
name|T6
name|t6
block|;
name|T7
name|t7
block|;
name|T8
name|t8
block|;
name|T9
name|t9
block|;
name|T10
name|t10
block|;
name|AlignerImpl
argument_list|()
operator|=
name|delete
block|; }
expr_stmt|;
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
operator|,
name|typename
name|T5
operator|=
name|char
operator|,
name|typename
name|T6
operator|=
name|char
operator|,
name|typename
name|T7
operator|=
name|char
operator|,
name|typename
name|T8
operator|=
name|char
operator|,
name|typename
name|T9
operator|=
name|char
operator|,
name|typename
name|T10
operator|=
name|char
operator|>
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
block|,
name|arr5
index|[
sizeof|sizeof
argument_list|(
name|T5
argument_list|)
index|]
block|,
name|arr6
index|[
sizeof|sizeof
argument_list|(
name|T6
argument_list|)
index|]
block|,
name|arr7
index|[
sizeof|sizeof
argument_list|(
name|T7
argument_list|)
index|]
block|,
name|arr8
index|[
sizeof|sizeof
argument_list|(
name|T8
argument_list|)
index|]
block|,
name|arr9
index|[
sizeof|sizeof
argument_list|(
name|T9
argument_list|)
index|]
block|,
name|arr10
index|[
sizeof|sizeof
argument_list|(
name|T10
argument_list|)
index|]
block|; }
expr_stmt|;
block|}
comment|// end namespace detail
comment|/// \brief This union template exposes a suitably aligned and sized character
comment|/// array member which can hold elements of any of up to ten types.
comment|///
comment|/// These types may be arrays, structs, or any other types. The goal is to
comment|/// expose a char array buffer member which can be used as suitable storage for
comment|/// a placement new of any of these types. Support for more than ten types can
comment|/// be added at the cost of more boilerplate.
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
operator|,
name|typename
name|T5
operator|=
name|char
operator|,
name|typename
name|T6
operator|=
name|char
operator|,
name|typename
name|T7
operator|=
name|char
operator|,
name|typename
name|T8
operator|=
name|char
operator|,
name|typename
name|T9
operator|=
name|char
operator|,
name|typename
name|T10
operator|=
name|char
operator|>
expr|struct
name|AlignedCharArrayUnion
operator|:
name|llvm
operator|::
name|AlignedCharArray
operator|<
name|alignof
argument_list|(
name|llvm
operator|::
name|detail
operator|::
name|AlignerImpl
operator|<
name|T1
argument_list|,
name|T2
argument_list|,
name|T3
argument_list|,
name|T4
argument_list|,
name|T5
argument_list|,
name|T6
argument_list|,
name|T7
argument_list|,
name|T8
argument_list|,
name|T9
argument_list|,
name|T10
operator|>
argument_list|)
operator|,
sizeof|sizeof
argument_list|(
operator|::
name|llvm
operator|::
name|detail
operator|::
name|SizerImpl
operator|<
name|T1
argument_list|,
name|T2
argument_list|,
name|T3
argument_list|,
name|T4
argument_list|,
name|T5
argument_list|,
name|T6
argument_list|,
name|T7
argument_list|,
name|T8
argument_list|,
name|T9
argument_list|,
name|T10
operator|>
argument_list|)
operator|>
block|{ }
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
comment|// LLVM_SUPPORT_ALIGNOF_H
end_comment

end_unit

