begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GCC.  VxWorks i586 version.    Copyright (C) 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Prefix for internally generated assembler labels.  If we aren't using    underscores, we are using prefix `.'s to identify labels that should    be ignored, as in `i386/gas.h' --karl@cs.umb.edu  */
end_comment

begin_define
define|#
directive|define
name|LPREFIX
value|"L"
end_define

begin_comment
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SHORT
value|"\t.word\t"
end_define

begin_define
define|#
directive|define
name|ASM_LONG
value|"\t.long\t"
end_define

begin_define
define|#
directive|define
name|ASM_QUAD
value|"\t.quad\t"
end_define

begin_comment
comment|/* Should not be used for 32bit compilation.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.balign %d\n", 1<<(LOG))
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
value|"%{v:-V} %{Qy:} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                                    \     {                                                   \       builtin_define ("__vxworks");                     \       builtin_assert ("system=unix");                   \                                                         \       if (TARGET_386)                                   \         builtin_define ("CPU=I80386");                  \       else if (TARGET_486)                              \         builtin_define ("CPU=I80486");                  \       else if (TARGET_PENTIUM)                          \         {                                               \           builtin_define ("CPU=PENTIUM");               \           builtin_define ("CPU_VARIANT=PENTIUM");       \         }                                               \       else if (TARGET_PENTIUMPRO)                       \         {                                               \           builtin_define ("CPU=PENTIUM2");               \           builtin_define ("CPU_VARIANT=PENTIUMPRO");    \         }                                               \       else if (TARGET_PENTIUM4)                       \         {                                               \           builtin_define ("CPU=PENTIUM4");               \           builtin_define ("CPU_VARIANT=PENTIUM4");    \         }                                               \     }                                                   \   while (0)
end_define

end_unit

