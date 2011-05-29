begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Optional.h - Simple variant for passing optional values ---*- C++ -*-=//
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
comment|//  This file provides Optional, a template class modeled in the spirit of
end_comment

begin_comment
comment|//  OCaml's 'opt' variant.  The idea is to strongly type whether or not
end_comment

begin_comment
comment|//  a value can be optional.
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
name|LLVM_ADT_OPTIONAL
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_OPTIONAL
end_define

begin_include
include|#
directive|include
file|<cassert>
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
name|class
name|Optional
block|{
name|T
name|x
block|;
name|unsigned
name|hasVal
operator|:
literal|1
block|;
name|public
operator|:
name|explicit
name|Optional
argument_list|()
operator|:
name|x
argument_list|()
block|,
name|hasVal
argument_list|(
argument|false
argument_list|)
block|{}
name|Optional
argument_list|(
specifier|const
name|T
operator|&
name|y
argument_list|)
operator|:
name|x
argument_list|(
name|y
argument_list|)
block|,
name|hasVal
argument_list|(
argument|true
argument_list|)
block|{}
specifier|static
specifier|inline
name|Optional
name|create
argument_list|(
argument|const T* y
argument_list|)
block|{
return|return
name|y
operator|?
name|Optional
argument_list|(
operator|*
name|y
argument_list|)
operator|:
name|Optional
argument_list|()
return|;
block|}
name|Optional
operator|&
name|operator
operator|=
operator|(
specifier|const
name|T
operator|&
name|y
operator|)
block|{
name|x
operator|=
name|y
block|;
name|hasVal
operator|=
name|true
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|const
name|T
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
operator|&
name|x
return|;
block|}
specifier|const
name|T
operator|&
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
name|x
return|;
block|}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|hasVal
return|;
block|}
name|bool
name|hasValue
argument_list|()
specifier|const
block|{
return|return
name|hasVal
return|;
block|}
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|getPointer
argument_list|()
return|;
block|}
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
name|x
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|Optional
operator|<
name|T
operator|>
expr|>
block|{
typedef|typedef
specifier|const
name|T
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const Optional<T>&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getPointer
argument_list|()
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|simplify_type
operator|<
name|Optional
operator|<
name|T
operator|>
expr|>
operator|:
name|public
name|simplify_type
operator|<
specifier|const
name|Optional
operator|<
name|T
operator|>
expr|>
block|{}
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|==
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|!=
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|<
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|<=
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|>=
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
comment|/// explicitly compare the underlying values and account for empty \c Optional
comment|/// objects.
comment|///
comment|/// This routine will never be defined. It returns \c void to help diagnose
comment|/// errors at compile time.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
name|void
name|operator
operator|>
operator|(
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|,
specifier|const
name|Optional
operator|<
name|U
operator|>
operator|&
name|Y
operator|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

