begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1980 Regents of the University of California */
end_comment

begin_comment
comment|/* "@(#)as.h 4.8 11/5/80" */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|vax
value|1
end_define

begin_define
define|#
directive|define
name|VAX
value|1
end_define

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_else
else|#
directive|else
else|not FLEXNAMES
end_else

begin_define
define|#
directive|define
name|ONLIST
end_define

begin_include
include|#
directive|include
file|"a.out.h"
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_endif
endif|#
directive|endif
endif|FLEXNAMES
end_endif

begin_endif
endif|#
directive|endif
endif|UNIX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|UNIXDEVEL
end_ifdef

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_else
else|#
directive|else
else|not UNIXDEVEL
end_else

begin_include
include|#
directive|include
file|<aout.h>
end_include

begin_endif
endif|#
directive|endif
endif|not UNIXDEVEL
end_endif

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

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
name|NEXP
value|20
end_define

begin_comment
comment|/* max number of expr. terms per instruction */
end_comment

begin_define
define|#
directive|define
name|NARG
value|6
end_define

begin_comment
comment|/* max number of args per instruction */
end_comment

begin_define
define|#
directive|define
name|NHASH
value|1103
end_define

begin_comment
comment|/* hash table is dynamically extended */
end_comment

begin_define
define|#
directive|define
name|TNAMESIZE
value|32
end_define

begin_comment
comment|/* maximum length of temporary file names */
end_comment

begin_define
define|#
directive|define
name|NLOC
value|4
end_define

begin_comment
comment|/* number of location ctrs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NCPS
end_ifndef

begin_define
define|#
directive|define
name|NCPS
value|8
end_define

begin_comment
comment|/* number of characters per symbol*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|NCPS
end_ifdef

begin_undef
undef|#
directive|undef
name|NCPS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NCPS
value|BUFSIZ
end_define

begin_comment
comment|/* needed to allocate yytext */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|UNIX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|NCPS
end_ifdef

begin_undef
undef|#
directive|undef
name|NCPS
end_undef

begin_endif
endif|#
directive|endif
endif|NCPS
end_endif

begin_define
define|#
directive|define
name|NCPS
value|15
end_define

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

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
name|ACCB
value|(4<<3)
end_define

begin_comment
comment|/* branch displacement */
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
name|ACCM
value|(ACCR | ACCW)
end_define

begin_comment
comment|/* modify */
end_comment

begin_define
define|#
directive|define
name|ACCI
value|(ACCB | ACCR)
end_define

begin_comment
comment|/* XFC code */
end_comment

begin_define
define|#
directive|define
name|ACCESSMASK
value|(ACCA | ACCR | ACCW | ACCB)
end_define

begin_comment
comment|/* the mask */
end_comment

begin_comment
comment|/*  *	Argument data types  *	Also used to tell outrel what it is relocating  *	(possibly in combination with RELOC_PCREL and TYPNONE)  */
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
name|TYPNONE
value|6
end_define

begin_comment
comment|/* when nothing */
end_comment

begin_define
define|#
directive|define
name|RELOC_PCREL
value|8
end_define

begin_comment
comment|/* implicit argument to outrel; ==> PCREL */
end_comment

begin_define
define|#
directive|define
name|TYPMASK
value|7
end_define

begin_comment
comment|/*  *	reference types for loader  */
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

