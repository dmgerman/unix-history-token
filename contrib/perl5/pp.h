begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    pp.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
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

begin_define
define|#
directive|define
name|PP
parameter_list|(
name|s
parameter_list|)
value|OP * Perl_##s(pTHX)
end_define

begin_comment
comment|/* =for apidoc AmU||SP Stack pointer.  This is usually handled by C<xsubpp>.  See C<dSP> and C<SPAGAIN>.  =for apidoc AmU||MARK Stack marker variable for the XSUB.  See C<dMARK>.  =for apidoc Ams||PUSHMARK Opening bracket for arguments on a callback.  See C<PUTBACK> and L<perlcall>.  =for apidoc Ams||dSP Declares a local copy of perl's stack pointer for the XSUB, available via the C<SP> macro.  See C<SP>.  =for apidoc Ams||dMARK Declare a stack marker variable, C<mark>, for the XSUB.  See C<MARK> and C<dORIGMARK>.  =for apidoc Ams||dORIGMARK Saves the original stack mark for the XSUB.  See C<ORIGMARK>.  =for apidoc AmU||ORIGMARK The original stack mark for the XSUB.  See C<dORIGMARK>.  =for apidoc Ams||SPAGAIN Refetch the stack pointer.  Used after a callback.  See L<perlcall>.  =cut */
end_comment

begin_undef
undef|#
directive|undef
name|SP
end_undef

begin_comment
comment|/* Solaris 2.7 i386 has this in /usr/include/sys/reg.h */
end_comment

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
name|dSP
value|register SV **sp = PL_stack_sp
end_define

begin_define
define|#
directive|define
name|djSP
value|dSP
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
value|return Perl_die
end_define

begin_comment
comment|/* =for apidoc Ams||PUTBACK Closing bracket for XSUB arguments.  This is usually handled by C<xsubpp>. See C<PUSHMARK> and L<perlcall> for other uses.  =for apidoc Amn|SV*|POPs Pops an SV off the stack.  =for apidoc Amn|char*|POPp Pops a string off the stack.  =for apidoc Amn|NV|POPn Pops a double off the stack.  =for apidoc Amn|IV|POPi Pops an integer off the stack.  =for apidoc Amn|long|POPl Pops a long off the stack.  =cut */
end_comment

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
name|POPul
value|((unsigned long)SvIVx(POPs))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_QUAD
end_ifdef

begin_define
define|#
directive|define
name|POPq
value|((Quad_t)SvIVx(POPs))
end_define

begin_define
define|#
directive|define
name|POPuq
value|((Uquad_t)SvUVx(POPs))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|TOPul
value|((unsigned long)SvUV(TOPs))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_QUAD
end_ifdef

begin_define
define|#
directive|define
name|TOPq
value|((Quad_t)SvIV(TOPs))
end_define

begin_define
define|#
directive|define
name|TOPuq
value|((Uquad_t)SvUV(TOPs))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Go to some pains in the rare event that we must extend the stack. */
end_comment

begin_comment
comment|/* =for apidoc Am|void|EXTEND|SP|int nitems Used to extend the argument stack for an XSUB's return values. Once used, guarantees that there is room for at least C<nitems> to be pushed onto the stack.  =for apidoc Am|void|PUSHs|SV* sv Push an SV onto the stack.  The stack must have room for this element. Does not handle 'set' magic.  See C<XPUSHs>.  =for apidoc Am|void|PUSHp|char* str|STRLEN len Push a string onto the stack.  The stack must have room for this element. The C<len> indicates the length of the string.  Handles 'set' magic.  See C<XPUSHp>.  =for apidoc Am|void|PUSHn|NV nv Push a double onto the stack.  The stack must have room for this element. Handles 'set' magic.  See C<XPUSHn>.  =for apidoc Am|void|PUSHi|IV iv Push an integer onto the stack.  The stack must have room for this element. Handles 'set' magic.  See C<XPUSHi>.  =for apidoc Am|void|PUSHu|UV uv Push an unsigned integer onto the stack.  The stack must have room for this element.  See C<XPUSHu>.  =for apidoc Am|void|XPUSHs|SV* sv Push an SV onto the stack, extending the stack if necessary.  Does not handle 'set' magic.  See C<PUSHs>.  =for apidoc Am|void|XPUSHp|char* str|STRLEN len Push a string onto the stack, extending the stack if necessary.  The C<len> indicates the length of the string.  Handles 'set' magic.  See C<PUSHp>.  =for apidoc Am|void|XPUSHn|NV nv Push a double onto the stack, extending the stack if necessary.  Handles 'set' magic.  See C<PUSHn>.  =for apidoc Am|void|XPUSHi|IV iv Push an integer onto the stack, extending the stack if necessary.  Handles 'set' magic. See C<PUSHi>.  =for apidoc Am|void|XPUSHu|UV uv Push an unsigned integer onto the stack, extending the stack if necessary. See C<PUSHu>.  =cut */
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
value|STMT_START { sv_setnv(TARG, (NV)(n)); PUSHTARG; } STMT_END
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
value|STMT_START { sv_setnv(TARG, (NV)(n)); XPUSHTARG; } STMT_END
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
name|XPUSHundef
value|STMT_START { SvOK_off(TARG); XPUSHs(TARG); } STMT_END
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
value|STMT_START { sv_setnv(TARG, (NV)(n)); SETTARG; } STMT_END
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
value|NV value = TOPn
end_define

