begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * balloon.c  *  * Xen balloon driver - enables returning/claiming memory to/from Xen.  *  * Copyright (c) 2003, B Dragovic  * Copyright (c) 2003-2004, M Williamson, K Fraser  * Copyright (c) 2005 Dan M. Smith, IBM Corporation  *   * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/hypervisor-ifs.h>
end_include

begin_include
include|#
directive|include
file|<machine/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<machine/xenbus.h>
end_include

begin_comment
comment|/*  * Protects atomic reservation decrease/increase against concurrent increases.  * Also protects non-atomic updates of current_pages and driver_pages, and  * balloon lists.  */
end_comment

begin_decl_stmt
name|struct
name|mtx
name|balloon_lock
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_comment
comment|/* We aim for 'current allocation' == 'target allocation'. */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|current_pages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|target_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* VM /proc information for memory */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|totalram_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We may hit the hard limit in Xen. If we do then we remember it. */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|hard_limit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Drivers may alter the memory reservation independently, but they must  * inform the balloon driver so that we can avoid hitting the hard limit.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|driver_pages
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|balloon_entry
block|{
name|vm_page_t
name|page
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|balloon_entry
argument_list|)
name|list
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* List of ballooned pages, threaded through the mem_map array. */
end_comment

begin_expr_stmt
specifier|static
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|balloon_entry
argument_list|)
name|ballooned_pages
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|long
name|balloon_low
decl_stmt|,
name|balloon_high
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Main work function, always executed in process context. */
end_comment

