begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    pp.h  *  *    Copyright (c) 1991-1999, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_define
define|#
directive|define
name|ARGS
value|thr
end_define

begin_define
define|#
directive|define
name|dARGS
value|struct perl_thread *thr;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARGS
end_define

begin_define
define|#
directive|define
name|dARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_define
define|#
directive|define
name|PP
parameter_list|(
name|s
parameter_list|)
value|OP * CPerlObj::s(ARGSproto)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PP
parameter_list|(
name|s
parameter_list|)
value|OP * s(ARGSproto)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SP
value|sp
end_define

begin_define
define|#
directive|define
name|MARK
value|mark
end_define

begin_define
define|#
directive|define
name|TARG
value|targ
end_define

begin_define
define|#
directive|define
name|PUSHMARK
parameter_list|(
name|p
parameter_list|)
value|if (++PL_markstack_ptr == PL_markstack_max)	\ 			markstack_grow();			\ 		    *PL_markstack_ptr = (p) - PL_stack_base
end_define

begin_define
define|#
directive|define
name|TOPMARK
value|(*PL_markstack_ptr)
end_define

begin_define
define|#
directive|define
name|POPMARK
value|(*PL_markstack_ptr--)
end_define

begin_define
define|#
directive|define
name|djSP
value|register SV **sp = PL_stack_sp
end_define

begin_define
define|#
directive|define
name|dSP
value|dTHR; djSP
end_define

begin_define
define|#
directive|define
name|dMARK
value|register SV **mark = PL_stack_base + POPMARK
end_define

begin_define
define|#
directive|define
name|dORIGMARK
value|I32 origmark = mark - PL_stack_base
end_define

begin_define
define|#
directive|define
name|SETORIGMARK
value|origmark = mark - PL_stack_base
end_define

begin_define
define|#
directive|define
name|ORIGMARK
value|(PL_stack_base + origmark)
end_define

begin_define
define|#
directive|define
name|SPAGAIN
value|sp = PL_stack_sp
end_define

begin_define
define|#
directive|define
name|MSPAGAIN
value|sp = PL_stack_sp; mark = ORIGMARK
end_define

begin_define
define|#
directive|define
name|GETTARGETSTACKED
value|targ = (PL_op->op_flags& OPf_STACKED ? POPs : PAD_SV(PL_op->op_targ))
end_define

begin_define
define|#
directive|define
name|dTARGETSTACKED
value|SV * GETTARGETSTACKED
end_define

begin_define
define|#
directive|define
name|GETTARGET
value|targ = PAD_SV(PL_op->op_targ)
end_define

begin_define
define|#
directive|define
name|dTARGET
value|SV * GETTARGET
end_define

begin_define
define|#
directive|define
name|GETATARGET
value|targ = (PL_op->op_flags& OPf_STACKED ? sp[-1] : PAD_SV(PL_op->op_targ))
end_define

begin_define
define|#
directive|define
name|dATARGET
value|SV * GETATARGET
end_define

begin_define
define|#
directive|define
name|dTARG
value|SV *targ
end_define

begin_define
define|#
directive|define
name|NORMAL
value|PL_op->op_next
end_define

begin_define
define|#
directive|define
name|DIE
value|return die
end_define

begin_define
define|#
directive|define
name|PUTBACK
value|PL_stack_sp = sp
end_define

begin_define
define|#
directive|define
name|RETURN
value|return PUTBACK, NORMAL
end_define

begin_define
define|#
directive|define
name|RETURNOP
parameter_list|(
name|o
parameter_list|)
value|return PUTBACK, o
end_define

begin_define
define|#
directive|define
name|RETURNX
parameter_list|(
name|x
parameter_list|)
value|return x, PUTBACK, NORMAL
end_define

begin_define
define|#
directive|define
name|POPs
value|(*sp--)
end_define

begin_define
define|#
directive|define
name|POPp
value|(SvPVx(POPs, PL_na))
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|POPpx
value|(SvPVx(POPs, n_a))
end_define

begin_define
define|#
directive|define
name|POPn
value|(SvNVx(POPs))
end_define

begin_define
define|#
directive|define
name|POPi
value|((IV)SvIVx(POPs))
end_define

begin_define
define|#
directive|define
name|POPu
value|((UV)SvUVx(POPs))
end_define

