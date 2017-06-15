begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|a0dalloc
value|JEMALLOC_N(a0dalloc)
end_define

begin_define
define|#
directive|define
name|a0malloc
value|JEMALLOC_N(a0malloc)
end_define

begin_define
define|#
directive|define
name|arena_choose_hard
value|JEMALLOC_N(arena_choose_hard)
end_define

begin_define
define|#
directive|define
name|arena_cleanup
value|JEMALLOC_N(arena_cleanup)
end_define

begin_define
define|#
directive|define
name|arena_init
value|JEMALLOC_N(arena_init)
end_define

begin_define
define|#
directive|define
name|arena_migrate
value|JEMALLOC_N(arena_migrate)
end_define

begin_define
define|#
directive|define
name|arena_set
value|JEMALLOC_N(arena_set)
end_define

begin_define
define|#
directive|define
name|arena_tdata_get_hard
value|JEMALLOC_N(arena_tdata_get_hard)
end_define

begin_define
define|#
directive|define
name|arenas
value|JEMALLOC_N(arenas)
end_define

begin_define
define|#
directive|define
name|arenas_lock
value|JEMALLOC_N(arenas_lock)
end_define

begin_define
define|#
directive|define
name|arenas_tdata_cleanup
value|JEMALLOC_N(arenas_tdata_cleanup)
end_define

begin_define
define|#
directive|define
name|bootstrap_calloc
value|JEMALLOC_N(bootstrap_calloc)
end_define

begin_define
define|#
directive|define
name|bootstrap_free
value|JEMALLOC_N(bootstrap_free)
end_define

begin_define
define|#
directive|define
name|bootstrap_malloc
value|JEMALLOC_N(bootstrap_malloc)
end_define

begin_define
define|#
directive|define
name|iarena_cleanup
value|JEMALLOC_N(iarena_cleanup)
end_define

begin_define
define|#
directive|define
name|jemalloc_postfork_child
value|JEMALLOC_N(jemalloc_postfork_child)
end_define

begin_define
define|#
directive|define
name|malloc_initialized
value|JEMALLOC_N(malloc_initialized)
end_define

begin_define
define|#
directive|define
name|malloc_slow
value|JEMALLOC_N(malloc_slow)
end_define

begin_define
define|#
directive|define
name|narenas_auto
value|JEMALLOC_N(narenas_auto)
end_define

begin_define
define|#
directive|define
name|narenas_total_get
value|JEMALLOC_N(narenas_total_get)
end_define

begin_define
define|#
directive|define
name|ncpus
value|JEMALLOC_N(ncpus)
end_define

begin_define
define|#
directive|define
name|opt_abort
value|JEMALLOC_N(opt_abort)
end_define

begin_define
define|#
directive|define
name|opt_abort_conf
value|JEMALLOC_N(opt_abort_conf)
end_define

begin_define
define|#
directive|define
name|opt_junk
value|JEMALLOC_N(opt_junk)
end_define

begin_define
define|#
directive|define
name|opt_junk_alloc
value|JEMALLOC_N(opt_junk_alloc)
end_define

begin_define
define|#
directive|define
name|opt_junk_free
value|JEMALLOC_N(opt_junk_free)
end_define

begin_define
define|#
directive|define
name|opt_narenas
value|JEMALLOC_N(opt_narenas)
end_define

begin_define
define|#
directive|define
name|opt_utrace
value|JEMALLOC_N(opt_utrace)
end_define

begin_define
define|#
directive|define
name|opt_xmalloc
value|JEMALLOC_N(opt_xmalloc)
end_define

begin_define
define|#
directive|define
name|opt_zero
value|JEMALLOC_N(opt_zero)
end_define

begin_define
define|#
directive|define
name|arena_alloc_junk_small
value|JEMALLOC_N(arena_alloc_junk_small)
end_define

begin_define
define|#
directive|define
name|arena_basic_stats_merge
value|JEMALLOC_N(arena_basic_stats_merge)
end_define

begin_define
define|#
directive|define
name|arena_bin_info
value|JEMALLOC_N(arena_bin_info)
end_define

begin_define
define|#
directive|define
name|arena_boot
value|JEMALLOC_N(arena_boot)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_bin_junked_locked
value|JEMALLOC_N(arena_dalloc_bin_junked_locked)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_junk_small
value|JEMALLOC_N(arena_dalloc_junk_small)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_promoted
value|JEMALLOC_N(arena_dalloc_promoted)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_small
value|JEMALLOC_N(arena_dalloc_small)
end_define

begin_define
define|#
directive|define
name|arena_decay
value|JEMALLOC_N(arena_decay)
end_define

begin_define
define|#
directive|define
name|arena_destroy
value|JEMALLOC_N(arena_destroy)
end_define

begin_define
define|#
directive|define
name|arena_dirty_decay_ms_default_get
value|JEMALLOC_N(arena_dirty_decay_ms_default_get)
end_define

begin_define
define|#
directive|define
name|arena_dirty_decay_ms_default_set
value|JEMALLOC_N(arena_dirty_decay_ms_default_set)
end_define

begin_define
define|#
directive|define
name|arena_dirty_decay_ms_get
value|JEMALLOC_N(arena_dirty_decay_ms_get)
end_define

begin_define
define|#
directive|define
name|arena_dirty_decay_ms_set
value|JEMALLOC_N(arena_dirty_decay_ms_set)
end_define

begin_define
define|#
directive|define
name|arena_dss_prec_get
value|JEMALLOC_N(arena_dss_prec_get)
end_define

begin_define
define|#
directive|define
name|arena_dss_prec_set
value|JEMALLOC_N(arena_dss_prec_set)
end_define

begin_define
define|#
directive|define
name|arena_extent_alloc_large
value|JEMALLOC_N(arena_extent_alloc_large)
end_define

