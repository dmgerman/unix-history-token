begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|a0calloc
value|JEMALLOC_N(a0calloc)
end_define

begin_define
define|#
directive|define
name|a0free
value|JEMALLOC_N(a0free)
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
name|arena_alloc_junk_small
value|JEMALLOC_N(arena_alloc_junk_small)
end_define

begin_define
define|#
directive|define
name|arena_bin_index
value|JEMALLOC_N(arena_bin_index)
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
name|arena_dalloc
value|JEMALLOC_N(arena_dalloc)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_bin
value|JEMALLOC_N(arena_dalloc_bin)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_bin_locked
value|JEMALLOC_N(arena_dalloc_bin_locked)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_junk_large
value|JEMALLOC_N(arena_dalloc_junk_large)
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
name|arena_dalloc_large
value|JEMALLOC_N(arena_dalloc_large)
end_define

begin_define
define|#
directive|define
name|arena_dalloc_large_locked
value|JEMALLOC_N(arena_dalloc_large_locked)
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
name|arena_malloc
value|JEMALLOC_N(arena_malloc)
end_define

begin_define
define|#
directive|define
name|arena_malloc_large
value|JEMALLOC_N(arena_malloc_large)
end_define

begin_define
define|#
directive|define
name|arena_malloc_small
value|JEMALLOC_N(arena_malloc_small)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_allocated_get
value|JEMALLOC_N(arena_mapbits_allocated_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_binind_get
value|JEMALLOC_N(arena_mapbits_binind_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_dirty_get
value|JEMALLOC_N(arena_mapbits_dirty_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_get
value|JEMALLOC_N(arena_mapbits_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_large_binind_set
value|JEMALLOC_N(arena_mapbits_large_binind_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_large_get
value|JEMALLOC_N(arena_mapbits_large_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_large_set
value|JEMALLOC_N(arena_mapbits_large_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_large_size_get
value|JEMALLOC_N(arena_mapbits_large_size_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_small_runind_get
value|JEMALLOC_N(arena_mapbits_small_runind_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_small_set
value|JEMALLOC_N(arena_mapbits_small_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_unallocated_set
value|JEMALLOC_N(arena_mapbits_unallocated_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_unallocated_size_get
value|JEMALLOC_N(arena_mapbits_unallocated_size_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_unallocated_size_set
value|JEMALLOC_N(arena_mapbits_unallocated_size_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_unzeroed_get
value|JEMALLOC_N(arena_mapbits_unzeroed_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_unzeroed_set
value|JEMALLOC_N(arena_mapbits_unzeroed_set)
end_define

begin_define
define|#
directive|define
name|arena_mapbitsp_get
value|JEMALLOC_N(arena_mapbitsp_get)
end_define

begin_define
define|#
directive|define
name|arena_mapbitsp_read
value|JEMALLOC_N(arena_mapbitsp_read)
end_define

begin_define
define|#
directive|define
name|arena_mapbitsp_write
value|JEMALLOC_N(arena_mapbitsp_write)
end_define

begin_define
define|#
directive|define
name|arena_mapp_get
value|JEMALLOC_N(arena_mapp_get)
end_define

begin_define
define|#
directive|define
name|arena_maxclass
value|JEMALLOC_N(arena_maxclass)
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
name|arena_prefork
value|JEMALLOC_N(arena_prefork)
end_define

begin_define
define|#
directive|define
name|arena_prof_accum
value|JEMALLOC_N(arena_prof_accum)
end_define

begin_define
define|#
directive|define
name|arena_prof_accum_impl
value|JEMALLOC_N(arena_prof_accum_impl)
end_define

begin_define
define|#
directive|define
name|arena_prof_accum_locked
value|JEMALLOC_N(arena_prof_accum_locked)
end_define

begin_define
define|#
directive|define
name|arena_prof_ctx_get
value|JEMALLOC_N(arena_prof_ctx_get)
end_define

begin_define
define|#
directive|define
name|arena_prof_ctx_set
value|JEMALLOC_N(arena_prof_ctx_set)
end_define

begin_define
define|#
directive|define
name|arena_prof_promoted
value|JEMALLOC_N(arena_prof_promoted)
end_define

begin_define
define|#
directive|define
name|arena_ptr_small_binind_get
value|JEMALLOC_N(arena_ptr_small_binind_get)
end_define

begin_define
define|#
directive|define
name|arena_purge_all
value|JEMALLOC_N(arena_purge_all)
end_define

begin_define
define|#
directive|define
name|arena_quarantine_junk_small
value|JEMALLOC_N(arena_quarantine_junk_small)
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
name|arena_ralloc_junk_large
value|JEMALLOC_N(arena_ralloc_junk_large)
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
name|arena_redzone_corruption
value|JEMALLOC_N(arena_redzone_corruption)
end_define

begin_define
define|#
directive|define
name|arena_run_regind
value|JEMALLOC_N(arena_run_regind)
end_define

begin_define
define|#
directive|define
name|arena_salloc
value|JEMALLOC_N(arena_salloc)
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
name|arenas
value|JEMALLOC_N(arenas)
end_define

begin_define
define|#
directive|define
name|arenas_booted
value|JEMALLOC_N(arenas_booted)
end_define

begin_define
define|#
directive|define
name|arenas_cleanup
value|JEMALLOC_N(arenas_cleanup)
end_define

begin_define
define|#
directive|define
name|arenas_extend
value|JEMALLOC_N(arenas_extend)
end_define

begin_define
define|#
directive|define
name|arenas_initialized
value|JEMALLOC_N(arenas_initialized)
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
name|arenas_tls
value|JEMALLOC_N(arenas_tls)
end_define

begin_define
define|#
directive|define
name|arenas_tsd
value|JEMALLOC_N(arenas_tsd)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_boot
value|JEMALLOC_N(arenas_tsd_boot)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_cleanup_wrapper
value|JEMALLOC_N(arenas_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_get
value|JEMALLOC_N(arenas_tsd_get)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_get_wrapper
value|JEMALLOC_N(arenas_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_init_head
value|JEMALLOC_N(arenas_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|arenas_tsd_set
value|JEMALLOC_N(arenas_tsd_set)
end_define

begin_define
define|#
directive|define
name|atomic_add_u
value|JEMALLOC_N(atomic_add_u)
end_define

begin_define
define|#
directive|define
name|atomic_add_uint32
value|JEMALLOC_N(atomic_add_uint32)
end_define

begin_define
define|#
directive|define
name|atomic_add_uint64
value|JEMALLOC_N(atomic_add_uint64)
end_define

begin_define
define|#
directive|define
name|atomic_add_z
value|JEMALLOC_N(atomic_add_z)
end_define

begin_define
define|#
directive|define
name|atomic_sub_u
value|JEMALLOC_N(atomic_sub_u)
end_define

begin_define
define|#
directive|define
name|atomic_sub_uint32
value|JEMALLOC_N(atomic_sub_uint32)
end_define

begin_define
define|#
directive|define
name|atomic_sub_uint64
value|JEMALLOC_N(atomic_sub_uint64)
end_define

begin_define
define|#
directive|define
name|atomic_sub_z
value|JEMALLOC_N(atomic_sub_z)
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
name|base_boot
value|JEMALLOC_N(base_boot)
end_define

begin_define
define|#
directive|define
name|base_calloc
value|JEMALLOC_N(base_calloc)
end_define

begin_define
define|#
directive|define
name|base_node_alloc
value|JEMALLOC_N(base_node_alloc)
end_define

begin_define
define|#
directive|define
name|base_node_dealloc
value|JEMALLOC_N(base_node_dealloc)
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
name|bitmap_full
value|JEMALLOC_N(bitmap_full)
end_define

begin_define
define|#
directive|define
name|bitmap_get
value|JEMALLOC_N(bitmap_get)
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
name|bitmap_info_ngroups
value|JEMALLOC_N(bitmap_info_ngroups)
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
name|bitmap_set
value|JEMALLOC_N(bitmap_set)
end_define

begin_define
define|#
directive|define
name|bitmap_sfu
value|JEMALLOC_N(bitmap_sfu)
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
name|bitmap_unset
value|JEMALLOC_N(bitmap_unset)
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
name|buferror
value|JEMALLOC_N(buferror)
end_define

begin_define
define|#
directive|define
name|choose_arena
value|JEMALLOC_N(choose_arena)
end_define

begin_define
define|#
directive|define
name|choose_arena_hard
value|JEMALLOC_N(choose_arena_hard)
end_define

begin_define
define|#
directive|define
name|chunk_alloc
value|JEMALLOC_N(chunk_alloc)
end_define

begin_define
define|#
directive|define
name|chunk_alloc_dss
value|JEMALLOC_N(chunk_alloc_dss)
end_define

begin_define
define|#
directive|define
name|chunk_alloc_mmap
value|JEMALLOC_N(chunk_alloc_mmap)
end_define

begin_define
define|#
directive|define
name|chunk_boot
value|JEMALLOC_N(chunk_boot)
end_define

begin_define
define|#
directive|define
name|chunk_dealloc
value|JEMALLOC_N(chunk_dealloc)
end_define

begin_define
define|#
directive|define
name|chunk_dealloc_mmap
value|JEMALLOC_N(chunk_dealloc_mmap)
end_define

begin_define
define|#
directive|define
name|chunk_dss_boot
value|JEMALLOC_N(chunk_dss_boot)
end_define

begin_define
define|#
directive|define
name|chunk_dss_postfork_child
value|JEMALLOC_N(chunk_dss_postfork_child)
end_define

begin_define
define|#
directive|define
name|chunk_dss_postfork_parent
value|JEMALLOC_N(chunk_dss_postfork_parent)
end_define

begin_define
define|#
directive|define
name|chunk_dss_prec_get
value|JEMALLOC_N(chunk_dss_prec_get)
end_define

begin_define
define|#
directive|define
name|chunk_dss_prec_set
value|JEMALLOC_N(chunk_dss_prec_set)
end_define

begin_define
define|#
directive|define
name|chunk_dss_prefork
value|JEMALLOC_N(chunk_dss_prefork)
end_define

begin_define
define|#
directive|define
name|chunk_in_dss
value|JEMALLOC_N(chunk_in_dss)
end_define

begin_define
define|#
directive|define
name|chunk_npages
value|JEMALLOC_N(chunk_npages)
end_define

begin_define
define|#
directive|define
name|chunk_postfork_child
value|JEMALLOC_N(chunk_postfork_child)
end_define

begin_define
define|#
directive|define
name|chunk_postfork_parent
value|JEMALLOC_N(chunk_postfork_parent)
end_define

begin_define
define|#
directive|define
name|chunk_prefork
value|JEMALLOC_N(chunk_prefork)
end_define

begin_define
define|#
directive|define
name|chunk_unmap
value|JEMALLOC_N(chunk_unmap)
end_define

begin_define
define|#
directive|define
name|chunks_mtx
value|JEMALLOC_N(chunks_mtx)
end_define

begin_define
define|#
directive|define
name|chunks_rtree
value|JEMALLOC_N(chunks_rtree)
end_define

begin_define
define|#
directive|define
name|chunksize
value|JEMALLOC_N(chunksize)
end_define

begin_define
define|#
directive|define
name|chunksize_mask
value|JEMALLOC_N(chunksize_mask)
end_define

begin_define
define|#
directive|define
name|ckh_bucket_search
value|JEMALLOC_N(ckh_bucket_search)
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
name|ckh_evict_reloc_insert
value|JEMALLOC_N(ckh_evict_reloc_insert)
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
name|ckh_isearch
value|JEMALLOC_N(ckh_isearch)
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
name|ckh_rebuild
value|JEMALLOC_N(ckh_rebuild)
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
name|ckh_try_bucket_insert
value|JEMALLOC_N(ckh_try_bucket_insert)
end_define

begin_define
define|#
directive|define
name|ckh_try_insert
value|JEMALLOC_N(ckh_try_insert)
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
name|dss_prec_names
value|JEMALLOC_N(dss_prec_names)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_first
value|JEMALLOC_N(extent_tree_ad_first)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_insert
value|JEMALLOC_N(extent_tree_ad_insert)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_iter
value|JEMALLOC_N(extent_tree_ad_iter)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_iter_recurse
value|JEMALLOC_N(extent_tree_ad_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_iter_start
value|JEMALLOC_N(extent_tree_ad_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_last
value|JEMALLOC_N(extent_tree_ad_last)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_new
value|JEMALLOC_N(extent_tree_ad_new)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_next
value|JEMALLOC_N(extent_tree_ad_next)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_nsearch
value|JEMALLOC_N(extent_tree_ad_nsearch)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_prev
value|JEMALLOC_N(extent_tree_ad_prev)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_psearch
value|JEMALLOC_N(extent_tree_ad_psearch)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_remove
value|JEMALLOC_N(extent_tree_ad_remove)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_reverse_iter
value|JEMALLOC_N(extent_tree_ad_reverse_iter)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_reverse_iter_recurse
value|JEMALLOC_N(extent_tree_ad_reverse_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_reverse_iter_start
value|JEMALLOC_N(extent_tree_ad_reverse_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_search
value|JEMALLOC_N(extent_tree_ad_search)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_first
value|JEMALLOC_N(extent_tree_szad_first)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_insert
value|JEMALLOC_N(extent_tree_szad_insert)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_iter
value|JEMALLOC_N(extent_tree_szad_iter)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_iter_recurse
value|JEMALLOC_N(extent_tree_szad_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_iter_start
value|JEMALLOC_N(extent_tree_szad_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_last
value|JEMALLOC_N(extent_tree_szad_last)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_new
value|JEMALLOC_N(extent_tree_szad_new)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_next
value|JEMALLOC_N(extent_tree_szad_next)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_nsearch
value|JEMALLOC_N(extent_tree_szad_nsearch)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_prev
value|JEMALLOC_N(extent_tree_szad_prev)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_psearch
value|JEMALLOC_N(extent_tree_szad_psearch)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_remove
value|JEMALLOC_N(extent_tree_szad_remove)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_reverse_iter
value|JEMALLOC_N(extent_tree_szad_reverse_iter)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_reverse_iter_recurse
value|JEMALLOC_N(extent_tree_szad_reverse_iter_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_reverse_iter_start
value|JEMALLOC_N(extent_tree_szad_reverse_iter_start)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_search
value|JEMALLOC_N(extent_tree_szad_search)
end_define

begin_define
define|#
directive|define
name|get_errno
value|JEMALLOC_N(get_errno)
end_define

begin_define
define|#
directive|define
name|hash
value|JEMALLOC_N(hash)
end_define

begin_define
define|#
directive|define
name|hash_fmix_32
value|JEMALLOC_N(hash_fmix_32)
end_define

begin_define
define|#
directive|define
name|hash_fmix_64
value|JEMALLOC_N(hash_fmix_64)
end_define

begin_define
define|#
directive|define
name|hash_get_block_32
value|JEMALLOC_N(hash_get_block_32)
end_define

begin_define
define|#
directive|define
name|hash_get_block_64
value|JEMALLOC_N(hash_get_block_64)
end_define

begin_define
define|#
directive|define
name|hash_rotl_32
value|JEMALLOC_N(hash_rotl_32)
end_define

begin_define
define|#
directive|define
name|hash_rotl_64
value|JEMALLOC_N(hash_rotl_64)
end_define

begin_define
define|#
directive|define
name|hash_x64_128
value|JEMALLOC_N(hash_x64_128)
end_define

begin_define
define|#
directive|define
name|hash_x86_128
value|JEMALLOC_N(hash_x86_128)
end_define

begin_define
define|#
directive|define
name|hash_x86_32
value|JEMALLOC_N(hash_x86_32)
end_define

begin_define
define|#
directive|define
name|huge_allocated
value|JEMALLOC_N(huge_allocated)
end_define

begin_define
define|#
directive|define
name|huge_boot
value|JEMALLOC_N(huge_boot)
end_define

begin_define
define|#
directive|define
name|huge_dalloc
value|JEMALLOC_N(huge_dalloc)
end_define

begin_define
define|#
directive|define
name|huge_dalloc_junk
value|JEMALLOC_N(huge_dalloc_junk)
end_define

begin_define
define|#
directive|define
name|huge_dss_prec_get
value|JEMALLOC_N(huge_dss_prec_get)
end_define

begin_define
define|#
directive|define
name|huge_malloc
value|JEMALLOC_N(huge_malloc)
end_define

begin_define
define|#
directive|define
name|huge_mtx
value|JEMALLOC_N(huge_mtx)
end_define

begin_define
define|#
directive|define
name|huge_ndalloc
value|JEMALLOC_N(huge_ndalloc)
end_define

begin_define
define|#
directive|define
name|huge_nmalloc
value|JEMALLOC_N(huge_nmalloc)
end_define

begin_define
define|#
directive|define
name|huge_palloc
value|JEMALLOC_N(huge_palloc)
end_define

begin_define
define|#
directive|define
name|huge_postfork_child
value|JEMALLOC_N(huge_postfork_child)
end_define

begin_define
define|#
directive|define
name|huge_postfork_parent
value|JEMALLOC_N(huge_postfork_parent)
end_define

begin_define
define|#
directive|define
name|huge_prefork
value|JEMALLOC_N(huge_prefork)
end_define

begin_define
define|#
directive|define
name|huge_prof_ctx_get
value|JEMALLOC_N(huge_prof_ctx_get)
end_define

begin_define
define|#
directive|define
name|huge_prof_ctx_set
value|JEMALLOC_N(huge_prof_ctx_set)
end_define

begin_define
define|#
directive|define
name|huge_ralloc
value|JEMALLOC_N(huge_ralloc)
end_define

begin_define
define|#
directive|define
name|huge_ralloc_no_move
value|JEMALLOC_N(huge_ralloc_no_move)
end_define

begin_define
define|#
directive|define
name|huge_salloc
value|JEMALLOC_N(huge_salloc)
end_define

begin_define
define|#
directive|define
name|iallocm
value|JEMALLOC_N(iallocm)
end_define

begin_define
define|#
directive|define
name|icalloc
value|JEMALLOC_N(icalloc)
end_define

begin_define
define|#
directive|define
name|icalloct
value|JEMALLOC_N(icalloct)
end_define

begin_define
define|#
directive|define
name|idalloc
value|JEMALLOC_N(idalloc)
end_define

begin_define
define|#
directive|define
name|idalloct
value|JEMALLOC_N(idalloct)
end_define

begin_define
define|#
directive|define
name|imalloc
value|JEMALLOC_N(imalloc)
end_define

begin_define
define|#
directive|define
name|imalloct
value|JEMALLOC_N(imalloct)
end_define

begin_define
define|#
directive|define
name|ipalloc
value|JEMALLOC_N(ipalloc)
end_define

begin_define
define|#
directive|define
name|ipalloct
value|JEMALLOC_N(ipalloct)
end_define

begin_define
define|#
directive|define
name|iqalloc
value|JEMALLOC_N(iqalloc)
end_define

begin_define
define|#
directive|define
name|iqalloct
value|JEMALLOC_N(iqalloct)
end_define

begin_define
define|#
directive|define
name|iralloc
value|JEMALLOC_N(iralloc)
end_define

begin_define
define|#
directive|define
name|iralloct
value|JEMALLOC_N(iralloct)
end_define

begin_define
define|#
directive|define
name|iralloct_realign
value|JEMALLOC_N(iralloct_realign)
end_define

begin_define
define|#
directive|define
name|isalloc
value|JEMALLOC_N(isalloc)
end_define

begin_define
define|#
directive|define
name|ivsalloc
value|JEMALLOC_N(ivsalloc)
end_define

begin_define
define|#
directive|define
name|ixalloc
value|JEMALLOC_N(ixalloc)
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
name|jemalloc_postfork_parent
value|JEMALLOC_N(jemalloc_postfork_parent)
end_define

begin_define
define|#
directive|define
name|jemalloc_prefork
value|JEMALLOC_N(jemalloc_prefork)
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
name|malloc_mutex_init
value|JEMALLOC_N(malloc_mutex_init)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_lock
value|JEMALLOC_N(malloc_mutex_lock)
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
name|malloc_mutex_unlock
value|JEMALLOC_N(malloc_mutex_unlock)
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
name|malloc_tsd_boot
value|JEMALLOC_N(malloc_tsd_boot)
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
name|malloc_tsd_no_cleanup
value|JEMALLOC_N(malloc_tsd_no_cleanup)
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
name|map_bias
value|JEMALLOC_N(map_bias)
end_define

begin_define
define|#
directive|define
name|mb_write
value|JEMALLOC_N(mb_write)
end_define

begin_define
define|#
directive|define
name|mutex_boot
value|JEMALLOC_N(mutex_boot)
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
name|narenas_total
value|JEMALLOC_N(narenas_total)
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
name|nhbins
value|JEMALLOC_N(nhbins)
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
name|opt_dss
value|JEMALLOC_N(opt_dss)
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
name|opt_lg_chunk
value|JEMALLOC_N(opt_lg_chunk)
end_define

begin_define
define|#
directive|define
name|opt_lg_dirty_mult
value|JEMALLOC_N(opt_lg_dirty_mult)
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
name|opt_lg_tcache_max
value|JEMALLOC_N(opt_lg_tcache_max)
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
name|opt_quarantine
value|JEMALLOC_N(opt_quarantine)
end_define

begin_define
define|#
directive|define
name|opt_redzone
value|JEMALLOC_N(opt_redzone)
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
name|opt_tcache
value|JEMALLOC_N(opt_tcache)
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
name|opt_valgrind
value|JEMALLOC_N(opt_valgrind)
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
name|p2rz
value|JEMALLOC_N(p2rz)
end_define

begin_define
define|#
directive|define
name|pages_purge
value|JEMALLOC_N(pages_purge)
end_define

begin_define
define|#
directive|define
name|pow2_ceil
value|JEMALLOC_N(pow2_ceil)
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
name|prof_bt_count
value|JEMALLOC_N(prof_bt_count)
end_define

begin_define
define|#
directive|define
name|prof_ctx_get
value|JEMALLOC_N(prof_ctx_get)
end_define

begin_define
define|#
directive|define
name|prof_ctx_set
value|JEMALLOC_N(prof_ctx_set)
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
name|prof_free
value|JEMALLOC_N(prof_free)
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
name|prof_malloc
value|JEMALLOC_N(prof_malloc)
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
name|prof_prefork
value|JEMALLOC_N(prof_prefork)
end_define

begin_define
define|#
directive|define
name|prof_promote
value|JEMALLOC_N(prof_promote)
end_define

begin_define
define|#
directive|define
name|prof_realloc
value|JEMALLOC_N(prof_realloc)
end_define

begin_define
define|#
directive|define
name|prof_sample_accum_update
value|JEMALLOC_N(prof_sample_accum_update)
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
name|prof_tdata_booted
value|JEMALLOC_N(prof_tdata_booted)
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
name|prof_tdata_get
value|JEMALLOC_N(prof_tdata_get)
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
name|prof_tdata_initialized
value|JEMALLOC_N(prof_tdata_initialized)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tls
value|JEMALLOC_N(prof_tdata_tls)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd
value|JEMALLOC_N(prof_tdata_tsd)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_boot
value|JEMALLOC_N(prof_tdata_tsd_boot)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_cleanup_wrapper
value|JEMALLOC_N(prof_tdata_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_get
value|JEMALLOC_N(prof_tdata_tsd_get)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_get_wrapper
value|JEMALLOC_N(prof_tdata_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_init_head
value|JEMALLOC_N(prof_tdata_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|prof_tdata_tsd_set
value|JEMALLOC_N(prof_tdata_tsd_set)
end_define

begin_define
define|#
directive|define
name|quarantine
value|JEMALLOC_N(quarantine)
end_define

begin_define
define|#
directive|define
name|quarantine_alloc_hook
value|JEMALLOC_N(quarantine_alloc_hook)
end_define

begin_define
define|#
directive|define
name|quarantine_boot
value|JEMALLOC_N(quarantine_boot)
end_define

begin_define
define|#
directive|define
name|quarantine_booted
value|JEMALLOC_N(quarantine_booted)
end_define

begin_define
define|#
directive|define
name|quarantine_cleanup
value|JEMALLOC_N(quarantine_cleanup)
end_define

begin_define
define|#
directive|define
name|quarantine_init
value|JEMALLOC_N(quarantine_init)
end_define

begin_define
define|#
directive|define
name|quarantine_tls
value|JEMALLOC_N(quarantine_tls)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd
value|JEMALLOC_N(quarantine_tsd)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_boot
value|JEMALLOC_N(quarantine_tsd_boot)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_cleanup_wrapper
value|JEMALLOC_N(quarantine_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_get
value|JEMALLOC_N(quarantine_tsd_get)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_get_wrapper
value|JEMALLOC_N(quarantine_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_init_head
value|JEMALLOC_N(quarantine_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|quarantine_tsd_set
value|JEMALLOC_N(quarantine_tsd_set)
end_define

begin_define
define|#
directive|define
name|register_zone
value|JEMALLOC_N(register_zone)
end_define

begin_define
define|#
directive|define
name|rtree_delete
value|JEMALLOC_N(rtree_delete)
end_define

begin_define
define|#
directive|define
name|rtree_get
value|JEMALLOC_N(rtree_get)
end_define

begin_define
define|#
directive|define
name|rtree_get_locked
value|JEMALLOC_N(rtree_get_locked)
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
name|rtree_postfork_child
value|JEMALLOC_N(rtree_postfork_child)
end_define

begin_define
define|#
directive|define
name|rtree_postfork_parent
value|JEMALLOC_N(rtree_postfork_parent)
end_define

begin_define
define|#
directive|define
name|rtree_prefork
value|JEMALLOC_N(rtree_prefork)
end_define

begin_define
define|#
directive|define
name|rtree_set
value|JEMALLOC_N(rtree_set)
end_define

begin_define
define|#
directive|define
name|s2u
value|JEMALLOC_N(s2u)
end_define

begin_define
define|#
directive|define
name|sa2u
value|JEMALLOC_N(sa2u)
end_define

begin_define
define|#
directive|define
name|set_errno
value|JEMALLOC_N(set_errno)
end_define

begin_define
define|#
directive|define
name|small_size2bin
value|JEMALLOC_N(small_size2bin)
end_define

begin_define
define|#
directive|define
name|stats_cactive
value|JEMALLOC_N(stats_cactive)
end_define

begin_define
define|#
directive|define
name|stats_cactive_add
value|JEMALLOC_N(stats_cactive_add)
end_define

begin_define
define|#
directive|define
name|stats_cactive_get
value|JEMALLOC_N(stats_cactive_get)
end_define

begin_define
define|#
directive|define
name|stats_cactive_sub
value|JEMALLOC_N(stats_cactive_sub)
end_define

begin_define
define|#
directive|define
name|stats_chunks
value|JEMALLOC_N(stats_chunks)
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
name|tcache_alloc_easy
value|JEMALLOC_N(tcache_alloc_easy)
end_define

begin_define
define|#
directive|define
name|tcache_alloc_large
value|JEMALLOC_N(tcache_alloc_large)
end_define

begin_define
define|#
directive|define
name|tcache_alloc_small
value|JEMALLOC_N(tcache_alloc_small)
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
name|tcache_arena_dissociate
value|JEMALLOC_N(tcache_arena_dissociate)
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
name|tcache_boot0
value|JEMALLOC_N(tcache_boot0)
end_define

begin_define
define|#
directive|define
name|tcache_boot1
value|JEMALLOC_N(tcache_boot1)
end_define

begin_define
define|#
directive|define
name|tcache_booted
value|JEMALLOC_N(tcache_booted)
end_define

begin_define
define|#
directive|define
name|tcache_create
value|JEMALLOC_N(tcache_create)
end_define

begin_define
define|#
directive|define
name|tcache_dalloc_large
value|JEMALLOC_N(tcache_dalloc_large)
end_define

begin_define
define|#
directive|define
name|tcache_dalloc_small
value|JEMALLOC_N(tcache_dalloc_small)
end_define

begin_define
define|#
directive|define
name|tcache_destroy
value|JEMALLOC_N(tcache_destroy)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_booted
value|JEMALLOC_N(tcache_enabled_booted)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_get
value|JEMALLOC_N(tcache_enabled_get)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_initialized
value|JEMALLOC_N(tcache_enabled_initialized)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_set
value|JEMALLOC_N(tcache_enabled_set)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tls
value|JEMALLOC_N(tcache_enabled_tls)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd
value|JEMALLOC_N(tcache_enabled_tsd)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_boot
value|JEMALLOC_N(tcache_enabled_tsd_boot)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_cleanup_wrapper
value|JEMALLOC_N(tcache_enabled_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_get
value|JEMALLOC_N(tcache_enabled_tsd_get)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_get_wrapper
value|JEMALLOC_N(tcache_enabled_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_init_head
value|JEMALLOC_N(tcache_enabled_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|tcache_enabled_tsd_set
value|JEMALLOC_N(tcache_enabled_tsd_set)
end_define

begin_define
define|#
directive|define
name|tcache_event
value|JEMALLOC_N(tcache_event)
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
name|tcache_get
value|JEMALLOC_N(tcache_get)
end_define

begin_define
define|#
directive|define
name|tcache_initialized
value|JEMALLOC_N(tcache_initialized)
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
name|tcache_thread_cleanup
value|JEMALLOC_N(tcache_thread_cleanup)
end_define

begin_define
define|#
directive|define
name|tcache_tls
value|JEMALLOC_N(tcache_tls)
end_define

begin_define
define|#
directive|define
name|tcache_tsd
value|JEMALLOC_N(tcache_tsd)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_boot
value|JEMALLOC_N(tcache_tsd_boot)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_cleanup_wrapper
value|JEMALLOC_N(tcache_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_get
value|JEMALLOC_N(tcache_tsd_get)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_get_wrapper
value|JEMALLOC_N(tcache_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_init_head
value|JEMALLOC_N(tcache_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|tcache_tsd_set
value|JEMALLOC_N(tcache_tsd_set)
end_define

begin_define
define|#
directive|define
name|thread_allocated_booted
value|JEMALLOC_N(thread_allocated_booted)
end_define

begin_define
define|#
directive|define
name|thread_allocated_initialized
value|JEMALLOC_N(thread_allocated_initialized)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tls
value|JEMALLOC_N(thread_allocated_tls)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd
value|JEMALLOC_N(thread_allocated_tsd)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_boot
value|JEMALLOC_N(thread_allocated_tsd_boot)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_cleanup_wrapper
value|JEMALLOC_N(thread_allocated_tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_get
value|JEMALLOC_N(thread_allocated_tsd_get)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_get_wrapper
value|JEMALLOC_N(thread_allocated_tsd_get_wrapper)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_init_head
value|JEMALLOC_N(thread_allocated_tsd_init_head)
end_define

begin_define
define|#
directive|define
name|thread_allocated_tsd_set
value|JEMALLOC_N(thread_allocated_tsd_set)
end_define

begin_define
define|#
directive|define
name|tsd_init_check_recursion
value|JEMALLOC_N(tsd_init_check_recursion)
end_define

begin_define
define|#
directive|define
name|tsd_init_finish
value|JEMALLOC_N(tsd_init_finish)
end_define

begin_define
define|#
directive|define
name|u2rz
value|JEMALLOC_N(u2rz)
end_define

end_unit