begin_define
define|#
directive|define
name|POPl
value|((long)SvIVx(POPs))
end_define

begin_define
define|#
directive|define
name|TOPs
value|(*sp)
end_define

begin_define
define|#
directive|define
name|TOPp
value|(SvPV(TOPs, PL_na))
end_define

begin_comment
comment|/* deprecated */
end_comment

begin_define
define|#
directive|define
name|TOPpx
value|(SvPV(TOPs, n_a))
end_define

begin_define
define|#
directive|define
name|TOPn
value|(SvNV(TOPs))
end_define

begin_define
define|#
directive|define
name|TOPi
value|((IV)SvIV(TOPs))
end_define

begin_define
define|#
directive|define
name|TOPu
value|((UV)SvUV(TOPs))
end_define

begin_define
define|#
directive|define
name|TOPl
value|((long)SvIV(TOPs))
end_define

begin_comment
comment|/* Go to some pains in the rare event that we must extend the stack. */
end_comment

begin_define
define|#
directive|define
name|EXTEND
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|STMT_START { if (PL_stack_max - p< (n)) {		\ 			    sp = stack_grow(sp,p, (int) (n));		\ 			} } STMT_END
end_define

begin_comment
comment|/* Same thing, but update mark register too. */
end_comment

begin_define
define|#
directive|define
name|MEXTEND
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|STMT_START {if (PL_stack_max - p< (n)) {		\ 			    int markoff = mark - PL_stack_base;		\ 			    sp = stack_grow(sp,p,(int) (n));		\ 			    mark = PL_stack_base + markoff;		\ 			} } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHs
parameter_list|(
name|s
parameter_list|)
value|(*++sp = (s))
end_define

