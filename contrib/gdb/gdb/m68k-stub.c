begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  		THIS SOFTWARE IS NOT COPYRIGHTED          HP offers the following for use in the public domain.  HP makes no    warranty with regard to the software or it's performance and the     user accepts the software "AS IS" with all faults.     HP DISCLAIMS ANY WARRANTIES, EXPRESS OR IMPLIED, WITH REGARD    TO THIS SOFTWARE INCLUDING BUT NOT LIMITED TO THE WARRANTIES    OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Header: remcom.c,v 1.34 91/03/09 12:29:49 glenne Exp $                     *  *  Module name: remcom.c $    *  Revision: 1.34 $  *  Date: 91/03/09 12:29:49 $  *  Contributor:     Lake Stevens Instrument Division$  *    *  Description:     low level support for gdb debugger. $  *  *  Considerations:  only works on target hardware $  *  *  Written by:      Glenn Engel $  *  ModuleState:     Experimental $   *  *  NOTES:           See Below $  *   *  To enable debugger support, two things need to happen.  One, a  *  call to set_debug_traps() is necessary in order to allow any breakpoints  *  or error conditions to be properly intercepted and reported to gdb.  *  Two, a breakpoint needs to be generated to begin communication.  This  *  is most easily accomplished by a call to breakpoint().  Breakpoint()  *  simulates a breakpoint by executing a trap #1.  The breakpoint instruction  *  is hardwired to trap #1 because not to do so is a compatibility problem--  *  there either should be a standard breakpoint instruction, or the protocol  *  should be extended to provide some means to communicate which breakpoint  *  instruction is in use (or have the stub insert the breakpoint).  *    *  Some explanation is probably necessary to explain how exceptions are  *  handled.  When an exception is encountered the 68000 pushes the current  *  program counter and status register onto the supervisor stack and then  *  transfers execution to a location specified in it's vector table.  *  The handlers for the exception vectors are hardwired to jmp to an address  *  given by the relation:  (exception - 256) * 6.  These are decending   *  addresses starting from -6, -12, -18, ...  By allowing 6 bytes for  *  each entry, a jsr, jmp, bsr, ... can be used to enter the exception   *  handler.  Using a jsr to handle an exception has an added benefit of  *  allowing a single handler to service several exceptions and use the  *  return address as the key differentiation.  The vector number can be  *  computed from the return address by [ exception = (addr + 1530) / 6 ].  *  The sole purpose of the routine _catchException is to compute the  *  exception number and push it on the stack in place of the return address.  *  The external function exceptionHandler() is  *  used to attach a specific handler to a specific m68k exception.  *  For 68020 machines, the ability to have a return address around just  *  so the vector can be determined is not necessary because the '020 pushes an  *  extra word onto the stack containing the vector offset  *   *  Because gdb will sometimes write to the stack area to execute function  *  calls, this program cannot rely on using the supervisor stack so it  *  uses it's own stack area reserved in the int array remcomStack.    *   *************  *  *    The following gdb commands are supported:  *   * command          function                               Return value  *   *    g             return the value of the CPU registers  hex data or ENN  *    G             set the value of the CPU registers     OK or ENN  *   *    mAA..AA,LLLL  Read LLLL bytes at address AA..AA      hex data or ENN  *    MAA..AA,LLLL: Write LLLL bytes at address AA.AA      OK or ENN  *   *    c             Resume at current address              SNN   ( signal NN)  *    cAA..AA       Continue at address AA..AA             SNN  *   *    s             Step one instruction                   SNN  *    sAA..AA       Step one instruction from AA..AA       SNN  *   *    k             kill  *  *    ?             What was the last sigval ?             SNN   (signal NN)  *   * All commands and responses are sent with a packet which includes a   * checksum.  A packet consists of   *   * $<packet info>#<checksum>.  *   * where  *<packet info> ::<characters representing the command or response>  *<checksum>    ::< two hex digits computed as modulo 256 sum of<packetinfo>>  *   * When a packet is received, it is first acknowledged with either '+' or '-'.  * '+' indicates a successful transfer.  '-' indicates a failed transfer.  *   * Example:  *   * Host:                  Reply:  * $m0,10#2a               +$00010203040506070809101112131415#42  *   ****************************************************************************/
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

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/************************************************************************  *  * external low-level support routines   */
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
comment|/************************/
end_comment

