begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)ttf100.c	3.10 (Berkeley) 6/29/88"
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
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|"tt.h"
end_include

begin_comment
comment|/*  * Freedom 100  */
end_comment

begin_define
define|#
directive|define
name|G
value|(WWM_GRP<< WWC_MSHIFT)
end_define

begin_decl_stmt
name|short
name|f100_frame
index|[
literal|16
index|]
init|=
block|{
literal|' '
block|,
literal|'J'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'A'
operator||
name|G
block|,
literal|'J'
operator||
name|G
block|,
literal|'J'
operator||
name|G
block|,
literal|'B'
operator||
name|G
block|,
literal|'M'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'D'
operator||
name|G
block|,
literal|'K'
operator||
name|G
block|,
literal|'O'
operator||
name|G
block|,
literal|'C'
operator||
name|G
block|,
literal|'L'
operator||
name|G
block|,
literal|'N'
operator||
name|G
block|,
literal|'I'
operator||
name|G
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tt_str
modifier|*
name|gen_AE
decl_stmt|,
modifier|*
name|gen_AS
decl_stmt|;
end_decl_stmt

begin_macro
name|tt_f100
argument_list|()
end_macro

begin_block
block|{
specifier|static
name|struct
name|tt_str
name|ae
init|=
block|{
literal|"\033%"
block|,
literal|2
block|}
decl_stmt|;
specifier|static
name|struct
name|tt_str
name|as
init|=
block|{
literal|"\033$"
block|,
literal|2
block|}
decl_stmt|;
if|if
condition|(
name|tt_generic
argument_list|()
operator|<
literal|0
condition|)
return|return
operator|-
literal|1
return|;
name|tt
operator|.
name|tt_frame
operator|=
name|f100_frame
expr_stmt|;
name|tt
operator|.
name|tt_availmodes
operator||=
name|WWM_GRP
expr_stmt|;
name|gen_AS
operator|=
operator|&
name|as
expr_stmt|;
name|gen_AE
operator|=
operator|&
name|ae
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

