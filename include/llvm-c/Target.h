begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Target.h - Target Lib C Iface --------------------*- C++ -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header declares the C interface to libLLVMTarget.a, which             *| |* implements target information.                                             *| |*                                                                            *| |* Many exotic languages can interoperate with C code but have a harder time  *| |* with C++ due to name mangling. So in addition to C, this interface enables *| |* tools written in such languages.                                           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_C_TARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_TARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
enum|enum
name|LLVMByteOrdering
block|{
name|LLVMBigEndian
block|,
name|LLVMLittleEndian
block|}
enum|;
typedef|typedef
name|struct
name|LLVMOpaqueTargetData
modifier|*
name|LLVMTargetDataRef
typedef|;
typedef|typedef
name|struct
name|LLVMStructLayout
modifier|*
name|LLVMStructLayoutRef
typedef|;
comment|/* Declare all of the target-initialization functions that are available. */
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|void LLVMInitialize##TargetName##TargetInfo();
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|void LLVMInitialize##TargetName##Target();
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
comment|/** LLVMInitializeAllTargetInfos - The main program should call this function if     it wants access to all available targets that LLVM is configured to     support. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllTargetInfos
parameter_list|()
block|{
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|LLVMInitialize##TargetName##TargetInfo();
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeAllTargets - The main program should call this function if it     wants to link in all available targets that LLVM is configured to     support. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllTargets
parameter_list|()
block|{
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|LLVMInitialize##TargetName##Target();
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeNativeTarget - The main program should call this function to     initialize the native target corresponding to the host.  This is useful      for JIT applications to ensure that the target gets linked in correctly. */
specifier|static
specifier|inline
name|LLVMBool
name|LLVMInitializeNativeTarget
parameter_list|()
block|{
comment|/* If we have a native target, initialize it to ensure it is linked in. */
ifdef|#
directive|ifdef
name|LLVM_NATIVE_ARCH
define|#
directive|define
name|DoInit2
parameter_list|(
name|TARG
parameter_list|)
define|\
value|LLVMInitialize ## TARG ## Info ();          \   LLVMInitialize ## TARG ()
define|#
directive|define
name|DoInit
parameter_list|(
name|T
parameter_list|)
value|DoInit2(T)
name|DoInit
argument_list|(
name|LLVM_NATIVE_ARCH
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
undef|#
directive|undef
name|DoInit
undef|#
directive|undef
name|DoInit2
else|#
directive|else
return|return
literal|1
return|;
endif|#
directive|endif
block|}
comment|/*===-- Target Data -------------------------------------------------------===*/
comment|/** Creates target data from a target layout string.     See the constructor llvm::TargetData::TargetData. */
name|LLVMTargetDataRef
name|LLVMCreateTargetData
parameter_list|(
specifier|const
name|char
modifier|*
name|StringRep
parameter_list|)
function_decl|;
comment|/** Adds target data information to a pass manager. This does not take ownership     of the target data.     See the method llvm::PassManagerBase::add. */
name|void
name|LLVMAddTargetData
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMPassManagerRef
parameter_list|)
function_decl|;
comment|/** Converts target data to a target layout string. The string must be disposed     with LLVMDisposeMessage.     See the constructor llvm::TargetData::TargetData. */
name|char
modifier|*
name|LLVMCopyStringRepOfTargetData
parameter_list|(
name|LLVMTargetDataRef
parameter_list|)
function_decl|;
comment|/** Returns the byte order of a target, either LLVMBigEndian or     LLVMLittleEndian.     See the method llvm::TargetData::isLittleEndian. */
name|enum
name|LLVMByteOrdering
name|LLVMByteOrder
parameter_list|(
name|LLVMTargetDataRef
parameter_list|)
function_decl|;
comment|/** Returns the pointer size in bytes for a target.     See the method llvm::TargetData::getPointerSize. */
name|unsigned
name|LLVMPointerSize
parameter_list|(
name|LLVMTargetDataRef
parameter_list|)
function_decl|;
comment|/** Returns the integer type that is the same size as a pointer on a target.     See the method llvm::TargetData::getIntPtrType. */
name|LLVMTypeRef
name|LLVMIntPtrType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|)
function_decl|;
comment|/** Computes the size of a type in bytes for a target.     See the method llvm::TargetData::getTypeSizeInBits. */
name|unsigned
name|long
name|long
name|LLVMSizeOfTypeInBits
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the storage size of a type in bytes for a target.     See the method llvm::TargetData::getTypeStoreSize. */
name|unsigned
name|long
name|long
name|LLVMStoreSizeOfType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the ABI size of a type in bytes for a target.     See the method llvm::TargetData::getTypeAllocSize. */
name|unsigned
name|long
name|long
name|LLVMABISizeOfType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the ABI alignment of a type in bytes for a target.     See the method llvm::TargetData::getTypeABISize. */
name|unsigned
name|LLVMABIAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the call frame alignment of a type in bytes for a target.     See the method llvm::TargetData::getTypeABISize. */
name|unsigned
name|LLVMCallFrameAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the preferred alignment of a type in bytes for a target.     See the method llvm::TargetData::getTypeABISize. */
name|unsigned
name|LLVMPreferredAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
parameter_list|)
function_decl|;
comment|/** Computes the preferred alignment of a global variable in bytes for a target.     See the method llvm::TargetData::getPreferredAlignment. */
name|unsigned
name|LLVMPreferredAlignmentOfGlobal
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMValueRef
name|GlobalVar
parameter_list|)
function_decl|;
comment|/** Computes the structure element that contains the byte offset for a target.     See the method llvm::StructLayout::getElementContainingOffset. */
name|unsigned
name|LLVMElementAtOffset
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
name|StructTy
parameter_list|,
name|unsigned
name|long
name|long
name|Offset
parameter_list|)
function_decl|;
comment|/** Computes the byte offset of the indexed struct element for a target.     See the method llvm::StructLayout::getElementContainingOffset. */
name|unsigned
name|long
name|long
name|LLVMOffsetOfElement
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
name|StructTy
parameter_list|,
name|unsigned
name|Element
parameter_list|)
function_decl|;
comment|/** Struct layouts are speculatively cached. If a TargetDataRef is alive when     types are being refined and removed, this method must be called whenever a     struct type is removed to avoid a dangling pointer in this cache.     See the method llvm::TargetData::InvalidateStructLayoutInfo. */
name|void
name|LLVMInvalidateStructLayout
parameter_list|(
name|LLVMTargetDataRef
parameter_list|,
name|LLVMTypeRef
name|StructTy
parameter_list|)
function_decl|;
comment|/** Deallocates a TargetData.     See the destructor llvm::TargetData::~TargetData. */
name|void
name|LLVMDisposeTargetData
parameter_list|(
name|LLVMTargetDataRef
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|TargetData
decl_stmt|;
specifier|inline
name|TargetData
modifier|*
name|unwrap
parameter_list|(
name|LLVMTargetDataRef
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|TargetData
operator|*
operator|>
operator|(
name|P
operator|)
return|;
block|}
specifier|inline
name|LLVMTargetDataRef
name|wrap
parameter_list|(
specifier|const
name|TargetData
modifier|*
name|P
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMTargetDataRef
operator|>
operator|(
name|const_cast
operator|<
name|TargetData
operator|*
operator|>
operator|(
name|P
operator|)
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__cplusplus) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

