begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    For ARM with COFF object format.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by Doug Evans (devans@cygnus.com).        This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Note - it is important that this definition matches the one in tcoff.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_escape
end_escape

begin_comment
comment|/* Run-time Target Specification.  */
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
value|fputs (" (ARM/coff)", stderr)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT_FLOAT_ABI
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_FLOAT_ABI
value|ARM_FLOAT_ABI_SOFT
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APCS_FRAME)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_DEFAULTS
end_ifndef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
define|\
value|{ "marm", "mlittle-endian", "msoft-float", "mno-thumb-interwork" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* This is COFF, but prefer stabs.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_APP_OFF
value|true
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_coff_asm_named_section
end_define

begin_escape
end_escape

begin_comment
comment|/* Support the ctors/dtors and other sections.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_comment
comment|/* Define this macro if jump tables (for `tablejump' insns) should be    output in the text section, along with the assembler instructions.    Otherwise, the readonly data section is used.  */
end_comment

begin_comment
comment|/* We put ARM jump tables in the text section, because it makes the code    more efficient, but for Thumb it's better to put them out of band.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|(TARGET_ARM)
end_define

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.section .rdata"
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section .ctors,\"x\""
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section .dtors,\"x\""
end_define

begin_escape
end_escape

begin_comment
comment|/* Support the ctors/dtors sections for g++.  */
end_comment

begin_comment
comment|/* __CTOR_LIST__ and __DTOR_LIST__ must be defined by the linker script.  */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
end_define

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_CTORS_BODY
end_undef

begin_undef
undef|#
directive|undef
name|DO_GLOBAL_DTORS_BODY
end_undef

begin_comment
comment|/* The ARM development system defines __main.  */
end_comment

begin_define
define|#
directive|define
name|NAME__MAIN
value|"__gccmain"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|__gccmain
end_define

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|0
end_define

end_unit

