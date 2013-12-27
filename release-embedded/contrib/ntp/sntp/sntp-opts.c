begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (sntp-opts.c)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:49 AM EST  *  From the definitions    sntp-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This source file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  sntp author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * sntp copyright 1970-2006 ntp.org - all rights reserved  *  *         General Public Licence for the software known as MSNTP  *         ------------------------------------------------------  *   * 	  (c) Copyright, N.M. Maclaren, 1996, 1997, 2000  * 	  (c) Copyright, University of Cambridge, 1996, 1997, 2000  *   *   *   * Free use of MSNTP in source and binary forms is permitted, provided that this  * entire licence is duplicated in all copies, and that any documentation,  * announcements, and other materials related to use acknowledge that the software  * was developed by N.M. Maclaren (hereafter refered to as the Author) at the  * University of Cambridge.  Neither the name of the Author nor the University of  * Cambridge may be used to endorse or promote products derived from this material  * without specific prior written permission.  *   * The Author and the University of Cambridge retain the copyright and all other  * legal rights to the software and make it available non-exclusively.  All users  * must ensure that the software in all its derivations carries a copyright notice  * in the form:  * 	  (c) Copyright N.M. Maclaren,  * 	  (c) Copyright University of Cambridge.  *   *   *   *                            NO WARRANTY  *   * Because the MSNTP software is licensed free of charge, the Author and the  * University of Cambridge provide absolutely no warranty, either expressed or  * implied, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose.  The entire risk as to  * the quality and performance of the MSNTP software is with you.  Should MSNTP  * prove defective, you assume the cost of all necessary servicing or repair.  *   * In no event, unless required by law, will the Author or the University of  * Cambridge, or any other party who may modify and redistribute this software as  * permitted in accordance with the provisions below, be liable for damages for  * any losses whatsoever, including but not limited to lost profits, lost monies,  * lost or corrupted data, or other special, incidental or consequential losses  * that may arise out of the use or inability to use the MSNTP software.  *   *   *   *                          COPYING POLICY  *   * Permission is hereby granted for copying and distribution of copies of the  * MSNTP source and binary files, and of any part thereof, subject to the  * following licence conditions:  *   * 1. You may distribute MSNTP or components of MSNTP, with or without additions  * developed by you or by others.  No charge, other than an "at-cost" distribution  * fee, may be charged for copies, derivations, or distributions of this material  * without the express written consent of the copyright holders.  *   * 2. You may also distribute MSNTP along with any other product for sale,  * provided that the cost of the bundled package is the same regardless of whether  * MSNTP is included or not, and provided that those interested only in MSNTP must  * be notified that it is a product freely available from the University of  * Cambridge.  *   * 3. If you distribute MSNTP software or parts of MSNTP, with or without  * additions developed by you or others, then you must either make available the  * source to all portions of the MSNTP system (exclusive of any additions made by  * you or by others) upon request, or instead you may notify anyone requesting  * source that it is freely available from the University of Cambridge.  *   * 4. You may not omit any of the copyright notices on either the source files,  * the executable files, or the documentation.  *   * 5. You may not omit transmission of this License agreement with whatever  * portions of MSNTP that are distributed.  *   * 6. Any users of this software must be notified that it is without warranty or  * guarantee of any nature, express or implied, nor is there any fitness for use  * represented.  *   *   * October 1996  * April 1997  * October 2000  */
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
name|tSCC
name|zCopyright
index|[]
init|=
literal|"sntp copyright (c) 1970-2006 ntp.org, all rights reserved"
decl_stmt|;
name|tSCC
name|zCopyrightNotice
index|[]
init|=
comment|/* extracted from sntp-opts.def near line 12 */
literal|"        General Public Licence for the software known as MSNTP\n\         ------------------------------------------------------\n\n\ \t  (c) Copyright, N.M. Maclaren, 1996, 1997, 2000\n\ \t  (c) Copyright, University of Cambridge, 1996, 1997, 2000\n\n\n\n\ Free use of MSNTP in source and binary forms is permitted, provided that this\n\ entire licence is duplicated in all copies, and that any documentation,\n\ announcements, and other materials related to use acknowledge that the software\n\ was developed by N.M. Maclaren (hereafter refered to as the Author) at the\n\ University of Cambridge.  Neither the name of the Author nor the University of\n\ Cambridge may be used to endorse or promote products derived from this material\n\ without specific prior written permission.\n\n\ The Author and the University of Cambridge retain the copyright and all other\n\ legal rights to the software and make it available non-exclusively.  All users\n\ must ensure that the software in all its derivations carries a copyright notice\n\ in the form:\n\ \t  (c) Copyright N.M. Maclaren,\n\ \t  (c) Copyright University of Cambridge.\n\n\n\n\                            NO WARRANTY\n\n\ Because the MSNTP software is licensed free of charge, the Author and the\n\ University of Cambridge provide absolutely no warranty, either expressed or\n\ implied, including, but not limited to, the implied warranties of\n\ merchantability and fitness for a particular purpose.  The entire risk as to\n\ the quality and performance of the MSNTP software is with you.  Should MSNTP\n\ prove defective, you assume the cost of all necessary servicing or repair.\n\n\ In no event, unless required by law, will the Author or the University of\n\ Cambridge, or any other party who may modify and redistribute this software as\n\ permitted in accordance with the provisions below, be liable for damages for\n\ any losses whatsoever, including but not limited to lost profits, lost monies,\n\ lost or corrupted data, or other special, incidental or consequential losses\n\ that may arise out of the use or inability to use the MSNTP software.\n\n\n\n\                          COPYING POLICY\n\n\ Permission is hereby granted for copying and distribution of copies of the\n\ MSNTP source and binary files, and of any part thereof, subject to the\n\ following licence conditions:\n\n\ 1. You may distribute MSNTP or components of MSNTP, with or without additions\n\ developed by you or by others.  No charge, other than an \"at-cost\" distribution\n\ fee, may be charged for copies, derivations, or distributions of this material\n\ without the express written consent of the copyright holders.\n\n\ 2. You may also distribute MSNTP along with any other product for sale,\n\ provided that the cost of the bundled package is the same regardless of whether\n\ MSNTP is included or not, and provided that those interested only in MSNTP must\n\ be notified that it is a product freely available from the University of\n\ Cambridge.\n\n\ 3. If you distribute MSNTP software or parts of MSNTP, with or without\n\ additions developed by you or others, then you must either make available the\n\ source to all portions of the MSNTP system (exclusive of any additions made by\n\ you or by others) upon request, or instead you may notify anyone requesting\n\ source that it is freely available from the University of Cambridge.\n\n\ 4. You may not omit any of the copyright notices on either the source files,\n\ the executable files, or the documentation.\n\n\ 5. You may not omit transmission of this License agreement with whatever\n\ portions of MSNTP that are distributed.\n\n\ 6. Any users of this software must be notified that it is without warranty or\n\ guarantee of any nature, express or implied, nor is there any fitness for use\n\ represented.\n\n\n\ October 1996\n\ April 1997\n\ October 2000"
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
comment|/*  *  Unprivport option description:  */
name|tSCC
name|zUnprivportText
index|[]
init|=
literal|"Use an unprivileged port"
decl_stmt|;
name|tSCC
name|zUnprivport_NAME
index|[]
init|=
literal|"UNPRIVPORT"
decl_stmt|;
name|tSCC
name|zUnprivport_Name
index|[]
init|=
literal|"unprivport"
decl_stmt|;
define|#
directive|define
name|UNPRIVPORT_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Normalverbose option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zNormalverboseText
index|[]
init|=
literal|"Slightly verbose"
decl_stmt|;
name|tSCC
name|zNormalverbose_NAME
index|[]
init|=
literal|"NORMALVERBOSE"
decl_stmt|;
name|tSCC
name|zNormalverbose_Name
index|[]
init|=
literal|"normalverbose"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aNormalverboseCantList
index|[]
init|=
block|{
name|INDEX_OPT_EXTRAVERBOSE
block|,
name|INDEX_OPT_MEGAVERBOSE
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|NORMALVERBOSE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Extraverbose option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zExtraverboseText
index|[]
init|=
literal|"Extra verbose"
decl_stmt|;
name|tSCC
name|zExtraverbose_NAME
index|[]
init|=
literal|"EXTRAVERBOSE"
decl_stmt|;
name|tSCC
name|zExtraverbose_Name
index|[]
init|=
literal|"extraverbose"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aExtraverboseCantList
index|[]
init|=
block|{
name|INDEX_OPT_NORMALVERBOSE
block|,
name|INDEX_OPT_MEGAVERBOSE
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|EXTRAVERBOSE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Megaverbose option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zMegaverboseText
index|[]
init|=
literal|"Mega verbose"
decl_stmt|;
name|tSCC
name|zMegaverbose_NAME
index|[]
init|=
literal|"MEGAVERBOSE"
decl_stmt|;
name|tSCC
name|zMegaverbose_Name
index|[]
init|=
literal|"megaverbose"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aMegaverboseCantList
index|[]
init|=
block|{
name|INDEX_OPT_NORMALVERBOSE
block|,
name|INDEX_OPT_EXTRAVERBOSE
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|MEGAVERBOSE_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Settimeofday option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zSettimeofdayText
index|[]
init|=
literal|"Set (step) the time with settimeofday()"
decl_stmt|;
name|tSCC
name|zSettimeofday_NAME
index|[]
init|=
literal|"SETTIMEOFDAY"
decl_stmt|;
name|tSCC
name|zSettimeofday_Name
index|[]
init|=
literal|"settimeofday"
decl_stmt|;
specifier|static
specifier|const
name|int
name|aSettimeofdayCantList
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
name|SETTIMEOFDAY_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Adjtime option description with  *  "Must also have options" and "Incompatible options":  */
name|tSCC
name|zAdjtimeText
index|[]
init|=
literal|"Set (slew) the time with adjtime()"
decl_stmt|;
name|tSCC
name|zAdjtime_NAME
index|[]
init|=
literal|"ADJTIME"
decl_stmt|;
name|tSCC
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
name|INDEX_OPT_SETTIMEOFDAY
block|,
name|NO_EQUIVALENT
block|}
decl_stmt|;
define|#
directive|define
name|ADJTIME_FLAGS
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
if|#
directive|if
name|defined
argument_list|(
name|TEST_SNTP_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
specifier|extern
name|tOptProc
name|optionPagedUsage
decl_stmt|,
name|optionVersionStderr
decl_stmt|;
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
name|optionPagedUsage
decl_stmt|,
name|optionPrintVersion
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
name|VALUE_OPT_UNPRIVPORT
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_UNPRIVPORT
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
name|UNPRIVPORT_FLAGS
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
name|zUnprivportText
block|,
name|zUnprivport_NAME
block|,
name|zUnprivport_Name
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
name|VALUE_OPT_NORMALVERBOSE
block|,
comment|/* equiv idx, value */
literal|3
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
name|aNormalverboseCantList
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
literal|4
block|,
name|VALUE_OPT_EXTRAVERBOSE
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_EXTRAVERBOSE
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
name|EXTRAVERBOSE_FLAGS
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
name|aExtraverboseCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zExtraverboseText
block|,
name|zExtraverbose_NAME
block|,
name|zExtraverbose_Name
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
name|VALUE_OPT_MEGAVERBOSE
block|,
comment|/* equiv idx, value */
literal|5
block|,
name|VALUE_OPT_MEGAVERBOSE
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
name|MEGAVERBOSE_FLAGS
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
name|aMegaverboseCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zMegaverboseText
block|,
name|zMegaverbose_NAME
block|,
name|zMegaverbose_Name
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
name|VALUE_OPT_SETTIMEOFDAY
block|,
comment|/* equiv idx, value */
literal|6
block|,
name|VALUE_OPT_SETTIMEOFDAY
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
name|SETTIMEOFDAY_FLAGS
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
name|aSettimeofdayCantList
block|,
comment|/* option proc      */
name|NULL
block|,
comment|/* desc, NAME, name */
name|zSettimeofdayText
block|,
name|zSettimeofday_NAME
block|,
name|zSettimeofday_Name
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
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Sntp Option Environment  */
name|tSCC
name|zPROGNAME
index|[]
init|=
literal|"SNTP"
decl_stmt|;
name|tSCC
name|zUsageTitle
index|[]
init|=
literal|"sntp - standard SNTP program - Ver. 4.2.4p8\n\ USAGE:  %s [ -<flag> | --<name> ]...\n"
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
literal|"\n\ .I sntp\n\ can be used as a SNTP client to query a NTP or SNTP server and either display\n\ the time or set the local system's time (given suitable privilege).  It can be\n\ run as an interactive command or in a\n\ .I cron\n\ job.\n\ NTP is the Network Time Protocol (RFC 1305) and SNTP is the\n\ Simple Network Time Protocol (RFC 2030, which supersedes RFC 1769).\n"
decl_stmt|;
name|tSCC
name|zFullVersion
index|[]
init|=
name|SNTP_FULL_VERSION
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
name|OPTPROC_NO_ARGS
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
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optmain.tpl near line 92 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_SNTP_OPTS
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
name|sntpOptions
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
name|sntpOptions
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* defined TEST_SNTP_OPTS */
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
value|coerce_it((void*)&(sntpOptions._f))
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
name|sntpOptions
operator|.
name|pOptDesc
decl_stmt|;
name|int
name|ix
init|=
name|sntpOptions
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
comment|/* sntp-opts.c ends here */
end_comment

end_unit

