begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* storag.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       storag.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_STORAG_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_STORAG_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFESTORAG_typeNONE
block|,
name|FFESTORAG_typeCBLOCK
block|,
comment|/* A COMMON block. */
name|FFESTORAG_typeCOMMON
block|,
comment|/* A COMMON variable. */
name|FFESTORAG_typeLOCAL
block|,
comment|/* A local entity (var/array/equivalence). */
name|FFESTORAG_typeEQUIV
block|,
comment|/* An entity equivalenced into a COMMON/LOCAL 				   entity. */
name|FFESTORAG_type
block|}
name|ffestoragType
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffestorag_
modifier|*
name|ffestorag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffestorag_list_
modifier|*
name|ffestoragList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffestorag_list_
name|ffestoragList_
typedef|;
end_typedef

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
file|"info.h"
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

begin_comment
comment|/* Structure definitions. */
end_comment

begin_struct
struct|struct
name|_ffestorag_list_
block|{
name|ffestorag
name|first
decl_stmt|;
comment|/* First storage area in list. */
name|ffestorag
name|last
decl_stmt|;
comment|/* Last storage area in list. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffestorag_
block|{
name|ffestorag
name|next
decl_stmt|;
comment|/* Next storage area in list. */
name|ffestorag
name|previous
decl_stmt|;
comment|/* Previous storage area in list. */
name|ffestorag
name|parent
decl_stmt|;
comment|/* Parent who holds aggregate 				   initializations. */
name|ffebld
name|init
decl_stmt|;
comment|/* Initialization expression. */
name|ffebld
name|accretion
decl_stmt|;
comment|/* Initializations seen so far for aggregate. */
name|ffetargetOffset
name|accretes
decl_stmt|;
comment|/* # inits needed to fill entire aggregate. */
name|ffesymbol
name|symbol
decl_stmt|;
comment|/* NULL if typeLOCAL and non-NULL equivs 				   and the first "rooted" symbol not known. */
name|ffestoragList_
name|equivs_
decl_stmt|;
comment|/* NULL if typeLOCAL and not an EQUIVALENCE 				   area. */
name|ffetargetOffset
name|size
decl_stmt|;
comment|/* Size of area. */
name|ffetargetOffset
name|offset
decl_stmt|;
comment|/* Offset of entity within area, 0 for CBLOCK 				   and non-equivalence LOCAL,<= 0 for equivalence 				   LOCAL. */
name|ffetargetAlign
name|alignment
decl_stmt|;
comment|/* Initial alignment for entity. */
name|ffetargetAlign
name|modulo
decl_stmt|;
comment|/* Modulo within alignment. */
ifdef|#
directive|ifdef
name|FFECOM_storageHOOK
name|ffecomStorage
name|hook
decl_stmt|;
comment|/* Whatever the backend needs here. */
endif|#
directive|endif
name|ffestoragType
name|type
decl_stmt|;
name|ffeinfoBasictype
name|basic_type
decl_stmt|;
comment|/* NONE=>1 non-CHARACTER; ANY= 				   CHAR+non-CHAR. */
name|ffeinfoKindtype
name|kind_type
decl_stmt|;
comment|/* NONE=>1 kind type or NONE/ANY basic_type. */
name|ffesymbol
name|type_symbol
decl_stmt|;
comment|/* First symbol for basic_type/kind_type. */
name|bool
name|is_save
decl_stmt|;
comment|/* SAVE flag set for this storage area. */
name|bool
name|is_init
decl_stmt|;
comment|/* INIT flag set for this storage area. */
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
name|ffestoragList_
name|ffestorag_list_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|void
name|ffestorag_drive
parameter_list|(
name|ffestoragList
name|sl
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffestorag
name|mst
parameter_list|,
name|ffestorag
name|st
parameter_list|)
parameter_list|,
name|ffestorag
name|mst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_dump
parameter_list|(
name|ffestorag
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_end_layout
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_exec_layout
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffestorag
name|ffestorag_new
parameter_list|(
name|ffestoragList
name|sl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_report
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_update
parameter_list|(
name|ffestorag
name|s
parameter_list|,
name|ffesymbol
name|sym
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_update_init
parameter_list|(
name|ffestorag
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffestorag_update_save
parameter_list|(
name|ffestorag
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffestorag_accretes
parameter_list|(
name|s
parameter_list|)
value|((s)->accretes)
end_define

begin_define
define|#
directive|define
name|ffestorag_accretion
parameter_list|(
name|s
parameter_list|)
value|((s)->accretion)
end_define

begin_define
define|#
directive|define
name|ffestorag_alignment
parameter_list|(
name|s
parameter_list|)
value|((s)->alignment)
end_define

begin_define
define|#
directive|define
name|ffestorag_basictype
parameter_list|(
name|s
parameter_list|)
value|((s)->basic_type)
end_define

begin_define
define|#
directive|define
name|ffestorag_hook
parameter_list|(
name|s
parameter_list|)
value|((s)->hook)
end_define

begin_define
define|#
directive|define
name|ffestorag_init
parameter_list|(
name|s
parameter_list|)
value|((s)->init)
end_define

begin_define
define|#
directive|define
name|ffestorag_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_is_init
parameter_list|(
name|s
parameter_list|)
value|((s)->is_init)
end_define

begin_define
define|#
directive|define
name|ffestorag_is_save
parameter_list|(
name|s
parameter_list|)
value|((s)->is_save)
end_define

begin_define
define|#
directive|define
name|ffestorag_kindtype
parameter_list|(
name|s
parameter_list|)
value|((s)->kind_type)
end_define

begin_define
define|#
directive|define
name|ffestorag_list_equivs
parameter_list|(
name|s
parameter_list|)
value|(&(s)->equivs_)
end_define

begin_define
define|#
directive|define
name|ffestorag_list_master
parameter_list|()
value|(&ffestorag_list_)
end_define

begin_define
define|#
directive|define
name|ffestorag_modulo
parameter_list|(
name|s
parameter_list|)
value|((s)->modulo)
end_define

begin_define
define|#
directive|define
name|ffestorag_offset
parameter_list|(
name|s
parameter_list|)
value|((s)->offset)
end_define

begin_define
define|#
directive|define
name|ffestorag_parent
parameter_list|(
name|s
parameter_list|)
value|((s)->parent)
end_define

begin_define
define|#
directive|define
name|ffestorag_ptr_to_alignment
parameter_list|(
name|s
parameter_list|)
value|(&(s)->alignment)
end_define

begin_define
define|#
directive|define
name|ffestorag_ptr_to_modulo
parameter_list|(
name|s
parameter_list|)
value|(&(s)->modulo)
end_define

begin_define
define|#
directive|define
name|ffestorag_set_accretes
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->accretes = (a))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_accretion
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->accretion = (a))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_alignment
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->alignment = (a))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_basictype
parameter_list|(
name|s
parameter_list|,
name|b
parameter_list|)
value|((s)->basic_type = (b))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_hook
parameter_list|(
name|s
parameter_list|,
name|h
parameter_list|)
value|((s)->hook = (h))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_init
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|)
value|((s)->init = (i))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_is_init
parameter_list|(
name|s
parameter_list|,
name|in
parameter_list|)
value|((s)->is_init = (in))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_is_save
parameter_list|(
name|s
parameter_list|,
name|sa
parameter_list|)
value|((s)->is_save = (sa))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_kindtype
parameter_list|(
name|s
parameter_list|,
name|k
parameter_list|)
value|((s)->kind_type = (k))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_modulo
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|((s)->modulo = (m))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_offset
parameter_list|(
name|s
parameter_list|,
name|o
parameter_list|)
value|((s)->offset = (o))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_parent
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|((s)->parent = (p))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_size
parameter_list|(
name|s
parameter_list|,
name|si
parameter_list|)
value|((s)->size = (si))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_symbol
parameter_list|(
name|s
parameter_list|,
name|sy
parameter_list|)
value|((s)->symbol = (sy))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_type
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((s)->type = (t))
end_define

begin_define
define|#
directive|define
name|ffestorag_set_typesymbol
parameter_list|(
name|s
parameter_list|,
name|sy
parameter_list|)
value|((s)->type_symbol = (sy))
end_define

begin_define
define|#
directive|define
name|ffestorag_size
parameter_list|(
name|s
parameter_list|)
value|((s)->size)
end_define

begin_define
define|#
directive|define
name|ffestorag_symbol
parameter_list|(
name|s
parameter_list|)
value|((s)->symbol)
end_define

begin_define
define|#
directive|define
name|ffestorag_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffestorag_type
parameter_list|(
name|s
parameter_list|)
value|((s)->type)
end_define

begin_define
define|#
directive|define
name|ffestorag_typesymbol
parameter_list|(
name|s
parameter_list|)
value|((s)->type_symbol)
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_STORAG_H */
end_comment

end_unit

