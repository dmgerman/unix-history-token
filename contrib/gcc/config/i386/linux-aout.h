begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Linux    Copyright (C) 1992, 1994, 1995 Free Software Foundation, Inc.    Contributed by H.J. Lu (hjl@nynexst.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is tested by i386/gas.h.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_include
include|#
directive|include
file|<i386/gstabs.h>
end_include

begin_include
include|#
directive|include
file|<linux-aout.h>
end_include

begin_comment
comment|/* some common stuff */
end_comment

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -Di386 -Dlinux -Asystem(unix) -Asystem(posix) -Acpu(i386) -Amachine(i386)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_if
if|#
directive|if
name|TARGET_CPU_DEFAULT
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{!m386:-D__i486__} %{posix:-D_POSIX_SOURCE}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{m486:-D__i486__} %{posix:-D_POSIX_SOURCE}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler,    and we want to retain compatibility with older gcc versions.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* We no longer link with libc_p.a or libg.a by default. If you  * want to profile or debug the Linux C library, please add  * -lc_p or -ggdb to LDFLAGS at the link time, respectively.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{mieee-fp:-lieee} %{p:-lgmon} %{pg:-lgmon} %{!ggdb:-lc} %{ggdb:-lg}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{mieee-fp:-lieee} %{p:-lgmon -lc_p} %{pg:-lgmon -lc_p} \  %{!p:%{!pg:%{!g*:-lc} %{g*:-lg -static}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m i386linux"
end_define

begin_comment
comment|/* Get perform_* macros to build libgcc.a.  */
end_comment

begin_include
include|#
directive|include
file|"i386/perform.h"
end_include

end_unit

