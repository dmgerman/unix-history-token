begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: support.h,v 1.3 2000/12/20 05:15:05 vorlon Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAM_UNIX_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|_PAM_UNIX_SUPPORT_H
end_define

begin_comment
comment|/*  * here is the string to inform the user that the new passwords they  * typed were not the same.  */
end_comment

begin_define
define|#
directive|define
name|MISTYPED_PASS
value|"Sorry, passwords do not match"
end_define

begin_comment
comment|/* type definition for the control options */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|token
decl_stmt|;
name|unsigned
name|int
name|mask
decl_stmt|;
comment|/* shall assume 32 bits of flags */
name|unsigned
name|int
name|flag
decl_stmt|;
block|}
name|UNIX_Ctrls
typedef|;
end_typedef

begin_comment
comment|/*  * macro to determine if a given flag is on  */
end_comment

begin_define
define|#
directive|define
name|on
parameter_list|(
name|x
parameter_list|,
name|ctrl
parameter_list|)
value|(unix_args[x].flag& ctrl)
end_define

begin_comment
comment|/*  * macro to determine that a given flag is NOT on  */
end_comment

begin_define
define|#
directive|define
name|off
parameter_list|(
name|x
parameter_list|,
name|ctrl
parameter_list|)
value|(!on(x,ctrl))
end_define

begin_comment
comment|/*  * macro to turn on/off a ctrl flag manually  */
end_comment

begin_define
define|#
directive|define
name|set
parameter_list|(
name|x
parameter_list|,
name|ctrl
parameter_list|)
value|(ctrl = ((ctrl)&unix_args[x].mask)|unix_args[x].flag)
end_define

begin_define
define|#
directive|define
name|unset
parameter_list|(
name|x
parameter_list|,
name|ctrl
parameter_list|)
value|(ctrl&= ~(unix_args[x].flag))
end_define

begin_comment
comment|/* the generic mask */
end_comment

begin_define
define|#
directive|define
name|_ALL_ON_
value|(~0U)
end_define

begin_comment
comment|/* end of macro definitions definitions for the control flags */
end_comment

begin_comment
comment|/* ****************************************************************** *  * ctrl flags proper..  */
end_comment

begin_comment
comment|/*  * here are the various options recognized by the unix module. They  * are enumerated here and then defined below. Internal arguments are  * given NULL tokens.  */
end_comment

begin_define
define|#
directive|define
name|UNIX__OLD_PASSWD
value|0
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX__VERIFY_PASSWD
value|1
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX__IAMROOT
value|2
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX_AUDIT
value|3
end_define

begin_comment
comment|/* print more things than debug.. 					   some information may be sensitive */
end_comment

begin_define
define|#
directive|define
name|UNIX_USE_FIRST_PASS
value|4
end_define

begin_define
define|#
directive|define
name|UNIX_TRY_FIRST_PASS
value|5
end_define

begin_define
define|#
directive|define
name|UNIX_NOT_SET_PASS
value|6
end_define

begin_comment
comment|/* don't set the AUTHTOK items */
end_comment

begin_define
define|#
directive|define
name|UNIX__PRELIM
value|7
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX__UPDATE
value|8
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX__NONULL
value|9
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX__QUIET
value|10
end_define

begin_comment
comment|/* internal */
end_comment

begin_define
define|#
directive|define
name|UNIX_USE_AUTHTOK
value|11
end_define

begin_comment
comment|/* insist on reading PAM_AUTHTOK */
end_comment

begin_define
define|#
directive|define
name|UNIX_SHADOW
value|12
end_define

begin_comment
comment|/* signal shadow on */
end_comment

begin_define
define|#
directive|define
name|UNIX_MD5_PASS
value|13
end_define

begin_comment
comment|/* force the use of MD5 passwords */
end_comment

begin_define
define|#
directive|define
name|UNIX__NULLOK
value|14
end_define

begin_comment
comment|/* Null token ok */
end_comment

begin_define
define|#
directive|define
name|UNIX_DEBUG
value|15
end_define

begin_comment
comment|/* send more info to syslog(3) */
end_comment

begin_define
define|#
directive|define
name|UNIX_NODELAY
value|16
end_define

begin_comment
comment|/* admin does not want a fail-delay */
end_comment

begin_define
define|#
directive|define
name|UNIX_NIS
value|17
end_define

begin_comment
comment|/* wish to use NIS for pwd */
end_comment

begin_define
define|#
directive|define
name|UNIX_BIGCRYPT
value|18
end_define

begin_comment
comment|/* use DEC-C2 crypt()^x function */
end_comment

begin_define
define|#
directive|define
name|UNIX_LIKE_AUTH
value|19
end_define

begin_comment
comment|/* need to auth for setcred to work */
end_comment

begin_define
define|#
directive|define
name|UNIX_REMEMBER_PASSWD
value|20
end_define

begin_comment
comment|/* Remember N previous passwords */
end_comment

begin_comment
comment|/* -------------- */
end_comment

begin_define
define|#
directive|define
name|UNIX_CTRLS_
value|21
end_define

