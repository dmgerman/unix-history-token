begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/DebugCounter.h - Debug counter support ------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file provides an implementation of debug counters.  Debug
end_comment

begin_comment
comment|/// counters are a tool that let you narrow down a miscompilation to a specific
end_comment

begin_comment
comment|/// thing happening.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// To give a use case: Imagine you have a file, very large, and you
end_comment

begin_comment
comment|/// are trying to understand the minimal transformation that breaks it. Bugpoint
end_comment

begin_comment
comment|/// and bisection is often helpful here in narrowing it down to a specific pass,
end_comment

begin_comment
comment|/// but it's still a very large file, and a very complicated pass to try to
end_comment

begin_comment
comment|/// debug.  That is where debug counting steps in.  You can instrument the pass
end_comment

begin_comment
comment|/// with a debug counter before it does a certain thing, and depending on the
end_comment

begin_comment
comment|/// counts, it will either execute that thing or not.  The debug counter itself
end_comment

begin_comment
comment|/// consists of a skip and a count.  Skip is the number of times shouldExecute
end_comment

begin_comment
comment|/// needs to be called before it returns true.  Count is the number of times to
end_comment

begin_comment
comment|/// return true once Skip is 0.  So a skip=47, count=2 ,would skip the first 47
end_comment

begin_comment
comment|/// executions by returning false from shouldExecute, then execute twice, and
end_comment

begin_comment
comment|/// then return false again.
end_comment

begin_comment
comment|/// Note that a counter set to a negative number will always execute.
end_comment

begin_comment
comment|/// For a concrete example, during predicateinfo creation, the renaming pass
end_comment

begin_comment
comment|/// replaces each use with a renamed use.
end_comment

begin_comment
comment|////
end_comment

begin_comment
comment|/// If I use DEBUG_COUNTER to create a counter called "predicateinfo", and
end_comment

begin_comment
comment|/// variable name RenameCounter, and then instrument this renaming with a debug
end_comment

begin_comment
comment|/// counter, like so:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// if (!DebugCounter::shouldExecute(RenameCounter)
end_comment

begin_comment
comment|///<continue or return or whatever not executing looks like>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Now I can, from the command line, make it rename or not rename certain uses
end_comment

begin_comment
comment|/// by setting the skip and count.
end_comment

begin_comment
comment|/// So for example
end_comment

begin_comment
comment|/// bin/opt -debug-counter=predicateinfo-skip=47,predicateinfo-count=1
end_comment

