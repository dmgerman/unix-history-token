begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	scb.h	1.1	86/01/05	*/
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
comment|/* 004: power failure */
name|int
function_decl|(
modifier|*
name|scb_doadump
function_decl|)
parameter_list|()
function_decl|;
comment|/* 008: power restore */
name|int
function_decl|(
modifier|*
name|scb_vec3
function_decl|)
parameter_list|()
function_decl|;
comment|/* 00c: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec4
function_decl|)
parameter_list|()
function_decl|;
comment|/* 010: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec5
function_decl|)
parameter_list|()
function_decl|;
comment|/* 014: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec6
function_decl|)
parameter_list|()
function_decl|;
comment|/* 018: reserved */
name|int
function_decl|(
modifier|*
name|scb_hardclock
function_decl|)
parameter_list|()
function_decl|;
comment|/* 01c: interval timer (clock) */
name|int
function_decl|(
modifier|*
name|scb_vec8
function_decl|)
parameter_list|()
function_decl|;
comment|/* 020: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec9
function_decl|)
parameter_list|()
function_decl|;
comment|/* 024: reserved */
name|int
function_decl|(
modifier|*
name|scb_cnrint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 028: console receive */
name|int
function_decl|(
modifier|*
name|scb_cnxint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 02c: console transmit */
name|int
function_decl|(
modifier|*
name|scb_rmtrint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 030: remote line receive */
name|int
function_decl|(
modifier|*
name|scb_rmtxint
function_decl|)
parameter_list|()
function_decl|;
comment|/* 034: remote line transmit */
name|int
function_decl|(
modifier|*
name|scb_vec14
function_decl|)
parameter_list|()
function_decl|;
comment|/* 038: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec15
function_decl|)
parameter_list|()
function_decl|;
comment|/* 03c: reserved */
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
comment|/* 040: software ints (ipl 1f-1) */
name|int
function_decl|(
modifier|*
name|scb_vec31
function_decl|)
parameter_list|()
function_decl|;
comment|/* 07c: reserved */
name|int
function_decl|(
modifier|*
name|scb_buserr
function_decl|)
parameter_list|()
function_decl|;
comment|/* 080: bus error */
name|int
function_decl|(
modifier|*
name|scb_vec33
function_decl|)
parameter_list|()
function_decl|;
comment|/* 084: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec34
function_decl|)
parameter_list|()
function_decl|;
comment|/* 088: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec35
function_decl|)
parameter_list|()
function_decl|;
comment|/* 08c: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec36
function_decl|)
parameter_list|()
function_decl|;
comment|/* 090: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec37
function_decl|)
parameter_list|()
function_decl|;
comment|/* 094: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec38
function_decl|)
parameter_list|()
function_decl|;
comment|/* 098: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec39
function_decl|)
parameter_list|()
function_decl|;
comment|/* 09c: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec40
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0a0: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec41
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0a4: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec42
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0a8: reserved */
name|int
function_decl|(
modifier|*
name|scb_syscall
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0ac: system call (kcall) */
name|int
function_decl|(
modifier|*
name|scb_privinflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0b0: privileged/reserved inst */
name|int
function_decl|(
modifier|*
name|scb_respoflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0b4: reserved operand */
name|int
function_decl|(
modifier|*
name|scb_resadflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0b8: reserved addressing mode */
name|int
function_decl|(
modifier|*
name|scb_protflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0bc: access control violation */
name|int
function_decl|(
modifier|*
name|scb_transflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0c0: translation not valid */
name|int
function_decl|(
modifier|*
name|scb_kspnotval
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0c4: kernel stack invalid */
name|int
function_decl|(
modifier|*
name|scb_tracep
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0c8: trace trap */
name|int
function_decl|(
modifier|*
name|scb_bptflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0cc: breakpoint */
name|int
function_decl|(
modifier|*
name|scb_arithtrap
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0d0: arithmetic exception */
name|int
function_decl|(
modifier|*
name|scb_alignflt
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0d4: alignment fault */
name|int
function_decl|(
modifier|*
name|scb_sfexcep
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0d8: system forced exception */
name|int
function_decl|(
modifier|*
name|scb_fpm
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0dc: floating point emulation */
name|int
function_decl|(
modifier|*
name|scb_vec56
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0e0: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec57
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0e4: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec58
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0e8: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec59
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0ec: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec60
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0f0: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec61
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0f4: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec62
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0f8: reserved */
name|int
function_decl|(
modifier|*
name|scb_vec63
function_decl|)
parameter_list|()
function_decl|;
comment|/* 0fc: reserved */
name|int
function_decl|(
modifier|*
name|scb_devint
index|[
literal|192
index|]
function_decl|)
parameter_list|()
function_decl|;
comment|/* 100: device vectors */
block|}
struct|;
end_struct

end_unit

