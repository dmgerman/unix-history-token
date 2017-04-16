begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FuzzerMerge.h - merging corpa ----------------------------*- C++ -* ===//
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
comment|// Merging Corpora.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The task:
end_comment

begin_comment
comment|//   Take the existing corpus (possibly empty) and merge new inputs into
end_comment

begin_comment
comment|//   it so that only inputs with new coverage ('features') are added.
end_comment

begin_comment
comment|//   The process should tolerate the crashes, OOMs, leaks, etc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Algorithm:
end_comment

begin_comment
comment|//   The outter process collects the set of files and writes their names
end_comment

begin_comment
comment|//   into a temporary "control" file, then repeatedly launches the inner
end_comment

begin_comment
comment|//   process until all inputs are processed.
end_comment

begin_comment
comment|//   The outer process does not actually execute the target code.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   The inner process reads the control file and sees a) list of all the inputs
end_comment

begin_comment
comment|//   and b) the last processed input. Then it starts processing the inputs one
end_comment

begin_comment
comment|//   by one. Before processing every input it writes one line to control file:
end_comment

begin_comment
comment|//   STARTED INPUT_ID INPUT_SIZE
end_comment

begin_comment
comment|//   After processing an input it write another line:
end_comment

begin_comment
comment|//   DONE INPUT_ID Feature1 Feature2 Feature3 ...
end_comment

begin_comment
comment|//   If a crash happens while processing an input the last line in the control
end_comment

begin_comment
comment|//   file will be "STARTED INPUT_ID" and so the next process will know
end_comment

begin_comment
comment|//   where to resume.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Once all inputs are processed by the innner process(es) the outer process
end_comment

begin_comment
comment|//   reads the control files and does the merge based entirely on the contents
end_comment

begin_comment
comment|//   of control file.
end_comment

begin_comment
comment|//   It uses a single pass greedy algorithm choosing first the smallest inputs
end_comment

begin_comment
comment|//   within the same size the inputs that have more new features.
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
name|LLVM_FUZZER_MERGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_FUZZER_MERGE_H
end_define

begin_include
include|#
directive|include
file|"FuzzerDefs.h"
end_include

begin_include
include|#
directive|include
file|<istream>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|fuzzer
block|{
struct|struct
name|MergeFileInfo
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|size_t
name|Size
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|Features
expr_stmt|;
block|}
struct|;
struct|struct
name|Merger
block|{
name|std
operator|::
name|vector
operator|<
name|MergeFileInfo
operator|>
name|Files
expr_stmt|;
name|size_t
name|NumFilesInFirstCorpus
init|=
literal|0
decl_stmt|;
name|size_t
name|FirstNotProcessedFile
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|string
name|LastFailure
expr_stmt|;
name|bool
name|Parse
argument_list|(
name|std
operator|::
name|istream
operator|&
name|IS
argument_list|,
name|bool
name|ParseCoverage
argument_list|)
decl_stmt|;
name|bool
name|Parse
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|,
name|bool
name|ParseCoverage
argument_list|)
decl_stmt|;
name|void
name|ParseOrExit
argument_list|(
name|std
operator|::
name|istream
operator|&
name|IS
argument_list|,
name|bool
name|ParseCoverage
argument_list|)
decl_stmt|;
name|void
name|PrintSummary
argument_list|(
name|std
operator|::
name|ostream
operator|&
name|OS
argument_list|)
decl_stmt|;
name|std
operator|::
name|set
operator|<
name|uint32_t
operator|>
name|ParseSummary
argument_list|(
name|std
operator|::
name|istream
operator|&
name|IS
argument_list|)
expr_stmt|;
name|size_t
name|Merge
argument_list|(
specifier|const
name|std
operator|::
name|set
operator|<
name|uint32_t
operator|>
operator|&
name|InitialFeatures
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|*
name|NewFiles
argument_list|)
decl_stmt|;
name|size_t
name|Merge
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|*
name|NewFiles
argument_list|)
block|{
return|return
name|Merge
argument_list|(
block|{}
argument_list|,
name|NewFiles
argument_list|)
return|;
block|}
name|size_t
name|ApproximateMemoryConsumption
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|set
operator|<
name|uint32_t
operator|>
name|AllFeatures
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace fuzzer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_FUZZER_MERGE_H
end_comment

end_unit

