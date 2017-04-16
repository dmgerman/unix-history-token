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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::LangOptions interface.
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
name|LLVM_CLANG_BASIC_LANGOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_LANGOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/CommentOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ObjCRuntime.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Sanitizers.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Visibility.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// Bitfields of LangOptions, split out from LangOptions in order to ensure that
comment|/// this large collection of bitfields is a trivial class type.
name|class
name|LangOptionsBase
block|{
name|public
label|:
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
name|protected
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
block|}
empty_stmt|;
comment|/// \brief Keeps track of the various options that can be
comment|/// enabled, which controls the dialect of C or C++ that is accepted.
name|class
name|LangOptions
range|:
name|public
name|LangOptionsBase
block|{
name|public
operator|:
typedef|typedef
name|clang
operator|::
name|Visibility
name|Visibility
expr_stmt|;
block|enum
name|GCMode
block|{
name|NonGC
block|,
name|GCOnly
block|,
name|HybridGC
block|}
decl_stmt|;
enum|enum
name|StackProtectorMode
block|{
name|SSPOff
block|,
name|SSPOn
block|,
name|SSPStrong
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
enum|enum
name|CompilingModuleKind
block|{
name|CMK_None
block|,
comment|///< Not compiling a module interface at all.
name|CMK_ModuleMap
block|,
comment|///< Compiling a module from a module map.
name|CMK_ModuleInterface
comment|///< Compiling a C++ modules TS module interface unit.
block|}
enum|;
enum|enum
name|PragmaMSPointersToMembersKind
block|{
name|PPTMK_BestCase
block|,
name|PPTMK_FullGeneralitySingleInheritance
block|,
name|PPTMK_FullGeneralityMultipleInheritance
block|,
name|PPTMK_FullGeneralityVirtualInheritance
block|}
enum|;
enum|enum
name|DefaultCallingConvention
block|{
name|DCC_None
block|,
name|DCC_CDecl
block|,
name|DCC_FastCall
block|,
name|DCC_StdCall
block|,
name|DCC_VectorCall
block|}
enum|;
enum|enum
name|AddrSpaceMapMangling
block|{
name|ASMM_Target
block|,
name|ASMM_On
block|,
name|ASMM_Off
block|}
enum|;
enum|enum
name|MSVCMajorVersion
block|{
name|MSVC2010
init|=
literal|16
block|,
name|MSVC2012
init|=
literal|17
block|,
name|MSVC2013
init|=
literal|18
block|,
name|MSVC2015
init|=
literal|19
block|}
enum|;
enum|enum
name|FPContractModeKind
block|{
name|FPC_Off
block|,
comment|// Form fused FP ops only where result will not be affected.
name|FPC_On
block|,
comment|// Form fused FP ops according to FP_CONTRACT rules.
name|FPC_Fast
comment|// Aggressively fuse FP ops (E.g. FMA).
block|}
enum|;
name|public
label|:
comment|/// \brief Set of enabled sanitizers.
name|SanitizerSet
name|Sanitize
decl_stmt|;
comment|/// \brief Paths to blacklist files specifying which objects
comment|/// (files, functions, variables) should not be instrumented.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|SanitizerBlacklistFiles
expr_stmt|;
comment|/// \brief Paths to the XRay "always instrument" files specifying which
comment|/// objects (files, functions, variables) should be imbued with the XRay
comment|/// "always instrument" attribute.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|XRayAlwaysInstrumentFiles
expr_stmt|;
comment|/// \brief Paths to the XRay "never instrument" files specifying which
comment|/// objects (files, functions, variables) should be imbued with the XRay
comment|/// "never instrument" attribute.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|XRayNeverInstrumentFiles
expr_stmt|;
name|clang
operator|::
name|ObjCRuntime
name|ObjCRuntime
expr_stmt|;
name|std
operator|::
name|string
name|ObjCConstantStringClass
expr_stmt|;
comment|/// \brief The name of the handler function to be called when -ftrapv is
comment|/// specified.
comment|///
comment|/// If none is specified, abort (GCC-compatible behaviour).
name|std
operator|::
name|string
name|OverflowHandler
expr_stmt|;
comment|/// \brief The name of the current module, of which the main source file
comment|/// is a part. If CompilingModule is set, we are compiling the interface
comment|/// of this module, otherwise we are compiling an implementation file of
comment|/// it.
name|std
operator|::
name|string
name|CurrentModule
expr_stmt|;
comment|/// \brief The names of any features to enable in module 'requires' decls
comment|/// in addition to the hard-coded list in Module.cpp and the target features.
comment|///
comment|/// This list is sorted.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ModuleFeatures
expr_stmt|;
comment|/// \brief Options for parsing comments.
name|CommentOptions
name|CommentOpts
decl_stmt|;
comment|/// \brief A list of all -fno-builtin-* function names (e.g., memset).
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|NoBuiltinFuncs
expr_stmt|;
comment|/// \brief Triples of the OpenMP targets that the host code codegen should
comment|/// take into account in order to generate accurate offloading descriptors.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|Triple
operator|>
name|OMPTargetTriples
expr_stmt|;
comment|/// \brief Name of the IR file that contains the result of the OpenMP target
comment|/// host code generation.
name|std
operator|::
name|string
name|OMPHostIRFile
expr_stmt|;
comment|/// \brief Indicates whether the front-end is explicitly told that the
comment|/// input is a header file (i.e. -x c-header).
name|bool
name|IsHeaderFile
decl_stmt|;
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
comment|/// Are we compiling a module interface (.cppm or module map)?
name|bool
name|isCompilingModule
argument_list|()
specifier|const
block|{
return|return
name|getCompilingModule
argument_list|()
operator|!=
name|CMK_None
return|;
block|}
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
name|bool
name|isSubscriptPointerArithmetic
argument_list|()
specifier|const
block|{
return|return
name|ObjCRuntime
operator|.
name|isSubscriptPointerArithmetic
argument_list|()
operator|&&
operator|!
name|ObjCSubscriptingLegacyRuntime
return|;
block|}
name|bool
name|isCompatibleWithMSVC
argument_list|(
name|MSVCMajorVersion
name|MajorVersion
argument_list|)
decl|const
block|{
return|return
name|MSCompatibilityVersion
operator|>=
name|MajorVersion
operator|*
literal|10000000U
return|;
block|}
comment|/// \brief Reset all of the options that are not considered when building a
comment|/// module.
name|void
name|resetNonModularOptions
parameter_list|()
function_decl|;
comment|/// \brief Is this a libc/libm function that is no longer recognized as a
comment|/// builtin because a -fno-builtin-* option has been specified?
name|bool
name|isNoBuiltinFunc
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief True if any ObjC types may have non-trivial lifetime qualifiers.
name|bool
name|allowsNonTrivialObjCLifetimeQualifiers
argument_list|()
specifier|const
block|{
return|return
name|ObjCAutoRefCount
operator|||
name|ObjCWeak
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Floating point control options
end_comment

begin_decl_stmt
name|class
name|FPOptions
block|{
name|public
label|:
name|FPOptions
argument_list|()
operator|:
name|fp_contract
argument_list|(
argument|LangOptions::FPC_Off
argument_list|)
block|{}
comment|// Used for serializing.
name|explicit
name|FPOptions
argument_list|(
argument|unsigned I
argument_list|)
operator|:
name|fp_contract
argument_list|(
argument|static_cast<LangOptions::FPContractModeKind>(I)
argument_list|)
block|{}
name|explicit
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
argument|LangOpts.getDefaultFPContractMode()
argument_list|)
block|{}
name|bool
name|allowFPContractWithinStatement
argument_list|()
specifier|const
block|{
return|return
name|fp_contract
operator|==
name|LangOptions
operator|::
name|FPC_On
return|;
block|}
name|bool
name|allowFPContractAcrossStatement
argument_list|()
specifier|const
block|{
return|return
name|fp_contract
operator|==
name|LangOptions
operator|::
name|FPC_Fast
return|;
block|}
name|void
name|setAllowFPContractWithinStatement
parameter_list|()
block|{
name|fp_contract
operator|=
name|LangOptions
operator|::
name|FPC_On
expr_stmt|;
block|}
name|void
name|setAllowFPContractAcrossStatement
parameter_list|()
block|{
name|fp_contract
operator|=
name|LangOptions
operator|::
name|FPC_Fast
expr_stmt|;
block|}
name|void
name|setDisallowFPContract
parameter_list|()
block|{
name|fp_contract
operator|=
name|LangOptions
operator|::
name|FPC_Off
expr_stmt|;
block|}
comment|/// Used to serialize this.
name|unsigned
name|getInt
argument_list|()
specifier|const
block|{
return|return
name|fp_contract
return|;
block|}
name|private
label|:
comment|/// Adjust BinaryOperator::FPFeatures to match the bit-field size of this.
name|unsigned
name|fp_contract
range|:
literal|2
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Describes the kind of translation unit being processed.
end_comment

begin_enum
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
end_enum

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

