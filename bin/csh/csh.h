begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)csh.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Fundamental definitions which may vary from system to system.  *  *	BUFSIZ		The i/o buffering size; also limits word size  *	MAILINTVL	How often to mailcheck; more often is more expensive  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_comment
comment|/* default buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUFSIZ */
end_comment

begin_define
define|#
directive|define
name|FORKSLEEP
value|10
end_define

begin_comment
comment|/* delay loop on non-interactive fork failure */
end_comment

begin_define
define|#
directive|define
name|MAILINTVL
value|600
end_define

begin_comment
comment|/* 10 minutes */
end_comment

begin_comment
comment|/*  * The shell moves std in/out/diag and the old std input away from units  * 0, 1, and 2 so that it is easy to set up these standards for invoked  * commands.  */
end_comment

begin_define
define|#
directive|define
name|FSHTTY
value|15
end_define

begin_comment
comment|/* /dev/tty when manip pgrps */
end_comment

begin_define
define|#
directive|define
name|FSHIN
value|16
end_define

begin_comment
comment|/* Preferred desc for shell input */
end_comment

begin_define
define|#
directive|define
name|FSHOUT
value|17
end_define

begin_comment
comment|/* ... shell output */
end_comment

begin_define
define|#
directive|define
name|FSHERR
value|18
end_define

begin_comment
comment|/* ... shell diagnostics */
end_comment

begin_define
define|#
directive|define
name|FOLDSTD
value|19
end_define

begin_comment
comment|/* ... old std input */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROF
end_ifdef

