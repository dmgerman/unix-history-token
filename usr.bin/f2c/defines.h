begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|PDP11
value|4
end_define

begin_define
define|#
directive|define
name|BIGGEST_CHAR
value|0x7f
end_define

begin_comment
comment|/* Assumes 32-bit arithmetic */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_SHORT
value|0x7fff
end_define

begin_comment
comment|/* Assumes 32-bit arithmetic */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_LONG
value|0x7fffffff
end_define

begin_comment
comment|/* Assumes 32-bit arithmetic */
end_comment

begin_define
define|#
directive|define
name|M
parameter_list|(
name|x
parameter_list|)
value|(1<<x)
end_define

begin_comment
comment|/* Mask (x) returns 2^x */
end_comment

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|(struct x *) ckalloc((int)sizeof(struct x))
end_define

begin_define
define|#
directive|define
name|ALLEXPR
value|(expptr) ckalloc((int)sizeof(union Expression) )
end_define

begin_typedef
typedef|typedef
name|int
modifier|*
name|ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|charptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FILE
modifier|*
name|FILEP
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|field
typedef|;
end_typedef

begin_comment
comment|/* actually need only 4 bits */
end_comment

begin_typedef
typedef|typedef
name|long
name|int
name|ftnint
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|CNULL
value|(char *) 0
end_define

begin_comment
comment|/* Character string null */
end_comment

begin_define
define|#
directive|define
name|PNULL
value|(ptr) 0
end_define

begin_define
define|#
directive|define
name|CHNULL
value|(chainp) 0
end_define

begin_comment
comment|/* Chain null */
end_comment

begin_define
define|#
directive|define
name|ENULL
value|(expptr) 0
end_define

begin_comment
comment|/* BAD_MEMNO - used to distinguish between long string constants and other    constants in the table */
end_comment

begin_define
define|#
directive|define
name|BAD_MEMNO
value|-32768
end_define

begin_comment
comment|/* block tag values -- syntactic stuff */
end_comment

begin_define
define|#
directive|define
name|TNAME
value|1
end_define

begin_define
define|#
directive|define
name|TCONST
value|2
end_define

begin_define
define|#
directive|define
name|TEXPR
value|3
end_define

begin_define
define|#
directive|define
name|TADDR
value|4
end_define

begin_define
define|#
directive|define
name|TPRIM
value|5
end_define

begin_comment
comment|/* Primitive datum - should not appear in an 			   expptr variable, it should have already been 			   identified */
end_comment

begin_define
define|#
directive|define
name|TLIST
value|6
end_define

begin_define
define|#
directive|define
name|TIMPLDO
value|7
end_define

begin_define
define|#
directive|define
name|TERROR
value|8
end_define

begin_comment
comment|/* parser states - order is important, since there are several tests for    state< INDATA   */
end_comment

begin_define
define|#
directive|define
name|OUTSIDE
value|0
end_define

begin_define
define|#
directive|define
name|INSIDE
value|1
end_define

begin_define
define|#
directive|define
name|INDCL
value|2
end_define

begin_define
define|#
directive|define
name|INDATA
value|3
end_define

begin_define
define|#
directive|define
name|INEXEC
value|4
end_define

begin_comment
comment|/* procedure classes */
end_comment

begin_define
define|#
directive|define
name|PROCMAIN
value|1
end_define

begin_define
define|#
directive|define
name|PROCBLOCK
value|2
end_define

begin_define
define|#
directive|define
name|PROCSUBR
value|3
end_define

begin_define
define|#
directive|define
name|PROCFUNCT
value|4
end_define

begin_comment
comment|/* storage classes -- vstg values.  BSS and INIT are used in the later    merge pass over identifiers; and they are entered differently into the    symbol table */
end_comment

begin_define
define|#
directive|define
name|STGUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|STGARG
value|1
end_define

begin_comment
comment|/* adjustable dimensions */
end_comment

