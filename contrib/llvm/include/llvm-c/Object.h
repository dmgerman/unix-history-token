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

begin_include
include|#
directive|include
file|"llvm/Object/ObjectFile.h"
end_include

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|object
block|{
specifier|inline
name|ObjectFile
modifier|*
name|unwrap
parameter_list|(
name|LLVMObjectFileRef
name|OF
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|ObjectFile
operator|*
operator|>
operator|(
name|OF
operator|)
return|;
block|}
specifier|inline
name|LLVMObjectFileRef
name|wrap
parameter_list|(
specifier|const
name|ObjectFile
modifier|*
name|OF
parameter_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMObjectFileRef
operator|>
operator|(
name|const_cast
operator|<
name|ObjectFile
operator|*
operator|>
operator|(
name|OF
operator|)
operator|)
return|;
block|}
specifier|inline
name|ObjectFile
operator|::
name|section_iterator
operator|*
name|unwrap
argument_list|(
argument|LLVMSectionIteratorRef SI
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|ObjectFile
operator|::
name|section_iterator
operator|*
operator|>
operator|(
name|SI
operator|)
return|;
block|}
specifier|inline
name|LLVMSectionIteratorRef
name|wrap
argument_list|(
specifier|const
name|ObjectFile
operator|::
name|section_iterator
operator|*
name|SI
argument_list|)
block|{
return|return
name|reinterpret_cast
operator|<
name|LLVMSectionIteratorRef
operator|>
operator|(
name|const_cast
operator|<
name|ObjectFile
operator|::
name|section_iterator
operator|*
operator|>
operator|(
name|SI
operator|)
operator|)
return|;
block|}
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

