begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C code startup routine.    Copyright (C) 1985 Richard M. Stallman  This program is distributed in the hope that it will be useful, but without any warranty.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.     Permission is granted to anyone to distribute verbatim copies    of this program's source code as received, in any medium, provided that    the copyright notice, the nonwarraty notice above    and this permission notice are preserved,    and that the distributor grants the recipient all rights    for further redistribution as permitted by this notice,    and informs him of these rights.     Permission is granted to distribute modified versions of this    program's source code, or of portions of it, under the above    conditions, plus the conditions that all changed files carry    prominent notices stating who last changed them and that the    derived material, including anything packaged together with it and    conceptually functioning as a modification of it rather than an    application of it, is in its entirety subject to a permission    notice identical to this one.     Permission is granted to distribute this program (verbatim or    as modified) in compiled or executable form, provided verbatim    redistribution is permitted as stated above for source code, and     A.  it is accompanied by the corresponding machine-readable       source code, under the above conditions, or     B.  it is accompanied by a written offer, with no time limit,       to distribute the corresponding machine-readable source code,       under the above conditions, to any one, in return for reimbursement       of the cost of distribution.   Verbatim redistribution of the       written offer must be permitted.  Or,     C.  it is distributed by someone who received only the       compiled or executable form, and is accompanied by a copy of the       written offer of source code which he received along with it.     Permission is granted to distribute this program (verbatim or as modified)    in executable form as part of a larger system provided that the source    code for this program, including any modifications used,    is also distributed or offered as stated in the preceding paragraph.  In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
end_comment

begin_comment
comment|/* The standard Vax 4.2 Unix crt0.c cannot be used for Emacs    because it makes `envron' an initialized variable.    It is easiest to have a special crt0.c on all machines    though I don't know whether other machines actually need it.  */
end_comment

begin_comment
comment|/* On the vax and 68000, in BSD4.2 and USG5.2,    this is the data format on startup:   (vax) ap and fp are unpredictable as far as I know; don't use them.   sp ->  word containing argc          word pointing to first arg string 	 [word pointing to next arg string]... 0 or more times 	 0 Optionally: 	 [word pointing to environment variable]... 1 or more times 	 ... 	 0 And always: 	 first arg string 	 [next arg string]... 0 or more times */
end_comment

begin_comment
comment|/* On the 16000, at least in the one 4.2 system I know about,   the initial data format is   sp ->  word containing argc          word containing argp          word pointing to first arg string, and so on as above */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/*		********  WARNING ********     Do not insert any data definitions before data_start!     Since this is the first file linked, the address of the following     variable should correspond to the start of initialized data space.     On some systems this is a constant that is independent of the text     size for shared executables.  On others, it is a function of the     text size. In short, this seems to be the most portable way to     discover the start of initialized data space dynamically at runtime,     for either shared or unshared executables, on either swapping or     virtual systems.  It only requires that the linker allocate objects     in the order encountered, a reasonable model for most Unix systems.     Similarly, note that the address of _start() should be the start     of text space.   Fred Fish, UniSoft Systems Inc.  */
end_comment

begin_decl_stmt
name|int
name|data_start
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_ERRNO
end_ifdef

begin_decl_stmt
name|int
name|errno
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|orion
argument_list|)
operator|||
name|defined
argument_list|(
name|pyramid
argument_list|)
operator|||
name|defined
argument_list|(
name|celerity
argument_list|)
end_if

begin_macro
name|_start
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|,
argument|envp
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|,
modifier|*
modifier|*
name|envp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|environ
operator|=
name|envp
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|envp
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* orion or pyramid or celerity */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ns16000
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|sequent
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|UMAX
argument_list|)
end_if

begin_macro
name|_start
argument_list|()
end_macro

begin_block
block|{
comment|/* On 16000, _start pushes fp onto stack */
name|start1
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ignore takes care of skipping the fp value pushed in start.  */
end_comment

begin_expr_stmt
specifier|static
name|start1
argument_list|(
argument|ignore
argument_list|,
argument|argc
argument_list|,
argument|argv
argument_list|)
name|int
name|ignore
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|environ
operator|=
name|argv
operator|+
name|argc
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|environ
operator|==
operator|*
name|argv
condition|)
name|environ
operator|--
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ns16000, not sequent and not UMAX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UMAX
end_ifdef

begin_macro
name|_start
argument_list|()
end_macro

