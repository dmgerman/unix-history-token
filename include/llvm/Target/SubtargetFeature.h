begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/SubtargetFeature.h - CPU characteristics ----*- C++ -*-===//
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
comment|// This file defines and manages user or tool specified CPU characteristics.
end_comment

begin_comment
comment|// The intent is to be able to package specific features that should or should
end_comment

begin_comment
comment|// not be used on a specific target processor.  A tool, such as llc, could, as
end_comment

begin_comment
comment|// as example, gather chip info from the command line, a long with features
end_comment

begin_comment
comment|// that should be used on that chip.
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
name|LLVM_TARGET_SUBTARGETFEATURE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_SUBTARGETFEATURE_H
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

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// SubtargetFeatureKV - Used to provide key value pairs for feature and
comment|/// CPU bit flags.
comment|//
struct|struct
name|SubtargetFeatureKV
block|{
specifier|const
name|char
modifier|*
name|Key
decl_stmt|;
comment|// K-V key string
specifier|const
name|char
modifier|*
name|Desc
decl_stmt|;
comment|// Help descriptor
name|uint32_t
name|Value
decl_stmt|;
comment|// K-V integer value
name|uint32_t
name|Implies
decl_stmt|;
comment|// K-V bit mask
comment|// Compare routine for std binary search
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SubtargetFeatureKV
operator|&
name|S
operator|)
specifier|const
block|{
return|return
name|strcmp
argument_list|(
name|Key
argument_list|,
name|S
operator|.
name|Key
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// SubtargetInfoKV - Used to provide key value pairs for CPU and arbitrary
comment|/// pointers.
comment|//
struct|struct
name|SubtargetInfoKV
block|{
specifier|const
name|char
modifier|*
name|Key
decl_stmt|;
comment|// K-V key string
name|void
modifier|*
name|Value
decl_stmt|;
comment|// K-V pointer value
comment|// Compare routine for std binary search
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SubtargetInfoKV
operator|&
name|S
operator|)
specifier|const
block|{
return|return
name|strcmp
argument_list|(
name|Key
argument_list|,
name|S
operator|.
name|Key
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|///
comment|/// SubtargetFeatures - Manages the enabling and disabling of subtarget
comment|/// specific features.  Features are encoded as a string of the form
comment|///   "cpu,+attr1,+attr2,-attr3,...,+attrN"
comment|/// A comma separates each feature from the next (all lowercase.)
comment|/// The first feature is always the CPU subtype (eg. pentiumm).  If the CPU
comment|/// value is "generic" then the CPU subtype should be generic for the target.
comment|/// Each of the remaining features is prefixed with + or - indicating whether
comment|/// that feature should be enabled or disabled contrary to the cpu
comment|/// specification.
comment|///
name|class
name|SubtargetFeatures
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Features
expr_stmt|;
comment|// Subtarget features as a vector
name|public
label|:
name|explicit
name|SubtargetFeatures
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Initial
operator|=
name|std
operator|::
name|string
argument_list|()
argument_list|)
decl_stmt|;
comment|/// Features string accessors.
name|std
operator|::
name|string
name|getString
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Initial
argument_list|)
decl_stmt|;
comment|/// Set the CPU string.  Replaces previous setting.  Setting to "" clears CPU.
name|void
name|setCPU
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
decl_stmt|;
comment|/// Setting CPU string only if no string is set.
name|void
name|setCPUIfNone
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
decl_stmt|;
comment|/// Returns current CPU string.
specifier|const
name|std
operator|::
name|string
operator|&
name|getCPU
argument_list|()
specifier|const
expr_stmt|;
comment|/// Adding Features.
name|void
name|AddFeature
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|,
name|bool
name|IsEnabled
operator|=
name|true
argument_list|)
decl_stmt|;
comment|/// Get feature bits.
name|uint32_t
name|getBits
parameter_list|(
specifier|const
name|SubtargetFeatureKV
modifier|*
name|CPUTable
parameter_list|,
name|size_t
name|CPUTableSize
parameter_list|,
specifier|const
name|SubtargetFeatureKV
modifier|*
name|FeatureTable
parameter_list|,
name|size_t
name|FeatureTableSize
parameter_list|)
function_decl|;
comment|/// Get info pointer
name|void
modifier|*
name|getInfo
parameter_list|(
specifier|const
name|SubtargetInfoKV
modifier|*
name|Table
parameter_list|,
name|size_t
name|TableSize
parameter_list|)
function_decl|;
comment|/// Print feature string.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|// Dump feature info.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Retrieve a formatted string of the default features for
comment|/// the specified target triple.
specifier|static
name|std
operator|::
name|string
name|getDefaultSubtargetFeatures
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

