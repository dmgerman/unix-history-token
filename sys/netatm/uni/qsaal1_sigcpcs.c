begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * ITU-T Q.SAAL1 - Process CPCS-signals (SSCOP PDUs)  *  */
end_comment

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_misc.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_pdu.h>
end_include

begin_include
include|#
directive|include
file|<netatm/uni/sscop_var.h>
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
comment|/*  * Local functions  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|sscop_bgn_outconn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_end_outresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_end_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_end_ready
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_endak_outresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_rs_outresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_rs_ready
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_rsak_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_sd_inresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_sd_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_sd_process
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_sd_ready
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_sdp_ready
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_poll_inresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_poll_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_poll_ready
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_stat_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|sscop_ustat_conresyn
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * PDU type state lookup tables  */
end_comment

begin_comment
comment|/* BGN PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_bgn_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_bgn_idle
block|,
comment|/* SOS_IDLE */
name|sscop_bgn_outconn
block|,
comment|/* SOS_OUTCONN */
name|sscop_noop
block|,
comment|/* SOS_INCONN */
name|sscop_bgn_outdisc
block|,
comment|/* SOS_OUTDISC */
name|sscop_bgn_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_bgn_inresyn
block|,
comment|/* SOS_INRESYN */
name|sscop_bgn_outresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_bgn_inresyn
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* BGAK PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_bgak_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_bgak_idle
block|,
comment|/* SOS_IDLE */
name|sscop_bgak_outconn
block|,
comment|/* SOS_OUTCONN */
name|sscop_bgak_error
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_bgak_error
block|,
comment|/* SOS_OUTRESYN */
name|sscop_bgak_error
block|,
comment|/* SOS_INRESYN */
name|sscop_bgak_error
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_noop
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* BGREJ PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_bgrej_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_bgrej_error
block|,
comment|/* SOS_IDLE */
name|sscop_bgrej_outconn
block|,
comment|/* SOS_OUTCONN */
name|sscop_bgrej_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_bgrej_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_bgrej_ready
block|,
comment|/* SOS_INRESYN */
name|sscop_bgrej_outresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_bgrej_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* END PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_end_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_end_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_end_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_end_outdisc
block|,
comment|/* SOS_OUTDISC */
name|sscop_end_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_end_ready
block|,
comment|/* SOS_INRESYN */
name|sscop_end_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_end_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ENDAK PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_endak_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_noop
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_endak_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_endak_outdisc
block|,
comment|/* SOS_OUTDISC */
name|sscop_endak_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_endak_ready
block|,
comment|/* SOS_INRESYN */
name|sscop_endak_outresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_endak_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* RS PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_rs_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_rs_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_rs_error
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_rs_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_noop
block|,
comment|/* SOS_INRESYN */
name|sscop_noop
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_rs_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* RSAK PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_rsak_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_rsak_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_rsak_error
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_rsak_outresyn
block|,
comment|/* SOS_OUTRESYN */
name|sscop_rsak_error
block|,
comment|/* SOS_INRESYN */
name|sscop_rsak_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_rsak_error
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SD PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_sd_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_sd_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_sd_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_sd_ready
block|,
comment|/* SOS_OUTRESYN */
name|sscop_sd_inresyn
block|,
comment|/* SOS_INRESYN */
name|sscop_sd_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_sd_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* SDP PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_sdp_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_sd_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_sd_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_sdp_ready
block|,
comment|/* SOS_OUTRESYN */
name|sscop_sd_inresyn
block|,
comment|/* SOS_INRESYN */
name|sscop_sd_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_sdp_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* POLL PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_poll_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_poll_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_poll_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_poll_ready
block|,
comment|/* SOS_OUTRESYN */
name|sscop_poll_inresyn
block|,
comment|/* SOS_INRESYN */
name|sscop_poll_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_poll_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* STAT PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_stat_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_stat_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_stat_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_noop
block|,
comment|/* SOS_OUTRESYN */
name|sscop_stat_ready
block|,
comment|/* SOS_INRESYN */
name|sscop_stat_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_stat_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* USTAT PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_ustat_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_ustat_idle
block|,
comment|/* SOS_IDLE */
name|sscop_noop
block|,
comment|/* SOS_OUTCONN */
name|sscop_ustat_inconn
block|,
comment|/* SOS_INCONN */
name|sscop_noop
block|,
comment|/* SOS_OUTDISC */
name|sscop_noop
block|,
comment|/* SOS_OUTRESYN */
name|sscop_ustat_ready
block|,
comment|/* SOS_INRESYN */
name|sscop_ustat_conresyn
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_ustat_ready
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* UD PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_ud_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_ud_all
block|,
comment|/* SOS_IDLE */
name|sscop_ud_all
block|,
comment|/* SOS_OUTCONN */
name|sscop_ud_all
block|,
comment|/* SOS_INCONN */
name|sscop_ud_all
block|,
comment|/* SOS_OUTDISC */
name|sscop_ud_all
block|,
comment|/* SOS_OUTRESYN */
name|sscop_ud_all
block|,
comment|/* SOS_INRESYN */
name|sscop_ud_all
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_ud_all
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* MD PDU */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
argument|*sscop_md_tab[SOS_NUMSTATES]
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
comment|/* SOS_INST */
name|sscop_md_all
block|,
comment|/* SOS_IDLE */
name|sscop_md_all
block|,
comment|/* SOS_OUTCONN */
name|sscop_md_all
block|,
comment|/* SOS_INCONN */
name|sscop_md_all
block|,
comment|/* SOS_OUTDISC */
name|sscop_md_all
block|,
comment|/* SOS_OUTRESYN */
name|sscop_md_all
block|,
comment|/* SOS_INRESYN */
name|sscop_md_all
block|,
comment|/* SOS_CONRESYN */
name|NULL
block|,
comment|/* invalid */
name|NULL
block|,
comment|/* invalid */
name|sscop_md_all
block|,
comment|/* SOS_READY */
name|sscop_noop
comment|/* SOS_TERM */
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * PDU type lookup table  */
end_comment

