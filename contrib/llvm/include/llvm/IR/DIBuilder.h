begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DIBuilder.h - Debug Information Builder ------------------*- C++ -*-===//
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
comment|// This file defines a DIBuilder that is useful for creating debugging
end_comment

begin_comment
comment|// information entries in LLVM IR form.
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
name|LLVM_IR_DIBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DIBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfoMetadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/TrackingMDRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|DIBuilder
block|{
name|Module
modifier|&
name|M
decl_stmt|;
name|LLVMContext
modifier|&
name|VMContext
decl_stmt|;
name|DICompileUnit
modifier|*
name|CUNode
decl_stmt|;
comment|///< The one compile unit created by this DIBuiler.
name|Function
modifier|*
name|DeclareFn
decl_stmt|;
comment|///< llvm.dbg.declare
name|Function
modifier|*
name|ValueFn
decl_stmt|;
comment|///< llvm.dbg.value
name|SmallVector
operator|<
name|Metadata
operator|*
operator|,
literal|4
operator|>
name|AllEnumTypes
expr_stmt|;
comment|/// Track the RetainTypes, since they can be updated later on.
name|SmallVector
operator|<
name|TrackingMDNodeRef
operator|,
literal|4
operator|>
name|AllRetainTypes
expr_stmt|;
name|SmallVector
operator|<
name|Metadata
operator|*
operator|,
literal|4
operator|>
name|AllSubprograms
expr_stmt|;
name|SmallVector
operator|<
name|Metadata
operator|*
operator|,
literal|4
operator|>
name|AllGVs
expr_stmt|;
name|SmallVector
operator|<
name|TrackingMDNodeRef
operator|,
literal|4
operator|>
name|AllImportedModules
expr_stmt|;
comment|/// Map Macro parent (which can be DIMacroFile or nullptr) to a list of
comment|/// Metadata all of type DIMacroNode.
comment|/// DIMacroNode's with nullptr parent are DICompileUnit direct children.
name|MapVector
operator|<
name|MDNode
operator|*
operator|,
name|SetVector
operator|<
name|Metadata
operator|*
operator|>>
name|AllMacrosPerParent
expr_stmt|;
comment|/// Track nodes that may be unresolved.
name|SmallVector
operator|<
name|TrackingMDNodeRef
operator|,
literal|4
operator|>
name|UnresolvedNodes
expr_stmt|;
name|bool
name|AllowUnresolvedNodes
decl_stmt|;
comment|/// Each subprogram's preserved local variables.
comment|///
comment|/// Do not use a std::vector.  Some versions of libc++ apparently copy
comment|/// instead of move on grow operations, and TrackingMDRef is expensive to
comment|/// copy.
name|DenseMap
operator|<
name|MDNode
operator|*
operator|,
name|SmallVector
operator|<
name|TrackingMDNodeRef
operator|,
literal|1
operator|>>
name|PreservedVariables
expr_stmt|;
comment|/// Create a temporary.
comment|///
comment|/// Create an \a temporary node and track it in \a UnresolvedNodes.
name|void
name|trackIfUnresolved
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Construct a builder for a module.
comment|///
comment|/// If \c AllowUnresolved, collect unresolved nodes attached to the module
comment|/// in order to resolve cycles during \a finalize().
name|explicit
name|DIBuilder
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|bool
name|AllowUnresolved
init|=
name|true
parameter_list|)
function_decl|;
name|DIBuilder
argument_list|(
specifier|const
name|DIBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|DIBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|DIBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// Construct any deferred debug info descriptors.
name|void
name|finalize
parameter_list|()
function_decl|;
comment|/// A CompileUnit provides an anchor for all debugging
comment|/// information generated during this instance of compilation.
comment|/// \param Lang          Source programming language, eg. dwarf::DW_LANG_C99
comment|/// \param File          File info.
comment|/// \param Producer      Identify the producer of debugging information
comment|///                      and code.  Usually this is a compiler
comment|///                      version string.
comment|/// \param isOptimized   A boolean flag which indicates whether optimization
comment|///                      is enabled or not.
comment|/// \param Flags         This string lists command line options. This
comment|///                      string is directly embedded in debug info
comment|///                      output which may be used by a tool
comment|///                      analyzing generated debugging information.
comment|/// \param RV            This indicates runtime version for languages like
comment|///                      Objective-C.
comment|/// \param SplitName     The name of the file that we'll split debug info
comment|///                      out into.
comment|/// \param Kind          The kind of debug information to generate.
comment|/// \param DWOId         The DWOId if this is a split skeleton compile unit.
comment|/// \param SplitDebugInlining    Whether to emit inline debug info.
comment|/// \param DebugInfoForProfiling Whether to emit extra debug info for
comment|///                              profile collection.
name|DICompileUnit
modifier|*
name|createCompileUnit
argument_list|(
name|unsigned
name|Lang
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|StringRef
name|Producer
argument_list|,
name|bool
name|isOptimized
argument_list|,
name|StringRef
name|Flags
argument_list|,
name|unsigned
name|RV
argument_list|,
name|StringRef
name|SplitName
operator|=
name|StringRef
argument_list|()
argument_list|,
name|DICompileUnit
operator|::
name|DebugEmissionKind
name|Kind
operator|=
name|DICompileUnit
operator|::
name|DebugEmissionKind
operator|::
name|FullDebug
argument_list|,
name|uint64_t
name|DWOId
operator|=
literal|0
argument_list|,
name|bool
name|SplitDebugInlining
operator|=
name|true
argument_list|,
name|bool
name|DebugInfoForProfiling
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// Create a file descriptor to hold debugging information for a file.
comment|/// \param Filename  File name.
comment|/// \param Directory Directory.
comment|/// \param CSKind    Checksum kind (e.g. CSK_None, CSK_MD5, CSK_SHA1, etc.).
comment|/// \param Checksum  Checksum data.
name|DIFile
modifier|*
name|createFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|StringRef
name|Directory
argument_list|,
name|DIFile
operator|::
name|ChecksumKind
name|CSKind
operator|=
name|DIFile
operator|::
name|CSK_None
argument_list|,
name|StringRef
name|Checksum
operator|=
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a macro.
comment|/// \param Parent     Macro parent (could be nullptr).
comment|/// \param Line       Source line number where the macro is defined.
comment|/// \param MacroType  DW_MACINFO_define or DW_MACINFO_undef.
comment|/// \param Name       Macro name.
comment|/// \param Value      Macro value.
name|DIMacro
modifier|*
name|createMacro
parameter_list|(
name|DIMacroFile
modifier|*
name|Parent
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|MacroType
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|Value
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|/// Create debugging information temporary entry for a macro file.
comment|/// List of macro node direct children will be calculated by DIBuilder,
comment|/// using the \p Parent relationship.
comment|/// \param Parent     Macro file parent (could be nullptr).
comment|/// \param Line       Source line number where the macro file is included.
comment|/// \param File       File descriptor containing the name of the macro file.
name|DIMacroFile
modifier|*
name|createTempMacroFile
parameter_list|(
name|DIMacroFile
modifier|*
name|Parent
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|)
function_decl|;
comment|/// Create a single enumerator value.
name|DIEnumerator
modifier|*
name|createEnumerator
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|int64_t
name|Val
parameter_list|)
function_decl|;
comment|/// Create a DWARF unspecified type.
name|DIBasicType
modifier|*
name|createUnspecifiedType
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/// Create C++11 nullptr type.
name|DIBasicType
modifier|*
name|createNullPtrType
parameter_list|()
function_decl|;
comment|/// Create debugging information entry for a basic
comment|/// type.
comment|/// \param Name        Type name.
comment|/// \param SizeInBits  Size of the type.
comment|/// \param Encoding    DWARF encoding code, e.g. dwarf::DW_ATE_float.
name|DIBasicType
modifier|*
name|createBasicType
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|uint64_t
name|SizeInBits
parameter_list|,
name|unsigned
name|Encoding
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for a qualified
comment|/// type, e.g. 'const int'.
comment|/// \param Tag         Tag identifing type, e.g. dwarf::TAG_volatile_type
comment|/// \param FromTy      Base Type.
name|DIDerivedType
modifier|*
name|createQualifiedType
parameter_list|(
name|unsigned
name|Tag
parameter_list|,
name|DIType
modifier|*
name|FromTy
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for a pointer.
comment|/// \param PointeeTy         Type pointed by this pointer.
comment|/// \param SizeInBits        Size.
comment|/// \param AlignInBits       Alignment. (optional)
comment|/// \param DWARFAddressSpace DWARF address space. (optional)
comment|/// \param Name              Pointer type name. (optional)
name|DIDerivedType
modifier|*
name|createPointerType
argument_list|(
name|DIType
operator|*
name|PointeeTy
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
name|DWARFAddressSpace
operator|=
name|None
argument_list|,
name|StringRef
name|Name
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a pointer to member.
comment|/// \param PointeeTy Type pointed to by this pointer.
comment|/// \param SizeInBits  Size.
comment|/// \param AlignInBits Alignment. (optional)
comment|/// \param Class Type for which this pointer points to members of.
name|DIDerivedType
modifier|*
name|createMemberPointerType
argument_list|(
name|DIType
operator|*
name|PointeeTy
argument_list|,
name|DIType
operator|*
name|Class
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a c++
comment|/// style reference or rvalue reference type.
name|DIDerivedType
modifier|*
name|createReferenceType
argument_list|(
name|unsigned
name|Tag
argument_list|,
name|DIType
operator|*
name|RTy
argument_list|,
name|uint64_t
name|SizeInBits
operator|=
literal|0
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|,
name|Optional
operator|<
name|unsigned
operator|>
name|DWARFAddressSpace
operator|=
name|None
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a typedef.
comment|/// \param Ty          Original type.
comment|/// \param Name        Typedef name.
comment|/// \param File        File where this type is defined.
comment|/// \param LineNo      Line number.
comment|/// \param Context     The surrounding context for the typedef.
name|DIDerivedType
modifier|*
name|createTypedef
parameter_list|(
name|DIType
modifier|*
name|Ty
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|LineNo
parameter_list|,
name|DIScope
modifier|*
name|Context
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for a 'friend'.
name|DIDerivedType
modifier|*
name|createFriend
parameter_list|(
name|DIType
modifier|*
name|Ty
parameter_list|,
name|DIType
modifier|*
name|FriendTy
parameter_list|)
function_decl|;
comment|/// Create debugging information entry to establish
comment|/// inheritance relationship between two types.
comment|/// \param Ty           Original type.
comment|/// \param BaseTy       Base type. Ty is inherits from base.
comment|/// \param BaseOffset   Base offset.
comment|/// \param Flags        Flags to describe inheritance attribute,
comment|///                     e.g. private
name|DIDerivedType
modifier|*
name|createInheritance
argument_list|(
name|DIType
operator|*
name|Ty
argument_list|,
name|DIType
operator|*
name|BaseTy
argument_list|,
name|uint64_t
name|BaseOffset
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a member.
comment|/// \param Scope        Member scope.
comment|/// \param Name         Member name.
comment|/// \param File         File where this member is defined.
comment|/// \param LineNo       Line number.
comment|/// \param SizeInBits   Member size.
comment|/// \param AlignInBits  Member alignment.
comment|/// \param OffsetInBits Member offset.
comment|/// \param Flags        Flags to encode member attribute, e.g. private
comment|/// \param Ty           Parent type.
name|DIDerivedType
modifier|*
name|createMemberType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
argument_list|,
name|uint64_t
name|OffsetInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a bit field member.
comment|/// \param Scope               Member scope.
comment|/// \param Name                Member name.
comment|/// \param File                File where this member is defined.
comment|/// \param LineNo              Line number.
comment|/// \param SizeInBits          Member size.
comment|/// \param OffsetInBits        Member offset.
comment|/// \param StorageOffsetInBits Member storage offset.
comment|/// \param Flags               Flags to encode member attribute.
comment|/// \param Ty                  Parent type.
name|DIDerivedType
modifier|*
name|createBitFieldMemberType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint64_t
name|OffsetInBits
argument_list|,
name|uint64_t
name|StorageOffsetInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a
comment|/// C++ static data member.
comment|/// \param Scope      Member scope.
comment|/// \param Name       Member name.
comment|/// \param File       File where this member is declared.
comment|/// \param LineNo     Line number.
comment|/// \param Ty         Type of the static member.
comment|/// \param Flags      Flags to encode member attribute, e.g. private.
comment|/// \param Val        Const initializer of the member.
comment|/// \param AlignInBits  Member alignment.
name|DIDerivedType
modifier|*
name|createStaticMemberType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|Constant
operator|*
name|Val
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for Objective-C
comment|/// instance variable.
comment|/// \param Name         Member name.
comment|/// \param File         File where this member is defined.
comment|/// \param LineNo       Line number.
comment|/// \param SizeInBits   Member size.
comment|/// \param AlignInBits  Member alignment.
comment|/// \param OffsetInBits Member offset.
comment|/// \param Flags        Flags to encode member attribute, e.g. private
comment|/// \param Ty           Parent type.
comment|/// \param PropertyNode Property associated with this ivar.
name|DIDerivedType
modifier|*
name|createObjCIVar
argument_list|(
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
argument_list|,
name|uint64_t
name|OffsetInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|,
name|MDNode
operator|*
name|PropertyNode
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for Objective-C
comment|/// property.
comment|/// \param Name         Property name.
comment|/// \param File         File where this property is defined.
comment|/// \param LineNumber   Line number.
comment|/// \param GetterName   Name of the Objective C property getter selector.
comment|/// \param SetterName   Name of the Objective C property setter selector.
comment|/// \param PropertyAttributes Objective C property attributes.
comment|/// \param Ty           Type.
name|DIObjCProperty
modifier|*
name|createObjCProperty
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|LineNumber
parameter_list|,
name|StringRef
name|GetterName
parameter_list|,
name|StringRef
name|SetterName
parameter_list|,
name|unsigned
name|PropertyAttributes
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for a class.
comment|/// \param Scope        Scope in which this class is defined.
comment|/// \param Name         class name.
comment|/// \param File         File where this member is defined.
comment|/// \param LineNumber   Line number.
comment|/// \param SizeInBits   Member size.
comment|/// \param AlignInBits  Member alignment.
comment|/// \param OffsetInBits Member offset.
comment|/// \param Flags        Flags to encode member attribute, e.g. private
comment|/// \param Elements     class members.
comment|/// \param VTableHolder Debug info of the base class that contains vtable
comment|///                     for this type. This is used in
comment|///                     DW_AT_containing_type. See DWARF documentation
comment|///                     for more info.
comment|/// \param TemplateParms Template type parameters.
comment|/// \param UniqueIdentifier A unique identifier for the class.
name|DICompositeType
modifier|*
name|createClassType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNumber
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
argument_list|,
name|uint64_t
name|OffsetInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DIType
operator|*
name|DerivedFrom
argument_list|,
name|DINodeArray
name|Elements
argument_list|,
name|DIType
operator|*
name|VTableHolder
operator|=
name|nullptr
argument_list|,
name|MDNode
operator|*
name|TemplateParms
operator|=
name|nullptr
argument_list|,
name|StringRef
name|UniqueIdentifier
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for a struct.
comment|/// \param Scope        Scope in which this struct is defined.
comment|/// \param Name         Struct name.
comment|/// \param File         File where this member is defined.
comment|/// \param LineNumber   Line number.
comment|/// \param SizeInBits   Member size.
comment|/// \param AlignInBits  Member alignment.
comment|/// \param Flags        Flags to encode member attribute, e.g. private
comment|/// \param Elements     Struct elements.
comment|/// \param RunTimeLang  Optional parameter, Objective-C runtime version.
comment|/// \param UniqueIdentifier A unique identifier for the struct.
name|DICompositeType
modifier|*
name|createStructType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNumber
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DIType
operator|*
name|DerivedFrom
argument_list|,
name|DINodeArray
name|Elements
argument_list|,
name|unsigned
name|RunTimeLang
operator|=
literal|0
argument_list|,
name|DIType
operator|*
name|VTableHolder
operator|=
name|nullptr
argument_list|,
name|StringRef
name|UniqueIdentifier
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// Create debugging information entry for an union.
comment|/// \param Scope        Scope in which this union is defined.
comment|/// \param Name         Union name.
comment|/// \param File         File where this member is defined.
comment|/// \param LineNumber   Line number.
comment|/// \param SizeInBits   Member size.
comment|/// \param AlignInBits  Member alignment.
comment|/// \param Flags        Flags to encode member attribute, e.g. private
comment|/// \param Elements     Union elements.
comment|/// \param RunTimeLang  Optional parameter, Objective-C runtime version.
comment|/// \param UniqueIdentifier A unique identifier for the union.
name|DICompositeType
modifier|*
name|createUnionType
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNumber
argument_list|,
name|uint64_t
name|SizeInBits
argument_list|,
name|uint32_t
name|AlignInBits
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
argument_list|,
name|DINodeArray
name|Elements
argument_list|,
name|unsigned
name|RunTimeLang
operator|=
literal|0
argument_list|,
name|StringRef
name|UniqueIdentifier
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// Create debugging information for template
comment|/// type parameter.
comment|/// \param Scope        Scope in which this type is defined.
comment|/// \param Name         Type parameter name.
comment|/// \param Ty           Parameter type.
name|DITemplateTypeParameter
modifier|*
name|createTemplateTypeParameter
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// Create debugging information for template
comment|/// value parameter.
comment|/// \param Scope        Scope in which this type is defined.
comment|/// \param Name         Value parameter name.
comment|/// \param Ty           Parameter type.
comment|/// \param Val          Constant parameter value.
name|DITemplateValueParameter
modifier|*
name|createTemplateValueParameter
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|Constant
modifier|*
name|Val
parameter_list|)
function_decl|;
comment|/// Create debugging information for a template template parameter.
comment|/// \param Scope        Scope in which this type is defined.
comment|/// \param Name         Value parameter name.
comment|/// \param Ty           Parameter type.
comment|/// \param Val          The fully qualified name of the template.
name|DITemplateValueParameter
modifier|*
name|createTemplateTemplateParameter
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|StringRef
name|Val
parameter_list|)
function_decl|;
comment|/// Create debugging information for a template parameter pack.
comment|/// \param Scope        Scope in which this type is defined.
comment|/// \param Name         Value parameter name.
comment|/// \param Ty           Parameter type.
comment|/// \param Val          An array of types in the pack.
name|DITemplateValueParameter
modifier|*
name|createTemplateParameterPack
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|DINodeArray
name|Val
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for an array.
comment|/// \param Size         Array size.
comment|/// \param AlignInBits  Alignment.
comment|/// \param Ty           Element type.
comment|/// \param Subscripts   Subscripts.
name|DICompositeType
modifier|*
name|createArrayType
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|uint32_t
name|AlignInBits
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|DINodeArray
name|Subscripts
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for a vector type.
comment|/// \param Size         Array size.
comment|/// \param AlignInBits  Alignment.
comment|/// \param Ty           Element type.
comment|/// \param Subscripts   Subscripts.
name|DICompositeType
modifier|*
name|createVectorType
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|uint32_t
name|AlignInBits
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|DINodeArray
name|Subscripts
parameter_list|)
function_decl|;
comment|/// Create debugging information entry for an
comment|/// enumeration.
comment|/// \param Scope          Scope in which this enumeration is defined.
comment|/// \param Name           Union name.
comment|/// \param File           File where this member is defined.
comment|/// \param LineNumber     Line number.
comment|/// \param SizeInBits     Member size.
comment|/// \param AlignInBits    Member alignment.
comment|/// \param Elements       Enumeration elements.
comment|/// \param UnderlyingType Underlying type of a C++11/ObjC fixed enum.
comment|/// \param UniqueIdentifier A unique identifier for the enum.
name|DICompositeType
modifier|*
name|createEnumerationType
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|LineNumber
parameter_list|,
name|uint64_t
name|SizeInBits
parameter_list|,
name|uint32_t
name|AlignInBits
parameter_list|,
name|DINodeArray
name|Elements
parameter_list|,
name|DIType
modifier|*
name|UnderlyingType
parameter_list|,
name|StringRef
name|UniqueIdentifier
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// Create subroutine type.
comment|/// \param ParameterTypes  An array of subroutine parameter types. This
comment|///                        includes return type at 0th index.
comment|/// \param Flags           E.g.: LValueReference.
comment|///                        These flags are used to emit dwarf attributes.
comment|/// \param CC              Calling convention, e.g. dwarf::DW_CC_normal
name|DISubroutineType
modifier|*
name|createSubroutineType
argument_list|(
name|DITypeRefArray
name|ParameterTypes
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|,
name|unsigned
name|CC
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Create a new DIType* with "artificial" flag set.
name|DIType
modifier|*
name|createArtificialType
parameter_list|(
name|DIType
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// Create a new DIType* with the "object pointer"
comment|/// flag set.
name|DIType
modifier|*
name|createObjectPointerType
parameter_list|(
name|DIType
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// Create a permanent forward-declared type.
name|DICompositeType
modifier|*
name|createForwardDecl
parameter_list|(
name|unsigned
name|Tag
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|DIFile
modifier|*
name|F
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|RuntimeLang
init|=
literal|0
parameter_list|,
name|uint64_t
name|SizeInBits
init|=
literal|0
parameter_list|,
name|uint32_t
name|AlignInBits
init|=
literal|0
parameter_list|,
name|StringRef
name|UniqueIdentifier
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// Create a temporary forward-declared type.
name|DICompositeType
modifier|*
name|createReplaceableCompositeType
argument_list|(
name|unsigned
name|Tag
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIScope
operator|*
name|Scope
argument_list|,
name|DIFile
operator|*
name|F
argument_list|,
name|unsigned
name|Line
argument_list|,
name|unsigned
name|RuntimeLang
operator|=
literal|0
argument_list|,
name|uint64_t
name|SizeInBits
operator|=
literal|0
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagFwdDecl
argument_list|,
name|StringRef
name|UniqueIdentifier
operator|=
literal|""
argument_list|)
decl_stmt|;
comment|/// Retain DIScope* in a module even if it is not referenced
comment|/// through debug info anchors.
name|void
name|retainType
parameter_list|(
name|DIScope
modifier|*
name|T
parameter_list|)
function_decl|;
comment|/// Create unspecified parameter type
comment|/// for a subroutine type.
name|DIBasicType
modifier|*
name|createUnspecifiedParameter
parameter_list|()
function_decl|;
comment|/// Get a DINodeArray, create one if required.
name|DINodeArray
name|getOrCreateArray
argument_list|(
name|ArrayRef
operator|<
name|Metadata
operator|*
operator|>
name|Elements
argument_list|)
decl_stmt|;
comment|/// Get a DIMacroNodeArray, create one if required.
name|DIMacroNodeArray
name|getOrCreateMacroArray
argument_list|(
name|ArrayRef
operator|<
name|Metadata
operator|*
operator|>
name|Elements
argument_list|)
decl_stmt|;
comment|/// Get a DITypeRefArray, create one if required.
name|DITypeRefArray
name|getOrCreateTypeArray
argument_list|(
name|ArrayRef
operator|<
name|Metadata
operator|*
operator|>
name|Elements
argument_list|)
decl_stmt|;
comment|/// Create a descriptor for a value range.  This
comment|/// implicitly uniques the values returned.
name|DISubrange
modifier|*
name|getOrCreateSubrange
parameter_list|(
name|int64_t
name|Lo
parameter_list|,
name|int64_t
name|Count
parameter_list|)
function_decl|;
comment|/// Create a new descriptor for the specified variable.
comment|/// \param Context     Variable scope.
comment|/// \param Name        Name of the variable.
comment|/// \param LinkageName Mangled  name of the variable.
comment|/// \param File        File where this variable is defined.
comment|/// \param LineNo      Line number.
comment|/// \param Ty          Variable Type.
comment|/// \param isLocalToUnit Boolean flag indicate whether this variable is
comment|///                      externally visible or not.
comment|/// \param Expr        The location of the global relative to the attached
comment|///                    GlobalVariable.
comment|/// \param Decl        Reference to the corresponding declaration.
comment|/// \param AlignInBits Variable alignment(or 0 if no alignment attr was
comment|///                    specified)
name|DIGlobalVariableExpression
modifier|*
name|createGlobalVariableExpression
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|LinkageName
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|LineNo
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|bool
name|isLocalToUnit
parameter_list|,
name|DIExpression
modifier|*
name|Expr
init|=
name|nullptr
parameter_list|,
name|MDNode
modifier|*
name|Decl
init|=
name|nullptr
parameter_list|,
name|uint32_t
name|AlignInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Identical to createGlobalVariable
comment|/// except that the resulting DbgNode is temporary and meant to be RAUWed.
name|DIGlobalVariable
modifier|*
name|createTempGlobalVariableFwdDecl
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|LinkageName
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|LineNo
parameter_list|,
name|DIType
modifier|*
name|Ty
parameter_list|,
name|bool
name|isLocalToUnit
parameter_list|,
name|MDNode
modifier|*
name|Decl
init|=
name|nullptr
parameter_list|,
name|uint32_t
name|AlignInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Create a new descriptor for an auto variable.  This is a local variable
comment|/// that is not a subprogram parameter.
comment|///
comment|/// \c Scope must be a \a DILocalScope, and thus its scope chain eventually
comment|/// leads to a \a DISubprogram.
comment|///
comment|/// If \c AlwaysPreserve, this variable will be referenced from its
comment|/// containing subprogram, and will survive some optimizations.
name|DILocalVariable
modifier|*
name|createAutoVariable
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|,
name|bool
name|AlwaysPreserve
operator|=
name|false
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|,
name|uint32_t
name|AlignInBits
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// Create a new descriptor for a parameter variable.
comment|///
comment|/// \c Scope must be a \a DILocalScope, and thus its scope chain eventually
comment|/// leads to a \a DISubprogram.
comment|///
comment|/// \c ArgNo is the index (starting from \c 1) of this variable in the
comment|/// subprogram parameters.  \c ArgNo should not conflict with other
comment|/// parameters of the same subprogram.
comment|///
comment|/// If \c AlwaysPreserve, this variable will be referenced from its
comment|/// containing subprogram, and will survive some optimizations.
name|DILocalVariable
modifier|*
name|createParameterVariable
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|unsigned
name|ArgNo
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DIType
operator|*
name|Ty
argument_list|,
name|bool
name|AlwaysPreserve
operator|=
name|false
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|)
decl_stmt|;
comment|/// Create a new descriptor for the specified
comment|/// variable which has a complex address expression for its address.
comment|/// \param Addr        An array of complex address operations.
name|DIExpression
modifier|*
name|createExpression
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Addr
operator|=
name|None
argument_list|)
decl_stmt|;
name|DIExpression
modifier|*
name|createExpression
argument_list|(
name|ArrayRef
operator|<
name|int64_t
operator|>
name|Addr
argument_list|)
decl_stmt|;
comment|/// Create a descriptor to describe one part
comment|/// of aggregate variable that is fragmented across multiple Values.
comment|///
comment|/// \param OffsetInBits Offset of the piece in bits.
comment|/// \param SizeInBits   Size of the piece in bits.
name|DIExpression
modifier|*
name|createFragmentExpression
parameter_list|(
name|unsigned
name|OffsetInBits
parameter_list|,
name|unsigned
name|SizeInBits
parameter_list|)
function_decl|;
comment|/// Create an expression for a variable that does not have an address, but
comment|/// does have a constant value.
name|DIExpression
modifier|*
name|createConstantValueExpression
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
name|DIExpression
operator|::
name|get
argument_list|(
name|VMContext
argument_list|,
block|{
name|dwarf
operator|::
name|DW_OP_constu
operator|,
name|Val
operator|,
name|dwarf
operator|::
name|DW_OP_stack_value
block|}
block|)
function|;
block|}
comment|/// Create a new descriptor for the specified subprogram.
comment|/// See comments in DISubprogram* for descriptions of these fields.
comment|/// \param Scope         Function scope.
comment|/// \param Name          Function name.
comment|/// \param LinkageName   Mangled function name.
comment|/// \param File          File where this variable is defined.
comment|/// \param LineNo        Line number.
comment|/// \param Ty            Function type.
comment|/// \param isLocalToUnit True if this function is not externally visible.
comment|/// \param isDefinition  True if this is a function definition.
comment|/// \param ScopeLine     Set to the beginning of the scope this starts
comment|/// \param Flags         e.g. is this function prototyped or not.
comment|///                      These flags are used to emit dwarf attributes.
comment|/// \param isOptimized   True if optimization is ON.
comment|/// \param TParams       Function template parameters.
comment|/// \param ThrownTypes   Exception types this function may throw.
name|DISubprogram
modifier|*
name|createFunction
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|StringRef
name|LinkageName
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DISubroutineType
operator|*
name|Ty
argument_list|,
name|bool
name|isLocalToUnit
argument_list|,
name|bool
name|isDefinition
argument_list|,
name|unsigned
name|ScopeLine
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|,
name|bool
name|isOptimized
operator|=
name|false
argument_list|,
name|DITemplateParameterArray
name|TParams
operator|=
name|nullptr
argument_list|,
name|DISubprogram
operator|*
name|Decl
operator|=
name|nullptr
argument_list|,
name|DITypeArray
name|ThrownTypes
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// Identical to createFunction,
comment|/// except that the resulting DbgNode is meant to be RAUWed.
name|DISubprogram
modifier|*
name|createTempFunctionFwdDecl
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|StringRef
name|LinkageName
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DISubroutineType
operator|*
name|Ty
argument_list|,
name|bool
name|isLocalToUnit
argument_list|,
name|bool
name|isDefinition
argument_list|,
name|unsigned
name|ScopeLine
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|,
name|bool
name|isOptimized
operator|=
name|false
argument_list|,
name|DITemplateParameterArray
name|TParams
operator|=
name|nullptr
argument_list|,
name|DISubprogram
operator|*
name|Decl
operator|=
name|nullptr
argument_list|,
name|DITypeArray
name|ThrownTypes
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// Create a new descriptor for the specified C++ method.
comment|/// See comments in \a DISubprogram* for descriptions of these fields.
comment|/// \param Scope         Function scope.
comment|/// \param Name          Function name.
comment|/// \param LinkageName   Mangled function name.
comment|/// \param File          File where this variable is defined.
comment|/// \param LineNo        Line number.
comment|/// \param Ty            Function type.
comment|/// \param isLocalToUnit True if this function is not externally visible..
comment|/// \param isDefinition  True if this is a function definition.
comment|/// \param Virtuality    Attributes describing virtualness. e.g. pure
comment|///                      virtual function.
comment|/// \param VTableIndex   Index no of this method in virtual table, or -1u if
comment|///                      unrepresentable.
comment|/// \param ThisAdjustment
comment|///                      MS ABI-specific adjustment of 'this' that occurs
comment|///                      in the prologue.
comment|/// \param VTableHolder  Type that holds vtable.
comment|/// \param Flags         e.g. is this function prototyped or not.
comment|///                      This flags are used to emit dwarf attributes.
comment|/// \param isOptimized   True if optimization is ON.
comment|/// \param TParams       Function template parameters.
comment|/// \param ThrownTypes   Exception types this function may throw.
name|DISubprogram
modifier|*
name|createMethod
argument_list|(
name|DIScope
operator|*
name|Scope
argument_list|,
name|StringRef
name|Name
argument_list|,
name|StringRef
name|LinkageName
argument_list|,
name|DIFile
operator|*
name|File
argument_list|,
name|unsigned
name|LineNo
argument_list|,
name|DISubroutineType
operator|*
name|Ty
argument_list|,
name|bool
name|isLocalToUnit
argument_list|,
name|bool
name|isDefinition
argument_list|,
name|unsigned
name|Virtuality
operator|=
literal|0
argument_list|,
name|unsigned
name|VTableIndex
operator|=
literal|0
argument_list|,
name|int
name|ThisAdjustment
operator|=
literal|0
argument_list|,
name|DIType
operator|*
name|VTableHolder
operator|=
name|nullptr
argument_list|,
name|DINode
operator|::
name|DIFlags
name|Flags
operator|=
name|DINode
operator|::
name|FlagZero
argument_list|,
name|bool
name|isOptimized
operator|=
name|false
argument_list|,
name|DITemplateParameterArray
name|TParams
operator|=
name|nullptr
argument_list|,
name|DITypeArray
name|ThrownTypes
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// This creates new descriptor for a namespace with the specified
comment|/// parent scope.
comment|/// \param Scope       Namespace scope
comment|/// \param Name        Name of this namespace
comment|/// \param ExportSymbols True for C++ inline namespaces.
name|DINamespace
modifier|*
name|createNameSpace
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|bool
name|ExportSymbols
parameter_list|)
function_decl|;
comment|/// This creates new descriptor for a module with the specified
comment|/// parent scope.
comment|/// \param Scope       Parent scope
comment|/// \param Name        Name of this module
comment|/// \param ConfigurationMacros
comment|///                    A space-separated shell-quoted list of -D macro
comment|///                    definitions as they would appear on a command line.
comment|/// \param IncludePath The path to the module map file.
comment|/// \param ISysRoot    The clang system root (value of -isysroot).
name|DIModule
modifier|*
name|createModule
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|ConfigurationMacros
parameter_list|,
name|StringRef
name|IncludePath
parameter_list|,
name|StringRef
name|ISysRoot
parameter_list|)
function_decl|;
comment|/// This creates a descriptor for a lexical block with a new file
comment|/// attached. This merely extends the existing
comment|/// lexical block as it crosses a file.
comment|/// \param Scope       Lexical block.
comment|/// \param File        Source file.
comment|/// \param Discriminator DWARF path discriminator value.
name|DILexicalBlockFile
modifier|*
name|createLexicalBlockFile
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|Discriminator
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// This creates a descriptor for a lexical block with the
comment|/// specified parent context.
comment|/// \param Scope         Parent lexical scope.
comment|/// \param File          Source file.
comment|/// \param Line          Line number.
comment|/// \param Col           Column number.
name|DILexicalBlock
modifier|*
name|createLexicalBlock
parameter_list|(
name|DIScope
modifier|*
name|Scope
parameter_list|,
name|DIFile
modifier|*
name|File
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|unsigned
name|Col
parameter_list|)
function_decl|;
comment|/// Create a descriptor for an imported module.
comment|/// \param Context The scope this module is imported into
comment|/// \param NS The namespace being imported here
comment|/// \param Line Line number
name|DIImportedEntity
modifier|*
name|createImportedModule
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|DINamespace
modifier|*
name|NS
parameter_list|,
name|unsigned
name|Line
parameter_list|)
function_decl|;
comment|/// Create a descriptor for an imported module.
comment|/// \param Context The scope this module is imported into
comment|/// \param NS An aliased namespace
comment|/// \param Line Line number
name|DIImportedEntity
modifier|*
name|createImportedModule
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|DIImportedEntity
modifier|*
name|NS
parameter_list|,
name|unsigned
name|Line
parameter_list|)
function_decl|;
comment|/// Create a descriptor for an imported module.
comment|/// \param Context The scope this module is imported into
comment|/// \param M The module being imported here
comment|/// \param Line Line number
name|DIImportedEntity
modifier|*
name|createImportedModule
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|DIModule
modifier|*
name|M
parameter_list|,
name|unsigned
name|Line
parameter_list|)
function_decl|;
comment|/// Create a descriptor for an imported function.
comment|/// \param Context The scope this module is imported into
comment|/// \param Decl The declaration (or definition) of a function, type, or
comment|///             variable
comment|/// \param Line Line number
name|DIImportedEntity
modifier|*
name|createImportedDeclaration
parameter_list|(
name|DIScope
modifier|*
name|Context
parameter_list|,
name|DINode
modifier|*
name|Decl
parameter_list|,
name|unsigned
name|Line
parameter_list|,
name|StringRef
name|Name
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// Insert a new llvm.dbg.declare intrinsic call.
comment|/// \param Storage     llvm::Value of the variable
comment|/// \param VarInfo     Variable's debug info descriptor.
comment|/// \param Expr        A complex location expression.
comment|/// \param DL          Debug info location.
comment|/// \param InsertAtEnd Location for the new intrinsic.
name|Instruction
modifier|*
name|insertDeclare
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Storage
argument_list|,
name|DILocalVariable
operator|*
name|VarInfo
argument_list|,
name|DIExpression
operator|*
name|Expr
argument_list|,
specifier|const
name|DILocation
operator|*
name|DL
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
decl_stmt|;
comment|/// Insert a new llvm.dbg.declare intrinsic call.
comment|/// \param Storage      llvm::Value of the variable
comment|/// \param VarInfo      Variable's debug info descriptor.
comment|/// \param Expr         A complex location expression.
comment|/// \param DL           Debug info location.
comment|/// \param InsertBefore Location for the new intrinsic.
name|Instruction
modifier|*
name|insertDeclare
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Storage
argument_list|,
name|DILocalVariable
operator|*
name|VarInfo
argument_list|,
name|DIExpression
operator|*
name|Expr
argument_list|,
specifier|const
name|DILocation
operator|*
name|DL
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
decl_stmt|;
comment|/// Insert a new llvm.dbg.value intrinsic call.
comment|/// \param Val          llvm::Value of the variable
comment|/// \param Offset       Offset
comment|/// \param VarInfo      Variable's debug info descriptor.
comment|/// \param Expr         A complex location expression.
comment|/// \param DL           Debug info location.
comment|/// \param InsertAtEnd Location for the new intrinsic.
name|Instruction
modifier|*
name|insertDbgValueIntrinsic
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Val
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|DILocalVariable
operator|*
name|VarInfo
argument_list|,
name|DIExpression
operator|*
name|Expr
argument_list|,
specifier|const
name|DILocation
operator|*
name|DL
argument_list|,
name|BasicBlock
operator|*
name|InsertAtEnd
argument_list|)
decl_stmt|;
comment|/// Insert a new llvm.dbg.value intrinsic call.
comment|/// \param Val          llvm::Value of the variable
comment|/// \param Offset       Offset
comment|/// \param VarInfo      Variable's debug info descriptor.
comment|/// \param Expr         A complex location expression.
comment|/// \param DL           Debug info location.
comment|/// \param InsertBefore Location for the new intrinsic.
name|Instruction
modifier|*
name|insertDbgValueIntrinsic
argument_list|(
name|llvm
operator|::
name|Value
operator|*
name|Val
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|DILocalVariable
operator|*
name|VarInfo
argument_list|,
name|DIExpression
operator|*
name|Expr
argument_list|,
specifier|const
name|DILocation
operator|*
name|DL
argument_list|,
name|Instruction
operator|*
name|InsertBefore
argument_list|)
decl_stmt|;
comment|/// Replace the vtable holder in the given composite type.
comment|///
comment|/// If this creates a self reference, it may orphan some unresolved cycles
comment|/// in the operands of \c T, so \a DIBuilder needs to track that.
name|void
name|replaceVTableHolder
parameter_list|(
name|DICompositeType
modifier|*
modifier|&
name|T
parameter_list|,
name|DICompositeType
modifier|*
name|VTableHolder
parameter_list|)
function_decl|;
comment|/// Replace arrays on a composite type.
comment|///
comment|/// If \c T is resolved, but the arrays aren't -- which can happen if \c T
comment|/// has a self-reference -- \a DIBuilder needs to track the array to
comment|/// resolve cycles.
name|void
name|replaceArrays
parameter_list|(
name|DICompositeType
modifier|*
modifier|&
name|T
parameter_list|,
name|DINodeArray
name|Elements
parameter_list|,
name|DINodeArray
name|TParams
init|=
name|DINodeArray
argument_list|()
parameter_list|)
function_decl|;
comment|/// Replace a temporary node.
comment|///
comment|/// Call \a MDNode::replaceAllUsesWith() on \c N, replacing it with \c
comment|/// Replacement.
comment|///
comment|/// If \c Replacement is the same as \c N.get(), instead call \a
comment|/// MDNode::replaceWithUniqued().  In this case, the uniqued node could
comment|/// have a different address, so we return the final address.
name|template
operator|<
name|class
name|NodeTy
operator|>
name|NodeTy
operator|*
name|replaceTemporary
argument_list|(
argument|TempMDNode&&N
argument_list|,
argument|NodeTy *Replacement
argument_list|)
block|{
if|if
condition|(
name|N
operator|.
name|get
argument_list|()
operator|==
name|Replacement
condition|)
return|return
name|cast
operator|<
name|NodeTy
operator|>
operator|(
name|MDNode
operator|::
name|replaceWithUniqued
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|N
argument_list|)
argument_list|)
operator|)
return|;
name|N
operator|->
name|replaceAllUsesWith
argument_list|(
name|Replacement
argument_list|)
expr_stmt|;
return|return
name|Replacement
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
end_comment

begin_macro
name|DEFINE_ISA_CONVERSION_FUNCTIONS
argument_list|(
argument|DIBuilder
argument_list|,
argument|LLVMDIBuilderRef
argument_list|)
end_macro

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DIBUILDER_H
end_comment

end_unit

