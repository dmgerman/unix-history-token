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

begin_include
include|#
directive|include
file|"llvm/Support/Wasm.h"
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
name|MVT
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
name|Target
modifier|&
name|getTheWebAssemblyTarget32
parameter_list|()
function_decl|;
name|Target
modifier|&
name|getTheWebAssemblyTarget64
parameter_list|()
function_decl|;
name|MCCodeEmitter
modifier|*
name|createWebAssemblyMCCodeEmitter
parameter_list|(
specifier|const
name|MCInstrInfo
modifier|&
name|MCII
parameter_list|,
name|MCContext
modifier|&
name|Ctx
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
name|MCObjectWriter
modifier|*
name|createWebAssemblyWasmObjectWriter
parameter_list|(
name|raw_pwrite_stream
modifier|&
name|OS
parameter_list|,
name|bool
name|Is64Bit
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
comment|/// Local index.
name|OPERAND_LOCAL
block|,
comment|/// Global index.
name|OPERAND_GLOBAL
block|,
comment|/// 32-bit integer immediates.
name|OPERAND_I32IMM
block|,
comment|/// 64-bit integer immediates.
name|OPERAND_I64IMM
block|,
comment|/// 32-bit floating-point immediates.
name|OPERAND_F32IMM
block|,
comment|/// 64-bit floating-point immediates.
name|OPERAND_F64IMM
block|,
comment|/// 32-bit unsigned function indices.
name|OPERAND_FUNCTION32
block|,
comment|/// 32-bit unsigned memory offsets.
name|OPERAND_OFFSET32
block|,
comment|/// p2align immediate for load and store address alignment.
name|OPERAND_P2ALIGN
block|,
comment|/// signature immediate for block/loop.
name|OPERAND_SIGNATURE
block|,
comment|/// type signature immediate for call_indirect.
name|OPERAND_TYPEINDEX
block|, }
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
block|}
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
name|LoadAddressOperandNo
init|=
literal|3
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|StoreAddressOperandNo
init|=
literal|2
decl_stmt|;
comment|/// The operand number of the load or store p2align in load/store instructions.
specifier|static
specifier|const
name|unsigned
name|LoadP2AlignOperandNo
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|StoreP2AlignOperandNo
init|=
literal|0
decl_stmt|;
comment|/// This is used to indicate block signatures.
name|enum
name|class
name|ExprType
block|{
name|Void
operator|=
operator|-
literal|0x40
operator|,
name|I32
operator|=
operator|-
literal|0x01
operator|,
name|I64
operator|=
operator|-
literal|0x02
operator|,
name|F32
operator|=
operator|-
literal|0x03
operator|,
name|F64
operator|=
operator|-
literal|0x04
operator|,
name|I8x16
operator|=
operator|-
literal|0x05
operator|,
name|I16x8
operator|=
operator|-
literal|0x06
operator|,
name|I32x4
operator|=
operator|-
literal|0x07
operator|,
name|F32x4
operator|=
operator|-
literal|0x08
operator|,
name|B8x16
operator|=
operator|-
literal|0x09
operator|,
name|B16x8
operator|=
operator|-
literal|0x0a
operator|,
name|B32x4
operator|=
operator|-
literal|0x0b
block|}
empty_stmt|;
comment|/// Instruction opcodes emitted via means other than CodeGen.
specifier|static
specifier|const
name|unsigned
name|Nop
init|=
literal|0x01
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|End
init|=
literal|0x0b
decl_stmt|;
name|wasm
operator|::
name|ValType
name|toValType
argument_list|(
specifier|const
name|MVT
operator|&
name|Ty
argument_list|)
expr_stmt|;
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

