begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* com.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995-1997 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       com.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_com
end_ifndef

begin_define
define|#
directive|define
name|_H_f_com
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_define
define|#
directive|define
name|FFECOM_dimensionsMAX
value|7
end_define

begin_comment
comment|/* Max # dimensions (quick hack). */
end_comment

begin_define
define|#
directive|define
name|FFECOM_targetFFE
value|1
end_define

begin_define
define|#
directive|define
name|FFECOM_targetGCC
value|2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FFE_STANDALONE
end_ifndef

begin_define
define|#
directive|define
name|FFECOM_targetCURRENT
value|FFECOM_targetGCC
end_define

begin_comment
comment|/* Backend! */
end_comment

begin_define
define|#
directive|define
name|FFECOM_ONEPASS
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FFECOM_targetCURRENT
value|FFECOM_targetFFE
end_define

begin_define
define|#
directive|define
name|FFECOM_ONEPASS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFECOM_ONEPASS
end_if

begin_define
define|#
directive|define
name|FFECOM_TWOPASS
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FFECOM_TWOPASS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FFECOM_SIZE_UNIT
value|"byte"
end_define

begin_comment
comment|/* Singular form. */
end_comment

begin_define
define|#
directive|define
name|FFECOM_SIZE_UNITS
value|"bytes"
end_define

begin_comment
comment|/* Plural form. */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_define
define|#
directive|define
name|FFECOM_constantNULL
value|NULL_TREE
end_define

begin_define
define|#
directive|define
name|FFECOM_nonterNULL
value|NULL_TREE
end_define

begin_define
define|#
directive|define
name|FFECOM_globalNULL
value|NULL_TREE
end_define

begin_define
define|#
directive|define
name|FFECOM_labelNULL
value|NULL_TREE
end_define

begin_define
define|#
directive|define
name|FFECOM_storageNULL
value|NULL_TREE
end_define

begin_define
define|#
directive|define
name|FFECOM_symbolNULL
value|ffecom_symbol_null_
end_define

begin_comment
comment|/* Shorthand for types used in f2c.h and that g77 perhaps allows some    flexibility regarding in the section below.  I.e. the actual numbers    below aren't important, as long as they're unique.  */
end_comment

begin_define
define|#
directive|define
name|FFECOM_f2ccodeCHAR
value|1
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeSHORT
value|2
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeINT
value|3
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeLONG
value|4
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeLONGLONG
value|5
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeCHARPTR
value|6
end_define

begin_comment
comment|/* char * */
end_comment

begin_define
define|#
directive|define
name|FFECOM_f2ccodeFLOAT
value|7
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeDOUBLE
value|8
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeLONGDOUBLE
value|9
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeTWOREALS
value|10
end_define

begin_define
define|#
directive|define
name|FFECOM_f2ccodeTWODOUBLEREALS
value|11
end_define

begin_if
if|#
directive|if
name|FFECOM_DETERMINE_TYPES
end_if

begin_comment
comment|/* only for com.c and configure */
end_comment

begin_comment
comment|/* Begin f2c.h information.  This must match the info in the f2c.h used    to build the libf2c with which g77-generated code is linked, or there    will probably be bugs, some of them difficult to detect or even trigger.  */
end_comment

