begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)roll.c	5.4 (Berkeley) 6/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *	This routine rolls ndie nside-sided dice.  */
end_comment

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXRAND
value|32767L
end_define

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|long
name|tot
decl_stmt|;
name|reg
name|unsigned
name|n
decl_stmt|,
name|r
decl_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
name|n
operator|=
name|ndie
expr_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
name|tot
operator|+=
name|rand
argument_list|()
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
operator|(
name|tot
operator|*
operator|(
name|long
operator|)
name|nsides
operator|)
operator|/
operator|(
operator|(
name|long
operator|)
name|MAXRAND
operator|+
literal|1
operator|)
argument_list|)
operator|+
name|ndie
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|tot
decl_stmt|,
name|r
decl_stmt|;
name|reg
name|double
name|num_sides
decl_stmt|;
name|num_sides
operator|=
name|nsides
expr_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ndie
operator|--
condition|)
name|tot
operator|+=
operator|(
name|r
operator|=
name|rand
argument_list|()
operator|)
operator|*
operator|(
name|num_sides
operator|/
literal|017777777777
operator|)
operator|+
literal|1
expr_stmt|;
return|return
name|tot
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

