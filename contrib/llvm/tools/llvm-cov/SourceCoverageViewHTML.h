begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SourceCoverageViewHTML.h - A html code coverage view ---------------===//
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
comment|/// \file This file defines the interface to the html coverage renderer.
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
name|LLVM_COV_SOURCECOVERAGEVIEWHTML_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_COV_SOURCECOVERAGEVIEWHTML_H
end_define

begin_include
include|#
directive|include
file|"SourceCoverageView.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|FileCoverageSummary
struct_decl|;
comment|/// \brief A coverage printer for html output.
name|class
name|CoveragePrinterHTML
range|:
name|public
name|CoveragePrinter
block|{
name|public
operator|:
name|Expected
operator|<
name|OwnedStream
operator|>
name|createViewFile
argument_list|(
argument|StringRef Path
argument_list|,
argument|bool InToplevel
argument_list|)
name|override
block|;
name|void
name|closeViewFile
argument_list|(
argument|OwnedStream OS
argument_list|)
name|override
block|;
name|Error
name|createIndexFile
argument_list|(
argument|ArrayRef<std::string> SourceFiles
argument_list|,
argument|const coverage::CoverageMapping&Coverage
argument_list|)
name|override
block|;
name|CoveragePrinterHTML
argument_list|(
specifier|const
name|CoverageViewOptions
operator|&
name|Opts
argument_list|)
operator|:
name|CoveragePrinter
argument_list|(
argument|Opts
argument_list|)
block|{}
name|private
operator|:
name|void
name|emitFileSummary
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|StringRef SF
argument_list|,
argument|const FileCoverageSummary&FCS
argument_list|,
argument|bool IsTotals = false
argument_list|)
specifier|const
block|; }
decl_stmt|;
comment|/// \brief A code coverage view which supports html-based rendering.
name|class
name|SourceCoverageViewHTML
range|:
name|public
name|SourceCoverageView
block|{
name|void
name|renderViewHeader
argument_list|(
argument|raw_ostream&OS
argument_list|)
name|override
block|;
name|void
name|renderViewFooter
argument_list|(
argument|raw_ostream&OS
argument_list|)
name|override
block|;
name|void
name|renderSourceName
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool WholeFile
argument_list|)
name|override
block|;
name|void
name|renderLinePrefix
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderLineSuffix
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderViewDivider
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderLine
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|LineRef L
argument_list|,
argument|const coverage::CoverageSegment *WrappedSegment
argument_list|,
argument|CoverageSegmentArray Segments
argument_list|,
argument|unsigned ExpansionCol
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderExpansionSite
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|LineRef L
argument_list|,
argument|const coverage::CoverageSegment *WrappedSegment
argument_list|,
argument|CoverageSegmentArray Segments
argument_list|,
argument|unsigned ExpansionCol
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderExpansionView
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|ExpansionView&ESV
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderInstantiationView
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|InstantiationView&ISV
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderLineCoverageColumn
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const LineCoverageStats&Line
argument_list|)
name|override
block|;
name|void
name|renderLineNumberColumn
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned LineNo
argument_list|)
name|override
block|;
name|void
name|renderRegionMarkers
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|CoverageSegmentArray Segments
argument_list|,
argument|unsigned ViewDepth
argument_list|)
name|override
block|;
name|void
name|renderTitle
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|StringRef Title
argument_list|)
name|override
block|;
name|void
name|renderTableHeader
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|unsigned FirstUncoveredLineNo
argument_list|,
argument|unsigned IndentLevel
argument_list|)
name|override
block|;
name|public
operator|:
name|SourceCoverageViewHTML
argument_list|(
argument|StringRef SourceName
argument_list|,
argument|const MemoryBuffer&File
argument_list|,
argument|const CoverageViewOptions&Options
argument_list|,
argument|coverage::CoverageData&&CoverageInfo
argument_list|)
operator|:
name|SourceCoverageView
argument_list|(
argument|SourceName
argument_list|,
argument|File
argument_list|,
argument|Options
argument_list|,
argument|std::move(CoverageInfo)
argument_list|)
block|{   }
block|}
decl_stmt|;
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
comment|// LLVM_COV_SOURCECOVERAGEVIEWHTML_H
end_comment

end_unit