begin_comment
comment|/* number of ctrl arguments defined */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|UNIX_Ctrls
name|unix_args
index|[
name|UNIX_CTRLS_
index|]
init|=
block|{
comment|/* symbol                  token name          ctrl mask             ctrl     *  * ----------------------- ------------------- --------------------- -------- */
comment|/* UNIX__OLD_PASSWD */
block|{
name|NULL
block|,
name|_ALL_ON_
block|,
literal|01
block|}
block|,
comment|/* UNIX__VERIFY_PASSWD */
block|{
name|NULL
block|,
name|_ALL_ON_
block|,
literal|02
block|}
block|,
comment|/* UNIX__IAMROOT */
block|{
name|NULL
block|,
name|_ALL_ON_
block|,
literal|04
block|}
block|,
comment|/* UNIX_AUDIT */
block|{
literal|"audit"
block|,
name|_ALL_ON_
block|,
literal|010
block|}
block|,
comment|/* UNIX_USE_FIRST_PASS */
block|{
literal|"use_first_pass"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|060
operator|)
block|,
literal|020
block|}
block|,
comment|/* UNIX_TRY_FIRST_PASS */
block|{
literal|"try_first_pass"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|060
operator|)
block|,
literal|040
block|}
block|,
comment|/* UNIX_NOT_SET_PASS */
block|{
literal|"not_set_pass"
block|,
name|_ALL_ON_
block|,
literal|0100
block|}
block|,
comment|/* UNIX__PRELIM */
block|{
name|NULL
block|,
name|_ALL_ON_
operator|^
operator|(
literal|0600
operator|)
block|,
literal|0200
block|}
block|,
comment|/* UNIX__UPDATE */
block|{
name|NULL
block|,
name|_ALL_ON_
operator|^
operator|(
literal|0600
operator|)
block|,
literal|0400
block|}
block|,
comment|/* UNIX__NONULL */
block|{
name|NULL
block|,
name|_ALL_ON_
block|,
literal|01000
block|}
block|,
comment|/* UNIX__QUIET */
block|{
name|NULL
block|,
name|_ALL_ON_
block|,
literal|02000
block|}
block|,
comment|/* UNIX_USE_AUTHTOK */
block|{
literal|"use_authtok"
block|,
name|_ALL_ON_
block|,
literal|04000
block|}
block|,
comment|/* UNIX_SHADOW */
block|{
literal|"shadow"
block|,
name|_ALL_ON_
block|,
literal|010000
block|}
block|,
comment|/* UNIX_MD5_PASS */
block|{
literal|"md5"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|0400000
operator|)
block|,
literal|020000
block|}
block|,
comment|/* UNIX__NULLOK */
block|{
literal|"nullok"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|01000
operator|)
block|,
literal|0
block|}
block|,
comment|/* UNIX_DEBUG */
block|{
literal|"debug"
block|,
name|_ALL_ON_
block|,
literal|040000
block|}
block|,
comment|/* UNIX_NODELAY */
block|{
literal|"nodelay"
block|,
name|_ALL_ON_
block|,
literal|0100000
block|}
block|,
comment|/* UNIX_NIS */
block|{
literal|"nis"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|010000
operator|)
block|,
literal|0200000
block|}
block|,
comment|/* UNIX_BIGCRYPT */
block|{
literal|"bigcrypt"
block|,
name|_ALL_ON_
operator|^
operator|(
literal|020000
operator|)
block|,
literal|0400000
block|}
block|,
comment|/* UNIX_LIKE_AUTH */
block|{
literal|"likeauth"
block|,
name|_ALL_ON_
block|,
literal|01000000
block|}
block|,
comment|/* UNIX_REMEMBER_PASSWD */
block|{
literal|"remember="
block|,
name|_ALL_ON_
block|,
literal|02000000
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UNIX_DEFAULTS
value|(unix_args[UNIX__NONULL].flag)
end_define

begin_comment
comment|/* use this to free strings. ESPECIALLY password strings */
end_comment

begin_define
define|#
directive|define
name|_pam_delete
parameter_list|(
name|xx
parameter_list|)
define|\
value|{				\ 	_pam_overwrite(xx);	\ 	_pam_drop(xx);		\ }
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|PAM_getlogin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_log_err
parameter_list|(
name|int
name|err
parameter_list|,
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_make_remark
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|unsigned
name|int
name|ctrl
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_set_ctrl
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
modifier|*
name|remember
parameter_list|,
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_unix_blankpasswd
parameter_list|(
name|unsigned
name|int
name|ctrl
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_unix_verify_password
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|p
parameter_list|,
name|unsigned
name|int
name|ctrl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_unix_read_password
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|unsigned
name|int
name|ctrl
parameter_list|,
specifier|const
name|char
modifier|*
name|comment
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt1
parameter_list|,
specifier|const
name|char
modifier|*
name|prompt2
parameter_list|,
specifier|const
name|char
modifier|*
name|data_name
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|pass
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PAM_UNIX_SUPPORT_H */
end_comment

end_unit

