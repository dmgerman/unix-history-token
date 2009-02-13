begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_ERRTAGS_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_ERRTAGS_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * This enum definition is used to define a set of error tags associated with  * the D compiler's various error conditions.  The shell script mkerrtags.sh is  * used to parse this file and create a corresponding dt_errtags.c source file.  * If you do something other than add a new error tag here, you may need to  * update the mkerrtags shell script as it is based upon simple regexps.  */
typedef|typedef
enum|enum
block|{
name|D_UNKNOWN
block|,
comment|/* unknown D compiler error */
name|D_SYNTAX
block|,
comment|/* syntax error in input stream */
name|D_EMPTY
block|,
comment|/* empty translation unit */
name|D_TYPE_ERR
block|,
comment|/* type definition missing */
name|D_TYPE_MEMBER
block|,
comment|/* type member not found */
name|D_ASRELO
block|,
comment|/* relocation remains against symbol */
name|D_CG_EXPR
block|,
comment|/* tracing function called from expr */
name|D_CG_DYN
block|,
comment|/* expression returns dynamic result */
name|D_ATTR_MIN
block|,
comment|/* attributes less than amin setting */
name|D_ID_OFLOW
block|,
comment|/* identifier space overflow */
name|D_PDESC_ZERO
block|,
comment|/* probedesc matches zero probes */
name|D_PDESC_INVAL
block|,
comment|/* probedesc is not valid */
name|D_PRED_SCALAR
block|,
comment|/* predicate must be of scalar type */
name|D_FUNC_IDENT
block|,
comment|/* function designator is not ident */
name|D_FUNC_UNDEF
block|,
comment|/* function ident is not defined */
name|D_FUNC_IDKIND
block|,
comment|/* function ident is of wrong idkind */
name|D_OFFSETOF_TYPE
block|,
comment|/* offsetof arg is not sou type */
name|D_OFFSETOF_BITFIELD
block|,
comment|/* offsetof applied to field member */
name|D_SIZEOF_TYPE
block|,
comment|/* invalid sizeof type */
name|D_SIZEOF_BITFIELD
block|,
comment|/* sizeof applied to field member */
name|D_STRINGOF_TYPE
block|,
comment|/* invalid stringof type */
name|D_OP_IDENT
block|,
comment|/* operand must be an identifier */
name|D_OP_INT
block|,
comment|/* operand must be integral type */
name|D_OP_SCALAR
block|,
comment|/* operand must be scalar type */
name|D_OP_ARITH
block|,
comment|/* operand must be arithmetic type */
name|D_OP_WRITE
block|,
comment|/* operand must be writable variable */
name|D_OP_LVAL
block|,
comment|/* operand must be lvalue */
name|D_OP_INCOMPAT
block|,
comment|/* operand types are not compatible */
name|D_OP_VFPTR
block|,
comment|/* operand cannot be void or func ptr */
name|D_OP_ARRFUN
block|,
comment|/* operand cannot be array or func */
name|D_OP_PTR
block|,
comment|/* operand must be a pointer */
name|D_OP_SOU
block|,
comment|/* operand must be struct or union */
name|D_OP_INCOMPLETE
block|,
comment|/* operand is an incomplete type */
name|D_OP_DYN
block|,
comment|/* operand cannot be of dynamic type */
name|D_OP_ACT
block|,
comment|/* operand cannot be action */
name|D_AGG_REDEF
block|,
comment|/* aggregation cannot be redefined */
name|D_AGG_FUNC
block|,
comment|/* aggregating function required */
name|D_AGG_MDIM
block|,
comment|/* aggregation used as multi-dim arr */
name|D_ARR_BADREF
block|,
comment|/* access non-array using tuple */
name|D_ARR_LOCAL
block|,
comment|/* cannot define local assc array */
name|D_DIV_ZERO
block|,
comment|/* division by zero detected */
name|D_DEREF_NONPTR
block|,
comment|/* dereference non-pointer type */
name|D_DEREF_VOID
block|,
comment|/* dereference void pointer */
name|D_DEREF_FUNC
block|,
comment|/* dereference function pointer */
name|D_ADDROF_LVAL
block|,
comment|/* unary& applied to non-lvalue */
name|D_ADDROF_VAR
block|,
comment|/* unary& applied to variable */
name|D_ADDROF_BITFIELD
block|,
comment|/* unary& applied to field member */
name|D_XLATE_REDECL
block|,
comment|/* translator redeclared */
name|D_XLATE_NOCONV
block|,
comment|/* no conversion for member defined */
name|D_XLATE_NONE
block|,
comment|/* no translator for type combo */
name|D_XLATE_SOU
block|,
comment|/* dst must be struct or union type */
name|D_XLATE_INCOMPAT
block|,
comment|/* translator member type incompat */
name|D_XLATE_MEMB
block|,
comment|/* translator member is not valid */
name|D_CAST_INVAL
block|,
comment|/* invalid cast expression */
name|D_PRAGERR
block|,
comment|/* #pragma error message */
name|D_PRAGCTL_INVAL
block|,
comment|/* invalid control directive */
name|D_PRAGMA_INVAL
block|,
comment|/* invalid compiler pragma */
name|D_PRAGMA_UNUSED
block|,
comment|/* unused compiler pragma */
name|D_PRAGMA_MALFORM
block|,
comment|/* malformed #pragma argument list */
name|D_PRAGMA_OPTSET
block|,
comment|/* failed to set #pragma option */
name|D_PRAGMA_SCOPE
block|,
comment|/* #pragma identifier scope error */
name|D_PRAGMA_DEPEND
block|,
comment|/* #pragma dependency not satisfied */
name|D_MACRO_UNDEF
block|,
comment|/* macro parameter is not defined */
name|D_MACRO_OFLOW
block|,
comment|/* macro parameter integer overflow */
name|D_MACRO_UNUSED
block|,
comment|/* macro parameter is never used */
name|D_INT_OFLOW
block|,
comment|/* integer constant overflow */
name|D_INT_DIGIT
block|,
comment|/* integer digit is not valid */
name|D_STR_NL
block|,
comment|/* newline in string literal */
name|D_CHR_NL
block|,
comment|/* newline in character constant */
name|D_CHR_NULL
block|,
comment|/* empty character constant */
name|D_CHR_OFLOW
block|,
comment|/* character constant is too long */
name|D_IDENT_BADREF
block|,
comment|/* identifier expected type mismatch */
name|D_IDENT_UNDEF
block|,
comment|/* identifier is not known/defined */
name|D_IDENT_AMBIG
block|,
comment|/* identifier is ambiguous (var/enum) */
name|D_SYM_BADREF
block|,
comment|/* kernel/user symbol ref mismatch */
name|D_SYM_NOTYPES
block|,
comment|/* no CTF data available for sym ref */
name|D_SYM_MODEL
block|,
comment|/* module/program data model mismatch */
name|D_VAR_UNDEF
block|,
comment|/* reference to undefined variable */
name|D_VAR_UNSUP
block|,
comment|/* unsupported variable specification */
name|D_PROTO_LEN
block|,
comment|/* prototype length mismatch */
name|D_PROTO_ARG
block|,
comment|/* prototype argument mismatch */
name|D_ARGS_MULTI
block|,
comment|/* description matches unstable set */
name|D_ARGS_XLATOR
block|,
comment|/* no args[] translator defined */
name|D_ARGS_NONE
block|,
comment|/* no args[] available */
name|D_ARGS_TYPE
block|,
comment|/* invalid args[] type */
name|D_ARGS_IDX
block|,
comment|/* invalid args[] index */
name|D_REGS_IDX
block|,
comment|/* invalid regs[] index */
name|D_KEY_TYPE
block|,
comment|/* invalid agg or array key type */
name|D_PRINTF_DYN_PROTO
block|,
comment|/* dynamic size argument missing */
name|D_PRINTF_DYN_TYPE
block|,
comment|/* dynamic size type mismatch */
name|D_PRINTF_AGG_CONV
block|,
comment|/* improper use of %@ conversion */
name|D_PRINTF_ARG_PROTO
block|,
comment|/* conversion missing value argument */
name|D_PRINTF_ARG_TYPE
block|,
comment|/* conversion arg has wrong type */
name|D_PRINTF_ARG_EXTRA
block|,
comment|/* extra arguments specified */
name|D_PRINTF_ARG_FMT
block|,
comment|/* format string is not a constant */
name|D_PRINTF_FMT_EMPTY
block|,
comment|/* format string is empty */
name|D_DECL_CHARATTR
block|,
comment|/* bad attributes for char decl */
name|D_DECL_VOIDATTR
block|,
comment|/* bad attributes for void decl */
name|D_DECL_SIGNINT
block|,
comment|/* sign/unsign with non-integer decl */
name|D_DECL_LONGINT
block|,
comment|/* long with non-arithmetic decl */
name|D_DECL_IDENT
block|,
comment|/* old-style declaration or bad type */
name|D_DECL_CLASS
block|,
comment|/* more than one storage class given */
name|D_DECL_BADCLASS
block|,
comment|/* decl class not supported in D */
name|D_DECL_PARMCLASS
block|,
comment|/* invalid class for parameter type */
name|D_DECL_COMBO
block|,
comment|/* bad decl specifier combination */
name|D_DECL_ARRSUB
block|,
comment|/* const int required for array size */
name|D_DECL_ARRNULL
block|,
comment|/* array decl requires dim or tuple */
name|D_DECL_ARRBIG
block|,
comment|/* array size too big */
name|D_DECL_IDRED
block|,
comment|/* decl identifier redeclared */
name|D_DECL_TYPERED
block|,
comment|/* decl type redeclared */
name|D_DECL_MNAME
block|,
comment|/* member name missing */
name|D_DECL_SCOPE
block|,
comment|/* scoping operator used in decl */
name|D_DECL_BFCONST
block|,
comment|/* bit-field requires const size expr */
name|D_DECL_BFSIZE
block|,
comment|/* bit-field size too big for type */
name|D_DECL_BFTYPE
block|,
comment|/* bit-field type is not valid */
name|D_DECL_ENCONST
block|,
comment|/* enum tag requires const size expr */
name|D_DECL_ENOFLOW
block|,
comment|/* enumerator value overflows INT_MAX */
name|D_DECL_USELESS
block|,
comment|/* useless external declaration */
name|D_DECL_LOCASSC
block|,
comment|/* attempt to decl local assc array */
name|D_DECL_VOIDOBJ
block|,
comment|/* attempt to decl void object */
name|D_DECL_DYNOBJ
block|,
comment|/* attempt to decl dynamic object */
name|D_DECL_INCOMPLETE
block|,
comment|/* declaration uses incomplete type */
name|D_DECL_PROTO_VARARGS
block|,
comment|/* varargs not allowed in prototype */
name|D_DECL_PROTO_TYPE
block|,
comment|/* type not allowed in prototype */
name|D_DECL_PROTO_VOID
block|,
comment|/* void must be sole parameter */
name|D_DECL_PROTO_NAME
block|,
comment|/* void parameter may not have a name */
name|D_DECL_PROTO_FORM
block|,
comment|/* parameter name has no formal */
name|D_COMM_COMM
block|,
comment|/* commit() after commit() */
name|D_COMM_DREC
block|,
comment|/* commit() after data action */
name|D_SPEC_SPEC
block|,
comment|/* speculate() after speculate() */
name|D_SPEC_COMM
block|,
comment|/* speculate() after commit() */
name|D_SPEC_DREC
block|,
comment|/* speculate() after data action */
name|D_AGG_COMM
block|,
comment|/* aggregating act after commit() */
name|D_AGG_SPEC
block|,
comment|/* aggregating act after speculate() */
name|D_AGG_NULL
block|,
comment|/* aggregation stmt has null effect */
name|D_AGG_SCALAR
block|,
comment|/* aggregating function needs scalar */
name|D_ACT_SPEC
block|,
comment|/* destructive action after speculate */
name|D_EXIT_SPEC
block|,
comment|/* exit() action after speculate */
name|D_DREC_COMM
block|,
comment|/* data action after commit() */
name|D_PRINTA_PROTO
block|,
comment|/* printa() prototype mismatch */
name|D_PRINTA_AGGARG
block|,
comment|/* aggregation arg type mismatch */
name|D_PRINTA_AGGBAD
block|,
comment|/* printa() aggregation not defined */
name|D_PRINTA_AGGKEY
block|,
comment|/* printa() aggregation key mismatch */
name|D_PRINTA_AGGPROTO
block|,
comment|/* printa() aggregation mismatch */
name|D_TRACE_VOID
block|,
comment|/* trace() argument has void type */
name|D_TRACE_DYN
block|,
comment|/* trace() argument has dynamic type */
name|D_TRACEMEM_ADDR
block|,
comment|/* tracemem() address bad type */
name|D_TRACEMEM_SIZE
block|,
comment|/* tracemem() size bad type */
name|D_STACK_PROTO
block|,
comment|/* stack() prototype mismatch */
name|D_STACK_SIZE
block|,
comment|/* stack() size argument bad type */
name|D_USTACK_FRAMES
block|,
comment|/* ustack() frames arg bad type */
name|D_USTACK_STRSIZE
block|,
comment|/* ustack() strsize arg bad type */
name|D_USTACK_PROTO
block|,
comment|/* ustack() prototype mismatch */
name|D_LQUANT_BASETYPE
block|,
comment|/* lquantize() bad base type */
name|D_LQUANT_BASEVAL
block|,
comment|/* lquantize() bad base value */
name|D_LQUANT_LIMTYPE
block|,
comment|/* lquantize() bad limit type */
name|D_LQUANT_LIMVAL
block|,
comment|/* lquantize() bad limit value */
name|D_LQUANT_MISMATCH
block|,
comment|/* lquantize() limit< base */
name|D_LQUANT_STEPTYPE
block|,
comment|/* lquantize() bad step type */
name|D_LQUANT_STEPVAL
block|,
comment|/* lquantize() bad step value */
name|D_LQUANT_STEPLARGE
block|,
comment|/* lquantize() step too large */
name|D_LQUANT_STEPSMALL
block|,
comment|/* lquantize() step too small */
name|D_QUANT_PROTO
block|,
comment|/* quantize() prototype mismatch */
name|D_PROC_OFF
block|,
comment|/* byte offset exceeds function size */
name|D_PROC_ALIGN
block|,
comment|/* byte offset has invalid alignment */
name|D_PROC_NAME
block|,
comment|/* invalid process probe name */
name|D_PROC_GRAB
block|,
comment|/* failed to grab process */
name|D_PROC_DYN
block|,
comment|/* process is not dynamically linked */
name|D_PROC_LIB
block|,
comment|/* invalid process library name */
name|D_PROC_FUNC
block|,
comment|/* no such function in process */
name|D_PROC_CREATEFAIL
block|,
comment|/* pid probe creation failed */
name|D_PROC_NODEV
block|,
comment|/* fasttrap device is not installed */
name|D_PROC_BADPID
block|,
comment|/* user probe pid invalid */
name|D_PROC_BADPROV
block|,
comment|/* user probe provider invalid */
name|D_PROC_USDT
block|,
comment|/* problem initializing usdt */
name|D_CLEAR_PROTO
block|,
comment|/* clear() prototype mismatch */
name|D_CLEAR_AGGARG
block|,
comment|/* aggregation arg type mismatch */
name|D_CLEAR_AGGBAD
block|,
comment|/* clear() aggregation not defined */
name|D_NORMALIZE_PROTO
block|,
comment|/* normalize() prototype mismatch */
name|D_NORMALIZE_SCALAR
block|,
comment|/* normalize() value must be scalar */
name|D_NORMALIZE_AGGARG
block|,
comment|/* aggregation arg type mismatch */
name|D_NORMALIZE_AGGBAD
block|,
comment|/* normalize() aggregation not def. */
name|D_TRUNC_PROTO
block|,
comment|/* trunc() prototype mismatch */
name|D_TRUNC_SCALAR
block|,
comment|/* trunc() value must be scalar */
name|D_TRUNC_AGGARG
block|,
comment|/* aggregation arg type mismatch */
name|D_TRUNC_AGGBAD
block|,
comment|/* trunc() aggregation not def. */
name|D_PROV_BADNAME
block|,
comment|/* invalid provider name */
name|D_PROV_INCOMPAT
block|,
comment|/* provider/probe interface mismatch */
name|D_PROV_PRDUP
block|,
comment|/* duplicate probe declaration */
name|D_PROV_PRARGLEN
block|,
comment|/* probe argument list too long */
name|D_PROV_PRXLATOR
block|,
comment|/* probe argument translator missing */
name|D_FREOPEN_INVALID
block|,
comment|/* frename() filename is invalid */
name|D_LQUANT_MATCHBASE
block|,
comment|/* lquantize() mismatch on base */
name|D_LQUANT_MATCHLIM
block|,
comment|/* lquantize() mismatch on limit */
name|D_LQUANT_MATCHSTEP
block|,
comment|/* lquantize() mismatch on step */
name|D_PRINTM_ADDR
block|,
comment|/* printm() memref bad type */
name|D_PRINTM_SIZE
block|,
comment|/* printm() size bad type */
name|D_PRINTT_ADDR
block|,
comment|/* printt() typeref bad type */
name|D_PRINTT_SIZE
comment|/* printt() size bad type */
block|}
name|dt_errtag_t
typedef|;
specifier|extern
specifier|const
name|char
modifier|*
name|dt_errtag
parameter_list|(
name|dt_errtag_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_ERRTAGS_H */
end_comment

end_unit

