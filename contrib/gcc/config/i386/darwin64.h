begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for x86_64 running Darwin.    Copyright (C) 2006 Free Software Foundation, Inc.    Contributed by Apple Computer Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (x86_64 Darwin)");
end_define

begin_undef
undef|#
directive|undef
name|DARWIN_ARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|DARWIN_ARCH_SPEC
value|"%{m32:i386;:x86_64}"
end_define

begin_undef
undef|#
directive|undef
name|DARWIN_SUBARCH_SPEC
end_undef

begin_define
define|#
directive|define
name|DARWIN_SUBARCH_SPEC
value|DARWIN_ARCH_SPEC
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "darwin_arch", DARWIN_ARCH_SPEC },                          \   { "darwin_crt2", "" },                                        \   { "darwin_subarch", DARWIN_SUBARCH_SPEC },
end_define

end_unit

