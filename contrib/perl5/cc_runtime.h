begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|DOOP
parameter_list|(
name|ppname
parameter_list|)
value|PUTBACK; PL_op = ppname(ARGS); SPAGAIN
end_define

begin_define
define|#
directive|define
name|PP_LIST
parameter_list|(
name|g
parameter_list|)
value|do {			\ 	dMARK;				\ 	if (g != G_ARRAY) {		\ 	    if (++MARK<= SP)		\ 		*MARK = *SP;		\ 	    else			\ 		*MARK =&PL_sv_undef;	\ 	    SP = MARK;			\ 	}				\    } while (0)
end_define

begin_define
define|#
directive|define
name|MAYBE_TAINT_SASSIGN_SRC
parameter_list|(
name|sv
parameter_list|)
define|\
value|if (PL_tainting&& PL_tainted&& (!SvGMAGICAL(left) || !SvSMAGICAL(left) || \                                 !((mg=mg_find(left, 't'))&& mg->mg_len& 1)))\         TAINT_NOT
end_define

begin_define
define|#
directive|define
name|PP_PREINC
parameter_list|(
name|sv
parameter_list|)
value|do {	\ 	if (SvIOK(sv)) {	\             ++SvIVX(sv);	\ 	    SvFLAGS(sv)&= ~(SVf_NOK|SVf_POK|SVp_NOK|SVp_POK); \ 	}			\ 	else			\ 	    sv_inc(sv);		\ 	SvSETMAGIC(sv);		\     } while (0)
end_define

begin_define
define|#
directive|define
name|PP_UNSTACK
value|do {		\ 	TAINT_NOT;		\ 	PL_stack_sp = PL_stack_base + cxstack[cxstack_ix].blk_oldsp;	\ 	FREETMPS;		\ 	oldsave = PL_scopestack[PL_scopestack_ix - 1]; \ 	LEAVE_SCOPE(oldsave);	\ 	SPAGAIN;		\     } while(0)
end_define

begin_comment
comment|/* Anyone using eval "" deserves this mess */
end_comment

begin_define
define|#
directive|define
name|PP_EVAL
parameter_list|(
name|ppaddr
parameter_list|,
name|nxt
parameter_list|)
value|do {		\ 	dJMPENV;				\ 	int ret;				\ 	PUTBACK;				\ 	JMPENV_PUSH(ret);			\ 	switch (ret) {				\ 	case 0:					\ 	    PL_op = ppaddr(ARGS);			\ 	    PL_retstack[PL_retstack_ix - 1] = Nullop;	\ 	    if (PL_op != nxt) CALLRUNOPS();		\ 	    JMPENV_POP;				\ 	    break;				\ 	case 1: JMPENV_POP; JMPENV_JUMP(1);	\ 	case 2: JMPENV_POP; JMPENV_JUMP(2);	\ 	case 3:					\ 	    JMPENV_POP;				\ 	    if (PL_restartop != nxt)		\ 		JMPENV_JUMP(3);			\ 	}					\ 	PL_op = nxt;				\ 	SPAGAIN;				\     } while (0)
end_define

begin_define
define|#
directive|define
name|PP_ENTERTRY
parameter_list|(
name|jmpbuf
parameter_list|,
name|label
parameter_list|)
value|do {		\ 	dJMPENV;				\ 	int ret;				\ 	JMPENV_PUSH(ret);			\ 	switch (ret) {				\ 	case 1: JMPENV_POP; JMPENV_JUMP(1);	\ 	case 2: JMPENV_POP; JMPENV_JUMP(2);	\ 	case 3: JMPENV_POP; SPAGAIN; goto label;\ 	}					\     } while (0)
end_define

end_unit

