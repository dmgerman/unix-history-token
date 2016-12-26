begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DependencyOutputOptions.h ------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_DEPENDENCYOUTPUTOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_DEPENDENCYOUTPUTOPTIONS_H
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
comment|/// DependencyOutputFormat - Format for the compiler dependency file.
name|enum
name|class
name|DependencyOutputFormat
block|{
name|Make
operator|,
name|NMake
block|}
empty_stmt|;
comment|/// DependencyOutputOptions - Options for controlling the compiler dependency
comment|/// file generation.
name|class
name|DependencyOutputOptions
block|{
name|public
label|:
name|unsigned
name|IncludeSystemHeaders
range|:
literal|1
decl_stmt|;
comment|///< Include system header dependencies.
name|unsigned
name|ShowHeaderIncludes
range|:
literal|1
decl_stmt|;
comment|///< Show header inclusions (-H).
name|unsigned
name|UsePhonyTargets
range|:
literal|1
decl_stmt|;
comment|///< Include phony targets for each
comment|/// dependency, which can avoid some 'make'
comment|/// problems.
name|unsigned
name|AddMissingHeaderDeps
range|:
literal|1
decl_stmt|;
comment|///< Add missing headers to dependency list
name|unsigned
name|PrintShowIncludes
range|:
literal|1
decl_stmt|;
comment|///< Print cl.exe style /showIncludes info.
name|unsigned
name|IncludeModuleFiles
range|:
literal|1
decl_stmt|;
comment|///< Include module file dependencies.
comment|/// The format for the dependency file.
name|DependencyOutputFormat
name|OutputFormat
decl_stmt|;
comment|/// The file to write dependency output to.
name|std
operator|::
name|string
name|OutputFile
expr_stmt|;
comment|/// The file to write header include output to. This is orthogonal to
comment|/// ShowHeaderIncludes (-H) and will include headers mentioned in the
comment|/// predefines buffer. If the output file is "-", output will be sent to
comment|/// stderr.
name|std
operator|::
name|string
name|HeaderIncludeOutputFile
expr_stmt|;
comment|/// A list of names to use as the targets in the dependency file; this list
comment|/// must contain at least one entry.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Targets
expr_stmt|;
comment|/// A list of filenames to be used as extra dependencies for every target.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ExtraDeps
expr_stmt|;
comment|/// In /showIncludes mode, pretend the main TU is a header with this name.
name|std
operator|::
name|string
name|ShowIncludesPretendHeader
expr_stmt|;
comment|/// \brief The file to write GraphViz-formatted header dependencies to.
name|std
operator|::
name|string
name|DOTOutputFile
expr_stmt|;
comment|/// \brief The directory to copy module dependencies to when collecting them.
name|std
operator|::
name|string
name|ModuleDependencyOutputDir
expr_stmt|;
name|public
label|:
name|DependencyOutputOptions
argument_list|()
block|{
name|IncludeSystemHeaders
operator|=
literal|0
expr_stmt|;
name|ShowHeaderIncludes
operator|=
literal|0
expr_stmt|;
name|UsePhonyTargets
operator|=
literal|0
expr_stmt|;
name|AddMissingHeaderDeps
operator|=
literal|0
expr_stmt|;
name|PrintShowIncludes
operator|=
literal|0
expr_stmt|;
name|IncludeModuleFiles
operator|=
literal|0
expr_stmt|;
name|OutputFormat
operator|=
name|DependencyOutputFormat
operator|::
name|Make
expr_stmt|;
block|}
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

