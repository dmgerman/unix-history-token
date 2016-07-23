begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- WebAssemblyMCTargetDesc.h - WebAssembly Target Descriptions -*- C++ -*-=//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file provides WebAssembly-specific target descriptions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYMCTARGETDESC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_MCTARGETDESC_WEBASSEMBLYMCTARGETDESC_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmBackend
decl_stmt|;
name|class
name|MCCodeEmitter
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCObjectWriter
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
specifier|extern
name|Target
name|TheWebAssemblyTarget32
decl_stmt|;
specifier|extern
name|Target
name|TheWebAssemblyTarget64
decl_stmt|;
name|MCCodeEmitter
modifier|*
name|createWebAssemblyMCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|)
function_decl|;
name|MCAsmBackend
modifier|*
name|createWebAssemblyAsmBackend
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|)
function_decl|;
name|MCObjectWriter
modifier|*
name|createWebAssemblyELFObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
parameter_list|,
name|uint8_t
name|OSABI
parameter_list|)
function_decl|;
name|namespace
name|WebAssembly
block|{
enum|enum
name|OperandType
block|{
comment|/// Basic block label in a branch construct.
name|OPERAND_BASIC_BLOCK
init|=
name|MCOI
operator|::
name|OPERAND_FIRST_TARGET
block|,
comment|/// 32-bit floating-point immediates.
name|OPERAND_FP32IMM
block|,
comment|/// 64-bit floating-point immediates.
name|OPERAND_FP64IMM
block|,
comment|/// p2align immediate for load and store address alignment.
name|OPERAND_P2ALIGN
block|}
enum|;
comment|/// WebAssembly-specific directive identifiers.
enum|enum
name|Directive
block|{
comment|// FIXME: This is not the real binary encoding.
name|DotParam
init|=
name|UINT64_MAX
operator|-
literal|0
block|,
comment|///< .param
name|DotResult
init|=
name|UINT64_MAX
operator|-
literal|1
block|,
comment|///< .result
name|DotLocal
init|=
name|UINT64_MAX
operator|-
literal|2
block|,
comment|///< .local
name|DotEndFunc
init|=
name|UINT64_MAX
operator|-
literal|3
block|,
comment|///< .endfunc
block|}
enum|;
block|}
comment|// end namespace WebAssembly
name|namespace
name|WebAssemblyII
block|{
enum|enum
block|{
comment|// For variadic instructions, this flag indicates whether an operand
comment|// in the variable_ops range is an immediate value.
name|VariableOpIsImmediate
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|// For immediate values in the variable_ops range, this flag indicates
comment|// whether the value represents a control-flow label.
name|VariableOpImmediateIsLabel
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|, }
enum|;
block|}
comment|// end namespace WebAssemblyII
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_comment
comment|// Defines symbolic names for WebAssembly registers. This defines a mapping from
end_comment

begin_comment
comment|// register name to register number.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_REGINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"WebAssemblyGenRegisterInfo.inc"
end_include

begin_comment
comment|// Defines symbolic names for the WebAssembly instructions.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GET_INSTRINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"WebAssemblyGenInstrInfo.inc"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_ENUM
end_define

begin_include
include|#
directive|include
file|"WebAssemblyGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|WebAssembly
block|{
comment|/// Return the default p2align value for a load or store with the given opcode.
specifier|inline
name|unsigned
name|GetDefaultP2Align
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
switch|switch
condition|(
name|Opcode
condition|)
block|{
case|case
name|WebAssembly
operator|::
name|LOAD8_S_I32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD8_U_I32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD8_S_I64
case|:
case|case
name|WebAssembly
operator|::
name|LOAD8_U_I64
case|:
case|case
name|WebAssembly
operator|::
name|STORE8_I32
case|:
case|case
name|WebAssembly
operator|::
name|STORE8_I64
case|:
return|return
literal|0
return|;
case|case
name|WebAssembly
operator|::
name|LOAD16_S_I32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD16_U_I32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD16_S_I64
case|:
case|case
name|WebAssembly
operator|::
name|LOAD16_U_I64
case|:
case|case
name|WebAssembly
operator|::
name|STORE16_I32
case|:
case|case
name|WebAssembly
operator|::
name|STORE16_I64
case|:
return|return
literal|1
return|;
case|case
name|WebAssembly
operator|::
name|LOAD_I32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD_F32
case|:
case|case
name|WebAssembly
operator|::
name|STORE_I32
case|:
case|case
name|WebAssembly
operator|::
name|STORE_F32
case|:
case|case
name|WebAssembly
operator|::
name|LOAD32_S_I64
case|:
case|case
name|WebAssembly
operator|::
name|LOAD32_U_I64
case|:
case|case
name|WebAssembly
operator|::
name|STORE32_I64
case|:
return|return
literal|2
return|;
case|case
name|WebAssembly
operator|::
name|LOAD_I64
case|:
case|case
name|WebAssembly
operator|::
name|LOAD_F64
case|:
case|case
name|WebAssembly
operator|::
name|STORE_I64
case|:
case|case
name|WebAssembly
operator|::
name|STORE_F64
case|:
return|return
literal|3
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Only loads and stores have p2align values"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// The operand number of the load or store address in load/store instructions.
specifier|static
specifier|const
name|unsigned
name|MemOpAddressOperandNo
init|=
literal|2
decl_stmt|;
comment|/// The operand number of the stored value in a store instruction.
specifier|static
specifier|const
name|unsigned
name|StoreValueOperandNo
init|=
literal|4
decl_stmt|;
block|}
comment|// end namespace WebAssembly
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