begin_define
define|#
directive|define
name|xexit
parameter_list|(
name|n
parameter_list|)
value|done(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_STRINGS
end_ifdef

begin_typedef
typedef|typedef
name|short
name|Char
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAVE
parameter_list|(
name|a
parameter_list|)
value|(Strsave(str2short(a)))
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|Char
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAVE
parameter_list|(
name|a
parameter_list|)
value|(strsave(a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Make sure a variable is not stored in a register by taking its address  * This is used where variables might be clobbered by longjmp.  */
end_comment

begin_define
define|#
directive|define
name|UNREGISTER
parameter_list|(
name|a
parameter_list|)
value|(void)&a
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|ioctl_t
typedef|;
end_typedef

begin_comment
comment|/* Third arg of ioctl */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|ptr_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"const.h"
end_include

begin_include
include|#
directive|include
file|"char.h"
end_include

begin_include
include|#
directive|include
file|"err.h"
end_include

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|i
parameter_list|)
value|Malloc(i)
end_define

begin_define
define|#
directive|define
name|xrealloc
parameter_list|(
name|p
parameter_list|,
name|i
parameter_list|)
value|Realloc(p, i)
end_define

begin_define
define|#
directive|define
name|xcalloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|Calloc(n, s)
end_define

begin_define
define|#
directive|define
name|xfree
parameter_list|(
name|p
parameter_list|)
value|Free(p)
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|FILE
modifier|*
name|cshin
decl_stmt|,
modifier|*
name|cshout
decl_stmt|,
modifier|*
name|csherr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|isdir
parameter_list|(
name|d
parameter_list|)
value|((d.st_mode& S_IFMT) == S_IFDIR)
end_define

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(Strcmp(a, b) == 0)
end_define

begin_comment
comment|/* globone() flags */
end_comment

begin_define
define|#
directive|define
name|G_ERROR
value|0
end_define

begin_comment
comment|/* default action: error if multiple words */
end_comment

begin_define
define|#
directive|define
name|G_IGNORE
value|1
end_define

begin_comment
comment|/* ignore the rest of the words */
end_comment

begin_define
define|#
directive|define
name|G_APPEND
value|2
end_define

begin_comment
comment|/* make a sentence by cat'ing the words */
end_comment

begin_comment
comment|/*  * Global flags  */
end_comment

begin_decl_stmt
name|bool
name|chkstop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warned of stopped jobs... allow exit */
end_comment

begin_decl_stmt
name|bool
name|didfds
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Have setup i/o fd's for child */
end_comment

begin_decl_stmt
name|bool
name|doneinp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EOF indicator after reset from readc */
end_comment

begin_decl_stmt
name|bool
name|exiterr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Exit if error or non-zero exit status */
end_comment

begin_decl_stmt
name|bool
name|child
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Child shell ... errors cause exit */
end_comment

begin_decl_stmt
name|bool
name|haderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reset was because of an error */
end_comment

begin_decl_stmt
name|bool
name|intty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input is a tty */
end_comment

begin_decl_stmt
name|bool
name|intact
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We are interactive... therefore prompt */
end_comment

begin_decl_stmt
name|bool
name|justpr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Just print because of :p hist mod */
end_comment

begin_decl_stmt
name|bool
name|loginsh
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We are a loginsh -> .login/.logout */
end_comment

begin_decl_stmt
name|bool
name|neednote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Need to pnotify() */
end_comment

begin_decl_stmt
name|bool
name|noexec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't execute, just syntax check */
end_comment

begin_decl_stmt
name|bool
name|pjobs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* want to print jobs if interrupted */
end_comment

begin_decl_stmt
name|bool
name|setintr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set interrupts on/off -> Wait intr... */
end_comment

begin_decl_stmt
name|bool
name|timflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time the next waited for command */
end_comment

begin_decl_stmt
name|bool
name|havhash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* path hashing is available */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FILEC
end_ifdef

begin_decl_stmt
name|bool
name|filec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* doing filename expansion */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global i/o info  */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|arginp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument input for sh -c and internal `xx` */
end_comment

begin_decl_stmt
name|int
name|onelflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 2 -> need line for -t, 1 -> exit on read */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|ffile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of shell file for $0 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|seterr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error message from scanner/parser */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|shtemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp name for<< shell files in /tmp */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_decl_stmt
name|struct
name|timeval
name|time0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time at which the shell started */
end_comment

begin_decl_stmt
name|struct
name|rusage
name|ru0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Miscellany  */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|doldol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character pid for $$ */
end_comment

begin_decl_stmt
name|int
name|backpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pid of the last background process */
end_comment

begin_decl_stmt
name|int
name|uid
decl_stmt|,
name|euid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invokers uid */
end_comment

begin_decl_stmt
name|int
name|gid
decl_stmt|,
name|egid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invokers gid */
end_comment

begin_decl_stmt
name|time_t
name|chktim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Time mail last checked */
end_comment

begin_decl_stmt
name|int
name|shpgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pgrp of shell */
end_comment

begin_decl_stmt
name|int
name|tpgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal process group */
end_comment

begin_comment
comment|/* If tpgrp is -1, leave tty alone! */
end_comment

begin_decl_stmt
name|int
name|opgrp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initial pgrp and tty pgrp */
end_comment

begin_comment
comment|/*  * To be able to redirect i/o for builtins easily, the shell moves the i/o  * descriptors it uses away from 0,1,2.  * Ideally these should be in units which are closed across exec's  * (this saves work) but for version 6, this is not usually possible.  * The desired initial values for these descriptors are F{SHIN,...}.  */
end_comment

begin_decl_stmt
name|int
name|SHIN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current shell input (script) */
end_comment

begin_decl_stmt
name|int
name|SHOUT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shell output */
end_comment

begin_decl_stmt
name|int
name|SHERR
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Diagnostic output... shell errs go here */
end_comment

begin_decl_stmt
name|int
name|OLDSTD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Old standard input (def for cmds) */
end_comment

begin_comment
comment|/*  * Error control  *  * Errors in scanning and parsing set up an error message to be printed  * at the end and complete.  Other errors always cause a reset.  * Because of source commands and .cshrc we need nested error catches.  */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
name|jmp_buf
name|reslab
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setexit
parameter_list|()
value|(setjmp(reslab))
end_define

begin_define
define|#
directive|define
name|reset
parameter_list|()
value|longjmp(reslab, 1)
end_define

begin_comment
comment|/* Should use structure assignment here */
end_comment

begin_define
define|#
directive|define
name|getexit
parameter_list|(
name|a
parameter_list|)
value|bcopy((char *)reslab, ((char *)(a)), sizeof reslab)
end_define

begin_define
define|#
directive|define
name|resexit
parameter_list|(
name|a
parameter_list|)
value|bcopy((char *)(a), (char *)reslab, sizeof reslab)
end_define

begin_decl_stmt
name|Char
modifier|*
name|gointr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Label for an onintr transfer */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
name|sig_t
name|parintr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parents interrupt catch */
end_comment

begin_decl_stmt
name|sig_t
name|parterm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parents terminate catch */
end_comment

begin_comment
comment|/*  * Lexical definitions.  *  * All lexical space is allocated dynamically.  * The eighth/sixteenth bit of characters is used to prevent recognition,  * and eventually stripped.  */
end_comment

begin_define
define|#
directive|define
name|META
value|0200
end_define

begin_define
define|#
directive|define
name|ASCII
value|0177
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SHORT_STRINGS
end_ifdef

begin_define
define|#
directive|define
name|CHAR
value|0377
end_define

begin_define
define|#
directive|define
name|QUOTE
value|0100000
end_define

begin_comment
comment|/* 16nth char bit used for 'ing */
end_comment

begin_define
define|#
directive|define
name|TRIM
value|0077777
end_define

begin_comment
comment|/* Mask to strip quote bit */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAR
value|0177
end_define

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_comment
comment|/* Eighth char bit used for 'ing */
end_comment

begin_define
define|#
directive|define
name|TRIM
value|0177
end_define

begin_comment
comment|/* Mask to strip quote bit */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|AsciiOnly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If set only 7 bits is expected in characters */
end_comment

begin_comment
comment|/*  * Each level of input has a buffered input structure.  * There are one or more blocks of buffered input for each level,  * exactly one if the input is seekable and tell is available.  * In other cases, the shell buffers enough blocks to keep all loops  * in the buffer.  */
end_comment

begin_struct
struct|struct
name|Bin
block|{
name|off_t
name|Bfseekp
decl_stmt|;
comment|/* Seek pointer */
name|off_t
name|Bfbobp
decl_stmt|;
comment|/* Seekp of beginning of buffers */
name|off_t
name|Bfeobp
decl_stmt|;
comment|/* Seekp of end of buffers */
name|int
name|Bfblocks
decl_stmt|;
comment|/* Number of buffer blocks */
name|Char
modifier|*
modifier|*
name|Bfbuf
decl_stmt|;
comment|/* The array of buffer blocks */
block|}
name|B
struct|;
end_struct

begin_comment
comment|/*  * This structure allows us to seek inside aliases  */
end_comment

begin_struct
struct|struct
name|Ain
block|{
name|int
name|type
decl_stmt|;
define|#
directive|define
name|I_SEEK
value|-1
comment|/* Invalid seek */
define|#
directive|define
name|A_SEEK
value|0
comment|/* Alias seek */
define|#
directive|define
name|F_SEEK
value|1
comment|/* File seek */
define|#
directive|define
name|E_SEEK
value|2
comment|/* Eval seek */
union|union
block|{
name|off_t
name|_f_seek
decl_stmt|;
name|Char
modifier|*
name|_c_seek
decl_stmt|;
block|}
name|fc
union|;
define|#
directive|define
name|f_seek
value|fc._f_seek
define|#
directive|define
name|c_seek
value|fc._c_seek
name|Char
modifier|*
modifier|*
name|a_seek
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|aret
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What was the last character returned */
end_comment

begin_define
define|#
directive|define
name|SEEKEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)->type == (b)->type&& \ 		      (a)->f_seek == (b)->f_seek&& \ 		      (a)->a_seek == (b)->a_seek)
end_define

begin_define
define|#
directive|define
name|fseekp
value|B.Bfseekp
end_define

begin_define
define|#
directive|define
name|fbobp
value|B.Bfbobp
end_define

begin_define
define|#
directive|define
name|feobp
value|B.Bfeobp
end_define

begin_define
define|#
directive|define
name|fblocks
value|B.Bfblocks
end_define

begin_define
define|#
directive|define
name|fbuf
value|B.Bfbuf
end_define

begin_comment
comment|/*  * The shell finds commands in loops by reseeking the input  * For whiles, in particular, it reseeks to the beginning of the  * line the while was on; hence the while placement restrictions.  */
end_comment

begin_decl_stmt
name|struct
name|Ain
name|lineloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|cantell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is current source tellable ? */
end_comment

begin_comment
comment|/*  * Input lines are parsed into doubly linked circular  * lists of words of the following form.  */
end_comment

begin_struct
struct|struct
name|wordent
block|{
name|Char
modifier|*
name|word
decl_stmt|;
name|struct
name|wordent
modifier|*
name|prev
decl_stmt|;
name|struct
name|wordent
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * During word building, both in the initial lexical phase and  * when expanding $ variable substitutions, expansion by `!' and `$'  * must be inhibited when reading ahead in routines which are themselves  * processing `!' and `$' expansion or after characters such as `\' or in  * quotations.  The following flags are passed to the getC routines  * telling them which of these substitutions are appropriate for the  * next character to be returned.  */
end_comment

begin_define
define|#
directive|define
name|DODOL
value|1
end_define

begin_define
define|#
directive|define
name|DOEXCL
value|2
end_define

begin_define
define|#
directive|define
name|DOALL
value|DODOL|DOEXCL
end_define

begin_comment
comment|/*  * Labuf implements a general buffer for lookahead during lexical operations.  * Text which is to be placed in the input stream can be stuck here.  * We stick parsed ahead $ constructs during initial input,  * process id's from `$$', and modified variable values (from qualifiers  * during expansion in sh.dol.c) here.  */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|lap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Parser structure  *  * Each command is parsed to a tree of command structures and  * flags are set bottom up during this process, to be propagated down  * as needed during the semantics/exeuction pass (sh.sem.c).  */
end_comment

begin_struct
struct|struct
name|command
block|{
name|short
name|t_dtyp
decl_stmt|;
comment|/* Type of node 		 */
define|#
directive|define
name|NODE_COMMAND
value|1
comment|/* t_dcom<t_dlef>t_drit	 */
define|#
directive|define
name|NODE_PAREN
value|2
comment|/* ( t_dspr )<t_dlef>t_drit	 */
define|#
directive|define
name|NODE_PIPE
value|3
comment|/* t_dlef | t_drit		 */
define|#
directive|define
name|NODE_LIST
value|4
comment|/* t_dlef ; t_drit		 */
define|#
directive|define
name|NODE_OR
value|5
comment|/* t_dlef || t_drit		 */
define|#
directive|define
name|NODE_AND
value|6
comment|/* t_dlef&& t_drit		 */
name|short
name|t_dflg
decl_stmt|;
comment|/* Flags, e.g. F_AMPERSAND|... 	 */
define|#
directive|define
name|F_SAVE
value|(F_NICE|F_TIME|F_NOHUP)
comment|/* save these when re-doing 	 */
define|#
directive|define
name|F_AMPERSAND
value|(1<<0)
comment|/* executes in background	 */
define|#
directive|define
name|F_APPEND
value|(1<<1)
comment|/* output is redirected>>	 */
define|#
directive|define
name|F_PIPEIN
value|(1<<2)
comment|/* input is a pipe		 */
define|#
directive|define
name|F_PIPEOUT
value|(1<<3)
comment|/* output is a pipe		 */
define|#
directive|define
name|F_NOFORK
value|(1<<4)
comment|/* don't fork, last ()ized cmd	 */
define|#
directive|define
name|F_NOINTERRUPT
value|(1<<5)
comment|/* should be immune from intr's */
comment|/* spare */
define|#
directive|define
name|F_STDERR
value|(1<<7)
comment|/* redirect unit 2 with unit 1	 */
define|#
directive|define
name|F_OVERWRITE
value|(1<<8)
comment|/* output was !			 */
define|#
directive|define
name|F_READ
value|(1<<9)
comment|/* input redirection is<<	 */
define|#
directive|define
name|F_REPEAT
value|(1<<10)
comment|/* reexec aft if, repeat,...	 */
define|#
directive|define
name|F_NICE
value|(1<<11)
comment|/* t_nice is meaningful 	 */
define|#
directive|define
name|F_NOHUP
value|(1<<12)
comment|/* nohup this command 		 */
define|#
directive|define
name|F_TIME
value|(1<<13)
comment|/* time this command 		 */
union|union
block|{
name|Char
modifier|*
name|T_dlef
decl_stmt|;
comment|/* Input redirect word 		 */
name|struct
name|command
modifier|*
name|T_dcar
decl_stmt|;
comment|/* Left part of list/pipe 	 */
block|}
name|L
union|;
union|union
block|{
name|Char
modifier|*
name|T_drit
decl_stmt|;
comment|/* Output redirect word 	 */
name|struct
name|command
modifier|*
name|T_dcdr
decl_stmt|;
comment|/* Right part of list/pipe 	 */
block|}
name|R
union|;
define|#
directive|define
name|t_dlef
value|L.T_dlef
define|#
directive|define
name|t_dcar
value|L.T_dcar
define|#
directive|define
name|t_drit
value|R.T_drit
define|#
directive|define
name|t_dcdr
value|R.T_dcdr
name|Char
modifier|*
modifier|*
name|t_dcom
decl_stmt|;
comment|/* Command/argument vector 	 */
name|struct
name|command
modifier|*
name|t_dspr
decl_stmt|;
comment|/* Pointer to ()'d subtree 	 */
name|int
name|t_nice
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are declared here because they want to be  * initialized in sh.init.c (to allow them to be made readonly)  */
end_comment

begin_struct
specifier|extern
struct|struct
name|biltins
block|{
name|char
modifier|*
name|bname
decl_stmt|;
name|void
argument_list|(
argument|*bfunct
argument_list|)
name|__P
argument_list|(
operator|(
name|Char
operator|*
operator|*
operator|,
expr|struct
name|command
operator|*
operator|)
argument_list|)
expr_stmt|;
name|short
name|minargs
decl_stmt|,
name|maxargs
decl_stmt|;
block|}
name|bfunc
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nbfunc
decl_stmt|;
end_decl_stmt

begin_struct
specifier|extern
struct|struct
name|srch
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
name|short
name|s_value
decl_stmt|;
block|}
name|srchn
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|nsrchn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The keywords for the parser  */
end_comment

begin_define
define|#
directive|define
name|T_BREAK
value|0
end_define

begin_define
define|#
directive|define
name|T_BRKSW
value|1
end_define

begin_define
define|#
directive|define
name|T_CASE
value|2
end_define

begin_define
define|#
directive|define
name|T_DEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|T_ELSE
value|4
end_define

begin_define
define|#
directive|define
name|T_END
value|5
end_define

begin_define
define|#
directive|define
name|T_ENDIF
value|6
end_define

begin_define
define|#
directive|define
name|T_ENDSW
value|7
end_define

begin_define
define|#
directive|define
name|T_EXIT
value|8
end_define

begin_define
define|#
directive|define
name|T_FOREACH
value|9
end_define

begin_define
define|#
directive|define
name|T_GOTO
value|10
end_define

begin_define
define|#
directive|define
name|T_IF
value|11
end_define

begin_define
define|#
directive|define
name|T_LABEL
value|12
end_define

begin_define
define|#
directive|define
name|T_LET
value|13
end_define

begin_define
define|#
directive|define
name|T_SET
value|14
end_define

begin_define
define|#
directive|define
name|T_SWITCH
value|15
end_define

begin_define
define|#
directive|define
name|T_TEST
value|16
end_define

begin_define
define|#
directive|define
name|T_THEN
value|17
end_define

begin_define
define|#
directive|define
name|T_WHILE
value|18
end_define

begin_comment
comment|/*  * Structure defining the existing while/foreach loops at this  * source level.  Loops are implemented by seeking back in the  * input.  For foreach (fe), the word list is attached here.  */
end_comment

begin_struct
struct|struct
name|whyle
block|{
name|struct
name|Ain
name|w_start
decl_stmt|;
comment|/* Point to restart loop */
name|struct
name|Ain
name|w_end
decl_stmt|;
comment|/* End of loop (0 if unknown) */
name|Char
modifier|*
modifier|*
name|w_fe
decl_stmt|,
modifier|*
modifier|*
name|w_fe0
decl_stmt|;
comment|/* Current/initial wordlist for fe */
name|Char
modifier|*
name|w_fename
decl_stmt|;
comment|/* Name for fe */
name|struct
name|whyle
modifier|*
name|w_next
decl_stmt|;
comment|/* Next (more outer) loop */
block|}
modifier|*
name|whyles
struct|;
end_struct

begin_comment
comment|/*  * Variable structure  *  * Aliases and variables are stored in AVL balanced binary trees.  */
end_comment

begin_struct
struct|struct
name|varent
block|{
name|Char
modifier|*
modifier|*
name|vec
decl_stmt|;
comment|/* Array of words which is the value */
name|Char
modifier|*
name|v_name
decl_stmt|;
comment|/* Name of variable/alias */
name|struct
name|varent
modifier|*
name|v_link
index|[
literal|3
index|]
decl_stmt|;
comment|/* The links, see below */
name|int
name|v_bal
decl_stmt|;
comment|/* Balance factor */
block|}
name|shvhed
struct|,
name|aliases
struct|;
end_struct

begin_define
define|#
directive|define
name|v_left
value|v_link[0]
end_define

begin_define
define|#
directive|define
name|v_right
value|v_link[1]
end_define

begin_define
define|#
directive|define
name|v_parent
value|v_link[2]
end_define

begin_function_decl
name|struct
name|varent
modifier|*
name|adrof1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|adrof
parameter_list|(
name|v
parameter_list|)
value|adrof1(v,&shvhed)
end_define

begin_define
define|#
directive|define
name|value
parameter_list|(
name|v
parameter_list|)
value|value1(v,&shvhed)
end_define

begin_comment
comment|/*  * The following are for interfacing redo substitution in  * aliases to the lexical routines.  */
end_comment

begin_decl_stmt
name|struct
name|wordent
modifier|*
name|alhistp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Argument list (first) */
end_comment

begin_decl_stmt
name|struct
name|wordent
modifier|*
name|alhistt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Node after last in arg list */
end_comment

begin_decl_stmt
name|Char
modifier|*
modifier|*
name|alvec
decl_stmt|,
modifier|*
name|alvecp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The (remnants of) alias vector */
end_comment

begin_comment
comment|/*  * Filename/command name expansion variables  */
end_comment

begin_decl_stmt
name|int
name|gflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After tglob -> is globbing needed? */
end_comment

begin_define
define|#
directive|define
name|MAXVARLEN
value|30
end_define

begin_comment
comment|/* Maximum number of char in a variable name */
end_comment

begin_comment
comment|/*  * Variables for filename expansion  */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
modifier|*
name|gargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the (stack) arglist */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|gargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number args in gargv */
end_comment

begin_comment
comment|/*  * Variables for command expansion.  */
end_comment

begin_decl_stmt
specifier|extern
name|Char
modifier|*
modifier|*
name|pargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the argv list space */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|pargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of arguments in pargv */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|pargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to start current word */
end_comment

begin_decl_stmt
name|long
name|pnleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of chars left in pargs */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|pargcp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current index into pargs */
end_comment

begin_comment
comment|/*  * History list  *  * Each history list entry contains an embedded wordlist  * from the scanner, a number for the event, and a reference count  * to aid in discarding old entries.  *  * Essentially "invisible" entries are put on the history list  * when history substitution includes modifiers, and thrown away  * at the next discarding since their event numbers are very negative.  */
end_comment

begin_struct
struct|struct
name|Hist
block|{
name|struct
name|wordent
name|Hlex
decl_stmt|;
name|int
name|Hnum
decl_stmt|;
name|int
name|Href
decl_stmt|;
name|struct
name|Hist
modifier|*
name|Hnext
decl_stmt|;
block|}
name|Histlist
struct|;
end_struct

begin_decl_stmt
name|struct
name|wordent
name|paraml
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current lexical word list */
end_comment

begin_decl_stmt
name|int
name|eventno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Next events number */
end_comment

begin_decl_stmt
name|int
name|lastev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last event reference (default) */
end_comment

begin_decl_stmt
name|Char
name|HIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* history invocation character */
end_comment

begin_decl_stmt
name|Char
name|HISTSUB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auto-substitute character */
end_comment

begin_comment
comment|/*  * strings.h:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_STRINGS
end_ifndef

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strrchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strcat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcat(a, b)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncat(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcpy(a, b)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncpy(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|a
parameter_list|)
value|strlen(a)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strcmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|strncmp(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strspl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strspl(a, b)
end_define

begin_define
define|#
directive|define
name|Strsave
parameter_list|(
name|a
parameter_list|)
value|strsave(a)
end_define

begin_define
define|#
directive|define
name|Strend
parameter_list|(
name|a
parameter_list|)
value|strend(a)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|strstr(a, b)
end_define

begin_define
define|#
directive|define
name|str2short
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|blk2short
parameter_list|(
name|a
parameter_list|)
value|saveblk(a)
end_define

begin_define
define|#
directive|define
name|short2blk
parameter_list|(
name|a
parameter_list|)
value|saveblk(a)
end_define

begin_define
define|#
directive|define
name|short2str
parameter_list|(
name|a
parameter_list|)
value|strip(a)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Strchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strrchr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strrchr(a, b)
end_define

begin_define
define|#
directive|define
name|Strcat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcat(a, b)
end_define

begin_define
define|#
directive|define
name|Strncat
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncat(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcpy(a, b)
end_define

begin_define
define|#
directive|define
name|Strncpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncpy(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strlen
parameter_list|(
name|a
parameter_list|)
value|s_strlen(a)
end_define

begin_define
define|#
directive|define
name|Strcmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strcmp(a, b)
end_define

begin_define
define|#
directive|define
name|Strncmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|s_strncmp(a, b, c)
end_define

begin_define
define|#
directive|define
name|Strspl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strspl(a, b)
end_define

begin_define
define|#
directive|define
name|Strsave
parameter_list|(
name|a
parameter_list|)
value|s_strsave(a)
end_define

begin_define
define|#
directive|define
name|Strend
parameter_list|(
name|a
parameter_list|)
value|s_strend(a)
end_define

begin_define
define|#
directive|define
name|Strstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|s_strstr(a, b)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * setname is a macro to save space (see sh.err.c)  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|bname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|setname
parameter_list|(
name|a
parameter_list|)
value|(bname = (a))
end_define

begin_decl_stmt
name|Char
modifier|*
name|Vsav
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Char
modifier|*
name|Vdp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Char
modifier|*
name|Vexpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|Vt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Char
modifier|*
modifier|*
name|evalvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Char
modifier|*
name|evalp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* word_chars is set by default to WORD_CHARS but can be overridden by    the worchars variable--if unset, reverts to WORD_CHARS */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|word_chars
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WORD_CHARS
value|"*?_-.[]~="
end_define

begin_comment
comment|/* default chars besides alnums in words */
end_comment

begin_decl_stmt
name|Char
modifier|*
name|STR_SHELLPATH
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_BSHELL
end_ifdef

begin_decl_stmt
name|Char
modifier|*
name|STR_BSHELL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|Char
modifier|*
name|STR_WORD_CHARS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Char
modifier|*
modifier|*
name|STR_environ
decl_stmt|;
end_decl_stmt

end_unit

