begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)defs.h	5.4 (Berkeley) %G%	*/
end_comment

begin_comment
comment|/*  * adb: common definitions  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_comment
comment|/* machine dependent types and definitions */
end_comment

begin_include
include|#
directive|include
file|"machdep.h"
end_include

begin_comment
comment|/*  * Signals.  Adb catches SIGINT and SIGQUIT; the variables sigint and  * sigquit hold the original state for adb's children.  */
end_comment

begin_decl_stmt
name|sig_t
name|sigint
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original SIGINT state */
end_comment

begin_decl_stmt
name|sig_t
name|sigquit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* original SIGQUIT state */
end_comment

begin_decl_stmt
name|sig_t
name|intcatch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupt catch routine, or SIG_IGN */
end_comment

begin_comment
comment|/*  * Address spaces.  We distinguish only between instruction& data.  * The spaces NONE, INSTR, and DATA (without the STAR flag) are also used  * to tag symbols.  */
end_comment

begin_define
define|#
directive|define
name|SP_NONE
value|0
end_define

begin_comment
comment|/* not in any space, just a number */
end_comment

begin_define
define|#
directive|define
name|SP_INSTR
value|1
end_define

begin_comment
comment|/* instruction space */
end_comment

begin_define
define|#
directive|define
name|SP_DATA
value|2
end_define

begin_comment
comment|/* data space */
end_comment

begin_define
define|#
directive|define
name|SP_STAR
value|4
end_define

begin_comment
comment|/* or'ed in; see below */
end_comment

begin_comment
comment|/*  * The symbol and core files.  */
end_comment

begin_struct
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* file name */
name|int
name|fd
decl_stmt|;
comment|/* and descriptor */
block|}
name|symfile
struct|,
name|corefile
struct|;
end_struct

begin_comment
comment|/*  * File address maps.  */
end_comment

