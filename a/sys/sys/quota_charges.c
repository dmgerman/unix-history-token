begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	quota_charges.c	Basser ?.? Melb 4.1	82/07/16	*/
end_comment

begin_comment
comment|/*  *	MUSH Share scheduling charges  */
end_comment

begin_if
if|#
directive|if
name|MUSH
end_if

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/share.h"
end_include

begin_decl_stmt
name|struct
name|sh_consts
name|shconsts
init|=
block|{
literal|0
comment|/* flags */
block|,
literal|35
comment|/* maxnice */
block|,
literal|4.0
comment|/* usagefactor */
block|,
literal|2.0
comment|/* ratefactor */
block|,
literal|880
comment|/* syscall */
block|,
literal|500
comment|/* bio */
block|,
literal|11
comment|/* tio */
block|,
literal|1000
comment|/* tic */
block|,
literal|10
comment|/* click */
block|,
literal|300
comment|/* pgin */
block|,
literal|0
comment|/* current share per usage */
block|,
literal|0
comment|/* current share per rate */
block|,
name|USAGEK
comment|/* usage decay factor */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

