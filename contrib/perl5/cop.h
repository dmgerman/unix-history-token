begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    cop.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_struct
struct|struct
name|cop
block|{
name|BASEOP
name|char
modifier|*
name|cop_label
decl_stmt|;
comment|/* label for this construct */
ifdef|#
directive|ifdef
name|USE_ITHREADS
name|char
modifier|*
name|cop_stashpv
decl_stmt|;
comment|/* package line was compiled in */
name|char
modifier|*
name|cop_file
decl_stmt|;
comment|/* file name the following line # is from */
else|#
directive|else
name|HV
modifier|*
name|cop_stash
decl_stmt|;
comment|/* package line was compiled in */
name|GV
modifier|*
name|cop_filegv
decl_stmt|;
comment|/* file the following line # is from */
endif|#
directive|endif
name|U32
name|cop_seq
decl_stmt|;
comment|/* parse sequence number */
name|I32
name|cop_arybase
decl_stmt|;
comment|/* array base this line was compiled with */
name|line_t
name|cop_line
decl_stmt|;
comment|/* line # of this command */
name|SV
modifier|*
name|cop_warnings
decl_stmt|;
comment|/* lexical warnings bitmask */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Nullcop
value|Null(COP*)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ITHREADS
end_ifdef

begin_define
define|#
directive|define
name|CopFILE
parameter_list|(
name|c
parameter_list|)
value|((c)->cop_file)
end_define

begin_define
define|#
directive|define
name|CopFILEGV
parameter_list|(
name|c
parameter_list|)
value|(CopFILE(c) \ 				 ? gv_fetchfile(CopFILE(c)) : Nullgv)
end_define

begin_define
define|#
directive|define
name|CopFILE_set
parameter_list|(
name|c
parameter_list|,
name|pv
parameter_list|)
value|((c)->cop_file = savepv(pv))
end_define

begin_define
define|#
directive|define
name|CopFILESV
parameter_list|(
name|c
parameter_list|)
value|(CopFILE(c) \ 				 ? GvSV(gv_fetchfile(CopFILE(c))) : Nullsv)
end_define

begin_define
define|#
directive|define
name|CopFILEAV
parameter_list|(
name|c
parameter_list|)
value|(CopFILE(c) \ 				 ? GvAV(gv_fetchfile(CopFILE(c))) : Nullav)
end_define

begin_define
define|#
directive|define
name|CopSTASHPV
parameter_list|(
name|c
parameter_list|)
value|((c)->cop_stashpv)
end_define

begin_define
define|#
directive|define
name|CopSTASHPV_set
parameter_list|(
name|c
parameter_list|,
name|pv
parameter_list|)
value|((c)->cop_stashpv = ((pv) ? savepv(pv) : Nullch))
end_define

begin_define
define|#
directive|define
name|CopSTASH
parameter_list|(
name|c
parameter_list|)
value|(CopSTASHPV(c) \ 				 ? gv_stashpv(CopSTASHPV(c),GV_ADD) : Nullhv)
end_define

begin_define
define|#
directive|define
name|CopSTASH_set
parameter_list|(
name|c
parameter_list|,
name|hv
parameter_list|)
value|CopSTASHPV_set(c, (hv) ? HvNAME(hv) : Nullch)
end_define

begin_define
define|#
directive|define
name|CopSTASH_eq
parameter_list|(
name|c
parameter_list|,
name|hv
parameter_list|)
value|((hv) 					\&& (CopSTASHPV(c) == HvNAME(hv)	\ 				     || (CopSTASHPV(c)&& HvNAME(hv)	\&& strEQ(CopSTASHPV(c), HvNAME(hv)))))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CopFILEGV
parameter_list|(
name|c
parameter_list|)
value|((c)->cop_filegv)
end_define

begin_define
define|#
directive|define
name|CopFILEGV_set
parameter_list|(
name|c
parameter_list|,
name|gv
parameter_list|)
value|((c)->cop_filegv = (GV*)SvREFCNT_inc(gv))
end_define

begin_define
define|#
directive|define
name|CopFILE_set
parameter_list|(
name|c
parameter_list|,
name|pv
parameter_list|)
value|CopFILEGV_set((c), gv_fetchfile(pv))
end_define

begin_define
define|#
directive|define
name|CopFILESV
parameter_list|(
name|c
parameter_list|)
value|(CopFILEGV(c) ? GvSV(CopFILEGV(c)) : Nullsv)
end_define

begin_define
define|#
directive|define
name|CopFILEAV
parameter_list|(
name|c
parameter_list|)
value|(CopFILEGV(c) ? GvAV(CopFILEGV(c)) : Nullav)
end_define

begin_define
define|#
directive|define
name|CopFILE
parameter_list|(
name|c
parameter_list|)
value|(CopFILESV(c) ? SvPVX(CopFILESV(c)) : Nullch)
end_define

begin_define
define|#
directive|define
name|CopSTASH
parameter_list|(
name|c
parameter_list|)
value|((c)->cop_stash)
end_define

begin_define
define|#
directive|define
name|CopSTASH_set
parameter_list|(
name|c
parameter_list|,
name|hv
parameter_list|)
value|((c)->cop_stash = (hv))
end_define

begin_define
define|#
directive|define
name|CopSTASHPV
parameter_list|(
name|c
parameter_list|)
value|(CopSTASH(c) ? HvNAME(CopSTASH(c)) : Nullch)
end_define

begin_comment
comment|/* cop_stash is not refcounted */
end_comment

begin_define
define|#
directive|define
name|CopSTASHPV_set
parameter_list|(
name|c
parameter_list|,
name|pv
parameter_list|)
value|CopSTASH_set((c), gv_stashpv(pv,GV_ADD))
end_define

begin_define
define|#
directive|define
name|CopSTASH_eq
parameter_list|(
name|c
parameter_list|,
name|hv
parameter_list|)
value|(CopSTASH(c) == (hv))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_ITHREADS */
end_comment

begin_define
define|#
directive|define
name|CopSTASH_ne
parameter_list|(
name|c
parameter_list|,
name|hv
parameter_list|)
value|(!CopSTASH_eq(c,hv))
end_define

begin_define
define|#
directive|define
name|CopLINE
parameter_list|(
name|c
parameter_list|)
value|((c)->cop_line)
end_define

begin_define
define|#
directive|define
name|CopLINE_inc
parameter_list|(
name|c
parameter_list|)
value|(++CopLINE(c))
end_define

begin_define
define|#
directive|define
name|CopLINE_dec
parameter_list|(
name|c
parameter_list|)
value|(--CopLINE(c))
end_define

begin_define
define|#
directive|define
name|CopLINE_set
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(CopLINE(c) = (l))
end_define

begin_comment
comment|/*  * Here we have some enormously heavy (or at least ponderous) wizardry.  */
end_comment

begin_comment
comment|/* subroutine context */
end_comment

begin_struct
struct|struct
name|block_sub
block|{
name|CV
modifier|*
name|cv
decl_stmt|;
name|GV
modifier|*
name|gv
decl_stmt|;
name|GV
modifier|*
name|dfoutgv
decl_stmt|;
ifndef|#
directive|ifndef
name|USE_THREADS
name|AV
modifier|*
name|savearray
decl_stmt|;
endif|#
directive|endif
comment|/* USE_THREADS */
name|AV
modifier|*
name|argarray
decl_stmt|;
name|U16
name|olddepth
decl_stmt|;
name|U8
name|hasargs
decl_stmt|;
name|U8
name|lval
decl_stmt|;
comment|/* XXX merge lval and hasargs? */
name|SV
modifier|*
modifier|*
name|oldcurpad
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUSHSUB
parameter_list|(
name|cx
parameter_list|)
define|\
value|cx->blk_sub.cv = cv;						\ 	cx->blk_sub.olddepth = CvDEPTH(cv);				\ 	cx->blk_sub.hasargs = hasargs;					\ 	cx->blk_sub.lval = PL_op->op_private&                          \ 	                      (OPpLVAL_INTRO|OPpENTERSUB_INARGS);
end_define

begin_define
define|#
directive|define
name|PUSHFORMAT
parameter_list|(
name|cx
parameter_list|)
define|\
value|cx->blk_sub.cv = cv;						\ 	cx->blk_sub.gv = gv;						\ 	cx->blk_sub.hasargs = 0;					\ 	cx->blk_sub.dfoutgv = PL_defoutgv;				\ 	(void)SvREFCNT_inc(cx->blk_sub.dfoutgv)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|POP_SAVEARRAY
parameter_list|()
value|NOOP
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POP_SAVEARRAY
parameter_list|()
define|\
value|STMT_START {							\ 	SvREFCNT_dec(GvAV(PL_defgv));					\ 	GvAV(PL_defgv) = cx->blk_sub.savearray;				\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_comment
comment|/* junk in @_ spells trouble when cloning CVs and in pp_caller(), so don't  * leave any (a fast av_clear(ary), basically) */
end_comment

begin_define
define|#
directive|define
name|CLEAR_ARGARRAY
parameter_list|(
name|ary
parameter_list|)
define|\
value|STMT_START {							\ 	AvMAX(ary) += AvARRAY(ary) - AvALLOC(ary);			\ 	SvPVX(ary) = (char*)AvALLOC(ary);				\ 	AvFILLp(ary) = -1;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|POPSUB
parameter_list|(
name|cx
parameter_list|,
name|sv
parameter_list|)
define|\
value|STMT_START {							\ 	if (cx->blk_sub.hasargs) {					\ 	    POP_SAVEARRAY();						\
comment|/* abandon @_ if it got reified */
value|\ 	    if (AvREAL(cx->blk_sub.argarray)) {				\ 		SSize_t fill = AvFILLp(cx->blk_sub.argarray);		\ 		SvREFCNT_dec(cx->blk_sub.argarray);			\ 		cx->blk_sub.argarray = newAV();				\ 		av_extend(cx->blk_sub.argarray, fill);			\ 		AvFLAGS(cx->blk_sub.argarray) = AVf_REIFY;		\ 		cx->blk_sub.oldcurpad[0] = (SV*)cx->blk_sub.argarray;	\ 	    }								\ 	    else {							\ 		CLEAR_ARGARRAY(cx->blk_sub.argarray);			\ 	    }								\ 	}								\ 	sv = (SV*)cx->blk_sub.cv;					\ 	if (sv&& (CvDEPTH((CV*)sv) = cx->blk_sub.olddepth))		\ 	    sv = Nullsv;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|LEAVESUB
parameter_list|(
name|sv
parameter_list|)
define|\
value|STMT_START {							\ 	if (sv)								\ 	    SvREFCNT_dec(sv);						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|POPFORMAT
parameter_list|(
name|cx
parameter_list|)
define|\
value|setdefout(cx->blk_sub.dfoutgv);					\ 	SvREFCNT_dec(cx->blk_sub.dfoutgv);
end_define

begin_comment
comment|/* eval context */
end_comment

begin_struct
struct|struct
name|block_eval
block|{
name|I32
name|old_in_eval
decl_stmt|;
name|I32
name|old_op_type
decl_stmt|;
name|SV
modifier|*
name|old_namesv
decl_stmt|;
name|OP
modifier|*
name|old_eval_root
decl_stmt|;
name|SV
modifier|*
name|cur_text
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PUSHEVAL
parameter_list|(
name|cx
parameter_list|,
name|n
parameter_list|,
name|fgv
parameter_list|)
define|\
value|STMT_START {							\ 	cx->blk_eval.old_in_eval = PL_in_eval;				\ 	cx->blk_eval.old_op_type = PL_op->op_type;			\ 	cx->blk_eval.old_namesv = (n ? newSVpv(n,0) : Nullsv);		\ 	cx->blk_eval.old_eval_root = PL_eval_root;			\ 	cx->blk_eval.cur_text = PL_linestr;				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|POPEVAL
parameter_list|(
name|cx
parameter_list|)
define|\
value|STMT_START {							\ 	PL_in_eval = cx->blk_eval.old_in_eval;				\ 	optype = cx->blk_eval.old_op_type;				\ 	PL_eval_root = cx->blk_eval.old_eval_root;			\ 	if (cx->blk_eval.old_namesv)					\ 	    sv_2mortal(cx->blk_eval.old_namesv);			\     } STMT_END
end_define

begin_comment
comment|/* loop context */
end_comment

begin_struct
struct|struct
name|block_loop
block|{
name|char
modifier|*
name|label
decl_stmt|;
name|I32
name|resetsp
decl_stmt|;
name|OP
modifier|*
name|redo_op
decl_stmt|;
name|OP
modifier|*
name|next_op
decl_stmt|;
name|OP
modifier|*
name|last_op
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_ITHREADS
name|void
modifier|*
name|iterdata
decl_stmt|;
name|SV
modifier|*
modifier|*
name|oldcurpad
decl_stmt|;
else|#
directive|else
name|SV
modifier|*
modifier|*
name|itervar
decl_stmt|;
endif|#
directive|endif
name|SV
modifier|*
name|itersave
decl_stmt|;
name|SV
modifier|*
name|iterlval
decl_stmt|;
name|AV
modifier|*
name|iterary
decl_stmt|;
name|IV
name|iterix
decl_stmt|;
name|IV
name|itermax
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ITHREADS
end_ifdef

begin_define
define|#
directive|define
name|CxITERVAR
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)->blk_loop.iterdata						\ 	 ? (CxPADLOOP(cx) 						\ 	    ?&((c)->blk_loop.oldcurpad)[(PADOFFSET)(c)->blk_loop.iterdata]	\ 	    :&GvSV((GV*)(c)->blk_loop.iterdata))			\ 	 : (SV**)NULL)
end_define

begin_define
define|#
directive|define
name|CX_ITERDATA_SET
parameter_list|(
name|cx
parameter_list|,
name|idata
parameter_list|)
define|\
value|cx->blk_loop.oldcurpad = PL_curpad;				\ 	if ((cx->blk_loop.iterdata = (idata)))				\ 	    cx->blk_loop.itersave = SvREFCNT_inc(*CxITERVAR(cx));
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CxITERVAR
parameter_list|(
name|c
parameter_list|)
value|((c)->blk_loop.itervar)
end_define

begin_define
define|#
directive|define
name|CX_ITERDATA_SET
parameter_list|(
name|cx
parameter_list|,
name|ivar
parameter_list|)
define|\
value|if ((cx->blk_loop.itervar = (SV**)(ivar)))			\ 	    cx->blk_loop.itersave = SvREFCNT_inc(*CxITERVAR(cx));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUSHLOOP
parameter_list|(
name|cx
parameter_list|,
name|dat
parameter_list|,
name|s
parameter_list|)
define|\
value|cx->blk_loop.label = PL_curcop->cop_label;			\ 	cx->blk_loop.resetsp = s - PL_stack_base;			\ 	cx->blk_loop.redo_op = cLOOP->op_redoop;			\ 	cx->blk_loop.next_op = cLOOP->op_nextop;			\ 	cx->blk_loop.last_op = cLOOP->op_lastop;			\ 	cx->blk_loop.iterlval = Nullsv;					\ 	cx->blk_loop.iterary = Nullav;					\ 	cx->blk_loop.iterix = -1;					\ 	CX_ITERDATA_SET(cx,dat);
end_define

begin_define
define|#
directive|define
name|POPLOOP
parameter_list|(
name|cx
parameter_list|)
define|\
value|SvREFCNT_dec(cx->blk_loop.iterlval);				\ 	if (CxITERVAR(cx)) {						\ 	    SV **s_v_p = CxITERVAR(cx);					\ 	    sv_2mortal(*s_v_p);						\ 	    *s_v_p = cx->blk_loop.itersave;				\ 	}								\ 	if (cx->blk_loop.iterary&& cx->blk_loop.iterary != PL_curstack)\ 	    SvREFCNT_dec(cx->blk_loop.iterary);
end_define

begin_comment
comment|/* context common to subroutines, evals and loops */
end_comment

begin_struct
struct|struct
name|block
block|{
name|I32
name|blku_oldsp
decl_stmt|;
comment|/* stack pointer to copy stuff down to */
name|COP
modifier|*
name|blku_oldcop
decl_stmt|;
comment|/* old curcop pointer */
name|I32
name|blku_oldretsp
decl_stmt|;
comment|/* return stack index */
name|I32
name|blku_oldmarksp
decl_stmt|;
comment|/* mark stack index */
name|I32
name|blku_oldscopesp
decl_stmt|;
comment|/* scope stack index */
name|PMOP
modifier|*
name|blku_oldpm
decl_stmt|;
comment|/* values of pattern match vars */
name|U8
name|blku_gimme
decl_stmt|;
comment|/* is this block running in list context? */
union|union
block|{
name|struct
name|block_sub
name|blku_sub
decl_stmt|;
name|struct
name|block_eval
name|blku_eval
decl_stmt|;
name|struct
name|block_loop
name|blku_loop
decl_stmt|;
block|}
name|blk_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|blk_oldsp
value|cx_u.cx_blk.blku_oldsp
end_define

begin_define
define|#
directive|define
name|blk_oldcop
value|cx_u.cx_blk.blku_oldcop
end_define

begin_define
define|#
directive|define
name|blk_oldretsp
value|cx_u.cx_blk.blku_oldretsp
end_define

begin_define
define|#
directive|define
name|blk_oldmarksp
value|cx_u.cx_blk.blku_oldmarksp
end_define

begin_define
define|#
directive|define
name|blk_oldscopesp
value|cx_u.cx_blk.blku_oldscopesp
end_define

begin_define
define|#
directive|define
name|blk_oldpm
value|cx_u.cx_blk.blku_oldpm
end_define

begin_define
define|#
directive|define
name|blk_gimme
value|cx_u.cx_blk.blku_gimme
end_define

begin_define
define|#
directive|define
name|blk_sub
value|cx_u.cx_blk.blk_u.blku_sub
end_define

begin_define
define|#
directive|define
name|blk_eval
value|cx_u.cx_blk.blk_u.blku_eval
end_define

begin_define
define|#
directive|define
name|blk_loop
value|cx_u.cx_blk.blk_u.blku_loop
end_define

begin_comment
comment|/* Enter a block. */
end_comment

begin_define
define|#
directive|define
name|PUSHBLOCK
parameter_list|(
name|cx
parameter_list|,
name|t
parameter_list|,
name|sp
parameter_list|)
value|CXINC, cx =&cxstack[cxstack_ix],		\ 	cx->cx_type		= t,					\ 	cx->blk_oldsp		= sp - PL_stack_base,			\ 	cx->blk_oldcop		= PL_curcop,				\ 	cx->blk_oldmarksp	= PL_markstack_ptr - PL_markstack,	\ 	cx->blk_oldscopesp	= PL_scopestack_ix,			\ 	cx->blk_oldretsp	= PL_retstack_ix,			\ 	cx->blk_oldpm		= PL_curpm,				\ 	cx->blk_gimme		= gimme;				\ 	DEBUG_l( PerlIO_printf(Perl_debug_log, "Entering block %ld, type %s\n",	\ 		    (long)cxstack_ix, PL_block_type[CxTYPE(cx)]); )
end_define

begin_comment
comment|/* Exit a block (RETURN and LAST). */
end_comment

begin_define
define|#
directive|define
name|POPBLOCK
parameter_list|(
name|cx
parameter_list|,
name|pm
parameter_list|)
value|cx =&cxstack[cxstack_ix--],			\ 	newsp		 = PL_stack_base + cx->blk_oldsp,		\ 	PL_curcop	 = cx->blk_oldcop,				\ 	PL_markstack_ptr = PL_markstack + cx->blk_oldmarksp,		\ 	PL_scopestack_ix = cx->blk_oldscopesp,				\ 	PL_retstack_ix	 = cx->blk_oldretsp,				\ 	pm		 = cx->blk_oldpm,				\ 	gimme		 = cx->blk_gimme;				\ 	DEBUG_l( PerlIO_printf(Perl_debug_log, "Leaving block %ld, type %s\n",		\ 		    (long)cxstack_ix+1,PL_block_type[CxTYPE(cx)]); )
end_define

begin_comment
comment|/* Continue a block elsewhere (NEXT and REDO). */
end_comment

begin_define
define|#
directive|define
name|TOPBLOCK
parameter_list|(
name|cx
parameter_list|)
value|cx  =&cxstack[cxstack_ix],			\ 	PL_stack_sp	 = PL_stack_base + cx->blk_oldsp,		\ 	PL_markstack_ptr = PL_markstack + cx->blk_oldmarksp,		\ 	PL_scopestack_ix = cx->blk_oldscopesp,				\ 	PL_retstack_ix	 = cx->blk_oldretsp,				\ 	PL_curpm         = cx->blk_oldpm
end_define

begin_comment
comment|/* substitution context */
end_comment

begin_struct
struct|struct
name|subst
block|{
name|I32
name|sbu_iters
decl_stmt|;
name|I32
name|sbu_maxiters
decl_stmt|;
name|I32
name|sbu_rflags
decl_stmt|;
name|I32
name|sbu_oldsave
decl_stmt|;
name|bool
name|sbu_once
decl_stmt|;
name|bool
name|sbu_rxtainted
decl_stmt|;
name|char
modifier|*
name|sbu_orig
decl_stmt|;
name|SV
modifier|*
name|sbu_dstr
decl_stmt|;
name|SV
modifier|*
name|sbu_targ
decl_stmt|;
name|char
modifier|*
name|sbu_s
decl_stmt|;
name|char
modifier|*
name|sbu_m
decl_stmt|;
name|char
modifier|*
name|sbu_strend
decl_stmt|;
name|void
modifier|*
name|sbu_rxres
decl_stmt|;
name|REGEXP
modifier|*
name|sbu_rx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sb_iters
value|cx_u.cx_subst.sbu_iters
end_define

begin_define
define|#
directive|define
name|sb_maxiters
value|cx_u.cx_subst.sbu_maxiters
end_define

begin_define
define|#
directive|define
name|sb_rflags
value|cx_u.cx_subst.sbu_rflags
end_define

begin_define
define|#
directive|define
name|sb_oldsave
value|cx_u.cx_subst.sbu_oldsave
end_define

begin_define
define|#
directive|define
name|sb_once
value|cx_u.cx_subst.sbu_once
end_define

begin_define
define|#
directive|define
name|sb_rxtainted
value|cx_u.cx_subst.sbu_rxtainted
end_define

begin_define
define|#
directive|define
name|sb_orig
value|cx_u.cx_subst.sbu_orig
end_define

begin_define
define|#
directive|define
name|sb_dstr
value|cx_u.cx_subst.sbu_dstr
end_define

begin_define
define|#
directive|define
name|sb_targ
value|cx_u.cx_subst.sbu_targ
end_define

begin_define
define|#
directive|define
name|sb_s
value|cx_u.cx_subst.sbu_s
end_define

begin_define
define|#
directive|define
name|sb_m
value|cx_u.cx_subst.sbu_m
end_define

begin_define
define|#
directive|define
name|sb_strend
value|cx_u.cx_subst.sbu_strend
end_define

begin_define
define|#
directive|define
name|sb_rxres
value|cx_u.cx_subst.sbu_rxres
end_define

begin_define
define|#
directive|define
name|sb_rx
value|cx_u.cx_subst.sbu_rx
end_define

begin_define
define|#
directive|define
name|PUSHSUBST
parameter_list|(
name|cx
parameter_list|)
value|CXINC, cx =&cxstack[cxstack_ix],			\ 	cx->sb_iters		= iters,				\ 	cx->sb_maxiters		= maxiters,				\ 	cx->sb_rflags		= r_flags,				\ 	cx->sb_oldsave		= oldsave,				\ 	cx->sb_once		= once,					\ 	cx->sb_rxtainted	= rxtainted,				\ 	cx->sb_orig		= orig,					\ 	cx->sb_dstr		= dstr,					\ 	cx->sb_targ		= targ,					\ 	cx->sb_s		= s,					\ 	cx->sb_m		= m,					\ 	cx->sb_strend		= strend,				\ 	cx->sb_rxres		= Null(void*),				\ 	cx->sb_rx		= rx,					\ 	cx->cx_type		= CXt_SUBST;				\ 	rxres_save(&cx->sb_rxres, rx)
end_define

begin_define
define|#
directive|define
name|POPSUBST
parameter_list|(
name|cx
parameter_list|)
value|cx =&cxstack[cxstack_ix--];			\ 	rxres_free(&cx->sb_rxres)
end_define

begin_struct
struct|struct
name|context
block|{
name|U32
name|cx_type
decl_stmt|;
comment|/* what kind of context this is */
union|union
block|{
name|struct
name|block
name|cx_blk
decl_stmt|;
name|struct
name|subst
name|cx_subst
decl_stmt|;
block|}
name|cx_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CXTYPEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|CXt_NULL
value|0
end_define

begin_define
define|#
directive|define
name|CXt_SUB
value|1
end_define

begin_define
define|#
directive|define
name|CXt_EVAL
value|2
end_define

begin_define
define|#
directive|define
name|CXt_LOOP
value|3
end_define

begin_define
define|#
directive|define
name|CXt_SUBST
value|4
end_define

begin_define
define|#
directive|define
name|CXt_BLOCK
value|5
end_define

begin_define
define|#
directive|define
name|CXt_FORMAT
value|6
end_define

begin_comment
comment|/* private flags for CXt_EVAL */
end_comment

begin_define
define|#
directive|define
name|CXp_REAL
value|0x00000100
end_define

begin_comment
comment|/* truly eval'', not a lookalike */
end_comment

begin_define
define|#
directive|define
name|CXp_TRYBLOCK
value|0x00000200
end_define

begin_comment
comment|/* eval{}, not eval'' or similar */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ITHREADS
end_ifdef

begin_comment
comment|/* private flags for CXt_LOOP */
end_comment

begin_define
define|#
directive|define
name|CXp_PADVAR
value|0x00000100
end_define

begin_comment
comment|/* itervar lives on pad, iterdata 					   has pad offset; if not set, 					   iterdata holds GV* */
end_comment

begin_define
define|#
directive|define
name|CxPADLOOP
parameter_list|(
name|c
parameter_list|)
value|(((c)->cx_type& (CXt_LOOP|CXp_PADVAR))		\ 			 == (CXt_LOOP|CXp_PADVAR))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CxTYPE
parameter_list|(
name|c
parameter_list|)
value|((c)->cx_type& CXTYPEMASK)
end_define

begin_define
define|#
directive|define
name|CxREALEVAL
parameter_list|(
name|c
parameter_list|)
value|(((c)->cx_type& (CXt_EVAL|CXp_REAL))		\ 			 == (CXt_EVAL|CXp_REAL))
end_define

begin_define
define|#
directive|define
name|CxTRYBLOCK
parameter_list|(
name|c
parameter_list|)
value|(((c)->cx_type& (CXt_EVAL|CXp_TRYBLOCK))	\ 			 == (CXt_EVAL|CXp_TRYBLOCK))
end_define

begin_define
define|#
directive|define
name|CXINC
value|(cxstack_ix< cxstack_max ? ++cxstack_ix : (cxstack_ix = cxinc()))
end_define

begin_comment
comment|/* "gimme" values */
end_comment

begin_comment
comment|/* =for apidoc AmU||G_SCALAR Used to indicate scalar context.  See C<GIMME_V>, C<GIMME>, and L<perlcall>.  =for apidoc AmU||G_ARRAY Used to indicate list context.  See C<GIMME_V>, C<GIMME> and L<perlcall>.  =for apidoc AmU||G_VOID Used to indicate void context.  See C<GIMME_V> and L<perlcall>.  =for apidoc AmU||G_DISCARD Indicates that arguments returned from a callback should be discarded.  See L<perlcall>.  =for apidoc AmU||G_EVAL  Used to force a Perl C<eval> wrapper around a callback.  See L<perlcall>.  =for apidoc AmU||G_NOARGS  Indicates that no arguments are being sent to a callback.  See L<perlcall>.  =cut */
end_comment

begin_define
define|#
directive|define
name|G_SCALAR
value|0
end_define

begin_define
define|#
directive|define
name|G_ARRAY
value|1
end_define

begin_define
define|#
directive|define
name|G_VOID
value|128
end_define

begin_comment
comment|/* skip this bit when adding flags below */
end_comment

begin_comment
comment|/* extra flags for Perl_call_* routines */
end_comment

begin_define
define|#
directive|define
name|G_DISCARD
value|2
end_define

begin_comment
comment|/* Call FREETMPS. */
end_comment

begin_define
define|#
directive|define
name|G_EVAL
value|4
end_define

begin_comment
comment|/* Assume eval {} around subroutine call. */
end_comment

begin_define
define|#
directive|define
name|G_NOARGS
value|8
end_define

begin_comment
comment|/* Don't construct a @_ array. */
end_comment

begin_define
define|#
directive|define
name|G_KEEPERR
value|16
end_define

begin_comment
comment|/* Append errors to $@, don't overwrite it */
end_comment

begin_define
define|#
directive|define
name|G_NODEBUG
value|32
end_define

begin_comment
comment|/* Disable debugging at toplevel.  */
end_comment

begin_define
define|#
directive|define
name|G_METHOD
value|64
end_define

begin_comment
comment|/* Calling method. */
end_comment

begin_comment
comment|/* flag bits for PL_in_eval */
end_comment

begin_define
define|#
directive|define
name|EVAL_NULL
value|0
end_define

begin_comment
comment|/* not in an eval */
end_comment

begin_define
define|#
directive|define
name|EVAL_INEVAL
value|1
end_define

begin_comment
comment|/* some enclosing scope is an eval */
end_comment

begin_define
define|#
directive|define
name|EVAL_WARNONLY
value|2
end_define

begin_comment
comment|/* used by yywarn() when calling yyerror() */
end_comment

begin_define
define|#
directive|define
name|EVAL_KEEPERR
value|4
end_define

begin_comment
comment|/* set by Perl_call_sv if G_KEEPERR */
end_comment

begin_define
define|#
directive|define
name|EVAL_INREQUIRE
value|8
end_define

begin_comment
comment|/* The code is being required. */
end_comment

begin_comment
comment|/* Support for switching (stack and block) contexts.  * This ensures magic doesn't invalidate local stack and cx pointers.  */
end_comment

begin_define
define|#
directive|define
name|PERLSI_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|PERLSI_UNDEF
value|0
end_define

begin_define
define|#
directive|define
name|PERLSI_MAIN
value|1
end_define

begin_define
define|#
directive|define
name|PERLSI_MAGIC
value|2
end_define

begin_define
define|#
directive|define
name|PERLSI_SORT
value|3
end_define

begin_define
define|#
directive|define
name|PERLSI_SIGNAL
value|4
end_define

begin_define
define|#
directive|define
name|PERLSI_OVERLOAD
value|5
end_define

begin_define
define|#
directive|define
name|PERLSI_DESTROY
value|6
end_define

begin_define
define|#
directive|define
name|PERLSI_WARNHOOK
value|7
end_define

begin_define
define|#
directive|define
name|PERLSI_DIEHOOK
value|8
end_define

begin_define
define|#
directive|define
name|PERLSI_REQUIRE
value|9
end_define

begin_struct
struct|struct
name|stackinfo
block|{
name|AV
modifier|*
name|si_stack
decl_stmt|;
comment|/* stack for current runlevel */
name|PERL_CONTEXT
modifier|*
name|si_cxstack
decl_stmt|;
comment|/* context stack for runlevel */
name|I32
name|si_cxix
decl_stmt|;
comment|/* current context index */
name|I32
name|si_cxmax
decl_stmt|;
comment|/* maximum allocated index */
name|I32
name|si_type
decl_stmt|;
comment|/* type of runlevel */
name|struct
name|stackinfo
modifier|*
name|si_prev
decl_stmt|;
name|struct
name|stackinfo
modifier|*
name|si_next
decl_stmt|;
name|I32
name|si_markoff
decl_stmt|;
comment|/* offset where markstack begins for us. 					 * currently used only with DEBUGGING, 					 * but not #ifdef-ed for bincompat */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|stackinfo
name|PERL_SI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|cxstack
value|(PL_curstackinfo->si_cxstack)
end_define

begin_define
define|#
directive|define
name|cxstack_ix
value|(PL_curstackinfo->si_cxix)
end_define

begin_define
define|#
directive|define
name|cxstack_max
value|(PL_curstackinfo->si_cxmax)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_define
define|#
directive|define
name|SET_MARK_OFFSET
define|\
value|PL_curstackinfo->si_markoff = PL_markstack_ptr - PL_markstack
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_MARK_OFFSET
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PUSHSTACKi
parameter_list|(
name|type
parameter_list|)
define|\
value|STMT_START {							\ 	PERL_SI *next = PL_curstackinfo->si_next;			\ 	if (!next) {							\ 	    next = new_stackinfo(32, 2048/sizeof(PERL_CONTEXT) - 1);	\ 	    next->si_prev = PL_curstackinfo;				\ 	    PL_curstackinfo->si_next = next;				\ 	}								\ 	next->si_type = type;						\ 	next->si_cxix = -1;						\ 	AvFILLp(next->si_stack) = 0;					\ 	SWITCHSTACK(PL_curstack,next->si_stack);			\ 	PL_curstackinfo = next;						\ 	SET_MARK_OFFSET;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHSTACK
value|PUSHSTACKi(PERLSI_UNKNOWN)
end_define

begin_comment
comment|/* POPSTACK works with PL_stack_sp, so it may need to be bracketed by  * PUTBACK/SPAGAIN to flush/refresh any local SP that may be active */
end_comment

begin_define
define|#
directive|define
name|POPSTACK
define|\
value|STMT_START {							\ 	dSP;								\ 	PERL_SI *prev = PL_curstackinfo->si_prev;			\ 	if (!prev) {							\ 	    PerlIO_printf(Perl_error_log, "panic: POPSTACK\n");		\ 	    my_exit(1);							\ 	}								\ 	SWITCHSTACK(PL_curstack,prev->si_stack);			\
comment|/* don't free prev here, free them all at the END{} */
value|\ 	PL_curstackinfo = prev;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|POPSTACK_TO
parameter_list|(
name|s
parameter_list|)
define|\
value|STMT_START {							\ 	while (PL_curstack != s) {					\ 	    dounwind(-1);						\ 	    POPSTACK;							\ 	}								\     } STMT_END
end_define

end_unit