begin_comment
comment|/* Do we need int (for 32-bit or 64-bit systems) or long (16-bit or    normally 32-bit) for f2c-type integers? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BITS_PER_WORD
end_ifndef

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|CHAR_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|(BITS_PER_UNIT * MIN ((UNITS_PER_WORD + 1) / 2, 2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_LONG_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_UNSIGNED
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LONG_TYPE_SIZE
operator|==
name|FLOAT_TYPE_SIZE
end_if

begin_define
define|#
directive|define
name|FFECOM_f2cINTEGER
value|FFECOM_f2ccodeLONG
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cLOGICAL
value|FFECOM_f2ccodeLONG
end_define

begin_elif
elif|#
directive|elif
name|INT_TYPE_SIZE
operator|==
name|FLOAT_TYPE_SIZE
end_elif

begin_define
define|#
directive|define
name|FFECOM_f2cINTEGER
value|FFECOM_f2ccodeINT
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cLOGICAL
value|FFECOM_f2ccodeINT
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Cannot find a suitable type for FFECOM_f2cINTEGER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LONG_TYPE_SIZE
operator|==
operator|(
name|FLOAT_TYPE_SIZE
operator|*
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|FFECOM_f2cLONGINT
value|FFECOM_f2ccodeLONG
end_define

begin_elif
elif|#
directive|elif
name|LONG_LONG_TYPE_SIZE
operator|==
operator|(
name|FLOAT_TYPE_SIZE
operator|*
literal|2
operator|)
end_elif

begin_define
define|#
directive|define
name|FFECOM_f2cLONGINT
value|FFECOM_f2ccodeLONGLONG
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Cannot find a suitable type for FFECOM_f2cLONGINT
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FFECOM_f2cADDRESS
value|FFECOM_f2ccodeCHARPTR
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cSHORTINT
value|FFECOM_f2ccodeSHORT
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cREAL
value|FFECOM_f2ccodeFLOAT
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cDOUBLEREAL
value|FFECOM_f2ccodeDOUBLE
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cCOMPLEX
value|FFECOM_f2ccodeTWOREALS
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cDOUBLECOMPLEX
value|FFECOM_f2ccodeTWODOUBLEREALS
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cSHORTLOGICAL
value|FFECOM_f2ccodeSHORT
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cLOGICAL1
value|FFECOM_f2ccodeCHAR
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cINTEGER1
value|FFECOM_f2ccodeCHAR
end_define

begin_comment
comment|/* These must be f2c's INTEGER type, to match runtime/f2c.h.in.  */
end_comment

begin_define
define|#
directive|define
name|FFECOM_f2cFLAG
value|FFECOM_f2cINTEGER
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cFTNINT
value|FFECOM_f2cINTEGER
end_define

begin_define
define|#
directive|define
name|FFECOM_f2cFTNLEN
value|FFECOM_f2cINTEGER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if FFECOM_DETERMINE_TYPES */
end_comment

begin_comment
comment|/* Everything else in f2c.h, specifically the structures used in    interfacing compiled code with the library, must remain exactly    as delivered, or g77 internals (mostly com.c and ste.c) must    be modified accordingly to compensate.  Or there will be...trouble.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|DEFGFRT
parameter_list|(
name|CODE
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|,
name|ARGS
parameter_list|,
name|VOLATILE
parameter_list|,
name|COMPLEX
parameter_list|)
value|CODE,
include|#
directive|include
file|"com-rt.def"
undef|#
directive|undef
name|DEFGFRT
name|FFECOM_gfrt
block|}
name|ffecomGfrt
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_comment
comment|/* Typedefs. */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|TREE_CODE
end_ifndef

begin_include
include|#
directive|include
file|"tree.j"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUILT_FOR_270
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_STATIC_CONSTRUCTOR
end_ifdef

begin_comment
comment|/* In gcc/tree.h. */
end_comment

begin_define
define|#
directive|define
name|BUILT_FOR_270
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUILT_FOR_270
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (BUILT_FOR_270) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUILT_FOR_280
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DECL_ONE_ONLY
end_ifdef

begin_comment
comment|/* In gcc/tree.h. */
end_comment

begin_define
define|#
directive|define
name|BUILT_FOR_280
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUILT_FOR_280
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (BUILT_FOR_280) */
end_comment

begin_typedef
typedef|typedef
name|tree
name|ffecomConstant
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_constantHOOK
end_define

begin_typedef
typedef|typedef
name|tree
name|ffecomNonter
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_nonterHOOK
end_define

begin_typedef
typedef|typedef
name|tree
name|ffecomLabel
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_globalHOOK
end_define

begin_typedef
typedef|typedef
name|tree
name|ffecomGlobal
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_labelHOOK
end_define

begin_typedef
typedef|typedef
name|tree
name|ffecomStorage
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_storageHOOK
end_define

begin_typedef
typedef|typedef
name|struct
name|_ffecom_symbol_
name|ffecomSymbol
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FFECOM_symbolHOOK
end_define

