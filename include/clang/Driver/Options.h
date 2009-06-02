begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Options.h - Option info& table ------------------------*- C++ -*-===//
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
name|CLANG_DRIVER_OPTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_OPTIONS_H_
end_define

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
name|ID
block|{
name|OPT_INVALID
init|=
literal|0
block|,
comment|// This is not an option ID.
name|OPT_INPUT
block|,
comment|// Reserved ID for input option.
name|OPT_UNKNOWN
block|,
comment|// Reserved ID for unknown option.
define|#
directive|define
name|OPTION
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|,
name|KIND
parameter_list|,
name|GROUP
parameter_list|,
name|ALIAS
parameter_list|,
name|FLAGS
parameter_list|,
name|PARAM
parameter_list|, \
name|HELPTEXT
parameter_list|,
name|METAVAR
parameter_list|)
value|OPT_##ID,
include|#
directive|include
file|"clang/Driver/Options.def"
name|LastOption
undef|#
directive|undef
name|OPTION
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
comment|/// The OptTable class provides a layer of indirection which allows
comment|/// Option instance to be created lazily. In the common case, only a
comment|/// few options will be needed at runtime; the OptTable class
comment|/// maintains enough information to parse command lines without
comment|/// instantiating Options, while letting other parts of the driver
comment|/// still use Option instances where convient.
name|class
name|OptTable
block|{
comment|/// The table of options which have been constructed, indexed by
comment|/// option::ID - 1.
name|mutable
name|Option
modifier|*
modifier|*
name|Options
decl_stmt|;
comment|/// The index of the first option which can be parsed (i.e., is
comment|/// not a special option like 'input' or 'unknown', and is not an
comment|/// option group).
name|unsigned
name|FirstSearchableOption
decl_stmt|;
name|Option
modifier|*
name|constructOption
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|OptTable
argument_list|()
expr_stmt|;
operator|~
name|OptTable
argument_list|()
expr_stmt|;
name|unsigned
name|getNumOptions
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|getOptionName
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// getOption - Get the given \arg id's Option instance, lazily
comment|/// creating it if necessary.
specifier|const
name|Option
modifier|*
name|getOption
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// getOptionKind - Get the kind of the given option.
name|unsigned
name|getOptionKind
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// getOptionHelpText - Get the help text to use to describe this
comment|/// option.
specifier|const
name|char
modifier|*
name|getOptionHelpText
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// getOptionMetaVar - Get the meta-variable name to use when
comment|/// describing this options values in the help text.
specifier|const
name|char
modifier|*
name|getOptionMetaVar
argument_list|(
name|options
operator|::
name|ID
name|id
argument_list|)
decl|const
decl_stmt|;
comment|/// parseOneArg - Parse a single argument; returning the new
comment|/// argument and updating Index.
comment|///
comment|/// \param [in] [out] Index - The current parsing position in the
comment|/// argument string list; on return this will be the index of the
comment|/// next argument string to parse.
comment|///
comment|/// \return - The parsed argument, or 0 if the argument is missing
comment|/// values (in which case Index still points at the conceptual
comment|/// next argument string to parse).
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

