begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MIPS32_SENTRY5_SENTRY5REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MIPS32_SENTRY5_SENTRY5REG_H_
end_define

begin_define
define|#
directive|define
name|SENTRY5_UART0ADR
value|0x18000300
end_define

begin_define
define|#
directive|define
name|SENTRY5_UART1ADR
value|0x18000400
end_define

begin_comment
comment|/* Reset register implemented here in a PLD device. */
end_comment

begin_define
define|#
directive|define
name|SENTRY5_EXTIFADR
value|0x1F000000
end_define

begin_define
define|#
directive|define
name|SENTRY5_DORESET
value|0x80
end_define

begin_comment
comment|/*  * Custom CP0 register macros.  * XXX: This really needs the mips cpuregs.h file for the barrier.  */
end_comment

begin_define
define|#
directive|define
name|S5_RDRW32_C0P0_CUST22
parameter_list|(
name|n
parameter_list|,
name|r
parameter_list|)
define|\
value|static __inline u_int32_t					\ s5_rd_ ## n (void)						\ {								\ 	int v0;							\ 	__asm __volatile ("mfc0 %[v0], $22, "__XSTRING(r)" ;"	\ 			  : [v0] "=&r"(v0));			\
comment|/*mips_barrier();*/
value|\ 	return (v0);						\ }								\ static __inline void						\ s5_wr_ ## n (u_int32_t a0)					\ {								\ 	__asm __volatile ("mtc0 %[a0], $22, "__XSTRING(r)" ;"	\ 			 __XSTRING(COP0_SYNC)";"		\ 			 "nop;"					\ 			 "nop;"					\ 			 :					\ 			 : [a0] "r"(a0));			\
comment|/*mips_barrier();*/
value|\ } struct __hack
end_define

begin_comment
comment|/*  * All 5 of these sub-registers are used by Linux.  * There is a further custom register at 25 which is not used.  */
end_comment

begin_define
define|#
directive|define
name|S5_CP0_DIAG
value|0
end_define

begin_define
define|#
directive|define
name|S5_CP0_CLKCFG1
value|1
end_define

begin_define
define|#
directive|define
name|S5_CP0_CLKCFG2
value|2
end_define

begin_define
define|#
directive|define
name|S5_CP0_SYNC
value|3
end_define

begin_define
define|#
directive|define
name|S5_CP0_CLKCFG3
value|4
end_define

begin_define
define|#
directive|define
name|S5_CP0_RESET
value|5
end_define

begin_comment
comment|/* s5_[rd|wr]_xxx() */
end_comment

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|diag
argument_list|,
name|S5_CP0_DIAG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|clkcfg1
argument_list|,
name|S5_CP0_CLKCFG1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|clkcfg2
argument_list|,
name|S5_CP0_CLKCFG2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|sync
argument_list|,
name|S5_CP0_SYNC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|clkcfg3
argument_list|,
name|S5_CP0_CLKCFG3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|S5_RDRW32_C0P0_CUST22
argument_list|(
name|reset
argument_list|,
name|S5_CP0_RESET
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MIPS32_SENTRY5_SENTRY5REG_H_ */
end_comment

end_unit

