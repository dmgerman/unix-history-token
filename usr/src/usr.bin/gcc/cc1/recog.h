begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for interface to insn recognizer and insn-output.c.    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Recognize an insn and return its insn-code,    which is the sequence number of the DEFINE_INSN that it matches.    If the insn does not match, return -1.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|recog_memoized
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Extract the operands from an insn that has been recognized.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|insn_extract
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The following vectors hold the results from insn_extract.  */
end_comment

begin_comment
comment|/* Indexed by N, gives value of operand N.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|recog_operand
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives location where operand N was found.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|recog_operand_loc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives location where the Nth duplicate-appearance of    an operand was found.  This is something that matched MATCH_DUP.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|recog_dup_loc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by N, gives the operand number that was duplicated in the    Nth duplicate-appearance of an operand.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|recog_dup_num
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tables defined in insn-output.c that give information about    each insn-code value.  */
end_comment

begin_comment
comment|/* These are vectors indexed by insn-code.  Details in genoutput.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|insn_template
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
function_decl|(
modifier|*
name|insn_outfun
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|insn_n_operands
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insn_n_dups
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|INSN_MACHINE_INFO
end_ifdef

begin_decl_stmt
specifier|extern
name|INSN_MACHINE_INFO
name|insn_machine_info
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indexed by insn code number, gives # of constraint alternatives.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|insn_n_alternatives
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These are two-dimensional arrays indexed first by the insn-code    and second by the operand number.  Details in genoutput.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|insn_operand_constraint
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|insn_operand_address_p
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|insn_operand_mode
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|insn_operand_strict_low
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|insn_operand_predicate
index|[]
index|[
name|MAX_RECOG_OPERANDS
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

end_unit

