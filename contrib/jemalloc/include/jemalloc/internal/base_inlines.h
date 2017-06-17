begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|JEMALLOC_INTERNAL_BASE_INLINES_H
end_ifndef

begin_define
define|#
directive|define
name|JEMALLOC_INTERNAL_BASE_INLINES_H
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|base_ind_get
parameter_list|(
specifier|const
name|base_t
modifier|*
name|base
parameter_list|)
block|{
return|return
name|base
operator|->
name|ind
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* JEMALLOC_INTERNAL_BASE_INLINES_H */
end_comment

end_unit

