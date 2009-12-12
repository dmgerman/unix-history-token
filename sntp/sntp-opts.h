begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (sntp-opts.h)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:49 AM EST  *  From the definitions    sntp-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This header file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  sntp author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * sntp copyright 1970-2006 ntp.org - all rights reserved  *  *         General Public Licence for the software known as MSNTP  *         ------------------------------------------------------  *   * 	  (c) Copyright, N.M. Maclaren, 1996, 1997, 2000  * 	  (c) Copyright, University of Cambridge, 1996, 1997, 2000  *   *   *   * Free use of MSNTP in source and binary forms is permitted, provided that this  * entire licence is duplicated in all copies, and that any documentation,  * announcements, and other materials related to use acknowledge that the software  * was developed by N.M. Maclaren (hereafter refered to as the Author) at the  * University of Cambridge.  Neither the name of the Author nor the University of  * Cambridge may be used to endorse or promote products derived from this material  * without specific prior written permission.  *   * The Author and the University of Cambridge retain the copyright and all other  * legal rights to the software and make it available non-exclusively.  All users  * must ensure that the software in all its derivations carries a copyright notice  * in the form:  * 	  (c) Copyright N.M. Maclaren,  * 	  (c) Copyright University of Cambridge.  *   *   *   *                            NO WARRANTY  *   * Because the MSNTP software is licensed free of charge, the Author and the  * University of Cambridge provide absolutely no warranty, either expressed or  * implied, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose.  The entire risk as to  * the quality and performance of the MSNTP software is with you.  Should MSNTP  * prove defective, you assume the cost of all necessary servicing or repair.  *   * In no event, unless required by law, will the Author or the University of  * Cambridge, or any other party who may modify and redistribute this software as  * permitted in accordance with the provisions below, be liable for damages for  * any losses whatsoever, including but not limited to lost profits, lost monies,  * lost or corrupted data, or other special, incidental or consequential losses  * that may arise out of the use or inability to use the MSNTP software.  *   *   *   *                          COPYING POLICY  *   * Permission is hereby granted for copying and distribution of copies of the  * MSNTP source and binary files, and of any part thereof, subject to the  * following licence conditions:  *   * 1. You may distribute MSNTP or components of MSNTP, with or without additions  * developed by you or by others.  No charge, other than an "at-cost" distribution  * fee, may be charged for copies, derivations, or distributions of this material  * without the express written consent of the copyright holders.  *   * 2. You may also distribute MSNTP along with any other product for sale,  * provided that the cost of the bundled package is the same regardless of whether  * MSNTP is included or not, and provided that those interested only in MSNTP must  * be notified that it is a product freely available from the University of  * Cambridge.  *   * 3. If you distribute MSNTP software or parts of MSNTP, with or without  * additions developed by you or others, then you must either make available the  * source to all portions of the MSNTP system (exclusive of any additions made by  * you or by others) upon request, or instead you may notify anyone requesting  * source that it is freely available from the University of Cambridge.  *   * 4. You may not omit any of the copyright notices on either the source files,  * the executable files, or the documentation.  *   * 5. You may not omit transmission of this License agreement with whatever  * portions of MSNTP that are distributed.  *   * 6. Any users of this software must be notified that it is without warranty or  * guarantee of any nature, express or implied, nor is there any fitness for use  * represented.  *   *   * October 1996  * April 1997  * October 2000  */
end_comment

begin_comment
comment|/*  *  This file contains the programmatic interface to the Automated  *  Options generated for the sntp program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_SNTP_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_SNTP_OPTS_H_GUARD
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
name|INDEX_OPT_UNPRIVPORT
operator|=
literal|2
block|,
name|INDEX_OPT_NORMALVERBOSE
operator|=
literal|3
block|,
name|INDEX_OPT_EXTRAVERBOSE
operator|=
literal|4
block|,
name|INDEX_OPT_MEGAVERBOSE
operator|=
literal|5
block|,
name|INDEX_OPT_SETTIMEOFDAY
operator|=
literal|6
block|,
name|INDEX_OPT_ADJTIME
operator|=
literal|7
block|,
name|INDEX_OPT_VERSION
operator|=
literal|8
block|,
name|INDEX_OPT_HELP
operator|=
literal|9
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|10
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|11
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|12
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|OPTION_CT
value|13
end_define

begin_define
define|#
directive|define
name|SNTP_VERSION
value|"4.2.4p8"
end_define

begin_define
define|#
directive|define
name|SNTP_FULL_VERSION
value|"sntp - standard SNTP program - Ver. 4.2.4p8"
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
value|(sntpOptions.pOptDesc[INDEX_OPT_## n])
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
name|UNPRIVPORT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining UNPRIVPORT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|UNPRIVPORT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NORMALVERBOSE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining NORMALVERBOSE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|NORMALVERBOSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXTRAVERBOSE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining EXTRAVERBOSE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|EXTRAVERBOSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MEGAVERBOSE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MEGAVERBOSE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MEGAVERBOSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SETTIMEOFDAY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SETTIMEOFDAY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SETTIMEOFDAY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ADJTIME
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining ADJTIME due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|ADJTIME
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
name|UNPRIVPORT
end_undef

begin_undef
undef|#
directive|undef
name|NORMALVERBOSE
end_undef

begin_undef
undef|#
directive|undef
name|EXTRAVERBOSE
end_undef

begin_undef
undef|#
directive|undef
name|MEGAVERBOSE
end_undef

begin_undef
undef|#
directive|undef
name|SETTIMEOFDAY
end_undef

begin_undef
undef|#
directive|undef
name|ADJTIME
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
name|VALUE_OPT_UNPRIVPORT
value|'u'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_NORMALVERBOSE
value|'v'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_EXTRAVERBOSE
value|'V'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_MEGAVERBOSE
value|'W'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_SETTIMEOFDAY
value|'r'
end_define

begin_define
define|#
directive|define
name|VALUE_OPT_ADJTIME
value|'a'
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
value|STMTS( sntpOptions.fOptSet&= ~OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS( sntpOptions.fOptSet |= OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 sntpOptions.curOptIdx = (n); \                 sntpOptions.pzCurOpt  = NULL )
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
value|(*sntpOptions.pUsageProc)(&sntpOptions, c )
end_define

begin_comment
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/opthead.tpl near line 360 */
end_comment

begin_comment
comment|/* * * * * *  *  *  Declare the sntp option descriptor.  */
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
name|sntpOptions
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
comment|/* AUTOOPTS_SNTP_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* sntp-opts.h ends here */
end_comment

end_unit

