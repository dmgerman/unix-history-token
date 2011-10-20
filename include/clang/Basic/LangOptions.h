begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LangOptions.h - C Language Family Language Options -----*- C++ -*-===//
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
comment|//  This file defines the LangOptions interface.
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
name|LLVM_CLANG_LANGOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LANGOPTIONS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Visibility.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// LangOptions - This class keeps track of the various options that can be
comment|/// enabled, which controls the dialect of C that is accepted.
name|class
name|LangOptions
block|{
name|public
label|:
typedef|typedef
name|clang
operator|::
name|Visibility
name|Visibility
expr_stmt|;
enum|enum
name|GCMode
block|{
name|NonGC
block|,
name|GCOnly
block|,
name|HybridGC
block|}
enum|;
enum|enum
name|StackProtectorMode
block|{
name|SSPOff
block|,
name|SSPOn
block|,
name|SSPReq
block|}
enum|;
enum|enum
name|SignedOverflowBehaviorTy
block|{
name|SOB_Undefined
block|,
comment|// Default C standard behavior.
name|SOB_Defined
block|,
comment|// -fwrapv
name|SOB_Trapping
comment|// -ftrapv
block|}
enum|;
comment|// Define simple language options (with no accessors).
define|#
directive|define
name|LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
value|unsigned Name : Bits;
define|#
directive|define
name|ENUM_LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
include|#
directive|include
file|"clang/Basic/LangOptions.def"
name|private
label|:
comment|// Define language options of enumeration type. These are private, and will
comment|// have accessors (below).
define|#
directive|define
name|LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
define|#
directive|define
name|ENUM_LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
define|\
value|unsigned Name : Bits;
include|#
directive|include
file|"clang/Basic/LangOptions.def"
name|public
label|:
name|std
operator|::
name|string
name|ObjCConstantStringClass
expr_stmt|;
comment|/// The name of the handler function to be called when -ftrapv is specified.
comment|/// If none is specified, abort (GCC-compatible behaviour).
name|std
operator|::
name|string
name|OverflowHandler
expr_stmt|;
name|LangOptions
argument_list|()
expr_stmt|;
comment|// Define accessors/mutators for language options of enumeration type.
define|#
directive|define
name|LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
define|#
directive|define
name|ENUM_LANGOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|,
name|Description
parameter_list|)
define|\
value|Type get##Name() const { return static_cast<Type>(Name); } \   void set##Name(Type Value) { Name = static_cast<unsigned>(Value); }
include|#
directive|include
file|"clang/Basic/LangOptions.def"
name|bool
name|isSignedOverflowDefined
argument_list|()
specifier|const
block|{
return|return
name|getSignedOverflowBehavior
argument_list|()
operator|==
name|SOB_Defined
return|;
block|}
comment|/// \brief Reset all of the options that are not considered when building a
comment|/// module.
name|void
name|resetNonModularOptions
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// Floating point control options
name|class
name|FPOptions
block|{
name|public
label|:
name|unsigned
name|fp_contract
range|:
literal|1
decl_stmt|;
name|FPOptions
argument_list|()
operator|:
name|fp_contract
argument_list|(
literal|0
argument_list|)
block|{}
name|FPOptions
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
operator|:
name|fp_contract
argument_list|(
argument|LangOpts.DefaultFPContract
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// OpenCL volatile options
name|class
name|OpenCLOptions
block|{
name|public
label|:
define|#
directive|define
name|OPENCLEXT
parameter_list|(
name|nm
parameter_list|)
value|unsigned nm : 1;
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
name|OpenCLOptions
argument_list|()
block|{
define|#
directive|define
name|OPENCLEXT
parameter_list|(
name|nm
parameter_list|)
value|nm = 0;
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
block|}
block|}
empty_stmt|;
comment|/// \brief Describes the kind of translation unit being processed.
enum|enum
name|TranslationUnitKind
block|{
comment|/// \brief The translation unit is a complete translation unit.
name|TU_Complete
block|,
comment|/// \brief The translation unit is a prefix to a translation unit, and is
comment|/// not complete.
name|TU_Prefix
block|,
comment|/// \brief The translation unit is a module.
name|TU_Module
block|}
enum|;
comment|/// \brief
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

