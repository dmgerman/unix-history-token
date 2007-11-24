begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ecoff.h -- header file for ECOFF debugging support    Copyright 1993, 1994, 1995, 1996, 1997, 1998    Free Software Foundation, Inc.    Contributed by Cygnus Support.    Put together by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAS_ECOFF_H
end_ifndef

begin_define
define|#
directive|define
name|GAS_ECOFF_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ECOFF_DEBUGGING
end_ifdef

begin_include
include|#
directive|include
file|"coff/sym.h"
end_include

begin_include
include|#
directive|include
file|"coff/ecoff.h"
end_include

begin_comment
comment|/* Whether we have seen any ECOFF debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ecoff_debugging_seen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function should be called at the start of assembly, by    obj_read_begin_hook.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_read_begin_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function should be called when the assembler switches to a new    file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_new_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function should be called when a new symbol is created, by    obj_symbol_new_hook.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_symbol_new_hook
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function should be called by the obj_frob_symbol hook.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_frob_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Build the ECOFF debugging information.  This should be called by    obj_frob_file.  This fills in the counts in *HDR; the offsets are    filled in relative to the start of the *BUFP.  It sets *BUFP to a    block of memory holding the debugging information.  It returns the    length of *BUFP.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|ecoff_build_debug
parameter_list|(
name|HDRR
modifier|*
name|hdr
parameter_list|,
name|char
modifier|*
modifier|*
name|bufp
parameter_list|,
specifier|const
name|struct
name|ecoff_debug_swap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to handle the ECOFF debugging directives.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_begin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_bend
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_end
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_ent
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_fmask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_frame
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_loc
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_mask
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Other ECOFF directives.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_extern
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_weakext
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to handle the COFF debugging directives.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_def
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_dim
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_endef
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_file
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_scl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_tag
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ecoff_directive_val
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Handle stabs.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_stab
parameter_list|(
name|segT
name|sec
parameter_list|,
name|int
name|what
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|other
parameter_list|,
name|int
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the GP prologue size.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_set_gp_prolog_size
parameter_list|(
name|int
name|sz
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This routine is called from the ECOFF code to set the external    information for a symbol.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|obj_ecoff_set_ext
end_ifndef

begin_function_decl
specifier|extern
name|void
name|obj_ecoff_set_ext
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|EXTR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This routine is used to patch up a line number directive when    instructions are moved around.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_fix_loc
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function is called from read.c to peek at cur_file_ptr.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ecoff_no_current_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function returns the symbol associated with the current proc.  */
end_comment

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|ecoff_get_cur_proc_sym
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECOFF_DEBUGGING */
end_comment

begin_comment
comment|/* This routine is called from read.c to generate line number for .s file.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ecoff_generate_asm_lineno
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GAS_ECOFF_H */
end_comment

end_unit

