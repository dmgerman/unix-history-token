begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Hierarchial argument parsing, layered over getopt.    Copyright (C) 1995-1999,2003,2004 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARGP_H
end_ifndef

begin_define
define|#
directive|define
name|_ARGP_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<getopt.h>
end_include

begin_define
define|#
directive|define
name|__need_error_t
end_define

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__const
end_ifndef

begin_define
define|#
directive|define
name|__const
value|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__THROW
end_ifndef

begin_define
define|#
directive|define
name|__THROW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__NTH
end_ifndef

begin_define
define|#
directive|define
name|__NTH
parameter_list|(
name|fct
parameter_list|)
value|fct __THROW
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_comment
comment|/* This feature is available in gcc versions 2.5 and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|Spec
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The __-protected variants of `format' and `printf' attributes    are accepted by gcc versions 2.6.4 (effectively 2.7) and later.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__format__
value|format
end_define

begin_define
define|#
directive|define
name|__printf__
value|printf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC 2.95 and later have "__restrict"; C99 compilers have    "restrict", and "configure" may have defined "restrict".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__restrict
end_ifndef

begin_if
if|#
directive|if
operator|!
operator|(
literal|2
operator|<
name|__GNUC__
operator|||
operator|(
literal|2
operator|==
name|__GNUC__
operator|&&
literal|95
operator|<=
name|__GNUC_MINOR__
operator|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
specifier|restrict
operator|||
literal|199901L
operator|<=
name|__STDC_VERSION__
end_if

begin_define
define|#
directive|define
name|__restrict
value|restrict
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__restrict
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__error_t_defined
end_ifndef

begin_typedef
typedef|typedef
name|int
name|error_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__error_t_defined
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* A description of a particular option.  A pointer to an array of    these is passed in the OPTIONS field of an argp structure.  Each option    entry can correspond to one long option and/or one short option; more    names for the same option can be added by following an entry in an option    array with options having the OPTION_ALIAS flag set.  */
struct|struct
name|argp_option
block|{
comment|/* The long option name.  For more than one name for the same option, you      can use following options with the OPTION_ALIAS flag set.  */
name|__const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* What key is returned for this option.  If> 0 and printable, then it's      also accepted as a short option.  */
name|int
name|key
decl_stmt|;
comment|/* If non-NULL, this is the name of the argument associated with this      option, which is required unless the OPTION_ARG_OPTIONAL flag is set. */
name|__const
name|char
modifier|*
name|arg
decl_stmt|;
comment|/* OPTION_ flags.  */
name|int
name|flags
decl_stmt|;
comment|/* The doc string for this option.  If both NAME and KEY are 0, This string      will be printed outdented from the normal option column, making it      useful as a group header (it will be the first thing printed in its      group); in this usage, it's conventional to end the string with a `:'.  */
name|__const
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* The group this option is in.  In a long help message, options are sorted      alphabetically within each group, and the groups presented in the order      0, 1, 2, ..., n, -m, ..., -2, -1.  Every entry in an options array with      if this field 0 will inherit the group number of the previous entry, or      zero if it's the first one, unless its a group header (NAME and KEY both      0), in which case, the previous entry + 1 is the default.  Automagic      options such as --help are put into group -1.  */
name|int
name|group
decl_stmt|;
block|}
struct|;
comment|/* The argument associated with this option is optional.  */
define|#
directive|define
name|OPTION_ARG_OPTIONAL
value|0x1
comment|/* This option isn't displayed in any help messages.  */
define|#
directive|define
name|OPTION_HIDDEN
value|0x2
comment|/* This option is an alias for the closest previous non-alias option.  This    means that it will be displayed in the same help entry, and will inherit    fields other than NAME and KEY from the aliased option.  */
define|#
directive|define
name|OPTION_ALIAS
value|0x4
comment|/* This option isn't actually an option (and so should be ignored by the    actual option parser), but rather an arbitrary piece of documentation that    should be displayed in much the same manner as the options.  If this flag    is set, then the option NAME field is displayed unmodified (e.g., no `--'    prefix is added) at the left-margin (where a *short* option would normally    be displayed), and the documentation string in the normal place. The NAME    field will be translated using gettext, unless OPTION_NO_TRANS is set (see    below). For purposes of sorting, any leading whitespace and punctuation is    ignored, except that if the first non-whitespace character is not `-', this    entry is displayed after all options (and OPTION_DOC entries with a leading    `-') in the same group.  */
define|#
directive|define
name|OPTION_DOC
value|0x8
comment|/* This option shouldn't be included in `long' usage messages (but is still    included in help messages).  This is mainly intended for options that are    completely documented in an argp's ARGS_DOC field, in which case including    the option in the generic usage list would be redundant.  For instance,    if ARGS_DOC is "FOO BAR\n-x BLAH", and the `-x' option's purpose is to    distinguish these two cases, -x should probably be marked    OPTION_NO_USAGE.  */
define|#
directive|define
name|OPTION_NO_USAGE
value|0x10
comment|/* Valid only in conjunction with OPTION_DOC. This option disables translation    of option name. */
define|#
directive|define
name|OPTION_NO_TRANS
value|0x20
struct_decl|struct
name|argp
struct_decl|;
comment|/* fwd declare this type */
struct_decl|struct
name|argp_state
struct_decl|;
comment|/* " */
struct_decl|struct
name|argp_child
struct_decl|;
comment|/* " */
comment|/* The type of a pointer to an argp parsing function.  */
typedef|typedef
name|error_t
function_decl|(
modifier|*
name|argp_parser_t
function_decl|)
parameter_list|(
name|int
name|key
parameter_list|,
name|char
modifier|*
name|arg
parameter_list|,
name|struct
name|argp_state
modifier|*
name|state
parameter_list|)
function_decl|;
comment|/* What to return for unrecognized keys.  For special ARGP_KEY_ keys, such    returns will simply be ignored.  For user keys, this error will be turned    into EINVAL (if the call to argp_parse is such that errors are propagated    back to the user instead of exiting); returning EINVAL itself would result    in an immediate stop to parsing in *all* cases.  */
define|#
directive|define
name|ARGP_ERR_UNKNOWN
value|E2BIG
comment|/* Hurd should never need E2BIG.  XXX */
comment|/* Special values for the KEY argument to an argument parsing function.    ARGP_ERR_UNKNOWN should be returned if they aren't understood.     The sequence of keys to a parsing function is either (where each    uppercased word should be prefixed by `ARGP_KEY_' and opt is a user key):         INIT opt... NO_ARGS END SUCCESS  -- No non-option arguments at all    or  INIT (opt | ARG)... END SUCCESS  -- All non-option args parsed    or  INIT (opt | ARG)... SUCCESS      -- Some non-option arg unrecognized     The third case is where every parser returned ARGP_KEY_UNKNOWN for an    argument, in which case parsing stops at that argument (returning the    unparsed arguments to the caller of argp_parse if requested, or stopping    with an error message if not).     If an error occurs (either detected by argp, or because the parsing    function returned an error value), then the parser is called with    ARGP_KEY_ERROR, and no further calls are made.  */
comment|/* This is not an option at all, but rather a command line argument.  If a    parser receiving this key returns success, the fact is recorded, and the    ARGP_KEY_NO_ARGS case won't be used.  HOWEVER, if while processing the    argument, a parser function decrements the NEXT field of the state it's    passed, the option won't be considered processed; this is to allow you to    actually modify the argument (perhaps into an option), and have it    processed again.  */
define|#
directive|define
name|ARGP_KEY_ARG
value|0
comment|/* There are remaining arguments not parsed by any parser, which may be found    starting at (STATE->argv + STATE->next).  If success is returned, but    STATE->next left untouched, it's assumed that all arguments were consume,    otherwise, the parser should adjust STATE->next to reflect any arguments    consumed.  */
define|#
directive|define
name|ARGP_KEY_ARGS
value|0x1000006
comment|/* There are no more command line arguments at all.  */
define|#
directive|define
name|ARGP_KEY_END
value|0x1000001
comment|/* Because it's common to want to do some special processing if there aren't    any non-option args, user parsers are called with this key if they didn't    successfully process any non-option arguments.  Called just before    ARGP_KEY_END (where more general validity checks on previously parsed    arguments can take place).  */
define|#
directive|define
name|ARGP_KEY_NO_ARGS
value|0x1000002
comment|/* Passed in before any parsing is done.  Afterwards, the values of each    element of the CHILD_INPUT field, if any, in the state structure is    copied to each child's state to be the initial value of the INPUT field.  */
define|#
directive|define
name|ARGP_KEY_INIT
value|0x1000003
comment|/* Use after all other keys, including SUCCESS& END.  */
define|#
directive|define
name|ARGP_KEY_FINI
value|0x1000007
comment|/* Passed in when parsing has successfully been completed (even if there are    still arguments remaining).  */
define|#
directive|define
name|ARGP_KEY_SUCCESS
value|0x1000004
comment|/* Passed in if an error occurs.  */
define|#
directive|define
name|ARGP_KEY_ERROR
value|0x1000005
comment|/* An argp structure contains a set of options declarations, a function to    deal with parsing one, documentation string, a possible vector of child    argp's, and perhaps a function to filter help output.  When actually    parsing options, getopt is called with the union of all the argp    structures chained together through their CHILD pointers, with conflicts    being resolved in favor of the first occurrence in the chain.  */
struct|struct
name|argp
block|{
comment|/* An array of argp_option structures, terminated by an entry with both      NAME and KEY having a value of 0.  */
name|__const
name|struct
name|argp_option
modifier|*
name|options
decl_stmt|;
comment|/* What to do with an option from this structure.  KEY is the key      associated with the option, and ARG is any associated argument (NULL if      none was supplied).  If KEY isn't understood, ARGP_ERR_UNKNOWN should be      returned.  If a non-zero, non-ARGP_ERR_UNKNOWN value is returned, then      parsing is stopped immediately, and that value is returned from      argp_parse().  For special (non-user-supplied) values of KEY, see the      ARGP_KEY_ definitions below.  */
name|argp_parser_t
name|parser
decl_stmt|;
comment|/* A string describing what other arguments are wanted by this program.  It      is only used by argp_usage to print the `Usage:' message.  If it      contains newlines, the strings separated by them are considered      alternative usage patterns, and printed on separate lines (lines after      the first are prefix by `  or: ' instead of `Usage:').  */
name|__const
name|char
modifier|*
name|args_doc
decl_stmt|;
comment|/* If non-NULL, a string containing extra text to be printed before and      after the options in a long help message (separated by a vertical tab      `\v' character).  */
name|__const
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* A vector of argp_children structures, terminated by a member with a 0      argp field, pointing to child argps should be parsed with this one.  Any      conflicts are resolved in favor of this argp, or early argps in the      CHILDREN list.  This field is useful if you use libraries that supply      their own argp structure, which you want to use in conjunction with your      own.  */
name|__const
name|struct
name|argp_child
modifier|*
name|children
decl_stmt|;
comment|/* If non-zero, this should be a function to filter the output of help      messages.  KEY is either a key from an option, in which case TEXT is      that option's help text, or a special key from the ARGP_KEY_HELP_      defines, below, describing which other help text TEXT is.  The function      should return either TEXT, if it should be used as-is, a replacement      string, which should be malloced, and will be freed by argp, or NULL,      meaning `print nothing'.  The value for TEXT is *after* any translation      has been done, so if any of the replacement text also needs translation,      that should be done by the filter function.  INPUT is either the input      supplied to argp_parse, or NULL, if argp_help was called directly.  */
name|char
modifier|*
function_decl|(
modifier|*
name|help_filter
function_decl|)
parameter_list|(
name|int
name|__key
parameter_list|,
name|__const
name|char
modifier|*
name|__text
parameter_list|,
name|void
modifier|*
name|__input
parameter_list|)
function_decl|;
comment|/* If non-zero the strings used in the argp library are translated using      the domain described by this string.  Otherwise the currently installed      default domain is used.  */
specifier|const
name|char
modifier|*
name|argp_domain
decl_stmt|;
block|}
struct|;
comment|/* Possible KEY arguments to a help filter function.  */
define|#
directive|define
name|ARGP_KEY_HELP_PRE_DOC
value|0x2000001
comment|/* Help text preceeding options. */
define|#
directive|define
name|ARGP_KEY_HELP_POST_DOC
value|0x2000002
comment|/* Help text following options. */
define|#
directive|define
name|ARGP_KEY_HELP_HEADER
value|0x2000003
comment|/* Option header string. */
define|#
directive|define
name|ARGP_KEY_HELP_EXTRA
value|0x2000004
comment|/* After all other documentation; 					     TEXT is NULL for this key.  */
comment|/* Explanatory note emitted when duplicate option arguments have been    suppressed.  */
define|#
directive|define
name|ARGP_KEY_HELP_DUP_ARGS_NOTE
value|0x2000005
define|#
directive|define
name|ARGP_KEY_HELP_ARGS_DOC
value|0x2000006
comment|/* Argument doc string.  */
comment|/* When an argp has a non-zero CHILDREN field, it should point to a vector of    argp_child structures, each of which describes a subsidiary argp.  */
struct|struct
name|argp_child
block|{
comment|/* The child parser.  */
name|__const
name|struct
name|argp
modifier|*
name|argp
decl_stmt|;
comment|/* Flags for this child.  */
name|int
name|flags
decl_stmt|;
comment|/* If non-zero, an optional header to be printed in help output before the      child options.  As a side-effect, a non-zero value forces the child      options to be grouped together; to achieve this effect without actually      printing a header string, use a value of "".  */
name|__const
name|char
modifier|*
name|header
decl_stmt|;
comment|/* Where to group the child options relative to the other (`consolidated')      options in the parent argp; the values are the same as the GROUP field      in argp_option structs, but all child-groupings follow parent options at      a particular group level.  If both this field and HEADER are zero, then      they aren't grouped at all, but rather merged with the parent options      (merging the child's grouping levels with the parents).  */
name|int
name|group
decl_stmt|;
block|}
struct|;
comment|/* Parsing state.  This is provided to parsing functions called by argp,    which may examine and, as noted, modify fields.  */
struct|struct
name|argp_state
block|{
comment|/* The top level ARGP being parsed.  */
name|__const
name|struct
name|argp
modifier|*
name|root_argp
decl_stmt|;
comment|/* The argument vector being parsed.  May be modified.  */
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* The index in ARGV of the next arg that to be parsed.  May be modified. */
name|int
name|next
decl_stmt|;
comment|/* The flags supplied to argp_parse.  May be modified.  */
name|unsigned
name|flags
decl_stmt|;
comment|/* While calling a parsing function with a key of ARGP_KEY_ARG, this is the      number of the current arg, starting at zero, and incremented after each      such call returns.  At all other times, this is the number of such      arguments that have been processed.  */
name|unsigned
name|arg_num
decl_stmt|;
comment|/* If non-zero, the index in ARGV of the first argument following a special      `--' argument (which prevents anything following being interpreted as an      option).  Only set once argument parsing has proceeded past this point. */
name|int
name|quoted
decl_stmt|;
comment|/* An arbitrary pointer passed in from the user.  */
name|void
modifier|*
name|input
decl_stmt|;
comment|/* Values to pass to child parsers.  This vector will be the same length as      the number of children for the current parser.  */
name|void
modifier|*
modifier|*
name|child_inputs
decl_stmt|;
comment|/* For the parser's use.  Initialized to 0.  */
name|void
modifier|*
name|hook
decl_stmt|;
comment|/* The name used when printing messages.  This is initialized to ARGV[0],      or PROGRAM_INVOCATION_NAME if that is unavailable.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Streams used when argp prints something.  */
name|FILE
modifier|*
name|err_stream
decl_stmt|;
comment|/* For errors; initialized to stderr. */
name|FILE
modifier|*
name|out_stream
decl_stmt|;
comment|/* For information; initialized to stdout. */
name|void
modifier|*
name|pstate
decl_stmt|;
comment|/* Private, for use by argp.  */
block|}
struct|;
comment|/* Flags for argp_parse (note that the defaults are those that are    convenient for program command line parsing): */
comment|/* Don't ignore the first element of ARGV.  Normally (and always unless    ARGP_NO_ERRS is set) the first element of the argument vector is    skipped for option parsing purposes, as it corresponds to the program name    in a command line.  */
define|#
directive|define
name|ARGP_PARSE_ARGV0
value|0x01
comment|/* Don't print error messages for unknown options to stderr; unless this flag    is set, ARGP_PARSE_ARGV0 is ignored, as ARGV[0] is used as the program    name in the error messages.  This flag implies ARGP_NO_EXIT (on the    assumption that silent exiting upon errors is bad behaviour).  */
define|#
directive|define
name|ARGP_NO_ERRS
value|0x02
comment|/* Don't parse any non-option args.  Normally non-option args are parsed by    calling the parse functions with a key of ARGP_KEY_ARG, and the actual arg    as the value.  Since it's impossible to know which parse function wants to    handle it, each one is called in turn, until one returns 0 or an error    other than ARGP_ERR_UNKNOWN; if an argument is handled by no one, the    argp_parse returns prematurely (but with a return value of 0).  If all    args have been parsed without error, all parsing functions are called one    last time with a key of ARGP_KEY_END.  This flag needn't normally be set,    as the normal behavior is to stop parsing as soon as some argument can't    be handled.  */
define|#
directive|define
name|ARGP_NO_ARGS
value|0x04
comment|/* Parse options and arguments in the same order they occur on the command    line -- normally they're rearranged so that all options come first. */
define|#
directive|define
name|ARGP_IN_ORDER
value|0x08
comment|/* Don't provide the standard long option --help, which causes usage and       option help information to be output to stdout, and exit (0) called. */
define|#
directive|define
name|ARGP_NO_HELP
value|0x10
comment|/* Don't exit on errors (they may still result in error messages).  */
define|#
directive|define
name|ARGP_NO_EXIT
value|0x20
comment|/* Use the gnu getopt `long-only' rules for parsing arguments.  */
define|#
directive|define
name|ARGP_LONG_ONLY
value|0x40
comment|/* Turns off any message-printing/exiting options.  */
define|#
directive|define
name|ARGP_SILENT
value|(ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_NO_HELP)
comment|/* Parse the options strings in ARGC& ARGV according to the options in ARGP.    FLAGS is one of the ARGP_ flags above.  If ARG_INDEX is non-NULL, the    index in ARGV of the first unparsed option is returned in it.  If an    unknown option is present, ARGP_ERR_UNKNOWN is returned; if some parser    routine returned a non-zero value, it is returned; otherwise 0 is    returned.  This function may also call exit unless the ARGP_NO_HELP flag    is set.  INPUT is a pointer to a value to be passed in to the parser.  */
specifier|extern
name|error_t
name|argp_parse
parameter_list|(
name|__const
name|struct
name|argp
modifier|*
name|__restrict
name|__argp
parameter_list|,
name|int
name|__argc
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
name|__argv
parameter_list|,
name|unsigned
name|__flags
parameter_list|,
name|int
modifier|*
name|__restrict
name|__arg_index
parameter_list|,
name|void
modifier|*
name|__restrict
name|__input
parameter_list|)
function_decl|;
specifier|extern
name|error_t
name|__argp_parse
parameter_list|(
name|__const
name|struct
name|argp
modifier|*
name|__restrict
name|__argp
parameter_list|,
name|int
name|__argc
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
name|__argv
parameter_list|,
name|unsigned
name|__flags
parameter_list|,
name|int
modifier|*
name|__restrict
name|__arg_index
parameter_list|,
name|void
modifier|*
name|__restrict
name|__input
parameter_list|)
function_decl|;
comment|/* Global variables.  */
comment|/* If defined or set by the user program to a non-zero value, then a default    option --version is added (unless the ARGP_NO_HELP flag is used), which    will print this string followed by a newline and exit (unless the    ARGP_NO_EXIT flag is used).  Overridden by ARGP_PROGRAM_VERSION_HOOK.  */
specifier|extern
name|__const
name|char
modifier|*
name|argp_program_version
decl_stmt|;
comment|/* If defined or set by the user program to a non-zero value, then a default    option --version is added (unless the ARGP_NO_HELP flag is used), which    calls this function with a stream to print the version to and a pointer to    the current parsing state, and then exits (unless the ARGP_NO_EXIT flag is    used).  This variable takes precedent over ARGP_PROGRAM_VERSION.  */
specifier|extern
name|void
function_decl|(
modifier|*
name|argp_program_version_hook
function_decl|)
parameter_list|(
name|FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|)
function_decl|;
comment|/* If defined or set by the user program, it should point to string that is    the bug-reporting address for the program.  It will be printed by    argp_help if the ARGP_HELP_BUG_ADDR flag is set (as it is by various    standard help messages), embedded in a sentence that says something like    `Report bugs to ADDR.'.  */
specifier|extern
name|__const
name|char
modifier|*
name|argp_program_bug_address
decl_stmt|;
comment|/* The exit status that argp will use when exiting due to a parsing error.    If not defined or set by the user program, this defaults to EX_USAGE from<sysexits.h>.  */
specifier|extern
name|error_t
name|argp_err_exit_status
decl_stmt|;
comment|/* Flags for argp_help.  */
define|#
directive|define
name|ARGP_HELP_USAGE
value|0x01
comment|/* a Usage: message. */
define|#
directive|define
name|ARGP_HELP_SHORT_USAGE
value|0x02
comment|/*  " but don't actually print options. */
define|#
directive|define
name|ARGP_HELP_SEE
value|0x04
comment|/* a `Try ... for more help' message. */
define|#
directive|define
name|ARGP_HELP_LONG
value|0x08
comment|/* a long help message. */
define|#
directive|define
name|ARGP_HELP_PRE_DOC
value|0x10
comment|/* doc string preceding long help.  */
define|#
directive|define
name|ARGP_HELP_POST_DOC
value|0x20
comment|/* doc string following long help.  */
define|#
directive|define
name|ARGP_HELP_DOC
value|(ARGP_HELP_PRE_DOC | ARGP_HELP_POST_DOC)
define|#
directive|define
name|ARGP_HELP_BUG_ADDR
value|0x40
comment|/* bug report address */
define|#
directive|define
name|ARGP_HELP_LONG_ONLY
value|0x80
comment|/* modify output appropriately to 					reflect ARGP_LONG_ONLY mode.  */
comment|/* These ARGP_HELP flags are only understood by argp_state_help.  */
define|#
directive|define
name|ARGP_HELP_EXIT_ERR
value|0x100
comment|/* Call exit(1) instead of returning.  */
define|#
directive|define
name|ARGP_HELP_EXIT_OK
value|0x200
comment|/* Call exit(0) instead of returning.  */
comment|/* The standard thing to do after a program command line parsing error, if an    error message has already been printed.  */
define|#
directive|define
name|ARGP_HELP_STD_ERR
define|\
value|(ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
comment|/* The standard thing to do after a program command line parsing error, if no    more specific error message has been printed.  */
define|#
directive|define
name|ARGP_HELP_STD_USAGE
define|\
value|(ARGP_HELP_SHORT_USAGE | ARGP_HELP_SEE | ARGP_HELP_EXIT_ERR)
comment|/* The standard thing to do in response to a --help option.  */
define|#
directive|define
name|ARGP_HELP_STD_HELP
define|\
value|(ARGP_HELP_SHORT_USAGE | ARGP_HELP_LONG | ARGP_HELP_EXIT_OK \    | ARGP_HELP_DOC | ARGP_HELP_BUG_ADDR)
comment|/* Output a usage message for ARGP to STREAM.  FLAGS are from the set    ARGP_HELP_*.  */
specifier|extern
name|void
name|argp_help
parameter_list|(
name|__const
name|struct
name|argp
modifier|*
name|__restrict
name|__argp
parameter_list|,
name|FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|unsigned
name|__flags
parameter_list|,
name|char
modifier|*
name|__restrict
name|__name
parameter_list|)
function_decl|;
specifier|extern
name|void
name|__argp_help
parameter_list|(
name|__const
name|struct
name|argp
modifier|*
name|__restrict
name|__argp
parameter_list|,
name|FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|unsigned
name|__flags
parameter_list|,
name|char
modifier|*
name|__name
parameter_list|)
function_decl|;
comment|/* The following routines are intended to be called from within an argp    parsing routine (thus taking an argp_state structure as the first    argument).  They may or may not print an error message and exit, depending    on the flags in STATE -- in any case, the caller should be prepared for    them *not* to exit, and should return an appropiate error after calling    them.  [argp_usage& argp_error should probably be called argp_state_...,    but they're used often enough that they should be short]  */
comment|/* Output, if appropriate, a usage message for STATE to STREAM.  FLAGS are    from the set ARGP_HELP_*.  */
specifier|extern
name|void
name|argp_state_help
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|unsigned
name|int
name|__flags
parameter_list|)
function_decl|;
specifier|extern
name|void
name|__argp_state_help
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|FILE
modifier|*
name|__restrict
name|__stream
parameter_list|,
name|unsigned
name|int
name|__flags
parameter_list|)
function_decl|;
comment|/* Possibly output the standard usage message for ARGP to stderr and exit.  */
specifier|extern
name|void
name|argp_usage
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__state
parameter_list|)
function_decl|;
specifier|extern
name|void
name|__argp_usage
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__state
parameter_list|)
function_decl|;
comment|/* If appropriate, print the printf string FMT and following args, preceded    by the program name and `:', to stderr, and followed by a `Try ... --help'    message, then exit (1).  */
specifier|extern
name|void
name|argp_error
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
end_extern

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|__argp_error
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Similar to the standard gnu error-reporting function error(), but will    respect the ARGP_NO_EXIT and ARGP_NO_ERRS flags in STATE, and will print    to STATE->err_stream.  This is useful for argument parsing code that is    shared between program startup (when exiting is desired) and runtime    option parsing (when typically an error code is returned instead).  The    difference between this function and argp_error is that the latter is for    *parsing errors*, and the former is for other problems that occur during    parsing but don't reflect a (syntactic) problem with the input.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|argp_failure
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|int
name|__status
parameter_list|,
name|int
name|__errnum
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|__argp_failure
parameter_list|(
name|__const
name|struct
name|argp_state
modifier|*
name|__restrict
name|__state
parameter_list|,
name|int
name|__status
parameter_list|,
name|int
name|__errnum
parameter_list|,
name|__const
name|char
modifier|*
name|__restrict
name|__fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|4
operator|,
function_decl|5
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Returns true if the option OPT is a valid short option.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_option_is_short
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__option_is_short
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns true if the option OPT is in fact the last (unused) entry in an    options array.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|_option_is_end
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__option_is_end
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the input field for ARGP in the parser corresponding to STATE; used    by the help routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|_argp_input
argument_list|(
name|__const
expr|struct
name|argp
operator|*
name|__restrict
name|__argp
argument_list|,
name|__const
expr|struct
name|argp_state
operator|*
name|__restrict
name|__state
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
modifier|*
name|__argp_input
argument_list|(
name|__const
expr|struct
name|argp
operator|*
name|__restrict
name|__argp
argument_list|,
name|__const
expr|struct
name|argp_state
operator|*
name|__restrict
name|__state
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|__USE_EXTERN_INLINES
end_ifdef

begin_if
if|#
directive|if
operator|!
name|_LIBC
end_if

begin_define
define|#
directive|define
name|__argp_usage
value|argp_usage
end_define

begin_define
define|#
directive|define
name|__argp_state_help
value|argp_state_help
end_define

begin_define
define|#
directive|define
name|__option_is_short
value|_option_is_short
end_define

begin_define
define|#
directive|define
name|__option_is_end
value|_option_is_end
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARGP_EI
end_ifndef

begin_define
define|#
directive|define
name|ARGP_EI
value|extern __inline__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|ARGP_EI
name|void
name|__NTH
argument_list|(
name|__argp_usage
argument_list|(
name|__const
expr|struct
name|argp_state
operator|*
name|__state
argument_list|)
argument_list|)
block|{
name|__argp_state_help
argument_list|(
name|__state
argument_list|,
name|stderr
argument_list|,
name|ARGP_HELP_STD_USAGE
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|ARGP_EI
name|int
name|__NTH
argument_list|(
name|__option_is_short
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
argument_list|)
block|{
if|if
condition|(
name|__opt
operator|->
name|flags
operator|&
name|OPTION_DOC
condition|)
return|return
literal|0
return|;
else|else
block|{
name|int
name|__key
init|=
name|__opt
operator|->
name|key
decl_stmt|;
return|return
name|__key
operator|>
literal|0
operator|&&
name|__key
operator|<
literal|256
operator|&&
name|isprint
argument_list|(
name|__key
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|ARGP_EI
name|int
name|__NTH
argument_list|(
name|__option_is_end
argument_list|(
name|__const
expr|struct
name|argp_option
operator|*
name|__opt
argument_list|)
argument_list|)
block|{
return|return
operator|!
name|__opt
operator|->
name|key
operator|&&
operator|!
name|__opt
operator|->
name|name
operator|&&
operator|!
name|__opt
operator|->
name|doc
operator|&&
operator|!
name|__opt
operator|->
name|group
return|;
block|}
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|_LIBC
end_if

begin_undef
undef|#
directive|undef
name|__argp_usage
end_undef

begin_undef
undef|#
directive|undef
name|__argp_state_help
end_undef

begin_undef
undef|#
directive|undef
name|__option_is_short
end_undef

begin_undef
undef|#
directive|undef
name|__option_is_end
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use extern inlines.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* argp.h */
end_comment

end_unit

