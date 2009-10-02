begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * os.h  *   * random collection of macros and definition  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_XEN_OS_H_
end_define

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PAE
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_X86_PAE
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
name|XEN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__XEN_INTERFACE_VERSION__
argument_list|)
end_if

begin_comment
comment|/*   * Can update to a more recent version when we implement   * the hypercall page   */
end_comment

begin_define
define|#
directive|define
name|__XEN_INTERFACE_VERSION__
value|0x00030204
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<xen/interface/xen.h>
end_include

begin_comment
comment|/* Force a proper event-channel callback from Xen. */
end_comment

begin_function_decl
name|void
name|force_evtchn_callback
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|likely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x),1)
end_define

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect((x),0)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vtophys
end_ifndef

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|gdtset
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* XXX for pcpu.h */
end_comment

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_comment
comment|/* XXX for PCPU_GET */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|smp_processor_id
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|likely
argument_list|(
name|gdtset
argument_list|)
condition|)
return|return
name|PCPU_GET
argument_list|(
name|cpuid
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|smp_processor_id
parameter_list|()
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(void *)0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PANIC_IF
end_ifndef

begin_define
define|#
directive|define
name|PANIC_IF
parameter_list|(
name|exp
parameter_list|)
value|if (unlikely(exp)) {printk("panic - %s: %s:%d\n",#exp, __FILE__, __LINE__); panic("%s: %s:%d", #exp, __FILE__, __LINE__);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|shared_info_t
modifier|*
name|HYPERVISOR_shared_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Somewhere in the middle of the GCC 2.96 development cycle, we implemented    a mechanism by which the user can annotate likely branch directions and    expect the blocks to be reordered appropriately.  Define __builtin_expect    to nothing for earlier compilers.  */
end_comment

begin_comment
comment|/* REP NOP (PAUSE) is a good thing to insert into busy-wait loops. */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|rep_nop
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( "rep;nop" : : : "memory" );
block|}
end_function

begin_define
define|#
directive|define
name|cpu_relax
parameter_list|()
value|rep_nop()
end_define

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|96
end_if

begin_define
define|#
directive|define
name|__builtin_expect
parameter_list|(
name|x
parameter_list|,
name|expected_value
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|per_cpu
parameter_list|(
name|var
parameter_list|,
name|cpu
parameter_list|)
value|(pcpu_find((cpu))->pc_ ## var)
end_define

begin_comment
comment|/* crude memory allocator for memory allocation early in   *  boot  */
end_comment

begin_function_decl
name|void
modifier|*
name|bootmem_alloc
parameter_list|(
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bootmem_free
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Everything below this point is not included by assembler (.S) files. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function_decl
name|void
name|printk
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* some function prototypes */
end_comment

begin_function_decl
name|void
name|trap_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * STI/CLI equivalents. These basically set and clear the virtual  * event_enable flag in teh shared_info structure. Note that when  * the enable bit is set, there may be pending events to be handled.  * We may therefore call into do_hypervisor_callback() directly.  */
end_comment

begin_define
define|#
directive|define
name|__cli
parameter_list|()
define|\
value|do {                                                                    \         vcpu_info_t *_vcpu;                                             \         _vcpu =&HYPERVISOR_shared_info->vcpu_info[smp_processor_id()]; \         _vcpu->evtchn_upcall_mask = 1;                                  \         barrier();                                                      \ } while (0)
end_define

begin_define
define|#
directive|define
name|__sti
parameter_list|()
define|\
value|do {                                                                    \         vcpu_info_t *_vcpu;                                             \         barrier();                                                      \         _vcpu =&HYPERVISOR_shared_info->vcpu_info[smp_processor_id()]; \         _vcpu->evtchn_upcall_mask = 0;                                  \         barrier();
comment|/* unmask then check (avoid races) */
value|\         if ( unlikely(_vcpu->evtchn_upcall_pending) )                   \                 force_evtchn_callback();                                \ } while (0)
end_define

begin_define
define|#
directive|define
name|__restore_flags
parameter_list|(
name|x
parameter_list|)
define|\
value|do {                                                                    \         vcpu_info_t *_vcpu;                                             \         barrier();                                                      \         _vcpu =&HYPERVISOR_shared_info->vcpu_info[smp_processor_id()]; \         if ((_vcpu->evtchn_upcall_mask = (x)) == 0) {                   \                 barrier();
comment|/* unmask then check (avoid races) */
value|\                 if ( unlikely(_vcpu->evtchn_upcall_pending) )           \                         force_evtchn_callback();                        \         } 								\ } while (0)
end_define

begin_comment
comment|/*  * Add critical_{enter, exit}?  *  */
end_comment

begin_define
define|#
directive|define
name|__save_and_cli
parameter_list|(
name|x
parameter_list|)
define|\
value|do {                                                                    \         vcpu_info_t *_vcpu;                                             \         _vcpu =&HYPERVISOR_shared_info->vcpu_info[smp_processor_id()]; \         (x) = _vcpu->evtchn_upcall_mask;                                \         _vcpu->evtchn_upcall_mask = 1;                                  \         barrier();                                                      \ } while (0)
end_define

begin_define
define|#
directive|define
name|cli
parameter_list|()
value|__cli()
end_define

begin_define
define|#
directive|define
name|sti
parameter_list|()
value|__sti()
end_define

begin_define
define|#
directive|define
name|save_flags
parameter_list|(
name|x
parameter_list|)
value|__save_flags(x)
end_define

begin_define
define|#
directive|define
name|restore_flags
parameter_list|(
name|x
parameter_list|)
value|__restore_flags(x)
end_define

begin_define
define|#
directive|define
name|save_and_cli
parameter_list|(
name|x
parameter_list|)
value|__save_and_cli(x)
end_define

begin_define
define|#
directive|define
name|local_irq_save
parameter_list|(
name|x
parameter_list|)
value|__save_and_cli(x)
end_define

begin_define
define|#
directive|define
name|local_irq_restore
parameter_list|(
name|x
parameter_list|)
value|__restore_flags(x)
end_define

begin_define
define|#
directive|define
name|local_irq_disable
parameter_list|()
value|__cli()
end_define

begin_define
define|#
directive|define
name|local_irq_enable
parameter_list|()
value|__sti()
end_define

begin_define
define|#
directive|define
name|mtx_lock_irqsave
parameter_list|(
name|lock
parameter_list|,
name|x
parameter_list|)
value|{local_irq_save((x)); mtx_lock_spin((lock));}
end_define

begin_define
define|#
directive|define
name|mtx_unlock_irqrestore
parameter_list|(
name|lock
parameter_list|,
name|x
parameter_list|)
value|{mtx_unlock_spin((lock)); local_irq_restore((x)); }
end_define

begin_define
define|#
directive|define
name|spin_lock_irqsave
value|mtx_lock_irqsave
end_define

begin_define
define|#
directive|define
name|spin_unlock_irqrestore
value|mtx_unlock_irqrestore
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|smp_mb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|smp_rmb
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|smp_wmb
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|smp_read_barrier_depends
parameter_list|()
value|read_barrier_depends()
end_define

begin_define
define|#
directive|define
name|set_mb
parameter_list|(
name|var
parameter_list|,
name|value
parameter_list|)
value|do { xchg(&var, value); } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|smp_mb
parameter_list|()
value|barrier()
end_define

begin_define
define|#
directive|define
name|smp_rmb
parameter_list|()
value|barrier()
end_define

begin_define
define|#
directive|define
name|smp_wmb
parameter_list|()
value|barrier()
end_define

begin_define
define|#
directive|define
name|smp_read_barrier_depends
parameter_list|()
value|do { } while(0)
end_define

begin_define
define|#
directive|define
name|set_mb
parameter_list|(
name|var
parameter_list|,
name|value
parameter_list|)
value|do { var = value; barrier(); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a barrier for the compiler only, NOT the processor! */
end_comment

begin_define
define|#
directive|define
name|barrier
parameter_list|()
value|__asm__ __volatile__("": : :"memory")
end_define

begin_define
define|#
directive|define
name|LOCK_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|LOCK
value|""
end_define

begin_define
define|#
directive|define
name|ADDR
value|(*(volatile long *) addr)
end_define

begin_comment
comment|/*  * Make sure gcc doesn't try to be clever and move things around  * on us. We need to use _exactly_ the address the user gave us,  * not some alias that contains the same information.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|volatile
name|int
name|counter
decl_stmt|;
block|}
name|atomic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xen_xchg
parameter_list|(
name|ptr
parameter_list|,
name|v
parameter_list|)
define|\
value|((__typeof__(*(ptr)))__xchg((unsigned long)(v),(ptr),sizeof(*(ptr))))
end_define

begin_struct
struct|struct
name|__xchg_dummy
block|{
name|unsigned
name|long
name|a
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__xg
parameter_list|(
name|x
parameter_list|)
value|((volatile struct __xchg_dummy *)(x))
end_define

begin_function
specifier|static
name|__inline
name|unsigned
name|long
name|__xchg
parameter_list|(
name|unsigned
name|long
name|x
parameter_list|,
specifier|volatile
name|void
modifier|*
name|ptr
parameter_list|,
name|int
name|size
parameter_list|)
block|{
switch|switch
condition|(
name|size
condition|)
block|{
case|case
literal|1
case|:
asm|__asm__
specifier|__volatile__
asm|("xchgb %b0,%1"                              :"=q" (x)                              :"m" (*__xg(ptr)), "0" (x)                              :"memory");
break|break;
case|case
literal|2
case|:
asm|__asm__
specifier|__volatile__
asm|("xchgw %w0,%1"                              :"=r" (x)                              :"m" (*__xg(ptr)), "0" (x)                              :"memory");
break|break;
case|case
literal|4
case|:
asm|__asm__
specifier|__volatile__
asm|("xchgl %0,%1"                              :"=r" (x)                              :"m" (*__xg(ptr)), "0" (x)                              :"memory");
break|break;
block|}
return|return
name|x
return|;
block|}
end_function

begin_comment
comment|/**  * test_and_clear_bit - Clear a bit and return its old value  * @nr: Bit to set  * @addr: Address to count from  *  * This operation is atomic and cannot be reordered.    * It also implies a memory barrier.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|test_and_clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX                 "btrl %2,%1\n\tsbbl %0,%0"                 :"=r" (oldbit),"=m" (ADDR)                 :"Ir" (nr) : "memory");
return|return
name|oldbit
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|constant_test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|const
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
return|return
operator|(
operator|(
literal|1UL
operator|<<
operator|(
name|nr
operator|&
literal|31
operator|)
operator|)
operator|&
operator|(
operator|(
operator|(
specifier|const
specifier|volatile
name|unsigned
name|int
operator|*
operator|)
name|addr
operator|)
index|[
name|nr
operator|>>
literal|5
index|]
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|variable_test_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|oldbit
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|(         "btl %2,%1\n\tsbbl %0,%0"         :"=r" (oldbit)         :"m" (ADDR),"Ir" (nr));
return|return
name|oldbit
return|;
block|}
end_function

begin_define
define|#
directive|define
name|test_bit
parameter_list|(
name|nr
parameter_list|,
name|addr
parameter_list|)
define|\
value|(__builtin_constant_p(nr) ? \  constant_test_bit((nr),(addr)) : \  variable_test_bit((nr),(addr)))
end_define

begin_comment
comment|/**  * set_bit - Atomically set a bit in memory  * @nr: the bit to set  * @addr: the address to start counting from  *  * This function is atomic and may not be reordered.  See __set_bit()  * if you do not require the atomic guarantees.  * Note that @nr may be almost arbitrarily large; this function is not  * restricted to acting on a single-word quantity.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|set_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX                 "btsl %1,%0"                 :"=m" (ADDR)                 :"Ir" (nr));
block|}
end_function

begin_comment
comment|/**  * clear_bit - Clears a bit in memory  * @nr: Bit to clear  * @addr: Address to start counting from  *  * clear_bit() is atomic and may not be reordered.  However, it does  * not contain a memory barrier, so if it is used for locking purposes,  * you should call smp_mb__before_clear_bit() and/or smp_mb__after_clear_bit()  * in order to ensure changes are visible on other processors.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|clear_bit
parameter_list|(
name|int
name|nr
parameter_list|,
specifier|volatile
name|void
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|( LOCK_PREFIX                 "btrl %1,%0"                 :"=m" (ADDR)                 :"Ir" (nr));
block|}
end_function

begin_comment
comment|/**  * atomic_inc - increment atomic variable  * @v: pointer of type atomic_t  *   * Atomically increments @v by 1.  Note that the guaranteed  * useful range of an atomic_t is only 24 bits.  */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|atomic_inc
parameter_list|(
name|atomic_t
modifier|*
name|v
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|(                 LOCK "incl %0"                 :"=m" (v->counter)                 :"m" (v->counter));
block|}
end_function

begin_define
define|#
directive|define
name|rdtscll
parameter_list|(
name|val
parameter_list|)
define|\
value|__asm__ __volatile__("rdtsc" : "=A" (val))
end_define

begin_comment
comment|/*  * Kernel pointers have redundant information, so we can use a  * scheme where we can return either an error code or a dentry  * pointer with the same return value.  *  * This should be a per-architecture thing, to allow different  * error and pointer decisions.  */
end_comment

begin_define
define|#
directive|define
name|IS_ERR_VALUE
parameter_list|(
name|x
parameter_list|)
value|unlikely((x)> (unsigned long)-1000L)
end_define

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|ERR_PTR
parameter_list|(
name|long
name|error
parameter_list|)
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|error
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|PTR_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
name|long
operator|)
name|ptr
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|long
name|IS_ERR
parameter_list|(
specifier|const
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|IS_ERR_VALUE
argument_list|(
operator|(
name|unsigned
name|long
operator|)
name|ptr
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OS_H_ */
end_comment

end_unit

