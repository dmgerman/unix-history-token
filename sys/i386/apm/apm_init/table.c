begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * APM (Advanced Power Management) BIOS Device Driver  *  * Copyright (c) 1994-1995 by HOSOKAWA, Tatsumi<hosokawa@jp.FreeBSD.org>  *  * This software may be used, modified, copied, and distributed, in  * both source and binary form provided that the above copyright and  * these terms are retained. Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with its  * use.  *  * Sep., 1994	Implemented on FreeBSD 1.1.5.1R (Toshiba AVS001WD)  *  *	$Id: table.c,v 1.4 1995/05/30 07:58:18 rgrimes Exp $  */
end_comment

begin_include
include|#
directive|include
file|<apm_bios.h>
end_include

begin_struct
struct|struct
name|pseudo_desc
block|{
name|unsigned
name|short
name|limit
decl_stmt|;
name|unsigned
name|long
name|base
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|pseudo_desc
name|Idtr_prot
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filled on run time */
end_comment

begin_decl_stmt
name|struct
name|pseudo_desc
name|Idtr_real
init|=
block|{
literal|0x400
operator|-
literal|1
block|,
literal|0x0
block|}
decl_stmt|;
end_decl_stmt

end_unit