begin_define
define|#
directive|define
name|arena_extent_dalloc_large_prep
value|JEMALLOC_N(arena_extent_dalloc_large_prep)
end_define

begin_define
define|#
directive|define
name|arena_extent_ralloc_large_expand
value|JEMALLOC_N(arena_extent_ralloc_large_expand)
end_define

begin_define
define|#
directive|define
name|arena_extent_ralloc_large_shrink
value|JEMALLOC_N(arena_extent_ralloc_large_shrink)
end_define

begin_define
define|#
directive|define
name|arena_extent_sn_next
value|JEMALLOC_N(arena_extent_sn_next)
end_define

begin_define
define|#
directive|define
name|arena_extents_dirty_dalloc
value|JEMALLOC_N(arena_extents_dirty_dalloc)
end_define

begin_define
define|#
directive|define
name|arena_malloc_hard
value|JEMALLOC_N(arena_malloc_hard)
end_define

begin_define
define|#
directive|define
name|arena_muzzy_decay_ms_default_get
value|JEMALLOC_N(arena_muzzy_decay_ms_default_get)
end_define

begin_define
define|#
directive|define
name|arena_muzzy_decay_ms_default_set
value|JEMALLOC_N(arena_muzzy_decay_ms_default_set)
end_define

begin_define
define|#
directive|define
name|arena_muzzy_decay_ms_get
value|JEMALLOC_N(arena_muzzy_decay_ms_get)
end_define

begin_define
define|#
directive|define
name|arena_muzzy_decay_ms_set
value|JEMALLOC_N(arena_muzzy_decay_ms_set)
end_define

begin_define
define|#
directive|define
name|arena_new
value|JEMALLOC_N(arena_new)
end_define

begin_define
define|#
directive|define
name|arena_nthreads_dec
value|JEMALLOC_N(arena_nthreads_dec)
end_define

begin_define
define|#
directive|define
name|arena_nthreads_get
value|JEMALLOC_N(arena_nthreads_get)
end_define

begin_define
define|#
directive|define
name|arena_nthreads_inc
value|JEMALLOC_N(arena_nthreads_inc)
end_define

begin_define
define|#
directive|define
name|arena_palloc
value|JEMALLOC_N(arena_palloc)
end_define

begin_define
define|#
directive|define
name|arena_postfork_child
value|JEMALLOC_N(arena_postfork_child)
end_define

begin_define
define|#
directive|define
name|arena_postfork_parent
value|JEMALLOC_N(arena_postfork_parent)
end_define

begin_define
define|#
directive|define
name|arena_prefork0
value|JEMALLOC_N(arena_prefork0)
end_define

begin_define
define|#
directive|define
name|arena_prefork1
value|JEMALLOC_N(arena_prefork1)
end_define

begin_define
define|#
directive|define
name|arena_prefork2
value|JEMALLOC_N(arena_prefork2)
end_define

begin_define
define|#
directive|define
name|arena_prefork3
value|JEMALLOC_N(arena_prefork3)
end_define

begin_define
define|#
directive|define
name|arena_prefork4
value|JEMALLOC_N(arena_prefork4)
end_define

begin_define
define|#
directive|define
name|arena_prefork5
value|JEMALLOC_N(arena_prefork5)
end_define

begin_define
define|#
directive|define
name|arena_prefork6
value|JEMALLOC_N(arena_prefork6)
end_define

begin_define
define|#
directive|define
name|arena_prof_promote
value|JEMALLOC_N(arena_prof_promote)
end_define

begin_define
define|#
directive|define
name|arena_ralloc
value|JEMALLOC_N(arena_ralloc)
end_define

begin_define
define|#
directive|define
name|arena_ralloc_no_move
value|JEMALLOC_N(arena_ralloc_no_move)
end_define

begin_define
define|#
directive|define
name|arena_reset
value|JEMALLOC_N(arena_reset)
end_define

begin_define
define|#
directive|define
name|arena_stats_large_nrequests_add
value|JEMALLOC_N(arena_stats_large_nrequests_add)
end_define

begin_define
define|#
directive|define
name|arena_stats_mapped_add
value|JEMALLOC_N(arena_stats_mapped_add)
end_define

begin_define
define|#
directive|define
name|arena_stats_merge
value|JEMALLOC_N(arena_stats_merge)
end_define

begin_define
define|#
directive|define
name|arena_tcache_fill_small
value|JEMALLOC_N(arena_tcache_fill_small)
end_define

begin_define
define|#
directive|define
name|h_steps
value|JEMALLOC_N(h_steps)
end_define

begin_define
define|#
directive|define
name|opt_dirty_decay_ms
value|JEMALLOC_N(opt_dirty_decay_ms)
end_define

begin_define
define|#
directive|define
name|opt_muzzy_decay_ms
value|JEMALLOC_N(opt_muzzy_decay_ms)
end_define

begin_define
define|#
directive|define
name|opt_percpu_arena
value|JEMALLOC_N(opt_percpu_arena)
end_define

begin_define
define|#
directive|define
name|percpu_arena_mode_names
value|JEMALLOC_N(percpu_arena_mode_names)
end_define

begin_define
define|#
directive|define
name|background_thread_boot0
value|JEMALLOC_N(background_thread_boot0)
end_define

begin_define
define|#
directive|define
name|background_thread_boot1
value|JEMALLOC_N(background_thread_boot1)
end_define

begin_define
define|#
directive|define
name|background_thread_create
value|JEMALLOC_N(background_thread_create)
end_define

begin_define
define|#
directive|define
name|background_thread_ctl_init
value|JEMALLOC_N(background_thread_ctl_init)
end_define

begin_define
define|#
directive|define
name|background_thread_enabled_state
value|JEMALLOC_N(background_thread_enabled_state)
end_define

