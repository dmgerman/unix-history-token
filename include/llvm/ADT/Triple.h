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
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
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
name|class
name|StringRef
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|/// Triple - Helper class for working with target triples.
comment|///
comment|/// Target triples are strings in the format of:
comment|///   ARCHITECTURE-VENDOR-OPERATING_SYSTEM
comment|/// or
comment|///   ARCHITECTURE-VENDOR-OPERATING_SYSTEM-ENVIRONMENT
comment|///
comment|/// This class is used for clients which want to support arbitrary
comment|/// target triples, but also want to implement certain special
comment|/// behavior for particular targets. This class isolates the mapping
comment|/// from the components of the target triple to well known IDs.
comment|///
comment|/// At its core the Triple class is designed to be a wrapper for a triple
comment|/// string; it does not normally change or normalize the triple string, instead
comment|/// it provides additional APIs to parse normalized parts out of the triple.
comment|///
comment|/// One curiosity this implies is that for some odd triples the results of,
comment|/// e.g., getOSName() can be very different from the result of getOS().  For
comment|/// example, for 'i386-mingw32', getOS() will return MinGW32, but since
comment|/// getOSName() is purely based on the string structure that will return the
comment|/// empty string.
comment|///
comment|/// Clients should generally avoid using getOSName() and related APIs unless
comment|/// they are familiar with the triple format (this is particularly true when
comment|/// rewriting a triple).
comment|///
comment|/// See autoconf/config.guess for a glimpse into what they look like in
comment|/// practice.
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
name|alpha
block|,
comment|// Alpha: alpha
name|arm
block|,
comment|// ARM; arm, armv.*, xscale
name|bfin
block|,
comment|// Blackfin: bfin
name|cellspu
block|,
comment|// CellSPU: spu, cellspu
name|mips
block|,
comment|// MIPS: mips, mipsallegrex
name|mipsel
block|,
comment|// MIPSEL: mipsel, mipsallegrexel, psp
name|msp430
block|,
comment|// MSP430: msp430
name|pic16
block|,
comment|// PIC16: pic16
name|ppc
block|,
comment|// PPC: powerpc
name|ppc64
block|,
comment|// PPC64: powerpc64
name|sparc
block|,
comment|// Sparc: sparc
name|systemz
block|,
comment|// SystemZ: s390x
name|tce
block|,
comment|// TCE (http://tce.cs.tut.fi/): tce
name|thumb
block|,
comment|// Thumb: thumb, thumbv.*
name|x86
block|,
comment|// X86: i[3-9]86
name|x86_64
block|,
comment|// X86-64: amd64, x86_64
name|xcore
block|,
comment|// XCore: xcore
name|InvalidArch
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
block|}
enum|;
enum|enum
name|OSType
block|{
name|UnknownOS
block|,
name|AuroraUX
block|,
name|Cygwin
block|,
name|Darwin
block|,
name|DragonFly
block|,
name|FreeBSD
block|,
name|Linux
block|,
name|MinGW32
block|,
name|MinGW64
block|,
name|NetBSD
block|,
name|OpenBSD
block|,
name|Psp
block|,
name|Solaris
block|,
name|Win32
block|,
name|Haiku
block|}
enum|;
name|private
label|:
name|std
operator|::
name|string
name|Data
expr_stmt|;
comment|/// The parsed arch type (or InvalidArch if uninitialized).
name|mutable
name|ArchType
name|Arch
decl_stmt|;
comment|/// The parsed vendor type.
name|mutable
name|VendorType
name|Vendor
decl_stmt|;
comment|/// The parsed OS type.
name|mutable
name|OSType
name|OS
decl_stmt|;
name|bool
name|isInitialized
argument_list|()
specifier|const
block|{
return|return
name|Arch
operator|!=
name|InvalidArch
return|;
block|}
name|void
name|Parse
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
comment|/// @name Constructors
comment|/// @{
name|Triple
argument_list|()
operator|:
name|Data
argument_list|()
operator|,
name|Arch
argument_list|(
argument|InvalidArch
argument_list|)
block|{}
name|explicit
name|Triple
argument_list|(
argument|StringRef Str
argument_list|)
operator|:
name|Data
argument_list|(
name|Str
argument_list|)
operator|,
name|Arch
argument_list|(
argument|InvalidArch
argument_list|)
block|{}
name|explicit
name|Triple
argument_list|(
argument|StringRef ArchStr
argument_list|,
argument|StringRef VendorStr
argument_list|,
argument|StringRef OSStr
argument_list|)
operator|:
name|Data
argument_list|(
name|ArchStr
argument_list|)
operator|,
name|Arch
argument_list|(
argument|InvalidArch
argument_list|)
block|{
name|Data
operator|+=
literal|'-'
block|;
name|Data
operator|+=
name|VendorStr
block|;
name|Data
operator|+=
literal|'-'
block|;
name|Data
operator|+=
name|OSStr
block|;   }
comment|/// @}
comment|/// @name Typed Component Access
comment|/// @{
comment|/// getArch - Get the parsed architecture type of this triple.
name|ArchType
name|getArch
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isInitialized
argument_list|()
condition|)
name|Parse
argument_list|()
expr_stmt|;
return|return
name|Arch
return|;
block|}
comment|/// getVendor - Get the parsed vendor type of this triple.
name|VendorType
name|getVendor
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isInitialized
argument_list|()
condition|)
name|Parse
argument_list|()
expr_stmt|;
return|return
name|Vendor
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getOS - Get the parsed operating system type of this triple.
end_comment

