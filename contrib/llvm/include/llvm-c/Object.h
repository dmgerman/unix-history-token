begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- llvm-c/Object.h - Object Lib C Iface --------------------*- C++ -*-===*/
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
comment|/* This header declares the C interface to libLLVMObject.a, which             */
end_comment

begin_comment
comment|/* implements object file reading and writing.                                */
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
name|LLVM_C_OBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_C_OBJECT_H
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
comment|/**  * @defgroup LLVMCObject Object file reading and writing  * @ingroup LLVMC  *  * @{  */
comment|// Opaque type wrappers
typedef|typedef
name|struct
name|LLVMOpaqueObjectFile
modifier|*
name|LLVMObjectFileRef
typedef|;
typedef|typedef
name|struct
name|LLVMOpaqueSectionIterator
modifier|*
name|LLVMSectionIteratorRef
typedef|;
typedef|typedef
name|struct
name|LLVMOpaqueSymbolIterator
modifier|*
name|LLVMSymbolIteratorRef
typedef|;
typedef|typedef
name|struct
name|LLVMOpaqueRelocationIterator
modifier|*
name|LLVMRelocationIteratorRef
typedef|;
comment|// ObjectFile creation
name|LLVMObjectFileRef
name|LLVMCreateObjectFile
parameter_list|(
name|LLVMMemoryBufferRef
name|MemBuf
parameter_list|)
function_decl|;
name|void
name|LLVMDisposeObjectFile
parameter_list|(
name|LLVMObjectFileRef
name|ObjectFile
parameter_list|)
function_decl|;
comment|// ObjectFile Section iterators
name|LLVMSectionIteratorRef
name|LLVMGetSections
parameter_list|(
name|LLVMObjectFileRef
name|ObjectFile
parameter_list|)
function_decl|;
name|void
name|LLVMDisposeSectionIterator
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMIsSectionIteratorAtEnd
parameter_list|(
name|LLVMObjectFileRef
name|ObjectFile
parameter_list|,
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|void
name|LLVMMoveToNextSection
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|void
name|LLVMMoveToContainingSection
parameter_list|(
name|LLVMSectionIteratorRef
name|Sect
parameter_list|,
name|LLVMSymbolIteratorRef
name|Sym
parameter_list|)
function_decl|;
comment|// ObjectFile Symbol iterators
name|LLVMSymbolIteratorRef
name|LLVMGetSymbols
parameter_list|(
name|LLVMObjectFileRef
name|ObjectFile
parameter_list|)
function_decl|;
name|void
name|LLVMDisposeSymbolIterator
parameter_list|(
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMIsSymbolIteratorAtEnd
parameter_list|(
name|LLVMObjectFileRef
name|ObjectFile
parameter_list|,
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
name|void
name|LLVMMoveToNextSymbol
parameter_list|(
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
comment|// SectionRef accessors
specifier|const
name|char
modifier|*
name|LLVMGetSectionName
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetSectionSize
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|LLVMGetSectionContents
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetSectionAddress
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMGetSectionContainsSymbol
parameter_list|(
name|LLVMSectionIteratorRef
name|SI
parameter_list|,
name|LLVMSymbolIteratorRef
name|Sym
parameter_list|)
function_decl|;
comment|// Section Relocation iterators
name|LLVMRelocationIteratorRef
name|LLVMGetRelocations
parameter_list|(
name|LLVMSectionIteratorRef
name|Section
parameter_list|)
function_decl|;
name|void
name|LLVMDisposeRelocationIterator
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
name|LLVMBool
name|LLVMIsRelocationIteratorAtEnd
parameter_list|(
name|LLVMSectionIteratorRef
name|Section
parameter_list|,
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
name|void
name|LLVMMoveToNextRelocation
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
comment|// SymbolRef accessors
specifier|const
name|char
modifier|*
name|LLVMGetSymbolName
parameter_list|(
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetSymbolAddress
parameter_list|(
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetSymbolSize
parameter_list|(
name|LLVMSymbolIteratorRef
name|SI
parameter_list|)
function_decl|;
comment|// RelocationRef accessors
name|uint64_t
name|LLVMGetRelocationAddress
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetRelocationOffset
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
name|LLVMSymbolIteratorRef
name|LLVMGetRelocationSymbol
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
name|uint64_t
name|LLVMGetRelocationType
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
comment|// NOTE: Caller takes ownership of returned string of the two
comment|// following functions.
specifier|const
name|char
modifier|*
name|LLVMGetRelocationTypeName
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|LLVMGetRelocationValueString
parameter_list|(
name|LLVMRelocationIteratorRef
name|RI
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