begin_decl_stmt
specifier|extern
name|int
name|reflen
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {LEN*+PCREL} ==> number of bytes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lgreflen
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {LEN*+PCREL} ==> lg number of bytes */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|len124
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {1,2,4,8} ==> {LEN1, LEN2, LEN4, LEN8} */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|mod124
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {1,2,4,8} ==> {bits to construct operands */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|type_124
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {1,2,4,8} ==> {TYPB, TYPW, TYPL, TYPQ} */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ty_NORELOC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {TYPB..TYPD} ==> {1 if relocation not OK */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ty_LEN
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {TYPB..TYPD} ==> {LEN1..LEN8} */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ty_nbyte
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {TYPB..TYPD} ==> {1,2,4,8} */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ty_nlg
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* {TYPB..TYPD} ==> lg{1,2,4,8} */
end_comment

begin_define
define|#
directive|define
name|TMPC
value|7
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX
end_ifdef

begin_include
include|#
directive|include
file|<pagsiz.h>
end_include

begin_endif
endif|#
directive|endif
endif|UNIX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|PAGRND
value|0x1FFL
end_define

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

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
comment|/*jxxx size unknown*/
end_comment

begin_define
define|#
directive|define
name|JXNOTYET
value|0xFE
end_define

begin_comment
comment|/*jxxx size known, but not yet expanded*/
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
comment|/*jxxx size known and expanded*/
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
comment|/*jxxx that jumps to another*/
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
comment|/*  *	The structure for one symbol table entry.  *	Symbol table entries are used for both user defined symbols,  *	and symbol slots generated to create the jxxx jump from  *	slots.  *	Caution: the instructions are stored in a shorter version  *	of the struct symtab, using all fields in sym_nm and  *	tag.  The fields used in sym_nm are carefully redeclared  *	in struct Instab and struct instab (see below).  *	If struct nlist gets changed, then Instab and instab may  *	have to be changed.  */
end_comment

begin_struct
struct|struct
name|symtab
block|{
name|struct
name|nlist
name|s_nm
decl_stmt|;
name|u_char
name|s_tag
decl_stmt|;
comment|/* assembler tag */
name|u_char
name|s_ptype
decl_stmt|;
comment|/* if tag == NAME */
name|u_char
name|s_jxoveralign
decl_stmt|;
comment|/* if a JXXX, jumped over align */
name|short
name|s_index
decl_stmt|;
comment|/* which segment */
name|struct
name|symtab
modifier|*
name|s_dest
decl_stmt|;
comment|/* if JXXX, where going to */
ifdef|#
directive|ifdef
name|DJXXX
name|short
name|s_jxline
decl_stmt|;
comment|/* source line of the jump from */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Redefinitions of the fields in symtab for  *	use when the symbol table entry marks a jxxx instruction.  */
end_comment

begin_define
define|#
directive|define
name|s_jxbump
value|s_ptype
end_define

begin_comment
comment|/* tag == JX..., how far to expand */
end_comment

begin_define
define|#
directive|define
name|s_jxfear
value|s_desc
end_define

begin_comment
comment|/* how far needs to be bumped */
end_comment

begin_comment
comment|/*  *	Redefinitions of fields in the struct nlist for symbols so that  *	one saves typing, and so that they conform   *	with the old naming conventions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FLEXNAMES
end_ifdef

begin_define
define|#
directive|define
name|s_name
value|s_nm.n_un.n_name
end_define

begin_comment
comment|/* name pointer */
end_comment

begin_define
define|#
directive|define
name|s_nmx
value|s_nm.n_un.n_strx
end_define

begin_comment
comment|/* string table index */
end_comment

begin_else
else|#
directive|else
else|not FLEXNAMES
end_else

begin_define
define|#
directive|define
name|s_name
value|s_nm.n_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|s_type
value|s_nm.n_type
end_define

begin_comment
comment|/* type of the symbol */
end_comment

begin_define
define|#
directive|define
name|s_other
value|s_nm.n_other
end_define

begin_comment
comment|/* other information for sdb */
end_comment

begin_define
define|#
directive|define
name|s_desc
value|s_nm.n_desc
end_define

begin_comment
comment|/* type descriptor */
end_comment

begin_define
define|#
directive|define
name|s_value
value|s_nm.n_value
end_define

begin_comment
comment|/* value of the symbol, or sdb delta */
end_comment

begin_struct
struct|struct
name|instab
block|{
name|struct
name|nlist
name|s_nm
decl_stmt|;
comment|/* instruction name, type (opcode) */
name|u_char
name|s_tag
decl_stmt|;
name|char
name|s_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* round to 20 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	The fields nm.n_desc and nm.n_value total 6 bytes; this is  *	just enough for the 6 bytes describing the argument types.  *	We use a macro to define access to these 6 bytes, assuming that  *	they are allocated adjacently.  *	IF THE FORMAT OF STRUCT nlist CHANGES, THESE MAY HAVE TO BE CHANGED.  *  *	Instab is cleverly declared to look very much like the combination of  *	a struct symtab and a struct nlist.  */
end_comment

begin_struct
struct|struct
name|Instab
block|{
ifdef|#
directive|ifdef
name|FLEXNAMES
name|char
modifier|*
name|I_name
decl_stmt|;
else|#
directive|else
else|not FLEXNAMES
name|char
name|I_name
index|[
name|NCPS
index|]
decl_stmt|;
endif|#
directive|endif
name|u_char
name|I_opcode
decl_stmt|;
name|char
name|I_nargs
decl_stmt|;
name|char
name|I_args
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|I_s_tag
decl_stmt|;
name|char
name|I_pad
index|[
literal|3
index|]
decl_stmt|;
comment|/* round to 20 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Redefinitions of fields in the struct nlist for instructions so that  *	one saves typing, and conforms to the old naming conventions  */
end_comment

begin_define
define|#
directive|define
name|i_opcode
value|s_nm.n_type
end_define

begin_comment
comment|/* use the same field as symtab.type */
end_comment

begin_define
define|#
directive|define
name|i_nargs
value|s_nm.n_other
end_define

begin_comment
comment|/* number of arguments */
end_comment

begin_define
define|#
directive|define
name|fetcharg
parameter_list|(
name|ptr
parameter_list|,
name|n
parameter_list|)
value|((struct Instab *)ptr)->I_args[n]
end_define

begin_struct
struct|struct
name|arg
block|{
comment|/*one argument to an instruction*/
name|char
name|a_atype
decl_stmt|;
name|char
name|a_areg1
decl_stmt|;
name|char
name|a_areg2
decl_stmt|;
name|char
name|a_dispsize
decl_stmt|;
comment|/*usually d124, unless have B^, etc*/
name|struct
name|exp
modifier|*
name|a_xp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|exp
block|{
name|long
name|e_xvalue
decl_stmt|;
comment|/* MUST be the first field (look at union Double) */
name|long
name|e_yvalue
decl_stmt|;
comment|/* MUST be second field; least sig word of a double */
name|char
name|e_xtype
decl_stmt|;
name|char
name|e_xloc
decl_stmt|;
name|struct
name|symtab
modifier|*
name|e_xname
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|doub_MSW
value|e_xvalue
end_define

begin_define
define|#
directive|define
name|doub_LSW
value|e_yvalue
end_define

begin_union
union|union
name|Double
block|{
struct|struct
block|{
name|long
name|doub_MSW
decl_stmt|;
name|long
name|doub_LSW
decl_stmt|;
block|}
name|dis_dvalue
struct|;
name|double
name|dvalue
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|Quad
block|{
name|long
name|quad_low_long
decl_stmt|;
name|long
name|quad_high_long
decl_stmt|;
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
value|(    (xp->doub_LSW == 0) \&&  ( (xp->doub_MSW& LITFLTMASK) \ 			      == xp->doub_MSW) )
end_define

begin_comment
comment|/*  *	If it is a slitflt, then extract the 6 interesting bits  */
end_comment

begin_define
define|#
directive|define
name|extlitflt
parameter_list|(
name|xp
parameter_list|)
define|\
value|xp->doub_MSW>> 4
end_define

begin_decl_stmt
specifier|extern
name|struct
name|arg
name|arglist
index|[
name|NARG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*building operands in instructions*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exp
name|explist
index|[
name|NEXP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*building up a list of expressions*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|exp
modifier|*
name|xp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current free expression*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|vms_obj_ptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object buffer pointer */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|sobuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* object buffer         */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|objfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VMS object file descriptor */
end_comment

begin_endif
endif|#
directive|endif
endif|VMS
end_endif

begin_comment
comment|/* 	 *	Lgensym is used to make up funny names for local labels. 	 *	lgensym[i] is the current funny number to put after 	 *	references to if, lgensym[i]-1 is for ib. 	 *	genref[i] is set when the label is referenced before 	 *	it is defined (i.e. 2f) so that we can be sure these 	 *	labels are always defined to avoid weird diagnostics 	 *	from the loader later. 	 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lgensym
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|genref
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|tmpn1
index|[
name|TNAMESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interpass temporary */
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
comment|/* the current dot location */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|loctr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|exec
name|hdr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a.out header */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|tsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total text size */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|dsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total data size */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|trsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total text relocation size */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
name|drsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total data relocation size */
end_comment

begin_decl_stmt
specifier|extern
name|u_long
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
specifier|extern
name|int
name|orgwarn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* questionable origin ? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|useVM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*use virtual memory temp file*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|jxxxJUMP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*use jmp instead of brw for jxxx */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|readonlydata
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*initialized data into text space*/
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
specifier|extern
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
extern|extern  readonly struct Instab instab[];
end_extern

begin_decl_stmt
specifier|extern
name|int
name|curlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current literal storage size*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|d124
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*current pointer storage size*/
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

begin_define
define|#
directive|define
name|outb
parameter_list|(
name|val
parameter_list|)
value|{dotp->e_xvalue++; if (passno==2) bputc((val), (txtfil));}
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
value|dotp->e_xvalue += (lg); if (passno == 2) bwrite((cp), (lg), (txtfil))
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

begin_comment
comment|/*  * The biobuf structure and associated routines are used to write  * into one file at several places concurrently.  Calling bopen  * with a biobuf structure sets it up to write ``biofd'' starting  * at the specified offset.  You can then use ``bwrite'' and/or ``bputc''  * to stuff characters in the stream, much like ``fwrite'' and ``fputc''.  * Calling bflush drains all the buffers and MUST be done before exit.  */
end_comment

begin_struct
struct|struct
name|biobuf
block|{
name|short
name|b_nleft
decl_stmt|;
comment|/* Number free spaces left in b_buf */
comment|/* Initialize to be less than BUFSIZ initially, to boundary align in file */
name|char
modifier|*
name|b_ptr
decl_stmt|;
comment|/* Next place to stuff characters */
name|char
name|b_buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* The buffer itself */
name|off_t
name|b_off
decl_stmt|;
comment|/* Current file offset */
name|struct
name|biobuf
modifier|*
name|b_link
decl_stmt|;
comment|/* Link in chain for bflush() */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bputc
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
value|((b)->b_nleft ? (--(b)->b_nleft, *(b)->b_ptr++ = (c)) \ 		       : bflushc(b, c))
end_define

begin_define
define|#
directive|define
name|BFILE
value|struct biobuf
end_define

begin_decl_stmt
specifier|extern
name|BFILE
modifier|*
name|biobufs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the block I/O buffer chain */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|biofd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for block I/O file */
end_comment

begin_decl_stmt
specifier|extern
name|off_t
name|boffset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* physical position in logical file */
end_comment

begin_comment
comment|/* 	 *	For each of the named .text .data segments 	 *	(introduced by .text<expr>), we maintain 	 *	the current value of the dot, and the BFILE where 	 *	the information for each of the segments is placed 	 *	during the second pass. 	 */
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
name|BFILE
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
name|BFILE
modifier|*
name|txtfil
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file for text and data: into usefile */
end_comment

begin_comment
comment|/* 	 *	Relocation information for each segment is accumulated 	 *	seperately from the others.  Writing the relocation 	 *	information is logically viewed as writing to one 	 *	relocation saving file for  each segment; physically 	 *	we have a bunch of buffers allocated internally that 	 *	contain the relocation information. 	 */
end_comment

begin_decl_stmt
name|struct
name|relbufdesc
modifier|*
name|rusefile
index|[
name|NLOC
operator|+
name|NLOC
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|relbufdesc
modifier|*
name|relfil
decl_stmt|;
end_decl_stmt

end_unit

