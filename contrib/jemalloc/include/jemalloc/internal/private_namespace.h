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
name|arena_aalloc
value|JEMALLOC_N(arena_aalloc)
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
name|arena_bitselm_get_const
value|JEMALLOC_N(arena_bitselm_get_const)
end_define

begin_define
define|#
directive|define
name|arena_bitselm_get_mutable
value|JEMALLOC_N(arena_bitselm_get_mutable)
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
name|arena_choose
value|JEMALLOC_N(arena_choose)
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
name|arena_choose_impl
value|JEMALLOC_N(arena_choose_impl)
end_define

begin_define
define|#
directive|define
name|arena_chunk_alloc_huge
value|JEMALLOC_N(arena_chunk_alloc_huge)
end_define

begin_define
define|#
directive|define
name|arena_chunk_cache_maybe_insert
value|JEMALLOC_N(arena_chunk_cache_maybe_insert)
end_define

begin_define
define|#
directive|define
name|arena_chunk_cache_maybe_remove
value|JEMALLOC_N(arena_chunk_cache_maybe_remove)
end_define

begin_define
define|#
directive|define
name|arena_chunk_dalloc_huge
value|JEMALLOC_N(arena_chunk_dalloc_huge)
end_define

begin_define
define|#
directive|define
name|arena_chunk_ralloc_huge_expand
value|JEMALLOC_N(arena_chunk_ralloc_huge_expand)
end_define

begin_define
define|#
directive|define
name|arena_chunk_ralloc_huge_shrink
value|JEMALLOC_N(arena_chunk_ralloc_huge_shrink)
end_define

begin_define
define|#
directive|define
name|arena_chunk_ralloc_huge_similar
value|JEMALLOC_N(arena_chunk_ralloc_huge_similar)
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
name|arena_dalloc_bin_junked_locked
value|JEMALLOC_N(arena_dalloc_bin_junked_locked)
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
name|arena_dalloc_large_junked_locked
value|JEMALLOC_N(arena_dalloc_large_junked_locked)
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
name|arena_decay_tick
value|JEMALLOC_N(arena_decay_tick)
end_define

begin_define
define|#
directive|define
name|arena_decay_ticks
value|JEMALLOC_N(arena_decay_ticks)
end_define

begin_define
define|#
directive|define
name|arena_decay_time_default_get
value|JEMALLOC_N(arena_decay_time_default_get)
end_define

begin_define
define|#
directive|define
name|arena_decay_time_default_set
value|JEMALLOC_N(arena_decay_time_default_set)
end_define

begin_define
define|#
directive|define
name|arena_decay_time_get
value|JEMALLOC_N(arena_decay_time_get)
end_define

begin_define
define|#
directive|define
name|arena_decay_time_set
value|JEMALLOC_N(arena_decay_time_set)
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
name|arena_get
value|JEMALLOC_N(arena_get)
end_define

begin_define
define|#
directive|define
name|arena_ichoose
value|JEMALLOC_N(arena_ichoose)
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
name|arena_lg_dirty_mult_default_get
value|JEMALLOC_N(arena_lg_dirty_mult_default_get)
end_define

begin_define
define|#
directive|define
name|arena_lg_dirty_mult_default_set
value|JEMALLOC_N(arena_lg_dirty_mult_default_set)
end_define

begin_define
define|#
directive|define
name|arena_lg_dirty_mult_get
value|JEMALLOC_N(arena_lg_dirty_mult_get)
end_define

begin_define
define|#
directive|define
name|arena_lg_dirty_mult_set
value|JEMALLOC_N(arena_lg_dirty_mult_set)
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
name|arena_malloc_hard
value|JEMALLOC_N(arena_malloc_hard)
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
name|arena_mapbits_decommitted_get
value|JEMALLOC_N(arena_mapbits_decommitted_get)
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
name|arena_mapbits_internal_set
value|JEMALLOC_N(arena_mapbits_internal_set)
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
name|arena_mapbits_size_decode
value|JEMALLOC_N(arena_mapbits_size_decode)
end_define

