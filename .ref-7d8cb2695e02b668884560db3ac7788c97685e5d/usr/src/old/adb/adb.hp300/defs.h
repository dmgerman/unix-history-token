begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.6	86/03/26	*/
end_comment

begin_comment
comment|/*  * adb - vax string table version; common definitions  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEWVM
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Ooff_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|off_t
value|Ooff_t
end_define

begin_include
include|#
directive|include
file|<hp300/pte.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEWVM
end_ifdef

begin_undef
undef|#
directive|undef
name|TRUE
end_undef

begin_undef
undef|#
directive|undef
name|FALSE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"mac.h"
end_include

begin_include
include|#
directive|include
file|"mode.h"
end_include

begin_include
include|#
directive|include
file|"head.h"
end_include

begin_comment
comment|/* access modes */
end_comment

begin_define
define|#
directive|define
name|RD
value|0
end_define

begin_define
define|#
directive|define
name|WT
value|1
end_define

begin_define
define|#
directive|define
name|NSP
value|0
end_define

begin_define
define|#
directive|define
name|ISP
value|1
end_define

begin_define
define|#
directive|define
name|DSP
value|2
end_define

begin_define
define|#
directive|define
name|STAR
value|4
end_define

begin_define
define|#
directive|define
name|PSP
value|8
end_define

begin_define
define|#
directive|define
name|STARCOM
value|0200
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_expr_stmt
name|I
name|guess
name|I
name|should
name|look
name|this
name|up
name|in
name|the
literal|2.10
name|source
operator|...
endif|#
directive|endif
ifdef|#
directive|ifdef
name|vax
comment|/*  * Symbol types, used internally in calls to findsym routine.  * One the VAX this all degenerates since I& D symbols are indistinct.  * Basically we get NSYM==0 for `=' command, ISYM==DSYM otherwise.  */
define|#
directive|define
name|NSYM
value|0
define|#
directive|define
name|DSYM
value|1
comment|/* Data space symbol */
define|#
directive|define
name|ISYM
value|DSYM
comment|/* Instruction space symbol == DSYM on VAX */
define|#
directive|define
name|BKPTSET
value|1
define|#
directive|define
name|BKPTEXEC
value|2
define|#
directive|define
name|USERPS
value|PSL
define|#
directive|define
name|USERPC
value|PC
define|#
directive|define
name|BPT
value|03
define|#
directive|define
name|TBIT
value|020
define|#
directive|define
name|FD
value|0200
define|#
directive|define
name|getradj
parameter_list|(
name|i
parameter_list|)
value|0
define|#
directive|define
name|lget
value|get
comment|/* puns from<sys/ptrace.h> */
define|#
directive|define
name|CONTIN
value|PT_CONTINUE
define|#
directive|define
name|SINGLE
value|PT_STEP
comment|/* the quantities involving ctob() are located in the kernel stack. */
comment|/* the others are in the pcb. */
define|#
directive|define
name|KSP
value|0
define|#
directive|define
name|ESP
value|4
define|#
directive|define
name|SSP
value|8
define|#
directive|define
name|USP
value|(ctob(UPAGES)-5*sizeof(int))
comment|/* should read this in from reg.h */
define|#
directive|define
name|R0
value|(ctob(UPAGES)-18*sizeof(int))
define|#
directive|define
name|R1
value|(ctob(UPAGES)-17*sizeof(int))
define|#
directive|define
name|R2
value|(ctob(UPAGES)-16*sizeof(int))
define|#
directive|define
name|R3
value|(ctob(UPAGES)-15*sizeof(int))
define|#
directive|define
name|R4
value|(ctob(UPAGES)-14*sizeof(int))
define|#
directive|define
name|R5
value|(ctob(UPAGES)-13*sizeof(int))
define|#
directive|define
name|R6
value|(ctob(UPAGES)-12*sizeof(int))
define|#
directive|define
name|R7
value|(ctob(UPAGES)-11*sizeof(int))
define|#
directive|define
name|R8
value|(ctob(UPAGES)-10*sizeof(int))
define|#
directive|define
name|R9
value|(ctob(UPAGES)-9*sizeof(int))
define|#
directive|define
name|R10
value|(ctob(UPAGES)-8*sizeof(int))
define|#
directive|define
name|R11
value|(ctob(UPAGES)-7*sizeof(int))
define|#
directive|define
name|AP
value|(ctob(UPAGES)-21*sizeof(int))
define|#
directive|define
name|FP
value|(ctob(UPAGES)-20*sizeof(int))
define|#
directive|define
name|PC
value|(ctob(UPAGES)-2*sizeof(int))
define|#
directive|define
name|PSL
value|(ctob(UPAGES)-1*sizeof(int))
define|#
directive|define
name|P0BR
value|80
define|#
directive|define
name|P0LR
value|84
define|#
directive|define
name|P1BR
value|88
define|#
directive|define
name|P1LR
value|92
endif|#
directive|endif
ifdef|#
directive|ifdef
name|hp300
define|#
directive|define
name|NSYM
value|0
comment|/* ??? */
define|#
directive|define
name|DSYM
value|1
comment|/* Data space symbol */
define|#
directive|define
name|ISYM
value|DSYM
comment|/* Instruction space symbol */
define|#
directive|define
name|BKPTSET
value|1
define|#
directive|define
name|BKPTEXEC
value|2
specifier|extern
name|L_INT
name|getradj
argument_list|()
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|BPT
value|0x4e42
end_define

