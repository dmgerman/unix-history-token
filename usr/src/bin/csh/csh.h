begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley Software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)csh.h	5.5 (Berkeley) %G%  */
end_comment

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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|"sh.local.h"
end_include

begin_include
include|#
directive|include
file|"sh.char.h"
end_include

begin_comment
comment|/*  * C shell  *  * Bill Joy, UC Berkeley  * October, 1978; May 1980  *  * Jim Kulp, IIASA, Laxenburg Austria  * April, 1980  */
end_comment

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
name|char
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
value|(strcmp(a, b) == 0)
end_define

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
name|char
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
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of shell file for $0 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|err
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error message from scanner/parser */
end_comment

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error from C library routines */
end_comment

begin_decl_stmt
name|char
modifier|*
name|shtemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temp name for<< shell files in /tmp */
end_comment

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
name|char
modifier|*
name|doldol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character pid for $$ */
end_comment

begin_decl_stmt
name|int
name|uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Invokers uid */
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
comment|/*  * These are declared here because they want to be  * initialized in sh.init.c (to allow them to be made readonly)  */
end_comment

begin_struct
struct|struct
name|biltins
block|{
name|char
modifier|*
name|bname
decl_stmt|;
name|int
function_decl|(
modifier|*
name|bfunct
function_decl|)
parameter_list|()
function_decl|;
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
comment|/*  * To be able to redirect i/o for builtins easily, the shell moves the i/o  * descriptors it uses away from 0,1,2.  * Ideally these should be in units which are closed across exec's  * (this saves work) but for version 6, this is not usually possible.  * The desired initial values for these descriptors are defined in  * sh.local.h.  */
end_comment

begin_decl_stmt
name|short
name|SHIN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current shell input (script) */
end_comment

begin_decl_stmt
name|short
name|SHOUT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Shell output */
end_comment

begin_decl_stmt
name|short
name|SHDIAG
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Diagnostic output... shell errs go here */
end_comment

begin_decl_stmt
name|short
name|OLDSTD
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Old standard input (def for cmds) */
end_comment

begin_comment
comment|/*  * Error control  *  * Errors in scanning and parsing set up an error message to be printed  * at the end and complete.  Other errors always cause a reset.  * Because of source commands and .cshrc we need nested error catches.  */
end_comment

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
value|((void) setjmp(reslab))
end_define

begin_define
define|#
directive|define
name|reset
parameter_list|()
value|longjmp(reslab, 0)
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
value|copy((char *)(a), (char *)reslab, sizeof reslab)
end_define

begin_define
define|#
directive|define
name|resexit
parameter_list|(
name|a
parameter_list|)
value|copy((char *)reslab, ((char *)(a)), sizeof reslab)
end_define

begin_decl_stmt
name|char
modifier|*
name|gointr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Label for an onintr transfer */
end_comment

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
comment|/*  * Lexical definitions.  *  * All lexical space is allocated dynamically.  * The eighth bit of characters is used to prevent recognition,  * and eventually stripped.  */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_comment
comment|/* Eighth char bit used internally for 'ing */
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
name|short
name|Bfblocks
decl_stmt|;
comment|/* Number of buffer blocks */
name|char
modifier|*
modifier|*
name|Bfbuf
decl_stmt|;
comment|/* The array of buffer blocks */
block|}
name|B
struct|;
end_struct

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

begin_define
define|#
directive|define
name|btell
parameter_list|()
value|fseekp
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|btell
end_ifndef

begin_function_decl
name|off_t
name|btell
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The shell finds commands in loops by reseeking the input  * For whiles, in particular, it reseeks to the beginning of the  * line the while was on; hence the while placement restrictions.  */
end_comment

begin_decl_stmt
name|off_t
name|lineloc
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TELL
end_ifdef

begin_decl_stmt
name|bool
name|cantell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is current source tellable ? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Input lines are parsed into doubly linked circular  * lists of words of the following form.  */
end_comment

