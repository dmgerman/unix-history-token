begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====-- PTXSubtarget.h - Define Subtarget for the PTX ---------*- C++ -*--===//
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
comment|// This file declares the PTX specific subclass of TargetSubtarget.
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
name|PTX_SUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_SUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PTXSubtarget
range|:
name|public
name|TargetSubtarget
block|{
name|private
operator|:
comment|/**        * Enumeration of Shader Models supported by the back-end.        */
expr|enum
name|PTXShaderModelEnum
block|{
name|PTX_SM_1_0
block|,
comment|/*< Shader Model 1.0 */
name|PTX_SM_1_3
block|,
comment|/*< Shader Model 1.3 */
name|PTX_SM_2_0
comment|/*< Shader Model 2.0 */
block|}
block|;
comment|/**        * Enumeration of PTX versions supported by the back-end.        *        * Currently, PTX 2.0 is the minimum supported version.        */
block|enum
name|PTXVersionEnum
block|{
name|PTX_VERSION_2_0
block|,
comment|/*< PTX Version 2.0 */
name|PTX_VERSION_2_1
block|,
comment|/*< PTX Version 2.1 */
name|PTX_VERSION_2_2
comment|/*< PTX Version 2.2 */
block|}
block|;
comment|/// Shader Model supported on the target GPU.
name|PTXShaderModelEnum
name|PTXShaderModel
block|;
comment|/// PTX Language Version.
name|PTXVersionEnum
name|PTXVersion
block|;
comment|// The native .f64 type is supported on the hardware.
name|bool
name|SupportsDouble
block|;
comment|// Use .u64 instead of .u32 for addresses.
name|bool
name|Is64Bit
block|;
name|public
operator|:
name|PTXSubtarget
argument_list|(
argument|const std::string&TT
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool is64Bit
argument_list|)
block|;
name|std
operator|::
name|string
name|getTargetString
argument_list|()
specifier|const
block|;
name|std
operator|::
name|string
name|getPTXVersionString
argument_list|()
specifier|const
block|;
name|bool
name|supportsDouble
argument_list|()
specifier|const
block|{
return|return
name|SupportsDouble
return|;
block|}
name|bool
name|is64Bit
argument_list|()
specifier|const
block|{
return|return
name|Is64Bit
return|;
block|}
name|bool
name|supportsSM13
argument_list|()
specifier|const
block|{
return|return
name|PTXShaderModel
operator|>=
name|PTX_SM_1_3
return|;
block|}
name|bool
name|supportsSM20
argument_list|()
specifier|const
block|{
return|return
name|PTXShaderModel
operator|>=
name|PTX_SM_2_0
return|;
block|}
name|bool
name|supportsPTX21
argument_list|()
specifier|const
block|{
return|return
name|PTXVersion
operator|>=
name|PTX_VERSION_2_1
return|;
block|}
name|bool
name|supportsPTX22
argument_list|()
specifier|const
block|{
return|return
name|PTXVersion
operator|>=
name|PTX_VERSION_2_2
return|;
block|}
name|std
operator|::
name|string
name|ParseSubtargetFeatures
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FS
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|CPU
argument_list|)
block|;   }
decl_stmt|;
comment|// class PTXSubtarget
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PTX_SUBTARGET_H
end_comment

end_unit