begin_comment
comment|/* puns from<sys/ptrace.h> */
end_comment

begin_define
define|#
directive|define
name|CONTIN
value|PT_CONTINUE
end_define

begin_define
define|#
directive|define
name|SINGLE
value|PT_STEP
end_define

begin_comment
comment|/*  * Appropriated from dbx (returning a favor)  * `10' comes from:  *	(4)	stack starts 4 bytes in from end of uarea  *	(2)	trap type 0 frame format word is 2 bytes back from that  *	(4)	trap type 0 pc is 4 bytes back from that  */
end_comment

begin_define
define|#
directive|define
name|regloc
parameter_list|(
name|reg
parameter_list|)
value|(ctob(UPAGES) + (sizeof(int) * ((reg) - 17)) - 10)
end_define

begin_comment
comment|/* select map */
end_comment

begin_define
define|#
directive|define
name|mapptr
parameter_list|(
name|s
parameter_list|)
value|(((s)&DSP)?&datmap:(((s)&PSP)?&physmap:&txtmap))
end_define

begin_define
define|#
directive|define
name|KSP
value|12
end_define

begin_comment
comment|/* who knows? */
end_comment

begin_comment
comment|/* should read this in from reg.h */
end_comment

begin_define
define|#
directive|define
name|D0
value|regloc(0)
end_define

begin_define
define|#
directive|define
name|D1
value|regloc(1)
end_define

begin_define
define|#
directive|define
name|D2
value|regloc(2)
end_define

begin_define
define|#
directive|define
name|D3
value|regloc(3)
end_define

begin_define
define|#
directive|define
name|D4
value|regloc(4)
end_define

begin_define
define|#
directive|define
name|D5
value|regloc(5)
end_define

begin_define
define|#
directive|define
name|D6
value|regloc(6)
end_define

begin_define
define|#
directive|define
name|D7
value|regloc(7)
end_define

begin_define
define|#
directive|define
name|A0
value|regloc(8)
end_define

begin_define
define|#
directive|define
name|A1
value|regloc(9)
end_define

begin_define
define|#
directive|define
name|A2
value|regloc(10)
end_define

begin_define
define|#
directive|define
name|A3
value|regloc(11)
end_define

begin_define
define|#
directive|define
name|A4
value|regloc(12)
end_define

begin_define
define|#
directive|define
name|A5
value|regloc(13)
end_define

begin_define
define|#
directive|define
name|A6
value|regloc(14)
end_define

begin_define
define|#
directive|define
name|A7
value|regloc(15)
end_define

