begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/AbsoluteAtom.h - An absolute Atom -----------------------------===//
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
name|LLD_CORE_ABSOLUTE_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_ABSOLUTE_ATOM_H
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
comment|/// An AbsoluteAtom has no content.
comment|/// It exists to represent content at fixed addresses in memory.
name|class
name|AbsoluteAtom
range|:
name|public
name|Atom
block|{
name|public
operator|:
name|virtual
name|uint64_t
name|value
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// scope - The visibility of this atom to other atoms.  C static functions
comment|/// have scope scopeTranslationUnit.  Regular C functions have scope
comment|/// scopeGlobal.  Functions compiled with visibility=hidden have scope
comment|/// scopeLinkageUnit so they can be see by other atoms being linked but not
comment|/// by the OS loader.
name|virtual
name|Scope
name|scope
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
name|definitionAbsolute
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const AbsoluteAtom *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
operator|:
name|AbsoluteAtom
argument_list|()
operator|:
name|Atom
argument_list|(
argument|definitionAbsolute
argument_list|)
block|{}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_ABSOLUTE_ATOM_H
end_comment

end_unit