begin_define
define|#
directive|define
name|STGAUTO
value|2
end_define

begin_comment
comment|/* for stack references */
end_comment

begin_define
define|#
directive|define
name|STGBSS
value|3
end_define

begin_comment
comment|/* uninitialized storage (normal variables) */
end_comment

begin_define
define|#
directive|define
name|STGINIT
value|4
end_define

begin_comment
comment|/* initialized storage */
end_comment

begin_define
define|#
directive|define
name|STGCONST
value|5
end_define

begin_define
define|#
directive|define
name|STGEXT
value|6
end_define

begin_comment
comment|/* external storage */
end_comment

begin_define
define|#
directive|define
name|STGINTR
value|7
end_define

begin_comment
comment|/* intrinsic (late decision) reference.  See 			   chapter 5 of the Fortran 77 standard */
end_comment

begin_define
define|#
directive|define
name|STGSTFUNCT
value|8
end_define

begin_define
define|#
directive|define
name|STGCOMMON
value|9
end_define

begin_define
define|#
directive|define
name|STGEQUIV
value|10
end_define

begin_define
define|#
directive|define
name|STGREG
value|11
end_define

begin_comment
comment|/* register - the outermost DO loop index will be 			   in a register (because the compiler is one 			   pass, it can't know where the innermost loop is 			   */
end_comment

begin_define
define|#
directive|define
name|STGLENG
value|12
end_define

begin_define
define|#
directive|define
name|STGNULL
value|13
end_define

begin_define
define|#
directive|define
name|STGMEMNO
value|14
end_define

begin_comment
comment|/* interemediate-file pointer to constant table */
end_comment

begin_comment
comment|/* name classes -- vclass values, also   procclass   values */
end_comment

begin_define
define|#
directive|define
name|CLUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|CLPARAM
value|1
end_define

begin_comment
comment|/* Parameter - macro definition */
end_comment

begin_define
define|#
directive|define
name|CLVAR
value|2
end_define

begin_comment
comment|/* variable */
end_comment

begin_define
define|#
directive|define
name|CLENTRY
value|3
end_define

begin_define
define|#
directive|define
name|CLMAIN
value|4
end_define

begin_define
define|#
directive|define
name|CLBLOCK
value|5
end_define

begin_define
define|#
directive|define
name|CLPROC
value|6
end_define

begin_define
define|#
directive|define
name|CLNAMELIST
value|7
end_define

begin_comment
comment|/* in data with this tag, the   vdcldone   flag should 			   be ignored (according to vardcl()) */
end_comment

begin_comment
comment|/* vprocclass values -- there is some overlap with the vclass values given    above */
end_comment

begin_define
define|#
directive|define
name|PUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|PEXTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|PINTRINSIC
value|2
end_define

begin_define
define|#
directive|define
name|PSTFUNCT
value|3
end_define

begin_define
define|#
directive|define
name|PTHISPROC
value|4
end_define

begin_comment
comment|/* here to allow recursion - further distinction 			   is given in the CL tag (those just above). 			   This applies to the presence of the name of a 			   function used within itself.  The function name 			   means either call the function again, or assign 			   some value to the storage allocated to the 			   function's return value. */
end_comment

begin_comment
comment|/* control stack codes - these are part of a state machine which handles    the nesting of blocks (i.e. what to do about the ELSE statement) */
end_comment

begin_define
define|#
directive|define
name|CTLDO
value|1
end_define

begin_define
define|#
directive|define
name|CTLIF
value|2
end_define

begin_define
define|#
directive|define
name|CTLELSE
value|3
end_define

begin_define
define|#
directive|define
name|CTLIFX
value|4
end_define

begin_comment
comment|/* operators for both Fortran input and C output.  They are common because    so many are shared between the trees */
end_comment

begin_define
define|#
directive|define
name|OPPLUS
value|1
end_define

begin_define
define|#
directive|define
name|OPMINUS
value|2
end_define

