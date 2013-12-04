begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (sntp-opts.c)  *    *  It has been AutoGen-ed  December 24, 2011 at 06:33:53 PM by AutoGen 5.12  *  From the definitions    sntp-opts.def  *  and the template file   options  *  * Generated from AutoOpts 35:0:10 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the sntp author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * This source file is copyrighted and licensed under the following terms:  *  *  see html/copyright.html  *    */
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
file|"sntp-opts.h"
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
literal|38
index|]
init|=
literal|"sntp 4.2.6p5\n\ see html/copyright.html\n"
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
comment|/*  *  Normalverbose option description:  */
specifier|static
name|char
specifier|const
name|zNormalverboseText
index|[]
init|=
literal|"Normal verbose"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNormalverbose_NAME
index|[]
init|=
literal|"NORMALVERBOSE"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zNormalverbose_Name
index|[]
init|=
literal|"normalverbose"
decl_stmt|;
define|#
directive|define
name|NORMALVERBOSE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Kod option description:  */
specifier|static
name|char
specifier|const
name|zKodText
index|[]
init|=
literal|"KoD history filename"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zKod_NAME
index|[]
init|=
literal|"KOD"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zKod_Name
index|[]
init|=
literal|"kod"
decl_stmt|;
define|#
directive|define
name|KOD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Syslog option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zSyslogText
index|[]
init|=
literal|"Logging with syslog"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSyslog_NAME
index|[]
init|=
literal|"SYSLOG"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSyslog_Name
index|[]
init|=
literal|"syslog"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aSyslogCantList
index|[]
init|=
block|{
name|INDEX_OPT_LOGFILE
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|SYSLOG_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Logfile option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zLogfileText
index|[]
init|=
literal|"Log to specified logfile"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zLogfile_NAME
index|[]
init|=
literal|"LOGFILE"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zLogfile_Name
index|[]
init|=
literal|"logfile"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aLogfileCantList
index|[]
init|=
block|{
name|INDEX_OPT_SYSLOG
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|LOGFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Settod option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zSettodText
index|[]
init|=
literal|"Set (step) the time with settimeofday()"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSettod_NAME
index|[]
init|=
literal|"SETTOD"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zSettod_Name
index|[]
init|=
literal|"settod"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aSettodCantList
index|[]
init|=
block|{
name|INDEX_OPT_ADJTIME
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|SETTOD_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Adjtime option description with  *  "Must also have options" and "Incompatible options":  */
specifier|static
name|char
specifier|const
name|zAdjtimeText
index|[]
init|=
literal|"Set (slew) the time with adjtime()"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zAdjtime_NAME
index|[]
init|=
literal|"ADJTIME"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zAdjtime_Name
index|[]
init|=
literal|"adjtime"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aAdjtimeCantList
index|[]
init|=
block|{
name|INDEX_OPT_SETTOD
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|ADJTIME_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Broadcast option description:  */
specifier|static
name|char
specifier|const
name|zBroadcastText
index|[]
init|=
literal|"Use broadcasts to the address specified for synchronisation"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zBroadcast_NAME
index|[]
init|=
literal|"BROADCAST"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zBroadcast_Name
index|[]
init|=
literal|"broadcast"
decl_stmt|;
define|#
directive|define
name|BROADCAST_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
comment|/*  *  Timeout option description:  */
specifier|static
name|char
specifier|const
name|zTimeoutText
index|[]
init|=
literal|"Specify the number of seconds to wait for broadcasts"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zTimeout_NAME
index|[]
init|=
literal|"TIMEOUT"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zTimeout_Name
index|[]
init|=
literal|"timeout"
decl_stmt|;
define|#
directive|define
name|zTimeoutDefaultArg
value|((char const*)68)
define|#
directive|define
name|TIMEOUT_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/*  *  Authentication option description:  */
specifier|static
name|char
specifier|const
name|zAuthenticationText
index|[]
init|=
literal|"Enable authentication with the key auth-keynumber"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zAuthentication_NAME
index|[]
init|=
literal|"AUTHENTICATION"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zAuthentication_Name
index|[]
init|=
literal|"authentication"
decl_stmt|;
define|#
directive|define
name|AUTHENTICATION_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/*  *  Keyfile option description:  */
specifier|static
name|char
specifier|const
name|zKeyfileText
index|[]
init|=
literal|"Specify a keyfile. SNTP will look in this file for the key specified with -a"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zKeyfile_NAME
index|[]
init|=
literal|"KEYFILE"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zKeyfile_Name
index|[]
init|=
literal|"keyfile"
decl_stmt|;
define|#
directive|define
name|KEYFILE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
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
name|TEST_SNTP_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
specifier|static
name|tOptProc
name|doUsageOpt
decl_stmt|;
else|#
directive|else
comment|/* NOT defined TEST_SNTP_OPTS */
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
name|doUsageOpt
decl_stmt|;
endif|#
directive|endif
comment|/* defined(TEST_SNTP_OPTS) */
ifdef|#
directive|ifdef
name|TEST_SNTP_OPTS
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
comment|/* TEST_SNTP_OPTS */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Sntp Option Descriptions.  */
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
name|VALUE_OPT_NORMALVERBOSE
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_NORMALVERBOSE
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
name|NORMALVERBOSE_FLAGS
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
name|zNormalverboseText
block|,
name|zNormalverbose_NAME
block|,
name|zNormalverbose_Name
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
name|VALUE_OPT_KOD
block|,
comment|/* equiv idx, value */
literal|3
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
name|zKodText
block|,
name|zKod_NAME
block|,
name|zKod_Name
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
name|VALUE_OPT_SYSLOG
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_SYSLOG
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
name|SYSLOG_FLAGS
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
name|aSyslogCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zSyslogText
block|,
name|zSyslog_NAME
block|,
name|zSyslog_Name
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
name|VALUE_OPT_LOGFILE
block|,
comment|/* equiv idx, value */
literal|5
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
name|aLogfileCantList
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
literal|6
block|,
name|VALUE_OPT_SETTOD
block|,
comment|/* equiv idx, value */
literal|6
block|,
name|VALUE_OPT_SETTOD
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
name|SETTOD_FLAGS
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
name|aSettodCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zSettodText
block|,
name|zSettod_NAME
block|,
name|zSettod_Name
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
name|VALUE_OPT_ADJTIME
block|,
comment|/* equiv idx, value */
literal|7
block|,
name|VALUE_OPT_ADJTIME
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
name|ADJTIME_FLAGS
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
name|aAdjtimeCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zAdjtimeText
block|,
name|zAdjtime_NAME
block|,
name|zAdjtime_Name
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
name|VALUE_OPT_BROADCAST
block|,
comment|/* equiv idx, value */
literal|8
block|,
name|VALUE_OPT_BROADCAST
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
name|BROADCAST_FLAGS
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
name|zBroadcastText
block|,
name|zBroadcast_NAME
block|,
name|zBroadcast_Name
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
name|VALUE_OPT_TIMEOUT
block|,
comment|/* equiv idx, value */
literal|9
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
name|zTimeoutDefaultArg
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
name|zTimeoutText
block|,
name|zTimeout_NAME
block|,
name|zTimeout_Name
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
name|VALUE_OPT_AUTHENTICATION
block|,
comment|/* equiv idx, value */
literal|10
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
name|zAuthenticationText
block|,
name|zAuthentication_NAME
block|,
name|zAuthentication_Name
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
name|VALUE_OPT_KEYFILE
block|,
comment|/* equiv idx, value */
literal|11
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
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Sntp Option Environment  */
specifier|static
name|char
specifier|const
name|zPROGNAME
index|[
literal|5
index|]
init|=
literal|"SNTP"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zUsageTitle
index|[
literal|152
index|]
init|=
literal|"sntp - standard Simple Network Time Protocol program - Ver. 4.2.6p5\n\ USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]... \\\n\ \t\t[ hostname-or-IP ...]\n"
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
specifier|static
name|char
specifier|const
name|zExplain
index|[]
init|=
literal|"\n\n"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zDetail
index|[
literal|352
index|]
init|=
literal|"\n\ sntp implements the Simple Network Time Protocol, and is used to query an\n\ NTP or SNTP server and either display the time or set the local system's\n\ time (given suitable privilege).\n\n\ It can be run interactively from the command line or as a cron job.\n\n\ NTP and SNTP are defined by RFC 5905, which obsoletes RFC 4330 and RFC\n\ 1305.\n"
decl_stmt|;
specifier|static
name|char
specifier|const
name|zFullVersion
index|[]
init|=
name|SNTP_FULL_VERSION
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
name|sntp_full_usage
value|NULL
define|#
directive|define
name|sntp_short_usage
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
name|sntp_packager_info
value|NULL
else|#
directive|else
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
literal|17
comment|/* full option count */
block|,
literal|12
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
name|SNTP_EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
comment|/* extracted from optmain.tlib near line 128 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_SNTP_OPTS
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
name|SNTP_EXIT_SUCCESS
decl_stmt|;
operator|(
name|void
operator|)
name|optionProcess
argument_list|(
operator|&
name|sntpOptions
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|optionPutShell
argument_list|(
operator|&
name|sntpOptions
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
comment|/* defined TEST_SNTP_OPTS */
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
name|SNTP_EXIT_FAILURE
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
name|sntpOptions
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
name|sntpOptions
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
comment|/* sntp-opts.c ends here */
end_comment

end_unit

