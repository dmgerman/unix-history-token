begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: scu.h,v 4.300 91/07/02 16:38:38 root Rel41 $ SONY  *  *	@(#)scu.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * screg.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SCU__
end_ifndef

begin_define
define|#
directive|define
name|__SCU__
value|1
end_define

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|RAWSCSI_USE_PIO
value|0
end_define

begin_define
define|#
directive|define
name|RAWSCSI_USE_DMA
value|1
end_define

begin_define
define|#
directive|define
name|SCSIIOCCMD
value|_IOWR('S', 0, struct sc_ureq)
end_define

begin_define
define|#
directive|define
name|SCSIIOCGTIMEO
value|_IOR('S', 1, int)
end_define

begin_define
define|#
directive|define
name|SCSIIOCSTIMEO
value|_IOW('S', 2, int)
end_define

begin_comment
comment|/*  *	scsi user request parameter block  */
end_comment

begin_struct
struct|struct
name|sc_ureq
block|{
comment|/*00*/
name|u_int
name|scu_istatus
decl_stmt|;
comment|/*04*/
name|u_int
name|scu_tstatus
decl_stmt|;
comment|/*08*/
name|u_int
name|scu_identify
decl_stmt|;
comment|/*0c*/
name|u_int
name|scu_message
decl_stmt|;
comment|/*10*/
name|u_int
name|scu_bytesec
decl_stmt|;
comment|/*14*/
name|u_char
name|scu_cdb
index|[
literal|12
index|]
decl_stmt|;
comment|/*20*/
name|u_char
name|scu_param
index|[
literal|20
index|]
decl_stmt|;
comment|/*34*/
name|u_char
modifier|*
name|scu_addr
decl_stmt|;
comment|/*38*/
name|u_int
name|scu_count
decl_stmt|;
comment|/*3c*/
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__SCU__ */
end_comment

end_unit

