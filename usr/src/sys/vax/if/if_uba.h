begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_uba.h	4.2	81/11/26	*/
end_comment

begin_comment
comment|/*  * Structure and routine definitions  * for UNIBUS network interfaces.  */
end_comment

begin_define
define|#
directive|define
name|IF_NUBAMR
value|6
end_define

begin_comment
comment|/*  * Each interface has one of these structures giving information  * about UNIBUS resources held by the interface.  *  * We hold IF_NUBAMR map registers for datagram data, starting  * at ifr_mr.  Map register ifr_mr[-1] maps the local network header  * ending on the page boundary.  Bdp's are reserved for read and for  * write, given by ifr_bdp.  The prototype of the map register for  * read and for write is saved in ifr_proto.  *  * When write transfers are not full pages on page boundaries we just  * copy the data into the pages mapped on the UNIBUS and start the  * transfer.  If a write transfer is of a (1024 byte) page on a page  * boundary, we swap in UNIBUS pte's to reference the pages, and then  * remap the initial pages (from ifu_wmap) when the transfer completes.  *  * When read transfers give whole pages of data to be input, we  * allocate page frames from a network page list and trade them  * with the pages already containing the data, mapping the allocated  * pages to replace the input pages for the next UNIBUS data input.  */
end_comment

begin_struct
struct|struct
name|ifuba
block|{
name|short
name|ifu_uban
decl_stmt|;
comment|/* uba number */
name|struct
name|uba_regs
modifier|*
name|ifu_uba
decl_stmt|;
comment|/* uba regs, in vm */
struct|struct
name|ifrw
block|{
name|int
name|ifrw_info
decl_stmt|;
comment|/* value from ubaalloc */
name|short
name|ifrw_bdp
decl_stmt|;
comment|/* unibus bdp */
name|struct
name|pte
modifier|*
name|ifrw_mr
decl_stmt|;
comment|/* base of map registers */
name|int
name|ifrw_proto
decl_stmt|;
comment|/* map register prototype */
name|caddr_t
name|ifrw_addr
decl_stmt|;
comment|/* virt addr of header */
block|}
name|ifu_r
struct|,
name|ifu_w
struct|;
name|struct
name|pte
name|ifu_wmap
index|[
name|IF_NUBAMR
index|]
decl_stmt|;
comment|/* base pages for output */
name|short
name|ifu_hlen
decl_stmt|;
comment|/* ifu_xswapd is set when we have swapped write pte's to do direct output */
comment|/* bit i of ifu_xswapd */
name|short
name|ifu_xswapd
decl_stmt|;
comment|/* bit map of pages swapped */
name|int
name|ifu_ierrors
decl_stmt|;
name|int
name|ifu_oerrors
decl_stmt|;
name|int
name|ifu_collisions
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
name|if_rubaget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

