begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__has_builtin
end_ifndef

begin_define
define|#
directive|define
name|__has_builtin
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__has_feature
end_ifndef

begin_define
define|#
directive|define
name|__has_feature
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * Swap macro that enforces a happens-before relationship with a corresponding  * ATOMIC_LOAD.  */
end_comment

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__c11_atomic_exchange
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_SWAP
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|__c11_atomic_exchange((_Atomic(__typeof__(val))*)addr, val, __ATOMIC_ACQ_REL)
end_define

begin_elif
elif|#
directive|elif
name|__has_builtin
argument_list|(
name|__sync_swap
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ATOMIC_SWAP
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|__sync_swap(addr, val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_SWAP
parameter_list|(
name|addr
parameter_list|,
name|val
parameter_list|)
define|\
value|__sync_lock_test_and_set(addr, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__c11_atomic_load
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_LOAD
parameter_list|(
name|addr
parameter_list|)
define|\
value|__c11_atomic_load((_Atomic(__typeof__(*addr))*)addr, __ATOMIC_ACQUIRE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_LOAD
parameter_list|(
name|addr
parameter_list|)
define|\
value|(__sync_synchronize(), *addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

