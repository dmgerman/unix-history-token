begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Driver initialization support  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni_var.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Initialize adapter for PDU processing  *  * Enable interrupts, set master control, initialize TX buffer,  * set initial pointers, etc.  *  * Arguments:  *	eup		pointer to device unit structure  *  * Returns:  *	0		successful  *	error		error condition  */
end_comment

begin_function
name|int
name|eni_init
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|u_long
name|words
decl_stmt|,
name|order
decl_stmt|;
comment|/* 	 * Allocate one large TX buffer. Currently we use only one 	 * channel with full cell rate which all VCs will use. 	 * This will (probably) have to change (alot) when we 	 * implement QoS. 	 */
comment|/* 	 * Server cards, which have more then 512KB of RAM, will 	 * allocate a 128KB TX buffer, while client cards, with 	 * 512KB or less will allocate a 32KB TX buffer. 	 */
name|words
operator|=
operator|(
name|eup
operator|->
name|eu_ramsize
operator|>
name|MAX_CLIENT_RAM
operator|*
name|ENI_BUF_PGSZ
condition|?
name|TX_LARGE_BSIZE
else|:
name|TX_SMALL_BSIZE
operator|)
operator|*
name|ENI_BUF_PGSZ
expr_stmt|;
if|if
condition|(
operator|(
name|eup
operator|->
name|eu_txbuf
operator|=
name|eni_allocate_buffer
argument_list|(
name|eup
argument_list|,
operator|&
name|words
argument_list|)
operator|)
operator|==
operator|(
name|caddr_t
operator|)
name|NULL
condition|)
block|{
return|return
name|ENOMEM
return|;
block|}
name|eup
operator|->
name|eu_txsize
operator|=
name|words
operator|>>
literal|2
expr_stmt|;
comment|/* Bytes to words */
name|words
operator|>>=
name|ENI_LOC_PREDIV
expr_stmt|;
comment|/* Predivide by 256 words */
for|for
control|(
name|order
operator|=
operator|-
literal|1
init|;
name|words
condition|;
name|order
operator|++
control|)
name|words
operator|>>=
literal|1
expr_stmt|;
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_TXPLACE
index|]
operator|=
operator|(
name|order
operator|<<
name|TXSIZE_SHIFT
operator|)
operator||
operator|(
operator|(
name|int
operator|)
name|eup
operator|->
name|eu_txbuf
operator|>>
name|ENI_LOC_PREDIV
operator|)
expr_stmt|;
name|eup
operator|->
name|eu_txpos
operator|=
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_DESCR
index|]
operator|&
literal|0x7FFF
expr_stmt|;
comment|/* 	 * Set first word of unack'ed data to start 	 */
name|eup
operator|->
name|eu_txfirst
operator|=
name|eup
operator|->
name|eu_txpos
expr_stmt|;
comment|/* 	 * Set initial values of local DMA pointer used to prevent wraps 	 */
name|eup
operator|->
name|eu_txdmawr
operator|=
literal|0
expr_stmt|;
name|eup
operator|->
name|eu_rxdmawr
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Initialize queue's for receive/transmit pdus 	 */
name|eup
operator|->
name|eu_txqueue
operator|.
name|ifq_maxlen
operator|=
name|ENI_IFQ_MAXLEN
expr_stmt|;
name|eup
operator|->
name|eu_rxqueue
operator|.
name|ifq_maxlen
operator|=
name|ENI_IFQ_MAXLEN
expr_stmt|;
comment|/* 	 * Acknowledge any interrupts 	 */
operator|(
name|void
operator|)
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_ISA
index|]
expr_stmt|;
comment|/* 	 * "Zero" Sonet error counters 	 */
name|eni_zero_stats
argument_list|(
name|eup
argument_list|)
expr_stmt|;
comment|/* 	 * Set master control register 	 * 	 * IntSel1 | LOCK_MODE | DMA_ENABLE | TX_ENABLE | RX_ENABLE 	 * 	 */
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_MASTER
index|]
operator|=
literal|1
operator|<<
name|ENI_ISEL_SHIFT
operator||
name|ENI_M_DMAENABLE
operator||
name|ENI_M_TXENABLE
operator||
name|ENI_M_RXENABLE
expr_stmt|;
comment|/* 	 * Enable interrupts 	 */
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_IE
index|]
operator|=
name|ENI_INT_SERVICE
operator||
name|ENI_INT_RX_DMA
operator||
name|ENI_INT_TX_DMA
operator||
name|ENI_INT_DMA_ERR
operator||
name|ENI_INT_DMA_LERR
operator||
name|ENI_INT_IDEN
operator||
name|ENI_INT_DMA_OVFL
expr_stmt|;
comment|/* 	 * Last thing to do is to indicate that we've finished initializing 	 * this unit. 	 */
name|eup
operator|->
name|eu_flags
operator||=
name|CUF_INITED
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

