begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_ITHREADS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<win32thread.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_PTHREADS_API
end_ifdef

begin_comment
comment|/* Here be dragons. */
end_comment

begin_define
define|#
directive|define
name|DETACH
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_detach(&(t)->self)) {			\ 	    MUTEX_UNLOCK(&(t)->mutex);				\ 	    Perl_croak_nocontext("panic: DETACH");		\ 	}							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|PERL_GET_CONTEXT
value|Perl_get_context()
end_define

begin_define
define|#
directive|define
name|PERL_SET_CONTEXT
parameter_list|(
name|t
parameter_list|)
value|Perl_set_context((void*)t)
end_define

begin_define
define|#
directive|define
name|PTHREAD_GETSPECIFIC_INT
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DJGPP
end_ifdef

begin_define
define|#
directive|define
name|pthread_addr_t
value|any_t
end_define

begin_define
define|#
directive|define
name|NEED_PTHREAD_INIT
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE_JOINABLE
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OPEN_VM
end_ifdef

begin_define
define|#
directive|define
name|pthread_addr_t
value|void *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_define
define|#
directive|define
name|pthread_attr_init
parameter_list|(
name|a
parameter_list|)
value|pthread_attr_create(a)
end_define

begin_define
define|#
directive|define
name|PTHREAD_ATTR_SETDETACHSTATE
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|pthread_setdetach_np(a,s)
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|pthread_create(t,a,s,d)
end_define

begin_define
define|#
directive|define
name|pthread_key_create
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|)
value|pthread_keycreate(k,(pthread_destructor_t)(d))
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_init
parameter_list|(
name|a
parameter_list|)
value|pthread_mutexattr_create(a)
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_settype
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|pthread_mutexattr_setkind_np(a,t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ux_version
argument_list|)
operator|&&
name|__ux_version
operator|<=
literal|1020
end_if

begin_define
define|#
directive|define
name|pthread_attr_init
parameter_list|(
name|a
parameter_list|)
value|pthread_attr_create(a)
end_define

begin_comment
comment|/* XXX pthread_setdetach_np() missing in DCE threads on HP-UX 10.20 */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_ATTR_SETDETACHSTATE
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|PTHREAD_CREATE
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|pthread_create(t,a,s,d)
end_define

begin_define
define|#
directive|define
name|pthread_key_create
parameter_list|(
name|k
parameter_list|,
name|d
parameter_list|)
value|pthread_keycreate(k,(pthread_destructor_t)(d))
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_init
parameter_list|(
name|a
parameter_list|)
value|pthread_mutexattr_create(a)
end_define

begin_define
define|#
directive|define
name|pthread_mutexattr_settype
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|pthread_mutexattr_setkind_np(a,t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DJGPP
argument_list|)
operator|||
name|defined
argument_list|(
name|__OPEN_VM
argument_list|)
end_if

begin_define
define|#
directive|define
name|PTHREAD_ATTR_SETDETACHSTATE
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|pthread_attr_setdetachstate(a,&(s))
end_define

begin_define
define|#
directive|define
name|YIELD
value|pthread_yield(NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__hpux
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__ux_version
argument_list|)
operator|||
name|__ux_version
operator|>
literal|1020
end_if

begin_define
define|#
directive|define
name|pthread_mutexattr_default
value|NULL
end_define

begin_define
define|#
directive|define
name|pthread_condattr_default
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTHREAD_CREATE
end_ifndef

begin_comment
comment|/* You are not supposed to pass NULL as the 2nd arg of PTHREAD_CREATE(). */
end_comment

