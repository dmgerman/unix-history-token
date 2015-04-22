begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (sntp-opts.c)  *  *  It has been AutoGen-ed  February  4, 2015 at 02:33:35 AM by AutoGen 5.18.5pre4  *  From the definitions    sntp-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the sntp author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The sntp program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware and Network Time Foundation makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
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
file|"sntp-opts.h"
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

begin_include
include|#
directive|include
file|<errno.h>
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
value|(sntp_opt_strs+0)
define|#
directive|define
name|zLicenseDescrip
value|(sntp_opt_strs+340)
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
comment|/**  *  static const strings for sntp options  */
specifier|static
name|char
specifier|const
name|sntp_opt_strs
index|[
literal|2549
index|]
init|=
comment|/*     0 */
literal|"sntp 4.2.8p1\n"
literal|"Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.\n"
literal|"This is free software. It is licensed for use, modification and\n"
literal|"redistribution under the terms of the NTP License, copies of which\n"
literal|"can be seen at:\n"
literal|"<http://ntp.org/license>\n"
literal|"<http://opensource.org/licenses/ntp-license.php>\n\0"
comment|/*   340 */
literal|"Permission to use, copy, modify, and distribute this software and its\n"
literal|"documentation for any purpose with or without fee is hereby granted,\n"
literal|"provided that the above copyright notice appears in all copies and that\n"
literal|"both the copyright notice and this permission notice appear in supporting\n"
literal|"documentation, and that the name The University of Delaware not be used in\n"
literal|"advertising or publicity pertaining to distribution of the software without\n"
literal|"specific, written prior permission.  The University of Delaware and Network\n"
literal|"Time Foundation makes no representations about the suitability this\n"
literal|"software for any purpose.  It is provided \"as is\" without express or\n"
literal|"implied warranty.\n\0"
comment|/*  1008 */
literal|"Force IPv4 DNS name resolution\0"
comment|/*  1039 */
literal|"IPV4\0"
comment|/*  1044 */
literal|"ipv4\0"
comment|/*  1049 */
literal|"Force IPv6 DNS name resolution\0"
comment|/*  1080 */
literal|"IPV6\0"
comment|/*  1085 */
literal|"ipv6\0"
comment|/*  1090 */
literal|"Enable authentication with the key auth-keynumber\0"
comment|/*  1140 */
literal|"AUTHENTICATION\0"
comment|/*  1155 */
literal|"authentication\0"
comment|/*  1170 */
literal|"Listen to the address specified for broadcast time sync\0"
comment|/*  1226 */
literal|"BROADCAST\0"
comment|/*  1236 */
literal|"broadcast\0"
comment|/*  1246 */
literal|"Concurrently query all IPs returned for host-name\0"
comment|/*  1296 */
literal|"CONCURRENT\0"
comment|/*  1307 */
literal|"concurrent\0"
comment|/*  1318 */
literal|"Increase debug verbosity level\0"
comment|/*  1349 */
literal|"DEBUG_LEVEL\0"
comment|/*  1361 */
literal|"debug-level\0"
comment|/*  1373 */
literal|"Set the debug verbosity level\0"
comment|/*  1403 */
literal|"SET_DEBUG_LEVEL\0"
comment|/*  1419 */
literal|"set-debug-level\0"
comment|/*  1435 */
literal|"The gap (in milliseconds) between time requests\0"
comment|/*  1483 */
literal|"GAP\0"
comment|/*  1487 */
literal|"gap\0"
comment|/*  1491 */
literal|"KoD history filename\0"
comment|/*  1512 */
literal|"KOD\0"
comment|/*  1516 */
literal|"kod\0"
comment|/*  1520 */
literal|"/var/db/ntp-kod\0"
comment|/*  1536 */
literal|"Look in this file for the key specified with -a\0"
comment|/*  1584 */
literal|"KEYFILE\0"
comment|/*  1592 */
literal|"keyfile\0"
comment|/*  1600 */
literal|"Log to specified logfile\0"
comment|/*  1625 */
literal|"LOGFILE\0"
comment|/*  1633 */
literal|"logfile\0"
comment|/*  1641 */
literal|"Adjustments less than steplimit msec will be slewed\0"
comment|/*  1693 */
literal|"STEPLIMIT\0"
comment|/*  1703 */
literal|"steplimit\0"
comment|/*  1713 */
literal|"Send int as our NTP protocol version\0"
comment|/*  1750 */
literal|"NTPVERSION\0"
comment|/*  1761 */
literal|"ntpversion\0"
comment|/*  1772 */
literal|"Use the NTP Reserved Port (port 123)\0"
comment|/*  1809 */
literal|"USERESERVEDPORT\0"
comment|/*  1825 */
literal|"usereservedport\0"
comment|/*  1841 */
literal|"OK to 'step' the time with settimeofday(2)\0"
comment|/*  1884 */
literal|"STEP\0"
comment|/*  1889 */
literal|"step\0"
comment|/*  1894 */
literal|"OK to 'slew' the time with adjtime(2)\0"
comment|/*  1932 */
literal|"SLEW\0"
comment|/*  1937 */
literal|"slew\0"
comment|/*  1942 */
literal|"The number of seconds to wait for responses\0"
comment|/*  1986 */
literal|"TIMEOUT\0"
comment|/*  1994 */
literal|"timeout\0"
comment|/*  2002 */
literal|"Wait for pending replies (if not setting the time)\0"
comment|/*  2053 */
literal|"WAIT\0"
comment|/*  2058 */
literal|"no-wait\0"
comment|/*  2066 */
literal|"no\0"
comment|/*  2069 */
literal|"display extended usage information and exit\0"
comment|/*  2113 */
literal|"help\0"
comment|/*  2118 */
literal|"extended usage information passed thru pager\0"
comment|/*  2163 */
literal|"more-help\0"
comment|/*  2173 */
literal|"output version information and exit\0"
comment|/*  2209 */
literal|"version\0"
comment|/*  2217 */
literal|"save the option state to a config file\0"
comment|/*  2256 */
literal|"save-opts\0"
comment|/*  2266 */
literal|"load options from a config file\0"
comment|/*  2298 */
literal|"LOAD_OPTS\0"
comment|/*  2308 */
literal|"no-load-opts\0"
comment|/*  2321 */
literal|"SNTP\0"
comment|/*  2326 */
literal|"sntp - standard Simple Network Time Protocol client program - Ver. 4.2.8p1\n"
literal|"Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \\\n"
literal|"\t\t[ hostname-or-IP ...]\n\0"
comment|/*  2485 */
literal|"$HOME\0"
comment|/*  2491 */
literal|".\0"
comment|/*  2493 */
literal|".ntprc\0"
comment|/*  2500 */
literal|"http://bugs.ntp.org, bugs@ntp.org\0"
comment|/*  2534 */
literal|"\n\0"
comment|/*  2536 */
literal|"sntp 4.2.8p1"
decl_stmt|;
comment|/**  *  ipv4 option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the ipv4 option */
define|#
directive|define
name|IPV4_DESC
value|(sntp_opt_strs+1008)
comment|/** Upper-cased name for the ipv4 option */
define|#
directive|define
name|IPV4_NAME
value|(sntp_opt_strs+1039)
comment|/** Name string for the ipv4 option */
define|#
directive|define
name|IPV4_name
value|(sntp_opt_strs+1044)
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
value|(sntp_opt_strs+1049)
comment|/** Upper-cased name for the ipv6 option */
define|#
directive|define
name|IPV6_NAME
value|(sntp_opt_strs+1080)
comment|/** Name string for the ipv6 option */
define|#
directive|define
name|IPV6_name
value|(sntp_opt_strs+1085)
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
comment|/**  *  authentication option description:  */
comment|/** Descriptive text for the authentication option */
define|#
directive|define
name|AUTHENTICATION_DESC
value|(sntp_opt_strs+1090)
comment|/** Upper-cased name for the authentication option */
define|#
directive|define
name|AUTHENTICATION_NAME
value|(sntp_opt_strs+1140)
comment|/** Name string for the authentication option */
define|#
directive|define
name|AUTHENTICATION_name
value|(sntp_opt_strs+1155)
comment|/** Compiled in flag settings for the authentication option */
define|#
directive|define
name|AUTHENTICATION_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  broadcast option description:  */
comment|/** Descriptive text for the broadcast option */
define|#
directive|define
name|BROADCAST_DESC
value|(sntp_opt_strs+1170)
comment|/** Upper-cased name for the broadcast option */
define|#
directive|define
name|BROADCAST_NAME
value|(sntp_opt_strs+1226)
comment|/** Name string for the broadcast option */
define|#
directive|define
name|BROADCAST_name
value|(sntp_opt_strs+1236)
comment|/** Compiled in flag settings for the broadcast option */
define|#
directive|define
name|BROADCAST_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  concurrent option description:  */
comment|/** Descriptive text for the concurrent option */
define|#
directive|define
name|CONCURRENT_DESC
value|(sntp_opt_strs+1246)
comment|/** Upper-cased name for the concurrent option */
define|#
directive|define
name|CONCURRENT_NAME
value|(sntp_opt_strs+1296)
comment|/** Name string for the concurrent option */
define|#
directive|define
name|CONCURRENT_name
value|(sntp_opt_strs+1307)
comment|/** Compiled in flag settings for the concurrent option */
define|#
directive|define
name|CONCURRENT_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  debug-level option description:  */
comment|/** Descriptive text for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_DESC
value|(sntp_opt_strs+1318)
comment|/** Upper-cased name for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_NAME
value|(sntp_opt_strs+1349)
comment|/** Name string for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_name
value|(sntp_opt_strs+1361)
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
value|(sntp_opt_strs+1373)
comment|/** Upper-cased name for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_NAME
value|(sntp_opt_strs+1403)
comment|/** Name string for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_name
value|(sntp_opt_strs+1419)
comment|/** Compiled in flag settings for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  gap option description:  */
comment|/** Descriptive text for the gap option */
define|#
directive|define
name|GAP_DESC
value|(sntp_opt_strs+1435)
comment|/** Upper-cased name for the gap option */
define|#
directive|define
name|GAP_NAME
value|(sntp_opt_strs+1483)
comment|/** Name string for the gap option */
define|#
directive|define
name|GAP_name
value|(sntp_opt_strs+1487)
comment|/** The compiled in default value for the gap option argument */
define|#
directive|define
name|GAP_DFT_ARG
value|((char const*)50)
comment|/** Compiled in flag settings for the gap option */
define|#
directive|define
name|GAP_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  kod option description:  */
comment|/** Descriptive text for the kod option */
define|#
directive|define
name|KOD_DESC
value|(sntp_opt_strs+1491)
comment|/** Upper-cased name for the kod option */
define|#
directive|define
name|KOD_NAME
value|(sntp_opt_strs+1512)
comment|/** Name string for the kod option */
define|#
directive|define
name|KOD_name
value|(sntp_opt_strs+1516)
comment|/** The compiled in default value for the kod option argument */
define|#
directive|define
name|KOD_DFT_ARG
value|(sntp_opt_strs+1520)
comment|/** Compiled in flag settings for the kod option */
define|#
directive|define
name|KOD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))
comment|/**  *  keyfile option description:  */
comment|/** Descriptive text for the keyfile option */
define|#
directive|define
name|KEYFILE_DESC
value|(sntp_opt_strs+1536)
comment|/** Upper-cased name for the keyfile option */
define|#
directive|define
name|KEYFILE_NAME
value|(sntp_opt_strs+1584)
comment|/** Name string for the keyfile option */
define|#
directive|define
name|KEYFILE_name
value|(sntp_opt_strs+1592)
comment|/** Compiled in flag settings for the keyfile option */
define|#
directive|define
name|KEYFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))
comment|/**  *  logfile option description:  */
comment|/** Descriptive text for the logfile option */
define|#
directive|define
name|LOGFILE_DESC
value|(sntp_opt_strs+1600)
comment|/** Upper-cased name for the logfile option */
define|#
directive|define
name|LOGFILE_NAME
value|(sntp_opt_strs+1625)
comment|/** Name string for the logfile option */
define|#
directive|define
name|LOGFILE_name
value|(sntp_opt_strs+1633)
comment|/** Compiled in flag settings for the logfile option */
define|#
directive|define
name|LOGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_FILE))
comment|/**  *  steplimit option description:  */
comment|/** Descriptive text for the steplimit option */
define|#
directive|define
name|STEPLIMIT_DESC
value|(sntp_opt_strs+1641)
comment|/** Upper-cased name for the steplimit option */
define|#
directive|define
name|STEPLIMIT_NAME
value|(sntp_opt_strs+1693)
comment|/** Name string for the steplimit option */
define|#
directive|define
name|STEPLIMIT_name
value|(sntp_opt_strs+1703)
comment|/** Compiled in flag settings for the steplimit option */
define|#
directive|define
name|STEPLIMIT_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  ntpversion option description:  */
comment|/** Descriptive text for the ntpversion option */
define|#
directive|define
name|NTPVERSION_DESC
value|(sntp_opt_strs+1713)
comment|/** Upper-cased name for the ntpversion option */
define|#
directive|define
name|NTPVERSION_NAME
value|(sntp_opt_strs+1750)
comment|/** Name string for the ntpversion option */
define|#
directive|define
name|NTPVERSION_name
value|(sntp_opt_strs+1761)
comment|/** The compiled in default value for the ntpversion option argument */
define|#
directive|define
name|NTPVERSION_DFT_ARG
value|((char const*)4)
comment|/** Compiled in flag settings for the ntpversion option */
define|#
directive|define
name|NTPVERSION_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  usereservedport option description:  */
comment|/** Descriptive text for the usereservedport option */
define|#
directive|define
name|USERESERVEDPORT_DESC
value|(sntp_opt_strs+1772)
comment|/** Upper-cased name for the usereservedport option */
define|#
directive|define
name|USERESERVEDPORT_NAME
value|(sntp_opt_strs+1809)
comment|/** Name string for the usereservedport option */
define|#
directive|define
name|USERESERVEDPORT_name
value|(sntp_opt_strs+1825)
comment|/** Compiled in flag settings for the usereservedport option */
define|#
directive|define
name|USERESERVEDPORT_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  step option description:  */
comment|/** Descriptive text for the step option */
define|#
directive|define
name|STEP_DESC
value|(sntp_opt_strs+1841)
comment|/** Upper-cased name for the step option */
define|#
directive|define
name|STEP_NAME
value|(sntp_opt_strs+1884)
comment|/** Name string for the step option */
define|#
directive|define
name|STEP_name
value|(sntp_opt_strs+1889)
comment|/** Compiled in flag settings for the step option */
define|#
directive|define
name|STEP_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  slew option description:  */
comment|/** Descriptive text for the slew option */
define|#
directive|define
name|SLEW_DESC
value|(sntp_opt_strs+1894)
comment|/** Upper-cased name for the slew option */
define|#
directive|define
name|SLEW_NAME
value|(sntp_opt_strs+1932)
comment|/** Name string for the slew option */
define|#
directive|define
name|SLEW_name
value|(sntp_opt_strs+1937)
comment|/** Compiled in flag settings for the slew option */
define|#
directive|define
name|SLEW_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  timeout option description:  */
comment|/** Descriptive text for the timeout option */
define|#
directive|define
name|TIMEOUT_DESC
value|(sntp_opt_strs+1942)
comment|/** Upper-cased name for the timeout option */
define|#
directive|define
name|TIMEOUT_NAME
value|(sntp_opt_strs+1986)
comment|/** Name string for the timeout option */
define|#
directive|define
name|TIMEOUT_name
value|(sntp_opt_strs+1994)
comment|/** The compiled in default value for the timeout option argument */
define|#
directive|define
name|TIMEOUT_DFT_ARG
value|((char const*)5)
comment|/** Compiled in flag settings for the timeout option */
define|#
directive|define
name|TIMEOUT_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  wait option description:  */
comment|/** Descriptive text for the wait option */
define|#
directive|define
name|WAIT_DESC
value|(sntp_opt_strs+2002)
comment|/** Upper-cased name for the wait option */
define|#
directive|define
name|WAIT_NAME
value|(sntp_opt_strs+2053)
comment|/** disablement name for the wait option */
define|#
directive|define
name|NOT_WAIT_name
value|(sntp_opt_strs+2058)
comment|/** disablement prefix for the wait option */
define|#
directive|define
name|NOT_WAIT_PFX
value|(sntp_opt_strs+2066)
comment|/** Name string for the wait option */
define|#
directive|define
name|WAIT_name
value|(NOT_WAIT_name + 3)
comment|/** Compiled in flag settings for the wait option */
define|#
directive|define
name|WAIT_FLAGS
value|(OPTST_INITENABLED)
comment|/*  *  Help/More_Help/Version option descriptions:  */
define|#
directive|define
name|HELP_DESC
value|(sntp_opt_strs+2069)
define|#
directive|define
name|HELP_name
value|(sntp_opt_strs+2113)
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
define|#
directive|define
name|MORE_HELP_DESC
value|(sntp_opt_strs+2118)
define|#
directive|define
name|MORE_HELP_name
value|(sntp_opt_strs+2163)
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
value|(sntp_opt_strs+2173)
define|#
directive|define
name|VER_name
value|(sntp_opt_strs+2209)
define|#
directive|define
name|SAVE_OPTS_DESC
value|(sntp_opt_strs+2217)
define|#
directive|define
name|SAVE_OPTS_name
value|(sntp_opt_strs+2256)
define|#
directive|define
name|LOAD_OPTS_DESC
value|(sntp_opt_strs+2266)
define|#
directive|define
name|LOAD_OPTS_NAME
value|(sntp_opt_strs+2298)
define|#
directive|define
name|NO_LOAD_OPTS_name
value|(sntp_opt_strs+2308)
define|#
directive|define
name|LOAD_OPTS_pfx
value|(sntp_opt_strs+2066)
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
name|doOptKeyfile
decl_stmt|,
name|doOptKod
decl_stmt|,
name|doOptLogfile
decl_stmt|,
name|doOptNtpversion
decl_stmt|,
name|doOptSteplimit
decl_stmt|,
name|doUsageOpt
decl_stmt|;
define|#
directive|define
name|VER_PROC
value|ntpOptionPrintVersion
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  *  Define the sntp Option Descriptions.  * This is an array of OPTION_CT entries, one for each  * option that the sntp program responds to.  */
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
name|VALUE_OPT_AUTHENTICATION
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_AUTHENTICATION
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
name|AUTHENTICATION_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --authentication */
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
name|AUTHENTICATION_DESC
block|,
name|AUTHENTICATION_NAME
block|,
name|AUTHENTICATION_name
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
name|VALUE_OPT_BROADCAST
block|,
comment|/* equiv idx, value */
literal|3
block|,
name|VALUE_OPT_BROADCAST
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
name|BROADCAST_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --broadcast */
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
name|BROADCAST_DESC
block|,
name|BROADCAST_NAME
block|,
name|BROADCAST_name
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
name|VALUE_OPT_CONCURRENT
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_CONCURRENT
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
name|CONCURRENT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --concurrent */
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
name|CONCURRENT_DESC
block|,
name|CONCURRENT_NAME
block|,
name|CONCURRENT_name
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
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|5
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
literal|6
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|6
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
literal|7
block|,
name|VALUE_OPT_GAP
block|,
comment|/* equiv idx, value */
literal|7
block|,
name|VALUE_OPT_GAP
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
name|GAP_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|GAP_DFT_ARG
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
name|GAP_DESC
block|,
name|GAP_NAME
block|,
name|GAP_name
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
name|VALUE_OPT_KOD
block|,
comment|/* equiv idx, value */
literal|8
block|,
name|VALUE_OPT_KOD
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
name|KOD_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|KOD_DFT_ARG
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
name|doOptKod
block|,
comment|/* desc, NAME, name */
name|KOD_DESC
block|,
name|KOD_NAME
block|,
name|KOD_name
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
name|VALUE_OPT_KEYFILE
block|,
comment|/* equiv idx, value */
literal|9
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
comment|/* --keyfile */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doOptKeyfile
block|,
comment|/* desc, NAME, name */
name|KEYFILE_DESC
block|,
name|KEYFILE_NAME
block|,
name|KEYFILE_name
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
name|VALUE_OPT_LOGFILE
block|,
comment|/* equiv idx, value */
literal|10
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
comment|/* --logfile */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doOptLogfile
block|,
comment|/* desc, NAME, name */
name|LOGFILE_DESC
block|,
name|LOGFILE_NAME
block|,
name|LOGFILE_name
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
name|VALUE_OPT_STEPLIMIT
block|,
comment|/* equiv idx, value */
literal|11
block|,
name|VALUE_OPT_STEPLIMIT
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
name|STEPLIMIT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --steplimit */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doOptSteplimit
block|,
comment|/* desc, NAME, name */
name|STEPLIMIT_DESC
block|,
name|STEPLIMIT_NAME
block|,
name|STEPLIMIT_name
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
name|VALUE_OPT_NTPVERSION
block|,
comment|/* equiv idx, value */
literal|12
block|,
name|VALUE_OPT_NTPVERSION
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
name|NTPVERSION_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NTPVERSION_DFT_ARG
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
name|doOptNtpversion
block|,
comment|/* desc, NAME, name */
name|NTPVERSION_DESC
block|,
name|NTPVERSION_NAME
block|,
name|NTPVERSION_name
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
name|VALUE_OPT_USERESERVEDPORT
block|,
comment|/* equiv idx, value */
literal|13
block|,
name|VALUE_OPT_USERESERVEDPORT
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
name|USERESERVEDPORT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --usereservedport */
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
name|USERESERVEDPORT_DESC
block|,
name|USERESERVEDPORT_NAME
block|,
name|USERESERVEDPORT_name
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
name|VALUE_OPT_STEP
block|,
comment|/* equiv idx, value */
literal|14
block|,
name|VALUE_OPT_STEP
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
name|STEP_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --step */
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
name|STEP_DESC
block|,
name|STEP_NAME
block|,
name|STEP_name
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
name|VALUE_OPT_SLEW
block|,
comment|/* equiv idx, value */
literal|15
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
comment|/* --slew */
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
name|SLEW_DESC
block|,
name|SLEW_NAME
block|,
name|SLEW_name
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
name|VALUE_OPT_TIMEOUT
block|,
comment|/* equiv idx, value */
literal|16
block|,
name|VALUE_OPT_TIMEOUT
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
name|TIMEOUT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|TIMEOUT_DFT_ARG
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
name|TIMEOUT_DESC
block|,
name|TIMEOUT_NAME
block|,
name|TIMEOUT_name
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
name|VALUE_OPT_WAIT
block|,
comment|/* equiv idx, value */
literal|17
block|,
name|VALUE_OPT_WAIT
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
name|WAIT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --wait */
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
name|WAIT_DESC
block|,
name|WAIT_NAME
block|,
name|WAIT_name
block|,
comment|/* disablement strs */
name|NOT_WAIT_name
block|,
name|NOT_WAIT_PFX
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
comment|/** Reference to the upper cased version of sntp. */
define|#
directive|define
name|zPROGNAME
value|(sntp_opt_strs+2321)
comment|/** Reference to the title line for sntp usage. */
define|#
directive|define
name|zUsageTitle
value|(sntp_opt_strs+2326)
comment|/** sntp configuration file name. */
define|#
directive|define
name|zRcName
value|(sntp_opt_strs+2493)
comment|/** Directories to search for sntp config files. */
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
name|sntp_opt_strs
operator|+
literal|2485
block|,
name|sntp_opt_strs
operator|+
literal|2491
block|,
name|NULL
block|}
decl_stmt|;
comment|/** The sntp program bug email address. */
define|#
directive|define
name|zBugsAddr
value|(sntp_opt_strs+2500)
comment|/** Clarification/explanation of what sntp does. */
define|#
directive|define
name|zExplain
value|(sntp_opt_strs+2534)
comment|/** Extra detail explaining what sntp does. */
define|#
directive|define
name|zDetail
value|(NULL)
comment|/** The full version string for sntp. */
define|#
directive|define
name|zFullVersion
value|(sntp_opt_strs+2536)
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
name|sntp_full_usage
value|(NULL)
define|#
directive|define
name|sntp_short_usage
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
name|SNTP_EXIT_SUCCESS
expr_stmt|;
name|optionUsage
argument_list|(
operator|&
name|sntpOptions
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
comment|/**  * Code to handle the debug-level option.  *  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
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
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the kod option.  * Specifies the filename to be used for the persistent history of KoD  * responses received from servers.  If the file does not exist, a  * warning message will be displayed.  The file will not be created.  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptKod
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
specifier|static
name|teOptFileType
specifier|const
name|type
init|=
name|FTYPE_MODE_MAY_EXIST
operator|+
name|FTYPE_MODE_NO_OPEN
decl_stmt|;
specifier|static
name|tuFileMode
name|mode
decl_stmt|;
ifndef|#
directive|ifndef
name|O_CLOEXEC
define|#
directive|define
name|O_CLOEXEC
value|0
endif|#
directive|endif
name|mode
operator|.
name|file_flags
operator|=
name|O_CLOEXEC
expr_stmt|;
comment|/*      * This function handles special invalid values for "pOptions"      */
name|optionFileCheck
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|,
name|type
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the keyfile option.  * This option specifies the keyfile.  * @code{sntp} will search for the key specified with @option{-a}  * @file{keyno} in this file.  See @command{ntp.keys(5)} for more  * information.  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptKeyfile
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
specifier|static
name|teOptFileType
specifier|const
name|type
init|=
name|FTYPE_MODE_MAY_EXIST
operator|+
name|FTYPE_MODE_NO_OPEN
decl_stmt|;
specifier|static
name|tuFileMode
name|mode
decl_stmt|;
ifndef|#
directive|ifndef
name|O_CLOEXEC
define|#
directive|define
name|O_CLOEXEC
value|0
endif|#
directive|endif
name|mode
operator|.
name|file_flags
operator|=
name|O_CLOEXEC
expr_stmt|;
comment|/*      * This function handles special invalid values for "pOptions"      */
name|optionFileCheck
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|,
name|type
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the logfile option.  * This option causes the client to write log messages to the specified  * @file{logfile}.  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptLogfile
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
specifier|static
name|teOptFileType
specifier|const
name|type
init|=
name|FTYPE_MODE_MAY_EXIST
operator|+
name|FTYPE_MODE_NO_OPEN
decl_stmt|;
specifier|static
name|tuFileMode
name|mode
decl_stmt|;
ifndef|#
directive|ifndef
name|O_CLOEXEC
define|#
directive|define
name|O_CLOEXEC
value|0
endif|#
directive|endif
name|mode
operator|.
name|file_flags
operator|=
name|O_CLOEXEC
expr_stmt|;
comment|/*      * This function handles special invalid values for "pOptions"      */
name|optionFileCheck
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|,
name|type
argument_list|,
name|mode
argument_list|)
expr_stmt|;
block|}
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the steplimit option.  * If the time adjustment is less than @file{steplimit} milliseconds,  * slew the amount using @command{adjtime(2)}.  Otherwise, step the  * correction using @command{settimeofday(2)}.  The default value is 0,  * which means all adjustments will be stepped.  This is a feature, as  * different situations demand different values.  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptSteplimit
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
specifier|static
struct|struct
block|{
name|long
name|rmin
decl_stmt|,
name|rmax
decl_stmt|;
block|}
decl|const
name|rng
index|[
literal|1
index|]
init|=
block|{
block|{
literal|0
block|,
name|LONG_MAX
block|}
block|}
struct|;
name|int
name|ix
decl_stmt|;
if|if
condition|(
name|pOptions
operator|<=
name|OPTPROC_EMIT_LIMIT
condition|)
goto|goto
name|emit_ranges
goto|;
name|optionNumericVal
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|)
expr_stmt|;
for|for
control|(
name|ix
operator|=
literal|0
init|;
name|ix
operator|<
literal|1
condition|;
name|ix
operator|++
control|)
block|{
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|<
name|rng
index|[
name|ix
index|]
operator|.
name|rmin
condition|)
continue|continue;
comment|/* ranges need not be ordered. */
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|==
name|rng
index|[
name|ix
index|]
operator|.
name|rmin
condition|)
return|return;
if|if
condition|(
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
operator|==
name|LONG_MIN
condition|)
continue|continue;
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|<=
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
condition|)
return|return;
block|}
name|option_usage_fp
operator|=
name|stderr
expr_stmt|;
name|emit_ranges
label|:
name|optionShowRange
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|,
operator|(
name|void
operator|*
operator|)
name|rng
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the ntpversion option.  * When sending requests to a remote server, tell them we are running  * NTP protocol version @file{ntpversion} .  * @param[in] pOptions the sntp options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
specifier|static
name|void
name|doOptNtpversion
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
specifier|static
struct|struct
block|{
name|long
name|rmin
decl_stmt|,
name|rmax
decl_stmt|;
block|}
decl|const
name|rng
index|[
literal|1
index|]
init|=
block|{
block|{
literal|0
block|,
literal|7
block|}
block|}
struct|;
name|int
name|ix
decl_stmt|;
if|if
condition|(
name|pOptions
operator|<=
name|OPTPROC_EMIT_LIMIT
condition|)
goto|goto
name|emit_ranges
goto|;
name|optionNumericVal
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|)
expr_stmt|;
for|for
control|(
name|ix
operator|=
literal|0
init|;
name|ix
operator|<
literal|1
condition|;
name|ix
operator|++
control|)
block|{
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|<
name|rng
index|[
name|ix
index|]
operator|.
name|rmin
condition|)
continue|continue;
comment|/* ranges need not be ordered. */
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|==
name|rng
index|[
name|ix
index|]
operator|.
name|rmin
condition|)
return|return;
if|if
condition|(
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
operator|==
name|LONG_MIN
condition|)
continue|continue;
if|if
condition|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|<=
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
condition|)
return|return;
block|}
name|option_usage_fp
operator|=
name|stderr
expr_stmt|;
name|emit_ranges
label|:
name|optionShowRange
argument_list|(
name|pOptions
argument_list|,
name|pOptDesc
argument_list|,
operator|(
name|void
operator|*
operator|)
name|rng
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* extracted from optmain.tlib near line 1245 */
comment|/**  * The directory containing the data associated with sntp.  */
ifndef|#
directive|ifndef
name|PKGDATADIR
define|#
directive|define
name|PKGDATADIR
value|""
endif|#
directive|endif
comment|/**  * Information about the person or institution that packaged sntp  * for the current distribution.  */
ifndef|#
directive|ifndef
name|WITH_PACKAGER
define|#
directive|define
name|sntp_packager_info
value|NULL
else|#
directive|else
comment|/** Packager information for sntp. */
specifier|static
name|char
specifier|const
name|sntp_packager_info
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
literal|"\nReport sntp bugs to "
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
comment|/**  * The option definitions for sntp.  The one structure that  * binds them all.  */
name|tOptions
name|sntpOptions
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
name|OPTPROC_NEGATIONS
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
literal|23
comment|/* full option count */
block|,
literal|18
comment|/* user option count */
block|,
name|sntp_full_usage
block|,
name|sntp_short_usage
block|,
name|NULL
block|,
name|NULL
block|,
name|PKGDATADIR
block|,
name|sntp_packager_info
block|}
decl_stmt|;
if|#
directive|if
name|ENABLE_NLS
comment|/**  * This code is designed to translate translatable option text for the  * sntp program.  These translations happen upon entry  * to optionProcess().  */
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
name|SNTP_EXIT_FAILURE
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
comment|/**  * Translate all the translatable strings in the sntpOptions  * structure defined above.  This is done only once.  */
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
name|sntpOptions
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
comment|/* TRANSLATORS:       The following dummy function was crated solely so that xgettext can      extract the correct strings.  These strings are actually referenced      by a field name in the sntpOptions structure noted in the      comments below.  The literal text is defined in sntp_opt_strs.          NOTE: the strings below are segmented with respect to the source string      sntp_opt_strs.  The strings above are handed off for translation      at run time a paragraph at a time.  Consequently, they are presented here      for translation a paragraph at a time.          ALSO: often the description for an option will reference another option      by name.  These are set off with apostrophe quotes (I hope).  Do not      translate option names.    */
comment|/* referenced via sntpOptions.pzCopyright */
name|puts
argument_list|(
name|_
argument_list|(
literal|"sntp 4.2.8p1\n\ Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.\n\ This is free software. It is licensed for use, modification and\n\ redistribution under the terms of the NTP License, copies of which\n\ can be seen at:\n"
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
comment|/* referenced via sntpOptions.pzCopyNotice */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Permission to use, copy, modify, and distribute this software and its\n\ documentation for any purpose with or without fee is hereby granted,\n\ provided that the above copyright notice appears in all copies and that\n\ both the copyright notice and this permission notice appear in supporting\n\ documentation, and that the name The University of Delaware not be used in\n\ advertising or publicity pertaining to distribution of the software without\n\ specific, written prior permission.  The University of Delaware and Network\n\ Time Foundation makes no representations about the suitability this\n\ software for any purpose.  It is provided \"as is\" without express or\n\ implied warranty.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv4 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv6 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Enable authentication with the key auth-keynumber"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Listen to the address specified for broadcast time sync"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Concurrently query all IPs returned for host-name"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Increase debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Set the debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"The gap (in milliseconds) between time requests"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"KoD history filename"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Look in this file for the key specified with -a"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Log to specified logfile"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Adjustments less than steplimit msec will be slewed"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Send int as our NTP protocol version"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Use the NTP Reserved Port (port 123)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"OK to 'step' the time with settimeofday(2)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"OK to 'slew' the time with adjtime(2)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"The number of seconds to wait for responses"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Wait for pending replies (if not setting the time)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"display extended usage information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"extended usage information passed thru pager"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"output version information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"save the option state to a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"load options from a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pzUsageTitle */
name|puts
argument_list|(
name|_
argument_list|(
literal|"sntp - standard Simple Network Time Protocol client program - Ver. 4.2.8p1\n\ Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \\\n\ \t\t[ hostname-or-IP ...]\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pzExplain */
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pzFullVersion */
name|puts
argument_list|(
name|_
argument_list|(
literal|"sntp 4.2.8p1"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pzFullUsage */
name|puts
argument_list|(
name|_
argument_list|(
literal|"<<<NOT-FOUND>>>"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via sntpOptions.pzShortUsage */
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
comment|/* sntp-opts.c ends here */
end_comment

end_unit