begin_define
define|#
directive|define
name|OPSTAR
value|3
end_define

begin_define
define|#
directive|define
name|OPSLASH
value|4
end_define

begin_define
define|#
directive|define
name|OPPOWER
value|5
end_define

begin_define
define|#
directive|define
name|OPNEG
value|6
end_define

begin_define
define|#
directive|define
name|OPOR
value|7
end_define

begin_define
define|#
directive|define
name|OPAND
value|8
end_define

begin_define
define|#
directive|define
name|OPEQV
value|9
end_define

begin_define
define|#
directive|define
name|OPNEQV
value|10
end_define

begin_define
define|#
directive|define
name|OPNOT
value|11
end_define

begin_define
define|#
directive|define
name|OPCONCAT
value|12
end_define

begin_define
define|#
directive|define
name|OPLT
value|13
end_define

begin_define
define|#
directive|define
name|OPEQ
value|14
end_define

begin_define
define|#
directive|define
name|OPGT
value|15
end_define

begin_define
define|#
directive|define
name|OPLE
value|16
end_define

begin_define
define|#
directive|define
name|OPNE
value|17
end_define

begin_define
define|#
directive|define
name|OPGE
value|18
end_define

begin_define
define|#
directive|define
name|OPCALL
value|19
end_define

begin_define
define|#
directive|define
name|OPCCALL
value|20
end_define

begin_define
define|#
directive|define
name|OPASSIGN
value|21
end_define

begin_define
define|#
directive|define
name|OPPLUSEQ
value|22
end_define

begin_define
define|#
directive|define
name|OPSTAREQ
value|23
end_define

begin_define
define|#
directive|define
name|OPCONV
value|24
end_define

begin_define
define|#
directive|define
name|OPLSHIFT
value|25
end_define

begin_define
define|#
directive|define
name|OPMOD
value|26
end_define

begin_define
define|#
directive|define
name|OPCOMMA
value|27
end_define

begin_define
define|#
directive|define
name|OPQUEST
value|28
end_define

begin_define
define|#
directive|define
name|OPCOLON
value|29
end_define

begin_define
define|#
directive|define
name|OPABS
value|30
end_define

begin_define
define|#
directive|define
name|OPMIN
value|31
end_define

begin_define
define|#
directive|define
name|OPMAX
value|32
end_define

begin_define
define|#
directive|define
name|OPADDR
value|33
end_define

begin_define
define|#
directive|define
name|OPCOMMA_ARG
value|34
end_define

begin_define
define|#
directive|define
name|OPBITOR
value|35
end_define

begin_define
define|#
directive|define
name|OPBITAND
value|36
end_define

begin_define
define|#
directive|define
name|OPBITXOR
value|37
end_define

begin_define
define|#
directive|define
name|OPBITNOT
value|38
end_define

begin_define
define|#
directive|define
name|OPRSHIFT
value|39
end_define

begin_define
define|#
directive|define
name|OPWHATSIN
value|40
end_define

begin_comment
comment|/* dereferencing operator */
end_comment

begin_define
define|#
directive|define
name|OPMINUSEQ
value|41
end_define

begin_comment
comment|/* assignment operators */
end_comment

begin_define
define|#
directive|define
name|OPSLASHEQ
value|42
end_define

begin_define
define|#
directive|define
name|OPMODEQ
value|43
end_define

begin_define
define|#
directive|define
name|OPLSHIFTEQ
value|44
end_define

begin_define
define|#
directive|define
name|OPRSHIFTEQ
value|45
end_define

begin_define
define|#
directive|define
name|OPBITANDEQ
value|46
end_define

begin_define
define|#
directive|define
name|OPBITXOREQ
value|47
end_define

begin_define
define|#
directive|define
name|OPBITOREQ
value|48
end_define

begin_define
define|#
directive|define
name|OPPREINC
value|49
end_define