begin_comment
comment|/* FORWARD DECLARATIONS */
end_comment

begin_comment
comment|/************************/
end_comment

begin_function_decl
specifier|static
name|void
name|initializeRemcomErrorFrame
parameter_list|()
function_decl|;
end_function_decl

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
comment|/* there are 180 bytes of registers on a 68020 w/68881      */
end_comment

begin_comment
comment|/* many of the fpa registers are 12 byte (96 bit) registers */
end_comment

begin_define
define|#
directive|define
name|NUMREGBYTES
value|180
end_define

begin_enum
enum|enum
name|regnames
block|{
name|D0
block|,
name|D1
block|,
name|D2
block|,
name|D3
block|,
name|D4
block|,
name|D5
block|,
name|D6
block|,
name|D7
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A4
block|,
name|A5
block|,
name|A6
block|,
name|A7
block|,
name|PS
block|,
name|PC
block|,
name|FP0
block|,
name|FP1
block|,
name|FP2
block|,
name|FP3
block|,
name|FP4
block|,
name|FP5
block|,
name|FP6
block|,
name|FP7
block|,
name|FPCONTROL
block|,
name|FPSTATUS
block|,
name|FPIADDR
block|}
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* We keep a whole frame cache here.  "Why?", I hear you cry, "doesn't    GDB handle that sort of thing?"  Well, yes, I believe the only    reason for this cache is to save and restore floating point state    (fsave/frestore).  A cleaner way to do this would be to make the  fsave data part of the registers which GDB deals with like any    other registers.  This should not be a performance problem if the    ability to read individual registers is added to the protocol.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|FrameStruct
block|{
name|struct
name|FrameStruct
modifier|*
name|previous
decl_stmt|;
name|int
name|exceptionPC
decl_stmt|;
comment|/* pc value when this frame created */
name|int
name|exceptionVector
decl_stmt|;
comment|/* cpu vector causing exception     */
name|short
name|frameSize
decl_stmt|;
comment|/* size of cpu frame in words       */
name|short
name|sr
decl_stmt|;
comment|/* for 68000, this not always sr    */
name|int
name|pc
decl_stmt|;
name|short
name|format
decl_stmt|;
name|int
name|fsaveHeader
decl_stmt|;
name|int
name|morejunk
index|[
literal|0
index|]
decl_stmt|;
comment|/* exception frame, fp save... */
block|}
name|Frame
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FRAMESIZE
value|500
end_define

