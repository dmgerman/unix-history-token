begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Efficient ENI Adapter Support  * -----------------------------  *  * Local driver include files and global declarations  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENI_ENI_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ENI_ENI_VAR_H
end_define

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* eni_buffer.c */
end_comment

begin_function_decl
name|int
name|eni_init_memory
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|eni_allocate_buffer
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_free_buffer
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* eni_if.c */
end_comment

begin_function_decl
name|int
name|eni_atm_ioctl
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_zero_stats
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* eni_init.c */
end_comment

begin_function_decl
name|int
name|eni_init
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* eni_intr.c */
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

begin_function_decl
name|int
name|eni_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|eni_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* eni_receive.c */
end_comment

begin_function_decl
name|void
name|eni_do_service
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_recv_drain
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* eni_transmit.c */
end_comment

begin_function_decl
name|int
name|eni_set_dma
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
modifier|*
parameter_list|,
name|int
parameter_list|,
name|long
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_output
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_xmit_drain
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* eni_vcm.c */
end_comment

begin_function_decl
name|int
name|eni_instvcc
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eni_openvcc
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eni_closevcc
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Global variable declarations  */
end_comment

begin_decl_stmt
specifier|extern
name|Eni_unit
modifier|*
name|eni_units
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stack_defn
modifier|*
name|eni_services
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|eni_nif_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|eni_vcc_pool
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ENI_ENI_VAR_H */
end_comment

end_unit