begin_expr_stmt
name|OSType
name|getOS
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|isInitialized
argument_list|()
condition|)
name|Parse
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|OS
return|;
end_return

begin_comment
unit|}
comment|/// hasEnvironment - Does this triple have the optional environment
end_comment

begin_comment
comment|/// (fourth) component?
end_comment

begin_macro
unit|bool
name|hasEnvironment
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getEnvironmentName
argument_list|()
operator|!=
literal|""
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Direct Component Access
end_comment

begin_comment
comment|/// @{
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// getArchName - Get the architecture (first) component of the
end_comment

begin_comment
comment|/// triple.
end_comment

begin_expr_stmt
name|StringRef
name|getArchName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getVendorName - Get the vendor (second) component of the triple.
end_comment

begin_expr_stmt
name|StringRef
name|getVendorName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getOSName - Get the operating system (third) component of the
end_comment

begin_comment
comment|/// triple.
end_comment

begin_expr_stmt
name|StringRef
name|getOSName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getEnvironmentName - Get the optional environment (fourth)
end_comment

begin_comment
comment|/// component of the triple, or "" if empty.
end_comment

begin_expr_stmt
name|StringRef
name|getEnvironmentName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getOSAndEnvironmentName - Get the operating system and optional
end_comment

begin_comment
comment|/// environment components as a single string (separated by a '-'
end_comment

begin_comment
comment|/// if the environment component is present).
end_comment

begin_expr_stmt
name|StringRef
name|getOSAndEnvironmentName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getDarwinNumber - Parse the 'darwin number' out of the specific target
end_comment

begin_comment
comment|/// triple.  For example, if we have darwin8.5 return 8,5,0.  If any entry is
end_comment

begin_comment
comment|/// not defined, return 0's.  This requires that the triple have an OSType of
end_comment

begin_comment
comment|/// darwin before it is called.
end_comment

