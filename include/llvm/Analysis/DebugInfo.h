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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
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
name|class
name|DbgDeclareInst
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// DIDescriptor - A thin wraper around MDNode to access encoded debug info.
comment|/// This should not be stored in a container, because underly MDNode may
comment|/// change in certain situations.
name|class
name|DIDescriptor
block|{
name|protected
label|:
name|MDNode
modifier|*
name|DbgNode
decl_stmt|;
name|StringRef
name|getStringField
argument_list|(
name|unsigned
name|Elt
argument_list|)
decl|const
decl_stmt|;
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
name|getNode
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
name|DbgNode
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|DIDescriptor
argument_list|(
name|MDNode
operator|*
name|N
argument_list|)
operator|:
name|DbgNode
argument_list|(
argument|N
argument_list|)
block|{}
name|bool
name|Verify
argument_list|()
specifier|const
block|{
return|return
name|DbgNode
operator|!=
literal|0
return|;
block|}
name|MDNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|DbgNode
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
comment|/// ValidDebugInfo - Return true if N represents valid debug info value.
specifier|static
name|bool
name|ValidDebugInfo
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|OptLevel
parameter_list|)
function_decl|;
comment|/// dump - print descriptor.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDerivedType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCompositeType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isBasicType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isVariable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSubprogram
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isGlobalVariable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isScope
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isFile
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isCompileUnit
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isNameSpace
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isLexicalBlock
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isSubrange
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEnumerator
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isGlobal
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
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
comment|/// DIScope - A base class for various scopes.
name|class
name|DIScope
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIScope
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
argument_list|)
block|{}
name|virtual
operator|~
name|DIScope
argument_list|()
block|{}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|;
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|;   }
block|;
comment|/// DICompileUnit - A wrapper for a compile unit.
name|class
name|DICompileUnit
operator|:
name|public
name|DIScope
block|{
name|public
operator|:
name|explicit
name|DICompileUnit
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
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
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|3
argument_list|)
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|StringRef
name|getProducer
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|5
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
name|StringRef
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|8
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
comment|/// DIFile - This is a wrapper for a file.
name|class
name|DIFile
operator|:
name|public
name|DIScope
block|{
name|public
operator|:
name|explicit
name|DIFile
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
argument_list|)
block|{
if|if
condition|(
name|DbgNode
operator|&&
operator|!
name|isFile
argument_list|()
condition|)
name|DbgNode
operator|=
literal|0
expr_stmt|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|1
argument_list|)
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
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
expr|}
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
argument_list|)
block|{}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|1
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
name|DIScope
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
block|,
name|FlagAppleBlock
operator|=
literal|1
operator|<<
literal|3
block|,
name|FlagBlockByrefStruct
operator|=
literal|1
operator|<<
literal|4
block|,
name|FlagVirtual
operator|=
literal|1
operator|<<
literal|5
block|,
name|FlagArtificial
operator|=
literal|1
operator|<<
literal|6
comment|// To identify artificial arguments in
comment|// a subroutine type. e.g. "this" in c++.
block|}
block|;
name|protected
operator|:
comment|// This ctor is used when the Tag has already been validated by a derived
comment|// ctor.
name|DIType
argument_list|(
name|MDNode
operator|*
name|N
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
argument_list|)
block|{}
name|public
operator|:
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
name|MDNode
operator|*
name|N
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
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|1
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|3
operator|)
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|3
operator|)
block|;
return|return
name|F
operator|.
name|getCompileUnit
argument_list|()
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
comment|// isAppleBlock - Return true if this is the Apple Blocks extension.
name|bool
name|isAppleBlockExtension
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagAppleBlock
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isBlockByrefStruct
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagBlockByrefStruct
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagVirtual
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isArtificial
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|FlagArtificial
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|DbgNode
operator|&&
operator|(
name|isBasicType
argument_list|()
operator|||
name|isDerivedType
argument_list|()
operator|||
name|isCompositeType
argument_list|()
operator|)
return|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getCompileUnit
argument_list|()
operator|.
name|getFilename
argument_list|()
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getCompileUnit
argument_list|()
operator|.
name|getDirectory
argument_list|()
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIType
argument_list|(
argument|N
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
name|MDNode
operator|*
name|N
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|)
operator|:
name|DIType
argument_list|(
argument|N
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIType
argument_list|(
argument|N
argument_list|,
argument|true
argument_list|,
argument|true
argument_list|)
block|{}
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
block|;
comment|/// replaceAllUsesWith - Replace all uses of debug info referenced by
comment|/// this descriptor. After this completes, the current debug info value
comment|/// is erased.
name|void
name|replaceAllUsesWith
argument_list|(
name|DIDescriptor
operator|&
name|D
argument_list|)
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
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDerivedType
argument_list|(
argument|N
argument_list|,
argument|true
argument_list|,
argument|true
argument_list|)
block|{
if|if
condition|(
name|N
operator|&&
operator|!
name|isCompositeType
argument_list|()
condition|)
name|DbgNode
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
name|DICompositeType
name|getContainingType
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompositeType
operator|>
operator|(
literal|12
operator|)
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
name|MDNode
operator|*
name|N
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
argument_list|)
block|{}
name|public
operator|:
name|virtual
operator|~
name|DIGlobal
argument_list|()
block|{}
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|2
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|3
argument_list|)
return|;
block|}
name|StringRef
name|getDisplayName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|StringRef
name|getLinkageName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|5
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|6
operator|)
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|6
operator|)
block|;
return|return
name|F
operator|.
name|getCompileUnit
argument_list|()
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
name|DIScope
block|{
name|public
operator|:
name|explicit
name|DISubprogram
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
argument_list|)
block|{}
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|2
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|3
argument_list|)
return|;
block|}
name|StringRef
name|getDisplayName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|4
argument_list|)
return|;
block|}
name|StringRef
name|getLinkageName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|5
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|6
operator|)
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|6
operator|)
block|;
return|return
name|F
operator|.
name|getCompileUnit
argument_list|()
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
name|StringRef
name|getReturnTypeName
argument_list|()
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
name|DCT
operator|.
name|Verify
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
name|getNode
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|T
operator|.
name|getName
argument_list|()
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
argument_list|()
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
name|unsigned
name|getVirtuality
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
name|unsigned
name|getVirtualIndex
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|12
argument_list|)
return|;
block|}
name|DICompositeType
name|getContainingType
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DICompositeType
operator|>
operator|(
literal|13
operator|)
return|;
block|}
name|unsigned
name|isArtificial
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|14
argument_list|)
return|;
block|}
name|unsigned
name|isOptimized
argument_list|()
specifier|const
block|;
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getCompileUnit
argument_list|()
operator|.
name|getFilename
argument_list|()
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|6
operator|)
block|;
return|return
name|F
operator|.
name|getFilename
argument_list|()
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getCompileUnit
argument_list|()
operator|.
name|getFilename
argument_list|()
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|6
operator|)
expr_stmt|;
return|return
name|F
operator|.
name|getDirectory
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Verify - Verify that a subprogram descriptor is well formed.
end_comment

