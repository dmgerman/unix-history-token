begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: ncr53c500hwtab.h,v 1.2 1998/11/26 01:59:13 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|ncv_hw
name|ncv_template
init|=
block|{
literal|0
block|,
comment|/* CFG1 img */
name|C2_FE
operator||
name|C2_SCSI2
block|,
comment|/* CFG2 img */
literal|0
block|,
comment|/* CFG3 img */
name|C4_ANE
block|,
comment|/* CFG4 img */
literal|0x80
block|,
comment|/* CFG5 img */
name|CLK_40M_F
block|,
comment|/* clock */
literal|200
operator|/
literal|4
block|,
comment|/* max period */
literal|15
block|,
comment|/* max offset */
literal|0x10
block|,
comment|/* CFG3_FSCSI bit */
literal|0x08
block|,
comment|/* CFG3_FCLK bit */
block|}
decl_stmt|;
end_decl_stmt

end_unit

