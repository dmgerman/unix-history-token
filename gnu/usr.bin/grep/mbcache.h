begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MB_CACHE_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|MB_CACHE_DEFINED
end_define

begin_struct
struct|struct
name|mb_cache
block|{
name|size_t
name|len
decl_stmt|;
specifier|const
name|char
modifier|*
name|orig_buf
decl_stmt|;
comment|/* not the only reference; do not free */
name|wchar_t
modifier|*
name|wcs_buf
decl_stmt|;
name|unsigned
name|char
modifier|*
name|mblen_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

