begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Target.h - Target Lib C Iface --------------------*- C++ -*-===*/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*                     The LLVM Compiler Infrastructure                       */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/* This file is distributed under the University of Illinois Open Source      */
end_comment

begin_comment
comment|/* License. See LICENSE.TXT for details.                                      */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*===----------------------------------------------------------------------===*/
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/* This header declares the C interface to libLLVMTarget.a, which             */
end_comment

begin_comment
comment|/* implements target information.                                             */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/* Many exotic languages can interoperate with C code but have a harder time  */
end_comment

begin_comment
comment|/* with C++ due to name mangling. So in addition to C, this interface enables */
end_comment

begin_comment
comment|/* tools written in such languages.                                           */
end_comment

begin_comment
comment|/*                                                                            */
end_comment

begin_comment
comment|/*===----------------------------------------------------------------------===*/
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
file|"llvm/Config/llvm-config.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|inline
argument_list|)
end_if

begin_define
define|#
directive|define
name|inline
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup LLVMCTarget Target information  * @ingroup LLVMC  *  * @{  */
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
name|LLVMOpaqueTargetLibraryInfotData
modifier|*
name|LLVMTargetLibraryInfoRef
typedef|;
comment|/* Declare all of the target-initialization functions that are available. */
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|void LLVMInitialize##TargetName##TargetInfo(void);
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
value|void LLVMInitialize##TargetName##Target(void);
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
define|\
value|void LLVMInitialize##TargetName##TargetMC(void);
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
comment|/* Declare all of the available assembly printer initialization functions. */
define|#
directive|define
name|LLVM_ASM_PRINTER
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|void LLVMInitialize##TargetName##AsmPrinter(void);
include|#
directive|include
file|"llvm/Config/AsmPrinters.def"
undef|#
directive|undef
name|LLVM_ASM_PRINTER
comment|/* Explicit undef to make SWIG happier */
comment|/* Declare all of the available assembly parser initialization functions. */
define|#
directive|define
name|LLVM_ASM_PARSER
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|void LLVMInitialize##TargetName##AsmParser(void);
include|#
directive|include
file|"llvm/Config/AsmParsers.def"
undef|#
directive|undef
name|LLVM_ASM_PARSER
comment|/* Explicit undef to make SWIG happier */
comment|/* Declare all of the available disassembler initialization functions. */
define|#
directive|define
name|LLVM_DISASSEMBLER
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|void LLVMInitialize##TargetName##Disassembler(void);
include|#
directive|include
file|"llvm/Config/Disassemblers.def"
undef|#
directive|undef
name|LLVM_DISASSEMBLER
comment|/* Explicit undef to make SWIG happier */
comment|/** LLVMInitializeAllTargetInfos - The main program should call this function if     it wants access to all available targets that LLVM is configured to     support. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllTargetInfos
parameter_list|(
name|void
parameter_list|)
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
parameter_list|(
name|void
parameter_list|)
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
comment|/** LLVMInitializeAllTargetMCs - The main program should call this function if     it wants access to all available target MC that LLVM is configured to     support. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllTargetMCs
parameter_list|(
name|void
parameter_list|)
block|{
define|#
directive|define
name|LLVM_TARGET
parameter_list|(
name|TargetName
parameter_list|)
value|LLVMInitialize##TargetName##TargetMC();
include|#
directive|include
file|"llvm/Config/Targets.def"
undef|#
directive|undef
name|LLVM_TARGET
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeAllAsmPrinters - The main program should call this function if     it wants all asm printers that LLVM is configured to support, to make them     available via the TargetRegistry. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllAsmPrinters
parameter_list|(
name|void
parameter_list|)
block|{
define|#
directive|define
name|LLVM_ASM_PRINTER
parameter_list|(
name|TargetName
parameter_list|)
value|LLVMInitialize##TargetName##AsmPrinter();
include|#
directive|include
file|"llvm/Config/AsmPrinters.def"
undef|#
directive|undef
name|LLVM_ASM_PRINTER
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeAllAsmParsers - The main program should call this function if     it wants all asm parsers that LLVM is configured to support, to make them     available via the TargetRegistry. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllAsmParsers
parameter_list|(
name|void
parameter_list|)
block|{
define|#
directive|define
name|LLVM_ASM_PARSER
parameter_list|(
name|TargetName
parameter_list|)
value|LLVMInitialize##TargetName##AsmParser();
include|#
directive|include
file|"llvm/Config/AsmParsers.def"
undef|#
directive|undef
name|LLVM_ASM_PARSER
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeAllDisassemblers - The main program should call this function     if it wants all disassemblers that LLVM is configured to support, to make     them available via the TargetRegistry. */
specifier|static
specifier|inline
name|void
name|LLVMInitializeAllDisassemblers
parameter_list|(
name|void
parameter_list|)
block|{
define|#
directive|define
name|LLVM_DISASSEMBLER
parameter_list|(
name|TargetName
parameter_list|)
define|\
value|LLVMInitialize##TargetName##Disassembler();
include|#
directive|include
file|"llvm/Config/Disassemblers.def"
undef|#
directive|undef
name|LLVM_DISASSEMBLER
comment|/* Explicit undef to make SWIG happier */
block|}
comment|/** LLVMInitializeNativeTarget - The main program should call this function to     initialize the native target corresponding to the host.  This is useful     for JIT applications to ensure that the target gets linked in correctly. */
specifier|static
specifier|inline
name|LLVMBool
name|LLVMInitializeNativeTarget
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* If we have a native target, initialize it to ensure it is linked in. */
ifdef|#
directive|ifdef
name|LLVM_NATIVE_TARGET
name|LLVM_NATIVE_TARGETINFO
argument_list|()
expr_stmt|;
name|LLVM_NATIVE_TARGET
argument_list|()
expr_stmt|;
name|LLVM_NATIVE_TARGETMC
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
return|return
literal|1
return|;
endif|#
directive|endif
block|}
comment|/** LLVMInitializeNativeTargetAsmParser - The main program should call this     function to initialize the parser for the native target corresponding to the     host. */
specifier|static
specifier|inline
name|LLVMBool
name|LLVMInitializeNativeAsmParser
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LLVM_NATIVE_ASMPARSER
name|LLVM_NATIVE_ASMPARSER
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
return|return
literal|1
return|;
endif|#
directive|endif
block|}
comment|/** LLVMInitializeNativeTargetAsmPrinter - The main program should call this     function to initialize the printer for the native target corresponding to     the host. */
specifier|static
specifier|inline
name|LLVMBool
name|LLVMInitializeNativeAsmPrinter
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LLVM_NATIVE_ASMPRINTER
name|LLVM_NATIVE_ASMPRINTER
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
return|return
literal|1
return|;
endif|#
directive|endif
block|}
comment|/** LLVMInitializeNativeTargetDisassembler - The main program should call this     function to initialize the disassembler for the native target corresponding     to the host. */
specifier|static
specifier|inline
name|LLVMBool
name|LLVMInitializeNativeDisassembler
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LLVM_NATIVE_DISASSEMBLER
name|LLVM_NATIVE_DISASSEMBLER
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
else|#
directive|else
return|return
literal|1
return|;
endif|#
directive|endif
block|}
comment|/*===-- Target Data -------------------------------------------------------===*/
comment|/** Creates target data from a target layout string.     See the constructor llvm::DataLayout::DataLayout. */
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
name|TD
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** Adds target library information to a pass manager. This does not take     ownership of the target library info.     See the method llvm::PassManagerBase::add. */
name|void
name|LLVMAddTargetLibraryInfo
parameter_list|(
name|LLVMTargetLibraryInfoRef
name|TLI
parameter_list|,
name|LLVMPassManagerRef
name|PM
parameter_list|)
function_decl|;
comment|/** Converts target data to a target layout string. The string must be disposed     with LLVMDisposeMessage.     See the constructor llvm::DataLayout::DataLayout. */
name|char
modifier|*
name|LLVMCopyStringRepOfTargetData
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/** Returns the byte order of a target, either LLVMBigEndian or     LLVMLittleEndian.     See the method llvm::DataLayout::isLittleEndian. */
name|enum
name|LLVMByteOrdering
name|LLVMByteOrder
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/** Returns the pointer size in bytes for a target.     See the method llvm::DataLayout::getPointerSize. */
name|unsigned
name|LLVMPointerSize
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/** Returns the pointer size in bytes for a target for a specified     address space.     See the method llvm::DataLayout::getPointerSize. */
name|unsigned
name|LLVMPointerSizeForAS
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|unsigned
name|AS
parameter_list|)
function_decl|;
comment|/** Returns the integer type that is the same size as a pointer on a target.     See the method llvm::DataLayout::getIntPtrType. */
name|LLVMTypeRef
name|LLVMIntPtrType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/** Returns the integer type that is the same size as a pointer on a target.     This version allows the address space to be specified.     See the method llvm::DataLayout::getIntPtrType. */
name|LLVMTypeRef
name|LLVMIntPtrTypeForAS
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|unsigned
name|AS
parameter_list|)
function_decl|;
comment|/** Returns the integer type that is the same size as a pointer on a target.     See the method llvm::DataLayout::getIntPtrType. */
name|LLVMTypeRef
name|LLVMIntPtrTypeInContext
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/** Returns the integer type that is the same size as a pointer on a target.     This version allows the address space to be specified.     See the method llvm::DataLayout::getIntPtrType. */
name|LLVMTypeRef
name|LLVMIntPtrTypeForASInContext
parameter_list|(
name|LLVMContextRef
name|C
parameter_list|,
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|unsigned
name|AS
parameter_list|)
function_decl|;
comment|/** Computes the size of a type in bytes for a target.     See the method llvm::DataLayout::getTypeSizeInBits. */
name|unsigned
name|long
name|long
name|LLVMSizeOfTypeInBits
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the storage size of a type in bytes for a target.     See the method llvm::DataLayout::getTypeStoreSize. */
name|unsigned
name|long
name|long
name|LLVMStoreSizeOfType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the ABI size of a type in bytes for a target.     See the method llvm::DataLayout::getTypeAllocSize. */
name|unsigned
name|long
name|long
name|LLVMABISizeOfType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the ABI alignment of a type in bytes for a target.     See the method llvm::DataLayout::getTypeABISize. */
name|unsigned
name|LLVMABIAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the call frame alignment of a type in bytes for a target.     See the method llvm::DataLayout::getTypeABISize. */
name|unsigned
name|LLVMCallFrameAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the preferred alignment of a type in bytes for a target.     See the method llvm::DataLayout::getTypeABISize. */
name|unsigned
name|LLVMPreferredAlignmentOfType
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|,
name|LLVMTypeRef
name|Ty
parameter_list|)
function_decl|;
comment|/** Computes the preferred alignment of a global variable in bytes for a target.     See the method llvm::DataLayout::getPreferredAlignment. */
name|unsigned
name|LLVMPreferredAlignmentOfGlobal
parameter_list|(
name|LLVMTargetDataRef
name|TD
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
name|TD
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
name|TD
parameter_list|,
name|LLVMTypeRef
name|StructTy
parameter_list|,
name|unsigned
name|Element
parameter_list|)
function_decl|;
comment|/** Deallocates a TargetData.     See the destructor llvm::DataLayout::~DataLayout. */
name|void
name|LLVMDisposeTargetData
parameter_list|(
name|LLVMTargetDataRef
name|TD
parameter_list|)
function_decl|;
comment|/**  * @}  */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

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

