begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: if_news.h,v 4.300 91/06/09 06:26:02 root Rel41 $ SONY  *  *	@(#)if_news.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Structure and routine definitions  * for NEWS network interfaces.  */
end_comment

begin_comment
comment|/*  * Each interface has one of these structures giving information  * about NEWS resources held by the interface.  */
end_comment

begin_struct
struct|struct
name|ifnews
block|{
name|int
name|ifn_hlen
decl_stmt|;
comment|/* local net header length */
name|caddr_t
name|ifn_raddr
decl_stmt|;
comment|/* receive buffer address */
name|caddr_t
name|ifn_waddr
decl_stmt|;
comment|/* transmit buffer address */
name|struct
name|mbuf
modifier|*
name|ifn_mbuf
decl_stmt|;
comment|/* packet being transmitted */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mbuf_segment
block|{
name|u_int
name|ms_physaddr
decl_stmt|;
name|u_int
name|ms_size
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|mbuf
modifier|*
name|if_rnewsget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LARGE_DATA
value|512
end_define

end_unit

