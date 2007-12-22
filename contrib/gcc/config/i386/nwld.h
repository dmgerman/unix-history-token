begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nwld.h -- defines to be used when targeting GCC for some generic NetWare    system while using the Novell linker.    Copyright (C) 2004 Free Software Foundation, Inc.     Written by Jan Beulich (jbeulich@novell.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lc --def-file libc.def%s"
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"-lgcc %{!static-libgcc:--def-file libgcc.def%s}"
end_define

begin_undef
undef|#
directive|undef
name|LINKER_NAME
end_undef

begin_define
define|#
directive|define
name|LINKER_NAME
value|"nwld"
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
value|"--format:NLM --extensions:GNU" \ 	" %{static:%{!nostdlib:%{!nodefaultlib:%eStatic linking is not supported.\n}}}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_GCC_C_SEQUENCE_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_GCC_C_SEQUENCE_SPEC
value|"%L %G"
end_define

begin_comment
comment|/* In order to permit the linker to derive the output filename from the first    input file, put the common startup code as the last object. */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|""
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
value|"crt0%O%s ../imports/%{!posix:libc}%{posix:posix}pre.gcc%O%s" \ 	" --def-file %{!posix:libc}%{posix:posix}pre.def%s"
end_define

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
value|"%{!static-libgcc:-shared-libgcc}"
end_define

begin_define
define|#
directive|define
name|TARGET_SUB_SECTION_SEPARATOR
value|"$"
end_define

begin_function_decl
name|void
name|nwld_named_section_asm_out_constructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nwld_named_section_asm_out_destructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|nwld_named_section_asm_out_constructor
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_DESTRUCTOR
value|nwld_named_section_asm_out_destructor
end_define

begin_undef
undef|#
directive|undef
name|EH_FRAME_SECTION_NAME
end_undef

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_NAME
value|".eh_frame"TARGET_SUB_SECTION_SEPARATOR
end_define

begin_comment
comment|/* nwld does not currently support stabs debug info */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

end_unit

