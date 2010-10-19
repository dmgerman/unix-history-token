begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-or32.h -- Assemble for the OpenRISC 1000.    Copyright (C) 2002, 2003. 2005 Free Software Foundation, Inc.    Contributed by Damjan Lampret<lampret@opencores.org>.    Based upon a29k port.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street - Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_OR32
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|LEX_DOLLAR
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-or32"
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_or32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"coff-or32-big"
end_define

begin_define
define|#
directive|define
name|reloc_type
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|tc_unrecognized_line
parameter_list|(
name|c
parameter_list|)
value|or32_unrecognized_line (c)
end_define

begin_function_decl
specifier|extern
name|int
name|or32_unrecognized_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* Not used.  */
end_comment

begin_define
define|#
directive|define
name|COFF_MAGIC
value|SIPFBOMAGIC
end_define

begin_comment
comment|/* No shared lib support, so we don't need to ensure externally    visible symbols can be overridden.  */
end_comment

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* Values passed to md_apply_fix don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ZERO_BASED_SEGMENTS
end_define

end_unit

