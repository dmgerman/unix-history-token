begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_define
define|#
directive|define
name|readonly
end_define

begin_define
define|#
directive|define
name|NINST
value|300
end_define

begin_define
define|#
directive|define
name|NSYM
value|4000
end_define

begin_define
define|#
directive|define
name|NHASH
value|(NSYM+1)
end_define

begin_define
define|#
directive|define
name|NLOC
value|4
end_define

begin_comment
comment|/* number of location ctrs */
end_comment

begin_define
define|#
directive|define
name|NCPS
value|8
end_define

begin_comment
comment|/* number of characters per symbol, fixed */
end_comment

begin_comment
comment|/*  * Symbol types  */
end_comment

begin_define
define|#
directive|define
name|XUNDEF
value|0x0
end_define

begin_define
define|#
directive|define
name|XABS
value|0x2
end_define

begin_define
define|#
directive|define
name|XTEXT
value|0x4
end_define

begin_define
define|#
directive|define
name|XDATA
value|0x6
end_define

begin_define
define|#
directive|define
name|XBSS
value|0x8
end_define

begin_define
define|#
directive|define
name|XDATAO
value|0xA
end_define

begin_define
define|#
directive|define
name|XBSSO
value|0xC
end_define

begin_define
define|#
directive|define
name|XTEXTO
value|0xE
end_define

begin_define
define|#
directive|define
name|XABSO
value|0x10
end_define

begin_define
define|#
directive|define
name|XUNDEFO
value|0x12
end_define

begin_define
define|#
directive|define
name|XTXRN
value|0xA
end_define

begin_comment
comment|/* external symbol */
end_comment

begin_define
define|#
directive|define
name|XXTRN
value|0x1
end_define

begin_define
define|#
directive|define
name|XTYPE
value|0x1E
end_define

begin_define
define|#
directive|define
name|XFORW
value|0x20
end_define

begin_comment
comment|/* Was forward-referenced when undefined */
end_comment

begin_define
define|#
directive|define
name|ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|NBPW
value|32
end_define

begin_comment
comment|/* Bits per word */
end_comment

begin_define
define|#
directive|define
name|AMASK
value|017
end_define

begin_comment
comment|/*  * Actual argument syntax types  */
end_comment

begin_define
define|#
directive|define
name|AREG
value|1
end_define

begin_comment
comment|/* %r */
end_comment

begin_define
define|#
directive|define
name|ABASE
value|2
end_define

begin_comment
comment|/* (%r) */
end_comment

begin_define
define|#
directive|define
name|ADECR
value|3
end_define

begin_comment
comment|/* -(%r) */
end_comment

begin_define
define|#
directive|define
name|AINCR
value|4
end_define

begin_comment
comment|/* (%r)+ */
end_comment

begin_define
define|#
directive|define
name|ADISP
value|5
end_define

begin_comment
comment|/* expr(%r) */
end_comment

begin_define
define|#
directive|define
name|AEXP
value|6
end_define

begin_comment
comment|/* expr */
end_comment

begin_define
define|#
directive|define
name|AIMM
value|7
end_define

begin_comment
comment|/* $ expr */
end_comment

begin_define
define|#
directive|define
name|ASTAR
value|8
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|AINDX
value|16
end_define

begin_comment
comment|/* [%r] */
end_comment

begin_comment
comment|/*  * Argument access types used to test validity of operands to operators  */
end_comment

begin_define
define|#
directive|define
name|ACCA
value|(8<<3)
end_define

begin_comment
comment|/* address only */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|(1<<3)
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ACCW
value|(2<<3)
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ACCM
value|(3<<3)
end_define

begin_comment
comment|/* modify */
end_comment

begin_define
define|#
directive|define
name|ACCB
value|(4<<3)
end_define

begin_comment
comment|/* branch displacement */
end_comment

begin_define
define|#
directive|define
name|ACCI
value|(5<<3)
end_define

begin_comment
comment|/* XFC code */
end_comment

begin_comment
comment|/*  * Argument data types  */
end_comment

begin_define
define|#
directive|define
name|TYPB
value|0
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|TYPW
value|1
end_define

begin_comment
comment|/* word */
end_comment

begin_define
define|#
directive|define
name|TYPL
value|2
end_define