begin_comment
comment|/*  * In 4.4 these have changed, stackadj (pad) field is 4 bytes not 2  * so PSW/PC are 2 bytes further away from D0.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD4_4
argument_list|)
operator|||
name|defined
argument_list|(
name|HPBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|PSW
value|(regloc(16)+2)
end_define

begin_define
define|#
directive|define
name|PC
value|(regloc(17)+2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PSW
value|regloc(16)
end_define

begin_define
define|#
directive|define
name|PC
value|regloc(17)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FP
value|A6
end_define

begin_define
define|#
directive|define
name|USP
value|A7
end_define

begin_define
define|#
directive|define
name|P0BR
value|60
end_define

begin_define
define|#
directive|define
name|P0LR
value|64
end_define

begin_define
define|#
directive|define
name|P1BR
value|68
end_define

begin_define
define|#
directive|define
name|P1LR
value|72
end_define

begin_define
define|#
directive|define
name|FP0
value|332
end_define

begin_define
define|#
directive|define
name|FP1
value|344
end_define

begin_define
define|#
directive|define
name|FP2
value|356
end_define

begin_define
define|#
directive|define
name|FP3
value|368
end_define

begin_define
define|#
directive|define
name|FP4
value|380
end_define

begin_define
define|#
directive|define
name|FP5
value|392
end_define

begin_define
define|#
directive|define
name|FP6
value|404
end_define

begin_define
define|#
directive|define
name|FP7
value|416
end_define

begin_define
define|#
directive|define
name|FPCR
value|428
end_define

begin_define
define|#
directive|define
name|FPSR
value|432
end_define

begin_define
define|#
directive|define
name|FPIAR
value|436
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|pdp11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|hp300
argument_list|)
end_if

begin_expr_stmt
literal|"edit this file to accommodate your machine's addressing"
endif|#
directive|endif
define|#
directive|define
name|MAXOFF
value|255
define|#
directive|define
name|MAXPOS
value|80
define|#
directive|define
name|MAXLIN
value|128
define|#
directive|define
name|EOR
value|'\n'
define|#
directive|define
name|SP
value|' '
define|#
directive|define
name|TB
value|'\t'
define|#
directive|define
name|QUOTE
value|0200
define|#
directive|define
name|STRIP
value|0177
define|#
directive|define
name|EVEN
value|-2
comment|/* long to ints and back (puns) */
expr|union
block|{
name|INT
name|I
index|[
literal|2
index|]
block|;
name|L_INT
name|L
block|; }
name|itolws
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|leng
parameter_list|(
name|a
parameter_list|)
value|((long)((unsigned)(a)))
end_define

begin_define
define|#
directive|define
name|shorten
parameter_list|(
name|a
parameter_list|)
value|((int)(a))
end_define

begin_define
define|#
directive|define
name|itol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(itolws.I[0]=(a), itolws.I[1]=(b), itolws.L)
end_define

begin_define
define|#
directive|define
name|lobyte
parameter_list|(
name|a
parameter_list|)
value|((a)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|leng
parameter_list|(
name|a
parameter_list|)
value|itol(0,a)
end_define

begin_define
define|#
directive|define
name|shorten
parameter_list|(
name|a
parameter_list|)
value|((short)(a))
end_define

begin_define
define|#
directive|define
name|itol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(itolws.I[0]=(b), itolws.I[1]=(a), itolws.L)
end_define

begin_define
define|#
directive|define
name|lobyte
parameter_list|(
name|a
parameter_list|)
value|((a)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_define
define|#
directive|define
name|leng
parameter_list|(
name|a
parameter_list|)
value|itol(0,a)
end_define

begin_define
define|#
directive|define
name|shorten
parameter_list|(
name|a
parameter_list|)
value|((short)(a))
end_define

begin_define
define|#
directive|define
name|itol
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(itolws.I[0]=(a), itolws.I[1]=(b), itolws.L)
end_define

begin_define
define|#
directive|define
name|lobyte
parameter_list|(
name|a
parameter_list|)
value|(((a)>> 8)& 0377)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|pdp11
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|mc68000
argument_list|)
end_if

begin_expr_stmt
literal|"edit this file to suit your machine's byte order"
endif|#
directive|endif
comment|/* result type declarations */
name|L_INT
name|inkdot
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|POS
name|get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|POS
name|chkget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|POS
name|lchkget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|STRING
name|exform
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|L_INT
name|round
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|BKPTR
name|scanbkpt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|VOID
name|fault
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|pcb
name|pcb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kernel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kcore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pte
modifier|*
name|sbr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|slr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|masterpcbb
decl_stmt|;
end_decl_stmt

end_unit

