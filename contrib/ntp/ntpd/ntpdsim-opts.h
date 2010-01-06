begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntpdsim-opts.h)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:13:12 AM EST  *  From the definitions    ntpdsim-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This header file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntpdsim author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntpdsim copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
end_comment

begin_comment
comment|/*  *  This file contains the programmatic interface to the Automated  *  Options generated for the ntpdsim program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_NTPDSIM_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_NTPDSIM_OPTS_H_GUARD
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
name|INDEX_OPT_AUTHREQ
operator|=
literal|2
block|,
name|INDEX_OPT_AUTHNOREQ
operator|=
literal|3
block|,
name|INDEX_OPT_BCASTSYNC
operator|=
literal|4
block|,
name|INDEX_OPT_SIMBROADCASTDELAY
operator|=
literal|5
block|,
name|INDEX_OPT_CONFIGFILE
operator|=
literal|6
block|,
name|INDEX_OPT_PHASENOISE
operator|=
literal|7
block|,
name|INDEX_OPT_DEBUG_LEVEL
operator|=
literal|8
block|,
name|INDEX_OPT_SET_DEBUG_LEVEL
operator|=
literal|9
block|,
name|INDEX_OPT_DRIFTFILE
operator|=
literal|10
block|,
name|INDEX_OPT_PANICGATE
operator|=
literal|11
block|,
name|INDEX_OPT_SIMSLEW
operator|=
literal|12
block|,
name|INDEX_OPT_JAILDIR
operator|=
literal|13
block|,
name|INDEX_OPT_INTERFACE
operator|=
literal|14
block|,
name|INDEX_OPT_KEYFILE
operator|=
literal|15
block|,
name|INDEX_OPT_LOGFILE
operator|=
literal|16
block|,
name|INDEX_OPT_NOVIRTUALIPS
operator|=
literal|17
block|,
name|INDEX_OPT_MODIFYMMTIMER
operator|=
literal|18
block|,
name|INDEX_OPT_NOFORK
operator|=
literal|19
block|,
name|INDEX_OPT_NICE
operator|=
literal|20
block|,
name|INDEX_OPT_SERVERTIME
operator|=
literal|21
block|,
name|INDEX_OPT_PIDFILE
operator|=
literal|22
block|,
name|INDEX_OPT_PRIORITY
operator|=
literal|23
block|,
name|INDEX_OPT_QUIT
operator|=
literal|24
block|,
name|INDEX_OPT_PROPAGATIONDELAY
operator|=
literal|25
block|,
name|INDEX_OPT_UPDATEINTERVAL
operator|=
literal|26
block|,
name|INDEX_OPT_STATSDIR
operator|=
literal|27
block|,
name|INDEX_OPT_ENDSIMTIME
operator|=
literal|28
block|,
name|INDEX_OPT_TRUSTEDKEY
operator|=
literal|29
block|,
name|INDEX_OPT_FREQERR
operator|=
literal|30
block|,
name|INDEX_OPT_WALKNOISE
operator|=
literal|31
block|,
name|INDEX_OPT_USER
operator|=
literal|32
block|,
name|INDEX_OPT_VAR
operator|=
literal|33
block|,
name|INDEX_OPT_DVAR
operator|=
literal|34
block|,
name|INDEX_OPT_SLEW
operator|=
literal|35
block|,
name|INDEX_OPT_NDELAY
operator|=
literal|36
block|,
name|INDEX_OPT_PDELAY
operator|=
literal|37
block|,
name|INDEX_OPT_VERSION
operator|=
literal|38
block|,
name|INDEX_OPT_HELP
operator|=
literal|39
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|40
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|41
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|42
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|OPTION_CT
value|43
end_define

begin_define
define|#
directive|define
name|NTPDSIM_VERSION
value|"4.2.4p8"
end_define

begin_define
define|#
directive|define
name|NTPDSIM_FULL_VERSION
value|"ntpdsim - NTP daemon simulation program - Ver. 4.2.4p8"
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
value|(ntpdsimOptions.pOptDesc[INDEX_OPT_## n])
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
name|AUTHREQ
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining AUTHREQ due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|AUTHREQ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUTHNOREQ
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining AUTHNOREQ due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|AUTHNOREQ
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BCASTSYNC
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining BCASTSYNC due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|BCASTSYNC
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIMBROADCASTDELAY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SIMBROADCASTDELAY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SIMBROADCASTDELAY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIGFILE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining CONFIGFILE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|CONFIGFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PHASENOISE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PHASENOISE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PHASENOISE
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
name|DRIFTFILE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining DRIFTFILE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|DRIFTFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PANICGATE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PANICGATE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PANICGATE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIMSLEW
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SIMSLEW due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SIMSLEW
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|JAILDIR
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining JAILDIR due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|JAILDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTERFACE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining INTERFACE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|INTERFACE
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
name|NOVIRTUALIPS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NOVIRTUALIPS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NOVIRTUALIPS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MODIFYMMTIMER
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MODIFYMMTIMER due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MODIFYMMTIMER
end_undef

begin_endif
endif|#
directive|endif
end_endif

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
name|NICE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NICE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NICE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SERVERTIME
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SERVERTIME due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SERVERTIME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PIDFILE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PIDFILE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PIDFILE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PRIORITY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PRIORITY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PRIORITY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|QUIT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining QUIT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|QUIT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PROPAGATIONDELAY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PROPAGATIONDELAY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PROPAGATIONDELAY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UPDATEINTERVAL
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining UPDATEINTERVAL due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|UPDATEINTERVAL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STATSDIR
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining STATSDIR due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|STATSDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENDSIMTIME
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining ENDSIMTIME due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|ENDSIMTIME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUSTEDKEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining TRUSTEDKEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|TRUSTEDKEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FREQERR
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining FREQERR due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|FREQERR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WALKNOISE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining WALKNOISE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|WALKNOISE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USER
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining USER due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|USER
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VAR
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining VAR due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|VAR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DVAR
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining DVAR due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|DVAR
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
name|NDELAY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NDELAY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NDELAY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PDELAY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PDELAY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PDELAY
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
name|AUTHREQ
end_undef

begin_undef
undef|#
directive|undef
name|AUTHNOREQ
end_undef

begin_undef
undef|#
directive|undef
name|BCASTSYNC
end_undef

begin_undef
undef|#
directive|undef
name|SIMBROADCASTDELAY
end_undef

begin_undef
undef|#
directive|undef
name|CONFIGFILE
end_undef

begin_undef
undef|#
directive|undef
name|PHASENOISE
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
name|DRIFTFILE
end_undef

begin_undef
undef|#
directive|undef
name|PANICGATE
end_undef

begin_undef
undef|#
directive|undef
name|SIMSLEW
end_undef

begin_undef
undef|#
directive|undef
name|JAILDIR
end_undef

begin_undef
undef|#
directive|undef
name|INTERFACE
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
name|NOVIRTUALIPS
end_undef

begin_undef
undef|#
directive|undef
name|MODIFYMMTIMER
end_undef

begin_undef
undef|#
directive|undef
name|NOFORK
end_undef

begin_undef
undef|#
directive|undef
name|NICE
end_undef

begin_undef
undef|#
directive|undef
name|SERVERTIME
end_undef

begin_undef
undef|#
directive|undef
name|PIDFILE
end_undef

begin_undef
undef|#
directive|undef
name|PRIORITY
end_undef

begin_undef
undef|#
directive|undef
name|QUIT
end_undef

begin_undef
undef|#
directive|undef
name|PROPAGATIONDELAY
end_undef

begin_undef
undef|#
directive|undef
name|UPDATEINTERVAL
end_undef

begin_undef
undef|#
directive|undef
name|STATSDIR
end_undef

begin_undef
undef|#
directive|undef
name|ENDSIMTIME
end_undef

begin_undef
undef|#
directive|undef
name|TRUSTEDKEY
end_undef

begin_undef
undef|#
directive|undef
name|FREQERR
end_undef

begin_undef
undef|#
directive|undef
name|WALKNOISE
end_undef

begin_undef
undef|#
directive|undef
name|USER
end_undef

begin_undef
undef|#
directive|undef
name|VAR
end_undef

begin_undef
undef|#
directive|undef
name|DVAR
end_undef

begin_undef
undef|#
directive|undef
name|SLEW
end_undef

begin_undef
undef|#
directive|undef
name|NDELAY
end_undef

begin_undef
undef|#
directive|undef
name|PDELAY
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
name|VALUE_OPT_AUTHREQ
value|'a'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_AUTHNOREQ
value|'A'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_BCASTSYNC
value|'b'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SIMBROADCASTDELAY
value|'B'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_CONFIGFILE
value|'c'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PHASENOISE
value|'C'
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
name|VALUE_OPT_DRIFTFILE
value|'f'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PANICGATE
value|'g'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SIMSLEW
value|'H'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_JAILDIR
value|'i'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_INTERFACE
value|'I'
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
name|VALUE_OPT_NOVIRTUALIPS
value|'L'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_WINNT
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_MODIFYMMTIMER
value|'M'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
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
name|VALUE_OPT_NICE
value|'N'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SERVERTIME
value|'O'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PIDFILE
value|'p'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PRIORITY
value|'P'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_PRIORITY
value|(DESC(PRIORITY).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_QUIT
value|'q'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PROPAGATIONDELAY
value|'r'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_UPDATEINTERVAL
value|'U'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_UPDATEINTERVAL
value|(DESC(UPDATEINTERVAL).optArg.argInt)
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_STATSDIR
value|'s'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_ENDSIMTIME
value|'S'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_TRUSTEDKEY
value|'t'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_FREQERR
value|'T'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_WALKNOISE
value|'W'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_USER
value|'u'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_VAR
value|'v'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_DVAR
value|'V'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SLEW
value|'x'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_NDELAY
value|'Y'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_PDELAY
value|'Z'
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
value|STMTS( ntpdsimOptions.fOptSet&= ~OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS( ntpdsimOptions.fOptSet |= OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 ntpdsimOptions.curOptIdx = (n); \                 ntpdsimOptions.pzCurOpt  = NULL )
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
value|(*ntpdsimOptions.pUsageProc)(&ntpdsimOptions, c )
end_define

begin_comment
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/opthead.tpl near line 360 */
end_comment

begin_comment
comment|/* * * * * *  *  *  Declare the ntpdsim option descriptor.  */
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
name|ntpdsimOptions
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
comment|/* AUTOOPTS_NTPDSIM_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* ntpdsim-opts.h ends here */
end_comment

end_unit

