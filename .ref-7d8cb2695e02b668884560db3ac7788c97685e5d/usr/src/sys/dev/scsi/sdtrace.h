begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratories.  *  * %sccs.include.redist.c%  *  *	@(#)sdtrace.h	5.3 (Berkeley) %G%  *  * from: $Header: sdtrace.h,v 1.6 92/12/02 03:53:47 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * SCSI disk command tracing  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SDTRACE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|KERNEL
argument_list|)
end_if

begin_struct
struct|struct
name|sdtrace
block|{
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* timestamp */
name|u_int
name|block
decl_stmt|;
comment|/* disk block */
name|u_int
name|bcount
decl_stmt|;
comment|/* # bytes transferred */
name|u_char
name|tcode
decl_stmt|;
comment|/* trace code */
name|u_char
name|target
decl_stmt|;
comment|/* target number */
name|u_char
name|unit
decl_stmt|;
comment|/* unit number on target */
name|u_char
name|read
decl_stmt|;
comment|/* read operation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T_START
value|0x01
end_define

begin_define
define|#
directive|define
name|T_MKCDB
value|0x02
end_define

begin_define
define|#
directive|define
name|T_INTR
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SDTRACE
end_ifdef

begin_comment
comment|/* Allow kernel config to override number of entries */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NSDOPBUF
end_ifndef

begin_define
define|#
directive|define
name|NSDOPBUF
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|sdtrace
name|sdopbuf
index|[
name|NSDOPBUF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|sdtrace
modifier|*
name|sdopptr
init|=
name|sdopbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nsdopbuf
init|=
name|NSDOPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for sdtrace */
end_comment

begin_decl_stmt
name|u_long
name|sdopcnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SD_TRACE
parameter_list|(
name|code
parameter_list|,
name|sc
parameter_list|,
name|bp
parameter_list|)
value|{ \ 	if (++sdopptr>=&sdopbuf[NSDOPBUF]) \ 		sdopptr = sdopbuf; \ 	microtime(&sdopptr->time); \ 	sdopptr->tcode = code; \ 	sdopptr->read = bp->b_flags& B_READ; \ 	sdopptr->block = bp->b_blkno; \ 	sdopptr->bcount = bp->b_bcount; \ 	sdopptr->target = sc->sc_unit.u_targ; \ 	sdopptr->unit = sc->sc_unit.u_unit; \ 	++sdopcnt; \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SD_TRACE
parameter_list|(
name|code
parameter_list|,
name|sc
parameter_list|,
name|bp
parameter_list|)
value|{ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

