begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: msreg.h,v 4.300 91/06/09 06:43:00 root Rel41 $ SONY  *  *	@(#)msreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * mouse register structure definition.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MSREG__
end_ifndef

begin_define
define|#
directive|define
name|__MSREG__
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|msreg
block|{
comment|/*00*/
name|u_char
name|ms_control
decl_stmt|;
comment|/* CPU/IOP */
define|#
directive|define
name|MS_DONE
value|0x01
comment|/* IOP has completed command from CPU */
define|#
directive|define
name|MS_EVREADY
value|0x02
comment|/* IOP has made event report ready */
comment|/*01*/
name|u_char
name|ms_command
decl_stmt|;
comment|/* CPU */
define|#
directive|define
name|MS_CPROBE
value|0
define|#
directive|define
name|MS_CATTACH
value|1
define|#
directive|define
name|MS_CSAMPLE
value|2
comment|/* requset current value */
define|#
directive|define
name|MS_CSETEM
value|3
comment|/* set event mask */
define|#
directive|define
name|MS_CSETXY
value|4
comment|/* set current coordinate */
define|#
directive|define
name|MS_CSETPARAM
value|5
comment|/* set mouse parameter (mag, delta) */
define|#
directive|define
name|MS_CQFLUSH
value|6
comment|/* flush event queue */
define|#
directive|define
name|MS_CSETRANGE
value|7
comment|/* set coordinate range */
comment|/*02*/
name|u_char
name|ms_result
decl_stmt|;
comment|/* IOP */
define|#
directive|define
name|MS_ROK
value|0
comment|/* done */
define|#
directive|define
name|MS_RERROR
value|1
comment|/* failed */
define|#
directive|define
name|MS_REVENT
value|2
comment|/* event has occured */
comment|/*03*/
name|u_char
name|ms_eventmask
decl_stmt|;
comment|/* CPU */
comment|/*04*/
name|struct
name|ms_param
name|ms_param
decl_stmt|;
comment|/* CPU */
comment|/*0c*/
name|struct
name|ms_coord
name|ms_coord
decl_stmt|;
comment|/* CPU */
comment|/*14*/
name|struct
name|ms_data
name|ms_data
decl_stmt|;
comment|/* IOP */
comment|/*20*/
name|struct
name|ms_event
name|ms_event
decl_stmt|;
comment|/* IOP */
comment|/*38*/
name|int
name|ms_unit
decl_stmt|;
comment|/* CPU */
comment|/*3c*/
name|int
name|ms_sevcount
decl_stmt|;
comment|/*XXX*/
comment|/*40*/
name|struct
name|ms_range
name|ms_range
decl_stmt|;
comment|/* CPU */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MS_S_BYTE
value|0
end_define

begin_comment
comment|/* start byte */
end_comment

begin_define
define|#
directive|define
name|MS_X_BYTE
value|1
end_define

begin_comment
comment|/* second byte */
end_comment

begin_define
define|#
directive|define
name|MS_Y_BYTE
value|2
end_define

begin_comment
comment|/* third byte */
end_comment

begin_define
define|#
directive|define
name|MS_DB_SIZE
value|3
end_define

begin_define
define|#
directive|define
name|MS_S_MARK
value|0x80
end_define

begin_comment
comment|/* start mark (first byte)*/
end_comment

begin_define
define|#
directive|define
name|MS_S_X7
value|0x08
end_define

begin_comment
comment|/* MSB(sign bit) of X */
end_comment

begin_define
define|#
directive|define
name|MS_S_Y7
value|0x10
end_define

begin_comment
comment|/* MSB(sign bit) of Y */
end_comment

begin_define
define|#
directive|define
name|MS_S_SW1
value|0x01
end_define

begin_comment
comment|/* left button is pressed */
end_comment

begin_define
define|#
directive|define
name|MS_S_SW2
value|0x02
end_define

begin_comment
comment|/* right button is pressed */
end_comment

begin_define
define|#
directive|define
name|MS_S_SW3
value|0x04
end_define

begin_comment
comment|/* middle button is pressed */
end_comment

begin_define
define|#
directive|define
name|MS_X_X06
value|0x7f
end_define

begin_comment
comment|/* data bits of X (second byte) */
end_comment

begin_define
define|#
directive|define
name|MS_Y_Y06
value|0x7f
end_define

begin_comment
comment|/* data bits of Y (third byte) */
end_comment

begin_struct
struct|struct
name|ms_stat
block|{
name|int
name|mss_stat
decl_stmt|;
define|#
directive|define
name|MS_ACTIVE
value|0x01
define|#
directive|define
name|MS_WAIT
value|0x02
comment|/* waiting for command completion */
define|#
directive|define
name|MS_EVWAIT
value|0x04
comment|/* waiting for event report */
define|#
directive|define
name|MS_RCOLL
value|0x08
comment|/* select collsion on read */
define|#
directive|define
name|MS_WCOLL
value|0x10
comment|/* select collsion on write */
define|#
directive|define
name|MS_NBIO
value|0x20
comment|/* noblocked read write */
define|#
directive|define
name|MS_ASYNC
value|0x40
comment|/* if event queued then send SIGIO */
name|int
name|mss_pgrp
decl_stmt|;
name|int
name|mss_mode
decl_stmt|;
name|int
name|mss_command
decl_stmt|;
name|int
name|mss_eventmask
decl_stmt|;
name|struct
name|ms_data
name|mss_data
decl_stmt|;
name|struct
name|ms_data
name|mss_data_old
decl_stmt|;
name|struct
name|ms_param
name|mss_param
decl_stmt|;
name|struct
name|ms_range
name|mss_range
decl_stmt|;
name|struct
name|proc
modifier|*
name|mss_rsel
decl_stmt|;
name|struct
name|proc
modifier|*
name|mss_wsel
decl_stmt|;
name|struct
name|ms_queue
modifier|*
name|mss_queue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSPRI
value|(PZERO+1)
end_define

begin_define
define|#
directive|define
name|MSUNIT
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev)&017)
end_define

begin_define
define|#
directive|define
name|MSOLDIF
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev)&020)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__MSREG__ */
end_comment

end_unit

