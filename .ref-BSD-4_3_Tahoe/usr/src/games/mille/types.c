begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)types.c	5.3 (Berkeley) 6/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"mille.h"
end_include

begin_comment
comment|/*  * @(#)types.c	1.1 (Berkeley) 4/1/82  */
end_comment

begin_macro
name|isrepair
argument_list|(
argument|card
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|CARD
name|card
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|card
operator|==
name|C_GAS
operator|||
name|card
operator|==
name|C_SPARE
operator|||
name|card
operator|==
name|C_REPAIRS
operator|||
name|card
operator|==
name|C_INIT
return|;
block|}
end_block

begin_macro
name|safety
argument_list|(
argument|card
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|CARD
name|card
decl_stmt|;
end_decl_stmt

begin_block
block|{
switch|switch
condition|(
name|card
condition|)
block|{
case|case
name|C_EMPTY
case|:
case|case
name|C_GAS
case|:
case|case
name|C_GAS_SAFE
case|:
return|return
name|C_GAS_SAFE
return|;
case|case
name|C_FLAT
case|:
case|case
name|C_SPARE
case|:
case|case
name|C_SPARE_SAFE
case|:
return|return
name|C_SPARE_SAFE
return|;
case|case
name|C_CRASH
case|:
case|case
name|C_REPAIRS
case|:
case|case
name|C_DRIVE_SAFE
case|:
return|return
name|C_DRIVE_SAFE
return|;
case|case
name|C_GO
case|:
case|case
name|C_STOP
case|:
case|case
name|C_RIGHT_WAY
case|:
case|case
name|C_LIMIT
case|:
case|case
name|C_END_LIMIT
case|:
return|return
name|C_RIGHT_WAY
return|;
block|}
comment|/* NOTREACHED */
block|}
end_block

end_unit

