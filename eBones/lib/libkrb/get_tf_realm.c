begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: get_tf_realm.c,v 4.2 90/01/02 13:40:19 jtkohl Exp $  *	$Id: get_tf_realm.c,v 1.2 1994/07/19 19:25:30 g89r4222 Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: get_tf_realm.c,v 1.2 1994/07/19 19:25:30 g89r4222 Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * This file contains a routine to extract the realm of a kerberos  * ticket file.  */
end_comment

begin_comment
comment|/*  * krb_get_tf_realm() takes two arguments: the name of a ticket   * and a variable to store the name of the realm in.  *   */
end_comment

begin_macro
name|krb_get_tf_realm
argument_list|(
argument|ticket_file
argument_list|,
argument|realm
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ticket_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|realm
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|krb_get_tf_fullname
argument_list|(
name|ticket_file
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|realm
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

