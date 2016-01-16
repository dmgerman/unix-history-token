begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===------------------- support/musl/xlocale.h ------------------------===//
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

begin_comment
comment|// This adds support for the extended locale functions that are currently
end_comment

begin_comment
comment|// missing from the Musl C library.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This only works when the specified locale is "C" or "POSIX", but that's
end_comment

begin_comment
comment|// about as good as we can do without implementing full xlocale support
end_comment

begin_comment
comment|// in Musl.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_SUPPORT_MUSL_XLOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_MUSL_XLOCALE_H
end_define

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cwchar>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|static
specifier|inline
name|long
name|long
name|strtoll_l
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|strtoll
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|long
name|long
name|strtoull_l
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|strtoull
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|long
name|long
name|wcstoll_l
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|nptr
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|wcstoll
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|long
name|long
name|wcstoull_l
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|nptr
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|wcstoull
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|,
name|base
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|long
name|double
name|wcstold_l
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|nptr
parameter_list|,
name|wchar_t
modifier|*
modifier|*
name|endptr
parameter_list|,
name|locale_t
parameter_list|)
block|{
return|return
name|wcstold
argument_list|(
name|nptr
argument_list|,
name|endptr
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_MUSL_XLOCALE_H
end_comment

end_unit

