begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1994  * Hewlett-Packard Company  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Hewlett-Packard Company makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  *  *  * Copyright (c) 1996-1998  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/* NOTE: This is an internal header file, included by other STL headers.  *   You should not attempt to use it directly.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ALGOBASE_H
end_ifndef

begin_define
define|#
directive|define
name|__SGI_STL_INTERNAL_ALGOBASE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_CONFIG_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_RELOPS
end_ifndef

begin_include
include|#
directive|include
file|<stl_relops.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_PAIR_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_pair.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPE_TRAITS_H_
end_ifndef

begin_include
include|#
directive|include
file|<type_traits.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<new.h>
end_include

begin_include
include|#
directive|include
file|<iostream.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__SGI_STL_INTERNAL_ITERATOR_H
end_ifndef

begin_include
include|#
directive|include
file|<stl_iterator.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|__STL_BEGIN_NAMESPACE
comment|// swap and iter_swap
name|template
operator|<
name|class
name|_ForwardIter1
operator|,
name|class
name|_ForwardIter2
operator|,
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|__iter_swap
argument_list|(
argument|_ForwardIter1 __a
argument_list|,
argument|_ForwardIter2 __b
argument_list|,
argument|_Tp*
argument_list|)
block|{
name|_Tp
name|__tmp
operator|=
operator|*
name|__a
block|;
operator|*
name|__a
operator|=
operator|*
name|__b
block|;
operator|*
name|__b
operator|=
name|__tmp
block|; }
name|template
operator|<
name|class
name|_ForwardIter1
operator|,
name|class
name|_ForwardIter2
operator|>
specifier|inline
name|void
name|iter_swap
argument_list|(
argument|_ForwardIter1 __a
argument_list|,
argument|_ForwardIter2 __b
argument_list|)
block|{
name|__iter_swap
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|__VALUE_TYPE
argument_list|(
name|__a
argument_list|)
argument_list|)
block|; }
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|void
name|swap
argument_list|(
argument|_Tp& __a
argument_list|,
argument|_Tp& __b
argument_list|)
block|{
name|_Tp
name|__tmp
operator|=
name|__a
block|;
name|__a
operator|=
name|__b
block|;
name|__b
operator|=
name|__tmp
block|; }
comment|//--------------------------------------------------
comment|// min and max
ifndef|#
directive|ifndef
name|__BORLANDC__
undef|#
directive|undef
name|min
undef|#
directive|undef
name|max
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|min
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|)
block|{
return|return
name|__b
operator|<
name|__a
operator|?
name|__b
operator|:
name|__a
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|max
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|)
block|{
return|return
name|__a
operator|<
name|__b
operator|?
name|__b
operator|:
name|__a
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BORLANDC__ */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Compare
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|min
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
return|return
name|__comp
argument_list|(
name|__b
argument_list|,
name|__a
argument_list|)
operator|?
name|__b
operator|:
name|__a
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|,
name|class
name|_Compare
operator|>
specifier|inline
specifier|const
name|_Tp
operator|&
name|max
argument_list|(
argument|const _Tp& __a
argument_list|,
argument|const _Tp& __b
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
return|return
name|__comp
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
operator|?
name|__b
operator|:
name|__a
return|;
block|}
end_expr_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// copy
end_comment

begin_comment
comment|// All of these auxiliary functions serve two purposes.  (1) Replace
end_comment

begin_comment
comment|// calls to copy with memmove whenever possible.  (Memmove, not memcpy,
end_comment

begin_comment
comment|// because the input and output ranges are permitted to overlap.)
end_comment

begin_comment
comment|// (2) If we're using random access iterators, then write the loop as
end_comment

begin_comment
comment|// a for loop with an explicit count.  The auxiliary class __copy_dispatch
end_comment

begin_comment
comment|// is a workaround for compilers that don't support partial ordering of
end_comment

