begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- ABIInfo.h - ABI information access& encapsulation ---*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_CODEGEN_ABIINFO_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_ABIINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Type.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenTypes
decl_stmt|;
block|}
comment|// FIXME: All of this stuff should be part of the target interface
comment|// somehow. It is currently here because it is not clear how to factor
comment|// the targets to support this, since the Targets currently live in a
comment|// layer below types n'stuff.
comment|/// ABIArgInfo - Helper class to encapsulate information about how a
comment|/// specific C type should be passed to or returned from a function.
name|class
name|ABIArgInfo
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|/// Direct - Pass the argument directly using the normal converted LLVM
comment|/// type, or by coercing to another specified type stored in
comment|/// 'CoerceToType').  If an offset is specified (in UIntData), then the
comment|/// argument passed is offset by some number of bytes in the memory
comment|/// representation.
name|Direct
block|,
comment|/// Extend - Valid only for integer argument types. Same as 'direct'
comment|/// but also emit a zero/sign extension attribute.
name|Extend
block|,
comment|/// Indirect - Pass the argument indirectly via a hidden pointer
comment|/// with the specified alignment (0 indicates default alignment).
name|Indirect
block|,
comment|/// Ignore - Ignore the argument (treat as void). Useful for void and
comment|/// empty structs.
name|Ignore
block|,
comment|/// Expand - Only valid for aggregate argument types. The structure should
comment|/// be expanded into consecutive arguments for its constituent fields.
comment|/// Currently expand is only allowed on structures whose fields
comment|/// are all scalar types or are themselves expandable types.
name|Expand
block|,
name|KindFirst
init|=
name|Direct
block|,
name|KindLast
init|=
name|Expand
block|}
enum|;
name|private
label|:
name|Kind
name|TheKind
decl_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|TypeData
expr_stmt|;
name|unsigned
name|UIntData
decl_stmt|;
name|bool
name|BoolData0
decl_stmt|;
name|bool
name|BoolData1
decl_stmt|;
name|ABIArgInfo
argument_list|(
argument|Kind K
argument_list|,
argument|llvm::Type *TD=
literal|0
argument_list|,
argument|unsigned UI=
literal|0
argument_list|,
argument|bool B0 = false
argument_list|,
argument|bool B1 = false
argument_list|)
block|:
name|TheKind
argument_list|(
name|K
argument_list|)
operator|,
name|TypeData
argument_list|(
name|TD
argument_list|)
operator|,
name|UIntData
argument_list|(
name|UI
argument_list|)
operator|,
name|BoolData0
argument_list|(
name|B0
argument_list|)
operator|,
name|BoolData1
argument_list|(
argument|B1
argument_list|)
block|{}
name|public
operator|:
name|ABIArgInfo
argument_list|()
operator|:
name|TheKind
argument_list|(
name|Direct
argument_list|)
operator|,
name|TypeData
argument_list|(
literal|0
argument_list|)
operator|,
name|UIntData
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|ABIArgInfo
name|getDirect
argument_list|(
argument|llvm::Type *T =
literal|0
argument_list|,
argument|unsigned Offset =
literal|0
argument_list|)
block|{
return|return
name|ABIArgInfo
argument_list|(
name|Direct
argument_list|,
name|T
argument_list|,
name|Offset
argument_list|)
return|;
block|}
specifier|static
name|ABIArgInfo
name|getExtend
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|T
operator|=
literal|0
argument_list|)
block|{
return|return
name|ABIArgInfo
argument_list|(
name|Extend
argument_list|,
name|T
argument_list|,
literal|0
argument_list|)
return|;
block|}
specifier|static
name|ABIArgInfo
name|getIgnore
parameter_list|()
block|{
return|return
name|ABIArgInfo
argument_list|(
name|Ignore
argument_list|)
return|;
block|}
specifier|static
name|ABIArgInfo
name|getIndirect
parameter_list|(
name|unsigned
name|Alignment
parameter_list|,
name|bool
name|ByVal
init|=
name|true
parameter_list|,
name|bool
name|Realign
init|=
name|false
parameter_list|)
block|{
return|return
name|ABIArgInfo
argument_list|(
name|Indirect
argument_list|,
literal|0
argument_list|,
name|Alignment
argument_list|,
name|ByVal
argument_list|,
name|Realign
argument_list|)
return|;
block|}
specifier|static
name|ABIArgInfo
name|getExpand
parameter_list|()
block|{
return|return
name|ABIArgInfo
argument_list|(
name|Expand
argument_list|)
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|TheKind
return|;
block|}
name|bool
name|isDirect
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Direct
return|;
block|}
name|bool
name|isExtend
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Extend
return|;
block|}
name|bool
name|isIgnore
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Ignore
return|;
block|}
name|bool
name|isIndirect
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Indirect
return|;
block|}
name|bool
name|isExpand
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Expand
return|;
block|}
name|bool
name|canHaveCoerceToType
argument_list|()
specifier|const
block|{
return|return
name|TheKind
operator|==
name|Direct
operator|||
name|TheKind
operator|==
name|Extend
return|;
block|}
comment|// Direct/Extend accessors
name|unsigned
name|getDirectOffset
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isDirect
argument_list|()
operator|||
name|isExtend
argument_list|()
operator|)
operator|&&
literal|"Not a direct or extend kind"
argument_list|)
block|;
return|return
name|UIntData
return|;
block|}
name|llvm
operator|::
name|Type
operator|*
name|getCoerceToType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|canHaveCoerceToType
argument_list|()
operator|&&
literal|"Invalid kind!"
argument_list|)
block|;
return|return
name|TypeData
return|;
block|}
name|void
name|setCoerceToType
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|T
argument_list|)
block|{
name|assert
argument_list|(
name|canHaveCoerceToType
argument_list|()
operator|&&
literal|"Invalid kind!"
argument_list|)
expr_stmt|;
name|TypeData
operator|=
name|T
expr_stmt|;
block|}
comment|// Indirect accessors
name|unsigned
name|getIndirectAlign
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TheKind
operator|==
name|Indirect
operator|&&
literal|"Invalid kind!"
argument_list|)
block|;
return|return
name|UIntData
return|;
block|}
name|bool
name|getIndirectByVal
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TheKind
operator|==
name|Indirect
operator|&&
literal|"Invalid kind!"
argument_list|)
block|;
return|return
name|BoolData0
return|;
block|}
name|bool
name|getIndirectRealign
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|TheKind
operator|==
name|Indirect
operator|&&
literal|"Invalid kind!"
argument_list|)
block|;
return|return
name|BoolData1
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|/// ABIInfo - Target specific hooks for defining how a type should be
comment|/// passed or returned from functions.
name|class
name|ABIInfo
block|{
name|public
label|:
name|CodeGen
operator|::
name|CodeGenTypes
operator|&
name|CGT
expr_stmt|;
name|ABIInfo
argument_list|(
name|CodeGen
operator|::
name|CodeGenTypes
operator|&
name|cgt
argument_list|)
operator|:
name|CGT
argument_list|(
argument|cgt
argument_list|)
block|{}
name|virtual
operator|~
name|ABIInfo
argument_list|()
expr_stmt|;
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
expr_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|getVMContext
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|getTargetData
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|void
name|computeInfo
argument_list|(
name|CodeGen
operator|::
name|CGFunctionInfo
operator|&
name|FI
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// EmitVAArg - Emit the target dependent code to load a value of
comment|/// \arg Ty from the va_list pointed to by \arg VAListAddr.
comment|// FIXME: This is a gaping layering violation if we wanted to drop
comment|// the ABI information any lower than CodeGen. Of course, for
comment|// VAArg handling it has to be at this level; there is no way to
comment|// abstract this out.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitVAArg
argument_list|(
argument|llvm::Value *VAListAddr
argument_list|,
argument|QualType Ty
argument_list|,
argument|CodeGen::CodeGenFunction&CGF
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

