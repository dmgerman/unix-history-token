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
file|"llvm/IR/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DerivedTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Comdat
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|GlobalObject
range|:
name|public
name|GlobalValue
block|{
name|GlobalObject
argument_list|(
argument|const GlobalObject&
argument_list|)
name|LLVM_DELETED_FUNCTION
block|;
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
name|std
operator|::
name|string
name|Section
block|;
comment|// Section to emit this into, empty means default
name|Comdat
operator|*
name|ObjComdat
block|;
specifier|static
specifier|const
name|unsigned
name|AlignmentBits
operator|=
literal|5
block|;
specifier|static
specifier|const
name|unsigned
name|GlobalObjectSubClassDataBits
operator|=
name|GlobalValueSubClassDataBits
operator|-
name|AlignmentBits
block|;
name|private
operator|:
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
name|public
operator|:
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
block|;
name|void
name|setGlobalObjectSubClassData
argument_list|(
argument|unsigned Val
argument_list|)
block|;
name|bool
name|hasSection
argument_list|()
specifier|const
block|{
return|return
operator|!
name|StringRef
argument_list|(
name|getSection
argument_list|()
argument_list|)
operator|.
name|empty
argument_list|()
return|;
block|}
specifier|const
name|char
operator|*
name|getSection
argument_list|()
specifier|const
block|{
return|return
name|Section
operator|.
name|c_str
argument_list|()
return|;
block|}
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
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

