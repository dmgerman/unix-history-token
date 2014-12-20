begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (ntpdc-opts.c)  *  *  It has been AutoGen-ed  December 19, 2014 at 07:49:26 AM by AutoGen 5.18.5pre4  *  From the definitions    ntpdc-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntpdc author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The ntpdc program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1970-2014 The University of Delaware, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__doxygen__
end_ifndef

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
define|#
directive|define
name|zCopyright
value|(ntpdc_opt_strs+0)
define|#
directive|define
name|zLicenseDescrip
value|(ntpdc_opt_strs+311)
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
comment|/**  *  static const strings for ntpdc options  */
specifier|static
name|char
specifier|const
name|ntpdc_opt_strs
index|[
literal|1849
index|]
init|=
comment|/*     0 */
literal|"ntpdc 4.2.8\n"
literal|"Copyright (C) 1970-2014 The University of Delaware, all rights reserved.\n"
literal|"This is free software. It is licensed for use, modification and\n"
literal|"redistribution under the terms of the NTP License, copies of which\n"
literal|"can be seen at:\n"
literal|"<http://ntp.org/license>\n"
literal|"<http://opensource.org/licenses/ntp-license.php>\n\0"
comment|/*   311 */
literal|"Permission to use, copy, modify, and distribute this software and its\n"
literal|"documentation for any purpose with or without fee is hereby granted,\n"
literal|"provided that the above copyright notice appears in all copies and that\n"
literal|"both the copyright notice and this permission notice appear in supporting\n"
literal|"documentation, and that the name The University of Delaware not be used in\n"
literal|"advertising or publicity pertaining to distribution of the software without\n"
literal|"specific, written prior permission.  The University of Delaware makes no\n"
literal|"representations about the suitability this software for any purpose.  It is\n"
literal|"provided \"as is\" without express or implied warranty.\n\0"
comment|/*   951 */
literal|"Force IPv4 DNS name resolution\0"
comment|/*   982 */
literal|"IPV4\0"
comment|/*   987 */
literal|"ipv4\0"
comment|/*   992 */
literal|"Force IPv6 DNS name resolution\0"
comment|/*  1023 */
literal|"IPV6\0"
comment|/*  1028 */
literal|"ipv6\0"
comment|/*  1033 */
literal|"run a command and exit\0"
comment|/*  1056 */
literal|"COMMAND\0"
comment|/*  1064 */
literal|"command\0"
comment|/*  1072 */
literal|"Increase debug verbosity level\0"
comment|/*  1103 */
literal|"DEBUG_LEVEL\0"
comment|/*  1115 */
literal|"debug-level\0"
comment|/*  1127 */
literal|"Set the debug verbosity level\0"
comment|/*  1157 */
literal|"SET_DEBUG_LEVEL\0"
comment|/*  1173 */
literal|"set-debug-level\0"
comment|/*  1189 */
literal|"Force ntpq to operate in interactive mode\0"
comment|/*  1231 */
literal|"INTERACTIVE\0"
comment|/*  1243 */
literal|"interactive\0"
comment|/*  1255 */
literal|"Print a list of the peers\0"
comment|/*  1281 */
literal|"LISTPEERS\0"
comment|/*  1291 */
literal|"listpeers\0"
comment|/*  1301 */
literal|"numeric host addresses\0"
comment|/*  1324 */
literal|"NUMERIC\0"
comment|/*  1332 */
literal|"numeric\0"
comment|/*  1340 */
literal|"PEERS\0"
comment|/*  1346 */
literal|"peers\0"
comment|/*  1352 */
literal|"Show a list of the peers\0"
comment|/*  1377 */
literal|"SHOWPEERS\0"
comment|/*  1387 */
literal|"showpeers\0"
comment|/*  1397 */
literal|"display extended usage information and exit\0"
comment|/*  1441 */
literal|"help\0"
comment|/*  1446 */
literal|"extended usage information passed thru pager\0"
comment|/*  1491 */
literal|"more-help\0"
comment|/*  1501 */
literal|"output version information and exit\0"
comment|/*  1537 */
literal|"version\0"
comment|/*  1545 */
literal|"save the option state to a config file\0"
comment|/*  1584 */
literal|"save-opts\0"
comment|/*  1594 */
literal|"load options from a config file\0"
comment|/*  1626 */
literal|"LOAD_OPTS\0"
comment|/*  1636 */
literal|"no-load-opts\0"
comment|/*  1649 */
literal|"no\0"
comment|/*  1652 */
literal|"NTPDC\0"
comment|/*  1658 */
literal|"ntpdc - vendor-specific NTPD control program - Ver. 4.2.8\n"
literal|"Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [ host ...]\n\0"
comment|/*  1786 */
literal|"$HOME\0"
comment|/*  1792 */
literal|".\0"
comment|/*  1794 */
literal|".ntprc\0"
comment|/*  1801 */
literal|"http://bugs.ntp.org, bugs@ntp.org\0"
comment|/*  1835 */
literal|"\n\0"
comment|/*  1837 */
literal|"ntpdc 4.2.8"
decl_stmt|;
comment|/**  *  ipv4 option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the ipv4 option */
define|#
directive|define
name|IPV4_DESC
value|(ntpdc_opt_strs+951)
comment|/** Upper-cased name for the ipv4 option */
define|#
directive|define
name|IPV4_NAME
value|(ntpdc_opt_strs+982)
comment|/** Name string for the ipv4 option */
define|#
directive|define
name|IPV4_name
value|(ntpdc_opt_strs+987)
comment|/** Other options that appear in conjunction with the ipv4 option */
specifier|static
name|int
specifier|const
name|aIpv4CantList
index|[]
init|=
block|{
name|INDEX_OPT_IPV6
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the ipv4 option */
define|#
directive|define
name|IPV4_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  ipv6 option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the ipv6 option */
define|#
directive|define
name|IPV6_DESC
value|(ntpdc_opt_strs+992)
comment|/** Upper-cased name for the ipv6 option */
define|#
directive|define
name|IPV6_NAME
value|(ntpdc_opt_strs+1023)
comment|/** Name string for the ipv6 option */
define|#
directive|define
name|IPV6_name
value|(ntpdc_opt_strs+1028)
comment|/** Other options that appear in conjunction with the ipv6 option */
specifier|static
name|int
specifier|const
name|aIpv6CantList
index|[]
init|=
block|{
name|INDEX_OPT_IPV4
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the ipv6 option */
define|#
directive|define
name|IPV6_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  command option description:  */
comment|/** Descriptive text for the command option */
define|#
directive|define
name|COMMAND_DESC
value|(ntpdc_opt_strs+1033)
comment|/** Upper-cased name for the command option */
define|#
directive|define
name|COMMAND_NAME
value|(ntpdc_opt_strs+1056)
comment|/** Name string for the command option */
define|#
directive|define
name|COMMAND_name
value|(ntpdc_opt_strs+1064)
comment|/** Compiled in flag settings for the command option */
define|#
directive|define
name|COMMAND_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  debug-level option description:  */
comment|/** Descriptive text for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_DESC
value|(ntpdc_opt_strs+1072)
comment|/** Upper-cased name for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_NAME
value|(ntpdc_opt_strs+1103)
comment|/** Name string for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_name
value|(ntpdc_opt_strs+1115)
comment|/** Compiled in flag settings for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  set-debug-level option description:  */
comment|/** Descriptive text for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_DESC
value|(ntpdc_opt_strs+1127)
comment|/** Upper-cased name for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_NAME
value|(ntpdc_opt_strs+1157)
comment|/** Name string for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_name
value|(ntpdc_opt_strs+1173)
comment|/** Compiled in flag settings for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  interactive option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the interactive option */
define|#
directive|define
name|INTERACTIVE_DESC
value|(ntpdc_opt_strs+1189)
comment|/** Upper-cased name for the interactive option */
define|#
directive|define
name|INTERACTIVE_NAME
value|(ntpdc_opt_strs+1231)
comment|/** Name string for the interactive option */
define|#
directive|define
name|INTERACTIVE_name
value|(ntpdc_opt_strs+1243)
comment|/** Other options that appear in conjunction with the interactive option */
specifier|static
name|int
specifier|const
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
comment|/** Compiled in flag settings for the interactive option */
define|#
directive|define
name|INTERACTIVE_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  listpeers option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the listpeers option */
define|#
directive|define
name|LISTPEERS_DESC
value|(ntpdc_opt_strs+1255)
comment|/** Upper-cased name for the listpeers option */
define|#
directive|define
name|LISTPEERS_NAME
value|(ntpdc_opt_strs+1281)
comment|/** Name string for the listpeers option */
define|#
directive|define
name|LISTPEERS_name
value|(ntpdc_opt_strs+1291)
comment|/** Other options that appear in conjunction with the listpeers option */
specifier|static
name|int
specifier|const
name|aListpeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the listpeers option */
define|#
directive|define
name|LISTPEERS_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  numeric option description:  */
comment|/** Descriptive text for the numeric option */
define|#
directive|define
name|NUMERIC_DESC
value|(ntpdc_opt_strs+1301)
comment|/** Upper-cased name for the numeric option */
define|#
directive|define
name|NUMERIC_NAME
value|(ntpdc_opt_strs+1324)
comment|/** Name string for the numeric option */
define|#
directive|define
name|NUMERIC_name
value|(ntpdc_opt_strs+1332)
comment|/** Compiled in flag settings for the numeric option */
define|#
directive|define
name|NUMERIC_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  peers option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the peers option */
define|#
directive|define
name|PEERS_DESC
value|(ntpdc_opt_strs+1255)
comment|/** Upper-cased name for the peers option */
define|#
directive|define
name|PEERS_NAME
value|(ntpdc_opt_strs+1340)
comment|/** Name string for the peers option */
define|#
directive|define
name|PEERS_name
value|(ntpdc_opt_strs+1346)
comment|/** Other options that appear in conjunction with the peers option */
specifier|static
name|int
specifier|const
name|aPeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the peers option */
define|#
directive|define
name|PEERS_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  showpeers option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the showpeers option */
define|#
directive|define
name|SHOWPEERS_DESC
value|(ntpdc_opt_strs+1352)
comment|/** Upper-cased name for the showpeers option */
define|#
directive|define
name|SHOWPEERS_NAME
value|(ntpdc_opt_strs+1377)
comment|/** Name string for the showpeers option */
define|#
directive|define
name|SHOWPEERS_name
value|(ntpdc_opt_strs+1387)
comment|/** Other options that appear in conjunction with the showpeers option */
specifier|static
name|int
specifier|const
name|aShowpeersCantList
index|[]
init|=
block|{
name|INDEX_OPT_COMMAND
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the showpeers option */
define|#
directive|define
name|SHOWPEERS_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Help/More_Help/Version option descriptions:  */
define|#
directive|define
name|HELP_DESC
value|(ntpdc_opt_strs+1397)
define|#
directive|define
name|HELP_name
value|(ntpdc_opt_strs+1441)
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
define|#
directive|define
name|MORE_HELP_DESC
value|(ntpdc_opt_strs+1446)
define|#
directive|define
name|MORE_HELP_name
value|(ntpdc_opt_strs+1491)
define|#
directive|define
name|MORE_HELP_FLAGS
value|(OPTST_IMM | OPTST_NO_INIT)
else|#
directive|else
define|#
directive|define
name|MORE_HELP_DESC
value|HELP_DESC
define|#
directive|define
name|MORE_HELP_name
value|HELP_name
define|#
directive|define
name|MORE_HELP_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
endif|#
directive|endif
ifdef|#
directive|ifdef
name|NO_OPTIONAL_OPT_ARGS
define|#
directive|define
name|VER_FLAGS
value|(OPTST_IMM | OPTST_NO_INIT)
else|#
directive|else
define|#
directive|define
name|VER_FLAGS
value|(OPTST_SET_ARGTYPE(OPARG_TYPE_STRING) | \                          OPTST_ARG_OPTIONAL | OPTST_IMM | OPTST_NO_INIT)
endif|#
directive|endif
define|#
directive|define
name|VER_DESC
value|(ntpdc_opt_strs+1501)
define|#
directive|define
name|VER_name
value|(ntpdc_opt_strs+1537)
define|#
directive|define
name|SAVE_OPTS_DESC
value|(ntpdc_opt_strs+1545)
define|#
directive|define
name|SAVE_OPTS_name
value|(ntpdc_opt_strs+1584)
define|#
directive|define
name|LOAD_OPTS_DESC
value|(ntpdc_opt_strs+1594)
define|#
directive|define
name|LOAD_OPTS_NAME
value|(ntpdc_opt_strs+1626)
define|#
directive|define
name|NO_LOAD_OPTS_name
value|(ntpdc_opt_strs+1636)
define|#
directive|define
name|LOAD_OPTS_pfx
value|(ntpdc_opt_strs+1649)
define|#
directive|define
name|LOAD_OPTS_name
value|(NO_LOAD_OPTS_name + 3)
comment|/**  *  Declare option callback procedures  */
specifier|extern
name|tOptProc
name|ntpOptionPrintVersion
decl_stmt|,
name|optionBooleanVal
decl_stmt|,
name|optionNestedVal
decl_stmt|,
name|optionNumericVal
decl_stmt|,
name|optionPagedUsage
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
name|optionVendorOption
decl_stmt|;
specifier|static
name|tOptProc
name|doOptDebug_Level
decl_stmt|,
name|doUsageOpt
decl_stmt|;
define|#
directive|define
name|VER_PROC
value|ntpOptionPrintVersion
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  *  Define the ntpdc Option Descriptions.  * This is an array of OPTION_CT entries, one for each  * option that the ntpdc program responds to.  */
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
comment|/* --ipv4 */
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
name|IPV4_DESC
block|,
name|IPV4_NAME
block|,
name|IPV4_name
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
comment|/* --ipv6 */
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
name|IPV6_DESC
block|,
name|IPV6_NAME
block|,
name|IPV6_name
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
comment|/* --command */
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
name|COMMAND_DESC
block|,
name|COMMAND_NAME
block|,
name|COMMAND_name
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
comment|/* --debug-level */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doOptDebug_Level
block|,
comment|/* desc, NAME, name */
name|DEBUG_LEVEL_DESC
block|,
name|DEBUG_LEVEL_NAME
block|,
name|DEBUG_LEVEL_name
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
comment|/* --set-debug-level */
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
name|SET_DEBUG_LEVEL_DESC
block|,
name|SET_DEBUG_LEVEL_NAME
block|,
name|SET_DEBUG_LEVEL_name
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
name|VALUE_OPT_INTERACTIVE
block|,
comment|/* equiv idx, value */
literal|5
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
comment|/* --interactive */
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
name|INTERACTIVE_DESC
block|,
name|INTERACTIVE_NAME
block|,
name|INTERACTIVE_name
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
name|VALUE_OPT_LISTPEERS
block|,
comment|/* equiv idx, value */
literal|6
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
comment|/* --listpeers */
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
name|LISTPEERS_DESC
block|,
name|LISTPEERS_NAME
block|,
name|LISTPEERS_name
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
comment|/* --numeric */
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
name|NUMERIC_DESC
block|,
name|NUMERIC_NAME
block|,
name|NUMERIC_name
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
name|VALUE_OPT_PEERS
block|,
comment|/* equiv idx, value */
literal|8
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
comment|/* --peers */
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
name|PEERS_DESC
block|,
name|PEERS_NAME
block|,
name|PEERS_name
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
name|VALUE_OPT_SHOWPEERS
block|,
comment|/* equiv idx, value */
literal|9
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
comment|/* --showpeers */
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
name|SHOWPEERS_DESC
block|,
name|SHOWPEERS_NAME
block|,
name|SHOWPEERS_name
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
name|VALUE_OPT_VERSION
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
name|VER_FLAGS
block|,
name|AOUSE_VERSION
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
name|VER_PROC
block|,
comment|/* desc, NAME, name */
name|VER_DESC
block|,
name|NULL
block|,
name|VER_name
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
name|VALUE_OPT_HELP
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
name|AOUSE_HELP
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
name|HELP_DESC
block|,
name|NULL
block|,
name|HELP_name
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
name|VALUE_OPT_MORE_HELP
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
name|MORE_HELP_FLAGS
block|,
name|AOUSE_MORE_HELP
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
name|MORE_HELP_DESC
block|,
name|NULL
block|,
name|MORE_HELP_name
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
name|VALUE_OPT_SAVE_OPTS
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
name|AOUSE_SAVE_OPTS
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
name|SAVE_OPTS_DESC
block|,
name|NULL
block|,
name|SAVE_OPTS_name
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
name|VALUE_OPT_LOAD_OPTS
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
name|AOUSE_LOAD_OPTS
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
name|LOAD_OPTS_DESC
block|,
name|LOAD_OPTS_NAME
block|,
name|LOAD_OPTS_name
block|,
comment|/* disablement strs */
name|NO_LOAD_OPTS_name
block|,
name|LOAD_OPTS_pfx
block|}
block|}
decl_stmt|;
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/** Reference to the upper cased version of ntpdc. */
define|#
directive|define
name|zPROGNAME
value|(ntpdc_opt_strs+1652)
comment|/** Reference to the title line for ntpdc usage. */
define|#
directive|define
name|zUsageTitle
value|(ntpdc_opt_strs+1658)
comment|/** ntpdc configuration file name. */
define|#
directive|define
name|zRcName
value|(ntpdc_opt_strs+1794)
comment|/** Directories to search for ntpdc config files. */
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
name|ntpdc_opt_strs
operator|+
literal|1786
block|,
name|ntpdc_opt_strs
operator|+
literal|1792
block|,
name|NULL
block|}
decl_stmt|;
comment|/** The ntpdc program bug email address. */
define|#
directive|define
name|zBugsAddr
value|(ntpdc_opt_strs+1801)
comment|/** Clarification/explanation of what ntpdc does. */
define|#
directive|define
name|zExplain
value|(ntpdc_opt_strs+1835)
comment|/** Extra detail explaining what ntpdc does. */
define|#
directive|define
name|zDetail
value|(NULL)
comment|/** The full version string for ntpdc. */
define|#
directive|define
name|zFullVersion
value|(ntpdc_opt_strs+1837)
comment|/* extracted from optcode.tlib near line 364 */
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
value|(NULL)
define|#
directive|define
name|ntpdc_short_usage
value|(NULL)
endif|#
directive|endif
comment|/* not defined __doxygen__ */
comment|/*  *  Create the static procedure(s) declared above.  */
comment|/**  * The callout function that invokes the optionUsage function.  *  * @param[in] opts the AutoOpts option description structure  * @param[in] od   the descriptor for the "help" (usage) option.  * @noreturn  */
specifier|static
name|void
name|doUsageOpt
parameter_list|(
name|tOptions
modifier|*
name|opts
parameter_list|,
name|tOptDesc
modifier|*
name|od
parameter_list|)
block|{
name|int
name|ex_code
decl_stmt|;
name|ex_code
operator|=
name|NTPDC_EXIT_SUCCESS
expr_stmt|;
name|optionUsage
argument_list|(
operator|&
name|ntpdcOptions
argument_list|,
name|ex_code
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|opts
expr_stmt|;
operator|(
name|void
operator|)
name|od
expr_stmt|;
block|}
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the debug-level option.  *  * @param[in] pOptions the ntpdc options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptDebug_Level
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
comment|/*      * Be sure the flag-code[0] handles special values for the options pointer      * viz. (poptions<= OPTPROC_EMIT_LIMIT) *and also* the special flag bit      * ((poptdesc->fOptState& OPTST_RESET) != 0) telling the option to      * reset its state.      */
comment|/* extracted from debug-opt.def, line 15 */
name|OPT_VALUE_SET_DEBUG_LEVEL
operator|++
expr_stmt|;
operator|(
name|void
operator|)
name|pOptDesc
expr_stmt|;
operator|(
name|void
operator|)
name|pOptions
expr_stmt|;
block|}
comment|/* extracted from optmain.tlib near line 1245 */
comment|/**  * The directory containing the data associated with ntpdc.  */
ifndef|#
directive|ifndef
name|PKGDATADIR
define|#
directive|define
name|PKGDATADIR
value|""
endif|#
directive|endif
comment|/**  * Information about the person or institution that packaged ntpdc  * for the current distribution.  */
ifndef|#
directive|ifndef
name|WITH_PACKAGER
define|#
directive|define
name|ntpdc_packager_info
value|NULL
else|#
directive|else
comment|/** Packager information for ntpdc. */
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
ifndef|#
directive|ifndef
name|__doxygen__
endif|#
directive|endif
comment|/* __doxygen__ */
comment|/**  * The option definitions for ntpdc.  The one structure that  * binds them all.  */
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
if|#
directive|if
name|ENABLE_NLS
comment|/**  * This code is designed to translate translatable option text for the  * ntpdc program.  These translations happen upon entry  * to optionProcess().  */
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
ifdef|#
directive|ifdef
name|HAVE_DCGETTEXT
include|#
directive|include
file|<gettext.h>
endif|#
directive|endif
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
comment|/**  * AutoGen specific wrapper function for gettext.  It relies on the macro _()  * to convert from English to the target language, then strdup-duplicates the  * result string.  It tries the "libopts" domain first, then whatever has been  * set via the \a textdomain(3) call.  *  * @param[in] pz the input text used as a lookup key.  * @returns the translated text (if there is one),  *   or the original text (if not).  */
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
name|res
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
ifdef|#
directive|ifdef
name|HAVE_DCGETTEXT
comment|/*      * While processing the option_xlateable_txt data, try to use the      * "libopts" domain.  Once we switch to the option descriptor data,      * do *not* use that domain.      */
if|if
condition|(
name|option_xlateable_txt
operator|.
name|field_ct
operator|!=
literal|0
condition|)
block|{
name|res
operator|=
name|dgettext
argument_list|(
literal|"libopts"
argument_list|,
name|pz
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
operator|==
name|pz
condition|)
name|res
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
name|_
argument_list|(
name|pz
argument_list|)
expr_stmt|;
block|}
else|else
name|res
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
name|_
argument_list|(
name|pz
argument_list|)
expr_stmt|;
else|#
directive|else
name|res
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
name|_
argument_list|(
name|pz
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|res
operator|==
name|pz
condition|)
return|return
name|res
return|;
name|res
operator|=
name|strdup
argument_list|(
name|res
argument_list|)
expr_stmt|;
if|if
condition|(
name|res
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
name|res
return|;
block|}
comment|/**  * All the pointers we use are marked "* const", but they are stored in  * writable memory.  Coerce the mutability and set the pointer.  */
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
comment|/**  * Translate all the translatable strings in the ntpdcOptions  * structure defined above.  This is done only once.  */
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
name|opts
init|=
operator|&
name|ntpdcOptions
decl_stmt|;
comment|/*      *  Guard against re-translation.  It won't work.  The strings will have      *  been changed by the first pass through this code.  One shot only.      */
if|if
condition|(
name|option_xlateable_txt
operator|.
name|field_ct
operator|!=
literal|0
condition|)
block|{
comment|/*          *  Do the translations.  The first pointer follows the field count          *  field.  The field count field is the size of a pointer.          */
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
name|option_xlateable_txt
operator|)
decl_stmt|;
name|int
name|ix
init|=
name|option_xlateable_txt
operator|.
name|field_ct
decl_stmt|;
do|do
block|{
name|ppz
operator|++
expr_stmt|;
comment|/* skip over field_ct */
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
comment|/* prevent re-translation and disable "libopts" domain lookup */
name|option_xlateable_txt
operator|.
name|field_ct
operator|=
literal|0
expr_stmt|;
name|coerce_it
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
operator|(
name|opts
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
name|opts
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
name|opts
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
name|opts
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
name|opts
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
name|opts
operator|->
name|pzDetail
operator|)
argument_list|)
expr_stmt|;
block|{
name|tOptDesc
modifier|*
name|od
init|=
name|opts
operator|->
name|pOptDesc
decl_stmt|;
for|for
control|(
name|ix
operator|=
name|opts
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
name|od
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
name|od
operator|->
name|pzText
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
endif|#
directive|endif
comment|/* ENABLE_NLS */
ifdef|#
directive|ifdef
name|DO_NOT_COMPILE_THIS_CODE_IT_IS_FOR_GETTEXT
comment|/** I18N function strictly for xgettext.  Do not compile. */
specifier|static
name|void
name|bogus_function
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* TRANSLATORS:       The following dummy function was crated solely so that xgettext can      extract the correct strings.  These strings are actually referenced      by a field name in the ntpdcOptions structure noted in the      comments below.  The literal text is defined in ntpdc_opt_strs.          NOTE: the strings below are segmented with respect to the source string      ntpdc_opt_strs.  The strings above are handed off for translation      at run time a paragraph at a time.  Consequently, they are presented here      for translation a paragraph at a time.          ALSO: often the description for an option will reference another option      by name.  These are set off with apostrophe quotes (I hope).  Do not      translate option names.    */
comment|/* referenced via ntpdcOptions.pzCopyright */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpdc 4.2.8\n\ Copyright (C) 1970-2014 The University of Delaware, all rights reserved.\n\ This is free software. It is licensed for use, modification and\n\ redistribution under the terms of the NTP License, copies of which\n\ can be seen at:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"<http://ntp.org/license>\n\<http://opensource.org/licenses/ntp-license.php>\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzCopyNotice */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Permission to use, copy, modify, and distribute this software and its\n\ documentation for any purpose with or without fee is hereby granted,\n\ provided that the above copyright notice appears in all copies and that\n\ both the copyright notice and this permission notice appear in supporting\n\ documentation, and that the name The University of Delaware not be used in\n\ advertising or publicity pertaining to distribution of the software without\n\ specific, written prior permission.  The University of Delaware makes no\n\ representations about the suitability this software for any purpose.  It is\n\ provided \"as is\" without express or implied warranty.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv4 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv6 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"run a command and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Increase debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Set the debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force ntpq to operate in interactive mode"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Print a list of the peers"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"numeric host addresses"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Print a list of the peers"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Show a list of the peers"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"display extended usage information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"extended usage information passed thru pager"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"output version information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"save the option state to a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"load options from a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzUsageTitle */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpdc - vendor-specific NTPD control program - Ver. 4.2.8\n\ Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... [ host ...]\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzExplain */
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzFullVersion */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpdc 4.2.8"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzFullUsage */
name|puts
argument_list|(
name|_
argument_list|(
literal|"<<<NOT-FOUND>>>"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdcOptions.pzShortUsage */
name|puts
argument_list|(
name|_
argument_list|(
literal|"<<<NOT-FOUND>>>"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* LIBOPTS-MESSAGES: */
line|#
directive|line
number|67
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"allocation of %d bytes failed\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|93
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"allocation of %d bytes failed\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|53
file|"../init.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"AutoOpts function called without option descriptor\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|86
file|"../init.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\tThis exceeds the compiled library version:  "
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|84
file|"../init.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Automated Options Processing Error!\n"
literal|"\t%s called AutoOpts function with structure version %d:%d:%d.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|80
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"realloc of %d bytes at 0x%p failed\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|88
file|"../init.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\tThis is less than the minimum library version:  "
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|121
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Automated Options version %s\n"
literal|"\tCopyright (C) 1999-2014 by Bruce Korb - all rights reserved\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|82
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"(AutoOpts bug):  %s.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|90
file|"../reset.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"optionResetOpt() called, but reset-option not configured"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|292
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"could not locate the 'help' option"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|336
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"optionProcess() was called with invalid data"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|748
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"invalid argument type specified"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|598
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"defaulted to option with optional arg"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|76
file|"../alias.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"aliasing option is out of range."
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|234
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  the keyword '%s' is ambiguous for %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|108
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  The following options match:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|293
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: ambiguous option name: %s (matches %d options)\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|161
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: Command line arguments required\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|43
file|"../alias.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%d %s%s options allowed\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|89
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error %d (%s) calling %s for '%s'\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|301
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"interprocess pipe"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|168
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"error: version option argument '%c' invalid.  Use:\n"
literal|"\t'v' - version only\n"
literal|"\t'c' - version and copyright\n"
literal|"\t'n' - version and full copyright notice\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|58
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  the '%s' and '%s' options conflict\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|217
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: The '%s' option has been disabled."
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|430
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: The '%s' option has been disabled."
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|38
file|"../alias.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"-equivalence"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|469
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: illegal option -- %c\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|110
file|"../reset.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: illegal option -- %c\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|271
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: illegal option -- %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|755
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: illegal option -- %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|118
file|"../reset.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: illegal option -- %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|335
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: unknown vendor extension option -- %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|159
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  or an integer from %d through %d\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|169
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  or an integer from %d through %d\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|747
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  invalid option descriptor for %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1081
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  invalid option descriptor for %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|385
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: invalid option name: %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|527
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: The '%s' option requires an argument.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|156
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"(AutoOpts bug):  Equivalenced option '%s' was equivalenced to both\n"
literal|"\t'%s' and '%s'."
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|94
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  The %s option is required\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|632
file|"../find.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: The '%s' option cannot have an argument.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|151
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s: Command line arguments are not allowed.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|535
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"error %d (%s) creating %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|234
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  '%s' does not match any %s keywords.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|93
file|"../reset.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error: The '%s' option requires an argument.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|184
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"error %d (%s) stat-ing %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|238
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"error %d (%s) stat-ing %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|143
file|"../restore.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error: no saved option state\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|231
file|"../autoopts.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"'%s' is not a command line option.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|111
file|"../time.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  '%s' is not a recognizable date/time.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|132
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"'%s' not defined\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|50
file|"../time.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  '%s' is not a recognizable time duration.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|92
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  The %s option must appear %d times.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|164
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  '%s' is not a recognizable number.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|200
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  %s exceeds %s keyword count\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|330
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Try '%s %s' for more information.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|45
file|"../alias.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"one %s%s option allowed\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|203
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|938
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|274
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|415
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|625
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|175
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard output"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|274
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard error"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|415
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard error"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|625
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard error"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|175
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"standard error"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|203
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|938
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|273
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|414
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|624
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|174
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"write"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|60
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  %s option value %ld is out of range.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|44
file|"../check.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  %s option requires the %s option\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|131
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s warning:  cannot save options - %s not regular file\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|183
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s warning:  cannot save options - %s not regular file\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|237
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s warning:  cannot save options - %s not regular file\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|256
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s warning:  cannot save options - %s not regular file\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|534
file|"../save.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s warning:  cannot save options - %s not regular file\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* END-LIBOPTS-MESSAGES */
comment|/* USAGE-TEXT: */
line|#
directive|line
number|873
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- an alternate for '%s'\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1148
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Version, usage and configuration options:"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|924
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- default option for unnamed options\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|837
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- disabled as '--%s'\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1117
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|" --- %-14s %s\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1115
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"This option has been disabled"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|864
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- enabled by default\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|40
file|"../alias.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s error:  only "
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1194
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|" - examining environment variables named %s_*\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|168
file|"../file.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- file must not pre-exist\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|172
file|"../file.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- file must pre-exist\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|380
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Options are specified by doubled hyphens and their name or by a single\n"
literal|"hyphen and the flag character.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|916
file|"../makeshell.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"= = = = = = = =\n\n"
literal|"This incarnation of genshell will produce\n"
literal|"a shell script to parse the options for %s:\n\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|166
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  or an integer mask with any of the lower %d bits set\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|897
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- is a set membership option\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|918
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- must appear between %d and %d times\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|382
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Options are specified by single or double hyphens and their name.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|904
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- may appear multiple times\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|891
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- may not be preset\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1309
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"   Arg Option-Name    Description\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1245
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  Flg Arg Option-Name    Description\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1303
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  Flg Arg Option-Name    Description\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1304
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|" %3s %s"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1310
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|" %3s %s"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|387
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"The '-#<number>' option may omit the hash char\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|383
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"All arguments are named options.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|971
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|" - reading file %s"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|409
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"Please send bug reports to:<%s>\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|100
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"Please send bug reports to:<%s>\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|129
file|"../version.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"Please send bug reports to:<%s>\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|903
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- may NOT appear - preset only\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|944
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"The following option preset mechanisms are supported:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1192
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"The following option preset mechanisms are supported:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|682
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"prohibits these options:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|677
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"prohibits the option '%s'\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|81
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s%ld to %ld"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|79
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%sgreater than or equal to %ld"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|75
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%s%ld exactly"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|68
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%sit must lie in one of the ranges:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|68
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%sit must be in the range:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|88
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|", or\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|66
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%sis scalable with a suffix: k/K/m/M/g/G/t/T\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|77
file|"../numeric.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"%sless than or equal to %ld"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|390
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"Operands and options may be intermixed.  They will be reordered.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|652
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"requires the option '%s'\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|655
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"requires these options:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1321
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"   Arg Option-Name   Req?  Description\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1315
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"  Flg Arg Option-Name   Req?  Description\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|167
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"or you may use a numeric representation.  Preceding these with a '!'\n"
literal|"will clear the bits, specifying 'none' will clear all bits, and 'all'\n"
literal|"will set them all.  Multiple entries may be passed as an option\n"
literal|"argument list.\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|910
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"\t\t\t\t- may appear up to %d times\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|77
file|"../enum.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"The valid \"%s\" option keywords are:\n"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|1152
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"The next option supports vendor supported extra options:"
argument_list|)
argument_list|)
expr_stmt|;
line|#
directive|line
number|773
file|"../usage.c"
name|puts
argument_list|(
name|_
argument_list|(
literal|"These additional options are:"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* END-USAGE-TEXT */
block|}
endif|#
directive|endif
comment|/* uncompilable code */
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

