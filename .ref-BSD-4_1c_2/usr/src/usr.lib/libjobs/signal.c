begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)signal.c	4.3	(Berkeley)	12/28/82	*/
end_comment

begin_comment
comment|/*  * C library -- sigsys  *  * sigsys(n, SIG_DFL);		default action on signal(n)  * sigsys(n, SIG_HOLD);		block signal temporarily  * sigsys(n, SIG_IGN);		ignore signal(n)  * sigsys(n, label);		goto label on signal(n)  * sigsys(n, DEFERSIG(label));	goto label with signal SIG_HOLD  *  * returns old label, only one level.  */
end_comment

begin_include
include|#
directive|include
file|"SYS.h"
end_include

begin_define
define|#
directive|define
name|SIGDORTI
value|0x200
end_define

begin_define
define|#
directive|define
name|SYS_signal
value|48
end_define

begin_define
define|#
directive|define
name|SYS_sigsys
value|SYS_signal
end_define

begin_macro
name|SYSCALL
argument_list|(
argument|sigsys
argument_list|)
end_macro

begin_decl_stmt
name|ret
comment|/*  * sigpeel(n, newact)  *  * when called from routine which was called by system, peels  * back frames to the last one, then calls the system to reenable  * the signal with newact, arranging to clean the stack before the  * signal can happen again  */
define|#
directive|define
name|RETOFF
value|16
comment|/* offset of return address in frame */
name|ENTRY
argument_list|(
name|sigpeel
argument_list|)
name|movl
decl|4
argument_list|(
name|ap
argument_list|)
decl_stmt|,
name|r0
comment|/* get signal number value to set */
name|movl
decl|8
argument_list|(
name|ap
argument_list|)
decl_stmt|,
name|r1
name|movab
name|unw1
decl_stmt|,
name|RETOFF
argument_list|(
name|fp
argument_list|)
name|ret
comment|/* peel off our frame */
comment|/* top frame is now frame of routine signal action called */
name|unw1
range|:
name|movab
name|unw2
decl_stmt|,
name|RETOFF
argument_list|(
name|fp
argument_list|)
name|ret
comment|/*  * now frame from callg of ``locore.s/sigcode()'' is gone  * if no value to set, can just ret now to go back to old code  * with an ret->rei, else must make the frame passed to us into a  * signal call frame by putting the new signal code in the  * second word, and call the kernel which will pop off the frame.  */
name|unw2
range|:
name|tstl
name|r1
name|bneq
name|unw3
name|ret
comment|/* easy */
comment|/* mark dorti wanted, and reenable signal */
name|unw3
operator|:
name|bisl3
name|$SIGDORTI
decl_stmt|,
name|r0
decl_stmt|,4
argument_list|(
name|ap
argument_list|)
name|movl
name|r1
decl_stmt|,8
argument_list|(
name|ap
argument_list|)
name|chmk
name|$SYS_signal
name|halt
end_decl_stmt

begin_comment
comment|/* can't happen */
end_comment

end_unit

