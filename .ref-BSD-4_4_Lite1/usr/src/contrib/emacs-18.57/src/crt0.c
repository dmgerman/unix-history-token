begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* C code startup routine.    Copyright (C) 1985, 1986 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 1, or (at your option)     any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; if not, write to the Free Software     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  In other words, you are welcome to use, share and improve this program. You are forbidden to forbid anyone else to use, share and improve what you give them.   Help stamp out software-hoarding!  */
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
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_NEED_ENVIRON
end_ifndef

begin_decl_stmt
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
operator|||
name|defined
argument_list|(
name|ALLIANT
argument_list|)
operator|||
name|defined
argument_list|(
name|clipper
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|ALLIANT
end_ifdef

begin_comment
comment|/* _start must initialize _curbrk and _minbrk on the first startup;    when starting up after dumping, it must initialize them to what they were    before the dumping, since they are in the shared library and    are not dumped.  See ADJUST_EXEC_HEADER in m-alliant.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|_curbrk
decl_stmt|,
modifier|*
name|_minbrk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
modifier|*
name|_setbrk
init|=
operator|&
name|end
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DUMMIES
end_ifndef

begin_define
define|#
directive|define
name|DUMMIES
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_start
argument_list|(
argument|DUMMIES argc
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
ifdef|#
directive|ifdef
name|ALLIANT
name|_curbrk
operator|=
name|_setbrk
expr_stmt|;
name|_minbrk
operator|=
name|_setbrk
expr_stmt|;
endif|#
directive|endif
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
comment|/* orion or pyramid or celerity or alliant or clipper */
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRT0_DUMMIES
end_ifdef

begin_comment
comment|/* Define symbol "start": here; some systems want that symbol.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOT_GLOBAL_START
end_ifdef

begin_asm
asm|asm("	.text		");
end_asm

begin_asm
asm|asm("	.globl start	");
end_asm

begin_asm
asm|asm("	start:		");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOT_GLOBAL_START */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NODOT_GLOBAL_START
end_ifdef

begin_asm
asm|asm("	text		");
end_asm

begin_asm
asm|asm("	global start	");
end_asm

begin_asm
asm|asm("	start:		");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NODOT_GLOBAL_START */
end_comment

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
argument|CRT0_DUMMIES argc
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
comment|/* not CRT0_DUMMIES */
end_comment

begin_comment
comment|/* "m68k" and "m68000" both stand for m68000 processors,    but with different program-entry conventions.    This is a kludge.  Now that the CRT0_DUMMIES mechanism above exists,    most of these machines could use the vax code above    with some suitable definition of CRT0_DUMMIES.    Then the symbol m68k could be flushed.    But I don't want to risk breaking these machines    in a version 17 patch release, so that change is being put off.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m68k
end_ifdef

begin_comment
comment|/* Can't do it all from C */
end_comment

begin_asm
asm|asm ("	global	_start");
end_asm

begin_asm
asm|asm ("	text");
end_asm

begin_asm
asm|asm ("_start:");
end_asm

begin_ifndef
ifndef|#
directive|ifndef
name|NU
end_ifndef

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
asm|asm ("  comm	splimit%,4");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRIDE */
end_comment

begin_asm
asm|asm ("	global	exit");
end_asm

begin_asm
asm|asm ("	text");
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not NU */
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

begin_ifdef
ifdef|#
directive|ifdef
name|ISI68K
end_ifdef

begin_comment
comment|/* Added by ESM Sun May 24 12:44:02 1987 to get new ISI library to work */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_3
end_ifdef

begin_expr_stmt
specifier|static
name|foo
argument_list|()
block|{
endif|#
directive|endif
name|asm
argument_list|(
literal|"	.globl  is68020"
argument_list|)
block|;
name|asm
argument_list|(
literal|"is68020:"
argument_list|)
block|;
ifndef|#
directive|ifndef
name|BSD4_3
name|asm
argument_list|(
literal|"	.long   0x00000000"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	.long   0xffffffff"
argument_list|)
block|;
comment|/* End of stuff added by ESM */
endif|#
directive|endif
name|asm
argument_list|(
literal|"	.text"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	.globl	__start"
argument_list|)
block|;
name|asm
argument_list|(
literal|"__start:"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	.word 0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	link	fp,#0"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	jbsr	_start1"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	unlk	fp"
argument_list|)
block|;
name|asm
argument_list|(
literal|"	rts"
argument_list|)
block|;
ifdef|#
directive|ifdef
name|BSD4_3
block|}
endif|#
directive|endif
else|#
directive|else
comment|/* not ISI68K */
name|_start
argument_list|()
block|{
comment|/* On 68000, _start pushes a6 onto stack  */
name|start1
argument_list|()
block|; }
endif|#
directive|endif
comment|/* not ISI68k */
endif|#
directive|endif
comment|/* m68000 */
endif|#
directive|endif
comment|/* m68k */
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
comment|/* ignore takes care of skipping the a6 value pushed in start.  */
specifier|static
if|#
directive|if
name|defined
argument_list|(
name|m68k
argument_list|)
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
comment|/* not CRT0_DUMMIES */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp9000s300
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

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_HP_ASSEMBLER
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* new hp assembler */
end_comment

begin_asm
asm|asm("	text");
end_asm

begin_asm
asm|asm("   global  float_loc");
end_asm

begin_asm
asm|asm("   set     float_loc,0xFFFFB000");
end_asm

begin_asm
asm|asm("	global	fpa_loc");
end_asm

begin_asm
asm|asm("	set	fpa_loc,0xfff08000");
end_asm

begin_asm
asm|asm("	global	__start");
end_asm

begin_asm
asm|asm("	global	_exit");
end_asm

begin_asm
asm|asm("	global	_main");
end_asm

begin_asm
asm|asm("__start:");
end_asm

begin_asm
asm|asm("	byte	0,0,0,0");
end_asm

begin_asm
asm|asm("	subq.w&1,%d0");
end_asm

begin_asm
asm|asm("	mov.w	%d0,float_soft");
end_asm

begin_asm
asm|asm("	mov.w	%d1,flag_68881");
end_asm

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX_68010
end_ifndef

begin_asm
asm|asm("	beq.b	skip_float");
end_asm

begin_asm
asm|asm("	fmov.l&0x7400,%fpcr");
end_asm

begin_comment
comment|/*	asm("	fmov.l&0x7480,%fpcr"); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX_68010 */
end_comment

begin_asm
asm|asm("skip_float:");
end_asm

begin_asm
asm|asm("	mov.l	%a0,%d0");
end_asm

begin_asm
asm|asm("	add.l	%d0,%d0");
end_asm

begin_asm
asm|asm("	subx.w	%d1,%d1");
end_asm

begin_asm
asm|asm("	mov.w	%d1,flag_68010");
end_asm

begin_asm
asm|asm("	add.l	%d0,%d0");
end_asm

begin_asm
asm|asm("	subx.w	%d1,%d1");
end_asm

begin_asm
asm|asm("	mov.w	%d1,flag_fpa");
end_asm

begin_asm
asm|asm("	tst.l	%d2");
end_asm

begin_asm
asm|asm("	ble.b	skip_3");
end_asm

begin_asm
asm|asm("	lsl	flag_68881");
end_asm

begin_asm
asm|asm("	lsl	flag_fpa");
end_asm

begin_asm
asm|asm("skip_3:");
end_asm

begin_asm
asm|asm("	mov.l	4(%a7),%d0");
end_asm

begin_asm
asm|asm("	beq.b	skip_1");
end_asm

begin_asm
asm|asm("	mov.l	%d0,%a0");
end_asm

begin_asm
asm|asm("	clr.l	-4(%a0)");
end_asm

begin_asm
asm|asm("skip_1:");
end_asm

begin_asm
asm|asm("	mov.l	%a7,%a0");
end_asm

begin_asm
asm|asm("	subq.l&8,%a7");
end_asm

begin_asm
asm|asm("	mov.l	(%a0),(%a7)");
end_asm

begin_asm
asm|asm("	mov.l	(%a0),_argc_value");
end_asm

begin_asm
asm|asm("	addq.l&4,%a0");
end_asm

begin_asm
asm|asm("	mov.l	%a0,4(%a7)");
end_asm

begin_asm
asm|asm("	mov.l	%a0,_argv_value");
end_asm

begin_asm
asm|asm("incr_loop:");
end_asm

begin_asm
asm|asm("	tst.l	(%a0)+");
end_asm

begin_asm
asm|asm("	bne.b	incr_loop");
end_asm

begin_asm
asm|asm("	mov.l	4(%a7),%a1");
end_asm

begin_asm
asm|asm("	cmp.l	%a0,(%a1)");
end_asm

begin_asm
asm|asm("	blt.b	skip_2");
end_asm

begin_asm
asm|asm("	subq.l&4,%a0");
end_asm

begin_asm
asm|asm("skip_2:");
end_asm

begin_asm
asm|asm("	mov.l	%a0,8(%a7)");
end_asm

begin_asm
asm|asm("	mov.l	%a0,_environ");
end_asm

begin_asm
asm|asm("	jsr	_main");
end_asm

begin_asm
asm|asm("	addq.l&8,%a7");
end_asm

begin_asm
asm|asm("	mov.l	%d0,-(%a7)");
end_asm

begin_asm
asm|asm("	jsr	_exit");
end_asm

begin_asm
asm|asm("	mov.w&1,%d0");
end_asm

begin_asm
asm|asm("	trap&0");
end_asm

begin_asm
asm|asm("	comm	float_soft, 4");
end_asm

begin_asm
asm|asm("	comm	flag_68881, 4");
end_asm

begin_asm
asm|asm("	comm	flag_68010, 4");
end_asm

begin_asm
asm|asm("	comm	flag_fpa, 4");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* new hp assembler */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hp9000s300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GOULD
end_ifdef

begin_comment
comment|/* startup code has to be in near text rather    than fartext as allocated by the C compiler. */
end_comment

begin_asm
asm|asm("	.text");
end_asm

begin_asm
asm|asm("	.align	2");
end_asm

begin_asm
asm|asm("	.globl	__start");
end_asm

begin_asm
asm|asm("	.text");
end_asm

begin_asm
asm|asm("__start:");
end_asm

begin_comment
comment|/* setup base register b1 (function base). */
end_comment

begin_asm
asm|asm("	.using	b1,.");
end_asm

begin_asm
asm|asm("	tpcbr	b1");
end_asm

begin_comment
comment|/* setup base registers b3 through b7 (data references). */
end_comment

begin_asm
asm|asm("	file	basevals,b3");
end_asm

begin_comment
comment|/* setup base register b2 (stack pointer); it should be    aligned on a 8-word boundary; but because it is pointing    to argc, its value should be remembered (in r5). */
end_comment

begin_asm
asm|asm("	movw	b2,r4");
end_asm

begin_asm
asm|asm("	movw	b2,r5");
end_asm

begin_asm
asm|asm("	andw	#~0x1f,r4");
end_asm

begin_asm
asm|asm("	movw	r4,b2");
end_asm

begin_comment
comment|/* allocate stack frame to do some work. */
end_comment

begin_asm
asm|asm("	subea	16w,b2");
end_asm

begin_comment
comment|/* initialize signal catching for UTX/32 1.2; this is    necessary to make restart from saved image work. */
end_comment

begin_asm
asm|asm("	movea	sigcatch,r1");
end_asm

begin_asm
asm|asm("	movw	r1,8w[b2]");
end_asm

begin_asm
asm|asm("	svc	#1,#150");
end_asm

begin_comment
comment|/* setup address of argc for start1. */
end_comment

begin_asm
asm|asm("	movw	r5,8w[b2]");
end_asm

begin_asm
asm|asm("   func	#1,_start1");
end_asm

begin_asm
asm|asm("	halt");
end_asm

begin_comment
comment|/* space for ld to store base register initial values. */
end_comment

begin_asm
asm|asm("	.align	5");
end_asm

begin_asm
asm|asm("basevals:");
end_asm

begin_asm
asm|asm("	.word	__base3,__base4,__base5,__base6,__base7");
end_asm

begin_expr_stmt
specifier|static
name|start1
argument_list|(
argument|xargc
argument_list|)
name|int
operator|*
name|xargc
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|argc
decl_stmt|;
specifier|register
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|argc
operator|=
operator|*
name|xargc
expr_stmt|;
name|argv
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
operator|(
name|xargc
operator|)
operator|+
literal|1
expr_stmt|;
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
comment|/* GOULD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|elxsi
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
end_decl_stmt

begin_macro
name|_start
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|r
decl_stmt|;
name|errno
operator|=
literal|0
expr_stmt|;
name|environ
operator|=
operator|*
operator|(
operator|&
name|environ
operator|+
literal|8
operator|)
expr_stmt|;
name|_stdinit
argument_list|()
expr_stmt|;
name|r
operator|=
name|main
argument_list|(
operator|*
operator|(
operator|&
name|environ
operator|+
literal|6
operator|)
argument_list|,
operator|*
operator|(
operator|&
name|environ
operator|+
literal|7
operator|)
argument_list|,
name|environ
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|r
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* elxsi */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_asm
asm|asm (".global __start");
end_asm

begin_asm
asm|asm (".text");
end_asm

begin_asm
asm|asm ("__start:");
end_asm

begin_asm
asm|asm ("	mov	0, %fp");
end_asm

begin_asm
asm|asm ("	ld	[%sp + 64], %o0");
end_asm

begin_asm
asm|asm ("	add	%sp, 68, %o1");
end_asm

begin_asm
asm|asm ("	sll	%o0, 2,	%o2");
end_asm

begin_asm
asm|asm ("	add	%o2, 4,	%o2");
end_asm

begin_asm
asm|asm ("	add	%o1, %o2, %o2");
end_asm

begin_asm
asm|asm ("	sethi	%hi(_environ), %o3");
end_asm

begin_asm
asm|asm ("	st	%o2, [%o3+%lo(_environ)]");
end_asm

begin_asm
asm|asm ("	andn	%sp, 7,	%sp");
end_asm

begin_asm
asm|asm ("	call	_main");
end_asm

begin_asm
asm|asm ("	sub	%sp, 24, %sp");
end_asm

begin_asm
asm|asm ("	call	__exit");
end_asm

begin_asm
asm|asm ("	nop");
end_asm

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

end_unit

