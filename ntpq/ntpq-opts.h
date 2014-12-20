begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (ntpq-opts.h)  *  *  It has been AutoGen-ed  December 19, 2014 at 07:49:47 AM by AutoGen 5.18.5pre4  *  From the definitions    ntpq-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This header file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntpq author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The ntpq program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1970-2014 The University of Delaware, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/**  *  This file contains the programmatic interface to the Automated  *  Options generated for the ntpq program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_NTPQ_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_NTPQ_OPTS_H_GUARD
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<autoopts/options.h>
end_include

begin_comment
comment|/**  *  Ensure that the library used for compiling this generated header is at  *  least as new as the version current when the header template was released  *  (not counting patch version increments).  Also ensure that the oldest  *  tolerable version is at least as old as what was current when the header  *  template was released.  */
end_comment

begin_define
define|#
directive|define
name|AO_TEMPLATE_VERSION
value|167936
end_define

begin_if
if|#
directive|if
operator|(
name|AO_TEMPLATE_VERSION
operator|<
name|OPTIONS_MINIMUM_VERSION
operator|)
expr|\
operator|||
operator|(
name|AO_TEMPLATE_VERSION
operator|>
name|OPTIONS_STRUCT_VERSION
operator|)
end_if

begin_error
error|#
directive|error
error|option template version mismatches autoopts/options.h header
end_error

begin_expr_stmt
name|Choke
name|Me
operator|.
endif|#
directive|endif
comment|/**  *  Enumeration of each option type for ntpq  */
expr|typedef enum
block|{
name|INDEX_OPT_IPV4
operator|=
literal|0
block|,
name|INDEX_OPT_IPV6
operator|=
literal|1
block|,
name|INDEX_OPT_COMMAND
operator|=
literal|2
block|,
name|INDEX_OPT_DEBUG_LEVEL
operator|=
literal|3
block|,
name|INDEX_OPT_SET_DEBUG_LEVEL
operator|=
literal|4
block|,
name|INDEX_OPT_INTERACTIVE
operator|=
literal|5
block|,
name|INDEX_OPT_NUMERIC
operator|=
literal|6
block|,
name|INDEX_OPT_OLD_RV
operator|=
literal|7
block|,
name|INDEX_OPT_PEERS
operator|=
literal|8
block|,
name|INDEX_OPT_WIDE
operator|=
literal|9
block|,
name|INDEX_OPT_VERSION
operator|=
literal|10
block|,
name|INDEX_OPT_HELP
operator|=
literal|11
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|12
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|13
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|14
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** count of all options for ntpq */
end_comment

begin_define
define|#
directive|define
name|OPTION_CT
value|15
end_define

begin_comment
comment|/** ntpq version */
end_comment

begin_define
define|#
directive|define
name|NTPQ_VERSION
value|"4.2.8"
end_define

begin_comment
comment|/** Full ntpq version text */
end_comment

begin_define
define|#
directive|define
name|NTPQ_FULL_VERSION
value|"ntpq 4.2.8"
end_define

begin_comment
comment|/**  *  Interface defines for all options.  Replace "n" with the UPPER_CASED  *  option name (as in the teOptIndex enumeration above).  *  e.g. HAVE_OPT(IPV4)  */
end_comment

begin_define
define|#
directive|define
name|DESC
parameter_list|(
name|n
parameter_list|)
value|(ntpqOptions.pOptDesc[INDEX_OPT_## n])
end_define

begin_comment
comment|/** 'true' if an option has been specified in any way */
end_comment

begin_define
define|#
directive|define
name|HAVE_OPT
parameter_list|(
name|n
parameter_list|)
value|(! UNUSED_OPT(& DESC(n)))
end_define

begin_comment
comment|/** The string argument to an option. The argument type must be \"string\". */
end_comment

begin_define
define|#
directive|define
name|OPT_ARG
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).optArg.argString)
end_define

begin_comment
comment|/** Mask the option state revealing how an option was specified.  *  It will be one and only one of \a OPTST_SET, \a OPTST_PRESET,  * \a OPTST_DEFINED, \a OPTST_RESET or zero.  */
end_comment

begin_define
define|#
directive|define
name|STATE_OPT
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).fOptState& OPTST_SET_MASK)
end_define

begin_comment
comment|/** Count of option's occurrances *on the command line*. */
end_comment

begin_define
define|#
directive|define
name|COUNT_OPT
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).optOccCt)
end_define

