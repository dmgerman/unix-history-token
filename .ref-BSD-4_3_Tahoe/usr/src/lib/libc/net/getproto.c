begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getproto.c	5.5 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|_proto_stayopen
decl_stmt|;
end_decl_stmt

begin_function
name|struct
name|protoent
modifier|*
name|getprotobynumber
parameter_list|(
name|proto
parameter_list|)
specifier|register
name|int
name|proto
decl_stmt|;
block|{
specifier|register
name|struct
name|protoent
modifier|*
name|p
decl_stmt|;
name|setprotoent
argument_list|(
name|_proto_stayopen
argument_list|)
expr_stmt|;
while|while
condition|(
name|p
operator|=
name|getprotoent
argument_list|()
condition|)
if|if
condition|(
name|p
operator|->
name|p_proto
operator|==
name|proto
condition|)
break|break;
if|if
condition|(
operator|!
name|_proto_stayopen
condition|)
name|endprotoent
argument_list|()
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

end_unit

