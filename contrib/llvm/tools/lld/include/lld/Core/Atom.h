begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/Atom.h - A node in linking graph --------------------*- C++ -*-===//
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
name|LLD_CORE_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_ATOM_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|File
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningAtomPtr
expr_stmt|;
comment|///
comment|/// The linker has a Graph Theory model of linking. An object file is seen
comment|/// as a set of Atoms with References to other Atoms.  Each Atom is a node
comment|/// and each Reference is an edge. An Atom can be a DefinedAtom which has
comment|/// content or a UndefinedAtom which is a placeholder and represents an
comment|/// undefined symbol (extern declaration).
comment|///
name|class
name|Atom
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
name|OwningAtomPtr
expr_stmt|;
name|public
label|:
comment|/// Whether this atom is defined or a proxy for an undefined symbol
enum|enum
name|Definition
block|{
name|definitionRegular
block|,
comment|///< Normal C/C++ function or global variable.
name|definitionAbsolute
block|,
comment|///< Asm-only (foo = 10). Not tied to any content.
name|definitionUndefined
block|,
comment|///< Only in .o files to model reference to undef.
name|definitionSharedLibrary
comment|///< Only in shared libraries to model export.
block|}
enum|;
comment|/// The scope in which this atom is acessible to other atoms.
enum|enum
name|Scope
block|{
name|scopeTranslationUnit
block|,
comment|///< Accessible only to atoms in the same translation
comment|///  unit (e.g. a C static).
name|scopeLinkageUnit
block|,
comment|///< Accessible to atoms being linked but not visible
comment|///  to runtime loader (e.g. visibility=hidden).
name|scopeGlobal
comment|///< Accessible to all atoms and visible to runtime
comment|///  loader (e.g. visibility=default).
block|}
enum|;
comment|/// file - returns the File that produced/owns this Atom
name|virtual
specifier|const
name|File
operator|&
name|file
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// name - The name of the atom. For a function atom, it is the (mangled)
comment|/// name of the function.
name|virtual
name|StringRef
name|name
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// definition - Whether this atom is a definition or represents an undefined
comment|/// symbol.
name|Definition
name|definition
argument_list|()
specifier|const
block|{
return|return
name|_definition
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Atom
modifier|*
name|a
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|protected
label|:
comment|/// Atom is an abstract base class.  Only subclasses can access constructor.
name|explicit
name|Atom
argument_list|(
argument|Definition def
argument_list|)
block|:
name|_definition
argument_list|(
argument|def
argument_list|)
block|{}
comment|/// The memory for Atom objects is always managed by the owning File
comment|/// object.  Therefore, no one but the owning File object should call
comment|/// delete on an Atom.  In fact, some File objects may bulk allocate
comment|/// an array of Atoms, so they cannot be individually deleted by anyone.
name|virtual
operator|~
name|Atom
argument_list|()
operator|=
expr|default
expr_stmt|;
name|private
label|:
name|Definition
name|_definition
decl_stmt|;
block|}
empty_stmt|;
comment|/// Class which owns an atom pointer and runs the atom destructor when the
comment|/// owning pointer goes out of scope.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|OwningAtomPtr
block|{
name|private
operator|:
name|OwningAtomPtr
argument_list|(
specifier|const
name|OwningAtomPtr
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|OwningAtomPtr
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
name|OwningAtomPtr
argument_list|()
operator|=
expr|default
block|;
name|OwningAtomPtr
argument_list|(
name|T
operator|*
name|atom
argument_list|)
operator|:
name|atom
argument_list|(
argument|atom
argument_list|)
block|{ }
operator|~
name|OwningAtomPtr
argument_list|()
block|{
if|if
condition|(
name|atom
condition|)
name|runDestructor
argument_list|(
name|atom
argument_list|)
expr_stmt|;
block|}
name|void
name|runDestructor
argument_list|(
argument|Atom *atom
argument_list|)
block|{
name|atom
operator|->
expr|~
name|Atom
argument_list|()
block|;   }
name|OwningAtomPtr
argument_list|(
name|OwningAtomPtr
operator|&&
name|ptr
argument_list|)
operator|:
name|atom
argument_list|(
argument|ptr.atom
argument_list|)
block|{
name|ptr
operator|.
name|atom
operator|=
name|nullptr
block|;   }
name|void
name|operator
operator|=
operator|(
name|OwningAtomPtr
operator|&&
name|ptr
operator|)
block|{
if|if
condition|(
name|atom
condition|)
name|runDestructor
argument_list|(
name|atom
argument_list|)
expr_stmt|;
name|atom
operator|=
name|ptr
operator|.
name|atom
block|;
name|ptr
operator|.
name|atom
operator|=
name|nullptr
block|;   }
name|T
operator|*
specifier|const
operator|&
name|get
argument_list|()
specifier|const
block|{
return|return
name|atom
return|;
block|}
name|T
modifier|*
modifier|&
name|get
parameter_list|()
block|{
return|return
name|atom
return|;
block|}
name|T
modifier|*
name|release
parameter_list|()
block|{
name|auto
operator|*
name|v
operator|=
name|atom
expr_stmt|;
name|atom
operator|=
name|nullptr
expr_stmt|;
return|return
name|v
return|;
block|}
name|private
label|:
name|T
modifier|*
name|atom
init|=
name|nullptr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_ATOM_H
end_comment

end_unit