begin_block
block|{
asm|asm("	exit []			# undo enter");
asm|asm("	.set	exitsc,1");
asm|asm("	.set	sigcatchall,0x400");
asm|asm("	.globl	_exit");
asm|asm("	.globl	start");
asm|asm("	.globl	__start");
asm|asm("	.globl	_main");
asm|asm("	.globl	_environ");
asm|asm("	.globl	_sigvec");
asm|asm("	.globl	sigentry");
asm|asm("start:");
asm|asm("	br	.xstart");
asm|asm("	.org	0x20");
asm|asm("	.double	p_glbl,0,0xf00000,0");
asm|asm("	.org	0x30");
asm|asm(".xstart:");
asm|asm("	adjspb	$8");
asm|asm("	movd	8(sp),0(sp)	# argc");
asm|asm("	addr	12(sp),r0");
asm|asm("	movd	r0,4(sp)	# argv");
asm|asm("L1:");
asm|asm("	movd	r0,r1");
asm|asm("	addqd	$4,r0");
asm|asm("	cmpqd	$0,0(r1)	# null args term ?");
asm|asm("	bne	L1");
asm|asm("	cmpd	r0,0(4(sp))	# end of 'env' or 'argv' ?");
asm|asm("	blt	L2");
asm|asm("	addqd	$-4,r0		# envp's are in list");
asm|asm("L2:");
asm|asm("	movd	r0,8(sp)	# env");
asm|asm("	movd	r0,@_environ	# indir is 0 if no env ; not 0 if env");
asm|asm("	movqd	$0,tos		# setup intermediate signal handler");
asm|asm("	addr	@sv,tos");
asm|asm("	movzwd	$sigcatchall,tos");
asm|asm("	jsr	@_sigvec");
asm|asm("	adjspb	$-12");
asm|asm("	jsr	@_main");
asm|asm("	adjspb	$-12");
asm|asm("	movd	r0,tos");
asm|asm("	jsr	@_exit");
asm|asm("	adjspb	$-4");
asm|asm("	addr	@exitsc,r0");
asm|asm("	svc");
asm|asm("	.align	4		# sigvec arg");
asm|asm("sv:");
asm|asm("	.double	sigentry");
asm|asm("	.double	0");
asm|asm("	.double	0");
asm|asm("	.comm	p_glbl,1");
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UMAX */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
operator|||
name|defined
argument_list|(
name|tahoe
argument_list|)
operator|||
name|defined
argument_list|(
name|sequent
argument_list|)
operator|||
name|defined
argument_list|(
name|BOGUS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|sequent
end_ifdef

begin_define
define|#
directive|define
name|BOGUS
value|bogus_fp,
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sequent */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|BOGUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|BOGUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tahoe */
end_comment

begin_comment
comment|/* Define symbol "start": here; some systems want that symbol.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tower32
end_ifdef

begin_asm
asm|asm("	text		");
end_asm

begin_asm
asm|asm("	global start	");
end_asm

begin_else
else|#
directive|else
end_else

begin_asm
asm|asm("	.text		");
end_asm

begin_asm
asm|asm("	.globl start	");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_asm
asm|asm("	start:		");
end_asm

begin_macro
name|_start
argument_list|()
end_macro

begin_block
block|{
comment|/* On vax, nothing is pushed here  */
comment|/* On sequent, bogus fp is pushed here  */
name|start1
argument_list|()
expr_stmt|;
block|}
end_block

begin_expr_stmt
specifier|static
name|start1
argument_list|(
argument|BOGUS argc
argument_list|,
argument|xargv
argument_list|)
name|int
name|argc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
modifier|*
name|argv
init|=
operator|&
name|xargv
decl_stmt|;
name|environ
operator|=
name|argv
operator|+
name|argc
operator|+
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|char
operator|*
operator|)
name|environ
operator|==
name|xargv
condition|)
name|environ
operator|--
expr_stmt|;
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not vax or tahoe or sequent or BOGUS */
end_comment

begin_comment
comment|/* "m68k" and "m68000" both stand for m68000 processors,    but with different program-entry conventions.    This is a kludge.  Now that the BOGUS mechanism above exists,    most of these machines could use the vax code above    with some suitable definition of BOGUS.    Then the symbol m68k could be flushed.    But I don't want to risk breaking these machines    in a version 17 patch release, so that change is being put off.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m68k
end_ifdef

begin_comment
comment|/* Can't do it all from C */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STRIDE
end_ifdef

begin_asm
asm|asm ("	comm	havefpu%,2");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* m68k, not STRIDE */
end_comment

begin_asm
asm|asm ("	data");
end_asm

begin_asm
asm|asm ("	even");
end_asm

begin_asm
asm|asm ("	global	splimit%");
end_asm

begin_asm
asm|asm ("splimit%:");
end_asm

begin_asm
asm|asm ("	space 4");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRIDE */
end_comment

begin_asm
asm|asm ("	global	_start");
end_asm

begin_asm
asm|asm ("	global	exit");
end_asm

begin_asm
asm|asm ("	text");
end_asm

begin_asm
asm|asm ("_start:");
end_asm

begin_ifdef
ifdef|#
directive|ifdef
name|STRIDE
end_ifdef

begin_asm
asm|asm ("	trap&3");
end_asm

begin_asm
asm|asm ("	mov.w	%d0,havefpu%");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* m68k, not STRIDE */
end_comment

