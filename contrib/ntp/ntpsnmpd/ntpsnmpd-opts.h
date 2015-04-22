begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (ntpsnmpd-opts.h)  *  *  It has been AutoGen-ed  February  4, 2015 at 02:43:21 AM by AutoGen 5.18.5pre4  *  From the definitions    ntpsnmpd-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This header file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntpsnmpd author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The ntpsnmpd program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware and Network Time Foundation makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/**  *  This file contains the programmatic interface to the Automated  *  Options generated for the ntpsnmpd program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_NTPSNMPD_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_NTPSNMPD_OPTS_H_GUARD
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
comment|/**  *  Enumeration of each option type for ntpsnmpd  */
expr|typedef enum
block|{
name|INDEX_OPT_NOFORK
operator|=
literal|0
block|,
name|INDEX_OPT_SYSLOG
operator|=
literal|1
block|,
name|INDEX_OPT_AGENTXSOCKET
operator|=
literal|2
block|,
name|INDEX_OPT_VERSION
operator|=
literal|3
block|,
name|INDEX_OPT_HELP
operator|=
literal|4
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|5
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|6
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|7
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** count of all options for ntpsnmpd */
end_comment

begin_define
define|#
directive|define
name|OPTION_CT
value|8
end_define

begin_comment
comment|/** ntpsnmpd version */
end_comment

begin_define
define|#
directive|define
name|NTPSNMPD_VERSION
value|"4.2.8p1"
end_define

begin_comment
comment|/** Full ntpsnmpd version text */
end_comment

begin_define
define|#
directive|define
name|NTPSNMPD_FULL_VERSION
value|"ntpsnmpd 4.2.8p1"
end_define

begin_comment
comment|/**  *  Interface defines for all options.  Replace "n" with the UPPER_CASED  *  option name (as in the teOptIndex enumeration above).  *  e.g. HAVE_OPT(NOFORK)  */
end_comment

begin_define
define|#
directive|define
name|DESC
parameter_list|(
name|n
parameter_list|)
value|(ntpsnmpdOptions.pOptDesc[INDEX_OPT_## n])
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
comment|/**  *  Enumeration of ntpsnmpd exit codes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NTPSNMPD_EXIT_SUCCESS
init|=
literal|0
block|,
name|NTPSNMPD_EXIT_FAILURE
init|=
literal|1
block|,
name|NTPSNMPD_EXIT_USAGE_ERROR
init|=
literal|64
block|,
name|NTPSNMPD_EXIT_NO_CONFIG_INPUT
init|=
literal|66
block|,
name|NTPSNMPD_EXIT_LIBOPTS_FAILURE
init|=
literal|70
block|}
name|ntpsnmpd_exit_code_t
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
name|NOFORK
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NOFORK due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NOFORK
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYSLOG
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SYSLOG due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SYSLOG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AGENTXSOCKET
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining AGENTXSOCKET due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|AGENTXSOCKET
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
name|NOFORK
end_undef

begin_undef
undef|#
directive|undef
name|SYSLOG
end_undef

begin_undef
undef|#
directive|undef
name|AGENTXSOCKET
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
name|VALUE_OPT_NOFORK
value|'n'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SYSLOG
value|'p'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_AGENTXSOCKET
value|0x1001
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
value|STMTS(ntpsnmpdOptions.fOptSet&= ~OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS(ntpsnmpdOptions.fOptSet |= OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 ntpsnmpdOptions.curOptIdx = (n); \                 ntpsnmpdOptions.pzCurOpt  = NULL )
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
value|(*ntpsnmpdOptions.pUsageProc)(&ntpsnmpdOptions, c)
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
comment|/* * * * * *  *  *  Declare the ntpsnmpd option descriptor.  */
specifier|extern
name|tOptions
name|ntpsnmpdOptions
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
value|STMTS(ntpsnmpdOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_NO_XLAT_OPT_NAMES
value|STMTS(ntpsnmpdOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_CFG_NAMES
value|STMTS(ntpsnmpdOptions.fOptSet&= \                                   ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_OPT_NAMES
value|STMTS(ntpsnmpdOptions.fOptSet&= \                                   ~OPTPROC_NXLAT_OPT;)
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
comment|/* AUTOOPTS_NTPSNMPD_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* ntpsnmpd-opts.h ends here */
end_comment

end_unit

