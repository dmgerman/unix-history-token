begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

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

begin_ifndef
ifndef|#
directive|ifndef
name|DJGPP
end_ifndef

begin_comment
comment|/* POSIXish threads */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_PTHREADS_API
end_ifdef

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
name|YIELD
value|pthread_yield()
end_define

begin_define
define|#
directive|define
name|DETACH
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_detach(&(t)->self)) {	\ 	    MUTEX_UNLOCK(&(t)->mutex);		\ 	    croak("panic: DETACH");		\ 	}					\     } STMT_END
end_define

begin_else
else|#
directive|else
end_else

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

begin_comment
comment|/* OLD_PTHREADS_API */
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
name|PTHREADS_CREATED_JOINABLE
end_ifdef

begin_define
define|#
directive|define
name|ATTR_JOINABLE
value|PTHREAD_CREATE_JOINABLE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PTHREAD_CREATE_UNDETACHED
end_ifdef

begin_define
define|#
directive|define
name|ATTR_JOINABLE
value|PTHREAD_CREATE_UNDETACHED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTR_JOINABLE
value|PTHREAD_CREATE_JOINABLE
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
name|YIELD
end_ifndef

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
define|\
value|STMT_START {						\ 	if (pthread_mutex_init((m), pthread_mutexattr_default))	\ 	    croak("panic: MUTEX_INIT");				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_mutex_lock((m)))		\ 	    croak("panic: MUTEX_LOCK");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_mutex_unlock((m)))		\ 	    croak("panic: MUTEX_UNLOCK");	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_mutex_destroy((m)))		\ 	    croak("panic: MUTEX_DESTROY");	\     } STMT_END
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
value|STMT_START {						\ 	if (pthread_cond_init((c), pthread_condattr_default))	\ 	    croak("panic: COND_INIT");				\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_cond_signal((c)))		\ 	    croak("panic: COND_SIGNAL");	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_cond_broadcast((c)))	\ 	    croak("panic: COND_BROADCAST");	\     } STMT_END
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
value|STMT_START {				\ 	if (pthread_cond_wait((c), (m)))	\ 	    croak("panic: COND_WAIT");		\     } STMT_END
end_define

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
define|\
value|STMT_START {				\ 	if (pthread_cond_destroy((c)))		\ 	    croak("panic: COND_DESTROY");	\     } STMT_END
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
value|STMT_START {				\ 	if (pthread_detach((t)->self)) {	\ 	    MUTEX_UNLOCK(&(t)->mutex);		\ 	    croak("panic: DETACH");		\ 	}					\     } STMT_END
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
value|STMT_START {					\ 	if (pthread_join((t)->self, (void**)(avp)))	\ 	    croak("panic: pthread_join");		\     } STMT_END
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
name|SET_THR
end_ifndef

begin_define
define|#
directive|define
name|SET_THR
parameter_list|(
name|t
parameter_list|)
define|\
value|STMT_START {					\ 	if (pthread_setspecific(PL_thr_key, (void *) (t)))	\ 	    croak("panic: pthread_setspecific");	\     } STMT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SET_THR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|THR
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_PTHREADS_API
end_ifdef

begin_decl_stmt
name|struct
name|perl_thread
modifier|*
name|getTHR
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|THR
value|getTHR()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|THR
value|((struct perl_thread *) pthread_getspecific(PL_thr_key))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLD_PTHREADS_API */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* THR */
end_comment

begin_comment
comment|/*  * dTHR is performance-critical. Here, we only do the pthread_get_specific  * if there may be more than one thread in existence, otherwise we get thr  * from thrsv which is cached in the per-interpreter structure.  * Systems with very fast pthread_get_specific (which should be all systems  * but unfortunately isn't) may wish to simplify to "...*thr = THR".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|dTHR
end_ifndef

begin_define
define|#
directive|define
name|dTHR
define|\
value|struct perl_thread *thr = PL_threadnum? THR : (struct perl_thread*)SvPVX(PL_thrsv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* dTHR */
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

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * LOCK_SV_MUTEX and UNLOCK_SV_MUTEX are performance-critical. Here, we  * try only locking them if there may be more than one thread in existence.  * Systems with very fast mutexes (and/or slow conditionals) may wish to  * remove the "if (threadnum) ..." test.  */
end_comment

begin_define
define|#
directive|define
name|LOCK_SV_MUTEX
define|\
value|STMT_START {			\ 	if (PL_threadnum)			\ 	    MUTEX_LOCK(&PL_sv_mutex);	\     } STMT_END
end_define

begin_define
define|#
directive|define
name|UNLOCK_SV_MUTEX
define|\
value|STMT_START {			\ 	if (PL_threadnum)			\ 	    MUTEX_UNLOCK(&PL_sv_mutex);	\     } STMT_END
end_define

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
value|STMT_START {		\ 	(t)->flags&= ~THRf_STATE_MASK;		\ 	(t)->flags |= (s);			\ 	DEBUG_S(PerlIO_printf(PerlIO_stderr(),	\ 			      "thread %p set to state %d\n", (t), (s))); \     } STMT_END
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* USE_THREADS is not defined */
end_comment

begin_define
define|#
directive|define
name|MUTEX_LOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_UNLOCK
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_INIT
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MUTEX_DESTROY
parameter_list|(
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COND_INIT
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COND_SIGNAL
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COND_BROADCAST
parameter_list|(
name|c
parameter_list|)
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
end_define

begin_define
define|#
directive|define
name|COND_DESTROY
parameter_list|(
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOCK_SV_MUTEX
end_define

begin_define
define|#
directive|define
name|UNLOCK_SV_MUTEX
end_define

begin_define
define|#
directive|define
name|THR
end_define

begin_comment
comment|/* Rats: if dTHR is just blank then the subsequent ";" throws an error */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|dTHR
value|extern int Perl___notused
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dTHR
value|extern int errno
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

end_unit