begin_function_decl
specifier|static
name|void
name|balloon_process
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IPRINTK
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|printk(KERN_INFO "xen_mem: " fmt, ##args)
end_define

begin_define
define|#
directive|define
name|WPRINTK
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|printk(KERN_WARNING "xen_mem: " fmt, ##args)
end_define

begin_comment
comment|/* balloon_append: add the given page to the balloon. */
end_comment

begin_function
specifier|static
name|void
name|balloon_append
parameter_list|(
name|vm_page_t
name|page
parameter_list|)
block|{
name|struct
name|balloon_entry
modifier|*
name|entry
decl_stmt|;
name|entry
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|balloon_entry
argument_list|)
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|STAILQ_INSERT_HEAD
argument_list|(
operator|&
name|ballooned_pages
argument_list|,
name|entry
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|balloon_low
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/* balloon_retrieve: rescue a page from the balloon, if it is not empty. */
end_comment

begin_function
specifier|static
name|vm_page_t
name|balloon_retrieve
parameter_list|(
name|void
parameter_list|)
block|{
name|vm_page_t
name|page
decl_stmt|;
name|struct
name|balloon_entry
modifier|*
name|entry
decl_stmt|;
if|if
condition|(
name|STAILQ_EMPTY
argument_list|(
operator|&
name|ballooned_pages
argument_list|)
condition|)
return|return
name|NULL
return|;
name|entry
operator|=
name|STAILQ_FIRST
argument_list|(
operator|&
name|ballooned_pages
argument_list|)
expr_stmt|;
name|STAILQ_REMOVE_HEAD
argument_list|(
operator|&
name|ballooned_pages
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|page
operator|=
name|entry
operator|->
name|page
expr_stmt|;
name|free
argument_list|(
name|entry
argument_list|,
name|M_DEVBUF
argument_list|)
expr_stmt|;
name|balloon_low
operator|--
expr_stmt|;
return|return
name|page
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|balloon_alarm
parameter_list|(
name|unsigned
name|long
name|unused
parameter_list|)
block|{
name|wakeup
argument_list|(
name|balloon_process
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|current_target
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|long
name|target
init|=
name|min
argument_list|(
name|target_pages
argument_list|,
name|hard_limit
argument_list|)
decl_stmt|;
if|if
condition|(
name|target
operator|>
operator|(
name|current_pages
operator|+
name|balloon_low
operator|+
name|balloon_high
operator|)
condition|)
name|target
operator|=
name|current_pages
operator|+
name|balloon_low
operator|+
name|balloon_high
expr_stmt|;
return|return
name|target
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|increase_reservation
parameter_list|(
name|unsigned
name|long
name|nr_pages
parameter_list|)
block|{
name|unsigned
name|long
modifier|*
name|mfn_list
decl_stmt|,
name|pfn
decl_stmt|,
name|i
decl_stmt|,
name|flags
decl_stmt|;
name|struct
name|page
modifier|*
name|page
decl_stmt|;
name|long
name|rc
decl_stmt|;
name|struct
name|xen_memory_reservation
name|reservation
init|=
block|{
operator|.
name|address_bits
operator|=
literal|0
block|,
operator|.
name|extent_order
operator|=
literal|0
block|,
operator|.
name|domid
operator|=
name|DOMID_SELF
block|}
decl_stmt|;
if|if
condition|(
name|nr_pages
operator|>
operator|(
name|PAGE_SIZE
operator|/
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|)
condition|)
name|nr_pages
operator|=
name|PAGE_SIZE
operator|/
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
expr_stmt|;
name|mfn_list
operator|=
operator|(
name|unsigned
name|long
operator|*
operator|)
name|malloc
argument_list|(
name|PAGE_SIZE
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|mfn_list
operator|==
name|NULL
condition|)
return|return
name|ENOMEM
return|;
name|reservation
operator|.
name|extent_start
operator|=
name|mfn_list
expr_stmt|;
name|reservation
operator|.
name|nr_extents
operator|=
name|nr_pages
expr_stmt|;
name|rc
operator|=
name|HYPERVISOR_memory_op
argument_list|(
name|XENMEM_increase_reservation
argument_list|,
operator|&
name|reservation
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|<
name|nr_pages
condition|)
block|{
name|int
name|ret
decl_stmt|;
comment|/* We hit the Xen hard limit: reprobe. */
name|reservation
operator|.
name|extent_start
operator|=
name|mfn_list
expr_stmt|;
name|reservation
operator|.
name|nr_extents
operator|=
name|rc
expr_stmt|;
name|ret
operator|=
name|HYPERVISOR_memory_op
argument_list|(
name|XENMEM_decrease_reservation
argument_list|,
operator|&
name|reservation
argument_list|)
expr_stmt|;
name|PANIC_IF
argument_list|(
name|ret
operator|!=
name|rc
argument_list|)
expr_stmt|;
name|hard_limit
operator|=
name|current_pages
operator|+
name|rc
operator|-
name|driver_pages
expr_stmt|;
goto|goto
name|out
goto|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nr_pages
condition|;
name|i
operator|++
control|)
block|{
name|page
operator|=
name|balloon_retrieve
argument_list|()
expr_stmt|;
name|PANIC_IF
argument_list|(
name|page
operator|==
name|NULL
argument_list|)
expr_stmt|;
name|pfn
operator|=
operator|(
name|VM_PAGE_TO_PHYS
argument_list|(
name|page
argument_list|)
operator|>>
name|PAGE_SHIFT
operator|)
expr_stmt|;
name|PANIC_IF
argument_list|(
name|phys_to_machine_mapping_valid
argument_list|(
name|pfn
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Update P->M and M->P tables. */
name|PFNTOMFN
argument_list|(
name|pfn
argument_list|)
operator|=
name|mfn_list
index|[
name|i
index|]
expr_stmt|;
name|xen_machphys_update
argument_list|(
name|mfn_list
index|[
name|i
index|]
argument_list|,
name|pfn
argument_list|)
expr_stmt|;
comment|/* Relinquish the page back to the allocator. */
name|ClearPageReserved
argument_list|(
name|page
argument_list|)
expr_stmt|;
name|set_page_count
argument_list|(
name|page
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|vm_page_free
argument_list|(
name|page
argument_list|)
expr_stmt|;
block|}
name|current_pages
operator|+=
name|nr_pages
expr_stmt|;
name|totalram_pages
operator|=
name|current_pages
expr_stmt|;
name|out
label|:
name|balloon_unlock
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|free
argument_list|(
argument|(mfn_list);  	return
literal|0
argument|; }  static int  decrease_reservation(unsigned long nr_pages) { 	unsigned long *mfn_list
argument_list|,
argument|pfn
argument_list|,
argument|i
argument_list|,
argument|flags; 	struct page   *page; 	void          *v; 	int            need_sleep =
literal|0
argument|; 	int ret; 	struct xen_memory_reservation reservation = { 		.address_bits =
literal|0
argument_list|,
argument|.extent_order =
literal|0
argument_list|,
argument|.domid        = DOMID_SELF 	};  	if (nr_pages> (PAGE_SIZE / sizeof(unsigned long))) 		nr_pages = PAGE_SIZE / sizeof(unsigned long);  	mfn_list = (unsigned long *)malloc(PAGE_SIZE, M_DEVBUF, M_NOWAIT); 	if (mfn_list == NULL) 		return ENOMEM;  	for (i =
literal|0
argument|; i< nr_pages; i++) { 		int color =
literal|0
argument|; 		if ((page = vm_page_alloc(NULL, color++,  					  VM_ALLOC_NORMAL | VM_ALLOC_NOOBJ |  					  VM_ALLOC_WIRED | VM_ALLOC_ZERO)) == NULL) { 			nr_pages = i; 			need_sleep =
literal|1
argument|; 			break; 		} 		pfn = (VM_PAGE_TO_PHYS(page)>> PAGE_SHIFT); 		mfn_list[i] = PFNTOMFN(pfn); 	}  	balloon_lock(flags);
comment|/* No more mappings: invalidate P2M and add to balloon. */
argument|for (i =
literal|0
argument|; i< nr_pages; i++) { 		pfn = MFNTOPFN(mfn_list[i]); 		PFNTOMFN(pfn) = INVALID_P2M_ENTRY; 		balloon_append(PHYS_TO_VM_PAGE(pfn<< PAGE_SHIFT)); 	}  	reservation.extent_start = mfn_list; 	reservation.nr_extents   = nr_pages; 	ret = HYPERVISOR_memory_op(XENMEM_decrease_reservation,&reservation); 	PANIC_IF(ret != nr_pages);  	current_pages -= nr_pages; 	totalram_pages = current_pages;  	balloon_unlock(flags);  	free(mfn_list, M_DEVBUF);  	return need_sleep; }
comment|/*  * We avoid multiple worker processes conflicting via the balloon mutex.  * We may of course race updates of the target counts (which are protected  * by the balloon lock), or with changes to the Xen hard limit, but we will  * recover from these in time.  */
argument|static void  balloon_process(void *unused) { 	int need_sleep =
literal|0
argument|; 	long credit; 	 	for (;;) { 		do { 			credit = current_target() - current_pages; 			if (credit>
literal|0
argument|) 				need_sleep = (increase_reservation(credit) !=
literal|0
argument|); 			if (credit<
literal|0
argument|) 				need_sleep = (decrease_reservation(-credit) !=
literal|0
argument|);
ifndef|#
directive|ifndef
name|CONFIG_PREEMPT
argument|if (need_resched()) 				schedule();
endif|#
directive|endif
argument|} while ((credit !=
literal|0
argument|)&& !need_sleep);
comment|/* Schedule more work if there is some still to be done. */
argument|if (current_target() != current_pages) 			timeout(balloon_alarm, NULL, ticks + HZ);  			msleep(balloon_process, balloon_lock,
literal|0
argument|,
literal|"balloon"
argument|, -
literal|1
argument|); 	}  }
comment|/* Resets the Xen limit, sets new target, and kicks off processing. */
argument|static void  set_new_target(unsigned long target) {
comment|/* No need for lock. Not read-modify-write updates. */
argument|hard_limit   = ~
literal|0UL
argument|; 	target_pages = target; 	wakeup(balloon_process); }  static struct xenbus_watch target_watch = { 	.node =
literal|"memory/target"
argument|};
comment|/* React to a change in the target key */
argument|static void  watch_target(struct xenbus_watch *watch, 	     const char **vec, unsigned int len) { 	unsigned long long new_target; 	int err;  	err = xenbus_scanf(NULL,
literal|"memory"
argument|,
literal|"target"
argument|,
literal|"%llu"
argument|,&new_target); 	if (err !=
literal|1
argument|) {
comment|/* This is ok (for domain0 at least) - so just return */
argument|return; 	}
comment|/* The given memory/target value is in KiB, so it needs converting to 	   pages.  PAGE_SHIFT converts bytes to pages, hence PAGE_SHIFT - 10. 	*/
argument|set_new_target(new_target>> (PAGE_SHIFT -
literal|10
argument|));      }  static void  balloon_init_watcher(void *) { 	int err;  	err = register_xenbus_watch(&target_watch); 	if (err) 		printf(
literal|"Failed to set balloon watcher\n"
argument|);  }  static void  balloon_init(void *) { 	unsigned long pfn; 	struct page *page;  	IPRINTK(
literal|"Initialising balloon driver.\n"
argument|);  	if (xen_init()<
literal|0
argument|) 		return -
literal|1
argument|;  	current_pages = min(xen_start_info->nr_pages, max_pfn); 	target_pages  = current_pages; 	balloon_low   =
literal|0
argument|; 	balloon_high  =
literal|0
argument|; 	driver_pages  =
literal|0UL
argument|; 	hard_limit    = ~
literal|0UL
argument|;  	init_timer(&balloon_timer); 	balloon_timer.data =
literal|0
argument|; 	balloon_timer.function = balloon_alarm;
comment|/* Initialise the balloon with excess memory space. */
argument|for (pfn = xen_start_info->nr_pages; pfn< max_pfn; pfn++) { 		page = PHYS_TO_VM_PAGE(pfn<< PAGE_SHIFT); 		balloon_append(page); 	}  	target_watch.callback = watch_target;      	return
literal|0
argument|; }  void  balloon_update_driver_allowance(long delta) { 	unsigned long flags;  	balloon_lock(flags); 	driver_pages += delta; 	balloon_unlock(flags); }
if|#
directive|if
literal|0
argument|static int dealloc_pte_fn( 	pte_t *pte, struct page *pte_page, unsigned long addr, void *data) { 	unsigned long mfn = pte_mfn(*pte); 	int ret; 	struct xen_memory_reservation reservation = { 		.extent_start =&mfn, 		.nr_extents   = 1, 		.extent_order = 0, 		.domid        = DOMID_SELF 	}; 	set_pte_at(&init_mm, addr, pte, __pte_ma(0)); 	set_phys_to_machine(__pa(addr)>> PAGE_SHIFT, INVALID_P2M_ENTRY); 	ret = HYPERVISOR_memory_op(XENMEM_decrease_reservation,&reservation); 	PANIC_IF(ret != 1); 	return 0; }
endif|#
directive|endif
argument|vm_page_t balloon_alloc_empty_page_range(unsigned long nr_pages) { 	unsigned long flags; 	vm_page_t pages; 	int i; 	unsigned long *mfn_list; 	struct xen_memory_reservation reservation = { 		.address_bits =
literal|0
argument_list|,
argument|.extent_order =
literal|0
argument_list|,
argument|.domid        = DOMID_SELF 	};  	pages = vm_page_alloc_contig(nr_pages,
literal|0
argument|, -
literal|1
argument|,
literal|4
argument|,
literal|4
argument|) 	if (pages == NULL) 		return NULL; 	 	mfn_list = malloc(nr_pages*sizeof(unsigned long), M_DEVBUF, M_WAITOK); 	 	for (i =
literal|0
argument|; i< nr_pages; i++) { 		mfn_list[i] = PFNTOMFN(VM_PAGE_TO_PHYS(pages[i])>> PAGE_SHIFT); 		PFNTOMFN(i) = INVALID_P2M_ENTRY; 		reservation.extent_start = mfn_list; 		reservation.nr_extents = nr_pages; 		PANIC_IF(HYPERVISOR_memory_op(XENMEM_decrease_reservation,&reservation) != nr_pages); 	}  	current_pages -= nr_pages;  	wakeup(balloon_process);  	return pages; }  void  balloon_dealloc_empty_page_range(vm_page_t page, unsigned long nr_pages) { 	unsigned long i
argument_list|,
argument|flags;  	for (i =
literal|0
argument|; i< nr_pages; i++) 		balloon_append(page + i);  	wakeup(balloon_process); }
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