begin_define
define|#
directive|define
name|PTHREAD_CREATE
parameter_list|(
name|t
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|)
value|pthread_create(t,&(a),s,d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTHREAD_ATTR_SETDETACHSTATE
end_ifndef

begin_define
define|#
directive|define
name|PTHREAD_ATTR_SETDETACHSTATE
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|pthread_attr_setdetachstate(a,s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTHREAD_CREATE_JOINABLE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_PTHREAD_CREATE_JOINABLE
end_ifdef

begin_define
define|#
directive|define
name|PTHREAD_CREATE_JOINABLE
value|OLD_PTHREAD_CREATE_JOINABLE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTHREAD_CREATE_JOINABLE
value|0
end_define

begin_comment
comment|/* Panic?  No, guess. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|I_MACH_CTHREADS
end_ifdef

begin_comment
comment|/* cthreads interface */
end_comment

begin_comment
comment|/* #include<mach/cthreads.h> is in perl.h #ifdef I_MACH_CTHREADS */
end_comment

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	*m = mutex_alloc();					\ 	if (*m) {						\ 	    mutex_init(*m);					\ 	} else {						\ 	    Perl_croak_nocontext("panic: MUTEX_INIT");		\ 	}							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
value|mutex_lock(*m)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
value|mutex_unlock(*m)
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	mutex_free(*m);						\ 	*m = 0;							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_INIT
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	*c = condition_alloc();					\ 	if (*c) {						\ 	    condition_init(*c);					\ 	}							\ 	else {							\ 	    Perl_croak_nocontext("panic: COND_INIT");		\ 	}							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
value|condition_signal(*c)
end_define

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
value|condition_broadcast(*c)
end_define

begin_define
define|#
directive|define
name|COND_WAIT
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|condition_wait(*c, *m)
end_define

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	condition_free(*c);					\ 	*c = 0;							\     } STMT_END
end_define

begin_define
define|#
directive|define
name|THREAD_CREATE
parameter_list|(
name|thr
parameter_list|,
name|f
parameter_list|)
value|(thr->self = cthread_fork(f, thr), 0)
end_define

begin_define
define|#
directive|define
name|THREAD_POST_CREATE
parameter_list|(
name|thr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|THREAD_RET_TYPE
value|any_t
end_define

begin_define
define|#
directive|define
name|THREAD_RET_CAST
parameter_list|(
name|x
parameter_list|)
value|((any_t) x)
end_define

begin_define
define|#
directive|define
name|DETACH
parameter_list|(
name|t
parameter_list|)
value|cthread_detach(t->self)
end_define

begin_define
define|#
directive|define
name|JOIN
parameter_list|(
name|t
parameter_list|,
name|avp
parameter_list|)
value|(*(avp) = (AV *)cthread_join(t->self))
end_define

begin_define
define|#
directive|define
name|PERL_SET_CONTEXT
parameter_list|(
name|t
parameter_list|)
value|cthread_set_data(cthread_self(), t)
end_define

begin_define
define|#
directive|define
name|PERL_GET_CONTEXT
value|cthread_data(cthread_self())
end_define

begin_define
define|#
directive|define
name|INIT_THREADS
value|cthread_init()
end_define

begin_define
define|#
directive|define
name|YIELD
value|cthread_yield()
end_define

begin_define
define|#
directive|define
name|ALLOC_THREAD_KEY
value|NOOP
end_define

begin_define
define|#
directive|define
name|FREE_THREAD_KEY
value|NOOP
end_define

begin_define
define|#
directive|define
name|SET_THREAD_SELF
parameter_list|(
name|thr
parameter_list|)
value|(thr->self = cthread_self())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I_MACH_CTHREADS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YIELD
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SCHED_YIELD
end_ifdef

begin_define
define|#
directive|define
name|YIELD
value|SCHED_YIELD
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_SCHED_YIELD
end_ifdef

begin_define
define|#
directive|define
name|YIELD
value|sched_yield()
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_PTHREAD_YIELD
end_ifdef

begin_comment
comment|/* pthread_yield(NULL) platforms are expected      * to have #defined YIELD for themselves. */
end_comment

begin_define
define|#
directive|define
name|YIELD
value|pthread_yield()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__hpux
end_ifdef

begin_define
define|#
directive|define
name|MUTEX_INIT_NEEDS_MUTEX_ZEROED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX_INIT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MUTEX_INIT_NEEDS_MUTEX_ZEROED
end_ifdef

begin_comment
comment|/* Temporary workaround, true bug is deeper. --jhi 1999-02-25 */
end_comment

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	Zero((m), 1, perl_mutex);                               \  	if (pthread_mutex_init((m), pthread_mutexattr_default))	\ 	    Perl_croak_nocontext("panic: MUTEX_INIT");		\     } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_mutex_init((m), pthread_mutexattr_default))	\ 	    Perl_croak_nocontext("panic: MUTEX_INIT");		\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_mutex_lock((m)))				\ 	    Perl_croak_nocontext("panic: MUTEX_LOCK");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_mutex_unlock((m)))				\ 	    Perl_croak_nocontext("panic: MUTEX_UNLOCK");	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_mutex_destroy((m)))				\ 	    Perl_croak_nocontext("panic: MUTEX_DESTROY");	\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUTEX_INIT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COND_INIT
end_ifndef

