begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/CodeGen/AsmPrinter/CodeViewDebug.h ----*- C++ -*--===//
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
file|"DebugHandlerBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/AsmPrinter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
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
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetLoweringObjectFile.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|LexicalScope
decl_stmt|;
struct_decl|struct
name|ClassInfo
struct_decl|;
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
name|llvm
operator|::
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
name|DebugLoc
name|LastLoc
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
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|DIFile
operator|*
operator|,
name|std
operator|::
name|string
operator|>
name|FileToFilepathMapTy
expr_stmt|;
name|FileToFilepathMapTy
name|FileToFilepathMap
decl_stmt|;
name|StringRef
name|getFullFilepath
parameter_list|(
specifier|const
name|DIFile
modifier|*
name|S
parameter_list|)
function_decl|;
name|unsigned
name|maybeRecordFile
parameter_list|(
specifier|const
name|DIFile
modifier|*
name|F
parameter_list|)
function_decl|;
name|void
name|maybeRecordLocation
parameter_list|(
specifier|const
name|DebugLoc
modifier|&
name|DL
parameter_list|,
specifier|const
name|MachineFunction
modifier|*
name|MF
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|setCurrentSubprogram
parameter_list|(
specifier|const
name|DISubprogram
modifier|*
name|SP
parameter_list|)
block|{
name|CurrentSubprogram
operator|=
name|SP
expr_stmt|;
name|LocalUDTs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
comment|/// Emit the magic version number at the start of a CodeView type or symbol
comment|/// section. Appears at the front of every .debug$S or .debug$T section.
name|void
name|emitCodeViewMagicVersion
parameter_list|()
function_decl|;
name|void
name|emitTypeInformation
parameter_list|()
function_decl|;
name|void
name|emitCompilerInformation
parameter_list|()
function_decl|;
name|void
name|emitInlineeLinesSubsection
parameter_list|()
function_decl|;
name|void
name|emitDebugInfoForFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|GV
parameter_list|,
name|FunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
name|void
name|emitDebugInfoForGlobals
parameter_list|()
function_decl|;
name|void
name|emitDebugInfoForRetainedTypes
parameter_list|()
function_decl|;
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
decl_stmt|;
name|void
name|emitDebugInfoForGlobal
parameter_list|(
specifier|const
name|DIGlobalVariable
modifier|*
name|DIGV
parameter_list|,
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|,
name|MCSymbol
modifier|*
name|GVSym
parameter_list|)
function_decl|;
comment|/// Opens a subsection of the given kind in a .debug$S codeview section.
comment|/// Returns an end label for use with endCVSubsection when the subsection is
comment|/// finished.
name|MCSymbol
modifier|*
name|beginCVSubsection
argument_list|(
name|codeview
operator|::
name|ModuleSubstreamKind
name|Kind
argument_list|)
decl_stmt|;
name|void
name|endCVSubsection
parameter_list|(
name|MCSymbol
modifier|*
name|EndLabel
parameter_list|)
function_decl|;
name|void
name|emitInlinedCallSite
parameter_list|(
specifier|const
name|FunctionInfo
modifier|&
name|FI
parameter_list|,
specifier|const
name|DILocation
modifier|*
name|InlinedAt
parameter_list|,
specifier|const
name|InlineSite
modifier|&
name|Site
parameter_list|)
function_decl|;
typedef|typedef
name|DbgValueHistoryMap
operator|::
name|InlinedVariable
name|InlinedVariable
expr_stmt|;
name|void
name|collectVariableInfo
parameter_list|(
specifier|const
name|DISubprogram
modifier|*
name|SP
parameter_list|)
function_decl|;
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
decl_stmt|;
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
decl_stmt|;
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
decl_stmt|;
comment|/// Emits an S_LOCAL record and its associated defined ranges.
name|void
name|emitLocalVariable
parameter_list|(
specifier|const
name|LocalVariable
modifier|&
name|Var
parameter_list|)
function_decl|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
name|codeview
operator|::
name|TypeIndex
name|getVBPTypeIndex
argument_list|()
expr_stmt|;
name|void
name|addToUDTs
argument_list|(
specifier|const
name|DIType
operator|*
name|Ty
argument_list|,
name|codeview
operator|::
name|TypeIndex
name|TI
argument_list|)
decl_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
struct_decl|struct
name|TypeLoweringScope
struct_decl|;
name|void
name|emitDeferredCompleteTypes
parameter_list|()
function_decl|;
name|void
name|collectMemberInfo
parameter_list|(
name|ClassInfo
modifier|&
name|Info
parameter_list|,
specifier|const
name|DIDerivedType
modifier|*
name|DDTy
parameter_list|)
function_decl|;
name|ClassInfo
name|collectClassInfo
parameter_list|(
specifier|const
name|DICompositeType
modifier|*
name|Ty
parameter_list|)
function_decl|;
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
operator|,
name|codeview
operator|::
name|TypeIndex
operator|,
name|unsigned
operator|,
name|bool
operator|>
name|lowerRecordFieldList
argument_list|(
specifier|const
name|DICompositeType
operator|*
name|Ty
argument_list|)
expr_stmt|;
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
expr_stmt|;
name|unsigned
name|getPointerSizeInBytes
parameter_list|()
function_decl|;
name|protected
label|:
comment|/// \brief Gather pre-function debug information.
name|void
name|beginFunctionImpl
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
name|override
decl_stmt|;
comment|/// \brief Gather post-function debug information.
name|void
name|endFunctionImpl
argument_list|(
specifier|const
name|MachineFunction
operator|*
argument_list|)
name|override
decl_stmt|;
name|public
label|:
name|CodeViewDebug
argument_list|(
name|AsmPrinter
operator|*
name|Asm
argument_list|)
expr_stmt|;
name|void
name|setSymbolSize
argument_list|(
specifier|const
name|llvm
operator|::
name|MCSymbol
operator|*
argument_list|,
name|uint64_t
argument_list|)
name|override
block|{}
comment|/// \brief Emit the COFF section that holds the line table information.
name|void
name|endModule
argument_list|()
name|override
expr_stmt|;
comment|/// \brief Process beginning of an instruction.
name|void
name|beginInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
name|override
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