begin_macro
name|void
argument_list|(
argument|*(*sscop_qsaal_pdutab[])
argument_list|)
end_macro

begin_expr_stmt
name|__P
argument_list|(
operator|(
expr|struct
name|sscop
operator|*
operator|,
name|KBuffer
operator|*
operator|,
name|caddr_t
operator|)
argument_list|)
operator|=
block|{
name|NULL
block|,
name|sscop_bgn_tab
block|,
name|sscop_bgak_tab
block|,
name|sscop_end_tab
block|,
name|sscop_endak_tab
block|,
name|sscop_rs_tab
block|,
name|sscop_rsak_tab
block|,
name|sscop_bgrej_tab
block|,
name|sscop_sd_tab
block|,
name|sscop_sdp_tab
block|,
name|sscop_poll_tab
block|,
name|sscop_stat_tab
block|,
name|sscop_ustat_tab
block|,
name|sscop_ud_tab
block|,
name|sscop_md_tab
block|,
name|NULL
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * BGN PDU / SOS_OUTCONN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_bgn_outconn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|struct
name|bgn_pdu
modifier|*
name|bp
init|=
operator|(
expr|struct
name|bgn_pdu
operator|*
operator|)
name|trlr
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* 	 * Initialize transmit window 	 */
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_sendmax
argument_list|,
name|ntohl
argument_list|(
name|bp
operator|->
name|bgn_nmr
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection establishment 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_REESTAB
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|STACK_CALL
argument_list|(
name|SSCOP_ESTABLISH_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_bgn_outconn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_REESTAB
expr_stmt|;
block|}
else|else
block|{
name|STACK_CALL
argument_list|(
name|SSCOP_ESTABLISH_CNF
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_bgn_outconn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
comment|/* 	 * Return an ACK to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_bgak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Reset receiver variables 	 */
name|qsaal1_reset_rcvr
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start polling timer 	 */
name|sscop_set_poll
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start lost poll/stat timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timeresp
expr_stmt|;
comment|/* 	 * OK, we're ready for data 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_READY
expr_stmt|;
comment|/* 	 * See if transmit queues need servicing 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_XMITSRVC
condition|)
name|sscop_service_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * END PDU / SOS_OUTRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_end_outresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|struct
name|end_pdu
modifier|*
name|ep
init|=
operator|(
expr|struct
name|end_pdu
operator|*
operator|)
name|trlr
decl_stmt|;
name|int
name|err
decl_stmt|,
name|source
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Acknowledge END 	 */
operator|(
name|void
operator|)
name|sscop_send_endak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Get Source value 	 */
if|if
condition|(
name|ep
operator|->
name|end_type
operator|&
name|PT_SOURCE_SSCOP
condition|)
name|source
operator|=
name|SSCOP_SOURCE_SSCOP
expr_stmt|;
else|else
name|source
operator|=
name|SSCOP_SOURCE_USER
expr_stmt|;
comment|/* 	 * Notify user of connection termination 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
name|source
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_end_outresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * END PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_end_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Free up buffers 	 */
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|/* 	 * Acknowledge END 	 */
operator|(
name|void
operator|)
name|sscop_send_endak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection termination 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_end_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * END PDU / SOS_READY Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_end_ready
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|struct
name|end_pdu
modifier|*
name|ep
init|=
operator|(
expr|struct
name|end_pdu
operator|*
operator|)
name|trlr
decl_stmt|;
name|int
name|err
decl_stmt|,
name|source
decl_stmt|;
comment|/* 	 * Stop poll timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_KEEPALIVE
expr_stmt|;
comment|/* 	 * Stop lost poll/stat timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Acknowledge END 	 */
operator|(
name|void
operator|)
name|sscop_send_endak
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Get Source value 	 */
if|if
condition|(
name|ep
operator|->
name|end_type
operator|&
name|PT_SOURCE_SSCOP
condition|)
name|source
operator|=
name|SSCOP_SOURCE_SSCOP
expr_stmt|;
else|else
name|source
operator|=
name|SSCOP_SOURCE_USER
expr_stmt|;
comment|/* 	 * Notify user of connection termination 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
name|source
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_end_ready: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * ENDAK PDU / SOS_OUTRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_endak_outresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Report protocol error 	 */
name|sscop_endak_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_endak_outresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * RS PDU / SOS_OUTRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_rs_outresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Notify user of resynchronization 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RESYNC_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_rs_outresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Reset receiver state variables 	 */
name|qsaal1_reset_rcvr
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Wait for both peer and user responses 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_CONRESYN
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * RS PDU / SOS_READY Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_rs_ready
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Notify user of resynchronization 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RESYNC_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_rs_ready: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Reset receiver state variables 	 */
name|qsaal1_reset_rcvr
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Wait for user response 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_INRESYN
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * RSAK PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_rsak_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Free buffers 	 */
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of resynchronization completion 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RESYNC_CNF
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_rsak_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Start the polling timer 	 */
name|sscop_set_poll
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Start lost poll/stat timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
name|sop
operator|->
name|so_parm
operator|.
name|sp_timeresp
expr_stmt|;
comment|/* 	 * Continue waiting for user response 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_INRESYN
expr_stmt|;
comment|/* 	 * See if transmit queues need servicing 	 */
if|if
condition|(
name|sop
operator|->
name|so_flags
operator|&
name|SOF_XMITSRVC
condition|)
name|sscop_service_xmit
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SD PDU / SOS_INRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_sd_inresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop poll timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_KEEPALIVE
expr_stmt|;
comment|/* 	 * Stop lost poll/stat timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Record error condition 	 */
name|sscop_sd_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_sd_inresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Go back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SD PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_sd_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Record error condition 	 */
name|sscop_sd_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_sd_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Go back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SD/SDP PDU Common Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU user data buffer chain  *	trlr	pointer to PDU trailer  *	type	PDU type (SD or SDP)  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_sd_process
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|,
name|type
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
name|int
name|type
decl_stmt|;
block|{
name|struct
name|sd_pdu
modifier|*
name|sp
decl_stmt|;
name|struct
name|sdp_pdu
modifier|*
name|spp
decl_stmt|;
name|struct
name|poll_pdu
name|poll
decl_stmt|;
name|struct
name|pdu_hdr
modifier|*
name|php
decl_stmt|;
name|KBuffer
modifier|*
name|n
decl_stmt|;
name|sscop_seq
name|ns
decl_stmt|,
name|nps
decl_stmt|;
name|int
name|err
decl_stmt|,
name|space
decl_stmt|;
comment|/* 	 * Get PDU sequence number(s) 	 */
if|if
condition|(
name|type
operator|==
name|PT_SD
condition|)
block|{
name|sp
operator|=
operator|(
expr|struct
name|sd_pdu
operator|*
operator|)
name|trlr
expr_stmt|;
name|SEQ_SET
argument_list|(
name|ns
argument_list|,
name|ntohl
argument_list|(
name|sp
operator|->
name|sd_ns
argument_list|)
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|nps
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|spp
operator|=
operator|(
expr|struct
name|sdp_pdu
operator|*
operator|)
name|trlr
expr_stmt|;
name|SEQ_SET
argument_list|(
name|ns
argument_list|,
name|ntohl
argument_list|(
name|spp
operator|->
name|sdp_ns
argument_list|)
argument_list|)
expr_stmt|;
name|SEQ_SET
argument_list|(
name|nps
argument_list|,
name|ntohl
argument_list|(
name|spp
operator|->
name|sdp_nps
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Ensure that the sequence number fits within the window 	 */
if|if
condition|(
name|SEQ_GEQ
argument_list|(
name|ns
argument_list|,
name|sop
operator|->
name|so_rcvmax
argument_list|,
name|sop
operator|->
name|so_rcvnext
argument_list|)
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * If this is the next in-sequence PDU, hand it to user 	 */
if|if
condition|(
name|ns
operator|==
name|sop
operator|->
name|so_rcvnext
condition|)
block|{
name|STACK_CALL
argument_list|(
name|SSCOP_DATA_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|m
argument_list|,
name|ns
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 		 * Bump next expected sequence number 		 */
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_rcvnext
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 		 * Slide receive window down 		 */
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_rcvmax
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 		 * Is this the highest sequence PDU we've received?? 		 */
if|if
condition|(
name|ns
operator|==
name|sop
operator|->
name|so_rcvhigh
condition|)
block|{
comment|/* 			 * Yes, bump the limit and exit 			 */
name|sop
operator|->
name|so_rcvhigh
operator|=
name|sop
operator|->
name|so_rcvnext
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|PT_SDP
condition|)
goto|goto
name|dopoll
goto|;
return|return;
block|}
comment|/* 		 * This is a retransmitted PDU, so see if we have 		 * more in-sequence PDUs already queued up 		 */
while|while
condition|(
operator|(
name|php
operator|=
name|sop
operator|->
name|so_recv_hd
operator|)
operator|&&
operator|(
name|php
operator|->
name|ph_ns
operator|==
name|sop
operator|->
name|so_rcvnext
operator|)
condition|)
block|{
comment|/* 			 * Yup we do, so remove next PDU from queue and 			 * pass it up to the user as well 			 */
name|sop
operator|->
name|so_recv_hd
operator|=
name|php
operator|->
name|ph_recv_lk
expr_stmt|;
if|if
condition|(
name|sop
operator|->
name|so_recv_hd
operator|==
name|NULL
condition|)
name|sop
operator|->
name|so_recv_tl
operator|=
name|NULL
expr_stmt|;
name|STACK_CALL
argument_list|(
name|SSCOP_DATA_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
operator|(
name|int
operator|)
name|php
operator|->
name|ph_buf
argument_list|,
name|php
operator|->
name|ph_ns
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
comment|/* 				 * Should never happen, but... 				 */
name|KB_FREEALL
argument_list|(
name|php
operator|->
name|ph_buf
argument_list|)
expr_stmt|;
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_sd_process: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 			 * Bump next expected sequence number 			 */
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_rcvnext
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* 			 * Slide receive window down 			 */
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_rcvmax
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* 		 * Finished with data...see if we need to poll 		 */
if|if
condition|(
name|type
operator|==
name|PT_SDP
condition|)
goto|goto
name|dopoll
goto|;
return|return;
block|}
comment|/* 	 * We're gonna have to queue this PDU, so find space  	 * for the PDU header 	 */
name|KB_HEADROOM
argument_list|(
name|m
argument_list|,
name|space
argument_list|)
expr_stmt|;
comment|/* 	 * If there's not enough room in the received buffer, 	 * allocate& link a new buffer for the header 	 */
if|if
condition|(
name|space
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|pdu_hdr
argument_list|)
condition|)
block|{
name|KB_ALLOC
argument_list|(
name|n
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pdu_hdr
argument_list|)
argument_list|,
name|KB_F_NOWAIT
argument_list|,
name|KB_T_HEADER
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
name|NULL
condition|)
block|{
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
return|return;
block|}
name|KB_HEADSET
argument_list|(
name|n
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|pdu_hdr
argument_list|)
argument_list|)
expr_stmt|;
name|KB_LEN
argument_list|(
name|n
argument_list|)
operator|=
literal|0
expr_stmt|;
name|KB_LINKHEAD
argument_list|(
name|n
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|m
operator|=
name|n
expr_stmt|;
block|}
comment|/* 	 * Build PDU header 	 * 	 * We can at least assume/require that the start of 	 * the user data is aligned.  Also note that we don't 	 * include this header in the buffer len/offset fields. 	 */
name|KB_DATASTART
argument_list|(
name|m
argument_list|,
name|php
argument_list|,
expr|struct
name|pdu_hdr
operator|*
argument_list|)
expr_stmt|;
name|php
operator|--
expr_stmt|;
name|php
operator|->
name|ph_ns
operator|=
name|ns
expr_stmt|;
name|php
operator|->
name|ph_buf
operator|=
name|m
expr_stmt|;
comment|/* 	 * Insert PDU into the receive queue 	 */
if|if
condition|(
name|sscop_recv_insert
argument_list|(
name|sop
argument_list|,
name|php
argument_list|)
condition|)
block|{
comment|/* 		 * Oops, a duplicate sequence number PDU is already on 		 * the queue, somethings wrong here. 		 */
name|sscop_maa_error
argument_list|(
name|sop
argument_list|,
literal|'Q'
argument_list|)
expr_stmt|;
comment|/* 		 * Free buffers 		 */
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|/* 		 * Reestablish a new connection 		 */
name|qsaal1_reestablish
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Are we at the high-water mark?? 	 */
if|if
condition|(
name|ns
operator|==
name|sop
operator|->
name|so_rcvhigh
condition|)
block|{
comment|/* 		 * Yes, just bump the mark 		 */
name|SEQ_INCR
argument_list|(
name|sop
operator|->
name|so_rcvhigh
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|PT_SDP
condition|)
goto|goto
name|dopoll
goto|;
return|return;
block|}
comment|/* 	 * Are we beyond the high-water mark?? 	 */
if|if
condition|(
name|SEQ_GT
argument_list|(
name|ns
argument_list|,
name|sop
operator|->
name|so_rcvhigh
argument_list|,
name|sop
operator|->
name|so_rcvnext
argument_list|)
condition|)
block|{
comment|/* 		 * Yes, then there's a missing PDU, so inform the transmitter 		 */
if|if
condition|(
name|type
operator|==
name|PT_SD
condition|)
operator|(
name|void
operator|)
name|sscop_send_ustat
argument_list|(
name|sop
argument_list|,
name|ns
argument_list|)
expr_stmt|;
comment|/* 		 * Update high-water mark 		 */
name|sop
operator|->
name|so_rcvhigh
operator|=
name|SEQ_ADD
argument_list|(
name|ns
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|type
operator|==
name|PT_SD
condition|)
return|return;
name|dopoll
label|:
comment|/* 	 * Do the "poll" part of an SDP PDU 	 */
name|poll
operator|.
name|poll_nps
operator|=
name|htonl
argument_list|(
name|nps
argument_list|)
expr_stmt|;
name|poll
operator|.
name|poll_ns
operator|=
name|htonl
argument_list|(
operator|(
name|PT_POLL
operator|<<
name|PT_TYPE_SHIFT
operator|)
operator||
name|ns
argument_list|)
expr_stmt|;
name|sscop_poll_ready
argument_list|(
name|sop
argument_list|,
name|NULL
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|poll
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SD PDU / SOS_READY Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_sd_ready
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
comment|/* 	 * Just call common SD/SDP processor 	 */
name|sscop_sd_process
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|,
name|PT_SD
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * SDP PDU / SOS_READY Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_sdp_ready
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
comment|/* 	 * Just call common SD/SDP processor 	 */
name|sscop_sd_process
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|,
name|PT_SDP
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * POLL PDU / SOS_INRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_poll_inresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop poll timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_POLL
index|]
operator|=
literal|0
expr_stmt|;
name|sop
operator|->
name|so_flags
operator|&=
operator|~
name|SOF_KEEPALIVE
expr_stmt|;
comment|/* 	 * Stop lost poll/stat timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_NORESP
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Report protocol error 	 */
name|sscop_poll_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_poll_inresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * POLL PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_poll_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Record error condition 	 */
name|sscop_poll_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_poll_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Go back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * POLL PDU / SOS_READY Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_poll_ready
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|struct
name|poll_pdu
modifier|*
name|pp
init|=
operator|(
expr|struct
name|poll_pdu
operator|*
operator|)
name|trlr
decl_stmt|;
name|sscop_seq
name|nps
decl_stmt|;
name|NTOHL
argument_list|(
name|pp
operator|->
name|poll_ns
argument_list|)
expr_stmt|;
comment|/* 	 * If the poll sequence number is less than highest number 	 * we've already seen, something's wrong - so attempt to 	 * reestablish a new connection. 	 */
if|if
condition|(
name|SEQ_LT
argument_list|(
name|pp
operator|->
name|poll_ns
argument_list|,
name|sop
operator|->
name|so_rcvhigh
argument_list|,
name|sop
operator|->
name|so_rcvnext
argument_list|)
condition|)
block|{
comment|/* 		 * Record error condition 		 */
name|sscop_maa_error
argument_list|(
name|sop
argument_list|,
literal|'Q'
argument_list|)
expr_stmt|;
comment|/* 		 * Free buffers 		 */
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
comment|/* 		 * Reestablish a new connection 		 */
name|qsaal1_reestablish
argument_list|(
name|sop
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Set a new "next highest" sequence number expected 	 */
if|if
condition|(
name|SEQ_LT
argument_list|(
name|pp
operator|->
name|poll_ns
argument_list|,
name|sop
operator|->
name|so_rcvmax
argument_list|,
name|sop
operator|->
name|so_rcvnext
argument_list|)
condition|)
name|SEQ_SET
argument_list|(
name|sop
operator|->
name|so_rcvhigh
argument_list|,
name|pp
operator|->
name|poll_ns
argument_list|)
expr_stmt|;
else|else
name|sop
operator|->
name|so_rcvhigh
operator|=
name|sop
operator|->
name|so_rcvmax
expr_stmt|;
comment|/* 	 * Return a STAT PDU to peer 	 */
name|SEQ_SET
argument_list|(
name|nps
argument_list|,
name|ntohl
argument_list|(
name|pp
operator|->
name|poll_nps
argument_list|)
argument_list|)
expr_stmt|;
name|KB_FREEALL
argument_list|(
name|m
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sscop_send_stat
argument_list|(
name|sop
argument_list|,
name|nps
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * STAT PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_stat_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Record error condition 	 */
name|sscop_stat_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_stat_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Go back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * USTAT PDU / SOS_CONRESYN Processor  *   * Arguments:  *	sop	pointer to sscop connection block  *	m	pointer to PDU buffer (without trailer)  *	trlr	pointer to PDU trailer  *  * Returns:  *	none  *  */
end_comment

begin_function
specifier|static
name|void
name|sscop_ustat_conresyn
parameter_list|(
name|sop
parameter_list|,
name|m
parameter_list|,
name|trlr
parameter_list|)
name|struct
name|sscop
modifier|*
name|sop
decl_stmt|;
name|KBuffer
modifier|*
name|m
decl_stmt|;
name|caddr_t
name|trlr
decl_stmt|;
block|{
name|int
name|err
decl_stmt|;
comment|/* 	 * Stop retransmit timer 	 */
name|sop
operator|->
name|so_timer
index|[
name|SSCOP_T_CC
index|]
operator|=
literal|0
expr_stmt|;
comment|/* 	 * Record error condition 	 */
name|sscop_ustat_error
argument_list|(
name|sop
argument_list|,
name|m
argument_list|,
name|trlr
argument_list|)
expr_stmt|;
comment|/* 	 * Return an END to peer 	 */
operator|(
name|void
operator|)
name|sscop_send_end
argument_list|(
name|sop
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|)
expr_stmt|;
comment|/* 	 * Notify user of connection failure 	 */
name|STACK_CALL
argument_list|(
name|SSCOP_RELEASE_IND
argument_list|,
name|sop
operator|->
name|so_upper
argument_list|,
name|sop
operator|->
name|so_toku
argument_list|,
name|sop
operator|->
name|so_connvc
argument_list|,
name|SSCOP_UU_NULL
argument_list|,
name|SSCOP_SOURCE_SSCOP
argument_list|,
name|err
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|sscop_abort
argument_list|(
name|sop
argument_list|,
literal|"sscop_ustat_conresyn: stack memory\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 * Clear connection data 	 */
name|qsaal1_clear_connection
argument_list|(
name|sop
argument_list|)
expr_stmt|;
comment|/* 	 * Go back to idle state 	 */
name|sop
operator|->
name|so_state
operator|=
name|SOS_IDLE
expr_stmt|;
return|return;
block|}
end_function

end_unit

