begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  		THIS SOFTWARE IS NOT COPYRIGHTED     HP offers the following for use in the public domain.  HP makes no    warranty with regard to the software or it's performance and the    user accepts the software "AS IS" with all faults.     HP DISCLAIMS ANY WARRANTIES, EXPRESS OR IMPLIED, WITH REGARD    TO THIS SOFTWARE INCLUDING BUT NOT LIMITED TO THE WARRANTIES    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Header: remcom.c,v 1.34 91/03/09 12:29:49 glenne Exp $  *  *  Module name: remcom.c $  *  Revision: 1.34 $  *  Date: 91/03/09 12:29:49 $  *  Contributor:     Lake Stevens Instrument Division$  *  *  Description:     low level support for gdb debugger. $  *  *  Considerations:  only works on target hardware $  *  *  Written by:      Glenn Engel $  *  ModuleState:     Experimental $  *  *  NOTES:           See Below $  *  *  Modified for 386 by Jim Kingdon, Cygnus Support.  *  *  To enable debugger support, two things need to happen.  One, a  *  call to set_debug_traps() is necessary in order to allow any breakpoints  *  or error conditions to be properly intercepted and reported to gdb.  *  Two, a breakpoint needs to be generated to begin communication.  This  *  is most easily accomplished by a call to breakpoint().  Breakpoint()  *  simulates a breakpoint by executing a trap #1.  *  *  The external function exceptionHandler() is  *  used to attach a specific handler to a specific 386 vector number.  *  It should use the same privilege level it runs at.  It should  *  install it as an interrupt gate so that interrupts are masked  *  while the handler runs.  *  Also, need to assign exceptionHook and oldExceptionHook.  *  *  Because gdb will sometimes write to the stack area to execute function  *  calls, this program cannot rely on using the supervisor stack so it  *  uses it's own stack area reserved in the int array remcomStack.  *  *************  *  *    The following gdb commands are supported:  *  * command          function                               Return value  *  *    g             return the value of the CPU registers  hex data or ENN  *    G             set the value of the CPU registers     OK or ENN  *  *    mAA..AA,LLLL  Read LLLL bytes at address AA..AA      hex data or ENN  *    MAA..AA,LLLL: Write LLLL bytes at address AA.AA      OK or ENN  *  *    c             Resume at current address              SNN   ( signal NN)  *    cAA..AA       Continue at address AA..AA             SNN  *  *    s             Step one instruction                   SNN  *    sAA..AA       Step one instruction from AA..AA       SNN  *  *    k             kill  *  *    ?             What was the last sigval ?             SNN   (signal NN)  *  * All commands and responses are sent with a packet which includes a  * checksum.  A packet consists of  *  * $<packet info>#<checksum>.  *  * where  *<packet info> ::<characters representing the command or response>  *<checksum>    ::< two hex digits computed as modulo 256 sum of<packetinfo>>  *  * When a packet is received, it is first acknowledged with either '+' or '-'.  * '+' indicates a successful transfer.  '-' indicates a failed transfer.  *  * Example:  *  * Host:                  Reply:  * $m0,10#2a               +$00010203040506070809101112131415#42  *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/************************************************************************  *  * external low-level support routines  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ExceptionHook
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* pointer to function with int parm */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|Function
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* pointer to a function */
end_comment

