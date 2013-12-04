begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntpdc-opts.c)  *    *  It has been AutoGen-ed  December 24, 2011 at 06:34:16 PM by AutoGen 5.12  *  From the definitions    ntpdc-opts.def  *  and the template file   options  *  * Generated from AutoOpts 35:0:10 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntpdc author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * This source file is copyrighted and licensed under the following terms:  *  *  see html/copyright.html  *    */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
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
file|"ntpdc-opts.h"
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
specifier|extern
name|FILE
modifier|*
name|option_usage_fp
decl_stmt|;
comment|/* TRANSLATORS: choose the translation for option names wisely because you                 cannot ever change your mind. */
specifier|static
name|char
specifier|const
name|zCopyright
index|[
literal|39
index|]
init|=
literal|"ntpdc 4.2.6p5\n\ see html/copyright.html\n"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zLicenseDescrip
index|[
literal|25
index|]
init|=
literal|"see html/copyright.html\n"
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
comment|/*  *  Ipv4 option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zIpv4Text
index|[]
init|=
literal|"Force IPv4 DNS name resolution"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zIpv4_NAME
index|[]
init|=
literal|"IPV4"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zIpv4_Name
index|[]
init|=
literal|"ipv4"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aIpv4CantList
index|[]
init|=
block|{
name|INDEX_OPT_IPV6
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|IPV4_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Ipv6 option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zIpv6Text
index|[]
init|=
literal|"Force IPv6 DNS name resolution"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zIpv6_NAME
index|[]
init|=
literal|"IPV6"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zIpv6_Name
index|[]
init|=
literal|"ipv6"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aIpv6CantList
index|[]
init|=
block|{
name|INDEX_OPT_IPV4
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|IPV6_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Command option description:  */
specifier|static
name|char
specifier|const
name|zCommandText
index|[]
init|=
literal|"run a command and exit"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zCommand_NAME
index|[]
init|=
literal|"COMMAND"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zCommand_Name
index|[]
init|=
literal|"command"
decl_stmt|;
define|#
directive|define
name|COMMAND_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Listpeers option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zListpeersText
index|[]
init|=
literal|"Print a list of the peers"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zListpeers_NAME
index|[]
init|=
literal|"LISTPEERS"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zListpeers_Name
index|[]
init|=
literal|"listpeers"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aListpeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|LISTPEERS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Peers option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zPeersText
index|[]
init|=
literal|"Print a list of the peers"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zPeers_NAME
index|[]
init|=
literal|"PEERS"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zPeers_Name
index|[]
init|=
literal|"peers"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aPeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|PEERS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Showpeers option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zShowpeersText
index|[]
init|=
literal|"Show a list of the peers"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zShowpeers_NAME
index|[]
init|=
literal|"SHOWPEERS"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zShowpeers_Name
index|[]
init|=
literal|"showpeers"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aShowpeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|SHOWPEERS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Interactive option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zInteractiveText
index|[]
init|=
literal|"Force ntpq to operate in interactive mode"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zInteractive_NAME
index|[]
init|=
literal|"INTERACTIVE"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zInteractive_Name
index|[]
init|=
literal|"interactive"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aInteractiveCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|INDEX_OPT_LISTPEERS
block|,
name|INDEX_OPT_PEERS
block|,
name|INDEX_OPT_SHOWPEERS
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|INTERACTIVE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Debug_Level option description:  */
specifier|static
name|char
specifier|const
name|zDebug_LevelText
index|[]
init|=
literal|"Increase output debug message level"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zDebug_Level_NAME
index|[]
init|=
literal|"DEBUG_LEVEL"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zDebug_Level_Name
index|[]
init|=
literal|"debug-level"
decl_stmt|;
define|#
directive|define
name|DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Set_Debug_Level option description:  */
specifier|static
name|char
specifier|const
name|zSet_Debug_LevelText
index|[]
init|=
literal|"Set the output debug message level"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSet_Debug_Level_NAME
index|[]
init|=
literal|"SET_DEBUG_LEVEL"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSet_Debug_Level_Name
index|[]
init|=
literal|"set-debug-level"
decl_stmt|;
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Numeric option description:  */
specifier|static
name|char
specifier|const
name|zNumericText
index|[]
init|=
literal|"numeric host addresses"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNumeric_NAME
index|[]
init|=
literal|"NUMERIC"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNumeric_Name
index|[]
init|=
literal|"numeric"
decl_stmt|;
define|#
directive|define
name|NUMERIC_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Help/More_Help/Version option descriptions:  */
specifier|static
name|char
specifier|const
name|zHelpText
index|[]
init|=
literal|"Display extended usage information and exit"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zHelp_Name
index|[]
init|=
literal|"help"
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
define|#
directive|define
name|OPTST_MORE_HELP_FLAGS
value|(OPTST_IMM | OPTST_NO_INIT)
specifier|static
name|char
specifier|const
name|zMore_Help_Name
index|[]
init|=
literal|"more-help"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zMore_HelpText
index|[]
init|=
literal|"Extended usage information passed thru pager"
decl_stmt|;
else|#
directive|else
define|#
directive|define
name|OPTST_MORE_HELP_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zMore_Help_Name
value|NULL
define|#
directive|define
name|zMore_HelpText
value|NULL
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NO_OPTIONAL_OPT_ARGS
define|#
directive|define
name|OPTST_VERSION_FLAGS
value|OPTST_IMM | OPTST_NO_INIT
else|#
directive|else
define|#
directive|define
name|OPTST_VERSION_FLAGS
value|OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \                                 OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT
endif|#
directive|endif
specifier|static
name|char
specifier|const
name|zVersionText
index|[]
init|=
literal|"Output version information and exit"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zVersion_Name
index|[]
init|=
literal|"version"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSave_OptsText
index|[]
init|=
literal|"Save the option state to a config file"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSave_Opts_Name
index|[]
init|=
literal|"save-opts"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zLoad_OptsText
index|[]
init|=
literal|"Load options from a config file"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zLoad_Opts_NAME
index|[]
init|=
literal|"LOAD_OPTS"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNotLoad_Opts_Name
index|[]
init|=
literal|"no-load-opts"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNotLoad_Opts_Pfx
index|[]
init|=
literal|"no"
decl_stmt|;
define|#
directive|define
name|zLoad_Opts_Name
value|(zNotLoad_Opts_Name + 3)
comment|/*  *  Declare option callback procedures  */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTPDC_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
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
comment|/* NOT defined TEST_NTPDC_OPTS */
comment|/*  *  When not under test, there are different procs to use  */
specifier|extern
name|tOptProc
name|optionBooleanVal
decl_stmt|,
name|optionNestedVal
decl_stmt|,
name|optionNumericVal
decl_stmt|,
name|optionPagedUsage
decl_stmt|,
name|optionPrintVersion
decl_stmt|,
name|optionResetOpt
decl_stmt|,
name|optionStackArg
decl_stmt|,
name|optionTimeDate
decl_stmt|,
name|optionTimeVal
decl_stmt|,
name|optionUnstackArg
decl_stmt|,
name|optionVersionStderr
decl_stmt|;
specifier|static
name|tOptProc
name|doOptSet_Debug_Level
decl_stmt|,
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
comment|/* defined(TEST_NTPDC_OPTS) */
ifdef|#
directive|ifdef
name|TEST_NTPDC_OPTS
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
comment|/* TEST_NTPDC_OPTS */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpdc Option Descriptions.  */
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
literal|0
block|,
name|VALUE_OPT_IPV4
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
name|aIpv4CantList
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
literal|1
block|,
name|VALUE_OPT_IPV6
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
name|aIpv6CantList
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
name|VALUE_OPT_COMMAND
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_COMMAND
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
name|COMMAND_FLAGS
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
name|zCommandText
block|,
name|zCommand_NAME
block|,
name|zCommand_Name
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
name|VALUE_OPT_LISTPEERS
block|,
comment|/* equiv idx, value */
literal|3
block|,
name|VALUE_OPT_LISTPEERS
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
name|LISTPEERS_FLAGS
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
name|aListpeersCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zListpeersText
block|,
name|zListpeers_NAME
block|,
name|zListpeers_Name
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
name|VALUE_OPT_PEERS
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_PEERS
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
name|PEERS_FLAGS
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
name|aPeersCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zPeersText
block|,
name|zPeers_NAME
block|,
name|zPeers_Name
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
name|VALUE_OPT_SHOWPEERS
block|,
comment|/* equiv idx, value */
literal|5
block|,
name|VALUE_OPT_SHOWPEERS
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
name|SHOWPEERS_FLAGS
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
name|aShowpeersCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zShowpeersText
block|,
name|zShowpeers_NAME
block|,
name|zShowpeers_Name
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
name|VALUE_OPT_INTERACTIVE
block|,
comment|/* equiv idx, value */
literal|6
block|,
name|VALUE_OPT_INTERACTIVE
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
name|INTERACTIVE_FLAGS
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
name|aInteractiveCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zInteractiveText
block|,
name|zInteractive_NAME
block|,
name|zInteractive_Name
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
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|7
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
literal|8
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|8
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
literal|9
block|,
name|VALUE_OPT_NUMERIC
block|,
comment|/* equiv idx, value */
literal|9
block|,
name|VALUE_OPT_NUMERIC
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
name|NUMERIC_FLAGS
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
name|zNumericText
block|,
name|zNumeric_NAME
block|,
name|zNumeric_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
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
name|OPTST_VERSION_FLAGS
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
name|OPTST_MORE_HELP_FLAGS
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
block|,
block|{
comment|/* entry idx, value */
name|INDEX_OPT_SAVE_OPTS
block|,
name|VALUE_OPT_SAVE_OPTS
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
name|OPTST_SET_ARGTYPE
argument_list|(
name|OPARG_TYPE_STRING
argument_list|)
operator||
name|OPTST_ARG_OPTIONAL
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
name|NULL
block|,
comment|/* desc, NAME, name */
name|zSave_OptsText
block|,
name|NULL
block|,
name|zSave_Opts_Name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
name|INDEX_OPT_LOAD_OPTS
block|,
name|VALUE_OPT_LOAD_OPTS
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
name|NOLIMIT
block|,
literal|0
block|,
comment|/* opt state flags  */
name|OPTST_SET_ARGTYPE
argument_list|(
name|OPARG_TYPE_STRING
argument_list|)
operator||
name|OPTST_DISABLE_IMM
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
name|optionLoadOpt
block|,
comment|/* desc, NAME, name */
name|zLoad_OptsText
block|,
name|zLoad_Opts_NAME
block|,
name|zLoad_Opts_Name
block|,
comment|/* disablement strs */
name|zNotLoad_Opts_Name
block|,
name|zNotLoad_Opts_Pfx
block|}
block|}
decl_stmt|;
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpdc Option Environment  */
specifier|static
name|char
specifier|const
name|zPROGNAME
index|[
literal|6
index|]
init|=
literal|"NTPDC"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zUsageTitle
index|[
literal|127
index|]
init|=
literal|"ntpdc - vendor-specific NTP query program - Ver. 4.2.6p5\n\ USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [ host ...]\n"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zRcName
index|[
literal|7
index|]
init|=
literal|".ntprc"
decl_stmt|;
specifier|static
name|char
specifier|const
modifier|*
specifier|const
name|apzHomeList
index|[
literal|3
index|]
init|=
block|{
literal|"$HOME"
block|,
literal|"."
block|,
name|NULL
block|}
decl_stmt|;
specifier|static
name|char
specifier|const
name|zBugsAddr
index|[
literal|34
index|]
init|=
literal|"http://bugs.ntp.org, bugs@ntp.org"
decl_stmt|;
define|#
directive|define
name|zExplain
value|NULL
specifier|static
name|char
specifier|const
name|zDetail
index|[
literal|601
index|]
init|=
literal|"\n\ The [= prog-name =] utility program is used to query an NTP daemon about\n\ its current state and to request changes in that state.  It uses NTP mode\n\ 7 control message formats described in the source code.  The program may\n\ be run either in interactive mode or controlled using command line\n\ arguments.  Extensive state and statistics information is available\n\ through the [= prog-name =] interface.  In addition, nearly all the\n\ configuration options which can be specified at startup using ntpd's\n\ configuration file may also be specified at run time using [= prog-name =]\n\ .\n"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zFullVersion
index|[]
init|=
name|NTPDC_FULL_VERSION
decl_stmt|;
comment|/* extracted from optcode.tlib near line 515 */
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
define|#
directive|define
name|ntpdc_full_usage
value|NULL
define|#
directive|define
name|ntpdc_short_usage
value|NULL
ifndef|#
directive|ifndef
name|PKGDATADIR
define|#
directive|define
name|PKGDATADIR
value|""
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WITH_PACKAGER
define|#
directive|define
name|ntpdc_packager_info
value|NULL
else|#
directive|else
specifier|static
name|char
specifier|const
name|ntpdc_packager_info
index|[]
init|=
literal|"Packaged by "
name|WITH_PACKAGER
ifdef|#
directive|ifdef
name|WITH_PACKAGER_VERSION
literal|" ("
name|WITH_PACKAGER_VERSION
literal|")"
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_PACKAGER_BUG_REPORTS
literal|"\nReport ntpdc bugs to "
name|WITH_PACKAGER_BUG_REPORTS
endif|#
directive|endif
literal|"\n"
decl_stmt|;
endif|#
directive|endif
name|tOptions
name|ntpdcOptions
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
name|OPTPROC_MISUSE
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
name|zLicenseDescrip
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
comment|/* more-help option index */
name|INDEX_OPT_SAVE_OPTS
block|,
comment|/* save option index */
name|NO_EQUIVALENT
block|,
comment|/* '-#' option index */
name|NO_EQUIVALENT
comment|/* index of default opt */
block|}
block|,
literal|15
comment|/* full option count */
block|,
literal|10
comment|/* user option count */
block|,
name|ntpdc_full_usage
block|,
name|ntpdc_short_usage
block|,
name|NULL
block|,
name|NULL
block|,
name|PKGDATADIR
block|,
name|ntpdc_packager_info
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
operator|(
name|void
operator|)
name|pOptions
expr_stmt|;
name|USAGE
argument_list|(
name|NTPDC_EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TEST_NTPDC_OPTS
argument_list|)
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *   For the set-debug-level option.  */
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
comment|/* extracted from debug-opt.def, line 27 */
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
comment|/* defined(TEST_NTPDC_OPTS) */
comment|/* extracted from optmain.tlib near line 128 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTPDC_OPTS
argument_list|)
comment|/* TEST MAIN PROCEDURE: */
specifier|extern
name|void
name|optionPutShell
parameter_list|(
name|tOptions
modifier|*
parameter_list|)
function_decl|;
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
name|NTPDC_EXIT_SUCCESS
decl_stmt|;
operator|(
name|void
operator|)
name|optionProcess
argument_list|(
operator|&
name|ntpdcOptions
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|optionPutShell
argument_list|(
operator|&
name|ntpdcOptions
argument_list|)
expr_stmt|;
name|res
operator|=
name|ferror
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|!=
literal|0
condition|)
name|fputs
argument_list|(
literal|"output error writing to stdout\n"
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* defined TEST_NTPDC_OPTS */
comment|/* extracted from optcode.tlib near line 666 */
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
name|NTPDC_EXIT_FAILURE
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
comment|/*  *  This invokes the translation code (e.g. gettext(3)).  */
specifier|static
name|void
name|translate_option_strings
parameter_list|(
name|void
parameter_list|)
block|{
name|tOptions
modifier|*
specifier|const
name|pOpt
init|=
operator|&
name|ntpdcOptions
decl_stmt|;
comment|/*      *  Guard against re-translation.  It won't work.  The strings will have      *  been changed by the first pass through this code.  One shot only.      */
if|if
condition|(
name|option_usage_text
operator|.
name|field_ct
operator|!=
literal|0
condition|)
block|{
comment|/*          *  Do the translations.  The first pointer follows the field count          *  field.  The field count field is the size of a pointer.          */
name|tOptDesc
modifier|*
name|pOD
init|=
name|pOpt
operator|->
name|pOptDesc
decl_stmt|;
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
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzCopyright
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzCopyNotice
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzFullVersion
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzUsageTitle
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzExplain
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzDetail
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOpt
operator|->
name|pzPackager
operator|)
argument_list|)
expr_stmt|;
name|option_usage_text
operator|.
name|field_ct
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|ix
operator|=
name|pOpt
operator|->
name|optCt
init|;
name|ix
operator|>
literal|0
condition|;
name|ix
operator|--
operator|,
name|pOD
operator|++
control|)
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOD
operator|->
name|pzText
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|pOpt
operator|->
name|fOptSet
operator|&
name|OPTPROC_NXLAT_OPT_CFG
operator|)
operator|==
literal|0
condition|)
block|{
name|tOptDesc
modifier|*
name|pOD
init|=
name|pOpt
operator|->
name|pOptDesc
decl_stmt|;
name|int
name|ix
decl_stmt|;
for|for
control|(
name|ix
operator|=
name|pOpt
operator|->
name|optCt
init|;
name|ix
operator|>
literal|0
condition|;
name|ix
operator|--
operator|,
name|pOD
operator|++
control|)
block|{
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOD
operator|->
name|pz_Name
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOD
operator|->
name|pz_DisableName
operator|)
argument_list|)
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|pOD
operator|->
name|pz_DisablePfx
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* prevent re-translation */
name|ntpdcOptions
operator|.
name|fOptSet
operator||=
name|OPTPROC_NXLAT_OPT_CFG
operator||
name|OPTPROC_NXLAT_OPT
expr_stmt|;
block|}
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
comment|/* ntpdc-opts.c ends here */
end_comment

end_unit

