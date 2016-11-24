begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OpenCLOptions.h ----------------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::OpenCLOptions class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_OPENCLOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_OPENCLOPTIONS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief OpenCL supported extensions and optional core features
name|class
name|OpenCLOptions
block|{
name|public
label|:
define|#
directive|define
name|OPENCLEXT
parameter_list|(
name|nm
parameter_list|)
value|unsigned nm : 1;
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
name|OpenCLOptions
argument_list|()
block|{
define|#
directive|define
name|OPENCLEXT
parameter_list|(
name|nm
parameter_list|)
value|nm = 0;
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
block|}
comment|// Enable all options.
name|void
name|setAll
parameter_list|()
block|{
define|#
directive|define
name|OPENCLEXT
parameter_list|(
name|nm
parameter_list|)
value|nm = 1;
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
block|}
comment|// Is supported with OpenCL version \p OCLVer.
define|#
directive|define
name|OPENCLEXT_INTERNAL
parameter_list|(
name|Ext
parameter_list|,
name|Avail
parameter_list|,
modifier|...
parameter_list|)
define|\
value|bool is_##Ext##_supported(unsigned OCLVer) const { \     return Ext&& OCLVer>= Avail; \   }
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
comment|// Is supported OpenCL extension with OpenCL version \p OCLVer.
comment|// For supported optional core feature, return false.
define|#
directive|define
name|OPENCLEXT_INTERNAL
parameter_list|(
name|Ext
parameter_list|,
name|Avail
parameter_list|,
name|Core
parameter_list|)
define|\
value|bool is_##Ext##_supported_extension(unsigned CLVer) const { \     return is_##Ext##_supported(CLVer)&& (Core == ~0U || CLVer< Core); \   }
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
comment|// Is supported OpenCL core features with OpenCL version \p OCLVer.
comment|// For supported extension, return false.
define|#
directive|define
name|OPENCLEXT_INTERNAL
parameter_list|(
name|Ext
parameter_list|,
name|Avail
parameter_list|,
name|Core
parameter_list|)
define|\
value|bool is_##Ext##_supported_core(unsigned CLVer) const { \     return is_##Ext##_supported(CLVer)&& Core != ~0U&& CLVer>= Core; \   }
include|#
directive|include
file|"clang/Basic/OpenCLExtensions.def"
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

