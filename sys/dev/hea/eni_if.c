begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Network interface layer support  *  */
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
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/domain.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/netisr.h>
end_include

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
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
file|<netatm/atm_vc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_ioctl.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sigmgr.h>
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
file|<netatm/atm_var.h>
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

begin_decl_stmt
specifier|static
name|void
name|eni_get_stats
name|__P
argument_list|(
operator|(
name|Eni_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * SUNI statistics counters take one of three forms:  *	single byte value 	(0x0 - 0xff)  *	two byte value		(0x0 - 0xffff)  *	two + 1/2 (three) byte value  *				(0x0 - 0x0fffff)  */
end_comment

begin_define
define|#
directive|define
name|READ_ONE
parameter_list|(
name|x
parameter_list|)
value|( (eup->eu_suni[(x)]& 0xff) )
end_define

begin_define
define|#
directive|define
name|READ_TWO
parameter_list|(
name|x
parameter_list|)
value|( (eup->eu_suni[(x)+1]& 0xff)<< 8 | \ 			  (eup->eu_suni[(x)]& 0xff) )
end_define

begin_define
define|#
directive|define
name|READ_THREE
parameter_list|(
name|x
parameter_list|)
value|( (eup->eu_suni[(x)+2]& 0xf)<< 16 | \ 			  (eup->eu_suni[(x)+1]& 0xff)<< 8 | \ 			  (eup->eu_suni[(x)]& 0xff) )
end_define

begin_comment
comment|/*  * Do an initial read of the error counters without saving them.  * In effect, this will "zero" our idea of the number of errors  * which have occurred since the driver was loaded.  *  * Arguments:  *	eup		pointer to per unit structure  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|eni_zero_stats
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|int
name|val
decl_stmt|;
comment|/* 	 * Write the SUNI master control register which 	 * will cause all the statistics counters to be 	 * loaded. 	 */
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_MASTER_REG
index|]
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_MASTER_REG
index|]
expr_stmt|;
comment|/* 	 * Delay to allow for counter load time... 	 */
name|DELAY
argument_list|(
name|SUNI_DELAY
argument_list|)
expr_stmt|;
comment|/* 	 * Statistics counters contain the number of events 	 * since the last time the counter was read. 	 */
name|val
operator|=
name|READ_TWO
argument_list|(
name|SUNI_SECT_BIP_REG
argument_list|)
expr_stmt|;
comment|/* oc3_sect_bip8 */
name|val
operator|=
name|READ_TWO
argument_list|(
name|SUNI_PATH_BIP_REG
argument_list|)
expr_stmt|;
comment|/* oc3_path_bip8 */
name|val
operator|=
name|READ_THREE
argument_list|(
name|SUNI_LINE_BIP_REG
argument_list|)
expr_stmt|;
comment|/* oc3_line_bip24 */
name|val
operator|=
name|READ_THREE
argument_list|(
name|SUNI_LINE_FEBE_REG
argument_list|)
expr_stmt|;
comment|/* oc3_line_febe */
name|val
operator|=
name|READ_TWO
argument_list|(
name|SUNI_PATH_FEBE_REG
argument_list|)
expr_stmt|;
comment|/* oc3_path_febe */
name|val
operator|=
name|READ_ONE
argument_list|(
name|SUNI_HECS_REG
argument_list|)
expr_stmt|;
comment|/* oc3_hec_corr */
name|val
operator|=
name|READ_ONE
argument_list|(
name|SUNI_UHECS_REG
argument_list|)
expr_stmt|;
comment|/* oc3_hec_uncorr */
block|}
end_function

