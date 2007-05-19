begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration file for Symbian OS on ARM processors.    Copyright (C) 2004, 2005    Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Do not expand builtin functions (unless explicitly prefixed with    "__builtin").  Symbian OS code relies on properties of the standard    library that go beyond those guaranteed by the ANSI/ISO standard.    For example, "memcpy" works even with overlapping memory, like    "memmove".  We cannot simply set flag_no_builtin in arm.c because    (a) flag_no_builtin is not declared in language-independent code,    and (b) that would prevent users from explicitly overriding the    default with -fbuiltin, which may sometimes be useful.     Make all symbols hidden by default.  Symbian OS expects that all    exported symbols will be explicitly marked with    "__declspec(dllexport)".       Enumeration types use 4 bytes, even if the enumerals are small,    unless explicitly overridden.     The wchar_t type is a 2-byte type, unless explicitly    overridden.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
define|\
value|"%{!fbuiltin:%{!fno-builtin:-fno-builtin}} "			\   "%{!fvisibility=*:-fvisibility=hidden} "			\   "%{!fshort-enums:%{!fno-short-enums:-fno-short-enums}} "	\   "%{!fshort-wchar:%{!fno-short-wchar:-fshort-wchar}} "
end_define

begin_define
define|#
directive|define
name|CC1PLUS_SPEC
value|CC1_SPEC
end_define

begin_comment
comment|/* Symbian OS does not use crt*.o, unlike the generic unknown-elf    configuration.  */
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
value|""
end_define

begin_comment
comment|/* Do not link with any libraries by default.  On Symbian OS, the user    must supply all required libraries on the command line.  */
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
value|""
end_define

begin_comment
comment|/* Support the "dllimport" attribute.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
value|1
end_define

begin_comment
comment|/* Symbian OS assumes ARM V5 or above.  Since -march=armv5 is    equivalent to making the ARM 10TDMI core the default, we can set    SUBTARGET_CPU_DEFAULT and get an equivalent effect.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_arm10tdmi
end_define

begin_comment
comment|/* The assembler should assume VFP FPU format, and armv5t.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_FLOAT_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_FLOAT_SPEC
define|\
value|"%{!mfpu=*:-mfpu=vfp} %{!mcpu=*:%{!march=*:-march=armv5t}}"
end_define

begin_comment
comment|/* SymbianOS provides the BPABI routines in a separate library.    Therefore, we do not need to define any of them in libgcc.  */
end_comment

begin_undef
undef|#
directive|undef
name|RENAME_LIBRARY
end_undef

begin_define
define|#
directive|define
name|RENAME_LIBRARY
parameter_list|(
name|GCC_NAME
parameter_list|,
name|AEABI_NAME
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_comment
comment|/* Define the __symbian__ macro.  */
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
value|do						\     {						\
comment|/* Include the default BPABI stuff.  */
value|\       TARGET_BPABI_CPP_BUILTINS ();		\       builtin_define ("__symbian__");		\     }						\   while (false)
end_define

begin_comment
comment|/* On SymbianOS, these sections are not writable, so we use "a",    rather than "aw", for the section attributes.  */
end_comment

begin_undef
undef|#
directive|undef
name|ARM_EABI_CTORS_SECTION_OP
end_undef

begin_define
define|#
directive|define
name|ARM_EABI_CTORS_SECTION_OP
define|\
value|"\t.section\t.init_array,\"a\",%init_array"
end_define

begin_undef
undef|#
directive|undef
name|ARM_EABI_DTORS_SECTION_OP
end_undef

begin_define
define|#
directive|define
name|ARM_EABI_DTORS_SECTION_OP
define|\
value|"\t.section\t.fini_array,\"a\",%fini_array"
end_define

begin_comment
comment|/* SymbianOS cannot merge entities with vague linkage at runtime.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARM_DYNAMIC_VAGUE_LINKAGE_P
value|false
end_define

end_unit