begin_define
define|#
directive|define
name|dPOPnv
value|NV value = POPn
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_QUAD
end_ifdef

begin_define
define|#
directive|define
name|dTOPqv
value|Quad_t value = TOPu
end_define

begin_define
define|#
directive|define
name|dPOPqv
value|Quad_t value = POPu
end_define

begin_define
define|#
directive|define
name|dTOPuqv
value|Uquad_t value = TOPuq
end_define

begin_define
define|#
directive|define
name|dPOPuqv
value|Uquad_t value = POPuq
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|NV right = POPn; NV left = CAT2(X,n)
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
value|NV right = POPn;				\     SV *leftsv = CAT2(X,s);				\     NV left = USE_LEFT(leftsv) ? SvNV(leftsv) : 0.0
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

begin_comment
comment|/* See OPpTARGET_MY: */
end_comment

begin_define
define|#
directive|define
name|MAXARG
value|(PL_op->op_private& 15)
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
value|STMT_START {							\ 	AvFILLp(f) = sp - PL_stack_base;				\ 	PL_stack_base = AvARRAY(t);					\ 	PL_stack_max = PL_stack_base + AvMAX(t);			\ 	sp = PL_stack_sp = PL_stack_base + AvFILLp(t);			\ 	PL_curstack = t;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|EXTEND_MORTAL
parameter_list|(
name|n
parameter_list|)
define|\
value|STMT_START {							\ 	if (PL_tmps_ix + (n)>= PL_tmps_max)				\ 	    tmps_grow(n);						\     } STMT_END
end_define

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
parameter_list|,
name|shift
parameter_list|,
name|ret
parameter_list|)
value|STMT_START { \           if (PL_amagic_generation) { \ 	    SV* tmpsv; \ 	    SV* arg= sp[shift]; \ 	  am_again: \ 	    if ((SvAMAGIC(arg))&&\ 		(tmpsv=AMG_CALLun(arg,meth))) {\ 	       SPAGAIN; if (shift) sp += shift; \ 	       set(tmpsv); ret; } \ 	  } \ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|FORCE_SETs
parameter_list|(
name|sv
parameter_list|)
value|STMT_START { sv_setsv(TARG, (sv)); SETTARG; } STMT_END
end_define

begin_define
define|#
directive|define
name|tryAMAGICun
parameter_list|(
name|meth
parameter_list|)
value|tryAMAGICunW(meth,SETsvUN,0,RETURN)
end_define

begin_define
define|#
directive|define
name|tryAMAGICunSET
parameter_list|(
name|meth
parameter_list|)
value|tryAMAGICunW(meth,SETs,0,RETURN)
end_define

begin_define
define|#
directive|define
name|tryAMAGICunTARGET
parameter_list|(
name|meth
parameter_list|,
name|shift
parameter_list|)
define|\
value|{ dSP; sp--;
comment|/* get TARGET from below PL_stack_sp */
value|\ 	    { dTARGETSTACKED; 						\ 		{ dSP; tryAMAGICunW(meth,FORCE_SETs,shift,RETURN);}}}
end_define

begin_define
define|#
directive|define
name|setAGAIN
parameter_list|(
name|ref
parameter_list|)
value|sv = ref;							\   if (!SvROK(ref))								\       Perl_croak(aTHX_ "Overloaded dereference did not return a reference");	\   if (ref != arg&& SvRV(ref) != SvRV(arg)) {					\       arg = ref;								\       goto am_again;								\   }
end_define

begin_define
define|#
directive|define
name|tryAMAGICunDEREF
parameter_list|(
name|meth
parameter_list|)
value|tryAMAGICunW(meth,setAGAIN,0,(void)0)
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
value|STMT_START {					\ 		if (opASSIGN || (SvFLAGS(TARG)& SVs_PADMY))		\ 		   { sv_setsv(TARG, (sv)); SETTARG; }			\ 		else SETs(sv); } STMT_END
end_define

begin_define
define|#
directive|define
name|SETsvUN
parameter_list|(
name|sv
parameter_list|)
value|STMT_START {					\ 		if (SvFLAGS(TARG)& SVs_PADMY)		\ 		   { sv_setsv(TARG, (sv)); SETTARG; }			\ 		else SETs(sv); } STMT_END
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

begin_comment
comment|/* =for apidoc mU||LVRET True if this op will be the return value of an lvalue subroutine  =cut */
end_comment

begin_define
define|#
directive|define
name|LVRET
value|((PL_op->op_private& OPpMAYBE_LVSUB)&& is_lvalue_sub())
end_define

end_unit

