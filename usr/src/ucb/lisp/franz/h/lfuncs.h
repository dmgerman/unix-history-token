begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Mon Jan 31 20:07:39 1983 by layer]-  * 	lfuncs.h			$Locker:  $  * lisp external function definitons  *  * $Header: /na/franz/franz/h/RCS/lfuncs.h,v 1.2 83/01/31 20:11:20 layer Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_comment
comment|/* these functions never return values.  The declarations    are merely to shut lint up. */
end_comment

begin_function_decl
name|lispval
name|Lcont
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lreturn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ngo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nreset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nthrow
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ntpl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Begin functions which return values */
end_comment

begin_function_decl
name|lispval
name|Lstacktrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lunstacktrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lalfalp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LDivide
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LEmuldiv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LMakhunk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Labsval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lacos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ladd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ladd1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lapply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Larg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Largv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Larrayp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Larrayref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lascii
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lasin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lassq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Latan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Latom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbaktrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbcdad
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbcdp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbigtol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbiglsh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lbind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lboole
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lboundp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lc02r
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lc03r
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* cdddr */
end_comment

begin_function_decl
name|lispval
name|Lc04r
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* cddddr */
end_comment

begin_function_decl
name|lispval
name|Lc12r
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* caddr */
end_comment

begin_function_decl
name|lispval
name|Lc13r
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* cadddr */
end_comment

begin_function_decl
name|lispval
name|Lc14r
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* caddddr */
end_comment

begin_function_decl
name|lispval
name|Lcaar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcadr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcfasl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lchdir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lconcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcopyint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* actually copyint* */
end_comment

begin_function_decl
name|lispval
name|Lcos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lcpy1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lctcherr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* function def of ER%unwind-protect */
end_comment

begin_function_decl
name|lispval
name|Lcxr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ldiff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ldrain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ldtpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Leq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lequal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lerr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Leval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Leval1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Levalf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Levalhook
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexece
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexplda
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexpldc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lexpldn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfact
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfadd1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfake
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfasl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfileopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfilestat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lft
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lflatsi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lflessp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfloat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfork
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lforget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfrexp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfsub1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfuncal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfunhook
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetsyntax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgcstat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgcpar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetaddress
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfretn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgensym
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgeta
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetaux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetdata
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetdel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetdim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetdisc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetentry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetenv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetlang
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgetparams
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lgreaterp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhaipar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhashst
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhau
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhtol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhunkp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lhunksize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LIfranzcall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Limplode
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Linfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lintern
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lkilcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llctrace
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llessp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llexfun
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lload
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Llsh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmakertbl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmaknam
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmaknum
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmakunb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmapc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmapcan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmapcar
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmapcon
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmaplist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmarray
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmfunction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lminus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lmonitor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnvec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnvecb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnvecw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnvecl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lncons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnegp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lfasl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnthelem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnull
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnumberp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lnwritn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Loblist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lonep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lopval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Loutfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpatom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lplist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lprocess
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpurcopy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpurep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpntlen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpolyev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lportp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lprname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lprobef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lptime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lptr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputa
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputaux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputdata
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputdel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputdim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputdisc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputlang
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputparams
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lputprop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lquo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrandom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lratom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lreadc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lreadli
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrematom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lremprop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lreplace
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function_decl
name|lispval
name|Lrestlsp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|lispval
name|Lretbrk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrfasl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrmadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrplaca
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrplacd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrplaci
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrplacx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lrset
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_function_decl
name|lispval
name|Lsavelsp
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|lispval
name|Lsbiglsh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lscons
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsegment
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsetarg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsetpli
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsetsyn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lshostk
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LIshowstack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsignal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsimpld
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsizeof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lslevel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsqrt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lstarinvmod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LstarMod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lstarrpx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lstringp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsub
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsub1
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsubstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsstrn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsymbolp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lsyscall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltci
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltcx
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lterpr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltimes
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltimestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltruename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltyi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltyipeek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltyo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ltype
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Luconcat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lvaluep
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lvbind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lvectorp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lpvp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lvprop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LIvref
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LIvset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LIvsize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lwait
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lzapline
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Lzerop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|LImemory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nand
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nbreak
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ncatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ncond
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ndef
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ndo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ndumplisp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nndumplisp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nerrset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nevwhen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nfunction
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ngc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Ngcafter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nopval
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprocess
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprod
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprog2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprogn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nprogv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nquote
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nresetio
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nsetq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nsstatus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Nstatus
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Luntyi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|lispval
name|Zequal
parameter_list|()
function_decl|;
end_function_decl

end_unit

