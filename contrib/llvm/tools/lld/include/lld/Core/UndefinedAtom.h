begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/UndefinedAtom.h - An Undefined Atom ---------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_CORE_UNDEFINED_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_UNDEFINED_ATOM_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Atom.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
comment|/// An UndefinedAtom has no content.
comment|/// It exists as a placeholder for a future atom.
name|class
name|UndefinedAtom
range|:
name|public
name|Atom
block|{
name|public
operator|:
comment|/// Whether this undefined symbol needs to be resolved,
comment|/// or whether it can just evaluate to nullptr.
comment|/// This concept is often called "weak", but that term
comment|/// is overloaded to mean other things too.
expr|enum
name|CanBeNull
block|{
comment|/// Normal symbols must be resolved at build time
name|canBeNullNever
block|,
comment|/// This symbol can be missing at runtime and will evalute to nullptr.
comment|/// That is, the static linker still must find a definition (usually
comment|/// is some shared library), but at runtime, the dynamic loader
comment|/// will allow the symbol to be missing and resolved to nullptr.
comment|///
comment|/// On Darwin this is generated using a function prototype with
comment|/// __attribute__((weak_import)).
comment|/// On linux this is generated using a function prototype with
comment|///  __attribute__((weak)).
comment|/// On Windows this feature is not supported.
name|canBeNullAtRuntime
block|,
comment|/// This symbol can be missing at build time.
comment|/// That is, the static linker will not error if a definition for
comment|/// this symbol is not found at build time. Instead, the linker
comment|/// will build an executable that lets the dynamic loader find the
comment|/// symbol at runtime.
comment|/// This feature is not supported on Darwin nor Windows.
comment|/// On linux this is generated using a function prototype with
comment|///  __attribute__((weak)).
name|canBeNullAtBuildtime
block|}
block|;
name|virtual
name|CanBeNull
name|canBeNull
argument_list|()
specifier|const
operator|=
literal|0
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Atom *a
argument_list|)
block|{
return|return
name|a
operator|->
name|definition
argument_list|()
operator|==
name|definitionUndefined
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UndefinedAtom *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|UndefinedAtom
argument_list|()
operator|:
name|Atom
argument_list|(
argument|definitionUndefined
argument_list|)
block|{}
operator|~
name|UndefinedAtom
argument_list|()
name|override
operator|=
expr|default
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_UNDEFINED_ATOM_H
end_comment

end_unit

