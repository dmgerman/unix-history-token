begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/lib/CodeGen/AsmPrinter/CodeViewDebug.h --------------*- C++ -*-===//
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
comment|// This file contains support for writing Microsoft CodeView debug info.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_CODEVIEWDEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_CODEVIEWDEBUG_H
end_define

begin_include
include|#
directive|include
file|"DbgValueHistoryCalculator.h"
end_include

begin_include
include|#
directive|include
file|"DebugHandlerBase.h"
end_include

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
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
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
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeTableBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<tuple>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|ClassInfo
struct_decl|;
name|class
name|StringRef
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|MCSectionCOFF
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
comment|/// \brief Collects and handles line tables information in a CodeView format.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|CodeViewDebug
range|:
name|public
name|DebugHandlerBase
block|{
name|MCStreamer
operator|&
name|OS
block|;
name|BumpPtrAllocator
name|Allocator
block|;
name|codeview
operator|::
name|TypeTableBuilder
name|TypeTable
block|;
comment|/// Represents the most general definition range.
block|struct
name|LocalVarDefRange
block|{
comment|/// Indicates that variable data is stored in memory relative to the
comment|/// specified register.
name|int
name|InMemory
operator|:
literal|1
block|;
comment|/// Offset of variable data in memory.
name|int
name|DataOffset
operator|:
literal|31
block|;
comment|/// Non-zero if this is a piece of an aggregate.
name|uint16_t
name|IsSubfield
operator|:
literal|1
block|;
comment|/// Offset into aggregate.
name|uint16_t
name|StructOffset
operator|:
literal|15
block|;
comment|/// Register containing the data or the register base of the memory
comment|/// location containing the data.
name|uint16_t
name|CVRegister
block|;
comment|/// Compares all location fields. This includes all fields except the label
comment|/// ranges.
name|bool
name|isDifferentLocation
argument_list|(
argument|LocalVarDefRange&O
argument_list|)
block|{
return|return
name|InMemory
operator|!=
name|O
operator|.
name|InMemory
operator|||
name|DataOffset
operator|!=
name|O
operator|.
name|DataOffset
operator|||
name|IsSubfield
operator|!=
name|O
operator|.
name|IsSubfield
operator|||
name|StructOffset
operator|!=
name|O
operator|.
name|StructOffset
operator|||
name|CVRegister
operator|!=
name|O
operator|.
name|CVRegister
return|;
block|}
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
specifier|const
name|MCSymbol
operator|*
operator|>
block|,
literal|1
operator|>
name|Ranges
block|;   }
block|;
specifier|static
name|LocalVarDefRange
name|createDefRangeMem
argument_list|(
argument|uint16_t CVRegister
argument_list|,
argument|int Offset
argument_list|)
block|;
specifier|static
name|LocalVarDefRange
name|createDefRangeGeneral
argument_list|(
argument|uint16_t CVRegister
argument_list|,
argument|bool InMemory
argument_list|,
argument|int Offset
argument_list|,
argument|bool IsSubfield
argument_list|,
argument|uint16_t StructOffset
argument_list|)
block|;
comment|/// Similar to DbgVariable in DwarfDebug, but not dwarf-specific.
block|struct
name|LocalVariable
block|{
specifier|const
name|DILocalVariable
operator|*
name|DIVar
operator|=
name|nullptr
block|;
name|SmallVector
operator|<
name|LocalVarDefRange
block|,
literal|1
operator|>
name|DefRanges
block|;   }
block|;    struct
name|InlineSite
block|{
name|SmallVector
operator|<
name|LocalVariable
block|,
literal|1
operator|>
name|InlinedLocals
block|;
name|SmallVector
operator|<
specifier|const
name|DILocation
operator|*
block|,
literal|1
operator|>
name|ChildSites
block|;
specifier|const
name|DISubprogram
operator|*
name|Inlinee
operator|=
name|nullptr
block|;
comment|/// The ID of the inline site or function used with .cv_loc. Not a type
comment|/// index.
name|unsigned
name|SiteFuncId
operator|=
literal|0
block|;   }
block|;
comment|// For each function, store a vector of labels to its instructions, as well as
comment|// to the end of the function.
block|struct
name|FunctionInfo
block|{
comment|/// Map from inlined call site to inlined instructions and child inlined
comment|/// call sites. Listed in program order.
name|std
operator|::
name|unordered_map
operator|<
specifier|const
name|DILocation
operator|*
block|,
name|InlineSite
operator|>
name|InlineSites
block|;
comment|/// Ordered list of top-level inlined call sites.
name|SmallVector
operator|<
specifier|const
name|DILocation
operator|*
block|,
literal|1
operator|>
name|ChildSites
block|;
name|SmallVector
operator|<
name|LocalVariable
block|,
literal|1
operator|>
name|Locals
block|;
specifier|const
name|MCSymbol
operator|*
name|Begin
operator|=
name|nullptr
block|;
specifier|const
name|MCSymbol
operator|*
name|End
operator|=
name|nullptr
block|;
name|unsigned
name|FuncId
operator|=
literal|0
block|;
name|unsigned
name|LastFileId
operator|=
literal|0
block|;
name|bool
name|HaveLineInfo
operator|=
name|false
block|;   }
block|;
name|FunctionInfo
operator|*
name|CurFn
operator|=
name|nullptr
block|;
comment|/// The set of comdat .debug$S sections that we've seen so far. Each section
comment|/// must start with a magic version number that must only be emitted once.
comment|/// This set tracks which sections we've already opened.
name|DenseSet
operator|<
name|MCSectionCOFF
operator|*
operator|>
name|ComdatDebugSections
block|;
comment|/// Switch to the appropriate .debug$S section for GVSym. If GVSym, the symbol
comment|/// of an emitted global value, is in a comdat COFF section, this will switch
comment|/// to a new .debug$S section in that comdat. This method ensures that the
comment|/// section starts with the magic version number on first use. If GVSym is
comment|/// null, uses the main .debug$S section.
name|void
name|switchToDebugSectionForSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|GVSym
argument_list|)
block|;
comment|/// The next available function index for use with our .cv_* directives. Not
comment|/// to be confused with type indices for LF_FUNC_ID records.
name|unsigned
name|NextFuncId
operator|=
literal|0
block|;
name|InlineSite
operator|&
name|getInlineSite
argument_list|(
specifier|const
name|DILocation
operator|*
name|InlinedAt
argument_list|,
specifier|const
name|DISubprogram
operator|*
name|Inlinee
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|getFuncIdForSubprogram
argument_list|(
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|)
block|;
specifier|static
name|void
name|collectInlineSiteChildren
argument_list|(
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Children
argument_list|,
specifier|const
name|FunctionInfo
operator|&
name|FI
argument_list|,
specifier|const
name|InlineSite
operator|&
name|Site
argument_list|)
block|;
comment|/// Remember some debug info about each function. Keep it in a stable order to
comment|/// emit at the end of the TU.
name|MapVector
operator|<
specifier|const
name|Function
operator|*
block|,
name|FunctionInfo
operator|>
name|FnDebugInfo
block|;
comment|/// Map from DIFile to .cv_file id.
name|DenseMap
operator|<
specifier|const
name|DIFile
operator|*
block|,
name|unsigned
operator|>
name|FileIdMap
block|;
comment|/// All inlined subprograms in the order they should be emitted.
name|SmallSetVector
operator|<
specifier|const
name|DISubprogram
operator|*
block|,
literal|4
operator|>
name|InlinedSubprograms
block|;
comment|/// Map from a pair of DI metadata nodes and its DI type (or scope) that can
comment|/// be nullptr, to CodeView type indices. Primarily indexed by
comment|/// {DIType*, DIType*} and {DISubprogram*, DIType*}.
comment|///
comment|/// The second entry in the key is needed for methods as DISubroutineType
comment|/// representing static method type are shared with non-method function type.
name|DenseMap
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|DINode
operator|*
block|,
specifier|const
name|DIType
operator|*
operator|>
block|,
name|codeview
operator|::
name|TypeIndex
operator|>
name|TypeIndices
block|;
comment|/// Map from DICompositeType* to complete type index. Non-record types are
comment|/// always looked up in the normal TypeIndices map.
name|DenseMap
operator|<
specifier|const
name|DICompositeType
operator|*
block|,
name|codeview
operator|::
name|TypeIndex
operator|>
name|CompleteTypeIndices
block|;
comment|/// Complete record types to emit after all active type lowerings are
comment|/// finished.
name|SmallVector
operator|<
specifier|const
name|DICompositeType
operator|*
block|,
literal|4
operator|>
name|DeferredCompleteTypes
block|;
comment|/// Number of type lowering frames active on the stack.
name|unsigned
name|TypeEmissionLevel
operator|=
literal|0
block|;
name|codeview
operator|::
name|TypeIndex
name|VBPType
block|;
specifier|const
name|DISubprogram
operator|*
name|CurrentSubprogram
operator|=
name|nullptr
block|;
comment|// The UDTs we have seen while processing types; each entry is a pair of type
comment|// index and type name.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
block|,
name|codeview
operator|::
name|TypeIndex
operator|>>
name|LocalUDTs
block|,
name|GlobalUDTs
block|;
name|using
name|FileToFilepathMapTy
operator|=
name|std
operator|::
name|map
operator|<
specifier|const
name|DIFile
operator|*
block|,
name|std
operator|::
name|string
operator|>
block|;
name|FileToFilepathMapTy
name|FileToFilepathMap
block|;
name|StringRef
name|getFullFilepath
argument_list|(
specifier|const
name|DIFile
operator|*
name|S
argument_list|)
block|;
name|unsigned
name|maybeRecordFile
argument_list|(
specifier|const
name|DIFile
operator|*
name|F
argument_list|)
block|;
name|void
name|maybeRecordLocation
argument_list|(
specifier|const
name|DebugLoc
operator|&
name|DL
argument_list|,
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
name|void
name|clear
argument_list|()
block|;
name|void
name|setCurrentSubprogram
argument_list|(
argument|const DISubprogram *SP
argument_list|)
block|{
name|CurrentSubprogram
operator|=
name|SP
block|;
name|LocalUDTs
operator|.
name|clear
argument_list|()
block|;   }
comment|/// Emit the magic version number at the start of a CodeView type or symbol
comment|/// section. Appears at the front of every .debug$S or .debug$T section.
name|void
name|emitCodeViewMagicVersion
argument_list|()
block|;
name|void
name|emitTypeInformation
argument_list|()
block|;
name|void
name|emitCompilerInformation
argument_list|()
block|;
name|void
name|emitInlineeLinesSubsection
argument_list|()
block|;
name|void
name|emitDebugInfoForFunction
argument_list|(
specifier|const
name|Function
operator|*
name|GV
argument_list|,
name|FunctionInfo
operator|&
name|FI
argument_list|)
block|;
name|void
name|emitDebugInfoForGlobals
argument_list|()
block|;
name|void
name|emitDebugInfoForRetainedTypes
argument_list|()
block|;
name|void
name|emitDebugInfoForUDTs
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
argument_list|,
name|codeview
operator|::
name|TypeIndex
operator|>>
name|UDTs
argument_list|)
block|;
name|void
name|emitDebugInfoForGlobal
argument_list|(
specifier|const
name|DIGlobalVariable
operator|*
name|DIGV
argument_list|,
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|MCSymbol
operator|*
name|GVSym
argument_list|)
block|;
comment|/// Opens a subsection of the given kind in a .debug$S codeview section.
comment|/// Returns an end label for use with endCVSubsection when the subsection is
comment|/// finished.
name|MCSymbol
operator|*
name|beginCVSubsection
argument_list|(
argument|codeview::DebugSubsectionKind Kind
argument_list|)
block|;
name|void
name|endCVSubsection
argument_list|(
name|MCSymbol
operator|*
name|EndLabel
argument_list|)
block|;
name|void
name|emitInlinedCallSite
argument_list|(
specifier|const
name|FunctionInfo
operator|&
name|FI
argument_list|,
specifier|const
name|DILocation
operator|*
name|InlinedAt
argument_list|,
specifier|const
name|InlineSite
operator|&
name|Site
argument_list|)
block|;
name|using
name|InlinedVariable
operator|=
name|DbgValueHistoryMap
operator|::
name|InlinedVariable
block|;
name|void
name|collectVariableInfo
argument_list|(
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|)
block|;
name|void
name|collectVariableInfoFromMFTable
argument_list|(
name|DenseSet
operator|<
name|InlinedVariable
operator|>
operator|&
name|Processed
argument_list|)
block|;
comment|/// Records information about a local variable in the appropriate scope. In
comment|/// particular, locals from inlined code live inside the inlining site.
name|void
name|recordLocalVariable
argument_list|(
name|LocalVariable
operator|&&
name|Var
argument_list|,
specifier|const
name|DILocation
operator|*
name|Loc
argument_list|)
block|;
comment|/// Emits local variables in the appropriate order.
name|void
name|emitLocalVariableList
argument_list|(
name|ArrayRef
operator|<
name|LocalVariable
operator|>
name|Locals
argument_list|)
block|;
comment|/// Emits an S_LOCAL record and its associated defined ranges.
name|void
name|emitLocalVariable
argument_list|(
specifier|const
name|LocalVariable
operator|&
name|Var
argument_list|)
block|;
comment|/// Translates the DIType to codeview if necessary and returns a type index
comment|/// for it.
name|codeview
operator|::
name|TypeIndex
name|getTypeIndex
argument_list|(
argument|DITypeRef TypeRef
argument_list|,
argument|DITypeRef ClassTyRef = DITypeRef()
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|getMemberFunctionType
argument_list|(
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|,
specifier|const
name|DICompositeType
operator|*
name|Class
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|getScopeIndex
argument_list|(
specifier|const
name|DIScope
operator|*
name|Scope
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|getVBPTypeIndex
argument_list|()
block|;
name|void
name|addToUDTs
argument_list|(
argument|const DIType *Ty
argument_list|,
argument|codeview::TypeIndex TI
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerType
argument_list|(
specifier|const
name|DIType
operator|*
name|Ty
argument_list|,
specifier|const
name|DIType
operator|*
name|ClassTy
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeAlias
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeArray
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeBasic
argument_list|(
specifier|const
name|DIBasicType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypePointer
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeMemberPointer
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeModifier
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeFunction
argument_list|(
specifier|const
name|DISubroutineType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeVFTableShape
argument_list|(
specifier|const
name|DIDerivedType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeMemberFunction
argument_list|(
argument|const DISubroutineType *Ty
argument_list|,
argument|const DIType *ClassTy
argument_list|,
argument|int ThisAdjustment
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeEnum
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeClass
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerTypeUnion
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
comment|/// Symbol records should point to complete types, but type records should
comment|/// always point to incomplete types to avoid cycles in the type graph. Only
comment|/// use this entry point when generating symbol records. The complete and
comment|/// incomplete type indices only differ for record types. All other types use
comment|/// the same index.
name|codeview
operator|::
name|TypeIndex
name|getCompleteTypeIndex
argument_list|(
argument|DITypeRef TypeRef
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerCompleteTypeClass
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
name|codeview
operator|::
name|TypeIndex
name|lowerCompleteTypeUnion
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;    struct
name|TypeLoweringScope
block|;
name|void
name|emitDeferredCompleteTypes
argument_list|()
block|;
name|void
name|collectMemberInfo
argument_list|(
name|ClassInfo
operator|&
name|Info
argument_list|,
specifier|const
name|DIDerivedType
operator|*
name|DDTy
argument_list|)
block|;
name|ClassInfo
name|collectClassInfo
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
comment|/// Common record member lowering functionality for record types, which are
comment|/// structs, classes, and unions. Returns the field list index and the member
comment|/// count.
name|std
operator|::
name|tuple
operator|<
name|codeview
operator|::
name|TypeIndex
block|,
name|codeview
operator|::
name|TypeIndex
block|,
name|unsigned
block|,
name|bool
operator|>
name|lowerRecordFieldList
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
block|;
comment|/// Inserts {{Node, ClassTy}, TI} into TypeIndices and checks for duplicates.
name|codeview
operator|::
name|TypeIndex
name|recordTypeIndexForDINode
argument_list|(
argument|const DINode *Node
argument_list|,
argument|codeview::TypeIndex TI
argument_list|,
argument|const DIType *ClassTy = nullptr
argument_list|)
block|;
name|unsigned
name|getPointerSizeInBytes
argument_list|()
block|;
name|protected
operator|:
comment|/// \brief Gather pre-function debug information.
name|void
name|beginFunctionImpl
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// \brief Gather post-function debug information.
name|void
name|endFunctionImpl
argument_list|(
argument|const MachineFunction *
argument_list|)
name|override
block|;
name|public
operator|:
name|CodeViewDebug
argument_list|(
name|AsmPrinter
operator|*
name|Asm
argument_list|)
block|;
name|void
name|setSymbolSize
argument_list|(
argument|const MCSymbol *
argument_list|,
argument|uint64_t
argument_list|)
name|override
block|{}
comment|/// \brief Emit the COFF section that holds the line table information.
name|void
name|endModule
argument_list|()
name|override
block|;
comment|/// \brief Process beginning of an instruction.
name|void
name|beginInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_CODEGEN_ASMPRINTER_CODEVIEWDEBUG_H
end_comment

end_unit

