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
literal|"@(#)ttzentec.c	3.3 (Berkeley) 6/29/88"
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
comment|/*  * Zentec 1021  *  * We let the termcap entry specify how to enter and exit graphics mode,  * since it varies with what the terminal is emulating.  */
end_comment

begin_define
define|#
directive|define
name|G
value|(WWM_GRP<< WWC_MSHIFT)
end_define

begin_decl_stmt
name|short
name|zentec_frame
index|[
literal|16
index|]
init|=
block|{
literal|' '
block|,
literal|'x'
operator||
name|G
block|,
literal|'q'
operator||
name|G
block|,
literal|'m'
operator||
name|G
block|,
literal|'x'
operator||
name|G
block|,
literal|'x'
operator||
name|G
block|,
literal|'l'
operator||
name|G
block|,
literal|'t'
operator||
name|G
block|,
literal|'q'
operator||
name|G
block|,
literal|'j'
operator||
name|G
block|,
literal|'q'
operator||
name|G
block|,
literal|'v'
operator||
name|G
block|,
literal|'k'
operator||
name|G
block|,
literal|'u'
operator||
name|G
block|,
literal|'w'
operator||
name|G
block|,
literal|'n'
operator||
name|G
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|tt_zentec
argument_list|()
end_macro

begin_block
block|{
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
if|if
condition|(
name|tt
operator|.
name|tt_availmodes
operator||
name|WWM_GRP
condition|)
name|tt
operator|.
name|tt_frame
operator|=
name|zentec_frame
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