begin_define
define|#
directive|define
name|arena_mapbits_size_encode
value|JEMALLOC_N(arena_mapbits_size_encode)
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
name|arena_mapbitsp_get_const
value|JEMALLOC_N(arena_mapbitsp_get_const)
end_define

begin_define
define|#
directive|define
name|arena_mapbitsp_get_mutable
value|JEMALLOC_N(arena_mapbitsp_get_mutable)
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
name|arena_maxrun
value|JEMALLOC_N(arena_maxrun)
end_define

begin_define
define|#
directive|define
name|arena_maybe_purge
value|JEMALLOC_N(arena_maybe_purge)
end_define

begin_define
define|#
directive|define
name|arena_metadata_allocated_add
value|JEMALLOC_N(arena_metadata_allocated_add)
end_define

begin_define
define|#
directive|define
name|arena_metadata_allocated_get
value|JEMALLOC_N(arena_metadata_allocated_get)
end_define

begin_define
define|#
directive|define
name|arena_metadata_allocated_sub
value|JEMALLOC_N(arena_metadata_allocated_sub)
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
name|arena_miscelm_get_const
value|JEMALLOC_N(arena_miscelm_get_const)
end_define

begin_define
define|#
directive|define
name|arena_miscelm_get_mutable
value|JEMALLOC_N(arena_miscelm_get_mutable)
end_define

begin_define
define|#
directive|define
name|arena_miscelm_to_pageind
value|JEMALLOC_N(arena_miscelm_to_pageind)
end_define

begin_define
define|#
directive|define
name|arena_miscelm_to_rpages
value|JEMALLOC_N(arena_miscelm_to_rpages)
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
name|arena_node_alloc
value|JEMALLOC_N(arena_node_alloc)
end_define

begin_define
define|#
directive|define
name|arena_node_dalloc
value|JEMALLOC_N(arena_node_dalloc)
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
name|arena_prof_promoted
value|JEMALLOC_N(arena_prof_promoted)
end_define

begin_define
define|#
directive|define
name|arena_prof_tctx_get
value|JEMALLOC_N(arena_prof_tctx_get)
end_define

begin_define
define|#
directive|define
name|arena_prof_tctx_reset
value|JEMALLOC_N(arena_prof_tctx_reset)
end_define

begin_define
define|#
directive|define
name|arena_prof_tctx_set
value|JEMALLOC_N(arena_prof_tctx_set)
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
name|arena_purge
value|JEMALLOC_N(arena_purge)
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
name|arena_rd_to_miscelm
value|JEMALLOC_N(arena_rd_to_miscelm)
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
name|arena_reset
value|JEMALLOC_N(arena_reset)
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
name|arena_run_to_miscelm
value|JEMALLOC_N(arena_run_to_miscelm)
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
name|arena_sdalloc
value|JEMALLOC_N(arena_sdalloc)
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
name|arena_tdata_get
value|JEMALLOC_N(arena_tdata_get)
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
name|arenas_tdata_bypass_cleanup
value|JEMALLOC_N(arenas_tdata_bypass_cleanup)
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
name|atomic_add_p
value|JEMALLOC_N(atomic_add_p)
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
name|atomic_cas_p
value|JEMALLOC_N(atomic_cas_p)
end_define

begin_define
define|#
directive|define
name|atomic_cas_u
value|JEMALLOC_N(atomic_cas_u)
end_define

begin_define
define|#
directive|define
name|atomic_cas_uint32
value|JEMALLOC_N(atomic_cas_uint32)
end_define

begin_define
define|#
directive|define
name|atomic_cas_uint64
value|JEMALLOC_N(atomic_cas_uint64)
end_define

begin_define
define|#
directive|define
name|atomic_cas_z
value|JEMALLOC_N(atomic_cas_z)
end_define

begin_define
define|#
directive|define
name|atomic_sub_p
value|JEMALLOC_N(atomic_sub_p)
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
name|atomic_write_p
value|JEMALLOC_N(atomic_write_p)
end_define

