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
comment|/// alignof - A templated function that returns the mininum alignment of
comment|///  of a type.  This provides no extra functionality beyond the AlignOf
comment|///  class besides some cosmetic cleanliness.  Example usage:
comment|///  alignof<int>() returns the alignment of an int.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
specifier|inline
name|unsigned
name|alignof
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

