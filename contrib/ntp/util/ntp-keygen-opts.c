begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    *  EDIT THIS FILE WITH CAUTION  (ntp-keygen-opts.c)  *    *  It has been AutoGen-ed  Tuesday December  8, 2009 at 08:14:56 AM EST  *  From the definitions    ntp-keygen-opts.def  *  and the template file   options  *  * Generated from AutoOpts 29:0:4 templates.  */
end_comment

begin_comment
comment|/*  *  This file was produced by an AutoOpts template.  AutoOpts is a  *  copyrighted work.  This source file is not encumbered by AutoOpts  *  licensing, but is provided under the licensing terms chosen by the  *  ntp-keygen author or copyright holder.  AutoOpts is licensed under  *  the terms of the LGPL.  The redistributable library (``libopts'') is  *  licensed under the terms of either the LGPL or, at the users discretion,  *  the BSD license.  See the AutoOpts and/or libopts sources for details.  *  * This source file is copyrighted and licensed under the following terms:  *  * ntp-keygen copyright 1970-2009 David L. Mills and/or others - all rights reserved  *  * see html/copyright.html  */
end_comment

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

begin_define
define|#
directive|define
name|OPTION_CODE_COMPILE
value|1
end_define

begin_include
include|#
directive|include
file|"ntp-keygen-opts.h"
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
literal|"ntp-keygen copyright (c) 1970-2009 David L. Mills and/or others, all rights reserved"
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
include|#
directive|include
file|<stdlib.h>
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
comment|/*  *  Certificate option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zCertificateText
index|[]
init|=
literal|"certificate scheme"
decl_stmt|;
name|tSCC
name|zCertificate_NAME
index|[]
init|=
literal|"CERTIFICATE"
decl_stmt|;
name|tSCC
name|zCertificate_Name
index|[]
init|=
literal|"certificate"
decl_stmt|;
define|#
directive|define
name|CERTIFICATE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Certificate */
define|#
directive|define
name|VALUE_OPT_CERTIFICATE
value|NO_EQUIVALENT
define|#
directive|define
name|CERTIFICATE_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zCertificateText
value|NULL
define|#
directive|define
name|zCertificate_NAME
value|NULL
define|#
directive|define
name|zCertificate_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
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
comment|/*  *  Id_Key option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zId_KeyText
index|[]
init|=
literal|"Write identity keys"
decl_stmt|;
name|tSCC
name|zId_Key_NAME
index|[]
init|=
literal|"ID_KEY"
decl_stmt|;
name|tSCC
name|zId_Key_Name
index|[]
init|=
literal|"id-key"
decl_stmt|;
define|#
directive|define
name|ID_KEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Id_Key */
define|#
directive|define
name|VALUE_OPT_ID_KEY
value|NO_EQUIVALENT
define|#
directive|define
name|ID_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zId_KeyText
value|NULL
define|#
directive|define
name|zId_Key_NAME
value|NULL
define|#
directive|define
name|zId_Key_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Gq_Params option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zGq_ParamsText
index|[]
init|=
literal|"Generate GQ parameters and keys"
decl_stmt|;
name|tSCC
name|zGq_Params_NAME
index|[]
init|=
literal|"GQ_PARAMS"
decl_stmt|;
name|tSCC
name|zGq_Params_Name
index|[]
init|=
literal|"gq-params"
decl_stmt|;
define|#
directive|define
name|GQ_PARAMS_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Gq_Params */
define|#
directive|define
name|VALUE_OPT_GQ_PARAMS
value|NO_EQUIVALENT
define|#
directive|define
name|GQ_PARAMS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zGq_ParamsText
value|NULL
define|#
directive|define
name|zGq_Params_NAME
value|NULL
define|#
directive|define
name|zGq_Params_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Gq_Keys option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zGq_KeysText
index|[]
init|=
literal|"update GQ keys"
decl_stmt|;
name|tSCC
name|zGq_Keys_NAME
index|[]
init|=
literal|"GQ_KEYS"
decl_stmt|;
name|tSCC
name|zGq_Keys_Name
index|[]
init|=
literal|"gq-keys"
decl_stmt|;
define|#
directive|define
name|GQ_KEYS_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Gq_Keys */
define|#
directive|define
name|VALUE_OPT_GQ_KEYS
value|NO_EQUIVALENT
define|#
directive|define
name|GQ_KEYS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zGq_KeysText
value|NULL
define|#
directive|define
name|zGq_Keys_NAME
value|NULL
define|#
directive|define
name|zGq_Keys_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Host_Key option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zHost_KeyText
index|[]
init|=
literal|"generate RSA host key"
decl_stmt|;
name|tSCC
name|zHost_Key_NAME
index|[]
init|=
literal|"HOST_KEY"
decl_stmt|;
name|tSCC
name|zHost_Key_Name
index|[]
init|=
literal|"host-key"
decl_stmt|;
define|#
directive|define
name|HOST_KEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Host_Key */
define|#
directive|define
name|VALUE_OPT_HOST_KEY
value|NO_EQUIVALENT
define|#
directive|define
name|HOST_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zHost_KeyText
value|NULL
define|#
directive|define
name|zHost_Key_NAME
value|NULL
define|#
directive|define
name|zHost_Key_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Iffkey option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zIffkeyText
index|[]
init|=
literal|"generate IFF parameters"
decl_stmt|;
name|tSCC
name|zIffkey_NAME
index|[]
init|=
literal|"IFFKEY"
decl_stmt|;
name|tSCC
name|zIffkey_Name
index|[]
init|=
literal|"iffkey"
decl_stmt|;
define|#
directive|define
name|IFFKEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Iffkey */
define|#
directive|define
name|VALUE_OPT_IFFKEY
value|NO_EQUIVALENT
define|#
directive|define
name|IFFKEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zIffkeyText
value|NULL
define|#
directive|define
name|zIffkey_NAME
value|NULL
define|#
directive|define
name|zIffkey_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Issuer_Name option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zIssuer_NameText
index|[]
init|=
literal|"set issuer name"
decl_stmt|;
name|tSCC
name|zIssuer_Name_NAME
index|[]
init|=
literal|"ISSUER_NAME"
decl_stmt|;
name|tSCC
name|zIssuer_Name_Name
index|[]
init|=
literal|"issuer-name"
decl_stmt|;
define|#
directive|define
name|ISSUER_NAME_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Issuer_Name */
define|#
directive|define
name|VALUE_OPT_ISSUER_NAME
value|NO_EQUIVALENT
define|#
directive|define
name|ISSUER_NAME_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zIssuer_NameText
value|NULL
define|#
directive|define
name|zIssuer_Name_NAME
value|NULL
define|#
directive|define
name|zIssuer_Name_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Md5key option description:  */
name|tSCC
name|zMd5keyText
index|[]
init|=
literal|"generate MD5 keys"
decl_stmt|;
name|tSCC
name|zMd5key_NAME
index|[]
init|=
literal|"MD5KEY"
decl_stmt|;
name|tSCC
name|zMd5key_Name
index|[]
init|=
literal|"md5key"
decl_stmt|;
define|#
directive|define
name|MD5KEY_FLAGS
value|(OPTST_DISABLED)
comment|/*  *  Modulus option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zModulusText
index|[]
init|=
literal|"modulus"
decl_stmt|;
name|tSCC
name|zModulus_NAME
index|[]
init|=
literal|"MODULUS"
decl_stmt|;
name|tSCC
name|zModulus_Name
index|[]
init|=
literal|"modulus"
decl_stmt|;
define|#
directive|define
name|MODULUS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable Modulus */
define|#
directive|define
name|VALUE_OPT_MODULUS
value|NO_EQUIVALENT
define|#
directive|define
name|MODULUS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zModulusText
value|NULL
define|#
directive|define
name|zModulus_NAME
value|NULL
define|#
directive|define
name|zModulus_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Pvt_Cert option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zPvt_CertText
index|[]
init|=
literal|"generate PC private certificate"
decl_stmt|;
name|tSCC
name|zPvt_Cert_NAME
index|[]
init|=
literal|"PVT_CERT"
decl_stmt|;
name|tSCC
name|zPvt_Cert_Name
index|[]
init|=
literal|"pvt-cert"
decl_stmt|;
define|#
directive|define
name|PVT_CERT_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Pvt_Cert */
define|#
directive|define
name|VALUE_OPT_PVT_CERT
value|NO_EQUIVALENT
define|#
directive|define
name|PVT_CERT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zPvt_CertText
value|NULL
define|#
directive|define
name|zPvt_Cert_NAME
value|NULL
define|#
directive|define
name|zPvt_Cert_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Pvt_Passwd option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zPvt_PasswdText
index|[]
init|=
literal|"output private password"
decl_stmt|;
name|tSCC
name|zPvt_Passwd_NAME
index|[]
init|=
literal|"PVT_PASSWD"
decl_stmt|;
name|tSCC
name|zPvt_Passwd_Name
index|[]
init|=
literal|"pvt-passwd"
decl_stmt|;
define|#
directive|define
name|PVT_PASSWD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Pvt_Passwd */
define|#
directive|define
name|VALUE_OPT_PVT_PASSWD
value|NO_EQUIVALENT
define|#
directive|define
name|PVT_PASSWD_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zPvt_PasswdText
value|NULL
define|#
directive|define
name|zPvt_Passwd_NAME
value|NULL
define|#
directive|define
name|zPvt_Passwd_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Get_Pvt_Passwd option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zGet_Pvt_PasswdText
index|[]
init|=
literal|"input private password"
decl_stmt|;
name|tSCC
name|zGet_Pvt_Passwd_NAME
index|[]
init|=
literal|"GET_PVT_PASSWD"
decl_stmt|;
name|tSCC
name|zGet_Pvt_Passwd_Name
index|[]
init|=
literal|"get-pvt-passwd"
decl_stmt|;
define|#
directive|define
name|GET_PVT_PASSWD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Get_Pvt_Passwd */
define|#
directive|define
name|VALUE_OPT_GET_PVT_PASSWD
value|NO_EQUIVALENT
define|#
directive|define
name|GET_PVT_PASSWD_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zGet_Pvt_PasswdText
value|NULL
define|#
directive|define
name|zGet_Pvt_Passwd_NAME
value|NULL
define|#
directive|define
name|zGet_Pvt_Passwd_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Sign_Key option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zSign_KeyText
index|[]
init|=
literal|"generate sign key (RSA or DSA)"
decl_stmt|;
name|tSCC
name|zSign_Key_NAME
index|[]
init|=
literal|"SIGN_KEY"
decl_stmt|;
name|tSCC
name|zSign_Key_Name
index|[]
init|=
literal|"sign-key"
decl_stmt|;
define|#
directive|define
name|SIGN_KEY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Sign_Key */
define|#
directive|define
name|VALUE_OPT_SIGN_KEY
value|NO_EQUIVALENT
define|#
directive|define
name|SIGN_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zSign_KeyText
value|NULL
define|#
directive|define
name|zSign_Key_NAME
value|NULL
define|#
directive|define
name|zSign_Key_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Subject_Name option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zSubject_NameText
index|[]
init|=
literal|"set subject name"
decl_stmt|;
name|tSCC
name|zSubject_Name_NAME
index|[]
init|=
literal|"SUBJECT_NAME"
decl_stmt|;
name|tSCC
name|zSubject_Name_Name
index|[]
init|=
literal|"subject-name"
decl_stmt|;
define|#
directive|define
name|SUBJECT_NAME_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable Subject_Name */
define|#
directive|define
name|VALUE_OPT_SUBJECT_NAME
value|NO_EQUIVALENT
define|#
directive|define
name|SUBJECT_NAME_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zSubject_NameText
value|NULL
define|#
directive|define
name|zSubject_Name_NAME
value|NULL
define|#
directive|define
name|zSubject_Name_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Trusted_Cert option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zTrusted_CertText
index|[]
init|=
literal|"trusted certificate (TC scheme)"
decl_stmt|;
name|tSCC
name|zTrusted_Cert_NAME
index|[]
init|=
literal|"TRUSTED_CERT"
decl_stmt|;
name|tSCC
name|zTrusted_Cert_Name
index|[]
init|=
literal|"trusted-cert"
decl_stmt|;
define|#
directive|define
name|TRUSTED_CERT_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable Trusted_Cert */
define|#
directive|define
name|VALUE_OPT_TRUSTED_CERT
value|NO_EQUIVALENT
define|#
directive|define
name|TRUSTED_CERT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zTrusted_CertText
value|NULL
define|#
directive|define
name|zTrusted_Cert_NAME
value|NULL
define|#
directive|define
name|zTrusted_Cert_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Mv_Params option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zMv_ParamsText
index|[]
init|=
literal|"generate<num> MV parameters"
decl_stmt|;
name|tSCC
name|zMv_Params_NAME
index|[]
init|=
literal|"MV_PARAMS"
decl_stmt|;
name|tSCC
name|zMv_Params_Name
index|[]
init|=
literal|"mv-params"
decl_stmt|;
define|#
directive|define
name|MV_PARAMS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable Mv_Params */
define|#
directive|define
name|VALUE_OPT_MV_PARAMS
value|NO_EQUIVALENT
define|#
directive|define
name|MV_PARAMS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zMv_ParamsText
value|NULL
define|#
directive|define
name|zMv_Params_NAME
value|NULL
define|#
directive|define
name|zMv_Params_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
comment|/*  *  Mv_Keys option description:  */
ifdef|#
directive|ifdef
name|OPENSSL
name|tSCC
name|zMv_KeysText
index|[]
init|=
literal|"update<num> MV keys"
decl_stmt|;
name|tSCC
name|zMv_Keys_NAME
index|[]
init|=
literal|"MV_KEYS"
decl_stmt|;
name|tSCC
name|zMv_Keys_Name
index|[]
init|=
literal|"mv-keys"
decl_stmt|;
define|#
directive|define
name|MV_KEYS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable Mv_Keys */
define|#
directive|define
name|VALUE_OPT_MV_KEYS
value|NO_EQUIVALENT
define|#
directive|define
name|MV_KEYS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|zMv_KeysText
value|NULL
define|#
directive|define
name|zMv_Keys_NAME
value|NULL
define|#
directive|define
name|zMv_Keys_Name
value|NULL
endif|#
directive|endif
comment|/* OPENSSL */
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
ifdef|#
directive|ifdef
name|OPENSSL
specifier|static
name|tOptProc
name|doOptModulus
decl_stmt|;
else|#
directive|else
comment|/* not OPENSSL */
define|#
directive|define
name|doOptModulus
value|NULL
endif|#
directive|endif
comment|/* def/not OPENSSL */
ifdef|#
directive|ifdef
name|OPENSSL
specifier|extern
name|tOptProc
name|optionNumericVal
decl_stmt|;
else|#
directive|else
comment|/* not OPENSSL */
define|#
directive|define
name|optionNumericVal
value|NULL
endif|#
directive|endif
comment|/* def/not OPENSSL */
ifdef|#
directive|ifdef
name|OPENSSL
specifier|extern
name|tOptProc
name|optionNumericVal
decl_stmt|;
else|#
directive|else
comment|/* not OPENSSL */
define|#
directive|define
name|optionNumericVal
value|NULL
endif|#
directive|endif
comment|/* def/not OPENSSL */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTP_KEYGEN_OPTS
argument_list|)
comment|/*  *  Under test, omit argument processing, or call optionStackArg,  *  if multiple copies are allowed.  */
specifier|extern
name|tOptProc
name|optionNumericVal
decl_stmt|,
name|optionPagedUsage
decl_stmt|,
name|optionVersionStderr
decl_stmt|;
specifier|static
name|tOptProc
name|doOptModulus
decl_stmt|,
name|doUsageOpt
decl_stmt|;
comment|/*  *  #define map the "normal" callout procs to the test ones...  */
define|#
directive|define
name|SET_DEBUG_LEVEL_OPT_PROC
value|optionStackArg
else|#
directive|else
comment|/* NOT defined TEST_NTP_KEYGEN_OPTS */
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
comment|/* defined(TEST_NTP_KEYGEN_OPTS) */
ifdef|#
directive|ifdef
name|TEST_NTP_KEYGEN_OPTS
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
comment|/* TEST_NTP_KEYGEN_OPTS */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntp_Keygen Option Descriptions.  */
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
name|VALUE_OPT_CERTIFICATE
block|,
comment|/* equiv idx, value */
literal|0
block|,
name|VALUE_OPT_CERTIFICATE
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
name|CERTIFICATE_FLAGS
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
name|zCertificateText
block|,
name|zCertificate_NAME
block|,
name|zCertificate_Name
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
name|VALUE_OPT_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|1
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
literal|2
block|,
name|VALUE_OPT_SET_DEBUG_LEVEL
block|,
comment|/* equiv idx, value */
literal|2
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
literal|3
block|,
name|VALUE_OPT_ID_KEY
block|,
comment|/* equiv idx, value */
literal|3
block|,
name|VALUE_OPT_ID_KEY
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
name|ID_KEY_FLAGS
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
name|zId_KeyText
block|,
name|zId_Key_NAME
block|,
name|zId_Key_Name
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
name|VALUE_OPT_GQ_PARAMS
block|,
comment|/* equiv idx, value */
literal|4
block|,
name|VALUE_OPT_GQ_PARAMS
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
name|GQ_PARAMS_FLAGS
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
name|zGq_ParamsText
block|,
name|zGq_Params_NAME
block|,
name|zGq_Params_Name
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
name|VALUE_OPT_GQ_KEYS
block|,
comment|/* equiv idx, value */
literal|5
block|,
name|VALUE_OPT_GQ_KEYS
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
name|GQ_KEYS_FLAGS
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
name|zGq_KeysText
block|,
name|zGq_Keys_NAME
block|,
name|zGq_Keys_Name
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
name|VALUE_OPT_HOST_KEY
block|,
comment|/* equiv idx, value */
literal|6
block|,
name|VALUE_OPT_HOST_KEY
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
name|HOST_KEY_FLAGS
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
name|zHost_KeyText
block|,
name|zHost_Key_NAME
block|,
name|zHost_Key_Name
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
name|VALUE_OPT_IFFKEY
block|,
comment|/* equiv idx, value */
literal|7
block|,
name|VALUE_OPT_IFFKEY
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
name|IFFKEY_FLAGS
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
name|zIffkeyText
block|,
name|zIffkey_NAME
block|,
name|zIffkey_Name
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
name|VALUE_OPT_ISSUER_NAME
block|,
comment|/* equiv idx, value */
literal|8
block|,
name|VALUE_OPT_ISSUER_NAME
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
name|ISSUER_NAME_FLAGS
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
name|zIssuer_NameText
block|,
name|zIssuer_Name_NAME
block|,
name|zIssuer_Name_Name
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
name|VALUE_OPT_MD5KEY
block|,
comment|/* equiv idx, value */
literal|9
block|,
name|VALUE_OPT_MD5KEY
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
name|MD5KEY_FLAGS
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
name|zMd5keyText
block|,
name|zMd5key_NAME
block|,
name|zMd5key_Name
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
name|VALUE_OPT_MODULUS
block|,
comment|/* equiv idx, value */
literal|10
block|,
name|VALUE_OPT_MODULUS
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
name|MODULUS_FLAGS
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
name|doOptModulus
block|,
comment|/* desc, NAME, name */
name|zModulusText
block|,
name|zModulus_NAME
block|,
name|zModulus_Name
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
name|VALUE_OPT_PVT_CERT
block|,
comment|/* equiv idx, value */
literal|11
block|,
name|VALUE_OPT_PVT_CERT
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
name|PVT_CERT_FLAGS
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
name|zPvt_CertText
block|,
name|zPvt_Cert_NAME
block|,
name|zPvt_Cert_Name
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
name|VALUE_OPT_PVT_PASSWD
block|,
comment|/* equiv idx, value */
literal|12
block|,
name|VALUE_OPT_PVT_PASSWD
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
name|PVT_PASSWD_FLAGS
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
name|zPvt_PasswdText
block|,
name|zPvt_Passwd_NAME
block|,
name|zPvt_Passwd_Name
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
name|VALUE_OPT_GET_PVT_PASSWD
block|,
comment|/* equiv idx, value */
literal|13
block|,
name|VALUE_OPT_GET_PVT_PASSWD
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
name|GET_PVT_PASSWD_FLAGS
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
name|zGet_Pvt_PasswdText
block|,
name|zGet_Pvt_Passwd_NAME
block|,
name|zGet_Pvt_Passwd_Name
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
name|VALUE_OPT_SIGN_KEY
block|,
comment|/* equiv idx, value */
literal|14
block|,
name|VALUE_OPT_SIGN_KEY
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
name|SIGN_KEY_FLAGS
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
name|zSign_KeyText
block|,
name|zSign_Key_NAME
block|,
name|zSign_Key_Name
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
name|VALUE_OPT_SUBJECT_NAME
block|,
comment|/* equiv idx, value */
literal|15
block|,
name|VALUE_OPT_SUBJECT_NAME
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
name|SUBJECT_NAME_FLAGS
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
name|zSubject_NameText
block|,
name|zSubject_Name_NAME
block|,
name|zSubject_Name_Name
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
name|VALUE_OPT_TRUSTED_CERT
block|,
comment|/* equiv idx, value */
literal|16
block|,
name|VALUE_OPT_TRUSTED_CERT
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
name|TRUSTED_CERT_FLAGS
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
name|zTrusted_CertText
block|,
name|zTrusted_Cert_NAME
block|,
name|zTrusted_Cert_Name
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
name|VALUE_OPT_MV_PARAMS
block|,
comment|/* equiv idx, value */
literal|17
block|,
name|VALUE_OPT_MV_PARAMS
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
name|MV_PARAMS_FLAGS
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
name|zMv_ParamsText
block|,
name|zMv_Params_NAME
block|,
name|zMv_Params_Name
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
name|VALUE_OPT_MV_KEYS
block|,
comment|/* equiv idx, value */
literal|18
block|,
name|VALUE_OPT_MV_KEYS
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
name|MV_KEYS_FLAGS
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
name|zMv_KeysText
block|,
name|zMv_Keys_NAME
block|,
name|zMv_Keys_Name
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
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  *  *  Define the Ntp_Keygen Option Environment  */
name|tSCC
name|zPROGNAME
index|[]
init|=
literal|"NTP_KEYGEN"
decl_stmt|;
name|tSCC
name|zUsageTitle
index|[]
init|=
literal|"ntp-keygen (ntp) - Create a NTP host key - Ver. 4.2.4p8\n\ USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n"
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
literal|"\n\ If there is no new host key, look for an existing one.\n\ If one is not found, create it.\n"
decl_stmt|;
name|tSCC
name|zFullVersion
index|[]
init|=
name|NTP_KEYGEN_FULL_VERSION
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
name|ntp_keygenOptions
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
literal|24
comment|/* full option count */
block|,
literal|19
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
name|TEST_NTP_KEYGEN_OPTS
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
comment|/* defined(TEST_NTP_KEYGEN_OPTS) */
comment|/* * * * * * *  *  *   For the modulus option, when OPENSSL is #define-d.  */
ifdef|#
directive|ifdef
name|OPENSSL
specifier|static
name|void
name|doOptModulus
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
specifier|const
struct|struct
block|{
specifier|const
name|int
name|rmin
decl_stmt|,
name|rmax
decl_stmt|;
block|}
name|rng
index|[
literal|1
index|]
init|=
block|{
block|{
literal|256
block|,
literal|2048
block|}
block|}
struct|;
name|int
name|val
decl_stmt|;
name|int
name|ix
decl_stmt|;
name|char
specifier|const
modifier|*
name|pzIndent
init|=
literal|"\t\t\t\t  "
decl_stmt|;
specifier|extern
name|FILE
modifier|*
name|option_usage_fp
decl_stmt|;
if|if
condition|(
name|pOptDesc
operator|==
name|NULL
condition|)
comment|/* usage is requesting range list                              option_usage_fp has already been set */
goto|goto
name|emit_ranges
goto|;
name|val
operator|=
name|atoi
argument_list|(
name|pOptDesc
operator|->
name|optArg
operator|.
name|argString
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
name|val
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
name|val
operator|==
name|rng
index|[
name|ix
index|]
operator|.
name|rmin
condition|)
goto|goto
name|valid_return
goto|;
if|if
condition|(
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
operator|==
name|INT_MIN
condition|)
continue|continue;
if|if
condition|(
name|val
operator|<=
name|rng
index|[
name|ix
index|]
operator|.
name|rmax
condition|)
goto|goto
name|valid_return
goto|;
block|}
name|option_usage_fp
operator|=
name|stderr
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"%s error:  %s option value ``%s''is out of range.\n"
argument_list|)
argument_list|,
name|pOptions
operator|->
name|pzProgName
argument_list|,
name|pOptDesc
operator|->
name|pz_Name
argument_list|,
name|pOptDesc
operator|->
name|optArg
operator|.
name|argString
argument_list|)
expr_stmt|;
name|pzIndent
operator|=
literal|"\t"
expr_stmt|;
name|emit_ranges
label|:
name|fprintf
argument_list|(
name|option_usage_fp
argument_list|,
name|_
argument_list|(
literal|"%sit must lie in the range: %d to %d\n"
argument_list|)
argument_list|,
name|pzIndent
argument_list|,
name|rng
index|[
literal|0
index|]
operator|.
name|rmin
argument_list|,
name|rng
index|[
literal|0
index|]
operator|.
name|rmax
argument_list|)
expr_stmt|;
if|if
condition|(
name|pOptDesc
operator|==
name|NULL
condition|)
return|return;
name|USAGE
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
comment|/* NOTREACHED */
return|return;
name|valid_return
label|:
name|pOptDesc
operator|->
name|optArg
operator|.
name|argInt
operator|=
name|val
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* defined OPENSSL */
comment|/* extracted from /usr/local/gnu/autogen-5.9.1/share/autogen/optmain.tpl near line 92 */
if|#
directive|if
name|defined
argument_list|(
name|TEST_NTP_KEYGEN_OPTS
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
name|ntp_keygenOptions
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
name|ntp_keygenOptions
argument_list|)
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
endif|#
directive|endif
comment|/* defined TEST_NTP_KEYGEN_OPTS */
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
value|coerce_it((void*)&(ntp_keygenOptions._f))
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
name|ntp_keygenOptions
operator|.
name|pOptDesc
decl_stmt|;
name|int
name|ix
init|=
name|ntp_keygenOptions
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
comment|/* ntp-keygen-opts.c ends here */
end_comment

end_unit

