begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: sd_var.c,v 4.300 91/06/09 06:38:23 root Rel41 $ SONY  *  *	@(#)sd_var.c	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989 by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	sd_var.c - SCSI disk device driver  *			variable definition file.  */
end_comment

begin_include
include|#
directive|include
file|"sd.h"
end_include

begin_if
if|#
directive|if
name|NSD
operator|>
literal|0
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<news3400/iodev/scsireg.h>
end_include

begin_include
include|#
directive|include
file|<news3400/iodev/sdreg.h>
end_include

begin_decl_stmt
name|struct
name|iop
comment|/**/
name|_ctlr
modifier|*
name|sdminfo
index|[
name|NSDC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iop
comment|/**/
name|_device
modifier|*
name|sddinfo
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|iop
comment|/**/
name|_device
modifier|*
name|sdip
index|[
name|NSDC
index|]
index|[
name|MAXSLAVE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|rsdbuf
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for raw I/O */
end_comment

begin_decl_stmt
name|struct
name|buf
name|csdbuf
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for controll */
end_comment

begin_decl_stmt
name|struct
name|buf
name|sdutab
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* per drive buffers */
end_comment

begin_decl_stmt
name|struct
name|sdc_softc
name|sdc_softc
index|[
name|NSDC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sdd_softc
name|sdd_softc
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|sd_b_openf
index|[
name|NSD
index|]
index|[
name|PNUM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|sd_c_openf
index|[
name|NSD
index|]
index|[
name|PNUM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|scsi
name|kernscsi
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sdst
name|sdstdrv
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|disklabel
name|sdlabel
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|size
name|sdsizedrv
index|[
name|NSD
index|]
index|[
name|PNUM
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|sdc_rsense
index|[
name|NSDC
index|]
index|[
name|RSEN_CNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sync_param
name|sd_sync_param
index|[
name|NSD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsd
init|=
name|NSD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsdc
init|=
name|NSDC
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NSD> 0 */
end_comment

end_unit

