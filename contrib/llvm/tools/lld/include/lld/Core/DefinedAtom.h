begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Core/DefinedAtom.h - An Atom with content --------------------------===//
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
name|LLD_CORE_DEFINED_ATOM_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_DEFINED_ATOM_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Atom.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reference.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|class
name|File
decl_stmt|;
comment|/// \brief The fundamental unit of linking.
comment|///
comment|/// A C function or global variable is an atom.  An atom has content and
comment|/// attributes. The content of a function atom is the instructions that
comment|/// implement the function.  The content of a global variable atom is its
comment|/// initial bytes.
comment|///
comment|/// Here are some example attribute sets for common atoms. If a particular
comment|/// attribute is not listed, the default values are:  definition=regular,
comment|/// sectionChoice=basedOnContent, scope=translationUnit, merge=no,
comment|/// deadStrip=normal, interposable=no
comment|///
comment|///  C function:  void foo() {}<br>
comment|///    name=foo, type=code, perm=r_x, scope=global
comment|///
comment|///  C static function:  staic void func() {}<br>
comment|///    name=func, type=code, perm=r_x
comment|///
comment|///  C global variable:  int count = 1;<br>
comment|///    name=count, type=data, perm=rw_, scope=global
comment|///
comment|///  C tentative definition:  int bar;<br>
comment|///    name=bar, type=zerofill, perm=rw_, scope=global,
comment|///    merge=asTentative, interposable=yesAndRuntimeWeak
comment|///
comment|///  Uninitialized C static variable:  static int stuff;<br>
comment|///    name=stuff, type=zerofill, perm=rw_
comment|///
comment|///  Weak C function:  __attribute__((weak)) void foo() {}<br>
comment|///    name=foo, type=code, perm=r_x, scope=global, merge=asWeak
comment|///
comment|///  Hidden C function:  __attribute__((visibility("hidden"))) void foo() {}<br>
comment|///    name=foo, type=code, perm=r_x, scope=linkageUnit
comment|///
comment|///  No-dead-strip function:  __attribute__((used)) void foo() {}<br>
comment|///    name=foo, type=code, perm=r_x, scope=global, deadStrip=never
comment|///
comment|///  Non-inlined C++ inline method:  inline void Foo::doit() {}<br>
comment|///    name=_ZN3Foo4doitEv, type=code, perm=r_x, scope=global,
comment|///    mergeDupes=asWeak
comment|///
comment|///  Non-inlined C++ inline method whose address is taken:
comment|///     inline void Foo::doit() {}<br>
comment|///    name=_ZN3Foo4doitEv, type=code, perm=r_x, scope=global,
comment|///    mergeDupes=asAddressedWeak
comment|///
comment|///  literal c-string:  "hello"<br>
comment|///    name="" type=cstring, perm=r__, scope=linkageUnit
comment|///
comment|///  literal double:  1.234<br>
comment|///    name="" type=literal8, perm=r__, scope=linkageUnit
comment|///
comment|///  constant:  { 1,2,3 }<br>
comment|///    name="" type=constant, perm=r__, scope=linkageUnit
comment|///
comment|///  Pointer to initializer function:<br>
comment|///    name="" type=initializer, perm=rw_l,
comment|///    sectionChoice=customRequired
comment|///
comment|///  C function place in custom section:  __attribute__((section("__foo")))
comment|///                                       void foo() {}<br>
comment|///    name=foo, type=code, perm=r_x, scope=global,
comment|///    sectionChoice=customRequired, customSectionName=__foo
comment|///
name|class
name|DefinedAtom
range|:
name|public
name|Atom
block|{
name|public
operator|:
expr|enum
name|Interposable
block|{
name|interposeNo
block|,
comment|// linker can directly bind uses of this atom
name|interposeYes
block|,
comment|// linker must indirect (through GOT) uses
name|interposeYesAndRuntimeWeak
comment|// must indirect and mark symbol weak in final
comment|// linked image
block|}
block|;    enum
name|Merge
block|{
name|mergeNo
block|,
comment|// Another atom with same name is error
name|mergeAsTentative
block|,
comment|// Is ANSI C tentative definition, can be coalesced
name|mergeAsWeak
block|,
comment|// Is C++ inline definition that was not inlined,
comment|// but address was not taken, so atom can be hidden
comment|// by linker
name|mergeAsWeakAndAddressUsed
block|,
comment|// Is C++ definition inline definition whose
comment|// address was taken.
name|mergeSameNameAndSize
block|,
comment|// Another atom with different size is error
name|mergeByLargestSection
block|,
comment|// Choose an atom whose section is the largest.
name|mergeByContent
block|,
comment|// Merge with other constants with same content.
block|}
block|;    enum
name|ContentType
block|{
name|typeUnknown
block|,
comment|// for use with definitionUndefined
name|typeMachHeader
block|,
comment|// atom representing mach_header [Darwin]
name|typeCode
block|,
comment|// executable code
name|typeResolver
block|,
comment|// function which returns address of target
name|typeBranchIsland
block|,
comment|// linker created for large binaries
name|typeBranchShim
block|,
comment|// linker created to switch thumb mode
name|typeStub
block|,
comment|// linker created for calling external function
name|typeStubHelper
block|,
comment|// linker created for initial stub binding
name|typeConstant
block|,
comment|// a read-only constant
name|typeCString
block|,
comment|// a zero terminated UTF8 C string
name|typeUTF16String
block|,
comment|// a zero terminated UTF16 string
name|typeCFI
block|,
comment|// a FDE or CIE from dwarf unwind info
name|typeLSDA
block|,
comment|// extra unwinding info
name|typeLiteral4
block|,
comment|// a four-btye read-only constant
name|typeLiteral8
block|,
comment|// an eight-btye read-only constant
name|typeLiteral16
block|,
comment|// a sixteen-btye read-only constant
name|typeData
block|,
comment|// read-write data
name|typeDataFast
block|,
comment|// allow data to be quickly accessed
name|typeZeroFill
block|,
comment|// zero-fill data
name|typeZeroFillFast
block|,
comment|// allow zero-fill data to be quicky accessed
name|typeConstData
block|,
comment|// read-only data after dynamic linker is done
name|typeObjC1Class
block|,
comment|// ObjC1 class [Darwin]
name|typeLazyPointer
block|,
comment|// pointer through which a stub jumps
name|typeLazyDylibPointer
block|,
comment|// pointer through which a stub jumps [Darwin]
name|typeNonLazyPointer
block|,
comment|// pointer to external symbol
name|typeCFString
block|,
comment|// NS/CFString object [Darwin]
name|typeGOT
block|,
comment|// pointer to external symbol
name|typeInitializerPtr
block|,
comment|// pointer to initializer function
name|typeTerminatorPtr
block|,
comment|// pointer to terminator function
name|typeCStringPtr
block|,
comment|// pointer to UTF8 C string [Darwin]
name|typeObjCClassPtr
block|,
comment|// pointer to ObjC class [Darwin]
name|typeObjC2CategoryList
block|,
comment|// pointers to ObjC category [Darwin]
name|typeObjCImageInfo
block|,
comment|// pointer to ObjC class [Darwin]
name|typeObjCMethodList
block|,
comment|// pointer to ObjC method list [Darwin]
name|typeDTraceDOF
block|,
comment|// runtime data for Dtrace [Darwin]
name|typeInterposingTuples
block|,
comment|// tuples of interposing info for dyld [Darwin]
name|typeTempLTO
block|,
comment|// temporary atom for bitcode reader
name|typeCompactUnwindInfo
block|,
comment|// runtime data for unwinder [Darwin]
name|typeProcessedUnwindInfo
block|,
comment|// compressed compact unwind info [Darwin]
name|typeThunkTLV
block|,
comment|// thunk used to access a TLV [Darwin]
name|typeTLVInitialData
block|,
comment|// initial data for a TLV [Darwin]
name|typeTLVInitialZeroFill
block|,
comment|// TLV initial zero fill data [Darwin]
name|typeTLVInitializerPtr
block|,
comment|// pointer to thread local initializer [Darwin]
name|typeDSOHandle
block|,
comment|// atom representing DSO handle [Darwin]
name|typeSectCreate
block|,
comment|// Created via the -sectcreate option [Darwin]
block|}
block|;
comment|// Permission bits for atoms and segments. The order of these values are
comment|// important, because the layout pass may sort atoms by permission if other
comment|// attributes are the same.
block|enum
name|ContentPermissions
block|{
name|perm___
operator|=
literal|0
block|,
comment|// mapped as unaccessible
name|permR__
operator|=
literal|8
block|,
comment|// mapped read-only
name|permRW_
operator|=
literal|8
operator|+
literal|2
block|,
comment|// mapped readable and writable
name|permRW_L
operator|=
literal|8
operator|+
literal|2
operator|+
literal|1
block|,
comment|// initially mapped r/w, then made read-only
comment|// loader writable
name|permR_X
operator|=
literal|8
operator|+
literal|4
block|,
comment|// mapped readable and executable
name|permRWX
operator|=
literal|8
operator|+
literal|2
operator|+
literal|4
block|,
comment|// mapped readable and writable and executable
name|permUnknown
operator|=
literal|16
comment|// unknown or invalid permissions
block|}
block|;    enum
name|SectionChoice
block|{
name|sectionBasedOnContent
block|,
comment|// linker infers final section based on content
name|sectionCustomPreferred
block|,
comment|// linker may place in specific section
name|sectionCustomRequired
comment|// linker must place in specific section
block|}
block|;    enum
name|DeadStripKind
block|{
name|deadStripNormal
block|,
comment|// linker may dead strip this atom
name|deadStripNever
block|,
comment|// linker must never dead strip this atom
name|deadStripAlways
comment|// linker must remove this atom if unused
block|}
block|;    enum
name|DynamicExport
block|{
comment|/// \brief The linker may or may not export this atom dynamically depending
comment|///   on the output type and other context of the link.
name|dynamicExportNormal
block|,
comment|/// \brief The linker will always export this atom dynamically.
name|dynamicExportAlways
block|,   }
block|;
comment|// Attributes describe a code model used by the atom.
block|enum
name|CodeModel
block|{
name|codeNA
block|,
comment|// no specific code model
comment|// MIPS code models
name|codeMipsPIC
block|,
comment|// PIC function in a PIC / non-PIC mixed file
name|codeMipsMicro
block|,
comment|// microMIPS instruction encoding
name|codeMipsMicroPIC
block|,
comment|// microMIPS instruction encoding + PIC
name|codeMips16
block|,
comment|// MIPS-16 instruction encoding
comment|// ARM code models
name|codeARMThumb
block|,
comment|// ARM Thumb instruction set
name|codeARM_a
block|,
comment|// $a-like mapping symbol (for ARM code)
name|codeARM_d
block|,
comment|// $d-like mapping symbol (for data)
name|codeARM_t
block|,
comment|// $t-like mapping symbol (for Thumb code)
block|}
block|;    struct
name|Alignment
block|{
name|Alignment
argument_list|(
argument|int v
argument_list|,
argument|int m =
literal|0
argument_list|)
operator|:
name|value
argument_list|(
name|v
argument_list|)
block|,
name|modulus
argument_list|(
argument|m
argument_list|)
block|{}
name|uint16_t
name|value
block|;
name|uint16_t
name|modulus
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Alignment
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|(
name|value
operator|==
name|rhs
operator|.
name|value
operator|)
operator|&&
operator|(
name|modulus
operator|==
name|rhs
operator|.
name|modulus
operator|)
return|;
block|}
expr|}
block|;
comment|/// \brief returns a value for the order of this Atom within its file.
comment|///
comment|/// This is used by the linker to order the layout of Atoms so that the
comment|/// resulting image is stable and reproducible.
name|virtual
name|uint64_t
name|ordinal
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief the number of bytes of space this atom's content will occupy in the
comment|/// final linked image.
comment|///
comment|/// For a function atom, it is the number of bytes of code in the function.
name|virtual
name|uint64_t
name|size
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief The size of the section from which the atom is instantiated.
comment|///
comment|/// Merge::mergeByLargestSection is defined in terms of section size
comment|/// and not in terms of atom size, so we need this function separate
comment|/// from size().
name|virtual
name|uint64_t
name|sectionSize
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief The visibility of this atom to other atoms.
comment|///
comment|/// C static functions have scope scopeTranslationUnit.  Regular C functions
comment|/// have scope scopeGlobal.  Functions compiled with visibility=hidden have
comment|/// scope scopeLinkageUnit so they can be see by other atoms being linked but
comment|/// not by the OS loader.
name|virtual
name|Scope
name|scope
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Whether the linker should use direct or indirect access to this
comment|/// atom.
name|virtual
name|Interposable
name|interposable
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief how the linker should handle if multiple atoms have the same name.
name|virtual
name|Merge
name|merge
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief The type of this atom, such as code or data.
name|virtual
name|ContentType
name|contentType
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief The alignment constraints on how this atom must be laid out in the
comment|/// final linked image (e.g. 16-byte aligned).
name|virtual
name|Alignment
name|alignment
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Whether this atom must be in a specially named section in the final
comment|/// linked image, or if the linker can infer the section based on the
comment|/// contentType().
name|virtual
name|SectionChoice
name|sectionChoice
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief If sectionChoice() != sectionBasedOnContent, then this return the
comment|/// name of the section the atom should be placed into.
name|virtual
name|StringRef
name|customSectionName
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief constraints on whether the linker may dead strip away this atom.
name|virtual
name|DeadStripKind
name|deadStrip
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Under which conditions should this atom be dynamically exported.
name|virtual
name|DynamicExport
name|dynamicExport
argument_list|()
specifier|const
block|{
return|return
name|dynamicExportNormal
return|;
block|}
comment|/// \brief Code model used by the atom.
name|virtual
name|CodeModel
name|codeModel
argument_list|()
specifier|const
block|{
return|return
name|codeNA
return|;
block|}
comment|/// \brief Returns the OS memory protections required for this atom's content
comment|/// at runtime.
comment|///
comment|/// A function atom is R_X, a global variable is RW_, and a read-only constant
comment|/// is R__.
name|virtual
name|ContentPermissions
name|permissions
argument_list|()
specifier|const
block|;
comment|/// \brief returns a reference to the raw (unrelocated) bytes of this Atom's
comment|/// content.
name|virtual
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|rawContent
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// This class abstracts iterating over the sequence of References
comment|/// in an Atom.  Concrete instances of DefinedAtom must implement
comment|/// the derefIterator() and incrementIterator() methods.
name|class
name|reference_iterator
block|{
name|public
operator|:
name|reference_iterator
argument_list|(
specifier|const
name|DefinedAtom
operator|&
name|a
argument_list|,
specifier|const
name|void
operator|*
name|it
argument_list|)
operator|:
name|_atom
argument_list|(
name|a
argument_list|)
block|,
name|_it
argument_list|(
argument|it
argument_list|)
block|{ }
specifier|const
name|Reference
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|_atom
operator|.
name|derefIterator
argument_list|(
name|_it
argument_list|)
return|;
block|}
specifier|const
name|Reference
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|_atom
operator|.
name|derefIterator
argument_list|(
name|_it
argument_list|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|reference_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|_it
operator|==
name|other
operator|.
name|_it
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|reference_iterator
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|reference_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|_atom
operator|.
name|incrementIterator
argument_list|(
name|_it
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|private
operator|:
specifier|const
name|DefinedAtom
operator|&
name|_atom
block|;
specifier|const
name|void
operator|*
name|_it
block|;   }
block|;
comment|/// \brief Returns an iterator to the beginning of this Atom's References.
name|virtual
name|reference_iterator
name|begin
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns an iterator to the end of this Atom's References.
name|virtual
name|reference_iterator
name|end
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// Adds a reference to this atom.
name|virtual
name|void
name|addReference
argument_list|(
argument|Reference::KindNamespace ns
argument_list|,
argument|Reference::KindArch arch
argument_list|,
argument|Reference::KindValue kindValue
argument_list|,
argument|uint64_t off
argument_list|,
argument|const Atom *target
argument_list|,
argument|Reference::Addend a
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Subclass does not permit adding references"
argument_list|)
block|;   }
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
name|definitionRegular
return|;
block|}
comment|/// Utility for deriving permissions from content type
specifier|static
name|ContentPermissions
name|permissions
argument_list|(
argument|ContentType type
argument_list|)
block|;
comment|/// Utility function to check if the atom occupies file space
name|bool
name|occupiesDiskSpace
argument_list|()
specifier|const
block|{
name|ContentType
name|atomContentType
operator|=
name|contentType
argument_list|()
block|;
return|return
operator|!
operator|(
name|atomContentType
operator|==
name|DefinedAtom
operator|::
name|typeZeroFill
operator|||
name|atomContentType
operator|==
name|DefinedAtom
operator|::
name|typeZeroFillFast
operator|||
name|atomContentType
operator|==
name|DefinedAtom
operator|::
name|typeTLVInitialZeroFill
operator|)
return|;
block|}
comment|/// Utility function to check if relocations in this atom to other defined
comment|/// atoms can be implicitly generated, and so we don't need to explicitly
comment|/// emit those relocations.
name|bool
name|relocsToDefinedCanBeImplicit
argument_list|()
specifier|const
block|{
name|ContentType
name|atomContentType
operator|=
name|contentType
argument_list|()
block|;
return|return
name|atomContentType
operator|==
name|typeCFI
return|;
block|}
name|protected
operator|:
comment|// DefinedAtom is an abstract base class. Only subclasses can access
comment|// constructor.
name|DefinedAtom
argument_list|()
operator|:
name|Atom
argument_list|(
argument|definitionRegular
argument_list|)
block|{ }
operator|~
name|DefinedAtom
argument_list|()
name|override
operator|=
expr|default
block|;
comment|/// \brief Returns a pointer to the Reference object that the abstract
comment|/// iterator "points" to.
name|virtual
specifier|const
name|Reference
operator|*
name|derefIterator
argument_list|(
argument|const void *iter
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Adjusts the abstract iterator to "point" to the next Reference
comment|/// object for this Atom.
name|virtual
name|void
name|incrementIterator
argument_list|(
argument|const void *&iter
argument_list|)
specifier|const
operator|=
literal|0
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

