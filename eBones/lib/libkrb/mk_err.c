begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: mk_err.c,v 4.4 88/11/15 16:33:36 jtkohl Exp $  * $FreeBSD$  */
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
unit|static char *rcsid = "$FreeBSD$";
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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * This routine creates a general purpose error reply message.  It  * doesn't use KTEXT because application protocol may have long  * messages, and may want this part of buffer contiguous to other  * stuff.  *  * The error reply is built in "p", using the error code "e" and  * error text "e_string" given.  The length of the error reply is  * returned.  *  * The error reply is in the following format:  *  * unsigned char	KRB_PROT_VERSION	protocol version no.  * unsigned char	AUTH_MSG_APPL_ERR	message type  * (least significant  * bit of above)	HOST_BYTE_ORDER		local byte order  * 4 bytes		e			given error code  * string		e_string		given error text  */
end_comment

begin_function
name|long
name|krb_mk_err
parameter_list|(
name|p
parameter_list|,
name|e
parameter_list|,
name|e_string
parameter_list|)
name|u_char
modifier|*
name|p
decl_stmt|;
comment|/* Where to build error packet */
name|long
name|e
decl_stmt|;
comment|/* Error code */
name|char
modifier|*
name|e_string
decl_stmt|;
comment|/* Text of error */
block|{
name|u_char
modifier|*
name|start
decl_stmt|;
name|start
operator|=
name|p
expr_stmt|;
comment|/* Create fixed part of packet */
operator|*
name|p
operator|++
operator|=
operator|(
name|unsigned
name|char
operator|)
name|KRB_PROT_VERSION
expr_stmt|;
operator|*
name|p
operator|=
operator|(
name|unsigned
name|char
operator|)
name|AUTH_MSG_APPL_ERR
expr_stmt|;
operator|*
name|p
operator|++
operator||=
name|HOST_BYTE_ORDER
expr_stmt|;
comment|/* Add the basic info */
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|e
argument_list|,
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|/* err code */
name|p
operator|+=
sizeof|sizeof
argument_list|(
name|e
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|p
argument_list|,
name|e_string
argument_list|)
expr_stmt|;
comment|/* err text */
name|p
operator|+=
name|strlen
argument_list|(
name|e_string
argument_list|)
expr_stmt|;
comment|/* And return the length */
return|return
name|p
operator|-
name|start
return|;
block|}
end_function

end_unit

