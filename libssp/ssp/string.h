begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Checking macros for string functions.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  In addition to the permissions in the GNU General Public License, the Free Software Foundation gives you unlimited permission to link the compiled version of this file into combinations with other programs, and to distribute those combinations without any restriction coming from the use of this file.  (The General Public License restrictions do apply in other respects; for example, they cover modification of the file, and distribution when not linked into a combine executable.)  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with files compiled with    GCC to produce an executable, this does not cause the resulting executable    to be covered by the GNU General Public License. This exception does not    however invalidate any other reasons why the executable file might be    covered by the GNU General Public License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSP_STRING_H
end_ifndef

begin_define
define|#
directive|define
name|_SSP_STRING_H
value|1
end_define

begin_include
include|#
directive|include
file|<ssp.h>
end_include

begin_empty
empty|#include_next<string.h>
end_empty

begin_if
if|#
directive|if
name|__SSP_FORTIFY_LEVEL
operator|>
literal|0
end_if

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_undef
undef|#
directive|undef
name|memmove
end_undef

begin_undef
undef|#
directive|undef
name|memset
end_undef

begin_undef
undef|#
directive|undef
name|strcat
end_undef

begin_undef
undef|#
directive|undef
name|strcpy
end_undef

begin_undef
undef|#
directive|undef
name|strncat
end_undef

begin_undef
undef|#
directive|undef
name|strncpy
end_undef

begin_undef
undef|#
directive|undef
name|mempcpy
end_undef

begin_undef
undef|#
directive|undef
name|stpcpy
end_undef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___memcpy_chk (dest, src, len, __ssp_bos0 (dest))		\    : __memcpy_ichk (dest, src, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|void
operator|*
name|__memcpy_ichk
argument_list|(
argument|void *__restrict__ __dest
argument_list|,
argument|const void *__restrict__ __src
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___memcpy_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__len
argument_list|,
name|__ssp_bos0
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___memmove_chk (dest, src, len, __ssp_bos0 (dest))		\    : __memmove_ichk (dest, src, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|void
operator|*
name|__memmove_ichk
argument_list|(
argument|void *__dest
argument_list|,
argument|const void *__src
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___memmove_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__len
argument_list|,
name|__ssp_bos0
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|mempcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___mempcpy_chk (dest, src, len, __ssp_bos0 (dest))	\    : __mempcpy_ichk (dest, src, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|void
operator|*
name|__mempcpy_ichk
argument_list|(
argument|void *__restrict__ __dest
argument_list|,
argument|const void *__restrict__ __src
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___mempcpy_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__len
argument_list|,
name|__ssp_bos0
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|dest
parameter_list|,
name|ch
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___memset_chk (dest, ch, len, __ssp_bos0 (dest))		\    : __memset_ichk (dest, ch, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|void
operator|*
name|__memset_ichk
argument_list|(
argument|void *__dest
argument_list|,
argument|int __ch
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___memset_chk
argument_list|(
name|__dest
argument_list|,
name|__ch
argument_list|,
name|__len
argument_list|,
name|__ssp_bos0
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|src
parameter_list|,
name|dest
parameter_list|,
name|len
parameter_list|)
value|((void) \  ((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___memmove_chk (dest, src, len, __ssp_bos0 (dest))	\    : __memmove_ichk (dest, src, len)))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|dest
parameter_list|,
name|len
parameter_list|)
value|((void) \   ((__ssp_bos0 (dest) != (size_t) -1)					\    ? __builtin___memset_chk (dest, '\0', len, __ssp_bos0 (dest))	\    : __memset_ichk (dest, '\0', len)))
end_define

begin_define
define|#
directive|define
name|strcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((__ssp_bos (dest) != (size_t) -1)					\    ? __builtin___strcpy_chk (dest, src, __ssp_bos (dest))		\    : __strcpy_ichk (dest, src))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|char
operator|*
name|__strcpy_ichk
argument_list|(
argument|char *__restrict__ __dest
argument_list|,
argument|const char *__restrict__ __src
argument_list|)
block|{
return|return
name|__builtin___strcpy_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__ssp_bos
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|stpcpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((__ssp_bos (dest) != (size_t) -1)					\    ? __builtin___stpcpy_chk (dest, src, __ssp_bos (dest))		\    : __stpcpy_ichk (dest, src))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|char
operator|*
name|__stpcpy_ichk
argument_list|(
argument|char *__restrict__ __dest
argument_list|,
argument|const char *__restrict__ __src
argument_list|)
block|{
return|return
name|__builtin___stpcpy_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__ssp_bos
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|strncpy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos (dest) != (size_t) -1)					\    ? __builtin___strncpy_chk (dest, src, len, __ssp_bos (dest))		\    : __strncpy_ichk (dest, src, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|char
operator|*
name|__strncpy_ichk
argument_list|(
argument|char *__restrict__ __dest
argument_list|,
argument|const char *__restrict__ __src
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___strncpy_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__len
argument_list|,
name|__ssp_bos
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|strcat
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
define|\
value|((__ssp_bos (dest) != (size_t) -1)					\    ? __builtin___strcat_chk (dest, src, __ssp_bos (dest))		\    : __strcat_ichk (dest, src))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|char
operator|*
name|__strcat_ichk
argument_list|(
argument|char *__restrict__ __dest
argument_list|,
argument|const char *__restrict__ __src
argument_list|)
block|{
return|return
name|__builtin___strcat_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__ssp_bos
argument_list|(
name|__dest
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|strncat
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|)
define|\
value|((__ssp_bos (dest) != (size_t) -1)					\    ? __builtin___strncat_chk (dest, src, len, __ssp_bos (dest))		\    : __strncat_ichk (dest, src, len))
end_define

begin_expr_stmt
specifier|static
specifier|inline
name|__attribute__
argument_list|(
argument|(__always_inline__)
argument_list|)
name|char
operator|*
name|__strncat_ichk
argument_list|(
argument|char *__restrict__ __dest
argument_list|,
argument|const char *__restrict__ __src
argument_list|,
argument|size_t __len
argument_list|)
block|{
return|return
name|__builtin___strncat_chk
argument_list|(
name|__dest
argument_list|,
name|__src
argument_list|,
name|__len
argument_list|,
name|__ssp_bos
argument_list|(
name|__dest
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
comment|/* __SSP_FORTIFY_LEVEL> 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSP_STRING_H */
end_comment

end_unit

