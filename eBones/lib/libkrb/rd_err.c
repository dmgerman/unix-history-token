begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * This routine dissects a a Kerberos 'safe msg',  * checking its integrity, and returning a pointer to the application  * data contained and its length.  *  * Returns 0 (RD_AP_OK) for success or an error code (RD_AP_...)  *  * Steve Miller    Project Athena  MIT/DEC  *  *	from: rd_err.c,v 4.5 89/01/13 17:26:38 steiner Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* system include files */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* application include files */
end_comment

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<prot.h>
end_include

begin_comment
comment|/*  * Given an AUTH_MSG_APPL_ERR message, "in" and its length "in_length",  * return the error code from the message in "code" and the text in  * "m_data" as follows:  *  *	m_data->app_data	points to the error text  *	m_data->app_length	points to the length of the error text  *  * If all goes well, return RD_AP_OK.  If the version number  * is wrong, return RD_AP_VERSION, and if it's not an AUTH_MSG_APPL_ERR  * type message, return RD_AP_MSG_TYPE.  *  * The AUTH_MSG_APPL_ERR message format can be found in mk_err.c  */
end_comment

begin_function
name|int
name|krb_rd_err
parameter_list|(
name|in
parameter_list|,
name|in_length
parameter_list|,
name|code
parameter_list|,
name|m_data
parameter_list|)
name|u_char
modifier|*
name|in
decl_stmt|;
comment|/* pointer to the msg received */
name|u_long
name|in_length
decl_stmt|;
comment|/* of in msg */
name|long
modifier|*
name|code
decl_stmt|;
comment|/* received error code */
name|MSG_DAT
modifier|*
name|m_data
decl_stmt|;
block|{
specifier|register
name|u_char
modifier|*
name|p
decl_stmt|;
name|int
name|swap_bytes
init|=
literal|0
decl_stmt|;
name|p
operator|=
name|in
expr_stmt|;
comment|/* beginning of message */
if|if
condition|(
operator|*
name|p
operator|++
operator|!=
name|KRB_PROT_VERSION
condition|)
return|return
operator|(
name|RD_AP_VERSION
operator|)
return|;
if|if
condition|(
operator|(
operator|(
operator|*
name|p
operator|)
operator|&
operator|~
literal|1
operator|)
operator|!=
name|AUTH_MSG_APPL_ERR
condition|)
return|return
operator|(
name|RD_AP_MSG_TYPE
operator|)
return|;
if|if
condition|(
operator|(
operator|*
name|p
operator|++
operator|&
literal|1
operator|)
operator|!=
name|HOST_BYTE_ORDER
condition|)
name|swap_bytes
operator|++
expr_stmt|;
comment|/* safely get code */
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
operator|(
name|char
operator|*
operator|)
name|code
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|code
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|swap_bytes
condition|)
name|swap_u_long
argument_list|(
operator|*
name|code
argument_list|)
expr_stmt|;
name|p
operator|+=
sizeof|sizeof
argument_list|(
operator|*
name|code
argument_list|)
expr_stmt|;
comment|/* skip over */
name|m_data
operator|->
name|app_data
operator|=
name|p
expr_stmt|;
comment|/* we're now at the error text                                  * message */
name|m_data
operator|->
name|app_length
operator|=
name|in_length
expr_stmt|;
return|return
operator|(
name|RD_AP_OK
operator|)
return|;
comment|/* OK == 0 */
block|}
end_function

end_unit