begin_comment
comment|/// will skip renaming the first 47 uses, then rename one, then skip the rest.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_DEBUGCOUNTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DEBUGCOUNTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/UniqueVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DebugCounter
block|{
name|public
label|:
comment|/// \brief Returns a reference to the singleton instance.
specifier|static
name|DebugCounter
modifier|&
name|instance
parameter_list|()
function_decl|;
comment|// Used by the command line option parser to push a new value it parsed.
name|void
name|push_back
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
comment|// Register a counter with the specified name.
comment|//
comment|// FIXME: Currently, counter registration is required to happen before command
comment|// line option parsing. The main reason to register counters is to produce a
comment|// nice list of them on the command line, but i'm not sure this is worth it.
specifier|static
name|unsigned
name|registerCounter
parameter_list|(
name|StringRef
name|Name
parameter_list|,
name|StringRef
name|Desc
parameter_list|)
block|{
return|return
name|instance
argument_list|()
operator|.
name|addCounter
argument_list|(
name|Name
argument_list|,
name|Desc
argument_list|)
return|;
block|}
specifier|inline
specifier|static
name|bool
name|shouldExecute
parameter_list|(
name|unsigned
name|CounterName
parameter_list|)
block|{
comment|// Compile to nothing when debugging is off
ifdef|#
directive|ifdef
name|NDEBUG
return|return
name|true
return|;
else|#
directive|else
name|auto
operator|&
name|Us
operator|=
name|instance
argument_list|()
expr_stmt|;
name|auto
name|Result
init|=
name|Us
operator|.
name|Counters
operator|.
name|find
argument_list|(
name|CounterName
argument_list|)
decl_stmt|;
if|if
condition|(
name|Result
operator|!=
name|Us
operator|.
name|Counters
operator|.
name|end
argument_list|()
condition|)
block|{
name|auto
operator|&
name|CounterPair
operator|=
name|Result
operator|->
name|second
expr_stmt|;
comment|// We only execute while the skip (first) is zero and the count (second)
comment|// is non-zero.
comment|// Negative counters always execute.
if|if
condition|(
name|CounterPair
operator|.
name|first
operator|<
literal|0
condition|)
return|return
name|true
return|;
if|if
condition|(
name|CounterPair
operator|.
name|first
operator|!=
literal|0
condition|)
block|{
operator|--
name|CounterPair
operator|.
name|first
expr_stmt|;
return|return
name|false
return|;
block|}
if|if
condition|(
name|CounterPair
operator|.
name|second
operator|<
literal|0
condition|)
return|return
name|true
return|;
if|if
condition|(
name|CounterPair
operator|.
name|second
operator|!=
literal|0
condition|)
block|{
operator|--
name|CounterPair
operator|.
name|second
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|// Didn't find the counter, should we warn?
return|return
name|true
return|;
endif|#
directive|endif
comment|// NDEBUG
block|}
comment|// Return true if a given counter had values set (either programatically or on
comment|// the command line).  This will return true even if those values are
comment|// currently in a state where the counter will always execute.
specifier|static
name|bool
name|isCounterSet
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
return|return
name|instance
argument_list|()
operator|.
name|Counters
operator|.
name|count
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|// Return the skip and count for a counter. This only works for set counters.
specifier|static
name|std
operator|::
name|pair
operator|<
name|int
operator|,
name|int
operator|>
name|getCounterValue
argument_list|(
argument|unsigned ID
argument_list|)
block|{
name|auto
operator|&
name|Us
operator|=
name|instance
argument_list|()
block|;
name|auto
name|Result
operator|=
name|Us
operator|.
name|Counters
operator|.
name|find
argument_list|(
name|ID
argument_list|)
block|;
name|assert
argument_list|(
name|Result
operator|!=
name|Us
operator|.
name|Counters
operator|.
name|end
argument_list|()
operator|&&
literal|"Asking about a non-set counter"
argument_list|)
block|;
return|return
name|Result
operator|->
name|second
return|;
block|}
comment|// Set a registered counter to a given value.
specifier|static
name|void
name|setCounterValue
argument_list|(
name|unsigned
name|ID
argument_list|,
specifier|const
name|std
operator|::
name|pair
operator|<
name|int
argument_list|,
name|int
operator|>
operator|&
name|Val
argument_list|)
block|{
name|auto
operator|&
name|Us
operator|=
name|instance
argument_list|()
expr_stmt|;
name|Us
operator|.
name|Counters
index|[
name|ID
index|]
operator|=
name|Val
expr_stmt|;
block|}
comment|// Dump or print the current counter set into llvm::dbgs().
name|LLVM_DUMP_METHOD
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|// Get the counter ID for a given named counter, or return 0 if none is found.
name|unsigned
name|getCounterId
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl|const
block|{
return|return
name|RegisteredCounters
operator|.
name|idFor
argument_list|(
name|Name
argument_list|)
return|;
block|}
comment|// Return the number of registered counters.
name|unsigned
name|int
name|getNumCounters
argument_list|()
specifier|const
block|{
return|return
name|RegisteredCounters
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Return the name and description of the counter with the given ID.
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|std
operator|::
name|string
operator|>
name|getCounterInfo
argument_list|(
argument|unsigned ID
argument_list|)
specifier|const
block|{
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|RegisteredCounters
index|[
name|ID
index|]
argument_list|,
name|CounterDesc
operator|.
name|lookup
argument_list|(
name|ID
argument_list|)
argument_list|)
return|;
block|}
comment|// Iterate through the registered counters
typedef|typedef
name|UniqueVector
operator|<
name|std
operator|::
name|string
operator|>
name|CounterVector
expr_stmt|;
name|CounterVector
operator|::
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|RegisteredCounters
operator|.
name|begin
argument_list|()
return|;
block|}
name|CounterVector
operator|::
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|RegisteredCounters
operator|.
name|end
argument_list|()
return|;
block|}
name|private
label|:
name|unsigned
name|addCounter
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Desc
argument_list|)
block|{
name|unsigned
name|Result
init|=
name|RegisteredCounters
operator|.
name|insert
argument_list|(
name|Name
argument_list|)
decl_stmt|;
name|CounterDesc
index|[
name|Result
index|]
operator|=
name|Desc
expr_stmt|;
return|return
name|Result
return|;
block|}
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|pair
operator|<
name|long
operator|,
name|long
operator|>>
name|Counters
expr_stmt|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|string
operator|>
name|CounterDesc
expr_stmt|;
name|CounterVector
name|RegisteredCounters
decl_stmt|;
block|}
empty_stmt|;
define|#
directive|define
name|DEBUG_COUNTER
parameter_list|(
name|VARNAME
parameter_list|,
name|COUNTERNAME
parameter_list|,
name|DESC
parameter_list|)
define|\
value|static const unsigned VARNAME =                                              \       DebugCounter::registerCounter(COUNTERNAME, DESC);
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

