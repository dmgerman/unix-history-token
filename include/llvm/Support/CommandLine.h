begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/CommandLine.h - Command line handler --------*- C++ -*-===//
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
comment|// This class implements a command line argument processor that is useful when
end_comment

begin_comment
comment|// creating a tool.  It provides a simple, minimalistic interface that is easily
end_comment

begin_comment
comment|// extensible and supports nonlocal (library) command line options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that rather than trying to figure out what this code does, you should
end_comment

begin_comment
comment|// read the library documentation located in docs/CommandLine.html or looks at
end_comment

begin_comment
comment|// the many example usages in tools/*/*.cpp
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
name|LLVM_SUPPORT_COMMANDLINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_COMMANDLINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<utility>
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
comment|/// cl Namespace - This namespace contains all of the command line option
comment|/// processing machinery.  It is intentionally a short name to make qualified
comment|/// usage concise.
name|namespace
name|cl
block|{
comment|//===----------------------------------------------------------------------===//
comment|// ParseCommandLineOptions - Command line option processing entry point.
comment|//
name|void
name|ParseCommandLineOptions
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
name|Overview
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|// ParseEnvironmentOptions - Environment variable option processing alternate
comment|//                           entry point.
comment|//
name|void
name|ParseEnvironmentOptions
parameter_list|(
specifier|const
name|char
modifier|*
name|progName
parameter_list|,
specifier|const
name|char
modifier|*
name|envvar
parameter_list|,
specifier|const
name|char
modifier|*
name|Overview
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|///===---------------------------------------------------------------------===//
comment|/// SetVersionPrinter - Override the default (LLVM specific) version printer
comment|///                     used to print out the version when --version is given
comment|///                     on the command line. This allows other systems using the
comment|///                     CommandLine utilities to print their own version string.
name|void
name|SetVersionPrinter
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
comment|///===---------------------------------------------------------------------===//
comment|/// AddExtraVersionPrinter - Add an extra printer to use in addition to the
comment|///                          default one. This can be called multiple times,
comment|///                          and each time it adds a new function to the list
comment|///                          which will be called after the basic LLVM version
comment|///                          printing is complete. Each can then add additional
comment|///                          information specific to the tool.
name|void
name|AddExtraVersionPrinter
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
comment|// PrintOptionValues - Print option values.
comment|// With -print-options print the difference between option values and defaults.
comment|// With -print-all-options print all option values.
comment|// (Currently not perfect, but best-effort.)
name|void
name|PrintOptionValues
parameter_list|()
function_decl|;
comment|// Forward declaration - AddLiteralOption needs to be up here to make gcc happy.
name|class
name|Option
decl_stmt|;
comment|/// \brief Adds a new option for parsing and provides the option it refers to.
comment|///
comment|/// \param O pointer to the option
comment|/// \param Name the string name for the option to handle during parsing
comment|///
comment|/// Literal options are used by some parsers to register special option values.
comment|/// This is how the PassNameParser registers pass names for opt.
name|void
name|AddLiteralOption
parameter_list|(
name|Option
modifier|&
name|O
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|//===----------------------------------------------------------------------===//
comment|// Flags permitted to be passed to command line arguments
comment|//
enum|enum
name|NumOccurrencesFlag
block|{
comment|// Flags for the number of occurrences allowed
name|Optional
init|=
literal|0x00
block|,
comment|// Zero or One occurrence
name|ZeroOrMore
init|=
literal|0x01
block|,
comment|// Zero or more occurrences allowed
name|Required
init|=
literal|0x02
block|,
comment|// One occurrence required
name|OneOrMore
init|=
literal|0x03
block|,
comment|// One or more occurrences required
comment|// ConsumeAfter - Indicates that this option is fed anything that follows the
comment|// last positional argument required by the application (it is an error if
comment|// there are zero positional arguments, and a ConsumeAfter option is used).
comment|// Thus, for example, all arguments to LLI are processed until a filename is
comment|// found.  Once a filename is found, all of the succeeding arguments are
comment|// passed, unprocessed, to the ConsumeAfter option.
comment|//
name|ConsumeAfter
init|=
literal|0x04
block|}
enum|;
enum|enum
name|ValueExpected
block|{
comment|// Is a value required for the option?
comment|// zero reserved for the unspecified value
name|ValueOptional
init|=
literal|0x01
block|,
comment|// The value can appear... or not
name|ValueRequired
init|=
literal|0x02
block|,
comment|// The value is required to appear!
name|ValueDisallowed
init|=
literal|0x03
comment|// A value may not be specified (for flags)
block|}
enum|;
enum|enum
name|OptionHidden
block|{
comment|// Control whether -help shows this option
name|NotHidden
init|=
literal|0x00
block|,
comment|// Option included in -help& -help-hidden
name|Hidden
init|=
literal|0x01
block|,
comment|// -help doesn't, but -help-hidden does
name|ReallyHidden
init|=
literal|0x02
comment|// Neither -help nor -help-hidden show this arg
block|}
enum|;
comment|// Formatting flags - This controls special features that the option might have
comment|// that cause it to be parsed differently...
comment|//
comment|// Prefix - This option allows arguments that are otherwise unrecognized to be
comment|// matched by options that are a prefix of the actual value.  This is useful for
comment|// cases like a linker, where options are typically of the form '-lfoo' or
comment|// '-L../../include' where -l or -L are the actual flags.  When prefix is
comment|// enabled, and used, the value for the flag comes from the suffix of the
comment|// argument.
comment|//
comment|// Grouping - With this option enabled, multiple letter options are allowed to
comment|// bunch together with only a single hyphen for the whole group.  This allows
comment|// emulation of the behavior that ls uses for example: ls -la === ls -l -a
comment|//
enum|enum
name|FormattingFlags
block|{
name|NormalFormatting
init|=
literal|0x00
block|,
comment|// Nothing special
name|Positional
init|=
literal|0x01
block|,
comment|// Is a positional argument, no '-' required
name|Prefix
init|=
literal|0x02
block|,
comment|// Can this option directly prefix its value?
name|Grouping
init|=
literal|0x03
comment|// Can this option group with other options?
block|}
enum|;
enum|enum
name|MiscFlags
block|{
comment|// Miscellaneous flags to adjust argument
name|CommaSeparated
init|=
literal|0x01
block|,
comment|// Should this cl::list split between commas?
name|PositionalEatsArgs
init|=
literal|0x02
block|,
comment|// Should this positional cl::list eat -args?
name|Sink
init|=
literal|0x04
comment|// Should this cl::list eat all unknown options?
block|}
enum|;
comment|//===----------------------------------------------------------------------===//
comment|// Option Category class
comment|//
name|class
name|OptionCategory
block|{
name|private
label|:
specifier|const
name|char
modifier|*
specifier|const
name|Name
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|Description
decl_stmt|;
name|void
name|registerCategory
parameter_list|()
function_decl|;
name|public
label|:
name|OptionCategory
argument_list|(
specifier|const
name|char
operator|*
specifier|const
name|Name
argument_list|,
specifier|const
name|char
operator|*
specifier|const
name|Description
operator|=
name|nullptr
argument_list|)
operator|:
name|Name
argument_list|(
name|Name
argument_list|)
operator|,
name|Description
argument_list|(
argument|Description
argument_list|)
block|{
name|registerCategory
argument_list|()
block|;   }
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|char
operator|*
name|getDescription
argument_list|()
specifier|const
block|{
return|return
name|Description
return|;
block|}
block|}
empty_stmt|;
comment|// The general Option Category (used as default category).
specifier|extern
name|OptionCategory
name|GeneralCategory
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Option Base class
comment|//
name|class
name|alias
decl_stmt|;
name|class
name|Option
block|{
name|friend
name|class
name|alias
decl_stmt|;
comment|// handleOccurrences - Overriden by subclasses to handle the value passed into
comment|// an argument.  Should return true if there was an error processing the
comment|// argument and the program should exit.
comment|//
name|virtual
name|bool
name|handleOccurrence
parameter_list|(
name|unsigned
name|pos
parameter_list|,
name|StringRef
name|ArgName
parameter_list|,
name|StringRef
name|Arg
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
expr|enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
block|{
return|return
name|ValueOptional
return|;
block|}
comment|// Out of line virtual function to provide home for the class.
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|int
name|NumOccurrences
decl_stmt|;
comment|// The number of times specified
comment|// Occurrences, HiddenFlag, and Formatting are all enum types but to avoid
comment|// problems with signed enums in bitfields.
name|unsigned
name|Occurrences
range|:
literal|3
decl_stmt|;
comment|// enum NumOccurrencesFlag
comment|// not using the enum type for 'Value' because zero is an implementation
comment|// detail representing the non-value
name|unsigned
name|Value
range|:
literal|2
decl_stmt|;
name|unsigned
name|HiddenFlag
range|:
literal|2
decl_stmt|;
comment|// enum OptionHidden
name|unsigned
name|Formatting
range|:
literal|2
decl_stmt|;
comment|// enum FormattingFlags
name|unsigned
name|Misc
range|:
literal|3
decl_stmt|;
name|unsigned
name|Position
decl_stmt|;
comment|// Position of last occurrence of the option
name|unsigned
name|AdditionalVals
decl_stmt|;
comment|// Greater than 0 for multi-valued option.
name|public
label|:
specifier|const
name|char
modifier|*
name|ArgStr
decl_stmt|;
comment|// The argument string itself (ex: "help", "o")
specifier|const
name|char
modifier|*
name|HelpStr
decl_stmt|;
comment|// The descriptive text message for -help
specifier|const
name|char
modifier|*
name|ValueStr
decl_stmt|;
comment|// String describing what the value of this option is
name|OptionCategory
modifier|*
name|Category
decl_stmt|;
comment|// The Category this option belongs to
name|bool
name|FullyInitialized
decl_stmt|;
comment|// Has addArguemnt been called?
specifier|inline
expr|enum
name|NumOccurrencesFlag
name|getNumOccurrencesFlag
argument_list|()
specifier|const
block|{
return|return
operator|(
expr|enum
name|NumOccurrencesFlag
operator|)
name|Occurrences
return|;
block|}
specifier|inline
expr|enum
name|ValueExpected
name|getValueExpectedFlag
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|?
operator|(
operator|(
expr|enum
name|ValueExpected
operator|)
name|Value
operator|)
operator|:
name|getValueExpectedFlagDefault
argument_list|()
return|;
block|}
specifier|inline
expr|enum
name|OptionHidden
name|getOptionHiddenFlag
argument_list|()
specifier|const
block|{
return|return
operator|(
expr|enum
name|OptionHidden
operator|)
name|HiddenFlag
return|;
block|}
specifier|inline
expr|enum
name|FormattingFlags
name|getFormattingFlag
argument_list|()
specifier|const
block|{
return|return
operator|(
expr|enum
name|FormattingFlags
operator|)
name|Formatting
return|;
block|}
specifier|inline
name|unsigned
name|getMiscFlags
argument_list|()
specifier|const
block|{
return|return
name|Misc
return|;
block|}
specifier|inline
name|unsigned
name|getPosition
argument_list|()
specifier|const
block|{
return|return
name|Position
return|;
block|}
specifier|inline
name|unsigned
name|getNumAdditionalVals
argument_list|()
specifier|const
block|{
return|return
name|AdditionalVals
return|;
block|}
comment|// hasArgStr - Return true if the argstr != ""
name|bool
name|hasArgStr
argument_list|()
specifier|const
block|{
return|return
name|ArgStr
index|[
literal|0
index|]
operator|!=
literal|0
return|;
block|}
comment|//-------------------------------------------------------------------------===
comment|// Accessor functions set by OptionModifiers
comment|//
name|void
name|setArgStr
parameter_list|(
specifier|const
name|char
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|setDescription
parameter_list|(
specifier|const
name|char
modifier|*
name|S
parameter_list|)
block|{
name|HelpStr
operator|=
name|S
expr_stmt|;
block|}
name|void
name|setValueStr
parameter_list|(
specifier|const
name|char
modifier|*
name|S
parameter_list|)
block|{
name|ValueStr
operator|=
name|S
expr_stmt|;
block|}
name|void
name|setNumOccurrencesFlag
parameter_list|(
name|enum
name|NumOccurrencesFlag
name|Val
parameter_list|)
block|{
name|Occurrences
operator|=
name|Val
expr_stmt|;
block|}
name|void
name|setValueExpectedFlag
parameter_list|(
name|enum
name|ValueExpected
name|Val
parameter_list|)
block|{
name|Value
operator|=
name|Val
expr_stmt|;
block|}
name|void
name|setHiddenFlag
parameter_list|(
name|enum
name|OptionHidden
name|Val
parameter_list|)
block|{
name|HiddenFlag
operator|=
name|Val
expr_stmt|;
block|}
name|void
name|setFormattingFlag
parameter_list|(
name|enum
name|FormattingFlags
name|V
parameter_list|)
block|{
name|Formatting
operator|=
name|V
expr_stmt|;
block|}
name|void
name|setMiscFlag
parameter_list|(
name|enum
name|MiscFlags
name|M
parameter_list|)
block|{
name|Misc
operator||=
name|M
expr_stmt|;
block|}
name|void
name|setPosition
parameter_list|(
name|unsigned
name|pos
parameter_list|)
block|{
name|Position
operator|=
name|pos
expr_stmt|;
block|}
name|void
name|setCategory
parameter_list|(
name|OptionCategory
modifier|&
name|C
parameter_list|)
block|{
name|Category
operator|=
operator|&
name|C
expr_stmt|;
block|}
name|protected
label|:
name|explicit
name|Option
argument_list|(
argument|enum NumOccurrencesFlag OccurrencesFlag
argument_list|,
argument|enum OptionHidden Hidden
argument_list|)
block|:
name|NumOccurrences
argument_list|(
literal|0
argument_list|)
operator|,
name|Occurrences
argument_list|(
name|OccurrencesFlag
argument_list|)
operator|,
name|Value
argument_list|(
literal|0
argument_list|)
operator|,
name|HiddenFlag
argument_list|(
name|Hidden
argument_list|)
operator|,
name|Formatting
argument_list|(
name|NormalFormatting
argument_list|)
operator|,
name|Misc
argument_list|(
literal|0
argument_list|)
operator|,
name|Position
argument_list|(
literal|0
argument_list|)
operator|,
name|AdditionalVals
argument_list|(
literal|0
argument_list|)
operator|,
name|ArgStr
argument_list|(
literal|""
argument_list|)
operator|,
name|HelpStr
argument_list|(
literal|""
argument_list|)
operator|,
name|ValueStr
argument_list|(
literal|""
argument_list|)
operator|,
name|Category
argument_list|(
operator|&
name|GeneralCategory
argument_list|)
operator|,
name|FullyInitialized
argument_list|(
argument|false
argument_list|)
block|{}
specifier|inline
name|void
name|setNumAdditionalVals
argument_list|(
argument|unsigned n
argument_list|)
block|{
name|AdditionalVals
operator|=
name|n
block|; }
name|public
operator|:
comment|// addArgument - Register this argument with the commandline system.
comment|//
name|void
name|addArgument
argument_list|()
expr_stmt|;
comment|/// Unregisters this option from the CommandLine system.
comment|///
comment|/// This option must have been the last option registered.
comment|/// For testing purposes only.
name|void
name|removeArgument
parameter_list|()
function_decl|;
comment|// Return the width of the option tag for printing...
name|virtual
name|size_t
name|getOptionWidth
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// printOptionInfo - Print out information about this option.  The
comment|// to-be-maintained width is specified.
comment|//
name|virtual
name|void
name|printOptionInfo
argument_list|(
name|size_t
name|GlobalWidth
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|printOptionValue
argument_list|(
name|size_t
name|GlobalWidth
argument_list|,
name|bool
name|Force
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|getExtraOptionNames
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
argument_list|)
block|{}
comment|// addOccurrence - Wrapper around handleOccurrence that enforces Flags.
comment|//
name|virtual
name|bool
name|addOccurrence
parameter_list|(
name|unsigned
name|pos
parameter_list|,
name|StringRef
name|ArgName
parameter_list|,
name|StringRef
name|Value
parameter_list|,
name|bool
name|MultiArg
init|=
name|false
parameter_list|)
function_decl|;
comment|// Prints option name followed by message.  Always returns true.
name|bool
name|error
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Message
parameter_list|,
name|StringRef
name|ArgName
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
name|public
label|:
specifier|inline
name|int
name|getNumOccurrences
argument_list|()
specifier|const
block|{
return|return
name|NumOccurrences
return|;
block|}
name|virtual
operator|~
name|Option
argument_list|()
block|{}
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Command line option modifiers that can be used to modify the behavior of
comment|// command line option parsers...
comment|//
comment|// desc - Modifier to set the description shown in the -help output...
struct|struct
name|desc
block|{
specifier|const
name|char
modifier|*
name|Desc
decl_stmt|;
name|desc
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
operator|:
name|Desc
argument_list|(
argument|Str
argument_list|)
block|{}
name|void
name|apply
argument_list|(
argument|Option&O
argument_list|)
specifier|const
block|{
name|O
operator|.
name|setDescription
argument_list|(
name|Desc
argument_list|)
block|; }
block|}
struct|;
comment|// value_desc - Modifier to set the value description shown in the -help
comment|// output...
struct|struct
name|value_desc
block|{
specifier|const
name|char
modifier|*
name|Desc
decl_stmt|;
name|value_desc
argument_list|(
specifier|const
name|char
operator|*
name|Str
argument_list|)
operator|:
name|Desc
argument_list|(
argument|Str
argument_list|)
block|{}
name|void
name|apply
argument_list|(
argument|Option&O
argument_list|)
specifier|const
block|{
name|O
operator|.
name|setValueStr
argument_list|(
name|Desc
argument_list|)
block|; }
block|}
struct|;
comment|// init - Specify a default (initial) value for the command line argument, if
comment|// the default constructor for the argument type does not give you what you
comment|// want.  This is only valid on "opt" arguments, not on "list" arguments.
comment|//
name|template
operator|<
name|class
name|Ty
operator|>
expr|struct
name|initializer
block|{
specifier|const
name|Ty
operator|&
name|Init
block|;
name|initializer
argument_list|(
specifier|const
name|Ty
operator|&
name|Val
argument_list|)
operator|:
name|Init
argument_list|(
argument|Val
argument_list|)
block|{}
name|template
operator|<
name|class
name|Opt
operator|>
name|void
name|apply
argument_list|(
argument|Opt&O
argument_list|)
specifier|const
block|{
name|O
operator|.
name|setInitialValue
argument_list|(
name|Init
argument_list|)
block|; }
block|}
expr_stmt|;
name|template
operator|<
name|class
name|Ty
operator|>
name|initializer
operator|<
name|Ty
operator|>
name|init
argument_list|(
argument|const Ty&Val
argument_list|)
block|{
return|return
name|initializer
operator|<
name|Ty
operator|>
operator|(
name|Val
operator|)
return|;
block|}
comment|// location - Allow the user to specify which external variable they want to
comment|// store the results of the command line argument processing into, if they don't
comment|// want to store it in the option itself.
comment|//
name|template
operator|<
name|class
name|Ty
operator|>
expr|struct
name|LocationClass
block|{
name|Ty
operator|&
name|Loc
block|;
name|LocationClass
argument_list|(
name|Ty
operator|&
name|L
argument_list|)
operator|:
name|Loc
argument_list|(
argument|L
argument_list|)
block|{}
name|template
operator|<
name|class
name|Opt
operator|>
name|void
name|apply
argument_list|(
argument|Opt&O
argument_list|)
specifier|const
block|{
name|O
operator|.
name|setLocation
argument_list|(
name|O
argument_list|,
name|Loc
argument_list|)
block|; }
block|}
expr_stmt|;
name|template
operator|<
name|class
name|Ty
operator|>
name|LocationClass
operator|<
name|Ty
operator|>
name|location
argument_list|(
argument|Ty&L
argument_list|)
block|{
return|return
name|LocationClass
operator|<
name|Ty
operator|>
operator|(
name|L
operator|)
return|;
block|}
comment|// cat - Specifiy the Option category for the command line argument to belong
comment|// to.
struct|struct
name|cat
block|{
name|OptionCategory
modifier|&
name|Category
decl_stmt|;
name|cat
argument_list|(
name|OptionCategory
operator|&
name|c
argument_list|)
operator|:
name|Category
argument_list|(
argument|c
argument_list|)
block|{}
name|template
operator|<
name|class
name|Opt
operator|>
name|void
name|apply
argument_list|(
argument|Opt&O
argument_list|)
specifier|const
block|{
name|O
operator|.
name|setCategory
argument_list|(
name|Category
argument_list|)
block|; }
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|// OptionValue class
comment|// Support value comparison outside the template.
struct|struct
name|GenericOptionValue
block|{
name|virtual
name|bool
name|compare
argument_list|(
specifier|const
name|GenericOptionValue
operator|&
name|V
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|protected
label|:
operator|~
name|GenericOptionValue
argument_list|()
operator|=
expr|default
expr_stmt|;
name|GenericOptionValue
argument_list|()
operator|=
expr|default
expr_stmt|;
name|GenericOptionValue
argument_list|(
specifier|const
name|GenericOptionValue
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|GenericOptionValue
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GenericOptionValue
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
block|}
struct|;
name|template
operator|<
name|class
name|DataType
operator|>
expr|struct
name|OptionValue
expr_stmt|;
comment|// The default value safely does nothing. Option value printing is only
comment|// best-effort.
name|template
operator|<
name|class
name|DataType
operator|,
name|bool
name|isClass
operator|>
expr|struct
name|OptionValueBase
operator|:
name|public
name|GenericOptionValue
block|{
comment|// Temporary storage for argument passing.
typedef|typedef
name|OptionValue
operator|<
name|DataType
operator|>
name|WrapperType
expr_stmt|;
name|bool
name|hasValue
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
specifier|const
name|DataType
operator|&
name|getValue
argument_list|()
specifier|const
block|{
name|llvm_unreachable
argument_list|(
literal|"no default value"
argument_list|)
block|; }
comment|// Some options may take their value from a different data type.
name|template
operator|<
name|class
name|DT
operator|>
name|void
name|setValue
argument_list|(
argument|const DT&
comment|/*V*/
argument_list|)
block|{}
name|bool
name|compare
argument_list|(
argument|const DataType&
comment|/*V*/
argument_list|)
specifier|const
block|{
return|return
name|false
return|;
block|}
name|bool
name|compare
argument_list|(
specifier|const
name|GenericOptionValue
operator|&
comment|/*V*/
argument_list|)
decl|const
name|override
block|{
return|return
name|false
return|;
block|}
name|protected
label|:
operator|~
name|OptionValueBase
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
empty_stmt|;
comment|// Simple copy of the option value.
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|OptionValueCopy
operator|:
name|public
name|GenericOptionValue
block|{
name|DataType
name|Value
block|;
name|bool
name|Valid
block|;
name|protected
operator|:
operator|~
name|OptionValueCopy
argument_list|()
operator|=
expr|default
block|;
name|OptionValueCopy
argument_list|(
specifier|const
name|OptionValueCopy
operator|&
argument_list|)
operator|=
expr|default
block|;
name|OptionValueCopy
operator|&
name|operator
operator|=
operator|(
specifier|const
name|OptionValueCopy
operator|&
operator|)
operator|=
expr|default
block|;
name|public
operator|:
name|OptionValueCopy
argument_list|()
operator|:
name|Valid
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|hasValue
argument_list|()
specifier|const
block|{
return|return
name|Valid
return|;
block|}
specifier|const
name|DataType
operator|&
name|getValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Valid
operator|&&
literal|"invalid option value"
argument_list|)
block|;
return|return
name|Value
return|;
block|}
name|void
name|setValue
argument_list|(
argument|const DataType&V
argument_list|)
block|{
name|Valid
operator|=
name|true
block|;
name|Value
operator|=
name|V
block|;   }
name|bool
name|compare
argument_list|(
argument|const DataType&V
argument_list|)
specifier|const
block|{
return|return
name|Valid
operator|&&
operator|(
name|Value
operator|!=
name|V
operator|)
return|;
block|}
name|bool
name|compare
argument_list|(
argument|const GenericOptionValue&V
argument_list|)
specifier|const
name|override
block|{
specifier|const
name|OptionValueCopy
operator|<
name|DataType
operator|>
operator|&
name|VC
operator|=
name|static_cast
operator|<
specifier|const
name|OptionValueCopy
operator|<
name|DataType
operator|>
operator|&
operator|>
operator|(
name|V
operator|)
block|;
if|if
condition|(
operator|!
name|VC
operator|.
name|hasValue
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|compare
argument_list|(
name|VC
operator|.
name|getValue
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Non-class option values.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
expr|struct
name|OptionValueBase
operator|<
name|DataType
operator|,
name|false
operator|>
operator|:
name|OptionValueCopy
operator|<
name|DataType
operator|>
block|{
typedef|typedef
name|DataType
name|WrapperType
typedef|;
name|protected
operator|:
operator|~
name|OptionValueBase
argument_list|()
operator|=
block|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OptionValueBase
argument_list|()
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|OptionValueBase
argument_list|(
specifier|const
name|OptionValueBase
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|OptionValueBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|OptionValueBase
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// Top-level option class.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
expr|struct
name|OptionValue
name|final
operator|:
name|OptionValueBase
operator|<
name|DataType
operator|,
name|std
operator|::
name|is_class
operator|<
name|DataType
operator|>
operator|::
name|value
operator|>
block|{
name|OptionValue
argument_list|()
operator|=
expr|default
block|;
name|OptionValue
argument_list|(
argument|const DataType&V
argument_list|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|V
argument_list|)
block|; }
comment|// Some options may take their value from a different data type.
name|template
operator|<
name|class
name|DT
operator|>
name|OptionValue
operator|<
name|DataType
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|DT
operator|&
name|V
operator|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|V
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Other safe-to-copy-by-value common option types.
end_comment

begin_enum
enum|enum
name|boolOrDefault
block|{
name|BOU_UNSET
block|,
name|BOU_TRUE
block|,
name|BOU_FALSE
block|}
enum|;
end_enum

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|OptionValue
operator|<
name|cl
operator|::
name|boolOrDefault
operator|>
name|final
operator|:
name|OptionValueCopy
operator|<
name|cl
operator|::
name|boolOrDefault
operator|>
block|{
typedef|typedef
name|cl
operator|::
name|boolOrDefault
name|WrapperType
expr_stmt|;
name|OptionValue
argument_list|()
block|{}
name|OptionValue
argument_list|(
argument|const cl::boolOrDefault&V
argument_list|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|V
argument_list|)
block|; }
name|OptionValue
operator|<
name|cl
operator|::
name|boolOrDefault
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|cl
operator|::
name|boolOrDefault
operator|&
name|V
operator|)
block|{
name|setValue
argument_list|(
name|V
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|OptionValue
operator|<
name|std
operator|::
name|string
operator|>
name|final
operator|:
name|OptionValueCopy
operator|<
name|std
operator|::
name|string
operator|>
block|{
typedef|typedef
name|StringRef
name|WrapperType
typedef|;
name|OptionValue
argument_list|()
block|{}
name|OptionValue
argument_list|(
argument|const std::string&V
argument_list|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|V
argument_list|)
block|; }
name|OptionValue
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|operator
operator|=
operator|(
specifier|const
name|std
operator|::
name|string
operator|&
name|V
operator|)
block|{
name|setValue
argument_list|(
name|V
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Enum valued command line option
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|clEnumVal
parameter_list|(
name|ENUMVAL
parameter_list|,
name|DESC
parameter_list|)
value|#ENUMVAL, int(ENUMVAL), DESC
end_define

begin_define
define|#
directive|define
name|clEnumValN
parameter_list|(
name|ENUMVAL
parameter_list|,
name|FLAGNAME
parameter_list|,
name|DESC
parameter_list|)
value|FLAGNAME, int(ENUMVAL), DESC
end_define

begin_define
define|#
directive|define
name|clEnumValEnd
value|(reinterpret_cast<void *>(0))
end_define

begin_comment
comment|// values - For custom data types, allow specifying a group of values together
end_comment

begin_comment
comment|// as the values that go into the mapping that the option handler uses.  Note
end_comment

begin_comment
comment|// that the values list must always have a 0 at the end of the list to indicate
end_comment

begin_comment
comment|// that the list has ended.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|ValuesClass
block|{
comment|// Use a vector instead of a map, because the lists should be short,
comment|// the overhead is less, and most importantly, it keeps them in the order
comment|// inserted so we can print our option out nicely.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|char
operator|*
block|,
name|std
operator|::
name|pair
operator|<
name|int
block|,
specifier|const
name|char
operator|*
operator|>>
block|,
literal|4
operator|>
name|Values
block|;
name|void
name|processValues
argument_list|(
argument|va_list Vals
argument_list|)
block|;
name|public
operator|:
name|ValuesClass
argument_list|(
argument|const char *EnumName
argument_list|,
argument|DataType Val
argument_list|,
argument|const char *Desc
argument_list|,
argument|va_list ValueArgs
argument_list|)
block|{
comment|// Insert the first value, which is required.
name|Values
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|EnumName
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|Val
argument_list|,
name|Desc
argument_list|)
argument_list|)
argument_list|)
block|;
comment|// Process the varargs portion of the values...
while|while
condition|(
specifier|const
name|char
modifier|*
name|enumName
init|=
name|va_arg
argument_list|(
name|ValueArgs
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
condition|)
block|{
name|DataType
name|EnumVal
init|=
name|static_cast
operator|<
name|DataType
operator|>
operator|(
name|va_arg
argument_list|(
name|ValueArgs
argument_list|,
name|int
argument_list|)
operator|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|EnumDesc
init|=
name|va_arg
argument_list|(
name|ValueArgs
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
decl_stmt|;
name|Values
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|enumName
argument_list|,
comment|// Add value to value map
name|std
operator|::
name|make_pair
argument_list|(
name|EnumVal
argument_list|,
name|EnumDesc
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|template
operator|<
name|class
name|Opt
operator|>
name|void
name|apply
argument_list|(
argument|Opt&O
argument_list|)
specifier|const
block|{
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|Values
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|O
operator|.
name|getParser
argument_list|()
operator|.
name|addLiteralOption
argument_list|(
name|Values
index|[
name|i
index|]
operator|.
name|first
argument_list|,
name|Values
index|[
name|i
index|]
operator|.
name|second
operator|.
name|first
argument_list|,
name|Values
index|[
name|i
index|]
operator|.
name|second
operator|.
name|second
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|DataType
operator|>
name|ValuesClass
operator|<
name|DataType
operator|>
name|LLVM_END_WITH_NULL
name|values
argument_list|(
argument|const char *Arg
argument_list|,
argument|DataType Val
argument_list|,
argument|const char *Desc
argument_list|,
argument|...
argument_list|)
block|{
name|va_list
name|ValueArgs
block|;
name|va_start
argument_list|(
name|ValueArgs
argument_list|,
name|Desc
argument_list|)
block|;
name|ValuesClass
operator|<
name|DataType
operator|>
name|Vals
argument_list|(
name|Arg
argument_list|,
name|Val
argument_list|,
name|Desc
argument_list|,
name|ValueArgs
argument_list|)
block|;
name|va_end
argument_list|(
name|ValueArgs
argument_list|)
block|;
return|return
name|Vals
return|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// parser class - Parameterizable parser for different data types.  By default,
end_comment

begin_comment
comment|// known data types (string, int, bool) have specialized parsers, that do what
end_comment

begin_comment
comment|// you would expect.  The default parser, used for data types that are not
end_comment

begin_comment
comment|// built-in, uses a mapping table to map specific options to values, which is
end_comment

begin_comment
comment|// used, among other things, to handle enum types.
end_comment

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// generic_parser_base - This class holds all the non-generic code that we do
end_comment

begin_comment
comment|// not need replicated for every instance of the generic parser.  This also
end_comment

begin_comment
comment|// allows us to put stuff into CommandLine.cpp
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|generic_parser_base
block|{
name|protected
label|:
name|class
name|GenericOptionInfo
block|{
name|public
label|:
name|GenericOptionInfo
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|helpStr
argument_list|)
operator|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|HelpStr
argument_list|(
argument|helpStr
argument_list|)
block|{}
specifier|const
name|char
operator|*
name|Name
expr_stmt|;
specifier|const
name|char
modifier|*
name|HelpStr
decl_stmt|;
block|}
empty_stmt|;
name|public
label|:
name|generic_parser_base
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|Owner
argument_list|(
argument|O
argument_list|)
block|{}
name|virtual
operator|~
name|generic_parser_base
argument_list|()
block|{}
comment|// Base class should have virtual-dtor
comment|// getNumOptions - Virtual function implemented by generic subclass to
comment|// indicate how many entries are in Values.
comment|//
name|virtual
name|unsigned
name|getNumOptions
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// getOption - Return option name N.
name|virtual
specifier|const
name|char
modifier|*
name|getOption
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// getDescription - Return description N
name|virtual
specifier|const
name|char
modifier|*
name|getDescription
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Return the width of the option tag for printing...
name|virtual
name|size_t
name|getOptionWidth
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
name|virtual
specifier|const
name|GenericOptionValue
modifier|&
name|getOptionValue
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// printOptionInfo - Print out information about this option.  The
comment|// to-be-maintained width is specified.
comment|//
name|virtual
name|void
name|printOptionInfo
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
name|void
name|printGenericOptionDiff
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
specifier|const
name|GenericOptionValue
operator|&
name|V
argument_list|,
specifier|const
name|GenericOptionValue
operator|&
name|Default
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
comment|// printOptionDiff - print the value of an option and it's default.
comment|//
comment|// Template definition ensures that the option and default have the same
comment|// DataType (via the same AnyOptionValue).
name|template
operator|<
name|class
name|AnyOptionValue
operator|>
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|const AnyOptionValue&V
argument_list|,
argument|const AnyOptionValue&Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
block|{
name|printGenericOptionDiff
argument_list|(
name|O
argument_list|,
name|V
argument_list|,
name|Default
argument_list|,
name|GlobalWidth
argument_list|)
block|;   }
name|void
name|initialize
argument_list|()
block|{}
name|void
name|getExtraOptionNames
argument_list|(
argument|SmallVectorImpl<const char *>&OptionNames
argument_list|)
block|{
comment|// If there has been no argstr specified, that means that we need to add an
comment|// argument for every possible option.  This ensures that our options are
comment|// vectored to us.
if|if
condition|(
operator|!
name|Owner
operator|.
name|hasArgStr
argument_list|()
condition|)
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|getNumOptions
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|OptionNames
operator|.
name|push_back
argument_list|(
name|getOption
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
block|{
comment|// If there is an ArgStr specified, then we are of the form:
comment|//
comment|//    -opt=O2   or   -opt O2  or  -optO2
comment|//
comment|// In which case, the value is required.  Otherwise if an arg str has not
comment|// been specified, we are of the form:
comment|//
comment|//    -O2 or O2 or -la (where -l and -a are separate options)
comment|//
comment|// If this is the case, we cannot allow a value.
comment|//
if|if
condition|(
name|Owner
operator|.
name|hasArgStr
argument_list|()
condition|)
return|return
name|ValueRequired
return|;
else|else
return|return
name|ValueDisallowed
return|;
block|}
comment|// findOption - Return the option number corresponding to the specified
comment|// argument string.  If the option is not found, getNumOptions() is returned.
comment|//
name|unsigned
name|findOption
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
name|protected
label|:
name|Option
modifier|&
name|Owner
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Default parser implementation - This implementation depends on having a
end_comment

begin_comment
comment|// mapping of recognized options to values of some sort.  In addition to this,
end_comment

begin_comment
comment|// each entry in the mapping also tracks a help message that is printed with the
end_comment

begin_comment
comment|// command line option for -help.  Because this is a simple mapping parser, the
end_comment

begin_comment
comment|// data type can be any unsupported type.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|parser
operator|:
name|public
name|generic_parser_base
block|{
name|protected
operator|:
name|class
name|OptionInfo
operator|:
name|public
name|GenericOptionInfo
block|{
name|public
operator|:
name|OptionInfo
argument_list|(
argument|const char *name
argument_list|,
argument|DataType v
argument_list|,
argument|const char *helpStr
argument_list|)
operator|:
name|GenericOptionInfo
argument_list|(
name|name
argument_list|,
name|helpStr
argument_list|)
block|,
name|V
argument_list|(
argument|v
argument_list|)
block|{}
name|OptionValue
operator|<
name|DataType
operator|>
name|V
block|;   }
block|;
name|SmallVector
operator|<
name|OptionInfo
block|,
literal|8
operator|>
name|Values
block|;
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|generic_parser_base
argument_list|(
argument|O
argument_list|)
block|{}
typedef|typedef
name|DataType
name|parser_data_type
typedef|;
comment|// Implement virtual functions needed by generic_parser_base
name|unsigned
name|getNumOptions
argument_list|()
specifier|const
name|override
block|{
return|return
name|unsigned
argument_list|(
name|Values
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|char
operator|*
name|getOption
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
name|override
block|{
return|return
name|Values
index|[
name|N
index|]
operator|.
name|Name
return|;
block|}
specifier|const
name|char
operator|*
name|getDescription
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
name|override
block|{
return|return
name|Values
index|[
name|N
index|]
operator|.
name|HelpStr
return|;
block|}
comment|// getOptionValue - Return the value of option name N.
specifier|const
name|GenericOptionValue
operator|&
name|getOptionValue
argument_list|(
argument|unsigned N
argument_list|)
specifier|const
name|override
block|{
return|return
name|Values
index|[
name|N
index|]
operator|.
name|V
return|;
block|}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|DataType&V
argument_list|)
block|{
name|StringRef
name|ArgVal
block|;
if|if
condition|(
name|Owner
operator|.
name|hasArgStr
argument_list|()
condition|)
name|ArgVal
operator|=
name|Arg
expr_stmt|;
else|else
name|ArgVal
operator|=
name|ArgName
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|,
name|e
init|=
name|Values
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|Values
index|[
name|i
index|]
operator|.
name|Name
operator|==
name|ArgVal
condition|)
block|{
name|V
operator|=
name|Values
index|[
name|i
index|]
operator|.
name|V
operator|.
name|getValue
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
end_for

begin_return
return|return
name|O
operator|.
name|error
argument_list|(
literal|"Cannot find option named '"
operator|+
name|ArgVal
operator|+
literal|"'!"
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// addLiteralOption - Add an entry to the mapping table.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
unit|template
operator|<
name|class
name|DT
operator|>
name|void
name|addLiteralOption
argument_list|(
argument|const char *Name
argument_list|,
argument|const DT&V
argument_list|,
argument|const char *HelpStr
argument_list|)
block|{
name|assert
argument_list|(
name|findOption
argument_list|(
name|Name
argument_list|)
operator|==
name|Values
operator|.
name|size
argument_list|()
operator|&&
literal|"Option already exists!"
argument_list|)
block|;
name|OptionInfo
name|X
argument_list|(
name|Name
argument_list|,
name|static_cast
operator|<
name|DataType
operator|>
operator|(
name|V
operator|)
argument_list|,
name|HelpStr
argument_list|)
block|;
name|Values
operator|.
name|push_back
argument_list|(
name|X
argument_list|)
block|;
name|AddLiteralOption
argument_list|(
name|Owner
argument_list|,
name|Name
argument_list|)
block|;   }
comment|/// removeLiteralOption - Remove the specified option.
comment|///
name|void
name|removeLiteralOption
argument_list|(
argument|const char *Name
argument_list|)
block|{
name|unsigned
name|N
operator|=
name|findOption
argument_list|(
name|Name
argument_list|)
block|;
name|assert
argument_list|(
name|N
operator|!=
name|Values
operator|.
name|size
argument_list|()
operator|&&
literal|"Option not found!"
argument_list|)
block|;
name|Values
operator|.
name|erase
argument_list|(
name|Values
operator|.
name|begin
argument_list|()
operator|+
name|N
argument_list|)
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// basic_parser - Super class of parsers to provide boilerplate code
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|basic_parser_impl
block|{
comment|// non-template implementation of basic_parser<t>
name|public
label|:
name|basic_parser_impl
argument_list|(
argument|Option&O
argument_list|)
block|{}
block|enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
block|{
return|return
name|ValueRequired
return|;
block|}
name|void
name|getExtraOptionNames
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
argument_list|)
block|{}
name|void
name|initialize
parameter_list|()
block|{}
comment|// Return the width of the option tag for printing...
name|size_t
name|getOptionWidth
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
comment|// printOptionInfo - Print out information about this option.  The
comment|// to-be-maintained width is specified.
comment|//
name|void
name|printOptionInfo
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
comment|// printOptionNoValue - Print a placeholder for options that don't yet support
comment|// printOptionDiff().
name|void
name|printOptionNoValue
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
comment|// getValueName - Overload in subclass to provide a better default value.
name|virtual
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
block|{
return|return
literal|"value"
return|;
block|}
comment|// An out-of-line virtual method to provide a 'home' for this class.
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|protected
label|:
operator|~
name|basic_parser_impl
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|// A helper for basic_parser::printOptionDiff.
name|void
name|printOptionName
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// basic_parser - The real basic parser is just a template wrapper that provides
end_comment

begin_comment
comment|// a typedef for the provided data type.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|basic_parser
operator|:
name|public
name|basic_parser_impl
block|{
name|public
operator|:
name|basic_parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser_impl
argument_list|(
argument|O
argument_list|)
block|{}
typedef|typedef
name|DataType
name|parser_data_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|OptionValue
operator|<
name|DataType
operator|>
name|OptVal
expr_stmt|;
end_typedef

begin_label
name|protected
label|:
end_label

begin_comment
comment|// Workaround Clang PR22793
end_comment

begin_expr_stmt
operator|~
name|basic_parser
argument_list|()
block|{}
end_expr_stmt

begin_comment
unit|};
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<bool>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|bool
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|bool
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|bool&Val
argument_list|)
block|;
name|void
name|initialize
argument_list|()
block|{}
expr|enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
block|{
return|return
name|ValueOptional
return|;
block|}
comment|// getValueName - Do not print =<value> at all.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
name|nullptr
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionDiff
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|bool
name|V
argument_list|,
name|OptVal
name|Default
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<bool>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<boolOrDefault>
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|boolOrDefault
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|boolOrDefault
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|boolOrDefault&Val
argument_list|)
block|;    enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
block|{
return|return
name|ValueOptional
return|;
block|}
comment|// getValueName - Do not print =<value> at all.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
name|nullptr
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionDiff
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|boolOrDefault
name|V
argument_list|,
name|OptVal
name|Default
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<boolOrDefault>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<int>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|int
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|int
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|int&Val
argument_list|)
block|;
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"int"
return|;
block|}
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|int V
argument_list|,
argument|OptVal Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<int>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<unsigned>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|unsigned
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|unsigned
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|unsigned&Val
argument_list|)
block|;
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"uint"
return|;
block|}
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|unsigned V
argument_list|,
argument|OptVal Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<unsigned>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<unsigned long long>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|unsigned
name|long
name|long
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|unsigned long long&Val
argument_list|)
block|;
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"uint"
return|;
block|}
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|unsigned long long V
argument_list|,
argument|OptVal Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<unsigned long long>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<double>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|double
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|double
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|double&Val
argument_list|)
block|;
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"number"
return|;
block|}
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|double V
argument_list|,
argument|OptVal Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<double>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<float>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|float
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|float
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|,
argument|float&Val
argument_list|)
block|;
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"number"
return|;
block|}
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|float V
argument_list|,
argument|OptVal Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<float>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<std::string>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|std
operator|::
name|string
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|std
operator|::
name|string
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&
argument_list|,
argument|StringRef
argument_list|,
argument|StringRef Arg
argument_list|,
argument|std::string&Value
argument_list|)
block|{
name|Value
operator|=
name|Arg
operator|.
name|str
argument_list|()
block|;
return|return
name|false
return|;
block|}
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"string"
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionDiff
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|StringRef
name|V
argument_list|,
name|OptVal
name|Default
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<std::string>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// parser<char>
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|char
operator|>
name|final
operator|:
name|public
name|basic_parser
operator|<
name|char
operator|>
block|{
name|public
operator|:
name|parser
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|basic_parser
argument_list|(
argument|O
argument_list|)
block|{}
comment|// parse - Return true on error.
name|bool
name|parse
argument_list|(
argument|Option&
argument_list|,
argument|StringRef
argument_list|,
argument|StringRef Arg
argument_list|,
argument|char&Value
argument_list|)
block|{
name|Value
operator|=
name|Arg
index|[
literal|0
index|]
block|;
return|return
name|false
return|;
block|}
comment|// getValueName - Overload in subclass to provide a better default value.
specifier|const
name|char
operator|*
name|getValueName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"char"
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionDiff
argument_list|(
specifier|const
name|Option
operator|&
name|O
argument_list|,
name|char
name|V
argument_list|,
name|OptVal
name|Default
argument_list|,
name|size_t
name|GlobalWidth
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// An out-of-line virtual method to provide a 'home' for this class.
end_comment

begin_expr_stmt
name|void
name|anchor
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class basic_parser<char>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//--------------------------------------------------
end_comment

begin_comment
comment|// PrintOptionDiff
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This collection of wrappers is the intermediary between class opt and class
end_comment

begin_comment
comment|// parser to handle all the template nastiness.
end_comment

begin_comment
comment|// This overloaded function is selected by the generic parser.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ParserClass
operator|,
name|class
name|DT
operator|>
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|const generic_parser_base&P
argument_list|,
argument|const DT&V
argument_list|,
argument|const OptionValue<DT>&Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
block|{
name|OptionValue
operator|<
name|DT
operator|>
name|OV
operator|=
name|V
block|;
name|P
operator|.
name|printOptionDiff
argument_list|(
name|O
argument_list|,
name|OV
argument_list|,
name|Default
argument_list|,
name|GlobalWidth
argument_list|)
block|; }
comment|// This is instantiated for basic parsers when the parsed value has a different
comment|// type than the option value. e.g. HelpPrinter.
name|template
operator|<
name|class
name|ParserDT
operator|,
name|class
name|ValDT
operator|>
expr|struct
name|OptionDiffPrinter
block|{
name|void
name|print
argument_list|(
argument|const Option&O
argument_list|,
argument|const parser<ParserDT>&P
argument_list|,
argument|const ValDT&
comment|/*V*/
argument_list|,
argument|const OptionValue<ValDT>&
comment|/*Default*/
argument_list|,
argument|size_t GlobalWidth
argument_list|)
block|{
name|P
operator|.
name|printOptionNoValue
argument_list|(
name|O
argument_list|,
name|GlobalWidth
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This is instantiated for basic parsers when the parsed value has the same
end_comment

begin_comment
comment|// type as the option value.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DT
operator|>
expr|struct
name|OptionDiffPrinter
operator|<
name|DT
operator|,
name|DT
operator|>
block|{
name|void
name|print
argument_list|(
argument|const Option&O
argument_list|,
argument|const parser<DT>&P
argument_list|,
argument|const DT&V
argument_list|,
argument|const OptionValue<DT>&Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
block|{
name|P
operator|.
name|printOptionDiff
argument_list|(
name|O
argument_list|,
name|V
argument_list|,
name|Default
argument_list|,
name|GlobalWidth
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This overloaded function is selected by the basic parser, which may parse a
end_comment

begin_comment
comment|// different type than the option type.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|ParserClass
operator|,
name|class
name|ValDT
operator|>
name|void
name|printOptionDiff
argument_list|(
argument|const Option&O
argument_list|,
argument|const basic_parser<typename ParserClass::parser_data_type>&P
argument_list|,
argument|const ValDT&V
argument_list|,
argument|const OptionValue<ValDT>&Default
argument_list|,
argument|size_t GlobalWidth
argument_list|)
block|{
name|OptionDiffPrinter
operator|<
name|typename
name|ParserClass
operator|::
name|parser_data_type
block|,
name|ValDT
operator|>
name|printer
block|;
name|printer
operator|.
name|print
argument_list|(
name|O
argument_list|,
name|static_cast
operator|<
specifier|const
name|ParserClass
operator|&
operator|>
operator|(
name|P
operator|)
argument_list|,
name|V
argument_list|,
name|Default
argument_list|,
name|GlobalWidth
argument_list|)
block|; }
comment|//===----------------------------------------------------------------------===//
comment|// applicator class - This class is used because we must use partial
comment|// specialization to handle literal string arguments specially (const char* does
comment|// not correctly respond to the apply method).  Because the syntax to use this
comment|// is a pain, we have the 'apply' method below to handle the nastiness...
comment|//
name|template
operator|<
name|class
name|Mod
operator|>
expr|struct
name|applicator
block|{
name|template
operator|<
name|class
name|Opt
operator|>
specifier|static
name|void
name|opt
argument_list|(
argument|const Mod&M
argument_list|,
argument|Opt&O
argument_list|)
block|{
name|M
operator|.
name|apply
argument_list|(
name|O
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Handle const char* as a special case...
end_comment

begin_expr_stmt
name|template
operator|<
name|unsigned
name|n
operator|>
expr|struct
name|applicator
operator|<
name|char
index|[
name|n
index|]
operator|>
block|{
name|template
operator|<
name|class
name|Opt
operator|>
specifier|static
name|void
name|opt
argument_list|(
argument|const char *Str
argument_list|,
argument|Opt&O
argument_list|)
block|{
name|O
operator|.
name|setArgStr
argument_list|(
name|Str
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|unsigned
name|n
operator|>
expr|struct
name|applicator
operator|<
specifier|const
name|char
index|[
name|n
index|]
operator|>
block|{
name|template
operator|<
name|class
name|Opt
operator|>
specifier|static
name|void
name|opt
argument_list|(
argument|const char *Str
argument_list|,
argument|Opt&O
argument_list|)
block|{
name|O
operator|.
name|setArgStr
argument_list|(
name|Str
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
specifier|const
name|char
operator|*
operator|>
block|{
name|template
operator|<
name|class
name|Opt
operator|>
specifier|static
name|void
name|opt
argument_list|(
argument|const char *Str
argument_list|,
argument|Opt&O
argument_list|)
block|{
name|O
operator|.
name|setArgStr
argument_list|(
name|Str
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
name|NumOccurrencesFlag
operator|>
block|{
specifier|static
name|void
name|opt
argument_list|(
argument|NumOccurrencesFlag N
argument_list|,
argument|Option&O
argument_list|)
block|{
name|O
operator|.
name|setNumOccurrencesFlag
argument_list|(
name|N
argument_list|)
block|;   }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
name|ValueExpected
operator|>
block|{
specifier|static
name|void
name|opt
argument_list|(
argument|ValueExpected VE
argument_list|,
argument|Option&O
argument_list|)
block|{
name|O
operator|.
name|setValueExpectedFlag
argument_list|(
name|VE
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
name|OptionHidden
operator|>
block|{
specifier|static
name|void
name|opt
argument_list|(
argument|OptionHidden OH
argument_list|,
argument|Option&O
argument_list|)
block|{
name|O
operator|.
name|setHiddenFlag
argument_list|(
name|OH
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
name|FormattingFlags
operator|>
block|{
specifier|static
name|void
name|opt
argument_list|(
argument|FormattingFlags FF
argument_list|,
argument|Option&O
argument_list|)
block|{
name|O
operator|.
name|setFormattingFlag
argument_list|(
name|FF
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|applicator
operator|<
name|MiscFlags
operator|>
block|{
specifier|static
name|void
name|opt
argument_list|(
argument|MiscFlags MF
argument_list|,
argument|Option&O
argument_list|)
block|{
name|O
operator|.
name|setMiscFlag
argument_list|(
name|MF
argument_list|)
block|; }
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// apply method - Apply modifiers to an option in a type safe way.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Opt
operator|,
name|class
name|Mod
operator|,
name|class
operator|...
name|Mods
operator|>
name|void
name|apply
argument_list|(
argument|Opt *O
argument_list|,
argument|const Mod&M
argument_list|,
argument|const Mods&... Ms
argument_list|)
block|{
name|applicator
operator|<
name|Mod
operator|>
operator|::
name|opt
argument_list|(
name|M
argument_list|,
operator|*
name|O
argument_list|)
block|;
name|apply
argument_list|(
name|O
argument_list|,
name|Ms
operator|...
argument_list|)
block|; }
name|template
operator|<
name|class
name|Opt
operator|,
name|class
name|Mod
operator|>
name|void
name|apply
argument_list|(
argument|Opt *O
argument_list|,
argument|const Mod&M
argument_list|)
block|{
name|applicator
operator|<
name|Mod
operator|>
operator|::
name|opt
argument_list|(
name|M
argument_list|,
operator|*
name|O
argument_list|)
block|; }
comment|//===----------------------------------------------------------------------===//
comment|// opt_storage class
comment|// Default storage class definition: external storage.  This implementation
comment|// assumes the user will specify a variable to store the data into with the
comment|// cl::location(x) modifier.
comment|//
name|template
operator|<
name|class
name|DataType
operator|,
name|bool
name|ExternalStorage
operator|,
name|bool
name|isClass
operator|>
name|class
name|opt_storage
block|{
name|DataType
operator|*
name|Location
block|;
comment|// Where to store the object...
name|OptionValue
operator|<
name|DataType
operator|>
name|Default
block|;
name|void
name|check_location
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Location
operator|&&
literal|"cl::location(...) not specified for a command "
literal|"line option with external storage, "
literal|"or cl::init specified before cl::location()!!"
argument_list|)
block|;   }
name|public
operator|:
name|opt_storage
argument_list|()
operator|:
name|Location
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|bool
name|setLocation
argument_list|(
argument|Option&O
argument_list|,
argument|DataType&L
argument_list|)
block|{
if|if
condition|(
name|Location
condition|)
return|return
name|O
operator|.
name|error
argument_list|(
literal|"cl::location(x) specified more than once!"
argument_list|)
return|;
name|Location
operator|=
operator|&
name|L
block|;
name|Default
operator|=
name|L
block|;
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|void
name|setValue
argument_list|(
argument|const T&V
argument_list|,
argument|bool initial = false
argument_list|)
block|{
name|check_location
argument_list|()
block|;
operator|*
name|Location
operator|=
name|V
block|;
if|if
condition|(
name|initial
condition|)
name|Default
operator|=
name|V
expr_stmt|;
block|}
end_expr_stmt

begin_function
name|DataType
modifier|&
name|getValue
parameter_list|()
block|{
name|check_location
argument_list|()
expr_stmt|;
return|return
operator|*
name|Location
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|DataType
operator|&
name|getValue
argument_list|()
specifier|const
block|{
name|check_location
argument_list|()
block|;
return|return
operator|*
name|Location
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|DataType
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|getValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|OptionValue
operator|<
name|DataType
operator|>
operator|&
name|getDefault
argument_list|()
specifier|const
block|{
return|return
name|Default
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Define how to hold a class type object, such as a string.  Since we can
end_comment

begin_comment
comment|// inherit from a class, we do so.  This makes us exactly compatible with the
end_comment

begin_comment
comment|// object in all cases that it is used.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|opt_storage
operator|<
name|DataType
operator|,
name|false
operator|,
name|true
operator|>
operator|:
name|public
name|DataType
block|{
name|public
operator|:
name|OptionValue
operator|<
name|DataType
operator|>
name|Default
block|;
name|template
operator|<
name|class
name|T
operator|>
name|void
name|setValue
argument_list|(
argument|const T&V
argument_list|,
argument|bool initial = false
argument_list|)
block|{
name|DataType
operator|::
name|operator
operator|=
operator|(
name|V
operator|)
block|;
if|if
condition|(
name|initial
condition|)
name|Default
operator|=
name|V
expr_stmt|;
block|}
name|DataType
operator|&
name|getValue
argument_list|()
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|DataType
operator|&
name|getValue
argument_list|()
specifier|const
block|{
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|OptionValue
operator|<
name|DataType
operator|>
operator|&
name|getDefault
argument_list|()
specifier|const
block|{
return|return
name|Default
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Define a partial specialization to handle things we cannot inherit from.  In
end_comment

begin_comment
comment|// this case, we store an instance through containment, and overload operators
end_comment

begin_comment
comment|// to get at the value.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|opt_storage
operator|<
name|DataType
operator|,
name|false
operator|,
name|false
operator|>
block|{
name|public
operator|:
name|DataType
name|Value
block|;
name|OptionValue
operator|<
name|DataType
operator|>
name|Default
block|;
comment|// Make sure we initialize the value with the default constructor for the
comment|// type.
name|opt_storage
argument_list|()
operator|:
name|Value
argument_list|(
name|DataType
argument_list|()
argument_list|)
block|,
name|Default
argument_list|(
argument|DataType()
argument_list|)
block|{}
name|template
operator|<
name|class
name|T
operator|>
name|void
name|setValue
argument_list|(
argument|const T&V
argument_list|,
argument|bool initial = false
argument_list|)
block|{
name|Value
operator|=
name|V
block|;
if|if
condition|(
name|initial
condition|)
name|Default
operator|=
name|V
expr_stmt|;
block|}
name|DataType
operator|&
name|getValue
argument_list|()
block|{
return|return
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DataType
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|OptionValue
operator|<
name|DataType
operator|>
operator|&
name|getDefault
argument_list|()
specifier|const
block|{
return|return
name|Default
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|DataType
argument_list|()
specifier|const
block|{
return|return
name|getValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// If the datatype is a pointer, support -> on it.
end_comment

begin_expr_stmt
name|DataType
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|Value
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// opt - A scalar command line option.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|,
name|bool
name|ExternalStorage
operator|=
name|false
operator|,
name|class
name|ParserClass
operator|=
name|parser
operator|<
name|DataType
operator|>>
name|class
name|opt
operator|:
name|public
name|Option
operator|,
name|public
name|opt_storage
operator|<
name|DataType
operator|,
name|ExternalStorage
operator|,
name|std
operator|::
name|is_class
operator|<
name|DataType
operator|>
operator|::
name|value
operator|>
block|{
name|ParserClass
name|Parser
block|;
name|bool
name|handleOccurrence
argument_list|(
argument|unsigned pos
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef Arg
argument_list|)
name|override
block|{
name|typename
name|ParserClass
operator|::
name|parser_data_type
name|Val
operator|=
name|typename
name|ParserClass
operator|::
name|parser_data_type
argument_list|()
block|;
if|if
condition|(
name|Parser
operator|.
name|parse
argument_list|(
operator|*
name|this
argument_list|,
name|ArgName
argument_list|,
name|Arg
argument_list|,
name|Val
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Parse error!
name|this
operator|->
name|setValue
argument_list|(
name|Val
argument_list|)
block|;
name|this
operator|->
name|setPosition
argument_list|(
name|pos
argument_list|)
block|;
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getValueExpectedFlagDefault
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|getExtraOptionNames
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|OptionNames
argument_list|)
name|override
block|{
return|return
name|Parser
operator|.
name|getExtraOptionNames
argument_list|(
name|OptionNames
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Forward printing stuff to the parser...
end_comment

begin_expr_stmt
name|size_t
name|getOptionWidth
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getOptionWidth
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionInfo
argument_list|(
name|size_t
name|GlobalWidth
argument_list|)
decl|const
name|override
block|{
name|Parser
operator|.
name|printOptionInfo
argument_list|(
operator|*
name|this
argument_list|,
name|GlobalWidth
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|printOptionValue
argument_list|(
name|size_t
name|GlobalWidth
argument_list|,
name|bool
name|Force
argument_list|)
decl|const
name|override
block|{
if|if
condition|(
name|Force
operator|||
name|this
operator|->
name|getDefault
argument_list|()
operator|.
name|compare
argument_list|(
name|this
operator|->
name|getValue
argument_list|()
argument_list|)
condition|)
block|{
name|cl
operator|::
name|printOptionDiff
operator|<
name|ParserClass
operator|>
operator|(
operator|*
name|this
operator|,
name|Parser
operator|,
name|this
operator|->
name|getValue
argument_list|()
operator|,
name|this
operator|->
name|getDefault
argument_list|()
operator|,
name|GlobalWidth
operator|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_function
name|void
name|done
parameter_list|()
block|{
name|addArgument
argument_list|()
expr_stmt|;
name|Parser
operator|.
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Command line options should not be copyable
end_comment

begin_expr_stmt
name|opt
argument_list|(
specifier|const
name|opt
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|opt
modifier|&
name|operator
init|=
operator|(
specifier|const
name|opt
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|// setInitialValue - Used by the cl::init modifier...
end_comment

begin_function
name|void
name|setInitialValue
parameter_list|(
specifier|const
name|DataType
modifier|&
name|V
parameter_list|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|V
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|ParserClass
modifier|&
name|getParser
parameter_list|()
block|{
return|return
name|Parser
return|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|DataType
operator|&
name|operator
operator|=
operator|(
specifier|const
name|T
operator|&
name|Val
operator|)
block|{
name|this
operator|->
name|setValue
argument_list|(
name|Val
argument_list|)
block|;
return|return
name|this
operator|->
name|getValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Mods
operator|>
name|explicit
name|opt
argument_list|(
specifier|const
name|Mods
operator|&
operator|...
name|Ms
argument_list|)
operator|:
name|Option
argument_list|(
name|Optional
argument_list|,
name|NotHidden
argument_list|)
operator|,
name|Parser
argument_list|(
argument|*this
argument_list|)
block|{
name|apply
argument_list|(
name|this
argument_list|,
name|Ms
operator|...
argument_list|)
block|;
name|done
argument_list|()
block|;   }
end_expr_stmt

begin_macro
unit|};
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class opt<unsigned>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class opt<int>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class opt<std::string>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class opt<char>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|EXTERN_TEMPLATE_INSTANTIATION
argument_list|(
argument|class opt<bool>
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// list_storage class
end_comment

begin_comment
comment|// Default storage class definition: external storage.  This implementation
end_comment

begin_comment
comment|// assumes the user will specify a variable to store the data into with the
end_comment

begin_comment
comment|// cl::location(x) modifier.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|,
name|class
name|StorageClass
operator|>
name|class
name|list_storage
block|{
name|StorageClass
operator|*
name|Location
block|;
comment|// Where to store the object...
name|public
operator|:
name|list_storage
argument_list|()
operator|:
name|Location
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|setLocation
argument_list|(
argument|Option&O
argument_list|,
argument|StorageClass&L
argument_list|)
block|{
if|if
condition|(
name|Location
condition|)
return|return
name|O
operator|.
name|error
argument_list|(
literal|"cl::location(x) specified more than once!"
argument_list|)
return|;
name|Location
operator|=
operator|&
name|L
block|;
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|void
name|addValue
argument_list|(
argument|const T&V
argument_list|)
block|{
name|assert
argument_list|(
name|Location
operator|!=
literal|0
operator|&&
literal|"cl::location(...) not specified for a command "
literal|"line option with external storage!"
argument_list|)
block|;
name|Location
operator|->
name|push_back
argument_list|(
name|V
argument_list|)
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|// Define how to hold a class type object, such as a string.
end_comment

begin_comment
comment|// Originally this code inherited from std::vector. In transitioning to a new
end_comment

begin_comment
comment|// API for command line options we should change this. The new implementation
end_comment

begin_comment
comment|// of this list_storage specialization implements the minimum subset of the
end_comment

begin_comment
comment|// std::vector API required for all the current clients.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Reduce this API to a more narrow subset of std::vector
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|list_storage
operator|<
name|DataType
operator|,
name|bool
operator|>
block|{
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
name|Storage
block|;
name|public
operator|:
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|Storage
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|Storage
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|::
name|size_type
name|size_type
expr_stmt|;
end_typedef

begin_expr_stmt
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|push_back
parameter_list|(
specifier|const
name|DataType
modifier|&
name|value
parameter_list|)
block|{
name|Storage
operator|.
name|push_back
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
name|push_back
argument_list|(
name|DataType
operator|&&
name|value
argument_list|)
block|{
name|Storage
operator|.
name|push_back
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|::
name|reference
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|::
name|const_reference
name|const_reference
expr_stmt|;
end_typedef

begin_function
name|reference
name|operator
function|[]
parameter_list|(
name|size_type
name|pos
parameter_list|)
block|{
return|return
name|Storage
index|[
name|pos
index|]
return|;
block|}
end_function

begin_decl_stmt
name|const_reference
name|operator
index|[]
argument_list|(
name|size_type
name|pos
argument_list|)
decl|const
block|{
return|return
name|Storage
index|[
name|pos
index|]
return|;
block|}
end_decl_stmt

begin_function
name|iterator
name|erase
parameter_list|(
name|const_iterator
name|pos
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|erase
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|erase
parameter_list|(
name|const_iterator
name|first
parameter_list|,
name|const_iterator
name|last
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|erase
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|pos
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|erase
argument_list|(
name|pos
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|erase
parameter_list|(
name|iterator
name|first
parameter_list|,
name|iterator
name|last
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|erase
argument_list|(
name|first
argument_list|,
name|last
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|insert
parameter_list|(
name|const_iterator
name|pos
parameter_list|,
specifier|const
name|DataType
modifier|&
name|value
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|iterator
name|insert
argument_list|(
name|const_iterator
name|pos
argument_list|,
name|DataType
operator|&&
name|value
argument_list|)
block|{
return|return
name|Storage
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
name|value
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|iterator
name|insert
parameter_list|(
name|iterator
name|pos
parameter_list|,
specifier|const
name|DataType
modifier|&
name|value
parameter_list|)
block|{
return|return
name|Storage
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
name|value
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|iterator
name|insert
argument_list|(
name|iterator
name|pos
argument_list|,
name|DataType
operator|&&
name|value
argument_list|)
block|{
return|return
name|Storage
operator|.
name|insert
argument_list|(
name|pos
argument_list|,
name|value
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|reference
name|front
parameter_list|()
block|{
return|return
name|Storage
operator|.
name|front
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_reference
name|front
argument_list|()
specifier|const
block|{
return|return
name|Storage
operator|.
name|front
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|&
operator|(
operator|)
block|{
return|return
name|Storage
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|ArrayRef
operator|<
name|DataType
operator|>
operator|(
operator|)
block|{
return|return
name|Storage
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|*
name|operator
operator|&
operator|(
operator|)
block|{
return|return
operator|&
name|Storage
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|DataType
operator|>
operator|*
name|operator
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
operator|&
name|Storage
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|void
name|addValue
argument_list|(
argument|const T&V
argument_list|)
block|{
name|Storage
operator|.
name|push_back
argument_list|(
name|V
argument_list|)
block|; }
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// list - A list of command line options.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|,
name|class
name|StorageClass
operator|=
name|bool
operator|,
name|class
name|ParserClass
operator|=
name|parser
operator|<
name|DataType
operator|>>
name|class
name|list
operator|:
name|public
name|Option
operator|,
name|public
name|list_storage
operator|<
name|DataType
operator|,
name|StorageClass
operator|>
block|{
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Positions
block|;
name|ParserClass
name|Parser
block|;    enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getValueExpectedFlagDefault
argument_list|()
return|;
block|}
name|void
name|getExtraOptionNames
argument_list|(
argument|SmallVectorImpl<const char *>&OptionNames
argument_list|)
name|override
block|{
return|return
name|Parser
operator|.
name|getExtraOptionNames
argument_list|(
name|OptionNames
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|bool
name|handleOccurrence
parameter_list|(
name|unsigned
name|pos
parameter_list|,
name|StringRef
name|ArgName
parameter_list|,
name|StringRef
name|Arg
parameter_list|)
function|override
block|{
name|typename
name|ParserClass
operator|::
name|parser_data_type
name|Val
operator|=
name|typename
name|ParserClass
operator|::
name|parser_data_type
argument_list|()
expr_stmt|;
if|if
condition|(
name|Parser
operator|.
name|parse
argument_list|(
operator|*
name|this
argument_list|,
name|ArgName
argument_list|,
name|Arg
argument_list|,
name|Val
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Parse Error!
name|list_storage
operator|<
name|DataType
operator|,
name|StorageClass
operator|>
operator|::
name|addValue
argument_list|(
name|Val
argument_list|)
expr_stmt|;
name|setPosition
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|Positions
operator|.
name|push_back
argument_list|(
name|pos
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|// Forward printing stuff to the parser...
end_comment

begin_expr_stmt
name|size_t
name|getOptionWidth
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getOptionWidth
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionInfo
argument_list|(
name|size_t
name|GlobalWidth
argument_list|)
decl|const
name|override
block|{
name|Parser
operator|.
name|printOptionInfo
argument_list|(
operator|*
name|this
argument_list|,
name|GlobalWidth
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Unimplemented: list options don't currently store their default value.
end_comment

begin_decl_stmt
name|void
name|printOptionValue
argument_list|(
name|size_t
comment|/*GlobalWidth*/
argument_list|,
name|bool
comment|/*Force*/
argument_list|)
decl|const
name|override
block|{   }
end_decl_stmt

begin_function
name|void
name|done
parameter_list|()
block|{
name|addArgument
argument_list|()
expr_stmt|;
name|Parser
operator|.
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Command line options should not be copyable
end_comment

begin_expr_stmt
name|list
argument_list|(
specifier|const
name|list
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|list
modifier|&
name|operator
init|=
operator|(
specifier|const
name|list
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function
name|ParserClass
modifier|&
name|getParser
parameter_list|()
block|{
return|return
name|Parser
return|;
block|}
end_function

begin_decl_stmt
name|unsigned
name|getPosition
argument_list|(
name|unsigned
name|optnum
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|optnum
operator|<
name|this
operator|->
name|size
argument_list|()
operator|&&
literal|"Invalid option index"
argument_list|)
expr_stmt|;
return|return
name|Positions
index|[
name|optnum
index|]
return|;
block|}
end_decl_stmt

begin_function
name|void
name|setNumAdditionalVals
parameter_list|(
name|unsigned
name|n
parameter_list|)
block|{
name|Option
operator|::
name|setNumAdditionalVals
argument_list|(
name|n
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Mods
operator|>
name|explicit
name|list
argument_list|(
specifier|const
name|Mods
operator|&
operator|...
name|Ms
argument_list|)
operator|:
name|Option
argument_list|(
name|ZeroOrMore
argument_list|,
name|NotHidden
argument_list|)
operator|,
name|Parser
argument_list|(
argument|*this
argument_list|)
block|{
name|apply
argument_list|(
name|this
argument_list|,
name|Ms
operator|...
argument_list|)
block|;
name|done
argument_list|()
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|// multi_val - Modifier to set the number of additional values.
end_comment

begin_struct
struct|struct
name|multi_val
block|{
name|unsigned
name|AdditionalVals
decl_stmt|;
name|explicit
name|multi_val
argument_list|(
argument|unsigned N
argument_list|)
block|:
name|AdditionalVals
argument_list|(
argument|N
argument_list|)
block|{}
name|template
operator|<
name|typename
name|D
operator|,
name|typename
name|S
operator|,
name|typename
name|P
operator|>
name|void
name|apply
argument_list|(
argument|list<D
argument_list|,
argument|S
argument_list|,
argument|P>&L
argument_list|)
specifier|const
block|{
name|L
operator|.
name|setNumAdditionalVals
argument_list|(
name|AdditionalVals
argument_list|)
block|;   }
block|}
struct|;
end_struct

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// bits_storage class
end_comment

begin_comment
comment|// Default storage class definition: external storage.  This implementation
end_comment

begin_comment
comment|// assumes the user will specify a variable to store the data into with the
end_comment

begin_comment
comment|// cl::location(x) modifier.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|,
name|class
name|StorageClass
operator|>
name|class
name|bits_storage
block|{
name|unsigned
operator|*
name|Location
block|;
comment|// Where to store the bits...
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|unsigned
name|Bit
argument_list|(
argument|const T&V
argument_list|)
block|{
name|unsigned
name|BitPos
operator|=
name|reinterpret_cast
operator|<
name|unsigned
operator|>
operator|(
name|V
operator|)
block|;
name|assert
argument_list|(
name|BitPos
operator|<
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|&&
literal|"enum exceeds width of bit vector!"
argument_list|)
block|;
return|return
literal|1
operator|<<
name|BitPos
return|;
block|}
name|public
operator|:
name|bits_storage
argument_list|()
operator|:
name|Location
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|bool
name|setLocation
argument_list|(
argument|Option&O
argument_list|,
argument|unsigned&L
argument_list|)
block|{
if|if
condition|(
name|Location
condition|)
return|return
name|O
operator|.
name|error
argument_list|(
literal|"cl::location(x) specified more than once!"
argument_list|)
return|;
name|Location
operator|=
operator|&
name|L
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_expr_stmt
unit|}    template
operator|<
name|class
name|T
operator|>
name|void
name|addValue
argument_list|(
argument|const T&V
argument_list|)
block|{
name|assert
argument_list|(
name|Location
operator|!=
literal|0
operator|&&
literal|"cl::location(...) not specified for a command "
literal|"line option with external storage!"
argument_list|)
block|;
operator|*
name|Location
operator||=
name|Bit
argument_list|(
name|V
argument_list|)
block|;   }
name|unsigned
name|getBits
argument_list|()
block|{
return|return
operator|*
name|Location
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|isSet
argument_list|(
argument|const T&V
argument_list|)
block|{
return|return
operator|(
operator|*
name|Location
operator|&
name|Bit
argument_list|(
name|V
argument_list|)
operator|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Define how to hold bits.  Since we can inherit from a class, we do so.
end_comment

begin_comment
comment|// This makes us exactly compatible with the bits in all cases that it is used.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|>
name|class
name|bits_storage
operator|<
name|DataType
operator|,
name|bool
operator|>
block|{
name|unsigned
name|Bits
block|;
comment|// Where to store the bits...
name|template
operator|<
name|class
name|T
operator|>
specifier|static
name|unsigned
name|Bit
argument_list|(
argument|const T&V
argument_list|)
block|{
name|unsigned
name|BitPos
operator|=
operator|(
name|unsigned
operator|)
name|V
block|;
name|assert
argument_list|(
name|BitPos
operator|<
sizeof|sizeof
argument_list|(
name|unsigned
argument_list|)
operator|*
name|CHAR_BIT
operator|&&
literal|"enum exceeds width of bit vector!"
argument_list|)
block|;
return|return
literal|1
operator|<<
name|BitPos
return|;
block|}
name|public
operator|:
name|template
operator|<
name|class
name|T
operator|>
name|void
name|addValue
argument_list|(
argument|const T&V
argument_list|)
block|{
name|Bits
operator||=
name|Bit
argument_list|(
name|V
argument_list|)
block|; }
name|unsigned
name|getBits
argument_list|()
block|{
return|return
name|Bits
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|isSet
argument_list|(
argument|const T&V
argument_list|)
block|{
return|return
operator|(
name|Bits
operator|&
name|Bit
argument_list|(
name|V
argument_list|)
operator|)
operator|!=
literal|0
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// bits - A bit vector of command options.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|DataType
operator|,
name|class
name|Storage
operator|=
name|bool
operator|,
name|class
name|ParserClass
operator|=
name|parser
operator|<
name|DataType
operator|>>
name|class
name|bits
operator|:
name|public
name|Option
operator|,
name|public
name|bits_storage
operator|<
name|DataType
operator|,
name|Storage
operator|>
block|{
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|Positions
block|;
name|ParserClass
name|Parser
block|;    enum
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getValueExpectedFlagDefault
argument_list|()
return|;
block|}
name|void
name|getExtraOptionNames
argument_list|(
argument|SmallVectorImpl<const char *>&OptionNames
argument_list|)
name|override
block|{
return|return
name|Parser
operator|.
name|getExtraOptionNames
argument_list|(
name|OptionNames
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|bool
name|handleOccurrence
parameter_list|(
name|unsigned
name|pos
parameter_list|,
name|StringRef
name|ArgName
parameter_list|,
name|StringRef
name|Arg
parameter_list|)
function|override
block|{
name|typename
name|ParserClass
operator|::
name|parser_data_type
name|Val
operator|=
name|typename
name|ParserClass
operator|::
name|parser_data_type
argument_list|()
expr_stmt|;
if|if
condition|(
name|Parser
operator|.
name|parse
argument_list|(
operator|*
name|this
argument_list|,
name|ArgName
argument_list|,
name|Arg
argument_list|,
name|Val
argument_list|)
condition|)
return|return
name|true
return|;
comment|// Parse Error!
name|this
operator|->
name|addValue
argument_list|(
name|Val
argument_list|)
expr_stmt|;
name|setPosition
argument_list|(
name|pos
argument_list|)
expr_stmt|;
name|Positions
operator|.
name|push_back
argument_list|(
name|pos
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|// Forward printing stuff to the parser...
end_comment

begin_expr_stmt
name|size_t
name|getOptionWidth
argument_list|()
specifier|const
name|override
block|{
return|return
name|Parser
operator|.
name|getOptionWidth
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|printOptionInfo
argument_list|(
name|size_t
name|GlobalWidth
argument_list|)
decl|const
name|override
block|{
name|Parser
operator|.
name|printOptionInfo
argument_list|(
operator|*
name|this
argument_list|,
name|GlobalWidth
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Unimplemented: bits options don't currently store their default values.
end_comment

begin_decl_stmt
name|void
name|printOptionValue
argument_list|(
name|size_t
comment|/*GlobalWidth*/
argument_list|,
name|bool
comment|/*Force*/
argument_list|)
decl|const
name|override
block|{   }
end_decl_stmt

begin_function
name|void
name|done
parameter_list|()
block|{
name|addArgument
argument_list|()
expr_stmt|;
name|Parser
operator|.
name|initialize
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Command line options should not be copyable
end_comment

begin_expr_stmt
name|bits
argument_list|(
specifier|const
name|bits
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bits
modifier|&
name|operator
init|=
operator|(
specifier|const
name|bits
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function
name|ParserClass
modifier|&
name|getParser
parameter_list|()
block|{
return|return
name|Parser
return|;
block|}
end_function

begin_decl_stmt
name|unsigned
name|getPosition
argument_list|(
name|unsigned
name|optnum
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|optnum
operator|<
name|this
operator|->
name|size
argument_list|()
operator|&&
literal|"Invalid option index"
argument_list|)
expr_stmt|;
return|return
name|Positions
index|[
name|optnum
index|]
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Mods
operator|>
name|explicit
name|bits
argument_list|(
specifier|const
name|Mods
operator|&
operator|...
name|Ms
argument_list|)
operator|:
name|Option
argument_list|(
name|ZeroOrMore
argument_list|,
name|NotHidden
argument_list|)
operator|,
name|Parser
argument_list|(
argument|*this
argument_list|)
block|{
name|apply
argument_list|(
name|this
argument_list|,
name|Ms
operator|...
argument_list|)
block|;
name|done
argument_list|()
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Aliased command line option (alias this name to a preexisting name)
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|alias
range|:
name|public
name|Option
block|{
name|Option
operator|*
name|AliasFor
block|;
name|bool
name|handleOccurrence
argument_list|(
argument|unsigned pos
argument_list|,
argument|StringRef
comment|/*ArgName*/
argument_list|,
argument|StringRef Arg
argument_list|)
name|override
block|{
return|return
name|AliasFor
operator|->
name|handleOccurrence
argument_list|(
name|pos
argument_list|,
name|AliasFor
operator|->
name|ArgStr
argument_list|,
name|Arg
argument_list|)
return|;
block|}
name|bool
name|addOccurrence
argument_list|(
argument|unsigned pos
argument_list|,
argument|StringRef
comment|/*ArgName*/
argument_list|,
argument|StringRef Value
argument_list|,
argument|bool MultiArg = false
argument_list|)
name|override
block|{
return|return
name|AliasFor
operator|->
name|addOccurrence
argument_list|(
name|pos
argument_list|,
name|AliasFor
operator|->
name|ArgStr
argument_list|,
name|Value
argument_list|,
name|MultiArg
argument_list|)
return|;
block|}
comment|// Handle printing stuff...
name|size_t
name|getOptionWidth
argument_list|()
specifier|const
name|override
block|;
name|void
name|printOptionInfo
argument_list|(
argument|size_t GlobalWidth
argument_list|)
specifier|const
name|override
block|;
comment|// Aliases do not need to print their values.
name|void
name|printOptionValue
argument_list|(
argument|size_t
comment|/*GlobalWidth*/
argument_list|,
argument|bool
comment|/*Force*/
argument_list|)
specifier|const
name|override
block|{   }
name|ValueExpected
name|getValueExpectedFlagDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|AliasFor
operator|->
name|getValueExpectedFlag
argument_list|()
return|;
block|}
name|void
name|done
argument_list|()
block|{
if|if
condition|(
operator|!
name|hasArgStr
argument_list|()
condition|)
name|error
argument_list|(
literal|"cl::alias must have argument name specified!"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|AliasFor
condition|)
name|error
argument_list|(
literal|"cl::alias must have an cl::aliasopt(option) specified!"
argument_list|)
expr_stmt|;
name|addArgument
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// Command line options should not be copyable
end_comment

begin_expr_stmt
unit|alias
operator|(
specifier|const
name|alias
operator|&
operator|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|alias
modifier|&
name|operator
init|=
operator|(
specifier|const
name|alias
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_function
name|void
name|setAliasFor
parameter_list|(
name|Option
modifier|&
name|O
parameter_list|)
block|{
if|if
condition|(
name|AliasFor
condition|)
name|error
argument_list|(
literal|"cl::alias must only have one cl::aliasopt(...) specified!"
argument_list|)
expr_stmt|;
name|AliasFor
operator|=
operator|&
name|O
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|class
operator|...
name|Mods
operator|>
name|explicit
name|alias
argument_list|(
specifier|const
name|Mods
operator|&
operator|...
name|Ms
argument_list|)
operator|:
name|Option
argument_list|(
name|Optional
argument_list|,
name|Hidden
argument_list|)
operator|,
name|AliasFor
argument_list|(
argument|nullptr
argument_list|)
block|{
name|apply
argument_list|(
name|this
argument_list|,
name|Ms
operator|...
argument_list|)
block|;
name|done
argument_list|()
block|;   }
end_expr_stmt

begin_comment
unit|};
comment|// aliasfor - Modifier to set the option an alias aliases.
end_comment

begin_struct
struct|struct
name|aliasopt
block|{
name|Option
modifier|&
name|Opt
decl_stmt|;
name|explicit
name|aliasopt
argument_list|(
name|Option
operator|&
name|O
argument_list|)
operator|:
name|Opt
argument_list|(
argument|O
argument_list|)
block|{}
name|void
name|apply
argument_list|(
argument|alias&A
argument_list|)
specifier|const
block|{
name|A
operator|.
name|setAliasFor
argument_list|(
name|Opt
argument_list|)
block|; }
block|}
struct|;
end_struct

begin_comment
comment|// extrahelp - provide additional help at the end of the normal help
end_comment

begin_comment
comment|// output. All occurrences of cl::extrahelp will be accumulated and
end_comment

begin_comment
comment|// printed to stderr at the end of the regular help, just before
end_comment

begin_comment
comment|// exit is called.
end_comment

begin_struct
struct|struct
name|extrahelp
block|{
specifier|const
name|char
modifier|*
name|morehelp
decl_stmt|;
name|explicit
name|extrahelp
parameter_list|(
specifier|const
name|char
modifier|*
name|help
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|PrintVersionMessage
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// This function just prints the help message, exactly the same way as if the
end_comment

begin_comment
comment|/// -help or -help-hidden option had been given on the command line.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// NOTE: THIS FUNCTION TERMINATES THE PROGRAM!
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Hidden if true will print hidden options
end_comment

begin_comment
comment|/// \param Categorized if true print options in categories
end_comment

begin_function_decl
name|void
name|PrintHelpMessage
parameter_list|(
name|bool
name|Hidden
init|=
name|false
parameter_list|,
name|bool
name|Categorized
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Public interface for accessing registered options.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \brief Use this to get a StringMap to all registered named options
end_comment

begin_comment
comment|/// (e.g. -help). Note \p Map Should be an empty StringMap.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return A reference to the StringMap used by the cl APIs to parse options.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Access to unnamed arguments (i.e. positional) are not provided because
end_comment

begin_comment
comment|/// it is expected that the client already has access to these.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Typical usage:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// main(int argc,char* argv[]) {
end_comment

begin_comment
comment|/// StringMap<llvm::cl::Option*>&opts = llvm::cl::getRegisteredOptions();
end_comment

begin_comment
comment|/// assert(opts.count("help") == 1)
end_comment

begin_comment
comment|/// opts["help"]->setDescription("Show alphabetical help information")
end_comment

begin_comment
comment|/// // More code
end_comment

begin_comment
comment|/// llvm::cl::ParseCommandLineOptions(argc,argv);
end_comment

begin_comment
comment|/// //More code
end_comment

begin_comment
comment|/// }
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This interface is useful for modifying options in libraries that are out of
end_comment

begin_comment
comment|/// the control of the client. The options should be modified before calling
end_comment

begin_comment
comment|/// llvm::cl::ParseCommandLineOptions().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Hopefully this API can be depricated soon. Any situation where options need
end_comment

begin_comment
comment|/// to be modified by tools or libraries should be handled by sane APIs rather
end_comment

begin_comment
comment|/// than just handing around a global list.
end_comment

begin_expr_stmt
name|StringMap
operator|<
name|Option
operator|*
operator|>
operator|&
name|getRegisteredOptions
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Standalone command line processing utilities.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \brief Saves strings in the inheritor's stable storage and returns a stable
end_comment

begin_comment
comment|/// raw character pointer.
end_comment

begin_decl_stmt
name|class
name|StringSaver
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
specifier|const
name|char
modifier|*
name|SaveString
parameter_list|(
specifier|const
name|char
modifier|*
name|Str
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|StringSaver
argument_list|()
block|{}
expr_stmt|;
comment|// Pacify -Wnon-virtual-dtor.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Tokenizes a command line that can contain escapes and quotes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// The quoting rules match those used by GCC and other tools that use
end_comment

begin_comment
comment|/// libiberty's buildargv() or expandargv() utilities, and do not match bash.
end_comment

begin_comment
comment|/// They differ from buildargv() on treatment of backslashes that do not escape
end_comment

begin_comment
comment|/// a special character to make it possible to accept most Windows file paths.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param [in] Source The string to be split on whitespace with quotes.
end_comment

begin_comment
comment|/// \param [in] Saver Delegates back to the caller for saving parsed strings.
end_comment

begin_comment
comment|/// \param [in] MarkEOLs true if tokenizing a response file and you want end of
end_comment

begin_comment
comment|/// lines and end of the response file to be marked with a nullptr string.
end_comment

begin_comment
comment|/// \param [out] NewArgv All parsed strings are appended to NewArgv.
end_comment

begin_decl_stmt
name|void
name|TokenizeGNUCommandLine
argument_list|(
name|StringRef
name|Source
argument_list|,
name|StringSaver
operator|&
name|Saver
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|NewArgv
argument_list|,
name|bool
name|MarkEOLs
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Tokenizes a Windows command line which may contain quotes and escaped
end_comment

begin_comment
comment|/// quotes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See MSDN docs for CommandLineToArgvW for information on the quoting rules.
end_comment

begin_comment
comment|/// http://msdn.microsoft.com/en-us/library/windows/desktop/17w5ykft(v=vs.85).aspx
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param [in] Source The string to be split on whitespace with quotes.
end_comment

begin_comment
comment|/// \param [in] Saver Delegates back to the caller for saving parsed strings.
end_comment

begin_comment
comment|/// \param [in] MarkEOLs true if tokenizing a response file and you want end of
end_comment

begin_comment
comment|/// lines and end of the response file to be marked with a nullptr string.
end_comment

begin_comment
comment|/// \param [out] NewArgv All parsed strings are appended to NewArgv.
end_comment

begin_decl_stmt
name|void
name|TokenizeWindowsCommandLine
argument_list|(
name|StringRef
name|Source
argument_list|,
name|StringSaver
operator|&
name|Saver
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|NewArgv
argument_list|,
name|bool
name|MarkEOLs
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief String tokenization function type.  Should be compatible with either
end_comment

begin_comment
comment|/// Windows or Unix command line tokenizers.
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*TokenizerCallback
argument_list|)
operator|(
name|StringRef
name|Source
operator|,
name|StringSaver
operator|&
name|Saver
operator|,
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|NewArgv
operator|,
name|bool
name|MarkEOLs
operator|)
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Expand response files on a command line recursively using the given
end_comment

begin_comment
comment|/// StringSaver and tokenization strategy.  Argv should contain the command line
end_comment

begin_comment
comment|/// before expansion and will be modified in place. If requested, Argv will
end_comment

begin_comment
comment|/// also be populated with nullptrs indicating where each response file line
end_comment

begin_comment
comment|/// ends, which is useful for the "/link" argument that needs to consume all
end_comment

begin_comment
comment|/// remaining arguments only until the next end of line, when in a response
end_comment

begin_comment
comment|/// file.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param [in] Saver Delegates back to the caller for saving parsed strings.
end_comment

begin_comment
comment|/// \param [in] Tokenizer Tokenization strategy. Typically Unix or Windows.
end_comment

begin_comment
comment|/// \param [in,out] Argv Command line into which to expand response files.
end_comment

begin_comment
comment|/// \param [in] MarkEOLs Mark end of lines and the end of the response file
end_comment

begin_comment
comment|/// with nullptrs in the Argv vector.
end_comment

begin_comment
comment|/// \return true if all @files were expanded successfully or there were none.
end_comment

begin_decl_stmt
name|bool
name|ExpandResponseFiles
argument_list|(
name|StringSaver
operator|&
name|Saver
argument_list|,
name|TokenizerCallback
name|Tokenizer
argument_list|,
name|SmallVectorImpl
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|Argv
argument_list|,
name|bool
name|MarkEOLs
operator|=
name|false
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Mark all options not part of this category as cl::ReallyHidden.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Category the category of options to keep displaying
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Some tools (like clang-format) like to be able to hide all options that are
end_comment

begin_comment
comment|/// not specific to the tool. This function allows a tool to specify a single
end_comment

begin_comment
comment|/// option category to display in the -help output.
end_comment

begin_decl_stmt
name|void
name|HideUnrelatedOptions
argument_list|(
name|cl
operator|::
name|OptionCategory
operator|&
name|Category
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Mark all options not part of the categories as cl::ReallyHidden.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Categories the categories of options to keep displaying.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Some tools (like clang-format) like to be able to hide all options that are
end_comment

begin_comment
comment|/// not specific to the tool. This function allows a tool to specify a single
end_comment

begin_comment
comment|/// option category to display in the -help output.
end_comment

begin_decl_stmt
name|void
name|HideUnrelatedOptions
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|cl
operator|::
name|OptionCategory
operator|*
operator|>
name|Categories
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// End namespace cl
end_comment

begin_comment
unit|}
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

