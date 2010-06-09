begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Tool.h - The LLVM Compiler Driver ----------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open
end_comment

begin_comment
comment|// Source License. See LICENSE.TXT for details.
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
comment|//  Tool abstract base class - an interface to tool descriptions.
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
name|LLVM_INCLUDE_COMPILER_DRIVER_TOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INCLUDE_COMPILER_DRIVER_TOOL_H
end_define

begin_include
include|#
directive|include
file|"llvm/CompilerDriver/Action.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
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

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvmc
block|{
name|class
name|LanguageMap
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|std
operator|::
name|string
operator|>
expr|>
name|ArgsVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|sys
operator|::
name|Path
operator|>
name|PathVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|StrVector
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|StringSet
operator|<
operator|>
name|InputLanguagesSet
expr_stmt|;
comment|/// Tool - Represents a single tool.
name|class
name|Tool
range|:
name|public
name|llvm
operator|::
name|RefCountedBaseVPTR
operator|<
name|Tool
operator|>
block|{
name|public
operator|:
name|virtual
operator|~
name|Tool
argument_list|()
block|{}
name|virtual
name|Action
name|GenerateAction
argument_list|(
argument|const PathVector& inFiles
argument_list|,
argument|bool  HasChildren
argument_list|,
argument|const llvm::sys::Path& TempDir
argument_list|,
argument|const InputLanguagesSet& InLangs
argument_list|,
argument|const LanguageMap& LangMap
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|Action
name|GenerateAction
argument_list|(
argument|const llvm::sys::Path& inFile
argument_list|,
argument|bool  HasChildren
argument_list|,
argument|const llvm::sys::Path& TempDir
argument_list|,
argument|const InputLanguagesSet& InLangs
argument_list|,
argument|const LanguageMap& LangMap
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|char
operator|*
name|Name
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|char
operator|*
operator|*
name|InputLanguages
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|char
operator|*
name|OutputLanguage
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsJoin
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|WorksOnEmpty
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|protected
operator|:
comment|/// OutFileName - Generate the output file name.
name|llvm
operator|::
name|sys
operator|::
name|Path
name|OutFilename
argument_list|(
argument|const llvm::sys::Path& In
argument_list|,
argument|const llvm::sys::Path& TempDir
argument_list|,
argument|bool StopCompilation
argument_list|,
argument|const char* OutputSuffix
argument_list|)
specifier|const
block|;
name|StrVector
name|SortArgs
argument_list|(
argument|ArgsVector& Args
argument_list|)
specifier|const
block|;   }
decl_stmt|;
comment|/// JoinTool - A Tool that has an associated input file list.
name|class
name|JoinTool
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|void
name|AddToJoinList
argument_list|(
argument|const llvm::sys::Path& P
argument_list|)
block|{
name|JoinList_
operator|.
name|push_back
argument_list|(
name|P
argument_list|)
block|; }
name|void
name|ClearJoinList
argument_list|()
block|{
name|JoinList_
operator|.
name|clear
argument_list|()
block|; }
name|bool
name|JoinListEmpty
argument_list|()
specifier|const
block|{
return|return
name|JoinList_
operator|.
name|empty
argument_list|()
return|;
block|}
name|Action
name|GenerateAction
argument_list|(
argument|bool  HasChildren
argument_list|,
argument|const llvm::sys::Path& TempDir
argument_list|,
argument|const InputLanguagesSet& InLangs
argument_list|,
argument|const LanguageMap& LangMap
argument_list|)
specifier|const
block|{
return|return
name|GenerateAction
argument_list|(
name|JoinList_
argument_list|,
name|HasChildren
argument_list|,
name|TempDir
argument_list|,
name|InLangs
argument_list|,
name|LangMap
argument_list|)
return|;
block|}
comment|// We shouldn't shadow base class's version of GenerateAction.
name|using
name|Tool
operator|::
name|GenerateAction
block|;
name|private
operator|:
name|PathVector
name|JoinList_
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_INCLUDE_COMPILER_DRIVER_TOOL_H
end_comment

end_unit

