begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  EDIT THIS FILE WITH CAUTION  (ntp-keygen-opts.c)  *  *  It has been AutoGen-ed  February  4, 2015 at 02:43:42 AM by AutoGen 5.18.5pre4  *  From the definitions    ntp-keygen-opts.def  *  and the template file   options  *  * Generated from AutoOpts 41:0:16 templates.  *  *  AutoOpts is a copyrighted work.  This source file is not encumbered  *  by AutoOpts licensing, but is provided under the licensing terms chosen  *  by the ntp-keygen author or copyright holder.  AutoOpts is  *  licensed under the terms of the LGPL.  The redistributable library  *  (``libopts'') is licensed under the terms of either the LGPL or, at the  *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources  *  for details.  *  * The ntp-keygen program is copyrighted and licensed  * under the following terms:  *  *  Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.  *  This is free software. It is licensed for use, modification and  *  redistribution under the terms of the NTP License, copies of which  *  can be seen at:  *<http://ntp.org/license>  *<http://opensource.org/licenses/ntp-license.php>  *  *  Permission to use, copy, modify, and distribute this software and its  *  documentation for any purpose with or without fee is hereby granted,  *  provided that the above copyright notice appears in all copies and that  *  both the copyright notice and this permission notice appear in  *  supporting documentation, and that the name The University of Delaware not be used in  *  advertising or publicity pertaining to distribution of the software  *  without specific, written prior permission. The University of Delaware and Network Time Foundation makes no  *  representations about the suitability this software for any purpose. It  *  is provided "as is" without express or implied warranty.  */
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
file|"ntp-keygen-opts.h"
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
value|(ntp_keygen_opt_strs+0)
define|#
directive|define
name|zLicenseDescrip
value|(ntp_keygen_opt_strs+352)
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
comment|/**  *  static const strings for ntp-keygen options  */
specifier|static
name|char
specifier|const
name|ntp_keygen_opt_strs
index|[
literal|2419
index|]
init|=
comment|/*     0 */
literal|"ntp-keygen (ntp) 4.2.8p1\n"
literal|"Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.\n"
literal|"This is free software. It is licensed for use, modification and\n"
literal|"redistribution under the terms of the NTP License, copies of which\n"
literal|"can be seen at:\n"
literal|"<http://ntp.org/license>\n"
literal|"<http://opensource.org/licenses/ntp-license.php>\n\0"
comment|/*   352 */
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
comment|/*  1020 */
literal|"identity modulus bits\0"
comment|/*  1042 */
literal|"IMBITS\0"
comment|/*  1049 */
literal|"imbits\0"
comment|/*  1056 */
literal|"certificate scheme\0"
comment|/*  1075 */
literal|"CERTIFICATE\0"
comment|/*  1087 */
literal|"certificate\0"
comment|/*  1099 */
literal|"privatekey cipher\0"
comment|/*  1117 */
literal|"CIPHER\0"
comment|/*  1124 */
literal|"cipher\0"
comment|/*  1131 */
literal|"Increase debug verbosity level\0"
comment|/*  1162 */
literal|"DEBUG_LEVEL\0"
comment|/*  1174 */
literal|"debug-level\0"
comment|/*  1186 */
literal|"Set the debug verbosity level\0"
comment|/*  1216 */
literal|"SET_DEBUG_LEVEL\0"
comment|/*  1232 */
literal|"set-debug-level\0"
comment|/*  1248 */
literal|"Write IFF or GQ identity keys\0"
comment|/*  1278 */
literal|"ID_KEY\0"
comment|/*  1285 */
literal|"id-key\0"
comment|/*  1292 */
literal|"Generate GQ parameters and keys\0"
comment|/*  1324 */
literal|"GQ_PARAMS\0"
comment|/*  1334 */
literal|"gq-params\0"
comment|/*  1344 */
literal|"generate RSA host key\0"
comment|/*  1366 */
literal|"HOST_KEY\0"
comment|/*  1375 */
literal|"host-key\0"
comment|/*  1384 */
literal|"generate IFF parameters\0"
comment|/*  1408 */
literal|"IFFKEY\0"
comment|/*  1415 */
literal|"iffkey\0"
comment|/*  1422 */
literal|"set Autokey group name\0"
comment|/*  1445 */
literal|"IDENT\0"
comment|/*  1451 */
literal|"ident\0"
comment|/*  1457 */
literal|"set certificate lifetime\0"
comment|/*  1482 */
literal|"LIFETIME\0"
comment|/*  1491 */
literal|"lifetime\0"
comment|/*  1500 */
literal|"generate MD5 keys\0"
comment|/*  1518 */
literal|"MD5KEY\0"
comment|/*  1525 */
literal|"md5key\0"
comment|/*  1532 */
literal|"modulus\0"
comment|/*  1540 */
literal|"MODULUS\0"
comment|/*  1548 */
literal|"generate PC private certificate\0"
comment|/*  1580 */
literal|"PVT_CERT\0"
comment|/*  1589 */
literal|"pvt-cert\0"
comment|/*  1598 */
literal|"local private password\0"
comment|/*  1621 */
literal|"PASSWORD\0"
comment|/*  1630 */
literal|"password\0"
comment|/*  1639 */
literal|"export IFF or GQ group keys with password\0"
comment|/*  1681 */
literal|"EXPORT_PASSWD\0"
comment|/*  1695 */
literal|"export-passwd\0"
comment|/*  1709 */
literal|"generate sign key (RSA or DSA)\0"
comment|/*  1740 */
literal|"SIGN_KEY\0"
comment|/*  1749 */
literal|"sign-key\0"
comment|/*  1758 */
literal|"set host and optionally group name\0"
comment|/*  1793 */
literal|"SUBJECT_NAME\0"
comment|/*  1806 */
literal|"subject-name\0"
comment|/*  1819 */
literal|"trusted certificate (TC scheme)\0"
comment|/*  1851 */
literal|"TRUSTED_CERT\0"
comment|/*  1864 */
literal|"trusted-cert\0"
comment|/*  1877 */
literal|"generate<num> MV parameters\0"
comment|/*  1906 */
literal|"MV_PARAMS\0"
comment|/*  1916 */
literal|"mv-params\0"
comment|/*  1926 */
literal|"update<num> MV keys\0"
comment|/*  1947 */
literal|"MV_KEYS\0"
comment|/*  1955 */
literal|"mv-keys\0"
comment|/*  1963 */
literal|"display extended usage information and exit\0"
comment|/*  2007 */
literal|"help\0"
comment|/*  2012 */
literal|"extended usage information passed thru pager\0"
comment|/*  2057 */
literal|"more-help\0"
comment|/*  2067 */
literal|"output version information and exit\0"
comment|/*  2103 */
literal|"version\0"
comment|/*  2111 */
literal|"save the option state to a config file\0"
comment|/*  2150 */
literal|"save-opts\0"
comment|/*  2160 */
literal|"load options from a config file\0"
comment|/*  2192 */
literal|"LOAD_OPTS\0"
comment|/*  2202 */
literal|"no-load-opts\0"
comment|/*  2215 */
literal|"no\0"
comment|/*  2218 */
literal|"NTP_KEYGEN\0"
comment|/*  2229 */
literal|"ntp-keygen (ntp) - Create a NTP host key - Ver. 4.2.8p1\n"
literal|"Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n\0"
comment|/*  2343 */
literal|"$HOME\0"
comment|/*  2349 */
literal|".\0"
comment|/*  2351 */
literal|".ntprc\0"
comment|/*  2358 */
literal|"http://bugs.ntp.org, bugs@ntp.org\0"
comment|/*  2392 */
literal|"\n\0"
comment|/*  2394 */
literal|"ntp-keygen (ntp) 4.2.8p1"
decl_stmt|;
comment|/**  *  imbits option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the imbits option */
define|#
directive|define
name|IMBITS_DESC
value|(ntp_keygen_opt_strs+1020)
comment|/** Upper-cased name for the imbits option */
define|#
directive|define
name|IMBITS_NAME
value|(ntp_keygen_opt_strs+1042)
comment|/** Name string for the imbits option */
define|#
directive|define
name|IMBITS_name
value|(ntp_keygen_opt_strs+1049)
comment|/** Compiled in flag settings for the imbits option */
define|#
directive|define
name|IMBITS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable imbits */
define|#
directive|define
name|IMBITS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|IMBITS_NAME
value|NULL
define|#
directive|define
name|IMBITS_DESC
value|NULL
define|#
directive|define
name|IMBITS_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  certificate option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the certificate option */
define|#
directive|define
name|CERTIFICATE_DESC
value|(ntp_keygen_opt_strs+1056)
comment|/** Upper-cased name for the certificate option */
define|#
directive|define
name|CERTIFICATE_NAME
value|(ntp_keygen_opt_strs+1075)
comment|/** Name string for the certificate option */
define|#
directive|define
name|CERTIFICATE_name
value|(ntp_keygen_opt_strs+1087)
comment|/** Compiled in flag settings for the certificate option */
define|#
directive|define
name|CERTIFICATE_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable certificate */
define|#
directive|define
name|CERTIFICATE_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|CERTIFICATE_NAME
value|NULL
define|#
directive|define
name|CERTIFICATE_DESC
value|NULL
define|#
directive|define
name|CERTIFICATE_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  cipher option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the cipher option */
define|#
directive|define
name|CIPHER_DESC
value|(ntp_keygen_opt_strs+1099)
comment|/** Upper-cased name for the cipher option */
define|#
directive|define
name|CIPHER_NAME
value|(ntp_keygen_opt_strs+1117)
comment|/** Name string for the cipher option */
define|#
directive|define
name|CIPHER_name
value|(ntp_keygen_opt_strs+1124)
comment|/** Compiled in flag settings for the cipher option */
define|#
directive|define
name|CIPHER_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable cipher */
define|#
directive|define
name|CIPHER_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|CIPHER_NAME
value|NULL
define|#
directive|define
name|CIPHER_DESC
value|NULL
define|#
directive|define
name|CIPHER_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  debug-level option description:  */
comment|/** Descriptive text for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_DESC
value|(ntp_keygen_opt_strs+1131)
comment|/** Upper-cased name for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_NAME
value|(ntp_keygen_opt_strs+1162)
comment|/** Name string for the debug-level option */
define|#
directive|define
name|DEBUG_LEVEL_name
value|(ntp_keygen_opt_strs+1174)
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
value|(ntp_keygen_opt_strs+1186)
comment|/** Upper-cased name for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_NAME
value|(ntp_keygen_opt_strs+1216)
comment|/** Name string for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_name
value|(ntp_keygen_opt_strs+1232)
comment|/** Compiled in flag settings for the set-debug-level option */
define|#
directive|define
name|SET_DEBUG_LEVEL_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
comment|/**  *  id-key option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the id-key option */
define|#
directive|define
name|ID_KEY_DESC
value|(ntp_keygen_opt_strs+1248)
comment|/** Upper-cased name for the id-key option */
define|#
directive|define
name|ID_KEY_NAME
value|(ntp_keygen_opt_strs+1278)
comment|/** Name string for the id-key option */
define|#
directive|define
name|ID_KEY_name
value|(ntp_keygen_opt_strs+1285)
comment|/** Compiled in flag settings for the id-key option */
define|#
directive|define
name|ID_KEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable id-key */
define|#
directive|define
name|ID_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|ID_KEY_NAME
value|NULL
define|#
directive|define
name|ID_KEY_DESC
value|NULL
define|#
directive|define
name|ID_KEY_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  gq-params option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the gq-params option */
define|#
directive|define
name|GQ_PARAMS_DESC
value|(ntp_keygen_opt_strs+1292)
comment|/** Upper-cased name for the gq-params option */
define|#
directive|define
name|GQ_PARAMS_NAME
value|(ntp_keygen_opt_strs+1324)
comment|/** Name string for the gq-params option */
define|#
directive|define
name|GQ_PARAMS_name
value|(ntp_keygen_opt_strs+1334)
comment|/** Compiled in flag settings for the gq-params option */
define|#
directive|define
name|GQ_PARAMS_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable gq-params */
define|#
directive|define
name|GQ_PARAMS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|GQ_PARAMS_NAME
value|NULL
define|#
directive|define
name|GQ_PARAMS_DESC
value|NULL
define|#
directive|define
name|GQ_PARAMS_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  host-key option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the host-key option */
define|#
directive|define
name|HOST_KEY_DESC
value|(ntp_keygen_opt_strs+1344)
comment|/** Upper-cased name for the host-key option */
define|#
directive|define
name|HOST_KEY_NAME
value|(ntp_keygen_opt_strs+1366)
comment|/** Name string for the host-key option */
define|#
directive|define
name|HOST_KEY_name
value|(ntp_keygen_opt_strs+1375)
comment|/** Compiled in flag settings for the host-key option */
define|#
directive|define
name|HOST_KEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable host-key */
define|#
directive|define
name|HOST_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|HOST_KEY_NAME
value|NULL
define|#
directive|define
name|HOST_KEY_DESC
value|NULL
define|#
directive|define
name|HOST_KEY_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  iffkey option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the iffkey option */
define|#
directive|define
name|IFFKEY_DESC
value|(ntp_keygen_opt_strs+1384)
comment|/** Upper-cased name for the iffkey option */
define|#
directive|define
name|IFFKEY_NAME
value|(ntp_keygen_opt_strs+1408)
comment|/** Name string for the iffkey option */
define|#
directive|define
name|IFFKEY_name
value|(ntp_keygen_opt_strs+1415)
comment|/** Compiled in flag settings for the iffkey option */
define|#
directive|define
name|IFFKEY_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable iffkey */
define|#
directive|define
name|IFFKEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|IFFKEY_NAME
value|NULL
define|#
directive|define
name|IFFKEY_DESC
value|NULL
define|#
directive|define
name|IFFKEY_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  ident option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the ident option */
define|#
directive|define
name|IDENT_DESC
value|(ntp_keygen_opt_strs+1422)
comment|/** Upper-cased name for the ident option */
define|#
directive|define
name|IDENT_NAME
value|(ntp_keygen_opt_strs+1445)
comment|/** Name string for the ident option */
define|#
directive|define
name|IDENT_name
value|(ntp_keygen_opt_strs+1451)
comment|/** Compiled in flag settings for the ident option */
define|#
directive|define
name|IDENT_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable ident */
define|#
directive|define
name|IDENT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|IDENT_NAME
value|NULL
define|#
directive|define
name|IDENT_DESC
value|NULL
define|#
directive|define
name|IDENT_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  lifetime option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the lifetime option */
define|#
directive|define
name|LIFETIME_DESC
value|(ntp_keygen_opt_strs+1457)
comment|/** Upper-cased name for the lifetime option */
define|#
directive|define
name|LIFETIME_NAME
value|(ntp_keygen_opt_strs+1482)
comment|/** Name string for the lifetime option */
define|#
directive|define
name|LIFETIME_name
value|(ntp_keygen_opt_strs+1491)
comment|/** Compiled in flag settings for the lifetime option */
define|#
directive|define
name|LIFETIME_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable lifetime */
define|#
directive|define
name|LIFETIME_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|LIFETIME_NAME
value|NULL
define|#
directive|define
name|LIFETIME_DESC
value|NULL
define|#
directive|define
name|LIFETIME_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  md5key option description:  */
comment|/** Descriptive text for the md5key option */
define|#
directive|define
name|MD5KEY_DESC
value|(ntp_keygen_opt_strs+1500)
comment|/** Upper-cased name for the md5key option */
define|#
directive|define
name|MD5KEY_NAME
value|(ntp_keygen_opt_strs+1518)
comment|/** Name string for the md5key option */
define|#
directive|define
name|MD5KEY_name
value|(ntp_keygen_opt_strs+1525)
comment|/** Compiled in flag settings for the md5key option */
define|#
directive|define
name|MD5KEY_FLAGS
value|(OPTST_DISABLED)
comment|/**  *  modulus option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the modulus option */
define|#
directive|define
name|MODULUS_DESC
value|(ntp_keygen_opt_strs+1532)
comment|/** Upper-cased name for the modulus option */
define|#
directive|define
name|MODULUS_NAME
value|(ntp_keygen_opt_strs+1540)
comment|/** Name string for the modulus option */
define|#
directive|define
name|MODULUS_name
value|(ntp_keygen_opt_strs+1532)
comment|/** Compiled in flag settings for the modulus option */
define|#
directive|define
name|MODULUS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable modulus */
define|#
directive|define
name|MODULUS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|MODULUS_NAME
value|NULL
define|#
directive|define
name|MODULUS_DESC
value|NULL
define|#
directive|define
name|MODULUS_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  pvt-cert option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the pvt-cert option */
define|#
directive|define
name|PVT_CERT_DESC
value|(ntp_keygen_opt_strs+1548)
comment|/** Upper-cased name for the pvt-cert option */
define|#
directive|define
name|PVT_CERT_NAME
value|(ntp_keygen_opt_strs+1580)
comment|/** Name string for the pvt-cert option */
define|#
directive|define
name|PVT_CERT_name
value|(ntp_keygen_opt_strs+1589)
comment|/** Compiled in flag settings for the pvt-cert option */
define|#
directive|define
name|PVT_CERT_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable pvt-cert */
define|#
directive|define
name|PVT_CERT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|PVT_CERT_NAME
value|NULL
define|#
directive|define
name|PVT_CERT_DESC
value|NULL
define|#
directive|define
name|PVT_CERT_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  password option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the password option */
define|#
directive|define
name|PASSWORD_DESC
value|(ntp_keygen_opt_strs+1598)
comment|/** Upper-cased name for the password option */
define|#
directive|define
name|PASSWORD_NAME
value|(ntp_keygen_opt_strs+1621)
comment|/** Name string for the password option */
define|#
directive|define
name|PASSWORD_name
value|(ntp_keygen_opt_strs+1630)
comment|/** Compiled in flag settings for the password option */
define|#
directive|define
name|PASSWORD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable password */
define|#
directive|define
name|PASSWORD_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|PASSWORD_NAME
value|NULL
define|#
directive|define
name|PASSWORD_DESC
value|NULL
define|#
directive|define
name|PASSWORD_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  export-passwd option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the export-passwd option */
define|#
directive|define
name|EXPORT_PASSWD_DESC
value|(ntp_keygen_opt_strs+1639)
comment|/** Upper-cased name for the export-passwd option */
define|#
directive|define
name|EXPORT_PASSWD_NAME
value|(ntp_keygen_opt_strs+1681)
comment|/** Name string for the export-passwd option */
define|#
directive|define
name|EXPORT_PASSWD_name
value|(ntp_keygen_opt_strs+1695)
comment|/** Compiled in flag settings for the export-passwd option */
define|#
directive|define
name|EXPORT_PASSWD_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable export-passwd */
define|#
directive|define
name|EXPORT_PASSWD_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|EXPORT_PASSWD_NAME
value|NULL
define|#
directive|define
name|EXPORT_PASSWD_DESC
value|NULL
define|#
directive|define
name|EXPORT_PASSWD_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  sign-key option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the sign-key option */
define|#
directive|define
name|SIGN_KEY_DESC
value|(ntp_keygen_opt_strs+1709)
comment|/** Upper-cased name for the sign-key option */
define|#
directive|define
name|SIGN_KEY_NAME
value|(ntp_keygen_opt_strs+1740)
comment|/** Name string for the sign-key option */
define|#
directive|define
name|SIGN_KEY_name
value|(ntp_keygen_opt_strs+1749)
comment|/** Compiled in flag settings for the sign-key option */
define|#
directive|define
name|SIGN_KEY_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable sign-key */
define|#
directive|define
name|SIGN_KEY_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|SIGN_KEY_NAME
value|NULL
define|#
directive|define
name|SIGN_KEY_DESC
value|NULL
define|#
directive|define
name|SIGN_KEY_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  subject-name option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the subject-name option */
define|#
directive|define
name|SUBJECT_NAME_DESC
value|(ntp_keygen_opt_strs+1758)
comment|/** Upper-cased name for the subject-name option */
define|#
directive|define
name|SUBJECT_NAME_NAME
value|(ntp_keygen_opt_strs+1793)
comment|/** Name string for the subject-name option */
define|#
directive|define
name|SUBJECT_NAME_name
value|(ntp_keygen_opt_strs+1806)
comment|/** Compiled in flag settings for the subject-name option */
define|#
directive|define
name|SUBJECT_NAME_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))
else|#
directive|else
comment|/* disable subject-name */
define|#
directive|define
name|SUBJECT_NAME_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|SUBJECT_NAME_NAME
value|NULL
define|#
directive|define
name|SUBJECT_NAME_DESC
value|NULL
define|#
directive|define
name|SUBJECT_NAME_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  trusted-cert option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the trusted-cert option */
define|#
directive|define
name|TRUSTED_CERT_DESC
value|(ntp_keygen_opt_strs+1819)
comment|/** Upper-cased name for the trusted-cert option */
define|#
directive|define
name|TRUSTED_CERT_NAME
value|(ntp_keygen_opt_strs+1851)
comment|/** Name string for the trusted-cert option */
define|#
directive|define
name|TRUSTED_CERT_name
value|(ntp_keygen_opt_strs+1864)
comment|/** Compiled in flag settings for the trusted-cert option */
define|#
directive|define
name|TRUSTED_CERT_FLAGS
value|(OPTST_DISABLED)
else|#
directive|else
comment|/* disable trusted-cert */
define|#
directive|define
name|TRUSTED_CERT_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|TRUSTED_CERT_NAME
value|NULL
define|#
directive|define
name|TRUSTED_CERT_DESC
value|NULL
define|#
directive|define
name|TRUSTED_CERT_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  mv-params option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the mv-params option */
define|#
directive|define
name|MV_PARAMS_DESC
value|(ntp_keygen_opt_strs+1877)
comment|/** Upper-cased name for the mv-params option */
define|#
directive|define
name|MV_PARAMS_NAME
value|(ntp_keygen_opt_strs+1906)
comment|/** Name string for the mv-params option */
define|#
directive|define
name|MV_PARAMS_name
value|(ntp_keygen_opt_strs+1916)
comment|/** Compiled in flag settings for the mv-params option */
define|#
directive|define
name|MV_PARAMS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable mv-params */
define|#
directive|define
name|MV_PARAMS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|MV_PARAMS_NAME
value|NULL
define|#
directive|define
name|MV_PARAMS_DESC
value|NULL
define|#
directive|define
name|MV_PARAMS_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/**  *  mv-keys option description:  */
ifdef|#
directive|ifdef
name|AUTOKEY
comment|/** Descriptive text for the mv-keys option */
define|#
directive|define
name|MV_KEYS_DESC
value|(ntp_keygen_opt_strs+1926)
comment|/** Upper-cased name for the mv-keys option */
define|#
directive|define
name|MV_KEYS_NAME
value|(ntp_keygen_opt_strs+1947)
comment|/** Name string for the mv-keys option */
define|#
directive|define
name|MV_KEYS_name
value|(ntp_keygen_opt_strs+1955)
comment|/** Compiled in flag settings for the mv-keys option */
define|#
directive|define
name|MV_KEYS_FLAGS
value|(OPTST_DISABLED \         | OPTST_SET_ARGTYPE(OPARG_TYPE_NUMERIC))
else|#
directive|else
comment|/* disable mv-keys */
define|#
directive|define
name|MV_KEYS_FLAGS
value|(OPTST_OMITTED | OPTST_NO_INIT)
define|#
directive|define
name|MV_KEYS_NAME
value|NULL
define|#
directive|define
name|MV_KEYS_DESC
value|NULL
define|#
directive|define
name|MV_KEYS_name
value|NULL
endif|#
directive|endif
comment|/* AUTOKEY */
comment|/*  *  Help/More_Help/Version option descriptions:  */
define|#
directive|define
name|HELP_DESC
value|(ntp_keygen_opt_strs+1963)
define|#
directive|define
name|HELP_name
value|(ntp_keygen_opt_strs+2007)
ifdef|#
directive|ifdef
name|HAVE_WORKING_FORK
define|#
directive|define
name|MORE_HELP_DESC
value|(ntp_keygen_opt_strs+2012)
define|#
directive|define
name|MORE_HELP_name
value|(ntp_keygen_opt_strs+2057)
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
value|(ntp_keygen_opt_strs+2067)
define|#
directive|define
name|VER_name
value|(ntp_keygen_opt_strs+2103)
define|#
directive|define
name|SAVE_OPTS_DESC
value|(ntp_keygen_opt_strs+2111)
define|#
directive|define
name|SAVE_OPTS_name
value|(ntp_keygen_opt_strs+2150)
define|#
directive|define
name|LOAD_OPTS_DESC
value|(ntp_keygen_opt_strs+2160)
define|#
directive|define
name|LOAD_OPTS_NAME
value|(ntp_keygen_opt_strs+2192)
define|#
directive|define
name|NO_LOAD_OPTS_name
value|(ntp_keygen_opt_strs+2202)
define|#
directive|define
name|LOAD_OPTS_pfx
value|(ntp_keygen_opt_strs+2215)
define|#
directive|define
name|LOAD_OPTS_name
value|(NO_LOAD_OPTS_name + 3)
comment|/**  *  Declare option callback procedures  */
ifdef|#
directive|ifdef
name|AUTOKEY
specifier|static
name|tOptProc
name|doOptImbits
decl_stmt|;
else|#
directive|else
comment|/* not AUTOKEY */
define|#
directive|define
name|doOptImbits
value|NULL
endif|#
directive|endif
comment|/* def/not AUTOKEY */
ifdef|#
directive|ifdef
name|AUTOKEY
specifier|static
name|tOptProc
name|doOptModulus
decl_stmt|;
else|#
directive|else
comment|/* not AUTOKEY */
define|#
directive|define
name|doOptModulus
value|NULL
endif|#
directive|endif
comment|/* def/not AUTOKEY */
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
comment|/**  *  Define the ntp-keygen Option Descriptions.  * This is an array of OPTION_CT entries, one for each  * option that the ntp-keygen program responds to.  */
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
name|VALUE_OPT_IMBITS
block|,
comment|/* equiv idx, value */
literal|0
block|,
name|VALUE_OPT_IMBITS
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
name|IMBITS_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --imbits */
comment|/* arg list/cookie  */
name|NULL
block|,
comment|/* must/cannot opts */
name|NULL
block|,
name|NULL
block|,
comment|/* option proc      */
name|doOptImbits
block|,
comment|/* desc, NAME, name */
name|IMBITS_DESC
block|,
name|IMBITS_NAME
block|,
name|IMBITS_name
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
name|VALUE_OPT_CERTIFICATE
block|,
comment|/* equiv idx, value */
literal|1
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
comment|/* --certificate */
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
name|CERTIFICATE_DESC
block|,
name|CERTIFICATE_NAME
block|,
name|CERTIFICATE_name
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
name|VALUE_OPT_CIPHER
block|,
comment|/* equiv idx, value */
literal|2
block|,
name|VALUE_OPT_CIPHER
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
name|CIPHER_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --cipher */
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
name|CIPHER_DESC
block|,
name|CIPHER_NAME
block|,
name|CIPHER_name
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
name|VALUE_OPT_ID_KEY
block|,
comment|/* equiv idx, value */
literal|5
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
comment|/* --id-key */
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
name|ID_KEY_DESC
block|,
name|ID_KEY_NAME
block|,
name|ID_KEY_name
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
name|VALUE_OPT_GQ_PARAMS
block|,
comment|/* equiv idx, value */
literal|6
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
comment|/* --gq-params */
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
name|GQ_PARAMS_DESC
block|,
name|GQ_PARAMS_NAME
block|,
name|GQ_PARAMS_name
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
name|VALUE_OPT_HOST_KEY
block|,
comment|/* equiv idx, value */
literal|7
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
comment|/* --host-key */
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
name|HOST_KEY_DESC
block|,
name|HOST_KEY_NAME
block|,
name|HOST_KEY_name
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
name|VALUE_OPT_IFFKEY
block|,
comment|/* equiv idx, value */
literal|8
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
comment|/* --iffkey */
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
name|IFFKEY_DESC
block|,
name|IFFKEY_NAME
block|,
name|IFFKEY_name
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
name|VALUE_OPT_IDENT
block|,
comment|/* equiv idx, value */
literal|9
block|,
name|VALUE_OPT_IDENT
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
name|IDENT_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --ident */
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
name|IDENT_DESC
block|,
name|IDENT_NAME
block|,
name|IDENT_name
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
name|VALUE_OPT_LIFETIME
block|,
comment|/* equiv idx, value */
literal|10
block|,
name|VALUE_OPT_LIFETIME
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
name|LIFETIME_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --lifetime */
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
name|LIFETIME_DESC
block|,
name|LIFETIME_NAME
block|,
name|LIFETIME_name
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
name|VALUE_OPT_MD5KEY
block|,
comment|/* equiv idx, value */
literal|11
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
comment|/* --md5key */
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
name|MD5KEY_DESC
block|,
name|MD5KEY_NAME
block|,
name|MD5KEY_name
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
name|VALUE_OPT_MODULUS
block|,
comment|/* equiv idx, value */
literal|12
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
comment|/* --modulus */
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
name|MODULUS_DESC
block|,
name|MODULUS_NAME
block|,
name|MODULUS_name
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
name|VALUE_OPT_PVT_CERT
block|,
comment|/* equiv idx, value */
literal|13
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
comment|/* --pvt-cert */
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
name|PVT_CERT_DESC
block|,
name|PVT_CERT_NAME
block|,
name|PVT_CERT_name
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
name|VALUE_OPT_PASSWORD
block|,
comment|/* equiv idx, value */
literal|14
block|,
name|VALUE_OPT_PASSWORD
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
name|PASSWORD_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --password */
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
name|PASSWORD_DESC
block|,
name|PASSWORD_NAME
block|,
name|PASSWORD_name
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
name|VALUE_OPT_EXPORT_PASSWD
block|,
comment|/* equiv idx, value */
literal|15
block|,
name|VALUE_OPT_EXPORT_PASSWD
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
name|EXPORT_PASSWD_FLAGS
block|,
literal|0
block|,
comment|/* last opt argumnt */
block|{
name|NULL
block|}
block|,
comment|/* --export-passwd */
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
name|EXPORT_PASSWD_DESC
block|,
name|EXPORT_PASSWD_NAME
block|,
name|EXPORT_PASSWD_name
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
name|VALUE_OPT_SIGN_KEY
block|,
comment|/* equiv idx, value */
literal|16
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
comment|/* --sign-key */
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
name|SIGN_KEY_DESC
block|,
name|SIGN_KEY_NAME
block|,
name|SIGN_KEY_name
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
name|VALUE_OPT_SUBJECT_NAME
block|,
comment|/* equiv idx, value */
literal|17
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
comment|/* --subject-name */
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
name|SUBJECT_NAME_DESC
block|,
name|SUBJECT_NAME_NAME
block|,
name|SUBJECT_NAME_name
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
name|VALUE_OPT_TRUSTED_CERT
block|,
comment|/* equiv idx, value */
literal|18
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
comment|/* --trusted-cert */
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
name|TRUSTED_CERT_DESC
block|,
name|TRUSTED_CERT_NAME
block|,
name|TRUSTED_CERT_name
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
name|VALUE_OPT_MV_PARAMS
block|,
comment|/* equiv idx, value */
literal|19
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
comment|/* --mv-params */
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
name|MV_PARAMS_DESC
block|,
name|MV_PARAMS_NAME
block|,
name|MV_PARAMS_name
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
name|VALUE_OPT_MV_KEYS
block|,
comment|/* equiv idx, value */
literal|20
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
comment|/* --mv-keys */
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
name|MV_KEYS_DESC
block|,
name|MV_KEYS_NAME
block|,
name|MV_KEYS_name
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
comment|/** Reference to the upper cased version of ntp-keygen. */
define|#
directive|define
name|zPROGNAME
value|(ntp_keygen_opt_strs+2218)
comment|/** Reference to the title line for ntp-keygen usage. */
define|#
directive|define
name|zUsageTitle
value|(ntp_keygen_opt_strs+2229)
comment|/** ntp-keygen configuration file name. */
define|#
directive|define
name|zRcName
value|(ntp_keygen_opt_strs+2351)
comment|/** Directories to search for ntp-keygen config files. */
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
name|ntp_keygen_opt_strs
operator|+
literal|2343
block|,
name|ntp_keygen_opt_strs
operator|+
literal|2349
block|,
name|NULL
block|}
decl_stmt|;
comment|/** The ntp-keygen program bug email address. */
define|#
directive|define
name|zBugsAddr
value|(ntp_keygen_opt_strs+2358)
comment|/** Clarification/explanation of what ntp-keygen does. */
define|#
directive|define
name|zExplain
value|(ntp_keygen_opt_strs+2392)
comment|/** Extra detail explaining what ntp-keygen does. */
define|#
directive|define
name|zDetail
value|(NULL)
comment|/** The full version string for ntp-keygen. */
define|#
directive|define
name|zFullVersion
value|(ntp_keygen_opt_strs+2394)
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
name|ntp_keygen_full_usage
value|(NULL)
define|#
directive|define
name|ntp_keygen_short_usage
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
name|NTP_KEYGEN_EXIT_SUCCESS
expr_stmt|;
name|optionUsage
argument_list|(
operator|&
name|ntp_keygenOptions
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
comment|/**  * Code to handle the imbits option, when AUTOKEY is #define-d.  * The number of bits in the identity modulus.  The default is 256.  * @param[in] pOptions the ntp-keygen options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
ifdef|#
directive|ifdef
name|AUTOKEY
specifier|static
name|void
name|doOptImbits
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
literal|256
block|,
literal|2048
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
endif|#
directive|endif
comment|/* defined AUTOKEY */
comment|/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
comment|/**  * Code to handle the debug-level option.  *  * @param[in] pOptions the ntp-keygen options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
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
comment|/**  * Code to handle the modulus option, when AUTOKEY is #define-d.  * The number of bits in the prime modulus.  The default is 512.  * @param[in] pOptions the ntp-keygen options data structure  * @param[in,out] pOptDesc the option descriptor for this option.  */
ifdef|#
directive|ifdef
name|AUTOKEY
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
literal|256
block|,
literal|2048
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
endif|#
directive|endif
comment|/* defined AUTOKEY */
comment|/* extracted from optmain.tlib near line 1245 */
comment|/**  * The directory containing the data associated with ntp-keygen.  */
ifndef|#
directive|ifndef
name|PKGDATADIR
define|#
directive|define
name|PKGDATADIR
value|""
endif|#
directive|endif
comment|/**  * Information about the person or institution that packaged ntp-keygen  * for the current distribution.  */
ifndef|#
directive|ifndef
name|WITH_PACKAGER
define|#
directive|define
name|ntp_keygen_packager_info
value|NULL
else|#
directive|else
comment|/** Packager information for ntp-keygen. */
specifier|static
name|char
specifier|const
name|ntp_keygen_packager_info
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
literal|"\nReport ntp_keygen bugs to "
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
comment|/**  * The option definitions for ntp-keygen.  The one structure that  * binds them all.  */
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
literal|26
comment|/* full option count */
block|,
literal|21
comment|/* user option count */
block|,
name|ntp_keygen_full_usage
block|,
name|ntp_keygen_short_usage
block|,
name|NULL
block|,
name|NULL
block|,
name|PKGDATADIR
block|,
name|ntp_keygen_packager_info
block|}
decl_stmt|;
if|#
directive|if
name|ENABLE_NLS
comment|/**  * This code is designed to translate translatable option text for the  * ntp-keygen program.  These translations happen upon entry  * to optionProcess().  */
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
name|NTP_KEYGEN_EXIT_FAILURE
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
comment|/**  * Translate all the translatable strings in the ntp_keygenOptions  * structure defined above.  This is done only once.  */
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
name|ntp_keygenOptions
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
comment|/* TRANSLATORS:       The following dummy function was crated solely so that xgettext can      extract the correct strings.  These strings are actually referenced      by a field name in the ntp_keygenOptions structure noted in the      comments below.  The literal text is defined in ntp_keygen_opt_strs.          NOTE: the strings below are segmented with respect to the source string      ntp_keygen_opt_strs.  The strings above are handed off for translation      at run time a paragraph at a time.  Consequently, they are presented here      for translation a paragraph at a time.          ALSO: often the description for an option will reference another option      by name.  These are set off with apostrophe quotes (I hope).  Do not      translate option names.    */
comment|/* referenced via ntp_keygenOptions.pzCopyright */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntp-keygen (ntp) 4.2.8p1\n\ Copyright (C) 1992-2015 The University of Delaware and Network Time Foundation, all rights reserved.\n\ This is free software. It is licensed for use, modification and\n\ redistribution under the terms of the NTP License, copies of which\n\ can be seen at:\n"
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
comment|/* referenced via ntp_keygenOptions.pzCopyNotice */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Permission to use, copy, modify, and distribute this software and its\n\ documentation for any purpose with or without fee is hereby granted,\n\ provided that the above copyright notice appears in all copies and that\n\ both the copyright notice and this permission notice appear in supporting\n\ documentation, and that the name The University of Delaware not be used in\n\ advertising or publicity pertaining to distribution of the software without\n\ specific, written prior permission.  The University of Delaware and Network\n\ Time Foundation makes no representations about the suitability this\n\ software for any purpose.  It is provided \"as is\" without express or\n\ implied warranty.\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"identity modulus bits"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"certificate scheme"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"privatekey cipher"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Increase debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Set the debug verbosity level"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Write IFF or GQ identity keys"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"Generate GQ parameters and keys"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate RSA host key"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate IFF parameters"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"set Autokey group name"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"set certificate lifetime"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate MD5 keys"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"modulus"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate PC private certificate"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"local private password"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"export IFF or GQ group keys with password"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate sign key (RSA or DSA)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"set host and optionally group name"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"trusted certificate (TC scheme)"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"generate<num> MV parameters"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"update<num> MV keys"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"display extended usage information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"extended usage information passed thru pager"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"output version information and exit"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"save the option state to a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pOptDesc->pzText */
name|puts
argument_list|(
name|_
argument_list|(
literal|"load options from a config file"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pzUsageTitle */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntp-keygen (ntp) - Create a NTP host key - Ver. 4.2.8p1\n\ Usage:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pzExplain */
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pzFullVersion */
name|puts
argument_list|(
name|_
argument_list|(
literal|"ntp-keygen (ntp) 4.2.8p1"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pzFullUsage */
name|puts
argument_list|(
name|_
argument_list|(
literal|"<<<NOT-FOUND>>>"
argument_list|)
argument_list|)
expr_stmt|;
comment|/* referenced via ntp_keygenOptions.pzShortUsage */
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
comment|/* ntp-keygen-opts.c ends here */
end_comment

end_unit

