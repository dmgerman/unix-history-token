begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)tttvi925.c	3.5 (Berkeley) %G%"
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
comment|/*  * Televideo 925 as emulated by Microterm.  *  * From David Barto<sdcsvax!celerity!barto>.  */
end_comment

begin_define
define|#
directive|define
name|G
value|(WWM_GRP<< WWC_MSHIFT)
end_define

begin_decl_stmt
name|short
name|tvi925_frame
index|[
literal|16
index|]
init|=
block|{
literal|' '
block|,
literal|'~'
operator||
name|G
block|,
literal|'|'
operator||
name|G
block|,
literal|'c'
operator||
name|G
block|,
literal|'~'
operator||
name|G
block|,
literal|'~'
operator||
name|G
block|,
literal|'`'
operator||
name|G
block|,
literal|'e'
operator||
name|G
block|,
literal|'|'
operator||
name|G
block|,
literal|'a'
operator||
name|G
block|,
literal|'|'
operator||
name|G
block|,
literal|'g'
operator||
name|G
block|,
literal|'b'
operator||
name|G
block|,
literal|'f'
operator||
name|G
block|,
literal|'h'
operator||
name|G
block|,
literal|'d'
operator||
name|G
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|tt_tvi925
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
name|tt
operator|.
name|tt_availmodes
operator||=
name|WWM_GRP
expr_stmt|;
name|tt
operator|.
name|tt_frame
operator|=
name|tvi925_frame
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

end_unit

