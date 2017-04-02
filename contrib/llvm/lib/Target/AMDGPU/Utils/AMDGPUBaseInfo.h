begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUBaseInfo.h - Top level definitions for AMDGPU -----*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUBASEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUBASEINFO_H
end_define

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"SIDefines.h"
end_include

begin_define
define|#
directive|define
name|GET_INSTRINFO_OPERAND_ENUM
end_define

begin_include
include|#
directive|include
file|"AMDGPUGenInstrInfo.inc"
end_include

begin_undef
undef|#
directive|undef
name|GET_INSTRINFO_OPERAND_ENUM
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FeatureBitset
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|MCRegisterClass
decl_stmt|;
name|class
name|MCRegisterInfo
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCSubtargetInfo
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|LLVM_READONLY
name|int16_t
name|getNamedOperandIdx
parameter_list|(
name|uint16_t
name|Opcode
parameter_list|,
name|uint16_t
name|NamedIdx
parameter_list|)
function_decl|;
struct|struct
name|IsaVersion
block|{
name|unsigned
name|Major
decl_stmt|;
name|unsigned
name|Minor
decl_stmt|;
name|unsigned
name|Stepping
decl_stmt|;
block|}
struct|;
name|IsaVersion
name|getIsaVersion
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
name|void
name|initDefaultAMDKernelCodeT
parameter_list|(
name|amd_kernel_code_t
modifier|&
name|Header
parameter_list|,
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
name|MCSection
modifier|*
name|getHSATextSection
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCSection
modifier|*
name|getHSADataGlobalAgentSection
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCSection
modifier|*
name|getHSADataGlobalProgramSection
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|MCSection
modifier|*
name|getHSARodataReadonlyAgentSection
parameter_list|(
name|MCContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
name|bool
name|isGroupSegment
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
name|bool
name|isGlobalSegment
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
name|bool
name|isReadOnlySegment
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// \returns True if constants should be emitted to .text section for given
comment|/// target triple \p TT, false otherwise.
name|bool
name|shouldEmitConstantsToTextSection
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|)
function_decl|;
comment|/// \returns Integer value requested using \p F's \p Name attribute.
comment|///
comment|/// \returns \p Default if attribute is not present.
comment|///
comment|/// \returns \p Default and emits error if requested value cannot be converted
comment|/// to integer.
name|int
name|getIntegerAttribute
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|int
name|Default
parameter_list|)
function_decl|;
comment|/// \returns A pair of integer values requested using \p F's \p Name attribute
comment|/// in "first[,second]" format ("second" is optional unless \p OnlyFirstRequired
comment|/// is false).
comment|///
comment|/// \returns \p Default if attribute is not present.
comment|///
comment|/// \returns \p Default and emits error if one of the requested values cannot be
comment|/// converted to integer, or \p OnlyFirstRequired is false and "second" value is
comment|/// not present.
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|getIntegerPairAttribute
argument_list|(
argument|const Function&F
argument_list|,
argument|StringRef Name
argument_list|,
argument|std::pair<int
argument_list|,
argument|int> Default
argument_list|,
argument|bool OnlyFirstRequired = false
argument_list|)
expr_stmt|;
comment|/// \returns Waitcnt bit mask for given isa \p Version.
name|unsigned
name|getWaitcntBitMask
parameter_list|(
name|IsaVersion
name|Version
parameter_list|)
function_decl|;
comment|/// \returns Vmcnt bit mask for given isa \p Version.
name|unsigned
name|getVmcntBitMask
parameter_list|(
name|IsaVersion
name|Version
parameter_list|)
function_decl|;
comment|/// \returns Expcnt bit mask for given isa \p Version.
name|unsigned
name|getExpcntBitMask
parameter_list|(
name|IsaVersion
name|Version
parameter_list|)
function_decl|;
comment|/// \returns Lgkmcnt bit mask for given isa \p Version.
name|unsigned
name|getLgkmcntBitMask
parameter_list|(
name|IsaVersion
name|Version
parameter_list|)
function_decl|;
comment|/// \returns Decoded Vmcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeVmcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|)
function_decl|;
comment|/// \returns Decoded Expcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeExpcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|)
function_decl|;
comment|/// \returns Decoded Lgkmcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeLgkmcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|)
function_decl|;
comment|/// \brief Decodes Vmcnt, Expcnt and Lgkmcnt from given \p Waitcnt for given isa
comment|/// \p Version, and writes decoded values into \p Vmcnt, \p Expcnt and
comment|/// \p Lgkmcnt respectively.
comment|///
comment|/// \details \p Vmcnt, \p Expcnt and \p Lgkmcnt are decoded as follows:
comment|///     \p Vmcnt = \p Waitcnt[3:0]
comment|///     \p Expcnt = \p Waitcnt[6:4]
comment|///     \p Lgkmcnt = \p Waitcnt[11:8]
name|void
name|decodeWaitcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|,
name|unsigned
modifier|&
name|Vmcnt
parameter_list|,
name|unsigned
modifier|&
name|Expcnt
parameter_list|,
name|unsigned
modifier|&
name|Lgkmcnt
parameter_list|)
function_decl|;
comment|/// \returns \p Waitcnt with encoded \p Vmcnt for given isa \p Version.
name|unsigned
name|encodeVmcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|,
name|unsigned
name|Vmcnt
parameter_list|)
function_decl|;
comment|/// \returns \p Waitcnt with encoded \p Expcnt for given isa \p Version.
name|unsigned
name|encodeExpcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|,
name|unsigned
name|Expcnt
parameter_list|)
function_decl|;
comment|/// \returns \p Waitcnt with encoded \p Lgkmcnt for given isa \p Version.
name|unsigned
name|encodeLgkmcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Waitcnt
parameter_list|,
name|unsigned
name|Lgkmcnt
parameter_list|)
function_decl|;
comment|/// \brief Encodes \p Vmcnt, \p Expcnt and \p Lgkmcnt into Waitcnt for given isa
comment|/// \p Version.
comment|///
comment|/// \details \p Vmcnt, \p Expcnt and \p Lgkmcnt are encoded as follows:
comment|///     Waitcnt[3:0]  = \p Vmcnt
comment|///     Waitcnt[6:4]  = \p Expcnt
comment|///     Waitcnt[11:8] = \p Lgkmcnt
comment|///
comment|/// \returns Waitcnt with encoded \p Vmcnt, \p Expcnt and \p Lgkmcnt for given
comment|/// isa \p Version.
name|unsigned
name|encodeWaitcnt
parameter_list|(
name|IsaVersion
name|Version
parameter_list|,
name|unsigned
name|Vmcnt
parameter_list|,
name|unsigned
name|Expcnt
parameter_list|,
name|unsigned
name|Lgkmcnt
parameter_list|)
function_decl|;
name|unsigned
name|getInitialPSInputAddr
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|bool
name|isShader
argument_list|(
name|CallingConv
operator|::
name|ID
name|cc
argument_list|)
decl_stmt|;
name|bool
name|isCompute
argument_list|(
name|CallingConv
operator|::
name|ID
name|cc
argument_list|)
decl_stmt|;
name|bool
name|isSI
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|bool
name|isCI
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
name|bool
name|isVI
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
comment|/// If \p Reg is a pseudo reg, return the correct hardware register given
comment|/// \p STI otherwise return \p Reg.
name|unsigned
name|getMCReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MCSubtargetInfo
modifier|&
name|STI
parameter_list|)
function_decl|;
comment|/// \brief Can this operand also contain immediate values?
name|bool
name|isSISrcOperand
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|,
name|unsigned
name|OpNo
parameter_list|)
function_decl|;
comment|/// \brief Is this floating-point operand?
name|bool
name|isSISrcFPOperand
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|,
name|unsigned
name|OpNo
parameter_list|)
function_decl|;
comment|/// \brief Does this opearnd support only inlinable literals?
name|bool
name|isSISrcInlinableOperand
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|,
name|unsigned
name|OpNo
parameter_list|)
function_decl|;
comment|/// \brief Get the size in bits of a register from the register class \p RC.
name|unsigned
name|getRegBitWidth
parameter_list|(
name|unsigned
name|RCID
parameter_list|)
function_decl|;
comment|/// \brief Get the size in bits of a register from the register class \p RC.
name|unsigned
name|getRegBitWidth
parameter_list|(
specifier|const
name|MCRegisterClass
modifier|&
name|RC
parameter_list|)
function_decl|;
comment|/// \brief Get size of register operand
name|unsigned
name|getRegOperandSize
parameter_list|(
specifier|const
name|MCRegisterInfo
modifier|*
name|MRI
parameter_list|,
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|,
name|unsigned
name|OpNo
parameter_list|)
function_decl|;
name|LLVM_READNONE
specifier|inline
name|unsigned
name|getOperandSize
parameter_list|(
specifier|const
name|MCOperandInfo
modifier|&
name|OpInfo
parameter_list|)
block|{
switch|switch
condition|(
name|OpInfo
operator|.
name|OperandType
condition|)
block|{
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_INT32
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_FP32
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_INT32
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_FP32
case|:
return|return
literal|4
return|;
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_INT64
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_FP64
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_INT64
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_FP64
case|:
return|return
literal|8
return|;
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_INT16
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_IMM_FP16
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_INT16
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_FP16
case|:
return|return
literal|2
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"unhandled operand type"
argument_list|)
expr_stmt|;
block|}
block|}
name|LLVM_READNONE
specifier|inline
name|unsigned
name|getOperandSize
parameter_list|(
specifier|const
name|MCInstrDesc
modifier|&
name|Desc
parameter_list|,
name|unsigned
name|OpNo
parameter_list|)
block|{
return|return
name|getOperandSize
argument_list|(
name|Desc
operator|.
name|OpInfo
index|[
name|OpNo
index|]
argument_list|)
return|;
block|}
comment|/// \brief Is this literal inlinable
name|LLVM_READNONE
name|bool
name|isInlinableLiteral64
parameter_list|(
name|int64_t
name|Literal
parameter_list|,
name|bool
name|HasInv2Pi
parameter_list|)
function_decl|;
name|LLVM_READNONE
name|bool
name|isInlinableLiteral32
parameter_list|(
name|int32_t
name|Literal
parameter_list|,
name|bool
name|HasInv2Pi
parameter_list|)
function_decl|;
name|LLVM_READNONE
name|bool
name|isInlinableLiteral16
parameter_list|(
name|int16_t
name|Literal
parameter_list|,
name|bool
name|HasInv2Pi
parameter_list|)
function_decl|;
block|}
comment|// end namespace AMDGPU
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

