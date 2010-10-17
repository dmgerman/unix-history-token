begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|cg_arcs_h
end_ifndef

begin_define
define|#
directive|define
name|cg_arcs_h
end_define

begin_comment
comment|/*  * Arc structure for call-graph.  *  * With pointers to the symbols of the parent and the child, a count  * of how many times this arc was traversed, and pointers to the next  * parent of this child and the next child of this parent.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|arc
block|{
name|Sym
modifier|*
name|parent
decl_stmt|;
comment|/* source vertice of arc */
name|Sym
modifier|*
name|child
decl_stmt|;
comment|/* dest vertice of arc */
name|unsigned
name|long
name|count
decl_stmt|;
comment|/* # of calls from parent to child */
name|double
name|time
decl_stmt|;
comment|/* time inherited along arc */
name|double
name|child_time
decl_stmt|;
comment|/* child-time inherited along arc */
name|struct
name|arc
modifier|*
name|next_parent
decl_stmt|;
comment|/* next parent of CHILD */
name|struct
name|arc
modifier|*
name|next_child
decl_stmt|;
comment|/* next child of PARENT */
name|int
name|has_been_placed
decl_stmt|;
comment|/* have this arc's functions been placed? */
block|}
name|Arc
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|num_cycles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of cycles discovered */
end_comment

begin_decl_stmt
specifier|extern
name|Sym
modifier|*
name|cycle_header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cycle headers */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|arc_add
name|PARAMS
argument_list|(
operator|(
name|Sym
operator|*
name|parent
operator|,
name|Sym
operator|*
name|child
operator|,
name|unsigned
name|long
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Arc
modifier|*
name|arc_lookup
name|PARAMS
argument_list|(
operator|(
name|Sym
operator|*
name|parent
operator|,
name|Sym
operator|*
name|child
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Sym
modifier|*
modifier|*
name|cg_assemble
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Arc
modifier|*
modifier|*
name|arcs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|numarcs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cg_arcs_h */
end_comment

end_unit

