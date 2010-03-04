begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntpq-opts.c)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:26 AM EST  *  From the definitions    ntpq-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This source file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntpq author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntpq copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
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
file|"ntpq-opts.h"
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
literal|"ntpq copyright (c) 1970-2009 David L. Mills and/or others, all rights reserved"
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
comment|/*  *  Command option description:  */
name|tSCC
name|zCommandText
index|[]
init|=
literal|"run a command and exit"
decl_stmt|;
name|tSCC
name|zCommand_NAME
index|[]
init|=
literal|"COMMAND"
decl_stmt|;
name|tSCC
name|zCommand_Name
index|[]
init|=
literal|"command"
decl_stmt|;
define|#
directive|define
name|COMMAND_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
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
comment|/*  *  Peers option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zPeersText
index|[]
init|=
literal|"Print a list of the peers"
decl_stmt|;
name|tSCC
name|zPeers_NAME
index|[]
init|=
literal|"PEERS"
decl_stmt|;
name|tSCC
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
name|INDEX_OPT_INTERACTIVE
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|PEERS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Interactive option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zInteractiveText
index|[]
init|=
literal|"Force ntpq to operate in interactive mode"
decl_stmt|;
name|tSCC
name|zInteractive_NAME
index|[]
init|=
literal|"INTERACTIVE"
decl_stmt|;
name|tSCC
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
name|INDEX_OPT_PEERS
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|INTERACTIVE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Numeric option description:  */
name|tSCC
name|zNumericText
index|[]
init|=
literal|"numeric host addresses"
decl_stmt|;
name|tSCC
name|zNumeric_NAME
index|[]
init|=
literal|"NUMERIC"
decl_stmt|;
name|tSCC
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
comment|/*  *  Save/Load_Opts option description:  */
name|tSCC
name|zSave_OptsText
index|[]
init|=
literal|"Save the option state to a config file"
decl_stmt|;
name|tSCC
name|zSave_Opts_Name
index|[]
init|=
literal|"save-opts"
decl_stmt|;
name|tSCC
name|zLoad_OptsText
index|[]
init|=
literal|"Load options from a config file"
decl_stmt|;
name|tSCC
name|zLoad_Opts_NAME
index|[]
init|=
literal|"LOAD_OPTS"
decl_stmt|;
name|tSCC
name|zNotLoad_Opts_Name
index|[]
init|=
literal|"no-load-opts"
decl_stmt|;
name|tSCC
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
name|TEST_NTPQ_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
specifier|extern
name|tOptProc
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
comment|/* NOT defined TEST_NTPQ_OPTS */
comment|/*  *  When not under test, there are different procs to use  */
specifier|extern
name|tOptProc
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
comment|/* defined(TEST_NTPQ_OPTS) */
ifdef|#
directive|ifdef
name|TEST_NTPQ_OPTS
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
comment|/* TEST_NTPQ_OPTS */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpq Option Descriptions.  */
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
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|3
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
literal|4
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|4
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
literal|5
block|,
name|VALUE_OPT_PEERS
block|,
comment|/* equiv idx, value */
literal|5
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
name|VALUE_OPT_NUMERIC
block|,
comment|/* equiv idx, value */
literal|7
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
expr|\
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
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntpq Option Environment  */
name|tSCC
name|zPROGNAME
index|[]
init|=
literal|"NTPQ"
decl_stmt|;
name|tSCC
name|zUsageTitle
index|[]
init|=
literal|"ntpq - standard NTP query program - Ver. 4.2.4p8\n\ USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [ host ...]\n"
decl_stmt|;
name|tSCC
name|zRcName
index|[]
init|=
literal|".ntprc"
decl_stmt|;
name|tSCC
modifier|*
name|apzHomeList
index|[]
init|=
block|{
literal|"$HOME"
block|,
literal|"."
block|,
name|NULL
block|}
decl_stmt|;
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
literal|"\n\ The\n\ [= prog-name =]\n\ utility program is used to query NTP servers which\n\ implement the standard NTP mode 6 control message formats defined\n\ in Appendix B of the NTPv3 specification RFC1305, requesting\n\ information about current state and/or changes in that state.\n\ The same formats are used in NTPv4, although some of the\n\ variables have changed and new ones added.\n"
decl_stmt|;
name|tSCC
name|zFullVersion
index|[]
init|=
name|NTPQ_FULL_VERSION
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
name|ntpqOptions
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
name|OPTPROC_HAS_IMMED
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
name|INDEX_OPT_SAVE_OPTS
block|,
name|NO_EQUIVALENT
comment|/* index of '-#' option */
block|,
name|NO_EQUIVALENT
comment|/* index of default opt */
block|}
block|,
literal|13
comment|/* full option count */
block|,
literal|8
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
name|TEST_NTPQ_OPTS
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
comment|/* defined(TEST_NTPQ_OPTS) */
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optmain.tpl near line 92 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTPQ_OPTS
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
name|ntpqOptions
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
name|ntpqOptions
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* defined TEST_NTPQ_OPTS */
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
value|coerce_it((void*)&(ntpqOptions._f))
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
name|ntpqOptions
operator|.
name|pOptDesc
decl_stmt|;
name|int
name|ix
init|=
name|ntpqOptions
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
comment|/* ntpq-opts.c ends here */
end_comment

end_unit

