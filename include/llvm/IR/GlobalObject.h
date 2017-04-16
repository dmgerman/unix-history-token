begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/GlobalObject.h - Class to represent global objects -*- C++ -*-===//
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
comment|// This represents an independent object. That is, a function or a global
end_comment

begin_comment
comment|// variable, but not an alias.
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
name|LLVM_IR_GLOBALOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_GLOBALOBJECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Comdat
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|Metadata
decl_stmt|;
name|class
name|GlobalObject
range|:
name|public
name|GlobalValue
block|{
name|protected
operator|:
name|GlobalObject
argument_list|(
argument|Type *Ty
argument_list|,
argument|ValueTy VTy
argument_list|,
argument|Use *Ops
argument_list|,
argument|unsigned NumOps
argument_list|,
argument|LinkageTypes Linkage
argument_list|,
argument|const Twine&Name
argument_list|,
argument|unsigned AddressSpace =
literal|0
argument_list|)
operator|:
name|GlobalValue
argument_list|(
name|Ty
argument_list|,
name|VTy
argument_list|,
name|Ops
argument_list|,
name|NumOps
argument_list|,
name|Linkage
argument_list|,
name|Name
argument_list|,
name|AddressSpace
argument_list|)
block|,
name|ObjComdat
argument_list|(
argument|nullptr
argument_list|)
block|{
name|setGlobalValueSubClassData
argument_list|(
literal|0
argument_list|)
block|;   }
name|Comdat
operator|*
name|ObjComdat
block|;   enum
block|{
name|LastAlignmentBit
operator|=
literal|4
block|,
name|HasMetadataHashEntryBit
block|,
name|HasSectionHashEntryBit
block|,
name|GlobalObjectBits
block|,   }
block|;
specifier|static
specifier|const
name|unsigned
name|GlobalObjectSubClassDataBits
operator|=
name|GlobalValueSubClassDataBits
operator|-
name|GlobalObjectBits
block|;
name|private
operator|:
specifier|static
specifier|const
name|unsigned
name|AlignmentBits
operator|=
name|LastAlignmentBit
operator|+
literal|1
block|;
specifier|static
specifier|const
name|unsigned
name|AlignmentMask
operator|=
operator|(
literal|1
operator|<<
name|AlignmentBits
operator|)
operator|-
literal|1
block|;
specifier|static
specifier|const
name|unsigned
name|GlobalObjectMask
operator|=
operator|(
literal|1
operator|<<
name|GlobalObjectBits
operator|)
operator|-
literal|1
block|;
name|public
operator|:
name|GlobalObject
argument_list|(
specifier|const
name|GlobalObject
operator|&
argument_list|)
operator|=
name|delete
block|;
name|unsigned
name|getAlignment
argument_list|()
specifier|const
block|{
name|unsigned
name|Data
operator|=
name|getGlobalValueSubClassData
argument_list|()
block|;
name|unsigned
name|AlignmentData
operator|=
name|Data
operator|&
name|AlignmentMask
block|;
return|return
operator|(
literal|1u
operator|<<
name|AlignmentData
operator|)
operator|>>
literal|1
return|;
block|}
name|void
name|setAlignment
argument_list|(
argument|unsigned Align
argument_list|)
block|;
name|unsigned
name|getGlobalObjectSubClassData
argument_list|()
specifier|const
block|{
name|unsigned
name|ValueData
operator|=
name|getGlobalValueSubClassData
argument_list|()
block|;
return|return
name|ValueData
operator|>>
name|GlobalObjectBits
return|;
block|}
name|void
name|setGlobalObjectSubClassData
argument_list|(
argument|unsigned Val
argument_list|)
block|{
name|unsigned
name|OldData
operator|=
name|getGlobalValueSubClassData
argument_list|()
block|;
name|setGlobalValueSubClassData
argument_list|(
operator|(
name|OldData
operator|&
name|GlobalObjectMask
operator|)
operator||
operator|(
name|Val
operator|<<
name|GlobalObjectBits
operator|)
argument_list|)
block|;
name|assert
argument_list|(
name|getGlobalObjectSubClassData
argument_list|()
operator|==
name|Val
operator|&&
literal|"representation error"
argument_list|)
block|;   }
comment|/// Check if this global has a custom object file section.
comment|///
comment|/// This is more efficient than calling getSection() and checking for an empty
comment|/// string.
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
name|getGlobalValueSubClassData
argument_list|()
operator|&
operator|(
literal|1
operator|<<
name|HasSectionHashEntryBit
operator|)
return|;
block|}
comment|/// Get the custom section of this global if it has one.
comment|///
comment|/// If this global does not have a custom section, this will be empty and the
comment|/// default object file section (.text, .data, etc) will be used.
name|StringRef
name|getSection
argument_list|()
specifier|const
block|{
return|return
name|hasSection
argument_list|()
operator|?
name|getSectionImpl
argument_list|()
operator|:
name|StringRef
argument_list|()
return|;
block|}
comment|/// Change the section for this global.
comment|///
comment|/// Setting the section to the empty string tells LLVM to choose an
comment|/// appropriate default object file section.
name|void
name|setSection
argument_list|(
argument|StringRef S
argument_list|)
block|;
name|bool
name|hasComdat
argument_list|()
specifier|const
block|{
return|return
name|getComdat
argument_list|()
operator|!=
name|nullptr
return|;
block|}
specifier|const
name|Comdat
operator|*
name|getComdat
argument_list|()
specifier|const
block|{
return|return
name|ObjComdat
return|;
block|}
name|Comdat
operator|*
name|getComdat
argument_list|()
block|{
return|return
name|ObjComdat
return|;
block|}
name|void
name|setComdat
argument_list|(
argument|Comdat *C
argument_list|)
block|{
name|ObjComdat
operator|=
name|C
block|; }
comment|/// Check if this has any metadata.
name|bool
name|hasMetadata
argument_list|()
specifier|const
block|{
return|return
name|hasMetadataHashEntry
argument_list|()
return|;
block|}
comment|/// Get the current metadata attachments for the given kind, if any.
comment|///
comment|/// These functions require that the function have at most a single attachment
comment|/// of the given kind, and return \c nullptr if such an attachment is missing.
comment|/// @{
name|MDNode
operator|*
name|getMetadata
argument_list|(
argument|unsigned KindID
argument_list|)
specifier|const
block|;
name|MDNode
operator|*
name|getMetadata
argument_list|(
argument|StringRef Kind
argument_list|)
specifier|const
block|;
comment|/// @}
comment|/// Appends all attachments with the given ID to \c MDs in insertion order.
comment|/// If the global has no attachments with the given ID, or if ID is invalid,
comment|/// leaves MDs unchanged.
comment|/// @{
name|void
name|getMetadata
argument_list|(
argument|unsigned KindID
argument_list|,
argument|SmallVectorImpl<MDNode *>&MDs
argument_list|)
specifier|const
block|;
name|void
name|getMetadata
argument_list|(
argument|StringRef Kind
argument_list|,
argument|SmallVectorImpl<MDNode *>&MDs
argument_list|)
specifier|const
block|;
comment|/// @}
comment|/// Set a particular kind of metadata attachment.
comment|///
comment|/// Sets the given attachment to \c MD, erasing it if \c MD is \c nullptr or
comment|/// replacing it if it already exists.
comment|/// @{
name|void
name|setMetadata
argument_list|(
argument|unsigned KindID
argument_list|,
argument|MDNode *MD
argument_list|)
block|;
name|void
name|setMetadata
argument_list|(
argument|StringRef Kind
argument_list|,
argument|MDNode *MD
argument_list|)
block|;
comment|/// @}
comment|/// Add a metadata attachment.
comment|/// @{
name|void
name|addMetadata
argument_list|(
argument|unsigned KindID
argument_list|,
argument|MDNode&MD
argument_list|)
block|;
name|void
name|addMetadata
argument_list|(
argument|StringRef Kind
argument_list|,
argument|MDNode&MD
argument_list|)
block|;
comment|/// @}
comment|/// Appends all attachments for the global to \c MDs, sorting by attachment
comment|/// ID. Attachments with the same ID appear in insertion order.
name|void
name|getAllMetadata
argument_list|(
argument|SmallVectorImpl<std::pair<unsigned
argument_list|,
argument|MDNode *>>&MDs
argument_list|)
specifier|const
block|;
comment|/// Erase all metadata attachments with the given kind.
name|void
name|eraseMetadata
argument_list|(
argument|unsigned KindID
argument_list|)
block|;
comment|/// Copy metadata from Src, adjusting offsets by Offset.
name|void
name|copyMetadata
argument_list|(
argument|const GlobalObject *Src
argument_list|,
argument|unsigned Offset
argument_list|)
block|;
name|void
name|addTypeMetadata
argument_list|(
argument|unsigned Offset
argument_list|,
argument|Metadata *TypeID
argument_list|)
block|;
name|void
name|copyAttributesFrom
argument_list|(
argument|const GlobalValue *Src
argument_list|)
name|override
block|;
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|FunctionVal
operator|||
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|GlobalVariableVal
return|;
block|}
name|void
name|clearMetadata
argument_list|()
block|;
name|private
operator|:
name|void
name|setGlobalObjectFlag
argument_list|(
argument|unsigned Bit
argument_list|,
argument|bool Val
argument_list|)
block|{
name|unsigned
name|Mask
operator|=
literal|1
operator|<<
name|Bit
block|;
name|setGlobalValueSubClassData
argument_list|(
operator|(
operator|~
name|Mask
operator|&
name|getGlobalValueSubClassData
argument_list|()
operator|)
operator||
operator|(
name|Val
condition|?
name|Mask
else|:
literal|0u
operator|)
argument_list|)
block|;   }
name|bool
name|hasMetadataHashEntry
argument_list|()
specifier|const
block|{
return|return
name|getGlobalValueSubClassData
argument_list|()
operator|&
operator|(
literal|1
operator|<<
name|HasMetadataHashEntryBit
operator|)
return|;
block|}
name|void
name|setHasMetadataHashEntry
argument_list|(
argument|bool HasEntry
argument_list|)
block|{
name|setGlobalObjectFlag
argument_list|(
name|HasMetadataHashEntryBit
argument_list|,
name|HasEntry
argument_list|)
block|;   }
name|StringRef
name|getSectionImpl
argument_list|()
specifier|const
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
comment|// LLVM_IR_GLOBALOBJECT_H
end_comment

end_unit

