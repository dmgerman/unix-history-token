begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SubtargetFeatureInfo.h - Helpers for subtarget features ------------===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_UTIL_TABLEGEN_SUBTARGETFEATUREINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTIL_TABLEGEN_SUBTARGETFEATUREINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/TableGen/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/Record.h"
end_include

begin_include
include|#
directive|include
file|<map>
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
name|class
name|Record
decl_stmt|;
name|class
name|RecordKeeper
decl_stmt|;
comment|/// Helper class for storing information on a subtarget feature which
comment|/// participates in instruction matching.
struct|struct
name|SubtargetFeatureInfo
block|{
comment|/// \brief The predicate record for this feature.
name|Record
modifier|*
name|TheDef
decl_stmt|;
comment|/// \brief An unique index assigned to represent this feature.
name|uint64_t
name|Index
decl_stmt|;
name|SubtargetFeatureInfo
argument_list|(
argument|Record *D
argument_list|,
argument|uint64_t Idx
argument_list|)
block|:
name|TheDef
argument_list|(
name|D
argument_list|)
operator|,
name|Index
argument_list|(
argument|Idx
argument_list|)
block|{}
comment|/// \brief The name of the enumerated constant identifying this feature.
name|std
operator|::
name|string
name|getEnumName
argument_list|()
specifier|const
block|{
return|return
literal|"Feature_"
operator|+
name|TheDef
operator|->
name|getName
argument_list|()
operator|.
name|str
argument_list|()
return|;
block|}
comment|/// \brief The name of the enumerated constant identifying the bitnumber for
comment|/// this feature.
name|std
operator|::
name|string
name|getEnumBitName
argument_list|()
specifier|const
block|{
return|return
literal|"Feature_"
operator|+
name|TheDef
operator|->
name|getName
argument_list|()
operator|.
name|str
argument_list|()
operator|+
literal|"Bit"
return|;
block|}
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|Record
operator|*
operator|,
name|SubtargetFeatureInfo
operator|>>
name|getAll
argument_list|(
specifier|const
name|RecordKeeper
operator|&
name|Records
argument_list|)
expr_stmt|;
comment|/// Emit the subtarget feature flag definitions.
comment|///
comment|/// This version emits the bit value for the feature and is therefore limited
comment|/// to 64 feature bits.
specifier|static
name|void
name|emitSubtargetFeatureFlagEnumeration
argument_list|(
name|std
operator|::
name|map
operator|<
name|Record
operator|*
argument_list|,
name|SubtargetFeatureInfo
argument_list|,
name|LessRecordByID
operator|>
operator|&
name|SubtargetFeatures
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|/// Emit the subtarget feature flag definitions.
comment|///
comment|/// This version emits the bit index for the feature and can therefore support
comment|/// more than 64 feature bits.
specifier|static
name|void
name|emitSubtargetFeatureBitEnumeration
argument_list|(
name|std
operator|::
name|map
operator|<
name|Record
operator|*
argument_list|,
name|SubtargetFeatureInfo
argument_list|,
name|LessRecordByID
operator|>
operator|&
name|SubtargetFeatures
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
specifier|static
name|void
name|emitNameTable
argument_list|(
name|std
operator|::
name|map
operator|<
name|Record
operator|*
argument_list|,
name|SubtargetFeatureInfo
argument_list|,
name|LessRecordByID
operator|>
operator|&
name|SubtargetFeatures
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|/// Emit the function to compute the list of available features given a
comment|/// subtarget.
comment|///
comment|/// This version is used for subtarget features defined using Predicate<>
comment|/// and supports more than 64 feature bits.
comment|///
comment|/// \param TargetName The name of the target as used in class prefixes (e.g.
comment|///<TargetName>Subtarget)
comment|/// \param ClassName  The name of the class (without the<Target> prefix)
comment|///                   that will contain the generated functions.
comment|/// \param FuncName   The name of the function to emit.
comment|/// \param SubtargetFeatures A map of TableGen records to the
comment|///                          SubtargetFeatureInfo equivalent.
specifier|static
name|void
name|emitComputeAvailableFeatures
argument_list|(
name|StringRef
name|TargetName
argument_list|,
name|StringRef
name|ClassName
argument_list|,
name|StringRef
name|FuncName
argument_list|,
name|std
operator|::
name|map
operator|<
name|Record
operator|*
argument_list|,
name|SubtargetFeatureInfo
argument_list|,
name|LessRecordByID
operator|>
operator|&
name|SubtargetFeatures
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
comment|/// Emit the function to compute the list of available features given a
comment|/// subtarget.
comment|///
comment|/// This version is used for subtarget features defined using
comment|/// AssemblerPredicate<> and supports up to 64 feature bits.
comment|///
comment|/// \param TargetName The name of the target as used in class prefixes (e.g.
comment|///<TargetName>Subtarget)
comment|/// \param ClassName  The name of the class (without the<Target> prefix)
comment|///                   that will contain the generated functions.
comment|/// \param FuncName   The name of the function to emit.
comment|/// \param SubtargetFeatures A map of TableGen records to the
comment|///                          SubtargetFeatureInfo equivalent.
specifier|static
name|void
name|emitComputeAssemblerAvailableFeatures
argument_list|(
name|StringRef
name|TargetName
argument_list|,
name|StringRef
name|ClassName
argument_list|,
name|StringRef
name|FuncName
argument_list|,
name|std
operator|::
name|map
operator|<
name|Record
operator|*
argument_list|,
name|SubtargetFeatureInfo
argument_list|,
name|LessRecordByID
operator|>
operator|&
name|SubtargetFeatures
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_UTIL_TABLEGEN_SUBTARGETFEATUREINFO_H
end_comment

end_unit

