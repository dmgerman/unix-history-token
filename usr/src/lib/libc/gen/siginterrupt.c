begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)siginterrupt.c	5.3 (Berkeley) %G%"
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
file|<signal.h>
end_include

begin_comment
comment|/*  * Set signal state to prevent restart of system calls  * after an instance of the indicated signal.  */
end_comment

begin_macro
name|siginterrupt
argument_list|(
argument|sig
argument_list|,
argument|flag
argument_list|)
end_macro

begin_decl_stmt
name|int
name|sig
decl_stmt|,
name|flag
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|sigvec
name|sv
decl_stmt|;
name|int
name|ret
decl_stmt|;
if|if
condition|(
operator|(
name|ret
operator|=
name|sigvec
argument_list|(
name|sig
argument_list|,
operator|(
expr|struct
name|sigvec
operator|*
operator|)
literal|0
argument_list|,
operator|&
name|sv
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
operator|(
name|ret
operator|)
return|;
if|if
condition|(
name|flag
condition|)
name|sv
operator|.
name|sv_flags
operator||=
name|SV_INTERRUPT
expr_stmt|;
else|else
name|sv
operator|.
name|sv_flags
operator|&=
operator|~
name|SV_INTERRUPT
expr_stmt|;
return|return
operator|(
name|sigvec
argument_list|(
name|sig
argument_list|,
operator|&
name|sv
argument_list|,
operator|(
expr|struct
name|sigvec
operator|*
operator|)
literal|0
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

