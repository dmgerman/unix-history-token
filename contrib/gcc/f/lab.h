begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lab.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       lab.c     Modifications:       22-Aug-89	 JCB  1.1 	 Change for new ffewhere interface. */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_LAB_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_LAB_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFELAB_typeUNKNOWN
block|,
comment|/* No info yet on label. */
name|FFELAB_typeANY
block|,
comment|/* Label valid for anything, no msgs. */
name|FFELAB_typeUSELESS
block|,
comment|/* No valid way to reference this label. */
name|FFELAB_typeASSIGNABLE
block|,
comment|/* Target of ASSIGN: so FORMAT or BRANCH. */
name|FFELAB_typeFORMAT
block|,
comment|/* FORMAT label. */
name|FFELAB_typeLOOPEND
block|,
comment|/* Target of a labeled DO statement. */
name|FFELAB_typeNOTLOOP
block|,
comment|/* Branch target statement not valid DO 				   target. */
name|FFELAB_typeENDIF
block|,
comment|/* END IF label. */
name|FFELAB_type
block|}
name|ffelabType
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFELAB_valueNONE
value|0
end_define

begin_define
define|#
directive|define
name|FFELAB_valueMAX
value|99999
end_define

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffelab_
modifier|*
name|ffelab
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ffelab
name|ffelabHandle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ffelabNumber
typedef|;
end_typedef

begin_comment
comment|/* Count of new labels. */
end_comment

