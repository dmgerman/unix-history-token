begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Mangler.h - Self-contained name mangler ----*- C++ -*-===//
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
comment|// Unified name mangler for various backends.
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
name|LLVM_SUPPORT_MANGLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_MANGLER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
name|class
name|Mangler
block|{
name|public
label|:
enum|enum
name|ManglerPrefixTy
block|{
name|Default
block|,
comment|///< Emit default string before each symbol.
name|Private
block|,
comment|///< Emit "private" prefix before each symbol.
name|LinkerPrivate
comment|///< Emit "linker private" prefix before each symbol.
block|}
enum|;
name|private
label|:
comment|/// Prefix - This string is added to each symbol that is emitted, unless the
comment|/// symbol is marked as not needing this prefix.
specifier|const
name|char
modifier|*
name|Prefix
decl_stmt|;
comment|/// PrivatePrefix - This string is emitted before each symbol with private
comment|/// linkage.
specifier|const
name|char
modifier|*
name|PrivatePrefix
decl_stmt|;
comment|/// LinkerPrivatePrefix - This string is emitted before each symbol with
comment|/// "linker_private" linkage.
specifier|const
name|char
modifier|*
name|LinkerPrivatePrefix
decl_stmt|;
comment|/// UseQuotes - If this is set, the target accepts global names in quotes,
comment|/// e.g. "foo bar" is a legal name.  This syntax is used instead of escaping
comment|/// the space character.  By default, this is false.
name|bool
name|UseQuotes
decl_stmt|;
comment|/// SymbolsCanStartWithDigit - If this is set, the target allows symbols to
comment|/// start with digits (e.g., "0x0021").  By default, this is false.
name|bool
name|SymbolsCanStartWithDigit
decl_stmt|;
comment|/// AnonGlobalIDs - We need to give global values the same name every time
comment|/// they are mangled.  This keeps track of the number we give to anonymous
comment|/// ones.
comment|///
name|DenseMap
operator|<
specifier|const
name|GlobalValue
operator|*
operator|,
name|unsigned
operator|>
name|AnonGlobalIDs
expr_stmt|;
comment|/// NextAnonGlobalID - This simple counter is used to unique value names.
comment|///
name|unsigned
name|NextAnonGlobalID
decl_stmt|;
comment|/// AcceptableChars - This bitfield contains a one for each character that is
comment|/// allowed to be part of an unmangled name.
name|unsigned
name|AcceptableChars
index|[
literal|256
operator|/
literal|32
index|]
decl_stmt|;
name|public
label|:
comment|// Mangler ctor - if a prefix is specified, it will be prepended onto all
comment|// symbols.
name|Mangler
argument_list|(
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|char
operator|*
name|Prefix
operator|=
literal|""
argument_list|,
specifier|const
name|char
operator|*
name|privatePrefix
operator|=
literal|""
argument_list|,
specifier|const
name|char
operator|*
name|linkerPrivatePrefix
operator|=
literal|""
argument_list|)
expr_stmt|;
comment|/// setUseQuotes - If UseQuotes is set to true, this target accepts quoted
comment|/// strings for assembler labels.
name|void
name|setUseQuotes
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|UseQuotes
operator|=
name|Val
expr_stmt|;
block|}
comment|/// setSymbolsCanStartWithDigit - If SymbolsCanStartWithDigit is set to true,
comment|/// this target allows symbols to start with digits.
name|void
name|setSymbolsCanStartWithDigit
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|SymbolsCanStartWithDigit
operator|=
name|Val
expr_stmt|;
block|}
comment|/// Acceptable Characters - This allows the target to specify which characters
comment|/// are acceptable to the assembler without being mangled.  By default we
comment|/// allow letters, numbers, '_', '$', '.', which is what GAS accepts, and '@'.
name|void
name|markCharAcceptable
parameter_list|(
name|unsigned
name|char
name|X
parameter_list|)
block|{
name|AcceptableChars
index|[
name|X
operator|/
literal|32
index|]
operator||=
literal|1
operator|<<
operator|(
name|X
operator|&
literal|31
operator|)
expr_stmt|;
block|}
name|void
name|markCharUnacceptable
parameter_list|(
name|unsigned
name|char
name|X
parameter_list|)
block|{
name|AcceptableChars
index|[
name|X
operator|/
literal|32
index|]
operator|&=
operator|~
operator|(
literal|1
operator|<<
operator|(
name|X
operator|&
literal|31
operator|)
operator|)
expr_stmt|;
block|}
name|bool
name|isCharAcceptable
argument_list|(
name|unsigned
name|char
name|X
argument_list|)
decl|const
block|{
return|return
operator|(
name|AcceptableChars
index|[
name|X
operator|/
literal|32
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|X
operator|&
literal|31
operator|)
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// getMangledName - Returns the mangled name of V, an LLVM Value,
comment|/// in the current module.  If 'Suffix' is specified, the name ends with the
comment|/// specified suffix.  If 'ForcePrivate' is specified, the label is specified
comment|/// to have a private label prefix.
comment|///
name|std
operator|::
name|string
name|getMangledName
argument_list|(
argument|const GlobalValue *V
argument_list|,
argument|const char *Suffix =
literal|""
argument_list|,
argument|bool ForcePrivate = false
argument_list|)
expr_stmt|;
comment|/// makeNameProper - We don't want identifier names with ., space, or
comment|/// - in them, so we mangle these characters into the strings "d_",
comment|/// "s_", and "D_", respectively. This is a very simple mangling that
comment|/// doesn't guarantee unique names for values. getValueName already
comment|/// does this for you, so there's no point calling it on the result
comment|/// from getValueName.
comment|///
name|std
operator|::
name|string
name|makeNameProper
argument_list|(
argument|const std::string&x
argument_list|,
argument|ManglerPrefixTy PrefixTy = Mangler::Default
argument_list|)
expr_stmt|;
comment|/// getNameWithPrefix - Fill OutName with the name of the appropriate prefix
comment|/// and the specified global variable's name.  If the global variable doesn't
comment|/// have a name, this fills in a unique name for the global.
name|void
name|getNameWithPrefix
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|OutName
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|bool
name|isImplicitlyPrivate
argument_list|)
decl_stmt|;
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

begin_comment
comment|// LLVM_SUPPORT_MANGLER_H
end_comment

end_unit

