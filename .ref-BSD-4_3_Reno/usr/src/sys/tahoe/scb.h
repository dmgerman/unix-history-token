begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)scb.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * System control block.  */
end_comment

begin_struct
struct|struct
name|scb
block|{
name|int
function_decl|(
modifier|*
name|scb_vec0
function_decl|)
parameter_list|()
function_decl|;
comment|/* 000: reserved */
name|int
function_decl|(
modifier|*
name|scb_powfail
function_decl|)
parameter_list|()
function_decl|;
comment|/* 001: power failure */
name|int
function_decl|(
modifier|*
name|scb_doadump
function_decl|)
parameter_list|()
function_decl|;
comment|/* 002: power restore */
name|int
function_decl|(
modifier|*
name|scb_vec3
function_decl|)
parameter_list|()
function_decl|;
comment|/* 003: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec4
function_decl|)
parameter_list|()
function_decl|;
comment|/* 004: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec5
function_decl|)
parameter_list|()
function_decl|;
comment|/* 005: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec6
function_decl|)
parameter_list|()
function_decl|;
comment|/* 006: reserved */
name|int
function_decl|(
modifier|*
name|scb_hardclock
function_decl|)
parameter_list|()
function_decl|;
comment|/* 007: interval timer (clock) */
name|int
function_decl|(
modifier|*
name|scb_vec8
function_decl|)
parameter_list|()
function_decl|;
comment|/* 008: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec9
function_decl|)
parameter_list|()
function_decl|;
comment|/* 009: reserved */
name|int
function_decl|(
modifier|*
name|scb_cnrint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00a: console receive */
name|int
function_decl|(
modifier|*
name|scb_cnxint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00b: console transmit */
name|int
function_decl|(
modifier|*
name|scb_rmtrint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00c: remote line receive */
name|int
function_decl|(
modifier|*
name|scb_rmtxint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00d: remote line transmit */
name|int
function_decl|(
modifier|*
name|scb_vec14
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00e: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec15
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00f: reserved */
name|int
function_decl|(
modifier|*
name|scb_softint
index|[
literal|15
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* 010: software ints (ipl 1f-1) */
name|int
function_decl|(
modifier|*
name|scb_vec31
function_decl|)
parameter_list|()
function_decl|;
comment|/* 01f: reserved */
name|int
function_decl|(
modifier|*
name|scb_buserr
function_decl|)
parameter_list|()
function_decl|;
comment|/* 020: bus error */
name|int
function_decl|(
modifier|*
name|scb_vec33
function_decl|)
parameter_list|()
function_decl|;
comment|/* 021: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec34
function_decl|)
parameter_list|()
function_decl|;
comment|/* 022: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec35
function_decl|)
parameter_list|()
function_decl|;
comment|/* 023: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec36
function_decl|)
parameter_list|()
function_decl|;
comment|/* 024: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec37
function_decl|)
parameter_list|()
function_decl|;
comment|/* 025: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec38
function_decl|)
parameter_list|()
function_decl|;
comment|/* 026: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec39
function_decl|)
parameter_list|()
function_decl|;
comment|/* 027: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec40
function_decl|)
parameter_list|()
function_decl|;
comment|/* 028: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec41
function_decl|)
parameter_list|()
function_decl|;
comment|/* 029: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec42
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02a: reserved */
name|int
function_decl|(
modifier|*
name|scb_syscall
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02b: system call (kcall) */
name|int
function_decl|(
modifier|*
name|scb_privinflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02c: privileged/reserved inst */
name|int
function_decl|(
modifier|*
name|scb_respoflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02d: reserved operand */
name|int
function_decl|(
modifier|*
name|scb_resadflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02e: reserved addressing mode */
name|int
function_decl|(
modifier|*
name|scb_protflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02f: access control violation */
name|int
function_decl|(
modifier|*
name|scb_transflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 030: translation not valid */
name|int
function_decl|(
modifier|*
name|scb_kspnotval
function_decl|)
parameter_list|()
function_decl|;
comment|/* 031: kernel stack invalid */
name|int
function_decl|(
modifier|*
name|scb_tracep
function_decl|)
parameter_list|()
function_decl|;
comment|/* 032: trace trap */
name|int
function_decl|(
modifier|*
name|scb_bptflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 033: breakpoint */
name|int
function_decl|(
modifier|*
name|scb_arithtrap
function_decl|)
parameter_list|()
function_decl|;
comment|/* 034: arithmetic exception */
name|int
function_decl|(
modifier|*
name|scb_alignflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 035: alignment fault */
name|int
function_decl|(
modifier|*
name|scb_sfexcep
function_decl|)
parameter_list|()
function_decl|;
comment|/* 036: system forced exception */
name|int
function_decl|(
modifier|*
name|scb_fpm
function_decl|)
parameter_list|()
function_decl|;
comment|/* 037: floating point emulation */
name|int
function_decl|(
modifier|*
name|scb_vec56
function_decl|)
parameter_list|()
function_decl|;
comment|/* 038: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec57
function_decl|)
parameter_list|()
function_decl|;
comment|/* 039: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec58
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03a: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec59
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03b: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec60
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03c: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec61
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03d: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec62
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03e: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec63
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03f: reserved */
name|int
function_decl|(
modifier|*
name|scb_devint
index|[
literal|191
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* 040: device vectors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCB_LASTIV
value|(sizeof (((struct scb *)0)->scb_devint) / \     sizeof (((struct scb *)0)->scb_devint[0]))
end_define

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

