begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* global.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1997 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       global.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_GLOBAL_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_GLOBAL_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFEGLOBAL_typeNONE
block|,
name|FFEGLOBAL_typeMAIN
block|,
name|FFEGLOBAL_typeEXT
block|,
comment|/* EXTERNAL is all we know. */
name|FFEGLOBAL_typeSUBR
block|,
name|FFEGLOBAL_typeFUNC
block|,
name|FFEGLOBAL_typeBDATA
block|,
name|FFEGLOBAL_typeCOMMON
block|,
name|FFEGLOBAL_typeANY
block|,
comment|/* Confusion reigns, so just ignore. */
name|FFEGLOBAL_type
block|}
name|ffeglobalType
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFEGLOBAL_argsummaryNONE
block|,
comment|/* No arg present. */
name|FFEGLOBAL_argsummaryVAL
block|,
comment|/* Pass-by-value. */
name|FFEGLOBAL_argsummaryREF
block|,
comment|/* Pass-by-reference. */
name|FFEGLOBAL_argsummaryDESCR
block|,
comment|/* Pass-by-descriptor. */
name|FFEGLOBAL_argsummaryPROC
block|,
comment|/* Procedure (intrinsic, external). */
name|FFEGLOBAL_argsummarySUBR
block|,
comment|/* Subroutine (intrinsic, external). */
name|FFEGLOBAL_argsummaryFUNC
block|,
comment|/* Function (intrinsic, external). */
name|FFEGLOBAL_argsummaryALTRTN
block|,
comment|/* Alternate-return (label). */
name|FFEGLOBAL_argsummaryANY
block|,
name|FFEGLOBAL_argsummary
block|}
name|ffeglobalArgSummary
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffeglobal_arginfo_
modifier|*
name|ffeglobalArgInfo_
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffeglobal_
modifier|*
name|ffeglobal
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"lex.h"
end_include

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffeglobal_arginfo_
block|{
name|ffelexToken
name|t
decl_stmt|;
comment|/* Different from master token when difference is important. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of dummy arg, or NULL if not yet known. */
name|ffeglobalArgSummary
name|as
decl_stmt|;
name|ffeinfoBasictype
name|bt
decl_stmt|;
name|ffeinfoKindtype
name|kt
decl_stmt|;
name|bool
name|array
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffeglobal_
block|{
name|ffelexToken
name|t
decl_stmt|;
name|ffename
name|n
decl_stmt|;
ifdef|#
directive|ifdef
name|FFECOM_globalHOOK
name|ffecomGlobal
name|hook
decl_stmt|;
endif|#
directive|endif
name|ffeCounter
name|tick
decl_stmt|;
comment|/* Recent transition in this progunit. */
name|ffeglobalType
name|type
decl_stmt|;
name|bool
name|intrinsic
decl_stmt|;
comment|/* Known as intrinsic? */
name|bool
name|explicit_intrinsic
decl_stmt|;
comment|/* Explicit intrinsic? */
union|union
block|{
struct|struct
block|{
name|ffelexToken
name|initt
decl_stmt|;
comment|/* First initial value. */
name|bool
name|have_pad
decl_stmt|;
comment|/* Padding info avail for COMMON? */
name|ffetargetAlign
name|pad
decl_stmt|;
comment|/* Initial padding for COMMON. */
name|ffewhereLine
name|pad_where_line
decl_stmt|;
name|ffewhereColumn
name|pad_where_col
decl_stmt|;
name|bool
name|have_save
decl_stmt|;
comment|/* Save info avail for COMMON? */
name|bool
name|save
decl_stmt|;
comment|/* Save info for COMMON. */
name|ffewhereLine
name|save_where_line
decl_stmt|;
name|ffewhereColumn
name|save_where_col
decl_stmt|;
name|bool
name|have_size
decl_stmt|;
comment|/* Size info avail for COMMON? */
name|ffetargetOffset
name|size
decl_stmt|;
comment|/* Size info for COMMON. */
name|bool
name|blank
decl_stmt|;
comment|/* TRUE if blank COMMON. */
block|}
name|common
struct|;
struct|struct
block|{
name|bool
name|defined
decl_stmt|;
comment|/* Seen actual code yet? */
name|ffeinfoBasictype
name|bt
decl_stmt|;
comment|/* NONE for non-function. */
name|ffeinfoKindtype
name|kt
decl_stmt|;
comment|/* NONE for non-function. */
name|ffetargetCharacterSize
name|sz
decl_stmt|;
name|int
name|n_args
decl_stmt|;
comment|/* 0 for main/blockdata. */
name|ffelexToken
name|other_t
decl_stmt|;
comment|/* Location of reference. */
name|ffeglobalArgInfo_
name|arg_info
decl_stmt|;
comment|/* Info on each argument. */
block|}
name|proc
struct|;
block|}
name|u
union|;
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
name|ffeglobal_drive
parameter_list|(
name|ffeglobal
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffeglobal
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_init_common
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_new_progunit_
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|ffeglobalType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_new_common
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|bool
name|blank
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_pad_common
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffetargetAlign
name|pad
parameter_list|,
name|ffewhereLine
name|wl
parameter_list|,
name|ffewhereColumn
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_proc_def_arg
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|int
name|argno
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|ffeglobalArgSummary
name|as
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|bool
name|array
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_proc_def_nargs
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|int
name|n_args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeglobal_proc_ref_arg
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|int
name|argno
parameter_list|,
name|ffeglobalArgSummary
name|as
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|bool
name|array
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeglobal_proc_ref_nargs
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|int
name|n_args
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeglobal
name|ffeglobal_promoted
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_ref_intrinsic
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|bool
name|explicit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeglobal_ref_progunit_
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|ffeglobalType
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_save_common
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|bool
name|save
parameter_list|,
name|ffewhereLine
name|wl
parameter_list|,
name|ffewhereColumn
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffeglobal_size_common
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffetargetOffset
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffeglobal_terminate_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|FFEGLOBAL_ENABLED
value|1
end_define

begin_define
define|#
directive|define
name|ffeglobal_common_init
parameter_list|(
name|g
parameter_list|)
value|((g)->tick != 0)
end_define

begin_define
define|#
directive|define
name|ffeglobal_common_have_pad
parameter_list|(
name|g
parameter_list|)
value|((g)->u.common.have_pad)
end_define

begin_define
define|#
directive|define
name|ffeglobal_common_have_size
parameter_list|(
name|g
parameter_list|)
value|((g)->u.common.have_size)
end_define

begin_define
define|#
directive|define
name|ffeglobal_common_pad
parameter_list|(
name|g
parameter_list|)
value|((g)->u.common.pad)
end_define

begin_define
define|#
directive|define
name|ffeglobal_common_size
parameter_list|(
name|g
parameter_list|)
value|((g)->u.common.size)
end_define

begin_define
define|#
directive|define
name|ffeglobal_hook
parameter_list|(
name|g
parameter_list|)
value|((g)->hook)
end_define

begin_define
define|#
directive|define
name|ffeglobal_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_new_blockdata
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_new_progunit_(s,t,FFEGLOBAL_typeBDATA)
end_define

begin_define
define|#
directive|define
name|ffeglobal_new_function
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_new_progunit_(s,t,FFEGLOBAL_typeFUNC)
end_define

begin_define
define|#
directive|define
name|ffeglobal_new_program
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_new_progunit_(s,t,FFEGLOBAL_typeMAIN)
end_define

begin_define
define|#
directive|define
name|ffeglobal_new_subroutine
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_new_progunit_(s,t,FFEGLOBAL_typeSUBR)
end_define

begin_define
define|#
directive|define
name|ffeglobal_ref_blockdata
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_ref_progunit_(s,t,FFEGLOBAL_typeBDATA)
end_define

begin_define
define|#
directive|define
name|ffeglobal_ref_external
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_ref_progunit_(s,t,FFEGLOBAL_typeEXT)
end_define

begin_define
define|#
directive|define
name|ffeglobal_ref_function
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_ref_progunit_(s,t,FFEGLOBAL_typeFUNC)
end_define

begin_define
define|#
directive|define
name|ffeglobal_ref_subroutine
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
define|\
value|ffeglobal_ref_progunit_(s,t,FFEGLOBAL_typeSUBR)
end_define

begin_define
define|#
directive|define
name|ffeglobal_set_hook
parameter_list|(
name|g
parameter_list|,
name|h
parameter_list|)
value|((g)->hook = (h))
end_define

begin_define
define|#
directive|define
name|ffeglobal_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffeglobal_text
parameter_list|(
name|g
parameter_list|)
value|ffename_text((g)->n)
end_define

begin_define
define|#
directive|define
name|ffeglobal_type
parameter_list|(
name|g
parameter_list|)
value|((g)->type)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_GLOBAL_H */
end_comment

end_unit

