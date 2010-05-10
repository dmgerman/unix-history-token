begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_common.h
end_comment

begin_comment
comment|/// \brief      Common definitions for tuklib modules
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_COMMON_H
end_define

begin_comment
comment|// The config file may be replaced by a package-specific file.
end_comment

begin_comment
comment|// It should include at least stddef.h, inttypes.h, and limits.h.
end_comment

begin_include
include|#
directive|include
file|"tuklib_config.h"
end_include

begin_comment
comment|// TUKLIB_SYMBOL_PREFIX is prefixed to all symbols exported by
end_comment

begin_comment
comment|// the tuklib modules. If you use a tuklib module in a library,
end_comment

begin_comment
comment|// you should use TUKLIB_SYMBOL_PREFIX to make sure that there
end_comment

begin_comment
comment|// are no symbol conflicts in case someone links your library
end_comment

begin_comment
comment|// into application that also uses the same tuklib module.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_SYMBOL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_SYMBOL_PREFIX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TUKLIB_CAT_X
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_define
define|#
directive|define
name|TUKLIB_CAT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|TUKLIB_CAT_X(a, b)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_SYMBOL
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_SYMBOL
parameter_list|(
name|sym
parameter_list|)
value|TUKLIB_CAT(TUKLIB_SYMBOL_PREFIX, sym)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_DECLS_BEGIN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|TUKLIB_DECLS_BEGIN
value|extern "C" {
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TUKLIB_DECLS_BEGIN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_DECLS_END
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|TUKLIB_DECLS_END
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TUKLIB_DECLS_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUC_MINOR__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TUKLIB_GNUC_REQ
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|((__GNUC__ == (major)&& __GNUC_MINOR__>= (minor)) \ 			|| __GNUC__> (major))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TUKLIB_GNUC_REQ
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TUKLIB_GNUC_REQ
argument_list|(
literal|2
operator|,
literal|5
argument_list|)
end_if

begin_define
define|#
directive|define
name|tuklib_attr_noreturn
value|__attribute__((__noreturn__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tuklib_attr_noreturn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|)
expr|\
operator|||
name|defined
argument_list|(
name|__OS2__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|TUKLIB_DOSLIKE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