begin_define
define|#
directive|define
name|atomic_write_u
value|JEMALLOC_N(atomic_write_u)
end_define

begin_define
define|#
directive|define
name|atomic_write_uint32
value|JEMALLOC_N(atomic_write_uint32)
end_define

begin_define
define|#
directive|define
name|atomic_write_uint64
value|JEMALLOC_N(atomic_write_uint64)
end_define

begin_define
define|#
directive|define
name|atomic_write_z
value|JEMALLOC_N(atomic_write_z)
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
name|chunk_alloc_base
value|JEMALLOC_N(chunk_alloc_base)
end_define

begin_define
define|#
directive|define
name|chunk_alloc_cache
value|JEMALLOC_N(chunk_alloc_cache)
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
name|chunk_alloc_wrapper
value|JEMALLOC_N(chunk_alloc_wrapper)
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
name|chunk_dalloc_cache
value|JEMALLOC_N(chunk_dalloc_cache)
end_define

begin_define
define|#
directive|define
name|chunk_dalloc_mmap
value|JEMALLOC_N(chunk_dalloc_mmap)
end_define

begin_define
define|#
directive|define
name|chunk_dalloc_wrapper
value|JEMALLOC_N(chunk_dalloc_wrapper)
end_define

begin_define
define|#
directive|define
name|chunk_deregister
value|JEMALLOC_N(chunk_deregister)
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
name|chunk_hooks_default
value|JEMALLOC_N(chunk_hooks_default)
end_define

begin_define
define|#
directive|define
name|chunk_hooks_get
value|JEMALLOC_N(chunk_hooks_get)
end_define

begin_define
define|#
directive|define
name|chunk_hooks_set
value|JEMALLOC_N(chunk_hooks_set)
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
name|chunk_lookup
value|JEMALLOC_N(chunk_lookup)
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
name|chunk_purge_wrapper
value|JEMALLOC_N(chunk_purge_wrapper)
end_define

begin_define
define|#
directive|define
name|chunk_register
value|JEMALLOC_N(chunk_register)
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
name|decay_ticker_get
value|JEMALLOC_N(decay_ticker_get)
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
name|extent_node_achunk_get
value|JEMALLOC_N(extent_node_achunk_get)
end_define

begin_define
define|#
directive|define
name|extent_node_achunk_set
value|JEMALLOC_N(extent_node_achunk_set)
end_define

begin_define
define|#
directive|define
name|extent_node_addr_get
value|JEMALLOC_N(extent_node_addr_get)
end_define

begin_define
define|#
directive|define
name|extent_node_addr_set
value|JEMALLOC_N(extent_node_addr_set)
end_define

begin_define
define|#
directive|define
name|extent_node_arena_get
value|JEMALLOC_N(extent_node_arena_get)
end_define

begin_define
define|#
directive|define
name|extent_node_arena_set
value|JEMALLOC_N(extent_node_arena_set)
end_define

begin_define
define|#
directive|define
name|extent_node_committed_get
value|JEMALLOC_N(extent_node_committed_get)
end_define

begin_define
define|#
directive|define
name|extent_node_committed_set
value|JEMALLOC_N(extent_node_committed_set)
end_define

begin_define
define|#
directive|define
name|extent_node_dirty_insert
value|JEMALLOC_N(extent_node_dirty_insert)
end_define

begin_define
define|#
directive|define
name|extent_node_dirty_linkage_init
value|JEMALLOC_N(extent_node_dirty_linkage_init)
end_define

begin_define
define|#
directive|define
name|extent_node_dirty_remove
value|JEMALLOC_N(extent_node_dirty_remove)
end_define

begin_define
define|#
directive|define
name|extent_node_init
value|JEMALLOC_N(extent_node_init)
end_define

begin_define
define|#
directive|define
name|extent_node_prof_tctx_get
value|JEMALLOC_N(extent_node_prof_tctx_get)
end_define

