begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* expr.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       expr.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_EXPR_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_EXPR_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFEEXPR_contextLET
block|,
name|FFEEXPR_contextASSIGN
block|,
name|FFEEXPR_contextIOLIST
block|,
name|FFEEXPR_contextPARAMETER
block|,
name|FFEEXPR_contextSUBROUTINEREF
block|,
name|FFEEXPR_contextDATA
block|,
name|FFEEXPR_contextIF
block|,
name|FFEEXPR_contextARITHIF
block|,
name|FFEEXPR_contextDO
block|,
name|FFEEXPR_contextDOWHILE
block|,
name|FFEEXPR_contextFORMAT
block|,
name|FFEEXPR_contextAGOTO
block|,
name|FFEEXPR_contextCGOTO
block|,
name|FFEEXPR_contextCHARACTERSIZE
block|,
name|FFEEXPR_contextEQUIVALENCE
block|,
name|FFEEXPR_contextSTOP
block|,
name|FFEEXPR_contextRETURN
block|,
name|FFEEXPR_contextSFUNCDEF
block|,
name|FFEEXPR_contextINCLUDE
block|,
name|FFEEXPR_contextWHERE
block|,
name|FFEEXPR_contextSELECTCASE
block|,
name|FFEEXPR_contextCASE
block|,
name|FFEEXPR_contextDIMLIST
block|,
name|FFEEXPR_contextDIMLISTCOMMON
block|,
comment|/* Dim list in COMMON stmt. */
name|FFEEXPR_contextFILEASSOC
block|,
comment|/* ASSOCIATEVARIABLE=. */
name|FFEEXPR_contextFILEINT
block|,
comment|/* IOSTAT=. */
name|FFEEXPR_contextFILEDFINT
block|,
comment|/* NEXTREC=. */
name|FFEEXPR_contextFILELOG
block|,
comment|/* NAMED=. */
name|FFEEXPR_contextFILENUM
block|,
comment|/* Numerical expression. */
name|FFEEXPR_contextFILECHAR
block|,
comment|/* Character expression. */
name|FFEEXPR_contextFILENUMCHAR
block|,
comment|/* READ KEYxyz=. */
name|FFEEXPR_contextFILEDFCHAR
block|,
comment|/* Default kind character expression. */
name|FFEEXPR_contextFILEKEY
block|,
comment|/* OPEN KEY=. */
name|FFEEXPR_contextFILEEXTFUNC
block|,
comment|/* USEROPEN=. */
name|FFEEXPR_contextFILEUNIT
block|,
comment|/* READ/WRITE UNIT=. */
name|FFEEXPR_contextFILEUNIT_DF
block|,
comment|/* DEFINE FILE unit (no "(" after it). */
name|FFEEXPR_contextFILEFORMATNML
block|,
comment|/* [FMT=] or [NML=]. */
name|FFEEXPR_contextFILEFORMAT
block|,
comment|/* FMT=. */
name|FFEEXPR_contextFILENAMELIST
block|,
comment|/* NML=. */
name|FFEEXPR_contextFILENUMAMBIG
block|,
comment|/* BACKSPACE, ENDFILE, REWIND, UNLOCK... 				   where at e.g. BACKSPACE(, if COMMA seen 				   before ), it is ok. */
name|FFEEXPR_contextFILEUNITAMBIG
block|,
comment|/* READ(, if COMMA seen before ), ok. */
name|FFEEXPR_contextFILEVXTCODE
block|,
comment|/* ENCODE/DECODE third arg (scalar/array). */
name|FFEEXPR_contextALLOCATE
block|,
comment|/* ALLOCATE objects (weird). */
name|FFEEXPR_contextDEALLOCATE
block|,
comment|/* DEALLOCATE objects (weird). */
name|FFEEXPR_contextHEAPSTAT
block|,
comment|/* ALLOCATE/DEALLOCATE STAT= variable. */
name|FFEEXPR_contextKINDTYPE
block|,
comment|/* KIND=. */
name|FFEEXPR_contextINITVAL
block|,
comment|/* R426 =initialization-expr. */
name|FFEEXPR_contextNULLIFY
block|,
comment|/* Pointer names only (F90) or pointers. */
name|FFEEXPR_contextIOLISTDF
block|,
comment|/* IOLIST w/internal file (V112 9-14 30,31). */
name|FFEEXPR_contextINDEX_
block|,
comment|/* Element dimension or substring value. */
name|FFEEXPR_contextEQVINDEX_
block|,
comment|/* EQUIVALENCE element dimension. */
name|FFEEXPR_contextDATAIMPDOINDEX_
block|,
comment|/* INDEX in DATAIMPDO context. */
name|FFEEXPR_contextIMPDOITEM_
block|,
name|FFEEXPR_contextIMPDOITEMDF_
block|,
comment|/* to ...ITEM_ as IOLISTDF is to IOLIST. */
name|FFEEXPR_contextIMPDOCTRL_
block|,
name|FFEEXPR_contextDATAIMPDOITEM_
block|,
name|FFEEXPR_contextDATAIMPDOCTRL_
block|,
name|FFEEXPR_contextLOC_
block|,
name|FFEEXPR_contextACTUALARG_
block|,
comment|/* Actual arg to function or subroutine; 				   turns into ACTUALARGEXPR_ if tokens not 				   NAME (CLOSE_PAREN/COMMA) or PERCENT.... */
name|FFEEXPR_contextACTUALARGEXPR_
block|,
comment|/* Like LET but disallow CHAR*(*) 					   concats. */
name|FFEEXPR_contextINDEXORACTUALARG_
block|,
comment|/* "CHARACTER FOO; PRINT *,FOO(?". */
name|FFEEXPR_contextINDEXORACTUALARGEXPR_
block|,
comment|/* ? not NAME 						   (CLOSE_PAREN/COMMA). */
name|FFEEXPR_contextSFUNCDEFINDEX_
block|,
comment|/* INDEX_ within stmt-func def. */
name|FFEEXPR_contextSFUNCDEFACTUALARG_
block|,
name|FFEEXPR_contextSFUNCDEFACTUALARGEXPR_
block|,
name|FFEEXPR_contextSFUNCDEFINDEXORACTUALARG_
block|,
name|FFEEXPR_contextSFUNCDEFINDEXORACTUALARGEXPR_
block|,
name|FFEEXPR_contextPAREN_
block|,
comment|/* Rhs paren except in LET context. */
name|FFEEXPR_contextPARENFILENUM_
block|,
comment|/* Either PAREN or FILENUM context. */
name|FFEEXPR_contextPARENFILEUNIT_
block|,
comment|/* Either PAREN or FILEUNIT context. */
name|FFEEXPR_context
block|}
name|ffeexprContext
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_typedef
typedef|typedef
name|ffelexHandler
function_decl|(
modifier|*
name|ffeexprCallback
function_decl|)
parameter_list|(
name|ffelexToken
name|ft
parameter_list|,
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|ffebld
name|ffeexpr_collapse_convert
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_paren
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_uplus
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_uminus
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_not
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_add
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_subtract
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_multiply
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_divide
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_power
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_concatenate
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_lt
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_le
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_eq
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_ne
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_gt
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_ge
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_and
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_or
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_xor
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_eqv
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_neqv
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_symter
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_funcref
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_arrayref
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_collapse_substr
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_convert
parameter_list|(
name|ffebld
name|source
parameter_list|,
name|ffelexToken
name|source_token
parameter_list|,
name|ffelexToken
name|dest_token
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffeinfoRank
name|rk
parameter_list|,
name|ffetargetCharacterSize
name|sz
parameter_list|,
name|ffeexprContext
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_convert_expr
parameter_list|(
name|ffebld
name|source
parameter_list|,
name|ffelexToken
name|source_token
parameter_list|,
name|ffebld
name|dest
parameter_list|,
name|ffelexToken
name|dest_token
parameter_list|,
name|ffeexprContext
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffeexpr_convert_to_sym
parameter_list|(
name|ffebld
name|source
parameter_list|,
name|ffelexToken
name|source_token
parameter_list|,
name|ffesymbol
name|dest
parameter_list|,
name|ffelexToken
name|dest_token
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeexpr_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffeexpr_rhs
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|ffeexprContext
name|context
parameter_list|,
name|ffeexprCallback
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffeexpr_lhs
parameter_list|(
name|mallocPool
name|pool
parameter_list|,
name|ffeexprContext
name|context
parameter_list|,
name|ffeexprCallback
name|callback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeexpr_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeexpr_type_combine
parameter_list|(
name|ffeinfoBasictype
modifier|*
name|nbt
parameter_list|,
name|ffeinfoKindtype
modifier|*
name|nkt
parameter_list|,
name|ffeinfoBasictype
name|lbt
parameter_list|,
name|ffeinfoKindtype
name|lkt
parameter_list|,
name|ffeinfoBasictype
name|rbt
parameter_list|,
name|ffeinfoKindtype
name|rkt
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffeexpr_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeexpr_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_EXPR_H */
end_comment

end_unit

