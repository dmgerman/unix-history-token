begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* In grokdeclarator, distinguish syntactic contexts of declarators.  */
end_comment

begin_enum
enum|enum
name|decl_context
block|{
name|NORMAL
block|,
comment|/* Ordinary declaration */
name|FUNCDEF
block|,
comment|/* Function definition */
name|PARM
block|,
comment|/* Declaration of parm before function body */
name|FIELD
block|,
comment|/* Declaration inside struct or union */
name|TYPENAME
block|,
comment|/* Typename (inside cast or sizeof)  */
name|MEMFUNCDEF
block|,
comment|/* Member function definition */
block|}
enum|;
end_enum

begin_comment
comment|/* C++: Keep these around to reduce calls to `get_identifier'.    Identifiers for `this' in member functions and the auto-delete    parameter for destructors.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|this_identifier
decl_stmt|,
name|in_charge_identifier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parsing a function declarator leaves a list of parameter names    or a chain or parameter decls here.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|last_function_parms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of static class variables.  This is needed, because a    static class variable can be declared inside the class without    an initializer, and then initialized, staticly, outside the class.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|pending_statics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of objects which have constructors or destructors    which reside in the global scope.  The decl is stored in    the TREE_VALUE slot and the initializer is stored    in the TREE_PURPOSE slot.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|static_aggregates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of functions which were declared inline, but later had their    address taken.  Used only for non-virtual member functions, since we can    find other functions easily enough.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|pending_addressable_inlines
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SOS
end_ifdef

begin_comment
comment|/* SOS extensions.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|zlink_type
decl_stmt|,
name|zret_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|zlink
decl_stmt|,
name|zret
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

