begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|DIRSIZ
end_ifndef

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|direct
block|{
name|ino_t
name|d_ino
decl_stmt|;
name|char
name|d_name
index|[
name|DIRSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

