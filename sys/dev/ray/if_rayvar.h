begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000  * Dr. Duncan McLennan Barclay, dmlb@ragnet.demon.co.uk.  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY DUNCAN BARCLAY AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL DUNCAN BARCLAY OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: if_rayvar.h,v 1.4 2000/05/21 20:43:24 dmlb Exp $  *  */
end_comment

begin_comment
comment|/*  * Network parameters, used twice in sotfc to store what we want and what  * we have.  */
end_comment

begin_struct
struct|struct
name|ray_nw_param
block|{
name|struct
name|ray_cmd_net
name|p_1
decl_stmt|;
name|u_int8_t
name|np_ap_status
decl_stmt|;
name|struct
name|ray_net_params
decl|\
name|p_2
decl_stmt|;
name|u_int8_t
name|np_countrycode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|np_upd_param
value|p_1.c_upd_param
end_define

begin_define
define|#
directive|define
name|np_bss_id
value|p_1.c_bss_id
end_define

begin_define
define|#
directive|define
name|np_inited
value|p_1.c_inited
end_define

begin_define
define|#
directive|define
name|np_def_txrate
value|p_1.c_def_txrate
end_define

begin_define
define|#
directive|define
name|np_encrypt
value|p_1.c_encrypt
end_define

begin_define
define|#
directive|define
name|np_net_type
value|p_2.p_net_type
end_define

begin_define
define|#
directive|define
name|np_ssid
value|p_2.p_ssid
end_define

begin_define
define|#
directive|define
name|np_priv_start
value|p_2.p_privacy_must_start
end_define

begin_define
define|#
directive|define
name|np_priv_join
value|p_2.p_privacy_can_join
end_define

begin_comment
comment|/*  * One of these structures per allocated device  */
end_comment

begin_struct
struct|struct
name|ray_softc
block|{
name|device_t
name|dev
decl_stmt|;
comment|/* Device */
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common 		*/
name|struct
name|ifmedia
name|ifmedia
decl_stmt|;
comment|/* Ifnet common 		*/
name|struct
name|callout_handle
name|reset_timerh
decl_stmt|;
comment|/* Handle for reset timer	*/
name|struct
name|callout_handle
name|tx_timerh
decl_stmt|;
comment|/* Handle for tx timer	*/
name|struct
name|callout_handle
name|com_timerh
decl_stmt|;
comment|/* Handle for command timer	*/
name|bus_space_tag_t
name|am_bst
decl_stmt|;
comment|/* Bus space tag for attribute memory */
name|bus_space_handle_t
name|am_bsh
decl_stmt|;
comment|/* Bus space handle for attribute mem */
name|int
name|am_rid
decl_stmt|;
comment|/* Resource id for attribute memory */
name|struct
name|resource
modifier|*
name|am_res
decl_stmt|;
comment|/* Resource for attribute memory */
name|bus_space_tag_t
name|cm_bst
decl_stmt|;
comment|/* Bus space tag for common memory */
name|bus_space_handle_t
name|cm_bsh
decl_stmt|;
comment|/* Bus space handle for common memory */
name|int
name|cm_rid
decl_stmt|;
comment|/* Resource id for common memory */
name|struct
name|resource
modifier|*
name|cm_res
decl_stmt|;
comment|/* Resource for common memory */
name|int
name|irq_rid
decl_stmt|;
comment|/* Resource id for irq */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* Resource for irq */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* Handle for irq handler */
name|u_char
name|gone
decl_stmt|;
comment|/* 1 = Card bailed out		*/
name|int
name|framing
decl_stmt|;
comment|/* Packet framing types		*/
name|struct
name|ray_ecf_startup_v5
name|sc_ecf_startup
decl_stmt|;
comment|/* Startup info from card	*/
name|TAILQ_HEAD
argument_list|(
argument|ray_comq
argument_list|,
argument|ray_comq_entry
argument_list|)
name|sc_comq
expr_stmt|;
comment|/* Command queue		*/
if|#
directive|if
name|XXX_IOCTLLOCK
name|int
name|sc_ioctl_lock
decl_stmt|;
comment|/* IOCTL lock 			*/
name|int
name|sc_ioctl_cnt
decl_stmt|;
comment|/* IOCTL lock count		*/
endif|#
directive|endif
comment|/* XXX_IOCTLLOCK */
name|struct
name|ray_nw_param
name|sc_c
decl_stmt|;
comment|/* current network params 	*/
name|struct
name|ray_nw_param
name|sc_d
decl_stmt|;
comment|/* desired network params	*/
name|int
name|sc_havenet
decl_stmt|;
comment|/* true if we have a network	*/
name|int
name|sc_promisc
decl_stmt|;
comment|/* current set value		*/
name|u_int8_t
name|sc_ccsinuse
index|[
literal|64
index|]
decl_stmt|;
comment|/* ccss' in use -- not for tx	*/
name|int
name|sc_checkcounters
decl_stmt|;
name|u_int64_t
name|sc_rxoverflow
decl_stmt|;
comment|/* Number of rx overflows	*/
name|u_int64_t
name|sc_rxcksum
decl_stmt|;
comment|/* Number of checksum errors	*/
name|u_int64_t
name|sc_rxhcksum
decl_stmt|;
comment|/* Number of header checksum errors */
name|u_int8_t
name|sc_rxnoise
decl_stmt|;
comment|/* Average receiver level	*/
name|struct
name|ray_siglev
name|sc_siglevs
index|[
name|RAY_NSIGLEVRECS
index|]
decl_stmt|;
comment|/* Antenna/levels	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_station_addr
value|sc_ecf_startup.e_station_addr
end_define

begin_define
define|#
directive|define
name|sc_version
value|sc_ecf_startup.e_fw_build_string
end_define

begin_define
define|#
directive|define
name|sc_tibsize
value|sc_ecf_startup.e_tibsize
end_define

begin_comment
comment|/*  * Command queue definitions  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ray_comqfn_t
function_decl|)
parameter_list|(
name|struct
name|ray_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ray_comq_entry
modifier|*
name|com
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_RAYCOM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|M_RAYCOM
argument_list|,
literal|"raycom"
argument_list|,
literal|"Raylink command queue entry"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ray_comq_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ray_comq_entry
argument_list|)
name|c_chain
expr_stmt|;
comment|/* Tail queue.		*/
name|ray_comqfn_t
name|c_function
decl_stmt|;
comment|/* Function to call */
name|int
name|c_flags
decl_stmt|;
comment|/* Flags		*/
name|u_int8_t
name|c_retval
decl_stmt|;
comment|/* Return value		*/
name|void
modifier|*
name|c_wakeup
decl_stmt|;
comment|/* Sleeping on this	*/
name|size_t
name|c_ccs
decl_stmt|;
comment|/* CCS structure	*/
name|struct
name|ray_param_req
modifier|*
name|c_pr
decl_stmt|;
comment|/* MIB report/update	*/
name|char
modifier|*
name|c_mesg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Framing types  */
end_comment

begin_comment
comment|/* XXX maybe better as part of the if structure? */
end_comment

begin_define
define|#
directive|define
name|SC_FRAMING_WEBGEAR
value|0
end_define

begin_comment
comment|/*  * Macro's and constants  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|mib_info
index|[
name|RAY_MIB_MAX
operator|+
literal|1
index|]
index|[
literal|3
index|]
init|=
name|RAY_MIB_INFO
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indirections for reading/writing memory - from NetBSD/if_ray.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|offsetof
end_ifndef

begin_define
define|#
directive|define
name|offsetof
parameter_list|(
name|type
parameter_list|,
name|member
parameter_list|)
define|\
value|((size_t)(&((type *)0)->member))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* offsetof */
end_comment

begin_if
if|#
directive|if
name|RAY_NEED_CM_REMAPPING
end_if

begin_define
define|#
directive|define
name|ATTR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|ray_attr_read_1((sc), (off))
end_define

begin_define
define|#
directive|define
name|ATTR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|ray_attr_write_1((sc), (off), (val))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|((u_int8_t)bus_space_read_1((sc)->am_bst, (sc)->am_bsh, (off)))
end_define

begin_define
define|#
directive|define
name|ATTR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->am_bst, (sc)->am_bsh, (off), (val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_NEED_CM_REMAPPING */
end_comment

begin_define
define|#
directive|define
name|SRAM_READ_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|)
define|\
value|((u_int8_t)bus_space_read_1((sc)->cm_bst, (sc)->cm_bsh, (off)))
end_define

begin_define
define|#
directive|define
name|SRAM_READ_REGION
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
define|\
value|bus_space_read_region_1((sc)->cm_bst, (sc)->cm_bsh, (off), (void *)(p), (n))
end_define

begin_define
define|#
directive|define
name|SRAM_READ_FIELD_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|SRAM_READ_1((sc), (off) + offsetof(struct s, f))
end_define

begin_define
define|#
directive|define
name|SRAM_READ_FIELD_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|((((u_int16_t)SRAM_READ_1((sc), (off) + offsetof(struct s, f))<< 8) \     |(SRAM_READ_1((sc), (off) + 1 + offsetof(struct s, f)))))
end_define

begin_define
define|#
directive|define
name|SRAM_READ_FIELD_N
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
define|\
value|SRAM_READ_REGION((sc), (off) + offsetof(struct s, f), (p), (n))
end_define

begin_define
define|#
directive|define
name|SRAM_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->cm_bst, (sc)->cm_bsh, (off), (val))
end_define

begin_define
define|#
directive|define
name|SRAM_WRITE_REGION
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
define|\
value|bus_space_write_region_1((sc)->cm_bst, (sc)->cm_bsh, (off), (void *)(p), (n))
end_define

begin_define
define|#
directive|define
name|SRAM_WRITE_FIELD_1
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|SRAM_WRITE_1((sc), (off) + offsetof(struct s, f), (v))
end_define

begin_define
define|#
directive|define
name|SRAM_WRITE_FIELD_2
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
value|do {	\     SRAM_WRITE_1((sc), (off) + offsetof(struct s, f), (((v)>> 8 )& 0xff)); \     SRAM_WRITE_1((sc), (off) + 1 + offsetof(struct s, f), ((v)& 0xff)); \ } while (0)
end_define

begin_define
define|#
directive|define
name|SRAM_WRITE_FIELD_N
parameter_list|(
name|sc
parameter_list|,
name|off
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|,
name|p
parameter_list|,
name|n
parameter_list|)
define|\
value|SRAM_WRITE_REGION((sc), (off) + offsetof(struct s, f), (p), (n))
end_define

begin_define
define|#
directive|define
name|RAY_COM_FWOK
value|0x0001
end_define

begin_comment
comment|/* Wakeup on completion	*/
end_comment

begin_define
define|#
directive|define
name|RAY_COM_FRUNNING
value|0x0002
end_define

begin_comment
comment|/* This one running	*/
end_comment

begin_define
define|#
directive|define
name|RAY_COM_FCOMPLETED
value|0x0004
end_define

begin_comment
comment|/* This one completed	*/
end_comment

begin_define
define|#
directive|define
name|RAY_COM_FWAIT
value|0x0008
end_define

begin_comment
comment|/* Do not run the queue */
end_comment

begin_define
define|#
directive|define
name|RAY_COM_FLAGS_PRINTFB
define|\
value|"\020"			\ 	"\001WOK"		\ 	"\002RUNNING"		\ 	"\003COMPLETED"		\ 	"\004WAIT"
end_define

begin_define
define|#
directive|define
name|RAY_COM_NEEDS_TIMO
parameter_list|(
name|cmd
parameter_list|)
value|(		\ 	 (cmd == RAY_CMD_DOWNLOAD_PARAMS) ||	\ 	 (cmd == RAY_CMD_UPDATE_PARAMS) ||	\ 	 (cmd == RAY_CMD_UPDATE_MCAST)		\ 	)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RAY_COM_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|RAY_COM_TIMEOUT
value|(hz / 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RAY_RESET_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|RAY_RESET_TIMEOUT
value|(10 * hz)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RAY_TX_TIMEOUT
end_ifndef

begin_define
define|#
directive|define
name|RAY_TX_TIMEOUT
value|(hz / 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RAY_CCS_FREE
parameter_list|(
name|sc
parameter_list|,
name|ccs
parameter_list|)
define|\
value|SRAM_WRITE_FIELD_1((sc), (ccs), ray_cmd, c_status, RAY_CCS_STATUS_FREE)
end_define

begin_define
define|#
directive|define
name|RAY_ECF_READY
parameter_list|(
name|sc
parameter_list|)
define|\
value|(!(ATTR_READ_1((sc), RAY_ECFIR)& RAY_ECFIR_IRQ))
end_define

begin_define
define|#
directive|define
name|RAY_ECF_START_CMD
parameter_list|(
name|sc
parameter_list|)
value|ATTR_WRITE_1((sc), RAY_ECFIR, RAY_ECFIR_IRQ)
end_define

begin_define
define|#
directive|define
name|RAY_HCS_CLEAR_INTR
parameter_list|(
name|sc
parameter_list|)
value|ATTR_WRITE_1((sc), RAY_HCSIR, 0)
end_define

begin_define
define|#
directive|define
name|RAY_HCS_INTR
parameter_list|(
name|sc
parameter_list|)
value|(ATTR_READ_1((sc), RAY_HCSIR)& RAY_HCSIR_IRQ)
end_define

begin_define
define|#
directive|define
name|RAY_PANIC
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\     panic("ray%d: %s(%d) " fmt "\n", device_get_unit((sc)->dev),	\ 	__FUNCTION__ , __LINE__ , ##args);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RAY_PRINTF
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\     device_printf((sc)->dev, "%s(%d) " fmt "\n",			\         __FUNCTION__ , __LINE__ , ##args);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|RAY_COM_MALLOC
parameter_list|(
name|function
parameter_list|,
name|flags
parameter_list|)
define|\
value|ray_com_malloc((function), (flags), __STRING(function));
end_define

begin_define
define|#
directive|define
name|RAY_COM_INIT
parameter_list|(
name|com
parameter_list|,
name|function
parameter_list|,
name|flags
parameter_list|)
define|\
value|ray_com_init((com), (function), (flags), __STRING(function));
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|RAY_COM_CHECK
end_ifndef

begin_define
define|#
directive|define
name|RAY_COM_CHECK
parameter_list|(
name|sc
parameter_list|,
name|com
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_COM_CHECK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RAY_MBUF_DUMP
end_ifndef

begin_define
define|#
directive|define
name|RAY_MBUF_DUMP
parameter_list|(
name|sc
parameter_list|,
name|mask
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_MBUF_DUMP */
end_comment

begin_comment
comment|/*  * The driver assumes that the common memory is always mapped in,  * for the moment we ensure this with the following macro at the  * head of each function and by using functions to access attribute  * memory. Hysterical raisins led to the non-"reflexive" approach.  * Roll on NEWCARD and it can all die...  */
end_comment

begin_if
if|#
directive|if
name|RAY_NEED_CM_REMAPPING
end_if

begin_define
define|#
directive|define
name|RAY_MAP_CM
parameter_list|(
name|sc
parameter_list|)
value|ray_attr_mapcm(sc)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RAY_MAP_CM
parameter_list|(
name|sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RAY_NEED_CM_REMAPPING */
end_comment

end_unit

