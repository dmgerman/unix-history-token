begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Multiple object format emulation.    Copyright 1995, 1996, 1997, 1999, 2000    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OBJ_MULTI_H
end_ifndef

begin_define
define|#
directive|define
name|_OBJ_MULTI_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_HEADER
end_ifdef

begin_include
include|#
directive|include
include|OBJ_HEADER
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"emul.h"
end_include

begin_include
include|#
directive|include
file|"targ-cpu.h"
end_include

begin_define
define|#
directive|define
name|OUTPUT_FLAVOR
define|\
value|(this_format->flavor)
end_define

begin_define
define|#
directive|define
name|obj_begin
parameter_list|()
define|\
value|(this_format->begin				\ 	 ? (*this_format->begin) ()			\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_app_file
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(this_format->app_file				\ 	 ? (*this_format->app_file) (NAME)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|S
parameter_list|,
name|P
parameter_list|)
define|\
value|(*this_format->frob_symbol) (S,&(P))
end_define

begin_define
define|#
directive|define
name|obj_frob_file
parameter_list|()
define|\
value|(this_format->frob_file				\ 	 ? (*this_format->frob_file) ()			\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_frob_file_before_adjust
parameter_list|()
define|\
value|(this_format->frob_file_before_adjust		\ 	 ? (*this_format->frob_file_before_adjust) ()	\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_frob_file_after_relocs
parameter_list|()
define|\
value|(this_format->frob_file_after_relocs		\ 	 ? (*this_format->frob_file_after_relocs) ()	\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_ecoff_set_ext
define|\
value|(*this_format->ecoff_set_ext)
end_define

begin_define
define|#
directive|define
name|obj_pop_insert
define|\
value|(*this_format->pop_insert)
end_define

begin_define
define|#
directive|define
name|obj_read_begin_hook
parameter_list|()
define|\
value|(this_format->read_begin_hook			\ 	 ? (*this_format->read_begin_hook) ()		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_symbol_new_hook
parameter_list|(
name|S
parameter_list|)
define|\
value|(this_format->symbol_new_hook			\ 	 ? (*this_format->symbol_new_hook) (S)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|obj_sec_sym_ok_for_reloc
parameter_list|(
name|A
parameter_list|)
define|\
value|(this_format->sec_sym_ok_for_reloc		\ 	 ? (*this_format->sec_sym_ok_for_reloc) (A)	\ 	 : 0)
end_define

begin_define
define|#
directive|define
name|S_GET_SIZE
define|\
value|(*this_format->s_get_size)
end_define

begin_define
define|#
directive|define
name|S_SET_SIZE
parameter_list|(
name|S
parameter_list|,
name|N
parameter_list|)
define|\
value|(this_format->s_set_size			\ 	 ? (*this_format->s_set_size) (S, N)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|S_GET_ALIGN
define|\
value|(*this_format->s_get_align)
end_define

begin_define
define|#
directive|define
name|S_SET_ALIGN
parameter_list|(
name|S
parameter_list|,
name|N
parameter_list|)
define|\
value|(this_format->s_set_align			\ 	 ? (*this_format->s_set_align) (S, N)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|S_GET_OTHER
define|\
value|(*this_format->s_get_other)
end_define

begin_define
define|#
directive|define
name|S_SET_OTHER
parameter_list|(
name|S
parameter_list|,
name|O
parameter_list|)
define|\
value|(this_format->s_set_other			\ 	 ? (*this_format->s_set_other) (S, O)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|S_GET_DESC
define|\
value|(*this_format->s_get_desc)
end_define

begin_define
define|#
directive|define
name|S_SET_DESC
parameter_list|(
name|S
parameter_list|,
name|D
parameter_list|)
define|\
value|(this_format->s_set_desc			\ 	 ? (*this_format->s_set_desc) (S, D)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|S_GET_TYPE
define|\
value|(*this_format->s_get_desc)
end_define

begin_define
define|#
directive|define
name|S_SET_TYPE
parameter_list|(
name|S
parameter_list|,
name|T
parameter_list|)
define|\
value|(this_format->s_set_type			\ 	 ? (*this_format->s_set_type) (S, T)		\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|OBJ_COPY_SYMBOL_ATTRIBUTES
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
define|\
value|(this_format->copy_symbol_attributes		\ 	 ? (*this_format->copy_symbol_attributes) (d, s) \ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|OBJ_PROCESS_STAB
parameter_list|(
name|SEG
parameter_list|,
name|W
parameter_list|,
name|S
parameter_list|,
name|T
parameter_list|,
name|O
parameter_list|,
name|D
parameter_list|)
define|\
value|(this_format->process_stab			\ 	 ? (*this_format->process_stab) (SEG,W,S,T,O,D)	\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|SEPARATE_STAB_SECTIONS
define|\
value|((*this_format->separate_stab_sections) ())
end_define

begin_define
define|#
directive|define
name|INIT_STAB_SECTION
parameter_list|(
name|S
parameter_list|)
define|\
value|(this_format->init_stab_section			\ 	 ? (*this_format->init_stab_section) (S)	\ 	 : (void) 0)
end_define

begin_define
define|#
directive|define
name|EMIT_SECTION_SYMBOLS
value|(this_format->emit_section_symbols)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_ELF
end_ifdef

begin_comment
comment|/* We need OBJ_SYMFIELD_TYPE so that symbol_get_obj is defined in symbol.c    We also need various STAB defines for stab.c  */
end_comment

begin_include
include|#
directive|include
file|"obj-elf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_MAYBE_AOUT
end_ifdef

begin_comment
comment|/* We want aout_process_stab in stabs.c for the aout table.  Defining this    macro will have no other effect.  */
end_comment

begin_define
define|#
directive|define
name|AOUT_STABS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !OBJ_HEADER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OBJ_MULTI_H */
end_comment

end_unit

