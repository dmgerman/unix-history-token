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

begin_comment
comment|/* #define SAVEt_ALLOC		28 */
end_comment

begin_comment
comment|/* defined in 5.005_5x */
end_comment

begin_define
define|#
directive|define
name|SAVEt_GENERIC_SVREF
value|29
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
value|STMT_START {						\ 	push_scope();						\ 	DEBUG_l(WITH_THR(deb("ENTER scope %ld at %s:%d\n",	\ 		    PL_scopestack_ix, __FILE__, __LINE__)));	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|LEAVE
define|\
value|STMT_START {						\ 	DEBUG_l(WITH_THR(deb("LEAVE scope %ld at %s:%d\n",	\ 		    PL_scopestack_ix, __FILE__, __LINE__)));	\ 	pop_scope();						\     } STMT_END
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
name|SAVEFREESV
parameter_list|(
name|s
parameter_list|)
value|save_freesv((SV*)(s))
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_define
define|#
directive|define
name|CALLDESTRUCTOR
value|this->*SSPOPDPTR
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
value|save_destructor((DESTRUCTORFUNC)(FUNC_NAME_TO_PTR(f)),	\ 			  SOFT_CAST(void*)(p))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CALLDESTRUCTOR
value|*SSPOPDPTR
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
value|save_destructor(SOFT_CAST(void(*)_((void*)))(FUNC_NAME_TO_PTR(f)), \ 			  SOFT_CAST(void*)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|je_ret
decl_stmt|;
comment|/* return value of last setjmp() */
name|bool
name|je_mustcatch
decl_stmt|;
comment|/* longjmp()s must be caught locally */
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
value|STMT_START {					\ 	cur_env.je_prev = PL_top_env;			\ 	OP_REG_TO_MEM;					\ 	cur_env.je_ret = PerlProc_setjmp(cur_env.je_buf, 1);	\ 	OP_MEM_TO_REG;					\ 	PL_top_env =&cur_env;				\ 	cur_env.je_mustcatch = FALSE;			\ 	(v) = cur_env.je_ret;				\     } STMT_END
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
value|STMT_START {						\ 	OP_REG_TO_MEM;						\ 	if (PL_top_env->je_prev)					\ 	    PerlProc_longjmp(PL_top_env->je_buf, (v));			\ 	if ((v) == 2)						\ 	    PerlProc_exit(STATUS_NATIVE_EXPORT);				\ 	PerlIO_printf(PerlIO_stderr(), "panic: top_env\n");	\ 	PerlProc_exit(1);						\     } STMT_END
end_define

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

