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

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_comment
comment|/*  * If not specified elsewhere, guess which type of bus support we want  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|FORE_PCI
argument_list|)
operator|||
name|defined
argument_list|(
name|FORE_SBUS
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
end_if

begin_define
define|#
directive|define
name|FORE_SBUS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|FORE_PCI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FORE_PCI
end_ifdef

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dev/hfa/fore.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_aali.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_slave.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hfa/fore_var.h>
end_include

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* fore_buffer.c */
end_comment

begin_decl_stmt
name|int
name|fore_buf_allocate
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_buf_initialize
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_buf_supply
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_buf_free
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_command.c */
end_comment

begin_decl_stmt
name|int
name|fore_cmd_allocate
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_cmd_initialize
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_cmd_drain
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_cmd_free
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_if.c */
end_comment

begin_decl_stmt
name|int
name|fore_atm_ioctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|caddr_t
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_interface_free
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_init.c */
end_comment

begin_decl_stmt
name|void
name|fore_initialize
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_initialize_complete
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_intr.c */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_decl_stmt
name|int
name|fore_poll
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|<=
literal|199306
operator|)
operator|)
end_if

begin_decl_stmt
name|int
name|fore_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|void
name|fore_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|fore_watchdog
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_load.c */
end_comment

begin_comment
comment|/* fore_output.c */
end_comment

begin_decl_stmt
name|void
name|fore_output
name|__P
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|,
name|Cmn_vcc
operator|*
operator|,
name|KBuffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_receive.c */
end_comment

begin_decl_stmt
name|int
name|fore_recv_allocate
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_recv_initialize
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_recv_drain
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_recv_free
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_stats.c */
end_comment

begin_decl_stmt
name|int
name|fore_get_stats
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_timer.c */
end_comment

begin_decl_stmt
name|void
name|fore_timeout
name|__P
argument_list|(
operator|(
expr|struct
name|atm_time
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_transmit.c */
end_comment

begin_decl_stmt
name|int
name|fore_xmit_allocate
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_xmit_initialize
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_xmit_drain
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fore_xmit_free
name|__P
argument_list|(
operator|(
name|Fore_unit
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fore_vcm.c */
end_comment

begin_decl_stmt
name|int
name|fore_instvcc
name|__P
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|,
name|Cmn_vcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fore_openvcc
name|__P
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|,
name|Cmn_vcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fore_closevcc
name|__P
argument_list|(
operator|(
name|Cmn_unit
operator|*
operator|,
name|Cmn_vcc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

