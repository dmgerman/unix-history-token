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
name|LLVM_ADT_OPTIONAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_OPTIONAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|AlignedCharArrayUnion
operator|<
name|T
operator|>
name|storage
block|;
name|bool
name|hasVal
block|;
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
name|Optional
argument_list|(
name|NoneType
argument_list|)
operator|:
name|hasVal
argument_list|(
argument|false
argument_list|)
block|{}
name|explicit
name|Optional
argument_list|()
operator|:
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
name|hasVal
argument_list|(
argument|true
argument_list|)
block|{
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|y
argument_list|)
block|;   }
name|Optional
argument_list|(
specifier|const
name|Optional
operator|&
name|O
argument_list|)
operator|:
name|hasVal
argument_list|(
argument|O.hasVal
argument_list|)
block|{
if|if
condition|(
name|hasVal
condition|)
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
operator|*
name|O
argument_list|)
expr_stmt|;
block|}
name|Optional
argument_list|(
name|T
operator|&&
name|y
argument_list|)
operator|:
name|hasVal
argument_list|(
argument|true
argument_list|)
block|{
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|T
operator|>
operator|(
name|y
operator|)
argument_list|)
block|;   }
name|Optional
argument_list|(
name|Optional
operator|<
name|T
operator|>
operator|&&
name|O
argument_list|)
operator|:
name|hasVal
argument_list|(
argument|O
argument_list|)
block|{
if|if
condition|(
name|O
condition|)
block|{
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|O
argument_list|)
argument_list|)
expr_stmt|;
name|O
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
name|Optional
operator|&
name|operator
operator|=
operator|(
name|T
operator|&&
name|y
operator|)
block|{
if|if
condition|(
name|hasVal
condition|)
operator|*
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
name|y
argument_list|)
expr_stmt|;
else|else
block|{
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|hasVal
operator|=
name|true
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|Optional
modifier|&
name|operator
init|=
operator|(
name|Optional
operator|&&
name|O
operator|)
block|{
if|if
condition|(
operator|!
name|O
condition|)
name|reset
argument_list|()
expr_stmt|;
else|else
block|{
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
operator|*
name|O
argument_list|)
expr_stmt|;
name|O
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
comment|/// Create a new object by constructing it in place with the given arguments.
name|template
operator|<
name|typename
operator|...
name|ArgTypes
operator|>
name|void
name|emplace
argument_list|(
argument|ArgTypes&&...Args
argument_list|)
block|{
name|reset
argument_list|()
block|;
name|hasVal
operator|=
name|true
block|;
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|std
operator|::
name|forward
operator|<
name|ArgTypes
operator|>
operator|(
name|Args
operator|)
operator|...
argument_list|)
block|;   }
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
comment|// FIXME: these assignments (& the equivalent const T&/const Optional& ctors)
comment|// could be made more efficient by passing by value, possibly unifying them
comment|// with the rvalue versions above - but this could place a different set of
comment|// requirements (notably: the existence of a default ctor) when implemented
comment|// in that way. Careful SFINAE to avoid such pitfalls would be required.
name|Optional
modifier|&
name|operator
init|=
operator|(
specifier|const
name|T
operator|&
name|y
operator|)
block|{
if|if
condition|(
name|hasVal
condition|)
operator|*
operator|*
name|this
operator|=
name|y
expr_stmt|;
else|else
block|{
name|new
argument_list|(
argument|storage.buffer
argument_list|)
name|T
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|hasVal
operator|=
name|true
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|Optional
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Optional
operator|&
name|O
operator|)
block|{
if|if
condition|(
operator|!
name|O
condition|)
name|reset
argument_list|()
expr_stmt|;
else|else
operator|*
name|this
operator|=
operator|*
name|O
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_function
name|void
name|reset
parameter_list|()
block|{
if|if
condition|(
name|hasVal
condition|)
block|{
operator|(
operator|*
operator|*
name|this
operator|)
operator|.
expr|~
name|T
argument_list|()
expr_stmt|;
name|hasVal
operator|=
name|false
expr_stmt|;
block|}
block|}
end_function

begin_expr_stmt
operator|~
name|Optional
argument_list|()
block|{
name|reset
argument_list|()
block|;   }
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
name|reinterpret_cast
operator|<
specifier|const
name|T
operator|*
operator|>
operator|(
name|storage
operator|.
name|buffer
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|T
modifier|*
name|getPointer
parameter_list|()
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|storage
operator|.
name|buffer
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|T
operator|&
name|getValue
argument_list|()
specifier|const
name|LLVM_LVALUE_FUNCTION
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
operator|*
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|T
modifier|&
name|getValue
parameter_list|()
function|LLVM_LVALUE_FUNCTION
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
expr_stmt|;
return|return
operator|*
name|getPointer
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|hasVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|hasValue
argument_list|()
specifier|const
block|{
return|return
name|hasVal
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|T
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
return|return
name|getPointer
argument_list|()
return|;
block|}
end_block

begin_expr_stmt
specifier|const
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
name|LLVM_LVALUE_FUNCTION
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
operator|*
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|T
modifier|&
name|operator
modifier|*
parameter_list|()
function|LLVM_LVALUE_FUNCTION
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
expr_stmt|;
return|return
operator|*
name|getPointer
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|LLVM_CONSTEXPR
name|T
name|getValueOr
argument_list|(
argument|U&&value
argument_list|)
specifier|const
name|LLVM_LVALUE_FUNCTION
block|{
return|return
name|hasValue
argument_list|()
operator|?
name|getValue
argument_list|()
operator|:
name|std
operator|::
name|forward
operator|<
name|U
operator|>
operator|(
name|value
operator|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
name|LLVM_HAS_RVALUE_REFERENCE_THIS
end_if

begin_expr_stmt
name|T
operator|&&
name|getValue
argument_list|()
operator|&&
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|T
operator|&&
name|operator
operator|*
operator|(
operator|)
operator|&&
block|{
name|assert
argument_list|(
name|hasVal
argument_list|)
block|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|U
operator|>
name|T
name|getValueOr
argument_list|(
name|U
operator|&&
name|value
argument_list|)
operator|&&
block|{
return|return
name|hasValue
argument_list|()
operator|?
name|std
operator|::
name|move
argument_list|(
name|getValue
argument_list|()
argument_list|)
operator|:
name|std
operator|::
name|forward
operator|<
name|U
operator|>
operator|(
name|value
operator|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|isPodLike
operator|<
name|Optional
operator|<
name|T
operator|>
expr|>
block|{
comment|// An Optional<T> is pod-like if T is.
specifier|static
specifier|const
name|bool
name|value
operator|=
name|isPodLike
operator|<
name|T
operator|>
operator|::
name|value
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
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
name|NoneType
operator|)
block|{
return|return
operator|!
name|X
operator|.
name|hasValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
name|NoneType
operator|,
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|)
block|{
return|return
name|X
operator|==
name|None
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
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
name|NoneType
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|None
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
name|NoneType
operator|,
specifier|const
name|Optional
operator|<
name|T
operator|>
operator|&
name|X
operator|)
block|{
return|return
name|X
operator|!=
name|None
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// \brief Poison comparison between two \c Optional objects. Clients needs to
end_comment

begin_comment
comment|/// explicitly compare the underlying values and account for empty \c Optional
end_comment

begin_comment
comment|/// objects.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine will never be defined. It returns \c void to help diagnose
end_comment

begin_comment
comment|/// errors at compile time.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

