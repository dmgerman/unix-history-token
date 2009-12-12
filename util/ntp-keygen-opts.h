begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntp-keygen-opts.h)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:55 AM EST  *  From the definitions    ntp-keygen-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This header file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntp-keygen author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntp-keygen copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
end_comment

begin_comment
comment|/*  *  This file contains the programmatic interface to the Automated  *  Options generated for the ntp-keygen program.  *  These macros are documented in the AutoGen info file in the  *  "AutoOpts" chapter.  Please refer to that doc for usage help.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUTOOPTS_NTP_KEYGEN_OPTS_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AUTOOPTS_NTP_KEYGEN_OPTS_H_GUARD
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
name|INDEX_OPT_CERTIFICATE
operator|=
literal|0
block|,
name|INDEX_OPT_DEBUG_LEVEL
operator|=
literal|1
block|,
name|INDEX_OPT_SET_DEBUG_LEVEL
operator|=
literal|2
block|,
name|INDEX_OPT_ID_KEY
operator|=
literal|3
block|,
name|INDEX_OPT_GQ_PARAMS
operator|=
literal|4
block|,
name|INDEX_OPT_GQ_KEYS
operator|=
literal|5
block|,
name|INDEX_OPT_HOST_KEY
operator|=
literal|6
block|,
name|INDEX_OPT_IFFKEY
operator|=
literal|7
block|,
name|INDEX_OPT_ISSUER_NAME
operator|=
literal|8
block|,
name|INDEX_OPT_MD5KEY
operator|=
literal|9
block|,
name|INDEX_OPT_MODULUS
operator|=
literal|10
block|,
name|INDEX_OPT_PVT_CERT
operator|=
literal|11
block|,
name|INDEX_OPT_PVT_PASSWD
operator|=
literal|12
block|,
name|INDEX_OPT_GET_PVT_PASSWD
operator|=
literal|13
block|,
name|INDEX_OPT_SIGN_KEY
operator|=
literal|14
block|,
name|INDEX_OPT_SUBJECT_NAME
operator|=
literal|15
block|,
name|INDEX_OPT_TRUSTED_CERT
operator|=
literal|16
block|,
name|INDEX_OPT_MV_PARAMS
operator|=
literal|17
block|,
name|INDEX_OPT_MV_KEYS
operator|=
literal|18
block|,
name|INDEX_OPT_VERSION
operator|=
literal|19
block|,
name|INDEX_OPT_HELP
operator|=
literal|20
block|,
name|INDEX_OPT_MORE_HELP
operator|=
literal|21
block|,
name|INDEX_OPT_SAVE_OPTS
operator|=
literal|22
block|,
name|INDEX_OPT_LOAD_OPTS
operator|=
literal|23
block|}
name|teOptIndex
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|OPTION_CT
value|24
end_define

begin_define
define|#
directive|define
name|NTP_KEYGEN_VERSION
value|"4.2.4p8"
end_define

begin_define
define|#
directive|define
name|NTP_KEYGEN_FULL_VERSION
value|"ntp-keygen (ntp) - Create a NTP host key - Ver. 4.2.4p8"
end_define

begin_comment
comment|/*  *  Interface defines for all options.  Replace "n" with the UPPER_CASED  *  option name (as in the teOptIndex enumeration above).  *  e.g. HAVE_OPT( CERTIFICATE )  */
end_comment

