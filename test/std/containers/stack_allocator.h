begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|STACK_ALLOCATOR_H
end_ifndef

begin_define
define|#
directive|define
name|STACK_ALLOCATOR_H
end_define

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|std
operator|::
name|size_t
name|N
operator|>
name|class
name|stack_allocator
block|{
name|char
name|buf_
index|[
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
name|N
index|]
block|;
name|char
operator|*
name|ptr_
block|;
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|*
name|const_pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|value_type
modifier|&
name|const_reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|size_t
name|size_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|U
operator|>
expr|struct
name|rebind
block|{
typedef|typedef
name|stack_allocator
operator|<
name|U
operator|,
name|N
operator|>
name|other
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|stack_allocator
argument_list|()
operator|:
name|ptr_
argument_list|(
argument|buf_
argument_list|)
block|{}
name|private
operator|:
name|stack_allocator
argument_list|(
specifier|const
name|stack_allocator
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// = delete;
end_comment

begin_decl_stmt
name|stack_allocator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|stack_allocator
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = delete;
end_comment

begin_label
name|public
label|:
end_label

begin_function
name|pointer
name|allocate
parameter_list|(
name|size_type
name|n
parameter_list|,
specifier|const
name|void
modifier|*
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|n
operator|>
name|N
operator|-
operator|(
name|ptr_
operator|-
name|buf_
operator|)
operator|/
sizeof|sizeof
argument_list|(
name|value_type
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|_LIBCPP_NO_EXCEPTIONS
name|throw
name|std
operator|::
name|bad_alloc
argument_list|()
expr_stmt|;
else|#
directive|else
name|std
operator|::
name|terminate
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
name|pointer
name|r
init|=
operator|(
name|T
operator|*
operator|)
name|ptr_
decl_stmt|;
name|ptr_
operator|+=
name|n
operator|*
sizeof|sizeof
argument_list|(
name|T
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
name|void
name|deallocate
parameter_list|(
name|pointer
name|p
parameter_list|,
name|size_type
name|n
parameter_list|)
block|{
if|if
condition|(
operator|(
name|char
operator|*
operator|)
operator|(
name|p
operator|+
name|n
operator|)
operator|==
name|ptr_
condition|)
name|ptr_
operator|=
operator|(
name|char
operator|*
operator|)
name|p
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|size_type
name|max_size
argument_list|()
specifier|const
block|{
return|return
name|N
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|,
name|std
operator|::
name|size_t
name|N
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|stack_allocator<T
argument_list|,
argument|N>& x
argument_list|,
argument|stack_allocator<T
argument_list|,
argument|N>& y
argument_list|)
block|{}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// STACK_ALLOCATOR_H
end_comment

end_unit

