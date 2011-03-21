begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__mtrack_h_
end_ifndef

begin_define
define|#
directive|define
name|__mtrack_h_
end_define

begin_include
include|#
directive|include
file|<memtrack.h>
end_include

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/vmalloc.h>
end_include

begin_include
include|#
directive|include
file|<linux/version.h>
end_include

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|14
argument_list|)
end_if

begin_define
define|#
directive|define
name|RDMA_KZALLOC_H
end_define

begin_define
define|#
directive|define
name|kzalloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|({ \         void *__memtrack_kz_addr;                 \                                 \         __memtrack_kz_addr = kmalloc(size, flags); \         if ( __memtrack_kz_addr ) {                               \                 memset( __memtrack_kz_addr, 0, size) ; \         }                                                                     \         __memtrack_kz_addr;                                                                              \ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kzalloc
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|)
value|({ \         void *__memtrack_addr;                 \                                 \         __memtrack_addr = kzalloc(size, flags); \         if ( __memtrack_addr&& (size)) {                               \                 memtrack_alloc(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), size, __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|19
argument_list|)
end_if

begin_define
define|#
directive|define
name|kcalloc
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|kzalloc((n)*(size), flags)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kcalloc
parameter_list|(
name|n
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|)
value|({ \         void *__memtrack_addr;                 \                                 \         __memtrack_addr = kcalloc(n, size, flags); \         if ( __memtrack_addr&& (size)) {                               \                 memtrack_alloc(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), (n)*(size), __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ZERO_OR_NULL_PTR
end_ifdef

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|sz
parameter_list|,
name|flgs
parameter_list|)
value|({ \         void *__memtrack_addr;                 \                                 \         __memtrack_addr = kmalloc(sz, flgs); \         if ( !ZERO_OR_NULL_PTR(__memtrack_addr)) {                               \                 memtrack_alloc(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), sz, __FILE__, __LINE__, flgs); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|sz
parameter_list|,
name|flgs
parameter_list|)
value|({ \         void *__memtrack_addr;                 \                                 \         __memtrack_addr = kmalloc(sz, flgs); \         if ( __memtrack_addr ) {                               \                 memtrack_alloc(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), sz, __FILE__, __LINE__, flgs); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ZERO_OR_NULL_PTR
end_ifdef

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|addr
parameter_list|)
value|({ \         void *__memtrack_addr = (void *)addr;                 \         if ( !ZERO_OR_NULL_PTR(__memtrack_addr) ) {      \                 memtrack_free(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), __FILE__, __LINE__); \         }                    \         kfree(__memtrack_addr); \ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|addr
parameter_list|)
value|({ \         void *__memtrack_addr = (void *)addr;                 \         if ( __memtrack_addr ) {      \                 memtrack_free(MEMTRACK_KMALLOC, (unsigned long)(__memtrack_addr), __FILE__, __LINE__); \         }                    \         kfree(__memtrack_addr); \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vmalloc
parameter_list|(
name|size
parameter_list|)
value|({ \         void *__memtrack_addr;                 \                                 \         __memtrack_addr = vmalloc(size); \         if ( __memtrack_addr ) {                               \                 memtrack_alloc(MEMTRACK_VMALLOC, (unsigned long)(__memtrack_addr), size, __FILE__, __LINE__, GFP_ATOMIC); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_define
define|#
directive|define
name|vfree
parameter_list|(
name|addr
parameter_list|)
value|({ \         void *__memtrack_addr = (void *)addr;   \         if ( __memtrack_addr ) {      \                 memtrack_free(MEMTRACK_VMALLOC, (unsigned long)(__memtrack_addr), __FILE__, __LINE__); \         }                    \         vfree(__memtrack_addr); \ })
end_define

begin_define
define|#
directive|define
name|kmem_cache_alloc
parameter_list|(
name|cache
parameter_list|,
name|flags
parameter_list|)
value|({ \         void *__memtrack_addr;         \                                 \         __memtrack_addr = kmem_cache_alloc(cache, flags); \         if ( __memtrack_addr ) {                               \                 memtrack_alloc(MEMTRACK_KMEM_OBJ, (unsigned long)(__memtrack_addr), 1, __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_define
define|#
directive|define
name|kmem_cache_free
parameter_list|(
name|cache
parameter_list|,
name|addr
parameter_list|)
value|({ \         void *__memtrack_addr = (void *)addr;                 \         if ( __memtrack_addr ) {      \                 memtrack_free(MEMTRACK_KMEM_OBJ, (unsigned long)(__memtrack_addr), __FILE__, __LINE__); \         }                    \         kmem_cache_free(cache, __memtrack_addr); \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mtrack_h_ */
end_comment

end_unit

