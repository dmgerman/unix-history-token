begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chkpassword.c - check the password */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/compat/RCS/chkpassword.c,v 7.1 91/02/22 09:15:03 mrose Interim $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/compat/RCS/chkpassword.c,v 7.1 91/02/22 09:15:03 mrose Interim $  *  *  * $Log:	chkpassword.c,v $  * Revision 7.1  91/02/22  09:15:03  mrose  * Interim 6.8  *   * Revision 7.0  91/01/14  11:00:31  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* LINTLIBRARY */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|KRB_PASSWD
end_ifdef

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* L.McLoughlin added kerberos passwd checking - based on original  * code from xnlock by S. Lacey.  * Takes the username, the password from the password file, and the passwd  * the user is trying to use.  * Returns 1 if the passwd matches otherwise 0.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KRB_PASSWD
end_ifndef

begin_comment
comment|/* ARGSUSED */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|chkpassword
parameter_list|(
name|usrname
parameter_list|,
name|pwpass
parameter_list|,
name|usrpass
parameter_list|)
name|char
modifier|*
name|usrname
decl_stmt|;
name|char
modifier|*
name|pwpass
decl_stmt|;
name|char
modifier|*
name|usrpass
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|KRB_PASSWD
name|char
name|realm
index|[
name|REALM_SZ
index|]
decl_stmt|;
name|int
name|krbval
decl_stmt|;
comment|/*  	 * check to see if the passwd is `*krb*' 	 * if it is, use kerberos 	 */
if|if
condition|(
name|strcmp
argument_list|(
name|pwpass
argument_list|,
literal|"*krb*"
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* 		 * use kerberos, first of all find the realm 		 */
if|if
condition|(
name|krb_get_lrealm
argument_list|(
name|realm
argument_list|,
literal|1
argument_list|)
operator|!=
name|KSUCCESS
condition|)
block|{
operator|(
name|void
operator|)
name|strncpy
argument_list|(
name|realm
argument_list|,
name|KRB_REALM
argument_list|,
sizeof|sizeof
argument_list|(
name|realm
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * now check the passwd 		 */
name|krbval
operator|=
name|krb_get_pw_in_tkt
argument_list|(
name|usrname
argument_list|,
literal|""
argument_list|,
name|realm
argument_list|,
literal|"krbtgt"
argument_list|,
name|realm
argument_list|,
name|DEFAULT_TKT_LIFE
argument_list|,
name|usrpass
argument_list|)
expr_stmt|;
return|return
operator|(
name|krbval
operator|==
name|INTK_OK
operator|)
return|;
empty_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * use passwd file password 	 */
return|return
operator|(
name|strcmp
argument_list|(
name|crypt
argument_list|(
name|usrpass
argument_list|,
name|pwpass
argument_list|)
argument_list|,
name|pwpass
argument_list|)
operator|==
literal|0
operator|)
return|;
block|}
end_function

end_unit

