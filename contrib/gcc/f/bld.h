begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bld.h -- Public #include File (module.h template V1.0)    Copyright (C) 1995, 1996, 2003 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       bld.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_BLD_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_BLD_H
end_define

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FFEBLD_constNONE
block|,
name|FFEBLD_constINTEGER1
block|,
name|FFEBLD_constINTEGER2
block|,
name|FFEBLD_constINTEGER3
block|,
name|FFEBLD_constINTEGER4
block|,
name|FFEBLD_constINTEGER5
block|,
name|FFEBLD_constINTEGER6
block|,
name|FFEBLD_constINTEGER7
block|,
name|FFEBLD_constINTEGER8
block|,
name|FFEBLD_constLOGICAL1
block|,
name|FFEBLD_constLOGICAL2
block|,
name|FFEBLD_constLOGICAL3
block|,
name|FFEBLD_constLOGICAL4
block|,
name|FFEBLD_constLOGICAL5
block|,
name|FFEBLD_constLOGICAL6
block|,
name|FFEBLD_constLOGICAL7
block|,
name|FFEBLD_constLOGICAL8
block|,
name|FFEBLD_constREAL1
block|,
name|FFEBLD_constREAL2
block|,
name|FFEBLD_constREAL3
block|,
name|FFEBLD_constREAL4
block|,
name|FFEBLD_constREAL5
block|,
name|FFEBLD_constREAL6
block|,
name|FFEBLD_constREAL7
block|,
name|FFEBLD_constREAL8
block|,
name|FFEBLD_constCOMPLEX1
block|,
name|FFEBLD_constCOMPLEX2
block|,
name|FFEBLD_constCOMPLEX3
block|,
name|FFEBLD_constCOMPLEX4
block|,
name|FFEBLD_constCOMPLEX5
block|,
name|FFEBLD_constCOMPLEX6
block|,
name|FFEBLD_constCOMPLEX7
block|,
name|FFEBLD_constCOMPLEX8
block|,
name|FFEBLD_constCHARACTER1
block|,
name|FFEBLD_constCHARACTER2
block|,
name|FFEBLD_constCHARACTER3
block|,
name|FFEBLD_constCHARACTER4
block|,
name|FFEBLD_constCHARACTER5
block|,
name|FFEBLD_constCHARACTER6
block|,
name|FFEBLD_constCHARACTER7
block|,
name|FFEBLD_constCHARACTER8
block|,
name|FFEBLD_constHOLLERITH
block|,
name|FFEBLD_constTYPELESS_FIRST
block|,
name|FFEBLD_constBINARY_MIL
init|=
name|FFEBLD_constTYPELESS_FIRST
block|,
name|FFEBLD_constBINARY_VXT
block|,
name|FFEBLD_constOCTAL_MIL
block|,
name|FFEBLD_constOCTAL_VXT
block|,
name|FFEBLD_constHEX_X_MIL
block|,
name|FFEBLD_constHEX_X_VXT
block|,
name|FFEBLD_constHEX_Z_MIL
block|,
name|FFEBLD_constHEX_Z_VXT
block|,
name|FFEBLD_constTYPELESS_LAST
init|=
name|FFEBLD_constHEX_Z_VXT
block|,
name|FFEBLD_const
block|}
name|ffebldConst
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|FFEBLD_OP
parameter_list|(
name|KWD
parameter_list|,
name|NAME
parameter_list|,
name|ARITY
parameter_list|)
value|KWD,
include|#
directive|include
file|"bld-op.def"
undef|#
directive|undef
name|FFEBLD_OP
name|FFEBLD_op
block|}
name|ffebldOp
typedef|;
end_typedef

begin_comment
comment|/* Typedefs. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ffebld_
modifier|*
name|ffebld
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ffebldArity
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|_ffebld_constant_array_
name|ffebldConstantArray
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ffebld_constant_
modifier|*
name|ffebldConstant
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|_ffebld_constant_union_
name|ffebldConstantUnion
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ffebld
modifier|*
name|ffebldListBottom
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ffebldListLength
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ffebldListLength_f
value|""
end_define

begin_typedef
typedef|typedef
name|struct
name|_ffebld_pool_stack_
modifier|*
name|ffebldPoolstack_
typedef|;
end_typedef

begin_comment
comment|/* Include files needed by this one. */
end_comment

begin_include
include|#
directive|include
file|"bit.h"
end_include

begin_include
include|#
directive|include
file|"com.h"
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
file|"lab.h"
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
file|"symbol.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_define
define|#
directive|define
name|FFEBLD_whereconstPROGUNIT_
value|1
end_define

begin_define
define|#
directive|define
name|FFEBLD_whereconstFILE_
value|2
end_define

begin_define
define|#
directive|define
name|FFEBLD_whereconstCURRENT_
value|FFEBLD_whereconstFILE_
end_define

begin_comment
comment|/* Structure definitions. */
end_comment

begin_define
define|#
directive|define
name|FFEBLD_constINTEGERDEFAULT
value|FFEBLD_constINTEGER1
end_define

begin_define
define|#
directive|define
name|FFEBLD_constLOGICALDEFAULT
value|FFEBLD_constLOGICAL1
end_define

begin_define
define|#
directive|define
name|FFEBLD_constREALDEFAULT
value|FFEBLD_constREAL1
end_define

begin_define
define|#
directive|define
name|FFEBLD_constREALDOUBLE
value|FFEBLD_constREAL2
end_define

