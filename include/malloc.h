begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is SYSV-ism (for compatibility only) */
end_comment

begin_comment
comment|/* this declarations must match stdlib.h ones */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MALLOC_H_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_STDLIB_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_MALLOC_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|void
modifier|*
name|calloc
name|__P
argument_list|(
operator|(
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|malloc
name|__P
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|realloc
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MALLOC_H_ */
end_comment

end_unit

