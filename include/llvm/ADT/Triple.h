begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/ADT/Triple.h - Target triple helper class ----------*- C++ -*-===//
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
name|LLVM_ADT_TRIPLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_TRIPLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_comment
comment|// Some system headers or GCC predefined macros conflict with identifiers in
end_comment

begin_comment
comment|// this file.  Undefine them here.
end_comment

begin_undef
undef|#
directive|undef
name|NetBSD
end_undef

begin_undef
undef|#
directive|undef
name|mips
end_undef

begin_undef
undef|#
directive|undef
name|sparc
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Triple - Helper class for working with autoconf configuration names. For
comment|/// historical reasons, we also call these 'triples' (they used to contain
comment|/// exactly three fields).
comment|///
comment|/// Configuration names are strings in the canonical form:
comment|///   ARCHITECTURE-VENDOR-OPERATING_SYSTEM
comment|/// or
comment|///   ARCHITECTURE-VENDOR-OPERATING_SYSTEM-ENVIRONMENT
comment|///
comment|/// This class is used for clients which want to support arbitrary
comment|/// configuration names, but also want to implement certain special
comment|/// behavior for particular configurations. This class isolates the mapping
comment|/// from the components of the configuration name to well known IDs.
comment|///
comment|/// At its core the Triple class is designed to be a wrapper for a triple
comment|/// string; the constructor does not change or normalize the triple string.
comment|/// Clients that need to handle the non-canonical triples that users often
comment|/// specify should use the normalize method.
comment|///
comment|/// See autoconf/config.guess for a glimpse into what configuration names
comment|/// look like in practice.
name|class
name|Triple
block|{
name|public
label|:
enum|enum
name|ArchType
block|{
name|UnknownArch
block|,
name|arm
block|,
comment|// ARM (little endian): arm, armv.*, xscale
name|armeb
block|,
comment|// ARM (big endian): armeb
name|aarch64
block|,
comment|// AArch64 (little endian): aarch64
name|aarch64_be
block|,
comment|// AArch64 (big endian): aarch64_be
name|avr
block|,
comment|// AVR: Atmel AVR microcontroller
name|bpfel
block|,
comment|// eBPF or extended BPF or 64-bit BPF (little endian)
name|bpfeb
block|,
comment|// eBPF or extended BPF or 64-bit BPF (big endian)
name|hexagon
block|,
comment|// Hexagon: hexagon
name|mips
block|,
comment|// MIPS: mips, mipsallegrex
name|mipsel
block|,
comment|// MIPSEL: mipsel, mipsallegrexel
name|mips64
block|,
comment|// MIPS64: mips64
name|mips64el
block|,
comment|// MIPS64EL: mips64el
name|msp430
block|,
comment|// MSP430: msp430
name|ppc
block|,
comment|// PPC: powerpc
name|ppc64
block|,
comment|// PPC64: powerpc64, ppu
name|ppc64le
block|,
comment|// PPC64LE: powerpc64le
name|r600
block|,
comment|// R600: AMD GPUs HD2XXX - HD6XXX
name|amdgcn
block|,
comment|// AMDGCN: AMD GCN GPUs
name|riscv32
block|,
comment|// RISC-V (32-bit): riscv32
name|riscv64
block|,
comment|// RISC-V (64-bit): riscv64
name|sparc
block|,
comment|// Sparc: sparc
name|sparcv9
block|,
comment|// Sparcv9: Sparcv9
name|sparcel
block|,
comment|// Sparc: (endianness = little). NB: 'Sparcle' is a CPU variant
name|systemz
block|,
comment|// SystemZ: s390x
name|tce
block|,
comment|// TCE (http://tce.cs.tut.fi/): tce
name|tcele
block|,
comment|// TCE little endian (http://tce.cs.tut.fi/): tcele
name|thumb
block|,
comment|// Thumb (little endian): thumb, thumbv.*
name|thumbeb
block|,
comment|// Thumb (big endian): thumbeb
name|x86
block|,
comment|// X86: i[3-9]86
name|x86_64
block|,
comment|// X86-64: amd64, x86_64
name|xcore
block|,
comment|// XCore: xcore
name|nvptx
block|,
comment|// NVPTX: 32-bit
name|nvptx64
block|,
comment|// NVPTX: 64-bit
name|le32
block|,
comment|// le32: generic little-endian 32-bit CPU (PNaCl)
name|le64
block|,
comment|// le64: generic little-endian 64-bit CPU (PNaCl)
name|amdil
block|,
comment|// AMDIL
name|amdil64
block|,
comment|// AMDIL with 64-bit pointers
name|hsail
block|,
comment|// AMD HSAIL
name|hsail64
block|,
comment|// AMD HSAIL with 64-bit pointers
name|spir
block|,
comment|// SPIR: standard portable IR for OpenCL 32-bit version
name|spir64
block|,
comment|// SPIR: standard portable IR for OpenCL 64-bit version
name|kalimba
block|,
comment|// Kalimba: generic kalimba
name|shave
block|,
comment|// SHAVE: Movidius vector VLIW processors
name|lanai
block|,
comment|// Lanai: Lanai 32-bit
name|wasm32
block|,
comment|// WebAssembly with 32-bit pointers
name|wasm64
block|,
comment|// WebAssembly with 64-bit pointers
name|renderscript32
block|,
comment|// 32-bit RenderScript
name|renderscript64
block|,
comment|// 64-bit RenderScript
name|LastArchType
init|=
name|renderscript64
block|}
enum|;
enum|enum
name|SubArchType
block|{
name|NoSubArch
block|,
name|ARMSubArch_v8_2a
block|,
name|ARMSubArch_v8_1a
block|,
name|ARMSubArch_v8
block|,
name|ARMSubArch_v8r
block|,
name|ARMSubArch_v8m_baseline
block|,
name|ARMSubArch_v8m_mainline
block|,
name|ARMSubArch_v7
block|,
name|ARMSubArch_v7em
block|,
name|ARMSubArch_v7m
block|,
name|ARMSubArch_v7s
block|,
name|ARMSubArch_v7k
block|,
name|ARMSubArch_v7ve
block|,
name|ARMSubArch_v6
block|,
name|ARMSubArch_v6m
block|,
name|ARMSubArch_v6k
block|,
name|ARMSubArch_v6t2
block|,
name|ARMSubArch_v5
block|,
name|ARMSubArch_v5te
block|,
name|ARMSubArch_v4t
block|,
name|KalimbaSubArch_v3
block|,
name|KalimbaSubArch_v4
block|,
name|KalimbaSubArch_v5
block|}
enum|;
enum|enum
name|VendorType
block|{
name|UnknownVendor
block|,
name|Apple
block|,
name|PC
block|,
name|SCEI
block|,
name|BGP
block|,
name|BGQ
block|,
name|Freescale
block|,
name|IBM
block|,
name|ImaginationTechnologies
block|,
name|MipsTechnologies
block|,
name|NVIDIA
block|,
name|CSR
block|,
name|Myriad
block|,
name|AMD
block|,
name|Mesa
block|,
name|LastVendorType
init|=
name|Mesa
block|}
enum|;
enum|enum
name|OSType
block|{
name|UnknownOS
block|,
name|CloudABI
block|,
name|Darwin
block|,
name|DragonFly
block|,
name|FreeBSD
block|,
name|Fuchsia
block|,
name|IOS
block|,
name|KFreeBSD
block|,
name|Linux
block|,
name|Lv2
block|,
comment|// PS3
name|MacOSX
block|,
name|NetBSD
block|,
name|OpenBSD
block|,
name|Solaris
block|,
name|Win32
block|,
name|Haiku
block|,
name|Minix
block|,
name|RTEMS
block|,
name|NaCl
block|,
comment|// Native Client
name|CNK
block|,
comment|// BG/P Compute-Node Kernel
name|Bitrig
block|,
name|AIX
block|,
name|CUDA
block|,
comment|// NVIDIA CUDA
name|NVCL
block|,
comment|// NVIDIA OpenCL
name|AMDHSA
block|,
comment|// AMD HSA Runtime
name|PS4
block|,
name|ELFIAMCU
block|,
name|TvOS
block|,
comment|// Apple tvOS
name|WatchOS
block|,
comment|// Apple watchOS
name|Mesa3D
block|,
name|Contiki
block|,
name|LastOSType
init|=
name|Contiki
block|}
enum|;
enum|enum
name|EnvironmentType
block|{
name|UnknownEnvironment
block|,
name|GNU
block|,
name|GNUABI64
block|,
name|GNUEABI
block|,
name|GNUEABIHF
block|,
name|GNUX32
block|,
name|CODE16
block|,
name|EABI
block|,
name|EABIHF
block|,
name|Android
block|,
name|Musl
block|,
name|MuslEABI
block|,
name|MuslEABIHF
block|,
name|MSVC
block|,
name|Itanium
block|,
name|Cygnus
block|,
name|AMDOpenCL
block|,
name|CoreCLR
block|,
name|OpenCL
block|,
name|LastEnvironmentType
init|=
name|OpenCL
block|}
enum|;
enum|enum
name|ObjectFormatType
block|{
name|UnknownObjectFormat
block|,
name|COFF
block|,
name|ELF
block|,
name|MachO
block|,
name|Wasm
block|,   }
enum|;
name|private
label|:
name|std
operator|::
name|string
name|Data
expr_stmt|;
comment|/// The parsed arch type.
name|ArchType
name|Arch
decl_stmt|;
comment|/// The parsed subarchitecture type.
name|SubArchType
name|SubArch
decl_stmt|;
comment|/// The parsed vendor type.
name|VendorType
name|Vendor
decl_stmt|;
comment|/// The parsed OS type.
name|OSType
name|OS
decl_stmt|;
comment|/// The parsed Environment type.
name|EnvironmentType
name|Environment
decl_stmt|;
comment|/// The object format type.
name|ObjectFormatType
name|ObjectFormat
decl_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
comment|/// Default constructor is the same as an empty string and leaves all
comment|/// triple fields unknown.
name|Triple
argument_list|()
operator|:
name|Data
argument_list|()
operator|,
name|Arch
argument_list|()
operator|,
name|Vendor
argument_list|()
operator|,
name|OS
argument_list|()
operator|,
name|Environment
argument_list|()
operator|,
name|ObjectFormat
argument_list|()
block|{}
name|explicit
name|Triple
argument_list|(
specifier|const
name|Twine
operator|&
name|Str
argument_list|)
expr_stmt|;
name|Triple
argument_list|(
specifier|const
name|Twine
operator|&
name|ArchStr
argument_list|,
specifier|const
name|Twine
operator|&
name|VendorStr
argument_list|,
specifier|const
name|Twine
operator|&
name|OSStr
argument_list|)
expr_stmt|;
name|Triple
argument_list|(
specifier|const
name|Twine
operator|&
name|ArchStr
argument_list|,
specifier|const
name|Twine
operator|&
name|VendorStr
argument_list|,
specifier|const
name|Twine
operator|&
name|OSStr
argument_list|,
specifier|const
name|Twine
operator|&
name|EnvironmentStr
argument_list|)
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Triple
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Arch
operator|==
name|Other
operator|.
name|Arch
operator|&&
name|SubArch
operator|==
name|Other
operator|.
name|SubArch
operator|&&
name|Vendor
operator|==
name|Other
operator|.
name|Vendor
operator|&&
name|OS
operator|==
name|Other
operator|.
name|OS
operator|&&
name|Environment
operator|==
name|Other
operator|.
name|Environment
operator|&&
name|ObjectFormat
operator|==
name|Other
operator|.
name|ObjectFormat
return|;
block|}
comment|/// @}
comment|/// @name Normalization
comment|/// @{
comment|/// normalize - Turn an arbitrary machine specification into the canonical
comment|/// triple form (or something sensible that the Triple class understands if
comment|/// nothing better can reasonably be done).  In particular, it handles the
comment|/// common case in which otherwise valid components are in the wrong order.
specifier|static
name|std
operator|::
name|string
name|normalize
argument_list|(
argument|StringRef Str
argument_list|)
expr_stmt|;
comment|/// Return the normalized form of this triple's string.
name|std
operator|::
name|string
name|normalize
argument_list|()
specifier|const
block|{
return|return
name|normalize
argument_list|(
name|Data
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Typed Component Access
comment|/// @{
comment|/// getArch - Get the parsed architecture type of this triple.
name|ArchType
name|getArch
argument_list|()
specifier|const
block|{
return|return
name|Arch
return|;
block|}
comment|/// getSubArch - get the parsed subarchitecture type for this triple.
name|SubArchType
name|getSubArch
argument_list|()
specifier|const
block|{
return|return
name|SubArch
return|;
block|}
comment|/// getVendor - Get the parsed vendor type of this triple.
name|VendorType
name|getVendor
argument_list|()
specifier|const
block|{
return|return
name|Vendor
return|;
block|}
comment|/// getOS - Get the parsed operating system type of this triple.
name|OSType
name|getOS
argument_list|()
specifier|const
block|{
return|return
name|OS
return|;
block|}
comment|/// hasEnvironment - Does this triple have the optional environment
comment|/// (fourth) component?
name|bool
name|hasEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getEnvironmentName
argument_list|()
operator|!=
literal|""
return|;
block|}
comment|/// getEnvironment - Get the parsed environment type of this triple.
name|EnvironmentType
name|getEnvironment
argument_list|()
specifier|const
block|{
return|return
name|Environment
return|;
block|}
comment|/// Parse the version number from the OS name component of the
comment|/// triple, if present.
comment|///
comment|/// For example, "fooos1.2.3" would return (1, 2, 3).
comment|///
comment|/// If an entry is not defined, it will be returned as 0.
name|void
name|getEnvironmentVersion
argument_list|(
name|unsigned
operator|&
name|Major
argument_list|,
name|unsigned
operator|&
name|Minor
argument_list|,
name|unsigned
operator|&
name|Micro
argument_list|)
decl|const
decl_stmt|;
comment|/// getFormat - Get the object format for this triple.
name|ObjectFormatType
name|getObjectFormat
argument_list|()
specifier|const
block|{
return|return
name|ObjectFormat
return|;
block|}
comment|/// getOSVersion - Parse the version number from the OS name component of the
comment|/// triple, if present.
comment|///
comment|/// For example, "fooos1.2.3" would return (1, 2, 3).
comment|///
comment|/// If an entry is not defined, it will be returned as 0.
name|void
name|getOSVersion
argument_list|(
name|unsigned
operator|&
name|Major
argument_list|,
name|unsigned
operator|&
name|Minor
argument_list|,
name|unsigned
operator|&
name|Micro
argument_list|)
decl|const
decl_stmt|;
comment|/// getOSMajorVersion - Return just the major version number, this is
comment|/// specialized because it is a common query.
name|unsigned
name|getOSMajorVersion
argument_list|()
specifier|const
block|{
name|unsigned
name|Maj
block|,
name|Min
block|,
name|Micro
block|;
name|getOSVersion
argument_list|(
name|Maj
argument_list|,
name|Min
argument_list|,
name|Micro
argument_list|)
block|;
return|return
name|Maj
return|;
block|}
comment|/// getMacOSXVersion - Parse the version number as with getOSVersion and then
comment|/// translate generic "darwin" versions to the corresponding OS X versions.
comment|/// This may also be called with IOS triples but the OS X version number is
comment|/// just set to a constant 10.4.0 in that case.  Returns true if successful.
name|bool
name|getMacOSXVersion
argument_list|(
name|unsigned
operator|&
name|Major
argument_list|,
name|unsigned
operator|&
name|Minor
argument_list|,
name|unsigned
operator|&
name|Micro
argument_list|)
decl|const
decl_stmt|;
comment|/// getiOSVersion - Parse the version number as with getOSVersion.  This should
comment|/// only be called with IOS or generic triples.
name|void
name|getiOSVersion
argument_list|(
name|unsigned
operator|&
name|Major
argument_list|,
name|unsigned
operator|&
name|Minor
argument_list|,
name|unsigned
operator|&
name|Micro
argument_list|)
decl|const
decl_stmt|;
comment|/// getWatchOSVersion - Parse the version number as with getOSVersion.  This
comment|/// should only be called with WatchOS or generic triples.
name|void
name|getWatchOSVersion
argument_list|(
name|unsigned
operator|&
name|Major
argument_list|,
name|unsigned
operator|&
name|Minor
argument_list|,
name|unsigned
operator|&
name|Micro
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// @name Direct Component Access
comment|/// @{
specifier|const
name|std
operator|::
name|string
operator|&
name|str
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
comment|/// getArchName - Get the architecture (first) component of the
comment|/// triple.
name|StringRef
name|getArchName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getVendorName - Get the vendor (second) component of the triple.
name|StringRef
name|getVendorName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getOSName - Get the operating system (third) component of the
comment|/// triple.
name|StringRef
name|getOSName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getEnvironmentName - Get the optional environment (fourth)
comment|/// component of the triple, or "" if empty.
name|StringRef
name|getEnvironmentName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getOSAndEnvironmentName - Get the operating system and optional
comment|/// environment components as a single string (separated by a '-'
comment|/// if the environment component is present).
name|StringRef
name|getOSAndEnvironmentName
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Convenience Predicates
comment|/// @{
comment|/// Test whether the architecture is 64-bit
comment|///
comment|/// Note that this tests for 64-bit pointer width, and nothing else. Note
comment|/// that we intentionally expose only three predicates, 64-bit, 32-bit, and
comment|/// 16-bit. The inner details of pointer width for particular architectures
comment|/// is not summed up in the triple, and so only a coarse grained predicate
comment|/// system is provided.
name|bool
name|isArch64Bit
argument_list|()
specifier|const
expr_stmt|;
comment|/// Test whether the architecture is 32-bit
comment|///
comment|/// Note that this tests for 32-bit pointer width, and nothing else.
name|bool
name|isArch32Bit
argument_list|()
specifier|const
expr_stmt|;
comment|/// Test whether the architecture is 16-bit
comment|///
comment|/// Note that this tests for 16-bit pointer width, and nothing else.
name|bool
name|isArch16Bit
argument_list|()
specifier|const
expr_stmt|;
comment|/// isOSVersionLT - Helper function for doing comparisons against version
comment|/// numbers included in the target triple.
name|bool
name|isOSVersionLT
argument_list|(
name|unsigned
name|Major
argument_list|,
name|unsigned
name|Minor
operator|=
literal|0
argument_list|,
name|unsigned
name|Micro
operator|=
literal|0
argument_list|)
decl|const
block|{
name|unsigned
name|LHS
index|[
literal|3
index|]
decl_stmt|;
name|getOSVersion
argument_list|(
name|LHS
index|[
literal|0
index|]
argument_list|,
name|LHS
index|[
literal|1
index|]
argument_list|,
name|LHS
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|LHS
index|[
literal|0
index|]
operator|!=
name|Major
condition|)
return|return
name|LHS
index|[
literal|0
index|]
operator|<
name|Major
return|;
if|if
condition|(
name|LHS
index|[
literal|1
index|]
operator|!=
name|Minor
condition|)
return|return
name|LHS
index|[
literal|1
index|]
operator|<
name|Minor
return|;
if|if
condition|(
name|LHS
index|[
literal|2
index|]
operator|!=
name|Micro
condition|)
return|return
name|LHS
index|[
literal|1
index|]
operator|<
name|Micro
return|;
return|return
name|false
return|;
block|}
name|bool
name|isOSVersionLT
argument_list|(
specifier|const
name|Triple
operator|&
name|Other
argument_list|)
decl|const
block|{
name|unsigned
name|RHS
index|[
literal|3
index|]
decl_stmt|;
name|Other
operator|.
name|getOSVersion
argument_list|(
name|RHS
index|[
literal|0
index|]
argument_list|,
name|RHS
index|[
literal|1
index|]
argument_list|,
name|RHS
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
return|return
name|isOSVersionLT
argument_list|(
name|RHS
index|[
literal|0
index|]
argument_list|,
name|RHS
index|[
literal|1
index|]
argument_list|,
name|RHS
index|[
literal|2
index|]
argument_list|)
return|;
block|}
comment|/// isMacOSXVersionLT - Comparison function for checking OS X version
comment|/// compatibility, which handles supporting skewed version numbering schemes
comment|/// used by the "darwin" triples.
name|bool
name|isMacOSXVersionLT
argument_list|(
name|unsigned
name|Major
argument_list|,
name|unsigned
name|Minor
operator|=
literal|0
argument_list|,
name|unsigned
name|Micro
operator|=
literal|0
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isMacOSX
argument_list|()
operator|&&
literal|"Not an OS X triple!"
argument_list|)
expr_stmt|;
comment|// If this is OS X, expect a sane version number.
if|if
condition|(
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|MacOSX
condition|)
return|return
name|isOSVersionLT
argument_list|(
name|Major
argument_list|,
name|Minor
argument_list|,
name|Micro
argument_list|)
return|;
comment|// Otherwise, compare to the "Darwin" number.
name|assert
argument_list|(
name|Major
operator|==
literal|10
operator|&&
literal|"Unexpected major version"
argument_list|)
expr_stmt|;
return|return
name|isOSVersionLT
argument_list|(
name|Minor
operator|+
literal|4
argument_list|,
name|Micro
argument_list|,
literal|0
argument_list|)
return|;
block|}
comment|/// isMacOSX - Is this a Mac OS X triple. For legacy reasons, we support both
comment|/// "darwin" and "osx" as OS X triples.
name|bool
name|isMacOSX
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Darwin
operator|||
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|MacOSX
return|;
block|}
comment|/// Is this an iOS triple.
comment|/// Note: This identifies tvOS as a variant of iOS. If that ever
comment|/// changes, i.e., if the two operating systems diverge or their version
comment|/// numbers get out of sync, that will need to be changed.
comment|/// watchOS has completely different version numbers so it is not included.
name|bool
name|isiOS
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|IOS
operator|||
name|isTvOS
argument_list|()
return|;
block|}
comment|/// Is this an Apple tvOS triple.
name|bool
name|isTvOS
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|TvOS
return|;
block|}
comment|/// Is this an Apple watchOS triple.
name|bool
name|isWatchOS
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|WatchOS
return|;
block|}
name|bool
name|isWatchABI
argument_list|()
specifier|const
block|{
return|return
name|getSubArch
argument_list|()
operator|==
name|Triple
operator|::
name|ARMSubArch_v7k
return|;
block|}
comment|/// isOSDarwin - Is this a "Darwin" OS (OS X, iOS, or watchOS).
name|bool
name|isOSDarwin
argument_list|()
specifier|const
block|{
return|return
name|isMacOSX
argument_list|()
operator|||
name|isiOS
argument_list|()
operator|||
name|isWatchOS
argument_list|()
return|;
block|}
name|bool
name|isOSNetBSD
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|NetBSD
return|;
block|}
name|bool
name|isOSOpenBSD
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|OpenBSD
return|;
block|}
name|bool
name|isOSFreeBSD
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|FreeBSD
return|;
block|}
name|bool
name|isOSFuchsia
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Fuchsia
return|;
block|}
name|bool
name|isOSDragonFly
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|DragonFly
return|;
block|}
name|bool
name|isOSSolaris
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Solaris
return|;
block|}
name|bool
name|isOSBitrig
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Bitrig
return|;
block|}
name|bool
name|isOSIAMCU
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|ELFIAMCU
return|;
block|}
name|bool
name|isGNUEnvironment
argument_list|()
specifier|const
block|{
name|EnvironmentType
name|Env
operator|=
name|getEnvironment
argument_list|()
block|;
return|return
name|Env
operator|==
name|Triple
operator|::
name|GNU
operator|||
name|Env
operator|==
name|Triple
operator|::
name|GNUABI64
operator|||
name|Env
operator|==
name|Triple
operator|::
name|GNUEABI
operator|||
name|Env
operator|==
name|Triple
operator|::
name|GNUEABIHF
operator|||
name|Env
operator|==
name|Triple
operator|::
name|GNUX32
return|;
block|}
name|bool
name|isOSContiki
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Contiki
return|;
block|}
comment|/// Checks if the environment could be MSVC.
name|bool
name|isWindowsMSVCEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
operator|(
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|UnknownEnvironment
operator|||
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|MSVC
operator|)
return|;
block|}
comment|/// Checks if the environment is MSVC.
name|bool
name|isKnownWindowsMSVCEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|MSVC
return|;
block|}
name|bool
name|isWindowsCoreCLREnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|CoreCLR
return|;
block|}
name|bool
name|isWindowsItaniumEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|Itanium
return|;
block|}
name|bool
name|isWindowsCygwinEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|Cygnus
return|;
block|}
name|bool
name|isWindowsGNUEnvironment
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
operator|&&
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|GNU
return|;
block|}
comment|/// Tests for either Cygwin or MinGW OS
name|bool
name|isOSCygMing
argument_list|()
specifier|const
block|{
return|return
name|isWindowsCygwinEnvironment
argument_list|()
operator|||
name|isWindowsGNUEnvironment
argument_list|()
return|;
block|}
comment|/// Is this a "Windows" OS targeting a "MSVCRT.dll" environment.
name|bool
name|isOSMSVCRT
argument_list|()
specifier|const
block|{
return|return
name|isWindowsMSVCEnvironment
argument_list|()
operator|||
name|isWindowsGNUEnvironment
argument_list|()
operator|||
name|isWindowsItaniumEnvironment
argument_list|()
return|;
block|}
comment|/// Tests whether the OS is Windows.
name|bool
name|isOSWindows
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Win32
return|;
block|}
comment|/// Tests whether the OS is NaCl (Native Client)
name|bool
name|isOSNaCl
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|NaCl
return|;
block|}
comment|/// Tests whether the OS is Linux.
name|bool
name|isOSLinux
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Linux
return|;
block|}
comment|/// Tests whether the OS is kFreeBSD.
name|bool
name|isOSKFreeBSD
argument_list|()
specifier|const
block|{
return|return
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|KFreeBSD
return|;
block|}
comment|/// Tests whether the OS uses glibc.
name|bool
name|isOSGlibc
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|Linux
operator|||
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|KFreeBSD
operator|)
operator|&&
operator|!
name|isAndroid
argument_list|()
return|;
block|}
comment|/// Tests whether the OS uses the ELF binary format.
name|bool
name|isOSBinFormatELF
argument_list|()
specifier|const
block|{
return|return
name|getObjectFormat
argument_list|()
operator|==
name|Triple
operator|::
name|ELF
return|;
block|}
comment|/// Tests whether the OS uses the COFF binary format.
name|bool
name|isOSBinFormatCOFF
argument_list|()
specifier|const
block|{
return|return
name|getObjectFormat
argument_list|()
operator|==
name|Triple
operator|::
name|COFF
return|;
block|}
comment|/// Tests whether the environment is MachO.
name|bool
name|isOSBinFormatMachO
argument_list|()
specifier|const
block|{
return|return
name|getObjectFormat
argument_list|()
operator|==
name|Triple
operator|::
name|MachO
return|;
block|}
comment|/// Tests whether the OS uses the Wasm binary format.
name|bool
name|isOSBinFormatWasm
argument_list|()
specifier|const
block|{
return|return
name|getObjectFormat
argument_list|()
operator|==
name|Triple
operator|::
name|Wasm
return|;
block|}
comment|/// Tests whether the target is the PS4 CPU
name|bool
name|isPS4CPU
argument_list|()
specifier|const
block|{
return|return
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|x86_64
operator|&&
name|getVendor
argument_list|()
operator|==
name|Triple
operator|::
name|SCEI
operator|&&
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|PS4
return|;
block|}
comment|/// Tests whether the target is the PS4 platform
name|bool
name|isPS4
argument_list|()
specifier|const
block|{
return|return
name|getVendor
argument_list|()
operator|==
name|Triple
operator|::
name|SCEI
operator|&&
name|getOS
argument_list|()
operator|==
name|Triple
operator|::
name|PS4
return|;
block|}
comment|/// Tests whether the target is Android
name|bool
name|isAndroid
argument_list|()
specifier|const
block|{
return|return
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|Android
return|;
block|}
name|bool
name|isAndroidVersionLT
argument_list|(
name|unsigned
name|Major
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|isAndroid
argument_list|()
operator|&&
literal|"Not an Android triple!"
argument_list|)
expr_stmt|;
name|unsigned
name|Env
index|[
literal|3
index|]
decl_stmt|;
name|getEnvironmentVersion
argument_list|(
name|Env
index|[
literal|0
index|]
argument_list|,
name|Env
index|[
literal|1
index|]
argument_list|,
name|Env
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|// 64-bit targets did not exist before API level 21 (Lollipop).
if|if
condition|(
name|isArch64Bit
argument_list|()
operator|&&
name|Env
index|[
literal|0
index|]
operator|<
literal|21
condition|)
name|Env
index|[
literal|0
index|]
operator|=
literal|21
expr_stmt|;
return|return
name|Env
index|[
literal|0
index|]
operator|<
name|Major
return|;
block|}
comment|/// Tests whether the environment is musl-libc
name|bool
name|isMusl
argument_list|()
specifier|const
block|{
return|return
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|Musl
operator|||
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|MuslEABI
operator|||
name|getEnvironment
argument_list|()
operator|==
name|Triple
operator|::
name|MuslEABIHF
return|;
block|}
comment|/// Tests whether the target is NVPTX (32- or 64-bit).
name|bool
name|isNVPTX
argument_list|()
specifier|const
block|{
return|return
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|nvptx
operator|||
name|getArch
argument_list|()
operator|==
name|Triple
operator|::
name|nvptx64
return|;
block|}
comment|/// Tests wether the target supports comdat
name|bool
name|supportsCOMDAT
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isOSBinFormatMachO
argument_list|()
return|;
block|}
comment|/// @}
comment|/// @name Mutators
comment|/// @{
comment|/// setArch - Set the architecture (first) component of the triple
comment|/// to a known type.
name|void
name|setArch
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
comment|/// setVendor - Set the vendor (second) component of the triple to a
comment|/// known type.
name|void
name|setVendor
parameter_list|(
name|VendorType
name|Kind
parameter_list|)
function_decl|;
comment|/// setOS - Set the operating system (third) component of the triple
comment|/// to a known type.
name|void
name|setOS
parameter_list|(
name|OSType
name|Kind
parameter_list|)
function_decl|;
comment|/// setEnvironment - Set the environment (fourth) component of the triple
comment|/// to a known type.
name|void
name|setEnvironment
parameter_list|(
name|EnvironmentType
name|Kind
parameter_list|)
function_decl|;
comment|/// setObjectFormat - Set the object file format
name|void
name|setObjectFormat
parameter_list|(
name|ObjectFormatType
name|Kind
parameter_list|)
function_decl|;
comment|/// setTriple - Set all components to the new triple \p Str.
name|void
name|setTriple
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Str
parameter_list|)
function_decl|;
comment|/// setArchName - Set the architecture (first) component of the
comment|/// triple by name.
name|void
name|setArchName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// setVendorName - Set the vendor (second) component of the triple
comment|/// by name.
name|void
name|setVendorName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// setOSName - Set the operating system (third) component of the
comment|/// triple by name.
name|void
name|setOSName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// setEnvironmentName - Set the optional environment (fourth)
comment|/// component of the triple by name.
name|void
name|setEnvironmentName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// setOSAndEnvironmentName - Set the operating system and optional
comment|/// environment components with a single string.
name|void
name|setOSAndEnvironmentName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Helpers to build variants of a particular triple.
comment|/// @{
comment|/// Form a triple with a 32-bit variant of the current architecture.
comment|///
comment|/// This can be used to move across "families" of architectures where useful.
comment|///
comment|/// \returns A new triple with a 32-bit architecture or an unknown
comment|///          architecture if no such variant can be found.
name|llvm
operator|::
name|Triple
name|get32BitArchVariant
argument_list|()
specifier|const
expr_stmt|;
comment|/// Form a triple with a 64-bit variant of the current architecture.
comment|///
comment|/// This can be used to move across "families" of architectures where useful.
comment|///
comment|/// \returns A new triple with a 64-bit architecture or an unknown
comment|///          architecture if no such variant can be found.
name|llvm
operator|::
name|Triple
name|get64BitArchVariant
argument_list|()
specifier|const
expr_stmt|;
comment|/// Form a triple with a big endian variant of the current architecture.
comment|///
comment|/// This can be used to move across "families" of architectures where useful.
comment|///
comment|/// \returns A new triple with a big endian architecture or an unknown
comment|///          architecture if no such variant can be found.
name|llvm
operator|::
name|Triple
name|getBigEndianArchVariant
argument_list|()
specifier|const
expr_stmt|;
comment|/// Form a triple with a little endian variant of the current architecture.
comment|///
comment|/// This can be used to move across "families" of architectures where useful.
comment|///
comment|/// \returns A new triple with a little endian architecture or an unknown
comment|///          architecture if no such variant can be found.
name|llvm
operator|::
name|Triple
name|getLittleEndianArchVariant
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the (LLVM) name of the minimum ARM CPU for the arch we are targeting.
comment|///
comment|/// \param Arch the architecture name (e.g., "armv7s"). If it is an empty
comment|/// string then the triple's arch name is used.
name|StringRef
name|getARMCPUForArch
argument_list|(
name|StringRef
name|Arch
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// Tests whether the target triple is little endian.
comment|///
comment|/// \returns true if the triple is little endian, false otherwise.
name|bool
name|isLittleEndian
argument_list|()
specifier|const
expr_stmt|;
comment|/// @}
comment|/// @name Static helpers for IDs.
comment|/// @{
comment|/// getArchTypeName - Get the canonical name for the \p Kind architecture.
specifier|static
name|StringRef
name|getArchTypeName
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
comment|/// getArchTypePrefix - Get the "prefix" canonical name for the \p Kind
comment|/// architecture. This is the prefix used by the architecture specific
comment|/// builtins, and is suitable for passing to \see
comment|/// Intrinsic::getIntrinsicForGCCBuiltin().
comment|///
comment|/// \return - The architecture prefix, or 0 if none is defined.
specifier|static
name|StringRef
name|getArchTypePrefix
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
comment|/// getVendorTypeName - Get the canonical name for the \p Kind vendor.
specifier|static
name|StringRef
name|getVendorTypeName
parameter_list|(
name|VendorType
name|Kind
parameter_list|)
function_decl|;
comment|/// getOSTypeName - Get the canonical name for the \p Kind operating system.
specifier|static
name|StringRef
name|getOSTypeName
parameter_list|(
name|OSType
name|Kind
parameter_list|)
function_decl|;
comment|/// getEnvironmentTypeName - Get the canonical name for the \p Kind
comment|/// environment.
specifier|static
name|StringRef
name|getEnvironmentTypeName
parameter_list|(
name|EnvironmentType
name|Kind
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Static helpers for converting alternate architecture names.
comment|/// @{
comment|/// getArchTypeForLLVMName - The canonical type for the given LLVM
comment|/// architecture name (e.g., "x86").
specifier|static
name|ArchType
name|getArchTypeForLLVMName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// @}
block|}
empty_stmt|;
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

