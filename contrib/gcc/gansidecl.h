begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ANSI and traditional C compatibility macros.    Copyright (C) 1996, 1997, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file mimics some of the support provided by include/ansidecl.h    in binutils and gdb releases.    ??? Over time the two should be merged into one.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GANSIDECL_H__
end_ifndef

begin_define
define|#
directive|define
name|__GANSIDECL_H__
end_define

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* Undef ansidecl.h's "obsolete" version. */
end_comment

begin_undef
undef|#
directive|undef
name|PROTO
end_undef

begin_comment
comment|/* These macros are deprecated, use ansidecl.h's PARAMS style instead. */
end_comment

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|PARAMS(ARGS)
end_define

begin_define
define|#
directive|define
name|VPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|VPARAMS(ARGS)
end_define

begin_define
define|#
directive|define
name|PVPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|PARAMS(ARGS)
end_define

begin_comment
comment|/* Autoconf will possibly define the `inline' or `const' keywords as    macros, however this is only valid for the stage1 compiler.  If we    detect a modern version of gcc, unconditionally reset the values.    This makes sure the right thing happens in stage2 and later.  We    need to do this very early; i.e. before any systems header files or    gcc header files in case they use these keywords.  Otherwise    conflicts might occur. */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
operator|)
end_if

begin_undef
undef|#
directive|undef
name|const
end_undef

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_define
define|#
directive|define
name|inline
value|__inline__
end_define

begin_comment
comment|/* Modern gcc can use `__inline__' freely. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC>= 2.7 */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED_LABEL
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|93
operator|)
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED_LABEL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED_LABEL
value|ATTRIBUTE_UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GNUC< 2.93 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_UNUSED_LABEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_UNUSED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_NORETURN
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_NORETURN
value|__attribute__ ((__noreturn__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_NORETURN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_PRINTF
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((format (__printf__, m, n)))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_1
value|ATTRIBUTE_PRINTF(1, 2)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_2
value|ATTRIBUTE_PRINTF(2, 3)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_3
value|ATTRIBUTE_PRINTF(3, 4)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_4
value|ATTRIBUTE_PRINTF(4, 5)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_5
value|ATTRIBUTE_PRINTF(5, 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_PRINTF */
end_comment

begin_define
define|#
directive|define
name|GENERIC_PTR
value|PTR
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_PTR
end_ifndef

begin_define
define|#
directive|define
name|NULL_PTR
value|((PTR) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GANSIDECL_H__ */
end_comment

end_unit

