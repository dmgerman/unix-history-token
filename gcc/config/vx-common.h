begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-independent configuration for VxWorks and VxWorks AE.       Copyright (C) 2005 Free Software Foundation, Inc.    Contributed by by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* VxWorks headers are C++-aware.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Most of these will probably be overridden by subsequent headers.  We    undefine them here just in case, and define VXWORKS_ versions of each,    to be used in port-specific vxworks.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|VXWORKS_LIBGCC_SPEC
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_comment
comment|/* Most of these macros are overridden in "config/vxworks.h" or    "config/vxworksae.h" and are here merely for documentation    purposes.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_ADDITIONAL_CPP_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_LIB_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_LINK_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_LIBGCC_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_STARTFILE_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_ENDFILE_SPEC
value|""
end_define

begin_comment
comment|/* VxWorks cannot have dots in constructor labels, because it uses a    mutant variation of collect2 that generates C code instead of    assembly.  Thus each constructor label must be a legitimate C    symbol.  FIXME: Have VxWorks use real collect2 instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_define
define|#
directive|define
name|NO_DOT_IN_LABEL
end_define

begin_comment
comment|/* VxWorks uses wchar_t == unsigned short (UCS2) on all architectures.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
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
value|16
end_define

begin_comment
comment|/* Dwarf2 unwind info is not supported.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* VxWorks uses DWARF2.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_comment
comment|/* None of these other formats is supported.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|XCOFF_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|VMS_DEBUGGING_INFO
end_undef

begin_comment
comment|/* Kernel mode doesn't have ctors/dtors, but RTP mode does.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAVE_CTORS_DTORS
value|false
end_define

begin_define
define|#
directive|define
name|VXWORKS_OVERRIDE_OPTIONS
end_define

begin_comment
comment|/* empty */
end_comment

begin_comment
comment|/* No math library needed.  */
end_comment

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_comment
comment|/* No profiling.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
value|do	\ {							\   sorry ("profiler support for VxWorks");		\ } while (0)
end_define

begin_comment
comment|/* We occasionally need to distinguish between the VxWorks variants.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_KIND_NORMAL
value|1
end_define

begin_define
define|#
directive|define
name|VXWORKS_KIND_AE
value|2
end_define

end_unit

