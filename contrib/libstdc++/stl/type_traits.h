begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1997  * Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, distribute and sell this software  * and its documentation for any purpose is hereby granted without fee,  * provided that the above copyright notice appear in all copies and  * that both that copyright notice and this permission notice appear  * in supporting documentation.  Silicon Graphics makes no  * representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|__TYPE_TRAITS_H
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

begin_comment
comment|/* This header file provides a framework for allowing compile time dispatch based on type attributes. This is useful when writing template code. For example, when making a copy of an array of an unknown type, it helps to know if the type has a trivial copy constructor or not, to help decide if a memcpy can be used.  The class template __type_traits provides a series of typedefs each of which is either __true_type or __false_type. The argument to __type_traits can be any type. The typedefs within this template will attain their correct values by one of these means:     1. The general instantiation contain conservative values which work        for all types.     2. Specializations may be declared to make distinctions between types.     3. Some compilers (such as the Silicon Graphics N32 and N64 compilers)        will automatically provide the appropriate specializations for all        types.  EXAMPLE:  //Copy an array of elements which have non-trivial copy constructors template<class T> void copy(T* source, T* destination, int n, __false_type); //Copy an array of elements which have trivial copy constructors. Use memcpy. template<class T> void copy(T* source, T* destination, int n, __true_type);  //Copy an array of any type by using the most efficient copy mechanism template<class T> inline void copy(T* source,T* destination,int n) {    copy(source, destination, n,         typename __type_traits<T>::has_trivial_copy_constructor()); } */
end_comment

begin_struct
struct|struct
name|__true_type
block|{ }
struct|;
end_struct

begin_struct
struct|struct
name|__false_type
block|{ }
struct|;
end_struct

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__type_traits
block|{
typedef|typedef
name|__true_type
name|this_dummy_member_must_be_first
typedef|;
end_expr_stmt

begin_comment
comment|/* Do not remove this member. It informs a compiler which                       automatically specializes __type_traits that this                       __type_traits template is special. It just makes sure that                       things work if an implementation is using a template                       called __type_traits for something unrelated. */
end_comment

begin_comment
comment|/* The following restrictions should be observed for the sake of       compilers which automatically produce type specific specializations        of this class:           - You may reorder the members below if you wish           - You may remove any of the members below if you wish           - You must not rename members without making the corresponding             name change in the compiler           - Members you add will be treated like regular members unless             you add the appropriate support in the compiler. */
end_comment

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_default_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__false_type
name|is_POD_type
typedef|;
end_typedef

begin_comment
unit|};
comment|// Provide some specializations.  This is harmless for compilers that
end_comment

begin_comment
comment|//  have built-in __types_traits support, and essential for compilers
end_comment

begin_comment
comment|//  that don't.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_NO_BOOL
end_ifndef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|bool
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_NO_BOOL */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|signed
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__STL_HAS_WCHAR_T
end_ifdef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|wchar_t
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_HAS_WCHAR_T */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__STL_LONG_LONG
end_ifdef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_LONG_LONG */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|float
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|double
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|long
name|double
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_ifdef
unit|};
ifdef|#
directive|ifdef
name|__STL_CLASS_PARTIAL_SPECIALIZATION
end_ifdef

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|__type_traits
operator|<
name|_Tp
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_else
unit|};
else|#
directive|else
end_else

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|signed
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
name|unsigned
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
specifier|const
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
specifier|const
name|signed
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_macro
unit|};
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|__type_traits
operator|<
specifier|const
name|unsigned
name|char
operator|*
operator|>
block|{
typedef|typedef
name|__true_type
name|has_trivial_default_constructor
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_copy_constructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_assignment_operator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|has_trivial_destructor
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__true_type
name|is_POD_type
typedef|;
end_typedef

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_CLASS_PARTIAL_SPECIALIZATION */
end_comment

begin_comment
comment|// The following could be written in terms of numeric_limits.
end_comment

begin_comment
comment|// We're doing it separately to reduce the number of dependencies.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|_Tp
operator|>
expr|struct
name|_Is_integer
block|{
typedef|typedef
name|__false_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__STL_NO_BOOL
end_ifndef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|bool
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_NO_BOOL */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|signed
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|unsigned
name|char
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_HAS_WCHAR_T
end_ifdef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|wchar_t
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_HAS_WCHAR_T */
end_comment

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|unsigned
name|short
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|unsigned
name|int
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|unsigned
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STL_LONG_LONG
end_ifdef

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__STL_TEMPLATE_NULL
end_macro

begin_expr_stmt
unit|struct
name|_Is_integer
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
typedef|typedef
name|__true_type
name|_Integral
typedef|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STL_LONG_LONG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __TYPE_TRAITS_H */
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

