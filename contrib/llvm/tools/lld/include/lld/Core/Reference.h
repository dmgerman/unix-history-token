begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/References.h - A Reference to Another Atom ----------*- C++ -*-===//
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
name|LLD_CORE_REFERENCES_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_REFERENCES_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|Atom
decl_stmt|;
comment|///
comment|/// The linker has a Graph Theory model of linking. An object file is seen
comment|/// as a set of Atoms with References to other Atoms.  Each Atom is a node
comment|/// and each Reference is an edge.
comment|///
comment|/// For example if a function contains a call site to "malloc" 40 bytes into
comment|/// the Atom, then the function Atom will have a Reference of: offsetInAtom=40,
comment|/// kind=callsite, target=malloc, addend=0.
comment|///
comment|/// Besides supporting traditional "relocations", references are also used
comment|/// forcing layout (one atom must follow another), marking data-in-code
comment|/// (jump tables or ARM constants), etc.
comment|///
comment|/// The "kind" of a reference is a tuple of<namespace, arch, value>.  This
comment|/// enable us to re-use existing relocation types definded for various
comment|/// file formats and architectures.
comment|///
comment|/// References and atoms form a directed graph. The dead-stripping pass
comment|/// traverses them starting from dead-strip root atoms to garbage collect
comment|/// unreachable ones.
comment|///
comment|/// References of any kind are considered as directed edges. In addition to
comment|/// that, references of some kind is considered as bidirected edges.
name|class
name|Reference
block|{
name|public
label|:
comment|/// Which universe defines the kindValue().
name|enum
name|class
name|KindNamespace
block|{
name|all
operator|=
literal|0
operator|,
name|testing
operator|=
literal|1
operator|,
name|mach_o
operator|=
literal|2
operator|,
block|}
empty_stmt|;
name|KindNamespace
name|kindNamespace
argument_list|()
specifier|const
block|{
return|return
operator|(
name|KindNamespace
operator|)
name|_kindNamespace
return|;
block|}
name|void
name|setKindNamespace
parameter_list|(
name|KindNamespace
name|ns
parameter_list|)
block|{
name|_kindNamespace
operator|=
operator|(
name|uint8_t
operator|)
name|ns
expr_stmt|;
block|}
comment|// Which architecture the kind value is for.
name|enum
name|class
name|KindArch
block|{
name|all
operator|,
name|AArch64
operator|,
name|ARM
operator|,
name|x86
operator|,
name|x86_64
block|}
empty_stmt|;
name|KindArch
name|kindArch
argument_list|()
specifier|const
block|{
return|return
operator|(
name|KindArch
operator|)
name|_kindArch
return|;
block|}
name|void
name|setKindArch
parameter_list|(
name|KindArch
name|a
parameter_list|)
block|{
name|_kindArch
operator|=
operator|(
name|uint8_t
operator|)
name|a
expr_stmt|;
block|}
typedef|typedef
name|uint16_t
name|KindValue
typedef|;
name|KindValue
name|kindValue
argument_list|()
specifier|const
block|{
return|return
name|_kindValue
return|;
block|}
comment|/// setKindValue() is needed because during linking, some optimizations may
comment|/// change the codegen and hence the reference kind.
name|void
name|setKindValue
parameter_list|(
name|KindValue
name|value
parameter_list|)
block|{
name|_kindValue
operator|=
name|value
expr_stmt|;
block|}
comment|/// KindValues used with KindNamespace::all and KindArch::all.
enum|enum
block|{
comment|// kindLayoutAfter is treated as a bidirected edge by the dead-stripping
comment|// pass.
name|kindLayoutAfter
init|=
literal|1
block|,
name|kindAssociate
block|,   }
enum|;
comment|// A value to be added to the value of a target
typedef|typedef
name|int64_t
name|Addend
typedef|;
comment|/// If the reference is a fixup in the Atom, then this returns the
comment|/// byte offset into the Atom's content to do the fix up.
name|virtual
name|uint64_t
name|offsetInAtom
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Returns the atom this reference refers to.
name|virtual
specifier|const
name|Atom
operator|*
name|target
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// During linking, the linker may merge graphs which coalesces some nodes
comment|/// (i.e. Atoms).  To switch the target of a reference, this method is called.
name|virtual
name|void
name|setTarget
parameter_list|(
specifier|const
name|Atom
modifier|*
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Some relocations require a symbol and a value (e.g. foo + 4).
name|virtual
name|Addend
name|addend
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// During linking, some optimzations may change addend value.
name|virtual
name|void
name|setAddend
parameter_list|(
name|Addend
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Returns target specific attributes of the reference.
name|virtual
name|uint32_t
name|tag
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|protected
label|:
comment|/// Reference is an abstract base class.  Only subclasses can use constructor.
name|Reference
argument_list|(
argument|KindNamespace ns
argument_list|,
argument|KindArch a
argument_list|,
argument|KindValue value
argument_list|)
block|:
name|_kindValue
argument_list|(
name|value
argument_list|)
operator|,
name|_kindNamespace
argument_list|(
operator|(
name|uint8_t
operator|)
name|ns
argument_list|)
operator|,
name|_kindArch
argument_list|(
argument|(uint8_t)a
argument_list|)
block|{}
comment|/// The memory for Reference objects is always managed by the owning File
comment|/// object.  Therefore, no one but the owning File object should call
comment|/// delete on an Reference.  In fact, some File objects may bulk allocate
comment|/// an array of References, so they cannot be individually deleted by anyone.
name|virtual
operator|~
name|Reference
argument_list|()
operator|=
expr|default
expr_stmt|;
name|KindValue
name|_kindValue
decl_stmt|;
name|uint8_t
name|_kindNamespace
decl_stmt|;
name|uint8_t
name|_kindArch
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_REFERENCES_H
end_comment

end_unit

