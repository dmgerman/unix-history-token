begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|SAVEt_ITEM
value|0
end_define

begin_define
define|#
directive|define
name|SAVEt_SV
value|1
end_define

begin_define
define|#
directive|define
name|SAVEt_AV
value|2
end_define

begin_define
define|#
directive|define
name|SAVEt_HV
value|3
end_define

begin_define
define|#
directive|define
name|SAVEt_INT
value|4
end_define

begin_define
define|#
directive|define
name|SAVEt_LONG
value|5
end_define

begin_define
define|#
directive|define
name|SAVEt_I32
value|6
end_define

begin_define
define|#
directive|define
name|SAVEt_IV
value|7
end_define

begin_define
define|#
directive|define
name|SAVEt_SPTR
value|8
end_define

begin_define
define|#
directive|define
name|SAVEt_APTR
value|9
end_define

begin_define
define|#
directive|define
name|SAVEt_HPTR
value|10
end_define

begin_define
define|#
directive|define
name|SAVEt_PPTR
value|11
end_define

begin_define
define|#
directive|define
name|SAVEt_NSTAB
value|12
end_define

begin_define
define|#
directive|define
name|SAVEt_SVREF
value|13
end_define

begin_define
define|#
directive|define
name|SAVEt_GP
value|14
end_define

begin_define
define|#
directive|define
name|SAVEt_FREESV
value|15
end_define

begin_define
define|#
directive|define
name|SAVEt_FREEOP
value|16
end_define

begin_define
define|#
directive|define
name|SAVEt_FREEPV
value|17
end_define

begin_define
define|#
directive|define
name|SAVEt_CLEARSV
value|18
end_define

begin_define
define|#
directive|define
name|SAVEt_DELETE
value|19
end_define

begin_define
define|#
directive|define
name|SAVEt_DESTRUCTOR
value|20
end_define

begin_define
define|#
directive|define
name|SAVEt_REGCONTEXT
value|21
end_define

begin_define
define|#
directive|define
name|SAVEt_STACK_POS
value|22
end_define

begin_define
define|#
directive|define
name|SAVEt_I16
value|23
end_define

begin_define
define|#
directive|define
name|SAVEt_AELEM
value|24
end_define

begin_define
define|#
directive|define
name|SAVEt_HELEM
value|25
end_define

begin_define
define|#
directive|define
name|SAVEt_OP
value|26
end_define

begin_define
define|#
directive|define
name|SAVEt_HINTS
value|27
end_define

begin_define
define|#
directive|define
name|SAVEt_ALLOC
value|28
end_define

begin_define
define|#
directive|define
name|SAVEt_GENERIC_SVREF
value|29
end_define

begin_define
define|#
directive|define
name|SAVEt_DESTRUCTOR_X
value|30
end_define

begin_define
define|#
directive|define
name|SAVEt_VPTR
value|31
end_define

begin_define
define|#
directive|define
name|SAVEt_I8
value|32
end_define

begin_define
define|#
directive|define
name|SAVEt_COMPPAD
value|33
end_define

begin_define
define|#
directive|define
name|SAVEt_GENERIC_PVREF
value|34
end_define

begin_define
define|#
directive|define
name|SAVEt_PADSV
value|35
end_define

begin_define
define|#
directive|define
name|SAVEt_MORTALIZESV
value|36
end_define

begin_define
define|#
directive|define
name|SSCHECK
parameter_list|(
name|need
parameter_list|)
value|if (PL_savestack_ix + need> PL_savestack_max) savestack_grow()
end_define

begin_define
define|#
directive|define
name|SSPUSHINT
parameter_list|(
name|i
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_i32 = (I32)(i))
end_define

begin_define
define|#
directive|define
name|SSPUSHLONG
parameter_list|(
name|i
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_long = (long)(i))
end_define

begin_define
define|#
directive|define
name|SSPUSHIV
parameter_list|(
name|i
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_iv = (IV)(i))
end_define

begin_define
define|#
directive|define
name|SSPUSHPTR
parameter_list|(
name|p
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_ptr = (void*)(p))
end_define

begin_define
define|#
directive|define
name|SSPUSHDPTR
parameter_list|(
name|p
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_dptr = (p))
end_define

begin_define
define|#
directive|define
name|SSPUSHDXPTR
parameter_list|(
name|p
parameter_list|)
value|(PL_savestack[PL_savestack_ix++].any_dxptr = (p))
end_define

