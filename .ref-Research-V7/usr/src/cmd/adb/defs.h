begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  *  *	UNIX debugger - common definitions  *  */
end_comment

begin_comment
comment|/*	Layout of a.out file (fsym):  *  *	header of 8 words	magic number 405, 407, 410, 411  *				text size	)  *				data size	) in bytes but even  *				bss size	)  *				symbol table size  *				entry point  *				{unused}  *				flag set if no relocation  *  *  *	header:		0  *	text:		16  *	data:		16+textsize  *	relocation:	16+textsize+datasize  *	symbol table:	16+2*(textsize+datasize) or 16+textsize+datasize  *  */
end_comment

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
file|<sys/reg.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
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

begin_define
define|#
directive|define
name|VARB
value|11
end_define

begin_define
define|#
directive|define
name|VARD
value|13
end_define

begin_define
define|#
directive|define
name|VARE
value|14
end_define

begin_define
define|#
directive|define
name|VARM
value|22
end_define

begin_define
define|#
directive|define
name|VARS
value|28
end_define

begin_define
define|#
directive|define
name|VART
value|29
end_define

begin_define
define|#
directive|define
name|COREMAGIC
value|0140000
end_define

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

begin_define
define|#
directive|define
name|DSYM
value|7
end_define

begin_define
define|#
directive|define
name|ISYM
value|2
end_define

begin_define
define|#
directive|define
name|ASYM
value|1
end_define

begin_define
define|#
directive|define
name|NSYM
value|0
end_define

begin_define
define|#
directive|define
name|ESYM
value|(-1)
end_define

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
name|SYMSIZ
value|100
end_define

begin_define
define|#
directive|define
name|MAXSIG
value|20
end_define

begin_define
define|#
directive|define
name|USERPS
value|2*(512-1)
end_define

begin_define
define|#
directive|define
name|USERPC
value|2*(512-2)
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
name|SINGLE
value|9
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
name|FROFF
value|(&(0->fpsr))
end_define

begin_define
define|#
directive|define
name|FRLEN
value|25
end_define

begin_define
define|#
directive|define
name|FRMAX
value|6
end_define

begin_define
define|#
directive|define
name|ps
value|-1
end_define

begin_define
define|#
directive|define
name|pc
value|-2
end_define

begin_define
define|#
directive|define
name|sp
value|-6
end_define

begin_define
define|#
directive|define
name|r5
value|-9
end_define

begin_define
define|#
directive|define
name|r4
value|-10
end_define

begin_define
define|#
directive|define
name|r3
value|-11
end_define

begin_define
define|#
directive|define
name|r2
value|-12
end_define

begin_define
define|#
directive|define
name|r1
value|-5
end_define

begin_define
define|#
directive|define
name|r0
value|-3
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
name|SYMPTR
name|lookupsym
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|SYMPTR
name|symget
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

begin_typedef
typedef|typedef
name|struct
name|sgttyb
name|TTY
typedef|;
end_typedef

begin_decl_stmt
name|TTY
name|adbtty
decl_stmt|,
name|usrtty
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|erradb
decl_stmt|;
end_decl_stmt

end_unit

