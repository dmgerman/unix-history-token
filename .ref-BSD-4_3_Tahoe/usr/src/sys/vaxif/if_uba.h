begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_uba.h	7.2 (Berkeley) 8/9/86  */
end_comment

begin_comment
comment|/*  * Structure and routine definitions  * for UNIBUS network interfaces.  */
end_comment

begin_define
define|#
directive|define
name|IF_MAXNUBAMR
value|10
end_define

begin_comment
comment|/*  * Each interface has structures giving information  * about UNIBUS resources held by the interface  * for each send and receive buffer.  *  * We hold IF_NUBAMR map registers for datagram data, starting  * at ifr_mr.  Map register ifr_mr[-1] maps the local network header  * ending on the page boundary.  Bdp's are reserved for read and for  * write, given by ifr_bdp.  The prototype of the map register for  * read and for write is saved in ifr_proto.  *  * When write transfers are not full pages on page boundaries we just  * copy the data into the pages mapped on the UNIBUS and start the  * transfer.  If a write transfer is of a (1024 byte) page on a page  * boundary, we swap in UNIBUS pte's to reference the pages, and then  * remap the initial pages (from ifu_wmap) when the transfer completes.  *  * When read transfers give whole pages of data to be input, we  * allocate page frames from a network page list and trade them  * with the pages already containing the data, mapping the allocated  * pages to replace the input pages for the next UNIBUS data input.  */
end_comment

begin_comment
comment|/*  * Information per interface.  */
end_comment

begin_struct
struct|struct
name|ifubinfo
block|{
name|short
name|iff_uban
decl_stmt|;
comment|/* uba number */
name|short
name|iff_hlen
decl_stmt|;
comment|/* local net header length */
name|struct
name|uba_regs
modifier|*
name|iff_uba
decl_stmt|;
comment|/* uba adaptor regs, in vm */
name|struct
name|pte
modifier|*
name|iff_ubamr
decl_stmt|;
comment|/* uba map regs, in vm */
name|short
name|iff_flags
decl_stmt|;
comment|/* used during uballoc's */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information per buffer.  */
end_comment

begin_struct
struct|struct
name|ifrw
block|{
name|caddr_t
name|ifrw_addr
decl_stmt|;
comment|/* virt addr of header */
name|short
name|ifrw_bdp
decl_stmt|;
comment|/* unibus bdp */
name|short
name|ifrw_flags
decl_stmt|;
comment|/* type, etc. */
define|#
directive|define
name|IFRW_W
value|0x01
comment|/* is a transmit buffer */
name|int
name|ifrw_info
decl_stmt|;
comment|/* value from ubaalloc */
name|int
name|ifrw_proto
decl_stmt|;
comment|/* map register prototype */
name|struct
name|pte
modifier|*
name|ifrw_mr
decl_stmt|;
comment|/* base of map registers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information per transmit buffer, including the above.  */
end_comment

begin_struct
struct|struct
name|ifxmt
block|{
name|struct
name|ifrw
name|ifrw
decl_stmt|;
name|caddr_t
name|ifw_base
decl_stmt|;
comment|/* virt addr of buffer */
name|struct
name|pte
name|ifw_wmap
index|[
name|IF_MAXNUBAMR
index|]
decl_stmt|;
comment|/* base pages for output */
name|struct
name|mbuf
modifier|*
name|ifw_xtofree
decl_stmt|;
comment|/* pages being dma'd out */
name|short
name|ifw_xswapd
decl_stmt|;
comment|/* mask of clusters swapped */
name|short
name|ifw_nmr
decl_stmt|;
comment|/* number of entries in wmap */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifw_addr
value|ifrw.ifrw_addr
end_define

begin_define
define|#
directive|define
name|ifw_bdp
value|ifrw.ifrw_bdp
end_define

begin_define
define|#
directive|define
name|ifw_flags
value|ifrw.ifrw_flags
end_define

begin_define
define|#
directive|define
name|ifw_info
value|ifrw.ifrw_info
end_define

begin_define
define|#
directive|define
name|ifw_proto
value|ifrw.ifrw_proto
end_define

begin_define
define|#
directive|define
name|ifw_mr
value|ifrw.ifrw_mr
end_define

begin_comment
comment|/*  * Most interfaces have a single receive and a single transmit buffer,  * and use struct ifuba to store all of the unibus information.  */
end_comment

begin_struct
struct|struct
name|ifuba
block|{
name|struct
name|ifubinfo
name|ifu_info
decl_stmt|;
name|struct
name|ifrw
name|ifu_r
decl_stmt|;
name|struct
name|ifxmt
name|ifu_xmt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifu_uban
value|ifu_info.iff_uban
end_define

begin_define
define|#
directive|define
name|ifu_hlen
value|ifu_info.iff_hlen
end_define

begin_define
define|#
directive|define
name|ifu_uba
value|ifu_info.iff_uba
end_define

begin_define
define|#
directive|define
name|ifu_ubamr
value|ifu_info.iff_ubamr
end_define

begin_define
define|#
directive|define
name|ifu_flags
value|ifu_info.iff_flags
end_define

begin_define
define|#
directive|define
name|ifu_w
value|ifu_xmt.ifrw
end_define

begin_define
define|#
directive|define
name|ifu_xtofree
value|ifu_xmt.ifw_xtofree
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|if_ubainit
parameter_list|(
name|ifuba
parameter_list|,
name|uban
parameter_list|,
name|hlen
parameter_list|,
name|nmr
parameter_list|)
define|\
value|if_ubaminit(&(ifuba)->ifu_info, uban, hlen, nmr, \&(ifuba)->ifu_r, 1,&(ifuba)->ifu_xmt, 1)
end_define

begin_define
define|#
directive|define
name|if_rubaget
parameter_list|(
name|ifu
parameter_list|,
name|totlen
parameter_list|,
name|off0
parameter_list|,
name|ifp
parameter_list|)
define|\
value|if_ubaget(&(ifu)->ifu_info,&(ifu)->ifu_r, totlen, off0, ifp)
end_define

begin_define
define|#
directive|define
name|if_wubaput
parameter_list|(
name|ifu
parameter_list|,
name|m
parameter_list|)
define|\
value|if_ubaput(&(ifu)->ifu_info,&(ifu)->ifu_xmt, m)
end_define

begin_function_decl
name|struct
name|mbuf
modifier|*
name|if_ubaget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