begin_define
define|#
directive|define
name|FFEBLD_constREALQUAD
value|FFEBLD_constREAL3
end_define

begin_define
define|#
directive|define
name|FFEBLD_constCOMPLEX
value|FFEBLD_constCOMPLEX1
end_define

begin_define
define|#
directive|define
name|FFEBLD_constCOMPLEXDOUBLE
value|FFEBLD_constCOMPLEX2
end_define

begin_define
define|#
directive|define
name|FFEBLD_constCOMPLEXQUAD
value|FFEBLD_constCOMPLEX3
end_define

begin_define
define|#
directive|define
name|FFEBLD_constCHARACTERDEFAULT
value|FFEBLD_constCHARACTER1
end_define

begin_union
union|union
name|_ffebld_constant_union_
block|{
name|ffetargetTypeless
name|typeless
decl_stmt|;
name|ffetargetHollerith
name|hollerith
decl_stmt|;
if|#
directive|if
name|FFETARGET_okINTEGER1
name|ffetargetInteger1
name|integer1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER2
name|ffetargetInteger2
name|integer2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER3
name|ffetargetInteger3
name|integer3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER4
name|ffetargetInteger4
name|integer4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL1
name|ffetargetLogical1
name|logical1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL2
name|ffetargetLogical2
name|logical2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL3
name|ffetargetLogical3
name|logical3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL4
name|ffetargetLogical4
name|logical4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL1
name|ffetargetReal1
name|real1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL2
name|ffetargetReal2
name|real2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL3
name|ffetargetReal3
name|real3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX1
name|ffetargetComplex1
name|complex1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX2
name|ffetargetComplex2
name|complex2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX3
name|ffetargetComplex3
name|complex3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCHARACTER1
name|ffetargetCharacter1
name|character1
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_union
union|union
name|_ffebld_constant_array_
block|{
if|#
directive|if
name|FFETARGET_okINTEGER1
name|ffetargetInteger1
modifier|*
name|integer1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER2
name|ffetargetInteger2
modifier|*
name|integer2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER3
name|ffetargetInteger3
modifier|*
name|integer3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okINTEGER4
name|ffetargetInteger4
modifier|*
name|integer4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL1
name|ffetargetLogical1
modifier|*
name|logical1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL2
name|ffetargetLogical2
modifier|*
name|logical2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL3
name|ffetargetLogical3
modifier|*
name|logical3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okLOGICAL4
name|ffetargetLogical4
modifier|*
name|logical4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL1
name|ffetargetReal1
modifier|*
name|real1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL2
name|ffetargetReal2
modifier|*
name|real2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okREAL3
name|ffetargetReal3
modifier|*
name|real3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX1
name|ffetargetComplex1
modifier|*
name|complex1
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX2
name|ffetargetComplex2
modifier|*
name|complex2
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCOMPLEX3
name|ffetargetComplex3
modifier|*
name|complex3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|FFETARGET_okCHARACTER1
name|ffetargetCharacterUnit1
modifier|*
name|character1
decl_stmt|;
endif|#
directive|endif
block|}
union|;
end_union

begin_struct
struct|struct
name|_ffebld_
block|{
name|ffebldOp
name|op
decl_stmt|;
name|ffeinfo
name|info
decl_stmt|;
comment|/* Not used or valid for 				   op=={STAR,ITEM,BOUNDS,REPEAT,LABTER, 				   LABTOK,IMPDO}. */
union|union
block|{
struct|struct
block|{
name|ffebld
name|left
decl_stmt|;
name|ffebld
name|right
decl_stmt|;
name|ffecomNonter
name|hook
decl_stmt|;
comment|/* Whatever the compiler/backend wants! */
block|}
name|nonter
struct|;
struct|struct
block|{
name|ffebld
name|head
decl_stmt|;
name|ffebld
name|trail
decl_stmt|;
block|}
name|item
struct|;
struct|struct
block|{
name|ffebldConstant
name|expr
decl_stmt|;
name|ffebld
name|orig
decl_stmt|;
comment|/* Original expression, or NULL if none. */
name|ffetargetAlign
name|pad
decl_stmt|;
comment|/* Initial padding (for DATA, etc.). */
block|}
name|conter
struct|;
struct|struct
block|{
name|ffebldConstantArray
name|array
decl_stmt|;
name|ffetargetOffset
name|size
decl_stmt|;
name|ffetargetAlign
name|pad
decl_stmt|;
comment|/* Initial padding (for DATA, etc.). */
block|}
name|arrter
struct|;
struct|struct
block|{
name|ffebldConstantArray
name|array
decl_stmt|;
name|ffebit
name|bits
decl_stmt|;
name|ffetargetAlign
name|pad
decl_stmt|;
comment|/* Initial padding (for DATA, etc.). */
block|}
name|accter
struct|;
struct|struct
block|{
name|ffesymbol
name|symbol
decl_stmt|;
name|ffeintrinGen
name|generic
decl_stmt|;
comment|/* Id for generic intrinsic. */
name|ffeintrinSpec
name|specific
decl_stmt|;
comment|/* Id for specific intrinsic. */
name|ffeintrinImp
name|implementation
decl_stmt|;
comment|/* Id for implementation. */
name|bool
name|do_iter
decl_stmt|;
comment|/* TRUE if this ref is a read-only ref by 				   definition (ref within DO loop using this 				   var as iterator). */
block|}
name|symter
struct|;
name|ffelab
name|labter
decl_stmt|;
name|ffelexToken
name|labtok
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffebld_constant_
block|{
name|ffebldConstant
name|rlink
decl_stmt|;
name|ffebldConstant
name|llink
decl_stmt|;
name|ffebldConstant
name|first_complex
decl_stmt|;
comment|/* First complex const with me as 					   real. */
name|ffebldConst
name|consttype
decl_stmt|;
name|ffecomConstant
name|hook
decl_stmt|;
comment|/* Whatever the compiler/backend wants! */
name|bool
name|numeric
decl_stmt|;
comment|/* A numeric kind of constant. */
name|ffebldConstantUnion
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_ffebld_pool_stack_
block|{
name|ffebldPoolstack_
name|next
decl_stmt|;
name|mallocPool
name|pool
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global objects accessed by users of this module. */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|ffebldArity
name|ffebld_arity_op_
index|[
operator|(
name|int
operator|)
name|FFEBLD_op
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_ffebld_pool_stack_
name|ffebld_pool_stack_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare functions with prototypes. */
end_comment

begin_function_decl
name|int
name|ffebld_constant_cmp
parameter_list|(
name|ffebldConstant
name|c1
parameter_list|,
name|ffebldConstant
name|c2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffebld_constant_is_magical
parameter_list|(
name|ffebldConstant
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ffebld_constant_is_zero
parameter_list|(
name|ffebldConstant
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okCHARACTER1
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_character1
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_character1_val
parameter_list|(
name|ffetargetCharacter1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX1
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex1
parameter_list|(
name|ffebldConstant
name|real
parameter_list|,
name|ffebldConstant
name|imaginary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex1_val
parameter_list|(
name|ffetargetComplex1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX2
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex2
parameter_list|(
name|ffebldConstant
name|real
parameter_list|,
name|ffebldConstant
name|imaginary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex2_val
parameter_list|(
name|ffetargetComplex2
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okCOMPLEX3
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex3
parameter_list|(
name|ffebldConstant
name|real
parameter_list|,
name|ffebldConstant
name|imaginary
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_complex3_val
parameter_list|(
name|ffetargetComplex3
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_hollerith
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_hollerith_val
parameter_list|(
name|ffetargetHollerith
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER1
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer1
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer1_val
parameter_list|(
name|ffetargetInteger1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER2
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer2
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer2_val
parameter_list|(
name|ffetargetInteger2
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER3
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer3
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer3_val
parameter_list|(
name|ffetargetInteger3
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okINTEGER4
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer4
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integer4_val
parameter_list|(
name|ffetargetInteger4
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integerbinary
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integerhex
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_integeroctal
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL1
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical1
parameter_list|(
name|bool
name|truth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical1_val
parameter_list|(
name|ffetargetLogical1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL2
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical2
parameter_list|(
name|bool
name|truth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical2_val
parameter_list|(
name|ffetargetLogical2
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL3
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical3
parameter_list|(
name|bool
name|truth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical3_val
parameter_list|(
name|ffetargetLogical3
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okLOGICAL4
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical4
parameter_list|(
name|bool
name|truth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_logical4_val
parameter_list|(
name|ffetargetLogical4
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL1
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real1
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real1_val
parameter_list|(
name|ffetargetReal1
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL2
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real2
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real2_val
parameter_list|(
name|ffetargetReal2
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FFETARGET_okREAL3
end_if

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real3
parameter_list|(
name|ffelexToken
name|integer
parameter_list|,
name|ffelexToken
name|decimal
parameter_list|,
name|ffelexToken
name|fraction
parameter_list|,
name|ffelexToken
name|exponent
parameter_list|,
name|ffelexToken
name|exponent_sign
parameter_list|,
name|ffelexToken
name|exponent_digits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_real3_val
parameter_list|(
name|ffetargetReal3
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_bm
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_bv
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_hxm
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_hxv
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_hzm
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_hzv
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_om
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_ov
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_new_typeless_val
parameter_list|(
name|ffebldConst
name|type
parameter_list|,
name|ffetargetTypeless
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstant
name|ffebld_constant_negated
parameter_list|(
name|ffebldConstant
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstantUnion
name|ffebld_constantarray_get
parameter_list|(
name|ffebldConstantArray
name|array
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffetargetOffset
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_constantarray_kill
parameter_list|(
name|ffebldConstantArray
name|array
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffetargetOffset
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldConstantArray
name|ffebld_constantarray_new
parameter_list|(
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffetargetOffset
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_constantarray_prepare
parameter_list|(
name|void
modifier|*
modifier|*
name|aptr
parameter_list|,
name|void
modifier|*
modifier|*
name|cptr
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|ffebldConstantArray
name|array
parameter_list|,
name|ffeinfoBasictype
name|abt
parameter_list|,
name|ffeinfoKindtype
name|akt
parameter_list|,
name|ffetargetOffset
name|offset
parameter_list|,
name|ffebldConstantUnion
modifier|*
name|constant
parameter_list|,
name|ffeinfoBasictype
name|cbt
parameter_list|,
name|ffeinfoKindtype
name|ckt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_constantarray_preparray
parameter_list|(
name|void
modifier|*
modifier|*
name|aptr
parameter_list|,
name|void
modifier|*
modifier|*
name|cptr
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|ffebldConstantArray
name|array
parameter_list|,
name|ffeinfoBasictype
name|abt
parameter_list|,
name|ffeinfoKindtype
name|akt
parameter_list|,
name|ffetargetOffset
name|offset
parameter_list|,
name|ffebldConstantArray
name|source_array
parameter_list|,
name|ffeinfoBasictype
name|cbt
parameter_list|,
name|ffeinfoKindtype
name|ckt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_constantarray_put
parameter_list|(
name|ffebldConstantArray
name|array
parameter_list|,
name|ffeinfoBasictype
name|bt
parameter_list|,
name|ffeinfoKindtype
name|kt
parameter_list|,
name|ffetargetOffset
name|offset
parameter_list|,
name|ffebldConstantUnion
name|constant
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_init_0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_init_2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebldListLength
name|ffebld_list_length
parameter_list|(
name|ffebld
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_accter
parameter_list|(
name|ffebldConstantArray
name|array
parameter_list|,
name|ffebit
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_arrter
parameter_list|(
name|ffebldConstantArray
name|array
parameter_list|,
name|ffetargetOffset
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_conter_with_orig
parameter_list|(
name|ffebldConstant
name|c
parameter_list|,
name|ffebld
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_item
parameter_list|(
name|ffebld
name|head
parameter_list|,
name|ffebld
name|trail
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_labter
parameter_list|(
name|ffelab
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_labtok
parameter_list|(
name|ffelexToken
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_none
parameter_list|(
name|ffebldOp
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_symter
parameter_list|(
name|ffesymbol
name|s
parameter_list|,
name|ffeintrinGen
name|gen
parameter_list|,
name|ffeintrinSpec
name|spec
parameter_list|,
name|ffeintrinImp
name|imp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_one
parameter_list|(
name|ffebldOp
name|o
parameter_list|,
name|ffebld
name|left
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffebld
name|ffebld_new_two
parameter_list|(
name|ffebldOp
name|o
parameter_list|,
name|ffebld
name|left
parameter_list|,
name|ffebld
name|right
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ffebld_op_string
parameter_list|(
name|ffebldOp
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_pool_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ffebld_pool_push
parameter_list|(
name|mallocPool
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ffetargetCharacterSize
name|ffebld_size_max
parameter_list|(
name|ffebld
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Define macros. */
end_comment

begin_define
define|#
directive|define
name|ffebld_accter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.accter.array)
end_define

begin_define
define|#
directive|define
name|ffebld_accter_bits
parameter_list|(
name|b
parameter_list|)
value|((b)->u.accter.bits)
end_define

begin_define
define|#
directive|define
name|ffebld_accter_pad
parameter_list|(
name|b
parameter_list|)
value|((b)->u.accter.pad)
end_define

begin_define
define|#
directive|define
name|ffebld_accter_set_bits
parameter_list|(
name|b
parameter_list|,
name|bt
parameter_list|)
value|((b)->u.accter.bits = (bt))
end_define

begin_define
define|#
directive|define
name|ffebld_accter_set_pad
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->u.accter.pad = (p))
end_define

begin_define
define|#
directive|define
name|ffebld_accter_size
parameter_list|(
name|b
parameter_list|)
value|ffebit_size((b)->u.accter.bits)
end_define

begin_define
define|#
directive|define
name|ffebld_append_item
parameter_list|(
name|b
parameter_list|,
name|i
parameter_list|)
value|(**(b) = ffebld_new_item((i),NULL),	      \ 				 *(b) =&((**(b))->u.item.trail))
end_define

begin_define
define|#
directive|define
name|ffebld_arity
parameter_list|(
name|b
parameter_list|)
value|ffebld_arity_op(ffebld_op(b))
end_define

begin_define
define|#
directive|define
name|ffebld_arity_op
parameter_list|(
name|o
parameter_list|)
value|(ffebld_arity_op_[o])
end_define

begin_define
define|#
directive|define
name|ffebld_arrter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.arrter.array)
end_define

begin_define
define|#
directive|define
name|ffebld_arrter_pad
parameter_list|(
name|b
parameter_list|)
value|((b)->u.arrter.pad)
end_define

begin_define
define|#
directive|define
name|ffebld_arrter_set_pad
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->u.arrter.pad = (p))
end_define

begin_define
define|#
directive|define
name|ffebld_arrter_set_size
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->u.arrter.size = (s))
end_define

begin_define
define|#
directive|define
name|ffebld_arrter_size
parameter_list|(
name|b
parameter_list|)
value|((b)->u.arrter.size)
end_define

begin_define
define|#
directive|define
name|ffebld_basictype
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_basictype (ffebld_info ((b))))
end_define

begin_if
if|#
directive|if
name|FFEBLD_whereconstCURRENT_
operator|==
name|FFEBLD_whereconstPROGUNIT_
end_if

begin_define
define|#
directive|define
name|ffebld_constant_pool
parameter_list|()
value|ffe_pool_program_unit()
end_define

begin_elif
elif|#
directive|elif
name|FFEBLD_whereconstCURRENT_
operator|==
name|FFEBLD_whereconstFILE_
end_elif

begin_define
define|#
directive|define
name|ffebld_constant_pool
parameter_list|()
value|ffe_pool_file()
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ffebld_constant_character1
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character1)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character2
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character2)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character3
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character3)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character4
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character4)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character5
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character5)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character6
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character6)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character7
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character7)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_character8
parameter_list|(
name|c
parameter_list|)
value|((c)->u.character8)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_characterdefault
value|ffebld_constant_character1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex1
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex1)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex2
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex2)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex3
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex3)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex4
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex4)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex5
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex5)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex6
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex6)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex7
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex7)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complex8
parameter_list|(
name|c
parameter_list|)
value|((c)->u.complex8)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complexdefault
value|ffebld_constant_complex1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complexdouble
value|ffebld_constant_complex2
end_define

begin_define
define|#
directive|define
name|ffebld_constant_complexquad
value|ffebld_constant_complex3
end_define

begin_define
define|#
directive|define
name|ffebld_constant_copy
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_hollerith
parameter_list|(
name|c
parameter_list|)
value|((c)->u.hollerith)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_hook
parameter_list|(
name|c
parameter_list|)
value|((c)->hook)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer1
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer1)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer2
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer2)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer3
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer3)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer4
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer4)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer5
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer5)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer6
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer6)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer7
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer7)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integer8
parameter_list|(
name|c
parameter_list|)
value|((c)->u.integer8)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_integerdefault
value|ffebld_constant_integer1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_is_numeric
parameter_list|(
name|c
parameter_list|)
value|((c)->numeric)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical1
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical1)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical2
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical2)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical3
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical3)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical4
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical4)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical5
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical5)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical6
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical6)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical7
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical7)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logical8
parameter_list|(
name|c
parameter_list|)
value|((c)->u.logical8)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_logicaldefault
value|ffebld_constant_logical1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_characterdefault
value|ffebld_constant_new_character1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_characterdefault_val
value|ffebld_constant_new_character1_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexdefault
value|ffebld_constant_new_complex1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexdefault_val
value|ffebld_constant_new_complex1_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexdouble
value|ffebld_constant_new_complex2
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexdouble_val
value|ffebld_constant_new_complex2_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexquad
value|ffebld_constant_new_complex3
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_complexquad_valffebld_constant_new_complex3_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_integerdefault
value|ffebld_constant_new_integer1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_integerdefault_val
value|ffebld_constant_new_integer1_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_logicaldefault
value|ffebld_constant_new_logical1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_logicaldefault_val
value|ffebld_constant_new_logical1_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realdefault
value|ffebld_constant_new_real1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realdefault_val
value|ffebld_constant_new_real1_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realdouble
value|ffebld_constant_new_real2
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realdouble_val
value|ffebld_constant_new_real2_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realquad
value|ffebld_constant_new_real3
end_define

begin_define
define|#
directive|define
name|ffebld_constant_new_realquad_val
value|ffebld_constant_new_real3_val
end_define

begin_define
define|#
directive|define
name|ffebld_constant_ptr_to_union
parameter_list|(
name|c
parameter_list|)
value|(&(c)->u)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real1
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real1)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real2
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real2)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real3
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real3)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real4
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real4)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real5
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real5)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real6
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real6)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real7
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real7)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_real8
parameter_list|(
name|c
parameter_list|)
value|((c)->u.real8)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_realdefault
value|ffebld_constant_real1
end_define

begin_define
define|#
directive|define
name|ffebld_constant_realdouble
value|ffebld_constant_real2
end_define

begin_define
define|#
directive|define
name|ffebld_constant_realquad
value|ffebld_constant_real3
end_define

begin_define
define|#
directive|define
name|ffebld_constant_set_hook
parameter_list|(
name|c
parameter_list|,
name|h
parameter_list|)
value|((c)->hook = (h))
end_define

begin_define
define|#
directive|define
name|ffebld_constant_set_union
parameter_list|(
name|c
parameter_list|,
name|un
parameter_list|)
value|((c)->u = (un))
end_define

begin_define
define|#
directive|define
name|ffebld_constant_type
parameter_list|(
name|c
parameter_list|)
value|((c)->consttype)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_typeless
parameter_list|(
name|c
parameter_list|)
value|((c)->u.typeless)
end_define

begin_define
define|#
directive|define
name|ffebld_constant_union
parameter_list|(
name|c
parameter_list|)
value|((c)->u)
end_define

begin_define
define|#
directive|define
name|ffebld_conter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.conter.expr)
end_define

begin_define
define|#
directive|define
name|ffebld_conter_orig
parameter_list|(
name|b
parameter_list|)
value|((b)->u.conter.orig)
end_define

begin_define
define|#
directive|define
name|ffebld_conter_pad
parameter_list|(
name|b
parameter_list|)
value|((b)->u.conter.pad)
end_define

begin_define
define|#
directive|define
name|ffebld_conter_set_orig
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|((b)->u.conter.orig = (o))
end_define

begin_define
define|#
directive|define
name|ffebld_conter_set_pad
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
value|((b)->u.conter.pad = (p))
end_define

begin_define
define|#
directive|define
name|ffebld_copy
parameter_list|(
name|b
parameter_list|)
value|(b)
end_define

begin_comment
comment|/* ~~~Someday really make a copy. */
end_comment

begin_define
define|#
directive|define
name|ffebld_cu_ptr_typeless
parameter_list|(
name|u
parameter_list|)
value|&(u).typeless
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_hollerith
parameter_list|(
name|u
parameter_list|)
value|&(u).hollerith
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer1
parameter_list|(
name|u
parameter_list|)
value|&(u).integer1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer2
parameter_list|(
name|u
parameter_list|)
value|&(u).integer2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer3
parameter_list|(
name|u
parameter_list|)
value|&(u).integer3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer4
parameter_list|(
name|u
parameter_list|)
value|&(u).integer4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer5
parameter_list|(
name|u
parameter_list|)
value|&(u).integer5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer6
parameter_list|(
name|u
parameter_list|)
value|&(u).integer6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer7
parameter_list|(
name|u
parameter_list|)
value|&(u).integer7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integer8
parameter_list|(
name|u
parameter_list|)
value|&(u).integer8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_integerdefault
value|ffebld_cu_ptr_integer1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical1
parameter_list|(
name|u
parameter_list|)
value|&(u).logical1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical2
parameter_list|(
name|u
parameter_list|)
value|&(u).logical2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical3
parameter_list|(
name|u
parameter_list|)
value|&(u).logical3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical4
parameter_list|(
name|u
parameter_list|)
value|&(u).logical4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical5
parameter_list|(
name|u
parameter_list|)
value|&(u).logical5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical6
parameter_list|(
name|u
parameter_list|)
value|&(u).logical6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical7
parameter_list|(
name|u
parameter_list|)
value|&(u).logical7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logical8
parameter_list|(
name|u
parameter_list|)
value|&(u).logical8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_logicaldefault
value|ffebld_cu_ptr_logical1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real1
parameter_list|(
name|u
parameter_list|)
value|&(u).real1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real2
parameter_list|(
name|u
parameter_list|)
value|&(u).real2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real3
parameter_list|(
name|u
parameter_list|)
value|&(u).real3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real4
parameter_list|(
name|u
parameter_list|)
value|&(u).real4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real5
parameter_list|(
name|u
parameter_list|)
value|&(u).real5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real6
parameter_list|(
name|u
parameter_list|)
value|&(u).real6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real7
parameter_list|(
name|u
parameter_list|)
value|&(u).real7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_real8
parameter_list|(
name|u
parameter_list|)
value|&(u).real8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_realdefault
value|ffebld_cu_ptr_real1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_realdouble
value|ffebld_cu_ptr_real2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_realquad
value|ffebld_cu_ptr_real3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex1
parameter_list|(
name|u
parameter_list|)
value|&(u).complex1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex2
parameter_list|(
name|u
parameter_list|)
value|&(u).complex2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex3
parameter_list|(
name|u
parameter_list|)
value|&(u).complex3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex4
parameter_list|(
name|u
parameter_list|)
value|&(u).complex4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex5
parameter_list|(
name|u
parameter_list|)
value|&(u).complex5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex6
parameter_list|(
name|u
parameter_list|)
value|&(u).complex6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex7
parameter_list|(
name|u
parameter_list|)
value|&(u).complex7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complex8
parameter_list|(
name|u
parameter_list|)
value|&(u).complex8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complexdefault
value|ffebld_cu_ptr_complex1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complexdouble
value|ffebld_cu_ptr_complex2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_complexquad
value|ffebld_cu_ptr_complex3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character1
parameter_list|(
name|u
parameter_list|)
value|&(u).character1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character2
parameter_list|(
name|u
parameter_list|)
value|&(u).character2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character3
parameter_list|(
name|u
parameter_list|)
value|&(u).character3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character4
parameter_list|(
name|u
parameter_list|)
value|&(u).character4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character5
parameter_list|(
name|u
parameter_list|)
value|&(u).character5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character6
parameter_list|(
name|u
parameter_list|)
value|&(u).character6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character7
parameter_list|(
name|u
parameter_list|)
value|&(u).character7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_ptr_character8
parameter_list|(
name|u
parameter_list|)
value|&(u).character8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_typeless
parameter_list|(
name|u
parameter_list|)
value|(u).typeless
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_hollerith
parameter_list|(
name|u
parameter_list|)
value|(u).hollerith
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer1
parameter_list|(
name|u
parameter_list|)
value|(u).integer1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer2
parameter_list|(
name|u
parameter_list|)
value|(u).integer2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer3
parameter_list|(
name|u
parameter_list|)
value|(u).integer3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer4
parameter_list|(
name|u
parameter_list|)
value|(u).integer4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer5
parameter_list|(
name|u
parameter_list|)
value|(u).integer5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer6
parameter_list|(
name|u
parameter_list|)
value|(u).integer6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer7
parameter_list|(
name|u
parameter_list|)
value|(u).integer7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integer8
parameter_list|(
name|u
parameter_list|)
value|(u).integer8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_integerdefault
value|ffebld_cu_val_integer1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical1
parameter_list|(
name|u
parameter_list|)
value|(u).logical1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical2
parameter_list|(
name|u
parameter_list|)
value|(u).logical2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical3
parameter_list|(
name|u
parameter_list|)
value|(u).logical3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical4
parameter_list|(
name|u
parameter_list|)
value|(u).logical4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical5
parameter_list|(
name|u
parameter_list|)
value|(u).logical5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical6
parameter_list|(
name|u
parameter_list|)
value|(u).logical6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical7
parameter_list|(
name|u
parameter_list|)
value|(u).logical7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logical8
parameter_list|(
name|u
parameter_list|)
value|(u).logical8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_logicaldefault
value|ffebld_cu_val_logical
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real1
parameter_list|(
name|u
parameter_list|)
value|(u).real1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real2
parameter_list|(
name|u
parameter_list|)
value|(u).real2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real3
parameter_list|(
name|u
parameter_list|)
value|(u).real3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real4
parameter_list|(
name|u
parameter_list|)
value|(u).real4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real5
parameter_list|(
name|u
parameter_list|)
value|(u).real5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real6
parameter_list|(
name|u
parameter_list|)
value|(u).real6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real7
parameter_list|(
name|u
parameter_list|)
value|(u).real7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_real8
parameter_list|(
name|u
parameter_list|)
value|(u).real8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_realdefault
value|ffebld_cu_val_real1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_realdouble
value|ffebld_cu_val_real2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_realquad
value|ffebld_cu_val_real3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex1
parameter_list|(
name|u
parameter_list|)
value|(u).complex1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex2
parameter_list|(
name|u
parameter_list|)
value|(u).complex2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex3
parameter_list|(
name|u
parameter_list|)
value|(u).complex3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex4
parameter_list|(
name|u
parameter_list|)
value|(u).complex4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex5
parameter_list|(
name|u
parameter_list|)
value|(u).complex5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex6
parameter_list|(
name|u
parameter_list|)
value|(u).complex6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex7
parameter_list|(
name|u
parameter_list|)
value|(u).complex7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complex8
parameter_list|(
name|u
parameter_list|)
value|(u).complex8
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complexdefault
value|ffebld_cu_val_complex1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complexdouble
value|ffebld_cu_val_complex2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_complexquad
value|ffebld_cu_val_complex3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character1
parameter_list|(
name|u
parameter_list|)
value|(u).character1
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character2
parameter_list|(
name|u
parameter_list|)
value|(u).character2
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character3
parameter_list|(
name|u
parameter_list|)
value|(u).character3
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character4
parameter_list|(
name|u
parameter_list|)
value|(u).character4
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character5
parameter_list|(
name|u
parameter_list|)
value|(u).character5
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character6
parameter_list|(
name|u
parameter_list|)
value|(u).character6
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character7
parameter_list|(
name|u
parameter_list|)
value|(u).character7
end_define

begin_define
define|#
directive|define
name|ffebld_cu_val_character8
parameter_list|(
name|u
parameter_list|)
value|(u).character8
end_define

begin_define
define|#
directive|define
name|ffebld_end_list
parameter_list|(
name|b
parameter_list|)
value|(*(b) = NULL)
end_define

begin_define
define|#
directive|define
name|ffebld_head
parameter_list|(
name|b
parameter_list|)
value|((b)->u.item.head)
end_define

begin_define
define|#
directive|define
name|ffebld_info
parameter_list|(
name|b
parameter_list|)
value|((b)->info)
end_define

begin_define
define|#
directive|define
name|ffebld_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_init_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_init_list
parameter_list|(
name|l
parameter_list|,
name|b
parameter_list|)
value|(*(l) = NULL, *(b) = (l))
end_define

begin_define
define|#
directive|define
name|ffebld_item_hook
parameter_list|(
name|b
parameter_list|)
value|((b)->u.item.hook)
end_define

begin_define
define|#
directive|define
name|ffebld_item_set_hook
parameter_list|(
name|b
parameter_list|,
name|h
parameter_list|)
value|((b)->u.item.hook = (h))
end_define

begin_define
define|#
directive|define
name|ffebld_kind
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_kind (ffebld_info ((b))))
end_define

begin_define
define|#
directive|define
name|ffebld_kindtype
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_kindtype (ffebld_info ((b))))
end_define

begin_define
define|#
directive|define
name|ffebld_labter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.labter)
end_define

begin_define
define|#
directive|define
name|ffebld_labtok
parameter_list|(
name|b
parameter_list|)
value|((b)->u.labtok)
end_define

begin_define
define|#
directive|define
name|ffebld_left
parameter_list|(
name|b
parameter_list|)
value|((b)->u.nonter.left)
end_define

begin_define
define|#
directive|define
name|ffebld_name_string
parameter_list|(
name|n
parameter_list|)
value|((n)->name)
end_define

begin_define
define|#
directive|define
name|ffebld_new
parameter_list|()
define|\
value|((ffebld) malloc_new_kp(ffebld_pool(), "FFEBLD",sizeof(struct _ffebld_)))
end_define

begin_define
define|#
directive|define
name|ffebld_new_any
parameter_list|()
value|ffebld_new_none(FFEBLD_opANY)
end_define

begin_define
define|#
directive|define
name|ffebld_new_conter
parameter_list|(
name|c
parameter_list|)
value|ffebld_new_conter_with_orig((c),NULL)
end_define

begin_define
define|#
directive|define
name|ffebld_new_star
parameter_list|()
value|ffebld_new_none(FFEBLD_opSTAR)
end_define

begin_define
define|#
directive|define
name|ffebld_new_uplus
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opUPLUS,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_uminus
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opUMINUS,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_add
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opADD,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_subtract
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opSUBTRACT,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_multiply
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opMULTIPLY,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_divide
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opDIVIDE,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_power
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opPOWER,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_bounds
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opBOUNDS,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_concatenate
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opCONCATENATE,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_not
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opNOT,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_lt
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opLT,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_le
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opLE,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_eq
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opEQ,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_ne
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opNE,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_gt
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opGT,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_ge
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opGE,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_and
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opAND,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_or
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opOR,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_xor
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opXOR,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_eqv
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opEQV,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_neqv
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opNEQV,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_paren
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opPAREN,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_repeat
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opREPEAT,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_percent_descr
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opPERCENT_DESCR,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_percent_loc
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opPERCENT_LOC,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_percent_ref
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opPERCENT_REF,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_percent_val
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opPERCENT_VAL,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_complex
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opCOMPLEX,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_convert
parameter_list|(
name|l
parameter_list|)
value|ffebld_new_one(FFEBLD_opCONVERT,(l))
end_define

begin_define
define|#
directive|define
name|ffebld_new_funcref
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opFUNCREF,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_subrref
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opSUBRREF,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_arrayref
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opARRAYREF,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_substr
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opSUBSTR,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_new_impdo
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
value|ffebld_new_two(FFEBLD_opIMPDO,(l),(r))
end_define

begin_define
define|#
directive|define
name|ffebld_nonter_hook
parameter_list|(
name|b
parameter_list|)
value|((b)->u.nonter.hook)
end_define

begin_define
define|#
directive|define
name|ffebld_nonter_set_hook
parameter_list|(
name|b
parameter_list|,
name|h
parameter_list|)
value|((b)->u.nonter.hook = (h))
end_define

begin_define
define|#
directive|define
name|ffebld_op
parameter_list|(
name|b
parameter_list|)
value|((b)->op)
end_define

begin_define
define|#
directive|define
name|ffebld_pool
parameter_list|()
value|(ffebld_pool_stack_.pool)
end_define

begin_define
define|#
directive|define
name|ffebld_rank
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_rank (ffebld_info ((b))))
end_define

begin_define
define|#
directive|define
name|ffebld_right
parameter_list|(
name|b
parameter_list|)
value|((b)->u.nonter.right)
end_define

begin_define
define|#
directive|define
name|ffebld_set_accter
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|)
value|((b)->u.accter.array = (a))
end_define

begin_define
define|#
directive|define
name|ffebld_set_arrter
parameter_list|(
name|b
parameter_list|,
name|a
parameter_list|)
value|((b)->u.arrter.array = (a))
end_define

begin_define
define|#
directive|define
name|ffebld_set_conter
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|)
value|((b)->u.conter.expr = (c))
end_define

begin_define
define|#
directive|define
name|ffebld_set_info
parameter_list|(
name|b
parameter_list|,
name|i
parameter_list|)
value|((b)->info = (i))
end_define

begin_define
define|#
directive|define
name|ffebld_set_labter
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|((b)->u.labter = (l))
end_define

begin_define
define|#
directive|define
name|ffebld_set_op
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|((b)->op = (o))
end_define

begin_define
define|#
directive|define
name|ffebld_set_head
parameter_list|(
name|b
parameter_list|,
name|h
parameter_list|)
value|((b)->u.item.head = (h))
end_define

begin_define
define|#
directive|define
name|ffebld_set_left
parameter_list|(
name|b
parameter_list|,
name|l
parameter_list|)
value|((b)->u.nonter.left = (l))
end_define

begin_define
define|#
directive|define
name|ffebld_set_right
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|((b)->u.nonter.right = (r))
end_define

begin_define
define|#
directive|define
name|ffebld_set_trail
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|((b)->u.item.trail = (t))
end_define

begin_define
define|#
directive|define
name|ffebld_size
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_size (ffebld_info ((b))))
end_define

begin_define
define|#
directive|define
name|ffebld_size_known
parameter_list|(
name|b
parameter_list|)
value|ffebld_size((b))
end_define

begin_define
define|#
directive|define
name|ffebld_symter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.symter.symbol)
end_define

begin_define
define|#
directive|define
name|ffebld_symter_generic
parameter_list|(
name|b
parameter_list|)
value|((b)->u.symter.generic)
end_define

begin_define
define|#
directive|define
name|ffebld_symter_doiter
parameter_list|(
name|b
parameter_list|)
value|((b)->u.symter.do_iter)
end_define

begin_define
define|#
directive|define
name|ffebld_symter_implementation
parameter_list|(
name|b
parameter_list|)
value|((b)->u.symter.implementation)
end_define

begin_define
define|#
directive|define
name|ffebld_symter_specific
parameter_list|(
name|b
parameter_list|)
value|((b)->u.symter.specific)
end_define

begin_define
define|#
directive|define
name|ffebld_symter_set_generic
parameter_list|(
name|b
parameter_list|,
name|g
parameter_list|)
value|((b)->u.symter.generic = (g))
end_define

begin_define
define|#
directive|define
name|ffebld_symter_set_implementation
parameter_list|(
name|b
parameter_list|,
name|i
parameter_list|)
define|\
value|((b)->u.symter.implementation = (i))
end_define

begin_define
define|#
directive|define
name|ffebld_symter_set_is_doiter
parameter_list|(
name|b
parameter_list|,
name|f
parameter_list|)
value|((b)->u.symter.do_iter = (f))
end_define

begin_define
define|#
directive|define
name|ffebld_symter_set_specific
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|)
value|((b)->u.symter.specific = (s))
end_define

begin_define
define|#
directive|define
name|ffebld_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_terminate_4
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffebld_trail
parameter_list|(
name|b
parameter_list|)
value|((b)->u.item.trail)
end_define

begin_define
define|#
directive|define
name|ffebld_where
parameter_list|(
name|b
parameter_list|)
value|(ffeinfo_where (ffebld_info ((b))))
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_BLD_H */
end_comment

end_unit

