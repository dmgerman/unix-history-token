begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenTypeCache.h - Commonly used LLVM types and info -*- C++ -*-===//
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
comment|// This structure provides a set of common types useful during IR emission.
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
name|LLVM_CLANG_LIB_CODEGEN_CODEGENTYPECACHE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CODEGENTYPECACHE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|IntegerType
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// This structure provides a set of types that are commonly used
comment|/// during IR emission.  It's initialized once in CodeGenModule's
comment|/// constructor and then copied around into new CodeGenFunctions.
struct|struct
name|CodeGenTypeCache
block|{
comment|/// void
name|llvm
operator|::
name|Type
operator|*
name|VoidTy
expr_stmt|;
comment|/// i8, i16, i32, and i64
name|llvm
operator|::
name|IntegerType
operator|*
name|Int8Ty
operator|,
operator|*
name|Int16Ty
operator|,
operator|*
name|Int32Ty
operator|,
operator|*
name|Int64Ty
expr_stmt|;
comment|/// float, double
name|llvm
operator|::
name|Type
operator|*
name|FloatTy
operator|,
operator|*
name|DoubleTy
expr_stmt|;
comment|/// int
name|llvm
operator|::
name|IntegerType
operator|*
name|IntTy
expr_stmt|;
comment|/// intptr_t, size_t, and ptrdiff_t, which we assume are the same size.
union|union
block|{
name|llvm
operator|::
name|IntegerType
operator|*
name|IntPtrTy
expr_stmt|;
name|llvm
operator|::
name|IntegerType
operator|*
name|SizeTy
expr_stmt|;
name|llvm
operator|::
name|IntegerType
operator|*
name|PtrDiffTy
expr_stmt|;
block|}
union|;
comment|/// void* in address space 0
union|union
block|{
name|llvm
operator|::
name|PointerType
operator|*
name|VoidPtrTy
expr_stmt|;
name|llvm
operator|::
name|PointerType
operator|*
name|Int8PtrTy
expr_stmt|;
block|}
union|;
comment|/// void** in address space 0
union|union
block|{
name|llvm
operator|::
name|PointerType
operator|*
name|VoidPtrPtrTy
expr_stmt|;
name|llvm
operator|::
name|PointerType
operator|*
name|Int8PtrPtrTy
expr_stmt|;
block|}
union|;
comment|/// void* in alloca address space
union|union
block|{
name|llvm
operator|::
name|PointerType
operator|*
name|AllocaVoidPtrTy
expr_stmt|;
name|llvm
operator|::
name|PointerType
operator|*
name|AllocaInt8PtrTy
expr_stmt|;
block|}
union|;
comment|/// The size and alignment of the builtin C type 'int'.  This comes
comment|/// up enough in various ABI lowering tasks to be worth pre-computing.
union|union
block|{
name|unsigned
name|char
name|IntSizeInBytes
decl_stmt|;
name|unsigned
name|char
name|IntAlignInBytes
decl_stmt|;
block|}
union|;
name|CharUnits
name|getIntSize
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|IntSizeInBytes
argument_list|)
return|;
block|}
name|CharUnits
name|getIntAlign
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|IntAlignInBytes
argument_list|)
return|;
block|}
comment|/// The width of a pointer into the generic address space.
name|unsigned
name|char
name|PointerWidthInBits
decl_stmt|;
comment|/// The size and alignment of a pointer into the generic address space.
union|union
block|{
name|unsigned
name|char
name|PointerAlignInBytes
decl_stmt|;
name|unsigned
name|char
name|PointerSizeInBytes
decl_stmt|;
block|}
union|;
comment|/// The size and alignment of size_t.
union|union
block|{
name|unsigned
name|char
name|SizeSizeInBytes
decl_stmt|;
comment|// sizeof(size_t)
name|unsigned
name|char
name|SizeAlignInBytes
decl_stmt|;
block|}
union|;
name|unsigned
name|ASTAllocaAddressSpace
decl_stmt|;
name|CharUnits
name|getSizeSize
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|SizeSizeInBytes
argument_list|)
return|;
block|}
name|CharUnits
name|getSizeAlign
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|SizeAlignInBytes
argument_list|)
return|;
block|}
name|CharUnits
name|getPointerSize
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|PointerSizeInBytes
argument_list|)
return|;
block|}
name|CharUnits
name|getPointerAlign
argument_list|()
specifier|const
block|{
return|return
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|PointerAlignInBytes
argument_list|)
return|;
block|}
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|RuntimeCC
expr_stmt|;
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|getRuntimeCC
argument_list|()
specifier|const
block|{
return|return
name|RuntimeCC
return|;
block|}
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|BuiltinCC
expr_stmt|;
name|llvm
operator|::
name|CallingConv
operator|::
name|ID
name|getBuiltinCC
argument_list|()
specifier|const
block|{
return|return
name|BuiltinCC
return|;
block|}
name|unsigned
name|getASTAllocaAddressSpace
argument_list|()
specifier|const
block|{
return|return
name|ASTAllocaAddressSpace
return|;
block|}
block|}
struct|;
block|}
comment|// end namespace CodeGen
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