begin_struct
struct|struct
name|m1
block|{
name|addr_t
name|b
decl_stmt|;
comment|/* begins at b */
name|addr_t
name|e
decl_stmt|;
comment|/* ends at e */
name|addr_t
name|f
decl_stmt|;
comment|/* with offset f */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|map
block|{
name|struct
name|m1
name|m1
decl_stmt|;
comment|/* regular map */
name|struct
name|m1
name|m2
decl_stmt|;
comment|/* `star' (alternate) map */
name|int
name|ufd
decl_stmt|;
comment|/* unix file descriptor */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|map
name|txtmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the `?' or text file */
end_comment

begin_decl_stmt
name|struct
name|map
name|datmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the `/' or data/core file */
end_comment

begin_comment
comment|/*  * Program and file I/O.  */
end_comment

begin_enum
enum|enum
name|rwmode
block|{
name|RWMODE_READ
block|,
name|RWMODE_WRITE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|adbread
parameter_list|(
name|space
parameter_list|,
name|rmtaddr
parameter_list|,
name|localaddr
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|adbio(RWMODE_READ, space, rmtaddr, (caddr_t)(localaddr), nbytes)
end_define

begin_define
define|#
directive|define
name|adbwrite
parameter_list|(
name|space
parameter_list|,
name|rmtaddr
parameter_list|,
name|localaddr
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|adbio(RWMODE_WRITE, space, rmtaddr, (caddr_t)(localaddr), nbytes)
end_define

begin_function_decl
name|addr_t
name|vtophys
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* -k: kernel virtual addr to physical */
end_comment

begin_comment
comment|/*  * Errors.  errflag should be set to point to the error message when  * an error occurs.  error(s) sets errflag to s and jumps back  * to the main loop via longjmp().  In some places this is unsafe  * or undesirable, and instead errflag is set directly; checkerr()  * can be used to test (and jump on) for such errors later.  *  * mkfault creates a `generic' error after a keyboard interrupt.  *  * Various error strings are defined in message.c and referenced  * through names below.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|errflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the error, or NULL */
end_comment

begin_decl_stmt
name|int
name|mkfault
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interrupted; pretend an error */
end_comment

begin_define
define|#
directive|define
name|iserr
parameter_list|()
value|(errflag || mkfault)
end_define

begin_define
define|#
directive|define
name|checkerr
parameter_list|()
define|\
value|if (!iserr()) \
comment|/* void */
value|; \ 	else \ 		error(errflag)
end_define

begin_comment
comment|/* if checkerr() above is undefined, a function version is used instead */
end_comment

begin_comment
comment|/*  * Locations.  *  * HSZ and FSZ are defined here as the sizes of `half' and `full' words  * respectively.  While these are not `locations', they are commonly used  * to set the value of dotinc.  */
end_comment

begin_decl_stmt
name|int
name|gavedot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true iff this command set dot */
end_comment

begin_decl_stmt
name|addr_t
name|dot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current location; but see also edot */
end_comment

begin_decl_stmt
name|addr_t
name|ditto
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous dot */
end_comment

begin_decl_stmt
name|int
name|dotinc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of last object examined */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ADDRWRAP
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* "address wrap around" */
end_comment

begin_comment
comment|/* compute dot+offset, checking for overflow */
end_comment

begin_define
define|#
directive|define
name|inkdot
parameter_list|(
name|o
parameter_list|)
value|(ADDRESS_WRAP(dot, dot+(o)) ? error(ADDRWRAP), 0 : dot+(o))
end_define

begin_comment
comment|/* if inkdot() above is undefined, a function version is used instead */
end_comment

begin_comment
comment|/*  * Expressions.  *  * oexpr() evaluates an optional expression; rexpr() does a required  * expression, and returns expv as a convenience.  *  * N.B.: edot is valid only if gavedot.  */
end_comment

begin_function_decl
name|int
name|oexpr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* returns 1 if found expr, else 0 */
end_comment

begin_function_decl
name|expr_t
name|rexpr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* aborts if no expression found */
end_comment

begin_decl_stmt
name|expr_t
name|edot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dot as an expression (possibly more bits) */
end_comment

begin_decl_stmt
name|int
name|gavecount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true iff this command gave a count */
end_comment

begin_decl_stmt
name|expr_t
name|ecount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* repeat count from addr,count format */
end_comment

begin_decl_stmt
name|expr_t
name|expv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* value from last expression */
end_comment

begin_decl_stmt
name|expr_t
name|var
index|[
literal|36
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adb's 36 variables (0..9 then a..z) */
end_comment

begin_comment
comment|/*  * Input.  *  * The global lp points to the current input line.  The routine  * readchar() picks up the next character, incrementing lp, but  * can read more if appropriate.  lastc retains the most recently  * read character.  unreadc() in effect `puts back' lastc.  rdc()  * is like readchar() but skips white space.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|lp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer into current line */
end_comment

begin_decl_stmt
name|int
name|lastc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character most recently read */
end_comment

begin_function_decl
name|int
name|readchar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the next char */
end_comment

begin_function_decl
name|int
name|rdc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get the next nonblank char */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|unreadc
parameter_list|()
value|(lastc ? lp-- : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unreadc
parameter_list|()
value|(lp--)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|readchar
parameter_list|()
value|(((lastc = *lp) == 0 ? 0 : lp++), lastc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if readchar() above is undefined, a function version is used instead */
end_comment

begin_define
define|#
directive|define
name|eol
parameter_list|(
name|c
parameter_list|)
value|((c) == '\n' || (c) == ';')
end_define

begin_comment
comment|/*  * Miscellaneous globals, functions, and macros.  */
end_comment

begin_decl_stmt
name|int
name|kernel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging kernel (-k flag) */
end_comment

begin_decl_stmt
name|int
name|kcore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* have a post-mortem dump (-k + core) */
end_comment

begin_decl_stmt
name|int
name|wtflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* adb => 0, adb -w => 2 */
end_comment

begin_decl_stmt
name|int
name|radix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current radix (input and %r/%R formats) */
end_comment

begin_decl_stmt
name|int
name|pid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process id being debugged, or 0 */
end_comment

begin_decl_stmt
name|int
name|signo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* signal that stopped process pid */
end_comment

begin_decl_stmt
name|int
name|sigcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extension info (machine dependent) */
end_comment

begin_decl_stmt
name|addr_t
name|maxoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max offset for symbol match ($s) */
end_comment

begin_define
define|#
directive|define
name|MAXOFF
value|1024
end_define

begin_comment
comment|/* default value */
end_comment

begin_decl_stmt
name|int
name|maxcol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max output column ($w) */
end_comment

begin_define
define|#
directive|define
name|MAXCOL
value|80
end_define

begin_comment
comment|/* default value */
end_comment

begin_define
define|#
directive|define
name|LINELEN
value|1024
end_define

begin_comment
comment|/* max input line length */
end_comment

begin_define
define|#
directive|define
name|SYMLEN
value|1024
end_define

begin_comment
comment|/* max symbol length */
end_comment

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our old friend */
end_comment

begin_comment
comment|/*  * checkfloat() returns an error string if a float or double is  * some sort of reserved bit pattern, such that trying to print it  * would cause a fault.  It is called with the address of the  * float or double, and a 0 or 1 to indicate float and double  * respectively.  checkfloat() returns NULL if the number is printable.  */
end_comment

begin_function_decl
name|char
modifier|*
name|checkfloat
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* check a float or double for correctness */
end_comment

begin_function_decl
name|struct
name|reglist
modifier|*
name|reglookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find a register by name */
end_comment

begin_function_decl
name|struct
name|nlist
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look up a symbol */
end_comment

begin_function_decl
name|struct
name|nlist
modifier|*
name|findsym
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* like lookup, but allows an offset */
end_comment

begin_function_decl
name|struct
name|nlist
modifier|*
name|nextlocal
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* given a sym, return the next local sym */
end_comment

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|symtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* symbol table */
end_comment

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|esymtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of symtab */
end_comment

begin_function_decl
name|expr_t
name|getreg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* returns the value in a register */
end_comment

begin_function_decl
name|addr_t
name|eval_localsym
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compute the address of a local symbol */
end_comment

begin_comment
comment|/*  * eqstr(a, b) is true iff the given strings compare equal.  * eqsym(a, b, c) is true if symbols a and b match, but allowing  * the `a' symbol to begin with the character `c'.  */
end_comment

begin_define
define|#
directive|define
name|eqstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(*(a) == *(b)&& strcmp(a, b) == 0)
end_define

begin_define
define|#
directive|define
name|eqsym
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|(eqstr(a, b) || *(a) == (c)&& eqstr((a) + 1, b))
end_define

begin_comment
comment|/*  * The user structure.  */
end_comment

begin_union
union|union
block|{
name|struct
name|user
name|user
decl_stmt|;
comment|/* the actual user struct */
name|char
name|upages
index|[
name|ctob
argument_list|(
name|UPAGES
argument_list|)
index|]
decl_stmt|;
comment|/* u. + kernel stack */
block|}
name|uu
union|;
end_union

begin_define
define|#
directive|define
name|u
value|uu.user
end_define

end_unit