begin_struct
struct|struct
name|wordent
block|{
name|char
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
name|char
name|labuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
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
comment|/* Type of node */
name|short
name|t_dflg
decl_stmt|;
comment|/* Flags, e.g. FAND|... */
union|union
block|{
name|char
modifier|*
name|T_dlef
decl_stmt|;
comment|/* Input redirect word */
name|struct
name|command
modifier|*
name|T_dcar
decl_stmt|;
comment|/* Left part of list/pipe */
block|}
name|L
union|;
union|union
block|{
name|char
modifier|*
name|T_drit
decl_stmt|;
comment|/* Output redirect word */
name|struct
name|command
modifier|*
name|T_dcdr
decl_stmt|;
comment|/* Right part of list/pipe */
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
name|char
modifier|*
modifier|*
name|t_dcom
decl_stmt|;
comment|/* Command/argument vector */
name|struct
name|command
modifier|*
name|t_dspr
decl_stmt|;
comment|/* Pointer to ()'d subtree */
name|short
name|t_nice
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TCOM
value|1
end_define

begin_comment
comment|/* t_dcom<t_dlef>t_drit	*/
end_comment

begin_define
define|#
directive|define
name|TPAR
value|2
end_define

begin_comment
comment|/* ( t_dspr )<t_dlef>t_drit	*/
end_comment

begin_define
define|#
directive|define
name|TFIL
value|3
end_define

begin_comment
comment|/* t_dlef | t_drit		*/
end_comment

begin_define
define|#
directive|define
name|TLST
value|4
end_define

begin_comment
comment|/* t_dlef ; t_drit		*/
end_comment

begin_define
define|#
directive|define
name|TOR
value|5
end_define

begin_comment
comment|/* t_dlef || t_drit		*/
end_comment

begin_define
define|#
directive|define
name|TAND
value|6
end_define

begin_comment
comment|/* t_dlef&& t_drit		*/
end_comment

begin_define
define|#
directive|define
name|FSAVE
value|(FNICE|FTIME|FNOHUP)
end_define

begin_comment
comment|/* save these when re-doing */
end_comment

begin_define
define|#
directive|define
name|FAND
value|(1<<0)
end_define

begin_comment
comment|/* executes in background	*/
end_comment

begin_define
define|#
directive|define
name|FCAT
value|(1<<1)
end_define

begin_comment
comment|/* output is redirected>>	*/
end_comment

begin_define
define|#
directive|define
name|FPIN
value|(1<<2)
end_define

begin_comment
comment|/* input is a pipe		*/
end_comment

begin_define
define|#
directive|define
name|FPOU
value|(1<<3)
end_define

begin_comment
comment|/* output is a pipe		*/
end_comment

begin_define
define|#
directive|define
name|FPAR
value|(1<<4)
end_define

begin_comment
comment|/* don't fork, last ()ized cmd	*/
end_comment

begin_define
define|#
directive|define
name|FINT
value|(1<<5)
end_define

begin_comment
comment|/* should be immune from intr's */
end_comment

begin_comment
comment|/* spare */
end_comment

begin_define
define|#
directive|define
name|FDIAG
value|(1<<7)
end_define

begin_comment
comment|/* redirect unit 2 with unit 1	*/
end_comment

begin_define
define|#
directive|define
name|FANY
value|(1<<8)
end_define

begin_comment
comment|/* output was !			*/
end_comment

begin_define
define|#
directive|define
name|FHERE
value|(1<<9)
end_define

begin_comment
comment|/* input redirection is<<	*/
end_comment

begin_define
define|#
directive|define
name|FREDO
value|(1<<10)
end_define

begin_comment
comment|/* reexec aft if, repeat,...	*/
end_comment

begin_define
define|#
directive|define
name|FNICE
value|(1<<11)
end_define

begin_comment
comment|/* t_nice is meaningful */
end_comment

begin_define
define|#
directive|define
name|FNOHUP
value|(1<<12)
end_define

begin_comment
comment|/* nohup this command */
end_comment

begin_define
define|#
directive|define
name|FTIME
value|(1<<13)
end_define

begin_comment
comment|/* time this command */
end_comment

begin_comment
comment|/*  * The keywords for the parser  */
end_comment

begin_define
define|#
directive|define
name|ZBREAK
value|0
end_define

begin_define
define|#
directive|define
name|ZBRKSW
value|1
end_define

begin_define
define|#
directive|define
name|ZCASE
value|2
end_define

begin_define
define|#
directive|define
name|ZDEFAULT
value|3
end_define

begin_define
define|#
directive|define
name|ZELSE
value|4
end_define

begin_define
define|#
directive|define
name|ZEND
value|5
end_define

begin_define
define|#
directive|define
name|ZENDIF
value|6
end_define

begin_define
define|#
directive|define
name|ZENDSW
value|7
end_define

begin_define
define|#
directive|define
name|ZEXIT
value|8
end_define

begin_define
define|#
directive|define
name|ZFOREACH
value|9
end_define

begin_define
define|#
directive|define
name|ZGOTO
value|10
end_define

begin_define
define|#
directive|define
name|ZIF
value|11
end_define

begin_define
define|#
directive|define
name|ZLABEL
value|12
end_define

begin_define
define|#
directive|define
name|ZLET
value|13
end_define

begin_define
define|#
directive|define
name|ZSET
value|14
end_define

begin_define
define|#
directive|define
name|ZSWITCH
value|15
end_define

begin_define
define|#
directive|define
name|ZTEST
value|16
end_define

begin_define
define|#
directive|define
name|ZTHEN
value|17
end_define

begin_define
define|#
directive|define
name|ZWHILE
value|18
end_define

begin_comment
comment|/*  * Structure defining the existing while/foreach loops at this  * source level.  Loops are implemented by seeking back in the  * input.  For foreach (fe), the word list is attached here.  */
end_comment

begin_struct
struct|struct
name|whyle
block|{
name|off_t
name|w_start
decl_stmt|;
comment|/* Point to restart loop */
name|off_t
name|w_end
decl_stmt|;
comment|/* End of loop (0 if unknown) */
name|char
modifier|*
modifier|*
name|w_fe
decl_stmt|,
modifier|*
modifier|*
name|w_fe0
decl_stmt|;
comment|/* Current/initial wordlist for fe */
name|char
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
name|char
modifier|*
modifier|*
name|vec
decl_stmt|;
comment|/* Array of words which is the value */
name|char
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
name|char
modifier|*
modifier|*
name|alvec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The (remnants of) alias vector */
end_comment

begin_comment
comment|/*  * Filename/command name expansion variables  */
end_comment

begin_decl_stmt
name|short
name|gflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* After tglob -> is globbing needed? */
end_comment

begin_comment
comment|/*  * A reasonable limit on number of arguments would seem to be  * the maximum number of characters in an arg list / 6.  */
end_comment

begin_define
define|#
directive|define
name|GAVSIZ
value|NCARGS / 6
end_define

begin_comment
comment|/*  * Variables for filename expansion  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|gargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the (stack) arglist */
end_comment

begin_decl_stmt
name|short
name|gargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number args in gargv */
end_comment

begin_decl_stmt
name|short
name|gnleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Variables for command expansion.  */
end_comment

begin_decl_stmt
name|char
modifier|*
modifier|*
name|pargv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the argv list space */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to start current word */
end_comment

begin_decl_stmt
name|short
name|pargc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count of arguments in pargv */
end_comment

begin_decl_stmt
name|short
name|pnleft
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of chars left in pargs */
end_comment

begin_decl_stmt
name|char
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
name|char
name|HIST
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* history invocation character */
end_comment

begin_decl_stmt
name|char
name|HISTSUB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* auto-substitute character */
end_comment

begin_comment
comment|/*  * In lines for frequently called functions  */
end_comment

begin_define
define|#
directive|define
name|XFREE
parameter_list|(
name|cp
parameter_list|)
value|{ \ 	extern char end[]; \ 	char stack; \ 	if ((cp)>= end&& (cp)<&stack) \ 		free(cp); \ }
end_define

begin_decl_stmt
name|char
modifier|*
name|alloctmp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|xalloc
parameter_list|(
name|i
parameter_list|)
value|((alloctmp = malloc(i)) ? alloctmp : (char *)nomem(i))
end_define

begin_function_decl
name|char
modifier|*
name|Dfix1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|blkcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|blkcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|blkend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|blkspl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|copyblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|dobackp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|domod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wordent
modifier|*
name|dosub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exp3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exp3a
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exp4
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exp5
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exp6
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|Hist
modifier|*
name|enthist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|Hist
modifier|*
name|findev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wordent
modifier|*
name|freenod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getinx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|varent
modifier|*
name|getvx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wordent
modifier|*
name|gethent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|wordent
modifier|*
name|getsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|glob
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|globone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|index
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|biltins
modifier|*
name|isbfunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|operate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|phup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pintr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pchild
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|putn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rindex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|saveblk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strings
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strip
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strspl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|subword
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syntax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn0
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn1a
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn1b
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|command
modifier|*
name|syn3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|value1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xhome
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|xset
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NOSTR
value|((char *) 0)
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|VFORK
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|Vsav
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|Vav
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Vdp
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
name|evalvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|evalp
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|mesg
block|{
name|char
modifier|*
name|iname
decl_stmt|;
comment|/* name from /usr/include */
name|char
modifier|*
name|pname
decl_stmt|;
comment|/* print name */
block|}
name|mesg
index|[]
struct|;
end_struct

end_unit