begin_expr_stmt
name|bool
name|Verify
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// dump - print subprogram.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// describes - Return true if this subprogram provides debugging
end_comment

begin_comment
comment|/// information for the function F.
end_comment

begin_function_decl
name|bool
name|describes
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|/// DIGlobalVariable - This is a wrapper for a global variable.
end_comment

begin_decl_stmt
name|class
name|DIGlobalVariable
range|:
name|public
name|DIGlobal
block|{
name|public
operator|:
name|explicit
name|DIGlobalVariable
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIGlobal
argument_list|(
argument|N
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DIVariable - This is a wrapper for a variable (e.g. parameter, local,
end_comment

begin_comment
comment|/// global etc).
end_comment

begin_decl_stmt
name|class
name|DIVariable
range|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DIVariable
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
argument_list|)
block|{}
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|1
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
argument_list|)
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|3
operator|)
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|3
operator|)
block|;
return|return
name|F
operator|.
name|getCompileUnit
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Verify - Verify that a variable descriptor is well formed.
end_comment

begin_expr_stmt
name|bool
name|Verify
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// HasComplexAddr - Return true if the variable has a complex address.
end_comment

begin_expr_stmt
name|bool
name|hasComplexAddress
argument_list|()
specifier|const
block|{
return|return
name|getNumAddrElements
argument_list|()
operator|>
literal|0
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getNumAddrElements
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint64_t
name|getAddrElement
argument_list|(
name|unsigned
name|Idx
argument_list|)
decl|const
block|{
return|return
name|getUInt64Field
argument_list|(
name|Idx
operator|+
literal|6
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isBlockByrefVariable - Return true if the variable was declared as
end_comment

begin_comment
comment|/// a "__block" variable (Apple Blocks).
end_comment

begin_expr_stmt
name|bool
name|isBlockByrefVariable
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|.
name|isBlockByrefStruct
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isInlinedFnArgument - Return trule if this variable provides debugging
end_comment

begin_comment
comment|/// information for an inlined function arguments.
end_comment

begin_function_decl
name|bool
name|isInlinedFnArgument
parameter_list|(
specifier|const
name|Function
modifier|*
name|CurFn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// dump - print variable.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// DILexicalBlock - This is a wrapper for a lexical block.
end_comment

begin_decl_stmt
name|class
name|DILexicalBlock
range|:
name|public
name|DIScope
block|{
name|public
operator|:
name|explicit
name|DILexicalBlock
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
argument_list|)
block|{}
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|1
operator|)
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getContext
argument_list|()
operator|.
name|getDirectory
argument_list|()
return|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getContext
argument_list|()
operator|.
name|getFilename
argument_list|()
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
literal|2
argument_list|)
return|;
block|}
name|unsigned
name|getColumnNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|3
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// DINameSpace - A wrapper for a C++ style name space.
name|class
name|DINameSpace
operator|:
name|public
name|DIScope
block|{
name|public
operator|:
name|explicit
name|DINameSpace
argument_list|(
name|MDNode
operator|*
name|N
operator|=
literal|0
argument_list|)
operator|:
name|DIScope
argument_list|(
argument|N
argument_list|)
block|{}
name|DIScope
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|1
operator|)
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|getStringField
argument_list|(
literal|2
argument_list|)
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getContext
argument_list|()
operator|.
name|getDirectory
argument_list|()
return|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getContext
argument_list|()
operator|.
name|getFilename
argument_list|()
return|;
block|}
name|DICompileUnit
name|getCompileUnit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getVersion
argument_list|()
operator|==
name|llvm
operator|::
name|LLVMDebugVersion7
condition|)
return|return
name|getFieldAs
operator|<
name|DICompileUnit
operator|>
operator|(
literal|3
operator|)
return|;
name|DIFile
name|F
operator|=
name|getFieldAs
operator|<
name|DIFile
operator|>
operator|(
literal|3
operator|)
block|;
return|return
name|F
operator|.
name|getCompileUnit
argument_list|()
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
expr|}
block|;
comment|/// DILocation - This object holds location information. This object
comment|/// is not associated with any DWARF tag.
name|class
name|DILocation
operator|:
name|public
name|DIDescriptor
block|{
name|public
operator|:
name|explicit
name|DILocation
argument_list|(
name|MDNode
operator|*
name|N
argument_list|)
operator|:
name|DIDescriptor
argument_list|(
argument|N
argument_list|)
block|{ }
name|unsigned
name|getLineNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|0
argument_list|)
return|;
block|}
name|unsigned
name|getColumnNumber
argument_list|()
specifier|const
block|{
return|return
name|getUnsignedField
argument_list|(
literal|1
argument_list|)
return|;
block|}
name|DIScope
name|getScope
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DIScope
operator|>
operator|(
literal|2
operator|)
return|;
block|}
name|DILocation
name|getOrigLocation
argument_list|()
specifier|const
block|{
return|return
name|getFieldAs
operator|<
name|DILocation
operator|>
operator|(
literal|3
operator|)
return|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|getScope
argument_list|()
operator|.
name|getFilename
argument_list|()
return|;
block|}
name|StringRef
name|getDirectory
argument_list|()
specifier|const
block|{
return|return
name|getScope
argument_list|()
operator|.
name|getDirectory
argument_list|()
return|;
block|}
name|bool
name|Verify
argument_list|()
specifier|const
block|;   }
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
name|LLVMContext
operator|&
name|VMContext
block|;
name|Function
operator|*
name|DeclareFn
block|;
comment|// llvm.dbg.declare
name|Function
operator|*
name|ValueFn
block|;
comment|// llvm.dbg.value
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
expr|enum
name|ComplexAddrKind
block|{
name|OpPlus
operator|=
literal|1
block|,
name|OpDeref
block|}
block|;
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
argument|StringRef Filename
argument_list|,
argument|StringRef Directory
argument_list|,
argument|StringRef Producer
argument_list|,
argument|bool isMain = false
argument_list|,
argument|bool isOptimized = false
argument_list|,
argument|StringRef Flags =
literal|""
argument_list|,
argument|unsigned RunTimeVer =
literal|0
argument_list|)
block|;
comment|/// CreateFile -  Create a new descriptor for the specified file.
name|DIFile
name|CreateFile
argument_list|(
argument|StringRef Filename
argument_list|,
argument|StringRef Directory
argument_list|,
argument|DICompileUnit CU
argument_list|)
block|;
comment|/// CreateEnumerator - Create a single enumerator value.
name|DIEnumerator
name|CreateEnumerator
argument_list|(
argument|StringRef Name
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
argument|StringRef Name
argument_list|,
argument|DIFile F
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
comment|/// CreateBasicType - Create a basic type like int, float, etc.
name|DIBasicType
name|CreateBasicTypeEx
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|StringRef Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|Constant *SizeInBits
argument_list|,
argument|Constant *AlignInBits
argument_list|,
argument|Constant *OffsetInBits
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
argument|StringRef Name
argument_list|,
argument|DIFile F
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
comment|/// CreateDerivedType - Create a derived type like const qualified type,
comment|/// pointer, typedef, etc.
name|DIDerivedType
name|CreateDerivedTypeEx
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|StringRef Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|Constant *SizeInBits
argument_list|,
argument|Constant *AlignInBits
argument_list|,
argument|Constant *OffsetInBits
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
argument|StringRef Name
argument_list|,
argument|DIFile F
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
argument_list|,
argument|MDNode *ContainingType =
literal|0
argument_list|)
block|;
comment|/// CreateArtificialType - Create a new DIType with "artificial" flag set.
name|DIType
name|CreateArtificialType
argument_list|(
argument|DIType Ty
argument_list|)
block|;
comment|/// CreateCompositeType - Create a composite type like array, struct, etc.
name|DICompositeType
name|CreateCompositeTypeEx
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|StringRef Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNumber
argument_list|,
argument|Constant *SizeInBits
argument_list|,
argument|Constant *AlignInBits
argument_list|,
argument|Constant *OffsetInBits
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
argument|StringRef Name
argument_list|,
argument|StringRef DisplayName
argument_list|,
argument|StringRef LinkageName
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Ty
argument_list|,
argument|bool isLocalToUnit
argument_list|,
argument|bool isDefinition
argument_list|,
argument|unsigned VK =
literal|0
argument_list|,
argument|unsigned VIndex =
literal|0
argument_list|,
argument|DIType = DIType()
argument_list|,
argument|bool isArtificial =
literal|0
argument_list|,
argument|bool isOptimized = false
argument_list|)
block|;
comment|/// CreateSubprogramDefinition - Create new subprogram descriptor for the
comment|/// given declaration.
name|DISubprogram
name|CreateSubprogramDefinition
argument_list|(
name|DISubprogram
operator|&
name|SPDeclaration
argument_list|)
block|;
comment|/// CreateGlobalVariable - Create a new descriptor for the specified global.
name|DIGlobalVariable
name|CreateGlobalVariable
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|StringRef Name
argument_list|,
argument|StringRef DisplayName
argument_list|,
argument|StringRef LinkageName
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Ty
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
argument|StringRef Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Ty
argument_list|)
block|;
comment|/// CreateComplexVariable - Create a new descriptor for the specified
comment|/// variable which has a complex address expression for its address.
name|DIVariable
name|CreateComplexVariable
argument_list|(
argument|unsigned Tag
argument_list|,
argument|DIDescriptor Context
argument_list|,
argument|const std::string&Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNo
argument_list|,
argument|DIType Ty
argument_list|,
argument|SmallVector<Value *
argument_list|,
literal|9
argument|>&addr
argument_list|)
block|;
comment|/// CreateLexicalBlock - This creates a descriptor for a lexical block
comment|/// with the specified parent context.
name|DILexicalBlock
name|CreateLexicalBlock
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|unsigned Line =
literal|0
argument_list|,
argument|unsigned Col =
literal|0
argument_list|)
block|;
comment|/// CreateNameSpace - This creates new descriptor for a namespace
comment|/// with the specified parent context.
name|DINameSpace
name|CreateNameSpace
argument_list|(
argument|DIDescriptor Context
argument_list|,
argument|StringRef Name
argument_list|,
argument|DIFile F
argument_list|,
argument|unsigned LineNo
argument_list|)
block|;
comment|/// CreateLocation - Creates a debug info location.
name|DILocation
name|CreateLocation
argument_list|(
argument|unsigned LineNo
argument_list|,
argument|unsigned ColumnNo
argument_list|,
argument|DIScope S
argument_list|,
argument|DILocation OrigLoc
argument_list|)
block|;
comment|/// CreateLocation - Creates a debug info location.
name|DILocation
name|CreateLocation
argument_list|(
argument|unsigned LineNo
argument_list|,
argument|unsigned ColumnNo
argument_list|,
argument|DIScope S
argument_list|,
argument|MDNode *OrigLoc =
literal|0
argument_list|)
block|;
comment|/// InsertDeclare - Insert a new llvm.dbg.declare intrinsic call.
name|Instruction
operator|*
name|InsertDeclare
argument_list|(
argument|llvm::Value *Storage
argument_list|,
argument|DIVariable D
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// InsertDeclare - Insert a new llvm.dbg.declare intrinsic call.
name|Instruction
operator|*
name|InsertDeclare
argument_list|(
argument|llvm::Value *Storage
argument_list|,
argument|DIVariable D
argument_list|,
argument|Instruction *InsertBefore
argument_list|)
block|;
comment|/// InsertDbgValueIntrinsic - Insert a new llvm.dbg.value intrinsic call.
name|Instruction
operator|*
name|InsertDbgValueIntrinsic
argument_list|(
argument|llvm::Value *V
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|DIVariable D
argument_list|,
argument|BasicBlock *InsertAtEnd
argument_list|)
block|;
comment|/// InsertDbgValueIntrinsic - Insert a new llvm.dbg.value intrinsic call.
name|Instruction
operator|*
name|InsertDbgValueIntrinsic
argument_list|(
argument|llvm::Value *V
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|DIVariable D
argument_list|,
argument|Instruction *InsertBefore
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
block|;   }
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
comment|/// getDISubprogram - Find subprogram that is enclosing this scope.
name|DISubprogram
name|getDISubprogram
argument_list|(
name|MDNode
operator|*
name|Scope
argument_list|)
block|;
comment|/// getDICompositeType - Find underlying composite type.
name|DICompositeType
name|getDICompositeType
argument_list|(
argument|DIType T
argument_list|)
block|;
name|class
name|DebugInfoFinder
block|{
name|public
operator|:
comment|/// processModule - Process entire module and collect debug info
comment|/// anchors.
name|void
name|processModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|private
operator|:
comment|/// processType - Process DIType.
name|void
name|processType
argument_list|(
argument|DIType DT
argument_list|)
block|;
comment|/// processLexicalBlock - Process DILexicalBlock.
name|void
name|processLexicalBlock
argument_list|(
argument|DILexicalBlock LB
argument_list|)
block|;
comment|/// processSubprogram - Process DISubprogram.
name|void
name|processSubprogram
argument_list|(
argument|DISubprogram SP
argument_list|)
block|;
comment|/// processDeclare - Process DbgDeclareInst.
name|void
name|processDeclare
argument_list|(
name|DbgDeclareInst
operator|*
name|DDI
argument_list|)
block|;
comment|/// processLocation - Process DILocation.
name|void
name|processLocation
argument_list|(
argument|DILocation Loc
argument_list|)
block|;
comment|/// addCompileUnit - Add compile unit into CUs.
name|bool
name|addCompileUnit
argument_list|(
argument|DICompileUnit CU
argument_list|)
block|;
comment|/// addGlobalVariable - Add global variable into GVs.
name|bool
name|addGlobalVariable
argument_list|(
argument|DIGlobalVariable DIG
argument_list|)
block|;
comment|// addSubprogram - Add subprgoram into SPs.
name|bool
name|addSubprogram
argument_list|(
argument|DISubprogram SP
argument_list|)
block|;
comment|/// addType - Add type into Tys.
name|bool
name|addType
argument_list|(
argument|DIType DT
argument_list|)
block|;
name|public
operator|:
typedef|typedef
name|SmallVector
operator|<
name|MDNode
operator|*
operator|,
literal|8
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|compile_unit_begin
argument_list|()
block|{
return|return
name|CUs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|compile_unit_end
argument_list|()
block|{
return|return
name|CUs
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|subprogram_begin
argument_list|()
block|{
return|return
name|SPs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|subprogram_end
argument_list|()
block|{
return|return
name|SPs
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|global_variable_begin
argument_list|()
block|{
return|return
name|GVs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|global_variable_end
argument_list|()
block|{
return|return
name|GVs
operator|.
name|end
argument_list|()
return|;
block|}
name|iterator
name|type_begin
argument_list|()
block|{
return|return
name|TYs
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|type_end
argument_list|()
block|{
return|return
name|TYs
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|compile_unit_count
argument_list|()
block|{
return|return
name|CUs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|global_variable_count
argument_list|()
block|{
return|return
name|GVs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|subprogram_count
argument_list|()
block|{
return|return
name|SPs
operator|.
name|size
argument_list|()
return|;
block|}
name|unsigned
name|type_count
argument_list|()
block|{
return|return
name|TYs
operator|.
name|size
argument_list|()
return|;
block|}
name|private
operator|:
name|SmallVector
operator|<
name|MDNode
operator|*
block|,
literal|8
operator|>
name|CUs
block|;
comment|// Compile Units
name|SmallVector
operator|<
name|MDNode
operator|*
block|,
literal|8
operator|>
name|SPs
block|;
comment|// Subprograms
name|SmallVector
operator|<
name|MDNode
operator|*
block|,
literal|8
operator|>
name|GVs
block|;
comment|// Global Variables;
name|SmallVector
operator|<
name|MDNode
operator|*
block|,
literal|8
operator|>
name|TYs
block|;
comment|// Types
name|SmallPtrSet
operator|<
name|MDNode
operator|*
block|,
literal|64
operator|>
name|NodesSeen
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

