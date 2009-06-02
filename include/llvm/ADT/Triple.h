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
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
comment|/// See autoconf/config.guess for a glimpse into what they look like
comment|/// in practice.
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
name|x86
block|,
comment|// i?86
name|ppc
block|,
comment|// powerpc
name|ppc64
block|,
comment|// powerpc64
name|x86_64
block|,
comment|// amd64, x86_64
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
name|Darwin
block|,
name|DragonFly
block|,
name|FreeBSD
block|,
name|Linux
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
argument_list|(
literal|""
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
specifier|const
name|char
operator|*
name|Str
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
specifier|const
name|char
operator|*
name|ArchStr
argument_list|,
specifier|const
name|char
operator|*
name|VendorStr
argument_list|,
specifier|const
name|char
operator|*
name|OSStr
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
comment|// FIXME: Invent a lightweight string representation for these to
end_comment

begin_comment
comment|// use.
end_comment

begin_comment
comment|/// getArchName - Get the architecture (first) component of the
end_comment

begin_comment
comment|/// triple.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getArchName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getVendorName - Get the vendor (second) component of the triple.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
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
name|std
operator|::
name|string
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
name|std
operator|::
name|string
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
name|std
operator|::
name|string
name|getOSAndEnvironmentName
argument_list|()
specifier|const
expr_stmt|;
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

begin_decl_stmt
name|void
name|setTriple
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// setArchName - Set the architecture (first) component of the
end_comment

begin_comment
comment|/// triple by name.
end_comment

begin_decl_stmt
name|void
name|setArchName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// setVendorName - Set the vendor (second) component of the triple
end_comment

begin_comment
comment|/// by name.
end_comment

begin_decl_stmt
name|void
name|setVendorName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// setOSName - Set the operating system (third) component of the
end_comment

begin_comment
comment|/// triple by name.
end_comment

begin_decl_stmt
name|void
name|setOSName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// setEnvironmentName - Set the optional environment (fourth)
end_comment

begin_comment
comment|/// component of the triple by name.
end_comment

begin_decl_stmt
name|void
name|setEnvironmentName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// setOSAndEnvironmentName - Set the operating system and optional
end_comment

begin_comment
comment|/// environment components with a single string.
end_comment

begin_decl_stmt
name|void
name|setOSAndEnvironmentName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
decl_stmt|;
end_decl_stmt

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
unit|};  }
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

