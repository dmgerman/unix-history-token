begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ealloc.h,v 1.1.1.1 1999/11/19 04:30:56 mrg Exp $	*/
end_comment

begin_decl_stmt
name|void
modifier|*
name|emalloc
name|__P
argument_list|(
operator|(
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|estrdup
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|erealloc
name|__P
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|ecalloc
name|__P
argument_list|(
operator|(
name|size_t
name|nmemb
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

