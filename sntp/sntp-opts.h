begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (sntp-opts.h)  *  *  It has been AutoGen-ed  December 19, 2014 at 07:51:00 AM by AutoGen 5.18.5pre4  *  From the definitions    sntp-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This header file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the sntp author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The sntp program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1970-2014 The University of Delaware, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
end_comment

begin_comment
comment|/**  *  This file contains the programmatic interface to the Automated  *  Options generated for the sntp program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_SNTP_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_SNTP_OPTS_H_GUARD
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
comment|/**  *  Enumeration of each option type for sntp  */
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
name|INDEX_OPT_AUTHENTICATION
operator|=
literal|2
block|,
name|INDEX_OPT_BROADCAST
operator|=
literal|3
block|,
name|INDEX_OPT_CONCURRENT
operator|=
literal|4
block|,
name|INDEX_OPT_DEBUG_LEVEL
operator|=
literal|5
block|,
name|INDEX_OPT_SET_DEBUG_LEVEL
operator|=
literal|6
block|,
name|INDEX_OPT_GAP
operator|=
literal|7
block|,
name|INDEX_OPT_KOD
operator|=
literal|8
block|,
name|INDEX_OPT_KEYFILE
operator|=
literal|9
block|,
name|INDEX_OPT_LOGFILE
operator|=
literal|10
block|,
name|INDEX_OPT_STEPLIMIT
operator|=
literal|11
block|,
name|INDEX_OPT_NTPVERSION
operator|=
literal|12
block|,
name|INDEX_OPT_USERESERVEDPORT
operator|=
literal|13
block|,
name|INDEX_OPT_STEP
operator|=
literal|14
block|,
name|INDEX_OPT_SLEW
operator|=
literal|15
block|,
name|INDEX_OPT_TIMEOUT
operator|=
literal|16
block|,
name|INDEX_OPT_WAIT
operator|=
literal|17
block|,
name|INDEX_OPT_VERSION
operator|=
literal|18
block|,
name|INDEX_OPT_HELP
operator|=
literal|19
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|20
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|21
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|22
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_comment
comment|/** count of all options for sntp */
end_comment

begin_define
define|#
directive|define
name|OPTION_CT
value|23
end_define

begin_comment
comment|/** sntp version */
end_comment

begin_define
define|#
directive|define
name|SNTP_VERSION
value|"4.2.8"
end_define

begin_comment
comment|/** Full sntp version text */
end_comment

begin_define
define|#
directive|define
name|SNTP_FULL_VERSION
value|"sntp 4.2.8"
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
value|(sntpOptions.pOptDesc[INDEX_OPT_## n])
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
comment|/**  *  Enumeration of sntp exit codes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SNTP_EXIT_SUCCESS
init|=
literal|0
block|,
name|SNTP_EXIT_FAILURE
init|=
literal|1
block|,
name|SNTP_EXIT_USAGE_ERROR
init|=
literal|64
block|,
name|SNTP_EXIT_NO_CONFIG_INPUT
init|=
literal|66
block|,
name|SNTP_EXIT_LIBOPTS_FAILURE
init|=
literal|70
block|}
name|sntp_exit_code_t
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
name|AUTHENTICATION
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining AUTHENTICATION due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|AUTHENTICATION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROADCAST
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining BROADCAST due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|BROADCAST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONCURRENT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining CONCURRENT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|CONCURRENT
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
name|GAP
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining GAP due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|GAP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KOD
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining KOD due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|KOD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KEYFILE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining KEYFILE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|KEYFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LOGFILE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining LOGFILE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|LOGFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STEPLIMIT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining STEPLIMIT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|STEPLIMIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NTPVERSION
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NTPVERSION due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NTPVERSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USERESERVEDPORT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining USERESERVEDPORT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|USERESERVEDPORT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STEP
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining STEP due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|STEP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SLEW
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SLEW due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SLEW
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TIMEOUT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining TIMEOUT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|TIMEOUT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WAIT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining WAIT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|WAIT
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
name|AUTHENTICATION
end_undef

begin_undef
undef|#
directive|undef
name|BROADCAST
end_undef

begin_undef
undef|#
directive|undef
name|CONCURRENT
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
name|GAP
end_undef

begin_undef
undef|#
directive|undef
name|KOD
end_undef

begin_undef
undef|#
directive|undef
name|KEYFILE
end_undef

begin_undef
undef|#
directive|undef
name|LOGFILE
end_undef

begin_undef
undef|#
directive|undef
name|STEPLIMIT
end_undef

begin_undef
undef|#
directive|undef
name|NTPVERSION
end_undef

begin_undef
undef|#
directive|undef
name|USERESERVEDPORT
end_undef

begin_undef
undef|#
directive|undef
name|STEP
end_undef

begin_undef
undef|#
directive|undef
name|SLEW
end_undef

begin_undef
undef|#
directive|undef
name|TIMEOUT
end_undef

begin_undef
undef|#
directive|undef
name|WAIT
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
name|VALUE_OPT_AUTHENTICATION
value|'a'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_AUTHENTICATION
value|(DESC(AUTHENTICATION).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_BROADCAST
value|'b'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_CONCURRENT
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
name|VALUE_OPT_GAP
value|'g'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_GAP
value|(DESC(GAP).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_KOD
value|'K'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_KEYFILE
value|'k'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_LOGFILE
value|'l'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_STEPLIMIT
value|'M'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_STEPLIMIT
value|(DESC(STEPLIMIT).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_NTPVERSION
value|'o'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_NTPVERSION
value|(DESC(NTPVERSION).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_USERESERVEDPORT
value|'r'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_STEP
value|'S'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SLEW
value|'s'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_TIMEOUT
value|'t'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_TIMEOUT
value|(DESC(TIMEOUT).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_WAIT
value|0x1001
end_define

begin_define
define|#
directive|define
name|SET_OPT_WAIT
value|STMTS( \         DESC(WAIT).optActualIndex = 17; \         DESC(WAIT).optActualValue = VALUE_OPT_WAIT; \         DESC(WAIT).fOptState&= OPTST_PERSISTENT_MASK; \         DESC(WAIT).fOptState |= OPTST_SET )
end_define

begin_define
define|#
directive|define
name|DISABLE_OPT_WAIT
value|STMTS( \         DESC(WAIT).fOptState&= OPTST_PERSISTENT_MASK; \         DESC(WAIT).fOptState |= OPTST_SET | OPTST_DISABLED; \         DESC(WAIT).optArg.argString = NULL )
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
value|STMTS(sntpOptions.fOptSet&= ~OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS(sntpOptions.fOptSet |= OPTPROC_ERRSTOP)
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 sntpOptions.curOptIdx = (n); \                 sntpOptions.pzCurOpt  = NULL )
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
value|(*sntpOptions.pUsageProc)(&sntpOptions, c)
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
comment|/* * * * * *  *  *  Declare the sntp option descriptor.  */
specifier|extern
name|tOptions
name|sntpOptions
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
value|STMTS(sntpOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_NO_XLAT_OPT_NAMES
value|STMTS(sntpOptions.fOptSet |= \                                     OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_CFG_NAMES
value|STMTS(sntpOptions.fOptSet&= \                                   ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
end_define

begin_define
define|#
directive|define
name|OPT_XLAT_OPT_NAMES
value|STMTS(sntpOptions.fOptSet&= \                                   ~OPTPROC_NXLAT_OPT;)
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
comment|/* AUTOOPTS_SNTP_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* sntp-opts.h ends here */
end_comment

end_unit

