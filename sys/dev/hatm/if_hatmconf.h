begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Default configuration  */
end_comment

begin_comment
comment|/* configuration */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_VPI_BITS
value|2
end_define

begin_define
define|#
directive|define
name|HE_CONFIG_VCI_BITS
value|10
end_define

begin_comment
comment|/* interrupt group 0 only */
end_comment

begin_comment
comment|/* the size must be 1<= size<= 1023 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_IRQ0_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|HE_CONFIG_IRQ0_THRESH
value|224
end_define

begin_comment
comment|/* retrigger interrupt */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_IRQ0_LINE
value|HE_REGM_IRQ_A
end_define

begin_comment
comment|/* routing */
end_comment

begin_comment
comment|/* don't change these */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TXMEM
value|(128 * 1024)
end_define

begin_comment
comment|/* words */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RXMEM
value|(64 * 1024)
end_define

begin_comment
comment|/* words */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_LCMEM
value|(512 * 1024)
end_define

begin_comment
comment|/* words */
end_comment

begin_comment
comment|/* group 0 - all AALs except AAL.raw */
end_comment

begin_comment
comment|/* receive group 0 buffer pools (mbufs and mbufs+cluster) */
end_comment

begin_comment
comment|/* the size must be a power of 2: 4<= size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPS0_SIZE
value|2048
end_define

begin_comment
comment|/* entries per queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPS0_THRESH
value|256
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPL0_SIZE
value|512
end_define

begin_comment
comment|/* entries per queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPL0_THRESH
value|32
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_comment
comment|/* receive group 0 buffer return queue */
end_comment

begin_comment
comment|/* the size must be a power of 2: 1<= size<= 16384 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ0_SIZE
value|512
end_define

begin_comment
comment|/* entries in queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ0_THRESH
value|256
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ0_TOUT
value|10
end_define

begin_comment
comment|/* interrupt timeout */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ0_PCNT
value|5
end_define

begin_comment
comment|/* packet count threshold */
end_comment

begin_comment
comment|/* group 1 - raw cells */
end_comment

begin_comment
comment|/* receive group 1 small buffer pool */
end_comment

begin_comment
comment|/* the size must be a power of 2: 4<= size<= 8192 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPS1_SIZE
value|1024
end_define

begin_comment
comment|/* entries in queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBPS1_THRESH
value|512
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_comment
comment|/* receive group 1 buffer return queue */
end_comment

begin_comment
comment|/* the size must be a power of 2: 1<= size<= 16384 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ1_SIZE
value|512
end_define

begin_comment
comment|/* entries in queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ1_THRESH
value|256
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ1_TOUT
value|100
end_define

begin_comment
comment|/* interrupt timeout */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_RBRQ1_PCNT
value|25
end_define

begin_comment
comment|/* packet count threshold */
end_comment

begin_comment
comment|/* there is only one TPD queue */
end_comment

begin_comment
comment|/* the size must be a power of 2: 1<= size<= 4096 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TPDRQ_SIZE
value|2048
end_define

begin_comment
comment|/* entries in queue */
end_comment

begin_comment
comment|/* transmit group 0 */
end_comment

begin_comment
comment|/* the size must be a power of 2: 1<= size<= 16384 */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TBRQ_SIZE
value|512
end_define

begin_comment
comment|/* entries in queue */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TBRQ_THRESH
value|400
end_define

begin_comment
comment|/* interrupt threshold */
end_comment

begin_comment
comment|/* Maximum number of TPDs to allocate to a single VCC. This  * number should depend on the cell rate and the maximum allowed cell delay */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TPD_MAXCC
value|2048
end_define

begin_comment
comment|/* Maximum number of external mbuf pages */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_MAX_MBUF_PAGES
value|256
end_define

begin_comment
comment|/* Maximum number of TPDs used for one packet */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_MAX_TPD_PER_PACKET
define|\
value|((((HE_MAX_PDU + MCLBYTES - 1) / MCLBYTES + 2) / 3) + 2)
end_define

begin_comment
comment|/* Number of TPDs to reserve for close operations */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TPD_RESERVE
value|32
end_define

begin_comment
comment|/* Number of TPDs per VCC when to re-enable flow control */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_TPD_FLOW_ENB
value|80
end_define

begin_comment
comment|/* MCR for flushing CBR and ABR connections at close */
end_comment

begin_define
define|#
directive|define
name|HE_CONFIG_FLUSH_RATE
value|200000
end_define

end_unit