begin_extern
extern|extern putDebugChar(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* write a single character      */
end_comment

begin_extern
extern|extern getDebugChar(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* read and return a single char */
end_comment

begin_function_decl
specifier|extern
name|Function
name|exceptionHandler
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* assign an exception handler */
end_comment

begin_decl_stmt
specifier|extern
name|ExceptionHook
name|exceptionHook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hook variable for errors/exceptions */
end_comment

begin_comment
comment|/************************************************************************/
end_comment

begin_comment
comment|/* BUFMAX defines the maximum number of characters in inbound/outbound buffers*/
end_comment

begin_comment
comment|/* at least NUMREGBYTES*2 are needed for register packets */
end_comment

begin_define
define|#
directive|define
name|BUFMAX
value|400
end_define

begin_decl_stmt
specifier|static
name|char
name|initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* boolean flag. != 0 means we've been initialized */
end_comment

begin_decl_stmt
name|int
name|remote_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  debug>  0 prints ill-formed commands in valid packets& checksum errors */
end_comment

begin_function_decl
name|void
name|waitabit
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
specifier|const
name|char
name|hexchars
index|[]
init|=
literal|"0123456789abcdef"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of bytes of registers.  */
end_comment

begin_define
define|#
directive|define
name|NUMREGBYTES
value|64
end_define

begin_enum
enum|enum
name|regnames
block|{
name|EAX
block|,
name|ECX
block|,
name|EDX
block|,
name|EBX
block|,
name|ESP
block|,
name|EBP
block|,
name|ESI
block|,
name|EDI
block|,
name|PC
comment|/* also known as eip */
block|,
name|PS
comment|/* also known as eflags */
block|,
name|CS
block|,
name|SS
block|,
name|DS
block|,
name|ES
block|,
name|FS
block|,
name|GS
block|}
enum|;
end_enum

begin_comment
comment|/*  * these should not be static cuz they can be used outside this module  */
end_comment

begin_decl_stmt
name|int
name|registers
index|[
name|NUMREGBYTES
operator|/
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STACKSIZE
value|10000
end_define

begin_decl_stmt
name|int
name|remcomStack
index|[
name|STACKSIZE
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
modifier|*
name|stackPtr
init|=
operator|&
name|remcomStack
index|[
name|STACKSIZE
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * In many cases, the system will want to continue exception processing  * when a continue command is given.  * oldExceptionHook is a function to invoke in this case.  */
end_comment

begin_decl_stmt
specifier|static
name|ExceptionHook
name|oldExceptionHook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************  ASSEMBLY CODE MACROS *************************/
end_comment

begin_comment
comment|/* 									   */
end_comment

begin_function_decl
specifier|extern
name|void
name|return_to_prog
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Restore the program's registers (including the stack pointer, which    means we get the right stack and don't have to worry about popping our    return address and any stack frames and so on) and return.  */
end_comment

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl _return_to_prog");
end_asm

begin_asm
asm|asm("_return_to_prog:");
end_asm

begin_asm
asm|asm("        movw _registers+44, %ss");
end_asm

begin_asm
asm|asm("        movl _registers+16, %esp");
end_asm

begin_asm
asm|asm("        movl _registers+4, %ecx");
end_asm

begin_asm
asm|asm("        movl _registers+8, %edx");
end_asm

begin_asm
asm|asm("        movl _registers+12, %ebx");
end_asm

begin_asm
asm|asm("        movl _registers+20, %ebp");
end_asm

begin_asm
asm|asm("        movl _registers+24, %esi");
end_asm

begin_asm
asm|asm("        movl _registers+28, %edi");
end_asm

begin_asm
asm|asm("        movw _registers+48, %ds");
end_asm

begin_asm
asm|asm("        movw _registers+52, %es");
end_asm

begin_asm
asm|asm("        movw _registers+56, %fs");
end_asm

begin_asm
asm|asm("        movw _registers+60, %gs");
end_asm

begin_asm
asm|asm("        movl _registers+36, %eax");
end_asm

begin_asm
asm|asm("        pushl %eax");
end_asm

begin_comment
comment|/* saved eflags */
end_comment

begin_asm
asm|asm("        movl _registers+40, %eax");
end_asm

begin_asm
asm|asm("        pushl %eax");
end_asm

begin_comment
comment|/* saved cs */
end_comment

begin_asm
asm|asm("        movl _registers+32, %eax");
end_asm

begin_asm
asm|asm("        pushl %eax");
end_asm

begin_comment
comment|/* saved eip */
end_comment

begin_asm
asm|asm("        movl _registers, %eax");
end_asm

begin_comment
comment|/* use iret to restore pc and flags together so    that trace flag works right.  */
end_comment

begin_asm
asm|asm("        iret");
end_asm

begin_define
define|#
directive|define
name|BREAKPOINT
parameter_list|()
value|asm("   int $3");
end_define

begin_comment
comment|/* Put the error code here just in case the user cares.  */
end_comment

begin_decl_stmt
name|int
name|gdb_i386errcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise, the vector number here (since GDB only gets the signal    number through the usual means, and that's not very specific).  */
end_comment

begin_decl_stmt
name|int
name|gdb_i386vector
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GDB stores segment registers in 32-bit words (that's just the way    m-i386v.h is written).  So zero the appropriate areas in registers.  */
end_comment

begin_define
define|#
directive|define
name|SAVE_REGISTERS1
parameter_list|()
define|\
value|asm ("movl %eax, _registers");                                   	  \   asm ("movl %ecx, _registers+4");			  		     \   asm ("movl %edx, _registers+8");			  		     \   asm ("movl %ebx, _registers+12");			  		     \   asm ("movl %ebp, _registers+20");			  		     \   asm ("movl %esi, _registers+24");			  		     \   asm ("movl %edi, _registers+28");			  		     \   asm ("movw $0, %ax");							     \   asm ("movw %ds, _registers+48");			  		     \   asm ("movw %ax, _registers+50");					     \   asm ("movw %es, _registers+52");			  		     \   asm ("movw %ax, _registers+54");					     \   asm ("movw %fs, _registers+56");			  		     \   asm ("movw %ax, _registers+58");					     \   asm ("movw %gs, _registers+60");			  		     \   asm ("movw %ax, _registers+62");
end_define

begin_define
define|#
directive|define
name|SAVE_ERRCODE
parameter_list|()
define|\
value|asm ("popl %ebx");                                  \   asm ("movl %ebx, _gdb_i386errcode");
end_define

begin_define
define|#
directive|define
name|SAVE_REGISTERS2
parameter_list|()
define|\
value|asm ("popl %ebx");
comment|/* old eip */
value|\   asm ("movl %ebx, _registers+32");			  		     \   asm ("popl %ebx");
comment|/* old cs */
value|\   asm ("movl %ebx, _registers+40");			  		     \   asm ("movw %ax, _registers+42");                                           \   asm ("popl %ebx");
comment|/* old eflags */
value|\   asm ("movl %ebx, _registers+36");			 		     \
comment|/* Now that we've done the pops, we can save the stack pointer.");  */
value|\   asm ("movw %ss, _registers+44");					     \   asm ("movw %ax, _registers+46");     	       	       	       	       	     \   asm ("movl %esp, _registers+16");
end_define

begin_comment
comment|/* See if mem_fault_routine is set, if so just IRET to that address.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_FAULT
parameter_list|()
define|\
value|asm ("cmpl $0, _mem_fault_routine");					   \   asm ("jne mem_fault");
end_define

begin_asm
asm|asm (".text");
end_asm

begin_asm
asm|asm ("mem_fault:");
end_asm

begin_comment
comment|/* OK to clobber temp registers; we're just going to end up in set_mem_err.  */
end_comment

begin_comment
comment|/* Pop error code from the stack and save it.  */
end_comment

begin_asm
asm|asm ("     popl %eax");
end_asm

begin_asm
asm|asm ("     movl %eax, _gdb_i386errcode");
end_asm

begin_asm
asm|asm ("     popl %eax");
end_asm

begin_comment
comment|/* eip */
end_comment

begin_comment
comment|/* We don't want to return there, we want to return to the function    pointed to by mem_fault_routine instead.  */
end_comment

begin_asm
asm|asm ("     movl _mem_fault_routine, %eax");
end_asm

begin_asm
asm|asm ("     popl %ecx");
end_asm

begin_comment
comment|/* cs (low 16 bits; junk in hi 16 bits).  */
end_comment

begin_asm
asm|asm ("     popl %edx");
end_asm

begin_comment
comment|/* eflags */
end_comment

begin_comment
comment|/* Remove this stack frame; when we do the iret, we will be going to    the start of a function, so we want the stack to look just like it    would after a "call" instruction.  */
end_comment

begin_asm
asm|asm ("     leave");
end_asm

begin_comment
comment|/* Push the stuff that iret wants.  */
end_comment

begin_asm
asm|asm ("     pushl %edx");
end_asm

begin_comment
comment|/* eflags */
end_comment

begin_asm
asm|asm ("     pushl %ecx");
end_asm

begin_comment
comment|/* cs */
end_comment

begin_asm
asm|asm ("     pushl %eax");
end_asm

begin_comment
comment|/* eip */
end_comment

begin_comment
comment|/* Zero mem_fault_routine.  */
end_comment

begin_asm
asm|asm ("     movl $0, %eax");
end_asm

begin_asm
asm|asm ("     movl %eax, _mem_fault_routine");
end_asm

begin_asm
asm|asm ("iret");
end_asm

begin_define
define|#
directive|define
name|CALL_HOOK
parameter_list|()
value|asm("call _remcomHandler");
end_define

begin_comment
comment|/* This function is called when a i386 exception occurs.  It saves  * all the cpu regs in the _registers array, munges the stack a bit,  * and invokes an exception handler (remcom_handler).  *  * stack on entry:                       stack on exit:  *   old eflags                          vector number  *   old cs (zero-filled to 32 bits)  *   old eip  *  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException3
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException3");
end_asm

begin_asm
asm|asm("__catchException3:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $3");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 1.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException1
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException1");
end_asm

begin_asm
asm|asm("__catchException1:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $1");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 0.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException0
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException0");
end_asm

begin_asm
asm|asm("__catchException0:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $0");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 4.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException4
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException4");
end_asm

begin_asm
asm|asm("__catchException4:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $4");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 5.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException5
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException5");
end_asm

begin_asm
asm|asm("__catchException5:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $5");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 6.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException6
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException6");
end_asm

begin_asm
asm|asm("__catchException6:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $6");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 7.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException7
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException7");
end_asm

begin_asm
asm|asm("__catchException7:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $7");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 8.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException8
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException8");
end_asm

begin_asm
asm|asm("__catchException8:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $8");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 9.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException9
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException9");
end_asm

begin_asm
asm|asm("__catchException9:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $9");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 10.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException10
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException10");
end_asm

begin_asm
asm|asm("__catchException10:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $10");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 12.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException12
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException12");
end_asm

begin_asm
asm|asm("__catchException12:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $12");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 16.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException16
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(".text");
end_asm

begin_asm
asm|asm(".globl __catchException16");
end_asm

begin_asm
asm|asm("__catchException16:");
end_asm

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $16");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For 13, 11, and 14 we have to deal with the CHECK_FAULT stuff.  */
end_comment

begin_comment
comment|/* Same thing for exception 13.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException13
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".text");
end_asm

begin_asm
asm|asm (".globl __catchException13");
end_asm

begin_asm
asm|asm ("__catchException13:");
end_asm

begin_expr_stmt
name|CHECK_FAULT
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $13");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 11.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException11
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".text");
end_asm

begin_asm
asm|asm (".globl __catchException11");
end_asm

begin_asm
asm|asm ("__catchException11:");
end_asm

begin_expr_stmt
name|CHECK_FAULT
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $11");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Same thing for exception 14.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_catchException14
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm (".text");
end_asm

begin_asm
asm|asm (".globl __catchException14");
end_asm

begin_asm
asm|asm ("__catchException14:");
end_asm

begin_expr_stmt
name|CHECK_FAULT
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS1
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_ERRCODE
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SAVE_REGISTERS2
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm ("pushl $14");
end_asm

begin_expr_stmt
name|CALL_HOOK
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * remcomHandler is a front end for handle_exception.  It moves the  * stack pointer into an area reserved for debugger use.  */
end_comment

begin_asm
asm|asm("_remcomHandler:");
end_asm

begin_asm
asm|asm("           popl %eax");
end_asm

begin_comment
comment|/* pop off return address     */
end_comment

begin_asm
asm|asm("           popl %eax");
end_asm

begin_comment
comment|/* get the exception number   */
end_comment

begin_asm
asm|asm("		movl _stackPtr, %esp");
end_asm

begin_comment
comment|/* move to remcom stack area  */
end_comment

begin_asm
asm|asm("		pushl %eax");
end_asm

begin_comment
comment|/* push exception onto stack  */
end_comment

begin_asm
asm|asm("		call  _handle_exception");
end_asm

begin_comment
comment|/* this never returns */
end_comment

begin_function
name|void
name|_returnFromException
parameter_list|()
block|{
name|return_to_prog
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|hex
parameter_list|(
name|ch
parameter_list|)
name|char
name|ch
decl_stmt|;
block|{
if|if
condition|(
operator|(
name|ch
operator|>=
literal|'a'
operator|)
operator|&&
operator|(
name|ch
operator|<=
literal|'f'
operator|)
condition|)
return|return
operator|(
name|ch
operator|-
literal|'a'
operator|+
literal|10
operator|)
return|;
if|if
condition|(
operator|(
name|ch
operator|>=
literal|'0'
operator|)
operator|&&
operator|(
name|ch
operator|<=
literal|'9'
operator|)
condition|)
return|return
operator|(
name|ch
operator|-
literal|'0'
operator|)
return|;
if|if
condition|(
operator|(
name|ch
operator|>=
literal|'A'
operator|)
operator|&&
operator|(
name|ch
operator|<=
literal|'F'
operator|)
condition|)
return|return
operator|(
name|ch
operator|-
literal|'A'
operator|+
literal|10
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* scan for the sequence $<data>#<checksum>     */
end_comment

begin_function
name|void
name|getpacket
parameter_list|(
name|buffer
parameter_list|)
name|char
modifier|*
name|buffer
decl_stmt|;
block|{
name|unsigned
name|char
name|checksum
decl_stmt|;
name|unsigned
name|char
name|xmitcsum
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|count
decl_stmt|;
name|char
name|ch
decl_stmt|;
do|do
block|{
comment|/* wait around for the start character, ignore all other characters */
while|while
condition|(
operator|(
name|ch
operator|=
operator|(
name|getDebugChar
argument_list|()
operator|&
literal|0x7f
operator|)
operator|)
operator|!=
literal|'$'
condition|)
empty_stmt|;
name|checksum
operator|=
literal|0
expr_stmt|;
name|xmitcsum
operator|=
operator|-
literal|1
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
comment|/* now, read until a # or end of buffer is found */
while|while
condition|(
name|count
operator|<
name|BUFMAX
condition|)
block|{
name|ch
operator|=
name|getDebugChar
argument_list|()
operator|&
literal|0x7f
expr_stmt|;
if|if
condition|(
name|ch
operator|==
literal|'#'
condition|)
break|break;
name|checksum
operator|=
name|checksum
operator|+
name|ch
expr_stmt|;
name|buffer
index|[
name|count
index|]
operator|=
name|ch
expr_stmt|;
name|count
operator|=
name|count
operator|+
literal|1
expr_stmt|;
block|}
name|buffer
index|[
name|count
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ch
operator|==
literal|'#'
condition|)
block|{
name|xmitcsum
operator|=
name|hex
argument_list|(
name|getDebugChar
argument_list|()
operator|&
literal|0x7f
argument_list|)
operator|<<
literal|4
expr_stmt|;
name|xmitcsum
operator|+=
name|hex
argument_list|(
name|getDebugChar
argument_list|()
operator|&
literal|0x7f
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|remote_debug
operator|)
operator|&&
operator|(
name|checksum
operator|!=
name|xmitcsum
operator|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"bad checksum.  My count = 0x%x, sent=0x%x. buf=%s\n"
argument_list|,
name|checksum
argument_list|,
name|xmitcsum
argument_list|,
name|buffer
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|checksum
operator|!=
name|xmitcsum
condition|)
name|putDebugChar
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
comment|/* failed checksum */
else|else
block|{
name|putDebugChar
argument_list|(
literal|'+'
argument_list|)
expr_stmt|;
comment|/* successful transfer */
comment|/* if a sequence char is present, reply the sequence ID */
if|if
condition|(
name|buffer
index|[
literal|2
index|]
operator|==
literal|':'
condition|)
block|{
name|putDebugChar
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|putDebugChar
argument_list|(
name|buffer
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
comment|/* remove sequence chars from buffer */
name|count
operator|=
name|strlen
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|3
init|;
name|i
operator|<=
name|count
condition|;
name|i
operator|++
control|)
name|buffer
index|[
name|i
operator|-
literal|3
index|]
operator|=
name|buffer
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
block|}
block|}
do|while
condition|(
name|checksum
operator|!=
name|xmitcsum
condition|)
do|;
block|}
end_function

begin_comment
comment|/* send the packet in buffer.  */
end_comment

begin_function
name|void
name|putpacket
parameter_list|(
name|buffer
parameter_list|)
name|char
modifier|*
name|buffer
decl_stmt|;
block|{
name|unsigned
name|char
name|checksum
decl_stmt|;
name|int
name|count
decl_stmt|;
name|char
name|ch
decl_stmt|;
comment|/*  $<packet info>#<checksum>. */
do|do
block|{
name|putDebugChar
argument_list|(
literal|'$'
argument_list|)
expr_stmt|;
name|checksum
operator|=
literal|0
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ch
operator|=
name|buffer
index|[
name|count
index|]
condition|)
block|{
if|if
condition|(
operator|!
name|putDebugChar
argument_list|(
name|ch
argument_list|)
condition|)
return|return;
name|checksum
operator|+=
name|ch
expr_stmt|;
name|count
operator|+=
literal|1
expr_stmt|;
block|}
name|putDebugChar
argument_list|(
literal|'#'
argument_list|)
expr_stmt|;
name|putDebugChar
argument_list|(
name|hexchars
index|[
name|checksum
operator|>>
literal|4
index|]
argument_list|)
expr_stmt|;
name|putDebugChar
argument_list|(
name|hexchars
index|[
name|checksum
operator|%
literal|16
index|]
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|getDebugChar
argument_list|()
operator|&
literal|0x7f
operator|)
operator|!=
literal|'+'
condition|)
do|;
block|}
end_function

begin_decl_stmt
name|char
name|remcomInBuffer
index|[
name|BUFMAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|remcomOutBuffer
index|[
name|BUFMAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|short
name|error
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|debug_error
parameter_list|(
name|format
parameter_list|,
name|parm
parameter_list|)
name|char
modifier|*
name|format
decl_stmt|;
name|char
modifier|*
name|parm
decl_stmt|;
block|{
if|if
condition|(
name|remote_debug
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|format
argument_list|,
name|parm
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Address of a routine to RTE to if we get a memory fault.  */
end_comment

begin_expr_stmt
specifier|static
name|void
argument_list|(
operator|*
specifier|volatile
name|mem_fault_routine
argument_list|)
argument_list|()
operator|=
name|NULL
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Indicate to caller of mem2hex or hex2mem that there has been an    error.  */
end_comment

begin_decl_stmt
specifier|static
specifier|volatile
name|int
name|mem_err
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|set_mem_err
parameter_list|()
block|{
name|mem_err
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/* These are separate functions so that they are so short and sweet    that the compiler won't save any registers (if there is a fault    to mem_fault, they won't get restored, so there better not be any    saved).  */
end_comment

begin_function
name|int
name|get_char
parameter_list|(
name|addr
parameter_list|)
name|char
modifier|*
name|addr
decl_stmt|;
block|{
return|return
operator|*
name|addr
return|;
block|}
end_function

begin_function
name|void
name|set_char
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
name|char
modifier|*
name|addr
decl_stmt|;
name|int
name|val
decl_stmt|;
block|{
operator|*
name|addr
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/* convert the memory pointed to by mem into hex, placing result in buf */
end_comment

begin_comment
comment|/* return a pointer to the last char put in buf (null) */
end_comment

begin_comment
comment|/* If MAY_FAULT is non-zero, then we should set mem_err in response to    a fault; if zero treat a fault like any other fault in the stub.  */
end_comment

begin_function
name|char
modifier|*
name|mem2hex
parameter_list|(
name|mem
parameter_list|,
name|buf
parameter_list|,
name|count
parameter_list|,
name|may_fault
parameter_list|)
name|char
modifier|*
name|mem
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|may_fault
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|char
name|ch
decl_stmt|;
if|if
condition|(
name|may_fault
condition|)
name|mem_fault_routine
operator|=
name|set_mem_err
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|ch
operator|=
name|get_char
argument_list|(
name|mem
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
name|may_fault
operator|&&
name|mem_err
condition|)
return|return
operator|(
name|buf
operator|)
return|;
operator|*
name|buf
operator|++
operator|=
name|hexchars
index|[
name|ch
operator|>>
literal|4
index|]
expr_stmt|;
operator|*
name|buf
operator|++
operator|=
name|hexchars
index|[
name|ch
operator|%
literal|16
index|]
expr_stmt|;
block|}
operator|*
name|buf
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|may_fault
condition|)
name|mem_fault_routine
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

begin_comment
comment|/* convert the hex array pointed to by buf into binary to be placed in mem */
end_comment

begin_comment
comment|/* return a pointer to the character AFTER the last byte written */
end_comment

begin_function
name|char
modifier|*
name|hex2mem
parameter_list|(
name|buf
parameter_list|,
name|mem
parameter_list|,
name|count
parameter_list|,
name|may_fault
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
name|char
modifier|*
name|mem
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|may_fault
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|char
name|ch
decl_stmt|;
if|if
condition|(
name|may_fault
condition|)
name|mem_fault_routine
operator|=
name|set_mem_err
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
name|ch
operator|=
name|hex
argument_list|(
operator|*
name|buf
operator|++
argument_list|)
operator|<<
literal|4
expr_stmt|;
name|ch
operator|=
name|ch
operator|+
name|hex
argument_list|(
operator|*
name|buf
operator|++
argument_list|)
expr_stmt|;
name|set_char
argument_list|(
name|mem
operator|++
argument_list|,
name|ch
argument_list|)
expr_stmt|;
if|if
condition|(
name|may_fault
operator|&&
name|mem_err
condition|)
return|return
operator|(
name|mem
operator|)
return|;
block|}
if|if
condition|(
name|may_fault
condition|)
name|mem_fault_routine
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|mem
operator|)
return|;
block|}
end_function

begin_comment
comment|/* this function takes the 386 exception vector and attempts to    translate this number into a unix compatible signal value */
end_comment

begin_function
name|int
name|computeSignal
parameter_list|(
name|exceptionVector
parameter_list|)
name|int
name|exceptionVector
decl_stmt|;
block|{
name|int
name|sigval
decl_stmt|;
switch|switch
condition|(
name|exceptionVector
condition|)
block|{
case|case
literal|0
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* divide by zero */
case|case
literal|1
case|:
name|sigval
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* debug exception */
case|case
literal|3
case|:
name|sigval
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* breakpoint */
case|case
literal|4
case|:
name|sigval
operator|=
literal|16
expr_stmt|;
break|break;
comment|/* into instruction (overflow) */
case|case
literal|5
case|:
name|sigval
operator|=
literal|16
expr_stmt|;
break|break;
comment|/* bound instruction */
case|case
literal|6
case|:
name|sigval
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* Invalid opcode */
case|case
literal|7
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* coprocessor not available */
case|case
literal|8
case|:
name|sigval
operator|=
literal|7
expr_stmt|;
break|break;
comment|/* double fault */
case|case
literal|9
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* coprocessor segment overrun */
case|case
literal|10
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* Invalid TSS */
case|case
literal|11
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* Segment not present */
case|case
literal|12
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* stack exception */
case|case
literal|13
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* general protection */
case|case
literal|14
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* page fault */
case|case
literal|16
case|:
name|sigval
operator|=
literal|7
expr_stmt|;
break|break;
comment|/* coprocessor error */
default|default:
name|sigval
operator|=
literal|7
expr_stmt|;
comment|/* "software generated"*/
block|}
return|return
operator|(
name|sigval
operator|)
return|;
block|}
end_function

begin_comment
comment|/**********************************************/
end_comment

begin_comment
comment|/* WHILE WE FIND NICE HEX CHARS, BUILD AN INT */
end_comment

begin_comment
comment|/* RETURN NUMBER OF CHARS PROCESSED           */
end_comment

begin_comment
comment|/**********************************************/
end_comment

begin_function
name|int
name|hexToInt
parameter_list|(
name|char
modifier|*
modifier|*
name|ptr
parameter_list|,
name|int
modifier|*
name|intValue
parameter_list|)
block|{
name|int
name|numChars
init|=
literal|0
decl_stmt|;
name|int
name|hexValue
decl_stmt|;
operator|*
name|intValue
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|*
operator|*
name|ptr
condition|)
block|{
name|hexValue
operator|=
name|hex
argument_list|(
operator|*
operator|*
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|hexValue
operator|>=
literal|0
condition|)
block|{
operator|*
name|intValue
operator|=
operator|(
operator|*
name|intValue
operator|<<
literal|4
operator|)
operator||
name|hexValue
expr_stmt|;
name|numChars
operator|++
expr_stmt|;
block|}
else|else
break|break;
operator|(
operator|*
name|ptr
operator|)
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|numChars
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This function does all command procesing for interfacing to gdb.  */
end_comment

begin_function
name|void
name|handle_exception
parameter_list|(
name|int
name|exceptionVector
parameter_list|)
block|{
name|int
name|sigval
decl_stmt|;
name|int
name|addr
decl_stmt|,
name|length
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|int
name|newPC
decl_stmt|;
name|gdb_i386vector
operator|=
name|exceptionVector
expr_stmt|;
if|if
condition|(
name|remote_debug
condition|)
name|printf
argument_list|(
literal|"vector=%d, sr=0x%x, pc=0x%x\n"
argument_list|,
name|exceptionVector
argument_list|,
name|registers
index|[
name|PS
index|]
argument_list|,
name|registers
index|[
name|PC
index|]
argument_list|)
expr_stmt|;
comment|/* reply to host that an exception has occurred */
name|sigval
operator|=
name|computeSignal
argument_list|(
name|exceptionVector
argument_list|)
expr_stmt|;
name|remcomOutBuffer
index|[
literal|0
index|]
operator|=
literal|'S'
expr_stmt|;
name|remcomOutBuffer
index|[
literal|1
index|]
operator|=
name|hexchars
index|[
name|sigval
operator|>>
literal|4
index|]
expr_stmt|;
name|remcomOutBuffer
index|[
literal|2
index|]
operator|=
name|hexchars
index|[
name|sigval
operator|%
literal|16
index|]
expr_stmt|;
name|remcomOutBuffer
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
name|putpacket
argument_list|(
name|remcomOutBuffer
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
operator|==
literal|1
condition|)
block|{
name|error
operator|=
literal|0
expr_stmt|;
name|remcomOutBuffer
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|getpacket
argument_list|(
name|remcomInBuffer
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|remcomInBuffer
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'?'
case|:
name|remcomOutBuffer
index|[
literal|0
index|]
operator|=
literal|'S'
expr_stmt|;
name|remcomOutBuffer
index|[
literal|1
index|]
operator|=
name|hexchars
index|[
name|sigval
operator|>>
literal|4
index|]
expr_stmt|;
name|remcomOutBuffer
index|[
literal|2
index|]
operator|=
name|hexchars
index|[
name|sigval
operator|%
literal|16
index|]
expr_stmt|;
name|remcomOutBuffer
index|[
literal|3
index|]
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|remote_debug
operator|=
operator|!
operator|(
name|remote_debug
operator|)
expr_stmt|;
comment|/* toggle debug flag */
break|break;
case|case
literal|'g'
case|:
comment|/* return the value of the CPU registers */
name|mem2hex
argument_list|(
operator|(
name|char
operator|*
operator|)
name|registers
argument_list|,
name|remcomOutBuffer
argument_list|,
name|NUMREGBYTES
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'G'
case|:
comment|/* set the value of the CPU registers - return OK */
name|hex2mem
argument_list|(
operator|&
name|remcomInBuffer
index|[
literal|1
index|]
argument_list|,
operator|(
name|char
operator|*
operator|)
name|registers
argument_list|,
name|NUMREGBYTES
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"OK"
argument_list|)
expr_stmt|;
break|break;
comment|/* mAA..AA,LLLL  Read LLLL bytes at address AA..AA */
case|case
literal|'m'
case|:
comment|/* TRY TO READ %x,%x.  IF SUCCEED, SET PTR = 0 */
name|ptr
operator|=
operator|&
name|remcomInBuffer
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|hexToInt
argument_list|(
operator|&
name|ptr
argument_list|,
operator|&
name|addr
argument_list|)
condition|)
if|if
condition|(
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|==
literal|','
condition|)
if|if
condition|(
name|hexToInt
argument_list|(
operator|&
name|ptr
argument_list|,
operator|&
name|length
argument_list|)
condition|)
block|{
name|ptr
operator|=
literal|0
expr_stmt|;
name|mem_err
operator|=
literal|0
expr_stmt|;
name|mem2hex
argument_list|(
operator|(
name|char
operator|*
operator|)
name|addr
argument_list|,
name|remcomOutBuffer
argument_list|,
name|length
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mem_err
condition|)
block|{
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E03"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"memory fault"
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ptr
condition|)
block|{
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E01"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"malformed read memory command: %s"
argument_list|,
name|remcomInBuffer
argument_list|)
expr_stmt|;
block|}
break|break;
comment|/* MAA..AA,LLLL: Write LLLL bytes at address AA.AA return OK */
case|case
literal|'M'
case|:
comment|/* TRY TO READ '%x,%x:'.  IF SUCCEED, SET PTR = 0 */
name|ptr
operator|=
operator|&
name|remcomInBuffer
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|hexToInt
argument_list|(
operator|&
name|ptr
argument_list|,
operator|&
name|addr
argument_list|)
condition|)
if|if
condition|(
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|==
literal|','
condition|)
if|if
condition|(
name|hexToInt
argument_list|(
operator|&
name|ptr
argument_list|,
operator|&
name|length
argument_list|)
condition|)
if|if
condition|(
operator|*
operator|(
name|ptr
operator|++
operator|)
operator|==
literal|':'
condition|)
block|{
name|mem_err
operator|=
literal|0
expr_stmt|;
name|hex2mem
argument_list|(
name|ptr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|addr
argument_list|,
name|length
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|mem_err
condition|)
block|{
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E03"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"memory fault"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"OK"
argument_list|)
expr_stmt|;
block|}
name|ptr
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|ptr
condition|)
block|{
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E02"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"malformed write memory command: %s"
argument_list|,
name|remcomInBuffer
argument_list|)
expr_stmt|;
block|}
break|break;
comment|/* cAA..AA    Continue at address AA..AA(optional) */
comment|/* sAA..AA   Step one instruction from AA..AA(optional) */
case|case
literal|'c'
case|:
case|case
literal|'s'
case|:
comment|/* try to read optional parameter, pc unchanged if no parm */
name|ptr
operator|=
operator|&
name|remcomInBuffer
index|[
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|hexToInt
argument_list|(
operator|&
name|ptr
argument_list|,
operator|&
name|addr
argument_list|)
condition|)
name|registers
index|[
name|PC
index|]
operator|=
name|addr
expr_stmt|;
name|newPC
operator|=
name|registers
index|[
name|PC
index|]
expr_stmt|;
comment|/* clear the trace bit */
name|registers
index|[
name|PS
index|]
operator|&=
literal|0xfffffeff
expr_stmt|;
comment|/* set the trace bit if we're stepping */
if|if
condition|(
name|remcomInBuffer
index|[
literal|0
index|]
operator|==
literal|'s'
condition|)
name|registers
index|[
name|PS
index|]
operator||=
literal|0x100
expr_stmt|;
comment|/*            * If we found a match for the PC AND we are not returning            * as a result of a breakpoint (33),            * trace exception (9), nmi (31), jmp to            * the old exception handler as if this code never ran.            */
if|#
directive|if
literal|0
comment|/* Don't really think we need this, except maybe for protection 	     exceptions.  */
comment|/*                    * invoke the previous handler.                    */
block|if (oldExceptionHook)                       (*oldExceptionHook) (frame->exceptionVector);                   newPC = registers[ PC ];
comment|/* pc may have changed  */
endif|#
directive|endif
comment|/* 0 */
name|_returnFromException
argument_list|()
expr_stmt|;
comment|/* this is a jump */
break|break;
comment|/* kill the program */
case|case
literal|'k'
case|:
comment|/* do nothing */
if|#
directive|if
literal|0
comment|/* Huh? This doesn't look like "nothing". 	   m68k-stub.c and sparc-stub.c don't have it.  */
block|BREAKPOINT();
endif|#
directive|endif
break|break;
block|}
comment|/* switch */
comment|/* reply to the request */
name|putpacket
argument_list|(
name|remcomOutBuffer
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* this function is used to set up exception handlers for tracing and    breakpoints */
end_comment

begin_function
name|void
name|set_debug_traps
parameter_list|()
block|{
specifier|extern
name|void
name|remcomHandler
parameter_list|()
function_decl|;
name|int
name|exception
decl_stmt|;
name|stackPtr
operator|=
operator|&
name|remcomStack
index|[
name|STACKSIZE
operator|/
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
index|]
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|0
argument_list|,
name|_catchException0
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|1
argument_list|,
name|_catchException1
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|3
argument_list|,
name|_catchException3
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|4
argument_list|,
name|_catchException4
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|5
argument_list|,
name|_catchException5
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|6
argument_list|,
name|_catchException6
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|7
argument_list|,
name|_catchException7
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|8
argument_list|,
name|_catchException8
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|9
argument_list|,
name|_catchException9
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|10
argument_list|,
name|_catchException10
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|11
argument_list|,
name|_catchException11
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|12
argument_list|,
name|_catchException12
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|13
argument_list|,
name|_catchException13
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|14
argument_list|,
name|_catchException14
argument_list|)
expr_stmt|;
name|exceptionHandler
argument_list|(
literal|16
argument_list|,
name|_catchException16
argument_list|)
expr_stmt|;
if|if
condition|(
name|exceptionHook
operator|!=
name|remcomHandler
condition|)
block|{
name|oldExceptionHook
operator|=
name|exceptionHook
expr_stmt|;
name|exceptionHook
operator|=
name|remcomHandler
expr_stmt|;
block|}
comment|/* In case GDB is started before us, ack any packets (presumably      "$?#xx") sitting there.  */
name|putDebugChar
argument_list|(
literal|'+'
argument_list|)
expr_stmt|;
name|initialized
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This function will generate a breakpoint exception.  It is used at the    beginning of a program to sync up with a debugger and can be used    otherwise as a quick means to stop program execution and "break" into    the debugger. */
end_comment

begin_function
name|void
name|breakpoint
parameter_list|()
block|{
if|if
condition|(
name|initialized
condition|)
if|#
directive|if
literal|0
then|handle_exception(3);
else|#
directive|else
name|BREAKPOINT
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|waitabit
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|waitlimit
init|=
literal|1000000
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void bogon() {   waitabit(); }
endif|#
directive|endif
end_endif

begin_function
name|void
name|waitabit
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|waitlimit
condition|;
name|i
operator|++
control|)
empty_stmt|;
block|}
end_function

end_unit