begin_comment
comment|/** mask of \a OPTST_SET and \a OPTST_DEFINED. */
end_comment

begin_define
define|#
directive|define
name|ISSEL_OPT
parameter_list|(
name|n
parameter_list|)
value|(SELECTED_OPT(&DESC(n)))
end_define

begin_comment
comment|/** 'true' if \a HAVE_OPT would yield 'false'. */
end_comment

begin_define
define|#
directive|define
name|ISUNUSED_OPT
parameter_list|(
name|n
parameter_list|)
value|(UNUSED_OPT(& DESC(n)))
end_define

begin_comment
comment|/** 'true' if OPTST_DISABLED bit not set. */
end_comment

begin_define
define|#
directive|define
name|ENABLED_OPT
parameter_list|(
name|n
parameter_list|)
value|(! DISABLED_OPT(& DESC(n)))
end_define

begin_comment
comment|/** number of stacked option arguments.  *  Valid only for stacked option arguments. */
end_comment

begin_define
define|#
directive|define
name|STACKCT_OPT
parameter_list|(
name|n
parameter_list|)
value|(((tArgList*)(DESC(n).optCookie))->useCt)
end_define

begin_comment
comment|/** stacked argument vector.  *  Valid only for stacked option arguments. */
end_comment

begin_define
define|#
directive|define
name|STACKLST_OPT
parameter_list|(
name|n
parameter_list|)
value|(((tArgList*)(DESC(n).optCookie))->apzArgs)
end_define

begin_comment
comment|/** Reset an option. */
end_comment

begin_define
define|#
directive|define
name|CLEAR_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 DESC(n).fOptState&= OPTST_PERSISTENT_MASK;   \                 if ((DESC(n).fOptState& OPTST_INITENABLED) == 0) \                     DESC(n).fOptState |= OPTST_DISABLED; \                 DESC(n).optCookie = NULL )
end_define

begin_comment
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
end_comment

begin_comment
comment|/**  *  Enumeration of ntpq exit codes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NTPQ_EXIT_SUCCESS
init|=
literal|0
block|,
name|NTPQ_EXIT_FAILURE
init|=
literal|1
block|,
name|NTPQ_EXIT_USAGE_ERROR
init|=
literal|64
block|,
name|NTPQ_EXIT_NO_CONFIG_INPUT
init|=
literal|66
block|,
name|NTPQ_EXIT_LIBOPTS_FAILURE
init|=
literal|70
block|}
name|ntpq_exit_code_t
typedef|;
end_typedef

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/**  *  Make sure there are no #define name conflicts with the option names  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_OPTION_NAME_WARNINGS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|IPV4
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining IPV4 due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|IPV4
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IPV6
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining IPV6 due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|IPV6
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMMAND
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining COMMAND due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|COMMAND
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_LEVEL
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining DEBUG_LEVEL due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|DEBUG_LEVEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SET_DEBUG_LEVEL
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SET_DEBUG_LEVEL due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SET_DEBUG_LEVEL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTERACTIVE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining INTERACTIVE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|INTERACTIVE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NUMERIC
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NUMERIC due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NUMERIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_RV
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining OLD_RV due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|OLD_RV
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PEERS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PEERS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PEERS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIDE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining WIDE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|WIDE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_OPTION_NAME_WARNINGS */
end_comment

begin_undef
undef|#
directive|undef
name|IPV4
end_undef

begin_undef
undef|#
directive|undef
name|IPV6
end_undef

begin_undef
undef|#
directive|undef
name|COMMAND
end_undef

begin_undef
undef|#
directive|undef
name|DEBUG_LEVEL
end_undef

begin_undef
undef|#
directive|undef
name|SET_DEBUG_LEVEL
end_undef

begin_undef
undef|#
directive|undef
name|INTERACTIVE
end_undef

begin_undef
undef|#
directive|undef
name|NUMERIC
end_undef

begin_undef
undef|#
directive|undef
name|OLD_RV
end_undef

begin_undef
undef|#
directive|undef
name|PEERS
end_undef

begin_undef
undef|#
directive|undef
name|WIDE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NO_OPTION_NAME_WARNINGS */
end_comment

