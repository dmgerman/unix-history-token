begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	4.3	82/12/19	*/
end_comment

begin_comment
comment|/*  * adb - vax string table version; common definitions  */
end_comment

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

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
name|STARCOM
value|0200
end_define

begin_comment
comment|/*  * Symbol types, used internally in calls to findsym routine.  * One the VAX this all degenerates since I& D symbols are indistinct.  * Basically we get NSYM==0 for `=' command, ISYM==DSYM otherwise.  */
end_comment

begin_define
define|#
directive|define
name|NSYM
value|0
end_define

begin_define
define|#
directive|define
name|DSYM
value|1
end_define

begin_comment
comment|/* Data space symbol */
end_comment

begin_define
define|#
directive|define
name|ISYM
value|DSYM
end_define

begin_comment
comment|/* Instruction space symbol == DSYM on VAX */
end_comment

begin_define
define|#
directive|define
name|BKPTSET
value|1
end_define

begin_define
define|#
directive|define
name|BKPTEXEC
value|2
end_define

begin_define
define|#
directive|define
name|USERPS
value|PSL
end_define

begin_define
define|#
directive|define
name|USERPC
value|PC
end_define

begin_define
define|#
directive|define
name|BPT
value|03
end_define

begin_define
define|#
directive|define
name|TBIT
value|020
end_define

begin_define
define|#
directive|define
name|FD
value|0200
end_define

begin_define
define|#
directive|define
name|SETTRC
value|0
end_define

begin_define
define|#
directive|define
name|RDUSER
value|2
end_define

begin_define
define|#
directive|define
name|RIUSER
value|1
end_define

begin_define
define|#
directive|define
name|WDUSER
value|5
end_define

begin_define
define|#
directive|define
name|WIUSER
value|4
end_define

begin_define
define|#
directive|define
name|RUREGS
value|3
end_define

begin_define
define|#
directive|define
name|WUREGS
value|6
end_define

begin_define
define|#
directive|define
name|CONTIN
value|7
end_define

begin_define
define|#
directive|define
name|EXIT
value|8
end_define

begin_define
define|#
directive|define
name|SINGLE
value|9
end_define

begin_comment
comment|/* the quantities involving ctob() are located in the kernel stack. */
end_comment

begin_comment
comment|/* the others are in the pcb. */
end_comment

begin_define
define|#
directive|define
name|KSP
value|0
end_define

begin_define
define|#
directive|define
name|ESP
value|4
end_define

begin_define
define|#
directive|define
name|SSP
value|8
end_define

begin_define
define|#
directive|define
name|USP
value|(ctob(UPAGES)-5*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R0
value|(ctob(UPAGES)-18*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R1
value|(ctob(UPAGES)-17*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R2
value|(ctob(UPAGES)-16*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R3
value|(ctob(UPAGES)-15*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R4
value|(ctob(UPAGES)-14*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R5
value|(ctob(UPAGES)-13*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R6
value|(ctob(UPAGES)-12*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R7
value|(ctob(UPAGES)-11*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R8
value|(ctob(UPAGES)-10*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R9
value|(ctob(UPAGES)-9*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R10
value|(ctob(UPAGES)-8*sizeof(int))
end_define

begin_define
define|#
directive|define
name|R11
value|(ctob(UPAGES)-7*sizeof(int))
end_define

begin_define
define|#
directive|define
name|AP
value|(ctob(UPAGES)-21*sizeof(int))
end_define

begin_define
define|#
directive|define
name|FP
value|(ctob(UPAGES)-20*sizeof(int))
end_define

begin_define
define|#
directive|define
name|PC
value|(ctob(UPAGES)-2*sizeof(int))
end_define

begin_define
define|#
directive|define
name|PSL
value|(ctob(UPAGES)-1*sizeof(int))
end_define

begin_define
define|#
directive|define
name|P0BR
value|80
end_define

begin_define
define|#
directive|define
name|P0LR
value|84
end_define

begin_define
define|#
directive|define
name|P1BR
value|88
end_define

begin_define
define|#
directive|define
name|P1LR
value|92
end_define

begin_define
define|#
directive|define
name|MAXOFF
value|255
end_define

begin_define
define|#
directive|define
name|MAXPOS
value|80
end_define

begin_define
define|#
directive|define
name|MAXLIN
value|128
end_define

begin_define
define|#
directive|define
name|EOF
value|0
end_define

begin_define
define|#
directive|define
name|EOR
value|'\n'
end_define

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_define
define|#
directive|define
name|TB
value|'\t'
end_define

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|STRIP
value|0177
end_define

begin_define
define|#
directive|define
name|LOBYTE
value|0377
end_define

begin_define
define|#
directive|define
name|EVEN
value|-2
end_define

begin_comment
comment|/* long to ints and back (puns) */
end_comment

begin_union
union|union
block|{
name|INT
name|I
index|[
literal|2
index|]
decl_stmt|;
name|L_INT
name|L
decl_stmt|;
block|}
name|itolws
union|;
end_union

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* result type declarations */
end_comment

begin_function_decl
name|L_INT
name|inkdot
parameter_list|()
function_decl|;
end_function_decl

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

