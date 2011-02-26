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
name|unsigned
name|Trigraphs
range|:
literal|1
decl_stmt|;
comment|// Trigraphs in source files.
name|unsigned
name|BCPLComment
range|:
literal|1
decl_stmt|;
comment|// BCPL-style '//' comments.
name|unsigned
name|Bool
range|:
literal|1
decl_stmt|;
comment|// 'bool', 'true', 'false' keywords.
name|unsigned
name|DollarIdents
range|:
literal|1
decl_stmt|;
comment|// '$' allowed in identifiers.
name|unsigned
name|AsmPreprocessor
range|:
literal|1
decl_stmt|;
comment|// Preprocessor in asm mode.
name|unsigned
name|GNUMode
range|:
literal|1
decl_stmt|;
comment|// True in gnu99 mode false in c99 mode (etc)
name|unsigned
name|GNUKeywords
range|:
literal|1
decl_stmt|;
comment|// True if GNU-only keywords are allowed
name|unsigned
name|ImplicitInt
range|:
literal|1
decl_stmt|;
comment|// C89 implicit 'int'.
name|unsigned
name|Digraphs
range|:
literal|1
decl_stmt|;
comment|// C94, C99 and C++
name|unsigned
name|HexFloats
range|:
literal|1
decl_stmt|;
comment|// C99 Hexadecimal float constants.
name|unsigned
name|C99
range|:
literal|1
decl_stmt|;
comment|// C99 Support
name|unsigned
name|Microsoft
range|:
literal|1
decl_stmt|;
comment|// Microsoft extensions.
name|unsigned
name|Borland
range|:
literal|1
decl_stmt|;
comment|// Borland extensions.
name|unsigned
name|CPlusPlus
range|:
literal|1
decl_stmt|;
comment|// C++ Support
name|unsigned
name|CPlusPlus0x
range|:
literal|1
decl_stmt|;
comment|// C++0x Support
name|unsigned
name|CXXOperatorNames
range|:
literal|1
decl_stmt|;
comment|// Treat C++ operator names as keywords.
name|unsigned
name|ObjC1
range|:
literal|1
decl_stmt|;
comment|// Objective-C 1 support enabled.
name|unsigned
name|ObjC2
range|:
literal|1
decl_stmt|;
comment|// Objective-C 2 support enabled.
name|unsigned
name|ObjCNonFragileABI
range|:
literal|1
decl_stmt|;
comment|// Objective-C modern abi enabled
name|unsigned
name|ObjCNonFragileABI2
range|:
literal|1
decl_stmt|;
comment|// Objective-C enhanced modern abi enabled
name|unsigned
name|ObjCDefaultSynthProperties
range|:
literal|1
decl_stmt|;
comment|// Objective-C auto-synthesized properties.
name|unsigned
name|AppleKext
range|:
literal|1
decl_stmt|;
comment|// Allow apple kext features.
name|unsigned
name|PascalStrings
range|:
literal|1
decl_stmt|;
comment|// Allow Pascal strings
name|unsigned
name|WritableStrings
range|:
literal|1
decl_stmt|;
comment|// Allow writable strings
name|unsigned
name|ConstStrings
range|:
literal|1
decl_stmt|;
comment|// Add const qualifier to strings (-Wwrite-strings)
name|unsigned
name|LaxVectorConversions
range|:
literal|1
decl_stmt|;
name|unsigned
name|AltiVec
range|:
literal|1
decl_stmt|;
comment|// Support AltiVec-style vector initializers.
name|unsigned
name|Exceptions
range|:
literal|1
decl_stmt|;
comment|// Support exception handling.
name|unsigned
name|ObjCExceptions
range|:
literal|1
decl_stmt|;
comment|// Support Objective-C exceptions.
name|unsigned
name|CXXExceptions
range|:
literal|1
decl_stmt|;
comment|// Support C++ exceptions.
name|unsigned
name|SjLjExceptions
range|:
literal|1
decl_stmt|;
comment|// Use setjmp-longjump exception handling.
name|unsigned
name|RTTI
range|:
literal|1
decl_stmt|;
comment|// Support RTTI information.
name|unsigned
name|MSBitfields
range|:
literal|1
decl_stmt|;
comment|// MS-compatible structure layout
name|unsigned
name|NeXTRuntime
range|:
literal|1
decl_stmt|;
comment|// Use NeXT runtime.
name|unsigned
name|Freestanding
range|:
literal|1
decl_stmt|;
comment|// Freestanding implementation
name|unsigned
name|NoBuiltin
range|:
literal|1
decl_stmt|;
comment|// Do not use builtin functions (-fno-builtin)
name|unsigned
name|ThreadsafeStatics
range|:
literal|1
decl_stmt|;
comment|// Whether static initializers are protected
comment|// by locks.
name|unsigned
name|POSIXThreads
range|:
literal|1
decl_stmt|;
comment|// Compiling with POSIX thread support
comment|// (-pthread)
name|unsigned
name|Blocks
range|:
literal|1
decl_stmt|;
comment|// block extension to C
name|unsigned
name|EmitAllDecls
range|:
literal|1
decl_stmt|;
comment|// Emit all declarations, even if
comment|// they are unused.
name|unsigned
name|MathErrno
range|:
literal|1
decl_stmt|;
comment|// Math functions must respect errno
comment|// (modulo the platform support).
name|unsigned
name|HeinousExtensions
range|:
literal|1
decl_stmt|;
comment|// Extensions that we really don't like and
comment|// may be ripped out at any time.
name|unsigned
name|Optimize
range|:
literal|1
decl_stmt|;
comment|// Whether __OPTIMIZE__ should be defined.
name|unsigned
name|OptimizeSize
range|:
literal|1
decl_stmt|;
comment|// Whether __OPTIMIZE_SIZE__ should be
comment|// defined.
name|unsigned
name|Static
range|:
literal|1
decl_stmt|;
comment|// Should __STATIC__ be defined (as
comment|// opposed to __DYNAMIC__).
name|unsigned
name|PICLevel
range|:
literal|2
decl_stmt|;
comment|// The value for __PIC__, if non-zero.
name|unsigned
name|GNUInline
range|:
literal|1
decl_stmt|;
comment|// Should GNU inline semantics be
comment|// used (instead of C99 semantics).
name|unsigned
name|NoInline
range|:
literal|1
decl_stmt|;
comment|// Should __NO_INLINE__ be defined.
name|unsigned
name|ObjCGCBitmapPrint
range|:
literal|1
decl_stmt|;
comment|// Enable printing of gc's bitmap layout
comment|// for __weak/__strong ivars.
name|unsigned
name|AccessControl
range|:
literal|1
decl_stmt|;
comment|// Whether C++ access control should
comment|// be enabled.
name|unsigned
name|CharIsSigned
range|:
literal|1
decl_stmt|;
comment|// Whether char is a signed or unsigned type
name|unsigned
name|ShortWChar
range|:
literal|1
decl_stmt|;
comment|// Force wchar_t to be unsigned short int.
name|unsigned
name|ShortEnums
range|:
literal|1
decl_stmt|;
comment|// The enum type will be equivalent to the
comment|// smallest integer type with enough room.
name|unsigned
name|OpenCL
range|:
literal|1
decl_stmt|;
comment|// OpenCL C99 language extensions.
name|unsigned
name|CUDA
range|:
literal|1
decl_stmt|;
comment|// CUDA C++ language extensions.
name|unsigned
name|AssumeSaneOperatorNew
range|:
literal|1
decl_stmt|;
comment|// Whether to add __attribute__((malloc))
comment|// to the declaration of C++'s new
comment|// operators
name|unsigned
name|ElideConstructors
range|:
literal|1
decl_stmt|;
comment|// Whether C++ copy constructors should be
comment|// elided if possible.
name|unsigned
name|CatchUndefined
range|:
literal|1
decl_stmt|;
comment|// Generate code to check for undefined ops.
name|unsigned
name|DumpRecordLayouts
range|:
literal|1
decl_stmt|;
comment|/// Dump the layout of IRgen'd records.
name|unsigned
name|DumpVTableLayouts
range|:
literal|1
decl_stmt|;
comment|/// Dump the layouts of emitted vtables.
name|unsigned
name|NoConstantCFStrings
range|:
literal|1
decl_stmt|;
comment|// Do not do CF strings
name|unsigned
name|InlineVisibilityHidden
range|:
literal|1
decl_stmt|;
comment|// Whether inline C++ methods have
comment|// hidden visibility by default.
name|unsigned
name|SpellChecking
range|:
literal|1
decl_stmt|;
comment|// Whether to perform spell-checking for error
comment|// recovery.
name|unsigned
name|SinglePrecisionConstants
range|:
literal|1
decl_stmt|;
comment|// Whether to treat double-precision
comment|// floating point constants as
comment|// single precision constants.
name|unsigned
name|FastRelaxedMath
range|:
literal|1
decl_stmt|;
comment|// OpenCL fast relaxed math (on its own,
comment|// defines __FAST_RELAXED_MATH__).
name|unsigned
name|DefaultFPContract
range|:
literal|1
decl_stmt|;
comment|// Default setting for FP_CONTRACT
comment|// FIXME: This is just a temporary option, for testing purposes.
name|unsigned
name|NoBitFieldTypeAlign
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|// We declare multibit enums as unsigned because MSVC insists on making enums
comment|// signed.  Set/Query these values using accessors.
name|unsigned
name|GC
range|:
literal|2
decl_stmt|;
comment|// Objective-C Garbage Collection modes.
name|unsigned
name|SymbolVisibility
range|:
literal|3
decl_stmt|;
comment|// Symbol's visibility.
name|unsigned
name|StackProtector
range|:
literal|2
decl_stmt|;
comment|// Whether stack protectors are on.
name|unsigned
name|SignedOverflowBehavior
range|:
literal|2
decl_stmt|;
comment|// How to handle signed integer overflow.
name|public
label|:
name|unsigned
name|InstantiationDepth
decl_stmt|;
comment|// Maximum template instantiation depth.
name|unsigned
name|NumLargeByValueCopy
decl_stmt|;
comment|// Warn if parameter/return value is larger
comment|// in bytes than this setting. 0 is no check.
comment|// Version of Microsoft Visual C/C++ we are pretending to be. This is
comment|// temporary until we support all MS extensions used in Windows SDK and stdlib
comment|// headers. Sets _MSC_VER.
name|unsigned
name|MSCVersion
decl_stmt|;
name|std
operator|::
name|string
name|ObjCConstantStringClass
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
comment|/// The name of the handler function to be called when -ftrapv is specified.
comment|/// If none is specified, abort (GCC-compatible behaviour).
name|std
operator|::
name|string
name|OverflowHandler
expr_stmt|;
name|LangOptions
argument_list|()
block|{
name|Trigraphs
operator|=
name|BCPLComment
operator|=
name|Bool
operator|=
name|DollarIdents
operator|=
name|AsmPreprocessor
operator|=
literal|0
expr_stmt|;
name|GNUMode
operator|=
name|GNUKeywords
operator|=
name|ImplicitInt
operator|=
name|Digraphs
operator|=
literal|0
expr_stmt|;
name|HexFloats
operator|=
literal|0
expr_stmt|;
name|GC
operator|=
name|ObjC1
operator|=
name|ObjC2
operator|=
name|ObjCNonFragileABI
operator|=
name|ObjCNonFragileABI2
operator|=
literal|0
expr_stmt|;
name|AppleKext
operator|=
literal|0
expr_stmt|;
name|ObjCDefaultSynthProperties
operator|=
literal|0
expr_stmt|;
name|NoConstantCFStrings
operator|=
literal|0
expr_stmt|;
name|InlineVisibilityHidden
operator|=
literal|0
expr_stmt|;
name|C99
operator|=
name|Microsoft
operator|=
name|Borland
operator|=
name|CPlusPlus
operator|=
name|CPlusPlus0x
operator|=
literal|0
expr_stmt|;
name|CXXOperatorNames
operator|=
name|PascalStrings
operator|=
name|WritableStrings
operator|=
name|ConstStrings
operator|=
literal|0
expr_stmt|;
name|Exceptions
operator|=
name|ObjCExceptions
operator|=
name|CXXExceptions
operator|=
name|SjLjExceptions
operator|=
literal|0
expr_stmt|;
name|Freestanding
operator|=
name|NoBuiltin
operator|=
literal|0
expr_stmt|;
name|MSBitfields
operator|=
literal|0
expr_stmt|;
name|NeXTRuntime
operator|=
literal|1
expr_stmt|;
name|RTTI
operator|=
literal|1
expr_stmt|;
name|LaxVectorConversions
operator|=
literal|1
expr_stmt|;
name|HeinousExtensions
operator|=
literal|0
expr_stmt|;
name|AltiVec
operator|=
name|OpenCL
operator|=
name|CUDA
operator|=
name|StackProtector
operator|=
literal|0
expr_stmt|;
name|SymbolVisibility
operator|=
operator|(
name|unsigned
operator|)
name|DefaultVisibility
expr_stmt|;
name|ThreadsafeStatics
operator|=
literal|1
expr_stmt|;
name|POSIXThreads
operator|=
literal|0
expr_stmt|;
name|Blocks
operator|=
literal|0
expr_stmt|;
name|EmitAllDecls
operator|=
literal|0
expr_stmt|;
name|MathErrno
operator|=
literal|1
expr_stmt|;
name|SignedOverflowBehavior
operator|=
name|SOB_Undefined
expr_stmt|;
name|AssumeSaneOperatorNew
operator|=
literal|1
expr_stmt|;
name|AccessControl
operator|=
literal|1
expr_stmt|;
name|ElideConstructors
operator|=
literal|1
expr_stmt|;
name|SignedOverflowBehavior
operator|=
literal|0
expr_stmt|;
name|ObjCGCBitmapPrint
operator|=
literal|0
expr_stmt|;
name|InstantiationDepth
operator|=
literal|1024
expr_stmt|;
name|NumLargeByValueCopy
operator|=
literal|0
expr_stmt|;
name|MSCVersion
operator|=
literal|0
expr_stmt|;
name|Optimize
operator|=
literal|0
expr_stmt|;
name|OptimizeSize
operator|=
literal|0
expr_stmt|;
name|Static
operator|=
literal|0
expr_stmt|;
name|PICLevel
operator|=
literal|0
expr_stmt|;
name|GNUInline
operator|=
literal|0
expr_stmt|;
name|NoInline
operator|=
literal|0
expr_stmt|;
name|CharIsSigned
operator|=
literal|1
expr_stmt|;
name|ShortWChar
operator|=
literal|0
expr_stmt|;
name|ShortEnums
operator|=
literal|0
expr_stmt|;
name|CatchUndefined
operator|=
literal|0
expr_stmt|;
name|DumpRecordLayouts
operator|=
literal|0
expr_stmt|;
name|DumpVTableLayouts
operator|=
literal|0
expr_stmt|;
name|SpellChecking
operator|=
literal|1
expr_stmt|;
name|SinglePrecisionConstants
operator|=
literal|0
expr_stmt|;
name|FastRelaxedMath
operator|=
literal|0
expr_stmt|;
name|DefaultFPContract
operator|=
literal|0
expr_stmt|;
name|NoBitFieldTypeAlign
operator|=
literal|0
expr_stmt|;
block|}
name|GCMode
name|getGCMode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|GCMode
operator|)
name|GC
return|;
block|}
name|void
name|setGCMode
parameter_list|(
name|GCMode
name|m
parameter_list|)
block|{
name|GC
operator|=
operator|(
name|unsigned
operator|)
name|m
expr_stmt|;
block|}
name|StackProtectorMode
name|getStackProtectorMode
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|StackProtectorMode
operator|>
operator|(
name|StackProtector
operator|)
return|;
block|}
name|void
name|setStackProtectorMode
parameter_list|(
name|StackProtectorMode
name|m
parameter_list|)
block|{
name|StackProtector
operator|=
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|m
operator|)
expr_stmt|;
block|}
name|Visibility
name|getVisibilityMode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Visibility
operator|)
name|SymbolVisibility
return|;
block|}
name|void
name|setVisibilityMode
parameter_list|(
name|Visibility
name|v
parameter_list|)
block|{
name|SymbolVisibility
operator|=
operator|(
name|unsigned
operator|)
name|v
expr_stmt|;
block|}
name|SignedOverflowBehaviorTy
name|getSignedOverflowBehavior
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SignedOverflowBehaviorTy
operator|)
name|SignedOverflowBehavior
return|;
block|}
name|void
name|setSignedOverflowBehavior
parameter_list|(
name|SignedOverflowBehaviorTy
name|V
parameter_list|)
block|{
name|SignedOverflowBehavior
operator|=
operator|(
name|unsigned
operator|)
name|V
expr_stmt|;
block|}
name|bool
name|areExceptionsEnabled
argument_list|()
specifier|const
block|{
return|return
name|Exceptions
return|;
block|}
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