begin_define
define|#
directive|define
name|COND_INIT
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_cond_init((c), pthread_condattr_default))	\ 	    Perl_croak_nocontext("panic: COND_INIT");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_cond_signal((c)))				\ 	    Perl_croak_nocontext("panic: COND_SIGNAL");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_cond_broadcast((c)))			\ 	    Perl_croak_nocontext("panic: COND_BROADCAST");	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_WAIT
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_cond_wait((c), (m)))			\ 	    Perl_croak_nocontext("panic: COND_WAIT");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_cond_destroy((c)))				\ 	    Perl_croak_nocontext("panic: COND_DESTROY");	\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COND_INIT */
end_comment

begin_comment
comment|/* DETACH(t) must only be called while holding t->mutex */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DETACH
end_ifndef

begin_define
define|#
directive|define
name|DETACH
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_detach((t)->self)) {			\ 	    MUTEX_UNLOCK(&(t)->mutex);				\ 	    Perl_croak_nocontext("panic: DETACH");		\ 	}							\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DETACH */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|JOIN
end_ifndef

begin_define
define|#
directive|define
name|JOIN
parameter_list|(
name|t
parameter_list|,
name|avp
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_join((t)->self, (void**)(avp)))		\ 	    Perl_croak_nocontext("panic: pthread_join");	\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JOIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_GET_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_GET_CONTEXT
value|pthread_getspecific(PL_thr_key)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PERL_SET_CONTEXT
end_ifndef

