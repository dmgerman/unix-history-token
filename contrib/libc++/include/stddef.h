begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- stddef.h ---------------------------------===//
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__need_ptrdiff_t
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_size_t
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__need_wchar_t
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_NULL
argument_list|)
operator|||
name|defined
argument_list|(
name|__need_wint_t
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stddef.h>
end_empty

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_LIBCPP_STDDEF_H
argument_list|)
end_elif

begin_define
define|#
directive|define
name|_LIBCPP_STDDEF_H
end_define

begin_comment
comment|/*     stddef.h synopsis  Macros:      offsetof(type,member-designator)     NULL  Types:      ptrdiff_t     size_t     max_align_t     nullptr_t  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stddef.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C++"
block|{
include|#
directive|include
file|<__nullptr>
name|using
name|std
operator|::
name|nullptr_t
expr_stmt|;
block|}
end_extern

begin_comment
comment|// Re-use the compiler's<stddef.h> max_align_t where possible.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__CLANG_MAX_ALIGN_T_DEFINED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_GCC_MAX_ALIGN_T
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|__DEFINED_max_align_t
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|double
name|max_align_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_STDDEF_H
end_comment

end_unit