begin_define
define|#
directive|define
name|background_thread_info
value|JEMALLOC_N(background_thread_info)
end_define

begin_define
define|#
directive|define
name|background_thread_interval_check
value|JEMALLOC_N(background_thread_interval_check)
end_define

begin_define
define|#
directive|define
name|background_thread_lock
value|JEMALLOC_N(background_thread_lock)
end_define

begin_define
define|#
directive|define
name|background_thread_postfork_child
value|JEMALLOC_N(background_thread_postfork_child)
end_define

begin_define
define|#
directive|define
name|background_thread_postfork_parent
value|JEMALLOC_N(background_thread_postfork_parent)
end_define

begin_define
define|#
directive|define
name|background_thread_prefork0
value|JEMALLOC_N(background_thread_prefork0)
end_define

begin_define
define|#
directive|define
name|background_thread_prefork1
value|JEMALLOC_N(background_thread_prefork1)
end_define

begin_define
define|#
directive|define
name|background_thread_stats_read
value|JEMALLOC_N(background_thread_stats_read)
end_define

begin_define
define|#
directive|define
name|background_threads_disable
value|JEMALLOC_N(background_threads_disable)
end_define

begin_define
define|#
directive|define
name|background_threads_enable
value|JEMALLOC_N(background_threads_enable)
end_define

begin_define
define|#
directive|define
name|can_enable_background_thread
value|JEMALLOC_N(can_enable_background_thread)
end_define

begin_define
define|#
directive|define
name|n_background_threads
value|JEMALLOC_N(n_background_threads)
end_define

begin_define
define|#
directive|define
name|opt_background_thread
value|JEMALLOC_N(opt_background_thread)
end_define

begin_define
define|#
directive|define
name|pthread_create_wrapper
value|JEMALLOC_N(pthread_create_wrapper)
end_define

begin_define
define|#
directive|define
name|b0get
value|JEMALLOC_N(b0get)
end_define

begin_define
define|#
directive|define
name|base_alloc
value|JEMALLOC_N(base_alloc)
end_define

begin_define
define|#
directive|define
name|base_alloc_extent
value|JEMALLOC_N(base_alloc_extent)
end_define

begin_define
define|#
directive|define
name|base_boot
value|JEMALLOC_N(base_boot)
end_define

begin_define
define|#
directive|define
name|base_delete
value|JEMALLOC_N(base_delete)
end_define

begin_define
define|#
directive|define
name|base_extent_hooks_get
value|JEMALLOC_N(base_extent_hooks_get)
end_define

begin_define
define|#
directive|define
name|base_extent_hooks_set
value|JEMALLOC_N(base_extent_hooks_set)
end_define

begin_define
define|#
directive|define
name|base_new
value|JEMALLOC_N(base_new)
end_define

begin_define
define|#
directive|define
name|base_postfork_child
value|JEMALLOC_N(base_postfork_child)
end_define

begin_define
define|#
directive|define
name|base_postfork_parent
value|JEMALLOC_N(base_postfork_parent)
end_define

begin_define
define|#
directive|define
name|base_prefork
value|JEMALLOC_N(base_prefork)
end_define

begin_define
define|#
directive|define
name|base_stats_get
value|JEMALLOC_N(base_stats_get)
end_define

begin_define
define|#
directive|define
name|bitmap_info_init
value|JEMALLOC_N(bitmap_info_init)
end_define

begin_define
define|#
directive|define
name|bitmap_init
value|JEMALLOC_N(bitmap_init)
end_define

begin_define
define|#
directive|define
name|bitmap_size
value|JEMALLOC_N(bitmap_size)
end_define

begin_define
define|#
directive|define
name|ckh_count
value|JEMALLOC_N(ckh_count)
end_define

begin_define
define|#
directive|define
name|ckh_delete
value|JEMALLOC_N(ckh_delete)
end_define

begin_define
define|#
directive|define
name|ckh_insert
value|JEMALLOC_N(ckh_insert)
end_define

begin_define
define|#
directive|define
name|ckh_iter
value|JEMALLOC_N(ckh_iter)
end_define

begin_define
define|#
directive|define
name|ckh_new
value|JEMALLOC_N(ckh_new)
end_define

begin_define
define|#
directive|define
name|ckh_pointer_hash
value|JEMALLOC_N(ckh_pointer_hash)
end_define

begin_define
define|#
directive|define
name|ckh_pointer_keycomp
value|JEMALLOC_N(ckh_pointer_keycomp)
end_define

begin_define
define|#
directive|define
name|ckh_remove
value|JEMALLOC_N(ckh_remove)
end_define

begin_define
define|#
directive|define
name|ckh_search
value|JEMALLOC_N(ckh_search)
end_define

begin_define
define|#
directive|define
name|ckh_string_hash
value|JEMALLOC_N(ckh_string_hash)
end_define

begin_define
define|#
directive|define
name|ckh_string_keycomp
value|JEMALLOC_N(ckh_string_keycomp)
end_define

begin_define
define|#
directive|define
name|ctl_boot
value|JEMALLOC_N(ctl_boot)
end_define

begin_define
define|#
directive|define
name|ctl_bymib
value|JEMALLOC_N(ctl_bymib)
end_define

begin_define
define|#
directive|define
name|ctl_byname
value|JEMALLOC_N(ctl_byname)
end_define

begin_define
define|#
directive|define
name|ctl_nametomib
value|JEMALLOC_N(ctl_nametomib)
end_define

begin_define
define|#
directive|define
name|ctl_postfork_child
value|JEMALLOC_N(ctl_postfork_child)
end_define

begin_define
define|#
directive|define
name|ctl_postfork_parent
value|JEMALLOC_N(ctl_postfork_parent)
end_define

