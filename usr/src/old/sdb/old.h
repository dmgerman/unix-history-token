begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* "@(#)old.h 4.2 8/17/82" */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMUNIX
end_ifndef

begin_struct
struct|struct
name|brbuf
block|{
name|int
name|nl
decl_stmt|,
name|nr
decl_stmt|;
name|char
modifier|*
name|next
decl_stmt|;
name|char
name|b
index|[
literal|1024
index|]
decl_stmt|;
name|int
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

