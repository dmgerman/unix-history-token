begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-tic30.h -- Header file for tc-tic30.c    Copyright 1998, 2000 Free Software Foundation, Inc.    Contributed by Steven Haworth (steve@pm.cse.rmit.edu.au)     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_TIC30_H_
end_ifndef

begin_define
define|#
directive|define
name|_TC_TIC30_H_
end_define

begin_define
define|#
directive|define
name|TC_TIC30
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-tic30"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_tic30
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
name|WORKING_DOT_WORD
end_define

begin_decl_stmt
name|char
modifier|*
name|output_invalid
name|PARAMS
argument_list|(
operator|(
name|int
name|c
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|END_OF_INSN
value|'\0'
end_define

begin_define
define|#
directive|define
name|MAX_OPERANDS
value|6
end_define

begin_define
define|#
directive|define
name|DIRECT_REFERENCE
value|'@'
end_define

begin_define
define|#
directive|define
name|INDIRECT_REFERENCE
value|'*'
end_define

begin_define
define|#
directive|define
name|PARALLEL_SEPARATOR
value|'|'
end_define

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_comment
comment|/* Define this to 1 if you want the debug output to be on stdout,    otherwise stderr will be used.  If stderr is used, there will be a    better synchronisation with the as_bad outputs, but you can't    capture the output.  */
end_comment

begin_define
define|#
directive|define
name|USE_STDOUT
value|0
end_define

begin_define
define|#
directive|define
name|tc_unrecognized_line
value|tic30_unrecognized_line
end_define

begin_decl_stmt
specifier|extern
name|int
name|tic30_unrecognized_line
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