begin_define
define|#
directive|define
name|PUSHTARG
value|STMT_START { SvSETMAGIC(TARG); PUSHs(TARG); } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHp
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|STMT_START { sv_setpvn(TARG, (p), (l)); PUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHn
parameter_list|(
name|n
parameter_list|)
value|STMT_START { sv_setnv(TARG, (double)(n)); PUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHi
parameter_list|(
name|i
parameter_list|)
value|STMT_START { sv_setiv(TARG, (IV)(i)); PUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|PUSHu
parameter_list|(
name|u
parameter_list|)
value|STMT_START { sv_setuv(TARG, (UV)(u)); PUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHs
parameter_list|(
name|s
parameter_list|)
value|STMT_START { EXTEND(sp,1); (*++sp = (s)); } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHTARG
value|STMT_START { SvSETMAGIC(TARG); XPUSHs(TARG); } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHp
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|STMT_START { sv_setpvn(TARG, (p), (l)); XPUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHn
parameter_list|(
name|n
parameter_list|)
value|STMT_START { sv_setnv(TARG, (double)(n)); XPUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHi
parameter_list|(
name|i
parameter_list|)
value|STMT_START { sv_setiv(TARG, (IV)(i)); XPUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|XPUSHu
parameter_list|(
name|u
parameter_list|)
value|STMT_START { sv_setuv(TARG, (UV)(u)); XPUSHTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|SETs
parameter_list|(
name|s
parameter_list|)
value|(*sp = s)
end_define

begin_define
define|#
directive|define
name|SETTARG
value|STMT_START { SvSETMAGIC(TARG); SETs(TARG); } STMT_END
end_define

begin_define
define|#
directive|define
name|SETp
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|STMT_START { sv_setpvn(TARG, (p), (l)); SETTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|SETn
parameter_list|(
name|n
parameter_list|)
value|STMT_START { sv_setnv(TARG, (double)(n)); SETTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|SETi
parameter_list|(
name|i
parameter_list|)
value|STMT_START { sv_setiv(TARG, (IV)(i)); SETTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|SETu
parameter_list|(
name|u
parameter_list|)
value|STMT_START { sv_setuv(TARG, (UV)(u)); SETTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|dTOPss
value|SV *sv = TOPs
end_define

begin_define
define|#
directive|define
name|dPOPss
value|SV *sv = POPs
end_define

begin_define
define|#
directive|define
name|dTOPnv
value|double value = TOPn
end_define

begin_define
define|#
directive|define
name|dPOPnv
value|double value = POPn
end_define

begin_define
define|#
directive|define
name|dTOPiv
value|IV value = TOPi
end_define

begin_define
define|#
directive|define
name|dPOPiv
value|IV value = POPi
end_define

begin_define
define|#
directive|define
name|dTOPuv
value|UV value = TOPu
end_define

begin_define
define|#
directive|define
name|dPOPuv
value|UV value = POPu
end_define

begin_define
define|#
directive|define
name|dPOPXssrl
parameter_list|(
name|X
parameter_list|)
value|SV *right = POPs; SV *left = CAT2(X,s)
end_define

begin_define
define|#
directive|define
name|dPOPXnnrl
parameter_list|(
name|X
parameter_list|)
value|double right = POPn; double left = CAT2(X,n)
end_define

begin_define
define|#
directive|define
name|dPOPXiirl
parameter_list|(
name|X
parameter_list|)
value|IV right = POPi; IV left = CAT2(X,i)
end_define

begin_define
define|#
directive|define
name|USE_LEFT
parameter_list|(
name|sv
parameter_list|)
define|\
value|(SvOK(sv) || SvGMAGICAL(sv) || !(PL_op->op_flags& OPf_STACKED))
end_define

begin_define
define|#
directive|define
name|dPOPXnnrl_ul
parameter_list|(
name|X
parameter_list|)
define|\
value|double right = POPn;				\     SV *leftsv = CAT2(X,s);				\     double left = USE_LEFT(leftsv) ? SvNV(leftsv) : 0.0
end_define

begin_define
define|#
directive|define
name|dPOPXiirl_ul
parameter_list|(
name|X
parameter_list|)
define|\
value|IV right = POPi;					\     SV *leftsv = CAT2(X,s);				\     IV left = USE_LEFT(leftsv) ? SvIV(leftsv) : 0
end_define

begin_define
define|#
directive|define
name|dPOPPOPssrl
value|dPOPXssrl(POP)
end_define

begin_define
define|#
directive|define
name|dPOPPOPnnrl
value|dPOPXnnrl(POP)
end_define

begin_define
define|#
directive|define
name|dPOPPOPnnrl_ul
value|dPOPXnnrl_ul(POP)
end_define

begin_define
define|#
directive|define
name|dPOPPOPiirl
value|dPOPXiirl(POP)
end_define

begin_define
define|#
directive|define
name|dPOPPOPiirl_ul
value|dPOPXiirl_ul(POP)
end_define

begin_define
define|#
directive|define
name|dPOPTOPssrl
value|dPOPXssrl(TOP)
end_define

begin_define
define|#
directive|define
name|dPOPTOPnnrl
value|dPOPXnnrl(TOP)
end_define

begin_define
define|#
directive|define
name|dPOPTOPnnrl_ul
value|dPOPXnnrl_ul(TOP)
end_define

begin_define
define|#
directive|define
name|dPOPTOPiirl
value|dPOPXiirl(TOP)
end_define

begin_define
define|#
directive|define
name|dPOPTOPiirl_ul
value|dPOPXiirl_ul(TOP)
end_define

begin_define
define|#
directive|define
name|RETPUSHYES
value|RETURNX(PUSHs(&PL_sv_yes))
end_define

begin_define
define|#
directive|define
name|RETPUSHNO
value|RETURNX(PUSHs(&PL_sv_no))
end_define

begin_define
define|#
directive|define
name|RETPUSHUNDEF
value|RETURNX(PUSHs(&PL_sv_undef))
end_define

begin_define
define|#
directive|define
name|RETSETYES
value|RETURNX(SETs(&PL_sv_yes))
end_define

begin_define
define|#
directive|define
name|RETSETNO
value|RETURNX(SETs(&PL_sv_no))
end_define

begin_define
define|#
directive|define
name|RETSETUNDEF
value|RETURNX(SETs(&PL_sv_undef))
end_define

begin_define
define|#
directive|define
name|ARGTARG
value|PL_op->op_targ
end_define

begin_define
define|#
directive|define
name|MAXARG
value|PL_op->op_private
end_define

begin_define
define|#
directive|define
name|SWITCHSTACK
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|STMT_START {							\ 	AvFILLp(f) = sp - PL_stack_base;					\ 	PL_stack_base = AvARRAY(t);					\ 	PL_stack_max = PL_stack_base + AvMAX(t);				\ 	sp = PL_stack_sp = PL_stack_base + AvFILLp(t);			\ 	PL_curstack = t;							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|EXTEND_MORTAL
parameter_list|(
name|n
parameter_list|)
define|\
value|STMT_START { \ 	    if (PL_tmps_ix + (n)>= PL_tmps_max) \ 		Renew(PL_tmps_stack, PL_tmps_max = PL_tmps_ix + (n) + 1, SV*); \ 	} STMT_END
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_define
define|#
directive|define
name|AMGf_noright
value|1
end_define

begin_define
define|#
directive|define
name|AMGf_noleft
value|2
end_define

begin_define
define|#
directive|define
name|AMGf_assign
value|4
end_define

begin_define
define|#
directive|define
name|AMGf_unary
value|8
end_define

begin_define
define|#
directive|define
name|tryAMAGICbinW
parameter_list|(
name|meth
parameter_list|,
name|assign
parameter_list|,
name|set
parameter_list|)
value|STMT_START { \           if (PL_amagic_generation) { \ 	    SV* tmpsv; \ 	    SV* right= *(sp); SV* left= *(sp-1);\ 	    if ((SvAMAGIC(left)||SvAMAGIC(right))&&\ 		(tmpsv=amagic_call(left, \ 				   right, \ 				   CAT2(meth,_amg), \ 				   (assign)? AMGf_assign: 0))) {\ 	       SPAGAIN;	\ 	       (void)POPs; set(tmpsv); RETURN; } \ 	  } \ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|tryAMAGICbin
parameter_list|(
name|meth
parameter_list|,
name|assign
parameter_list|)
value|tryAMAGICbinW(meth,assign,SETsv)
end_define

begin_define
define|#
directive|define
name|tryAMAGICbinSET
parameter_list|(
name|meth
parameter_list|,
name|assign
parameter_list|)
value|tryAMAGICbinW(meth,assign,SETs)
end_define

begin_define
define|#
directive|define
name|AMG_CALLun
parameter_list|(
name|sv
parameter_list|,
name|meth
parameter_list|)
value|amagic_call(sv,&PL_sv_undef,  \ 					CAT2(meth,_amg),AMGf_noright | AMGf_unary)
end_define

begin_define
define|#
directive|define
name|AMG_CALLbinL
parameter_list|(
name|left
parameter_list|,
name|right
parameter_list|,
name|meth
parameter_list|)
define|\
value|amagic_call(left,right,CAT2(meth,_amg),AMGf_noright)
end_define

begin_define
define|#
directive|define
name|tryAMAGICunW
parameter_list|(
name|meth
parameter_list|,
name|set
parameter_list|)
value|STMT_START { \           if (PL_amagic_generation) { \ 	    SV* tmpsv; \ 	    SV* arg= *(sp); \ 	    if ((SvAMAGIC(arg))&&\ 		(tmpsv=AMG_CALLun(arg,meth))) {\ 	       SPAGAIN;	\ 	       set(tmpsv); RETURN; } \ 	  } \ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|tryAMAGICun
value|tryAMAGICunSET
end_define

begin_define
define|#
directive|define
name|tryAMAGICunSET
parameter_list|(
name|meth
parameter_list|)
value|tryAMAGICunW(meth,SETs)
end_define

begin_define
define|#
directive|define
name|opASSIGN
value|(PL_op->op_flags& OPf_STACKED)
end_define

begin_define
define|#
directive|define
name|SETsv
parameter_list|(
name|sv
parameter_list|)
value|STMT_START {					\ 		if (opASSIGN) { sv_setsv(TARG, (sv)); SETTARG; }	\ 		else SETs(sv); } STMT_END
end_define

begin_comment
comment|/* newSVsv does not behave as advertised, so we copy missing  * information by hand */
end_comment

begin_comment
comment|/* SV* ref causes confusion with the member variable    changed SV* ref to SV* tmpRef */
end_comment

begin_define
define|#
directive|define
name|RvDEEPCP
parameter_list|(
name|rv
parameter_list|)
value|STMT_START { SV* tmpRef=SvRV(rv);      \   if (SvREFCNT(tmpRef)>1) {                 \     SvREFCNT_dec(tmpRef);                   \     SvRV(rv)=AMG_CALLun(rv,copy);        \   } } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tryAMAGICbin
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tryAMAGICbinSET
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tryAMAGICun
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|tryAMAGICunSET
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OVERLOAD */
end_comment

end_unit