begin_decl_stmt
name|int
name|gdbFrameStack
index|[
name|FRAMESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Frame
modifier|*
name|lastFrame
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
name|int
name|superStack
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
comment|/*  * In many cases, the system will want to continue exception processing  * when a continue command is given.    * oldExceptionHook is a function to invoke in this case.  */
end_comment

begin_decl_stmt
specifier|static
name|ExceptionHook
name|oldExceptionHook
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|mc68020
end_ifdef

begin_comment
comment|/* the size of the exception stack on the 68020 varies with the type of  * exception.  The following table is the number of WORDS used  * for each exception format.  */
end_comment

begin_decl_stmt
specifier|const
name|short
name|exceptionSize
index|[]
init|=
block|{
literal|4
block|,
literal|4
block|,
literal|6
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|29
block|,
literal|10
block|,
literal|16
block|,
literal|46
block|,
literal|12
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|mc68332
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|short
name|exceptionSize
index|[]
init|=
block|{
literal|4
block|,
literal|4
block|,
literal|6
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|,
literal|16
block|,
literal|4
block|,
literal|4
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************* jump buffer used for setjmp/longjmp **************************/
end_comment

begin_decl_stmt
name|jmp_buf
name|remcomEnv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/***************************  ASSEMBLY CODE MACROS *************************/
end_comment

begin_comment
comment|/* 									   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__HAVE_68881__
end_ifdef

begin_comment
comment|/* do an fsave, then remember the address to begin a restore from */
end_comment

begin_define
define|#
directive|define
name|SAVE_FP_REGS
parameter_list|()
value|asm(" fsave   a0@-");		\ 			  asm(" fmovemx fp0-fp7,_registers+72");        \ 			  asm(" fmoveml fpcr/fpsr/fpi,_registers+168");
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_REGS
parameter_list|()
define|\
value|asm("                                                \n\     fmoveml  _registers+168,fpcr/fpsr/fpi            \n\     fmovemx  _registers+72,fp0-fp7                   \n\     cmpl     #-1,a0@     |  skip frestore flag set ? \n\     beq      skip_frestore                           \n\     frestore a0@+                                    \n\ skip_frestore:                                       \n\ ");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SAVE_FP_REGS
parameter_list|()
end_define

begin_define
define|#
directive|define
name|RESTORE_FP_REGS
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HAVE_68881__ */
end_comment

begin_function_decl
name|void
name|return_to_super
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|return_to_user
parameter_list|()
function_decl|;
end_function_decl

begin_asm
asm|asm(" .text .globl _return_to_super _return_to_super:         movel   _registers+60,sp /* get new stack pointer */                 movel   _lastFrame,a0   /* get last frame info  */                       bra     return_to_any  .globl _return_to_user _return_to_user:         movel   _registers+60,a0 /* get usp */                                   movel   a0,usp           /* set usp */				         movel   _superStack,sp  /* get original stack pointer */          return_to_any:         movel   _lastFrame,a0   /* get last frame info  */                       movel   a0@+,_lastFrame /* link in previous frame     */                 addql   #8,a0           /* skip over pc, vector#*/                       movew   a0@+,d0         /* get # of words in cpu frame */                addw    d0,a0           /* point to end of data        */                addw    d0,a0           /* point to end of data        */                movel   a0,a1                                                    #                                                                        # copy the stack frame                                                           subql   #1,d0                                                    copyUserLoop:                                                                        movew   a1@-,sp@-                                                        dbf     d0,copyUserLoop                                              ");
end_asm

begin_macro
name|RESTORE_FP_REGS
argument_list|()
end_macro

begin_asm
asm|asm("   moveml  _registers,d0-d7/a0-a6");
end_asm

begin_asm
asm|asm("   rte");
end_asm

begin_comment
comment|/* pop and go! */
end_comment

begin_define
define|#
directive|define
name|DISABLE_INTERRUPTS
parameter_list|()
value|asm("         oriw   #0x0700,sr");
end_define

begin_define
define|#
directive|define
name|BREAKPOINT
parameter_list|()
value|asm("   trap #1");
end_define

begin_comment
comment|/* this function is called immediately when a level 7 interrupt occurs */
end_comment

begin_comment
comment|/* if the previous interrupt level was 7 then we're already servicing  */
end_comment

begin_comment
comment|/* this interrupt and an rte is in order to return to the debugger.    */
end_comment

begin_comment
comment|/* For the 68000, the offset for sr is 6 due to the jsr return address */
end_comment

begin_asm
asm|asm(" .text .globl __debug_level7 __debug_level7: 	movew   d0,sp@-");
end_asm

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68332
argument_list|)
end_if

begin_asm
asm|asm("	movew   sp@(2),d0");
end_asm

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm("	movew   sp@(6),d0");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|asm("	andiw   #0x700,d0 	cmpiw   #0x700,d0 	beq     _already7         movew   sp@+,d0	         bra     __catchException _already7: 	movew   sp@+,d0");
end_asm

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|mc68332
argument_list|)
end_if

begin_asm
asm|asm("	lea     sp@(4),sp");
end_asm

begin_comment
comment|/* pull off 68000 return address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|asm("	rte");
end_asm

begin_function_decl
specifier|extern
name|void
name|_catchException
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68332
argument_list|)
end_if

begin_comment
comment|/* This function is called when a 68020 exception occurs.  It saves  * all the cpu and fpcp regs in the _registers array, creates a frame on a  * linked list of frames which has the cpu and fpcp stack frames needed  * to properly restore the context of these processors, and invokes  * an exception handler (remcom_handler).  *  * stack on entry:                       stack on exit:  *   N bytes of junk                     exception # MSWord  *   Exception Format Word               exception # MSWord  *   Program counter LSWord                *   Program counter MSWord               *   Status Register                      *                                         *                                         */
end_comment

begin_asm
asm|asm("  .text .globl __catchException __catchException:");
end_asm

begin_expr_stmt
name|DISABLE_INTERRUPTS
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm("         moveml  d0-d7/a0-a6,_registers /* save registers        */ 	movel	_lastFrame,a0	/* last frame pointer */ ");
end_asm

begin_expr_stmt
name|SAVE_FP_REGS
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm(" 	lea     _registers,a5   /* get address of registers     */         movew   sp@,d1          /* get status register          */         movew   d1,a5@(66)      /* save sr		 	*/	 	movel   sp@(2),a4       /* save pc in a4 for later use  */         movel   a4,a5@(68)      /* save pc in _regisers[]      	*/  # # figure out how many bytes in the stack frame 	movew   sp@(6),d0	/* get '020 exception format	*/         movew   d0,d2           /* make a copy of format word   */         andiw   #0xf000,d0      /* mask off format type         */         rolw    #5,d0           /* rotate into the low byte *2  */         lea     _exceptionSize,a1            addw    d0,a1           /* index into the table         */ 	movew   a1@,d0          /* get number of words in frame */         movew   d0,d3           /* save it                      */         subw    d0,a0		/* adjust save pointer          */         subw    d0,a0		/* adjust save pointer(bytes)   */ 	movel   a0,a1           /* copy save pointer            */ 	subql   #1,d0           /* predecrement loop counter    */ # # copy the frame saveFrameLoop: 	movew  	sp@+,a1@+ 	dbf     d0,saveFrameLoop # # now that the stack has been clenaed, # save the a7 in use at time of exception         movel   sp,_superStack  /* save supervisor sp           */         andiw   #0x2000,d1      /* were we in supervisor mode ? */         beq     userMode                movel   a7,a5@(60)      /* save a7                  */         bra     a7saveDone userMode:   	movel   usp,a1    	         movel   a1,a5@(60)      /* save user stack pointer	*/ a7saveDone:  # # save size of frame         movew   d3,a0@-  # # compute exception number 	andl    #0xfff,d2   	/* mask off vector offset	*/ 	lsrw    #2,d2   	/* divide by 4 to get vect num	*/         movel   d2,a0@-         /* save it                      */ # # save pc causing exception         movel   a4,a0@- # # save old frame link and set the new value 	movel	_lastFrame,a1	/* last frame pointer */ 	movel   a1,a0@-		/* save pointer to prev frame	*/         movel   a0,_lastFrame          movel   d2,sp@-		/* push exception num           */ 	movel   _exceptionHook,a0  /* get address of handler */         jbsr    a0@             /* and call it */         clrl    sp@             /* replace exception num parm with frame ptr */         jbsr     __returnFromException   /* jbsr, but never returns */ ");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* mc68000 */
end_comment

begin_comment
comment|/* This function is called when an exception occurs.  It translates the  * return address found on the stack into an exception vector # which  * is then handled by either handle_exception or a system handler.  * _catchException provides a front end for both.    *  * stack on entry:                       stack on exit:  *   Program counter MSWord              exception # MSWord   *   Program counter LSWord              exception # MSWord  *   Status Register                       *   Return Address  MSWord                *   Return Address  LSWord               */
end_comment

begin_asm
asm|asm(" .text .globl __catchException __catchException:");
end_asm

begin_expr_stmt
name|DISABLE_INTERRUPTS
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm("         moveml d0-d7/a0-a6,_registers  /* save registers               */ 	movel	_lastFrame,a0	/* last frame pointer */ ");
end_asm

begin_expr_stmt
name|SAVE_FP_REGS
argument_list|()
expr_stmt|;
end_expr_stmt

begin_asm
asm|asm("         lea     _registers,a5   /* get address of registers     */         movel   sp@+,d2         /* pop return address           */ 	addl 	#1530,d2        /* convert return addr to 	*/ 	divs 	#6,d2   	/*  exception number		*/ 	extl    d2             moveql  #3,d3           /* assume a three word frame     */          cmpiw   #3,d2           /* bus error or address error ? */         bgt     normal          /* if>3 then normal error      */         movel   sp@+,a0@-       /* copy error info to frame buff*/         movel   sp@+,a0@-       /* these are never used         */         moveql  #7,d3           /* this is a 7 word frame       */       normal:    	movew   sp@+,d1         /* pop status register          */         movel   sp@+,a4         /* pop program counter          */         movew   d1,a5@(66)      /* save sr		 	*/	         movel   a4,a5@(68)      /* save pc in _regisers[]      	*/         movel   a4,a0@-         /* copy pc to frame buffer      */ 	movew   d1,a0@-         /* copy sr to frame buffer      */          movel   sp,_superStack  /* save supervisor sp          */          andiw   #0x2000,d1      /* were we in supervisor mode ? */         beq     userMode                movel   a7,a5@(60)      /* save a7                  */         bra     saveDone              userMode:         movel   usp,a1    	/* save user stack pointer 	*/         movel   a1,a5@(60)      /* save user stack pointer	*/ saveDone:          movew   d3,a0@-         /* push frame size in words     */         movel   d2,a0@-         /* push vector number           */         movel   a4,a0@-         /* push exception pc            */  # # save old frame link and set the new value 	movel	_lastFrame,a1	/* last frame pointer */ 	movel   a1,a0@-		/* save pointer to prev frame	*/         movel   a0,_lastFrame          movel   d2,sp@-		/* push exception num           */ 	movel   _exceptionHook,a0  /* get address of handler */         jbsr    a0@             /* and call it */         clrl    sp@             /* replace exception num parm with frame ptr */         jbsr     __returnFromException   /* jbsr, but never returns */ ");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * remcomHandler is a front end for handle_exception.  It moves the  * stack pointer into an area reserved for debugger use in case the  * breakpoint happened in supervisor mode.  */
end_comment

begin_asm
asm|asm("_remcomHandler:");
end_asm

begin_asm
asm|asm("           addl    #4,sp");
end_asm

begin_comment
comment|/* pop off return address     */
end_comment

begin_asm
asm|asm("           movel   sp@+,d0");
end_asm

begin_comment
comment|/* get the exception number   */
end_comment

begin_asm
asm|asm("		movel   _stackPtr,sp");
end_asm

begin_comment
comment|/* move to remcom stack area  */
end_comment

begin_asm
asm|asm("		movel   d0,sp@-");
end_asm

begin_comment
comment|/* push exception onto stack  */
end_comment

begin_asm
asm|asm("		jbsr    _handle_exception");
end_asm

begin_comment
comment|/* this never returns */
end_comment

begin_asm
asm|asm("           rts");
end_asm

begin_comment
comment|/* return */
end_comment

begin_function
name|void
name|_returnFromException
parameter_list|(
name|Frame
modifier|*
name|frame
parameter_list|)
block|{
comment|/* if no passed in frame, use the last one */
if|if
condition|(
operator|!
name|frame
condition|)
block|{
name|frame
operator|=
name|lastFrame
expr_stmt|;
name|frame
operator|->
name|frameSize
operator|=
literal|4
expr_stmt|;
name|frame
operator|->
name|format
operator|=
literal|0
expr_stmt|;
name|frame
operator|->
name|fsaveHeader
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* restore regs, but we dont have fsave info*/
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|mc68020
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|mc68332
argument_list|)
comment|/* a 68000 cannot use the internal info pushed onto a bus error      * or address error frame when doing an RTE so don't put this info      * onto the stack or the stack will creep every time this happens.      */
name|frame
operator|->
name|frameSize
operator|=
literal|3
expr_stmt|;
endif|#
directive|endif
comment|/* throw away any frames in the list after this frame */
name|lastFrame
operator|=
name|frame
expr_stmt|;
name|frame
operator|->
name|sr
operator|=
name|registers
index|[
operator|(
name|int
operator|)
name|PS
index|]
expr_stmt|;
name|frame
operator|->
name|pc
operator|=
name|registers
index|[
operator|(
name|int
operator|)
name|PC
index|]
expr_stmt|;
if|if
condition|(
name|registers
index|[
operator|(
name|int
operator|)
name|PS
index|]
operator|&
literal|0x2000
condition|)
block|{
comment|/* return to supervisor mode... */
name|return_to_super
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|/* return to user mode */
name|return_to_user
argument_list|()
expr_stmt|;
block|}
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
comment|/* send the packet in buffer.  The host get's one chance to read it.      This routine does not wait for a positive acknowledge.  */
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
literal|1
operator|==
literal|0
condition|)
do|;
comment|/* (getDebugChar() != '+'); */
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
comment|/* convert the memory pointed to by mem into hex, placing result in buf */
end_comment

begin_comment
comment|/* return a pointer to the last char put in buf (null) */
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
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|char
name|ch
decl_stmt|;
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
operator|*
name|mem
operator|++
expr_stmt|;
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
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|char
name|ch
decl_stmt|;
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
operator|*
name|mem
operator|++
operator|=
name|ch
expr_stmt|;
block|}
return|return
operator|(
name|mem
operator|)
return|;
block|}
end_function