begin_comment
comment|// function templates.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_OutputIter
operator|,
name|class
name|_Distance
operator|>
specifier|inline
name|_OutputIter
name|__copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|input_iterator_tag
argument_list|,
argument|_Distance*
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__result
operator|,
operator|++
name|__first
control|)
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_RandomAccessIter
operator|,
name|class
name|_OutputIter
operator|,
name|class
name|_Distance
operator|>
specifier|inline
name|_OutputIter
name|__copy
argument_list|(
argument|_RandomAccessIter __first
argument_list|,
argument|_RandomAccessIter __last
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|,
argument|_Distance*
argument_list|)
block|{
for|for
control|(
name|_Distance
name|__n
init|=
name|__last
operator|-
name|__first
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
block|{
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
operator|++
name|__first
expr_stmt|;
operator|++
name|__result
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_Tp
operator|>
specifier|inline
name|_Tp
operator|*
name|__copy_trivial
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
operator|(
name|__last
operator|-
name|__first
operator|)
argument_list|)
block|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
operator|)
return|;
block|}
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifdef

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_OutputIter
operator|,
name|class
name|_BoolType
operator|>
expr|struct
name|__copy_dispatch
block|{
specifier|static
name|_OutputIter
name|copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|iterator_category
name|_Category
expr_stmt|;
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_Category
argument_list|()
argument_list|,
operator|(
name|_Distance
operator|*
operator|)
literal|0
argument_list|)
return|;
end_return

begin_empty_stmt
unit|} }
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__copy_dispatch
operator|<
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
return|return
name|__copy_trivial
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__copy_dispatch
operator|<
specifier|const
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
return|return
name|__copy_trivial
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_InputIter
operator|>
operator|::
name|value_type
name|_Tp
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|__type_traits
operator|<
name|_Tp
operator|>
operator|::
name|has_trivial_assignment_operator
name|_Trivial
expr_stmt|;
end_typedef

