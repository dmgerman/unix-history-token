begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Interrupt processing  *  */
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
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
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
file|<dev/hea/eni_suni.h>
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

begin_function_decl
specifier|static
name|void
name|eni_suni_intr
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * SUNI Interrupt processing  *  * Currently, we don't do anything more then clear the interrupt  * for the SUNI chip.  *  * Arguments:  *	eup		pointer to device unit structure  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|eni_suni_intr
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|int
name|SuniInt
decl_stmt|;
name|int
name|val
decl_stmt|;
name|SuniInt
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_IS_REG
index|]
expr_stmt|;
comment|/* RSOPI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_RSOPI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_RSOP_REG
index|]
expr_stmt|;
comment|/* RLOPI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_RLOPI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_RLOP_REG
index|]
expr_stmt|;
comment|/* RPOPI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_RPOPI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_RPOP_IS_REG
index|]
expr_stmt|;
comment|/* RACPI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_RACPI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_RACP_REG
index|]
expr_stmt|;
comment|/* TACPI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_TACPI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_TACP_REG
index|]
expr_stmt|;
comment|/* TROOLI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_TROOLI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_CLOCK_REG
index|]
expr_stmt|;
comment|/* LCDI */
comment|/* Cleared when reading Master Interrupt Status Reg */
comment|/* RDOOLI */
if|if
condition|(
name|SuniInt
operator|&
name|SUNI_RDOOLI
condition|)
name|val
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_CLOCK_REG
index|]
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * Device interrupt routine  *  * Service an interrupt from this device  *  * Arguments:  *	eup		pointer to device unit structure  *  * Returns:  *	none  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|BSD
operator|<
literal|199506
end_if

begin_function
name|int
else|#
directive|else
name|void
endif|#
directive|endif
name|eni_intr
parameter_list|(
name|arg
parameter_list|)
name|void
modifier|*
name|arg
decl_stmt|;
block|{
name|Eni_unit
modifier|*
name|eup
init|=
operator|(
name|Eni_unit
operator|*
operator|)
name|arg
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|BSD
operator|<
literal|199506
name|int
name|serviced
init|=
literal|1
decl_stmt|;
endif|#
directive|endif
comment|/* BSD< 199506 */
comment|/* 	 * Read and acknowledge any interrupts 	 */
name|u_long
name|mask
init|=
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_ISA
index|]
decl_stmt|;
comment|/* 	 * Read the error statistics counter 	 */
name|u_long
name|sval
init|=
name|eup
operator|->
name|eu_midway
index|[
name|MIDWAY_STAT
index|]
decl_stmt|;
comment|/* 	 * Update statistics from adapter 	 */
name|eup
operator|->
name|eu_trash
operator|+=
operator|(
name|sval
operator|>>
literal|16
operator|)
expr_stmt|;
name|eup
operator|->
name|eu_ovfl
operator|+=
operator|(
name|sval
operator|&
literal|0xffff
operator|)
expr_stmt|;
comment|/* 	 * We handle any DMA completes first so 	 * that we can free resources for use 	 * during transmit and especially receive 	 */
comment|/* 	 * Handle RX DMA Complete 	 */
if|if
condition|(
name|mask
operator|&
name|ENI_INT_RX_DMA
condition|)
block|{
name|eni_recv_drain
argument_list|(
name|eup
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Handle TX DMA Complete 	 */
if|if
condition|(
name|mask
operator|&
name|ENI_INT_TX_DMA
condition|)
block|{
name|eni_xmit_drain
argument_list|(
name|eup
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Look for any PDUs in service list 	 */
if|if
condition|(
name|mask
operator|&
name|ENI_INT_SERVICE
condition|)
block|{
name|eni_do_service
argument_list|(
name|eup
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Handle miscelaneous interrupts 	 */
if|if
condition|(
name|mask
operator|&
name|ENI_INT_STAT
condition|)
block|{
comment|/* STAT_OVFL */
name|log
argument_list|(
name|LOG_INFO
argument_list|,
literal|"eni_intr: stat_ovfl: 0x%lx\n"
argument_list|,
name|sval
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|ENI_INT_SUNI
condition|)
block|{
comment|/* SUNI_INTR */
name|eni_suni_intr
argument_list|(
name|eup
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|&
name|ENI_INT_DMA_ERR
condition|)
block|{
comment|/* DMA Error */
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"eni_intr: DMA Error\n"
argument_list|)
expr_stmt|;
comment|/* 		 * We don't know how to recover from DMA errors 		 * yet. The adapter has disabled any further 		 * processing and we're going to leave it like 		 * that. 		 */
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|BSD
operator|<
literal|199506
return|return
name|serviced
return|;
comment|/* Leave now */
else|#
directive|else
return|return;
comment|/* Leave now */
endif|#
directive|endif
block|}
if|if
condition|(
name|mask
operator|&
name|ENI_INT_IDEN
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"eni_intr: TX DMA Ident mismatch\n"
argument_list|)
expr_stmt|;
comment|/* 		 * Something in the TX buffer has really gotten messed 		 * up. Since this is most likely a driver bug, and 		 * the adapter has shut everything down, leave it 		 * like that. 		 */
if|#
directive|if
name|BSD
operator|<
literal|199506
return|return
literal|0
return|;
comment|/* Leave now */
else|#
directive|else
return|return;
comment|/* Leave now */
endif|#
directive|endif
block|}
if|if
condition|(
name|mask
operator|&
name|ENI_INT_DMA_OVFL
condition|)
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_drv
operator|.
name|drv_xm_dmaovfl
operator|++
expr_stmt|;
if|if
condition|(
name|mask
operator|&
name|ENI_INT_DMA_LERR
condition|)
block|{
name|log
argument_list|(
name|LOG_ERR
argument_list|,
literal|"eni_intr: DMA LERR\n"
argument_list|)
expr_stmt|;
if|#
directive|if
name|BSD
operator|<
literal|199506
return|return
literal|0
return|;
else|#
directive|else
return|return;
endif|#
directive|endif
block|}
if|#
directive|if
name|BSD
operator|<
literal|199506
return|return
literal|0
return|;
else|#
directive|else
return|return;
endif|#
directive|endif
block|}
end_function

end_unit