begin_define
define|#
directive|define
name|DESC
parameter_list|(
name|n
parameter_list|)
value|(ntp_keygenOptions.pOptDesc[INDEX_OPT_## n])
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
name|CERTIFICATE
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining CERTIFICATE due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|CERTIFICATE
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
name|ID_KEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining ID_KEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|ID_KEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GQ_PARAMS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining GQ_PARAMS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|GQ_PARAMS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GQ_KEYS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining GQ_KEYS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|GQ_KEYS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_KEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining HOST_KEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|HOST_KEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|IFFKEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining IFFKEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|IFFKEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ISSUER_NAME
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining ISSUER_NAME due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|ISSUER_NAME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MD5KEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MD5KEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MD5KEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MODULUS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MODULUS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MODULUS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PVT_CERT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PVT_CERT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PVT_CERT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PVT_PASSWD
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining PVT_PASSWD due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|PVT_PASSWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GET_PVT_PASSWD
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining GET_PVT_PASSWD due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|GET_PVT_PASSWD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIGN_KEY
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SIGN_KEY due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SIGN_KEY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SUBJECT_NAME
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining SUBJECT_NAME due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|SUBJECT_NAME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUSTED_CERT
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining TRUSTED_CERT due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|TRUSTED_CERT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MV_PARAMS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MV_PARAMS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MV_PARAMS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MV_KEYS
end_ifdef

begin_warning
warning|#
directive|warning
warning|undefining MV_KEYS due to option name conflict
end_warning

begin_undef
undef|#
directive|undef
name|MV_KEYS
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
name|CERTIFICATE
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
name|ID_KEY
end_undef

begin_undef
undef|#
directive|undef
name|GQ_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|GQ_KEYS
end_undef

begin_undef
undef|#
directive|undef
name|HOST_KEY
end_undef

begin_undef
undef|#
directive|undef
name|IFFKEY
end_undef

begin_undef
undef|#
directive|undef
name|ISSUER_NAME
end_undef

begin_undef
undef|#
directive|undef
name|MD5KEY
end_undef

begin_undef
undef|#
directive|undef
name|MODULUS
end_undef

begin_undef
undef|#
directive|undef
name|PVT_CERT
end_undef

begin_undef
undef|#
directive|undef
name|PVT_PASSWD
end_undef

begin_undef
undef|#
directive|undef
name|GET_PVT_PASSWD
end_undef

begin_undef
undef|#
directive|undef
name|SIGN_KEY
end_undef

begin_undef
undef|#
directive|undef
name|SUBJECT_NAME
end_undef

begin_undef
undef|#
directive|undef
name|TRUSTED_CERT
end_undef

begin_undef
undef|#
directive|undef
name|MV_PARAMS
end_undef

begin_undef
undef|#
directive|undef
name|MV_KEYS
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

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_CERTIFICATE
value|'c'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_ID_KEY
value|'e'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_GQ_PARAMS
value|'G'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_GQ_KEYS
value|'g'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_HOST_KEY
value|'H'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_IFFKEY
value|'I'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_ISSUER_NAME
value|'i'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_define
define|#
directive|define
name|VALUE_OPT_MD5KEY
value|'M'
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_MODULUS
value|'m'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_MODULUS
value|(DESC(MODULUS).optArg.argInt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_PVT_CERT
value|'P'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_PVT_PASSWD
value|'p'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_GET_PVT_PASSWD
value|'q'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_SIGN_KEY
value|'S'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_SUBJECT_NAME
value|'s'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_TRUSTED_CERT
value|'T'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_MV_PARAMS
value|'V'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_MV_PARAMS
value|(DESC(MV_PARAMS).optArg.argInt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL
end_ifdef

begin_define
define|#
directive|define
name|VALUE_OPT_MV_KEYS
value|'v'
end_define

begin_define
define|#
directive|define
name|OPT_VALUE_MV_KEYS
value|(DESC(MV_KEYS).optArg.argInt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL */
end_comment

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
value|STMTS( ntp_keygenOptions.fOptSet&= ~OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|ERRSTOP_OPTERR
value|STMTS( ntp_keygenOptions.fOptSet |= OPTPROC_ERRSTOP )
end_define

begin_define
define|#
directive|define
name|RESTART_OPT
parameter_list|(
name|n
parameter_list|)
value|STMTS( \                 ntp_keygenOptions.curOptIdx = (n); \                 ntp_keygenOptions.pzCurOpt  = NULL )
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
value|(*ntp_keygenOptions.pUsageProc)(&ntp_keygenOptions, c )
end_define

begin_comment
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/opthead.tpl near line 360 */
end_comment

begin_comment
comment|/* * * * * *  *  *  Declare the ntp-keygen option descriptor.  */
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
name|ntp_keygenOptions
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
comment|/* AUTOOPTS_NTP_KEYGEN_OPTS_H_GUARD */
end_comment

begin_comment
comment|/* ntp-keygen-opts.h ends here */
end_comment

end_unit

