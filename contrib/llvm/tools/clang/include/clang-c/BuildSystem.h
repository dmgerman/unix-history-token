begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*==-- clang-c/BuildSystem.h - Utilities for use by build systems -*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides various utilities for use by build systems.           *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_C_BUILD_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_C_BUILD_SYSTEM_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Platform.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/CXErrorCode.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/CXString.h"
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
comment|/**  * \defgroup BUILD_SYSTEM Build system utilities  * @{  */
comment|/**  * \brief Return the timestamp for use with Clang's  * \c -fbuild-session-timestamp= option.  */
name|CINDEX_LINKAGE
name|unsigned
name|long
name|long
name|clang_getBuildSessionTimestamp
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Object encapsulating information about overlaying virtual  * file/directories over the real file system.  */
typedef|typedef
name|struct
name|CXVirtualFileOverlayImpl
modifier|*
name|CXVirtualFileOverlay
typedef|;
comment|/**  * \brief Create a \c CXVirtualFileOverlay object.  * Must be disposed with \c clang_VirtualFileOverlay_dispose().  *  * \param options is reserved, always pass 0.  */
name|CINDEX_LINKAGE
name|CXVirtualFileOverlay
name|clang_VirtualFileOverlay_create
parameter_list|(
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Map an absolute virtual file path to an absolute real one.  * The virtual path must be canonicalized (not contain "."/"..").  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_VirtualFileOverlay_addFileMapping
parameter_list|(
name|CXVirtualFileOverlay
parameter_list|,
specifier|const
name|char
modifier|*
name|virtualPath
parameter_list|,
specifier|const
name|char
modifier|*
name|realPath
parameter_list|)
function_decl|;
comment|/**  * \brief Set the case sensitivity for the \c CXVirtualFileOverlay object.  * The \c CXVirtualFileOverlay object is case-sensitive by default, this  * option can be used to override the default.  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_VirtualFileOverlay_setCaseSensitivity
parameter_list|(
name|CXVirtualFileOverlay
parameter_list|,
name|int
name|caseSensitive
parameter_list|)
function_decl|;
comment|/**  * \brief Write out the \c CXVirtualFileOverlay object to a char buffer.  *  * \param options is reserved, always pass 0.  * \param out_buffer_ptr pointer to receive the buffer pointer, which should be  * disposed using \c free().  * \param out_buffer_size pointer to receive the buffer size.  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_VirtualFileOverlay_writeToBuffer
parameter_list|(
name|CXVirtualFileOverlay
parameter_list|,
name|unsigned
name|options
parameter_list|,
name|char
modifier|*
modifier|*
name|out_buffer_ptr
parameter_list|,
name|unsigned
modifier|*
name|out_buffer_size
parameter_list|)
function_decl|;
comment|/**  * \brief Dispose a \c CXVirtualFileOverlay object.  */
name|CINDEX_LINKAGE
name|void
name|clang_VirtualFileOverlay_dispose
parameter_list|(
name|CXVirtualFileOverlay
parameter_list|)
function_decl|;
comment|/**  * \brief Object encapsulating information about a module.map file.  */
typedef|typedef
name|struct
name|CXModuleMapDescriptorImpl
modifier|*
name|CXModuleMapDescriptor
typedef|;
comment|/**  * \brief Create a \c CXModuleMapDescriptor object.  * Must be disposed with \c clang_ModuleMapDescriptor_dispose().  *  * \param options is reserved, always pass 0.  */
name|CINDEX_LINKAGE
name|CXModuleMapDescriptor
name|clang_ModuleMapDescriptor_create
parameter_list|(
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Sets the framework module name that the module.map describes.  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_ModuleMapDescriptor_setFrameworkModuleName
parameter_list|(
name|CXModuleMapDescriptor
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * \brief Sets the umbrealla header name that the module.map describes.  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_ModuleMapDescriptor_setUmbrellaHeader
parameter_list|(
name|CXModuleMapDescriptor
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|/**  * \brief Write out the \c CXModuleMapDescriptor object to a char buffer.  *  * \param options is reserved, always pass 0.  * \param out_buffer_ptr pointer to receive the buffer pointer, which should be  * disposed using \c free().  * \param out_buffer_size pointer to receive the buffer size.  * \returns 0 for success, non-zero to indicate an error.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_ModuleMapDescriptor_writeToBuffer
parameter_list|(
name|CXModuleMapDescriptor
parameter_list|,
name|unsigned
name|options
parameter_list|,
name|char
modifier|*
modifier|*
name|out_buffer_ptr
parameter_list|,
name|unsigned
modifier|*
name|out_buffer_size
parameter_list|)
function_decl|;
comment|/**  * \brief Dispose a \c CXModuleMapDescriptor object.  */
name|CINDEX_LINKAGE
name|void
name|clang_ModuleMapDescriptor_dispose
parameter_list|(
name|CXModuleMapDescriptor
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLANG_C_BUILD_SYSTEM_H */
end_comment

end_unit