begin_comment
comment|/*  * Retrieve SUNI stats  *  * Arguments:  *	eup		pointer to per unit structure  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|eni_get_stats
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
comment|/* 	 * Write the SUNI master control register which 	 * will cause all the statistics counters to be 	 * loaded. 	 */
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_MASTER_REG
index|]
operator|=
name|eup
operator|->
name|eu_suni
index|[
name|SUNI_MASTER_REG
index|]
expr_stmt|;
comment|/* 	 * Delay to allow for counter load time... 	 */
name|DELAY
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|/* 	 * Statistics counters contain the number of events 	 * since the last time the counter was read. 	 */
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_sect_bip8
operator|+=
name|READ_TWO
argument_list|(
name|SUNI_SECT_BIP_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_path_bip8
operator|+=
name|READ_TWO
argument_list|(
name|SUNI_PATH_BIP_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_line_bip24
operator|+=
name|READ_THREE
argument_list|(
name|SUNI_LINE_BIP_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_line_febe
operator|+=
name|READ_THREE
argument_list|(
name|SUNI_LINE_FEBE_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_path_febe
operator|+=
name|READ_TWO
argument_list|(
name|SUNI_PATH_FEBE_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_hec_corr
operator|+=
name|READ_ONE
argument_list|(
name|SUNI_HECS_REG
argument_list|)
expr_stmt|;
name|eup
operator|->
name|eu_stats
operator|.
name|eni_st_oc3
operator|.
name|oc3_hec_uncorr
operator|+=
name|READ_ONE
argument_list|(
name|SUNI_UHECS_REG
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Handle netatm core service interface ioctl requests  *  * Called at splnet.  *  * Arguments:  *	code		ioctl function (sub)code  *	data		data to/from ioctl  *	arg		optional code-specific argument  *  * Returns:  *	0		request processed successfully  *	error		request failed - reason code  *  */
end_comment

begin_function
name|int
name|eni_atm_ioctl
parameter_list|(
name|code
parameter_list|,
name|data
parameter_list|,
name|arg
parameter_list|)
name|int
name|code
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|caddr_t
name|arg
decl_stmt|;
block|{
name|struct
name|atminfreq
modifier|*
name|aip
init|=
operator|(
expr|struct
name|atminfreq
operator|*
operator|)
name|data
decl_stmt|;
name|struct
name|atm_pif
modifier|*
name|pip
init|=
operator|(
expr|struct
name|atm_pif
operator|*
operator|)
name|arg
decl_stmt|;
name|Eni_unit
modifier|*
name|eup
init|=
operator|(
name|Eni_unit
operator|*
operator|)
name|pip
decl_stmt|;
name|caddr_t
name|buf
init|=
name|aip
operator|->
name|air_buf_addr
decl_stmt|;
name|struct
name|air_vinfo_rsp
modifier|*
name|avr
decl_stmt|;
name|int
name|count
decl_stmt|,
name|len
decl_stmt|,
name|buf_len
init|=
name|aip
operator|->
name|air_buf_len
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|char
name|ifname
index|[
literal|2
operator|*
name|IFNAMSIZ
index|]
decl_stmt|;
name|ATM_DEBUG2
argument_list|(
literal|"eni_atm_ioctl: code=%d, opcode=%d\n"
argument_list|,
name|code
argument_list|,
name|aip
operator|->
name|air_opcode
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|aip
operator|->
name|air_opcode
condition|)
block|{
case|case
name|AIOCS_INF_VST
case|:
comment|/* 		 * Get vendor statistics 		 */
if|if
condition|(
name|eup
operator|==
name|NULL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|snprintf
argument_list|(
name|ifname
argument_list|,
sizeof|sizeof
argument_list|(
name|ifname
argument_list|)
argument_list|,
literal|"%s%d"
argument_list|,
name|pip
operator|->
name|pif_name
argument_list|,
name|pip
operator|->
name|pif_unit
argument_list|)
expr_stmt|;
comment|/* 		 * Cast response structure onto user's buffer 		 */
name|avr
operator|=
operator|(
expr|struct
name|air_vinfo_rsp
operator|*
operator|)
name|buf
expr_stmt|;
comment|/* 		 * How large is the response structure 		 */
name|len
operator|=
sizeof|sizeof
argument_list|(
expr|struct
name|air_vinfo_rsp
argument_list|)
expr_stmt|;
comment|/* 		 * Sanity check - enough room for response structure? 		 */
if|if
condition|(
name|buf_len
operator|<
name|len
condition|)
return|return
operator|(
name|ENOSPC
operator|)
return|;
comment|/* 		 * Copy interface name into response structure 		 */
if|if
condition|(
operator|(
name|err
operator|=
name|copyout
argument_list|(
name|ifname
argument_list|,
name|avr
operator|->
name|avsp_intf
argument_list|,
name|IFNAMSIZ
argument_list|)
operator|)
operator|!=
literal|0
condition|)
break|break;
comment|/* 		 * Advance the buffer address and decrement the size 		 */
name|buf
operator|+=
name|len
expr_stmt|;
name|buf_len
operator|-=
name|len
expr_stmt|;
comment|/* 		 * Get the vendor stats (SUNI) from the hardware 		 */
name|eni_get_stats
argument_list|(
name|eup
argument_list|)
expr_stmt|;
comment|/* 		 * Stick as much of it as we have room for 		 * into the response 		 */
name|count
operator|=
name|MIN
argument_list|(
sizeof|sizeof
argument_list|(
name|Eni_stats
argument_list|)
argument_list|,
name|buf_len
argument_list|)
expr_stmt|;
comment|/* 		 * Copy stats into user's buffer. Return value is 		 * amount of data copied. 		 */
if|if
condition|(
operator|(
name|err
operator|=
name|copyout
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|eup
operator|->
name|eu_stats
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
operator|)
operator|!=
literal|0
condition|)
break|break;
name|buf
operator|+=
name|count
expr_stmt|;
name|buf_len
operator|-=
name|count
expr_stmt|;
if|if
condition|(
name|count
operator|<
sizeof|sizeof
argument_list|(
name|Eni_stats
argument_list|)
condition|)
name|err
operator|=
name|ENOSPC
expr_stmt|;
comment|/* 		 * Record amount we're returning as vendor info... 		 */
if|if
condition|(
operator|(
name|err
operator|=
name|copyout
argument_list|(
operator|&
name|count
argument_list|,
operator|&
name|avr
operator|->
name|avsp_len
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|)
operator|)
operator|!=
literal|0
condition|)
break|break;
comment|/* 		 * Update the reply pointers and length 		 */
name|aip
operator|->
name|air_buf_addr
operator|=
name|buf
expr_stmt|;
name|aip
operator|->
name|air_buf_len
operator|=
name|buf_len
expr_stmt|;
break|break;
default|default:
name|err
operator|=
name|ENOSYS
expr_stmt|;
comment|/* Operation not supported */
break|break;
block|}
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

end_unit

