begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ecoff.h -- header file for ECOFF debugging support    Copyright (C) 1993, 94, 95, 1996 Free Software Foundation, Inc.    Contributed by Cygnus Support.    Put together by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ECOFF_DEBUGGING
end_ifdef

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

begin_decl_stmt
specifier|extern
name|void
name|ecoff_read_begin_hook
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function should be called when the assembler switches to a new    file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_new_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function should be called when a new symbol is created, by    obj_symbol_new_hook.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_symbol_new_hook
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function should be called by the obj_frob_symbol hook.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_frob_symbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Build the ECOFF debugging information.  This should be called by    obj_frob_file.  This fills in the counts in *HDR; the offsets are    filled in relative to the start of the *BUFP.  It sets *BUFP to a    block of memory holding the debugging information.  It returns the    length of *BUFP.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|ecoff_build_debug
name|PARAMS
argument_list|(
operator|(
name|HDRR
operator|*
name|hdr
operator|,
name|char
operator|*
operator|*
name|bufp
operator|,
specifier|const
expr|struct
name|ecoff_debug_swap
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions to handle the ECOFF debugging directives.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_begin
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_bend
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_end
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_ent
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_fmask
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_frame
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_loc
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_mask
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Other ECOFF directives.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_extern
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_weakext
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions to handle the COFF debugging directives.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_def
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_dim
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_endef
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_file
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_scl
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_size
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_tag
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_type
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ecoff_directive_val
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle stabs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_stab
name|PARAMS
argument_list|(
operator|(
name|segT
name|sec
operator|,
name|int
name|what
operator|,
specifier|const
name|char
operator|*
name|string
operator|,
name|int
name|type
operator|,
name|int
name|other
operator|,
name|int
name|desc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the GP prologue size.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_set_gp_prolog_size
name|PARAMS
argument_list|(
operator|(
name|int
name|sz
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is called from the ECOFF code to set the external    information for a symbol.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|obj_ecoff_set_ext
end_ifndef

begin_decl_stmt
specifier|extern
name|void
name|obj_ecoff_set_ext
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
name|EXTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This routine is used to patch up a line number directive when    instructions are moved around.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_fix_loc
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is called from read.c to peek at cur_file_ptr.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ecoff_no_current_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is called from read.c to generate line number for .s    file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_generate_asm_lineno
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This routine is called from read.c to generate line number stabs    for .s file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|ecoff_generate_asm_line_stab
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GAS_ECOFF_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECOFF_DEBUGGING */
end_comment

end_unit

