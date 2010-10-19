begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|cg_dfn_h
end_ifndef

begin_define
define|#
directive|define
name|cg_dfn_h
end_define

begin_comment
comment|/*  * Flags which mark a symbol as topologically ``busy'' or as  * topologically ``not_numbered'':  */
end_comment

begin_define
define|#
directive|define
name|DFN_BUSY
value|-1
end_define

begin_define
define|#
directive|define
name|DFN_NAN
value|0
end_define

begin_comment
comment|/*  * Depth-first numbering of a call-graph.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|cg_dfn
parameter_list|(
name|Sym
modifier|*
name|root
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* cg_dfn_h */
end_comment

end_unit