begin_decl_stmt
name|void
name|getDarwinNumber
argument_list|(
name|unsigned
operator|&
name|Maj
argument_list|,
name|unsigned
operator|&
name|Min
argument_list|,
name|unsigned
operator|&
name|Revision
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getDarwinMajorNumber - Return just the major version number, this is
end_comment

begin_comment
comment|/// specialized because it is a common query.
end_comment

begin_expr_stmt
name|unsigned
name|getDarwinMajorNumber
argument_list|()
specifier|const
block|{
name|unsigned
name|Maj
block|,
name|Min
block|,
name|Rev
block|;
name|getDarwinNumber
argument_list|(
name|Maj
argument_list|,
name|Min
argument_list|,
name|Rev
argument_list|)
block|;
return|return
name|Maj
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Mutators
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// setArch - Set the architecture (first) component of the triple
end_comment

begin_comment
comment|/// to a known type.
end_comment

begin_function_decl
name|void
name|setArch
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setVendor - Set the vendor (second) component of the triple to a
end_comment

begin_comment
comment|/// known type.
end_comment

begin_function_decl
name|void
name|setVendor
parameter_list|(
name|VendorType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setOS - Set the operating system (third) component of the triple
end_comment

begin_comment
comment|/// to a known type.
end_comment

begin_function_decl
name|void
name|setOS
parameter_list|(
name|OSType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setTriple - Set all components to the new triple \arg Str.
end_comment

begin_function_decl
name|void
name|setTriple
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setArchName - Set the architecture (first) component of the
end_comment

begin_comment
comment|/// triple by name.
end_comment

begin_function_decl
name|void
name|setArchName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setVendorName - Set the vendor (second) component of the triple
end_comment

begin_comment
comment|/// by name.
end_comment

begin_function_decl
name|void
name|setVendorName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setOSName - Set the operating system (third) component of the
end_comment

begin_comment
comment|/// triple by name.
end_comment

begin_function_decl
name|void
name|setOSName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setEnvironmentName - Set the optional environment (fourth)
end_comment

begin_comment
comment|/// component of the triple by name.
end_comment

begin_function_decl
name|void
name|setEnvironmentName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// setOSAndEnvironmentName - Set the operating system and optional
end_comment

begin_comment
comment|/// environment components with a single string.
end_comment

begin_function_decl
name|void
name|setOSAndEnvironmentName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getArchNameForAssembler - Get an architecture name that is understood by the
end_comment

begin_comment
comment|/// target assembler.
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|getArchNameForAssembler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Static helpers for IDs.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// getArchTypeName - Get the canonical name for the \arg Kind
end_comment

begin_comment
comment|/// architecture.
end_comment

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|getArchTypeName
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getArchTypePrefix - Get the "prefix" canonical name for the \arg Kind
end_comment

begin_comment
comment|/// architecture. This is the prefix used by the architecture specific
end_comment

begin_comment
comment|/// builtins, and is suitable for passing to \see
end_comment

begin_comment
comment|/// Intrinsic::getIntrinsicForGCCBuiltin().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return - The architecture prefix, or 0 if none is defined.
end_comment

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|getArchTypePrefix
parameter_list|(
name|ArchType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getVendorTypeName - Get the canonical name for the \arg Kind
end_comment

begin_comment
comment|/// vendor.
end_comment

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|getVendorTypeName
parameter_list|(
name|VendorType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getOSTypeName - Get the canonical name for the \arg Kind vendor.
end_comment

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|getOSTypeName
parameter_list|(
name|OSType
name|Kind
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
comment|/// @name Static helpers for converting alternate architecture names.
end_comment

begin_comment
comment|/// @{
end_comment

begin_comment
comment|/// getArchTypeForLLVMName - The canonical type for the given LLVM
end_comment

begin_comment
comment|/// architecture name (e.g., "x86").
end_comment

begin_function_decl
specifier|static
name|ArchType
name|getArchTypeForLLVMName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getArchTypeForDarwinArchName - Get the architecture type for a "Darwin"
end_comment

begin_comment
comment|/// architecture name, for example as accepted by "gcc -arch" (see also
end_comment

begin_comment
comment|/// arch(3)).
end_comment

begin_function_decl
specifier|static
name|ArchType
name|getArchTypeForDarwinArchName
parameter_list|(
name|StringRef
name|Str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @}
end_comment

begin_comment
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

