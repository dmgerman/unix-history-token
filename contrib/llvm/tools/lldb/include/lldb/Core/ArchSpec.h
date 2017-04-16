begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ArchSpec.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_ArchSpec_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ArchSpec_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// for string
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Platform
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|StringList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Thread
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ArchSpec ArchSpec.h "lldb/Core/ArchSpec.h"
comment|/// @brief An architecture specification class.
comment|///
comment|/// A class designed to be created from a cpu type and subtype, a
comment|/// string representation, or an llvm::Triple.  Keeping all of the
comment|/// conversions of strings to architecture enumeration values confined
comment|/// to this class allows new architecture support to be added easily.
comment|//----------------------------------------------------------------------
name|class
name|ArchSpec
block|{
name|public
label|:
enum|enum
name|MIPSSubType
block|{
name|eMIPSSubType_unknown
block|,
name|eMIPSSubType_mips32
block|,
name|eMIPSSubType_mips32r2
block|,
name|eMIPSSubType_mips32r6
block|,
name|eMIPSSubType_mips32el
block|,
name|eMIPSSubType_mips32r2el
block|,
name|eMIPSSubType_mips32r6el
block|,
name|eMIPSSubType_mips64
block|,
name|eMIPSSubType_mips64r2
block|,
name|eMIPSSubType_mips64r6
block|,
name|eMIPSSubType_mips64el
block|,
name|eMIPSSubType_mips64r2el
block|,
name|eMIPSSubType_mips64r6el
block|,   }
enum|;
comment|// Masks for the ases word of an ABI flags structure.
enum|enum
name|MIPSASE
block|{
name|eMIPSAse_dsp
init|=
literal|0x00000001
block|,
comment|// DSP ASE
name|eMIPSAse_dspr2
init|=
literal|0x00000002
block|,
comment|// DSP R2 ASE
name|eMIPSAse_eva
init|=
literal|0x00000004
block|,
comment|// Enhanced VA Scheme
name|eMIPSAse_mcu
init|=
literal|0x00000008
block|,
comment|// MCU (MicroController) ASE
name|eMIPSAse_mdmx
init|=
literal|0x00000010
block|,
comment|// MDMX ASE
name|eMIPSAse_mips3d
init|=
literal|0x00000020
block|,
comment|// MIPS-3D ASE
name|eMIPSAse_mt
init|=
literal|0x00000040
block|,
comment|// MT ASE
name|eMIPSAse_smartmips
init|=
literal|0x00000080
block|,
comment|// SmartMIPS ASE
name|eMIPSAse_virt
init|=
literal|0x00000100
block|,
comment|// VZ ASE
name|eMIPSAse_msa
init|=
literal|0x00000200
block|,
comment|// MSA ASE
name|eMIPSAse_mips16
init|=
literal|0x00000400
block|,
comment|// MIPS16 ASE
name|eMIPSAse_micromips
init|=
literal|0x00000800
block|,
comment|// MICROMIPS ASE
name|eMIPSAse_xpa
init|=
literal|0x00001000
block|,
comment|// XPA ASE
name|eMIPSAse_mask
init|=
literal|0x00001fff
block|,
name|eMIPSABI_O32
init|=
literal|0x00002000
block|,
name|eMIPSABI_N32
init|=
literal|0x00004000
block|,
name|eMIPSABI_N64
init|=
literal|0x00008000
block|,
name|eMIPSABI_O64
init|=
literal|0x00020000
block|,
name|eMIPSABI_EABI32
init|=
literal|0x00040000
block|,
name|eMIPSABI_EABI64
init|=
literal|0x00080000
block|,
name|eMIPSABI_mask
init|=
literal|0x000ff000
block|}
enum|;
comment|// MIPS Floating point ABI Values
enum|enum
name|MIPS_ABI_FP
block|{
name|eMIPS_ABI_FP_ANY
init|=
literal|0x00000000
block|,
name|eMIPS_ABI_FP_DOUBLE
init|=
literal|0x00100000
block|,
comment|// hard float / -mdouble-float
name|eMIPS_ABI_FP_SINGLE
init|=
literal|0x00200000
block|,
comment|// hard float / -msingle-float
name|eMIPS_ABI_FP_SOFT
init|=
literal|0x00300000
block|,
comment|// soft float
name|eMIPS_ABI_FP_OLD_64
init|=
literal|0x00400000
block|,
comment|// -mips32r2 -mfp64
name|eMIPS_ABI_FP_XX
init|=
literal|0x00500000
block|,
comment|// -mfpxx
name|eMIPS_ABI_FP_64
init|=
literal|0x00600000
block|,
comment|// -mips32r2 -mfp64
name|eMIPS_ABI_FP_64A
init|=
literal|0x00700000
block|,
comment|// -mips32r2 -mfp64 -mno-odd-spreg
name|eMIPS_ABI_FP_mask
init|=
literal|0x00700000
block|}
enum|;
comment|// ARM specific e_flags
enum|enum
name|ARMeflags
block|{
name|eARM_abi_soft_float
init|=
literal|0x00000200
block|,
name|eARM_abi_hard_float
init|=
literal|0x00000400
block|}
enum|;
enum|enum
name|Core
block|{
name|eCore_arm_generic
block|,
name|eCore_arm_armv4
block|,
name|eCore_arm_armv4t
block|,
name|eCore_arm_armv5
block|,
name|eCore_arm_armv5e
block|,
name|eCore_arm_armv5t
block|,
name|eCore_arm_armv6
block|,
name|eCore_arm_armv6m
block|,
name|eCore_arm_armv7
block|,
name|eCore_arm_armv7f
block|,
name|eCore_arm_armv7s
block|,
name|eCore_arm_armv7k
block|,
name|eCore_arm_armv7m
block|,
name|eCore_arm_armv7em
block|,
name|eCore_arm_xscale
block|,
name|eCore_thumb
block|,
name|eCore_thumbv4t
block|,
name|eCore_thumbv5
block|,
name|eCore_thumbv5e
block|,
name|eCore_thumbv6
block|,
name|eCore_thumbv6m
block|,
name|eCore_thumbv7
block|,
name|eCore_thumbv7s
block|,
name|eCore_thumbv7k
block|,
name|eCore_thumbv7f
block|,
name|eCore_thumbv7m
block|,
name|eCore_thumbv7em
block|,
name|eCore_arm_arm64
block|,
name|eCore_arm_armv8
block|,
name|eCore_arm_aarch64
block|,
name|eCore_mips32
block|,
name|eCore_mips32r2
block|,
name|eCore_mips32r3
block|,
name|eCore_mips32r5
block|,
name|eCore_mips32r6
block|,
name|eCore_mips32el
block|,
name|eCore_mips32r2el
block|,
name|eCore_mips32r3el
block|,
name|eCore_mips32r5el
block|,
name|eCore_mips32r6el
block|,
name|eCore_mips64
block|,
name|eCore_mips64r2
block|,
name|eCore_mips64r3
block|,
name|eCore_mips64r5
block|,
name|eCore_mips64r6
block|,
name|eCore_mips64el
block|,
name|eCore_mips64r2el
block|,
name|eCore_mips64r3el
block|,
name|eCore_mips64r5el
block|,
name|eCore_mips64r6el
block|,
name|eCore_ppc_generic
block|,
name|eCore_ppc_ppc601
block|,
name|eCore_ppc_ppc602
block|,
name|eCore_ppc_ppc603
block|,
name|eCore_ppc_ppc603e
block|,
name|eCore_ppc_ppc603ev
block|,
name|eCore_ppc_ppc604
block|,
name|eCore_ppc_ppc604e
block|,
name|eCore_ppc_ppc620
block|,
name|eCore_ppc_ppc750
block|,
name|eCore_ppc_ppc7400
block|,
name|eCore_ppc_ppc7450
block|,
name|eCore_ppc_ppc970
block|,
name|eCore_ppc64_generic
block|,
name|eCore_ppc64_ppc970_64
block|,
name|eCore_s390x_generic
block|,
name|eCore_sparc_generic
block|,
name|eCore_sparc9_generic
block|,
name|eCore_x86_32_i386
block|,
name|eCore_x86_32_i486
block|,
name|eCore_x86_32_i486sx
block|,
name|eCore_x86_32_i686
block|,
name|eCore_x86_64_x86_64
block|,
name|eCore_x86_64_x86_64h
block|,
comment|// Haswell enabled x86_64
name|eCore_hexagon_generic
block|,
name|eCore_hexagon_hexagonv4
block|,
name|eCore_hexagon_hexagonv5
block|,
name|eCore_uknownMach32
block|,
name|eCore_uknownMach64
block|,
name|eCore_kalimba3
block|,
name|eCore_kalimba4
block|,
name|eCore_kalimba5
block|,
name|kNumCores
block|,
name|kCore_invalid
block|,
comment|// The following constants are used for wildcard matching only
name|kCore_any
block|,
name|kCore_arm_any
block|,
name|kCore_ppc_any
block|,
name|kCore_ppc64_any
block|,
name|kCore_x86_32_any
block|,
name|kCore_x86_64_any
block|,
name|kCore_hexagon_any
block|,
name|kCore_arm_first
init|=
name|eCore_arm_generic
block|,
name|kCore_arm_last
init|=
name|eCore_arm_xscale
block|,
name|kCore_thumb_first
init|=
name|eCore_thumb
block|,
name|kCore_thumb_last
init|=
name|eCore_thumbv7em
block|,
name|kCore_ppc_first
init|=
name|eCore_ppc_generic
block|,
name|kCore_ppc_last
init|=
name|eCore_ppc_ppc970
block|,
name|kCore_ppc64_first
init|=
name|eCore_ppc64_generic
block|,
name|kCore_ppc64_last
init|=
name|eCore_ppc64_ppc970_64
block|,
name|kCore_x86_32_first
init|=
name|eCore_x86_32_i386
block|,
name|kCore_x86_32_last
init|=
name|eCore_x86_32_i686
block|,
name|kCore_x86_64_first
init|=
name|eCore_x86_64_x86_64
block|,
name|kCore_x86_64_last
init|=
name|eCore_x86_64_x86_64h
block|,
name|kCore_hexagon_first
init|=
name|eCore_hexagon_generic
block|,
name|kCore_hexagon_last
init|=
name|eCore_hexagon_hexagonv5
block|,
name|kCore_kalimba_first
init|=
name|eCore_kalimba3
block|,
name|kCore_kalimba_last
init|=
name|eCore_kalimba5
block|,
name|kCore_mips32_first
init|=
name|eCore_mips32
block|,
name|kCore_mips32_last
init|=
name|eCore_mips32r6
block|,
name|kCore_mips32el_first
init|=
name|eCore_mips32el
block|,
name|kCore_mips32el_last
init|=
name|eCore_mips32r6el
block|,
name|kCore_mips64_first
init|=
name|eCore_mips64
block|,
name|kCore_mips64_last
init|=
name|eCore_mips64r6
block|,
name|kCore_mips64el_first
init|=
name|eCore_mips64el
block|,
name|kCore_mips64el_last
init|=
name|eCore_mips64r6el
block|,
name|kCore_mips_first
init|=
name|eCore_mips32
block|,
name|kCore_mips_last
init|=
name|eCore_mips64r6el
block|}
enum|;
typedef|typedef
name|void
argument_list|(
operator|*
name|StopInfoOverrideCallbackType
argument_list|)
argument_list|(
name|lldb_private
operator|::
name|Thread
operator|&
name|thread
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Default constructor that initializes the object with invalid
comment|/// cpu type and subtype values.
comment|//------------------------------------------------------------------
name|ArchSpec
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor over triple.
comment|///
comment|/// Constructs an ArchSpec with properties consistent with the given
comment|/// Triple.
comment|//------------------------------------------------------------------
name|explicit
name|ArchSpec
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
name|explicit
name|ArchSpec
parameter_list|(
specifier|const
name|char
modifier|*
name|triple_cstr
parameter_list|)
function_decl|;
name|explicit
name|ArchSpec
argument_list|(
name|llvm
operator|::
name|StringRef
name|triple_str
argument_list|)
decl_stmt|;
name|ArchSpec
argument_list|(
specifier|const
name|char
operator|*
name|triple_cstr
argument_list|,
name|Platform
operator|*
name|platform
argument_list|)
expr_stmt|;
name|ArchSpec
argument_list|(
argument|llvm::StringRef triple_str
argument_list|,
argument|Platform *platform
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Constructor over architecture name.
comment|///
comment|/// Constructs an ArchSpec with properties consistent with the given
comment|/// object type and architecture name.
comment|//------------------------------------------------------------------
name|explicit
name|ArchSpec
parameter_list|(
name|ArchitectureType
name|arch_type
parameter_list|,
name|uint32_t
name|cpu_type
parameter_list|,
name|uint32_t
name|cpu_subtype
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|ArchSpec
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// @param[in] rhs another ArchSpec object to copy.
comment|///
comment|/// @return A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|ArchSpec
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ArchSpec
operator|&
name|rhs
operator|)
decl_stmt|;
specifier|static
name|size_t
name|AutoComplete
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|StringList
operator|&
name|matches
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a static string representing the current architecture.
comment|///
comment|/// @return A static string correcponding to the current
comment|///         architecture.
comment|//------------------------------------------------------------------
specifier|const
name|char
operator|*
name|GetArchitectureName
argument_list|()
specifier|const
expr_stmt|;
comment|//-----------------------------------------------------------------
comment|/// if MIPS architecture return true.
comment|///
comment|///  @return a boolean value.
comment|//-----------------------------------------------------------------
name|bool
name|IsMIPS
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a string representing current architecture as a target CPU
comment|/// for tools like compiler, disassembler etc.
comment|///
comment|/// @return A string representing target CPU for the current
comment|///         architecture.
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|GetClangTargetCPU
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return a string representing target application ABI.
comment|///
comment|/// @return A string representing target application ABI.
comment|//------------------------------------------------------------------
name|std
operator|::
name|string
name|GetTargetABI
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Clears the object state.
comment|///
comment|/// Clears the object state back to a default invalid state.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the size in bytes of an address of the current
comment|/// architecture.
comment|///
comment|/// @return The byte size of an address of the current architecture.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a machine family for the current architecture.
comment|///
comment|/// @return An LLVM arch type.
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|Triple
operator|::
name|ArchType
name|GetMachine
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns the distribution id of the architecture.
comment|///
comment|/// This will be something like "ubuntu", "fedora", etc. on Linux.
comment|///
comment|/// @return A ConstString ref containing the distribution id,
comment|///         potentially empty.
comment|//------------------------------------------------------------------
specifier|const
name|ConstString
operator|&
name|GetDistributionId
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set the distribution id of the architecture.
comment|///
comment|/// This will be something like "ubuntu", "fedora", etc. on Linux.
comment|/// This should be the same value returned by
comment|/// HostInfo::GetDistributionId ().
comment|///------------------------------------------------------------------
name|void
name|SetDistributionId
parameter_list|(
specifier|const
name|char
modifier|*
name|distribution_id
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tests if this ArchSpec is valid.
comment|///
comment|/// @return True if the current architecture is valid, false
comment|///         otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_core
operator|>=
name|eCore_arm_generic
operator|&&
name|m_core
operator|<
name|kNumCores
return|;
block|}
name|bool
name|TripleVendorWasSpecified
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_triple
operator|.
name|getVendorName
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|TripleVendorIsUnspecifiedUnknown
argument_list|()
specifier|const
block|{
return|return
name|m_triple
operator|.
name|getVendor
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|UnknownVendor
operator|&&
name|m_triple
operator|.
name|getVendorName
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|TripleOSWasSpecified
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_triple
operator|.
name|getOSName
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|TripleEnvironmentWasSpecified
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_triple
operator|.
name|getEnvironmentName
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|TripleOSIsUnspecifiedUnknown
argument_list|()
specifier|const
block|{
return|return
name|m_triple
operator|.
name|getOS
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|UnknownOS
operator|&&
name|m_triple
operator|.
name|getOSName
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Merges fields from another ArchSpec into this ArchSpec.
comment|///
comment|/// This will use the supplied ArchSpec to fill in any fields of
comment|/// the triple in this ArchSpec which were unspecified.  This can
comment|/// be used to refine a generic ArchSpec with a more specific one.
comment|/// For example, if this ArchSpec's triple is something like
comment|/// i386-unknown-unknown-unknown, and we have a triple which is
comment|/// x64-pc-windows-msvc, then merging that triple into this one
comment|/// will result in the triple i386-pc-windows-msvc.
comment|///
comment|//------------------------------------------------------------------
name|void
name|MergeFrom
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|other
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Change the architecture object type, CPU type and OS type.
comment|///
comment|/// @param[in] arch_type The object type of this ArchSpec.
comment|///
comment|/// @param[in] cpu The required CPU type.
comment|///
comment|/// @param[in] os The optional OS type
comment|/// The default value of 0 was chosen to from the ELF spec value
comment|/// ELFOSABI_NONE.  ELF is the only one using this parameter.  If another
comment|/// format uses this parameter and 0 does not work, use a value over
comment|/// 255 because in the ELF header this is value is only a byte.
comment|///
comment|/// @return True if the object, and CPU were successfully set.
comment|///
comment|/// As a side effect, the vendor value is usually set to unknown.
comment|/// The exections are
comment|///   aarch64-apple-ios
comment|///   arm-apple-ios
comment|///   thumb-apple-ios
comment|///   x86-apple-
comment|///   x86_64-apple-
comment|///
comment|/// As a side effect, the os value is usually set to unknown
comment|/// The exceptions are
comment|///   *-*-aix
comment|///   aarch64-apple-ios
comment|///   arm-apple-ios
comment|///   thumb-apple-ios
comment|///   powerpc-apple-darwin
comment|///   *-*-freebsd
comment|///   *-*-linux
comment|///   *-*-netbsd
comment|///   *-*-openbsd
comment|///   *-*-solaris
comment|//------------------------------------------------------------------
name|bool
name|SetArchitecture
parameter_list|(
name|ArchitectureType
name|arch_type
parameter_list|,
name|uint32_t
name|cpu
parameter_list|,
name|uint32_t
name|sub
parameter_list|,
name|uint32_t
name|os
init|=
literal|0
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the byte order for the architecture specification.
comment|///
comment|/// @return The endian enumeration for the current endianness of
comment|///     the architecture specification
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets this ArchSpec's byte order.
comment|///
comment|/// In the common case there is no need to call this method as the
comment|/// byte order can almost always be determined by the architecture.
comment|/// However, many CPU's are bi-endian (ARM, Alpha, PowerPC, etc)
comment|/// and the default/assumed byte order may be incorrect.
comment|//------------------------------------------------------------------
name|void
name|SetByteOrder
argument_list|(
name|lldb
operator|::
name|ByteOrder
name|byte_order
argument_list|)
block|{
name|m_byte_order
operator|=
name|byte_order
expr_stmt|;
block|}
name|uint32_t
name|GetMinimumOpcodeByteSize
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetMaximumOpcodeByteSize
argument_list|()
specifier|const
expr_stmt|;
name|Core
name|GetCore
argument_list|()
specifier|const
block|{
return|return
name|m_core
return|;
block|}
name|uint32_t
name|GetMachOCPUType
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetMachOCPUSubType
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Architecture data byte width accessor
comment|///
comment|/// @return the size in 8-bit (host) bytes of a minimum addressable
comment|/// unit from the Architecture's data bus
comment|//------------------------------------------------------------------
name|uint32_t
name|GetDataByteSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Architecture code byte width accessor
comment|///
comment|/// @return the size in 8-bit (host) bytes of a minimum addressable
comment|/// unit from the Architecture's code bus
comment|//------------------------------------------------------------------
name|uint32_t
name|GetCodeByteSize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Architecture tripple accessor.
comment|///
comment|/// @return A triple describing this ArchSpec.
comment|//------------------------------------------------------------------
name|llvm
operator|::
name|Triple
operator|&
name|GetTriple
argument_list|()
block|{
return|return
name|m_triple
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Architecture tripple accessor.
comment|///
comment|/// @return A triple describing this ArchSpec.
comment|//------------------------------------------------------------------
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|GetTriple
argument_list|()
specifier|const
block|{
return|return
name|m_triple
return|;
block|}
name|void
name|DumpTriple
argument_list|(
name|Stream
operator|&
name|s
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Architecture tripple setter.
comment|///
comment|/// Configures this ArchSpec according to the given triple.  If the
comment|/// triple has unknown components in all of the vendor, OS, and
comment|/// the optional environment field (i.e. "i386-unknown-unknown")
comment|/// then default values are taken from the host.  Architecture and
comment|/// environment components are used to further resolve the CPU type
comment|/// and subtype, endian characteristics, etc.
comment|///
comment|/// @return A triple describing this ArchSpec.
comment|//------------------------------------------------------------------
name|bool
name|SetTriple
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|triple
argument_list|)
decl_stmt|;
name|bool
name|SetTriple
argument_list|(
name|llvm
operator|::
name|StringRef
name|triple_str
argument_list|)
decl_stmt|;
name|bool
name|SetTriple
argument_list|(
name|llvm
operator|::
name|StringRef
name|triple_str
argument_list|,
name|Platform
operator|*
name|platform
argument_list|)
decl_stmt|;
name|bool
name|SetTriple
parameter_list|(
specifier|const
name|char
modifier|*
name|triple_cstr
parameter_list|)
function_decl|;
name|bool
name|SetTriple
parameter_list|(
specifier|const
name|char
modifier|*
name|triple_cstr
parameter_list|,
name|Platform
modifier|*
name|platform
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the default endianness of the architecture.
comment|///
comment|/// @return The endian enumeration for the default endianness of
comment|///         the architecture.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ByteOrder
name|GetDefaultEndian
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns true if 'char' is a signed type by defualt in the
comment|/// architecture false otherwise
comment|///
comment|/// @return True if 'char' is a signed type by default on the
comment|///         architecture and false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|CharIsSignedByDefault
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Compare an ArchSpec to another ArchSpec, requiring an exact cpu
comment|/// type match between them.
comment|/// e.g. armv7s is not an exact match with armv7 - this would return false
comment|///
comment|/// @return true if the two ArchSpecs match.
comment|//------------------------------------------------------------------
name|bool
name|IsExactMatch
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|rhs
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Compare an ArchSpec to another ArchSpec, requiring a compatible
comment|/// cpu type match between them.
comment|/// e.g. armv7s is compatible with armv7 - this method would return true
comment|///
comment|/// @return true if the two ArchSpecs are compatible
comment|//------------------------------------------------------------------
name|bool
name|IsCompatibleMatch
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|rhs
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get a stop info override callback for the current architecture.
comment|///
comment|/// Most platform specific code should go in lldb_private::Platform,
comment|/// but there are cases where no matter which platform you are on
comment|/// certain things hold true.
comment|///
comment|/// This callback is currently intended to handle cases where a
comment|/// program stops at an instruction that won't get executed and it
comment|/// allows the stop reasonm, like "breakpoint hit", to be replaced
comment|/// with a different stop reason like "no stop reason".
comment|///
comment|/// This is specifically used for ARM in Thumb code when we stop in
comment|/// an IT instruction (if/then/else) where the instruction won't get
comment|/// executed and therefore it wouldn't be correct to show the program
comment|/// stopped at the current PC. The code is generic and applies to all
comment|/// ARM CPUs.
comment|///
comment|/// @return NULL or a valid stop info override callback for the
comment|///     current architecture.
comment|//------------------------------------------------------------------
name|StopInfoOverrideCallbackType
name|GetStopInfoOverrideCallback
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsFullySpecifiedTriple
argument_list|()
specifier|const
expr_stmt|;
name|void
name|PiecewiseTripleCompare
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|other
parameter_list|,
name|bool
modifier|&
name|arch_different
parameter_list|,
name|bool
modifier|&
name|vendor_different
parameter_list|,
name|bool
modifier|&
name|os_different
parameter_list|,
name|bool
modifier|&
name|os_version_different
parameter_list|,
name|bool
modifier|&
name|env_different
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Detect whether this architecture uses thumb code exclusively
comment|///
comment|/// Some embedded ARM chips (e.g. the ARM Cortex M0-7 line) can
comment|/// only execute the Thumb instructions, never Arm.  We should normally
comment|/// pick up arm/thumbness from their the processor status bits (cpsr/xpsr)
comment|/// or hints on each function - but when doing bare-boards low level
comment|/// debugging (especially common with these embedded processors), we may
comment|/// not have those things easily accessible.
comment|///
comment|/// @return true if this is an arm ArchSpec which can only execute Thumb
comment|///         instructions
comment|//------------------------------------------------------------------
name|bool
name|IsAlwaysThumbInstructions
argument_list|()
specifier|const
expr_stmt|;
name|uint32_t
name|GetFlags
argument_list|()
specifier|const
block|{
return|return
name|m_flags
return|;
block|}
name|void
name|SetFlags
parameter_list|(
name|uint32_t
name|flags
parameter_list|)
block|{
name|m_flags
operator|=
name|flags
expr_stmt|;
block|}
name|void
name|SetFlags
argument_list|(
name|std
operator|::
name|string
name|elf_abi
argument_list|)
decl_stmt|;
name|protected
label|:
name|bool
name|IsEqualTo
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|rhs
argument_list|,
name|bool
name|exact_match
argument_list|)
decl|const
decl_stmt|;
name|llvm
operator|::
name|Triple
name|m_triple
expr_stmt|;
name|Core
name|m_core
init|=
name|kCore_invalid
decl_stmt|;
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
operator|=
name|lldb
operator|::
name|eByteOrderInvalid
expr_stmt|;
comment|// Additional arch flags which we cannot get from triple and core
comment|// For MIPS these are application specific extensions like
comment|// micromips, mips16 etc.
name|uint32_t
name|m_flags
init|=
literal|0
decl_stmt|;
name|ConstString
name|m_distribution_id
decl_stmt|;
comment|// Called when m_def or m_entry are changed.  Fills in all remaining
comment|// members with default values.
name|void
name|CoreUpdated
parameter_list|(
name|bool
name|update_triple
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// @fn bool operator< (const ArchSpec& lhs, const ArchSpec& rhs)
comment|/// @brief Less than operator.
comment|///
comment|/// Tests two ArchSpec objects to see if \a lhs is less than \a
comment|/// rhs.
comment|///
comment|/// @param[in] lhs The Left Hand Side ArchSpec object to compare.
comment|/// @param[in] rhs The Left Hand Side ArchSpec object to compare.
comment|///
comment|/// @return true if \a lhs is less than \a rhs
comment|//------------------------------------------------------------------
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ArchSpec
operator|&
name|lhs
operator|,
specifier|const
name|ArchSpec
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|ParseMachCPUDashSubtypeTriple
argument_list|(
name|llvm
operator|::
name|StringRef
name|triple_str
argument_list|,
name|ArchSpec
operator|&
name|arch
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_ArchSpec_h_
end_comment

end_unit

