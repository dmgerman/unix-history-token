begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* #define OLD_BSD if you're running< 4.2 bsd */
end_comment

begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)trpfpe_.c	5.5	%G%  *  *  *	Fortran floating-point error handler  *  *	Synopsis:  *		call trpfpe (n, retval)  *			causes floating point faults to be trapped, with the  *			first 'n' errors getting a message printed.  *			'retval' is put in place of the bad result.  *		k = fpecnt()  *			causes 'k' to get the number of errors since the  *			last call to trpfpe().  *  *		common /fpeflt/ fpflag  *		logical fpflag  *			fpflag will become .true. on faults  *  *	David Wasley, UCBerkeley, June 1983.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|"../libI77/fiodefs.h"
end_include

begin_define
define|#
directive|define
name|SIG_VAL
value|void (*)()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_include
include|#
directive|include
file|"opcodes.h"
end_include

begin_include
include|#
directive|include
file|"operand.h"
end_include

begin_struct
struct|struct
name|arglist
block|{
comment|/* what AP points to */
name|long
name|al_numarg
decl_stmt|;
comment|/* only true in CALLS format */
name|long
name|al_arg
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cframe
block|{
comment|/* VAX call frame */
name|long
name|cf_handler
decl_stmt|;
name|unsigned
name|short
name|cf_psw
decl_stmt|;
name|unsigned
name|short
name|cf_mask
decl_stmt|;
name|struct
name|arglist
modifier|*
name|cf_ap
decl_stmt|;
name|struct
name|cframe
modifier|*
name|cf_fp
decl_stmt|;
name|char
modifier|*
name|cf_pc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * bits in the PSW  */
end_comment

begin_define
define|#
directive|define
name|PSW_V
value|0x2
end_define

begin_define
define|#
directive|define
name|PSW_FU
value|0x40
end_define

begin_define
define|#
directive|define
name|PSW_IV
value|0x20
end_define

begin_comment
comment|/*  * where the registers are stored as we see them in the handler  */
end_comment

begin_struct
struct|struct
name|reg0_6
block|{
name|long
name|reg
index|[
literal|7
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg7_11
block|{
name|long
name|reg
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|iR0
value|reg0_6->reg[0]
end_define

begin_define
define|#
directive|define
name|iR1
value|reg0_6->reg[1]
end_define

begin_define
define|#
directive|define
name|iR2
value|reg0_6->reg[2]
end_define

begin_define
define|#
directive|define
name|iR3
value|reg0_6->reg[3]
end_define

begin_define
define|#
directive|define
name|iR4
value|reg0_6->reg[4]
end_define

begin_define
define|#
directive|define
name|iR5
value|reg0_6->reg[5]
end_define

begin_define
define|#
directive|define
name|iR6
value|reg0_6->reg[6]
end_define

begin_define
define|#
directive|define
name|iR7
value|reg7_11->reg[0]
end_define

begin_define
define|#
directive|define
name|iR8
value|reg7_11->reg[1]
end_define

begin_define
define|#
directive|define
name|iR9
value|reg7_11->reg[2]
end_define

begin_define
define|#
directive|define
name|iR10
value|reg7_11->reg[3]
end_define

begin_define
define|#
directive|define
name|iR11
value|reg7_11->reg[4]
end_define

begin_union
union|union
name|objects
block|{
comment|/* for load/store */
name|char
name|ua_byte
decl_stmt|;
name|short
name|ua_word
decl_stmt|;
name|long
name|ua_long
decl_stmt|;
name|float
name|ua_float
decl_stmt|;
name|double
name|ua_double
decl_stmt|;
name|union
name|objects
modifier|*
name|ua_anything
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|objects
name|anything
typedef|;
end_typedef

begin_enum
enum|enum
name|object_type
block|{
name|BYTE
block|,
name|WORD
block|,
name|LONG
block|,
name|FLOAT
block|,
name|QUAD
block|,
name|DOUBLE
block|,
name|UNKNOWN
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/*  * assembly language assist  * There are some things you just can't do in C  */
end_comment

begin_asm
asm|asm(".text");
end_asm

begin_function_decl
name|struct
name|cframe
modifier|*
name|myfp
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_myfp: .word 0x0");
end_asm

begin_asm
asm|asm("movl 12(fp),r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_function_decl
name|struct
name|arglist
modifier|*
name|myap
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_myap: .word 0x0");
end_asm

begin_asm
asm|asm("movl 8(fp),r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_function_decl
name|char
modifier|*
name|mysp
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_mysp: .word 0x0");
end_asm

begin_asm
asm|asm("extzv $30,$2,4(fp),r0");
end_asm

begin_asm
asm|asm("addl2 ap,r0");
end_asm

begin_comment
comment|/* SP in caller is AP+4 here + SPA bits! */
end_comment

begin_asm
asm|asm("addl2 $4,r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_function_decl
name|char
modifier|*
name|mypc
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_mypc: .word 0x0");
end_asm

begin_asm
asm|asm("movl 16(fp),r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_asm
asm|asm(".data");
end_asm

begin_escape
end_escape

begin_comment
comment|/*  * Where interrupted objects are  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|cframe
modifier|*
modifier|*
name|ifp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved FP */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|arglist
modifier|*
modifier|*
name|iap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved AP */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|isp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of interrupted SP */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|ipc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved PC */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|reg0_6
modifier|*
name|reg0_6
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* registers 0-6 are saved on the exception */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|reg7_11
modifier|*
name|reg7_11
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we save 7-11 by our entry mask */
end_comment

begin_decl_stmt
specifier|static
name|anything
modifier|*
name|result_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where the dummy result goes */
end_comment

begin_decl_stmt
specifier|static
name|enum
name|object_type
name|result_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what kind of object it is */
end_comment

begin_comment
comment|/*  * some globals  */
end_comment

begin_union
specifier|static
union|union
block|{
name|long
name|rv_long
index|[
literal|2
index|]
decl_stmt|;
name|float
name|rv_float
decl_stmt|;
name|double
name|rv_double
decl_stmt|;
block|}
name|retval
union|;
end_union

begin_comment
comment|/* the user specified dummy result */
end_comment

begin_decl_stmt
specifier|static
name|int
name|max_messages
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the user can tell us */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fpe_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how bad is it ? */
end_comment

begin_decl_stmt
name|long
name|fpeflt_
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fortran "common /fpeflt/ flag" */
end_comment

begin_function_decl
specifier|static
name|int
function_decl|(
modifier|*
name|sigfpe_dfl
function_decl|)
parameter_list|()
init|=
name|SIG_DFL
function_decl|;
end_function_decl

begin_comment
comment|/* if we can't fix it ... */
end_comment

begin_comment
comment|/*  * The fortran unit control table  */
end_comment

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Fortran message table is in main  */
end_comment

begin_struct
struct|struct
name|msgtbl
block|{
name|char
modifier|*
name|mesg
decl_stmt|;
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|msgtbl
name|act_fpe
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * Get the address of the (saved) next operand& update saved PC.  * The major purpose of this is to determine where to store the result.  * There is one case we can't deal with: -(SP) or (SP)+  * since we can't change the size of the stack.  * Let's just hope compilers don't generate that for results.  */
end_comment

begin_function
name|anything
modifier|*
name|get_operand
parameter_list|(
name|oper_size
parameter_list|)
name|int
name|oper_size
decl_stmt|;
comment|/* size of operand we expect */
block|{
specifier|register
name|int
name|regnum
decl_stmt|;
specifier|register
name|int
name|operand_code
decl_stmt|;
name|int
name|index
decl_stmt|;
name|anything
modifier|*
name|oper_addr
decl_stmt|;
name|anything
modifier|*
name|reg_addr
decl_stmt|;
name|regnum
operator|=
operator|(
operator|*
operator|*
name|ipc
operator|&
literal|0xf
operator|)
expr_stmt|;
if|if
condition|(
name|regnum
operator|==
name|PC
condition|)
name|operand_code
operator|=
operator|(
operator|*
operator|(
operator|*
name|ipc
operator|)
operator|++
operator|&
literal|0xff
operator|)
expr_stmt|;
else|else
name|operand_code
operator|=
operator|(
operator|*
operator|(
operator|*
name|ipc
operator|)
operator|++
operator|&
literal|0xf0
operator|)
expr_stmt|;
if|if
condition|(
name|regnum
operator|<=
name|R6
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|&
name|reg0_6
operator|->
name|reg
index|[
name|regnum
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|regnum
operator|<=
name|R11
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|&
name|reg7_11
operator|->
name|reg
index|[
name|regnum
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|regnum
operator|==
name|AP
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
name|iap
expr_stmt|;
elseif|else
if|if
condition|(
name|regnum
operator|==
name|FP
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
name|ifp
expr_stmt|;
elseif|else
if|if
condition|(
name|regnum
operator|==
name|SP
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|&
name|isp
expr_stmt|;
comment|/* We saved this ourselves */
elseif|else
if|if
condition|(
name|regnum
operator|==
name|PC
condition|)
name|reg_addr
operator|=
operator|(
name|anything
operator|*
operator|)
name|ipc
expr_stmt|;
switch|switch
condition|(
name|operand_code
condition|)
block|{
case|case
name|IMMEDIATE
case|:
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
expr_stmt|;
operator|*
name|ipc
operator|+=
name|oper_size
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|ABSOLUTE
case|:
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
operator|*
name|ipc
operator|)
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|anything
operator|*
argument_list|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|LITERAL0
case|:
case|case
name|LITERAL1
case|:
case|case
name|LITERAL2
case|:
case|case
name|LITERAL3
case|:
comment|/* we don't care about the address of these */
return|return
operator|(
operator|(
name|anything
operator|*
operator|)
literal|0
operator|)
return|;
case|case
name|INDEXED
case|:
name|index
operator|=
name|reg_addr
operator|->
name|ua_long
operator|*
name|oper_size
expr_stmt|;
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|long
argument_list|)
argument_list|)
operator|->
name|ua_long
operator|+
name|index
operator|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|REGISTER
case|:
return|return
operator|(
name|reg_addr
operator|)
return|;
case|case
name|REGDEFERED
case|:
return|return
operator|(
name|reg_addr
operator|->
name|ua_anything
operator|)
return|;
case|case
name|AUTODEC
case|:
if|if
condition|(
name|regnum
operator|==
name|SP
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"trp: can't fix -(SP) operand\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|reg_addr
operator|->
name|ua_long
operator|-=
name|oper_size
expr_stmt|;
name|oper_addr
operator|=
name|reg_addr
operator|->
name|ua_anything
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|AUTOINC
case|:
if|if
condition|(
name|regnum
operator|==
name|SP
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"trp: can't fix (SP)+ operand\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|oper_addr
operator|=
name|reg_addr
operator|->
name|ua_anything
expr_stmt|;
name|reg_addr
operator|->
name|ua_long
operator|+=
name|oper_size
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|AUTOINCDEF
case|:
if|if
condition|(
name|regnum
operator|==
name|SP
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"trp: can't fix @(SP)+ operand\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|oper_addr
operator|=
operator|(
name|reg_addr
operator|->
name|ua_anything
operator|)
operator|->
name|ua_anything
expr_stmt|;
name|reg_addr
operator|->
name|ua_long
operator|+=
sizeof|sizeof
argument_list|(
name|anything
operator|*
argument_list|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|BYTEDISP
case|:
case|case
name|BYTEREL
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_byte
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|BYTEDISPDEF
case|:
case|case
name|BYTERELDEF
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_byte
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|char
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
name|oper_addr
operator|=
name|oper_addr
operator|->
name|ua_anything
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|WORDDISP
case|:
case|case
name|WORDREL
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_word
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|WORDDISPDEF
case|:
case|case
name|WORDRELDEF
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_word
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
name|oper_addr
operator|=
name|oper_addr
operator|->
name|ua_anything
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|LONGDISP
case|:
case|case
name|LONGREL
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_long
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|long
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
case|case
name|LONGDISPDEF
case|:
case|case
name|LONGRELDEF
case|:
name|index
operator|=
operator|(
operator|(
name|anything
operator|*
operator|)
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|->
name|ua_long
expr_stmt|;
operator|*
name|ipc
operator|+=
sizeof|sizeof
argument_list|(
name|long
argument_list|)
expr_stmt|;
comment|/* do it now in case reg==PC */
name|oper_addr
operator|=
operator|(
name|anything
operator|*
operator|)
operator|(
name|index
operator|+
name|reg_addr
operator|->
name|ua_long
operator|)
expr_stmt|;
name|oper_addr
operator|=
name|oper_addr
operator|->
name|ua_anything
expr_stmt|;
return|return
operator|(
name|oper_addr
operator|)
return|;
comment|/* NOTREACHED */
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * Trap& repair floating exceptions so that a program may proceed.  * There is no notion of "correctness" here; just the ability to continue.  *  * The on_fpe() routine first checks the type code to see if the  * exception is repairable. If so, it checks the opcode to see if  * it is one that it knows. If this is true, it then simulates the  * VAX cpu in retrieving operands in order to increment iPC correctly.  * It notes where the result of the operation would have been stored  * and substitutes a previously supplied value.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_BSD
end_ifdef

begin_macro
name|on_fpe
argument_list|(
argument|signo
argument_list|,
argument|code
argument_list|,
argument|myaddr
argument_list|,
argument|pc
argument_list|,
argument|ps
argument_list|)
end_macro

begin_decl_stmt
name|int
name|signo
decl_stmt|,
name|code
decl_stmt|,
name|ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myaddr
decl_stmt|,
modifier|*
name|pc
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|on_fpe
parameter_list|(
name|signo
parameter_list|,
name|code
parameter_list|,
name|sc
parameter_list|,
name|grbg
parameter_list|)
name|int
name|signo
decl_stmt|,
name|code
decl_stmt|;
name|struct
name|sigcontext
modifier|*
name|sc
decl_stmt|;
endif|#
directive|endif
block|{
comment|/* 	 * There must be at least 5 register variables here 	 * so our entry mask will save R11-R7. 	 */
specifier|register
name|long
modifier|*
name|stk
decl_stmt|;
specifier|register
name|long
modifier|*
name|sp
decl_stmt|;
specifier|register
name|struct
name|arglist
modifier|*
name|ap
decl_stmt|;
specifier|register
name|struct
name|cframe
modifier|*
name|fp
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|ef
decl_stmt|;
name|ef
operator|=
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
expr_stmt|;
comment|/* fortran error stream */
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|FPE_INTOVF_TRAP
case|:
comment|/* integer overflow */
case|case
name|FPE_INTDIV_TRAP
case|:
comment|/* integer divide by zero */
case|case
name|FPE_FLTOVF_TRAP
case|:
comment|/* floating overflow */
case|case
name|FPE_FLTDIV_TRAP
case|:
comment|/* floating/decimal divide by zero */
case|case
name|FPE_FLTUND_TRAP
case|:
comment|/* floating underflow */
case|case
name|FPE_DECOVF_TRAP
case|:
comment|/* decimal overflow */
case|case
name|FPE_SUBRNG_TRAP
case|:
comment|/* subscript out of range */
default|default:
name|cant_fix
label|:
if|if
condition|(
name|sigfpe_dfl
operator|>
operator|(
name|SIG_VAL
operator|)
literal|7
condition|)
comment|/* user specified */
ifdef|#
directive|ifdef
name|OLD_BSD
call|(
modifier|*
name|sigfpe_dfl
call|)
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|myaddr
argument_list|,
name|pc
argument_list|,
name|ps
argument_list|)
expr_stmt|;
else|#
directive|else
call|(
modifier|*
name|sigfpe_dfl
call|)
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|sc
argument_list|,
name|grbg
argument_list|)
expr_stmt|;
endif|#
directive|endif
else|else
ifdef|#
directive|ifdef
name|OLD_BSD
name|sigdie
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|myaddr
argument_list|,
name|pc
argument_list|,
name|ps
argument_list|)
expr_stmt|;
else|#
directive|else
name|sigdie
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|sc
argument_list|,
name|grbg
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOTREACHED */
case|case
name|FPE_FLTOVF_FAULT
case|:
comment|/* floating overflow fault */
case|case
name|FPE_FLTDIV_FAULT
case|:
comment|/* divide by zero floating fault */
case|case
name|FPE_FLTUND_FAULT
case|:
comment|/* floating underflow fault */
if|if
condition|(
operator|++
name|fpe_count
operator|<=
name|max_messages
condition|)
block|{
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|"trpfpe: %s"
argument_list|,
name|act_fpe
index|[
name|code
operator|-
literal|1
index|]
operator|.
name|mesg
argument_list|)
expr_stmt|;
if|if
condition|(
name|fpe_count
operator|==
name|max_messages
condition|)
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|": No more messages will be printed.\n"
argument_list|)
expr_stmt|;
else|else
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|ef
argument_list|)
expr_stmt|;
block|}
name|fpeflt_
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
name|ap
operator|=
name|myap
argument_list|()
expr_stmt|;
comment|/* my arglist pointer */
name|fp
operator|=
name|myfp
argument_list|()
expr_stmt|;
comment|/* my frame pointer */
name|ifp
operator|=
operator|&
operator|(
name|fp
operator|->
name|cf_fp
operator|)
operator|->
name|cf_fp
expr_stmt|;
comment|/* user's stored in next frame back */
name|iap
operator|=
operator|&
operator|(
name|fp
operator|->
name|cf_fp
operator|)
operator|->
name|cf_ap
expr_stmt|;
comment|/* 	 * these are likely to be system dependent 	 */
name|reg0_6
operator|=
operator|(
expr|struct
name|reg0_6
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|fp
operator|->
name|cf_fp
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|cframe
argument_list|)
operator|)
expr_stmt|;
name|reg7_11
operator|=
operator|(
expr|struct
name|reg7_11
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|fp
operator|->
name|cf_fp
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|reg7_11
argument_list|)
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|OLD_BSD
name|ipc
operator|=
operator|&
name|pc
expr_stmt|;
name|isp
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
name|ap
operator|->
name|al_arg
index|[
name|ap
operator|->
name|al_numarg
operator|+
literal|2
index|]
expr_stmt|;
comment|/* assumes 2 dummys */
name|ps
operator|&=
operator|~
operator|(
name|PSW_V
operator||
name|PSW_FU
operator|)
expr_stmt|;
else|#
directive|else
name|ipc
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|&
name|sc
operator|->
name|sc_pc
expr_stmt|;
name|isp
operator|=
operator|(
name|char
operator|*
operator|)
name|sc
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|sigcontext
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_ps
operator|&=
operator|~
operator|(
name|PSW_V
operator||
name|PSW_FU
operator|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
operator|*
operator|(
operator|*
name|ipc
operator|)
operator|++
condition|)
block|{
case|case
name|ADDD3
case|:
case|case
name|DIVD3
case|:
case|case
name|MULD3
case|:
case|case
name|SUBD3
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
comment|/* intentional fall-thru */
case|case
name|ADDD2
case|:
case|case
name|DIVD2
case|:
case|case
name|MULD2
case|:
case|case
name|SUBD2
case|:
case|case
name|MNEGD
case|:
case|case
name|MOVD
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
name|result_addr
operator|=
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
name|result_type
operator|=
name|DOUBLE
expr_stmt|;
break|break;
case|case
name|ADDF3
case|:
case|case
name|DIVF3
case|:
case|case
name|MULF3
case|:
case|case
name|SUBF3
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
comment|/* intentional fall-thru */
case|case
name|ADDF2
case|:
case|case
name|DIVF2
case|:
case|case
name|MULF2
case|:
case|case
name|SUBF2
case|:
case|case
name|MNEGF
case|:
case|case
name|MOVF
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|result_addr
operator|=
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|result_type
operator|=
name|FLOAT
expr_stmt|;
break|break;
case|case
name|CVTDF
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
name|result_addr
operator|=
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|result_type
operator|=
name|FLOAT
expr_stmt|;
break|break;
case|case
name|CVTFD
case|:
operator|(
name|void
operator|)
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|result_addr
operator|=
name|get_operand
argument_list|(
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
name|result_type
operator|=
name|DOUBLE
expr_stmt|;
break|break;
case|case
name|EMODF
case|:
case|case
name|EMODD
case|:
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|"trpfpe: can't fix emod yet\n"
argument_list|)
expr_stmt|;
goto|goto
name|cant_fix
goto|;
case|case
name|POLYF
case|:
case|case
name|POLYD
case|:
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|"trpfpe: can't fix poly yet\n"
argument_list|)
expr_stmt|;
goto|goto
name|cant_fix
goto|;
case|case
name|ACBD
case|:
case|case
name|ACBF
case|:
case|case
name|CMPD
case|:
case|case
name|CMPF
case|:
case|case
name|TSTD
case|:
case|case
name|TSTF
case|:
case|case
name|CVTDB
case|:
case|case
name|CVTDL
case|:
case|case
name|CVTDW
case|:
case|case
name|CVTFB
case|:
case|case
name|CVTFL
case|:
case|case
name|CVTFW
case|:
case|case
name|CVTRDL
case|:
case|case
name|CVTRFL
case|:
comment|/* These can generate only reserved operand faults */
comment|/* They are shown here for completeness */
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"trp: opcode 0x%02x unknown\n"
argument_list|,
operator|*
operator|(
operator|--
operator|(
operator|*
name|ipc
operator|)
operator|)
operator|&
literal|0xff
argument_list|)
expr_stmt|;
goto|goto
name|cant_fix
goto|;
comment|/* NOTREACHED */
block|}
if|if
condition|(
name|result_type
operator|==
name|FLOAT
condition|)
name|result_addr
operator|->
name|ua_float
operator|=
name|retval
operator|.
name|rv_float
expr_stmt|;
else|else
block|{
if|if
condition|(
name|result_addr
operator|==
operator|(
name|anything
operator|*
operator|)
operator|&
name|iR6
condition|)
block|{
comment|/* 			 * special case - the R6/R7 pair is stored apart 			 */
name|result_addr
operator|->
name|ua_long
operator|=
name|retval
operator|.
name|rv_long
index|[
literal|0
index|]
expr_stmt|;
operator|(
operator|(
name|anything
operator|*
operator|)
operator|&
name|iR7
operator|)
operator|->
name|ua_long
operator|=
name|retval
operator|.
name|rv_long
index|[
literal|1
index|]
expr_stmt|;
block|}
else|else
name|result_addr
operator|->
name|ua_double
operator|=
name|retval
operator|.
name|rv_double
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|on_fpe
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|trpfpe_
argument_list|(
argument|count
argument_list|,
argument|rval
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many to announce */
end_comment

begin_decl_stmt
name|double
modifier|*
name|rval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy return value */
end_comment

begin_block
block|{
name|max_messages
operator|=
operator|*
name|count
expr_stmt|;
name|retval
operator|.
name|rv_double
operator|=
operator|*
name|rval
expr_stmt|;
name|sigfpe_dfl
operator|=
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|on_fpe
argument_list|)
expr_stmt|;
name|fpe_count
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_function
name|long
name|fpecnt_
parameter_list|()
block|{
return|return
operator|(
name|fpe_count
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|vax
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_comment
comment|/*  *	This handler just prints a message. It cannot fix anything  * 	on Power6 because of its fpp architecture. In any case, there  * 	are no arithmetic faults (only traps) around, so that no instruction  *	is interrupted befor it completes, and PC points to the next floating  *	point instruction (not necessarily next executable instr after the one  *	that got the exception).  */
end_comment

begin_struct
struct|struct
name|arglist
block|{
comment|/* what AP points to */
name|long
name|al_arg
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg0_1
block|{
name|long
name|reg
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reg2_12
block|{
name|long
name|reg
index|[
literal|11
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<frame.h>
end_include

begin_include
include|#
directive|include
file|"sigframe.h"
end_include

begin_comment
comment|/*  * bits in the PSL  */
end_comment

begin_include
include|#
directive|include
file|<machine/psl.h>
end_include

begin_comment
comment|/*  * where the registers are stored as we see them in the handler  */
end_comment

begin_define
define|#
directive|define
name|iR0
value|reg0_1->reg[1]
end_define

begin_define
define|#
directive|define
name|iR1
value|reg0_1->reg[0]
end_define

begin_define
define|#
directive|define
name|iR2
value|reg2_12->reg[0]
end_define

begin_define
define|#
directive|define
name|iR3
value|reg2_12->reg[1]
end_define

begin_define
define|#
directive|define
name|iR4
value|reg2_12->reg[2]
end_define

begin_define
define|#
directive|define
name|iR5
value|reg2_12->reg[3]
end_define

begin_define
define|#
directive|define
name|iR6
value|reg2_12->reg[4]
end_define

begin_define
define|#
directive|define
name|iR7
value|reg2_12->reg[5]
end_define

begin_define
define|#
directive|define
name|iR8
value|reg2_12->reg[6]
end_define

begin_define
define|#
directive|define
name|iR9
value|reg2_12->reg[7]
end_define

begin_define
define|#
directive|define
name|iR10
value|reg2_12->reg[8]
end_define

begin_define
define|#
directive|define
name|iR11
value|reg2_12->reg[9]
end_define

begin_define
define|#
directive|define
name|iR12
value|reg2_12->reg[10]
end_define

begin_union
union|union
name|objects
block|{
comment|/* for load/store */
name|char
name|ua_byte
decl_stmt|;
name|short
name|ua_word
decl_stmt|;
name|long
name|ua_long
decl_stmt|;
name|float
name|ua_float
decl_stmt|;
name|double
name|ua_double
decl_stmt|;
name|union
name|objects
modifier|*
name|ua_anything
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|objects
name|anything
typedef|;
end_typedef

begin_enum
enum|enum
name|object_type
block|{
name|BYTE
block|,
name|WORD
block|,
name|LONG
block|,
name|FLOAT
block|,
name|QUAD
block|,
name|DOUBLE
block|,
name|UNKNOWN
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/*  * assembly language assist  * There are some things you just can't do in C  */
end_comment

begin_asm
asm|asm(".text");
end_asm

begin_function_decl
name|long
modifier|*
name|myfp
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_myfp: .word 0");
end_asm

begin_asm
asm|asm("movl (fp),r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_function
name|struct
name|frame
modifier|*
name|framep
parameter_list|(
name|p
parameter_list|)
name|long
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
operator|(
expr|struct
name|frame
operator|*
operator|)
operator|(
name|p
operator|-
literal|2
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|struct
name|arglist
modifier|*
name|argp
parameter_list|(
name|p
parameter_list|)
name|long
modifier|*
name|p
decl_stmt|;
block|{
return|return
operator|(
operator|(
expr|struct
name|arglist
operator|*
operator|)
operator|(
name|p
operator|+
literal|1
operator|)
operator|)
return|;
block|}
end_function

begin_function_decl
name|char
modifier|*
name|mysp
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_mysp: .word 0");
end_asm

begin_asm
asm|asm("addl3 $4,fp,r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_function_decl
name|char
modifier|*
name|mypc
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm("_mypc: .word 0");
end_asm

begin_asm
asm|asm("movl -8(fp),r0");
end_asm

begin_asm
asm|asm("ret");
end_asm

begin_asm
asm|asm(".data");
end_asm

begin_escape
end_escape

begin_comment
comment|/*  * Where interrupted objects are  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|frame
modifier|*
name|ifp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved FP */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|arglist
modifier|*
name|iap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved AP */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|isp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value of interrupted SP */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
modifier|*
name|ipc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* addr of saved PC */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|reg0_1
modifier|*
name|reg0_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* registers 0-1 are saved on the exception */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|reg2_12
modifier|*
name|reg2_12
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* we save 2-12 by our entry mask */
end_comment

begin_decl_stmt
specifier|static
name|anything
modifier|*
name|result_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where the dummy result goes */
end_comment

begin_decl_stmt
specifier|static
name|enum
name|object_type
name|result_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what kind of object it is */
end_comment

begin_comment
comment|/*  * some globals  */
end_comment

begin_union
specifier|static
union|union
block|{
name|long
name|rv_long
index|[
literal|2
index|]
decl_stmt|;
name|float
name|rv_float
decl_stmt|;
name|double
name|rv_double
decl_stmt|;
block|}
name|retval
union|;
end_union

begin_comment
comment|/* the user specified dummy result */
end_comment

begin_decl_stmt
specifier|static
name|int
name|max_messages
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the user can tell us */
end_comment

begin_decl_stmt
specifier|static
name|int
name|fpe_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how bad is it ? */
end_comment

begin_decl_stmt
name|long
name|fpeflt_
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fortran "common /fpeflt/ flag" */
end_comment

begin_decl_stmt
specifier|static
name|sig_t
name|sigfpe_dfl
init|=
name|SIG_DFL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if we can't fix it ... */
end_comment

begin_comment
comment|/*  * The fortran unit control table  */
end_comment

begin_decl_stmt
specifier|extern
name|unit
name|units
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Fortran message table is in main  */
end_comment

begin_struct
struct|struct
name|msgtbl
block|{
name|char
modifier|*
name|mesg
decl_stmt|;
name|int
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|msgtbl
name|act_fpe
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* VALID ONLY ON VAX !!!  *  * Get the address of the (saved) next operand& update saved PC.  * The major purpose of this is to determine where to store the result.  * There is one case we can't deal with: -(SP) or (SP)+  * since we can't change the size of the stack.  * Let's just hope compilers don't generate that for results.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/*  * Trap& repair floating exceptions so that a program may proceed.  * There is no notion of "correctness" here; just the ability to continue.  *  * The on_fpe() routine first checks the type code to see if the  * exception is repairable. If so, it checks the opcode to see if  * it is one that it knows. If this is true, it then simulates the  * VAX cpu in retrieving operands in order to increment iPC correctly.  * It notes where the result of the operation would have been stored  * and substitutes a previously supplied value.  *  DOES NOT REPAIR ON TAHOE !!!  */
end_comment

begin_function
name|void
name|on_fpe
parameter_list|(
name|signo
parameter_list|,
name|code
parameter_list|,
name|sc
parameter_list|)
name|int
name|signo
decl_stmt|,
name|code
decl_stmt|;
name|struct
name|sigcontext
modifier|*
name|sc
decl_stmt|;
block|{
comment|/* 	 * There must be at least 11 register variables here 	 * so our entry mask will save R12-R2. 	 */
specifier|register
name|long
modifier|*
name|stk
decl_stmt|;
specifier|register
name|long
modifier|*
name|sp
decl_stmt|,
modifier|*
name|rfp
decl_stmt|;
specifier|register
name|struct
name|arglist
modifier|*
name|ap
decl_stmt|;
specifier|register
name|struct
name|frame
modifier|*
name|fp
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|ef
decl_stmt|;
specifier|register
name|struct
name|sigframe
modifier|*
name|sfp
decl_stmt|;
specifier|register
name|long
name|dmy1
decl_stmt|,
name|dmy2
decl_stmt|,
name|dmy3
decl_stmt|,
name|dmy4
decl_stmt|;
name|dmy1
operator|=
name|dmy2
operator|=
name|dmy3
operator|=
name|dmy4
operator|=
literal|0
expr_stmt|;
name|ef
operator|=
name|units
index|[
name|STDERR
index|]
operator|.
name|ufd
expr_stmt|;
comment|/* fortran error stream */
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|FPE_INTOVF_TRAP
case|:
comment|/* integer overflow */
case|case
name|FPE_INTDIV_TRAP
case|:
comment|/* integer divide by zero */
case|case
name|FPE_FLTOVF_TRAP
case|:
comment|/* floating overflow */
case|case
name|FPE_FLTDIV_TRAP
case|:
comment|/* floating divide by zero */
case|case
name|FPE_FLTUND_TRAP
case|:
comment|/* floating underflow */
default|default:
name|cant_fix
label|:
if|if
condition|(
name|sigfpe_dfl
operator|>
operator|(
name|SIG_VAL
operator|)
literal|7
condition|)
comment|/* user specified */
call|(
modifier|*
name|sigfpe_dfl
call|)
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|sc
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|++
name|fpe_count
operator|<=
name|max_messages
condition|)
block|{
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|"trpfpe: %s"
argument_list|,
name|act_fpe
index|[
name|code
operator|-
literal|1
index|]
operator|.
name|mesg
argument_list|)
expr_stmt|;
if|if
condition|(
name|fpe_count
operator|==
name|max_messages
condition|)
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|": No more messages will be printed.\n"
argument_list|)
expr_stmt|;
else|else
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|ef
argument_list|)
expr_stmt|;
block|}
name|fpeflt_
operator|=
operator|-
literal|1
expr_stmt|;
break|break;
block|}
comment|/*  * Find all the registers just in case something better can be done.  */
name|rfp
operator|=
name|myfp
argument_list|()
expr_stmt|;
comment|/* contents of fp register */
name|ap
operator|=
name|argp
argument_list|(
name|rfp
argument_list|)
expr_stmt|;
comment|/* my arglist pointer */
name|fp
operator|=
name|framep
argument_list|(
name|rfp
argument_list|)
expr_stmt|;
comment|/* my frame pointer */
name|ifp
operator|=
name|framep
argument_list|(
operator|*
name|rfp
argument_list|)
expr_stmt|;
comment|/* user's stored in next frame back */
name|iap
operator|=
name|argp
argument_list|(
operator|*
name|rfp
argument_list|)
expr_stmt|;
name|sfp
operator|=
operator|(
expr|struct
name|sigframe
operator|*
operator|)
name|ap
expr_stmt|;
comment|/* sigframe contains at its bottom the 					   signal handler arguments */
name|reg0_1
operator|=
operator|(
expr|struct
name|reg0_1
operator|*
operator|)
operator|&
name|sfp
operator|->
name|r1
expr_stmt|;
name|reg2_12
operator|=
operator|(
expr|struct
name|reg2_12
operator|*
operator|)
operator|(
operator|(
name|char
operator|*
operator|)
name|fp
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|reg2_12
argument_list|)
operator|)
expr_stmt|;
name|ipc
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|&
name|sc
operator|->
name|sc_pc
expr_stmt|;
name|isp
operator|=
operator|(
name|char
operator|*
operator|)
name|sc
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|sigcontext
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_ps
operator|&=
operator|~
operator|(
name|PSL_V
operator||
name|PSL_FU
operator|)
expr_stmt|;
name|fprintf
argument_list|(
name|ef
argument_list|,
literal|"Current PC = %X \n"
argument_list|,
name|sc
operator|->
name|sc_pc
argument_list|)
expr_stmt|;
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|on_fpe
argument_list|)
expr_stmt|;
name|sigdie
argument_list|(
name|signo
argument_list|,
name|code
argument_list|,
name|sc
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|trpfpe_
argument_list|(
argument|count
argument_list|,
argument|rval
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how many to announce */
end_comment

begin_decl_stmt
name|double
modifier|*
name|rval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dummy return value */
end_comment

begin_block
block|{
name|max_messages
operator|=
operator|*
name|count
expr_stmt|;
name|retval
operator|.
name|rv_double
operator|=
operator|*
name|rval
expr_stmt|;
name|sigfpe_dfl
operator|=
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|on_fpe
argument_list|)
expr_stmt|;
name|fpe_count
operator|=
literal|0
expr_stmt|;
block|}
end_block

begin_function
name|long
name|fpecnt_
parameter_list|()
block|{
return|return
operator|(
name|fpe_count
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

end_unit

