begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Specific definitions for HPUX  -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 2000, 2002 Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCPP_OS_DEFINES
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCPP_OS_DEFINES
value|1
end_define

begin_comment
comment|// System-specific #define, typedefs, corrections, etc, go here.  This
end_comment

begin_comment
comment|// file will come before all others.
end_comment

begin_define
define|#
directive|define
name|__off_t
value|off_t
end_define

begin_define
define|#
directive|define
name|__off64_t
value|off64_t
end_define

begin_define
define|#
directive|define
name|__ssize_t
value|ssize_t
end_define

begin_comment
comment|// Use macro form of ctype functions to ensure __SB_masks is defined.
end_comment

begin_define
define|#
directive|define
name|_SB_CTYPE_MACROS
value|1
end_define

begin_comment
comment|/* HP-UX, for reasons unknown choose to use a different name for    the string to [unsigned] long long conversion routines.     Furthermore, instead of having the prototypes in stdlib.h like    everyone else, they put them into a non-standard header<inttypes.h>.  Ugh.<inttypes.h> defines a variety of things, some of which we     probably do not want.  So we don't want to include it here.     Luckily we can just declare strtoll and strtoull with the    __asm extension which effectively renames calls at the    source level without namespace pollution.     Also note that the compiler defines _INCLUDE_LONGLONG for C++    unconditionally, which makes intmax_t and uintmax_t long long    types.     We also force _GLIBCPP_USE_LONG_LONG here so that we don't have    to bastardize configure to deal with this sillyness.  */
end_comment

begin_decl_stmt
name|namespace
name|std
block|{
ifndef|#
directive|ifndef
name|__LP64__
name|__extension__
specifier|extern
literal|"C"
name|long
name|long
name|strtoll
argument_list|(
argument|const char *
argument_list|,
argument|char **
argument_list|,
argument|int
argument_list|)
asm|__asm  ("__strtoll");
name|__extension__
specifier|extern
literal|"C"
name|unsigned
name|long
name|long
name|strtoull
argument_list|(
argument|const char *
argument_list|,
argument|char **
argument_list|,
argument|int
argument_list|)
asm|__asm  ("__strtoull");
else|#
directive|else
name|__extension__
specifier|extern
literal|"C"
name|long
name|long
name|strtoll
argument_list|(
argument|const char *
argument_list|,
argument|char **
argument_list|,
argument|int
argument_list|)
asm|__asm  ("strtol");
name|__extension__
specifier|extern
literal|"C"
name|unsigned
name|long
name|long
name|strtoull
argument_list|(
argument|const char *
argument_list|,
argument|char **
argument_list|,
argument|int
argument_list|)
asm|__asm  ("strtoul");
endif|#
directive|endif
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|_GLIBCPP_USE_LONG_LONG
value|1
end_define

begin_comment
comment|// HPUX on IA64 requires vtable to be 64 bit aligned even at 32 bit
end_comment

begin_comment
comment|// mode.  We need to pad the vtable structure to achieve this.
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LP64
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_VTABLE_PADDING
value|8
end_define

begin_typedef
typedef|typedef
name|long
name|int
name|__padding_type
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GCC on IA64 HP-UX uses the HP-UX system unwind library,
end_comment

begin_comment
comment|// it does not have the _Unwind_Resume_or_Rethrow entry point
end_comment

begin_comment
comment|// because that is not part of the standard IA64 Unwind ABI.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_LIBUNWIND_STD_ABI
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We need explicit instantiation of the atomicity lock on HPPA if    there is no weak support.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_GLIBCPP_SUPPORTS_WEAK
argument_list|)
operator|&&
name|defined
argument_list|(
name|__hppa__
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GLIBCPP_INST_ATOMICITY_LOCK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't use pragma weak in gthread headers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hppa__
end_ifdef

begin_define
define|#
directive|define
name|_GLIBCPP_GTHREAD_USE_WEAK
value|0
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

