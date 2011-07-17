begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfCompileUnit.h - Dwarf Compile Unit ---*- C++ -*--===//
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
comment|// This file contains support for writing dwarf compile unit.
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
name|CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_ASMPRINTER_DWARFCOMPILEUNIT_H
end_define

begin_include
include|#
directive|include
file|"DIE.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/DebugInfo.h"
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
file|"llvm/ADT/OwningPtr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|MachineLocation
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|DbgVariable
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// CompileUnit - This dwarf writer support class manages information associate
comment|/// with a source file.
name|class
name|CompileUnit
block|{
comment|/// ID - File identifier for source.
comment|///
name|unsigned
name|ID
decl_stmt|;
comment|/// Die - Compile unit debug information entry.
comment|///
specifier|const
name|OwningPtr
operator|<
name|DIE
operator|>
name|CUDie
expr_stmt|;
comment|/// Asm - Target of Dwarf emission.
name|AsmPrinter
modifier|*
name|Asm
decl_stmt|;
name|DwarfDebug
modifier|*
name|DD
decl_stmt|;
comment|/// IndexTyDie - An anonymous type for index type.  Owned by CUDie.
name|DIE
modifier|*
name|IndexTyDie
decl_stmt|;
comment|/// MDNodeToDieMap - Tracks the mapping of unit level debug informaton
comment|/// variables to debug information entries.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIE
operator|*
operator|>
name|MDNodeToDieMap
expr_stmt|;
comment|/// MDNodeToDIEEntryMap - Tracks the mapping of unit level debug informaton
comment|/// descriptors to debug information entries using a DIEEntry proxy.
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIEEntry
operator|*
operator|>
name|MDNodeToDIEEntryMap
expr_stmt|;
comment|/// Globals - A map of globally visible named entities for this unit.
comment|///
name|StringMap
operator|<
name|DIE
operator|*
operator|>
name|Globals
expr_stmt|;
comment|/// GlobalTypes - A map of globally visible types for this unit.
comment|///
name|StringMap
operator|<
name|DIE
operator|*
operator|>
name|GlobalTypes
expr_stmt|;
comment|/// DIEBlocks - A list of all the DIEBlocks in use.
name|std
operator|::
name|vector
operator|<
name|DIEBlock
operator|*
operator|>
name|DIEBlocks
expr_stmt|;
name|public
label|:
name|CompileUnit
argument_list|(
argument|unsigned I
argument_list|,
argument|DIE *D
argument_list|,
argument|AsmPrinter *A
argument_list|,
argument|DwarfDebug *DW
argument_list|)
empty_stmt|;
operator|~
name|CompileUnit
argument_list|()
expr_stmt|;
comment|// Accessors.
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|DIE
operator|*
name|getCUDie
argument_list|()
specifier|const
block|{
return|return
name|CUDie
operator|.
name|get
argument_list|()
return|;
block|}
specifier|const
name|StringMap
operator|<
name|DIE
operator|*
operator|>
operator|&
name|getGlobals
argument_list|()
specifier|const
block|{
return|return
name|Globals
return|;
block|}
specifier|const
name|StringMap
operator|<
name|DIE
operator|*
operator|>
operator|&
name|getGlobalTypes
argument_list|()
specifier|const
block|{
return|return
name|GlobalTypes
return|;
block|}
comment|/// hasContent - Return true if this compile unit has something to write out.
comment|///
name|bool
name|hasContent
argument_list|()
specifier|const
block|{
return|return
operator|!
name|CUDie
operator|->
name|getChildren
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// addGlobal - Add a new global entity to the compile unit.
comment|///
name|void
name|addGlobal
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|)
block|{
name|Globals
index|[
name|Name
index|]
operator|=
name|Die
expr_stmt|;
block|}
comment|/// addGlobalType - Add a new global type to the compile unit.
comment|///
name|void
name|addGlobalType
parameter_list|(
name|DIType
name|Ty
parameter_list|)
function_decl|;
comment|/// getDIE - Returns the debug information entry map slot for the
comment|/// specified debug variable.
name|DIE
modifier|*
name|getDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
block|{
return|return
name|MDNodeToDieMap
operator|.
name|lookup
argument_list|(
name|N
argument_list|)
return|;
block|}
name|DIEBlock
modifier|*
name|getDIEBlock
parameter_list|()
block|{
return|return
name|new
argument_list|(
argument|DIEValueAllocator
argument_list|)
name|DIEBlock
argument_list|()
return|;
block|}
comment|/// insertDIE - Insert DIE into the map.
name|void
name|insertDIE
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|,
name|DIE
modifier|*
name|D
parameter_list|)
block|{
name|MDNodeToDieMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|N
argument_list|,
name|D
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// getDIEEntry - Returns the debug information entry for the specified
comment|/// debug variable.
name|DIEEntry
modifier|*
name|getDIEEntry
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|)
block|{
name|DenseMap
operator|<
specifier|const
name|MDNode
operator|*
operator|,
name|DIEEntry
operator|*
operator|>
operator|::
name|iterator
name|I
operator|=
name|MDNodeToDIEEntryMap
operator|.
name|find
argument_list|(
name|N
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|==
name|MDNodeToDIEEntryMap
operator|.
name|end
argument_list|()
condition|)
return|return
name|NULL
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
comment|/// insertDIEEntry - Insert debug information entry into the map.
name|void
name|insertDIEEntry
parameter_list|(
specifier|const
name|MDNode
modifier|*
name|N
parameter_list|,
name|DIEEntry
modifier|*
name|E
parameter_list|)
block|{
name|MDNodeToDIEEntryMap
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|N
argument_list|,
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// addDie - Adds or interns the DIE to the compile unit.
comment|///
name|void
name|addDie
parameter_list|(
name|DIE
modifier|*
name|Buffer
parameter_list|)
block|{
name|this
operator|->
name|CUDie
operator|->
name|addChild
argument_list|(
name|Buffer
argument_list|)
expr_stmt|;
block|}
comment|// getIndexTyDie - Get an anonymous type for index type.
name|DIE
modifier|*
name|getIndexTyDie
parameter_list|()
block|{
return|return
name|IndexTyDie
return|;
block|}
comment|// setIndexTyDie - Set D as anonymous type for index which can be reused
comment|// later.
name|void
name|setIndexTyDie
parameter_list|(
name|DIE
modifier|*
name|D
parameter_list|)
block|{
name|IndexTyDie
operator|=
name|D
expr_stmt|;
block|}
name|public
label|:
comment|/// addUInt - Add an unsigned integer attribute data and value.
comment|///
name|void
name|addUInt
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|uint64_t
name|Integer
parameter_list|)
function_decl|;
comment|/// addSInt - Add an signed integer attribute data and value.
comment|///
name|void
name|addSInt
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|int64_t
name|Integer
parameter_list|)
function_decl|;
comment|/// addString - Add a string attribute data and value.
comment|///
name|void
name|addString
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|StringRef
name|Str
parameter_list|)
function_decl|;
comment|/// addLabel - Add a Dwarf label attribute data and value.
comment|///
name|void
name|addLabel
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Label
parameter_list|)
function_decl|;
comment|/// addDelta - Add a label delta attribute data and value.
comment|///
name|void
name|addDelta
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Hi
parameter_list|,
specifier|const
name|MCSymbol
modifier|*
name|Lo
parameter_list|)
function_decl|;
comment|/// addDIEEntry - Add a DIE attribute data and value.
comment|///
name|void
name|addDIEEntry
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|DIE
modifier|*
name|Entry
parameter_list|)
function_decl|;
comment|/// addBlock - Add block data.
comment|///
name|void
name|addBlock
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
name|unsigned
name|Form
parameter_list|,
name|DIEBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
comment|/// addSourceLine - Add location information to specified debug information
comment|/// entry.
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DIVariable
name|V
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DIGlobalVariable
name|G
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
name|void
name|addSourceLine
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DINameSpace
name|NS
parameter_list|)
function_decl|;
comment|/// addAddress - Add an address attribute to a die based on the location
comment|/// provided.
name|void
name|addAddress
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|/// addConstantValue - Add constant value entry in variable DIE.
name|bool
name|addConstantValue
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
name|bool
name|addConstantValue
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|ConstantInt
modifier|*
name|CI
parameter_list|,
name|bool
name|Unsigned
parameter_list|)
function_decl|;
comment|/// addConstantFPValue - Add constant value entry in variable DIE.
name|bool
name|addConstantFPValue
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
comment|/// addTemplateParams - Add template parameters in buffer.
name|void
name|addTemplateParams
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIArray
name|TParams
parameter_list|)
function_decl|;
comment|/// addRegisterOp - Add register operand.
name|void
name|addRegisterOp
parameter_list|(
name|DIE
modifier|*
name|TheDie
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// addRegisterOffset - Add register offset.
name|void
name|addRegisterOffset
parameter_list|(
name|DIE
modifier|*
name|TheDie
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|int64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// addComplexAddress - Start with the address based on the location provided,
comment|/// and generate the DWARF information necessary to find the actual variable
comment|/// (navigating the extra location information encoded in the type) based on
comment|/// the starting location.  Add the DWARF information to the die.
comment|///
name|void
name|addComplexAddress
parameter_list|(
name|DbgVariable
modifier|*
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|// FIXME: Should be reformulated in terms of addComplexAddress.
comment|/// addBlockByrefAddress - Start with the address based on the location
comment|/// provided, and generate the DWARF information necessary to find the
comment|/// actual Block variable (navigating the Block struct) based on the
comment|/// starting location.  Add the DWARF information to the die.  Obsolete,
comment|/// please use addComplexAddress instead.
comment|///
name|void
name|addBlockByrefAddress
parameter_list|(
name|DbgVariable
modifier|*
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|,
name|unsigned
name|Attribute
parameter_list|,
specifier|const
name|MachineLocation
modifier|&
name|Location
parameter_list|)
function_decl|;
comment|/// addVariableAddress - Add DW_AT_location attribute for a
comment|/// DbgVariable based on provided MachineLocation.
name|void
name|addVariableAddress
parameter_list|(
name|DbgVariable
modifier|*
modifier|&
name|DV
parameter_list|,
name|DIE
modifier|*
name|Die
parameter_list|,
name|MachineLocation
name|Location
parameter_list|)
function_decl|;
comment|/// addToContextOwner - Add Die into the list of its context owner's children.
name|void
name|addToContextOwner
parameter_list|(
name|DIE
modifier|*
name|Die
parameter_list|,
name|DIDescriptor
name|Context
parameter_list|)
function_decl|;
comment|/// addType - Add a new type attribute to the specified entity.
name|void
name|addType
parameter_list|(
name|DIE
modifier|*
name|Entity
parameter_list|,
name|DIType
name|Ty
parameter_list|)
function_decl|;
comment|/// getOrCreateNameSpace - Create a DIE for DINameSpace.
name|DIE
modifier|*
name|getOrCreateNameSpace
parameter_list|(
name|DINameSpace
name|NS
parameter_list|)
function_decl|;
comment|/// getOrCreateTypeDIE - Find existing DIE or create new DIE for the
comment|/// given DIType.
name|DIE
modifier|*
name|getOrCreateTypeDIE
parameter_list|(
name|DIType
name|Ty
parameter_list|)
function_decl|;
comment|/// getOrCreateTemplateTypeParameterDIE - Find existing DIE or create new DIE
comment|/// for the given DITemplateTypeParameter.
name|DIE
modifier|*
name|getOrCreateTemplateTypeParameterDIE
parameter_list|(
name|DITemplateTypeParameter
name|TP
parameter_list|)
function_decl|;
comment|/// getOrCreateTemplateValueParameterDIE - Find existing DIE or create new DIE
comment|/// for the given DITemplateValueParameter.
name|DIE
modifier|*
name|getOrCreateTemplateValueParameterDIE
parameter_list|(
name|DITemplateValueParameter
name|TVP
parameter_list|)
function_decl|;
comment|/// createDIEEntry - Creates a new DIEEntry to be a proxy for a debug
comment|/// information entry.
name|DIEEntry
modifier|*
name|createDIEEntry
parameter_list|(
name|DIE
modifier|*
name|Entry
parameter_list|)
function_decl|;
name|void
name|addPubTypes
parameter_list|(
name|DISubprogram
name|SP
parameter_list|)
function_decl|;
comment|/// constructTypeDIE - Construct basic type die from DIBasicType.
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIBasicType
name|BTy
parameter_list|)
function_decl|;
comment|/// constructTypeDIE - Construct derived type die from DIDerivedType.
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DIDerivedType
name|DTy
parameter_list|)
function_decl|;
comment|/// constructTypeDIE - Construct type DIE from DICompositeType.
name|void
name|constructTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
name|CTy
parameter_list|)
function_decl|;
comment|/// constructSubrangeDIE - Construct subrange DIE from DISubrange.
name|void
name|constructSubrangeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DISubrange
name|SR
parameter_list|,
name|DIE
modifier|*
name|IndexTy
parameter_list|)
function_decl|;
comment|/// constructArrayTypeDIE - Construct array type DIE from DICompositeType.
name|void
name|constructArrayTypeDIE
parameter_list|(
name|DIE
modifier|&
name|Buffer
parameter_list|,
name|DICompositeType
modifier|*
name|CTy
parameter_list|)
function_decl|;
comment|/// constructEnumTypeDIE - Construct enum type DIE from DIEnumerator.
name|DIE
modifier|*
name|constructEnumTypeDIE
parameter_list|(
name|DIEnumerator
name|ETy
parameter_list|)
function_decl|;
comment|/// createMemberDIE - Create new member DIE.
name|DIE
modifier|*
name|createMemberDIE
parameter_list|(
name|DIDerivedType
name|DT
parameter_list|)
function_decl|;
name|private
label|:
comment|// DIEValueAllocator - All DIEValues are allocated through this allocator.
name|BumpPtrAllocator
name|DIEValueAllocator
decl_stmt|;
name|DIEInteger
modifier|*
name|DIEIntegerOne
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

