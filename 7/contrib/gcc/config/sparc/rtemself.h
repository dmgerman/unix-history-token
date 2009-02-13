begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for rtems targeting a SPARC using ELF.    Copyright (C) 1996, 1997, 2000, 2002, 2005 Free Software Foundation, Inc.    Contributed by Joel Sherrill (joel@OARcorp.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define ("__rtems__");		\ 	builtin_define ("__USE_INIT_FINI__");	\ 	builtin_assert ("system=rtems");	\     }						\   while (0)
end_define

begin_comment
comment|/* Use the default */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_GCC_C_SEQUENCE_SPEC
end_undef

end_unit

