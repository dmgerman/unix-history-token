begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: scc.h,v 4.300 91/06/09 06:44:56 root Rel41 $ SONY  *  *	@(#)scc.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|news3400
end_ifdef

begin_define
define|#
directive|define
name|splscc
value|spl4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCCWAIT
value|DELAY(2)
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE0
value|0
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE1
value|1
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE2
value|2
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE3
value|3
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE4
value|4
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE5
value|5
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE6
value|6
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE7
value|7
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE8
value|8
end_define

begin_define
define|#
directive|define
name|SCC_REMOTE9
value|9
end_define

begin_define
define|#
directive|define
name|SCCVEC0
value|64
end_define

begin_define
define|#
directive|define
name|SCCVEC1
value|(SCCVEC0+16)
end_define

begin_define
define|#
directive|define
name|SCCVEC2
value|(SCCVEC0+32)
end_define

begin_define
define|#
directive|define
name|SCCVEC3
value|(SCCVEC0+48)
end_define

begin_define
define|#
directive|define
name|SCCVEC4
value|(SCCVEC0+64)
end_define

begin_comment
comment|/*  *	SCC channel control block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|scc_dma
block|{
name|char
modifier|*
name|dma_addr
decl_stmt|;
name|int
name|dma_count
decl_stmt|;
block|}
name|Scc_dma
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|scc_channel
block|{
name|int
name|scc_status
decl_stmt|;
comment|/* channel status		*/
name|int
name|scc_param
decl_stmt|;
comment|/* channel parameter		*/
name|struct
name|scc_reg
modifier|*
name|scc_port
decl_stmt|;
comment|/* port address			*/
name|char
modifier|*
name|scc_init
decl_stmt|;
comment|/* initialize data		*/
name|int
name|scc_vec
decl_stmt|;
comment|/* interrupt vector		*/
name|Scc_dma
name|x_dma
decl_stmt|;
name|Scc_dma
name|r_dma
decl_stmt|;
block|}
name|Scc_channel
typedef|;
end_typedef

begin_comment
comment|/*  *	SCC channel status  */
end_comment

begin_define
define|#
directive|define
name|OACTIVE
value|0x00000001
end_define

begin_comment
comment|/* transmit in progress	*/
end_comment

begin_define
define|#
directive|define
name|OSTOP
value|0x00000002
end_define

begin_comment
comment|/* output stop request	*/
end_comment

begin_define
define|#
directive|define
name|OFLUSH
value|0x00000004
end_define

begin_comment
comment|/* output flush request	*/
end_comment

begin_define
define|#
directive|define
name|OBUSY
value|0x00000008
end_define

begin_comment
comment|/* output in use	*/
end_comment

begin_define
define|#
directive|define
name|LINE_BREAK
value|0x00000010
end_define

begin_comment
comment|/* line break interrupt	*/
end_comment

begin_define
define|#
directive|define
name|ENABLE
value|0x00000020
end_define

begin_comment
comment|/* receiver enable	*/
end_comment

begin_define
define|#
directive|define
name|CHAN_ACTIVE
value|0x80000000
end_define

begin_comment
comment|/* channel active	*/
end_comment

begin_comment
comment|/*  *	SCC channel usage  */
end_comment

begin_define
define|#
directive|define
name|SCC_MOUSE
value|0
end_define

begin_define
define|#
directive|define
name|SCC_KEYBOARD
value|1
end_define

end_unit

