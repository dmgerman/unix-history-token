begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lex.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       lex.c     Modifications:       22-Aug-89	 JCB  1.1 	 Change for new ffewhere interface. */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_LEX_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_LEX_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFELEX_typeNONE
block|,
name|FFELEX_typeCOMMENT
block|,
name|FFELEX_typeEOS
block|,
name|FFELEX_typeEOF
block|,
name|FFELEX_typeERROR
block|,
name|FFELEX_typeRAW
block|,
name|FFELEX_typeQUOTE
block|,
name|FFELEX_typeDOLLAR
block|,
name|FFELEX_typeHASH
block|,
name|FFELEX_typePERCENT
block|,
name|FFELEX_typeAMPERSAND
block|,
name|FFELEX_typeAPOSTROPHE
block|,
name|FFELEX_typeOPEN_PAREN
block|,
name|FFELEX_typeCLOSE_PAREN
block|,
name|FFELEX_typeASTERISK
block|,
name|FFELEX_typePLUS
block|,
name|FFELEX_typeMINUS
block|,
name|FFELEX_typePERIOD
block|,
name|FFELEX_typeSLASH
block|,
name|FFELEX_typeNUMBER
block|,
comment|/* Grep: [0-9][0-9]*. */
name|FFELEX_typeOPEN_ANGLE
block|,
name|FFELEX_typeEQUALS
block|,
name|FFELEX_typeCLOSE_ANGLE
block|,
name|FFELEX_typeNAME
block|,
comment|/* Grep: [A-Za-z][A-Za-z0-9_]*. */
name|FFELEX_typeCOMMA
block|,
name|FFELEX_typePOWER
block|,
comment|/* "**". */
name|FFELEX_typeCONCAT
block|,
comment|/* "//". */
name|FFELEX_typeDEBUG
block|,
name|FFELEX_typeNAMES
block|,
comment|/* Same as FFELEX_typeNAME in initial 				   context. */
name|FFELEX_typeHOLLERITH
block|,
comment|/*<text> part of<nn>H<text>. */
name|FFELEX_typeCHARACTER
block|,
comment|/*<text> part of '<text>' or "<text>". */
name|FFELEX_typeCOLON
block|,
name|FFELEX_typeSEMICOLON
block|,
name|FFELEX_typeUNDERSCORE
block|,
name|FFELEX_typeQUESTION
block|,
name|FFELEX_typeOPEN_ARRAY
block|,
comment|/* "(/". */
name|FFELEX_typeCLOSE_ARRAY
block|,
comment|/* "/)". */
name|FFELEX_typeCOLONCOLON
block|,
comment|/* "::". */
name|FFELEX_typeREL_LE
block|,
comment|/* "<=". */
name|FFELEX_typeREL_NE
block|,
comment|/* "<>". */
name|FFELEX_typeREL_EQ
block|,
comment|/* "==". */
name|FFELEX_typePOINTS
block|,
comment|/* "=>". */
name|FFELEX_typeREL_GE
block|,
comment|/* ">=". */
name|FFELEX_type
block|}
name|ffelexType
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_lextoken_
modifier|*
name|ffelexToken
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|lex_sigh_
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|lex_sigh_
function_decl|(
modifier|*
name|lex_sigh__
function_decl|)
parameter_list|(
name|ffelexToken
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|lex_sigh__
function_decl|(
modifier|*
name|ffelexHandler
function_decl|)
parameter_list|(
name|ffelexToken
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_lextoken_
block|{
name|long
name|int
name|id_
decl_stmt|;
comment|/* DEBUG ONLY. */
name|ffeTokenLength
name|size
decl_stmt|;
name|ffeTokenLength
name|length
decl_stmt|;
name|unsigned
name|short
name|uses
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
name|ffelexType
name|type
decl_stmt|;
name|ffewhereLine
name|where_line
decl_stmt|;
name|ffewhereColumn
name|where_col
decl_stmt|;
name|ffewhereLine
name|currentnames_line
decl_stmt|;
comment|/* For tracking NAMES tokens. */
name|ffewhereColumn
name|currentnames_col
decl_stmt|;
comment|/* For tracking NAMES tokens. */
name|ffewhereTrack
name|wheretrack
decl_stmt|;
comment|/* For tracking NAMES tokens. */
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffelex_display_token
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffelex_expecting_character
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffelex_file_fixed
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffelex_file_free
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|,
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_hash_kludge
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffelex_is_names_expected
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ffelex_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereColumnNumber
name|ffelex_line_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffewhereLineNumber
name|ffelex_line_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_expecting_hollerith
parameter_list|(
name|long
name|length
parameter_list|,
name|char
name|which
parameter_list|,
name|ffewhereLine
name|line
parameter_list|,
name|ffewhereColumn
name|column
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_handler
parameter_list|(
name|ffelexHandler
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_hexnum
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_include
parameter_list|(
name|ffewhereFile
name|wf
parameter_list|,
name|bool
name|free_form
parameter_list|,
name|FILE
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_names
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_set_names_pure
parameter_list|(
name|bool
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffelex_splice_tokens
parameter_list|(
name|ffelexHandler
name|first
parameter_list|,
name|ffelexToken
name|master
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexHandler
name|ffelex_swallow_tokens
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffelexHandler
name|handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_dollar_from_names
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelex_token_kill
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_name_from_names
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|,
name|ffeTokenLength
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_names_from_names
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|,
name|ffeTokenLength
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_character
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_eof
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_name
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_names
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_number
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_new_simple_
parameter_list|(
name|ffelexType
name|type
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_number_from_names
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_uscore_from_names
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|ffeTokenLength
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelexToken
name|ffelex_token_use
parameter_list|(
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
name|ffelex_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_is_firstnamechar
parameter_list|(
name|c
parameter_list|)
value|ISIDST (c)
end_define

begin_define
define|#
directive|define
name|ffelex_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelex_token_length
parameter_list|(
name|t
parameter_list|)
value|((t)->length)
end_define

begin_define
define|#
directive|define
name|ffelex_token_new_eos
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
define|\
value|ffelex_token_new_simple_ (FFELEX_typeEOS, (l), (c))
end_define

begin_define
define|#
directive|define
name|ffelex_token_new_period
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
define|\
value|ffelex_token_new_simple_ (FFELEX_typePERIOD, (l), (c))
end_define

begin_define
define|#
directive|define
name|ffelex_token_strcmp
parameter_list|(
name|t1
parameter_list|,
name|t2
parameter_list|)
value|strcmp ((t1)->text, (t2)->text)
end_define

begin_define
define|#
directive|define
name|ffelex_token_text
parameter_list|(
name|t
parameter_list|)
value|((t)->text)
end_define

begin_define
define|#
directive|define
name|ffelex_token_type
parameter_list|(
name|t
parameter_list|)
value|((t)->type)
end_define

begin_define
define|#
directive|define
name|ffelex_token_where_column
parameter_list|(
name|t
parameter_list|)
value|((t)->where_col)
end_define

begin_define
define|#
directive|define
name|ffelex_token_where_filename
parameter_list|(
name|t
parameter_list|)
define|\
value|ffewhere_line_filename ((t)->where_line)
end_define

begin_define
define|#
directive|define
name|ffelex_token_where_filelinenum
parameter_list|(
name|t
parameter_list|)
define|\
value|ffewhere_line_filelinenum((t)->where_line)
end_define

begin_define
define|#
directive|define
name|ffelex_token_where_line
parameter_list|(
name|t
parameter_list|)
value|((t)->where_line)
end_define

begin_define
define|#
directive|define
name|ffelex_token_where_line_number
parameter_list|(
name|t
parameter_list|)
define|\
value|ffewhere_line_number ((t)->where_line)
end_define

begin_define
define|#
directive|define
name|ffelex_token_wheretrack
parameter_list|(
name|t
parameter_list|)
value|((t)->wheretrack)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_LEX_H */
end_comment

end_unit

