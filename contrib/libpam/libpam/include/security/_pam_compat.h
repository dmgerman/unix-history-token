begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_PAM_COMPAT_H
end_define

begin_comment
comment|/*  * This file was contributed by Derrick J Brashear<shadow@dementia.org>  *  * A number of operating systems have started to implement PAM.  * unfortunately, they have a different set of numeric values for  * certain constants.  This file is included for compatibility's sake.  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Solaris uses different constants. We redefine to those here */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|solaris
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__SVR4
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
end_if

begin_comment
comment|/* generic for pam_* functions */
end_comment

begin_undef
undef|#
directive|undef
name|PAM_SILENT
end_undef

begin_define
define|#
directive|define
name|PAM_SILENT
value|0x80000000
end_define

begin_comment
comment|/* flags for pam_chauthtok() */
end_comment

begin_undef
undef|#
directive|undef
name|PAM_PRELIM_CHECK
end_undef

begin_define
define|#
directive|define
name|PAM_PRELIM_CHECK
value|0x1
end_define

begin_undef
undef|#
directive|undef
name|PAM_UPDATE_AUTHTOK
end_undef

begin_define
define|#
directive|define
name|PAM_UPDATE_AUTHTOK
value|0x2
end_define

begin_comment
comment|/* flags for pam_setcred() */
end_comment

begin_undef
undef|#
directive|undef
name|PAM_ESTABLISH_CRED
end_undef

begin_define
define|#
directive|define
name|PAM_ESTABLISH_CRED
value|0x1
end_define

begin_undef
undef|#
directive|undef
name|PAM_DELETE_CRED
end_undef

begin_define
define|#
directive|define
name|PAM_DELETE_CRED
value|0x2
end_define

begin_undef
undef|#
directive|undef
name|PAM_REINITIALIZE_CRED
end_undef

begin_define
define|#
directive|define
name|PAM_REINITIALIZE_CRED
value|0x4
end_define

begin_define
define|#
directive|define
name|PAM_REFRESH_CRED
value|0x8
end_define

begin_undef
undef|#
directive|undef
name|PAM_REFRESH_CRED
end_undef

begin_comment
comment|/* another binary incompatibility comes from the return codes! */
end_comment

begin_undef
undef|#
directive|undef
name|PAM_CONV_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_CONV_ERR
value|6
end_define

begin_undef
undef|#
directive|undef
name|PAM_PERM_DENIED
end_undef

begin_define
define|#
directive|define
name|PAM_PERM_DENIED
value|7
end_define

begin_undef
undef|#
directive|undef
name|PAM_MAXTRIES
end_undef

begin_define
define|#
directive|define
name|PAM_MAXTRIES
value|8
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTH_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_AUTH_ERR
value|9
end_define

begin_undef
undef|#
directive|undef
name|PAM_NEW_AUTHTOK_REQD
end_undef

begin_define
define|#
directive|define
name|PAM_NEW_AUTHTOK_REQD
value|10
end_define

begin_undef
undef|#
directive|undef
name|PAM_CRED_INSUFFICIENT
end_undef

begin_define
define|#
directive|define
name|PAM_CRED_INSUFFICIENT
value|11
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHINFO_UNAVAIL
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHINFO_UNAVAIL
value|12
end_define

begin_undef
undef|#
directive|undef
name|PAM_USER_UNKNOWN
end_undef

begin_define
define|#
directive|define
name|PAM_USER_UNKNOWN
value|13
end_define

begin_undef
undef|#
directive|undef
name|PAM_CRED_UNAVAIL
end_undef

begin_define
define|#
directive|define
name|PAM_CRED_UNAVAIL
value|14
end_define

begin_undef
undef|#
directive|undef
name|PAM_CRED_EXPIRED
end_undef

begin_define
define|#
directive|define
name|PAM_CRED_EXPIRED
value|15
end_define

begin_undef
undef|#
directive|undef
name|PAM_CRED_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_CRED_ERR
value|16
end_define

begin_undef
undef|#
directive|undef
name|PAM_ACCT_EXPIRED
end_undef

begin_define
define|#
directive|define
name|PAM_ACCT_EXPIRED
value|17
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHTOK_EXPIRED
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHTOK_EXPIRED
value|18
end_define

begin_undef
undef|#
directive|undef
name|PAM_SESSION_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_SESSION_ERR
value|19
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHTOK_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHTOK_ERR
value|20
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHTOK_RECOVERY_ERR
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHTOK_RECOVERY_ERR
value|21
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHTOK_LOCK_BUSY
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHTOK_LOCK_BUSY
value|22
end_define

begin_undef
undef|#
directive|undef
name|PAM_AUTHTOK_DISABLE_AGING
end_undef

begin_define
define|#
directive|define
name|PAM_AUTHTOK_DISABLE_AGING
value|23
end_define

begin_undef
undef|#
directive|undef
name|PAM_NO_MODULE_DATA
end_undef

begin_define
define|#
directive|define
name|PAM_NO_MODULE_DATA
value|24
end_define

begin_undef
undef|#
directive|undef
name|PAM_IGNORE
end_undef

begin_define
define|#
directive|define
name|PAM_IGNORE
value|25
end_define

begin_undef
undef|#
directive|undef
name|PAM_ABORT
end_undef

begin_define
define|#
directive|define
name|PAM_ABORT
value|26
end_define

begin_undef
undef|#
directive|undef
name|PAM_TRY_AGAIN
end_undef

begin_define
define|#
directive|define
name|PAM_TRY_AGAIN
value|27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(solaris) || (defined(__SVR4)&& defined(sun)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAM_COMPAT_H */
end_comment

end_unit

