begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	scb.h	6.1	83/08/01	*/
end_comment

begin_comment
comment|/*  * VAX System control block layout  */
end_comment

begin_struct
struct|struct
name|scb
block|{
name|int
function_decl|(
modifier|*
name|scb_stray
function_decl|)
parameter_list|()
function_decl|;
comment|/* reserved */
name|int
function_decl|(
modifier|*
name|scb_machchk
function_decl|)
parameter_list|()
function_decl|;
comment|/* machine chack */
name|int
function_decl|(
modifier|*
name|scb_kspinval
function_decl|)
parameter_list|()
function_decl|;
comment|/* KSP invalid */
name|int
function_decl|(
modifier|*
name|scb_powfail
function_decl|)
parameter_list|()
function_decl|;
comment|/* power fail */
name|int
function_decl|(
modifier|*
name|scb_resinstr
function_decl|)
parameter_list|()
function_decl|;
comment|/* reserved instruction */
name|int
function_decl|(
modifier|*
name|scb_custinst
function_decl|)
parameter_list|()
function_decl|;
comment|/* XFC instr */
name|int
function_decl|(
modifier|*
name|scb_resopnd
function_decl|)
parameter_list|()
function_decl|;
comment|/* reserved operand */
name|int
function_decl|(
modifier|*
name|scb_resaddr
function_decl|)
parameter_list|()
function_decl|;
comment|/* reserved addr mode */
name|int
function_decl|(
modifier|*
name|scb_acv
function_decl|)
parameter_list|()
function_decl|;
comment|/* access control violation */
name|int
function_decl|(
modifier|*
name|scb_tnv
function_decl|)
parameter_list|()
function_decl|;
comment|/* translation not valid */
name|int
function_decl|(
modifier|*
name|scb_tracep
function_decl|)
parameter_list|()
function_decl|;
comment|/* trace pending */
name|int
function_decl|(
modifier|*
name|scb_bpt
function_decl|)
parameter_list|()
function_decl|;
comment|/* breakpoint instr */
name|int
function_decl|(
modifier|*
name|scb_compat
function_decl|)
parameter_list|()
function_decl|;
comment|/* compatibility mode fault */
name|int
function_decl|(
modifier|*
name|scb_arith
function_decl|)
parameter_list|()
function_decl|;
comment|/* arithmetic fault */
name|int
function_decl|(
modifier|*
name|scb_stray2
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|scb_stray3
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|scb_chmk
function_decl|)
parameter_list|()
function_decl|;
comment|/* CHMK instr */
name|int
function_decl|(
modifier|*
name|scb_chme
function_decl|)
parameter_list|()
function_decl|;
comment|/* CHME instr */
name|int
function_decl|(
modifier|*
name|scb_chms
function_decl|)
parameter_list|()
function_decl|;
comment|/* CHMS instr */
name|int
function_decl|(
modifier|*
name|scb_chmu
function_decl|)
parameter_list|()
function_decl|;
comment|/* CHMU instr */
name|int
function_decl|(
modifier|*
name|scb_sbisilo
function_decl|)
parameter_list|()
function_decl|;
comment|/* SBI silo compare */
name|int
function_decl|(
modifier|*
name|scb_cmrd
function_decl|)
parameter_list|()
function_decl|;
comment|/* corrected mem read data */
name|int
function_decl|(
modifier|*
name|scb_sbialert
function_decl|)
parameter_list|()
function_decl|;
comment|/* SBI alert */
name|int
function_decl|(
modifier|*
name|scb_sbiflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* SBI fault */
name|int
function_decl|(
modifier|*
name|scb_wtime
function_decl|)
parameter_list|()
function_decl|;
comment|/* memory write timeout */
name|int
function_decl|(
modifier|*
name|scb_stray4
index|[
literal|8
index|]
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|scb_soft
index|[
literal|15
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* software interrupt */
name|int
function_decl|(
modifier|*
name|scb_timer
function_decl|)
parameter_list|()
function_decl|;
comment|/* interval timer interrupt */
name|int
function_decl|(
modifier|*
name|scb_stray5
index|[
literal|7
index|]
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|scb_stray6
index|[
literal|4
index|]
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|scb_csdr
function_decl|)
parameter_list|()
function_decl|;
comment|/* console storage receive */
name|int
function_decl|(
modifier|*
name|scb_csdx
function_decl|)
parameter_list|()
function_decl|;
comment|/* console storage transmit */
name|int
function_decl|(
modifier|*
name|scb_ctr
function_decl|)
parameter_list|()
function_decl|;
comment|/* console terminal receive */
name|int
function_decl|(
modifier|*
name|scb_ctx
function_decl|)
parameter_list|()
function_decl|;
comment|/* console terminal transmit */
name|int
function_decl|(
modifier|*
name|scb_ipl14
index|[
literal|16
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* device interrupts IPL 14 */
name|int
function_decl|(
modifier|*
name|scb_ipl15
index|[
literal|16
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/*   "		"    IPL 15 */
name|int
function_decl|(
modifier|*
name|scb_ipl16
index|[
literal|16
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/*   "		"    IPL 16 */
name|int
function_decl|(
modifier|*
name|scb_ipl17
index|[
literal|16
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/*   "		"    IPL 17 */
name|int
function_decl|(
modifier|*
name|scb_ubaint
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* Unibus device intr */
name|int
function_decl|(
modifier|*
name|scb_uba1int
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* Unibus 1 device intr */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|scb
name|scb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scb.scb_ubaint is the same as UNIvec */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|scbentry
parameter_list|(
name|f
parameter_list|,
name|how
parameter_list|)
value|((int (*)())(((int)f)+how))
end_define

begin_define
define|#
directive|define
name|SCB_KSTACK
value|0
end_define

begin_define
define|#
directive|define
name|SCB_ISTACK
value|1
end_define

begin_define
define|#
directive|define
name|SCB_WCS
value|2
end_define

begin_define
define|#
directive|define
name|SCB_HALT
value|3
end_define

end_unit

