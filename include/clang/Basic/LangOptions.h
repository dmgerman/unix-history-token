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
name|Rtti
range|:
literal|1
decl_stmt|;
comment|// Support rtti information.
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
name|BlockIntrospection
range|:
literal|1
decl_stmt|;
comment|// block have ObjC type encodings.
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
name|OverflowChecking
range|:
literal|1
decl_stmt|;
comment|// Extension to call a handler function when
comment|// signed integer arithmetic overflows.
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
name|OpenCL
range|:
literal|1
decl_stmt|;
comment|// OpenCL C99 language extensions.
name|unsigned
name|ElideConstructors
range|:
literal|1
decl_stmt|;
comment|// Whether C++ copy constructors should be
comment|// elided if possible.
name|private
label|:
name|unsigned
name|GC
range|:
literal|2
decl_stmt|;
comment|// Objective-C Garbage Collection modes.  We
comment|// declare this enum as unsigned because MSVC
comment|// insists on making enums signed.  Set/Query
comment|// this value using accessors.
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
comment|// Whether stack protectors are on. We declare
comment|// this enum as unsigned because MSVC insists
comment|// on making enums signed.  Set/Query this
comment|// value using accessors.
comment|/// The user provided name for the "main file", if non-null. This is
comment|/// useful in situations where the input file name does not match
comment|/// the original input file, for example with -save-temps.
specifier|const
name|char
modifier|*
name|MainFileName
decl_stmt|;
name|public
label|:
name|unsigned
name|InstantiationDepth
decl_stmt|;
comment|// Maximum template instantiation depth.
specifier|const
name|char
modifier|*
name|ObjCConstantStringClass
decl_stmt|;
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
name|VisibilityMode
block|{
name|Default
block|,
name|Protected
block|,
name|Hidden
block|}
enum|;
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
literal|0
expr_stmt|;
name|ObjCConstantStringClass
operator|=
literal|0
expr_stmt|;
name|C99
operator|=
name|Microsoft
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
literal|0
expr_stmt|;
name|Exceptions
operator|=
name|Freestanding
operator|=
name|NoBuiltin
operator|=
literal|0
expr_stmt|;
name|NeXTRuntime
operator|=
literal|1
expr_stmt|;
name|Rtti
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
name|StackProtector
operator|=
literal|0
expr_stmt|;
name|SymbolVisibility
operator|=
operator|(
name|unsigned
operator|)
name|Default
expr_stmt|;
comment|// FIXME: The default should be 1.
name|ThreadsafeStatics
operator|=
literal|0
expr_stmt|;
name|POSIXThreads
operator|=
literal|0
expr_stmt|;
name|Blocks
operator|=
literal|0
expr_stmt|;
name|BlockIntrospection
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
comment|// FIXME: The default should be 1.
name|AccessControl
operator|=
literal|0
expr_stmt|;
name|ElideConstructors
operator|=
literal|1
expr_stmt|;
name|OverflowChecking
operator|=
literal|0
expr_stmt|;
name|ObjCGCBitmapPrint
operator|=
literal|0
expr_stmt|;
name|InstantiationDepth
operator|=
literal|99
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
name|MainFileName
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
specifier|const
name|char
operator|*
name|getMainFileName
argument_list|()
specifier|const
block|{
return|return
name|MainFileName
return|;
block|}
name|void
name|setMainFileName
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|MainFileName
operator|=
name|Name
expr_stmt|;
block|}
name|VisibilityMode
name|getVisibilityMode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|VisibilityMode
operator|)
name|SymbolVisibility
return|;
block|}
name|void
name|setVisibilityMode
parameter_list|(
name|VisibilityMode
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

