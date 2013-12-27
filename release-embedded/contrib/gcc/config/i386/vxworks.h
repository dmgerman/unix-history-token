begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IA32 VxWorks target definitions for GNU compiler.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Updated by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (80586, VxWorks syntax)");
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v:-v} %{Qy:} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"
end_define

begin_define
define|#
directive|define
name|VXWORKS_CPU_DEFINE
parameter_list|()
define|\
value|do							\     {							\       if (TARGET_386)					\         builtin_define ("CPU=I80386");			\       else if (TARGET_486)				\         builtin_define ("CPU=I80486");			\       else if (TARGET_PENTIUM)				\         {						\           builtin_define ("CPU=PENTIUM");		\           builtin_define ("CPU_VARIANT=PENTIUM");	\         }						\       else if (TARGET_PENTIUMPRO)			\         {						\           builtin_define ("CPU=PENTIUM2");		\           builtin_define ("CPU_VARIANT=PENTIUMPRO");	\         }						\       else if (TARGET_PENTIUM4)				\         {						\           builtin_define ("CPU=PENTIUM4");		\           builtin_define ("CPU_VARIANT=PENTIUM4");	\         }						\     }  							\   while (0)
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("__vxworks");		\       builtin_define ("__VXWORKS__");		\       builtin_assert ("system=unix");		\ 						\       VXWORKS_CPU_DEFINE();			\     }						\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|VXWORKS_ADDITIONAL_CPP_SPEC
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|VXWORKS_LIB_SPEC
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|VXWORKS_STARTFILE_SPEC
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|VXWORKS_ENDFILE_SPEC
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|VXWORKS_LINK_SPEC
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
value|EXTRA_SUBTARGET_SWITCHES
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
value|VXWORKS_OVERRIDE_OPTIONS
end_define

begin_comment
comment|/* No _mcount profiling on VxWorks.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
value|VXWORKS_FUNCTION_PROFILER(FILE,LABELNO)
end_define

end_unit

