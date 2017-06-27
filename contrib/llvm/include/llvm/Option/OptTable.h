begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OptTable.h - Option Table --------------------------------*- C++ -*-===//
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
name|LLVM_OPTION_OPTTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPTION_OPTTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
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
name|raw_ostream
decl_stmt|;
name|namespace
name|opt
block|{
name|class
name|Arg
decl_stmt|;
name|class
name|ArgList
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
name|class
name|Option
decl_stmt|;
comment|/// \brief Provide access to the Option info table.
comment|///
comment|/// The OptTable class provides a layer of indirection which allows Option
comment|/// instance to be created lazily. In the common case, only a few options will
comment|/// be needed at runtime; the OptTable class maintains enough information to
comment|/// parse command lines without instantiating Options, while letting other
comment|/// parts of the driver still use Option instances where convenient.
name|class
name|OptTable
block|{
name|public
label|:
comment|/// \brief Entry for a single option instance in the option data table.
struct|struct
name|Info
block|{
comment|/// A null terminated array of prefix strings to apply to name while
comment|/// matching.
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|Prefixes
decl_stmt|;
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
specifier|const
name|char
modifier|*
name|HelpText
decl_stmt|;
specifier|const
name|char
modifier|*
name|MetaVar
decl_stmt|;
name|unsigned
name|ID
decl_stmt|;
name|unsigned
name|char
name|Kind
decl_stmt|;
name|unsigned
name|char
name|Param
decl_stmt|;
name|unsigned
name|short
name|Flags
decl_stmt|;
name|unsigned
name|short
name|GroupID
decl_stmt|;
name|unsigned
name|short
name|AliasID
decl_stmt|;
specifier|const
name|char
modifier|*
name|AliasArgs
decl_stmt|;
specifier|const
name|char
modifier|*
name|Values
decl_stmt|;
block|}
struct|;
name|private
label|:
comment|/// \brief The static option information table.
name|ArrayRef
operator|<
name|Info
operator|>
name|OptionInfos
expr_stmt|;
name|bool
name|IgnoreCase
decl_stmt|;
name|unsigned
name|TheInputOptionID
init|=
literal|0
decl_stmt|;
name|unsigned
name|TheUnknownOptionID
init|=
literal|0
decl_stmt|;
comment|/// The index of the first option which can be parsed (i.e., is not a
comment|/// special option like 'input' or 'unknown', and is not an option group).
name|unsigned
name|FirstSearchableIndex
init|=
literal|0
decl_stmt|;
comment|/// The union of all option prefixes. If an argument does not begin with
comment|/// one of these, it is an input.
name|StringSet
operator|<
operator|>
name|PrefixesUnion
expr_stmt|;
name|std
operator|::
name|string
name|PrefixChars
expr_stmt|;
name|private
label|:
specifier|const
name|Info
modifier|&
name|getInfo
argument_list|(
name|OptSpecifier
name|Opt
argument_list|)
decl|const
block|{
name|unsigned
name|id
init|=
name|Opt
operator|.
name|getID
argument_list|()
decl_stmt|;
name|assert
argument_list|(
name|id
operator|>
literal|0
operator|&&
name|id
operator|-
literal|1
operator|<
name|getNumOptions
argument_list|()
operator|&&
literal|"Invalid Option ID."
argument_list|)
expr_stmt|;
return|return
name|OptionInfos
index|[
name|id
operator|-
literal|1
index|]
return|;
block|}
name|protected
label|:
name|OptTable
argument_list|(
argument|ArrayRef<Info> OptionInfos
argument_list|,
argument|bool IgnoreCase = false
argument_list|)
empty_stmt|;
name|public
label|:
operator|~
name|OptTable
argument_list|()
expr_stmt|;
comment|/// \brief Return the total number of option classes.
name|unsigned
name|getNumOptions
argument_list|()
specifier|const
block|{
return|return
name|OptionInfos
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// \brief Get the given Opt's Option instance, lazily creating it
comment|/// if necessary.
comment|///
comment|/// \return The option, or null for the INVALID option id.
specifier|const
name|Option
name|getOption
argument_list|(
name|OptSpecifier
name|Opt
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Lookup the name of the given option.
specifier|const
name|char
modifier|*
name|getOptionName
argument_list|(
name|OptSpecifier
name|id
argument_list|)
decl|const
block|{
return|return
name|getInfo
argument_list|(
name|id
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// \brief Get the kind of the given option.
name|unsigned
name|getOptionKind
argument_list|(
name|OptSpecifier
name|id
argument_list|)
decl|const
block|{
return|return
name|getInfo
argument_list|(
name|id
argument_list|)
operator|.
name|Kind
return|;
block|}
comment|/// \brief Get the group id for the given option.
name|unsigned
name|getOptionGroupID
argument_list|(
name|OptSpecifier
name|id
argument_list|)
decl|const
block|{
return|return
name|getInfo
argument_list|(
name|id
argument_list|)
operator|.
name|GroupID
return|;
block|}
comment|/// \brief Get the help text to use to describe this option.
specifier|const
name|char
modifier|*
name|getOptionHelpText
argument_list|(
name|OptSpecifier
name|id
argument_list|)
decl|const
block|{
return|return
name|getInfo
argument_list|(
name|id
argument_list|)
operator|.
name|HelpText
return|;
block|}
comment|/// \brief Get the meta-variable name to use when describing
comment|/// this options values in the help text.
specifier|const
name|char
modifier|*
name|getOptionMetaVar
argument_list|(
name|OptSpecifier
name|id
argument_list|)
decl|const
block|{
return|return
name|getInfo
argument_list|(
name|id
argument_list|)
operator|.
name|MetaVar
return|;
block|}
comment|/// Find possible value for given flags. This is used for shell
comment|/// autocompletion.
comment|///
comment|/// \param [in] Option - Key flag like "-stdlib=" when "-stdlib=l"
comment|/// was passed to clang.
comment|///
comment|/// \param [in] Arg - Value which we want to autocomplete like "l"
comment|/// when "-stdlib=l" was passed to clang.
comment|///
comment|/// \return The vector of possible values.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|suggestValueCompletions
argument_list|(
argument|StringRef Option
argument_list|,
argument|StringRef Arg
argument_list|)
specifier|const
expr_stmt|;
comment|/// Find flags from OptTable which starts with Cur.
comment|///
comment|/// \param [in] Cur - String prefix that all returned flags need
comment|//  to start with.
comment|///
comment|/// \return The vector of flags which start with Cur.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|findByPrefix
argument_list|(
argument|StringRef Cur
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Parse a single argument; returning the new argument and
comment|/// updating Index.
comment|///
comment|/// \param [in,out] Index - The current parsing position in the argument
comment|/// string list; on return this will be the index of the next argument
comment|/// string to parse.
comment|/// \param [in] FlagsToInclude - Only parse options with any of these flags.
comment|/// Zero is the default which includes all flags.
comment|/// \param [in] FlagsToExclude - Don't parse options with this flag.  Zero
comment|/// is the default and means exclude nothing.
comment|///
comment|/// \return The parsed argument, or 0 if the argument is missing values
comment|/// (in which case Index still points at the conceptual next argument string
comment|/// to parse).
name|Arg
modifier|*
name|ParseOneArg
argument_list|(
specifier|const
name|ArgList
operator|&
name|Args
argument_list|,
name|unsigned
operator|&
name|Index
argument_list|,
name|unsigned
name|FlagsToInclude
operator|=
literal|0
argument_list|,
name|unsigned
name|FlagsToExclude
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Parse an list of arguments into an InputArgList.
comment|///
comment|/// The resulting InputArgList will reference the strings in [\p ArgBegin,
comment|/// \p ArgEnd), and their lifetime should extend past that of the returned
comment|/// InputArgList.
comment|///
comment|/// The only error that can occur in this routine is if an argument is
comment|/// missing values; in this case \p MissingArgCount will be non-zero.
comment|///
comment|/// \param MissingArgIndex - On error, the index of the option which could
comment|/// not be parsed.
comment|/// \param MissingArgCount - On error, the number of missing options.
comment|/// \param FlagsToInclude - Only parse options with any of these flags.
comment|/// Zero is the default which includes all flags.
comment|/// \param FlagsToExclude - Don't parse options with this flag.  Zero
comment|/// is the default and means exclude nothing.
comment|/// \return An InputArgList; on error this will contain all the options
comment|/// which could be parsed.
name|InputArgList
name|ParseArgs
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|Args
argument_list|,
name|unsigned
operator|&
name|MissingArgIndex
argument_list|,
name|unsigned
operator|&
name|MissingArgCount
argument_list|,
name|unsigned
name|FlagsToInclude
operator|=
literal|0
argument_list|,
name|unsigned
name|FlagsToExclude
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Render the help text for an option table.
comment|///
comment|/// \param OS - The stream to write the help text to.
comment|/// \param Name - The name to use in the usage line.
comment|/// \param Title - The title to use in the usage line.
comment|/// \param FlagsToInclude - If non-zero, only include options with any
comment|///                         of these flags set.
comment|/// \param FlagsToExclude - Exclude options with any of these flags set.
name|void
name|PrintHelp
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|Title
argument_list|,
name|unsigned
name|FlagsToInclude
argument_list|,
name|unsigned
name|FlagsToExclude
argument_list|)
decl|const
decl_stmt|;
name|void
name|PrintHelp
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|Title
argument_list|,
name|bool
name|ShowHidden
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace opt
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
comment|// LLVM_OPTION_OPTTABLE_H
end_comment

end_unit

