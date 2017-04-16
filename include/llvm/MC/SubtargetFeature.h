begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/SubtargetFeature.h - CPU characteristics ---------*- C++ -*-===//
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
comment|/// \file Defines and manages user or tool specified CPU characteristics.
end_comment

begin_comment
comment|/// The intent is to be able to package specific features that should or should
end_comment

begin_comment
comment|/// not be used on a specific target processor.  A tool, such as llc, could, as
end_comment

begin_comment
comment|/// as example, gather chip info from the command line, a long with features
end_comment

begin_comment
comment|/// that should be used on that chip.
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
name|LLVM_MC_SUBTARGETFEATURE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_SUBTARGETFEATURE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

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
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Triple
decl_stmt|;
specifier|const
name|unsigned
name|MAX_SUBTARGET_FEATURES
init|=
literal|192
decl_stmt|;
comment|/// Container class for subtarget features.
comment|/// This is convenient because std::bitset does not have a constructor
comment|/// with an initializer list of set bits.
name|class
name|FeatureBitset
range|:
name|public
name|std
operator|::
name|bitset
operator|<
name|MAX_SUBTARGET_FEATURES
operator|>
block|{
name|public
operator|:
comment|// Cannot inherit constructors because it's not supported by VC++..
name|FeatureBitset
argument_list|()
operator|=
expr|default
block|;
name|FeatureBitset
argument_list|(
specifier|const
name|bitset
operator|<
name|MAX_SUBTARGET_FEATURES
operator|>
operator|&
name|B
argument_list|)
operator|:
name|bitset
argument_list|(
argument|B
argument_list|)
block|{}
name|FeatureBitset
argument_list|(
argument|std::initializer_list<unsigned> Init
argument_list|)
block|{
for|for
control|(
name|auto
name|I
range|:
name|Init
control|)
name|set
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// Used to provide key value pairs for feature and CPU bit flags.
block|struct
name|SubtargetFeatureKV
block|{
specifier|const
name|char
operator|*
name|Key
block|;
comment|///< K-V key string
specifier|const
name|char
operator|*
name|Desc
block|;
comment|///< Help descriptor
name|FeatureBitset
name|Value
block|;
comment|///< K-V integer value
name|FeatureBitset
name|Implies
block|;
comment|///< K-V bit mask
comment|/// Compare routine for std::lower_bound
name|bool
name|operator
operator|<
operator|(
name|StringRef
name|S
operator|)
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|Key
argument_list|)
operator|<
name|S
return|;
block|}
comment|/// Compare routine for std::is_sorted.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SubtargetFeatureKV
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|Key
argument_list|)
operator|<
name|StringRef
argument_list|(
name|Other
operator|.
name|Key
argument_list|)
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// Used to provide key value pairs for CPU and arbitrary pointers.
block|struct
name|SubtargetInfoKV
block|{
specifier|const
name|char
operator|*
name|Key
block|;
comment|///< K-V key string
specifier|const
name|void
operator|*
name|Value
block|;
comment|///< K-V pointer value
comment|/// Compare routine for std::lower_bound
name|bool
name|operator
operator|<
operator|(
name|StringRef
name|S
operator|)
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|Key
argument_list|)
operator|<
name|S
return|;
block|}
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// Manages the enabling and disabling of subtarget specific features.
comment|///
comment|/// Features are encoded as a string of the form
comment|///   "+attr1,+attr2,-attr3,...,+attrN"
comment|/// A comma separates each feature from the next (all lowercase.)
comment|/// Each of the remaining features is prefixed with + or - indicating whether
comment|/// that feature should be enabled or disabled contrary to the cpu
comment|/// specification.
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
block|;
comment|///< Subtarget features as a vector
name|public
operator|:
name|explicit
name|SubtargetFeatures
argument_list|(
argument|StringRef Initial =
literal|""
argument_list|)
block|;
comment|/// Returns features as a string.
name|std
operator|::
name|string
name|getString
argument_list|()
specifier|const
block|;
comment|/// Adds Features.
name|void
name|AddFeature
argument_list|(
argument|StringRef String
argument_list|,
argument|bool Enable = true
argument_list|)
block|;
comment|/// Toggles a feature and update the feature bits.
specifier|static
name|void
name|ToggleFeature
argument_list|(
argument|FeatureBitset&Bits
argument_list|,
argument|StringRef String
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> FeatureTable
argument_list|)
block|;
comment|/// Applies the feature flag and update the feature bits.
specifier|static
name|void
name|ApplyFeatureFlag
argument_list|(
argument|FeatureBitset&Bits
argument_list|,
argument|StringRef Feature
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> FeatureTable
argument_list|)
block|;
comment|/// Returns feature bits of a CPU.
name|FeatureBitset
name|getFeatureBits
argument_list|(
argument|StringRef CPU
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> CPUTable
argument_list|,
argument|ArrayRef<SubtargetFeatureKV> FeatureTable
argument_list|)
block|;
comment|/// Prints feature string.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|// Dumps feature info.
name|void
name|dump
argument_list|()
specifier|const
block|;
comment|/// Adds the default features for the specified target triple.
name|void
name|getDefaultSubtargetFeatures
argument_list|(
specifier|const
name|Triple
operator|&
name|Triple
argument_list|)
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_SUBTARGETFEATURE_H
end_comment

end_unit

