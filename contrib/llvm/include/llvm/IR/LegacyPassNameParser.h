begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LegacyPassNameParser.h -----------------------------------*- C++ -*-===//
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
comment|// This file contains the PassNameParser and FilteredPassNameParser<> classes,
end_comment

begin_comment
comment|// which are used to add command line arguments to a utility for all of the
end_comment

begin_comment
comment|// passes that have been registered into the system.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The PassNameParser class adds ALL passes linked into the system (that are
end_comment

begin_comment
comment|// creatable) as command line arguments to the tool (when instantiated with the
end_comment

begin_comment
comment|// appropriate command line option template).  The FilteredPassNameParser<>
end_comment

begin_comment
comment|// template is used for the same purposes as PassNameParser, except that it only
end_comment

begin_comment
comment|// includes passes that have a PassType that are compatible with the filter
end_comment

begin_comment
comment|// (which is the template argument).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that this is part of the legacy pass manager infrastructure and will be
end_comment

begin_comment
comment|// (eventually) going away.
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
name|LLVM_IR_LEGACYPASSNAMEPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_LEGACYPASSNAMEPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// PassNameParser class - Make use of the pass registration mechanism to
comment|// automatically add a command line argument to opt for each pass.
comment|//
name|class
name|PassNameParser
range|:
name|public
name|PassRegistrationListener
decl_stmt|,
name|public
name|cl
decl|::
name|parser
decl|<const
name|PassInfo
modifier|*
decl|>
block|{
name|public
label|:
name|PassNameParser
argument_list|(
name|cl
operator|::
name|Option
operator|&
name|O
argument_list|)
expr_stmt|;
operator|~
name|PassNameParser
argument_list|()
name|override
expr_stmt|;
name|void
name|initialize
parameter_list|()
block|{
name|cl
operator|::
name|parser
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|::
name|initialize
argument_list|()
expr_stmt|;
comment|// Add all of the passes to the map that got initialized before 'this' did.
name|enumeratePasses
argument_list|()
expr_stmt|;
block|}
comment|// ignorablePassImpl - Can be overriden in subclasses to refine the list of
comment|// which passes we want to include.
comment|//
name|virtual
name|bool
name|ignorablePassImpl
argument_list|(
specifier|const
name|PassInfo
operator|*
name|P
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
specifier|inline
name|bool
name|ignorablePass
argument_list|(
specifier|const
name|PassInfo
operator|*
name|P
argument_list|)
decl|const
block|{
comment|// Ignore non-selectable and non-constructible passes!  Ignore
comment|// non-optimizations.
return|return
name|P
operator|->
name|getPassArgument
argument_list|()
operator|.
name|empty
argument_list|()
operator|||
name|P
operator|->
name|getNormalCtor
argument_list|()
operator|==
name|nullptr
operator|||
name|ignorablePassImpl
argument_list|(
name|P
argument_list|)
return|;
block|}
comment|// Implement the PassRegistrationListener callbacks used to populate our map
comment|//
name|void
name|passRegistered
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|P
parameter_list|)
function|override
block|{
if|if
condition|(
name|ignorablePass
argument_list|(
name|P
argument_list|)
condition|)
return|return;
if|if
condition|(
name|findOption
argument_list|(
name|P
operator|->
name|getPassArgument
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
operator|!=
name|getNumOptions
argument_list|()
condition|)
block|{
name|errs
argument_list|()
operator|<<
literal|"Two passes with the same argument (-"
operator|<<
name|P
operator|->
name|getPassArgument
argument_list|()
operator|<<
literal|") attempted to be registered!\n"
expr_stmt|;
name|llvm_unreachable
argument_list|(
name|nullptr
argument_list|)
expr_stmt|;
block|}
name|addLiteralOption
argument_list|(
name|P
operator|->
name|getPassArgument
argument_list|()
operator|.
name|data
argument_list|()
argument_list|,
name|P
argument_list|,
name|P
operator|->
name|getPassName
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|passEnumerate
parameter_list|(
specifier|const
name|PassInfo
modifier|*
name|P
parameter_list|)
function|override
block|{
name|passRegistered
argument_list|(
name|P
argument_list|)
expr_stmt|;
block|}
comment|// printOptionInfo - Print out information about this option.  Override the
comment|// default implementation to sort the table before we print...
name|void
name|printOptionInfo
argument_list|(
specifier|const
name|cl
operator|::
name|Option
operator|&
name|O
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
name|override
block|{
name|PassNameParser
modifier|*
name|PNP
init|=
name|const_cast
operator|<
name|PassNameParser
operator|*
operator|>
operator|(
name|this
operator|)
decl_stmt|;
name|array_pod_sort
argument_list|(
name|PNP
operator|->
name|Values
operator|.
name|begin
argument_list|()
argument_list|,
name|PNP
operator|->
name|Values
operator|.
name|end
argument_list|()
argument_list|,
name|ValCompare
argument_list|)
expr_stmt|;
name|cl
operator|::
name|parser
operator|<
specifier|const
name|PassInfo
operator|*
operator|>
operator|::
name|printOptionInfo
argument_list|(
name|O
argument_list|,
name|GlobalWidth
argument_list|)
expr_stmt|;
block|}
name|private
label|:
comment|// ValCompare - Provide a sorting comparator for Values elements...
specifier|static
name|int
name|ValCompare
argument_list|(
specifier|const
name|PassNameParser
operator|::
name|OptionInfo
operator|*
name|VT1
argument_list|,
specifier|const
name|PassNameParser
operator|::
name|OptionInfo
operator|*
name|VT2
argument_list|)
block|{
return|return
name|VT1
operator|->
name|Name
operator|.
name|compare
argument_list|(
name|VT2
operator|->
name|Name
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|///===----------------------------------------------------------------------===//
comment|/// FilteredPassNameParser class - Make use of the pass registration
comment|/// mechanism to automatically add a command line argument to opt for
comment|/// each pass that satisfies a filter criteria.  Filter should return
comment|/// true for passes to be registered as command-line options.
comment|///
name|template
operator|<
name|typename
name|Filter
operator|>
name|class
name|FilteredPassNameParser
operator|:
name|public
name|PassNameParser
block|{
name|private
operator|:
name|Filter
name|filter
block|;
name|public
operator|:
name|bool
name|ignorablePassImpl
argument_list|(
argument|const PassInfo *P
argument_list|)
specifier|const
name|override
block|{
return|return
operator|!
name|filter
argument_list|(
operator|*
name|P
argument_list|)
return|;
block|}
expr|}
block|;
comment|///===----------------------------------------------------------------------===//
comment|/// PassArgFilter - A filter for use with PassNameFilterParser that only
comment|/// accepts a Pass whose Arg matches certain strings.
comment|///
comment|/// Use like this:
comment|///
comment|/// extern const char AllowedPassArgs[] = "-anders_aa -dse";
comment|///
comment|/// static cl::list<
comment|///   const PassInfo*,
comment|///   bool,
comment|///   FilteredPassNameParser<PassArgFilter<AllowedPassArgs>>>
comment|/// PassList(cl::desc("Passes available:"));
comment|///
comment|/// Only the -anders_aa and -dse options will be available to the user.
comment|///
name|template
operator|<
specifier|const
name|char
operator|*
name|Args
operator|>
name|class
name|PassArgFilter
block|{
name|public
operator|:
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|PassInfo
operator|&
name|P
operator|)
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|Args
argument_list|)
operator|.
name|contains
argument_list|(
name|P
operator|.
name|getPassArgument
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

