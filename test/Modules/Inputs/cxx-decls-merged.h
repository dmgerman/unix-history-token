begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|extern
name|int
name|mergeUsedFlag
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|n
decl_stmt|;
name|int
name|m
decl_stmt|;
block|}
name|NameForLinkage
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|NameForLinkage
name|name_for_linkage
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|HasVirtualFunctions
block|{
name|virtual
name|void
name|f
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|OverridesVirtualFunctions
range|:
name|HasVirtualFunctions
block|{
name|void
name|f
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OverridesVirtualFunctions
name|overrides_virtual_functions
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern
literal|"C"
name|void
name|ExternCFunction
parameter_list|()
function_decl|;
end_extern

begin_typedef
typedef|typedef
struct|struct
block|{
struct|struct
name|Inner
block|{
name|int
name|n
decl_stmt|;
block|}
struct|;
block|}
name|NameForLinkage2
typedef|;
end_typedef

begin_decl_stmt
name|auto
name|name_for_linkage2_inner_b
init|=
name|NameForLinkage2
operator|::
name|Inner
argument_list|()
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|decltype
argument_list|(
argument|name_for_linkage2_inner_b
argument_list|)
name|NameForLinkage2Inner
expr_stmt|;
end_typedef

begin_decl_stmt
name|namespace
name|Aliased
block|{
specifier|extern
name|int
name|b
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|Alias
init|=
name|Aliased
decl_stmt|;
end_decl_stmt

end_unit

