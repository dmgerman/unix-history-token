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
name|class
name|Mangler
block|{
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
comment|/// UseQuotes - If this is set, the target accepts global names in quotes,
comment|/// e.g. "foo bar" is a legal name.  This syntax is used instead of escaping
comment|/// the space character.  By default, this is false.
name|bool
name|UseQuotes
decl_stmt|;
comment|/// PreserveAsmNames - If this is set, the asm escape character is not removed
comment|/// from names with 'asm' specifiers.
name|bool
name|PreserveAsmNames
decl_stmt|;
comment|/// Memo - This is used to remember the name that we assign a value.
comment|///
name|DenseMap
operator|<
specifier|const
name|Value
operator|*
operator|,
name|std
operator|::
name|string
operator|>
name|Memo
expr_stmt|;
comment|/// Count - This simple counter is used to unique value names.
comment|///
name|unsigned
name|Count
decl_stmt|;
comment|/// TypeMap - If the client wants us to unique types, this keeps track of the
comment|/// current assignments and TypeCounter keeps track of the next id to assign.
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|unsigned
operator|>
name|TypeMap
expr_stmt|;
name|unsigned
name|TypeCounter
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
comment|/// setPreserveAsmNames - If the mangler should not strip off the asm name
comment|/// @verbatim identifier (\001), this should be set. @endverbatim
name|void
name|setPreserveAsmNames
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|PreserveAsmNames
operator|=
name|Val
expr_stmt|;
block|}
comment|/// Acceptable Characters - This allows the target to specify which characters
comment|/// are acceptable to the assembler without being mangled.  By default we
comment|/// allow letters, numbers, '_', '$', and '.', which is what GAS accepts.
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
comment|/// getValueName - Returns the mangled name of V, an LLVM Value,
comment|/// in the current module.
comment|///
name|std
operator|::
name|string
name|getValueName
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|V
argument_list|,
specifier|const
name|char
operator|*
name|Suffix
operator|=
literal|""
argument_list|)
expr_stmt|;
name|std
operator|::
name|string
name|getValueName
argument_list|(
specifier|const
name|Value
operator|*
name|V
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
specifier|const
name|std
operator|::
name|string
operator|&
name|x
argument_list|,
specifier|const
name|char
operator|*
name|Prefix
operator|=
literal|0
argument_list|,
specifier|const
name|char
operator|*
name|PrivatePrefix
operator|=
literal|0
argument_list|)
expr_stmt|;
name|private
label|:
comment|/// getTypeID - Return a unique ID for the specified LLVM type.
comment|///
name|unsigned
name|getTypeID
parameter_list|(
specifier|const
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
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