begin_define
define|#
directive|define
name|SSPOPINT
value|(PL_savestack[--PL_savestack_ix].any_i32)
end_define

begin_define
define|#
directive|define
name|SSPOPLONG
value|(PL_savestack[--PL_savestack_ix].any_long)
end_define

begin_define
define|#
directive|define
name|SSPOPIV
value|(PL_savestack[--PL_savestack_ix].any_iv)
end_define

begin_define
define|#
directive|define
name|SSPOPPTR
value|(PL_savestack[--PL_savestack_ix].any_ptr)
end_define

begin_define
define|#
directive|define
name|SSPOPDPTR
value|(PL_savestack[--PL_savestack_ix].any_dptr)
end_define

begin_define
define|#
directive|define
name|SSPOPDXPTR
value|(PL_savestack[--PL_savestack_ix].any_dxptr)
end_define

begin_comment
comment|/* =for apidoc Ams||SAVETMPS Opening bracket for temporaries on a callback.  See C<FREETMPS> and L<perlcall>.  =for apidoc Ams||FREETMPS Closing bracket for temporaries on a callback.  See C<SAVETMPS> and L<perlcall>.  =for apidoc Ams||ENTER Opening bracket on a callback.  See C<LEAVE> and L<perlcall>.  =for apidoc Ams||LEAVE Closing bracket on a callback.  See C<ENTER> and L<perlcall>.  =cut */
end_comment

begin_define
define|#
directive|define
name|SAVETMPS
value|save_int((int*)&PL_tmps_floor), PL_tmps_floor = PL_tmps_ix
end_define