begin_comment
comment|/* Preincrement (++x) operator */
end_comment

begin_define
define|#
directive|define
name|OPPREDEC
value|50
end_define

begin_comment
comment|/* Predecrement (--x) operator */
end_comment

begin_define
define|#
directive|define
name|OPDOT
value|51
end_define

begin_comment
comment|/* structure field reference */
end_comment

begin_define
define|#
directive|define
name|OPARROW
value|52
end_define

begin_comment
comment|/* structure pointer field reference */
end_comment

begin_define
define|#
directive|define
name|OPNEG1
value|53
end_define

begin_comment
comment|/* simple negation under forcedouble */
end_comment

begin_define
define|#
directive|define
name|OPDMIN
value|54
end_define

begin_comment
comment|/* min(a,b) macro under forcedouble */
end_comment

begin_define
define|#
directive|define
name|OPDMAX
value|55
end_define

begin_comment
comment|/* max(a,b) macro under forcedouble */
end_comment

begin_define
define|#
directive|define
name|OPASSIGNI
value|56
end_define

begin_comment
comment|/* assignment for inquire stmt */
end_comment

begin_define
define|#
directive|define
name|OPIDENTITY
value|57
end_define

begin_comment
comment|/* for turning TADDR into TEXPR */
end_comment

begin_define
define|#
directive|define
name|OPCHARCAST
value|58
end_define

begin_comment
comment|/* for casting to char * (in I/O stmts) */
end_comment

begin_define
define|#
directive|define
name|OPDABS
value|59
end_define

begin_comment
comment|/* abs macro under forcedouble */
end_comment

begin_define
define|#
directive|define
name|OPMIN2
value|60
end_define

begin_comment
comment|/* min(a,b) macro */
end_comment

begin_define
define|#
directive|define
name|OPMAX2
value|61
end_define

begin_comment
comment|/* max(a,b) macro */
end_comment

begin_define
define|#
directive|define
name|OPBITTEST
value|62
end_define

begin_comment
comment|/* btest */
end_comment

begin_define
define|#
directive|define
name|OPBITCLR
value|63
end_define

begin_comment
comment|/* ibclr */
end_comment

begin_define
define|#
directive|define
name|OPBITSET
value|64
end_define

begin_comment
comment|/* ibset */
end_comment

begin_define
define|#
directive|define
name|OPQBITCLR
value|65
end_define

begin_comment
comment|/* ibclr, integer*8 */
end_comment

begin_define
define|#
directive|define
name|OPQBITSET
value|66
end_define

begin_comment
comment|/* ibset, integer*8 */
end_comment

begin_define
define|#
directive|define
name|OPBITBITS
value|67
end_define

begin_comment
comment|/* ibits */
end_comment

begin_define
define|#
directive|define
name|OPBITSH
value|68
end_define

begin_comment
comment|/* ishft */
end_comment

begin_define
define|#
directive|define
name|OPBITSHC
value|69
end_define

begin_comment
comment|/* ishftc */
end_comment

begin_comment
comment|/* label type codes -- used with the ASSIGN statement */
end_comment

begin_define
define|#
directive|define
name|LABUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|LABEXEC
value|1
end_define

begin_define
define|#
directive|define
name|LABFORMAT
value|2
end_define

begin_define
define|#
directive|define
name|LABOTHER
value|3
end_define

begin_comment
comment|/* INTRINSIC function codes*/
end_comment

begin_define
define|#
directive|define
name|INTREND
value|0
end_define

begin_define
define|#
directive|define
name|INTRCONV
value|1
end_define

begin_define
define|#
directive|define
name|INTRMIN
value|2
end_define

begin_define
define|#
directive|define
name|INTRMAX
value|3
end_define

begin_define
define|#
directive|define
name|INTRGEN
value|4
end_define

begin_comment
comment|/* General intrinsic, e.g. cos v. dcos, zcos, ccos */
end_comment

