begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * User Space Library Functions  * ----------------------------  *  * Library functions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HARP_LIBHARP_H
end_ifndef

begin_define
define|#
directive|define
name|_HARP_LIBHARP_H
end_define

begin_comment
comment|/*  * Start a HARP user-space timer  *  *	tp	pointer to timer control block  *	time	number of seconds for timer to run  *	fp	pointer to function to call at expiration  */
end_comment

begin_define
define|#
directive|define
name|HARP_TIMER
parameter_list|(
name|tp
parameter_list|,
name|time
parameter_list|,
name|fp
parameter_list|)
define|\
value|{								\ 	(tp)->ht_ticks = (time);				\ 	(tp)->ht_mark = 0;					\ 	(tp)->ht_func = (fp);					\ 	LINK2HEAD((tp), Harp_timer, harp_timer_head, ht_next);	\ }
end_define

begin_comment
comment|/*  * Cancel a HARP user-space timer  *  *	tp	pointer to timer control block  */
end_comment

begin_define
define|#
directive|define
name|HARP_CANCEL
parameter_list|(
name|tp
parameter_list|)
define|\
value|{								\ 	UNLINK((tp), Harp_timer, harp_timer_head, ht_next);	\ }
end_define

begin_comment
comment|/*  * HARP user-space timer control block  */
end_comment

begin_struct
struct|struct
name|harp_timer
block|{
name|struct
name|harp_timer
modifier|*
name|ht_next
decl_stmt|;
comment|/* Timer chain */
name|int
name|ht_ticks
decl_stmt|;
comment|/* Seconds till exp */
name|int
name|ht_mark
decl_stmt|;
comment|/* Processing flag */
name|void
function_decl|(
modifier|*
name|ht_func
function_decl|)
parameter_list|()
function_decl|;
comment|/* Function to call */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|harp_timer
name|Harp_timer
typedef|;
end_typedef

begin_comment
comment|/*  * Externally-visible variables and functions  */
end_comment

begin_comment
comment|/* atm_addr.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_hex_atm_addr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|format_atm_addr
name|__P
argument_list|(
operator|(
name|Atm_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cache_key.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|scsp_cache_key
name|__P
argument_list|(
operator|(
name|Atm_addr
operator|*
operator|,
expr|struct
name|in_addr
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ioctl_subr.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|do_info_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|atminfreq
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_vcc_info
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|air_vcc_rsp
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_subnet_mask
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_mtu
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verify_nif_name
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_cfg_info
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|air_cfg_rsp
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_intf_info
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|air_int_rsp
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_netif_info
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|air_netif_rsp
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip_addr.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_in
modifier|*
name|get_ip_addr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|format_ip_addr
name|__P
argument_list|(
operator|(
expr|struct
name|in_addr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip_checksum.c */
end_comment

begin_decl_stmt
specifier|extern
name|short
name|ip_checksum
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* timer.c */
end_comment

begin_decl_stmt
specifier|extern
name|Harp_timer
modifier|*
name|harp_timer_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|harp_timer_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|timer_proc
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|init_timer
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|block_timer
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|enable_timer
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HARP_LIBHARP_H */
end_comment

end_unit

