begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LLToken.h - Token Codes for LLVM Assembly Files ----------*- C++ -*-===//
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
comment|// This file defines the enums for the .ll lexer.
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
name|LIBS_ASMPARSER_LLTOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|LIBS_ASMPARSER_LLTOKEN_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|lltok
block|{
enum|enum
name|Kind
block|{
comment|// Markers
name|Eof
block|,
name|Error
block|,
comment|// Tokens with no info.
name|dotdotdot
block|,
comment|// ...
name|equal
block|,
name|comma
block|,
comment|// =  ,
name|star
block|,
comment|// *
name|lsquare
block|,
name|rsquare
block|,
comment|// [  ]
name|lbrace
block|,
name|rbrace
block|,
comment|// {  }
name|less
block|,
name|greater
block|,
comment|//<>
name|lparen
block|,
name|rparen
block|,
comment|// (  )
name|backslash
block|,
comment|// \    (not /)
name|exclaim
block|,
comment|// !
name|kw_x
block|,
name|kw_begin
block|,
name|kw_end
block|,
name|kw_true
block|,
name|kw_false
block|,
name|kw_declare
block|,
name|kw_define
block|,
name|kw_global
block|,
name|kw_constant
block|,
name|kw_private
block|,
name|kw_linker_private
block|,
name|kw_internal
block|,
name|kw_linkonce
block|,
name|kw_linkonce_odr
block|,
name|kw_weak
block|,
name|kw_weak_odr
block|,
name|kw_appending
block|,
name|kw_dllimport
block|,
name|kw_dllexport
block|,
name|kw_common
block|,
name|kw_available_externally
block|,
name|kw_default
block|,
name|kw_hidden
block|,
name|kw_protected
block|,
name|kw_extern_weak
block|,
name|kw_external
block|,
name|kw_thread_local
block|,
name|kw_zeroinitializer
block|,
name|kw_undef
block|,
name|kw_null
block|,
name|kw_to
block|,
name|kw_tail
block|,
name|kw_target
block|,
name|kw_triple
block|,
name|kw_deplibs
block|,
name|kw_datalayout
block|,
name|kw_volatile
block|,
name|kw_nuw
block|,
name|kw_nsw
block|,
name|kw_exact
block|,
name|kw_inbounds
block|,
name|kw_align
block|,
name|kw_addrspace
block|,
name|kw_section
block|,
name|kw_alias
block|,
name|kw_module
block|,
name|kw_asm
block|,
name|kw_sideeffect
block|,
name|kw_alignstack
block|,
name|kw_gc
block|,
name|kw_c
block|,
name|kw_cc
block|,
name|kw_ccc
block|,
name|kw_fastcc
block|,
name|kw_coldcc
block|,
name|kw_x86_stdcallcc
block|,
name|kw_x86_fastcallcc
block|,
name|kw_arm_apcscc
block|,
name|kw_arm_aapcscc
block|,
name|kw_arm_aapcs_vfpcc
block|,
name|kw_msp430_intrcc
block|,
name|kw_signext
block|,
name|kw_zeroext
block|,
name|kw_inreg
block|,
name|kw_sret
block|,
name|kw_nounwind
block|,
name|kw_noreturn
block|,
name|kw_noalias
block|,
name|kw_nocapture
block|,
name|kw_byval
block|,
name|kw_nest
block|,
name|kw_readnone
block|,
name|kw_readonly
block|,
name|kw_inlinehint
block|,
name|kw_noinline
block|,
name|kw_alwaysinline
block|,
name|kw_optsize
block|,
name|kw_ssp
block|,
name|kw_sspreq
block|,
name|kw_noredzone
block|,
name|kw_noimplicitfloat
block|,
name|kw_naked
block|,
name|kw_type
block|,
name|kw_opaque
block|,
name|kw_eq
block|,
name|kw_ne
block|,
name|kw_slt
block|,
name|kw_sgt
block|,
name|kw_sle
block|,
name|kw_sge
block|,
name|kw_ult
block|,
name|kw_ugt
block|,
name|kw_ule
block|,
name|kw_uge
block|,
name|kw_oeq
block|,
name|kw_one
block|,
name|kw_olt
block|,
name|kw_ogt
block|,
name|kw_ole
block|,
name|kw_oge
block|,
name|kw_ord
block|,
name|kw_uno
block|,
name|kw_ueq
block|,
name|kw_une
block|,
comment|// Instruction Opcodes (Opcode in UIntVal).
name|kw_add
block|,
name|kw_fadd
block|,
name|kw_sub
block|,
name|kw_fsub
block|,
name|kw_mul
block|,
name|kw_fmul
block|,
name|kw_udiv
block|,
name|kw_sdiv
block|,
name|kw_fdiv
block|,
name|kw_urem
block|,
name|kw_srem
block|,
name|kw_frem
block|,
name|kw_shl
block|,
name|kw_lshr
block|,
name|kw_ashr
block|,
name|kw_and
block|,
name|kw_or
block|,
name|kw_xor
block|,
name|kw_icmp
block|,
name|kw_fcmp
block|,
name|kw_phi
block|,
name|kw_call
block|,
name|kw_trunc
block|,
name|kw_zext
block|,
name|kw_sext
block|,
name|kw_fptrunc
block|,
name|kw_fpext
block|,
name|kw_uitofp
block|,
name|kw_sitofp
block|,
name|kw_fptoui
block|,
name|kw_fptosi
block|,
name|kw_inttoptr
block|,
name|kw_ptrtoint
block|,
name|kw_bitcast
block|,
name|kw_select
block|,
name|kw_va_arg
block|,
name|kw_ret
block|,
name|kw_br
block|,
name|kw_switch
block|,
name|kw_indirectbr
block|,
name|kw_invoke
block|,
name|kw_unwind
block|,
name|kw_unreachable
block|,
name|kw_malloc
block|,
name|kw_alloca
block|,
name|kw_free
block|,
name|kw_load
block|,
name|kw_store
block|,
name|kw_getelementptr
block|,
name|kw_extractelement
block|,
name|kw_insertelement
block|,
name|kw_shufflevector
block|,
name|kw_getresult
block|,
name|kw_extractvalue
block|,
name|kw_insertvalue
block|,
name|kw_blockaddress
block|,
comment|// Unsigned Valued tokens (UIntVal).
name|GlobalID
block|,
comment|// @42
name|LocalVarID
block|,
comment|// %42
comment|// String valued tokens (StrVal).
name|LabelStr
block|,
comment|// foo:
name|GlobalVar
block|,
comment|// @foo @"foo"
name|LocalVar
block|,
comment|// %foo %"foo"
name|MetadataVar
block|,
comment|// !foo
name|StringConstant
block|,
comment|// "foo"
comment|// Type valued tokens (TyVal).
name|Type
block|,
name|APFloat
block|,
comment|// APFloatVal
name|APSInt
comment|// APSInt
block|}
enum|;
block|}
comment|// end namespace lltok
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