begin_comment
comment|/* long */
end_comment

begin_define
define|#
directive|define
name|TYPQ
value|3
end_define

begin_comment
comment|/* quad */
end_comment

begin_define
define|#
directive|define
name|TYPF
value|4
end_define

begin_comment
comment|/* floating */
end_comment

begin_define
define|#
directive|define
name|TYPD
value|5
end_define

begin_comment
comment|/* double floating */
end_comment

begin_define
define|#
directive|define
name|TYPMASK
value|7
end_define

begin_comment
comment|/* reference types for loader */
end_comment

begin_define
define|#
directive|define
name|PCREL
value|1
end_define

begin_define
define|#
directive|define
name|LEN1
value|2
end_define

begin_define
define|#
directive|define
name|LEN2
value|4
end_define

begin_define
define|#
directive|define
name|LEN4
value|6
end_define

begin_define
define|#
directive|define
name|LEN8
value|8
end_define

begin_define
define|#
directive|define
name|TMPC
value|7
end_define

begin_comment
comment|/* offset into the string /tmp/aaaXXX for creating tmp file names*/
end_comment

begin_define
define|#
directive|define
name|HW
value|01
end_define

begin_define
define|#
directive|define
name|FW
value|03
end_define

begin_define
define|#
directive|define
name|DW
value|07
end_define

begin_include
include|#
directive|include
file|<pagsiz.h>
end_include

begin_define
define|#
directive|define
name|round
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+(y))& ~(y))
end_define

begin_define
define|#
directive|define
name|STABTYPS
value|0340
end_define

begin_define
define|#
directive|define
name|STABFLAG
value|0200
end_define

begin_comment
comment|/*  *	Follows are the definitions for the symbol table tags, which are  *	all unsigned characters..  *	High value tags are generated by the asembler for internal  *	use.  *	Low valued tags are the parser coded tokens the scanner returns.  *	There are several pertinant bounds in this ordering:  *		a)	Symbols greater than JXQUESTIONABLE  *			are used by the jxxx bumper, indicating that  *			the symbol table entry is a jxxx entry  *			that has yet to be bumped.  *		b)	Symbols greater than IGNOREBOUND are not  *			bequeathed to the loader; they are truly  *			for assembler internal use only.  *		c)	Symbols greater than OKTOBUMP represent  *			indices into the program text that should  *			be changed in preceeding jumps or aligns  *			must get turned into their long form.  */
end_comment

begin_define
define|#
directive|define
name|TAGMASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|JXACTIVE
value|0xFF
end_define

begin_comment
comment|/*jxxx instruction size unknown*/
end_comment

begin_define
define|#
directive|define
name|JXNOTYET
value|0xFE
end_define

begin_comment
comment|/*jxxx instruction size known, but not yet expanded*/
end_comment

begin_define
define|#
directive|define
name|JXALIGN
value|0xFD
end_define

begin_comment
comment|/*align jxxx entry*/
end_comment

begin_define
define|#
directive|define
name|JXINACTIVE
value|0xFC
end_define

begin_comment
comment|/*jxxx instruction size known and expanded*/
end_comment

begin_define
define|#
directive|define
name|JXQUESTIONABLE
value|0xFB
end_define

begin_define
define|#
directive|define
name|JXTUNNEL
value|0xFA
end_define

begin_comment
comment|/*jxxx instruction that jumps to another*/
end_comment

begin_define
define|#
directive|define
name|OBSOLETE
value|0xF9
end_define

begin_comment
comment|/*erroneously entered symbol*/
end_comment

begin_define
define|#
directive|define
name|IGNOREBOUND
value|0xF8
end_define

begin_comment
comment|/*symbols greater than this are ignored*/
end_comment

begin_define
define|#
directive|define
name|STABFLOATING
value|0xF7
end_define

begin_define
define|#
directive|define
name|LABELID
value|0xF6
end_define

begin_define
define|#
directive|define
name|OKTOBUMP
value|0xF5
end_define

begin_define
define|#
directive|define
name|STABFIXED
value|0xF4
end_define

begin_comment
comment|/*  *	astoks.h contains reserved word codings the parser should  *	know about  */
end_comment

begin_include
include|#
directive|include
file|"astoks.h"
end_include

