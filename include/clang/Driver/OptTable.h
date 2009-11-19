begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OptTable.h - Option Table ------------------------------*- C++ -*-===//
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
name|CLANG_DRIVER_OPTTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_OPTTABLE_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/OptSpecifier.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|options
block|{
enum|enum
name|DriverFlag
block|{
name|DriverOption
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|LinkerInput
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|NoArgumentUnused
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|RenderAsInput
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|RenderJoined
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|RenderSeparate
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|Unsupported
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|}
enum|;
block|}
name|class
name|Arg
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
name|class
name|Option
decl_stmt|;
comment|/// OptTable - Provide access to the Option info table.
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
comment|/// Info - Entry for a single option instance in the option data table.
struct|struct
name|Info
block|{
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
name|char
name|Kind
decl_stmt|;
name|unsigned
name|char
name|Flags
decl_stmt|;
name|unsigned
name|char
name|Param
decl_stmt|;
name|unsigned
name|short
name|GroupID
decl_stmt|;
name|unsigned
name|short
name|AliasID
decl_stmt|;
block|}
struct|;
name|private
label|:
comment|/// The static option information table.
specifier|const
name|Info
modifier|*
name|OptionInfos
decl_stmt|;
name|unsigned
name|NumOptionInfos
decl_stmt|;
comment|/// The lazily constructed options table, indexed by option::ID - 1.
name|mutable
name|Option
modifier|*
modifier|*
name|Options
decl_stmt|;
comment|/// Prebound input option instance.
specifier|const
name|Option
modifier|*
name|TheInputOption
decl_stmt|;
comment|/// Prebound unknown option instance.
specifier|const
name|Option
modifier|*
name|TheUnknownOption
decl_stmt|;
comment|/// The index of the first option which can be parsed (i.e., is not a
comment|/// special option like 'input' or 'unknown', and is not an option group).
name|unsigned
name|FirstSearchableIndex
decl_stmt|;
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
name|Option
modifier|*
name|CreateOption
argument_list|(
name|unsigned
name|id
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
name|OptTable
argument_list|(
argument|const Info *_OptionInfos
argument_list|,
argument|unsigned _NumOptionInfos
argument_list|)
empty_stmt|;
name|public
label|:
operator|~
name|OptTable
argument_list|()
expr_stmt|;
comment|/// getNumOptions - Return the total number of option classes.
name|unsigned
name|getNumOptions
argument_list|()
specifier|const
block|{
return|return
name|NumOptionInfos
return|;
block|}
comment|/// getOption - Get the given \arg id's Option instance, lazily creating it
comment|/// if necessary.
comment|///
comment|/// \return The option, or null for the INVALID option id.
specifier|const
name|Option
modifier|*
name|getOption
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
if|if
condition|(
name|id
operator|==
literal|0
condition|)
return|return
literal|0
return|;
name|assert
argument_list|(
call|(
name|unsigned
call|)
argument_list|(
name|id
operator|-
literal|1
argument_list|)
operator|<
name|getNumOptions
argument_list|()
operator|&&
literal|"Invalid ID."
argument_list|)
expr_stmt|;
name|Option
modifier|*
modifier|&
name|Entry
init|=
name|Options
index|[
name|id
operator|-
literal|1
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|Entry
condition|)
name|Entry
operator|=
name|CreateOption
argument_list|(
name|id
argument_list|)
expr_stmt|;
return|return
name|Entry
return|;
block|}
comment|/// getOptionName - Lookup the name of the given option.
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
comment|/// getOptionKind - Get the kind of the given option.
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
comment|/// getOptionHelpText - Get the help text to use to describe this option.
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
comment|/// getOptionMetaVar - Get the meta-variable name to use when describing
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
comment|/// ParseOneArg - Parse a single argument; returning the new argument and
comment|/// updating Index.
comment|///
comment|/// \param [in] [out] Index - The current parsing position in the argument
comment|/// string list; on return this will be the index of the next argument
comment|/// string to parse.
comment|///
comment|/// \return - The parsed argument, or 0 if the argument is missing values
comment|/// (in which case Index still points at the conceptual next argument string
comment|/// to parse).
name|Arg
modifier|*
name|ParseOneArg
argument_list|(
specifier|const
name|InputArgList
operator|&
name|Args
argument_list|,
name|unsigned
operator|&
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// ParseArgs - Parse an list of arguments into an InputArgList.
comment|///
comment|/// The resulting InputArgList will reference the strings in [ArgBegin,
comment|/// ArgEnd), and their lifetime should extend past that of the returned
comment|/// InputArgList.
comment|///
comment|/// The only error that can occur in this routine is if an argument is
comment|/// missing values; in this case \arg MissingArgCount will be non-zero.
comment|///
comment|/// \param ArgBegin - The beginning of the argument vector.
comment|/// \param ArgEnd - The end of the argument vector.
comment|/// \param MissingArgIndex - On error, the index of the option which could
comment|/// not be parsed.
comment|/// \param MissingArgCount - On error, the number of missing options.
comment|/// \return - An InputArgList; on error this will contain all the options
comment|/// which could be parsed.
name|InputArgList
modifier|*
name|ParseArgs
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|ArgBegin
argument_list|,
specifier|const
name|char
operator|*
operator|*
name|ArgEnd
argument_list|,
name|unsigned
operator|&
name|MissingArgIndex
argument_list|,
name|unsigned
operator|&
name|MissingArgCount
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

