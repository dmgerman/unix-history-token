begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Local driver include files and global declarations  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_INCLUDE_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_INCLUDE_H
end_define

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* fore_buffer.c */
end_comment

begin_function_decl
name|int
name|fore_buf_allocate
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_buf_initialize
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_buf_supply
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_buf_free
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_command.c */
end_comment

begin_function_decl
name|int
name|fore_cmd_allocate
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_cmd_initialize
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_cmd_drain
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_cmd_free
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_if.c */
end_comment

begin_function_decl
name|int
name|fore_atm_ioctl
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
name|fore_interface_free
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_init.c */
end_comment

begin_function_decl
name|void
name|fore_initialize
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_initialize_complete
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_intr.c */
end_comment

begin_function_decl
name|void
name|fore_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_watchdog
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_load.c */
end_comment

begin_comment
comment|/* fore_output.c */
end_comment

begin_function_decl
name|void
name|fore_output
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

begin_comment
comment|/* fore_receive.c */
end_comment

begin_function_decl
name|int
name|fore_recv_allocate
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_recv_initialize
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_recv_drain
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_recv_free
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_stats.c */
end_comment

begin_function_decl
name|int
name|fore_get_stats
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_timer.c */
end_comment

begin_function_decl
name|void
name|fore_timeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_transmit.c */
end_comment

begin_function_decl
name|int
name|fore_xmit_allocate
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_xmit_initialize
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_xmit_drain
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fore_xmit_free
parameter_list|(
name|Fore_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fore_vcm.c */
end_comment

begin_function_decl
name|int
name|fore_instvcc
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
name|fore_openvcc
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
name|fore_closevcc
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
name|Fore_device
name|fore_devices
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Fore_unit
modifier|*
name|fore_units
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fore_nunits
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stack_defn
modifier|*
name|fore_services
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|fore_nif_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|fore_vcc_pool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|atm_time
name|fore_timer
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_INCLUDE_H */
end_comment

end_unit