begin_define
define|#
directive|define
name|INTRSPEC
value|5
end_define

begin_define
define|#
directive|define
name|INTRBOOL
value|6
end_define

begin_define
define|#
directive|define
name|INTRCNST
value|7
end_define

begin_comment
comment|/* constants, e.g. bigint(1.0) v. bigint (1d0) */
end_comment

begin_define
define|#
directive|define
name|INTRBGEN
value|8
end_define

begin_comment
comment|/* bit manipulation */
end_comment

begin_comment
comment|/* I/O statement codes - these all form Integer Constants, and are always    reevaluated */
end_comment

begin_define
define|#
directive|define
name|IOSTDIN
value|ICON(5)
end_define

begin_define
define|#
directive|define
name|IOSTDOUT
value|ICON(6)
end_define

begin_define
define|#
directive|define
name|IOSTDERR
value|ICON(0)
end_define

begin_define
define|#
directive|define
name|IOSBAD
value|(-1)
end_define

begin_define
define|#
directive|define
name|IOSPOSITIONAL
value|0
end_define

begin_define
define|#
directive|define
name|IOSUNIT
value|1
end_define

begin_define
define|#
directive|define
name|IOSFMT
value|2
end_define

begin_define
define|#
directive|define
name|IOINQUIRE
value|1
end_define

begin_define
define|#
directive|define
name|IOOPEN
value|2
end_define

begin_define
define|#
directive|define
name|IOCLOSE
value|3
end_define

begin_define
define|#
directive|define
name|IOREWIND
value|4
end_define

begin_define
define|#
directive|define
name|IOBACKSPACE
value|5
end_define

begin_define
define|#
directive|define
name|IOENDFILE
value|6
end_define

begin_define
define|#
directive|define
name|IOREAD
value|7
end_define

begin_define
define|#
directive|define
name|IOWRITE
value|8
end_define

begin_comment
comment|/* User name tags -- these identify the form of the original identifier    stored in a   struct Addrblock   structure (in the   user   field). */
end_comment

begin_define
define|#
directive|define
name|UNAM_UNKNOWN
value|0
end_define

begin_comment
comment|/* Not specified */
end_comment

begin_define
define|#
directive|define
name|UNAM_NAME
value|1
end_define

begin_comment
comment|/* Local symbol, store in the hash table */
end_comment

begin_define
define|#
directive|define
name|UNAM_IDENT
value|2
end_define

begin_comment
comment|/* Character string not stored elsewhere */
end_comment

begin_define
define|#
directive|define
name|UNAM_EXTERN
value|3
end_define

begin_comment
comment|/* External reference; check symbol table 				   using   memno   as index */
end_comment

begin_define
define|#
directive|define
name|UNAM_CONST
value|4
end_define

begin_comment
comment|/* Constant value */
end_comment

begin_define
define|#
directive|define
name|UNAM_CHARP
value|5
end_define

begin_comment
comment|/* pointer to string */
end_comment

begin_define
define|#
directive|define
name|UNAM_REF
value|6
end_define

begin_comment
comment|/* subscript reference with -s */
end_comment

begin_define
define|#
directive|define
name|IDENT_LEN
value|31
end_define

begin_comment
comment|/* Maximum length user.ident */
end_comment

begin_define
define|#
directive|define
name|MAXNAMELEN
value|50
end_define

begin_comment
comment|/* Maximum Fortran name length */
end_comment

begin_comment
comment|/* type masks - TYLOGICAL defined in   ftypes   */
end_comment

begin_define
define|#
directive|define
name|MSKLOGICAL
value|M(TYLOGICAL)|M(TYLOGICAL1)|M(TYLOGICAL2)
end_define

begin_define
define|#
directive|define
name|MSKADDR
value|M(TYADDR)
end_define

begin_define
define|#
directive|define
name|MSKCHAR
value|M(TYCHAR)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TYQUAD
end_ifdef