begin_comment
comment|/* a bus error has occurred, perform a longjmp    to return execution and allow handling of the error */
end_comment

begin_function
name|void
name|handle_buserror
parameter_list|()
block|{
name|longjmp
argument_list|(
name|remcomEnv
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* this function takes the 68000 exception number and attempts to     translate this number into a unix compatible signal value */
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
literal|2
case|:
name|sigval
operator|=
literal|10
expr_stmt|;
break|break;
comment|/* bus error           */
case|case
literal|3
case|:
name|sigval
operator|=
literal|10
expr_stmt|;
break|break;
comment|/* address error       */
case|case
literal|4
case|:
name|sigval
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* illegal instruction */
case|case
literal|5
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* zero divide         */
case|case
literal|6
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* chk instruction     */
case|case
literal|7
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* trapv instruction   */
case|case
literal|8
case|:
name|sigval
operator|=
literal|11
expr_stmt|;
break|break;
comment|/* privilege violation */
case|case
literal|9
case|:
name|sigval
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* trace trap          */
case|case
literal|10
case|:
name|sigval
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* line 1010 emulator  */
case|case
literal|11
case|:
name|sigval
operator|=
literal|4
expr_stmt|;
break|break;
comment|/* line 1111 emulator  */
comment|/* Coprocessor protocol violation.  Using a standard MMU or FPU 	 this cannot be triggered by software.  Call it a SIGBUS.  */
case|case
literal|13
case|:
name|sigval
operator|=
literal|10
expr_stmt|;
break|break;
case|case
literal|31
case|:
name|sigval
operator|=
literal|2
expr_stmt|;
break|break;
comment|/* interrupt           */
case|case
literal|33
case|:
name|sigval
operator|=
literal|5
expr_stmt|;
break|break;
comment|/* breakpoint          */
comment|/* This is a trap #8 instruction.  Apparently it is someone's software 	 convention for some sort of SIGFPE condition.  Whose?  How many 	 people are being screwed by having this code the way it is? 	 Is there a clean solution?  */
case|case
literal|40
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* floating point err  */
case|case
literal|48
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* floating point err  */
case|case
literal|49
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* floating point err  */
case|case
literal|50
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* zero divide         */
case|case
literal|51
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* underflow           */
case|case
literal|52
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* operand error       */
case|case
literal|53
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* overflow            */
case|case
literal|54
case|:
name|sigval
operator|=
literal|8
expr_stmt|;
break|break;
comment|/* NAN                 */
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
name|Frame
modifier|*
name|frame
decl_stmt|;
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
if|if
condition|(
name|setjmp
argument_list|(
name|remcomEnv
argument_list|)
operator|==
literal|0
condition|)
block|{
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|handle_buserror
argument_list|)
expr_stmt|;
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
argument_list|)
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
block|}
else|else
block|{
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E03"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"bus error"
argument_list|)
expr_stmt|;
block|}
comment|/* restore handler for bus error */
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
break|break;
comment|/* MAA..AA,LLLL: Write LLLL bytes at address AA.AA return OK */
case|case
literal|'M'
case|:
if|if
condition|(
name|setjmp
argument_list|(
name|remcomEnv
argument_list|)
operator|==
literal|0
condition|)
block|{
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|handle_buserror
argument_list|)
expr_stmt|;
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
argument_list|)
expr_stmt|;
name|ptr
operator|=
literal|0
expr_stmt|;
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"OK"
argument_list|)
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
block|}
else|else
block|{
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|remcomOutBuffer
argument_list|,
literal|"E03"
argument_list|)
expr_stmt|;
name|debug_error
argument_list|(
literal|"bus error"
argument_list|)
expr_stmt|;
block|}
comment|/* restore handler for bus error */
name|exceptionHandler
argument_list|(
literal|2
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
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
literal|0x7fff
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
literal|0x8000
expr_stmt|;
comment|/*            * look for newPC in the linked list of exception frames.            * if it is found, use the old frame it.  otherwise,            * fake up a dummy frame in returnFromException().            */
if|if
condition|(
name|remote_debug
condition|)
name|printf
argument_list|(
literal|"new pc = 0x%x\n"
argument_list|,
name|newPC
argument_list|)
expr_stmt|;
name|frame
operator|=
name|lastFrame
expr_stmt|;
while|while
condition|(
name|frame
condition|)
block|{
if|if
condition|(
name|remote_debug
condition|)
name|printf
argument_list|(
literal|"frame at 0x%x has pc=0x%x, except#=%d\n"
argument_list|,
name|frame
argument_list|,
name|frame
operator|->
name|exceptionPC
argument_list|,
name|frame
operator|->
name|exceptionVector
argument_list|)
expr_stmt|;
if|if
condition|(
name|frame
operator|->
name|exceptionPC
operator|==
name|newPC
condition|)
break|break;
comment|/* bingo! a match */
comment|/*                * for a breakpoint instruction, the saved pc may                * be off by two due to re-executing the instruction                * replaced by the trap instruction.  Check for this.                */
if|if
condition|(
operator|(
name|frame
operator|->
name|exceptionVector
operator|==
literal|33
operator|)
operator|&&
operator|(
name|frame
operator|->
name|exceptionPC
operator|==
operator|(
name|newPC
operator|+
literal|2
operator|)
operator|)
condition|)
break|break;
if|if
condition|(
name|frame
operator|==
name|frame
operator|->
name|previous
condition|)
block|{
name|frame
operator|=
literal|0
expr_stmt|;
comment|/* no match found */
break|break;
block|}
name|frame
operator|=
name|frame
operator|->
name|previous
expr_stmt|;
block|}
comment|/*            * If we found a match for the PC AND we are not returning            * as a result of a breakpoint (33),            * trace exception (9), nmi (31), jmp to            * the old exception handler as if this code never ran.            */
if|if
condition|(
name|frame
condition|)
block|{
if|if
condition|(
operator|(
name|frame
operator|->
name|exceptionVector
operator|!=
literal|9
operator|)
operator|&&
operator|(
name|frame
operator|->
name|exceptionVector
operator|!=
literal|31
operator|)
operator|&&
operator|(
name|frame
operator|->
name|exceptionVector
operator|!=
literal|33
operator|)
condition|)
block|{
comment|/*                    * invoke the previous handler.                    */
if|if
condition|(
name|oldExceptionHook
condition|)
call|(
modifier|*
name|oldExceptionHook
call|)
argument_list|(
name|frame
operator|->
name|exceptionVector
argument_list|)
expr_stmt|;
name|newPC
operator|=
name|registers
index|[
name|PC
index|]
expr_stmt|;
comment|/* pc may have changed  */
if|if
condition|(
name|newPC
operator|!=
name|frame
operator|->
name|exceptionPC
condition|)
block|{
if|if
condition|(
name|remote_debug
condition|)
name|printf
argument_list|(
literal|"frame at 0x%x has pc=0x%x, except#=%d\n"
argument_list|,
name|frame
argument_list|,
name|frame
operator|->
name|exceptionPC
argument_list|,
name|frame
operator|->
name|exceptionVector
argument_list|)
expr_stmt|;
comment|/* re-use the last frame, we're skipping it (longjump?)*/
name|frame
operator|=
operator|(
name|Frame
operator|*
operator|)
literal|0
expr_stmt|;
name|_returnFromException
argument_list|(
name|frame
argument_list|)
expr_stmt|;
comment|/* this is a jump */
block|}
block|}
block|}
comment|/* if we couldn't find a frame, create one */
if|if
condition|(
name|frame
operator|==
literal|0
condition|)
block|{
name|frame
operator|=
name|lastFrame
operator|-
literal|1
expr_stmt|;
comment|/* by using a bunch of print commands with breakpoints,     	         it's possible for the frame stack to creep down.  If it creeps 		 too far, give up and reset it to the top.  Normal use should     	         not see this happen.     	      */
if|if
condition|(
call|(
name|unsigned
name|int
call|)
argument_list|(
name|frame
operator|-
literal|2
argument_list|)
operator|<
operator|(
name|unsigned
name|int
operator|)
operator|&
name|gdbFrameStack
condition|)
block|{
name|initializeRemcomErrorFrame
argument_list|()
expr_stmt|;
name|frame
operator|=
name|lastFrame
expr_stmt|;
block|}
name|frame
operator|->
name|previous
operator|=
name|lastFrame
expr_stmt|;
name|lastFrame
operator|=
name|frame
expr_stmt|;
name|frame
operator|=
literal|0
expr_stmt|;
comment|/* null so _return... will properly initialize it */
block|}
name|_returnFromException
argument_list|(
name|frame
argument_list|)
expr_stmt|;
comment|/* this is a jump */
break|break;
comment|/* kill the program */
case|case
literal|'k'
case|:
comment|/* do nothing */
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

begin_function
name|void
name|initializeRemcomErrorFrame
parameter_list|()
block|{
name|lastFrame
operator|=
operator|(
operator|(
name|Frame
operator|*
operator|)
operator|&
name|gdbFrameStack
index|[
name|FRAMESIZE
operator|-
literal|1
index|]
operator|)
operator|-
literal|1
expr_stmt|;
name|lastFrame
operator|->
name|previous
operator|=
name|lastFrame
expr_stmt|;
block|}
end_function

begin_comment
comment|/* this function is used to set up exception handlers for tracing and     breakpoints */
end_comment

begin_function
name|void
name|set_debug_traps
parameter_list|()
block|{
specifier|extern
name|void
name|_debug_level7
parameter_list|()
function_decl|;
specifier|extern
name|void
name|remcomHandler
parameter_list|()
function_decl|;
name|int
name|exception
decl_stmt|;
name|initializeRemcomErrorFrame
argument_list|()
expr_stmt|;
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
for|for
control|(
name|exception
operator|=
literal|2
init|;
name|exception
operator|<=
literal|23
condition|;
name|exception
operator|++
control|)
name|exceptionHandler
argument_list|(
name|exception
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
comment|/* level 7 interrupt              */
name|exceptionHandler
argument_list|(
literal|31
argument_list|,
name|_debug_level7
argument_list|)
expr_stmt|;
comment|/* breakpoint exception (trap #1) */
name|exceptionHandler
argument_list|(
literal|33
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
comment|/* This is a trap #8 instruction.  Apparently it is someone's software      convention for some sort of SIGFPE condition.  Whose?  How many      people are being screwed by having this code the way it is?      Is there a clean solution?  */
name|exceptionHandler
argument_list|(
literal|40
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
comment|/* 48 to 54 are floating point coprocessor errors */
for|for
control|(
name|exception
operator|=
literal|48
init|;
name|exception
operator|<=
literal|54
condition|;
name|exception
operator|++
control|)
name|exceptionHandler
argument_list|(
name|exception
argument_list|,
name|_catchException
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldExceptionHook
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
name|BREAKPOINT
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

