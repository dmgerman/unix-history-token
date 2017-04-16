begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPUBaseInfo.h - Top level definitions for AMDGPU ------*- C++ -*-===//
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
file|"AMDGPU.h"
end_include

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_include
include|#
directive|include
file|"SIDefines.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCInstrDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

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
name|MachineMemOperand
decl_stmt|;
name|class
name|MCContext
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
name|class
name|Triple
decl_stmt|;
name|namespace
name|AMDGPU
block|{
name|namespace
name|IsaInfo
block|{
enum|enum
block|{
comment|// The closed Vulkan driver sets 96, which limits the wave count to 8 but
comment|// doesn't spill SGPRs as much as when 80 is set.
name|FIXED_NUM_SGPRS_FOR_INIT_BUG
init|=
literal|96
block|}
enum|;
comment|/// \brief Instruction set architecture version.
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
comment|/// \returns Isa version for given subtarget \p Features.
name|IsaVersion
name|getIsaVersion
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Wavefront size for given subtarget \p Features.
name|unsigned
name|getWavefrontSize
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Local memory size in bytes for given subtarget \p Features.
name|unsigned
name|getLocalMemorySize
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Number of execution units per compute unit for given subtarget \p
comment|/// Features.
name|unsigned
name|getEUsPerCU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of work groups per compute unit for given subtarget
comment|/// \p Features and limited by given \p FlatWorkGroupSize.
name|unsigned
name|getMaxWorkGroupsPerCU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|FlatWorkGroupSize
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of waves per compute unit for given subtarget \p
comment|/// Features without any kind of limitation.
name|unsigned
name|getMaxWavesPerCU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of waves per compute unit for given subtarget \p
comment|/// Features and limited by given \p FlatWorkGroupSize.
name|unsigned
name|getMaxWavesPerCU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|FlatWorkGroupSize
parameter_list|)
function_decl|;
comment|/// \returns Minimum number of waves per execution unit for given subtarget \p
comment|/// Features.
name|unsigned
name|getMinWavesPerEU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of waves per execution unit for given subtarget \p
comment|/// Features without any kind of limitation.
name|unsigned
name|getMaxWavesPerEU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of waves per execution unit for given subtarget \p
comment|/// Features and limited by given \p FlatWorkGroupSize.
name|unsigned
name|getMaxWavesPerEU
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|FlatWorkGroupSize
parameter_list|)
function_decl|;
comment|/// \returns Minimum flat work group size for given subtarget \p Features.
name|unsigned
name|getMinFlatWorkGroupSize
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Maximum flat work group size for given subtarget \p Features.
name|unsigned
name|getMaxFlatWorkGroupSize
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Number of waves per work group for given subtarget \p Features and
comment|/// limited by given \p FlatWorkGroupSize.
name|unsigned
name|getWavesPerWorkGroup
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|FlatWorkGroupSize
parameter_list|)
function_decl|;
comment|/// \returns SGPR allocation granularity for given subtarget \p Features.
name|unsigned
name|getSGPRAllocGranule
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns SGPR encoding granularity for given subtarget \p Features.
name|unsigned
name|getSGPREncodingGranule
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Total number of SGPRs for given subtarget \p Features.
name|unsigned
name|getTotalNumSGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Addressable number of SGPRs for given subtarget \p Features.
name|unsigned
name|getAddressableNumSGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Minimum number of SGPRs that meets the given number of waves per
comment|/// execution unit requirement for given subtarget \p Features.
name|unsigned
name|getMinNumSGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|WavesPerEU
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of SGPRs that meets the given number of waves per
comment|/// execution unit requirement for given subtarget \p Features.
name|unsigned
name|getMaxNumSGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|WavesPerEU
parameter_list|,
name|bool
name|Addressable
parameter_list|)
function_decl|;
comment|/// \returns VGPR allocation granularity for given subtarget \p Features.
name|unsigned
name|getVGPRAllocGranule
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns VGPR encoding granularity for given subtarget \p Features.
name|unsigned
name|getVGPREncodingGranule
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Total number of VGPRs for given subtarget \p Features.
name|unsigned
name|getTotalNumVGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Addressable number of VGPRs for given subtarget \p Features.
name|unsigned
name|getAddressableNumVGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|/// \returns Minimum number of VGPRs that meets given number of waves per
comment|/// execution unit requirement for given subtarget \p Features.
name|unsigned
name|getMinNumVGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|WavesPerEU
parameter_list|)
function_decl|;
comment|/// \returns Maximum number of VGPRs that meets given number of waves per
comment|/// execution unit requirement for given subtarget \p Features.
name|unsigned
name|getMaxNumVGPRs
parameter_list|(
specifier|const
name|FeatureBitset
modifier|&
name|Features
parameter_list|,
name|unsigned
name|WavesPerEU
parameter_list|)
function_decl|;
block|}
comment|// end namespace IsaInfo
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
parameter_list|,
name|AMDGPUAS
name|AS
parameter_list|)
function_decl|;
name|bool
name|isGlobalSegment
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|AMDGPUAS
name|AS
parameter_list|)
function_decl|;
name|bool
name|isReadOnlySegment
parameter_list|(
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|AMDGPUAS
name|AS
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
comment|/// \returns Vmcnt bit mask for given isa \p Version.
name|unsigned
name|getVmcntBitMask
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|)
decl_stmt|;
comment|/// \returns Expcnt bit mask for given isa \p Version.
name|unsigned
name|getExpcntBitMask
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|)
decl_stmt|;
comment|/// \returns Lgkmcnt bit mask for given isa \p Version.
name|unsigned
name|getLgkmcntBitMask
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|)
decl_stmt|;
comment|/// \returns Waitcnt bit mask for given isa \p Version.
name|unsigned
name|getWaitcntBitMask
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|)
decl_stmt|;
comment|/// \returns Decoded Vmcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeVmcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|)
decl_stmt|;
comment|/// \returns Decoded Expcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeExpcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|)
decl_stmt|;
comment|/// \returns Decoded Lgkmcnt from given \p Waitcnt for given isa \p Version.
name|unsigned
name|decodeLgkmcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|)
decl_stmt|;
comment|/// \brief Decodes Vmcnt, Expcnt and Lgkmcnt from given \p Waitcnt for given isa
comment|/// \p Version, and writes decoded values into \p Vmcnt, \p Expcnt and
comment|/// \p Lgkmcnt respectively.
comment|///
comment|/// \details \p Vmcnt, \p Expcnt and \p Lgkmcnt are decoded as follows:
comment|///     \p Vmcnt = \p Waitcnt[3:0]                      (pre-gfx9 only)
comment|///     \p Vmcnt = \p Waitcnt[3:0] | \p Waitcnt[15:14]  (gfx9+ only)
comment|///     \p Expcnt = \p Waitcnt[6:4]
comment|///     \p Lgkmcnt = \p Waitcnt[11:8]
name|void
name|decodeWaitcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|,
name|unsigned
operator|&
name|Vmcnt
argument_list|,
name|unsigned
operator|&
name|Expcnt
argument_list|,
name|unsigned
operator|&
name|Lgkmcnt
argument_list|)
decl_stmt|;
comment|/// \returns \p Waitcnt with encoded \p Vmcnt for given isa \p Version.
name|unsigned
name|encodeVmcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|,
name|unsigned
name|Vmcnt
argument_list|)
decl_stmt|;
comment|/// \returns \p Waitcnt with encoded \p Expcnt for given isa \p Version.
name|unsigned
name|encodeExpcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|,
name|unsigned
name|Expcnt
argument_list|)
decl_stmt|;
comment|/// \returns \p Waitcnt with encoded \p Lgkmcnt for given isa \p Version.
name|unsigned
name|encodeLgkmcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Waitcnt
argument_list|,
name|unsigned
name|Lgkmcnt
argument_list|)
decl_stmt|;
comment|/// \brief Encodes \p Vmcnt, \p Expcnt and \p Lgkmcnt into Waitcnt for given isa
comment|/// \p Version.
comment|///
comment|/// \details \p Vmcnt, \p Expcnt and \p Lgkmcnt are encoded as follows:
comment|///     Waitcnt[3:0]   = \p Vmcnt       (pre-gfx9 only)
comment|///     Waitcnt[3:0]   = \p Vmcnt[3:0]  (gfx9+ only)
comment|///     Waitcnt[6:4]   = \p Expcnt
comment|///     Waitcnt[11:8]  = \p Lgkmcnt
comment|///     Waitcnt[15:14] = \p Vmcnt[5:4]  (gfx9+ only)
comment|///
comment|/// \returns Waitcnt with encoded \p Vmcnt, \p Expcnt and \p Lgkmcnt for given
comment|/// isa \p Version.
name|unsigned
name|encodeWaitcnt
argument_list|(
specifier|const
name|IsaInfo
operator|::
name|IsaVersion
operator|&
name|Version
argument_list|,
name|unsigned
name|Vmcnt
argument_list|,
name|unsigned
name|Expcnt
argument_list|,
name|unsigned
name|Lgkmcnt
argument_list|)
decl_stmt|;
name|unsigned
name|getInitialPSInputAddr
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
name|LLVM_READNONE
name|bool
name|isShader
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl_stmt|;
name|LLVM_READNONE
name|bool
name|isCompute
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl_stmt|;
name|LLVM_READNONE
name|bool
name|isEntryFunctionCC
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
decl_stmt|;
comment|// FIXME: Remove this when calling conventions cleaned up
name|LLVM_READNONE
specifier|inline
name|bool
name|isKernel
argument_list|(
name|CallingConv
operator|::
name|ID
name|CC
argument_list|)
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
case|case
name|CallingConv
operator|::
name|C
case|:
case|case
name|CallingConv
operator|::
name|AMDGPU_KERNEL
case|:
case|case
name|CallingConv
operator|::
name|SPIR_KERNEL
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
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
comment|/// \brief Convert hardware register \p Reg to a pseudo register
name|LLVM_READNONE
name|unsigned
name|mc2PseudoReg
parameter_list|(
name|unsigned
name|Reg
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
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_V2INT16
case|:
case|case
name|AMDGPU
operator|::
name|OPERAND_REG_INLINE_C_V2FP16
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
name|LLVM_READNONE
name|bool
name|isInlinableLiteralV216
parameter_list|(
name|int32_t
name|Literal
parameter_list|,
name|bool
name|HasInv2Pi
parameter_list|)
function_decl|;
name|bool
name|isUniformMMO
parameter_list|(
specifier|const
name|MachineMemOperand
modifier|*
name|MMO
parameter_list|)
function_decl|;
comment|/// \returns The encoding that will be used for \p ByteOffset in the SMRD
comment|/// offset field.
name|int64_t
name|getSMRDEncodedOffset
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|ST
parameter_list|,
name|int64_t
name|ByteOffset
parameter_list|)
function_decl|;
comment|/// \returns true if this offset is small enough to fit in the SMRD
comment|/// offset field.  \p ByteOffset should be the offset in bytes and
comment|/// not the encoded offset.
name|bool
name|isLegalSMRDImmOffset
parameter_list|(
specifier|const
name|MCSubtargetInfo
modifier|&
name|ST
parameter_list|,
name|int64_t
name|ByteOffset
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

begin_comment
comment|// LLVM_LIB_TARGET_AMDGPU_UTILS_AMDGPUBASEINFO_H
end_comment

end_unit

