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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct_decl|struct
name|CoreDefinition
struct_decl|;
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
name|eCore_thumbv7f
block|,
name|eCore_thumbv7s
block|,
name|eCore_thumbv7k
block|,
name|eCore_thumbv7m
block|,
name|eCore_thumbv7em
block|,
name|eCore_mips64
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
name|eCore_x86_32_i486sx
block|,
name|kCore_hexagon_first
init|=
name|eCore_hexagon_generic
block|,
name|kCore_hexagon_last
init|=
name|eCore_hexagon_hexagonv5
block|}
enum|;
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
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|StringList
modifier|&
name|matches
parameter_list|)
function_decl|;
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
comment|/// Host::GetDistributionId ().
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
comment|//------------------------------------------------------------------
comment|/// Sets this ArchSpec according to the given architecture name.
comment|///
comment|/// The architecture name can be one of the generic system default
comment|/// values:
comment|///
comment|/// @li \c LLDB_ARCH_DEFAULT - The arch the current system defaults
comment|///        to when a program is launched without any extra
comment|///        attributes or settings.
comment|/// @li \c LLDB_ARCH_DEFAULT_32BIT - The default host architecture
comment|///        for 32 bit (if any).
comment|/// @li \c LLDB_ARCH_DEFAULT_64BIT - The default host architecture
comment|///        for 64 bit (if any).
comment|///
comment|/// Alternatively, if the object type of this ArchSpec has been
comment|/// configured,  a concrete architecture can be specified to set
comment|/// the CPU type ("x86_64" for example).
comment|///
comment|/// Finally, an encoded object and archetecture format is accepted.
comment|/// The format contains an object type (like "macho" or "elf"),
comment|/// followed by a platform dependent encoding of CPU type and
comment|/// subtype.  For example:
comment|///
comment|///     "macho"        : Specifies an object type of MachO.
comment|///     "macho-16-6"   : MachO specific encoding for ARMv6.
comment|///     "elf-43        : ELF specific encoding for Sparc V9.
comment|///
comment|/// @param[in] arch_name The name of an architecture.
comment|///
comment|/// @return True if @p arch_name was successfully translated, false
comment|///         otherwise.
comment|//------------------------------------------------------------------
comment|//    bool
comment|//    SetArchitecture (const llvm::StringRef& arch_name);
comment|//
comment|//    bool
comment|//    SetArchitecture (const char *arch_name);
comment|//------------------------------------------------------------------
comment|/// Change the architecture object type and CPU type.
comment|///
comment|/// @param[in] arch_type The object type of this ArchSpec.
comment|///
comment|/// @param[in] cpu The required CPU type.
comment|///
comment|/// @return True if the object and CPU type were sucessfully set.
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
decl_stmt|;
name|lldb
operator|::
name|ByteOrder
name|m_byte_order
expr_stmt|;
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

