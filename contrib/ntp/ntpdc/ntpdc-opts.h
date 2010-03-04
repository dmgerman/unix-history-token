begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntpdc-opts.h)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:00 AM EST  *  From the definitions    ntpdc-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This header file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntpdc author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntpdc copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
end_comment

begin_comment
comment|/*  *  This file contains the programmatic interface to the Automated  *  Options generated for the ntpdc program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_NTPDC_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_NTPDC_OPTS_H_GUARD
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
comment|/*  *  Ensure that the library used for compiling this generated header is at  *  least as new as the version current when the header template was released  *  (not counting patch version increments).  Also ensure that the oldest  *  tolerable version is at least as old as what was current when the header  *  template was released.  */
end_comment

begin_define
define|#
directive|define
name|AO_TEMPLATE_VERSION
value|118784
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
comment|/*  *  Enumeration of each option:  */
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
name|INDEX_OPT_LISTPEERS
operator|=
literal|3
block|,
name|INDEX_OPT_PEERS
operator|=
literal|4
block|,
name|INDEX_OPT_SHOWPEERS
operator|=
literal|5
block|,
name|INDEX_OPT_INTERACTIVE
operator|=
literal|6
block|,
name|INDEX_OPT_DEBUG_LEVEL
operator|=
literal|7
block|,
name|INDEX_OPT_SET_DEBUG_LEVEL
operator|=
literal|8
block|,
name|INDEX_OPT_NUMERIC
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

begin_define
define|#
directive|define
name|OPTION_CT
value|15
end_define

begin_define
define|#
directive|define
name|NTPDC_VERSION
value|"4.2.4p8"
end_define

begin_define
define|#
directive|define
name|NTPDC_FULL_VERSION
value|"ntpdc - vendor-specific NTP query program - Ver. 4.2.4p8"
end_define

begin_comment
comment|/*  *  Interface defines for all options.  Replace "n" with the UPPER_CASED  *  option name (as in the teOptIndex enumeration above).  *  e.g. HAVE_OPT( IPV4 )  */
end_comment

begin_define
define|#
directive|define
name|DESC
parameter_list|(
name|n
parameter_list|)
value|(ntpdcOptions.pOptDesc[INDEX_OPT_## n])
end_define

begin_define
define|#
directive|define
name|HAVE_OPT
parameter_list|(
name|n
parameter_list|)
value|(! UNUSED_OPT(& DESC(n)))
end_define

begin_define
define|#
directive|define
name|OPT_ARG
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).optArg.argString)
end_define

begin_define
define|#
directive|define
name|STATE_OPT
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).fOptState& OPTST_SET_MASK)
end_define

begin_define
define|#
directive|define
name|COUNT_OPT
parameter_list|(
name|n
parameter_list|)
value|(DESC(n).optOccCt)
end_define

begin_define
define|#
directive|define
name|ISSEL_OPT
parameter_list|(
name|n
parameter_list|)
value|(SELECTED_OPT(&DESC(n)))
end_define

begin_define
define|#
directive|define
name|ISUNUSED_OPT
parameter_list|(
name|n
parameter_list|)
value|(UNUSED_OPT(& DESC(n)))
end_define

begin_define
define|#
directive|define
name|ENABLED_OPT
parameter_list|(
name|n
parameter_list|)
value|(! DISABLED_OPT(& DESC(n)))
end_define

begin_define
define|#
directive|define
name|STACKCT_OPT
parameter_list|(
name|n
parameter_list|)
value|(((tArgList*)(DESC(n).optCookie))->useCt)
end_define

begin_define
define|#
directive|define
name|STACKLST_OPT
parameter_list|(
name|n
parameter_list|)
value|(((tArgList*)(DESC(n).optCookie))->apzArgs)
end_define

begin_define
define|#
directive|define
name|CLEAR_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 DESC(n).fOptState&= OPTST_PERSISTENT_MASK;   \                 if ( (DESC(n).fOptState& OPTST_INITENABLED) == 0) \                     DESC(n).fOptState |= OPTST_DISABLED; \                 DESC(n).optCookie = NULL )
end_define

begin_comment
comment|/*  *  Make sure there are no #define name conflicts with the option names  */
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
name|LISTPEERS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining LISTPEERS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|LISTPEERS
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
name|SHOWPEERS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SHOWPEERS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SHOWPEERS
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
name|LISTPEERS
end_undef

begin_undef
undef|#
directive|undef
name|PEERS
end_undef

begin_undef
undef|#
directive|undef
name|SHOWPEERS
end_undef

begin_undef
undef|#
directive|undef
name|INTERACTIVE
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
name|NUMERIC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  NO_OPTION_NAME_WARNINGS */
end_comment

begin_comment
comment|/*  *  Interface defines for specific options.  */
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
name|WHICH_OPT_IPV4
value|(DESC(IPV4).optActualValue)
end_define

begin_define
define|#
directive|define
name|WHICH_IDX_IPV4
value|(DESC(IPV4).optActualIndex)
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
name|VALUE_OPT_LISTPEERS
value|'l'
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
name|VALUE_OPT_SHOWPEERS
value|'s'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_INTERACTIVE
value|'i'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_DEBUG_LEVEL
value|'d'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_SET_DEBUG_LEVEL
value|'D'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_NUMERIC
value|'n'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_VERSION
value|'v'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_HELP
value|'?'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_MORE_HELP
value|'!'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SAVE_OPTS
value|'>'
end_define

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
value|STMTS( \         DESC(SAVE_OPTS).fOptState&= OPTST_PERSISTENT_MASK; \         DESC(SAVE_OPTS).fOptState |= OPTST_SET; \         DESC(SAVE_OPTS).optArg.argString = (char const*)(a) )
end_define

begin_comment
comment|/*  *  Interface defines not associated with particular options  */
end_comment

begin_define
define|#
directive|define
name|ERRSKIP_OPTERR
value|STMTS( ntpdcOptions.fOptSet&= ~OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS( ntpdcOptions.fOptSet |= OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 ntpdcOptions.curOptIdx = (n); \                 ntpdcOptions.pzCurOpt  = NULL )
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
value|(*ntpdcOptions.pUsageProc)(&ntpdcOptions, c )
end_define

begin_comment
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/opthead.tpl near line 360 */
end_comment

begin_comment
comment|/* * * * * *  *  *  Declare the ntpdc option descriptor.  */
end_comment

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
specifier|extern
name|tOptions
name|ntpdcOptions
decl_stmt|;
ifndef|#
directive|ifndef
name|_
if|#
directive|if
name|ENABLE_NLS
include|#
directive|include
file|<stdio.h>
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
define|#
directive|define
name|_
parameter_list|(
name|s
parameter_list|)
value|aoGetsText(s)
else|#
directive|else
comment|/* ENABLE_NLS */
define|#
directive|define
name|_
parameter_list|(
name|s
parameter_list|)
value|s
endif|#
directive|endif
comment|/* ENABLE_NLS */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_NTPDC_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* ntpdc-opts.h ends here */
end_comment

end_unit

