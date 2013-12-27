begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_TYPES
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|extent_node_s
name|extent_node_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_TYPES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_STRUCTS
end_ifdef

begin_comment
comment|/* Tree of extents. */
end_comment

begin_struct
struct|struct
name|extent_node_s
block|{
comment|/* Linkage for the size/address-ordered tree. */
name|rb_node
argument_list|(
argument|extent_node_t
argument_list|)
name|link_szad
expr_stmt|;
comment|/* Linkage for the address-ordered tree. */
name|rb_node
argument_list|(
argument|extent_node_t
argument_list|)
name|link_ad
expr_stmt|;
comment|/* Profile counters, used for huge objects. */
name|prof_ctx_t
modifier|*
name|prof_ctx
decl_stmt|;
comment|/* Pointer to the extent that this tree node is responsible for. */
name|void
modifier|*
name|addr
decl_stmt|;
comment|/* Total region size. */
name|size_t
name|size
decl_stmt|;
comment|/* True if zero-filled; used by chunk recycling code. */
name|bool
name|zeroed
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|rb_tree
argument_list|(
argument|extent_node_t
argument_list|)
name|extent_tree_t
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_STRUCTS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_EXTERNS
end_ifdef

begin_macro
name|rb_proto
argument_list|(
argument_list|,
argument|extent_tree_szad_
argument_list|,
argument|extent_tree_t
argument_list|,
argument|extent_node_t
argument_list|)
end_macro

begin_macro
name|rb_proto
argument_list|(
argument_list|,
argument|extent_tree_ad_
argument_list|,
argument|extent_tree_t
argument_list|,
argument|extent_node_t
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_EXTERNS */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|JEMALLOC_H_INLINES
end_ifdef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_H_INLINES */
end_comment

begin_comment
comment|/******************************************************************************/
end_comment

end_unit

