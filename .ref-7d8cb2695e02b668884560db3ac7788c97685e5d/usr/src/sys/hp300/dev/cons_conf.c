begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cons_conf.c 1.1 92/01/21  *  *	@(#)cons_conf.c	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This entire table could be autoconfig()ed but that would mean that  * the kernel's idea of the console would be out of sync with that of  * the standalone boot.  I think it best that they both use the same  * known algorithm unless we see a pressing need otherwise.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<hp/dev/cons.h>
end_include

begin_include
include|#
directive|include
file|"ite.h"
end_include

begin_include
include|#
directive|include
file|"dca.h"
end_include

begin_include
include|#
directive|include
file|"dcm.h"
end_include

begin_if
if|#
directive|if
name|NITE
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|int
name|itecnprobe
argument_list|()
decl_stmt|,
name|itecninit
argument_list|()
decl_stmt|,
name|itecngetc
argument_list|()
decl_stmt|,
name|itecnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NDCA
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|int
name|dcacnprobe
argument_list|()
decl_stmt|,
name|dcacninit
argument_list|()
decl_stmt|,
name|dcacngetc
argument_list|()
decl_stmt|,
name|dcacnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NDCM
operator|>
literal|0
end_if

begin_decl_stmt
specifier|extern
name|int
name|dcmcnprobe
argument_list|()
decl_stmt|,
name|dcmcninit
argument_list|()
decl_stmt|,
name|dcmcngetc
argument_list|()
decl_stmt|,
name|dcmcnputc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|consdev
name|constab
index|[]
init|=
block|{
if|#
directive|if
name|NITE
operator|>
literal|0
block|{
name|itecnprobe
block|,
name|itecninit
block|,
name|itecngetc
block|,
name|itecnputc
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|NDCA
operator|>
literal|0
block|{
name|dcacnprobe
block|,
name|dcacninit
block|,
name|dcacngetc
block|,
name|dcacnputc
block|}
block|,
endif|#
directive|endif
if|#
directive|if
name|NDCM
operator|>
literal|0
block|{
name|dcmcnprobe
block|,
name|dcmcninit
block|,
name|dcmcngetc
block|,
name|dcmcnputc
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

end_unit

