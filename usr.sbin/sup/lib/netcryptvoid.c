begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software_Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/**********************************************************************  * HISTORY  * $Log: netcryptvoid.c,v $  * Revision 1.1.1.1  1993/08/21  00:46:33  jkh  * Current sup with compression support.  *  * Revision 1.1.1.1  1993/05/21  14:52:17  cgd  * initial import of CMU's SUP to NetBSD  *  * Revision 2.2  92/09/09  22:04:34  mrt  * 	Created.  * 	[92/09/09            mrt]  *   */
end_comment

begin_comment
comment|/*  * DATA ENCRYPTION  *	netcrypt (key)		turn on/off encryption of strings and files  *	  char *key;			encryption key  *  */
end_comment

begin_comment
comment|/*  * Replacement for subroutine version of "crypt" program  *  for foreign and non-BSD-licensed sites. With this code  *  you can only run unencrypted sups  */
end_comment

begin_include
include|#
directive|include
file|<libc.h>
end_include

begin_include
include|#
directive|include
file|"sup.h"
end_include

begin_include
include|#
directive|include
file|"supmsg.h"
end_include

begin_comment
comment|/*********************************************  ***    G L O B A L   V A R I A B L E S    ***  *********************************************/
end_comment

begin_decl_stmt
name|int
name|cryptflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* whether to encrypt/decrypt data */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cryptbuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for data encryption/decryption */
end_comment

begin_function
name|int
name|netcrypt
parameter_list|(
name|pword
parameter_list|)
name|char
modifier|*
name|pword
decl_stmt|;
block|{
if|if
condition|(
name|pword
operator|==
name|NULL
operator|||
operator|(
name|strcmp
argument_list|(
name|pword
argument_list|,
name|PSWDCRYPT
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|cryptflag
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|getcryptbuf
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|SCMOK
operator|)
return|;
block|}
return|return
operator|(
name|SCMERR
operator|)
return|;
block|}
end_function

begin_function
name|int
name|getcryptbuf
parameter_list|(
name|x
parameter_list|)
name|int
name|x
decl_stmt|;
block|{
specifier|static
name|int
name|cryptsize
init|=
literal|0
decl_stmt|;
comment|/* size of current cryptbuf */
if|if
condition|(
name|cryptflag
operator|==
literal|0
condition|)
block|{
return|return
operator|(
name|SCMOK
operator|)
return|;
block|}
else|else
return|return
operator|(
name|SCMERR
operator|)
return|;
block|}
end_function

begin_function
name|void
name|decode
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|in
decl_stmt|,
decl|*
name|out
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

begin_function
name|void
name|encode
parameter_list|(
name|in
parameter_list|,
name|out
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|in
decl_stmt|,
decl|*
name|out
decl_stmt|;
end_function

begin_decl_stmt
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

