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
comment|// This file declares the PTX specific subclass of TargetSubtargetInfo.
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
file|"llvm/Target/TargetSubtargetInfo.h"
end_include

begin_define
define|#
directive|define
name|GET_SUBTARGETINFO_HEADER
end_define

begin_include
include|#
directive|include
file|"PTXGenSubtargetInfo.inc"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|PTXSubtarget
range|:
name|public
name|PTXGenSubtargetInfo
block|{
name|public
operator|:
comment|/**        * Enumeration of Shader Models supported by the back-end.        */
expr|enum
name|PTXTargetEnum
block|{
name|PTX_COMPUTE_1_0
block|,
comment|/*< Compute Compatibility 1.0 */
name|PTX_COMPUTE_1_1
block|,
comment|/*< Compute Compatibility 1.1 */
name|PTX_COMPUTE_1_2
block|,
comment|/*< Compute Compatibility 1.2 */
name|PTX_COMPUTE_1_3
block|,
comment|/*< Compute Compatibility 1.3 */
name|PTX_COMPUTE_2_0
block|,
comment|/*< Compute Compatibility 2.0 */
name|PTX_LAST_COMPUTE
block|,
name|PTX_SM_1_0
block|,
comment|/*< Shader Model 1.0 */
name|PTX_SM_1_1
block|,
comment|/*< Shader Model 1.1 */
name|PTX_SM_1_2
block|,
comment|/*< Shader Model 1.2 */
name|PTX_SM_1_3
block|,
comment|/*< Shader Model 1.3 */
name|PTX_SM_2_0
block|,
comment|/*< Shader Model 2.0 */
name|PTX_SM_2_1
block|,
comment|/*< Shader Model 2.1 */
name|PTX_SM_2_2
block|,
comment|/*< Shader Model 2.2 */
name|PTX_SM_2_3
block|,
comment|/*< Shader Model 2.3 */
name|PTX_LAST_SM
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
block|,
comment|/*< PTX Version 2.2 */
name|PTX_VERSION_2_3
comment|/*< PTX Version 2.3 */
block|}
block|;
name|private
operator|:
comment|/// Shader Model supported on the target GPU.
name|PTXTargetEnum
name|PTXTarget
block|;
comment|/// PTX Language Version.
name|PTXVersionEnum
name|PTXVersion
block|;
comment|// The native .f64 type is supported on the hardware.
name|bool
name|SupportsDouble
block|;
comment|// Support the fused-multiply add (FMA) and multiply-add (MAD)
comment|// instructions
name|bool
name|SupportsFMA
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
argument|const std::string&CPU
argument_list|,
argument|const std::string&FS
argument_list|,
argument|bool is64Bit
argument_list|)
block|;
comment|// Target architecture accessors
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
name|supportsFMA
argument_list|()
specifier|const
block|{
return|return
name|SupportsFMA
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
name|bool
name|supportsPTX23
argument_list|()
specifier|const
block|{
return|return
name|PTXVersion
operator|>=
name|PTX_VERSION_2_3
return|;
block|}
name|bool
name|fdivNeedsRoundingMode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PTXTarget
operator|>=
name|PTX_SM_1_3
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_SM
operator|)
operator|||
operator|(
name|PTXTarget
operator|>=
name|PTX_COMPUTE_1_3
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_COMPUTE
operator|)
return|;
block|}
name|bool
name|fmadNeedsRoundingMode
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PTXTarget
operator|>=
name|PTX_SM_1_3
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_SM
operator|)
operator|||
operator|(
name|PTXTarget
operator|>=
name|PTX_COMPUTE_1_3
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_COMPUTE
operator|)
return|;
block|}
name|bool
name|useParamSpaceForDeviceArgs
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PTXTarget
operator|>=
name|PTX_SM_2_0
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_SM
operator|)
operator|||
operator|(
name|PTXTarget
operator|>=
name|PTX_COMPUTE_2_0
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_COMPUTE
operator|)
return|;
block|}
name|bool
name|callsAreHandled
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PTXTarget
operator|>=
name|PTX_SM_2_0
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_SM
operator|)
operator|||
operator|(
name|PTXTarget
operator|>=
name|PTX_COMPUTE_2_0
operator|&&
name|PTXTarget
operator|<
name|PTX_LAST_COMPUTE
operator|)
return|;
block|}
name|bool
name|emitPtrAttribute
argument_list|()
specifier|const
block|{
return|return
name|PTXVersion
operator|>=
name|PTX_VERSION_2_2
return|;
block|}
name|void
name|ParseSubtargetFeatures
argument_list|(
argument|StringRef CPU
argument_list|,
argument|StringRef FS
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

