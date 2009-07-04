begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- llvm/Analysis/DebugInfo.h - Debug Information Helpers --*- C++ -*-===//
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
comment|// This file defines a bunch of datatypes that are useful for creating and
end_comment

begin_comment
comment|// walking debug info in LLVM IR form. They essentially provide wrappers around
end_comment

begin_comment
comment|// the information in the global variables that's needed when constructing the
end_comment

begin_comment
comment|// DWARF information.
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
name|LLVM_ANALYSIS_DEBUGINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_DEBUGINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
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
name|GlobalVariable
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
struct_decl|struct
name|DbgStopPointInst
struct_decl|;
struct_decl|struct
name|DbgDeclareInst
struct_decl|;
struct_decl|struct
name|DbgFuncStartInst
struct_decl|;
struct_decl|struct
name|DbgRegionStartInst
struct_decl|;
struct_decl|struct
name|DbgRegionEndInst
struct_decl|;
name|class
name|DebugLoc
decl_stmt|;
name|class
name|DebugLocTracker
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DIDescriptor
block|{
name|protected
label|:
name|GlobalVariable
modifier|*
name|DbgGV
decl_stmt|;
comment|/// DIDescriptor constructor.  If the specified GV is non-null, this checks
comment|/// to make sure that the tag in the descriptor matches 'RequiredTag'.  If
comment|/// not, the debug info is corrupt and we ignore it.
name|DIDescriptor
argument_list|(
argument|GlobalVariable *GV
argument_list|,
argument|unsigned RequiredTag
argument_list|)
empty_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getStringField
argument_list|(
argument|unsigned Elt
argument_list|,
argument|std::string&Result
argument_list|)
specifier|const
expr_stmt|;
name|unsigned
name|getUnsignedField
argument_list|(
name|unsigned
name|Elt
argument_list|)
decl|const
block|{
return|return
operator|(
name|unsigned
operator|)
name|getUInt64Field
argument_list|(
name|Elt
argument_list|)
return|;
block|}
name|uint64_t
name|getUInt64Field
argument_list|(
name|unsigned
name|Elt
argument_list|)
decl|const
decl_stmt|;
name|DIDescriptor
name|getDescriptorField
argument_list|(
name|unsigned
name|Elt
argument_list|)
decl|const
decl_stmt|;
name|template
operator|<
name|typename
name|DescTy
operator|>
name|DescTy
name|getFieldAs
argument_list|(
argument|unsigned Elt
argument_list|)
specifier|const
block|{
return|return
name|DescTy
argument_list|(
name|getDescriptorField
argument_list|(
name|Elt
argument_list|)
operator|.
name|getGV
argument_list|()
argument_list|)
return|;
block|}
name|GlobalVariable
modifier|*
name|getGlobalVariableField
argument_list|(
name|unsigned
name|Elt
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|explicit
name|DIDescriptor
argument_list|()
operator|:
name|DbgGV
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|DIDescriptor
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
operator|:
name|DbgGV
argument_list|(
argument|GV
argument_list|)
block|{}
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|DbgGV
operator|==
literal|0
return|;
block|}
name|GlobalVariable
operator|*
name|getGV
argument_list|()
specifier|const
block|{
return|return
name|DbgGV
return|;
block|}
name|unsigned
name|getVersion
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|0
argument_list|)
operator|&
name|LLVMDebugVersionMask
return|;
block|}
name|unsigned
name|getTag
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|0
argument_list|)
operator|&
operator|~
name|LLVMDebugVersionMask
return|;
block|}
comment|/// ValidDebugInfo - Return true if V represents valid debug info value.
specifier|static
name|bool
name|ValidDebugInfo
argument_list|(
name|Value
operator|*
name|V
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
comment|/// dump - print descriptor.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// DISubrange - This is used to represent ranges, for array bounds.
name|class
name|DISubrange
range|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DISubrange
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_subrange_type
argument_list|)
block|{}
name|int64_t
name|getLo
argument_list|()
specifier|const
block|{
return|return
operator|(
name|int64_t
operator|)
name|getUInt64Field
argument_list|(
literal|1
argument_list|)
return|;
block|}
name|int64_t
name|getHi
argument_list|()
specifier|const
block|{
return|return
operator|(
name|int64_t
operator|)
name|getUInt64Field
argument_list|(
literal|2
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// DIArray - This descriptor holds an array of descriptors.
name|class
name|DIArray
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIArray
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|)
block|{}
name|unsigned
name|getNumElements
argument_list|()
specifier|const
block|;
name|DIDescriptor
name|getElement
argument_list|(
argument|unsigned Idx
argument_list|)
specifier|const
block|{
return|return
name|getDescriptorField
argument_list|(
name|Idx
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// DICompileUnit - A wrapper for a compile unit.
name|class
name|DICompileUnit
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DICompileUnit
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_compile_unit
argument_list|)
block|{}
name|unsigned
name|getLanguage
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getFilename
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|3
argument_list|,
name|F
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getDirectory
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|4
argument_list|,
name|F
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getProducer
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|5
argument_list|,
name|F
argument_list|)
return|;
block|}
comment|/// isMain - Each input file is encoded as a separate compile unit in LLVM
comment|/// debugging information output. However, many target specific tool chains
comment|/// prefer to encode only one compile unit in an object file. In this
comment|/// situation, the LLVM code generator will include  debugging information
comment|/// entities in the compile unit that is marked as main compile unit. The
comment|/// code generator accepts maximum one main compile unit per module. If a
comment|/// module does not contain any main compile unit then the code generator
comment|/// will emit multiple compile units in the output object file.
name|bool
name|isMain
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|6
argument_list|)
return|;
block|}
name|bool
name|isOptimized
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|7
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getFlags
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|8
argument_list|,
name|F
argument_list|)
return|;
block|}
name|unsigned
name|getRunTimeVersion
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|9
argument_list|)
return|;
block|}
comment|/// Verify - Verify that a compile unit is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
comment|/// dump - print compile unit.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIEnumerator - A wrapper for an enumerator (e.g. X and Y in 'enum {X,Y}').
comment|/// FIXME: it seems strange that this doesn't have either a reference to the
comment|/// type/precision or a file/line pair for location info.
name|class
name|DIEnumerator
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIEnumerator
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_enumerator
argument_list|)
block|{}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|1
argument_list|,
name|F
argument_list|)
return|;
block|}
name|uint64_t
name|getEnumValue
argument_list|()
specifier|const
block|{
return|return
name|getUInt64Field
argument_list|(
literal|2
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// DIType - This is a wrapper for a type.
comment|/// FIXME: Types should be factored much better so that CV qualifiers and
comment|/// others do not require a huge and empty descriptor full of zeros.
name|class
name|DIType
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
expr|enum
block|{
name|FlagPrivate
operator|=
literal|1
operator|<<
literal|0
block|,
name|FlagProtected
operator|=
literal|1
operator|<<
literal|1
block|,
name|FlagFwdDecl
operator|=
literal|1
operator|<<
literal|2
block|}
block|;
name|protected
operator|:
name|DIType
argument_list|(
argument|GlobalVariable *GV
argument_list|,
argument|unsigned Tag
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|Tag
argument_list|)
block|{}
comment|// This ctor is used when the Tag has already been validated by a derived
comment|// ctor.
name|DIType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|)
block|{}
name|public
operator|:
comment|/// isDerivedType - Return true if the specified tag is legal for
comment|/// DIDerivedType.
specifier|static
name|bool
name|isDerivedType
argument_list|(
argument|unsigned TAG
argument_list|)
block|;
comment|/// isCompositeType - Return true if the specified tag is legal for
comment|/// DICompositeType.
specifier|static
name|bool
name|isCompositeType
argument_list|(
argument|unsigned TAG
argument_list|)
block|;
comment|/// isBasicType - Return true if the specified tag is legal for
comment|/// DIBasicType.
specifier|static
name|bool
name|isBasicType
argument_list|(
argument|unsigned TAG
argument_list|)
block|{
return|return
name|TAG
operator|==
name|dwarf
operator|::
name|DW_TAG_base_type
return|;
block|}
comment|/// Verify - Verify that a type descriptor is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
name|public
operator|:
name|explicit
name|DIType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
name|explicit
name|DIType
argument_list|()
block|{}
name|virtual
operator|~
name|DIType
argument_list|()
block|{}
name|DIDescriptor
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getDescriptorField
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
argument_list|,
name|F
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|3
operator|)
return|;
block|}
name|unsigned
name|getLineNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|uint64_t
name|getSizeInBits
argument_list|()
specifier|const
block|{
return|return
name|getUInt64Field
argument_list|(
literal|5
argument_list|)
return|;
block|}
name|uint64_t
name|getAlignInBits
argument_list|()
specifier|const
block|{
return|return
name|getUInt64Field
argument_list|(
literal|6
argument_list|)
return|;
block|}
comment|// FIXME: Offset is only used for DW_TAG_member nodes.  Making every type
comment|// carry this is just plain insane.
name|uint64_t
name|getOffsetInBits
argument_list|()
specifier|const
block|{
return|return
name|getUInt64Field
argument_list|(
literal|7
argument_list|)
return|;
block|}
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|8
argument_list|)
return|;
block|}
name|bool
name|isPrivate
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagPrivate
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isProtected
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagProtected
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isForwardDecl
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagFwdDecl
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// dump - print type.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIBasicType - A basic type, like 'int' or 'float'.
name|class
name|DIBasicType
operator|:
name|public
name|DIType
block|{
name|public
operator|:
name|explicit
name|DIBasicType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
operator|:
name|DIType
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_base_type
argument_list|)
block|{}
name|unsigned
name|getEncoding
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|9
argument_list|)
return|;
block|}
comment|/// dump - print basic type.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIDerivedType - A simple derived type, like a const qualified type,
comment|/// a typedef, a pointer or reference, etc.
name|class
name|DIDerivedType
operator|:
name|public
name|DIType
block|{
name|protected
operator|:
name|explicit
name|DIDerivedType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|)
operator|:
name|DIType
argument_list|(
argument|GV
argument_list|,
argument|true
argument_list|,
argument|true
argument_list|)
block|{}
name|public
operator|:
name|explicit
name|DIDerivedType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
operator|:
name|DIType
argument_list|(
argument|GV
argument_list|,
argument|true
argument_list|,
argument|true
argument_list|)
block|{
if|if
condition|(
name|GV
operator|&&
operator|!
name|isDerivedType
argument_list|(
name|getTag
argument_list|()
argument_list|)
condition|)
name|DbgGV
operator|=
literal|0
expr_stmt|;
block|}
name|DIType
name|getTypeDerivedFrom
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIType
operator|>
operator|(
literal|9
operator|)
return|;
block|}
comment|/// getOriginalTypeSize - If this type is derived from a base type then
comment|/// return base type size.
name|uint64_t
name|getOriginalTypeSize
argument_list|()
specifier|const
block|;
comment|/// dump - print derived type.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DICompositeType - This descriptor holds a type that can refer to multiple
comment|/// other types, like a function or struct.
comment|/// FIXME: Why is this a DIDerivedType??
name|class
name|DICompositeType
operator|:
name|public
name|DIDerivedType
block|{
name|public
operator|:
name|explicit
name|DICompositeType
argument_list|(
name|GlobalVariable
operator|*
name|GV
argument_list|)
operator|:
name|DIDerivedType
argument_list|(
argument|GV
argument_list|,
argument|true
argument_list|,
argument|true
argument_list|)
block|{
if|if
condition|(
name|GV
operator|&&
operator|!
name|isCompositeType
argument_list|(
name|getTag
argument_list|()
argument_list|)
condition|)
name|DbgGV
operator|=
literal|0
expr_stmt|;
block|}
name|DIArray
name|getTypeArray
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIArray
operator|>
operator|(
literal|10
operator|)
return|;
block|}
name|unsigned
name|getRunTimeLang
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|11
argument_list|)
return|;
block|}
comment|/// Verify - Verify that a composite type descriptor is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
comment|/// dump - print composite type.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIGlobal - This is a common class for global variables and subprograms.
name|class
name|DIGlobal
operator|:
name|public
name|DIDescriptor
block|{
name|protected
operator|:
name|explicit
name|DIGlobal
argument_list|(
argument|GlobalVariable *GV
argument_list|,
argument|unsigned RequiredTag
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|RequiredTag
argument_list|)
block|{}
comment|/// isSubprogram - Return true if the specified tag is legal for
comment|/// DISubprogram.
specifier|static
name|bool
name|isSubprogram
argument_list|(
argument|unsigned TAG
argument_list|)
block|{
return|return
name|TAG
operator|==
name|dwarf
operator|::
name|DW_TAG_subprogram
return|;
block|}
comment|/// isGlobalVariable - Return true if the specified tag is legal for
comment|/// DIGlobalVariable.
specifier|static
name|bool
name|isGlobalVariable
argument_list|(
argument|unsigned TAG
argument_list|)
block|{
return|return
name|TAG
operator|==
name|dwarf
operator|::
name|DW_TAG_variable
return|;
block|}
name|public
operator|:
name|virtual
operator|~
name|DIGlobal
argument_list|()
block|{}
name|DIDescriptor
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getDescriptorField
argument_list|(
literal|2
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|3
argument_list|,
name|F
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getDisplayName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|4
argument_list|,
name|F
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getLinkageName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|5
argument_list|,
name|F
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|6
operator|)
return|;
block|}
name|unsigned
name|getLineNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|7
argument_list|)
return|;
block|}
name|DIType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIType
operator|>
operator|(
literal|8
operator|)
return|;
block|}
comment|/// isLocalToUnit - Return true if this subprogram is local to the current
comment|/// compile unit, like 'static' in C.
name|unsigned
name|isLocalToUnit
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|9
argument_list|)
return|;
block|}
name|unsigned
name|isDefinition
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|10
argument_list|)
return|;
block|}
comment|/// dump - print global.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DISubprogram - This is a wrapper for a subprogram (e.g. a function).
name|class
name|DISubprogram
operator|:
name|public
name|DIGlobal
block|{
name|public
operator|:
name|explicit
name|DISubprogram
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIGlobal
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_subprogram
argument_list|)
block|{}
name|DICompositeType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompositeType
operator|>
operator|(
literal|8
operator|)
return|;
block|}
comment|/// getReturnTypeName - Subprogram return types are encoded either as
comment|/// DIType or as DICompositeType.
specifier|const
name|std
operator|::
name|string
operator|&
name|getReturnTypeName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
name|DICompositeType
name|DCT
argument_list|(
name|getFieldAs
operator|<
name|DICompositeType
operator|>
operator|(
literal|8
operator|)
argument_list|)
block|;
if|if
condition|(
operator|!
name|DCT
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|DIArray
name|A
init|=
name|DCT
operator|.
name|getTypeArray
argument_list|()
decl_stmt|;
name|DIType
name|T
argument_list|(
name|A
operator|.
name|getElement
argument_list|(
literal|0
argument_list|)
operator|.
name|getGV
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|T
operator|.
name|getName
argument_list|(
name|F
argument_list|)
return|;
block|}
name|DIType
name|T
argument_list|(
name|getFieldAs
operator|<
name|DIType
operator|>
operator|(
literal|8
operator|)
argument_list|)
decl_stmt|;
return|return
name|T
operator|.
name|getName
argument_list|(
name|F
argument_list|)
return|;
block|}
comment|/// Verify - Verify that a subprogram descriptor is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
comment|/// dump - print subprogram.
name|void
name|dump
argument_list|()
specifier|const
block|;
comment|/// describes - Return true if this subprogram provides debugging
comment|/// information for the function F.
name|bool
name|describes
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
block|;   }
block|;
comment|/// DIGlobalVariable - This is a wrapper for a global variable.
name|class
name|DIGlobalVariable
operator|:
name|public
name|DIGlobal
block|{
name|public
operator|:
name|explicit
name|DIGlobalVariable
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIGlobal
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_variable
argument_list|)
block|{}
name|GlobalVariable
operator|*
name|getGlobal
argument_list|()
specifier|const
block|{
return|return
name|getGlobalVariableField
argument_list|(
literal|11
argument_list|)
return|;
block|}
comment|/// Verify - Verify that a global variable descriptor is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
comment|/// dump - print global variable.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIVariable - This is a wrapper for a variable (e.g. parameter, local,
comment|/// global etc).
name|class
name|DIVariable
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIVariable
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|)
block|{
if|if
condition|(
name|GV
operator|&&
operator|!
name|isVariable
argument_list|(
name|getTag
argument_list|()
argument_list|)
condition|)
name|DbgGV
operator|=
literal|0
expr_stmt|;
block|}
name|DIDescriptor
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getDescriptorField
argument_list|(
literal|1
argument_list|)
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|(
argument|std::string&F
argument_list|)
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
argument_list|,
name|F
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|3
operator|)
return|;
block|}
name|unsigned
name|getLineNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|DIType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIType
operator|>
operator|(
literal|5
operator|)
return|;
block|}
comment|/// isVariable - Return true if the specified tag is legal for DIVariable.
specifier|static
name|bool
name|isVariable
argument_list|(
argument|unsigned Tag
argument_list|)
block|;
comment|/// Verify - Verify that a variable descriptor is well formed.
name|bool
name|Verify
argument_list|()
specifier|const
block|;
comment|/// dump - print variable.
name|void
name|dump
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DIBlock - This is a wrapper for a block (e.g. a function, scope, etc).
name|class
name|DIBlock
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIBlock
argument_list|(
name|GlobalVariable
operator|*
name|GV
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|GV
argument_list|,
argument|dwarf::DW_TAG_lexical_block
argument_list|)
block|{}
name|DIDescriptor
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getDescriptorField
argument_list|(
literal|1
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// DIFactory - This object assists with the construction of the various
comment|/// descriptors.
name|class
name|DIFactory
block|{
name|Module
operator|&
name|M
block|;
comment|// Cached values for uniquing and faster lookups.
specifier|const
name|Type
operator|*
name|EmptyStructPtr
block|;
comment|// "{}*".
name|Function
operator|*
name|StopPointFn
block|;
comment|// llvm.dbg.stoppoint
name|Function
operator|*
name|FuncStartFn
block|;
comment|// llvm.dbg.func.start
name|Function
operator|*
name|RegionStartFn
block|;
comment|// llvm.dbg.region.start
name|Function
operator|*
name|RegionEndFn
block|;
comment|// llvm.dbg.region.end
name|Function
operator|*
name|DeclareFn
block|;
comment|// llvm.dbg.declare
name|StringMap
operator|<
name|Constant
operator|*
operator|>
name|StringCache
block|;
name|DenseMap
operator|<
name|Constant
operator|*
block|,
name|DIDescriptor
operator|>
name|SimpleConstantCache
block|;
name|DIFactory
argument_list|(
specifier|const
name|DIFactory
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|DIFactory
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|public
operator|:
name|explicit
name|DIFactory
argument_list|(
name|Module
operator|&
name|m
argument_list|)
block|;
comment|/// GetOrCreateArray - Create an descriptor for an array of descriptors.
comment|/// This implicitly uniques the arrays created.
name|DIArray
name|GetOrCreateArray
argument_list|(
argument|DIDescriptor *Tys
argument_list|,
argument|unsigned NumTys
argument_list|)
block|;
comment|/// GetOrCreateSubrange - Create a descriptor for a value range.  This
comment|/// implicitly uniques the values returned.
name|DISubrange
name|GetOrCreateSubrange
argument_list|(
argument|int64_t Lo
argument_list|,
argument|int64_t Hi
argument_list|)
block|;
comment|/// CreateCompileUnit - Create a new descriptor for the specified compile
comment|/// unit.
name|DICompileUnit
name|CreateCompileUnit
argument_list|(
argument|unsigned LangID
argument_list|,
argument|const std::string&Filename
argument_list|,
argument|const std::string&Directory
argument_list|,
argument|const std::string&Producer
argument_list|,
argument|bool isMain = false
argument_list|,
argument|bool isOptimized = false
argument_list|,
argument|const char *Flags =
literal|""
argument_list|,
argument|unsigned RunTimeVer =
literal|0
argument_list|)
block|;
comment|/// CreateEnumerator - Create a single enumerator value.
name|DIEnumerator
name|CreateEnumerator
argument_list|(
argument|const std::string&Name
argument_list|,
argument|uint64_t Val
argument_list|)
block|;
comment|/// CreateBasicType - Create a basic type like int, float, etc.
name|DIBasicType
name|CreateBasicType
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|uint64_t SizeInBits
argument_list|,
argument|uint64_t AlignInBits
argument_list|,
argument|uint64_t OffsetInBits
argument_list|,
argument|unsigned Flags
argument_list|,
argument|unsigned Encoding
argument_list|)
block|;
comment|/// CreateDerivedType - Create a derived type like const qualified type,
comment|/// pointer, typedef, etc.
name|DIDerivedType
name|CreateDerivedType
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|uint64_t SizeInBits
argument_list|,
argument|uint64_t AlignInBits
argument_list|,
argument|uint64_t OffsetInBits
argument_list|,
argument|unsigned Flags
argument_list|,
argument|DIType DerivedFrom
argument_list|)
block|;
comment|/// CreateCompositeType - Create a composite type like array, struct, etc.
name|DICompositeType
name|CreateCompositeType
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|uint64_t SizeInBits
argument_list|,
argument|uint64_t AlignInBits
argument_list|,
argument|uint64_t OffsetInBits
argument_list|,
argument|unsigned Flags
argument_list|,
argument|DIType DerivedFrom
argument_list|,
argument|DIArray Elements
argument_list|,
argument|unsigned RunTimeLang =
literal|0
argument_list|)
block|;
comment|/// CreateSubprogram - Create a new descriptor for the specified subprogram.
comment|/// See comments in DISubprogram for descriptions of these fields.
name|DISubprogram
name|CreateSubprogram
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|const std::string&DisplayName
argument_list|,
argument|const std::string&LinkageName
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Type
argument_list|,
argument|bool isLocalToUnit
argument_list|,
argument|bool isDefinition
argument_list|)
block|;
comment|/// CreateGlobalVariable - Create a new descriptor for the specified global.
name|DIGlobalVariable
name|CreateGlobalVariable
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|const std::string&DisplayName
argument_list|,
argument|const std::string&LinkageName
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Type
argument_list|,
argument|bool isLocalToUnit
argument_list|,
argument|bool isDefinition
argument_list|,
argument|llvm::GlobalVariable *GV
argument_list|)
block|;
comment|/// CreateVariable - Create a new descriptor for the specified variable.
name|DIVariable
name|CreateVariable
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|DICompileUnit CompileUnit
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Type
argument_list|)
block|;
comment|/// CreateBlock - This creates a descriptor for a lexical block with the
comment|/// specified parent context.
name|DIBlock
name|CreateBlock
argument_list|(
argument|DIDescriptor Context
argument_list|)
block|;
comment|/// InsertStopPoint - Create a new llvm.dbg.stoppoint intrinsic invocation,
comment|/// inserting it at the end of the specified basic block.
name|void
name|InsertStopPoint
argument_list|(
argument|DICompileUnit CU
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|unsigned ColNo
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|;
comment|/// InsertSubprogramStart - Create a new llvm.dbg.func.start intrinsic to
comment|/// mark the start of the specified subprogram.
name|void
name|InsertSubprogramStart
argument_list|(
argument|DISubprogram SP
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|;
comment|/// InsertRegionStart - Insert a new llvm.dbg.region.start intrinsic call to
comment|/// mark the start of a region for the specified scoping descriptor.
name|void
name|InsertRegionStart
argument_list|(
argument|DIDescriptor D
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|;
comment|/// InsertRegionEnd - Insert a new llvm.dbg.region.end intrinsic call to
comment|/// mark the end of a region for the specified scoping descriptor.
name|void
name|InsertRegionEnd
argument_list|(
argument|DIDescriptor D
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|;
comment|/// InsertDeclare - Insert a new llvm.dbg.declare intrinsic call.
name|void
name|InsertDeclare
argument_list|(
argument|llvm::Value *Storage
argument_list|,
argument|DIVariable D
argument_list|,
argument|BasicBlock *BB
argument_list|)
block|;
name|private
operator|:
name|Constant
operator|*
name|GetTagConstant
argument_list|(
argument|unsigned TAG
argument_list|)
block|;
name|Constant
operator|*
name|GetStringConstant
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
block|;
comment|/// getCastToEmpty - Return the descriptor as a Constant* with type '{}*'.
name|Constant
operator|*
name|getCastToEmpty
argument_list|(
argument|DIDescriptor D
argument_list|)
block|;   }
block|;
comment|/// Finds the stoppoint coressponding to this instruction, that is the
comment|/// stoppoint that dominates this instruction
specifier|const
name|DbgStopPointInst
operator|*
name|findStopPoint
argument_list|(
specifier|const
name|Instruction
operator|*
name|Inst
argument_list|)
block|;
comment|/// Finds the stoppoint corresponding to first real (non-debug intrinsic)
comment|/// instruction in this Basic Block, and returns the stoppoint for it.
specifier|const
name|DbgStopPointInst
operator|*
name|findBBStopPoint
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
block|;
comment|/// Finds the dbg.declare intrinsic corresponding to this value if any.
comment|/// It looks through pointer casts too.
specifier|const
name|DbgDeclareInst
operator|*
name|findDbgDeclare
argument_list|(
argument|const Value *V
argument_list|,
argument|bool stripCasts = true
argument_list|)
block|;
comment|/// Find the debug info descriptor corresponding to this global variable.
name|Value
operator|*
name|findDbgGlobalDeclare
argument_list|(
name|GlobalVariable
operator|*
name|V
argument_list|)
block|;
name|bool
name|getLocationInfo
argument_list|(
specifier|const
name|Value
operator|*
name|V
argument_list|,
name|std
operator|::
name|string
operator|&
name|DisplayName
argument_list|,
name|std
operator|::
name|string
operator|&
name|Type
argument_list|,
name|unsigned
operator|&
name|LineNo
argument_list|,
name|std
operator|::
name|string
operator|&
name|File
argument_list|,
name|std
operator|::
name|string
operator|&
name|Dir
argument_list|)
block|;
comment|/// CollectDebugInfoAnchors - Collect debugging information anchors.
name|void
name|CollectDebugInfoAnchors
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|SmallVector
operator|<
name|GlobalVariable
operator|*
argument_list|,
literal|2
operator|>
operator|&
name|CompileUnits
argument_list|,
name|SmallVector
operator|<
name|GlobalVariable
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|GlobalVars
argument_list|,
name|SmallVector
operator|<
name|GlobalVariable
operator|*
argument_list|,
literal|4
operator|>
operator|&
name|Subprograms
argument_list|)
block|;
comment|/// isValidDebugInfoIntrinsic - Return true if SPI is a valid debug
comment|/// info intrinsic.
name|bool
name|isValidDebugInfoIntrinsic
argument_list|(
argument|DbgStopPointInst&SPI
argument_list|,
argument|CodeGenOpt::Level OptLev
argument_list|)
block|;
comment|/// isValidDebugInfoIntrinsic - Return true if FSI is a valid debug
comment|/// info intrinsic.
name|bool
name|isValidDebugInfoIntrinsic
argument_list|(
argument|DbgFuncStartInst&FSI
argument_list|,
argument|CodeGenOpt::Level OptLev
argument_list|)
block|;
comment|/// isValidDebugInfoIntrinsic - Return true if RSI is a valid debug
comment|/// info intrinsic.
name|bool
name|isValidDebugInfoIntrinsic
argument_list|(
argument|DbgRegionStartInst&RSI
argument_list|,
argument|CodeGenOpt::Level OptLev
argument_list|)
block|;
comment|/// isValidDebugInfoIntrinsic - Return true if REI is a valid debug
comment|/// info intrinsic.
name|bool
name|isValidDebugInfoIntrinsic
argument_list|(
argument|DbgRegionEndInst&REI
argument_list|,
argument|CodeGenOpt::Level OptLev
argument_list|)
block|;
comment|/// isValidDebugInfoIntrinsic - Return true if DI is a valid debug
comment|/// info intrinsic.
name|bool
name|isValidDebugInfoIntrinsic
argument_list|(
argument|DbgDeclareInst&DI
argument_list|,
argument|CodeGenOpt::Level OptLev
argument_list|)
block|;
comment|/// ExtractDebugLocation - Extract debug location information
comment|/// from llvm.dbg.stoppoint intrinsic.
name|DebugLoc
name|ExtractDebugLocation
argument_list|(
name|DbgStopPointInst
operator|&
name|SPI
argument_list|,
name|DebugLocTracker
operator|&
name|DebugLocInfo
argument_list|)
block|;
comment|/// ExtractDebugLocation - Extract debug location information
comment|/// from llvm.dbg.func_start intrinsic.
name|DebugLoc
name|ExtractDebugLocation
argument_list|(
name|DbgFuncStartInst
operator|&
name|FSI
argument_list|,
name|DebugLocTracker
operator|&
name|DebugLocInfo
argument_list|)
block|;
comment|/// isInlinedFnStart - Return true if FSI is starting an inlined function.
name|bool
name|isInlinedFnStart
argument_list|(
name|DbgFuncStartInst
operator|&
name|FSI
argument_list|,
specifier|const
name|Function
operator|*
name|CurrentFn
argument_list|)
block|;
comment|/// isInlinedFnEnd - Return true if REI is ending an inlined function.
name|bool
name|isInlinedFnEnd
argument_list|(
name|DbgRegionEndInst
operator|&
name|REI
argument_list|,
specifier|const
name|Function
operator|*
name|CurrentFn
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

