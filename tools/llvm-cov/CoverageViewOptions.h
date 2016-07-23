begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CoverageViewOptions.h - Code coverage display options -------------===//
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
name|LLVM_COV_COVERAGEVIEWOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_COVERAGEVIEWOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"RenderingSupport.h"
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
comment|/// \brief The options for displaying the code coverage information.
struct|struct
name|CoverageViewOptions
block|{
name|enum
name|class
name|OutputFormat
block|{
name|Text
operator|,
name|HTML
block|}
empty_stmt|;
name|bool
name|Debug
decl_stmt|;
name|bool
name|Colors
decl_stmt|;
name|bool
name|ShowLineNumbers
decl_stmt|;
name|bool
name|ShowLineStats
decl_stmt|;
name|bool
name|ShowRegionMarkers
decl_stmt|;
name|bool
name|ShowLineStatsOrRegionMarkers
decl_stmt|;
name|bool
name|ShowExpandedRegions
decl_stmt|;
name|bool
name|ShowFunctionInstantiations
decl_stmt|;
name|bool
name|ShowFullFilenames
decl_stmt|;
name|OutputFormat
name|Format
decl_stmt|;
name|std
operator|::
name|string
name|ShowOutputDirectory
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|DemanglerOpts
expr_stmt|;
comment|/// \brief Change the output's stream color if the colors are enabled.
name|ColoredRawOstream
name|colored_ostream
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|raw_ostream
operator|::
name|Colors
name|Color
argument_list|)
decl|const
block|{
return|return
name|llvm
operator|::
name|colored_ostream
argument_list|(
name|OS
argument_list|,
name|Color
argument_list|,
name|Colors
argument_list|)
return|;
block|}
comment|/// \brief Check if an output directory has been specified.
name|bool
name|hasOutputDirectory
argument_list|()
specifier|const
block|{
return|return
operator|!
name|ShowOutputDirectory
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Check if a demangler has been specified.
name|bool
name|hasDemangler
argument_list|()
specifier|const
block|{
return|return
operator|!
name|DemanglerOpts
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_COV_COVERAGEVIEWOPTIONS_H
end_comment

end_unit