begin_define
define|#
directive|define
name|extent_node_prof_tctx_set
value|JEMALLOC_N(extent_node_prof_tctx_set)
end_define

begin_define
define|#
directive|define
name|extent_node_size_get
value|JEMALLOC_N(extent_node_size_get)
end_define

begin_define
define|#
directive|define
name|extent_node_size_set
value|JEMALLOC_N(extent_node_size_set)
end_define

begin_define
define|#
directive|define
name|extent_node_zeroed_get
value|JEMALLOC_N(extent_node_zeroed_get)
end_define

begin_define
define|#
directive|define
name|extent_node_zeroed_set
value|JEMALLOC_N(extent_node_zeroed_set)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_destroy
value|JEMALLOC_N(extent_tree_ad_destroy)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_destroy_recurse
value|JEMALLOC_N(extent_tree_ad_destroy_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_ad_empty
value|JEMALLOC_N(extent_tree_ad_empty)
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
name|extent_tree_szad_destroy
value|JEMALLOC_N(extent_tree_szad_destroy)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_destroy_recurse
value|JEMALLOC_N(extent_tree_szad_destroy_recurse)
end_define

begin_define
define|#
directive|define
name|extent_tree_szad_empty
value|JEMALLOC_N(extent_tree_szad_empty)
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
name|ffs_llu
value|JEMALLOC_N(ffs_llu)
end_define

begin_define
define|#
directive|define
name|ffs_lu
value|JEMALLOC_N(ffs_lu)
end_define

begin_define
define|#
directive|define
name|ffs_u
value|JEMALLOC_N(ffs_u)
end_define

begin_define
define|#
directive|define
name|ffs_u32
value|JEMALLOC_N(ffs_u32)
end_define

begin_define
define|#
directive|define
name|ffs_u64
value|JEMALLOC_N(ffs_u64)
end_define

begin_define
define|#
directive|define
name|ffs_zu
value|JEMALLOC_N(ffs_zu)
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
name|huge_aalloc
value|JEMALLOC_N(huge_aalloc)
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
name|huge_malloc
value|JEMALLOC_N(huge_malloc)
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
name|huge_prof_tctx_get
value|JEMALLOC_N(huge_prof_tctx_get)
end_define

begin_define
define|#
directive|define
name|huge_prof_tctx_reset
value|JEMALLOC_N(huge_prof_tctx_reset)
end_define

begin_define
define|#
directive|define
name|huge_prof_tctx_set
value|JEMALLOC_N(huge_prof_tctx_set)
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
name|iaalloc
value|JEMALLOC_N(iaalloc)
end_define

begin_define
define|#
directive|define
name|ialloc
value|JEMALLOC_N(ialloc)
end_define

begin_define
define|#
directive|define
name|iallocztm
value|JEMALLOC_N(iallocztm)
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
name|idalloc
value|JEMALLOC_N(idalloc)
end_define

begin_define
define|#
directive|define
name|idalloctm
value|JEMALLOC_N(idalloctm)
end_define

begin_define
define|#
directive|define
name|in_valgrind
value|JEMALLOC_N(in_valgrind)
end_define

begin_define
define|#
directive|define
name|index2size
value|JEMALLOC_N(index2size)
end_define

begin_define
define|#
directive|define
name|index2size_compute
value|JEMALLOC_N(index2size_compute)
end_define

begin_define
define|#
directive|define
name|index2size_lookup
value|JEMALLOC_N(index2size_lookup)
end_define

begin_define
define|#
directive|define
name|index2size_tab
value|JEMALLOC_N(index2size_tab)
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
name|ipallocztm
value|JEMALLOC_N(ipallocztm)
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
name|isdalloct
value|JEMALLOC_N(isdalloct)
end_define

begin_define
define|#
directive|define
name|isqalloc
value|JEMALLOC_N(isqalloc)
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
name|large_maxclass
value|JEMALLOC_N(large_maxclass)
end_define

begin_define
define|#
directive|define
name|lg_floor
value|JEMALLOC_N(lg_floor)
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
name|malloc_cprintf
value|JEMALLOC_N(malloc_cprintf)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_assert_not_owner
value|JEMALLOC_N(malloc_mutex_assert_not_owner)
end_define

begin_define
define|#
directive|define
name|malloc_mutex_assert_owner
value|JEMALLOC_N(malloc_mutex_assert_owner)
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
name|map_misc_offset
value|JEMALLOC_N(map_misc_offset)
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
name|narenas_auto
value|JEMALLOC_N(narenas_auto)
end_define

begin_define
define|#
directive|define
name|narenas_tdata_cleanup
value|JEMALLOC_N(narenas_tdata_cleanup)
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
name|nhclasses
value|JEMALLOC_N(nhclasses)
end_define

begin_define
define|#
directive|define
name|nlclasses
value|JEMALLOC_N(nlclasses)
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
name|opt_abort
value|JEMALLOC_N(opt_abort)
end_define

begin_define
define|#
directive|define
name|opt_decay_time
value|JEMALLOC_N(opt_decay_time)
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
name|opt_prof_thread_active_init
value|JEMALLOC_N(opt_prof_thread_active_init)
end_define

begin_define
define|#
directive|define
name|opt_purge
value|JEMALLOC_N(opt_purge)
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
name|pages_map
value|JEMALLOC_N(pages_map)
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
name|pages_trim
value|JEMALLOC_N(pages_trim)
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
name|pow2_ceil_u32
value|JEMALLOC_N(pow2_ceil_u32)
end_define

begin_define
define|#
directive|define
name|pow2_ceil_u64
value|JEMALLOC_N(pow2_ceil_u64)
end_define

begin_define
define|#
directive|define
name|pow2_ceil_zu
value|JEMALLOC_N(pow2_ceil_zu)
end_define

begin_define
define|#
directive|define
name|prng_lg_range
value|JEMALLOC_N(prng_lg_range)
end_define

begin_define
define|#
directive|define
name|prng_range
value|JEMALLOC_N(prng_range)
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
name|prof_active_get_unlocked
value|JEMALLOC_N(prof_active_get_unlocked)
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
name|prof_alloc_prep
value|JEMALLOC_N(prof_alloc_prep)
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
name|prof_bt_count
value|JEMALLOC_N(prof_bt_count)
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
name|prof_free
value|JEMALLOC_N(prof_free)
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
name|prof_gdump_get_unlocked
value|JEMALLOC_N(prof_gdump_get_unlocked)
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
name|prof_malloc
value|JEMALLOC_N(prof_malloc)
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
name|prof_realloc
value|JEMALLOC_N(prof_realloc)
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
name|prof_tctx_get
value|JEMALLOC_N(prof_tctx_get)
end_define

begin_define
define|#
directive|define
name|prof_tctx_reset
value|JEMALLOC_N(prof_tctx_reset)
end_define

begin_define
define|#
directive|define
name|prof_tctx_set
value|JEMALLOC_N(prof_tctx_set)
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
name|prof_tdata_count
value|JEMALLOC_N(prof_tdata_count)
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
name|purge_mode_names
value|JEMALLOC_N(purge_mode_names)
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
name|quarantine_alloc_hook_work
value|JEMALLOC_N(quarantine_alloc_hook_work)
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
name|register_zone
value|JEMALLOC_N(register_zone)
end_define

begin_define
define|#
directive|define
name|rtree_child_read
value|JEMALLOC_N(rtree_child_read)
end_define

begin_define
define|#
directive|define
name|rtree_child_read_hard
value|JEMALLOC_N(rtree_child_read_hard)
end_define

begin_define
define|#
directive|define
name|rtree_child_tryread
value|JEMALLOC_N(rtree_child_tryread)
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
name|rtree_new
value|JEMALLOC_N(rtree_new)
end_define

begin_define
define|#
directive|define
name|rtree_node_valid
value|JEMALLOC_N(rtree_node_valid)
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
name|rtree_start_level
value|JEMALLOC_N(rtree_start_level)
end_define

begin_define
define|#
directive|define
name|rtree_subkey
value|JEMALLOC_N(rtree_subkey)
end_define

begin_define
define|#
directive|define
name|rtree_subtree_read
value|JEMALLOC_N(rtree_subtree_read)
end_define

begin_define
define|#
directive|define
name|rtree_subtree_read_hard
value|JEMALLOC_N(rtree_subtree_read_hard)
end_define

begin_define
define|#
directive|define
name|rtree_subtree_tryread
value|JEMALLOC_N(rtree_subtree_tryread)
end_define

begin_define
define|#
directive|define
name|rtree_val_read
value|JEMALLOC_N(rtree_val_read)
end_define

begin_define
define|#
directive|define
name|rtree_val_write
value|JEMALLOC_N(rtree_val_write)
end_define

begin_define
define|#
directive|define
name|run_quantize_ceil
value|JEMALLOC_N(run_quantize_ceil)
end_define

begin_define
define|#
directive|define
name|run_quantize_floor
value|JEMALLOC_N(run_quantize_floor)
end_define

begin_define
define|#
directive|define
name|run_quantize_max
value|JEMALLOC_N(run_quantize_max)
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
name|s2u_compute
value|JEMALLOC_N(s2u_compute)
end_define

begin_define
define|#
directive|define
name|s2u_lookup
value|JEMALLOC_N(s2u_lookup)
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
name|size2index
value|JEMALLOC_N(size2index)
end_define

begin_define
define|#
directive|define
name|size2index_compute
value|JEMALLOC_N(size2index_compute)
end_define

begin_define
define|#
directive|define
name|size2index_lookup
value|JEMALLOC_N(size2index_lookup)
end_define

begin_define
define|#
directive|define
name|size2index_tab
value|JEMALLOC_N(size2index_tab)
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
name|tcache_enabled_cleanup
value|JEMALLOC_N(tcache_enabled_cleanup)
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
name|tcache_enabled_set
value|JEMALLOC_N(tcache_enabled_set)
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
name|tcache_get_hard
value|JEMALLOC_N(tcache_get_hard)
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
name|tcaches_get
value|JEMALLOC_N(tcaches_get)
end_define

begin_define
define|#
directive|define
name|thread_allocated_cleanup
value|JEMALLOC_N(thread_allocated_cleanup)
end_define

begin_define
define|#
directive|define
name|thread_deallocated_cleanup
value|JEMALLOC_N(thread_deallocated_cleanup)
end_define

begin_define
define|#
directive|define
name|ticker_copy
value|JEMALLOC_N(ticker_copy)
end_define

begin_define
define|#
directive|define
name|ticker_init
value|JEMALLOC_N(ticker_init)
end_define

begin_define
define|#
directive|define
name|ticker_read
value|JEMALLOC_N(ticker_read)
end_define

begin_define
define|#
directive|define
name|ticker_tick
value|JEMALLOC_N(ticker_tick)
end_define

begin_define
define|#
directive|define
name|ticker_ticks
value|JEMALLOC_N(ticker_ticks)
end_define

begin_define
define|#
directive|define
name|tsd_arena_get
value|JEMALLOC_N(tsd_arena_get)
end_define

begin_define
define|#
directive|define
name|tsd_arena_set
value|JEMALLOC_N(tsd_arena_set)
end_define

begin_define
define|#
directive|define
name|tsd_arenap_get
value|JEMALLOC_N(tsd_arenap_get)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdata_bypass_get
value|JEMALLOC_N(tsd_arenas_tdata_bypass_get)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdata_bypass_set
value|JEMALLOC_N(tsd_arenas_tdata_bypass_set)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdata_bypassp_get
value|JEMALLOC_N(tsd_arenas_tdata_bypassp_get)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdata_get
value|JEMALLOC_N(tsd_arenas_tdata_get)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdata_set
value|JEMALLOC_N(tsd_arenas_tdata_set)
end_define

begin_define
define|#
directive|define
name|tsd_arenas_tdatap_get
value|JEMALLOC_N(tsd_arenas_tdatap_get)
end_define

begin_define
define|#
directive|define
name|tsd_boot
value|JEMALLOC_N(tsd_boot)
end_define

begin_define
define|#
directive|define
name|tsd_boot0
value|JEMALLOC_N(tsd_boot0)
end_define

begin_define
define|#
directive|define
name|tsd_boot1
value|JEMALLOC_N(tsd_boot1)
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
name|tsd_booted_get
value|JEMALLOC_N(tsd_booted_get)
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
name|tsd_cleanup_wrapper
value|JEMALLOC_N(tsd_cleanup_wrapper)
end_define

begin_define
define|#
directive|define
name|tsd_fetch
value|JEMALLOC_N(tsd_fetch)
end_define

begin_define
define|#
directive|define
name|tsd_get
value|JEMALLOC_N(tsd_get)
end_define

begin_define
define|#
directive|define
name|tsd_iarena_get
value|JEMALLOC_N(tsd_iarena_get)
end_define

begin_define
define|#
directive|define
name|tsd_iarena_set
value|JEMALLOC_N(tsd_iarena_set)
end_define

begin_define
define|#
directive|define
name|tsd_iarenap_get
value|JEMALLOC_N(tsd_iarenap_get)
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
name|tsd_init_head
value|JEMALLOC_N(tsd_init_head)
end_define

begin_define
define|#
directive|define
name|tsd_narenas_tdata_get
value|JEMALLOC_N(tsd_narenas_tdata_get)
end_define

begin_define
define|#
directive|define
name|tsd_narenas_tdata_set
value|JEMALLOC_N(tsd_narenas_tdata_set)
end_define

begin_define
define|#
directive|define
name|tsd_narenas_tdatap_get
value|JEMALLOC_N(tsd_narenas_tdatap_get)
end_define

begin_define
define|#
directive|define
name|tsd_wrapper_get
value|JEMALLOC_N(tsd_wrapper_get)
end_define

begin_define
define|#
directive|define
name|tsd_wrapper_set
value|JEMALLOC_N(tsd_wrapper_set)
end_define

begin_define
define|#
directive|define
name|tsd_nominal
value|JEMALLOC_N(tsd_nominal)
end_define

begin_define
define|#
directive|define
name|tsd_prof_tdata_get
value|JEMALLOC_N(tsd_prof_tdata_get)
end_define

begin_define
define|#
directive|define
name|tsd_prof_tdata_set
value|JEMALLOC_N(tsd_prof_tdata_set)
end_define

begin_define
define|#
directive|define
name|tsd_prof_tdatap_get
value|JEMALLOC_N(tsd_prof_tdatap_get)
end_define

begin_define
define|#
directive|define
name|tsd_quarantine_get
value|JEMALLOC_N(tsd_quarantine_get)
end_define

begin_define
define|#
directive|define
name|tsd_quarantine_set
value|JEMALLOC_N(tsd_quarantine_set)
end_define

begin_define
define|#
directive|define
name|tsd_quarantinep_get
value|JEMALLOC_N(tsd_quarantinep_get)
end_define

begin_define
define|#
directive|define
name|tsd_set
value|JEMALLOC_N(tsd_set)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_enabled_get
value|JEMALLOC_N(tsd_tcache_enabled_get)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_enabled_set
value|JEMALLOC_N(tsd_tcache_enabled_set)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_enabledp_get
value|JEMALLOC_N(tsd_tcache_enabledp_get)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_get
value|JEMALLOC_N(tsd_tcache_get)
end_define

begin_define
define|#
directive|define
name|tsd_tcache_set
value|JEMALLOC_N(tsd_tcache_set)
end_define

begin_define
define|#
directive|define
name|tsd_tcachep_get
value|JEMALLOC_N(tsd_tcachep_get)
end_define

begin_define
define|#
directive|define
name|tsd_thread_allocated_get
value|JEMALLOC_N(tsd_thread_allocated_get)
end_define

begin_define
define|#
directive|define
name|tsd_thread_allocated_set
value|JEMALLOC_N(tsd_thread_allocated_set)
end_define

begin_define
define|#
directive|define
name|tsd_thread_allocatedp_get
value|JEMALLOC_N(tsd_thread_allocatedp_get)
end_define

begin_define
define|#
directive|define
name|tsd_thread_deallocated_get
value|JEMALLOC_N(tsd_thread_deallocated_get)
end_define

begin_define
define|#
directive|define
name|tsd_thread_deallocated_set
value|JEMALLOC_N(tsd_thread_deallocated_set)
end_define

begin_define
define|#
directive|define
name|tsd_thread_deallocatedp_get
value|JEMALLOC_N(tsd_thread_deallocatedp_get)
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
name|tsd_tsd
value|JEMALLOC_N(tsd_tsd)
end_define

begin_define
define|#
directive|define
name|tsd_tsdn
value|JEMALLOC_N(tsd_tsdn)
end_define

begin_define
define|#
directive|define
name|tsd_witness_fork_get
value|JEMALLOC_N(tsd_witness_fork_get)
end_define

begin_define
define|#
directive|define
name|tsd_witness_fork_set
value|JEMALLOC_N(tsd_witness_fork_set)
end_define

begin_define
define|#
directive|define
name|tsd_witness_forkp_get
value|JEMALLOC_N(tsd_witness_forkp_get)
end_define

begin_define
define|#
directive|define
name|tsd_witnesses_get
value|JEMALLOC_N(tsd_witnesses_get)
end_define

begin_define
define|#
directive|define
name|tsd_witnesses_set
value|JEMALLOC_N(tsd_witnesses_set)
end_define

begin_define
define|#
directive|define
name|tsd_witnessesp_get
value|JEMALLOC_N(tsd_witnessesp_get)
end_define

begin_define
define|#
directive|define
name|tsdn_fetch
value|JEMALLOC_N(tsdn_fetch)
end_define

begin_define
define|#
directive|define
name|tsdn_null
value|JEMALLOC_N(tsdn_null)
end_define

begin_define
define|#
directive|define
name|tsdn_tsd
value|JEMALLOC_N(tsdn_tsd)
end_define

begin_define
define|#
directive|define
name|u2rz
value|JEMALLOC_N(u2rz)
end_define

begin_define
define|#
directive|define
name|valgrind_freelike_block
value|JEMALLOC_N(valgrind_freelike_block)
end_define

begin_define
define|#
directive|define
name|valgrind_make_mem_defined
value|JEMALLOC_N(valgrind_make_mem_defined)
end_define

begin_define
define|#
directive|define
name|valgrind_make_mem_noaccess
value|JEMALLOC_N(valgrind_make_mem_noaccess)
end_define

begin_define
define|#
directive|define
name|valgrind_make_mem_undefined
value|JEMALLOC_N(valgrind_make_mem_undefined)
end_define

begin_define
define|#
directive|define
name|witness_assert_lockless
value|JEMALLOC_N(witness_assert_lockless)
end_define

begin_define
define|#
directive|define
name|witness_assert_not_owner
value|JEMALLOC_N(witness_assert_not_owner)
end_define

begin_define
define|#
directive|define
name|witness_assert_owner
value|JEMALLOC_N(witness_assert_owner)
end_define

begin_define
define|#
directive|define
name|witness_fork_cleanup
value|JEMALLOC_N(witness_fork_cleanup)
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
name|witness_lock
value|JEMALLOC_N(witness_lock)
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
name|witness_lockless_error
value|JEMALLOC_N(witness_lockless_error)
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
name|witness_unlock
value|JEMALLOC_N(witness_unlock)
end_define

begin_define
define|#
directive|define
name|witnesses_cleanup
value|JEMALLOC_N(witnesses_cleanup)
end_define

end_unit

