begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* itbl-ops.h    Copyright 1997, 1999, 2000 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* External functions, constants and defines for itbl support */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_comment
comment|/* Include file notes: "expr.h" needed before targ-*.h,  * "targ-env.h" includes the chain of target dependant headers,  * "targ-cpu.h" has the HAVE_ITBL_CPU define, and  * as.h includes them all */
end_comment

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ITBL_CPU
end_ifdef

begin_include
include|#
directive|include
file|"itbl-cpu.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defaults for definitions required by generic code */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_NUMBER_OF_PROCESSORS
end_ifndef

begin_define
define|#
directive|define
name|ITBL_NUMBER_OF_PROCESSORS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_MAX_BITPOS
end_ifndef

begin_define
define|#
directive|define
name|ITBL_MAX_BITPOS
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_TYPE
end_ifndef

begin_define
define|#
directive|define
name|ITBL_TYPE
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_IS_INSN
end_ifndef

begin_define
define|#
directive|define
name|ITBL_IS_INSN
parameter_list|(
name|insn
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_DECODE_PNUM
end_ifndef

begin_define
define|#
directive|define
name|ITBL_DECODE_PNUM
parameter_list|(
name|insn
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ITBL_ENCODE_PNUM
end_ifndef

begin_define
define|#
directive|define
name|ITBL_ENCODE_PNUM
parameter_list|(
name|pnum
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|ITBL_TYPE
name|t_insn
typedef|;
end_typedef

begin_comment
comment|/* types of entries */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_insn
block|,
name|e_dreg
block|,
name|e_regtype0
init|=
name|e_dreg
block|,
name|e_creg
block|,
name|e_greg
block|,
name|e_addr
block|,
name|e_nregtypes
init|=
name|e_greg
operator|+
literal|1
block|,
name|e_immed
block|,
name|e_ntypes
block|,
name|e_invtype
comment|/* invalid type */
block|}
name|e_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|e_p0
block|,
name|e_nprocs
init|=
name|NUMBER_OF_PROCESSORS
block|,
name|e_invproc
comment|/* invalid processor */
block|}
name|e_processor
typedef|;
end_typedef

begin_comment
comment|/* 0 means an instruction table was not specified.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|itbl_have_entries
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These routines are visible to the main part of the assembler */
end_comment

begin_function_decl
name|int
name|itbl_parse
parameter_list|(
name|char
modifier|*
name|insntbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|itbl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|itbl_get_field
parameter_list|(
name|char
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|itbl_assemble
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|operands
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|itbl_disassemble
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|unsigned
name|long
name|insn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|itbl_parse
parameter_list|(
name|char
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* parses insn tbl */
end_comment

begin_function_decl
name|int
name|itbl_get_reg_val
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
modifier|*
name|pval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|itbl_get_val
parameter_list|(
name|e_processor
name|processor
parameter_list|,
name|e_type
name|type
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
modifier|*
name|pval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|itbl_get_name
parameter_list|(
name|e_processor
name|processor
parameter_list|,
name|e_type
name|type
parameter_list|,
name|unsigned
name|long
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These routines are called by the table parser used to build the    dynamic list of new processor instructions and registers.  */
end_comment

begin_function_decl
name|struct
name|itbl_entry
modifier|*
name|itbl_add_reg
parameter_list|(
name|int
name|yyproc
parameter_list|,
name|int
name|yytype
parameter_list|,
name|char
modifier|*
name|regname
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|itbl_entry
modifier|*
name|itbl_add_insn
parameter_list|(
name|int
name|yyproc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
name|value
parameter_list|,
name|int
name|sbit
parameter_list|,
name|int
name|ebit
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|itbl_field
modifier|*
name|itbl_add_operand
parameter_list|(
name|struct
name|itbl_entry
modifier|*
name|e
parameter_list|,
name|int
name|yytype
parameter_list|,
name|int
name|sbit
parameter_list|,
name|int
name|ebit
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
end_function_decl

end_unit

