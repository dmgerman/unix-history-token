begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include/llvm/ADT/iterator.h.  Generated from iterator.h.in by configure.  */
end_comment

begin_comment
comment|//==-- llvm/ADT/iterator.h - Portable wrapper around<iterator> --*- C++ -*-==//
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
comment|// This file provides a wrapper around the mysterious<iterator> header file.
end_comment

begin_comment
comment|// In GCC 2.95.3, the file defines a bidirectional_iterator class (and other
end_comment

begin_comment
comment|// friends), instead of the standard iterator class.  In GCC 3.1, the
end_comment

begin_comment
comment|// bidirectional_iterator class got moved out and the new, standards compliant,
end_comment

begin_comment
comment|// iterator<> class was added.  Because there is nothing that we can do to get
end_comment

begin_comment
comment|// correct behavior on both compilers, we have this header with #ifdef's.  Gross
end_comment

begin_comment
comment|// huh?
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// By #includ'ing this file, you get the contents of<iterator> plus the
end_comment

begin_comment
comment|// following classes in the global namespace:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   1. bidirectional_iterator
end_comment

begin_comment
comment|//   2. forward_iterator
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The #if directives' expressions are filled in by Autoconf.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// $FreeBSD$
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ADT_ITERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_ITERATOR_H
end_define

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_define
define|#
directive|define
name|HAVE_BI_ITERATOR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STD_ITERATOR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FWD_ITERATOR
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|HAVE_BI_ITERATOR
value|0
end_define

begin_define
define|#
directive|define
name|HAVE_STD_ITERATOR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FWD_ITERATOR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_BI_ITERATOR
end_if

begin_if
if|#
directive|if
name|HAVE_STD_ITERATOR
end_if

begin_comment
comment|/// If the bidirectional iterator is not defined, we attempt to define it in
end_comment

begin_comment
comment|/// terms of the C++ standard iterator. Otherwise, we import it with a "using"
end_comment

begin_comment
comment|/// statement.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Ty
operator|,
name|class
name|PtrDiffTy
operator|>
expr|struct
name|bidirectional_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|bidirectional_iterator_tag
operator|,
name|Ty
operator|,
name|PtrDiffTy
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Need to have standard iterator to define bidirectional iterator!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|using
name|std
operator|::
name|bidirectional_iterator
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_FWD_ITERATOR
end_if

begin_if
if|#
directive|if
name|HAVE_STD_ITERATOR
end_if

begin_comment
comment|/// If the forward iterator is not defined, attempt to define it in terms of
end_comment

begin_comment
comment|/// the C++ standard iterator. Otherwise, we import it with a "using" statement.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Ty
operator|,
name|class
name|PtrDiffTy
operator|>
expr|struct
name|forward_iterator
operator|:
name|public
name|std
operator|::
name|iterator
operator|<
name|std
operator|::
name|forward_iterator_tag
operator|,
name|Ty
operator|,
name|PtrDiffTy
operator|>
block|{ }
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"Need to have standard iterator to define forward iterator!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|using
name|std
operator|::
name|forward_iterator
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_ITERATOR_H
end_comment

end_unit

