begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pam_rootok module */
end_comment

begin_comment
comment|/*  * $Id: pam_rootok.c,v 1.1.1.1 2000/06/20 22:11:56 agmorgan Exp $  * $FreeBSD$  *  * Written by Andrew Morgan<morgan@linux.kernel.org> 1996/3/11  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/*  * here, we make a definition for the externally accessible function  * in this file (this definition is required for static a module  * but strongly encouraged generally) it is used to instruct the  * modules include file to define the function prototypes.  */
end_comment

begin_define
define|#
directive|define
name|PAM_SM_AUTH
end_define

begin_include
include|#
directive|include
file|<security/pam_modules.h>
end_include

begin_comment
comment|/* some syslogging */
end_comment

begin_function
specifier|static
name|void
name|_pam_log
parameter_list|(
name|int
name|err
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
literal|"PAM-rootok"
argument_list|,
name|LOG_CONS
operator||
name|LOG_PID
argument_list|,
name|LOG_AUTH
argument_list|)
expr_stmt|;
name|vsyslog
argument_list|(
name|err
argument_list|,
name|format
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|closelog
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* argument parsing */
end_comment

begin_define
define|#
directive|define
name|PAM_DEBUG_ARG
value|01
end_define

begin_function
specifier|static
name|int
name|_pam_parse
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|int
name|ctrl
init|=
literal|0
decl_stmt|;
comment|/* step through arguments */
for|for
control|(
name|ctrl
operator|=
literal|0
init|;
name|argc
operator|--
operator|>
literal|0
condition|;
operator|++
name|argv
control|)
block|{
comment|/* generic options */
if|if
condition|(
operator|!
name|strcmp
argument_list|(
operator|*
name|argv
argument_list|,
literal|"debug"
argument_list|)
condition|)
name|ctrl
operator||=
name|PAM_DEBUG_ARG
expr_stmt|;
else|else
block|{
name|_pam_log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"pam_parse: unknown option; %s"
argument_list|,
operator|*
name|argv
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|ctrl
return|;
block|}
end_function

begin_comment
comment|/* --- authentication management functions (only) --- */
end_comment

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_authenticate
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
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
block|{
name|int
name|ctrl
decl_stmt|;
name|int
name|retval
init|=
name|PAM_AUTH_ERR
decl_stmt|;
name|ctrl
operator|=
name|_pam_parse
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|getuid
argument_list|()
operator|==
literal|0
condition|)
name|retval
operator|=
name|PAM_SUCCESS
expr_stmt|;
if|if
condition|(
name|ctrl
operator|&
name|PAM_DEBUG_ARG
condition|)
block|{
name|_pam_log
argument_list|(
name|LOG_DEBUG
argument_list|,
literal|"authetication %s"
argument_list|,
name|retval
operator|==
name|PAM_SUCCESS
condition|?
literal|"succeeded"
else|:
literal|"failed"
argument_list|)
expr_stmt|;
block|}
return|return
name|retval
return|;
block|}
end_function

begin_function
name|PAM_EXTERN
name|int
name|pam_sm_setcred
parameter_list|(
name|pam_handle_t
modifier|*
name|pamh
parameter_list|,
name|int
name|flags
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
block|{
return|return
name|PAM_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* end of module definition */
end_comment

begin_expr_stmt
name|PAM_MODULE_ENTRY
argument_list|(
literal|"pam_rootok"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

