begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** types.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	types.h,v $  * Revision 5.1  91/12/05  07:59:39  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/*  types.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAWK_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|MAWK_TYPES_H
end_define

begin_if
if|#
directive|if
name|HAVE_VOID_PTR
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|PTR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|PTR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sizes.h"
end_include

begin_comment
comment|/*  CELL  types  */
end_comment

begin_define
define|#
directive|define
name|C_NOINIT
value|0
end_define

begin_define
define|#
directive|define
name|C_DOUBLE
value|1
end_define

begin_define
define|#
directive|define
name|C_STRING
value|2
end_define

begin_define
define|#
directive|define
name|C_STRNUM
value|3
end_define

begin_define
define|#
directive|define
name|C_MBSTRN
value|4
end_define

begin_comment
comment|/*could be STRNUM, has not been checked */
end_comment

begin_define
define|#
directive|define
name|C_RE
value|5
end_define

begin_define
define|#
directive|define
name|C_SPACE
value|6
end_define

begin_comment
comment|/* split on space */
end_comment

begin_define
define|#
directive|define
name|C_SNULL
value|7
end_define

begin_comment
comment|/* split on the empty string  */
end_comment

begin_define
define|#
directive|define
name|C_REPL
value|8
end_define

begin_comment
comment|/* a replacement string   '\&' changed to&  */
end_comment

begin_define
define|#
directive|define
name|C_REPLV
value|9
end_define

begin_comment
comment|/* a vector replacement -- broken on&  */
end_comment

begin_define
define|#
directive|define
name|NUM_CELL_TYPES
value|10
end_define

begin_comment
comment|/* these defines are used to check types for two    CELLs which are adjacent in memory */
end_comment

begin_define
define|#
directive|define
name|TWO_NOINITS
value|(2*(1<<C_NOINIT))
end_define

begin_define
define|#
directive|define
name|TWO_DOUBLES
value|(2*(1<<C_DOUBLE))
end_define

begin_define
define|#
directive|define
name|TWO_STRINGS
value|(2*(1<<C_STRING))
end_define

begin_define
define|#
directive|define
name|TWO_STRNUMS
value|(2*(1<<C_STRNUM))
end_define

begin_define
define|#
directive|define
name|TWO_MBSTRNS
value|(2*(1<<C_MBSTRN))
end_define

begin_define
define|#
directive|define
name|NOINIT_AND_DOUBLE
value|((1<<C_NOINIT)+(1<<C_DOUBLE))
end_define

begin_define
define|#
directive|define
name|NOINIT_AND_STRING
value|((1<<C_NOINIT)+(1<<C_STRING))
end_define

begin_define
define|#
directive|define
name|NOINIT_AND_STRNUM
value|((1<<C_NOINIT)+(1<<C_STRNUM))
end_define

begin_define
define|#
directive|define
name|DOUBLE_AND_STRING
value|((1<<C_DOUBLE)+(1<<C_STRING))
end_define

begin_define
define|#
directive|define
name|DOUBLE_AND_STRNUM
value|((1<<C_STRNUM)+(1<<C_DOUBLE))
end_define

begin_define
define|#
directive|define
name|STRING_AND_STRNUM
value|((1<<C_STRING)+(1<<C_STRNUM))
end_define

begin_define
define|#
directive|define
name|NOINIT_AND_MBSTRN
value|((1<<C_NOINIT)+(1<<C_MBSTRN))
end_define

begin_define
define|#
directive|define
name|DOUBLE_AND_MBSTRN
value|((1<<C_DOUBLE)+(1<<C_MBSTRN))
end_define

begin_define
define|#
directive|define
name|STRING_AND_MBSTRN
value|((1<<C_STRING)+(1<<C_MBSTRN))
end_define

begin_define
define|#
directive|define
name|STRNUM_AND_MBSTRN
value|((1<<C_STRNUM)+(1<<C_MBSTRN))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|len
decl_stmt|;
name|unsigned
name|short
name|ref_cnt
decl_stmt|;
name|char
name|str
index|[
literal|2
index|]
decl_stmt|;
block|}
name|STRING
typedef|;
end_typedef

begin_comment
comment|/* number of bytes more than the characters to store a    string */
end_comment

begin_define
define|#
directive|define
name|STRING_OH
value|(sizeof(STRING)-1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|cell
block|{
name|short
name|type
decl_stmt|;
name|short
name|vcnt
decl_stmt|;
comment|/* only used if type == C_REPLV   */
name|PTR
name|ptr
decl_stmt|;
name|double
name|dval
decl_stmt|;
block|}
name|CELL
typedef|;
end_typedef

begin_comment
comment|/* all builtins are passed the evaluation stack pointer and    return its new value, here is the type */
end_comment

begin_if
if|#
directive|if
name|HAVE_PROTOS
end_if

begin_typedef
typedef|typedef
name|CELL
modifier|*
function_decl|(
modifier|*
name|PF_CP
function_decl|)
parameter_list|(
name|CELL
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|CELL
modifier|*
function_decl|(
modifier|*
name|PF_CP
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* an element of code (instruction) */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|op
decl_stmt|;
name|PTR
name|ptr
decl_stmt|;
block|}
name|INST
typedef|;
end_typedef

begin_comment
comment|/* how we give parser table memory to zmalloc */
end_comment

begin_struct
struct|struct
name|yacc_mem
block|{
name|PTR
name|mem
decl_stmt|;
name|short
name|zblocks
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

