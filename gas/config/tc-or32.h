begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-or32.h -- Assemble for the OpenRISC 1000.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Damjan Lampret<lampret@opencores.org>.    Based upon a29k port.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|int
name|or32_unrecognized_line
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

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
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|80
end_define

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fix_ptr
parameter_list|)
value|tc_coff_fix2rtype (fix_ptr)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_or32
end_define

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
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
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

begin_comment
comment|/* Should the reloc be output ?    on the 29k, this is true only if there is a symbol attached.    on the h8, this is always true, since no fixup is done.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|x
parameter_list|)
value|(x->fx_addsy)
end_define

begin_define
define|#
directive|define
name|TC_CONS_RELOC
value|RELOC_32
end_define

begin_define
define|#
directive|define
name|COFF_FLAGS
value|F_AR32W
end_define

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_define
define|#
directive|define
name|ZERO_BASED_SEGMENTS
end_define

end_unit