begin_comment
comment|/**  *  Interface defines for specific options.  * @{  */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_IPV4
value|'4'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_IPV6
value|'6'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_COMMAND
value|'c'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_DEBUG_LEVEL
value|'d'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SET_DEBUG_LEVEL
value|'D'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_SET_DEBUG_LEVEL
value|(DESC(SET_DEBUG_LEVEL).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_INTERACTIVE
value|'i'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_NUMERIC
value|'n'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_OLD_RV
value|0x1001
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PEERS
value|'p'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_WIDE
value|'w'
end_define

begin_comment
comment|/** option flag (value) for help-value option */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_HELP
value|'?'
end_define

begin_comment
comment|/** option flag (value) for more-help-value option */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_MORE_HELP
value|'!'
end_define

begin_comment
comment|/** option flag (value) for version-value option */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_VERSION
value|0x1002
end_define

begin_comment
comment|/** option flag (value) for save-opts-value option */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_SAVE_OPTS
value|'>'
end_define

begin_comment
comment|/** option flag (value) for load-opts-value option */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_LOAD_OPTS
value|'<'
end_define

begin_define
define|#
directive|define
name|SET_OPT_SAVE_OPTS
parameter_list|(
name|a
parameter_list|)
value|STMTS( \         DESC(SAVE_OPTS).fOptState&= OPTST_PERSISTENT_MASK; \         DESC(SAVE_OPTS).fOptState |= OPTST_SET; \         DESC(SAVE_OPTS).optArg.argString = (char const*)(a))
end_define

begin_comment
comment|/*  *  Interface defines not associated with particular options  */
end_comment

begin_define
define|#
directive|define
name|ERRSKIP_OPTERR
value|STMTS(ntpqOptions.fOptSet&= ~OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS(ntpqOptions.fOptSet |= OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 ntpqOptions.curOptIdx = (n); \                 ntpqOptions.pzCurOpt  = NULL )
end_define

begin_define
define|#
directive|define
name|START_OPT
value|RESTART_OPT(1)
end_define

begin_define
define|#
directive|define
name|USAGE
parameter_list|(
name|c
parameter_list|)
value|(*ntpqOptions.pUsageProc)(&ntpqOptions, c)
end_define

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
comment|/* * * * * *  *  *  Declare the ntpq option descriptor.  */
specifier|extern
name|tOptions
name|ntpqOptions
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_NLS
argument_list|)
ifndef|#
directive|ifndef
name|_
include|#
directive|include
file|<stdio.h>
ifndef|#
directive|ifndef
name|HAVE_GETTEXT
specifier|extern
name|char
modifier|*
name|gettext
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
include|#
directive|include
file|<libintl.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|ATTRIBUTE_FORMAT_ARG
define|#
directive|define
name|ATTRIBUTE_FORMAT_ARG
parameter_list|(
name|_a
parameter_list|)
endif|#
directive|endif
specifier|static
specifier|inline
name|char
modifier|*
name|aoGetsText
parameter_list|(
name|char
specifier|const
modifier|*
name|pz
parameter_list|)
function_decl|ATTRIBUTE_FORMAT_ARG
parameter_list|(
function_decl|1
block|)
empty_stmt|;
end_extern

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|aoGetsText
parameter_list|(
name|char
specifier|const
modifier|*
name|pz
parameter_list|)
block|{
if|if
condition|(
name|pz
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
return|return
operator|(
name|char
operator|*
operator|)
name|gettext
argument_list|(
name|pz
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|_
parameter_list|(
name|s
parameter_list|)
value|aoGetsText(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _() */
end_comment

begin_define
define|#
directive|define
name|OPT_NO_XLAT_CFG_NAMES
value|STMTS(ntpqOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_NO_XLAT_OPT_NAMES
value|STMTS(ntpqOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_CFG_NAMES
value|STMTS(ntpqOptions.fOptSet&= \                                   ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_OPT_NAMES
value|STMTS(ntpqOptions.fOptSet&= \                                   ~OPTPROC_NXLAT_OPT;)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ENABLE_NLS */
end_comment

begin_define
define|#
directive|define
name|OPT_NO_XLAT_CFG_NAMES
end_define

begin_define
define|#
directive|define
name|OPT_NO_XLAT_OPT_NAMES
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_CFG_NAMES
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_OPT_NAMES
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_
end_ifndef

begin_define
define|#
directive|define
name|_
parameter_list|(
name|_s
parameter_list|)
value|_s
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
comment|/* ENABLE_NLS */
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
comment|/* AUTOOPTS_NTPQ_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* ntpq-opts.h ends here */
end_comment

end_unit