begin_return
return|return
name|__copy_dispatch
operator|<
name|_InputIter
operator|,
name|_OutputIter
operator|,
name|_Trivial
operator|>
operator|::
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_OutputIter
operator|>
specifier|inline
name|_OutputIter
name|copy
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_InputIter __last
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
return|return
name|__copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__ITERATOR_CATEGORY
argument_list|(
name|__first
argument_list|)
argument_list|,
name|__DISTANCE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|char
modifier|*
name|copy
parameter_list|(
specifier|const
name|char
modifier|*
name|__first
parameter_list|,
specifier|const
name|char
modifier|*
name|__last
parameter_list|,
name|char
modifier|*
name|__result
parameter_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
name|__last
operator|-
name|__first
argument_list|)
expr_stmt|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|wchar_t
modifier|*
name|copy
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|__first
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__last
parameter_list|,
name|wchar_t
modifier|*
name|__result
parameter_list|)
block|{
name|memmove
argument_list|(
name|__result
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
operator|(
name|__last
operator|-
name|__first
operator|)
argument_list|)
expr_stmt|;
return|return
name|__result
operator|+
operator|(
name|__last
operator|-
name|__first
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// copy_backward
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_BidirectionalIter1
operator|,
name|class
name|_BidirectionalIter2
operator|,
name|class
name|_Distance
operator|>
specifier|inline
name|_BidirectionalIter2
name|__copy_backward
argument_list|(
argument|_BidirectionalIter1 __first
argument_list|,
argument|_BidirectionalIter1 __last
argument_list|,
argument|_BidirectionalIter2 __result
argument_list|,
argument|bidirectional_iterator_tag
argument_list|,
argument|_Distance*
argument_list|)
block|{
while|while
condition|(
name|__first
operator|!=
name|__last
condition|)
operator|*
operator|--
name|__result
operator|=
operator|*
operator|--
name|__last
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_RandomAccessIter
operator|,
name|class
name|_BidirectionalIter
operator|,
name|class
name|_Distance
operator|>
specifier|inline
name|_BidirectionalIter
name|__copy_backward
argument_list|(
argument|_RandomAccessIter __first
argument_list|,
argument|_RandomAccessIter __last
argument_list|,
argument|_BidirectionalIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|,
argument|_Distance*
argument_list|)
block|{
for|for
control|(
name|_Distance
name|__n
init|=
name|__last
operator|-
name|__first
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
control|)
operator|*
operator|--
name|__result
operator|=
operator|*
operator|--
name|__last
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__result
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifdef

begin_comment
comment|// This dispatch class is a workaround for compilers that do not
end_comment

begin_comment
comment|// have partial ordering of function templates.  All we're doing is
end_comment

begin_comment
comment|// creating a specialization so that we can turn a call to copy_backward
end_comment

begin_comment
comment|// into a memmove whenever possible.
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_BidirectionalIter1
operator|,
name|class
name|_BidirectionalIter2
operator|,
name|class
name|_BoolType
operator|>
expr|struct
name|__copy_backward_dispatch
block|{
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_BidirectionalIter1
operator|>
operator|::
name|iterator_category
name|_Cat
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|iterator_traits
operator|<
name|_BidirectionalIter1
operator|>
operator|::
name|difference_type
name|_Distance
expr_stmt|;
end_typedef

begin_function
specifier|static
name|_BidirectionalIter2
name|copy
parameter_list|(
name|_BidirectionalIter1
name|__first
parameter_list|,
name|_BidirectionalIter1
name|__last
parameter_list|,
name|_BidirectionalIter2
name|__result
parameter_list|)
block|{
return|return
name|__copy_backward
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|_Cat
argument_list|()
argument_list|,
operator|(
name|_Distance
operator|*
operator|)
literal|0
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__copy_backward_dispatch
operator|<
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
specifier|const
name|ptrdiff_t
name|_Num
operator|=
name|__last
operator|-
name|__first
block|;
name|memmove
argument_list|(
name|__result
operator|-
name|_Num
argument_list|,
name|__first
argument_list|,
sizeof|sizeof
argument_list|(
name|_Tp
argument_list|)
operator|*
name|_Num
argument_list|)
block|;
return|return
name|__result
operator|-
name|_Num
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__copy_backward_dispatch
operator|<
specifier|const
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
block|{
specifier|static
name|_Tp
operator|*
name|copy
argument_list|(
argument|const _Tp* __first
argument_list|,
argument|const _Tp* __last
argument_list|,
argument|_Tp* __result
argument_list|)
block|{
return|return
name|__copy_backward_dispatch
operator|<
name|_Tp
operator|*
operator|,
name|_Tp
operator|*
operator|,
name|__true_type
operator|>
operator|::
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|_BI1
operator|,
name|class
name|_BI2
operator|>
specifier|inline
name|_BI2
name|copy_backward
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
typedef|typedef
name|typename
name|__type_traits
operator|<
name|typename
name|iterator_traits
operator|<
name|_BI2
operator|>
operator|::
name|value_type
operator|>
operator|::
name|has_trivial_assignment_operator
name|_Trivial
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__copy_backward_dispatch
operator|<
name|_BI1
operator|,
name|_BI2
operator|,
name|_Trivial
operator|>
operator|::
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
return|;
end_return

begin_else
unit|}
else|#
directive|else
end_else

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_BI1
operator|,
name|class
name|_BI2
operator|>
specifier|inline
name|_BI2
name|copy_backward
argument_list|(
argument|_BI1 __first
argument_list|,
argument|_BI1 __last
argument_list|,
argument|_BI2 __result
argument_list|)
block|{
return|return
name|__copy_backward
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|,
name|__ITERATOR_CATEGORY
argument_list|(
name|__first
argument_list|)
argument_list|,
name|__DISTANCE_TYPE
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// copy_n (not part of the C++ standard)
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_OutputIter
operator|>
name|pair
operator|<
name|_InputIter
operator|,
name|_OutputIter
operator|>
name|__copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|input_iterator_tag
argument_list|)
block|{
for|for
control|(
init|;
name|__count
operator|>
literal|0
condition|;
operator|--
name|__count
control|)
block|{
operator|*
name|__result
operator|=
operator|*
name|__first
expr_stmt|;
operator|++
name|__first
expr_stmt|;
operator|++
name|__result
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|_InputIter
operator|,
name|_OutputIter
operator|>
operator|(
name|__first
operator|,
name|__result
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_RAIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_OutputIter
operator|>
specifier|inline
name|pair
operator|<
name|_RAIter
operator|,
name|_OutputIter
operator|>
name|__copy_n
argument_list|(
argument|_RAIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_OutputIter __result
argument_list|,
argument|random_access_iterator_tag
argument_list|)
block|{
name|_RAIter
name|__last
operator|=
name|__first
operator|+
name|__count
block|;
return|return
name|pair
operator|<
name|_RAIter
operator|,
name|_OutputIter
operator|>
operator|(
name|__last
operator|,
name|copy
argument_list|(
name|__first
argument_list|,
name|__last
argument_list|,
name|__result
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_OutputIter
operator|>
specifier|inline
name|pair
operator|<
name|_InputIter
operator|,
name|_OutputIter
operator|>
name|__copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
return|return
name|__copy_n
argument_list|(
name|__first
argument_list|,
name|__count
argument_list|,
name|__result
argument_list|,
name|__ITERATOR_CATEGORY
argument_list|(
name|__first
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_OutputIter
operator|>
specifier|inline
name|pair
operator|<
name|_InputIter
operator|,
name|_OutputIter
operator|>
name|copy_n
argument_list|(
argument|_InputIter __first
argument_list|,
argument|_Size __count
argument_list|,
argument|_OutputIter __result
argument_list|)
block|{
return|return
name|__copy_n
argument_list|(
name|__first
argument_list|,
name|__count
argument_list|,
name|__result
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// fill and fill_n
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_ForwardIter
operator|,
name|class
name|_Tp
operator|>
name|void
name|fill
argument_list|(
argument|_ForwardIter __first
argument_list|,
argument|_ForwardIter __last
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
for|for
control|(
init|;
name|__first
operator|!=
name|__last
condition|;
operator|++
name|__first
control|)
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|_OutputIter
operator|,
name|class
name|_Size
operator|,
name|class
name|_Tp
operator|>
name|_OutputIter
name|fill_n
argument_list|(
argument|_OutputIter __first
argument_list|,
argument|_Size __n
argument_list|,
argument|const _Tp& __value
argument_list|)
block|{
for|for
control|(
init|;
name|__n
operator|>
literal|0
condition|;
operator|--
name|__n
operator|,
operator|++
name|__first
control|)
operator|*
name|__first
operator|=
name|__value
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|__first
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// equal and mismatch
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|>
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
name|mismatch
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|)
block|{
while|while
condition|(
name|__first1
operator|!=
name|__last1
operator|&&
operator|*
name|__first1
operator|==
operator|*
name|__first2
condition|)
block|{
operator|++
name|__first1
expr_stmt|;
operator|++
name|__first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
operator|(
name|__first1
operator|,
name|__first2
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|,
name|class
name|_BinaryPredicate
operator|>
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
name|mismatch
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
argument_list|)
block|{
while|while
condition|(
name|__first1
operator|!=
name|__last1
operator|&&
name|__binary_pred
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
block|{
operator|++
name|__first1
expr_stmt|;
operator|++
name|__first2
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|pair
operator|<
name|_InputIter1
operator|,
name|_InputIter2
operator|>
operator|(
name|__first1
operator|,
name|__first2
operator|)
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
if|if
condition|(
operator|*
name|__first1
operator|!=
operator|*
name|__first2
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|,
name|class
name|_BinaryPredicate
operator|>
specifier|inline
name|bool
name|equal
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_BinaryPredicate __binary_pred
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
if|if
condition|(
operator|!
name|__binary_pred
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// lexicographical_compare and lexicographical_compare_3way.
end_comment

begin_comment
comment|// (the latter is not part of the C++ standard.)
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
block|{
if|if
condition|(
operator|*
name|__first1
operator|<
operator|*
name|__first2
condition|)
return|return
name|true
return|;
if|if
condition|(
operator|*
name|__first2
operator|<
operator|*
name|__first1
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|__first1
operator|==
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|,
name|class
name|_Compare
operator|>
name|bool
name|lexicographical_compare
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|,
argument|_Compare __comp
argument_list|)
block|{
for|for
control|(
init|;
name|__first1
operator|!=
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
condition|;
operator|++
name|__first1
operator|,
operator|++
name|__first2
control|)
block|{
if|if
condition|(
name|__comp
argument_list|(
operator|*
name|__first1
argument_list|,
operator|*
name|__first2
argument_list|)
condition|)
return|return
name|true
return|;
if|if
condition|(
name|__comp
argument_list|(
operator|*
name|__first2
argument_list|,
operator|*
name|__first1
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_expr_stmt

begin_return
return|return
name|__first1
operator|==
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
return|;
end_return

begin_function
unit|}  inline
name|bool
name|lexicographical_compare
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last2
parameter_list|)
block|{
specifier|const
name|size_t
name|__len1
init|=
name|__last1
operator|-
name|__first1
decl_stmt|;
specifier|const
name|size_t
name|__len2
init|=
name|__last2
operator|-
name|__first2
decl_stmt|;
specifier|const
name|int
name|__result
init|=
name|memcmp
argument_list|(
name|__first1
argument_list|,
name|__first2
argument_list|,
name|min
argument_list|(
name|__len1
argument_list|,
name|__len2
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|__result
operator|!=
literal|0
condition|?
name|__result
operator|<
literal|0
else|:
name|__len1
operator|<
name|__len2
return|;
block|}
end_function

begin_function
specifier|inline
name|bool
name|lexicographical_compare
parameter_list|(
specifier|const
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|char
modifier|*
name|__last2
parameter_list|)
block|{
if|#
directive|if
name|CHAR_MAX
operator|==
name|SCHAR_MAX
return|return
name|lexicographical_compare
argument_list|(
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
else|#
directive|else
comment|/* CHAR_MAX == SCHAR_MAX */
return|return
name|lexicographical_compare
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
endif|#
directive|endif
comment|/* CHAR_MAX == SCHAR_MAX */
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|>
name|int
name|__lexicographical_compare_3way
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|)
block|{
while|while
condition|(
name|__first1
operator|!=
name|__last1
operator|&&
name|__first2
operator|!=
name|__last2
condition|)
block|{
if|if
condition|(
operator|*
name|__first1
operator|<
operator|*
name|__first2
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|*
name|__first2
operator|<
operator|*
name|__first1
condition|)
return|return
literal|1
return|;
operator|++
name|__first1
expr_stmt|;
operator|++
name|__first2
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|__first2
operator|==
name|__last2
condition|)
block|{
return|return
operator|!
operator|(
name|__first1
operator|==
name|__last1
operator|)
return|;
block|}
else|else
block|{
return|return
operator|-
literal|1
return|;
block|}
end_if

begin_function
unit|}  inline
name|int
name|__lexicographical_compare_3way
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|__last2
parameter_list|)
block|{
specifier|const
name|ptrdiff_t
name|__len1
init|=
name|__last1
operator|-
name|__first1
decl_stmt|;
specifier|const
name|ptrdiff_t
name|__len2
init|=
name|__last2
operator|-
name|__first2
decl_stmt|;
specifier|const
name|int
name|__result
init|=
name|memcmp
argument_list|(
name|__first1
argument_list|,
name|__first2
argument_list|,
name|min
argument_list|(
name|__len1
argument_list|,
name|__len2
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|__result
operator|!=
literal|0
condition|?
name|__result
else|:
operator|(
name|__len1
operator|==
name|__len2
condition|?
literal|0
else|:
operator|(
name|__len1
operator|<
name|__len2
condition|?
operator|-
literal|1
else|:
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|int
name|__lexicographical_compare_3way
parameter_list|(
specifier|const
name|char
modifier|*
name|__first1
parameter_list|,
specifier|const
name|char
modifier|*
name|__last1
parameter_list|,
specifier|const
name|char
modifier|*
name|__first2
parameter_list|,
specifier|const
name|char
modifier|*
name|__last2
parameter_list|)
block|{
if|#
directive|if
name|CHAR_MAX
operator|==
name|SCHAR_MAX
return|return
name|__lexicographical_compare_3way
argument_list|(
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|signed
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
else|#
directive|else
return|return
name|__lexicographical_compare_3way
argument_list|(
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last1
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__first2
argument_list|,
operator|(
specifier|const
name|unsigned
name|char
operator|*
operator|)
name|__last2
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|_InputIter1
operator|,
name|class
name|_InputIter2
operator|>
name|int
name|lexicographical_compare_3way
argument_list|(
argument|_InputIter1 __first1
argument_list|,
argument|_InputIter1 __last1
argument_list|,
argument|_InputIter2 __first2
argument_list|,
argument|_InputIter2 __last2
argument_list|)
block|{
return|return
name|__lexicographical_compare_3way
argument_list|(
name|__first1
argument_list|,
name|__last1
argument_list|,
name|__first2
argument_list|,
name|__last2
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
name|__STL_END_NAMESPACE
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SGI_STL_INTERNAL_ALGOBASE_H */
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

