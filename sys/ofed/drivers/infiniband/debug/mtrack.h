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
file|"memtrack.h"
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
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/io.h>
end_include

begin_comment
comment|/* For ioremap_nocache, ioremap, iounmap */
end_comment

begin_include
include|#
directive|include
file|<linux/random.h>
end_include

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|27
argument_list|)
end_if

begin_include
include|#
directive|include
file|<linux/io-mapping.h>
end_include

begin_comment
comment|/* For ioremap_nocache, ioremap, iounmap */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<linux/mm.h>
end_include

begin_comment
comment|/* For all page handling */
end_comment

begin_include
include|#
directive|include
file|<linux/workqueue.h>
end_include

begin_comment
comment|/* For all work-queue handling */
end_comment

begin_include
include|#
directive|include
file|<linux/scatterlist.h>
end_include

begin_comment
comment|/* For using scatterlists */
end_comment

begin_include
include|#
directive|include
file|<linux/skbuff.h>
end_include

begin_comment
comment|/* For skbufs handling */
end_comment

begin_include
include|#
directive|include
file|<asm/uaccess.h>
end_include

begin_comment
comment|/* For copy from/to user */
end_comment

begin_define
define|#
directive|define
name|MEMTRACK_ERROR_INJECTION_MESSAGE
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|,
name|func
parameter_list|)
value|({ \ 	printk(KERN_ERR "%s failure injected at %s:%d\n", func, file, line);	\ 	dump_stack();								\ })
end_define

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
value|({ \ 	void *__memtrack_kz_addr = NULL;					\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kzalloc");\ 	else									\         __memtrack_kz_addr = kmalloc(size, flags); \ 	if (__memtrack_kz_addr&& !is_non_trackable_alloc_func(__func__)) {	\ 		memset(__memtrack_kz_addr, 0, size);				\         }                                                                     \         __memtrack_kz_addr;                                                                              \ })
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
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kzalloc");\ 	else									\         __memtrack_addr = kzalloc(size, flags); \ 	if (__memtrack_addr&& !is_non_trackable_alloc_func(__func__)) {	\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|kzalloc_node
parameter_list|(
name|size
parameter_list|,
name|flags
parameter_list|,
name|node
parameter_list|)
value|({					\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kzalloc_node"); \ 	else									\ 		__memtrack_addr = kzalloc_node(size, flags, node);		\ 	if (__memtrack_addr&& (size)&&					\ 	    !is_non_trackable_alloc_func(__func__)) {				\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, flags); \ 	}									\ 	__memtrack_addr;							\ })
end_define

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
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kcalloc");\ 	else									\         __memtrack_addr = kcalloc(n, size, flags); \ 	if (__memtrack_addr&& (size)) {					\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), (n)*(size), 0UL, 0, __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
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
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmalloc");\ 	else									\         __memtrack_addr = kmalloc(sz, flgs); \ 	if (!ZERO_OR_NULL_PTR(__memtrack_addr)) {				\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), sz, 0UL, 0, __FILE__, __LINE__, flgs); \ 		if (memtrack_randomize_mem())					\ 			get_random_bytes(__memtrack_addr, sz);			\         }                                                                     \         __memtrack_addr;                                                                              \ })
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
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmalloc");\ 	else									\         __memtrack_addr = kmalloc(sz, flgs); \ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), sz, 0UL, 0, __FILE__, __LINE__, flgs); \ 		if (memtrack_randomize_mem())					\ 			get_random_bytes(__memtrack_addr, sz);			\         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|kmalloc_node
parameter_list|(
name|sz
parameter_list|,
name|flgs
parameter_list|,
name|node
parameter_list|)
value|({						\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmalloc_node"); \ 	else									\ 		__memtrack_addr = kmalloc_node(sz, flgs, node);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), sz, 0UL, 0, __FILE__, __LINE__, flgs); \ 		if (memtrack_randomize_mem()&& ((flgs) == GFP_KERNEL))		\ 			get_random_bytes(__memtrack_addr, sz);			\ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ZERO_OR_NULL_PTR
end_ifdef

begin_define
define|#
directive|define
name|kmemdup
parameter_list|(
name|src
parameter_list|,
name|sz
parameter_list|,
name|flgs
parameter_list|)
value|({						\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmemdup");\ 	else									\ 		__memtrack_addr = kmemdup(src, sz, flgs);			\ 	if (!ZERO_OR_NULL_PTR(__memtrack_addr)) {				\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), sz, 0UL, 0, __FILE__, __LINE__, flgs); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kmemdup
parameter_list|(
name|src
parameter_list|,
name|sz
parameter_list|,
name|flgs
parameter_list|)
value|({						\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmemdup");\ 	else									\ 		__memtrack_addr = kmemdup(src, sz, flgs);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), sz, 0UL, 0, __FILE__, __LINE__, flgs); \ 	}									\ 	__memtrack_addr;							\ })
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
value|({ \         void *__memtrack_addr = (void *)addr;                 \ 										\ 	if (!ZERO_OR_NULL_PTR(__memtrack_addr)&&				\ 	    !is_non_trackable_free_func(__func__)) {				\ 		memtrack_free(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \         }                    \         kfree(__memtrack_addr); \ })
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
value|({ \         void *__memtrack_addr = (void *)addr;                 \ 										\ 	if (__memtrack_addr&& !is_non_trackable_free_func(__func__)) {		\ 		memtrack_free(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \         }                    \         kfree(__memtrack_addr); \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|LINUX_VERSION_CODE
operator|>=
name|KERNEL_VERSION
argument_list|(
literal|3
operator|,
literal|0
operator|,
literal|0
argument_list|)
operator|||
name|defined
argument_list|(
name|CONFIG_COMPAT_RCU
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|kfree_rcu
end_ifdef

begin_undef
undef|#
directive|undef
name|kfree_rcu
end_undef

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
name|kfree_rcu
parameter_list|(
name|addr
parameter_list|,
name|rcu_head
parameter_list|)
value|({								\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (!ZERO_OR_NULL_PTR(__memtrack_addr)&&				\ 	    !is_non_trackable_free_func(__func__)) {				\ 		memtrack_free(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	__kfree_rcu(&((addr)->rcu_head), offsetof(typeof(*(addr)), rcu_head));					\ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|kfree_rcu
parameter_list|(
name|addr
parameter_list|,
name|rcu_head
parameter_list|)
value|({								\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr&& !is_non_trackable_free_func(__func__)) {		\ 		memtrack_free(MEMTRACK_KMALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	__kfree_rcu(&((addr)->rcu_head), offsetof(typeof(*(addr)), rcu_head));					\ })
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
comment|/* LINUX_VERSION_CODE< KERNEL_VERSION(3, 0, 0) */
end_comment

begin_define
define|#
directive|define
name|vmalloc
parameter_list|(
name|size
parameter_list|)
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "vmalloc");\ 	else									\         __memtrack_addr = vmalloc(size); \ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_VMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 		if (memtrack_randomize_mem())					\ 			get_random_bytes(__memtrack_addr, size);		\ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vzalloc
end_ifndef

begin_define
define|#
directive|define
name|vzalloc
parameter_list|(
name|size
parameter_list|)
value|({							\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "vzalloc");\ 	else									\ 		__memtrack_addr = vzalloc(size);				\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_VMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \         }                                                                     \         __memtrack_addr;                                                                              \ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|vzalloc_node
end_ifndef

begin_define
define|#
directive|define
name|vzalloc_node
parameter_list|(
name|size
parameter_list|,
name|node
parameter_list|)
value|({						\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "vzalloc_node"); \ 	else									\ 		__memtrack_addr = vzalloc_node(size, node);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_VMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 		if (memtrack_randomize_mem())					\ 			get_random_bytes(__memtrack_addr, size);		\ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|vmalloc_node
parameter_list|(
name|size
parameter_list|,
name|node
parameter_list|)
value|({						\ 	void *__memtrack_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "vmalloc_node"); \ 	else									\ 		__memtrack_addr = vmalloc_node(size, node);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_VMALLOC, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 		if (memtrack_randomize_mem())					\ 			get_random_bytes(__memtrack_addr, size);		\ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_define
define|#
directive|define
name|vfree
parameter_list|(
name|addr
parameter_list|)
value|({ \         void *__memtrack_addr = (void *)addr;   \ 	if (__memtrack_addr) {							\ 		memtrack_free(MEMTRACK_VMALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \         }                    \         vfree(__memtrack_addr); \ })
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
value|({ \ 	void *__memtrack_addr = NULL;						\                                 \ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "kmem_cache_alloc"); \ 	else									\         __memtrack_addr = kmem_cache_alloc(cache, flags); \ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_KMEM_OBJ, 0UL, (unsigned long)(__memtrack_addr), 1, 0UL, 0, __FILE__, __LINE__, flags); \         }                                                                     \         __memtrack_addr;                                                                              \ })
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
value|({ \         void *__memtrack_addr = (void *)addr;                 \ 										\ 	if (__memtrack_addr) {						\ 		memtrack_free(MEMTRACK_KMEM_OBJ, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \         }                    \         kmem_cache_free(cache, __memtrack_addr); \ })
end_define

begin_comment
comment|/* All IO-MAP handling */
end_comment

begin_define
define|#
directive|define
name|ioremap
parameter_list|(
name|phys_addr
parameter_list|,
name|size
parameter_list|)
value|({						\ 	void __iomem *__memtrack_addr = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "ioremap");\ 	else									\ 		__memtrack_addr = ioremap(phys_addr, size);			\ 	if (__memtrack_addr) {						\ 		memtrack_alloc(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_define
define|#
directive|define
name|io_mapping_create_wc
parameter_list|(
name|base
parameter_list|,
name|size
parameter_list|)
value|({					\ 	void __iomem *__memtrack_addr = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "io_mapping_create_wc"); \ 	else									\ 		__memtrack_addr = io_mapping_create_wc(base, size);		\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_define
define|#
directive|define
name|io_mapping_free
parameter_list|(
name|addr
parameter_list|)
value|({						\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr) {							\ 		memtrack_free(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	io_mapping_free(__memtrack_addr);					\ })
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_PPC
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|ioremap_nocache
end_ifdef

begin_undef
undef|#
directive|undef
name|ioremap_nocache
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ioremap_nocache
parameter_list|(
name|phys_addr
parameter_list|,
name|size
parameter_list|)
value|({					\ 	void __iomem *__memtrack_addr = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "ioremap_nocache"); \ 	else									\ 		__memtrack_addr = ioremap(phys_addr, size);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_else
else|#
directive|else
end_else

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
literal|18
argument_list|)
end_if

begin_comment
comment|/* 2.6.16 - 2.6.17 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ioremap_nocache
end_ifdef

begin_undef
undef|#
directive|undef
name|ioremap_nocache
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ioremap_nocache
parameter_list|(
name|phys_addr
parameter_list|,
name|size
parameter_list|)
value|({					\ 	void __iomem *__memtrack_addr = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "ioremap_nocache"); \ 	else									\ 		__memtrack_addr = ioremap(phys_addr, size);			\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ioremap_nocache
parameter_list|(
name|phys_addr
parameter_list|,
name|size
parameter_list|)
value|({ \ 	void __iomem *__memtrack_addr = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "ioremap_nocache"); \ 	else									\ 		__memtrack_addr = ioremap_nocache(phys_addr, size);		\ 	if (__memtrack_addr) {							\ 		memtrack_alloc(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), size, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_addr;							\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Kernel version is under 2.6.18 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPC */
end_comment

begin_define
define|#
directive|define
name|iounmap
parameter_list|(
name|addr
parameter_list|)
value|({							\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr) {							\ 		memtrack_free(MEMTRACK_IOREMAP, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	iounmap(__memtrack_addr);						\ })
end_define

begin_comment
comment|/* All Page handlers */
end_comment

begin_comment
comment|/* TODO: Catch netif_rx for page dereference */
end_comment

begin_define
define|#
directive|define
name|alloc_pages_node
parameter_list|(
name|nid
parameter_list|,
name|gfp_mask
parameter_list|,
name|order
parameter_list|)
value|({				\ 	struct page *page_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_pages_node"); \ 	else									\ 	page_addr = (struct page *)alloc_pages_node(nid, gfp_mask, order);	\ 	if (page_addr&& !is_non_trackable_alloc_func(__func__)) {		\ 		memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(page_addr), (unsigned long)(order), 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	page_addr;								\ })
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NUMA
end_ifdef

begin_define
define|#
directive|define
name|alloc_pages
parameter_list|(
name|gfp_mask
parameter_list|,
name|order
parameter_list|)
value|({						\ 	struct page *page_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_pages"); \ 	else									\ 		page_addr = (struct page *)alloc_pages(gfp_mask, order);	\ 	if (page_addr&& !is_non_trackable_alloc_func(__func__)) {		\ 		memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(page_addr), (unsigned long)(order), 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	page_addr;								\ })
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|alloc_pages
end_ifdef

begin_undef
undef|#
directive|undef
name|alloc_pages
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|alloc_pages
parameter_list|(
name|gfp_mask
parameter_list|,
name|order
parameter_list|)
value|({						\ 	struct page *page_addr;							\ 										\ 	page_addr = (struct page *)alloc_pages_node(numa_node_id(), gfp_mask, order); \ 	page_addr;								\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__get_free_pages
parameter_list|(
name|gfp_mask
parameter_list|,
name|order
parameter_list|)
value|({					\ 	struct page *page_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "__get_free_pages"); \ 	else									\ 		page_addr = (struct page *)__get_free_pages(gfp_mask, order);	\ 	if (page_addr&& !is_non_trackable_alloc_func(__func__)) {		\ 		memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(page_addr), (unsigned long)(order), 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	page_addr;								\ })
end_define

begin_define
define|#
directive|define
name|get_zeroed_page
parameter_list|(
name|gfp_mask
parameter_list|)
value|({						\ 	struct page *page_addr = NULL;						\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "get_zeroed_page"); \ 	else									\ 		page_addr = (struct page *)get_zeroed_page(gfp_mask);		\ 	if (page_addr&& !is_non_trackable_alloc_func(__func__)) {		\ 		memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(page_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	(unsigned long)page_addr;						\ })
end_define

begin_define
define|#
directive|define
name|__free_pages
parameter_list|(
name|addr
parameter_list|,
name|order
parameter_list|)
value|({						\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr&& !is_non_trackable_alloc_func(__func__)) {	\ 		if (!memtrack_check_size(MEMTRACK_PAGE_ALLOC, (unsigned long)(__memtrack_addr), (unsigned long)(order), __FILE__, __LINE__)) \ 			memtrack_free(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	__free_pages(addr, order);						\ })
end_define

begin_define
define|#
directive|define
name|free_pages
parameter_list|(
name|addr
parameter_list|,
name|order
parameter_list|)
value|({						\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr&& !is_non_trackable_alloc_func(__func__)) {	\ 		if (!memtrack_check_size(MEMTRACK_PAGE_ALLOC, (unsigned long)(__memtrack_addr), (unsigned long)(order), __FILE__, __LINE__)) \ 			memtrack_free(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	free_pages(addr, order);						\ })
end_define

begin_define
define|#
directive|define
name|get_page
parameter_list|(
name|addr
parameter_list|)
value|({							\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr&& !is_non_trackable_alloc_func(__func__)) {	\ 		if (memtrack_is_new_addr(MEMTRACK_PAGE_ALLOC, (unsigned long)(__memtrack_addr), 0, __FILE__, __LINE__)) { \ 			memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(__memtrack_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 		}								\ 	}									\ 	get_page(addr);								\ })
end_define

begin_define
define|#
directive|define
name|get_user_pages_fast
parameter_list|(
name|start
parameter_list|,
name|nr_pages
parameter_list|,
name|write
parameter_list|,
name|pages
parameter_list|)
value|({			\ 	int __memtrack_rc = -1;							\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "get_user_pages_fast"); \ 	else									\ 		__memtrack_rc = get_user_pages_fast(start, nr_pages, write, pages); \ 	if (__memtrack_rc> 0&& !is_non_trackable_alloc_func(__func__)) {	\ 		int __memtrack_i;						\ 										\ 		for (__memtrack_i = 0; __memtrack_i< __memtrack_rc; __memtrack_i++) \ 			memtrack_alloc(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(pages[__memtrack_i]), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	__memtrack_rc;								\ })
end_define

begin_define
define|#
directive|define
name|put_page
parameter_list|(
name|addr
parameter_list|)
value|({							\ 	void *__memtrack_addr = (void *)addr;					\ 										\ 	if (__memtrack_addr&& !is_non_trackable_alloc_func(__func__)) {	\
comment|/* Check whether this is not part of umem put page& not */
value|\
comment|/* a new addr and the ref-count is 1 then we'll free this addr */
value|\
comment|/* Don't change the order these conditions */
value|\ 		if (!is_umem_put_page(__func__)&& \ 		    !memtrack_is_new_addr(MEMTRACK_PAGE_ALLOC, (unsigned long)(__memtrack_addr), 1, __FILE__, __LINE__)&& \ 		    (memtrack_get_page_ref_count((unsigned long)(__memtrack_addr)) == 1)) { \ 			memtrack_free(MEMTRACK_PAGE_ALLOC, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 		}								\ 	}									\ 	put_page(addr);								\ })
end_define

begin_comment
comment|/* Work-Queue handlers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|create_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|create_workqueue
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|create_rt_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|create_rt_workqueue
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|create_freezeable_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|create_freezeable_workqueue
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|create_singlethread_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|create_singlethread_workqueue
end_undef

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
literal|20
argument_list|)
end_if

begin_comment
comment|/* 2.6.18 - 2.6.19 */
end_comment

begin_define
define|#
directive|define
name|create_workqueue
parameter_list|(
name|name
parameter_list|)
value|({						\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 0);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_define
define|#
directive|define
name|create_singlethread_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_singlethread_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 1);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_elif
elif|#
directive|elif
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|28
argument_list|)
end_elif

begin_comment
comment|/* 2.6.20 - 2.6.27 */
end_comment

begin_define
define|#
directive|define
name|create_workqueue
parameter_list|(
name|name
parameter_list|)
value|({						\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 0, 0);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

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
literal|22
argument_list|)
end_if

begin_comment
comment|/* 2.6.20 - 2.6.21 */
end_comment

begin_define
define|#
directive|define
name|create_freezeable_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_freezeable_workqueue"); \ 	else									\ 	wq_addr = __create_workqueue((name), 0, 1);				\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 2.6.22 - 2.6.27 */
end_comment

begin_define
define|#
directive|define
name|create_freezeable_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_freezeable_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 1, 1);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 2.6.20 - 2.6.27 */
end_comment

begin_define
define|#
directive|define
name|create_singlethread_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_singlethread_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 1, 0);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_elif
elif|#
directive|elif
name|LINUX_VERSION_CODE
operator|<
name|KERNEL_VERSION
argument_list|(
literal|2
operator|,
literal|6
operator|,
literal|36
argument_list|)
end_elif

begin_comment
comment|/* 2.6.28 - 2.6.35 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|alloc_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|alloc_workqueue
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|alloc_workqueue
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|max_active
parameter_list|)
value|({				\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_workqueue"); \ 	else									\ 	wq_addr = __create_workqueue((name), (flags), (max_active), 0);				\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_define
define|#
directive|define
name|create_workqueue
parameter_list|(
name|name
parameter_list|)
value|({						\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_workqueue"); \ 	else									\ 	wq_addr = __create_workqueue((name), 0, 0, 0);				\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_define
define|#
directive|define
name|create_rt_workqueue
parameter_list|(
name|name
parameter_list|)
value|({						\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_rt_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 0, 0, 1);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_define
define|#
directive|define
name|create_freezeable_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_freezeable_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 1, 1, 0);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_define
define|#
directive|define
name|create_singlethread_workqueue
parameter_list|(
name|name
parameter_list|)
value|({					\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "create_singlethread_workqueue"); \ 	else									\ 		wq_addr = __create_workqueue((name), 1, 0, 0);			\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 2.6.36 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|alloc_workqueue
end_ifdef

begin_undef
undef|#
directive|undef
name|alloc_workqueue
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_LOCKDEP
end_ifdef

begin_define
define|#
directive|define
name|alloc_workqueue
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|max_active
parameter_list|)
define|\
value|({										\ 	static struct lock_class_key __key;					\ 	const char *__lock_name;						\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (__builtin_constant_p(name))						\ 		__lock_name = (name);						\ 	else									\ 		__lock_name = #name;						\ 										\ 	if (memtrack_inject_error()) 						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_workqueue"); \ 	else									\ 		wq_addr = __alloc_workqueue_key((name), (flags), (max_active),	\&__key, __lock_name);		\ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|alloc_workqueue
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|max_active
parameter_list|)
value|({				\ 	struct workqueue_struct *wq_addr = NULL;				\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_workqueue"); \ 	else									\ 		wq_addr = __alloc_workqueue_key((name), (flags), (max_active), NULL, NULL); \ 	if (wq_addr) {								\ 		memtrack_alloc(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(wq_addr), 0, 0UL, 0, __FILE__, __LINE__, GFP_ATOMIC); \ 	}									\ 	wq_addr;								\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|create_workqueue
parameter_list|(
name|name
parameter_list|)
define|\
value|alloc_workqueue((name), WQ_RESCUER, 1);
end_define

begin_define
define|#
directive|define
name|create_freezeable_workqueue
parameter_list|(
name|name
parameter_list|)
define|\
value|alloc_workqueue((name), WQ_FREEZEABLE | WQ_UNBOUND | WQ_RESCUER, 1);
end_define

begin_define
define|#
directive|define
name|create_singlethread_workqueue
parameter_list|(
name|name
parameter_list|)
define|\
value|alloc_workqueue((name), WQ_UNBOUND | WQ_RESCUER, 1);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Work-Queue Kernel Versions */
end_comment

begin_define
define|#
directive|define
name|destroy_workqueue
parameter_list|(
name|wq_addr
parameter_list|)
value|({						\ 	void *__memtrack_addr = (void *)wq_addr;				\ 										\ 	if (__memtrack_addr) {							\ 		memtrack_free(MEMTRACK_WORK_QUEUE, 0UL, (unsigned long)(__memtrack_addr), 0UL, 0, __FILE__, __LINE__); \ 	}									\ 	destroy_workqueue(wq_addr);						\ })
end_define

begin_comment
comment|/* ONLY error injection to functions that we don't monitor */
end_comment

begin_define
define|#
directive|define
name|alloc_skb
parameter_list|(
name|size
parameter_list|,
name|prio
parameter_list|)
value|({ \ 	struct sk_buff *__memtrack_skb = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_skb"); \ 	else									\ 		 __memtrack_skb = alloc_skb(size, prio);			\ 	__memtrack_skb;								\ })
end_define

begin_define
define|#
directive|define
name|dev_alloc_skb
parameter_list|(
name|size
parameter_list|)
value|({							\ 	struct sk_buff *__memtrack_skb = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "dev_alloc_skb"); \ 	else									\ 		__memtrack_skb = dev_alloc_skb(size);				\ 	__memtrack_skb;								\ })
end_define

begin_define
define|#
directive|define
name|alloc_skb_fclone
parameter_list|(
name|size
parameter_list|,
name|prio
parameter_list|)
value|({						\ 	struct sk_buff *__memtrack_skb = NULL;					\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "alloc_skb_fclone"); \ 	else									\ 		__memtrack_skb = alloc_skb_fclone(size, prio);			\ 	__memtrack_skb;								\ })
end_define

begin_define
define|#
directive|define
name|copy_from_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|({						\ 	int ret = n;								\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "copy_from_user"); \ 	else									\ 		ret = copy_from_user(to, from, n);				\ 	ret;									\ })
end_define

begin_define
define|#
directive|define
name|copy_to_user
parameter_list|(
name|to
parameter_list|,
name|from
parameter_list|,
name|n
parameter_list|)
value|({						\ 	int ret = n;								\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "copy_to_user"); \ 	else									\ 		ret = copy_to_user(to, from, n);				\ 	ret;									\ })
end_define

begin_define
define|#
directive|define
name|sysfs_create_file
parameter_list|(
name|kobj
parameter_list|,
name|attr
parameter_list|)
value|({						\ 	int ret = -ENOSYS;							\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "sysfs_create_file"); \ 	else									\ 		ret = sysfs_create_file(kobj, attr);				\ 	ret;									\ })
end_define

begin_define
define|#
directive|define
name|sysfs_create_link
parameter_list|(
name|kobj
parameter_list|,
name|target
parameter_list|,
name|name
parameter_list|)
value|({				\ 	int ret = -ENOSYS;							\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "sysfs_create_link"); \ 	else									\ 		ret = sysfs_create_link(kobj, target, name);			\ 	ret;									\ })
end_define

begin_define
define|#
directive|define
name|sysfs_create_group
parameter_list|(
name|kobj
parameter_list|,
name|grp
parameter_list|)
value|({					\ 	int ret = -ENOSYS;							\ 										\ 	if (memtrack_inject_error())						\ 		MEMTRACK_ERROR_INJECTION_MESSAGE(__FILE__, __LINE__, "sysfs_create_group"); \ 	else									\ 		ret = sysfs_create_group(kobj, grp);				\ 	ret;									\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mtrack_h_ */
end_comment

end_unit