begin_define
define|#
directive|define
name|MSKINT
value|M(TYINT1)|M(TYSHORT)|M(TYLONG)|M(TYQUAD)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MSKINT
value|M(TYINT1)|M(TYSHORT)|M(TYLONG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MSKREAL
value|M(TYREAL)|M(TYDREAL)
end_define

begin_comment
comment|/* DREAL means Double Real */
end_comment

begin_define
define|#
directive|define
name|MSKCOMPLEX
value|M(TYCOMPLEX)|M(TYDCOMPLEX)
end_define

begin_define
define|#
directive|define
name|MSKSTATIC
value|(M(STGINIT)|M(STGBSS)|M(STGCOMMON)|M(STGEQUIV)|M(STGCONST))
end_define

begin_comment
comment|/* miscellaneous macros */
end_comment

begin_comment
comment|/* ONEOF (x, y) -- x is the number of one of the OR'ed masks in y (i.e., x is    the log of one of the OR'ed masks in y) */
end_comment

begin_define
define|#
directive|define
name|ONEOF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(M(x)& (y))
end_define

begin_define
define|#
directive|define
name|ISCOMPLEX
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKCOMPLEX)
end_define

begin_define
define|#
directive|define
name|ISREAL
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKREAL)
end_define

begin_define
define|#
directive|define
name|ISNUMERIC
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKINT|MSKREAL|MSKCOMPLEX)
end_define

begin_define
define|#
directive|define
name|ISICON
parameter_list|(
name|z
parameter_list|)
value|(z->tag==TCONST&& ISINT(z->constblock.vtype))
end_define

begin_define
define|#
directive|define
name|ISLOGICAL
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKLOGICAL)
end_define

begin_comment
comment|/* ISCHAR assumes that   z   has some kind of structure, i.e. is not null */
end_comment

begin_define
define|#
directive|define
name|ISCHAR
parameter_list|(
name|z
parameter_list|)
value|(z->headblock.vtype==TYCHAR)
end_define

begin_define
define|#
directive|define
name|ISINT
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKINT)
end_define

begin_comment
comment|/*   z   is a tag, i.e. a mask number */
end_comment

begin_define
define|#
directive|define
name|ISCONST
parameter_list|(
name|z
parameter_list|)
value|(z->tag==TCONST)
end_define

begin_define
define|#
directive|define
name|ISERROR
parameter_list|(
name|z
parameter_list|)
value|(z->tag==TERROR)
end_define

begin_define
define|#
directive|define
name|ISPLUSOP
parameter_list|(
name|z
parameter_list|)
value|(z->tag==TEXPR&& z->exprblock.opcode==OPPLUS)
end_define

begin_define
define|#
directive|define
name|ISSTAROP
parameter_list|(
name|z
parameter_list|)
value|(z->tag==TEXPR&& z->exprblock.opcode==OPSTAR)
end_define

begin_define
define|#
directive|define
name|ISONE
parameter_list|(
name|z
parameter_list|)
value|(ISICON(z)&& z->constblock.Const.ci==1)
end_define

begin_define
define|#
directive|define
name|INT
parameter_list|(
name|z
parameter_list|)
value|ONEOF(z, MSKINT|MSKCHAR)
end_define

begin_comment
comment|/* has INT storage in real life */
end_comment

begin_define
define|#
directive|define
name|ICON
parameter_list|(
name|z
parameter_list|)
value|mkintcon( (ftnint)(z) )
end_define

begin_comment
comment|/* NO66 -- F77 feature is being used    NOEXT -- F77 extension is being used */
end_comment

begin_define
define|#
directive|define
name|NO66
parameter_list|(
name|s
parameter_list|)
value|if(no66flag) err66(s)
end_define

begin_define
define|#
directive|define
name|NOEXT
parameter_list|(
name|s
parameter_list|)
value|if(noextflag) errext(s)
end_define

end_unit

