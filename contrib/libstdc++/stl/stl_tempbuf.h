begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996,1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_TEMPBUF_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_TEMPBUF_H
end_define

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
name|template
operator|<
name|class
name|_Tp
operator|>
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
name|__get_temporary_buffer
argument_list|(
argument|ptrdiff_t __len
argument_list|,
argument|_Tp*
argument_list|)
block|{
if|if
condition|(
name|__len
operator|>
name|ptrdiff_t
argument_list|(
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
condition|)
name|__len
operator|=
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
name|__len
operator|>
literal|0
condition|)
block|{
name|_Tp
modifier|*
name|__tmp
init|=
operator|(
name|_Tp
operator|*
operator|)
name|malloc
argument_list|(
operator|(
name|size_t
operator|)
name|__len
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|__tmp
operator|!=
literal|0
condition|)
return|return
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
operator|(
name|__tmp
operator|,
name|__len
operator|)
return|;
name|__len
operator|/=
literal|2
expr_stmt|;
block|}
end_while

begin_return
return|return
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
operator|(
operator|(
name|_Tp
operator|*
operator|)
literal|0
operator|,
literal|0
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__STL_EXPLICIT_FUNCTION_TMPL_ARGS
end_ifdef

begin_expr_stmt
unit|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
name|get_temporary_buffer
argument_list|(
argument|ptrdiff_t __len
argument_list|)
block|{
return|return
name|__get_temporary_buffer
argument_list|(
name|__len
argument_list|,
operator|(
name|_Tp
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_EXPLICIT_FUNCTION_TMPL_ARGS */
end_comment

begin_comment
comment|// This overload is not required by the standard; it is an extension.
end_comment

begin_comment
comment|// It is supported for backward compatibility with the HP STL, and
end_comment

begin_comment
comment|// because not all compilers support the language feature (explicit
end_comment

begin_comment
comment|// function template arguments) that is required for the standard
end_comment

begin_comment
comment|// version of get_temporary_buffer.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|pair
operator|<
name|_Tp
operator|*
operator|,
name|ptrdiff_t
operator|>
name|get_temporary_buffer
argument_list|(
argument|ptrdiff_t __len
argument_list|,
argument|_Tp*
argument_list|)
block|{
return|return
name|__get_temporary_buffer
argument_list|(
name|__len
argument_list|,
operator|(
name|_Tp
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
name|void
name|return_temporary_buffer
argument_list|(
argument|_Tp* __p
argument_list|)
block|{
name|free
argument_list|(
name|__p
argument_list|)
block|; }
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
operator|>
name|class
name|_Temporary_buffer
block|{
name|private
operator|:
name|ptrdiff_t
name|_M_original_len
block|;
name|ptrdiff_t
name|_M_len
block|;
name|_Tp
operator|*
name|_M_buffer
block|;
name|void
name|_M_allocate_buffer
argument_list|()
block|{
name|_M_original_len
operator|=
name|_M_len
block|;
name|_M_buffer
operator|=
literal|0
block|;
if|if
condition|(
name|_M_len
operator|>
call|(
name|ptrdiff_t
call|)
argument_list|(
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
condition|)
name|_M_len
operator|=
name|INT_MAX
operator|/
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
expr_stmt|;
while|while
condition|(
name|_M_len
operator|>
literal|0
condition|)
block|{
name|_M_buffer
operator|=
operator|(
name|_Tp
operator|*
operator|)
name|malloc
argument_list|(
name|_M_len
operator|*
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|_M_buffer
condition|)
break|break;
name|_M_len
operator|/=
literal|2
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|}    void
name|_M_initialize_buffer
argument_list|(
argument|const _Tp&
argument_list|,
argument|__true_type
argument_list|)
end_macro

begin_block
block|{}
end_block

begin_function
name|void
name|_M_initialize_buffer
parameter_list|(
specifier|const
name|_Tp
modifier|&
name|val
parameter_list|,
name|__false_type
parameter_list|)
block|{
name|uninitialized_fill_n
argument_list|(
name|_M_buffer
argument_list|,
name|_M_len
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|ptrdiff_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|_M_len
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ptrdiff_t
name|requested_size
argument_list|()
specifier|const
block|{
return|return
name|_M_original_len
return|;
block|}
end_expr_stmt

begin_function
name|_Tp
modifier|*
name|begin
parameter_list|()
block|{
return|return
name|_M_buffer
return|;
block|}
end_function

begin_function
name|_Tp
modifier|*
name|end
parameter_list|()
block|{
return|return
name|_M_buffer
operator|+
name|_M_len
return|;
block|}
end_function

begin_macro
name|_Temporary_buffer
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
end_macro

begin_block
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Tp
operator|>
operator|::
name|has_trivial_default_constructor
name|_Trivial
expr_stmt|;
name|__STL_TRY
block|{
name|_M_len
operator|=
literal|0
expr_stmt|;
name|distance
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|_M_len
argument_list|)
expr_stmt|;
name|_M_allocate_buffer
argument_list|()
expr_stmt|;
if|if
condition|(
name|_M_len
operator|>
literal|0
condition|)
name|_M_initialize_buffer
argument_list|(
operator|*
name|__first
argument_list|,
name|_Trivial
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|__STL_UNWIND
argument_list|(
argument|free(_M_buffer); _M_buffer =
literal|0
argument|; _M_len =
literal|0
argument_list|)
empty_stmt|;
block|}
end_block

begin_expr_stmt
operator|~
name|_Temporary_buffer
argument_list|()
block|{
name|destroy
argument_list|(
name|_M_buffer
argument_list|,
name|_M_buffer
operator|+
name|_M_len
argument_list|)
block|;
name|free
argument_list|(
name|_M_buffer
argument_list|)
block|;   }
name|private
operator|:
comment|// Disable copy constructor and assignment operator.
name|_Temporary_buffer
argument_list|(
argument|const _Temporary_buffer&
argument_list|)
block|{}
name|void
name|operator
operator|=
operator|(
specifier|const
name|_Temporary_buffer
operator|&
operator|)
block|{}
end_expr_stmt

begin_comment
unit|};
comment|// Class temporary_buffer is not part of the standard.  It is an extension.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIterator
operator|,
name|class
name|_Tp
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
operator|=
name|typename
name|iterator_traits
operator|<
name|_ForwardIterator
operator|>
operator|::
name|value_type
endif|#
directive|endif
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
operator|>
expr|struct
name|temporary_buffer
operator|:
name|public
name|_Temporary_buffer
operator|<
name|_ForwardIterator
operator|,
name|_Tp
operator|>
block|{
name|temporary_buffer
argument_list|(
argument|_ForwardIterator __first
argument_list|,
argument|_ForwardIterator __last
argument_list|)
operator|:
name|_Temporary_buffer
operator|<
name|_ForwardIterator
block|,
name|_Tp
operator|>
operator|(
name|__first
operator|,
name|__last
operator|)
block|{}
operator|~
name|temporary_buffer
argument_list|()
block|{}
block|}
expr_stmt|;
end_expr_stmt

begin_macro
name|__STL_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_TEMPBUF_H */
end_comment

begin_comment
comment|// Local Variables:
end_comment

begin_comment
comment|// mode:C++
end_comment

begin_comment
comment|// End:
end_comment

end_unit