begin_define
define|#
directive|define
name|PERL_SET_CONTEXT
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {						\ 	if (pthread_setspecific(PL_thr_key, (void *)(t)))	\ 	    Perl_croak_nocontext("panic: pthread_setspecific");	\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_SET_CONTEXT */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INIT_THREADS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_PTHREAD_INIT
end_ifdef

begin_define
define|#
directive|define
name|INIT_THREADS
value|pthread_init()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ALLOC_THREAD_KEY
end_ifndef

begin_define
define|#
directive|define
name|ALLOC_THREAD_KEY
define|\
value|STMT_START {						\ 	if (pthread_key_create(&PL_thr_key, 0))	{		\ 	    PerlIO_printf(PerlIO_stderr(), "panic: pthread_key_create");	\ 	    exit(1);						\ 	}							\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FREE_THREAD_KEY
end_ifndef

begin_define
define|#
directive|define
name|FREE_THREAD_KEY
define|\
value|STMT_START {						\ 	pthread_key_delete(PL_thr_key);				\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|THREAD_RET_TYPE
end_ifndef

begin_define
define|#
directive|define
name|THREAD_RET_TYPE
value|void *
end_define

begin_define
define|#
directive|define
name|THREAD_RET_CAST
parameter_list|(
name|p
parameter_list|)
value|((void *)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THREAD_RET */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
end_if

begin_comment
comment|/* Accessor for per-thread SVs */
end_comment

begin_define
define|#
directive|define
name|THREADSV
parameter_list|(
name|i
parameter_list|)
value|(thr->threadsvp[i])
end_define

begin_comment
comment|/*  * LOCK_SV_MUTEX and UNLOCK_SV_MUTEX are performance-critical. Here, we  * try only locking them if there may be more than one thread in existence.  * Systems with very fast mutexes (and/or slow conditionals) may wish to  * remove the "if (threadnum) ..." test.  * XXX do NOT use C<if (PL_threadnum) ...> -- it sets up race conditions!  */
end_comment

begin_define
define|#
directive|define
name|LOCK_SV_MUTEX
value|MUTEX_LOCK(&PL_sv_mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK_SV_MUTEX
value|MUTEX_UNLOCK(&PL_sv_mutex)
end_define

begin_define
define|#
directive|define
name|LOCK_STRTAB_MUTEX
value|MUTEX_LOCK(&PL_strtab_mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK_STRTAB_MUTEX
value|MUTEX_UNLOCK(&PL_strtab_mutex)
end_define

begin_define
define|#
directive|define
name|LOCK_CRED_MUTEX
value|MUTEX_LOCK(&PL_cred_mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK_CRED_MUTEX
value|MUTEX_UNLOCK(&PL_cred_mutex)
end_define

begin_define
define|#
directive|define
name|LOCK_FDPID_MUTEX
value|MUTEX_LOCK(&PL_fdpid_mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK_FDPID_MUTEX
value|MUTEX_UNLOCK(&PL_fdpid_mutex)
end_define

begin_define
define|#
directive|define
name|LOCK_SV_LOCK_MUTEX
value|MUTEX_LOCK(&PL_sv_lock_mutex)
end_define

begin_define
define|#
directive|define
name|UNLOCK_SV_LOCK_MUTEX
value|MUTEX_UNLOCK(&PL_sv_lock_mutex)
end_define

begin_comment
comment|/* Values and macros for thr->flags */
end_comment

begin_define
define|#
directive|define
name|THRf_STATE_MASK
value|7
end_define

begin_define
define|#
directive|define
name|THRf_R_JOINABLE
value|0
end_define

begin_define
define|#
directive|define
name|THRf_R_JOINED
value|1
end_define

begin_define
define|#
directive|define
name|THRf_R_DETACHED
value|2
end_define

begin_define
define|#
directive|define
name|THRf_ZOMBIE
value|3
end_define

begin_define
define|#
directive|define
name|THRf_DEAD
value|4
end_define

begin_define
define|#
directive|define
name|THRf_DID_DIE
value|8
end_define

begin_comment
comment|/* ThrSTATE(t) and ThrSETSTATE(t) must only be called while holding t->mutex */
end_comment

begin_define
define|#
directive|define
name|ThrSTATE
parameter_list|(
name|t
parameter_list|)
value|((t)->flags& THRf_STATE_MASK)
end_define

begin_define
define|#
directive|define
name|ThrSETSTATE
parameter_list|(
name|t
parameter_list|,
name|s
parameter_list|)
value|STMT_START {		\ 	(t)->flags&= ~THRf_STATE_MASK;		\ 	(t)->flags |= (s);			\ 	DEBUG_S(PerlIO_printf(Perl_debug_log,	\ 			      "thread %p set to state %d\n", (t), (s))); \     } STMT_END
end_define

begin_typedef
typedef|typedef
struct|struct
name|condpair
block|{
name|perl_mutex
name|mutex
decl_stmt|;
comment|/* Protects all other fields */
name|perl_cond
name|owner_cond
decl_stmt|;
comment|/* For when owner changes at all */
name|perl_cond
name|cond
decl_stmt|;
comment|/* For cond_signal and cond_broadcast */
name|Thread
name|owner
decl_stmt|;
comment|/* Currently owning thread */
block|}
name|condpair_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MgMUTEXP
parameter_list|(
name|mg
parameter_list|)
value|(&((condpair_t *)(mg->mg_ptr))->mutex)
end_define

begin_define
define|#
directive|define
name|MgOWNERCONDP
parameter_list|(
name|mg
parameter_list|)
value|(&((condpair_t *)(mg->mg_ptr))->owner_cond)
end_define

begin_define
define|#
directive|define
name|MgCONDP
parameter_list|(
name|mg
parameter_list|)
value|(&((condpair_t *)(mg->mg_ptr))->cond)
end_define

begin_define
define|#
directive|define
name|MgOWNER
parameter_list|(
name|mg
parameter_list|)
value|((condpair_t *)(mg->mg_ptr))->owner
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS || USE_ITHREADS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX_LOCK
end_ifndef

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX_UNLOCK
end_ifndef

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX_INIT
end_ifndef

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MUTEX_DESTROY
end_ifndef

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COND_INIT
end_ifndef

begin_define
define|#
directive|define
name|COND_INIT
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COND_SIGNAL
end_ifndef

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COND_BROADCAST
end_ifndef

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COND_WAIT
end_ifndef

begin_define
define|#
directive|define
name|COND_WAIT
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|COND_DESTROY
end_ifndef

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SV_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_SV_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCK_SV_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|UNLOCK_SV_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_STRTAB_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_STRTAB_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCK_STRTAB_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|UNLOCK_STRTAB_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_CRED_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_CRED_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCK_CRED_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|UNLOCK_CRED_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_FDPID_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_FDPID_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCK_FDPID_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|UNLOCK_FDPID_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCK_SV_LOCK_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|LOCK_SV_LOCK_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCK_SV_LOCK_MUTEX
end_ifndef

begin_define
define|#
directive|define
name|UNLOCK_SV_LOCK_MUTEX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THR, SET_THR, and dTHR are there for compatibility with old versions */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THR
end_ifndef

begin_define
define|#
directive|define
name|THR
value|PERL_GET_THX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SET_THR
end_ifndef

begin_define
define|#
directive|define
name|SET_THR
parameter_list|(
name|t
parameter_list|)
value|PERL_SET_THX(t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|dTHR
end_ifndef

begin_define
define|#
directive|define
name|dTHR
value|dNOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INIT_THREADS
end_ifndef

begin_define
define|#
directive|define
name|INIT_THREADS
value|NOOP
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