begin_define
define|#
directive|define
name|ctl_prefork
value|JEMALLOC_N(ctl_prefork)
end_define

begin_define
define|#
directive|define
name|extent_alloc
value|JEMALLOC_N(extent_alloc)
end_define

begin_define
define|#
directive|define
name|extent_alloc_wrapper
value|JEMALLOC_N(extent_alloc_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_avail_destroy
value|JEMALLOC_N(extent_avail_destroy)
end_define

begin_define
define|#
directive|define
name|extent_avail_destroy_recurse
value|JEMALLOC_N(extent_avail_destroy_recurse)
end_define

begin_define
define|#
directive|define
name|extent_avail_empty
value|JEMALLOC_N(extent_avail_empty)
end_define

begin_define
define|#
directive|define
name|extent_avail_first
value|JEMALLOC_N(extent_avail_first)
end_define

begin_define
define|#
directive|define
name|extent_avail_insert
value|JEMALLOC_N(extent_avail_insert)
end_define

begin_define
define|#
directive|define
name|extent_avail_iter
value|JEMALLOC_N(extent_avail_iter)
end_define

begin_define
define|#
directive|define
name|extent_avail_iter_recurse
value|JEMALLOC_N(extent_avail_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_avail_iter_start
value|JEMALLOC_N(extent_avail_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_avail_last
value|JEMALLOC_N(extent_avail_last)
end_define

begin_define
define|#
directive|define
name|extent_avail_new
value|JEMALLOC_N(extent_avail_new)
end_define

begin_define
define|#
directive|define
name|extent_avail_next
value|JEMALLOC_N(extent_avail_next)
end_define

begin_define
define|#
directive|define
name|extent_avail_nsearch
value|JEMALLOC_N(extent_avail_nsearch)
end_define

begin_define
define|#
directive|define
name|extent_avail_prev
value|JEMALLOC_N(extent_avail_prev)
end_define

begin_define
define|#
directive|define
name|extent_avail_psearch
value|JEMALLOC_N(extent_avail_psearch)
end_define

begin_define
define|#
directive|define
name|extent_avail_remove
value|JEMALLOC_N(extent_avail_remove)
end_define

begin_define
define|#
directive|define
name|extent_avail_reverse_iter
value|JEMALLOC_N(extent_avail_reverse_iter)
end_define

begin_define
define|#
directive|define
name|extent_avail_reverse_iter_recurse
value|JEMALLOC_N(extent_avail_reverse_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_avail_reverse_iter_start
value|JEMALLOC_N(extent_avail_reverse_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_avail_search
value|JEMALLOC_N(extent_avail_search)
end_define

begin_define
define|#
directive|define
name|extent_boot
value|JEMALLOC_N(extent_boot)
end_define

begin_define
define|#
directive|define
name|extent_commit_wrapper
value|JEMALLOC_N(extent_commit_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_dalloc
value|JEMALLOC_N(extent_dalloc)
end_define

begin_define
define|#
directive|define
name|extent_dalloc_gap
value|JEMALLOC_N(extent_dalloc_gap)
end_define

begin_define
define|#
directive|define
name|extent_dalloc_wrapper
value|JEMALLOC_N(extent_dalloc_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_decommit_wrapper
value|JEMALLOC_N(extent_decommit_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_destroy_wrapper
value|JEMALLOC_N(extent_destroy_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_heap_any
value|JEMALLOC_N(extent_heap_any)
end_define

begin_define
define|#
directive|define
name|extent_heap_empty
value|JEMALLOC_N(extent_heap_empty)
end_define

begin_define
define|#
directive|define
name|extent_heap_first
value|JEMALLOC_N(extent_heap_first)
end_define

begin_define
define|#
directive|define
name|extent_heap_insert
value|JEMALLOC_N(extent_heap_insert)
end_define

begin_define
define|#
directive|define
name|extent_heap_new
value|JEMALLOC_N(extent_heap_new)
end_define

begin_define
define|#
directive|define
name|extent_heap_remove
value|JEMALLOC_N(extent_heap_remove)
end_define

begin_define
define|#
directive|define
name|extent_heap_remove_any
value|JEMALLOC_N(extent_heap_remove_any)
end_define

begin_define
define|#
directive|define
name|extent_heap_remove_first
value|JEMALLOC_N(extent_heap_remove_first)
end_define

begin_define
define|#
directive|define
name|extent_hooks_default
value|JEMALLOC_N(extent_hooks_default)
end_define

begin_define
define|#
directive|define
name|extent_hooks_get
value|JEMALLOC_N(extent_hooks_get)
end_define

begin_define
define|#
directive|define
name|extent_hooks_set
value|JEMALLOC_N(extent_hooks_set)
end_define

begin_define
define|#
directive|define
name|extent_merge_wrapper
value|JEMALLOC_N(extent_merge_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_mutex_pool
value|JEMALLOC_N(extent_mutex_pool)
end_define

begin_define
define|#
directive|define
name|extent_purge_forced_wrapper
value|JEMALLOC_N(extent_purge_forced_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_purge_lazy_wrapper
value|JEMALLOC_N(extent_purge_lazy_wrapper)
end_define

begin_define
define|#
directive|define
name|extent_split_wrapper
value|JEMALLOC_N(extent_split_wrapper)
end_define

begin_define
define|#
directive|define
name|extents_alloc
value|JEMALLOC_N(extents_alloc)
end_define

begin_define
define|#
directive|define
name|extents_dalloc
value|JEMALLOC_N(extents_dalloc)
end_define

begin_define
define|#
directive|define
name|extents_evict
value|JEMALLOC_N(extents_evict)
end_define

begin_define
define|#
directive|define
name|extents_init
value|JEMALLOC_N(extents_init)
end_define

begin_define
define|#
directive|define
name|extents_npages_get
value|JEMALLOC_N(extents_npages_get)
end_define

begin_define
define|#
directive|define
name|extents_postfork_child
value|JEMALLOC_N(extents_postfork_child)
end_define

begin_define
define|#
directive|define
name|extents_postfork_parent
value|JEMALLOC_N(extents_postfork_parent)
end_define

begin_define
define|#
directive|define
name|extents_prefork
value|JEMALLOC_N(extents_prefork)
end_define

begin_define
define|#
directive|define
name|extents_rtree
value|JEMALLOC_N(extents_rtree)
end_define

begin_define
define|#
directive|define
name|extents_state_get
value|JEMALLOC_N(extents_state_get)
end_define

begin_define
define|#
directive|define
name|dss_prec_names
value|JEMALLOC_N(dss_prec_names)
end_define

begin_define
define|#
directive|define
name|extent_alloc_dss
value|JEMALLOC_N(extent_alloc_dss)
end_define

begin_define
define|#
directive|define
name|extent_dss_boot
value|JEMALLOC_N(extent_dss_boot)
end_define

begin_define
define|#
directive|define
name|extent_dss_mergeable
value|JEMALLOC_N(extent_dss_mergeable)
end_define

begin_define
define|#
directive|define
name|extent_dss_prec_get
value|JEMALLOC_N(extent_dss_prec_get)
end_define

begin_define
define|#
directive|define
name|extent_dss_prec_set
value|JEMALLOC_N(extent_dss_prec_set)
end_define

begin_define
define|#
directive|define
name|extent_in_dss
value|JEMALLOC_N(extent_in_dss)
end_define

begin_define
define|#
directive|define
name|opt_dss
value|JEMALLOC_N(opt_dss)
end_define

begin_define
define|#
directive|define
name|extent_alloc_mmap
value|JEMALLOC_N(extent_alloc_mmap)
end_define

begin_define
define|#
directive|define
name|extent_dalloc_mmap
value|JEMALLOC_N(extent_dalloc_mmap)
end_define

begin_define
define|#
directive|define
name|opt_retain
value|JEMALLOC_N(opt_retain)
end_define

begin_define
define|#
directive|define
name|hooks_arena_new_hook
value|JEMALLOC_N(hooks_arena_new_hook)
end_define

begin_define
define|#
directive|define
name|hooks_libc_hook
value|JEMALLOC_N(hooks_libc_hook)
end_define

begin_define
define|#
directive|define
name|large_dalloc
value|JEMALLOC_N(large_dalloc)
end_define

begin_define
define|#
directive|define
name|large_dalloc_finish
value|JEMALLOC_N(large_dalloc_finish)
end_define

begin_define
define|#
directive|define
name|large_dalloc_junk
value|JEMALLOC_N(large_dalloc_junk)
end_define

begin_define
define|#
directive|define
name|large_dalloc_maybe_junk
value|JEMALLOC_N(large_dalloc_maybe_junk)
end_define

begin_define
define|#
directive|define
name|large_dalloc_prep_junked_locked
value|JEMALLOC_N(large_dalloc_prep_junked_locked)
end_define

begin_define
define|#
directive|define
name|large_malloc
value|JEMALLOC_N(large_malloc)
end_define

begin_define
define|#
directive|define
name|large_palloc
value|JEMALLOC_N(large_palloc)
end_define

begin_define
define|#
directive|define
name|large_prof_tctx_get
value|JEMALLOC_N(large_prof_tctx_get)
end_define

begin_define
define|#
directive|define
name|large_prof_tctx_reset
value|JEMALLOC_N(large_prof_tctx_reset)
end_define

begin_define
define|#
directive|define
name|large_prof_tctx_set
value|JEMALLOC_N(large_prof_tctx_set)
end_define

begin_define
define|#
directive|define
name|large_ralloc
value|JEMALLOC_N(large_ralloc)
end_define

begin_define
define|#
directive|define
name|large_ralloc_no_move
value|JEMALLOC_N(large_ralloc_no_move)
end_define

begin_define
define|#
directive|define
name|large_salloc
value|JEMALLOC_N(large_salloc)
end_define

begin_define
define|#
directive|define
name|buferror
value|JEMALLOC_N(buferror)
end_define

begin_define
define|#
directive|define
name|malloc_cprintf
value|JEMALLOC_N(malloc_cprintf)
end_define

begin_define
define|#
directive|define
name|malloc_printf
value|JEMALLOC_N(malloc_printf)
end_define

begin_define
define|#
directive|define
name|malloc_snprintf
value|JEMALLOC_N(malloc_snprintf)
end_define

begin_define
define|#
directive|define
name|malloc_strtoumax
value|JEMALLOC_N(malloc_strtoumax)
end_define

begin_define
define|#
directive|define
name|malloc_vcprintf
value|JEMALLOC_N(malloc_vcprintf)
end_define

begin_define
define|#
directive|define
name|malloc_vsnprintf
value|JEMALLOC_N(malloc_vsnprintf)
end_define

begin_define
define|#
directive|define
name|malloc_write
value|JEMALLOC_N(malloc_write)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_boot
value|JEMALLOC_N(malloc_mutex_boot)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_init
value|JEMALLOC_N(malloc_mutex_init)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_lock_slow
value|JEMALLOC_N(malloc_mutex_lock_slow)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_postfork_child
value|JEMALLOC_N(malloc_mutex_postfork_child)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_postfork_parent
value|JEMALLOC_N(malloc_mutex_postfork_parent)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_prefork
value|JEMALLOC_N(malloc_mutex_prefork)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_prof_data_reset
value|JEMALLOC_N(malloc_mutex_prof_data_reset)
end_define

begin_define
define|#
directive|define
name|mutex_pool_init
value|JEMALLOC_N(mutex_pool_init)
end_define

begin_define
define|#
directive|define
name|nstime_add
value|JEMALLOC_N(nstime_add)
end_define

begin_define
define|#
directive|define
name|nstime_compare
value|JEMALLOC_N(nstime_compare)
end_define

begin_define
define|#
directive|define
name|nstime_copy
value|JEMALLOC_N(nstime_copy)
end_define

begin_define
define|#
directive|define
name|nstime_divide
value|JEMALLOC_N(nstime_divide)
end_define

begin_define
define|#
directive|define
name|nstime_iadd
value|JEMALLOC_N(nstime_iadd)
end_define

begin_define
define|#
directive|define
name|nstime_idivide
value|JEMALLOC_N(nstime_idivide)
end_define

begin_define
define|#
directive|define
name|nstime_imultiply
value|JEMALLOC_N(nstime_imultiply)
end_define

begin_define
define|#
directive|define
name|nstime_init
value|JEMALLOC_N(nstime_init)
end_define

begin_define
define|#
directive|define
name|nstime_init2
value|JEMALLOC_N(nstime_init2)
end_define

begin_define
define|#
directive|define
name|nstime_isubtract
value|JEMALLOC_N(nstime_isubtract)
end_define

begin_define
define|#
directive|define
name|nstime_monotonic
value|JEMALLOC_N(nstime_monotonic)
end_define

begin_define
define|#
directive|define
name|nstime_msec
value|JEMALLOC_N(nstime_msec)
end_define

begin_define
define|#
directive|define
name|nstime_ns
value|JEMALLOC_N(nstime_ns)
end_define

begin_define
define|#
directive|define
name|nstime_nsec
value|JEMALLOC_N(nstime_nsec)
end_define

begin_define
define|#
directive|define
name|nstime_sec
value|JEMALLOC_N(nstime_sec)
end_define

begin_define
define|#
directive|define
name|nstime_subtract
value|JEMALLOC_N(nstime_subtract)
end_define

begin_define
define|#
directive|define
name|nstime_update
value|JEMALLOC_N(nstime_update)
end_define

begin_define
define|#
directive|define
name|pages_boot
value|JEMALLOC_N(pages_boot)
end_define

begin_define
define|#
directive|define
name|pages_commit
value|JEMALLOC_N(pages_commit)
end_define

begin_define
define|#
directive|define
name|pages_decommit
value|JEMALLOC_N(pages_decommit)
end_define

begin_define
define|#
directive|define
name|pages_huge
value|JEMALLOC_N(pages_huge)
end_define

begin_define
define|#
directive|define
name|pages_map
value|JEMALLOC_N(pages_map)
end_define

begin_define
define|#
directive|define
name|pages_nohuge
value|JEMALLOC_N(pages_nohuge)
end_define

begin_define
define|#
directive|define
name|pages_purge_forced
value|JEMALLOC_N(pages_purge_forced)
end_define

begin_define
define|#
directive|define
name|pages_purge_lazy
value|JEMALLOC_N(pages_purge_lazy)
end_define

begin_define
define|#
directive|define
name|pages_unmap
value|JEMALLOC_N(pages_unmap)
end_define

begin_define
define|#
directive|define
name|bt2gctx_mtx
value|JEMALLOC_N(bt2gctx_mtx)
end_define

begin_define
define|#
directive|define
name|bt_init
value|JEMALLOC_N(bt_init)
end_define

begin_define
define|#
directive|define
name|lg_prof_sample
value|JEMALLOC_N(lg_prof_sample)
end_define

begin_define
define|#
directive|define
name|opt_lg_prof_interval
value|JEMALLOC_N(opt_lg_prof_interval)
end_define

begin_define
define|#
directive|define
name|opt_lg_prof_sample
value|JEMALLOC_N(opt_lg_prof_sample)
end_define

begin_define
define|#
directive|define
name|opt_prof
value|JEMALLOC_N(opt_prof)
end_define

begin_define
define|#
directive|define
name|opt_prof_accum
value|JEMALLOC_N(opt_prof_accum)
end_define

begin_define
define|#
directive|define
name|opt_prof_active
value|JEMALLOC_N(opt_prof_active)
end_define

begin_define
define|#
directive|define
name|opt_prof_final
value|JEMALLOC_N(opt_prof_final)
end_define

begin_define
define|#
directive|define
name|opt_prof_gdump
value|JEMALLOC_N(opt_prof_gdump)
end_define

begin_define
define|#
directive|define
name|opt_prof_leak
value|JEMALLOC_N(opt_prof_leak)
end_define

begin_define
define|#
directive|define
name|opt_prof_prefix
value|JEMALLOC_N(opt_prof_prefix)
end_define

begin_define
define|#
directive|define
name|opt_prof_thread_active_init
value|JEMALLOC_N(opt_prof_thread_active_init)
end_define

begin_define
define|#
directive|define
name|prof_accum_init
value|JEMALLOC_N(prof_accum_init)
end_define

begin_define
define|#
directive|define
name|prof_active
value|JEMALLOC_N(prof_active)
end_define

begin_define
define|#
directive|define
name|prof_active_get
value|JEMALLOC_N(prof_active_get)
end_define

begin_define
define|#
directive|define
name|prof_active_set
value|JEMALLOC_N(prof_active_set)
end_define

begin_define
define|#
directive|define
name|prof_alloc_rollback
value|JEMALLOC_N(prof_alloc_rollback)
end_define

begin_define
define|#
directive|define
name|prof_backtrace
value|JEMALLOC_N(prof_backtrace)
end_define

begin_define
define|#
directive|define
name|prof_boot0
value|JEMALLOC_N(prof_boot0)
end_define

begin_define
define|#
directive|define
name|prof_boot1
value|JEMALLOC_N(prof_boot1)
end_define

begin_define
define|#
directive|define
name|prof_boot2
value|JEMALLOC_N(prof_boot2)
end_define

begin_define
define|#
directive|define
name|prof_dump_header
value|JEMALLOC_N(prof_dump_header)
end_define

begin_define
define|#
directive|define
name|prof_dump_open
value|JEMALLOC_N(prof_dump_open)
end_define

begin_define
define|#
directive|define
name|prof_free_sampled_object
value|JEMALLOC_N(prof_free_sampled_object)
end_define

begin_define
define|#
directive|define
name|prof_gdump
value|JEMALLOC_N(prof_gdump)
end_define

begin_define
define|#
directive|define
name|prof_gdump_get
value|JEMALLOC_N(prof_gdump_get)
end_define

begin_define
define|#
directive|define
name|prof_gdump_set
value|JEMALLOC_N(prof_gdump_set)
end_define

begin_define
define|#
directive|define
name|prof_gdump_val
value|JEMALLOC_N(prof_gdump_val)
end_define

begin_define
define|#
directive|define
name|prof_idump
value|JEMALLOC_N(prof_idump)
end_define

begin_define
define|#
directive|define
name|prof_interval
value|JEMALLOC_N(prof_interval)
end_define

begin_define
define|#
directive|define
name|prof_lookup
value|JEMALLOC_N(prof_lookup)
end_define

begin_define
define|#
directive|define
name|prof_malloc_sample_object
value|JEMALLOC_N(prof_malloc_sample_object)
end_define

begin_define
define|#
directive|define
name|prof_mdump
value|JEMALLOC_N(prof_mdump)
end_define

begin_define
define|#
directive|define
name|prof_postfork_child
value|JEMALLOC_N(prof_postfork_child)
end_define

begin_define
define|#
directive|define
name|prof_postfork_parent
value|JEMALLOC_N(prof_postfork_parent)
end_define

begin_define
define|#
directive|define
name|prof_prefork0
value|JEMALLOC_N(prof_prefork0)
end_define

begin_define
define|#
directive|define
name|prof_prefork1
value|JEMALLOC_N(prof_prefork1)
end_define

begin_define
define|#
directive|define
name|prof_reset
value|JEMALLOC_N(prof_reset)
end_define

begin_define
define|#
directive|define
name|prof_sample_threshold_update
value|JEMALLOC_N(prof_sample_threshold_update)
end_define

begin_define
define|#
directive|define
name|prof_tdata_cleanup
value|JEMALLOC_N(prof_tdata_cleanup)
end_define

begin_define
define|#
directive|define
name|prof_tdata_init
value|JEMALLOC_N(prof_tdata_init)
end_define

begin_define
define|#
directive|define
name|prof_tdata_reinit
value|JEMALLOC_N(prof_tdata_reinit)
end_define

begin_define
define|#
directive|define
name|prof_thread_active_get
value|JEMALLOC_N(prof_thread_active_get)
end_define

begin_define
define|#
directive|define
name|prof_thread_active_init_get
value|JEMALLOC_N(prof_thread_active_init_get)
end_define

begin_define
define|#
directive|define
name|prof_thread_active_init_set
value|JEMALLOC_N(prof_thread_active_init_set)
end_define

begin_define
define|#
directive|define
name|prof_thread_active_set
value|JEMALLOC_N(prof_thread_active_set)
end_define

begin_define
define|#
directive|define
name|prof_thread_name_get
value|JEMALLOC_N(prof_thread_name_get)
end_define

begin_define
define|#
directive|define
name|prof_thread_name_set
value|JEMALLOC_N(prof_thread_name_set)
end_define

begin_define
define|#
directive|define
name|rtree_ctx_data_init
value|JEMALLOC_N(rtree_ctx_data_init)
end_define

begin_define
define|#
directive|define
name|rtree_leaf_alloc
value|JEMALLOC_N(rtree_leaf_alloc)
end_define

begin_define
define|#
directive|define
name|rtree_leaf_dalloc
value|JEMALLOC_N(rtree_leaf_dalloc)
end_define

begin_define
define|#
directive|define
name|rtree_leaf_elm_lookup_hard
value|JEMALLOC_N(rtree_leaf_elm_lookup_hard)
end_define

begin_define
define|#
directive|define
name|rtree_new
value|JEMALLOC_N(rtree_new)
end_define

begin_define
define|#
directive|define
name|rtree_node_alloc
value|JEMALLOC_N(rtree_node_alloc)
end_define

begin_define
define|#
directive|define
name|rtree_node_dalloc
value|JEMALLOC_N(rtree_node_dalloc)
end_define

begin_define
define|#
directive|define
name|arena_mutex_names
value|JEMALLOC_N(arena_mutex_names)
end_define

begin_define
define|#
directive|define
name|global_mutex_names
value|JEMALLOC_N(global_mutex_names)
end_define

begin_define
define|#
directive|define
name|opt_stats_print
value|JEMALLOC_N(opt_stats_print)
end_define

begin_define
define|#
directive|define
name|opt_stats_print_opts
value|JEMALLOC_N(opt_stats_print_opts)
end_define

begin_define
define|#
directive|define
name|stats_print
value|JEMALLOC_N(stats_print)
end_define

begin_define
define|#
directive|define
name|spin_adaptive
value|JEMALLOC_N(spin_adaptive)
end_define

begin_define
define|#
directive|define
name|sz_index2size_tab
value|JEMALLOC_N(sz_index2size_tab)
end_define

begin_define
define|#
directive|define
name|sz_pind2sz_tab
value|JEMALLOC_N(sz_pind2sz_tab)
end_define

begin_define
define|#
directive|define
name|sz_size2index_tab
value|JEMALLOC_N(sz_size2index_tab)
end_define

begin_define
define|#
directive|define
name|nhbins
value|JEMALLOC_N(nhbins)
end_define

begin_define
define|#
directive|define
name|opt_lg_tcache_max
value|JEMALLOC_N(opt_lg_tcache_max)
end_define

begin_define
define|#
directive|define
name|opt_tcache
value|JEMALLOC_N(opt_tcache)
end_define

begin_define
define|#
directive|define
name|tcache_alloc_small_hard
value|JEMALLOC_N(tcache_alloc_small_hard)
end_define

begin_define
define|#
directive|define
name|tcache_arena_associate
value|JEMALLOC_N(tcache_arena_associate)
end_define

begin_define
define|#
directive|define
name|tcache_arena_reassociate
value|JEMALLOC_N(tcache_arena_reassociate)
end_define

begin_define
define|#
directive|define
name|tcache_bin_flush_large
value|JEMALLOC_N(tcache_bin_flush_large)
end_define

begin_define
define|#
directive|define
name|tcache_bin_flush_small
value|JEMALLOC_N(tcache_bin_flush_small)
end_define

begin_define
define|#
directive|define
name|tcache_bin_info
value|JEMALLOC_N(tcache_bin_info)
end_define

begin_define
define|#
directive|define
name|tcache_boot
value|JEMALLOC_N(tcache_boot)
end_define

begin_define
define|#
directive|define
name|tcache_cleanup
value|JEMALLOC_N(tcache_cleanup)
end_define

begin_define
define|#
directive|define
name|tcache_create_explicit
value|JEMALLOC_N(tcache_create_explicit)
end_define

begin_define
define|#
directive|define
name|tcache_event_hard
value|JEMALLOC_N(tcache_event_hard)
end_define

begin_define
define|#
directive|define
name|tcache_flush
value|JEMALLOC_N(tcache_flush)
end_define

begin_define
define|#
directive|define
name|tcache_maxclass
value|JEMALLOC_N(tcache_maxclass)
end_define

begin_define
define|#
directive|define
name|tcache_postfork_child
value|JEMALLOC_N(tcache_postfork_child)
end_define

begin_define
define|#
directive|define
name|tcache_postfork_parent
value|JEMALLOC_N(tcache_postfork_parent)
end_define

begin_define
define|#
directive|define
name|tcache_prefork
value|JEMALLOC_N(tcache_prefork)
end_define

begin_define
define|#
directive|define
name|tcache_salloc
value|JEMALLOC_N(tcache_salloc)
end_define

begin_define
define|#
directive|define
name|tcache_stats_merge
value|JEMALLOC_N(tcache_stats_merge)
end_define

begin_define
define|#
directive|define
name|tcaches
value|JEMALLOC_N(tcaches)
end_define

begin_define
define|#
directive|define
name|tcaches_create
value|JEMALLOC_N(tcaches_create)
end_define

begin_define
define|#
directive|define
name|tcaches_destroy
value|JEMALLOC_N(tcaches_destroy)
end_define

begin_define
define|#
directive|define
name|tcaches_flush
value|JEMALLOC_N(tcaches_flush)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_data_init
value|JEMALLOC_N(tsd_tcache_data_init)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_enabled_data_init
value|JEMALLOC_N(tsd_tcache_enabled_data_init)
end_define

begin_define
define|#
directive|define
name|malloc_tsd_boot0
value|JEMALLOC_N(malloc_tsd_boot0)
end_define

begin_define
define|#
directive|define
name|malloc_tsd_boot1
value|JEMALLOC_N(malloc_tsd_boot1)
end_define

begin_define
define|#
directive|define
name|malloc_tsd_cleanup_register
value|JEMALLOC_N(malloc_tsd_cleanup_register)
end_define

begin_define
define|#
directive|define
name|malloc_tsd_dalloc
value|JEMALLOC_N(malloc_tsd_dalloc)
end_define

begin_define
define|#
directive|define
name|malloc_tsd_malloc
value|JEMALLOC_N(malloc_tsd_malloc)
end_define

begin_define
define|#
directive|define
name|tsd_booted
value|JEMALLOC_N(tsd_booted)
end_define

begin_define
define|#
directive|define
name|tsd_cleanup
value|JEMALLOC_N(tsd_cleanup)
end_define

begin_define
define|#
directive|define
name|tsd_fetch_slow
value|JEMALLOC_N(tsd_fetch_slow)
end_define

begin_define
define|#
directive|define
name|tsd_initialized
value|JEMALLOC_N(tsd_initialized)
end_define

begin_define
define|#
directive|define
name|tsd_slow_update
value|JEMALLOC_N(tsd_slow_update)
end_define

begin_define
define|#
directive|define
name|tsd_tls
value|JEMALLOC_N(tsd_tls)
end_define

begin_define
define|#
directive|define
name|witness_depth_error
value|JEMALLOC_N(witness_depth_error)
end_define

begin_define
define|#
directive|define
name|witness_init
value|JEMALLOC_N(witness_init)
end_define

begin_define
define|#
directive|define
name|witness_lock_error
value|JEMALLOC_N(witness_lock_error)
end_define

begin_define
define|#
directive|define
name|witness_not_owner_error
value|JEMALLOC_N(witness_not_owner_error)
end_define

begin_define
define|#
directive|define
name|witness_owner_error
value|JEMALLOC_N(witness_owner_error)
end_define

begin_define
define|#
directive|define
name|witness_postfork_child
value|JEMALLOC_N(witness_postfork_child)
end_define

begin_define
define|#
directive|define
name|witness_postfork_parent
value|JEMALLOC_N(witness_postfork_parent)
end_define

begin_define
define|#
directive|define
name|witness_prefork
value|JEMALLOC_N(witness_prefork)
end_define

begin_define
define|#
directive|define
name|witnesses_cleanup
value|JEMALLOC_N(witnesses_cleanup)
end_define

end_unit

