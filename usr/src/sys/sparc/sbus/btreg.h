begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)btreg.h	8.2 (Berkeley) 1/21/94  *  * from: $Header: btreg.h,v 1.1 93/10/12 15:28:52 torek Exp $  */
end_comment

begin_comment
comment|/*  * Several Sun color frame buffers use some kind of Brooktree video  * DAC (e.g., the Bt458, -- in any case, Brooktree make the only  * decent color frame buffer chips).  *  * Color map control on these is a bit funky in a SPARCstation.  * To update the color map one would normally do byte writes, but  * the hardware takes longword writes.  Since there are three  * registers for each color map entry (R, then G, then B), we have  * to set color 1 with a write to address 0 (setting 0's R/G/B and  * color 1's R) followed by a second write to address 1 (setting  * color 1's G/B and color 2's R/G).  Software must therefore keep  * a copy of the current map.  *  * The colormap address register increments automatically, so the  * above write is done as:  *  *	bt->bt_addr = 0;  *	bt->bt_cmap = R0G0B0R1;  *	bt->bt_cmap = G1B1R2G2;  *	...  *  * Yow!  *  * Bonus complication: on the cg6, only the top 8 bits of each 32 bit  * register matter, even though the cg3 takes all the bits from all  * bytes written to it.  */
end_comment

begin_struct
struct|struct
name|bt_regs
block|{
name|u_int
name|bt_addr
decl_stmt|;
comment|/* map address register */
name|u_int
name|bt_cmap
decl_stmt|;
comment|/* colormap data register */
name|u_int
name|bt_ctrl
decl_stmt|;
comment|/* control register */
name|u_int
name|bt_omap
decl_stmt|;
comment|/* overlay (cursor) map register */
block|}
struct|;
end_struct

end_unit

