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

begin_decl_stmt
name|int
name|itbl_parse
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|insntbl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|itbl_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|itbl_get_field
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|itbl_assemble
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|operands
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|itbl_disassemble
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|unsigned
name|long
name|insn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|itbl_parse
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|tbl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* parses insn tbl */
end_comment

begin_decl_stmt
name|int
name|itbl_get_reg_val
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|unsigned
name|long
operator|*
name|pval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|itbl_get_val
name|PARAMS
argument_list|(
operator|(
name|e_processor
name|processor
operator|,
name|e_type
name|type
operator|,
name|char
operator|*
name|name
operator|,
name|unsigned
name|long
operator|*
name|pval
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|itbl_get_name
name|PARAMS
argument_list|(
operator|(
name|e_processor
name|processor
operator|,
name|e_type
name|type
operator|,
name|unsigned
name|long
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These routines are called by the table parser used to build the    dynamic list of new processor instructions and registers.  */
end_comment

begin_decl_stmt
name|struct
name|itbl_entry
modifier|*
name|itbl_add_reg
name|PARAMS
argument_list|(
operator|(
name|int
name|yyproc
operator|,
name|int
name|yytype
operator|,
name|char
operator|*
name|regname
operator|,
name|int
name|regnum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|itbl_entry
modifier|*
name|itbl_add_insn
name|PARAMS
argument_list|(
operator|(
name|int
name|yyproc
operator|,
name|char
operator|*
name|name
operator|,
name|unsigned
name|long
name|value
operator|,
name|int
name|sbit
operator|,
name|int
name|ebit
operator|,
name|unsigned
name|long
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|itbl_field
modifier|*
name|itbl_add_operand
name|PARAMS
argument_list|(
operator|(
expr|struct
name|itbl_entry
operator|*
name|e
operator|,
name|int
name|yytype
operator|,
name|int
name|sbit
operator|,
name|int
name|ebit
operator|,
name|unsigned
name|long
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

