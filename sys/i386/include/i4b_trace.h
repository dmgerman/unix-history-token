begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_trace.h - header file for trace data read device  *	----------------------------------------------------  *  * $FreeBSD$  *  *      last edit-date: [Sun Mar 17 10:10:52 2002]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_TRACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_TRACE_H_
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	structure of the header at the beginning of every trace mbuf  *---------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|length
decl_stmt|;
comment|/* length of the following mbuf		*/
name|int
name|unit
decl_stmt|;
comment|/* controller unit number		*/
name|int
name|type
decl_stmt|;
comment|/* type of channel			*/
define|#
directive|define
name|TRC_CH_I
value|0
comment|/* Layer 1 INFO's		*/
define|#
directive|define
name|TRC_CH_D
value|1
comment|/* D channel 			*/
define|#
directive|define
name|TRC_CH_B1
value|2
comment|/* B1 channel			*/
define|#
directive|define
name|TRC_CH_B2
value|3
comment|/* B2 channel			*/
name|int
name|dir
decl_stmt|;
comment|/* direction 				*/
define|#
directive|define
name|FROM_TE
value|0
comment|/* user -> network		*/
define|#
directive|define
name|FROM_NT
value|1
comment|/* network -> user		*/
name|int
name|trunc
decl_stmt|;
comment|/* # of truncated bytes (frame> MCLBYTES) */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* frame count for this unit/type	*/
name|struct
name|timeval
name|time
decl_stmt|;
comment|/* timestamp for this frame		*/
block|}
name|i4b_trace_hdr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INFO0
value|0
end_define

begin_comment
comment|/* layer 1 */
end_comment

begin_define
define|#
directive|define
name|INFO1_8
value|1
end_define

begin_define
define|#
directive|define
name|INFO1_10
value|2
end_define

begin_define
define|#
directive|define
name|INFO2
value|3
end_define

begin_define
define|#
directive|define
name|INFO3
value|4
end_define

begin_define
define|#
directive|define
name|INFO4_8
value|5
end_define

begin_define
define|#
directive|define
name|INFO4_10
value|6
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  * 	ioctl via /dev/i4btrc device(s):  *	get/set current trace flag settings  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|I4B_TRC_SET
value|_IOW('T', 0, int)
end_define

begin_comment
comment|/* set trace settings	*/
end_comment

begin_define
define|#
directive|define
name|TRACE_OFF
value|0x00
end_define

begin_comment
comment|/* tracing off 		*/
end_comment

begin_define
define|#
directive|define
name|TRACE_I
value|0x01
end_define

begin_comment
comment|/* trace L1 INFO's on	*/
end_comment

begin_define
define|#
directive|define
name|TRACE_D_TX
value|0x02
end_define

begin_comment
comment|/* trace D channel on	*/
end_comment

begin_define
define|#
directive|define
name|TRACE_D_RX
value|0x04
end_define

begin_comment
comment|/* trace D channel on	*/
end_comment

begin_define
define|#
directive|define
name|TRACE_B_TX
value|0x08
end_define

begin_comment
comment|/* trace B channel on	*/
end_comment

begin_define
define|#
directive|define
name|TRACE_B_RX
value|0x10
end_define

begin_comment
comment|/* trace B channel on	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rxunit
decl_stmt|;
comment|/* unit # for rx frames	*/
name|int
name|rxflags
decl_stmt|;
comment|/* d and/or b channel	*/
name|int
name|txunit
decl_stmt|;
comment|/* unit # for tx frames */
name|int
name|txflags
decl_stmt|;
comment|/* d and/or b channel	*/
block|}
name|i4b_trace_setupa_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I4B_TRC_SETA
value|_IOW('T', 1, i4b_trace_setupa_t)
end_define

begin_comment
comment|/* set analyze mode */
end_comment

begin_define
define|#
directive|define
name|I4B_TRC_RESETA
value|_IOW('T', 2, int)
end_define

begin_comment
comment|/* reset analyze mode	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_TRACE_H_ */
end_comment

end_unit

