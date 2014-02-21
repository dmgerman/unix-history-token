begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LLVMBitCodes.h - Enum values for the LLVM bitcode format -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This header defines Bitcode enum values for LLVM IR bitcode files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The enum values defined in this file should be considered permanent.  If
end_comment

begin_comment
comment|// new features are added, they should have values added at the end of the
end_comment

begin_comment
comment|// respective lists.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_BITCODE_LLVMBITCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_BITCODE_LLVMBITCODES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitCodes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|bitc
block|{
comment|// The only top-level block type defined is for a module.
enum|enum
name|BlockIDs
block|{
comment|// Blocks
name|MODULE_BLOCK_ID
init|=
name|FIRST_APPLICATION_BLOCKID
block|,
comment|// Module sub-block id's.
name|PARAMATTR_BLOCK_ID
block|,
name|PARAMATTR_GROUP_BLOCK_ID
block|,
name|CONSTANTS_BLOCK_ID
block|,
name|FUNCTION_BLOCK_ID
block|,
name|UNUSED_ID1
block|,
name|VALUE_SYMTAB_BLOCK_ID
block|,
name|METADATA_BLOCK_ID
block|,
name|METADATA_ATTACHMENT_ID
block|,
name|TYPE_BLOCK_ID_NEW
block|,
name|USELIST_BLOCK_ID
block|}
enum|;
comment|/// MODULE blocks have a number of optional fields and subblocks.
enum|enum
name|ModuleCodes
block|{
name|MODULE_CODE_VERSION
init|=
literal|1
block|,
comment|// VERSION:     [version#]
name|MODULE_CODE_TRIPLE
init|=
literal|2
block|,
comment|// TRIPLE:      [strchr x N]
name|MODULE_CODE_DATALAYOUT
init|=
literal|3
block|,
comment|// DATALAYOUT:  [strchr x N]
name|MODULE_CODE_ASM
init|=
literal|4
block|,
comment|// ASM:         [strchr x N]
name|MODULE_CODE_SECTIONNAME
init|=
literal|5
block|,
comment|// SECTIONNAME: [strchr x N]
comment|// FIXME: Remove DEPLIB in 4.0.
name|MODULE_CODE_DEPLIB
init|=
literal|6
block|,
comment|// DEPLIB:      [strchr x N]
comment|// GLOBALVAR: [pointer type, isconst, initid,
comment|//             linkage, alignment, section, visibility, threadlocal]
name|MODULE_CODE_GLOBALVAR
init|=
literal|7
block|,
comment|// FUNCTION:  [type, callingconv, isproto, linkage, paramattrs, alignment,
comment|//             section, visibility, gc, unnamed_addr]
name|MODULE_CODE_FUNCTION
init|=
literal|8
block|,
comment|// ALIAS: [alias type, aliasee val#, linkage, visibility]
name|MODULE_CODE_ALIAS
init|=
literal|9
block|,
comment|// MODULE_CODE_PURGEVALS: [numvals]
name|MODULE_CODE_PURGEVALS
init|=
literal|10
block|,
name|MODULE_CODE_GCNAME
init|=
literal|11
comment|// GCNAME: [strchr x N]
block|}
enum|;
comment|/// PARAMATTR blocks have code for defining a parameter attribute set.
enum|enum
name|AttributeCodes
block|{
comment|// FIXME: Remove `PARAMATTR_CODE_ENTRY_OLD' in 4.0
name|PARAMATTR_CODE_ENTRY_OLD
init|=
literal|1
block|,
comment|// ENTRY: [paramidx0, attr0,
comment|//         paramidx1, attr1...]
name|PARAMATTR_CODE_ENTRY
init|=
literal|2
block|,
comment|// ENTRY: [paramidx0, attrgrp0,
comment|//         paramidx1, attrgrp1, ...]
name|PARAMATTR_GRP_CODE_ENTRY
init|=
literal|3
comment|// ENTRY: [id, attr0, att1, ...]
block|}
enum|;
comment|/// TYPE blocks have codes for each type primitive they use.
enum|enum
name|TypeCodes
block|{
name|TYPE_CODE_NUMENTRY
init|=
literal|1
block|,
comment|// NUMENTRY: [numentries]
comment|// Type Codes
name|TYPE_CODE_VOID
init|=
literal|2
block|,
comment|// VOID
name|TYPE_CODE_FLOAT
init|=
literal|3
block|,
comment|// FLOAT
name|TYPE_CODE_DOUBLE
init|=
literal|4
block|,
comment|// DOUBLE
name|TYPE_CODE_LABEL
init|=
literal|5
block|,
comment|// LABEL
name|TYPE_CODE_OPAQUE
init|=
literal|6
block|,
comment|// OPAQUE
name|TYPE_CODE_INTEGER
init|=
literal|7
block|,
comment|// INTEGER: [width]
name|TYPE_CODE_POINTER
init|=
literal|8
block|,
comment|// POINTER: [pointee type]
name|TYPE_CODE_FUNCTION_OLD
init|=
literal|9
block|,
comment|// FUNCTION: [vararg, attrid, retty,
comment|//            paramty x N]
name|TYPE_CODE_HALF
init|=
literal|10
block|,
comment|// HALF
name|TYPE_CODE_ARRAY
init|=
literal|11
block|,
comment|// ARRAY: [numelts, eltty]
name|TYPE_CODE_VECTOR
init|=
literal|12
block|,
comment|// VECTOR: [numelts, eltty]
comment|// These are not with the other floating point types because they're
comment|// a late addition, and putting them in the right place breaks
comment|// binary compatibility.
name|TYPE_CODE_X86_FP80
init|=
literal|13
block|,
comment|// X86 LONG DOUBLE
name|TYPE_CODE_FP128
init|=
literal|14
block|,
comment|// LONG DOUBLE (112 bit mantissa)
name|TYPE_CODE_PPC_FP128
init|=
literal|15
block|,
comment|// PPC LONG DOUBLE (2 doubles)
name|TYPE_CODE_METADATA
init|=
literal|16
block|,
comment|// METADATA
name|TYPE_CODE_X86_MMX
init|=
literal|17
block|,
comment|// X86 MMX
name|TYPE_CODE_STRUCT_ANON
init|=
literal|18
block|,
comment|// STRUCT_ANON: [ispacked, eltty x N]
name|TYPE_CODE_STRUCT_NAME
init|=
literal|19
block|,
comment|// STRUCT_NAME: [strchr x N]
name|TYPE_CODE_STRUCT_NAMED
init|=
literal|20
block|,
comment|// STRUCT_NAMED: [ispacked, eltty x N]
name|TYPE_CODE_FUNCTION
init|=
literal|21
comment|// FUNCTION: [vararg, retty, paramty x N]
block|}
enum|;
comment|// The type symbol table only has one code (TST_ENTRY_CODE).
enum|enum
name|TypeSymtabCodes
block|{
name|TST_CODE_ENTRY
init|=
literal|1
comment|// TST_ENTRY: [typeid, namechar x N]
block|}
enum|;
comment|// The value symbol table only has one code (VST_ENTRY_CODE).
enum|enum
name|ValueSymtabCodes
block|{
name|VST_CODE_ENTRY
init|=
literal|1
block|,
comment|// VST_ENTRY: [valid, namechar x N]
name|VST_CODE_BBENTRY
init|=
literal|2
comment|// VST_BBENTRY: [bbid, namechar x N]
block|}
enum|;
enum|enum
name|MetadataCodes
block|{
name|METADATA_STRING
init|=
literal|1
block|,
comment|// MDSTRING:      [values]
comment|// 2 is unused.
comment|// 3 is unused.
name|METADATA_NAME
init|=
literal|4
block|,
comment|// STRING:        [values]
comment|// 5 is unused.
name|METADATA_KIND
init|=
literal|6
block|,
comment|// [n x [id, name]]
comment|// 7 is unused.
name|METADATA_NODE
init|=
literal|8
block|,
comment|// NODE:          [n x (type num, value num)]
name|METADATA_FN_NODE
init|=
literal|9
block|,
comment|// FN_NODE:       [n x (type num, value num)]
name|METADATA_NAMED_NODE
init|=
literal|10
block|,
comment|// NAMED_NODE:    [n x mdnodes]
name|METADATA_ATTACHMENT
init|=
literal|11
comment|// [m x [value, [n x [id, mdnode]]]
block|}
enum|;
comment|// The constants block (CONSTANTS_BLOCK_ID) describes emission for each
comment|// constant and maintains an implicit current type value.
enum|enum
name|ConstantsCodes
block|{
name|CST_CODE_SETTYPE
init|=
literal|1
block|,
comment|// SETTYPE:       [typeid]
name|CST_CODE_NULL
init|=
literal|2
block|,
comment|// NULL
name|CST_CODE_UNDEF
init|=
literal|3
block|,
comment|// UNDEF
name|CST_CODE_INTEGER
init|=
literal|4
block|,
comment|// INTEGER:       [intval]
name|CST_CODE_WIDE_INTEGER
init|=
literal|5
block|,
comment|// WIDE_INTEGER:  [n x intval]
name|CST_CODE_FLOAT
init|=
literal|6
block|,
comment|// FLOAT:         [fpval]
name|CST_CODE_AGGREGATE
init|=
literal|7
block|,
comment|// AGGREGATE:     [n x value number]
name|CST_CODE_STRING
init|=
literal|8
block|,
comment|// STRING:        [values]
name|CST_CODE_CSTRING
init|=
literal|9
block|,
comment|// CSTRING:       [values]
name|CST_CODE_CE_BINOP
init|=
literal|10
block|,
comment|// CE_BINOP:      [opcode, opval, opval]
name|CST_CODE_CE_CAST
init|=
literal|11
block|,
comment|// CE_CAST:       [opcode, opty, opval]
name|CST_CODE_CE_GEP
init|=
literal|12
block|,
comment|// CE_GEP:        [n x operands]
name|CST_CODE_CE_SELECT
init|=
literal|13
block|,
comment|// CE_SELECT:     [opval, opval, opval]
name|CST_CODE_CE_EXTRACTELT
init|=
literal|14
block|,
comment|// CE_EXTRACTELT: [opty, opval, opval]
name|CST_CODE_CE_INSERTELT
init|=
literal|15
block|,
comment|// CE_INSERTELT:  [opval, opval, opval]
name|CST_CODE_CE_SHUFFLEVEC
init|=
literal|16
block|,
comment|// CE_SHUFFLEVEC: [opval, opval, opval]
name|CST_CODE_CE_CMP
init|=
literal|17
block|,
comment|// CE_CMP:        [opty, opval, opval, pred]
name|CST_CODE_INLINEASM_OLD
init|=
literal|18
block|,
comment|// INLINEASM:     [sideeffect|alignstack,
comment|//                 asmstr,conststr]
name|CST_CODE_CE_SHUFVEC_EX
init|=
literal|19
block|,
comment|// SHUFVEC_EX:    [opty, opval, opval, opval]
name|CST_CODE_CE_INBOUNDS_GEP
init|=
literal|20
block|,
comment|// INBOUNDS_GEP:  [n x operands]
name|CST_CODE_BLOCKADDRESS
init|=
literal|21
block|,
comment|// CST_CODE_BLOCKADDRESS [fnty, fnval, bb#]
name|CST_CODE_DATA
init|=
literal|22
block|,
comment|// DATA:          [n x elements]
name|CST_CODE_INLINEASM
init|=
literal|23
comment|// INLINEASM:     [sideeffect|alignstack|
comment|//                 asmdialect,asmstr,conststr]
block|}
enum|;
comment|/// CastOpcodes - These are values used in the bitcode files to encode which
comment|/// cast a CST_CODE_CE_CAST or a XXX refers to.  The values of these enums
comment|/// have no fixed relation to the LLVM IR enum values.  Changing these will
comment|/// break compatibility with old files.
enum|enum
name|CastOpcodes
block|{
name|CAST_TRUNC
init|=
literal|0
block|,
name|CAST_ZEXT
init|=
literal|1
block|,
name|CAST_SEXT
init|=
literal|2
block|,
name|CAST_FPTOUI
init|=
literal|3
block|,
name|CAST_FPTOSI
init|=
literal|4
block|,
name|CAST_UITOFP
init|=
literal|5
block|,
name|CAST_SITOFP
init|=
literal|6
block|,
name|CAST_FPTRUNC
init|=
literal|7
block|,
name|CAST_FPEXT
init|=
literal|8
block|,
name|CAST_PTRTOINT
init|=
literal|9
block|,
name|CAST_INTTOPTR
init|=
literal|10
block|,
name|CAST_BITCAST
init|=
literal|11
block|,
name|CAST_ADDRSPACECAST
init|=
literal|12
block|}
enum|;
comment|/// BinaryOpcodes - These are values used in the bitcode files to encode which
comment|/// binop a CST_CODE_CE_BINOP or a XXX refers to.  The values of these enums
comment|/// have no fixed relation to the LLVM IR enum values.  Changing these will
comment|/// break compatibility with old files.
enum|enum
name|BinaryOpcodes
block|{
name|BINOP_ADD
init|=
literal|0
block|,
name|BINOP_SUB
init|=
literal|1
block|,
name|BINOP_MUL
init|=
literal|2
block|,
name|BINOP_UDIV
init|=
literal|3
block|,
name|BINOP_SDIV
init|=
literal|4
block|,
comment|// overloaded for FP
name|BINOP_UREM
init|=
literal|5
block|,
name|BINOP_SREM
init|=
literal|6
block|,
comment|// overloaded for FP
name|BINOP_SHL
init|=
literal|7
block|,
name|BINOP_LSHR
init|=
literal|8
block|,
name|BINOP_ASHR
init|=
literal|9
block|,
name|BINOP_AND
init|=
literal|10
block|,
name|BINOP_OR
init|=
literal|11
block|,
name|BINOP_XOR
init|=
literal|12
block|}
enum|;
comment|/// These are values used in the bitcode files to encode AtomicRMW operations.
comment|/// The values of these enums have no fixed relation to the LLVM IR enum
comment|/// values.  Changing these will break compatibility with old files.
enum|enum
name|RMWOperations
block|{
name|RMW_XCHG
init|=
literal|0
block|,
name|RMW_ADD
init|=
literal|1
block|,
name|RMW_SUB
init|=
literal|2
block|,
name|RMW_AND
init|=
literal|3
block|,
name|RMW_NAND
init|=
literal|4
block|,
name|RMW_OR
init|=
literal|5
block|,
name|RMW_XOR
init|=
literal|6
block|,
name|RMW_MAX
init|=
literal|7
block|,
name|RMW_MIN
init|=
literal|8
block|,
name|RMW_UMAX
init|=
literal|9
block|,
name|RMW_UMIN
init|=
literal|10
block|}
enum|;
comment|/// OverflowingBinaryOperatorOptionalFlags - Flags for serializing
comment|/// OverflowingBinaryOperator's SubclassOptionalData contents.
enum|enum
name|OverflowingBinaryOperatorOptionalFlags
block|{
name|OBO_NO_UNSIGNED_WRAP
init|=
literal|0
block|,
name|OBO_NO_SIGNED_WRAP
init|=
literal|1
block|}
enum|;
comment|/// PossiblyExactOperatorOptionalFlags - Flags for serializing
comment|/// PossiblyExactOperator's SubclassOptionalData contents.
enum|enum
name|PossiblyExactOperatorOptionalFlags
block|{
name|PEO_EXACT
init|=
literal|0
block|}
enum|;
comment|/// Encoded AtomicOrdering values.
enum|enum
name|AtomicOrderingCodes
block|{
name|ORDERING_NOTATOMIC
init|=
literal|0
block|,
name|ORDERING_UNORDERED
init|=
literal|1
block|,
name|ORDERING_MONOTONIC
init|=
literal|2
block|,
name|ORDERING_ACQUIRE
init|=
literal|3
block|,
name|ORDERING_RELEASE
init|=
literal|4
block|,
name|ORDERING_ACQREL
init|=
literal|5
block|,
name|ORDERING_SEQCST
init|=
literal|6
block|}
enum|;
comment|/// Encoded SynchronizationScope values.
enum|enum
name|AtomicSynchScopeCodes
block|{
name|SYNCHSCOPE_SINGLETHREAD
init|=
literal|0
block|,
name|SYNCHSCOPE_CROSSTHREAD
init|=
literal|1
block|}
enum|;
comment|// The function body block (FUNCTION_BLOCK_ID) describes function bodies.  It
comment|// can contain a constant block (CONSTANTS_BLOCK_ID).
enum|enum
name|FunctionCodes
block|{
name|FUNC_CODE_DECLAREBLOCKS
init|=
literal|1
block|,
comment|// DECLAREBLOCKS: [n]
name|FUNC_CODE_INST_BINOP
init|=
literal|2
block|,
comment|// BINOP:      [opcode, ty, opval, opval]
name|FUNC_CODE_INST_CAST
init|=
literal|3
block|,
comment|// CAST:       [opcode, ty, opty, opval]
name|FUNC_CODE_INST_GEP
init|=
literal|4
block|,
comment|// GEP:        [n x operands]
name|FUNC_CODE_INST_SELECT
init|=
literal|5
block|,
comment|// SELECT:     [ty, opval, opval, opval]
name|FUNC_CODE_INST_EXTRACTELT
init|=
literal|6
block|,
comment|// EXTRACTELT: [opty, opval, opval]
name|FUNC_CODE_INST_INSERTELT
init|=
literal|7
block|,
comment|// INSERTELT:  [ty, opval, opval, opval]
name|FUNC_CODE_INST_SHUFFLEVEC
init|=
literal|8
block|,
comment|// SHUFFLEVEC: [ty, opval, opval, opval]
name|FUNC_CODE_INST_CMP
init|=
literal|9
block|,
comment|// CMP:        [opty, opval, opval, pred]
name|FUNC_CODE_INST_RET
init|=
literal|10
block|,
comment|// RET:        [opty,opval<both optional>]
name|FUNC_CODE_INST_BR
init|=
literal|11
block|,
comment|// BR:         [bb#, bb#, cond] or [bb#]
name|FUNC_CODE_INST_SWITCH
init|=
literal|12
block|,
comment|// SWITCH:     [opty, op0, op1, ...]
name|FUNC_CODE_INST_INVOKE
init|=
literal|13
block|,
comment|// INVOKE:     [attr, fnty, op0,op1, ...]
comment|// 14 is unused.
name|FUNC_CODE_INST_UNREACHABLE
init|=
literal|15
block|,
comment|// UNREACHABLE
name|FUNC_CODE_INST_PHI
init|=
literal|16
block|,
comment|// PHI:        [ty, val0,bb0, ...]
comment|// 17 is unused.
comment|// 18 is unused.
name|FUNC_CODE_INST_ALLOCA
init|=
literal|19
block|,
comment|// ALLOCA:     [instty, op, align]
name|FUNC_CODE_INST_LOAD
init|=
literal|20
block|,
comment|// LOAD:       [opty, op, align, vol]
comment|// 21 is unused.
comment|// 22 is unused.
name|FUNC_CODE_INST_VAARG
init|=
literal|23
block|,
comment|// VAARG:      [valistty, valist, instty]
comment|// This store code encodes the pointer type, rather than the value type
comment|// this is so information only available in the pointer type (e.g. address
comment|// spaces) is retained.
name|FUNC_CODE_INST_STORE
init|=
literal|24
block|,
comment|// STORE:      [ptrty,ptr,val, align, vol]
comment|// 25 is unused.
name|FUNC_CODE_INST_EXTRACTVAL
init|=
literal|26
block|,
comment|// EXTRACTVAL: [n x operands]
name|FUNC_CODE_INST_INSERTVAL
init|=
literal|27
block|,
comment|// INSERTVAL:  [n x operands]
comment|// fcmp/icmp returning Int1TY or vector of Int1Ty. Same as CMP, exists to
comment|// support legacy vicmp/vfcmp instructions.
name|FUNC_CODE_INST_CMP2
init|=
literal|28
block|,
comment|// CMP2:       [opty, opval, opval, pred]
comment|// new select on i1 or [N x i1]
name|FUNC_CODE_INST_VSELECT
init|=
literal|29
block|,
comment|// VSELECT:    [ty,opval,opval,predty,pred]
name|FUNC_CODE_INST_INBOUNDS_GEP
init|=
literal|30
block|,
comment|// INBOUNDS_GEP: [n x operands]
name|FUNC_CODE_INST_INDIRECTBR
init|=
literal|31
block|,
comment|// INDIRECTBR: [opty, op0, op1, ...]
comment|// 32 is unused.
name|FUNC_CODE_DEBUG_LOC_AGAIN
init|=
literal|33
block|,
comment|// DEBUG_LOC_AGAIN
name|FUNC_CODE_INST_CALL
init|=
literal|34
block|,
comment|// CALL:       [attr, fnty, fnid, args...]
name|FUNC_CODE_DEBUG_LOC
init|=
literal|35
block|,
comment|// DEBUG_LOC:  [Line,Col,ScopeVal, IAVal]
name|FUNC_CODE_INST_FENCE
init|=
literal|36
block|,
comment|// FENCE: [ordering, synchscope]
name|FUNC_CODE_INST_CMPXCHG
init|=
literal|37
block|,
comment|// CMPXCHG: [ptrty,ptr,cmp,new, align, vol,
comment|//           ordering, synchscope]
name|FUNC_CODE_INST_ATOMICRMW
init|=
literal|38
block|,
comment|// ATOMICRMW: [ptrty,ptr,val, operation,
comment|//             align, vol,
comment|//             ordering, synchscope]
name|FUNC_CODE_INST_RESUME
init|=
literal|39
block|,
comment|// RESUME:     [opval]
name|FUNC_CODE_INST_LANDINGPAD
init|=
literal|40
block|,
comment|// LANDINGPAD: [ty,val,val,num,id0,val0...]
name|FUNC_CODE_INST_LOADATOMIC
init|=
literal|41
block|,
comment|// LOAD: [opty, op, align, vol,
comment|//        ordering, synchscope]
name|FUNC_CODE_INST_STOREATOMIC
init|=
literal|42
comment|// STORE: [ptrty,ptr,val, align, vol
comment|//         ordering, synchscope]
block|}
enum|;
enum|enum
name|UseListCodes
block|{
name|USELIST_CODE_ENTRY
init|=
literal|1
comment|// USELIST_CODE_ENTRY: TBD.
block|}
enum|;
enum|enum
name|AttributeKindCodes
block|{
comment|// = 0 is unused
name|ATTR_KIND_ALIGNMENT
init|=
literal|1
block|,
name|ATTR_KIND_ALWAYS_INLINE
init|=
literal|2
block|,
name|ATTR_KIND_BY_VAL
init|=
literal|3
block|,
name|ATTR_KIND_INLINE_HINT
init|=
literal|4
block|,
name|ATTR_KIND_IN_REG
init|=
literal|5
block|,
name|ATTR_KIND_MIN_SIZE
init|=
literal|6
block|,
name|ATTR_KIND_NAKED
init|=
literal|7
block|,
name|ATTR_KIND_NEST
init|=
literal|8
block|,
name|ATTR_KIND_NO_ALIAS
init|=
literal|9
block|,
name|ATTR_KIND_NO_BUILTIN
init|=
literal|10
block|,
name|ATTR_KIND_NO_CAPTURE
init|=
literal|11
block|,
name|ATTR_KIND_NO_DUPLICATE
init|=
literal|12
block|,
name|ATTR_KIND_NO_IMPLICIT_FLOAT
init|=
literal|13
block|,
name|ATTR_KIND_NO_INLINE
init|=
literal|14
block|,
name|ATTR_KIND_NON_LAZY_BIND
init|=
literal|15
block|,
name|ATTR_KIND_NO_RED_ZONE
init|=
literal|16
block|,
name|ATTR_KIND_NO_RETURN
init|=
literal|17
block|,
name|ATTR_KIND_NO_UNWIND
init|=
literal|18
block|,
name|ATTR_KIND_OPTIMIZE_FOR_SIZE
init|=
literal|19
block|,
name|ATTR_KIND_READ_NONE
init|=
literal|20
block|,
name|ATTR_KIND_READ_ONLY
init|=
literal|21
block|,
name|ATTR_KIND_RETURNED
init|=
literal|22
block|,
name|ATTR_KIND_RETURNS_TWICE
init|=
literal|23
block|,
name|ATTR_KIND_S_EXT
init|=
literal|24
block|,
name|ATTR_KIND_STACK_ALIGNMENT
init|=
literal|25
block|,
name|ATTR_KIND_STACK_PROTECT
init|=
literal|26
block|,
name|ATTR_KIND_STACK_PROTECT_REQ
init|=
literal|27
block|,
name|ATTR_KIND_STACK_PROTECT_STRONG
init|=
literal|28
block|,
name|ATTR_KIND_STRUCT_RET
init|=
literal|29
block|,
name|ATTR_KIND_SANITIZE_ADDRESS
init|=
literal|30
block|,
name|ATTR_KIND_SANITIZE_THREAD
init|=
literal|31
block|,
name|ATTR_KIND_SANITIZE_MEMORY
init|=
literal|32
block|,
name|ATTR_KIND_UW_TABLE
init|=
literal|33
block|,
name|ATTR_KIND_Z_EXT
init|=
literal|34
block|,
name|ATTR_KIND_BUILTIN
init|=
literal|35
block|,
name|ATTR_KIND_COLD
init|=
literal|36
block|,
name|ATTR_KIND_OPTIMIZE_NONE
init|=
literal|37
block|}
enum|;
block|}
comment|// End bitc namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

