begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface definitions for Fortran symbol manager    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_symbol
end_ifndef

begin_define
define|#
directive|define
name|_H_f_symbol
end_define

begin_comment
comment|/* The main symbol type.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffesymbol_
modifier|*
name|ffesymbol
typedef|;
end_typedef

begin_comment
comment|/* State of understanding about what the symbol represents.  */
end_comment

begin_enum
enum|enum
name|_ffesymbol_state_
block|{
comment|/* See ffesymbol_state_is_exec() macro below when making changes.  */
name|FFESYMBOL_stateNONE
block|,
comment|/* Never before seen. */
name|FFESYMBOL_stateSEEN
block|,
comment|/* Seen before exec transition and not yet 				   understood (info not filled in, etc). */
name|FFESYMBOL_stateUNCERTAIN
block|,
comment|/* Almost understood (info partly filled in). */
name|FFESYMBOL_stateUNDERSTOOD
block|,
comment|/* Fully understood (info filled in). */
name|FFESYMBOL_state
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffesymbol_state_
name|ffesymbolState
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffesymbolState_f
value|""
end_define

begin_comment
comment|/* Attributes.  Symbols acquire attributes while their state is SEEN.    These attributes are basically ignored once the symbol becomes    UNDERSTOOD.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|ffesymbolAttrs
typedef|;
end_typedef

begin_comment
comment|/* Holds set of attributes. */
end_comment

begin_define
define|#
directive|define
name|ffesymbolAttrs_f
value|"l"
end_define

begin_enum
enum|enum
name|_ffesymbol_attr_
block|{
define|#
directive|define
name|DEFATTR
parameter_list|(
name|ATTR
parameter_list|,
name|ATTRS
parameter_list|,
name|NAME
parameter_list|)
value|ATTR,
include|#
directive|include
file|"symbol.def"
undef|#
directive|undef
name|DEFATTR
name|FFESYMBOL_attr
block|}
enum|;
end_enum

begin_comment
comment|/* A given attribute. */
end_comment

begin_typedef
typedef|typedef
name|enum
name|_ffesymbol_attr_
name|ffesymbolAttr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffesymbolAttr_f
value|""
end_define

begin_define
define|#
directive|define
name|FFESYMBOL_attrsetNONE
value|0
end_define

begin_define
define|#
directive|define
name|FFESYMBOL_attrsetALL
value|(((ffesymbolAttrs) 1<< FFESYMBOL_attr) - 1)
end_define

begin_comment
comment|/* This is just for avoiding complaining about, e.g., "I = IABS(3)", that    IABS doesn't meet the requirements for a user-defined symbol name as    a result of, say, --symbol-case-lower, if IABS turns out to indeed be    a reference to the intrinsic IABS (in which case it's a Fortran keyword    like CALL) and not a user-defined name.  */
end_comment

begin_enum
enum|enum
name|_ffesymbol_checkstate_
block|{
name|FFESYMBOL_checkstateNONE_
block|,
comment|/* Not checked/never necessary to check. */
name|FFESYMBOL_checkstateINHIBITED_
block|,
comment|/* Bad name, but inhibited. */
name|FFESYMBOL_checkstatePENDING_
block|,
comment|/* Bad name, might be intrinsic. */
name|FFESYMBOL_checkstateCHECKED_
block|,
comment|/* Ok name, intrinsic, or bad name 					   reported. */
name|FFESYMBOL_checkstate_
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|_ffesymbol_checkstate_
name|ffesymbolCheckState_
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffesymbolCheckState_f_
value|""
end_define

begin_include
include|#
directive|include
file|"bld.h"
end_include

begin_include
include|#
directive|include
file|"com.h"
end_include

begin_include
include|#
directive|include
file|"equiv.h"
end_include

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"intrin.h"
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

begin_include
include|#
directive|include
file|"name.h"
end_include

begin_include
include|#
directive|include
file|"storag.h"
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

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_struct
struct|struct
name|_ffesymbol_
block|{
name|ffename
name|name
decl_stmt|;
name|ffename
name|other_space_name
decl_stmt|;
comment|/* For dual-space objects. */
name|ffeglobal
name|global
decl_stmt|;
comment|/* In filewide name space. */
name|ffesymbolAttrs
name|attrs
decl_stmt|;
comment|/* What kind of symbol am I? */
name|ffesymbolState
name|state
decl_stmt|;
comment|/* What state am I in? */
name|ffeinfo
name|info
decl_stmt|;
comment|/* Info filled in when _stateUNDERSTOOD. */
name|ffebld
name|dims
decl_stmt|;
comment|/* Dimension list expression. */
name|ffebld
name|extents
decl_stmt|;
comment|/* Extents list expression. */
name|ffebld
name|dim_syms
decl_stmt|;
comment|/* List of SYMTERs of all symbols in dims. */
name|ffebld
name|array_size
decl_stmt|;
comment|/* Size as an expression involving some of 				   dims. */
name|ffebld
name|init
decl_stmt|;
comment|/* Initialization expression or expr list or 				   PARAMETER value. */
name|ffebld
name|accretion
decl_stmt|;
comment|/* Initializations seen so far for 				   array/substr. */
name|ffetargetOffset
name|accretes
decl_stmt|;
comment|/* # inits needed to fill entire array. */
name|ffebld
name|dummy_args
decl_stmt|;
comment|/* For functions, subroutines, and entry 				   points. */
name|ffebld
name|namelist
decl_stmt|;
comment|/* List of symbols in NML. */
name|ffebld
name|common_list
decl_stmt|;
comment|/* List of entities in BCB/NCB. */
name|ffebld
name|sfunc_expr
decl_stmt|;
comment|/* SFN's expression. */
name|ffebldListBottom
name|list_bottom
decl_stmt|;
comment|/* For BCB, NCB, NML. */
name|ffesymbol
name|common
decl_stmt|;
comment|/* Who is my containing COMMON area? */
name|ffeequiv
name|equiv
decl_stmt|;
comment|/* Who have I been equivalenced with? */
name|ffestorag
name|storage
decl_stmt|;
comment|/* Where am I in relation to my outside 				   world? */
ifdef|#
directive|ifdef
name|FFECOM_symbolHOOK
name|ffecomSymbol
name|hook
decl_stmt|;
comment|/* Whatever the compiler/backend wants! */
endif|#
directive|endif
name|ffesymbol
name|sfa_dummy_parent
decl_stmt|;
comment|/* "X" outside sfunc "CIRC(X) = 3.14 * X". */
name|ffesymbol
name|func_result
decl_stmt|;
comment|/* FUN sym's corresponding RES sym,& vice 				   versa. */
name|ffetargetIntegerDefault
name|value
decl_stmt|;
comment|/* IMMEDIATE (DATA impdo) value. */
name|ffesymbolCheckState_
name|check_state
decl_stmt|;
comment|/* Valid name? */
name|ffelexToken
name|check_token
decl_stmt|;
comment|/* checkstatePENDING_ only. */
name|int
name|max_entry_num
decl_stmt|;
comment|/* For detecting dummy arg listed twice/IMPDO 				   iterator nesting violation; also for id of 				   sfunc dummy arg. */
name|int
name|num_entries
decl_stmt|;
comment|/* Number of entry points in which this 				   symbol appears as a dummy arg; helps 				   determine whether arg might not be passed, 				   for example.  */
name|ffeintrinGen
name|generic
decl_stmt|;
comment|/* Generic intrinsic id, if any. */
name|ffeintrinSpec
name|specific
decl_stmt|;
comment|/* Specific intrinsic id, if any. */
name|ffeintrinImp
name|implementation
decl_stmt|;
comment|/* Implementation id, if any. */
name|bool
name|is_save
decl_stmt|;
comment|/* SAVE flag set for this symbol (see also 				   ffe_is_saveall()). */
name|bool
name|is_init
decl_stmt|;
comment|/* INIT flag set for this symbol. */
name|bool
name|do_iter
decl_stmt|;
comment|/* Is currently a DO-loop iter (can't be 				   changed in loop). */
name|bool
name|reported
decl_stmt|;
comment|/* (Debug) TRUE if the latest version has 				   been reported. */
name|bool
name|have_old
decl_stmt|;
comment|/* TRUE if old copy of this symbol saved 				   away. */
name|bool
name|explicit_where
decl_stmt|;
comment|/* TRUE if INTRINSIC/EXTERNAL explicit. */
name|bool
name|namelisted
decl_stmt|;
comment|/* TRUE if in NAMELIST (needs static alloc). */
name|bool
name|assigned
decl_stmt|;
comment|/* TRUE if ever ASSIGNed to.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ffesymbol_accretes
parameter_list|(
name|s
parameter_list|)
value|((s)->accretes)
end_define

begin_define
define|#
directive|define
name|ffesymbol_accretion
parameter_list|(
name|s
parameter_list|)
value|((s)->accretion)
end_define

begin_define
define|#
directive|define
name|ffesymbol_arraysize
parameter_list|(
name|s
parameter_list|)
value|((s)->array_size)
end_define

begin_define
define|#
directive|define
name|ffesymbol_assigned
parameter_list|(
name|s
parameter_list|)
value|((s)->assigned)
end_define

begin_define
define|#
directive|define
name|ffesymbol_attr
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->attrs& ((ffesymbolAttrs) 1<< (a)))
end_define

begin_define
define|#
directive|define
name|ffesymbol_attrs
parameter_list|(
name|s
parameter_list|)
value|((s)->attrs)
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|ffesymbol_attrs_string
parameter_list|(
name|ffesymbolAttrs
name|attrs
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_basictype
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_basictype((s)->info)
end_define

begin_function_decl
name|void
name|ffesymbol_check
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|,
name|bool
name|maybe_intrin
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_common
parameter_list|(
name|s
parameter_list|)
value|((s)->common)
end_define

begin_define
define|#
directive|define
name|ffesymbol_commonlist
parameter_list|(
name|s
parameter_list|)
value|((s)->common_list)
end_define

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_blockdataunit
parameter_list|(
name|ffelexToken
name|t
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
name|ffesymbol
name|ffesymbol_declare_cblock
parameter_list|(
name|ffelexToken
name|t
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
name|ffesymbol
name|ffesymbol_declare_funcnotresunit
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_funcresult
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_funcunit
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_local
parameter_list|(
name|ffelexToken
name|t
parameter_list|,
name|bool
name|maybe_intrin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_programunit
parameter_list|(
name|ffelexToken
name|t
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
name|ffesymbol
name|ffesymbol_declare_sfdummy
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffesymbol_declare_subrunit
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_dims
parameter_list|(
name|s
parameter_list|)
value|((s)->dims)
end_define

begin_define
define|#
directive|define
name|ffesymbol_dim_syms
parameter_list|(
name|s
parameter_list|)
value|((s)->dim_syms)
end_define

begin_function_decl
name|void
name|ffesymbol_drive
parameter_list|(
name|ffesymbol
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffesymbol
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_drive_sfnames
parameter_list|(
name|ffesymbol
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|ffesymbol
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_dummyargs
parameter_list|(
name|s
parameter_list|)
value|((s)->dummy_args)
end_define

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetFFE
end_if

begin_function_decl
name|void
name|ffesymbol_dump
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffesymbol_error
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_equiv
parameter_list|(
name|s
parameter_list|)
value|((s)->equiv)
end_define

begin_define
define|#
directive|define
name|ffesymbol_explicitwhere
parameter_list|(
name|s
parameter_list|)
value|((s)->explicit_where)
end_define

begin_define
define|#
directive|define
name|ffesymbol_extents
parameter_list|(
name|s
parameter_list|)
value|((s)->extents)
end_define

begin_define
define|#
directive|define
name|ffesymbol_first_token
parameter_list|(
name|s
parameter_list|)
value|((s)->name == NULL ? NULL  \       : ffename_first_token((s)->name))
end_define

begin_define
define|#
directive|define
name|ffesymbol_funcresult
parameter_list|(
name|s
parameter_list|)
value|((s)->func_result)
end_define

begin_define
define|#
directive|define
name|ffesymbol_generic
parameter_list|(
name|s
parameter_list|)
value|((s)->generic)
end_define

begin_define
define|#
directive|define
name|ffesymbol_global
parameter_list|(
name|s
parameter_list|)
value|((s)->global)
end_define

begin_define
define|#
directive|define
name|ffesymbol_hook
parameter_list|(
name|s
parameter_list|)
value|((s)->hook)
end_define

begin_define
define|#
directive|define
name|ffesymbol_implementation
parameter_list|(
name|s
parameter_list|)
value|((s)->implementation)
end_define

begin_define
define|#
directive|define
name|ffesymbol_info
parameter_list|(
name|s
parameter_list|)
value|((s)->info)
end_define

begin_define
define|#
directive|define
name|ffesymbol_init
parameter_list|(
name|s
parameter_list|)
value|((s)->init)
end_define

begin_function_decl
name|void
name|ffesymbol_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_init_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_init_4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_is_doiter
parameter_list|(
name|s
parameter_list|)
value|((s)->do_iter)
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_dualspace
parameter_list|(
name|s
parameter_list|)
value|((s)->other_space_name != NULL)
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_f2c
parameter_list|(
name|s
parameter_list|)
value|(ffe_is_f2c())
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_init
parameter_list|(
name|s
parameter_list|)
value|((s)->is_init)
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_reported
parameter_list|(
name|s
parameter_list|)
value|((s)->reported)
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_save
parameter_list|(
name|s
parameter_list|)
value|((s)->is_save)
end_define

begin_define
define|#
directive|define
name|ffesymbol_is_specable
parameter_list|(
name|s
parameter_list|)
value|ffesymbol_state_is_specable(s->state)
end_define

begin_define
define|#
directive|define
name|ffesymbol_kindtype
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_kindtype((s)->info)
end_define

begin_define
define|#
directive|define
name|ffesymbol_kind
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_kind((s)->info)
end_define

begin_function_decl
name|ffesymbol
name|ffesymbol_lookup_local
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_maxentrynum
parameter_list|(
name|s
parameter_list|)
value|((s)->max_entry_num)
end_define

begin_define
define|#
directive|define
name|ffesymbol_name
parameter_list|(
name|s
parameter_list|)
value|((s)->name)
end_define

begin_define
define|#
directive|define
name|ffesymbol_namelist
parameter_list|(
name|s
parameter_list|)
value|((s)->namelist)
end_define

begin_define
define|#
directive|define
name|ffesymbol_namelisted
parameter_list|(
name|s
parameter_list|)
value|((s)->namelisted)
end_define

begin_define
define|#
directive|define
name|ffesymbol_numentries
parameter_list|(
name|s
parameter_list|)
value|((s)->num_entries)
end_define

begin_define
define|#
directive|define
name|ffesymbol_ptr_to_commonlist
parameter_list|(
name|s
parameter_list|)
value|(&(s)->common_list)
end_define

begin_define
define|#
directive|define
name|ffesymbol_ptr_to_listbottom
parameter_list|(
name|s
parameter_list|)
value|(&(s)->list_bottom)
end_define

begin_define
define|#
directive|define
name|ffesymbol_ptr_to_namelist
parameter_list|(
name|s
parameter_list|)
value|(&(s)->namelist)
end_define

begin_define
define|#
directive|define
name|ffesymbol_rank
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_rank((s)->info)
end_define

begin_function_decl
name|void
name|ffesymbol_reference
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

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetFFE
end_if

begin_function_decl
name|ffesymbol
name|ffesymbol_report
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_report_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|ffesymbol_resolve_intrin
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_retract
parameter_list|(
name|bool
name|retract
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffesymbol_retractable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_set_accretes
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
name|ffesymbol_set_accretion
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
name|ffesymbol_set_arraysize
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->array_size = (a))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_assigned
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->assigned = (a))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_attr
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->attrs |= ((ffesymbolAttrs) 1<< (a)))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_attrs
parameter_list|(
name|s
parameter_list|,
name|a
parameter_list|)
value|((s)->attrs = (a))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_common
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|((s)->common = (c))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_commonlist
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|((s)->common_list = (c))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_dims
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|((s)->dims = (d))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_dim_syms
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|((s)->dim_syms = (d))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_dummyargs
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|((s)->dummy_args = (d))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_equiv
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|((s)->equiv = (e))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_explicitwhere
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|((s)->explicit_where = (e))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_extents
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|((s)->extents = (e))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_funcresult
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|((s)->func_result = (f))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_generic
parameter_list|(
name|s
parameter_list|,
name|g
parameter_list|)
value|((s)->generic = (g))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_global
parameter_list|(
name|s
parameter_list|,
name|g
parameter_list|)
value|((s)->global = (g))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_hook
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
name|ffesymbol_set_implementation
parameter_list|(
name|s
parameter_list|,
name|im
parameter_list|)
value|((s)->implementation = (im))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_init
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
name|ffesymbol_set_info
parameter_list|(
name|s
parameter_list|,
name|i
parameter_list|)
value|((s)->info = (i))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_is_doiter
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|((s)->do_iter = (f))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_is_init
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
name|ffesymbol_set_is_save
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
name|ffesymbol_set_maxentrynum
parameter_list|(
name|s
parameter_list|,
name|m
parameter_list|)
value|((s)->max_entry_num = (m))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_namelist
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((s)->namelist = (n))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_namelisted
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((s)->namelisted = (n))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_numentries
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((s)->num_entries = (n))
end_define

begin_function_decl
name|void
name|ffesymbol_set_retractable
parameter_list|(
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_set_sfexpr
parameter_list|(
name|s
parameter_list|,
name|e
parameter_list|)
value|((s)->sfunc_expr = (e))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_specific
parameter_list|(
name|s
parameter_list|,
name|sp
parameter_list|)
value|((s)->specific = (sp))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_state
parameter_list|(
name|s
parameter_list|,
name|st
parameter_list|)
value|((s)->state = (st))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_storage
parameter_list|(
name|s
parameter_list|,
name|st
parameter_list|)
value|((s)->storage = (st))
end_define

begin_define
define|#
directive|define
name|ffesymbol_set_value
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s)->value = (v))
end_define

begin_define
define|#
directive|define
name|ffesymbol_sfdummyparent
parameter_list|(
name|s
parameter_list|)
value|((s)->sfa_dummy_parent)
end_define

begin_define
define|#
directive|define
name|ffesymbol_sfexpr
parameter_list|(
name|s
parameter_list|)
value|((s)->sfunc_expr)
end_define

begin_function_decl
name|void
name|ffesymbol_signal_change
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_signal_unreported
parameter_list|(
name|s
parameter_list|)
value|((s)->reported = FALSE)
end_define

begin_define
define|#
directive|define
name|ffesymbol_size
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_size((s)->info)
end_define

begin_define
define|#
directive|define
name|ffesymbol_specific
parameter_list|(
name|s
parameter_list|)
value|((s)->specific)
end_define

begin_define
define|#
directive|define
name|ffesymbol_state
parameter_list|(
name|s
parameter_list|)
value|((s)->state)
end_define

begin_define
define|#
directive|define
name|ffesymbol_state_is_specable
parameter_list|(
name|s
parameter_list|)
value|((s)<= FFESYMBOL_stateSEEN)
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|ffesymbol_state_string
parameter_list|(
name|ffesymbolState
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_storage
parameter_list|(
name|s
parameter_list|)
value|((s)->storage)
end_define

begin_function_decl
name|void
name|ffesymbol_terminate_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_terminate_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_terminate_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_terminate_3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_terminate_4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_text
parameter_list|(
name|s
parameter_list|)
value|(((s)->name == NULL) ? "<->" : ffename_text((s)->name))
end_define

begin_function_decl
name|void
name|ffesymbol_update_init
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffesymbol_update_save
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesymbol_value
parameter_list|(
name|s
parameter_list|)
value|((s)->value)
end_define

begin_define
define|#
directive|define
name|ffesymbol_where
parameter_list|(
name|s
parameter_list|)
value|ffeinfo_where((s)->info)
end_define

begin_define
define|#
directive|define
name|ffesymbol_where_column
parameter_list|(
name|s
parameter_list|)
value|(((s)->name == NULL)	\       ? ffewhere_column_unknown() : ffename_where_column((s)->name))
end_define

begin_define
define|#
directive|define
name|ffesymbol_where_filename
parameter_list|(
name|s
parameter_list|)
define|\
value|ffewhere_line_filename(ffesymbol_where_line(s))
end_define

begin_define
define|#
directive|define
name|ffesymbol_where_filelinenum
parameter_list|(
name|s
parameter_list|)
define|\
value|ffewhere_line_filelinenum(ffesymbol_where_line(s))
end_define

begin_define
define|#
directive|define
name|ffesymbol_where_line
parameter_list|(
name|s
parameter_list|)
value|(((s)->name == NULL) ? ffewhere_line_unknown() \       : ffename_where_line((s)->name))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