begin_define
define|#
directive|define
name|ffelabNumber_f
value|"l"
end_define

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ffelabValue
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffelabValue_f
value|"l"
end_define

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"com.h"
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
name|_ffelab_
block|{
name|ffelab
name|next
decl_stmt|;
ifdef|#
directive|ifdef
name|FFECOM_labelHOOK
name|ffecomLabel
name|hook
decl_stmt|;
endif|#
directive|endif
name|ffelabValue
name|value
decl_stmt|;
comment|/* 1 through 99999, or 100000+ for temp 				   labels. */
name|unsigned
name|long
name|blocknum
decl_stmt|;
comment|/* Managed entirely by user of module. */
name|ffewhereLine
name|firstref_line
decl_stmt|;
name|ffewhereColumn
name|firstref_col
decl_stmt|;
name|ffewhereLine
name|doref_line
decl_stmt|;
name|ffewhereColumn
name|doref_col
decl_stmt|;
name|ffewhereLine
name|definition_line
decl_stmt|;
comment|/* ffewhere_line_unknown() if not 					   defined. */
name|ffewhereColumn
name|definition_col
decl_stmt|;
name|ffelabType
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|ffelab
name|ffelab_list_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffelabNumber
name|ffelab_num_news_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|ffelab
name|ffelab_find
parameter_list|(
name|ffelabValue
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelab_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffelab_init_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffelab
name|ffelab_new
parameter_list|(
name|ffelabValue
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffelab_blocknum
parameter_list|(
name|l
parameter_list|)
value|((l)->blocknum)
end_define

begin_define
define|#
directive|define
name|ffelab_definition_column
parameter_list|(
name|l
parameter_list|)
value|((l)->definition_col)
end_define

begin_define
define|#
directive|define
name|ffelab_definition_filename
parameter_list|(
name|l
parameter_list|)
define|\
value|ffewhere_line_filename((l)->definition_line)
end_define

begin_define
define|#
directive|define
name|ffelab_definition_filelinenum
parameter_list|(
name|l
parameter_list|)
define|\
value|ffewhere_line_filelinenum((l)->definition_line)
end_define

begin_define
define|#
directive|define
name|ffelab_definition_line
parameter_list|(
name|l
parameter_list|)
value|((l)->definition_line)
end_define

begin_define
define|#
directive|define
name|ffelab_definition_line_number
parameter_list|(
name|l
parameter_list|)
define|\
value|ffewhere_line_number((l)->definition_line)
end_define

begin_define
define|#
directive|define
name|ffelab_doref_column
parameter_list|(
name|l
parameter_list|)
value|((l)->doref_col)
end_define

begin_define
define|#
directive|define
name|ffelab_doref_filename
parameter_list|(
name|l
parameter_list|)
value|ffewhere_line_filename((l)->doref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_doref_filelinenum
parameter_list|(
name|l
parameter_list|)
value|ffewhere_line_filelinenum((l)->doref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_doref_line
parameter_list|(
name|l
parameter_list|)
value|((l)->doref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_doref_line_number
parameter_list|(
name|l
parameter_list|)
value|ffewhere_line_number((l)->doref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_firstref_column
parameter_list|(
name|l
parameter_list|)
value|((l)->firstref_col)
end_define

begin_define
define|#
directive|define
name|ffelab_firstref_filename
parameter_list|(
name|l
parameter_list|)
value|ffewhere_line_filename((l)->firstref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_firstref_filelinenum
parameter_list|(
name|l
parameter_list|)
define|\
value|ffewhere_line_filelinenum((l)->firstref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_firstref_line
parameter_list|(
name|l
parameter_list|)
value|((l)->firstref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_firstref_line_number
parameter_list|(
name|l
parameter_list|)
value|ffewhere_line_number((l)->firstref_line)
end_define

begin_define
define|#
directive|define
name|ffelab_handle_done
parameter_list|(
name|h
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ffelab_handle_first
parameter_list|()
value|((ffelabHandle) ffelab_list_)
end_define

begin_define
define|#
directive|define
name|ffelab_handle_next
parameter_list|(
name|h
parameter_list|)
value|((ffelabHandle) (((ffelab) h)->next))
end_define

begin_define
define|#
directive|define
name|ffelab_handle_target
parameter_list|(
name|h
parameter_list|)
value|((ffelab) h)
end_define

begin_define
define|#
directive|define
name|ffelab_hook
parameter_list|(
name|l
parameter_list|)
value|((l)->hook)
end_define

begin_define
define|#
directive|define
name|ffelab_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_kill
parameter_list|(
name|l
parameter_list|)
value|ffelab_set_value(l,FFELAB_valueNONE);
end_define

begin_define
define|#
directive|define
name|ffelab_new_generated
parameter_list|()
value|(ffelab_new(ffelab_generated_++))
end_define

begin_define
define|#
directive|define
name|ffelab_number
parameter_list|()
value|(ffelab_num_news_)
end_define

begin_define
define|#
directive|define
name|ffelab_set_blocknum
parameter_list|(
name|l
parameter_list|,
name|b
parameter_list|)
value|((l)->blocknum = (b))
end_define

begin_define
define|#
directive|define
name|ffelab_set_definition_column
parameter_list|(
name|l
parameter_list|,
name|cn
parameter_list|)
value|((l)->definition_col = (cn))
end_define

begin_define
define|#
directive|define
name|ffelab_set_definition_line
parameter_list|(
name|l
parameter_list|,
name|ln
parameter_list|)
value|((l)->definition_line = (ln))
end_define

begin_define
define|#
directive|define
name|ffelab_set_doref_column
parameter_list|(
name|l
parameter_list|,
name|cn
parameter_list|)
value|((l)->doref_col = (cn))
end_define

begin_define
define|#
directive|define
name|ffelab_set_doref_line
parameter_list|(
name|l
parameter_list|,
name|ln
parameter_list|)
value|((l)->doref_line = (ln))
end_define

begin_define
define|#
directive|define
name|ffelab_set_firstref_column
parameter_list|(
name|l
parameter_list|,
name|cn
parameter_list|)
value|((l)->firstref_col = (cn))
end_define

begin_define
define|#
directive|define
name|ffelab_set_firstref_line
parameter_list|(
name|l
parameter_list|,
name|ln
parameter_list|)
value|((l)->firstref_line = (ln))
end_define

begin_define
define|#
directive|define
name|ffelab_set_hook
parameter_list|(
name|l
parameter_list|,
name|h
parameter_list|)
value|((l)->hook = (h))
end_define

begin_define
define|#
directive|define
name|ffelab_set_type
parameter_list|(
name|l
parameter_list|,
name|t
parameter_list|)
value|((l)->type = (t))
end_define

begin_define
define|#
directive|define
name|ffelab_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffelab_type
parameter_list|(
name|l
parameter_list|)
value|((l)->type)
end_define

begin_define
define|#
directive|define
name|ffelab_value
parameter_list|(
name|l
parameter_list|)
value|((l)->value)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_LAB_H */
end_comment

end_unit

