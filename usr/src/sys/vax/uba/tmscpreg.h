begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tmscpreg.h	7.2 (Berkeley) 5/9/91  */
end_comment

begin_comment
comment|/*	@(#)tmscpreg.h	1.1	11/2/84	84/09/25	*/
end_comment

begin_comment
comment|/****************************************************************  *								*  *        Licensed from Digital Equipment Corporation 		*  *                       Copyright (c) 				*  *               Digital Equipment Corporation			*  *                   Maynard, Massachusetts 			*  *                         1985, 1986 				*  *                    All rights reserved. 			*  *								*  *        The Information in this software is subject to change *  *   without notice and should not be construed as a commitment *  *   by  Digital  Equipment  Corporation.   Digital   makes  no *  *   representations about the suitability of this software for *  *   any purpose.  It is supplied "As Is" without expressed  or *  *   implied  warranty. 					*  *								*  *        If the Regents of the University of California or its *  *   licensees modify the software in a manner creating  	*  *   diriviative copyright rights, appropriate copyright  	*  *   legends may be placed on  the drivative work in addition   *  *   to that set forth above. 					*  *								*  ****************************************************************/
end_comment

begin_comment
comment|/*  * TMSCP registers and structures  */
end_comment

begin_struct
struct|struct
name|tmscpdevice
block|{
name|short
name|tmscpip
decl_stmt|;
comment|/* initialization and polling */
name|short
name|tmscpsa
decl_stmt|;
comment|/* status and address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TMSCP_ERR
value|0100000
end_define

begin_comment
comment|/* error bit */
end_comment

begin_define
define|#
directive|define
name|TMSCP_STEP4
value|0040000
end_define

begin_comment
comment|/* step 4 has started */
end_comment

begin_define
define|#
directive|define
name|TMSCP_STEP3
value|0020000
end_define

begin_comment
comment|/* step 3 has started */
end_comment

begin_define
define|#
directive|define
name|TMSCP_STEP2
value|0010000
end_define

begin_comment
comment|/* step 2 has started */
end_comment

begin_define
define|#
directive|define
name|TMSCP_STEP1
value|0004000
end_define

begin_comment
comment|/* step 1 has started */
end_comment

begin_define
define|#
directive|define
name|TMSCP_NV
value|0002000
end_define

begin_comment
comment|/* no host settable interrupt vector */
end_comment

begin_define
define|#
directive|define
name|TMSCP_QB
value|0001000
end_define

begin_comment
comment|/* controller supports Q22 bus */
end_comment

begin_define
define|#
directive|define
name|TMSCP_DI
value|0000400
end_define

begin_comment
comment|/* controller implements diagnostics */
end_comment

begin_define
define|#
directive|define
name|TMSCP_OD
value|0000200
end_define

begin_comment
comment|/* port allows odd host addr's in the buffer descriptor */
end_comment

begin_define
define|#
directive|define
name|TMSCP_IE
value|0000200
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TMSCP_MP
value|0000100
end_define

begin_comment
comment|/* port supports address mapping */
end_comment

begin_define
define|#
directive|define
name|TMSCP_LF
value|0000002
end_define

begin_comment
comment|/* host requests last fail response packet */
end_comment

begin_define
define|#
directive|define
name|TMSCP_PI
value|0000001
end_define

begin_comment
comment|/* host requests adapter purge interrupts */
end_comment

begin_define
define|#
directive|define
name|TMSCP_GO
value|0000001
end_define

begin_comment
comment|/* start operation, after init */
end_comment

begin_comment
comment|/*  * TMSCP Communications Area  */
end_comment

begin_struct
struct|struct
name|tmscpca
block|{
name|short
name|ca_xxx1
decl_stmt|;
comment|/* unused */
name|char
name|ca_xxx2
decl_stmt|;
comment|/* unused */
name|char
name|ca_bdp
decl_stmt|;
comment|/* BDP to purge */
name|short
name|ca_cmdint
decl_stmt|;
comment|/* command queue transition interrupt flag */
name|short
name|ca_rspint
decl_stmt|;
comment|/* response queue transition interrupt flag */
name|long
name|ca_rspdsc
index|[
name|NRSP
index|]
decl_stmt|;
comment|/* response descriptors */
name|long
name|ca_cmddsc
index|[
name|NCMD
index|]
decl_stmt|;
comment|/* command descriptors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ca_ringbase
value|ca_rspdsc[0]
end_define

begin_define
define|#
directive|define
name|TMSCP_OWN
value|0x80000000
end_define

begin_comment
comment|/* port owns this descriptor (else host  owns it) */
end_comment

begin_define
define|#
directive|define
name|TMSCP_INT
value|0x40000000
end_define

begin_comment
comment|/* allow interrupt on ring transition */
end_comment

begin_define
define|#
directive|define
name|TMSCP_MAP
value|0x80000000
end_define

begin_comment
comment|/* modifier for mapped buffer descriptors */
end_comment

begin_comment
comment|/*  * TMSCP packet info (same as MSCP)  */
end_comment

begin_struct
struct|struct
name|mscp_header
block|{
name|short
name|tmscp_msglen
decl_stmt|;
comment|/* length of MSCP packet */
name|char
name|tmscp_credits
decl_stmt|;
comment|/* low 4 bits: credits, high 4 bits: msgtype */
name|char
name|tmscp_vcid
decl_stmt|;
comment|/* virtual circuit id (connection id) */
block|}
struct|;
end_struct

end_unit