begin_asm
asm|asm ("	mov.l	%d0,splimit%");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRIDE */
end_comment

begin_asm
asm|asm ("	jsr	start1");
end_asm

begin_asm
asm|asm ("	mov.l	%d0,(%sp)");
end_asm

begin_asm
asm|asm ("	jsr	exit");
end_asm

begin_asm
asm|asm ("	mov.l&1,%d0");
end_asm

begin_comment
comment|/* d0 = 1 => exit */
end_comment

begin_asm
asm|asm ("	trap&0");
end_asm

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* m68000, not m68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m68000
end_ifdef

begin_macro
name|_start
argument_list|()
end_macro

begin_block
block|{
comment|/* On 68000, _start pushes a6 onto stack  */
name|start1
argument_list|()
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m68000 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m68k */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|m68k
argument_list|)
operator|||
name|defined
argument_list|(
name|m68000
argument_list|)
end_if

begin_comment
comment|/* ignore takes care of skipping the a6 value pushed in start.  */
end_comment

begin_expr_stmt
specifier|static
ifdef|#
directive|ifdef
name|m68k
name|start1
argument_list|(
argument|argc
argument_list|,
argument|xargv
argument_list|)
else|#
directive|else
name|start1
argument_list|(
argument|ignore
argument_list|,
argument|argc
argument_list|,
argument|xargv
argument_list|)
endif|#
directive|endif
name|int
name|argc
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|xargv
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
modifier|*
name|argv
init|=
operator|&
name|xargv
decl_stmt|;
name|environ
operator|=
name|argv
operator|+
name|argc
operator|+
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|char
operator|*
operator|)
name|environ
operator|==
name|xargv
condition|)
name|environ
operator|--
expr_stmt|;
ifdef|#
directive|ifdef
name|sun2
name|hack_sky
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* sun2 */
name|exit
argument_list|(
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|environ
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m68k or m68000 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not vax or tahoe or sequent or BOGUS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s200
end_ifdef

begin_decl_stmt
name|int
name|argc_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv_value
decl_stmt|;
end_decl_stmt

begin_asm
asm|asm("   text");
end_asm

begin_asm
asm|asm("	globl __start");
end_asm

begin_asm
asm|asm("	globl _exit");
end_asm

begin_asm
asm|asm("	globl _main");
end_asm

begin_asm
asm|asm("__start");
end_asm

begin_asm
asm|asm("	dc.l	0");
end_asm

begin_asm
asm|asm("	subq.w	#0x1,d0");
end_asm

begin_asm
asm|asm("	move.w	d0,float_soft");
end_asm

begin_asm
asm|asm("	move.l	0x4(a7),d0");
end_asm

begin_asm
asm|asm("	beq.s	skip_1");
end_asm

begin_asm
asm|asm("	move.l	d0,a0");
end_asm

begin_asm
asm|asm("	clr.l	-0x4(a0)");
end_asm

begin_asm
asm|asm("skip_1");
end_asm

begin_asm
asm|asm("	move.l	a7,a0");
end_asm

begin_asm
asm|asm("	subq.l	#0x8,a7");
end_asm

begin_asm
asm|asm("	move.l	(a0),(a7)");
end_asm

begin_asm
asm|asm("	move.l	(a0),_argc_value");
end_asm

begin_asm
asm|asm("	addq.l	#0x4,a0");
end_asm

begin_asm
asm|asm("	move.l	a0,0x4(a7)");
end_asm

begin_asm
asm|asm("	move.l	a0,_argv_value");
end_asm

begin_asm
asm|asm("incr_loop");
end_asm

begin_asm
asm|asm("	tst.l	(a0)+");
end_asm

begin_asm
asm|asm("	bne.s	incr_loop");
end_asm

begin_asm
asm|asm("	move.l	0x4(a7),a1");
end_asm

begin_asm
asm|asm("	cmp.l	(a1),a0");
end_asm

begin_asm
asm|asm("	blt.s	skip_2");
end_asm

begin_asm
asm|asm("	subq.l	#0x4,a0");
end_asm

begin_asm
asm|asm("skip_2");
end_asm

begin_asm
asm|asm("	move.l	a0,0x8(a7)");
end_asm

begin_asm
asm|asm("	move.l	a0,_environ");
end_asm

begin_asm
asm|asm("	jsr	_main");
end_asm

begin_asm
asm|asm("	addq.l	#0x8,a7");
end_asm

begin_asm
asm|asm("	move.l	d0,-(a7)");
end_asm

begin_asm
asm|asm("	jsr	_exit");
end_asm

begin_asm
asm|asm("	move.w	#0x1,d0");
end_asm

begin_asm
asm|asm("	trap	#0x0");
end_asm

begin_asm
asm|asm("	comm	float_soft,4");
end_asm

begin_comment
comment|/* float_soft is allocated in this way because C would    put an underscore character in its name otherwise. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hp9000s200 */
end_comment

end_unit

