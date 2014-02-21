begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntpd-opts.c)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:13:10 AM EST  *  From the definitions    ntpd-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This source file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntpd author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntpd copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_define
define|#
directive|define
name|OPTION_CODE_COMPILE
value|1
end_define

begin_include
include|#
directive|include
file|"ntpd-opts.h"
end_include

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
name|tSCC
name|zCopyright
index|[]
init|=
literal|"ntpd copyright (c) 1970-2009 David L. Mills and/or others, all rights reserved"
decl_stmt|;
name|tSCC
name|zCopyrightNotice
index|[]
init|=
comment|/* extracted from ../include/copyright.def near line 8 */
literal|"see html/copyright.html"
decl_stmt|;
specifier|extern
name|tUsageProc
name|optionUsage
decl_stmt|;
comment|/*  *  global included definitions  */
ifdef|#
directive|ifdef
name|__windows
specifier|extern
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
else|#
directive|else
include|#
directive|include
file|<stdlib.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NULL
define|#
directive|define
name|NULL
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EXIT_SUCCESS
define|#
directive|define
name|EXIT_SUCCESS
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EXIT_FAILURE
define|#
directive|define
name|EXIT_FAILURE
value|1
endif|#
directive|endif
comment|/*  *  Ipv4 option description:  */
name|tSCC
name|zIpv4Text
index|[]
init|=
literal|"Force IPv4 DNS name resolution"
decl_stmt|;
name|tSCC
name|zIpv4_NAME
index|[]
init|=
literal|"IPV4"
decl_stmt|;
name|tSCC
name|zIpv4_Name
index|[]
init|=
literal|"ipv4"
decl_stmt|;
define|#
directive|define
name|IPV4_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Ipv6 option description:  */
name|tSCC
name|zIpv6Text
index|[]
init|=
literal|"Force IPv6 DNS name resolution"
decl_stmt|;
name|tSCC
name|zIpv6_NAME
index|[]
init|=
literal|"IPV6"
decl_stmt|;
name|tSCC
name|zIpv6_Name
index|[]
init|=
literal|"ipv6"
decl_stmt|;
define|#
directive|define
name|IPV6_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Authreq option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zAuthreqText
index|[]
init|=
literal|"Require crypto authentication"
decl_stmt|;
name|tSCC
name|zAuthreq_NAME
index|[]
init|=
literal|"AUTHREQ"
decl_stmt|;
name|tSCC
name|zAuthreq_Name
index|[]
init|=
literal|"authreq"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aAuthreqCantList
index|[]
init|=
block|{
name|INDEX_OPT_AUTHNOREQ
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|AUTHREQ_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Authnoreq option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zAuthnoreqText
index|[]
init|=
literal|"Do not require crypto authentication"
decl_stmt|;
name|tSCC
name|zAuthnoreq_NAME
index|[]
init|=
literal|"AUTHNOREQ"
decl_stmt|;
name|tSCC
name|zAuthnoreq_Name
index|[]
init|=
literal|"authnoreq"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aAuthnoreqCantList
index|[]
init|=
block|{
name|INDEX_OPT_AUTHREQ
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|AUTHNOREQ_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Bcastsync option description:  */
name|tSCC
name|zBcastsyncText
index|[]
init|=
literal|"Allow us to sync to broadcast servers"
decl_stmt|;
name|tSCC
name|zBcastsync_NAME
index|[]
init|=
literal|"BCASTSYNC"
decl_stmt|;
name|tSCC
name|zBcastsync_Name
index|[]
init|=
literal|"bcastsync"
decl_stmt|;
define|#
directive|define
name|BCASTSYNC_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Configfile option description:  */
name|tSCC
name|zConfigfileText
index|[]
init|=
literal|"configuration file name"
decl_stmt|;
name|tSCC
name|zConfigfile_NAME
index|[]
init|=
literal|"CONFIGFILE"
decl_stmt|;
name|tSCC
name|zConfigfile_Name
index|[]
init|=
literal|"configfile"
decl_stmt|;
define|#
directive|define
name|CONFIGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Debug_Level option description:  */
ifdef|#
directive|ifdef
name|DEBUG
name|tSCC
name|zDebug_LevelText
index|[]
init|=
literal|"Increase output debug message level"
decl_stmt|;
name|tSCC
name|zDebug_Level_NAME
index|[]
init|=
literal|"DEBUG_LEVEL"
decl_stmt|;
name|tSCC
name|zDebug_Level_Name
index|[]
init|=
literal|"debug-level"
decl_stmt|;
define|#
directive|define
name|DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Debug_Level */
define|#
directive|define
name|VALUE_OPT_DEBUG_LEVEL
value|NO_EQUIVALENT
define|#
directive|define
name|DEBUG_LEVEL_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zDebug_LevelText
value|NULL
define|#
directive|define
name|zDebug_Level_NAME
value|NULL
define|#
directive|define
name|zDebug_Level_Name
value|NULL
endif|#
directive|endif
comment|/* DEBUG */
comment|/*  *  Set_Debug_Level option description:  */
ifdef|#
directive|ifdef
name|DEBUG
name|tSCC
name|zSet_Debug_LevelText
index|[]
init|=
literal|"Set the output debug message level"
decl_stmt|;
name|tSCC
name|zSet_Debug_Level_NAME
index|[]
init|=
literal|"SET_DEBUG_LEVEL"
decl_stmt|;
name|tSCC
name|zSet_Debug_Level_Name
index|[]
init|=
literal|"set-debug-level"
decl_stmt|;
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Set_Debug_Level */
define|#
directive|define
name|VALUE_OPT_SET_DEBUG_LEVEL
value|NO_EQUIVALENT
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zSet_Debug_LevelText
value|NULL
define|#
directive|define
name|zSet_Debug_Level_NAME
value|NULL
define|#
directive|define
name|zSet_Debug_Level_Name
value|NULL
endif|#
directive|endif
comment|/* DEBUG */
comment|/*  *  Driftfile option description:  */
name|tSCC
name|zDriftfileText
index|[]
init|=
literal|"frequency drift file name"
decl_stmt|;
name|tSCC
name|zDriftfile_NAME
index|[]
init|=
literal|"DRIFTFILE"
decl_stmt|;
name|tSCC
name|zDriftfile_Name
index|[]
init|=
literal|"driftfile"
decl_stmt|;
define|#
directive|define
name|DRIFTFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Panicgate option description:  */
name|tSCC
name|zPanicgateText
index|[]
init|=
literal|"Allow the first adjustment to be Big"
decl_stmt|;
name|tSCC
name|zPanicgate_NAME
index|[]
init|=
literal|"PANICGATE"
decl_stmt|;
name|tSCC
name|zPanicgate_Name
index|[]
init|=
literal|"panicgate"
decl_stmt|;
define|#
directive|define
name|PANICGATE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Jaildir option description:  */
name|tSCC
name|zJaildirText
index|[]
init|=
literal|"Jail directory"
decl_stmt|;
name|tSCC
name|zJaildir_NAME
index|[]
init|=
literal|"JAILDIR"
decl_stmt|;
name|tSCC
name|zJaildir_Name
index|[]
init|=
literal|"jaildir"
decl_stmt|;
define|#
directive|define
name|JAILDIR_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Interface option description:  */
name|tSCC
name|zInterfaceText
index|[]
init|=
literal|"Listen on interface"
decl_stmt|;
name|tSCC
name|zInterface_NAME
index|[]
init|=
literal|"INTERFACE"
decl_stmt|;
name|tSCC
name|zInterface_Name
index|[]
init|=
literal|"interface"
decl_stmt|;
define|#
directive|define
name|INTERFACE_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Keyfile option description:  */
name|tSCC
name|zKeyfileText
index|[]
init|=
literal|"path to symmetric keys"
decl_stmt|;
name|tSCC
name|zKeyfile_NAME
index|[]
init|=
literal|"KEYFILE"
decl_stmt|;
name|tSCC
name|zKeyfile_Name
index|[]
init|=
literal|"keyfile"
decl_stmt|;
define|#
directive|define
name|KEYFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Logfile option description:  */
name|tSCC
name|zLogfileText
index|[]
init|=
literal|"path to the log file"
decl_stmt|;
name|tSCC
name|zLogfile_NAME
index|[]
init|=
literal|"LOGFILE"
decl_stmt|;
name|tSCC
name|zLogfile_Name
index|[]
init|=
literal|"logfile"
decl_stmt|;
define|#
directive|define
name|LOGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Novirtualips option description:  */
name|tSCC
name|zNovirtualipsText
index|[]
init|=
literal|"Do not listen to virtual IPs"
decl_stmt|;
name|tSCC
name|zNovirtualips_NAME
index|[]
init|=
literal|"NOVIRTUALIPS"
decl_stmt|;
name|tSCC
name|zNovirtualips_Name
index|[]
init|=
literal|"novirtualips"
decl_stmt|;
define|#
directive|define
name|NOVIRTUALIPS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Modifymmtimer option description:  */
ifdef|#
directive|ifdef
name|SYS_WINNT
name|tSCC
name|zModifymmtimerText
index|[]
init|=
literal|"Modify Multimedia Timer (Windows only)"
decl_stmt|;
name|tSCC
name|zModifymmtimer_NAME
index|[]
init|=
literal|"MODIFYMMTIMER"
decl_stmt|;
name|tSCC
name|zModifymmtimer_Name
index|[]
init|=
literal|"modifymmtimer"
decl_stmt|;
define|#
directive|define
name|MODIFYMMTIMER_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Modifymmtimer */
define|#
directive|define
name|VALUE_OPT_MODIFYMMTIMER
value|NO_EQUIVALENT
define|#
directive|define
name|MODIFYMMTIMER_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zModifymmtimerText
value|NULL
define|#
directive|define
name|zModifymmtimer_NAME
value|NULL
define|#
directive|define
name|zModifymmtimer_Name
value|NULL
endif|#
directive|endif
comment|/* SYS_WINNT */
comment|/*  *  Nofork option description:  */
name|tSCC
name|zNoforkText
index|[]
init|=
literal|"Do not fork"
decl_stmt|;
name|tSCC
name|zNofork_NAME
index|[]
init|=
literal|"NOFORK"
decl_stmt|;
name|tSCC
name|zNofork_Name
index|[]
init|=
literal|"nofork"
decl_stmt|;
define|#
directive|define
name|NOFORK_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Nice option description:  */
name|tSCC
name|zNiceText
index|[]
init|=
literal|"Run at high priority"
decl_stmt|;
name|tSCC
name|zNice_NAME
index|[]
init|=
literal|"NICE"
decl_stmt|;
name|tSCC
name|zNice_Name
index|[]
init|=
literal|"nice"
decl_stmt|;
define|#
directive|define
name|NICE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Pidfile option description:  */
name|tSCC
name|zPidfileText
index|[]
init|=
literal|"path to the PID file"
decl_stmt|;
name|tSCC
name|zPidfile_NAME
index|[]
init|=
literal|"PIDFILE"
decl_stmt|;
name|tSCC
name|zPidfile_Name
index|[]
init|=
literal|"pidfile"
decl_stmt|;
define|#
directive|define
name|PIDFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Priority option description:  */
name|tSCC
name|zPriorityText
index|[]
init|=
literal|"Process priority"
decl_stmt|;
name|tSCC
name|zPriority_NAME
index|[]
init|=
literal|"PRIORITY"
decl_stmt|;
name|tSCC
name|zPriority_Name
index|[]
init|=
literal|"priority"
decl_stmt|;
define|#
directive|define
name|PRIORITY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/*  *  Quit option description:  */
name|tSCC
name|zQuitText
index|[]
init|=
literal|"Set the time and quit"
decl_stmt|;
name|tSCC
name|zQuit_NAME
index|[]
init|=
literal|"QUIT"
decl_stmt|;
name|tSCC
name|zQuit_Name
index|[]
init|=
literal|"quit"
decl_stmt|;
define|#
directive|define
name|QUIT_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Propagationdelay option description:  */
name|tSCC
name|zPropagationdelayText
index|[]
init|=
literal|"Broadcast/propagation delay"
decl_stmt|;
name|tSCC
name|zPropagationdelay_NAME
index|[]
init|=
literal|"PROPAGATIONDELAY"
decl_stmt|;
name|tSCC
name|zPropagationdelay_Name
index|[]
init|=
literal|"propagationdelay"
decl_stmt|;
define|#
directive|define
name|PROPAGATIONDELAY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Updateinterval option description:  */
name|tSCC
name|zUpdateintervalText
index|[]
init|=
literal|"interval in seconds between scans for new or dropped interfaces"
decl_stmt|;
name|tSCC
name|zUpdateinterval_NAME
index|[]
init|=
literal|"UPDATEINTERVAL"
decl_stmt|;
name|tSCC
name|zUpdateinterval_Name
index|[]
init|=
literal|"updateinterval"
decl_stmt|;
define|#
directive|define
name|UPDATEINTERVAL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/*  *  Statsdir option description:  */
name|tSCC
name|zStatsdirText
index|[]
init|=
literal|"Statistics file location"
decl_stmt|;
name|tSCC
name|zStatsdir_NAME
index|[]
init|=
literal|"STATSDIR"
decl_stmt|;
name|tSCC
name|zStatsdir_Name
index|[]
init|=
literal|"statsdir"
decl_stmt|;
define|#
directive|define
name|STATSDIR_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Trustedkey option description:  */
name|tSCC
name|zTrustedkeyText
index|[]
init|=
literal|"Trusted key number"
decl_stmt|;
name|tSCC
name|zTrustedkey_NAME
index|[]
init|=
literal|"TRUSTEDKEY"
decl_stmt|;
name|tSCC
name|zTrustedkey_Name
index|[]
init|=
literal|"trustedkey"
decl_stmt|;
define|#
directive|define
name|TRUSTEDKEY_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  User option description:  */
name|tSCC
name|zUserText
index|[]
init|=
literal|"Run as userid (or userid:groupid)"
decl_stmt|;
name|tSCC
name|zUser_NAME
index|[]
init|=
literal|"USER"
decl_stmt|;
name|tSCC
name|zUser_Name
index|[]
init|=
literal|"user"
decl_stmt|;
define|#
directive|define
name|USER_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Var option description:  */
name|tSCC
name|zVarText
index|[]
init|=
literal|"make ARG an ntp variable (RW)"
decl_stmt|;
name|tSCC
name|zVar_NAME
index|[]
init|=
literal|"VAR"
decl_stmt|;
name|tSCC
name|zVar_Name
index|[]
init|=
literal|"var"
decl_stmt|;
define|#
directive|define
name|VAR_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Dvar option description:  */
name|tSCC
name|zDvarText
index|[]
init|=
literal|"make ARG an ntp variable (RW|DEF)"
decl_stmt|;
name|tSCC
name|zDvar_NAME
index|[]
init|=
literal|"DVAR"
decl_stmt|;
name|tSCC
name|zDvar_Name
index|[]
init|=
literal|"dvar"
decl_stmt|;
define|#
directive|define
name|DVAR_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Slew option description:  */
name|tSCC
name|zSlewText
index|[]
init|=
literal|"Slew up to 600 seconds"
decl_stmt|;
name|tSCC
name|zSlew_NAME
index|[]
init|=
literal|"SLEW"
decl_stmt|;
name|tSCC
name|zSlew_Name
index|[]
init|=
literal|"slew"
decl_stmt|;
define|#
directive|define
name|SLEW_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Help/More_Help/Version option descriptions:  */
name|tSCC
name|zHelpText
index|[]
init|=
literal|"Display usage information and exit"
decl_stmt|;
name|tSCC
name|zHelp_Name
index|[]
init|=
literal|"help"
decl_stmt|;
name|tSCC
name|zMore_HelpText
index|[]
init|=
literal|"Extended usage information passed thru pager"
decl_stmt|;
name|tSCC
name|zMore_Help_Name
index|[]
init|=
literal|"more-help"
decl_stmt|;
name|tSCC
name|zVersionText
index|[]
init|=
literal|"Output version information and exit"
decl_stmt|;
name|tSCC
name|zVersion_Name
index|[]
init|=
literal|"version"
decl_stmt|;
comment|/*  *  Declare option callback procedures  */
ifdef|#
directive|ifdef
name|DEBUG
specifier|static
name|tOptProc
name|doOptSet_Debug_Level
decl_stmt|;
else|#
directive|else
comment|/* not DEBUG */
define|#
directive|define
name|doOptSet_Debug_Level
value|NULL
endif|#
directive|endif
comment|/* def/not DEBUG */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTPD_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
specifier|extern
name|tOptProc
name|optionNumericVal
decl_stmt|,
name|optionPagedUsage
decl_stmt|,
name|optionStackArg
decl_stmt|,
name|optionVersionStderr
decl_stmt|;
specifier|static
name|tOptProc
name|doUsageOpt
decl_stmt|;
comment|/*  *  #define map the "normal" callout procs to the test ones...  */
define|#
directive|define
name|SET_DEBUG_LEVEL_OPT_PROC
value|optionStackArg
else|#
directive|else
comment|/* NOT defined TEST_NTPD_OPTS */
comment|/*  *  When not under test, there are different procs to use  */
specifier|extern
name|tOptProc
name|optionNumericVal
decl_stmt|,
name|optionPagedUsage
decl_stmt|,
name|optionPrintVersion
decl_stmt|,
name|optionStackArg
decl_stmt|;
specifier|static
name|tOptProc
name|doUsageOpt
decl_stmt|;
comment|/*  *  #define map the "normal" callout procs  */
define|#
directive|define
name|SET_DEBUG_LEVEL_OPT_PROC
value|doOptSet_Debug_Level
define|#
directive|define
name|SET_DEBUG_LEVEL_OPT_PROC
value|doOptSet_Debug_Level
endif|#
directive|endif
comment|/* defined(TEST_NTPD_OPTS) */
ifdef|#
directive|ifdef
name|TEST_NTPD_OPTS
define|#
directive|define
name|DOVERPROC
value|optionVersionStderr
else|#
directive|else
define|#
directive|define
name|DOVERPROC
value|optionPrintVersion
endif|#
directive|endif
comment|/* TEST_NTPD_OPTS */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpd Option Descriptions.  */
specifier|static
name|tOptDesc
name|optDesc
index|[
name|OPTION_CT
index|]
init|=
block|{
block|{
comment|/* entry idx, value */
literal|0
block|,
name|VALUE_OPT_IPV4
block|,
comment|/* equiv idx, value */
name|NO_EQUIVALENT
block|,
literal|0
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|IPV4_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zIpv4Text
block|,
name|zIpv4_NAME
block|,
name|zIpv4_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|1
block|,
name|VALUE_OPT_IPV6
block|,
comment|/* equiv idx, value */
name|NOLIMIT
block|,
name|NOLIMIT
block|,
comment|/* equivalenced to  */
name|INDEX_OPT_IPV4
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|IPV6_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zIpv6Text
block|,
name|zIpv6_NAME
block|,
name|zIpv6_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|2
block|,
name|VALUE_OPT_AUTHREQ
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_AUTHREQ
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|AUTHREQ_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aAuthreqCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zAuthreqText
block|,
name|zAuthreq_NAME
block|,
name|zAuthreq_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|3
block|,
name|VALUE_OPT_AUTHNOREQ
block|,
comment|/* equiv idx, value */
literal|3
block|,
name|VALUE_OPT_AUTHNOREQ
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|AUTHNOREQ_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aAuthnoreqCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zAuthnoreqText
block|,
name|zAuthnoreq_NAME
block|,
name|zAuthnoreq_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|4
block|,
name|VALUE_OPT_BCASTSYNC
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_BCASTSYNC
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|BCASTSYNC_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zBcastsyncText
block|,
name|zBcastsync_NAME
block|,
name|zBcastsync_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|5
block|,
name|VALUE_OPT_CONFIGFILE
block|,
comment|/* equiv idx, value */
literal|5
block|,
name|VALUE_OPT_CONFIGFILE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|CONFIGFILE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zConfigfileText
block|,
name|zConfigfile_NAME
block|,
name|zConfigfile_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|6
block|,
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|6
block|,
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|DEBUG_LEVEL_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zDebug_LevelText
block|,
name|zDebug_Level_NAME
block|,
name|zDebug_Level_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|7
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|7
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|SET_DEBUG_LEVEL_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|SET_DEBUG_LEVEL_OPT_PROC
block|,
comment|/* desc, NAME, name */
name|zSet_Debug_LevelText
block|,
name|zSet_Debug_Level_NAME
block|,
name|zSet_Debug_Level_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|8
block|,
name|VALUE_OPT_DRIFTFILE
block|,
comment|/* equiv idx, value */
literal|8
block|,
name|VALUE_OPT_DRIFTFILE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|DRIFTFILE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zDriftfileText
block|,
name|zDriftfile_NAME
block|,
name|zDriftfile_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|9
block|,
name|VALUE_OPT_PANICGATE
block|,
comment|/* equiv idx, value */
literal|9
block|,
name|VALUE_OPT_PANICGATE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|PANICGATE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zPanicgateText
block|,
name|zPanicgate_NAME
block|,
name|zPanicgate_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|10
block|,
name|VALUE_OPT_JAILDIR
block|,
comment|/* equiv idx, value */
literal|10
block|,
name|VALUE_OPT_JAILDIR
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|JAILDIR_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zJaildirText
block|,
name|zJaildir_NAME
block|,
name|zJaildir_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|11
block|,
name|VALUE_OPT_INTERFACE
block|,
comment|/* equiv idx, value */
literal|11
block|,
name|VALUE_OPT_INTERFACE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|INTERFACE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionStackArg
block|,
comment|/* desc, NAME, name */
name|zInterfaceText
block|,
name|zInterface_NAME
block|,
name|zInterface_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|12
block|,
name|VALUE_OPT_KEYFILE
block|,
comment|/* equiv idx, value */
literal|12
block|,
name|VALUE_OPT_KEYFILE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|KEYFILE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zKeyfileText
block|,
name|zKeyfile_NAME
block|,
name|zKeyfile_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|13
block|,
name|VALUE_OPT_LOGFILE
block|,
comment|/* equiv idx, value */
literal|13
block|,
name|VALUE_OPT_LOGFILE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|LOGFILE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zLogfileText
block|,
name|zLogfile_NAME
block|,
name|zLogfile_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|14
block|,
name|VALUE_OPT_NOVIRTUALIPS
block|,
comment|/* equiv idx, value */
literal|14
block|,
name|VALUE_OPT_NOVIRTUALIPS
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|NOVIRTUALIPS_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zNovirtualipsText
block|,
name|zNovirtualips_NAME
block|,
name|zNovirtualips_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|15
block|,
name|VALUE_OPT_MODIFYMMTIMER
block|,
comment|/* equiv idx, value */
literal|15
block|,
name|VALUE_OPT_MODIFYMMTIMER
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|MODIFYMMTIMER_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zModifymmtimerText
block|,
name|zModifymmtimer_NAME
block|,
name|zModifymmtimer_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|16
block|,
name|VALUE_OPT_NOFORK
block|,
comment|/* equiv idx, value */
literal|16
block|,
name|VALUE_OPT_NOFORK
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|NOFORK_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zNoforkText
block|,
name|zNofork_NAME
block|,
name|zNofork_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|17
block|,
name|VALUE_OPT_NICE
block|,
comment|/* equiv idx, value */
literal|17
block|,
name|VALUE_OPT_NICE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|NICE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zNiceText
block|,
name|zNice_NAME
block|,
name|zNice_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|18
block|,
name|VALUE_OPT_PIDFILE
block|,
comment|/* equiv idx, value */
literal|18
block|,
name|VALUE_OPT_PIDFILE
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|PIDFILE_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zPidfileText
block|,
name|zPidfile_NAME
block|,
name|zPidfile_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|19
block|,
name|VALUE_OPT_PRIORITY
block|,
comment|/* equiv idx, value */
literal|19
block|,
name|VALUE_OPT_PRIORITY
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|PRIORITY_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionNumericVal
block|,
comment|/* desc, NAME, name */
name|zPriorityText
block|,
name|zPriority_NAME
block|,
name|zPriority_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|20
block|,
name|VALUE_OPT_QUIT
block|,
comment|/* equiv idx, value */
literal|20
block|,
name|VALUE_OPT_QUIT
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|QUIT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zQuitText
block|,
name|zQuit_NAME
block|,
name|zQuit_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|21
block|,
name|VALUE_OPT_PROPAGATIONDELAY
block|,
comment|/* equiv idx, value */
literal|21
block|,
name|VALUE_OPT_PROPAGATIONDELAY
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|PROPAGATIONDELAY_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zPropagationdelayText
block|,
name|zPropagationdelay_NAME
block|,
name|zPropagationdelay_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|22
block|,
name|VALUE_OPT_UPDATEINTERVAL
block|,
comment|/* equiv idx, value */
literal|22
block|,
name|VALUE_OPT_UPDATEINTERVAL
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|UPDATEINTERVAL_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionNumericVal
block|,
comment|/* desc, NAME, name */
name|zUpdateintervalText
block|,
name|zUpdateinterval_NAME
block|,
name|zUpdateinterval_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|23
block|,
name|VALUE_OPT_STATSDIR
block|,
comment|/* equiv idx, value */
literal|23
block|,
name|VALUE_OPT_STATSDIR
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|STATSDIR_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zStatsdirText
block|,
name|zStatsdir_NAME
block|,
name|zStatsdir_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|24
block|,
name|VALUE_OPT_TRUSTEDKEY
block|,
comment|/* equiv idx, value */
literal|24
block|,
name|VALUE_OPT_TRUSTEDKEY
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|TRUSTEDKEY_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionStackArg
block|,
comment|/* desc, NAME, name */
name|zTrustedkeyText
block|,
name|zTrustedkey_NAME
block|,
name|zTrustedkey_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|25
block|,
name|VALUE_OPT_USER
block|,
comment|/* equiv idx, value */
literal|25
block|,
name|VALUE_OPT_USER
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|USER_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zUserText
block|,
name|zUser_NAME
block|,
name|zUser_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|26
block|,
name|VALUE_OPT_VAR
block|,
comment|/* equiv idx, value */
literal|26
block|,
name|VALUE_OPT_VAR
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|VAR_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionStackArg
block|,
comment|/* desc, NAME, name */
name|zVarText
block|,
name|zVar_NAME
block|,
name|zVar_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|27
block|,
name|VALUE_OPT_DVAR
block|,
comment|/* equiv idx, value */
literal|27
block|,
name|VALUE_OPT_DVAR
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|DVAR_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionStackArg
block|,
comment|/* desc, NAME, name */
name|zDvarText
block|,
name|zDvar_NAME
block|,
name|zDvar_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|28
block|,
name|VALUE_OPT_SLEW
block|,
comment|/* equiv idx, value */
literal|28
block|,
name|VALUE_OPT_SLEW
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|SLEW_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zSlewText
block|,
name|zSlew_NAME
block|,
name|zSlew_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
ifdef|#
directive|ifdef
name|NO_OPTIONAL_OPT_ARGS
define|#
directive|define
name|VERSION_OPT_FLAGS
value|OPTST_IMM | OPTST_NO_INIT
else|#
directive|else
define|#
directive|define
name|VERSION_OPT_FLAGS
value|OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \                                 OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT
endif|#
directive|endif
block|{
comment|/* entry idx, value */
name|INDEX_OPT_VERSION
block|,
name|VALUE_OPT_VERSION
block|,
comment|/* equiv idx value  */
name|NO_EQUIVALENT
block|,
literal|0
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|VERSION_OPT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|DOVERPROC
block|,
comment|/* desc, NAME, name */
name|zVersionText
block|,
name|NULL
block|,
name|zVersion_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
undef|#
directive|undef
name|VERSION_OPT_FLAGS
block|{
comment|/* entry idx, value */
name|INDEX_OPT_HELP
block|,
name|VALUE_OPT_HELP
block|,
comment|/* equiv idx value  */
name|NO_EQUIVALENT
block|,
literal|0
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|OPTST_IMM
operator||
name|OPTST_NO_INIT
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doUsageOpt
block|,
comment|/* desc, NAME, name */
name|zHelpText
block|,
name|NULL
block|,
name|zHelp_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
name|INDEX_OPT_MORE_HELP
block|,
name|VALUE_OPT_MORE_HELP
block|,
comment|/* equiv idx value  */
name|NO_EQUIVALENT
block|,
literal|0
block|,
comment|/* equivalenced to  */
name|NO_EQUIVALENT
block|,
comment|/* min, max, act ct */
literal|0
block|,
literal|1
block|,
literal|0
block|,
comment|/* opt state flags  */
name|OPTST_IMM
operator||
name|OPTST_NO_INIT
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|optionPagedUsage
block|,
comment|/* desc, NAME, name */
name|zMore_HelpText
block|,
name|NULL
block|,
name|zMore_Help_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpd Option Environment  */
name|tSCC
name|zPROGNAME
index|[]
init|=
literal|"NTPD"
decl_stmt|;
name|tSCC
name|zUsageTitle
index|[]
init|=
literal|"ntpd - NTP daemon program - Ver. 4.2.4p8\n\ USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n"
decl_stmt|;
define|#
directive|define
name|zRcName
value|NULL
define|#
directive|define
name|apzHomeList
value|NULL
name|tSCC
name|zBugsAddr
index|[]
init|=
literal|"http://bugs.ntp.org, bugs@ntp.org"
decl_stmt|;
define|#
directive|define
name|zExplain
value|NULL
name|tSCC
name|zDetail
index|[]
init|=
literal|"\n\n"
decl_stmt|;
name|tSCC
name|zFullVersion
index|[]
init|=
name|NTPD_FULL_VERSION
decl_stmt|;
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optcode.tpl near line 408 */
if|#
directive|if
name|defined
argument_list|(
name|ENABLE_NLS
argument_list|)
define|#
directive|define
name|OPTPROC_BASE
value|OPTPROC_TRANSLATE
specifier|static
name|tOptionXlateProc
name|translate_option_strings
decl_stmt|;
else|#
directive|else
define|#
directive|define
name|OPTPROC_BASE
value|OPTPROC_NONE
define|#
directive|define
name|translate_option_strings
value|NULL
endif|#
directive|endif
comment|/* ENABLE_NLS */
name|tOptions
name|ntpdOptions
init|=
block|{
name|OPTIONS_STRUCT_VERSION
block|,
literal|0
block|,
name|NULL
block|,
comment|/* original argc + argv    */
operator|(
name|OPTPROC_BASE
operator|+
name|OPTPROC_ERRSTOP
operator|+
name|OPTPROC_SHORTOPT
operator|+
name|OPTPROC_LONGOPT
operator|+
name|OPTPROC_NO_REQ_OPT
operator|+
name|OPTPROC_ENVIRON
operator|+
name|OPTPROC_NO_ARGS
operator|)
block|,
literal|0
block|,
name|NULL
block|,
comment|/* current option index, current option */
name|NULL
block|,
name|NULL
block|,
name|zPROGNAME
block|,
name|zRcName
block|,
name|zCopyright
block|,
name|zCopyrightNotice
block|,
name|zFullVersion
block|,
name|apzHomeList
block|,
name|zUsageTitle
block|,
name|zExplain
block|,
name|zDetail
block|,
name|optDesc
block|,
name|zBugsAddr
block|,
comment|/* address to send bugs to */
name|NULL
block|,
name|NULL
block|,
comment|/* extensions/saved state  */
name|optionUsage
block|,
comment|/* usage procedure */
name|translate_option_strings
block|,
comment|/* translation procedure */
comment|/*      *  Indexes to special options      */
block|{
name|INDEX_OPT_MORE_HELP
block|,
literal|0
comment|/* no option state saving */
block|,
name|NO_EQUIVALENT
comment|/* index of '-#' option */
block|,
name|NO_EQUIVALENT
comment|/* index of default opt */
block|}
block|,
literal|32
comment|/* full option count */
block|,
literal|29
comment|/* user option count */
block|}
decl_stmt|;
comment|/*  *  Create the static procedure(s) declared above.  */
specifier|static
name|void
name|doUsageOpt
parameter_list|(
name|tOptions
modifier|*
name|pOptions
parameter_list|,
name|tOptDesc
modifier|*
name|pOptDesc
parameter_list|)
block|{
name|USAGE
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TEST_NTPD_OPTS
argument_list|)
comment|/* * * * * * *  *  *   For the set-debug-level option, when DEBUG is #define-d.  */
ifdef|#
directive|ifdef
name|DEBUG
specifier|static
name|void
name|doOptSet_Debug_Level
parameter_list|(
name|tOptions
modifier|*
name|pOptions
parameter_list|,
name|tOptDesc
modifier|*
name|pOptDesc
parameter_list|)
block|{
comment|/* extracted from ../include/debug-opt.def, line 29 */
name|DESC
argument_list|(
name|DEBUG_LEVEL
argument_list|)
operator|.
name|optOccCt
operator|=
name|atoi
argument_list|(
name|pOptDesc
operator|->
name|pzLastArg
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* defined DEBUG */
endif|#
directive|endif
comment|/* defined(TEST_NTPD_OPTS) */
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optmain.tpl near line 92 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTPD_OPTS
argument_list|)
comment|/* TEST MAIN PROCEDURE: */
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|res
init|=
name|EXIT_SUCCESS
decl_stmt|;
operator|(
name|void
operator|)
name|optionProcess
argument_list|(
operator|&
name|ntpdOptions
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
block|{
name|void
name|optionPutShell
argument_list|(
name|tOptions
operator|*
argument_list|)
decl_stmt|;
name|optionPutShell
argument_list|(
operator|&
name|ntpdOptions
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* defined TEST_NTPD_OPTS */
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optcode.tpl near line 514 */
if|#
directive|if
name|ENABLE_NLS
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<string.h>
include|#
directive|include
file|<unistd.h>
include|#
directive|include
file|<autoopts/usage-txt.h>
specifier|static
name|char
modifier|*
name|AO_gettext
parameter_list|(
name|char
specifier|const
modifier|*
name|pz
parameter_list|)
function_decl|;
specifier|static
name|void
name|coerce_it
parameter_list|(
name|void
modifier|*
modifier|*
name|s
parameter_list|)
function_decl|;
specifier|static
name|char
modifier|*
name|AO_gettext
parameter_list|(
name|char
specifier|const
modifier|*
name|pz
parameter_list|)
block|{
name|char
modifier|*
name|pzRes
decl_stmt|;
if|if
condition|(
name|pz
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|pzRes
operator|=
name|_
argument_list|(
name|pz
argument_list|)
expr_stmt|;
if|if
condition|(
name|pzRes
operator|==
name|pz
condition|)
return|return
name|pzRes
return|;
name|pzRes
operator|=
name|strdup
argument_list|(
name|pzRes
argument_list|)
expr_stmt|;
if|if
condition|(
name|pzRes
operator|==
name|NULL
condition|)
block|{
name|fputs
argument_list|(
name|_
argument_list|(
literal|"No memory for duping translated strings\n"
argument_list|)
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
return|return
name|pzRes
return|;
block|}
specifier|static
name|void
name|coerce_it
parameter_list|(
name|void
modifier|*
modifier|*
name|s
parameter_list|)
block|{
operator|*
name|s
operator|=
name|AO_gettext
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
block|}
define|#
directive|define
name|COERSION
parameter_list|(
name|_f
parameter_list|)
define|\
value|coerce_it((void*)&(ntpdOptions._f))
comment|/*  *  This invokes the translation code (e.g. gettext(3)).  */
specifier|static
name|void
name|translate_option_strings
parameter_list|(
name|void
parameter_list|)
block|{
comment|/*      *  Guard against re-translation.  It won't work.  The strings will have      *  been changed by the first pass through this code.  One shot only.      */
if|if
condition|(
name|option_usage_text
operator|.
name|field_ct
operator|==
literal|0
condition|)
return|return;
comment|/*      *  Do the translations.  The first pointer follows the field count field.      *  The field count field is the size of a pointer.      */
block|{
name|char
modifier|*
modifier|*
name|ppz
init|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|option_usage_text
operator|)
decl_stmt|;
name|int
name|ix
init|=
name|option_usage_text
operator|.
name|field_ct
decl_stmt|;
do|do
block|{
name|ppz
operator|++
expr_stmt|;
operator|*
name|ppz
operator|=
name|AO_gettext
argument_list|(
operator|*
name|ppz
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|ix
operator|>
literal|0
condition|)
do|;
block|}
name|option_usage_text
operator|.
name|field_ct
operator|=
literal|0
expr_stmt|;
block|{
name|tOptDesc
modifier|*
name|pOD
init|=
name|ntpdOptions
operator|.
name|pOptDesc
decl_stmt|;
name|int
name|ix
init|=
name|ntpdOptions
operator|.
name|optCt
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|pOD
operator|->
name|pzText
operator|=
name|AO_gettext
argument_list|(
name|pOD
operator|->
name|pzText
argument_list|)
expr_stmt|;
name|pOD
operator|->
name|pz_NAME
operator|=
name|AO_gettext
argument_list|(
name|pOD
operator|->
name|pz_NAME
argument_list|)
expr_stmt|;
name|pOD
operator|->
name|pz_Name
operator|=
name|AO_gettext
argument_list|(
name|pOD
operator|->
name|pz_Name
argument_list|)
expr_stmt|;
name|pOD
operator|->
name|pz_DisableName
operator|=
name|AO_gettext
argument_list|(
name|pOD
operator|->
name|pz_DisableName
argument_list|)
expr_stmt|;
name|pOD
operator|->
name|pz_DisablePfx
operator|=
name|AO_gettext
argument_list|(
name|pOD
operator|->
name|pz_DisablePfx
argument_list|)
expr_stmt|;
if|if
condition|(
operator|--
name|ix
operator|<=
literal|0
condition|)
break|break;
name|pOD
operator|++
expr_stmt|;
block|}
block|}
name|COERSION
argument_list|(
name|pzCopyright
argument_list|)
expr_stmt|;
name|COERSION
argument_list|(
name|pzCopyNotice
argument_list|)
expr_stmt|;
name|COERSION
argument_list|(
name|pzFullVersion
argument_list|)
expr_stmt|;
name|COERSION
argument_list|(
name|pzUsageTitle
argument_list|)
expr_stmt|;
name|COERSION
argument_list|(
name|pzExplain
argument_list|)
expr_stmt|;
name|COERSION
argument_list|(
name|pzDetail
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ENABLE_NLS */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ntpd-opts.c ends here */
end_comment

end_unit

