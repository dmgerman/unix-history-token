begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (ntpd-opts.c)  *  *  It has been AutoGen-ed  February  4, 2015 at 02:39:17 AM by AutoGen 5.18.5pre4  *  From the definitions    ntpd-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntpd author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The ntpd program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware and Network Time Foundation makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
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
file|"ntpd-opts.h"
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
value|(ntpd_opt_strs+0)
define|#
directive|define
name|zLicenseDescrip
value|(ntpd_opt_strs+340)
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
comment|/**  *  static const strings for ntpd options  */
specifier|static
name|char
specifier|const
name|ntpd_opt_strs
index|[
literal|3061
index|]
init|=
comment|/*     0 */
literal|"ntpd 4.2.8p1\n"
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
literal|"Require crypto authentication\0"
comment|/*  1120 */
literal|"AUTHREQ\0"
comment|/*  1128 */
literal|"authreq\0"
comment|/*  1136 */
literal|"Do not require crypto authentication\0"
comment|/*  1173 */
literal|"AUTHNOREQ\0"
comment|/*  1183 */
literal|"authnoreq\0"
comment|/*  1193 */
literal|"Allow us to sync to broadcast servers\0"
comment|/*  1231 */
literal|"BCASTSYNC\0"
comment|/*  1241 */
literal|"bcastsync\0"
comment|/*  1251 */
literal|"configuration file name\0"
comment|/*  1275 */
literal|"CONFIGFILE\0"
comment|/*  1286 */
literal|"configfile\0"
comment|/*  1297 */
literal|"Increase debug verbosity level\0"
comment|/*  1328 */
literal|"DEBUG_LEVEL\0"
comment|/*  1340 */
literal|"debug-level\0"
comment|/*  1352 */
literal|"Set the debug verbosity level\0"
comment|/*  1382 */
literal|"SET_DEBUG_LEVEL\0"
comment|/*  1398 */
literal|"set-debug-level\0"
comment|/*  1414 */
literal|"frequency drift file name\0"
comment|/*  1440 */
literal|"DRIFTFILE\0"
comment|/*  1450 */
literal|"driftfile\0"
comment|/*  1460 */
literal|"Allow the first adjustment to be Big\0"
comment|/*  1497 */
literal|"PANICGATE\0"
comment|/*  1507 */
literal|"panicgate\0"
comment|/*  1517 */
literal|"Jail directory\0"
comment|/*  1532 */
literal|"JAILDIR\0"
comment|/*  1540 */
literal|"jaildir\0"
comment|/*  1548 */
literal|"built without --enable-clockctl or --enable-linuxcaps or --enable-solarisprivs\0"
comment|/*  1627 */
literal|"Listen on an interface name or address\0"
comment|/*  1666 */
literal|"INTERFACE\0"
comment|/*  1676 */
literal|"interface\0"
comment|/*  1686 */
literal|"path to symmetric keys\0"
comment|/*  1709 */
literal|"KEYFILE\0"
comment|/*  1717 */
literal|"keyfile\0"
comment|/*  1725 */
literal|"path to the log file\0"
comment|/*  1746 */
literal|"LOGFILE\0"
comment|/*  1754 */
literal|"logfile\0"
comment|/*  1762 */
literal|"Do not listen to virtual interfaces\0"
comment|/*  1798 */
literal|"NOVIRTUALIPS\0"
comment|/*  1811 */
literal|"novirtualips\0"
comment|/*  1824 */
literal|"Modify Multimedia Timer (Windows only)\0"
comment|/*  1863 */
literal|"MODIFYMMTIMER\0"
comment|/*  1877 */
literal|"modifymmtimer\0"
comment|/*  1891 */
literal|"Do not fork\0"
comment|/*  1903 */
literal|"NOFORK\0"
comment|/*  1910 */
literal|"nofork\0"
comment|/*  1917 */
literal|"Run at high priority\0"
comment|/*  1938 */
literal|"NICE\0"
comment|/*  1943 */
literal|"nice\0"
comment|/*  1948 */
literal|"path to the PID file\0"
comment|/*  1969 */
literal|"PIDFILE\0"
comment|/*  1977 */
literal|"pidfile\0"
comment|/*  1985 */
literal|"Process priority\0"
comment|/*  2002 */
literal|"PRIORITY\0"
comment|/*  2011 */
literal|"priority\0"
comment|/*  2020 */
literal|"Set the time and quit\0"
comment|/*  2042 */
literal|"QUIT\0"
comment|/*  2047 */
literal|"quit\0"
comment|/*  2052 */
literal|"Broadcast/propagation delay\0"
comment|/*  2080 */
literal|"PROPAGATIONDELAY\0"
comment|/*  2097 */
literal|"propagationdelay\0"
comment|/*  2114 */
literal|"Save parsed configuration and quit\0"
comment|/*  2149 */
literal|"SAVECONFIGQUIT\0"
comment|/*  2164 */
literal|"saveconfigquit\0"
comment|/*  2179 */
literal|"Statistics file location\0"
comment|/*  2204 */
literal|"STATSDIR\0"
comment|/*  2213 */
literal|"statsdir\0"
comment|/*  2222 */
literal|"Trusted key number\0"
comment|/*  2241 */
literal|"TRUSTEDKEY\0"
comment|/*  2252 */
literal|"trustedkey\0"
comment|/*  2263 */
literal|"Run as userid (or userid:groupid)\0"
comment|/*  2297 */
literal|"USER\0"
comment|/*  2302 */
literal|"user\0"
comment|/*  2307 */
literal|"interval in seconds between scans for new or dropped interfaces\0"
comment|/*  2371 */
literal|"UPDATEINTERVAL\0"
comment|/*  2386 */
literal|"updateinterval\0"
comment|/*  2401 */
literal|"make ARG an ntp variable (RW)\0"
comment|/*  2431 */
literal|"VAR\0"
comment|/*  2435 */
literal|"var\0"
comment|/*  2439 */
literal|"make ARG an ntp variable (RW|DEF)\0"
comment|/*  2473 */
literal|"DVAR\0"
comment|/*  2478 */
literal|"dvar\0"
comment|/*  2483 */
literal|"Seconds to wait for first clock sync\0"
comment|/*  2520 */
literal|"WAIT_SYNC\0"
comment|/*  2530 */
literal|"wait-sync\0"
comment|/*  2540 */
literal|"Slew up to 600 seconds\0"
comment|/*  2563 */
literal|"SLEW\0"
comment|/*  2568 */
literal|"slew\0"
comment|/*  2573 */
literal|"Use CPU cycle counter (Windows only)\0"
comment|/*  2610 */
literal|"USEPCC\0"
comment|/*  2617 */
literal|"usepcc\0"
comment|/*  2624 */
literal|"Force CPU cycle counter use (Windows only)\0"
comment|/*  2667 */
literal|"PCCFREQ\0"
comment|/*  2675 */
literal|"pccfreq\0"
comment|/*  2683 */
literal|"Register with mDNS as a NTP server\0"
comment|/*  2718 */
literal|"MDNS\0"
comment|/*  2723 */
literal|"mdns\0"
comment|/*  2728 */
literal|"display extended usage information and exit\0"
comment|/*  2772 */
literal|"help\0"
comment|/*  2777 */
literal|"extended usage information passed thru pager\0"
comment|/*  2822 */
literal|"more-help\0"
comment|/*  2832 */
literal|"output version information and exit\0"
comment|/*  2868 */
literal|"version\0"
comment|/*  2876 */
literal|"NTPD\0"
comment|/*  2881 */
literal|"ntpd - NTP daemon program - Ver. 4.2.8p1\n"
literal|"Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \\\n"
literal|"\t\t[<server1> ...<serverN> ]\n\0"
comment|/*  3012 */
literal|"http://bugs.ntp.org, bugs@ntp.org\0"
comment|/*  3046 */
literal|"\n\0"
comment|/*  3048 */
literal|"ntpd 4.2.8p1"
decl_stmt|;
comment|/**  *  ipv4 option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the ipv4 option */
define|#
directive|define
name|IPV4_DESC
value|(ntpd_opt_strs+1008)
comment|/** Upper-cased name for the ipv4 option */
define|#
directive|define
name|IPV4_NAME
value|(ntpd_opt_strs+1039)
comment|/** Name string for the ipv4 option */
define|#
directive|define
name|IPV4_name
value|(ntpd_opt_strs+1044)
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
value|(ntpd_opt_strs+1049)
comment|/** Upper-cased name for the ipv6 option */
define|#
directive|define
name|IPV6_NAME
value|(ntpd_opt_strs+1080)
comment|/** Name string for the ipv6 option */
define|#
directive|define
name|IPV6_name
value|(ntpd_opt_strs+1085)
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
comment|/**  *  authreq option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the authreq option */
define|#
directive|define
name|AUTHREQ_DESC
value|(ntpd_opt_strs+1090)
comment|/** Upper-cased name for the authreq option */
define|#
directive|define
name|AUTHREQ_NAME
value|(ntpd_opt_strs+1120)
comment|/** Name string for the authreq option */
define|#
directive|define
name|AUTHREQ_name
value|(ntpd_opt_strs+1128)
comment|/** Other options that appear in conjunction with the authreq option */
specifier|static
name|int
specifier|const
name|aAuthreqCantList
index|[]
init|=
block|{
name|INDEX_OPT_AUTHNOREQ
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the authreq option */
define|#
directive|define
name|AUTHREQ_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  authnoreq option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the authnoreq option */
define|#
directive|define
name|AUTHNOREQ_DESC
value|(ntpd_opt_strs+1136)
comment|/** Upper-cased name for the authnoreq option */
define|#
directive|define
name|AUTHNOREQ_NAME
value|(ntpd_opt_strs+1173)
comment|/** Name string for the authnoreq option */
define|#
directive|define
name|AUTHNOREQ_name
value|(ntpd_opt_strs+1183)
comment|/** Other options that appear in conjunction with the authnoreq option */
specifier|static
name|int
specifier|const
name|aAuthnoreqCantList
index|[]
init|=
block|{
name|INDEX_OPT_AUTHREQ
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the authnoreq option */
define|#
directive|define
name|AUTHNOREQ_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  bcastsync option description:  */
comment|/** Descriptive text for the bcastsync option */
define|#
directive|define
name|BCASTSYNC_DESC
value|(ntpd_opt_strs+1193)
comment|/** Upper-cased name for the bcastsync option */
define|#
directive|define
name|BCASTSYNC_NAME
value|(ntpd_opt_strs+1231)
comment|/** Name string for the bcastsync option */
define|#
directive|define
name|BCASTSYNC_name
value|(ntpd_opt_strs+1241)
comment|/** Compiled in flag settings for the bcastsync option */
define|#
directive|define
name|BCASTSYNC_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  configfile option description:  */
comment|/** Descriptive text for the configfile option */
define|#
directive|define
name|CONFIGFILE_DESC
value|(ntpd_opt_strs+1251)
comment|/** Upper-cased name for the configfile option */
define|#
directive|define
name|CONFIGFILE_NAME
value|(ntpd_opt_strs+1275)
comment|/** Name string for the configfile option */
define|#
directive|define
name|CONFIGFILE_name
value|(ntpd_opt_strs+1286)
comment|/** Compiled in flag settings for the configfile option */
define|#
directive|define
name|CONFIGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  debug-level option description:  */
comment|/** Descriptive text for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_DESC
value|(ntpd_opt_strs+1297)
comment|/** Upper-cased name for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_NAME
value|(ntpd_opt_strs+1328)
comment|/** Name string for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_name
value|(ntpd_opt_strs+1340)
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
value|(ntpd_opt_strs+1352)
comment|/** Upper-cased name for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_NAME
value|(ntpd_opt_strs+1382)
comment|/** Name string for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_name
value|(ntpd_opt_strs+1398)
comment|/** Compiled in flag settings for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  driftfile option description:  */
comment|/** Descriptive text for the driftfile option */
define|#
directive|define
name|DRIFTFILE_DESC
value|(ntpd_opt_strs+1414)
comment|/** Upper-cased name for the driftfile option */
define|#
directive|define
name|DRIFTFILE_NAME
value|(ntpd_opt_strs+1440)
comment|/** Name string for the driftfile option */
define|#
directive|define
name|DRIFTFILE_name
value|(ntpd_opt_strs+1450)
comment|/** Compiled in flag settings for the driftfile option */
define|#
directive|define
name|DRIFTFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  panicgate option description:  */
comment|/** Descriptive text for the panicgate option */
define|#
directive|define
name|PANICGATE_DESC
value|(ntpd_opt_strs+1460)
comment|/** Upper-cased name for the panicgate option */
define|#
directive|define
name|PANICGATE_NAME
value|(ntpd_opt_strs+1497)
comment|/** Name string for the panicgate option */
define|#
directive|define
name|PANICGATE_name
value|(ntpd_opt_strs+1507)
comment|/** Compiled in flag settings for the panicgate option */
define|#
directive|define
name|PANICGATE_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  jaildir option description:  */
ifdef|#
directive|ifdef
name|HAVE_DROPROOT
comment|/** Descriptive text for the jaildir option */
define|#
directive|define
name|JAILDIR_DESC
value|(ntpd_opt_strs+1517)
comment|/** Upper-cased name for the jaildir option */
define|#
directive|define
name|JAILDIR_NAME
value|(ntpd_opt_strs+1532)
comment|/** Name string for the jaildir option */
define|#
directive|define
name|JAILDIR_name
value|(ntpd_opt_strs+1540)
comment|/** Compiled in flag settings for the jaildir option */
define|#
directive|define
name|JAILDIR_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable jaildir */
define|#
directive|define
name|JAILDIR_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|JAILDIR_NAME
value|NULL
comment|/** Descriptive text for the jaildir option */
define|#
directive|define
name|JAILDIR_DESC
value|(ntpd_opt_strs+1548)
define|#
directive|define
name|JAILDIR_name
value|(ntpd_opt_strs+1540)
endif|#
directive|endif
comment|/* HAVE_DROPROOT */
comment|/**  *  interface option description:  */
comment|/** Descriptive text for the interface option */
define|#
directive|define
name|INTERFACE_DESC
value|(ntpd_opt_strs+1627)
comment|/** Upper-cased name for the interface option */
define|#
directive|define
name|INTERFACE_NAME
value|(ntpd_opt_strs+1666)
comment|/** Name string for the interface option */
define|#
directive|define
name|INTERFACE_name
value|(ntpd_opt_strs+1676)
comment|/** Compiled in flag settings for the interface option */
define|#
directive|define
name|INTERFACE_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  keyfile option description:  */
comment|/** Descriptive text for the keyfile option */
define|#
directive|define
name|KEYFILE_DESC
value|(ntpd_opt_strs+1686)
comment|/** Upper-cased name for the keyfile option */
define|#
directive|define
name|KEYFILE_NAME
value|(ntpd_opt_strs+1709)
comment|/** Name string for the keyfile option */
define|#
directive|define
name|KEYFILE_name
value|(ntpd_opt_strs+1717)
comment|/** Compiled in flag settings for the keyfile option */
define|#
directive|define
name|KEYFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  logfile option description:  */
comment|/** Descriptive text for the logfile option */
define|#
directive|define
name|LOGFILE_DESC
value|(ntpd_opt_strs+1725)
comment|/** Upper-cased name for the logfile option */
define|#
directive|define
name|LOGFILE_NAME
value|(ntpd_opt_strs+1746)
comment|/** Name string for the logfile option */
define|#
directive|define
name|LOGFILE_name
value|(ntpd_opt_strs+1754)
comment|/** Compiled in flag settings for the logfile option */
define|#
directive|define
name|LOGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  novirtualips option description:  */
comment|/** Descriptive text for the novirtualips option */
define|#
directive|define
name|NOVIRTUALIPS_DESC
value|(ntpd_opt_strs+1762)
comment|/** Upper-cased name for the novirtualips option */
define|#
directive|define
name|NOVIRTUALIPS_NAME
value|(ntpd_opt_strs+1798)
comment|/** Name string for the novirtualips option */
define|#
directive|define
name|NOVIRTUALIPS_name
value|(ntpd_opt_strs+1811)
comment|/** Compiled in flag settings for the novirtualips option */
define|#
directive|define
name|NOVIRTUALIPS_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  modifymmtimer option description:  */
ifdef|#
directive|ifdef
name|SYS_WINNT
comment|/** Descriptive text for the modifymmtimer option */
define|#
directive|define
name|MODIFYMMTIMER_DESC
value|(ntpd_opt_strs+1824)
comment|/** Upper-cased name for the modifymmtimer option */
define|#
directive|define
name|MODIFYMMTIMER_NAME
value|(ntpd_opt_strs+1863)
comment|/** Name string for the modifymmtimer option */
define|#
directive|define
name|MODIFYMMTIMER_name
value|(ntpd_opt_strs+1877)
comment|/** Compiled in flag settings for the modifymmtimer option */
define|#
directive|define
name|MODIFYMMTIMER_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable modifymmtimer */
define|#
directive|define
name|MODIFYMMTIMER_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|MODIFYMMTIMER_NAME
value|NULL
define|#
directive|define
name|MODIFYMMTIMER_DESC
value|NULL
define|#
directive|define
name|MODIFYMMTIMER_name
value|NULL
endif|#
directive|endif
comment|/* SYS_WINNT */
comment|/**  *  nofork option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the nofork option */
define|#
directive|define
name|NOFORK_DESC
value|(ntpd_opt_strs+1891)
comment|/** Upper-cased name for the nofork option */
define|#
directive|define
name|NOFORK_NAME
value|(ntpd_opt_strs+1903)
comment|/** Name string for the nofork option */
define|#
directive|define
name|NOFORK_name
value|(ntpd_opt_strs+1910)
comment|/** Other options that appear in conjunction with the nofork option */
specifier|static
name|int
specifier|const
name|aNoforkCantList
index|[]
init|=
block|{
name|INDEX_OPT_WAIT_SYNC
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the nofork option */
define|#
directive|define
name|NOFORK_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  nice option description:  */
comment|/** Descriptive text for the nice option */
define|#
directive|define
name|NICE_DESC
value|(ntpd_opt_strs+1917)
comment|/** Upper-cased name for the nice option */
define|#
directive|define
name|NICE_NAME
value|(ntpd_opt_strs+1938)
comment|/** Name string for the nice option */
define|#
directive|define
name|NICE_name
value|(ntpd_opt_strs+1943)
comment|/** Compiled in flag settings for the nice option */
define|#
directive|define
name|NICE_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  pidfile option description:  */
comment|/** Descriptive text for the pidfile option */
define|#
directive|define
name|PIDFILE_DESC
value|(ntpd_opt_strs+1948)
comment|/** Upper-cased name for the pidfile option */
define|#
directive|define
name|PIDFILE_NAME
value|(ntpd_opt_strs+1969)
comment|/** Name string for the pidfile option */
define|#
directive|define
name|PIDFILE_name
value|(ntpd_opt_strs+1977)
comment|/** Compiled in flag settings for the pidfile option */
define|#
directive|define
name|PIDFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  priority option description:  */
comment|/** Descriptive text for the priority option */
define|#
directive|define
name|PRIORITY_DESC
value|(ntpd_opt_strs+1985)
comment|/** Upper-cased name for the priority option */
define|#
directive|define
name|PRIORITY_NAME
value|(ntpd_opt_strs+2002)
comment|/** Name string for the priority option */
define|#
directive|define
name|PRIORITY_name
value|(ntpd_opt_strs+2011)
comment|/** Compiled in flag settings for the priority option */
define|#
directive|define
name|PRIORITY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  quit option description with  *  "Must also have options" and "Incompatible options":  */
comment|/** Descriptive text for the quit option */
define|#
directive|define
name|QUIT_DESC
value|(ntpd_opt_strs+2020)
comment|/** Upper-cased name for the quit option */
define|#
directive|define
name|QUIT_NAME
value|(ntpd_opt_strs+2042)
comment|/** Name string for the quit option */
define|#
directive|define
name|QUIT_name
value|(ntpd_opt_strs+2047)
comment|/** Other options that appear in conjunction with the quit option */
specifier|static
name|int
specifier|const
name|aQuitCantList
index|[]
init|=
block|{
name|INDEX_OPT_SAVECONFIGQUIT
block|,
name|INDEX_OPT_WAIT_SYNC
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the quit option */
define|#
directive|define
name|QUIT_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  propagationdelay option description:  */
comment|/** Descriptive text for the propagationdelay option */
define|#
directive|define
name|PROPAGATIONDELAY_DESC
value|(ntpd_opt_strs+2052)
comment|/** Upper-cased name for the propagationdelay option */
define|#
directive|define
name|PROPAGATIONDELAY_NAME
value|(ntpd_opt_strs+2080)
comment|/** Name string for the propagationdelay option */
define|#
directive|define
name|PROPAGATIONDELAY_name
value|(ntpd_opt_strs+2097)
comment|/** Compiled in flag settings for the propagationdelay option */
define|#
directive|define
name|PROPAGATIONDELAY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  saveconfigquit option description with  *  "Must also have options" and "Incompatible options":  */
ifdef|#
directive|ifdef
name|SAVECONFIG
comment|/** Descriptive text for the saveconfigquit option */
define|#
directive|define
name|SAVECONFIGQUIT_DESC
value|(ntpd_opt_strs+2114)
comment|/** Upper-cased name for the saveconfigquit option */
define|#
directive|define
name|SAVECONFIGQUIT_NAME
value|(ntpd_opt_strs+2149)
comment|/** Name string for the saveconfigquit option */
define|#
directive|define
name|SAVECONFIGQUIT_name
value|(ntpd_opt_strs+2164)
comment|/** Other options that appear in conjunction with the saveconfigquit option */
specifier|static
name|int
specifier|const
name|aSaveconfigquitCantList
index|[]
init|=
block|{
name|INDEX_OPT_QUIT
block|,
name|INDEX_OPT_WAIT_SYNC
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the saveconfigquit option */
define|#
directive|define
name|SAVECONFIGQUIT_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable saveconfigquit */
define|#
directive|define
name|SAVECONFIGQUIT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|aSaveconfigquitCantList
value|NULL
define|#
directive|define
name|SAVECONFIGQUIT_NAME
value|NULL
define|#
directive|define
name|SAVECONFIGQUIT_DESC
value|NULL
define|#
directive|define
name|SAVECONFIGQUIT_name
value|NULL
endif|#
directive|endif
comment|/* SAVECONFIG */
comment|/**  *  statsdir option description:  */
comment|/** Descriptive text for the statsdir option */
define|#
directive|define
name|STATSDIR_DESC
value|(ntpd_opt_strs+2179)
comment|/** Upper-cased name for the statsdir option */
define|#
directive|define
name|STATSDIR_NAME
value|(ntpd_opt_strs+2204)
comment|/** Name string for the statsdir option */
define|#
directive|define
name|STATSDIR_name
value|(ntpd_opt_strs+2213)
comment|/** Compiled in flag settings for the statsdir option */
define|#
directive|define
name|STATSDIR_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  trustedkey option description:  */
comment|/** Descriptive text for the trustedkey option */
define|#
directive|define
name|TRUSTEDKEY_DESC
value|(ntpd_opt_strs+2222)
comment|/** Upper-cased name for the trustedkey option */
define|#
directive|define
name|TRUSTEDKEY_NAME
value|(ntpd_opt_strs+2241)
comment|/** Name string for the trustedkey option */
define|#
directive|define
name|TRUSTEDKEY_name
value|(ntpd_opt_strs+2252)
comment|/** Compiled in flag settings for the trustedkey option */
define|#
directive|define
name|TRUSTEDKEY_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  user option description:  */
ifdef|#
directive|ifdef
name|HAVE_DROPROOT
comment|/** Descriptive text for the user option */
define|#
directive|define
name|USER_DESC
value|(ntpd_opt_strs+2263)
comment|/** Upper-cased name for the user option */
define|#
directive|define
name|USER_NAME
value|(ntpd_opt_strs+2297)
comment|/** Name string for the user option */
define|#
directive|define
name|USER_name
value|(ntpd_opt_strs+2302)
comment|/** Compiled in flag settings for the user option */
define|#
directive|define
name|USER_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable user */
define|#
directive|define
name|USER_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|USER_NAME
value|NULL
comment|/** Descriptive text for the user option */
define|#
directive|define
name|USER_DESC
value|(ntpd_opt_strs+1548)
define|#
directive|define
name|USER_name
value|(ntpd_opt_strs+2302)
endif|#
directive|endif
comment|/* HAVE_DROPROOT */
comment|/**  *  updateinterval option description:  */
comment|/** Descriptive text for the updateinterval option */
define|#
directive|define
name|UPDATEINTERVAL_DESC
value|(ntpd_opt_strs+2307)
comment|/** Upper-cased name for the updateinterval option */
define|#
directive|define
name|UPDATEINTERVAL_NAME
value|(ntpd_opt_strs+2371)
comment|/** Name string for the updateinterval option */
define|#
directive|define
name|UPDATEINTERVAL_name
value|(ntpd_opt_strs+2386)
comment|/** Compiled in flag settings for the updateinterval option */
define|#
directive|define
name|UPDATEINTERVAL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  var option description:  */
comment|/** Descriptive text for the var option */
define|#
directive|define
name|VAR_DESC
value|(ntpd_opt_strs+2401)
comment|/** Upper-cased name for the var option */
define|#
directive|define
name|VAR_NAME
value|(ntpd_opt_strs+2431)
comment|/** Name string for the var option */
define|#
directive|define
name|VAR_name
value|(ntpd_opt_strs+2435)
comment|/** Compiled in flag settings for the var option */
define|#
directive|define
name|VAR_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  dvar option description:  */
comment|/** Descriptive text for the dvar option */
define|#
directive|define
name|DVAR_DESC
value|(ntpd_opt_strs+2439)
comment|/** Upper-cased name for the dvar option */
define|#
directive|define
name|DVAR_NAME
value|(ntpd_opt_strs+2473)
comment|/** Name string for the dvar option */
define|#
directive|define
name|DVAR_name
value|(ntpd_opt_strs+2478)
comment|/** Compiled in flag settings for the dvar option */
define|#
directive|define
name|DVAR_FLAGS
value|(OPTST_DISABLED | OPTST_STACKED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/**  *  wait-sync option description with  *  "Must also have options" and "Incompatible options":  */
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
comment|/** Descriptive text for the wait-sync option */
define|#
directive|define
name|WAIT_SYNC_DESC
value|(ntpd_opt_strs+2483)
comment|/** Upper-cased name for the wait-sync option */
define|#
directive|define
name|WAIT_SYNC_NAME
value|(ntpd_opt_strs+2520)
comment|/** Name string for the wait-sync option */
define|#
directive|define
name|WAIT_SYNC_name
value|(ntpd_opt_strs+2530)
comment|/** Other options that appear in conjunction with the wait-sync option */
specifier|static
name|int
specifier|const
name|aWait_SyncCantList
index|[]
init|=
block|{
name|INDEX_OPT_NOFORK
block|,
name|INDEX_OPT_QUIT
block|,
name|INDEX_OPT_SAVECONFIGQUIT
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
comment|/** Compiled in flag settings for the wait-sync option */
define|#
directive|define
name|WAIT_SYNC_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable wait-sync */
define|#
directive|define
name|WAIT_SYNC_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|aWait_SyncCantList
value|NULL
define|#
directive|define
name|WAIT_SYNC_NAME
value|NULL
define|#
directive|define
name|WAIT_SYNC_DESC
value|NULL
define|#
directive|define
name|WAIT_SYNC_name
value|NULL
endif|#
directive|endif
comment|/* HAVE_WORKING_FORK */
comment|/**  *  slew option description:  */
comment|/** Descriptive text for the slew option */
define|#
directive|define
name|SLEW_DESC
value|(ntpd_opt_strs+2540)
comment|/** Upper-cased name for the slew option */
define|#
directive|define
name|SLEW_NAME
value|(ntpd_opt_strs+2563)
comment|/** Name string for the slew option */
define|#
directive|define
name|SLEW_name
value|(ntpd_opt_strs+2568)
comment|/** Compiled in flag settings for the slew option */
define|#
directive|define
name|SLEW_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  usepcc option description:  */
ifdef|#
directive|ifdef
name|SYS_WINNT
comment|/** Descriptive text for the usepcc option */
define|#
directive|define
name|USEPCC_DESC
value|(ntpd_opt_strs+2573)
comment|/** Upper-cased name for the usepcc option */
define|#
directive|define
name|USEPCC_NAME
value|(ntpd_opt_strs+2610)
comment|/** Name string for the usepcc option */
define|#
directive|define
name|USEPCC_name
value|(ntpd_opt_strs+2617)
comment|/** Compiled in flag settings for the usepcc option */
define|#
directive|define
name|USEPCC_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable usepcc */
define|#
directive|define
name|USEPCC_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|USEPCC_NAME
value|NULL
define|#
directive|define
name|USEPCC_DESC
value|NULL
define|#
directive|define
name|USEPCC_name
value|NULL
endif|#
directive|endif
comment|/* SYS_WINNT */
comment|/**  *  pccfreq option description:  */
ifdef|#
directive|ifdef
name|SYS_WINNT
comment|/** Descriptive text for the pccfreq option */
define|#
directive|define
name|PCCFREQ_DESC
value|(ntpd_opt_strs+2624)
comment|/** Upper-cased name for the pccfreq option */
define|#
directive|define
name|PCCFREQ_NAME
value|(ntpd_opt_strs+2667)
comment|/** Name string for the pccfreq option */
define|#
directive|define
name|PCCFREQ_name
value|(ntpd_opt_strs+2675)
comment|/** Compiled in flag settings for the pccfreq option */
define|#
directive|define
name|PCCFREQ_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable pccfreq */
define|#
directive|define
name|PCCFREQ_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|PCCFREQ_NAME
value|NULL
define|#
directive|define
name|PCCFREQ_DESC
value|NULL
define|#
directive|define
name|PCCFREQ_name
value|NULL
endif|#
directive|endif
comment|/* SYS_WINNT */
comment|/**  *  mdns option description:  */
ifdef|#
directive|ifdef
name|HAVE_DNSREGISTRATION
comment|/** Descriptive text for the mdns option */
define|#
directive|define
name|MDNS_DESC
value|(ntpd_opt_strs+2683)
comment|/** Upper-cased name for the mdns option */
define|#
directive|define
name|MDNS_NAME
value|(ntpd_opt_strs+2718)
comment|/** Name string for the mdns option */
define|#
directive|define
name|MDNS_name
value|(ntpd_opt_strs+2723)
comment|/** Compiled in flag settings for the mdns option */
define|#
directive|define
name|MDNS_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable mdns */
define|#
directive|define
name|MDNS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|MDNS_NAME
value|NULL
define|#
directive|define
name|MDNS_DESC
value|NULL
define|#
directive|define
name|MDNS_name
value|NULL
endif|#
directive|endif
comment|/* HAVE_DNSREGISTRATION */
comment|/*  *  Help/More_Help/Version option descriptions:  */
define|#
directive|define
name|HELP_DESC
value|(ntpd_opt_strs+2728)
define|#
directive|define
name|HELP_name
value|(ntpd_opt_strs+2772)
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
define|#
directive|define
name|MORE_HELP_DESC
value|(ntpd_opt_strs+2777)
define|#
directive|define
name|MORE_HELP_name
value|(ntpd_opt_strs+2822)
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
value|(ntpd_opt_strs+2832)
define|#
directive|define
name|VER_name
value|(ntpd_opt_strs+2868)
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
comment|/**  *  Define the ntpd Option Descriptions.  * This is an array of OPTION_CT entries, one for each  * option that the ntpd program responds to.  */
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
comment|/* --authreq */
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
name|AUTHREQ_DESC
block|,
name|AUTHREQ_NAME
block|,
name|AUTHREQ_name
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
comment|/* --authnoreq */
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
name|AUTHNOREQ_DESC
block|,
name|AUTHNOREQ_NAME
block|,
name|AUTHNOREQ_name
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
comment|/* --bcastsync */
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
name|BCASTSYNC_DESC
block|,
name|BCASTSYNC_NAME
block|,
name|BCASTSYNC_name
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
comment|/* --configfile */
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
name|CONFIGFILE_DESC
block|,
name|CONFIGFILE_NAME
block|,
name|CONFIGFILE_name
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
comment|/* --driftfile */
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
name|DRIFTFILE_DESC
block|,
name|DRIFTFILE_NAME
block|,
name|DRIFTFILE_name
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
name|NOLIMIT
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
comment|/* --panicgate */
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
name|PANICGATE_DESC
block|,
name|PANICGATE_NAME
block|,
name|PANICGATE_name
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
comment|/* --jaildir */
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
name|JAILDIR_DESC
block|,
name|JAILDIR_NAME
block|,
name|JAILDIR_name
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
comment|/* --interface */
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
name|INTERFACE_DESC
block|,
name|INTERFACE_NAME
block|,
name|INTERFACE_name
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
name|NULL
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
name|NULL
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
comment|/* --novirtualips */
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
name|NOVIRTUALIPS_DESC
block|,
name|NOVIRTUALIPS_NAME
block|,
name|NOVIRTUALIPS_name
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
comment|/* --modifymmtimer */
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
name|MODIFYMMTIMER_DESC
block|,
name|MODIFYMMTIMER_NAME
block|,
name|MODIFYMMTIMER_name
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
comment|/* --nofork */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aNoforkCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|NOFORK_DESC
block|,
name|NOFORK_NAME
block|,
name|NOFORK_name
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
comment|/* --nice */
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
name|NICE_DESC
block|,
name|NICE_NAME
block|,
name|NICE_name
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
comment|/* --pidfile */
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
name|PIDFILE_DESC
block|,
name|PIDFILE_NAME
block|,
name|PIDFILE_name
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
comment|/* --priority */
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
name|PRIORITY_DESC
block|,
name|PRIORITY_NAME
block|,
name|PRIORITY_name
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
comment|/* --quit */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aQuitCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|QUIT_DESC
block|,
name|QUIT_NAME
block|,
name|QUIT_name
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
comment|/* --propagationdelay */
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
name|PROPAGATIONDELAY_DESC
block|,
name|PROPAGATIONDELAY_NAME
block|,
name|PROPAGATIONDELAY_name
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
name|VALUE_OPT_SAVECONFIGQUIT
block|,
comment|/* equiv idx, value */
literal|22
block|,
name|VALUE_OPT_SAVECONFIGQUIT
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
name|SAVECONFIGQUIT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --saveconfigquit */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aSaveconfigquitCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|SAVECONFIGQUIT_DESC
block|,
name|SAVECONFIGQUIT_NAME
block|,
name|SAVECONFIGQUIT_name
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
comment|/* --statsdir */
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
name|STATSDIR_DESC
block|,
name|STATSDIR_NAME
block|,
name|STATSDIR_name
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
comment|/* --trustedkey */
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
name|TRUSTEDKEY_DESC
block|,
name|TRUSTEDKEY_NAME
block|,
name|TRUSTEDKEY_name
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
comment|/* --user */
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
name|USER_DESC
block|,
name|USER_NAME
block|,
name|USER_name
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
name|VALUE_OPT_UPDATEINTERVAL
block|,
comment|/* equiv idx, value */
literal|26
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
comment|/* --updateinterval */
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
name|UPDATEINTERVAL_DESC
block|,
name|UPDATEINTERVAL_NAME
block|,
name|UPDATEINTERVAL_name
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
name|VALUE_OPT_VAR
block|,
comment|/* equiv idx, value */
literal|27
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
comment|/* --var */
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
name|VAR_DESC
block|,
name|VAR_NAME
block|,
name|VAR_name
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
name|VALUE_OPT_DVAR
block|,
comment|/* equiv idx, value */
literal|28
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
comment|/* --dvar */
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
name|DVAR_DESC
block|,
name|DVAR_NAME
block|,
name|DVAR_name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|29
block|,
name|VALUE_OPT_WAIT_SYNC
block|,
comment|/* equiv idx, value */
literal|29
block|,
name|VALUE_OPT_WAIT_SYNC
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
name|WAIT_SYNC_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --wait-sync */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|aWait_SyncCantList
block|,
comment|/* option proc      */
name|optionNumericVal
block|,
comment|/* desc, NAME, name */
name|WAIT_SYNC_DESC
block|,
name|WAIT_SYNC_NAME
block|,
name|WAIT_SYNC_name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|30
block|,
name|VALUE_OPT_SLEW
block|,
comment|/* equiv idx, value */
literal|30
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
literal|31
block|,
name|VALUE_OPT_USEPCC
block|,
comment|/* equiv idx, value */
literal|31
block|,
name|VALUE_OPT_USEPCC
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
name|USEPCC_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --usepcc */
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
name|USEPCC_DESC
block|,
name|USEPCC_NAME
block|,
name|USEPCC_name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|32
block|,
name|VALUE_OPT_PCCFREQ
block|,
comment|/* equiv idx, value */
literal|32
block|,
name|VALUE_OPT_PCCFREQ
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
name|PCCFREQ_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --pccfreq */
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
name|PCCFREQ_DESC
block|,
name|PCCFREQ_NAME
block|,
name|PCCFREQ_name
block|,
comment|/* disablement strs */
name|NULL
block|,
name|NULL
block|}
block|,
block|{
comment|/* entry idx, value */
literal|33
block|,
name|VALUE_OPT_MDNS
block|,
comment|/* equiv idx, value */
literal|33
block|,
name|VALUE_OPT_MDNS
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
name|MDNS_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --mdns */
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
name|MDNS_DESC
block|,
name|MDNS_NAME
block|,
name|MDNS_name
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
block|}
decl_stmt|;
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/** Reference to the upper cased version of ntpd. */
define|#
directive|define
name|zPROGNAME
value|(ntpd_opt_strs+2876)
comment|/** Reference to the title line for ntpd usage. */
define|#
directive|define
name|zUsageTitle
value|(ntpd_opt_strs+2881)
comment|/** There is no ntpd configuration file. */
define|#
directive|define
name|zRcName
value|NULL
comment|/** There are no directories to search for ntpd config files. */
define|#
directive|define
name|apzHomeList
value|NULL
comment|/** The ntpd program bug email address. */
define|#
directive|define
name|zBugsAddr
value|(ntpd_opt_strs+3012)
comment|/** Clarification/explanation of what ntpd does. */
define|#
directive|define
name|zExplain
value|(ntpd_opt_strs+3046)
comment|/** Extra detail explaining what ntpd does. */
define|#
directive|define
name|zDetail
value|(NULL)
comment|/** The full version string for ntpd. */
define|#
directive|define
name|zFullVersion
value|(ntpd_opt_strs+3048)
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
name|ntpd_full_usage
value|(NULL)
define|#
directive|define
name|ntpd_short_usage
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
name|NTPD_EXIT_SUCCESS
expr_stmt|;
name|optionUsage
argument_list|(
operator|&
name|ntpdOptions
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
comment|/**  * Code to handle the debug-level option.  *  * @param[in] pOptions the ntpd options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
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
comment|/**  * The directory containing the data associated with ntpd.  */
ifndef|#
directive|ifndef
name|PKGDATADIR
define|#
directive|define
name|PKGDATADIR
value|""
endif|#
directive|endif
comment|/**  * Information about the person or institution that packaged ntpd  * for the current distribution.  */
ifndef|#
directive|ifndef
name|WITH_PACKAGER
define|#
directive|define
name|ntpd_packager_info
value|NULL
else|#
directive|else
comment|/** Packager information for ntpd. */
specifier|static
name|char
specifier|const
name|ntpd_packager_info
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
literal|"\nReport ntpd bugs to "
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
comment|/**  * The option definitions for ntpd.  The one structure that  * binds them all.  */
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
name|NO_EQUIVALENT
block|,
comment|/* save option index */
name|NO_EQUIVALENT
block|,
comment|/* '-#' option index */
name|NO_EQUIVALENT
comment|/* index of default opt */
block|}
block|,
literal|37
comment|/* full option count */
block|,
literal|34
comment|/* user option count */
block|,
name|ntpd_full_usage
block|,
name|ntpd_short_usage
block|,
name|NULL
block|,
name|NULL
block|,
name|PKGDATADIR
block|,
name|ntpd_packager_info
block|}
decl_stmt|;
if|#
directive|if
name|ENABLE_NLS
comment|/**  * This code is designed to translate translatable option text for the  * ntpd program.  These translations happen upon entry  * to optionProcess().  */
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
name|NTPD_EXIT_FAILURE
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
comment|/**  * Translate all the translatable strings in the ntpdOptions  * structure defined above.  This is done only once.  */
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
name|ntpdOptions
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
comment|/* TRANSLATORS:       The following dummy function was crated solely so that xgettext can      extract the correct strings.  These strings are actually referenced      by a field name in the ntpdOptions structure noted in the      comments below.  The literal text is defined in ntpd_opt_strs.          NOTE: the strings below are segmented with respect to the source string      ntpd_opt_strs.  The strings above are handed off for translation      at run time a paragraph at a time.  Consequently, they are presented here      for translation a paragraph at a time.          ALSO: often the description for an option will reference another option      by name.  These are set off with apostrophe quotes (I hope).  Do not      translate option names.    */
comment|/* referenced via ntpdOptions.pzCopyright */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpd 4.2.8p1\n\ Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.\n\ This is free software. It is licensed for use, modification and\n\ redistribution under the terms of the NTP License, copies of which\n\ can be seen at:\n"
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
comment|/* referenced via ntpdOptions.pzCopyNotice */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Permission to use, copy, modify, and distribute this software and its\n\ documentation for any purpose with or without fee is hereby granted,\n\ provided that the above copyright notice appears in all copies and that\n\ both the copyright notice and this permission notice appear in supporting\n\ documentation, and that the name The University of Delaware not be used in\n\ advertising or publicity pertaining to distribution of the software without\n\ specific, written prior permission.  The University of Delaware and Network\n\ Time Foundation makes no representations about the suitability this\n\ software for any purpose.  It is provided \"as is\" without express or\n\ implied warranty.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv4 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force IPv6 DNS name resolution"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Require crypto authentication"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Do not require crypto authentication"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Allow us to sync to broadcast servers"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"configuration file name"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Increase debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Set the debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"frequency drift file name"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Allow the first adjustment to be Big"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Jail directory"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"built without --enable-clockctl or --enable-linuxcaps or --enable-solarisprivs"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Listen on an interface name or address"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"path to symmetric keys"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"path to the log file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Do not listen to virtual interfaces"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Modify Multimedia Timer (Windows only)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Do not fork"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Run at high priority"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"path to the PID file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Process priority"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Set the time and quit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Broadcast/propagation delay"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Save parsed configuration and quit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Statistics file location"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Trusted key number"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Run as userid (or userid:groupid)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"built without --enable-clockctl or --enable-linuxcaps or --enable-solarisprivs"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"interval in seconds between scans for new or dropped interfaces"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"make ARG an ntp variable (RW)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"make ARG an ntp variable (RW|DEF)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Seconds to wait for first clock sync"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Slew up to 600 seconds"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Use CPU cycle counter (Windows only)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Force CPU cycle counter use (Windows only)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Register with mDNS as a NTP server"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"display extended usage information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"extended usage information passed thru pager"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"output version information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pzUsageTitle */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpd - NTP daemon program - Ver. 4.2.8p1\n\ Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \\\n\ \t\t[<server1> ...<serverN> ]\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pzExplain */
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pzFullVersion */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntpd 4.2.8p1"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pzFullUsage */
name|puts
argument_list|(
name|_
argument_list|(
literal|"<<<NOT-FOUND>>>"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntpdOptions.pzShortUsage */
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
comment|/* ntpd-opts.c ends here */
end_comment

end_unit

