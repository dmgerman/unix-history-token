begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defines.h	5.3 (Berkeley) 1/3/88  */
end_comment

begin_comment
comment|/*  * defines.h  *  * Global definitions for the first pass of the f77 compiler, Unix 4.3 BSD.  *  * University of Utah CS Dept modification history:  *  * $Log:	defines.h,v $  * Revision 5.2  85/08/10  05:11:20  donn  * Added comment header; added Jerry Berkman's changes to delete INTRCNST  * and to ifdef 66 code.  *   */
end_comment

begin_define
define|#
directive|define
name|INTERDATA
value|2
end_define

begin_define
define|#
directive|define
name|GCOS
value|3
end_define

begin_define
define|#
directive|define
name|PDP11
value|4
end_define

begin_define
define|#
directive|define
name|IBM
value|5
end_define

begin_define
define|#
directive|define
name|CMACH
value|6
end_define

begin_define
define|#
directive|define
name|VAX
value|7
end_define

begin_define
define|#
directive|define
name|DMR
value|2
end_define

begin_define
define|#
directive|define
name|PCC
value|3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FAMILY
end_ifndef

begin_expr_stmt
name|FAMILY
name|NOT
name|DEFINED
operator|!
operator|!
operator|!
name|Family
operator|=
name|FAMILY
endif|#
directive|endif
ifndef|#
directive|ifndef
name|HERE
name|HERE
name|NOT
name|DEFINED
operator|!
operator|!
operator|!
operator|!
name|Here
operator|=
name|HERE
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M
parameter_list|(
name|x
parameter_list|)
value|(1<<x)
end_define

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|(struct x *) ckalloc(sizeof(struct x))
end_define

begin_define
define|#
directive|define
name|ALLOCN
parameter_list|(
name|n
parameter_list|,
name|x
parameter_list|)
value|(struct x *) ckalloc(n*sizeof(struct x))
end_define

begin_define
define|#
directive|define
name|ALLEXPR
value|(expptr) ckalloc( sizeof(union Expression) )
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
name|short
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

begin_define
define|#
directive|define
name|ENULL
value|(expptr) 0
end_define

begin_comment
comment|/* block tag values */
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
name|TTEMP
value|5
end_define

begin_define
define|#
directive|define
name|TPRIM
value|6
end_define

begin_define
define|#
directive|define
name|TLIST
value|7
end_define

begin_define
define|#
directive|define
name|TIMPLDO
value|8
end_define

begin_define
define|#
directive|define
name|TERROR
value|9
end_define

begin_comment
comment|/* parser states */
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
comment|/* storage classes -- vstg values */
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

begin_define
define|#
directive|define
name|STGAUTO
value|2
end_define

begin_define
define|#
directive|define
name|STGBSS
value|3
end_define

begin_define
define|#
directive|define
name|STGINIT
value|4
end_define

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

begin_define
define|#
directive|define
name|STGINTR
value|7
end_define

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
name|STGPREG
value|14
end_define

begin_comment
comment|/* name classes -- vclass values */
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

begin_define
define|#
directive|define
name|CLVAR
value|2
end_define

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
comment|/* vprocclass values */
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
comment|/* control stack codes */
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

begin_comment
comment|/* operators -- see also arrays 'ops' and 'ops2' in put.c */
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
name|OPINDIRECT
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
name|OPPAREN
value|40
end_define

begin_define
define|#
directive|define
name|OPUNARYPLUS
value|41
end_define

begin_comment
comment|/* label type codes */
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

begin_comment
comment|/* I/O statement codes */
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
comment|/* type masks */
end_comment

begin_define
define|#
directive|define
name|MSKLOGICAL
value|M(TYLOGICAL)
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

begin_define
define|#
directive|define
name|MSKINT
value|M(TYSHORT)|M(TYLONG)
end_define

begin_define
define|#
directive|define
name|MSKREAL
value|M(TYREAL)|M(TYDREAL)
end_define

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
value|(ISICON(z)&& z->constblock.constant.ci==1)
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

begin_define
define|#
directive|define
name|ICON
parameter_list|(
name|z
parameter_list|)
value|mkintcon( (ftnint)(z) )
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ONLY66
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NO66
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NOEXT
parameter_list|(
name|s
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* round a up to a multiple of b */
end_comment

begin_define
define|#
directive|define
name|roundup
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( b * ( (a+b-1)/b) )
end_define

begin_comment
comment|/* optimization buffer slot types */
end_comment

begin_define
define|#
directive|define
name|SKNULL
value|0
end_define

begin_define
define|#
directive|define
name|SKIFN
value|1
end_define

begin_define
define|#
directive|define
name|SKGOTO
value|2
end_define

begin_define
define|#
directive|define
name|SKLABEL
value|3
end_define

begin_define
define|#
directive|define
name|SKEQ
value|4
end_define

begin_define
define|#
directive|define
name|SKCALL
value|5
end_define

begin_define
define|#
directive|define
name|SKCMGOTO
value|6
end_define

begin_define
define|#
directive|define
name|SKSTOP
value|7
end_define

begin_define
define|#
directive|define
name|SKDOHEAD
value|8
end_define

begin_define
define|#
directive|define
name|SKENDDO
value|9
end_define

begin_define
define|#
directive|define
name|SKARIF
value|10
end_define

begin_define
define|#
directive|define
name|SKRETURN
value|11
end_define

begin_define
define|#
directive|define
name|SKASGOTO
value|12
end_define

begin_define
define|#
directive|define
name|SKPAUSE
value|13
end_define

begin_define
define|#
directive|define
name|SKASSIGN
value|14
end_define

begin_define
define|#
directive|define
name|SKIOIFN
value|15
end_define

begin_define
define|#
directive|define
name|SKFRTEMP
value|16
end_define

end_unit