begin_define
define|#
directive|define
name|FREETMPS
value|if (PL_tmps_ix> PL_tmps_floor) free_tmps()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_define
define|#
directive|define
name|ENTER
define|\
value|STMT_START {						\ 	push_scope();						\ 	DEBUG_l(WITH_THR(Perl_deb(aTHX_ "ENTER scope %ld at %s:%d\n",	\ 		    PL_scopestack_ix, __FILE__, __LINE__)));	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|LEAVE
define|\
value|STMT_START {						\ 	DEBUG_l(WITH_THR(Perl_deb(aTHX_ "LEAVE scope %ld at %s:%d\n",	\ 		    PL_scopestack_ix, __FILE__, __LINE__)));	\ 	pop_scope();						\     } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTER
value|push_scope()
end_define

begin_define
define|#
directive|define
name|LEAVE
value|pop_scope()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LEAVE_SCOPE
parameter_list|(
name|old
parameter_list|)
value|if (PL_savestack_ix> old) leave_scope(old)
end_define

begin_comment
comment|/*  * Not using SOFT_CAST on SAVESPTR, SAVEGENERICSV and SAVEFREESV  * because these are used for several kinds of pointer values  */
end_comment

begin_define
define|#
directive|define
name|SAVEI8
parameter_list|(
name|i
parameter_list|)
value|save_I8(SOFT_CAST(I8*)&(i))
end_define

begin_define
define|#
directive|define
name|SAVEI16
parameter_list|(
name|i
parameter_list|)
value|save_I16(SOFT_CAST(I16*)&(i))
end_define

begin_define
define|#
directive|define
name|SAVEI32
parameter_list|(
name|i
parameter_list|)
value|save_I32(SOFT_CAST(I32*)&(i))
end_define

begin_define
define|#
directive|define
name|SAVEINT
parameter_list|(
name|i
parameter_list|)
value|save_int(SOFT_CAST(int*)&(i))
end_define

begin_define
define|#
directive|define
name|SAVEIV
parameter_list|(
name|i
parameter_list|)
value|save_iv(SOFT_CAST(IV*)&(i))
end_define

begin_define
define|#
directive|define
name|SAVELONG
parameter_list|(
name|l
parameter_list|)
value|save_long(SOFT_CAST(long*)&(l))
end_define

begin_define
define|#
directive|define
name|SAVESPTR
parameter_list|(
name|s
parameter_list|)
value|save_sptr((SV**)&(s))
end_define

begin_define
define|#
directive|define
name|SAVEPPTR
parameter_list|(
name|s
parameter_list|)
value|save_pptr(SOFT_CAST(char**)&(s))
end_define

begin_define
define|#
directive|define
name|SAVEVPTR
parameter_list|(
name|s
parameter_list|)
value|save_vptr((void*)&(s))
end_define

begin_define
define|#
directive|define
name|SAVEPADSV
parameter_list|(
name|s
parameter_list|)
value|save_padsv(s)
end_define

begin_define
define|#
directive|define
name|SAVEFREESV
parameter_list|(
name|s
parameter_list|)
value|save_freesv((SV*)(s))
end_define

begin_define
define|#
directive|define
name|SAVEMORTALIZESV
parameter_list|(
name|s
parameter_list|)
value|save_mortalizesv((SV*)(s))
end_define

begin_define
define|#
directive|define
name|SAVEFREEOP
parameter_list|(
name|o
parameter_list|)
value|save_freeop(SOFT_CAST(OP*)(o))
end_define

begin_define
define|#
directive|define
name|SAVEFREEPV
parameter_list|(
name|p
parameter_list|)
value|save_freepv(SOFT_CAST(char*)(p))
end_define

begin_define
define|#
directive|define
name|SAVECLEARSV
parameter_list|(
name|sv
parameter_list|)
value|save_clearsv(SOFT_CAST(SV**)&(sv))
end_define

begin_define
define|#
directive|define
name|SAVEGENERICSV
parameter_list|(
name|s
parameter_list|)
value|save_generic_svref((SV**)&(s))
end_define

begin_define
define|#
directive|define
name|SAVEGENERICPV
parameter_list|(
name|s
parameter_list|)
value|save_generic_pvref((char**)&(s))
end_define

begin_define
define|#
directive|define
name|SAVEDELETE
parameter_list|(
name|h
parameter_list|,
name|k
parameter_list|,
name|l
parameter_list|)
define|\
value|save_delete(SOFT_CAST(HV*)(h), SOFT_CAST(char*)(k), (I32)(l))
end_define

begin_define
define|#
directive|define
name|SAVEDESTRUCTOR
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|save_destructor((DESTRUCTORFUNC_NOCONTEXT_t)(f), SOFT_CAST(void*)(p))
end_define

begin_define
define|#
directive|define
name|SAVEDESTRUCTOR_X
parameter_list|(
name|f
parameter_list|,
name|p
parameter_list|)
define|\
value|save_destructor_x((DESTRUCTORFUNC_t)(f), SOFT_CAST(void*)(p))
end_define

begin_define
define|#
directive|define
name|SAVESTACK_POS
parameter_list|()
define|\
value|STMT_START {				\ 	SSCHECK(2);				\ 	SSPUSHINT(PL_stack_sp - PL_stack_base);	\ 	SSPUSHINT(SAVEt_STACK_POS);		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|SAVEOP
parameter_list|()
value|save_op()
end_define

begin_define
define|#
directive|define
name|SAVEHINTS
parameter_list|()
define|\
value|STMT_START {				\ 	if (PL_hints& HINT_LOCALIZE_HH)	\ 	    save_hints();			\ 	else {					\ 	    SSCHECK(2);				\ 	    SSPUSHINT(PL_hints);		\ 	    SSPUSHINT(SAVEt_HINTS);		\ 	}					\     } STMT_END
end_define

begin_define
define|#
directive|define
name|SAVECOMPPAD
parameter_list|()
define|\
value|STMT_START {						\ 	if (PL_comppad&& PL_curpad == AvARRAY(PL_comppad)) {	\ 	    SSCHECK(2);						\ 	    SSPUSHPTR((SV*)PL_comppad);				\ 	    SSPUSHINT(SAVEt_COMPPAD);				\ 	}							\ 	else {							\ 	    SAVEVPTR(PL_curpad);				\ 	    SAVESPTR(PL_comppad);				\ 	}							\     } STMT_END
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_ITHREADS
end_ifdef

begin_define
define|#
directive|define
name|SAVECOPSTASH
parameter_list|(
name|c
parameter_list|)
value|SAVEPPTR(CopSTASHPV(c))
end_define

begin_define
define|#
directive|define
name|SAVECOPSTASH_FREE
parameter_list|(
name|c
parameter_list|)
value|SAVEGENERICPV(CopSTASHPV(c))
end_define

begin_define
define|#
directive|define
name|SAVECOPFILE
parameter_list|(
name|c
parameter_list|)
value|SAVEPPTR(CopFILE(c))
end_define

begin_define
define|#
directive|define
name|SAVECOPFILE_FREE
parameter_list|(
name|c
parameter_list|)
value|SAVEGENERICPV(CopFILE(c))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SAVECOPSTASH
parameter_list|(
name|c
parameter_list|)
value|SAVESPTR(CopSTASH(c))
end_define

begin_define
define|#
directive|define
name|SAVECOPSTASH_FREE
parameter_list|(
name|c
parameter_list|)
value|SAVECOPSTASH(c)
end_define

begin_comment
comment|/* XXX not refcounted */
end_comment

begin_define
define|#
directive|define
name|SAVECOPFILE
parameter_list|(
name|c
parameter_list|)
value|SAVESPTR(CopFILEGV(c))
end_define

begin_define
define|#
directive|define
name|SAVECOPFILE_FREE
parameter_list|(
name|c
parameter_list|)
value|SAVEGENERICSV(CopFILEGV(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SAVECOPLINE
parameter_list|(
name|c
parameter_list|)
value|SAVEI16(CopLINE(c))
end_define

begin_comment
comment|/* SSNEW() temporarily allocates a specified number of bytes of data on the  * savestack.  It returns an integer index into the savestack, because a  * pointer would get broken if the savestack is moved on reallocation.  * SSNEWa() works like SSNEW(), but also aligns the data to the specified  * number of bytes.  MEM_ALIGNBYTES is perhaps the most useful.  The  * alignment will be preserved therough savestack reallocation *only* if  * realloc returns data aligned to a size divisible by `align'!  *  * SSPTR() converts the index returned by SSNEW/SSNEWa() into a pointer.  */
end_comment

begin_define
define|#
directive|define
name|SSNEW
parameter_list|(
name|size
parameter_list|)
value|Perl_save_alloc(aTHX_ (size), 0)
end_define

begin_define
define|#
directive|define
name|SSNEWt
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|)
value|SSNEW((n)*sizeof(t))
end_define

begin_define
define|#
directive|define
name|SSNEWa
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
value|Perl_save_alloc(aTHX_ (size), \     (align - ((int)((caddr_t)&PL_savestack[PL_savestack_ix]) % align)) % align)
end_define

begin_define
define|#
directive|define
name|SSNEWat
parameter_list|(
name|n
parameter_list|,
name|t
parameter_list|,
name|align
parameter_list|)
value|SSNEWa((n)*sizeof(t), align)
end_define

begin_define
define|#
directive|define
name|SSPTR
parameter_list|(
name|off
parameter_list|,
name|type
parameter_list|)
value|((type)  ((char*)PL_savestack + off))
end_define

begin_define
define|#
directive|define
name|SSPTRt
parameter_list|(
name|off
parameter_list|,
name|type
parameter_list|)
value|((type*) ((char*)PL_savestack + off))
end_define

begin_comment
comment|/* A jmpenv packages the state required to perform a proper non-local jump.  * Note that there is a start_env initialized when perl starts, and top_env  * points to this initially, so top_env should always be non-null.  *  * Existence of a non-null top_env->je_prev implies it is valid to call  * longjmp() at that runlevel (we make sure start_env.je_prev is always  * null to ensure this).  *  * je_mustcatch, when set at any runlevel to TRUE, means eval ops must  * establish a local jmpenv to handle exception traps.  Care must be taken  * to restore the previous value of je_mustcatch before exiting the  * stack frame iff JMPENV_PUSH was not called in that stack frame.  * GSAR 97-03-27  */
end_comment

begin_struct
struct|struct
name|jmpenv
block|{
name|struct
name|jmpenv
modifier|*
name|je_prev
decl_stmt|;
name|Sigjmp_buf
name|je_buf
decl_stmt|;
comment|/* only for use if !je_throw */
name|int
name|je_ret
decl_stmt|;
comment|/* last exception thrown */
name|bool
name|je_mustcatch
decl_stmt|;
comment|/* need to call longjmp()? */
ifdef|#
directive|ifdef
name|PERL_FLEXIBLE_EXCEPTIONS
name|void
function_decl|(
modifier|*
name|je_throw
function_decl|)
parameter_list|(
name|int
name|v
parameter_list|)
function_decl|;
comment|/* last for bincompat */
name|bool
name|je_noset
decl_stmt|;
comment|/* no need for setjmp() */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|jmpenv
name|JMPENV
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|OP_IN_REGISTER
end_ifdef

begin_define
define|#
directive|define
name|OP_REG_TO_MEM
value|PL_opsave = op
end_define

begin_define
define|#
directive|define
name|OP_MEM_TO_REG
value|op = PL_opsave
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OP_REG_TO_MEM
value|NOOP
end_define

begin_define
define|#
directive|define
name|OP_MEM_TO_REG
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * How to build the first jmpenv.  *  * top_env needs to be non-zero. It points to an area  * in which longjmp() stuff is stored, as C callstack  * info there at least is thread specific this has to  * be per-thread. Otherwise a 'die' in a thread gives  * that thread the C stack of last thread to do an eval {}!  */
end_comment

begin_define
define|#
directive|define
name|JMPENV_BOOTSTRAP
define|\
value|STMT_START {				\ 	Zero(&PL_start_env, 1, JMPENV);		\ 	PL_start_env.je_ret = -1;		\ 	PL_start_env.je_mustcatch = TRUE;	\ 	PL_top_env =&PL_start_env;		\     } STMT_END
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_FLEXIBLE_EXCEPTIONS
end_ifdef

begin_comment
comment|/*  * These exception-handling macros are split up to  * ease integration with C++ exceptions.  *  * To use C++ try+catch to catch Perl exceptions, an extension author  * needs to first write an extern "C" function to throw an appropriate  * exception object; typically it will be or contain an integer,  * because Perl's internals use integers to track exception types:  *    extern "C" { static void thrower(int i) { throw i; } }  *  * Then (as shown below) the author needs to use, not the simple  * JMPENV_PUSH, but several of its constitutent macros, to arrange for  * the Perl internals to call thrower() rather than longjmp() to  * report exceptions:  *  *    dJMPENV;  *    JMPENV_PUSH_INIT(thrower);  *    try {  *        ... stuff that may throw exceptions ...  *    }  *    catch (int why) {  // or whatever matches thrower()  *        JMPENV_POST_CATCH;  *        EXCEPT_SET(why);  *        switch (why) {  *          ... // handle various Perl exception codes  *        }  *    }  *    JMPENV_POP;  // don't forget this!  */
end_comment

begin_comment
comment|/*  * Function that catches/throws, and its callback for the  *  body of protected processing.  */
end_comment

begin_typedef
typedef|typedef
name|void
operator|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|protect_body_t
argument_list|)
operator|)
operator|(
name|pTHX_
name|va_list
operator|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|*
operator|(
name|CPERLscope
argument_list|(
operator|*
name|protect_proc_t
argument_list|)
operator|)
operator|(
name|pTHX_
specifier|volatile
name|JMPENV
operator|*
name|pcur_env
operator|,
name|int
operator|*
operator|,
name|protect_body_t
operator|,
operator|...
operator|)
argument_list|;
end_typedef

begin_define
define|#
directive|define
name|dJMPENV
value|JMPENV cur_env;	\ 		volatile JMPENV *pcur_env = ((cur_env.je_noset = 0),&cur_env)
end_define

begin_define
define|#
directive|define
name|JMPENV_PUSH_INIT_ENV
parameter_list|(
name|ce
parameter_list|,
name|THROWFUNC
parameter_list|)
define|\
value|STMT_START {					\ 	(ce).je_throw = (THROWFUNC);			\ 	(ce).je_ret = -1;				\ 	(ce).je_mustcatch = FALSE;			\ 	(ce).je_prev = PL_top_env;			\ 	PL_top_env =&(ce);				\ 	OP_REG_TO_MEM;					\     } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_PUSH_INIT
parameter_list|(
name|THROWFUNC
parameter_list|)
value|JMPENV_PUSH_INIT_ENV(*(JMPENV*)pcur_env,THROWFUNC)
end_define

begin_define
define|#
directive|define
name|JMPENV_POST_CATCH_ENV
parameter_list|(
name|ce
parameter_list|)
define|\
value|STMT_START {					\ 	OP_MEM_TO_REG;					\ 	PL_top_env =&(ce);				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_POST_CATCH
value|JMPENV_POST_CATCH_ENV(*(JMPENV*)pcur_env)
end_define

begin_define
define|#
directive|define
name|JMPENV_PUSH_ENV
parameter_list|(
name|ce
parameter_list|,
name|v
parameter_list|)
define|\
value|STMT_START {						\ 	if (!(ce).je_noset) {					\ 	    DEBUG_l(Perl_deb(aTHX_ "Setting up jumplevel %p, was %p\n",	\ 			     ce, PL_top_env));			\ 	    JMPENV_PUSH_INIT_ENV(ce,NULL);			\ 	    EXCEPT_SET_ENV(ce,PerlProc_setjmp((ce).je_buf, 1));\ 	    (ce).je_noset = 1;					\ 	}							\ 	else							\ 	    EXCEPT_SET_ENV(ce,0);				\ 	JMPENV_POST_CATCH_ENV(ce);				\ 	(v) = EXCEPT_GET_ENV(ce);				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_PUSH
parameter_list|(
name|v
parameter_list|)
value|JMPENV_PUSH_ENV(*(JMPENV*)pcur_env,v)
end_define

begin_define
define|#
directive|define
name|JMPENV_POP_ENV
parameter_list|(
name|ce
parameter_list|)
define|\
value|STMT_START {						\ 	if (PL_top_env ==&(ce))				\ 	    PL_top_env = (ce).je_prev;				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_POP
value|JMPENV_POP_ENV(*(JMPENV*)pcur_env)
end_define

begin_define
define|#
directive|define
name|JMPENV_JUMP
parameter_list|(
name|v
parameter_list|)
define|\
value|STMT_START {						\ 	OP_REG_TO_MEM;						\ 	if (PL_top_env->je_prev) {				\ 	    if (PL_top_env->je_throw)				\ 		PL_top_env->je_throw(v);			\ 	    else						\ 		PerlProc_longjmp(PL_top_env->je_buf, (v));	\ 	}							\ 	if ((v) == 2)						\ 	    PerlProc_exit(STATUS_NATIVE_EXPORT);		\ 	PerlIO_printf(Perl_error_log, "panic: top_env\n");	\ 	PerlProc_exit(1);					\     } STMT_END
end_define

begin_define
define|#
directive|define
name|EXCEPT_GET_ENV
parameter_list|(
name|ce
parameter_list|)
value|((ce).je_ret)
end_define

begin_define
define|#
directive|define
name|EXCEPT_GET
value|EXCEPT_GET_ENV(*(JMPENV*)pcur_env)
end_define

begin_define
define|#
directive|define
name|EXCEPT_SET_ENV
parameter_list|(
name|ce
parameter_list|,
name|v
parameter_list|)
value|((ce).je_ret = (v))
end_define

begin_define
define|#
directive|define
name|EXCEPT_SET
parameter_list|(
name|v
parameter_list|)
value|EXCEPT_SET_ENV(*(JMPENV*)pcur_env,v)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !PERL_FLEXIBLE_EXCEPTIONS */
end_comment

begin_define
define|#
directive|define
name|dJMPENV
value|JMPENV cur_env
end_define

begin_define
define|#
directive|define
name|JMPENV_PUSH
parameter_list|(
name|v
parameter_list|)
define|\
value|STMT_START {							\ 	DEBUG_l(Perl_deb(aTHX_ "Setting up jumplevel %p, was %p\n",	\&cur_env, PL_top_env));			\ 	cur_env.je_prev = PL_top_env;					\ 	OP_REG_TO_MEM;							\ 	cur_env.je_ret = PerlProc_setjmp(cur_env.je_buf, 1);		\ 	OP_MEM_TO_REG;							\ 	PL_top_env =&cur_env;						\ 	cur_env.je_mustcatch = FALSE;					\ 	(v) = cur_env.je_ret;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_POP
define|\
value|STMT_START { PL_top_env = cur_env.je_prev; } STMT_END
end_define

begin_define
define|#
directive|define
name|JMPENV_JUMP
parameter_list|(
name|v
parameter_list|)
define|\
value|STMT_START {						\ 	OP_REG_TO_MEM;						\ 	if (PL_top_env->je_prev)				\ 	    PerlProc_longjmp(PL_top_env->je_buf, (v));		\ 	if ((v) == 2)						\ 	    PerlProc_exit(STATUS_NATIVE_EXPORT);		\ 	PerlIO_printf(PerlIO_stderr(), "panic: top_env\n");	\ 	PerlProc_exit(1);					\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_FLEXIBLE_EXCEPTIONS */
end_comment

begin_define
define|#
directive|define
name|CATCH_GET
value|(PL_top_env->je_mustcatch)
end_define

begin_define
define|#
directive|define
name|CATCH_SET
parameter_list|(
name|v
parameter_list|)
value|(PL_top_env->je_mustcatch = (v))
end_define

end_unit