begin_struct
struct|struct
name|_ffecom_symbol_
block|{
name|tree
name|decl_tree
decl_stmt|;
name|tree
name|length_tree
decl_stmt|;
comment|/* For CHARACTER dummies. */
name|tree
name|vardesc_tree
decl_stmt|;
comment|/* For NAMELIST. */
name|tree
name|assign_tree
decl_stmt|;
comment|/* For ASSIGN'ed vars. */
name|bool
name|addr
decl_stmt|;
comment|/* Is address of item instead of item. */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
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
file|"info.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
end_include

begin_include
include|#
directive|include
file|"storag.h"
end_include

begin_include
include|#
directive|include
file|"symbol.h"
end_include

begin_comment
comment|/* Structure definitions. */
end_comment

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_decl_stmt
specifier|extern
name|tree
name|long_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|complex_double_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|string_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_integer_zero_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_integer_one_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_tree_type
index|[
name|FFEINFO_basictype
index|]
index|[
name|FFEINFO_kindtype
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffecomSymbol
name|ffecom_symbol_null_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeinfoKindtype
name|ffecom_pointer_kind_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffeinfoKindtype
name|ffecom_label_kind_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ffecom_f2c_typecode_
index|[
name|FFEINFO_basictype
index|]
index|[
name|FFEINFO_kindtype
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_integer_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_address_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_real_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_doublereal_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_complex_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_doublecomplex_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_longint_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_logical_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_flag_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ftnlen_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ftnlen_zero_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ftnlen_one_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ftnlen_two_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ptr_to_ftnlen_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ftnint_type_node
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|ffecom_f2c_ptr_to_ftnint_type_node
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|tree
name|ffecom_1
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|,
name|tree
name|type
parameter_list|,
name|tree
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_1_fn
parameter_list|(
name|tree
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_2
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|,
name|tree
name|type
parameter_list|,
name|tree
name|node1
parameter_list|,
name|tree
name|node2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffecom_2pass_advise_entrypoint
parameter_list|(
name|ffesymbol
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_2pass_do_entrypoint
parameter_list|(
name|ffesymbol
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_2s
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|,
name|tree
name|type
parameter_list|,
name|tree
name|node1
parameter_list|,
name|tree
name|node2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_3
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|,
name|tree
name|type
parameter_list|,
name|tree
name|node1
parameter_list|,
name|tree
name|node2
parameter_list|,
name|tree
name|node3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_3s
parameter_list|(
name|enum
name|tree_code
name|code
parameter_list|,
name|tree
name|type
parameter_list|,
name|tree
name|node1
parameter_list|,
name|tree
name|node2
parameter_list|,
name|tree
name|node3
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_arg_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|tree
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_arg_ptr_to_const_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|tree
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_arg_ptr_to_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|tree
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_call_gfrt
parameter_list|(
name|ffecomGfrt
name|ix
parameter_list|,
name|tree
name|args
parameter_list|,
name|tree
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_constantunion
parameter_list|(
name|ffebldConstantUnion
modifier|*
name|cu
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|tree
name|tree_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_const_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_decl_field
parameter_list|(
name|tree
name|context
parameter_list|,
name|tree
name|prevfield
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|tree
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_function_decl
name|void
name|ffecom_close_include
parameter_list|(
name|FILE
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffecom_decode_include_option
parameter_list|(
name|char
modifier|*
name|spec
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|tree
name|ffecom_end_compstmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_function_decl
name|void
name|ffecom_end_transition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_exec_transition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_expand_let_stmt
parameter_list|(
name|ffebld
name|dest
parameter_list|,
name|ffebld
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|tree
name|ffecom_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_expr_assign
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_expr_assign_w
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_expr_rw
parameter_list|(
name|tree
name|type
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_expr_w
parameter_list|(
name|tree
name|type
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_finish_compile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_finish_decl
parameter_list|(
name|tree
name|decl
parameter_list|,
name|tree
name|init
parameter_list|,
name|bool
name|is_top_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_finish_progunit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_get_invented_identifier
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|number
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfoKindtype
name|ffecom_gfrt_basictype
parameter_list|(
name|ffecomGfrt
name|ix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffeinfoKindtype
name|ffecom_gfrt_kindtype
parameter_list|(
name|ffecomGfrt
name|ix
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_list_expr
parameter_list|(
name|ffebld
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_list_ptr_to_expr
parameter_list|(
name|ffebld
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_lookup_label
parameter_list|(
name|ffelab
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_make_tempvar
parameter_list|(
specifier|const
name|char
modifier|*
name|commentary
parameter_list|,
name|tree
name|type
parameter_list|,
name|ffetargetCharacterSize
name|size
parameter_list|,
name|int
name|elements
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_modify
parameter_list|(
name|tree
name|newtype
parameter_list|,
name|tree
name|lhs
parameter_list|,
name|tree
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_function_decl
name|void
name|ffecom_file
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_notify_init_storage
parameter_list|(
name|ffestorag
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_notify_init_symbol
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_notify_primary_entry
parameter_list|(
name|ffesymbol
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|ffecom_open_include
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|ffewhereLine
name|l
parameter_list|,
name|ffewhereColumn
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|void
name|ffecom_prepare_arg_ptr_to_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffecom_prepare_end
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_prepare_expr_
parameter_list|(
name|ffebld
name|expr
parameter_list|,
name|ffebld
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_prepare_expr_rw
parameter_list|(
name|tree
name|type
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_prepare_expr_w
parameter_list|(
name|tree
name|type
parameter_list|,
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_prepare_ptr_to_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_prepare_return_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_ptr_to_const_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_ptr_to_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_return_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_save_tree
parameter_list|(
name|tree
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_start_compstmt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_start_decl
parameter_list|(
name|tree
name|decl
parameter_list|,
name|bool
name|is_init
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffecom_sym_commit
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

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_function_decl
name|ffesymbol
name|ffecom_sym_end_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffecom_sym_exec_transition
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffesymbol
name|ffecom_sym_learned
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_function_decl
name|void
name|ffecom_sym_retract
parameter_list|(
name|ffesymbol
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_temp_label
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_truth_value
parameter_list|(
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_truth_value_invert
parameter_list|(
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_type_expr
parameter_list|(
name|ffebld
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|ffecom_which_entrypoint_decl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* These need to be in the front end with exactly these interfaces,    as they're called by the back end.  */
end_comment

begin_function_decl
name|int
name|mark_addressable
parameter_list|(
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_comment
comment|/* Define macros. */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetFFE
end_if

begin_define
define|#
directive|define
name|ffecom_expr
parameter_list|(
name|e
parameter_list|)
value|(e)
end_define

begin_define
define|#
directive|define
name|ffecom_init_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_label_kind
parameter_list|()
value|FFEINFO_kindtypeINTEGERDEFAULT
end_define

begin_define
define|#
directive|define
name|ffecom_pointer_kind
parameter_list|()
value|FFEINFO_kindtypeINTEGERDEFAULT
end_define

begin_define
define|#
directive|define
name|ffecom_ptr_to_expr
parameter_list|(
name|e
parameter_list|)
value|(e)
end_define

begin_define
define|#
directive|define
name|ffecom_sym_commit
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ffecom_sym_retract
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetFFE */
end_comment

begin_if
if|#
directive|if
name|FFECOM_targetCURRENT
operator|==
name|FFECOM_targetGCC
end_if

begin_define
define|#
directive|define
name|ffecom_f2c_typecode
parameter_list|(
name|bt
parameter_list|,
name|kt
parameter_list|)
value|ffecom_f2c_typecode_[(bt)][(kt)]
end_define

begin_define
define|#
directive|define
name|ffecom_label_kind
parameter_list|()
value|ffecom_label_kind_
end_define

begin_define
define|#
directive|define
name|ffecom_pointer_kind
parameter_list|()
value|ffecom_pointer_kind_
end_define

begin_define
define|#
directive|define
name|ffecom_prepare_expr
parameter_list|(
name|e
parameter_list|)
value|ffecom_prepare_expr_ ((e), NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FFECOM_targetCURRENT == FFECOM_targetGCC */
end_comment

begin_define
define|#
directive|define
name|ffecom_init_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffecom_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

