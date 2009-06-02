begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/type_traits.h - Simplfied type traits -------*- C++ -*-===//
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
comment|// This file provides a template class that determines if a type is a class or
end_comment

begin_comment
comment|// not. The basic mechanism, based on using the pointer to member function of
end_comment

begin_comment
comment|// a zero argument to a function was "boosted" from the boost type_traits
end_comment

begin_comment
comment|// library. See http://www.boost.org/ for all the gory details.
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
name|LLVM_SUPPORT_TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TYPE_TRAITS_H
end_define

begin_comment
comment|// This is actually the conforming implementation which works with abstract
end_comment

begin_comment
comment|// classes.  However, enough compilers have trouble with it that most will use
end_comment

begin_comment
comment|// the one in boost/type_traits/object_traits.hpp. This implementation actually
end_comment

begin_comment
comment|// works with VC7.0, but other interactions seem to fail when we use it.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dont_use
block|{
comment|// These two functions should never be used. They are helpers to
comment|// the is_class template below. They cannot be located inside
comment|// is_class because doing so causes at least GCC to think that
comment|// the value of the "value" enumerator is not constant. Placing
comment|// them out here (for some strange reason) allows the sizeof
comment|// operator against them to magically be constant. This is
comment|// important to make the is_class<T>::value idiom zero cost. it
comment|// evaluates to a constant 1 or 0 depending on whether the
comment|// parameter T is a class or not (respectively).
name|template
operator|<
name|typename
name|T
operator|>
name|char
name|is_class_helper
argument_list|(
name|void
argument_list|(
name|T
operator|::
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|double
name|is_class_helper
argument_list|(
operator|...
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|is_class
block|{
comment|// is_class<> metafunction due to Paul Mensonides (leavings@attbi.com). For
comment|// more details:
comment|// http://groups.google.com/groups?hl=en&selm=000001c1cc83%24e154d5e0%247772e50c%40c161550a&rnum=1
name|public
operator|:
expr|enum
block|{
name|value
operator|=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
operator|==
expr|sizeof
operator|(
name|dont_use
operator|::
name|is_class_helper
operator|<
name|T
operator|>
operator|(
literal|0
operator|)
operator|)
block|}
block|; }
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