begin_comment
comment|/*  *	The structure for one symbol table entry.  *	Symbol table entries are used for both user defined symbols,  *	and symbol slots generated to create the jxxx jump from  *	slots.  */
end_comment

begin_define
define|#
directive|define
name|symfirstfields
value|char	*name;	unsigned char tag, type
end_define

begin_struct
struct|struct
name|symtab
block|{
name|symfirstfields
expr_stmt|;
ifdef|#
directive|ifdef
name|vax
name|short
name|___hole
decl_stmt|;
endif|#
directive|endif
comment|/*save*/
name|char
name|ptype
decl_stmt|;
comment|/*tag == NAME*/
define|#
directive|define
name|jxbump
value|ptype
comment|/*tag == JX..., how far to expand*/
comment|/*save*/
name|char
name|other
decl_stmt|;
comment|/*for stab info*/
comment|/*save*/
name|short
name|desc
decl_stmt|;
comment|/*tag == NAME*/
define|#
directive|define
name|jxfear
value|desc
comment|/*how far needs to be bumped*/
comment|/*save*/
name|long
name|value
decl_stmt|;
comment|/*address in the segment*/
name|char
name|jxoveralign
decl_stmt|;
comment|/*if a JXXX, jumped over an align*/
name|short
name|index
decl_stmt|;
comment|/*which segment*/
name|struct
name|symtab
modifier|*
name|dest
decl_stmt|;
comment|/*if JXXX, where going to*/
ifdef|#
directive|ifdef
name|DJXXX
name|short
name|jxline
decl_stmt|;
comment|/*source line of the jump from*/
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|instab
block|{
name|symfirstfields
expr_stmt|;
define|#
directive|define
name|opcode
value|type
comment|/*use the same field as symtab.type*/
name|char
name|nargs
decl_stmt|;
comment|/*how many arguments*/
name|char
name|argtype
index|[
literal|6
index|]
decl_stmt|;
comment|/*argument type info*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arg
block|{
comment|/*one argument to an instruction*/
name|char
name|atype
decl_stmt|;
name|char
name|areg1
decl_stmt|;
name|char
name|areg2
decl_stmt|;
name|char
name|dispsize
decl_stmt|;
comment|/*usually d124, unless have B^, etc*/
name|struct
name|exp
modifier|*
name|xp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|exp
block|{
name|char
name|xtype
decl_stmt|;
name|char
name|xloc
decl_stmt|;
name|long
name|xvalue
decl_stmt|;
name|struct
name|symtab
modifier|*
name|xname
decl_stmt|;
union|union
block|{
name|double
name|dvalue
decl_stmt|;
struct|struct
block|{
name|unsigned
name|int
name|doub_MSW
decl_stmt|,
name|doub_LSW
decl_stmt|;
block|}
name|dis_dvalue
struct|;
block|}
name|doubval
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Magic layout macros  */
end_comment

begin_define
define|#
directive|define
name|MINBYTE
value|-128
end_define

begin_define
define|#
directive|define
name|MAXBYTE
value|127
end_define

begin_define
define|#
directive|define
name|MINWORD
value|-32768
end_define

begin_define
define|#
directive|define
name|MAXWORD
value|32767
end_define

begin_define
define|#
directive|define
name|LITFLTMASK
value|0x000043F0
end_define

begin_comment
comment|/*really magic*/
end_comment

begin_comment
comment|/*  *		Is the floating point double word in xp a  *		short literal floating point number?  */
end_comment

begin_define
define|#
directive|define
name|slitflt
parameter_list|(
name|xp
parameter_list|)
define|\
value|(    (xp->doubval.dis_dvalue.doub_LSW == 0) \&& ((xp->doubval.dis_dvalue.doub_MSW& LITFLTMASK) \ 			   == xp->doubval.dis_dvalue.doub_MSW) )
end_define

begin_define
define|#
directive|define
name|extlitflt
parameter_list|(
name|xp
parameter_list|)
define|\
value|xp->doubval.dis_dvalue.doub_MSW>> 4
end_define

begin_comment
comment|/*  *	Structure that appears at the head of a.out  */
end_comment

begin_struct
struct|struct
name|hdr
block|{
name|long
name|magic
decl_stmt|;
name|long
name|tsize
decl_stmt|;
name|long
name|dsize
decl_stmt|;
name|long
name|bsize
decl_stmt|;
name|long
name|ssize
decl_stmt|;
name|long
name|entry
decl_stmt|;
name|long
name|trsize
decl_stmt|;
name|long
name|drsize
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|arg
name|arglist
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*building operands in instructions*/
end_comment

begin_decl_stmt
name|struct
name|exp
name|explist
index|[
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*building up a list of expressions*/
end_comment

begin_comment
comment|/* 	 *	Communication between the scanner and the jxxx handlers. 	 *	lastnam:	the last name seen on the input 	 *	lastjxxx:	pointer to the last symbol table entry for 	 *			a jump from 	 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lastnam
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|lastjxxx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	 *	For each of the named .text .data segments 	 *	(introduced by .text<expr>), we maintain 	 *	the current value of the dot, and the Files where 	 *	the information for each of the segments is salted 	 *	away. 	 * 	 *	Use of rulesfile and usefile is unclear 	 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exp
name|usedot
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|usefile
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|rusefile
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	 *	Strings used to construct the temporary files 	 *	for each of the named segments in pass 2. 	 */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpn2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /tmp/aaaXXXX */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tmpn3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* /tmp/aabXXX */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exp
modifier|*
name|dotp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the current dot location*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|loctr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total text size */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|dsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total data size */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|datbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base of the data segment */
end_comment

begin_comment
comment|/* 	 *	Bitoff and bitfield keep track of the packing into  	 *	bytes mandated by the expression syntax<expr> ':'<expr> 	 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bitoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|bitfield
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	 *	The lexical analyzer builds up symbols in yytext.  Lookup 	 *	expects its argument in this buffer 	 */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|yytext
index|[
name|NCPS
operator|+
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* text buffer for lexical */
end_comment

begin_comment
comment|/* 	 *	Variables to manage the input assembler source file 	 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the line number*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dotsname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the name of the as source*/
end_comment

begin_comment
comment|/*extern FILE	stdin*;*/
end_comment

begin_comment
comment|/*the as source input*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|txtfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file for text*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|tmpfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* interpass communication*/
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|relfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds relocation informtion*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|passno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 or 2 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|anyerrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*errors assembling arguments*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|silent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*don't mention the errors*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|savelabels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*save labels in a.out*/
end_comment

begin_decl_stmt
name|int
name|orgwarn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* questionable origin ? */
end_comment

begin_decl_stmt
name|int
name|useVM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*use virtual memory temp file*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|toktrace
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 *	Information about the instructions 	 */
end_comment

begin_decl_stmt
name|struct
name|instab
modifier|*
name|itab
index|[
name|NINST
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*maps opcodes to instructions*/
end_comment

begin_extern
extern|extern  readonly struct instab instab[];
end_extern

begin_decl_stmt
name|int
name|curlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current storage size*/
end_comment

begin_function_decl
name|struct
name|symtab
modifier|*
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*argument in yytext*/
end_comment

begin_function_decl
name|struct
name|symtab
modifier|*
name|symalloc
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|METRIC
end_ifdef

begin_decl_stmt
name|int
name|outcounters
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*should we print them?*/
end_comment

begin_decl_stmt
name|int
name|nhcollision
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nhashed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nentered
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lgtmpfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|jxxxiterate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|jxxxtunnel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*how many tunnel jumps done*/
end_comment

begin_decl_stmt
name|int
name|jxdeadlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nbadjxsegs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|val
parameter_list|)
value|{dotp->xvalue++; if (passno==2) putc((val), txtfil);}
end_define

begin_define
define|#
directive|define
name|outs
parameter_list|(
name|cp
parameter_list|,
name|lg
parameter_list|)
value|dotp->xvalue += (lg); if (passno == 2) fwrite((cp), 1, (lg), txtfil)
end_define

begin_comment
comment|/*  *	Most of the time, the argument to flushfield is a power of two constant,  *	the calculations involving it can be optimized to shifts.  */
end_comment

begin_define
define|#
directive|define
name|flushfield
parameter_list|(
name|n
parameter_list|)
value|if (bitoff != 0)  Flushfield( ( (bitoff+n-1) /n ) * n)
end_define

end_unit

